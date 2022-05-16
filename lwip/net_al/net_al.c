/**
 ****************************************************************************************
 *
 * @file net_al.c
 *
 * @brief Implementation of the networking stack abstraction layer using LwIP.
 *
 * Copyright (C) RivieraWaves 2017-2019
 *
 ****************************************************************************************
 */

/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include "net_def.h"
#include "lwip/tcpip.h"
#include "lwip/etharp.h"
#include "lwip/netifapi.h"
#include "lwip/sockets.h"
#include "lwip/netbuf.h"
#include "lwip/api.h"
#include "lwip/dns.h"
#include "netif/ethernet.h"
#include "fhost_tx.h"
#include "dbg_assert.h"
#include "dma_generic.h"
#include "dma_api.h"

#define NX_NB_L2_FILTER 2

struct l2_filter_tag
{
    struct netif *net_if;
    int sock;
    struct netconn *conn;
    uint16_t ethertype;
};

static struct l2_filter_tag l2_filter[NX_NB_L2_FILTER];
static rtos_semaphore l2_semaphore;
static rtos_mutex     l2_mutex;

/*
 * FUNCTIONS
 ****************************************************************************************
 */
/// Fake function used to detected too small link encapsulation header length
void p_buf_link_encapsulation_hlen_too_small(void);

/// Declaration of the LwIP checksum computation function
u16_t lwip_standard_chksum(const void *dataptr, int len);

/**
 ****************************************************************************************
 * @brief Callback used by the networking stack to push a buffer for transmission by the
 * WiFi interface.
 *
 * @param[in] net_if Pointer to the network interface on which the TX is done
 * @param[in] p_buf  Pointer to the buffer to transmit
 *
 * @return ERR_OK upon successful pushing of the buffer, ERR_BUF otherwise
 ****************************************************************************************
 */
static err_t net_if_output(struct netif *net_if, struct pbuf *p_buf)
{
    err_t status = ERR_BUF;

    // Increase the ref count so that the buffer is not freed by the networking stack
    // until it is actually sent over the WiFi interface
    pbuf_ref(p_buf);

    // Push the buffer and verify the status
    if (netif_is_up(net_if) && fhost_tx_start(net_if->state, p_buf, NULL, NULL) == 0)
    {
        status = ERR_OK;
    }
    else
    {
        // Failed to push message to TX task, call pbuf_free only to decrease ref count
        pbuf_free(p_buf);
    }

    return (status);
}

/**
 ****************************************************************************************
 * @brief Callback used by the networking stack to setup the network interface.
 * This function should be passed as a parameter to netifapi_netif_add().
 *
 * @param[in] net_if Pointer to the network interface to setup
 * @param[in] p_buf  Pointer to the buffer to transmit
 *
 * @return ERR_OK upon successful setup of the interface, other status otherwise
 ****************************************************************************************
 */
static err_t net_if_init(struct netif *net_if)
{
    err_t status = ERR_OK;
    struct fhost_vif_tag *vif = (struct fhost_vif_tag *)net_if->state;

    #if LWIP_NETIF_HOSTNAME
    {
        /* Initialize interface hostname */
        net_if->hostname = "AicWlan";
    }
    #endif /* LWIP_NETIF_HOSTNAME */

    net_if->name[ 0 ] = 'w';
    net_if->name[ 1 ] = 'l';

    net_if->output = etharp_output;
    net_if->flags = NETIF_FLAG_BROADCAST | NETIF_FLAG_ETHARP | NETIF_FLAG_LINK_UP | NETIF_FLAG_IGMP;
    net_if->hwaddr_len = ETHARP_HWADDR_LEN;
    net_if->mtu = LLC_ETHER_MTU;
    net_if->linkoutput = net_if_output;
    memcpy(net_if->hwaddr, &vif->mac_addr, ETHARP_HWADDR_LEN);

    return status;
}

uint16_t net_ip_chksum(const void *dataptr, int len)
{
    // Simply call the LwIP function
    return lwip_standard_chksum(dataptr, len);
}

int net_if_add(net_if_t *net_if,
               const uint32_t *ipaddr,
               const uint32_t *netmask,
               const uint32_t *gw,
               struct fhost_vif_tag *vif)
{
    err_t status;

    status = netifapi_netif_add(net_if,
                               (const ip4_addr_t *)ipaddr,
                               (const ip4_addr_t *)netmask,
                               (const ip4_addr_t *)gw,
                               vif,
                               net_if_init,
                               tcpip_input);

    return (status == ERR_OK ? 0 : -1);
}

const uint8_t *net_if_get_mac_addr(net_if_t *net_if)
{
    return net_if->hwaddr;
}

net_if_t *net_if_find_from_name(const char *name)
{
    return netif_find(name);
}

net_if_t *net_if_find_from_wifi_idx(unsigned int idx)
{
    if ((idx >= NX_VIRT_DEV_MAX) || (fhost_env.vif[idx].mac_vif == NULL))
        return NULL;


    if (fhost_env.vif[idx].mac_vif->type != VIF_UNKNOWN)
    {
        return &fhost_env.vif[idx].net_if;
    }

    return NULL;
}

int net_if_get_name(net_if_t *net_if, char *buf, int len)
{
    if (len > 0)
        buf[0] = net_if->name[0];
    if (len > 1)
        buf[1] = net_if->name[1];
    if (len > 2)
        buf[2] = net_if->num + '0';
    if ( len > 3)
        buf[3] = '\0';

    return 3;
}

int net_if_get_wifi_idx(net_if_t *net_if)
{
    struct fhost_vif_tag *vif;
    int idx;

    if (!net_if)
        return -1;

    vif = (struct fhost_vif_tag *)net_if;
    idx = CO_GET_INDEX(vif, fhost_env.vif);

    /* sanity check */
    if (&fhost_env.vif[idx].net_if == net_if)
        return idx;

    return -1;
}

void net_if_up(net_if_t *net_if)
{
    netifapi_netif_set_up(net_if);
}

void net_if_down(net_if_t *net_if)
{
    netifapi_netif_set_down(net_if);
}

void net_if_set_default(net_if_t *net_if)
{
    netifapi_netif_set_default(net_if);
}

void net_if_set_ip(net_if_t *net_if, uint32_t ip, uint32_t mask, uint32_t gw)
{
    if (!net_if)
        return;
    netif_set_addr(net_if, (const ip4_addr_t *)&ip, (const ip4_addr_t *)&mask,
                   (const ip4_addr_t *)&gw);
}

int net_if_get_ip(net_if_t *net_if, uint32_t *ip, uint32_t *mask, uint32_t *gw)
{
    if (!net_if)
        return -1;

    if (ip)
        *ip = netif_ip4_addr(net_if)->addr;
    if (mask)
        *mask = netif_ip4_netmask(net_if)->addr;
    if (gw)
        *gw = netif_ip4_gw(net_if)->addr;

    return 0;
}

int net_if_input(net_buf_rx_t *buf, net_if_t *net_if, void *addr, uint16_t len, net_buf_free_fn free_fn)
{
    struct pbuf* p;

    buf->custom_free_function = (pbuf_free_custom_fn)free_fn;
    p = pbuf_alloced_custom(PBUF_RAW, len, PBUF_REF, buf, addr, len);
    ASSERT_ERR(p != NULL);

    if (net_if->input(p, net_if))
    {
        free_fn(buf);
        return -1;
    }

    return 0;
}

struct fhost_vif_tag *net_if_vif_info(net_if_t *net_if)
{
    return ((struct fhost_vif_tag *)net_if->state);
}

net_buf_tx_t *net_buf_tx_alloc(const uint8_t *payload, uint32_t length)
{
    struct pbuf *pbuf;

    pbuf = pbuf_alloc(PBUF_RAW_TX, length, PBUF_RAM);
    if (pbuf == NULL)
        return NULL;

    #if 0
    memcpy(pbuf->payload, payload, length);
    #else
    dma_desc_t dma_desc = {0};
    memset(&dma_desc, 0, (sizeof(dma_desc_t)));
    dma_desc.SAR = (uint32_t)payload;
    dma_desc.DAR = (uint32_t)pbuf->payload;
    dma_desc_length_set(&dma_desc, length);
    dma_desc.LNAR = 0;

    dma_push(&dma_desc, &dma_desc, DMA_CHANNEL_IPC_DATA_AC1_TX);
    dma_lli_poll(DMA_CHANNEL_IPC_DATA_AC1_TX);
    dma_ch_int_clear(DMA_CHANNEL_IPC_DATA_AC1_TX);
    #endif
    return pbuf;
}

void net_buf_tx_info(net_buf_tx_t *buf, uint16_t *tot_len, uint8_t *seg_cnt)
{
    uint8_t  idx;
    uint16_t length = buf->tot_len;

    *tot_len = length;

    idx = 0;
    while (length && buf)
    {
        // Sanity check - the payload shall be in shared RAM
        //ASSERT_ERR(!TST_SHRAM_PTR(buf->payload));

        length -= buf->len;
        idx++;
        // Get info of extra segments if any
        buf = buf->next;
    }

    *seg_cnt = idx;
    if (length != 0)
    {
        // The complete buffer must be included in all the segments
        ASSERT_ERR(0);
    }
}

void net_buf_tx_free(net_buf_tx_t *buf)
{
    // Free the buffer
    pbuf_free(buf);
}

int net_init(void)
{
    int i;

    for (i = 0; i < NX_NB_L2_FILTER; i++)
    {
        l2_filter[i].net_if = NULL;
    }

    if (rtos_semaphore_create(&l2_semaphore, 1, 0))
    {
        ASSERT_ERR(0);
    }

    if (rtos_mutex_create(&l2_mutex))
    {
        ASSERT_ERR(0);
    }

    // Initialize the TCP/IP stack
    tcpip_init(NULL, NULL);

    return 0;
}

static void net_l2_send_cfm(uint32_t frame_id, bool acknowledged, void *arg)
{
    if (arg)
        *((bool *)arg) = acknowledged;
    rtos_semaphore_signal(l2_semaphore, false);
}

int net_l2_send(net_if_t *net_if, const uint8_t *data, int data_len, uint16_t ethertype,
                const uint8_t *dst_addr, bool *ack)
{
    struct pbuf *pbuf;
    int res;

    if (net_if == NULL || data == NULL || data_len >= net_if->mtu || !netif_is_up(net_if))
        return -1;

    pbuf = pbuf_alloc(PBUF_LINK, data_len, PBUF_RAM);
    if (pbuf == NULL)
        return -1;

    memcpy(pbuf->payload, data, data_len);

    if (dst_addr)
    {
        // Need to add ethernet header as fhost_tx_start is called directly
        struct eth_hdr* ethhdr;
        if (pbuf_header(pbuf, SIZEOF_ETH_HDR))
        {
            pbuf_free(pbuf);
            return -1;
        }
        ethhdr = (struct eth_hdr*)pbuf->payload;
        ethhdr->type = htons(ethertype);
        memcpy(&ethhdr->dest, dst_addr, sizeof(struct eth_addr));
        memcpy(&ethhdr->src, net_if->hwaddr, sizeof(struct eth_addr));
    }

    // Ensure no other thread will program a L2 transmission while this one is waiting
    // for its confirmation
    rtos_mutex_lock(l2_mutex, -1);

    // In order to implement this function as blocking until the completion of the frame
    // transmission, directly call fhost_tx_start with a confirmation callback.
    res = fhost_tx_start(net_if->state, pbuf, net_l2_send_cfm, ack);

    // Wait for the transmission completion
    rtos_semaphore_wait(l2_semaphore, -1);

    // Now new L2 transmissions are possible
    rtos_mutex_unlock(l2_mutex);

    return res;
}

int net_l2_socket_create(net_if_t *net_if, uint16_t ethertype)
{
    struct l2_filter_tag *filter = NULL;
    socklen_t len = sizeof(filter->conn);
    int i;

    /* First find free filter and check that socket for this ethertype/net_if couple
       doesn't already exists */
    for (i = 0; i < NX_NB_L2_FILTER; i++)
    {
        if ((l2_filter[i].net_if == net_if) &&
            (l2_filter[i].ethertype == ethertype))
        {
            return -1;
        }
        else if ((filter == NULL) && (l2_filter[i].net_if == NULL))
        {
            filter = &l2_filter[i];
        }
    }

    if (!filter)
        return -1;

    /* Note: we create DGRAM socket here but in practice we don't care, net_eth_receive
       will use the socket as a L2 raw socket */
    filter->sock = socket(PF_INET, SOCK_DGRAM, 0);
    if (filter->sock < 0)
        return -1;

    if (getsockopt(filter->sock, SOL_SOCKET, SO_CONNINFO, &(filter->conn), &len))
    {
        close(filter->sock);
        return -1;
    }

    filter->net_if = net_if;
    filter->ethertype = ethertype;

    return filter->sock;
}

int net_l2_socket_delete(int sock)
{
    int i;
    for (i = 0; i < NX_NB_L2_FILTER; i++)
    {
        if ((l2_filter[i].net_if != NULL) &&
            (l2_filter[i].sock == sock))
        {
            l2_filter[i].net_if = NULL;
            close(l2_filter[i].sock);
            l2_filter[i].sock = -1;
            return 0;
        }
    }

    return -1;
}

err_t net_eth_receive(struct pbuf *pbuf, struct netif *netif)
{
    struct l2_filter_tag *filter = NULL;
    struct eth_hdr* ethhdr = pbuf->payload;
    uint16_t ethertype = ntohs(ethhdr->type);
    struct netconn *conn;
    struct netbuf *buf;
    int i;

    for (i = 0; i < NX_NB_L2_FILTER; i++)
    {
        if ((l2_filter[i].net_if == netif) &&
            (l2_filter[i].ethertype == ethertype))
        {
            filter = &l2_filter[i];
            break;
        }
    }

    if (!filter)
        return ERR_VAL;

    buf = (struct netbuf *)memp_malloc(MEMP_NETBUF);
    if (buf == NULL)
    {
        return ERR_MEM;
    }

    buf->p = pbuf;
    buf->ptr = pbuf;
    conn = filter->conn;

    if (sys_mbox_trypost(&conn->recvmbox, buf) != ERR_OK)
    {
        netbuf_delete(buf);
        return ERR_OK;
    }
    else
    {
        #if LWIP_SO_RCVBUF
        SYS_ARCH_INC(conn->recv_avail, pbuf->tot_len);
        #endif /* LWIP_SO_RCVBUF */
        /* Register event with callback */
        API_EVENT(conn, NETCONN_EVT_RCVPLUS, pbuf->tot_len);
    }

    return ERR_OK;
}

static int net_dhcp_started = 0;
int net_dhcp_start(net_if_t *net_if)
{
    #if LWIP_IPV4 && LWIP_DHCP
    if (netifapi_dhcp_start(net_if) ==  ERR_OK) {
        net_dhcp_started = 1;
        return 0;
    }
    #endif //LWIP_IPV4 && LWIP_DHCP
    return -1;
}

void net_dhcp_stop(net_if_t *net_if)
{
    #if LWIP_IPV4 && LWIP_DHCP
    netifapi_dhcp_stop(net_if);
    net_dhcp_started = 0;
    #endif //LWIP_IPV4 && LWIP_DHCP
}

int net_dhcp_start_status(void)
{
    return net_dhcp_started;
}

int net_dhcp_release(net_if_t *net_if)
{
    #if LWIP_IPV4 && LWIP_DHCP
    if (netifapi_dhcp_release(net_if) ==  ERR_OK)
        return 0;
    #endif //LWIP_IPV4 && LWIP_DHCP
    return -1;
}

int net_dhcp_address_obtained(net_if_t *net_if)
{
    #if LWIP_IPV4 && LWIP_DHCP
    if (dhcp_supplied_address(net_if))
        return 0;
    #endif //LWIP_IPV4 && LWIP_DHCP
    return -1;
}

int net_set_dns(uint32_t dns_server)
{
    #if LWIP_DNS
    ip_addr_t ip;
    ip_addr_set_ip4_u32(&ip, dns_server);
    dns_setserver(0, &ip);
    return 0;
    #else
    return -1;
    #endif
}

int net_get_dns(uint32_t *dns_server)
{
    #if LWIP_DNS
    const ip_addr_t *ip;

    if (dns_server == NULL)
        return -1;

    ip = dns_getserver(0);
    *dns_server = ip_addr_get_ip4_u32(ip);
    return 0;
    #else
    return -1;
    #endif
}

void lwip_data_save(void)
{
    lwip_arp_data_save();
}

void lwip_data_restore(void)
{
    lwip_arp_data_restore();
}
