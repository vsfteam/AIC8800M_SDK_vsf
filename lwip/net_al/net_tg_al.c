/**
 ****************************************************************************************
 *
 * @file net_tg_al.c
 *
 * @brief Definition of the networking stack abstraction layer used for traffic generator.
 *
 * Copyright (C) RivieraWaves 2017-2019
 *
 ****************************************************************************************
 */

/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include <string.h>
#include "co_endian.h"
#include "net_def.h"
#include "time_api.h"
#include "fhost_tg.h"
#include "fhost_ping.h"
#include "lwip/raw.h"
#include "lwip/udp.h"
#include "lwip/icmp.h"
#include "lwip/igmp.h"
#include "lwip/inet_chksum.h"

/*
 * DEFINITIONS
 ****************************************************************************************
 */
#if NX_TG
/// Maximum length of UDP payload
#define NET_MAX_UDP_LEN 1500 - UDP_HLEN - IP_HLEN
/// Multicast test rate is fixed at 50 frames/sec
#define NET_MCAST_FRATE            50
/// TG frame header size
#define NET_TG_HEADER_SIZE         20
/// TG frame total header size
#define NET_TG_HEADER_TOTAL_SIZE   LWIP_MEM_ALIGN_SIZE( \
        NET_TG_HEADER_SIZE + PBUF_LINK_ENCAPSULATION_HLEN + PBUF_LINK_HLEN + \
        PBUF_IP_HLEN + PBUF_TRANSPORT_HLEN)
/// Minimum transmission time for sending process (1 us)
#define NET_TG_MIN_SEND_TIME       1000000
/// Maximum transmission time for sending process (340 s)
#define NET_TG_MAX_SEND_TIME       340000000
#endif // NX_TG
/// Maximum length of PING payload
#define NET_MAX_PING_LEN 1500 - IP_HLEN
/// Ping identifier - must fit on a u16_t
#define NET_TG_PING_ID             0xAFAF
/// Ping ICMP ECHO header length : 8 bytes
#define NET_TG_PING_HDR_LEN        sizeof(struct icmp_echo_hdr)
/// Ping timestamp length : 8 bytes
#define NET_TG_PING_TIMESTAMP_LEN       8
/// Maximum ping time for sending process (340 s)
#define NET_TG_MAX_PING_TIME       340000000

#if NX_TG
/// Structure containing the information about the TG sending buffer
struct net_tg_send_info
{
    /// Pointer to TG stream
    struct fhost_tg_stream *my_stream;
    /// Flag to describe if this buffer is occupied : 1 for occupied, 0 for free
    int flag;
};
/// TG sending process environment structure
struct net_tg_send_buf_tag
{
    /// Network stack buffer element for TG payload
    struct pbuf_custom p;
    /// Structure containing the information about the TG sending buffer
    struct net_tg_send_info info;
    /// Network stack buffer element for TG header
    struct pbuf_custom h;
    /// TG header string
    char hdr[NET_TG_HEADER_TOTAL_SIZE];
};
#endif // NX_TG

/*
 * GLOBAL VARIABLES
 ****************************************************************************************
 */
#if NX_TG
/// Payload to send (no copy memory) which is pointed by pbuf->payload
static char net_udp_send_nocopy_buf[NET_MAX_UDP_LEN] __SHAREDRAM;
/// Pool of TG send buffers
static struct net_tg_send_buf_tag
net_tg_send_buf_mem[FHOST_TG_MAX_TRAFFIC_STREAMS][FHOST_TG_SEND_BUF_CNT] __SHAREDRAM;
#endif // NX_TG

/*
 * FUNCTIONS
 ****************************************************************************************
 */
#if PLF_PING
/**
 ****************************************************************************************
 * @brief Calculate the sleep time for different frame rate
 * It should be done according the device
 * This is just one way to adjust the packet delivery speed. If you find
 * you device does not meet the test requirements, you MUST re-adjust
 * the method.
 *
 * @param[in] profile        profile of stream
 * @param[in] rate           frame rate packets / sec
 * @param[out] sleep_time     interval sleep time
 * @param[out] throttled_rate frames to send in each interval
 ****************************************************************************************
 **/
static void net_sleep_time(enum profile_id prof, u32_t rate,
        u32_t *sleep_time, u32_t *throttled_rate)
{
    u32_t throttled_rate_int = 0;
    // in microseconds
    *sleep_time = 0;
    // calculate the sleep time based on frame rate
    switch(prof)
    {
        #if NX_TG
        case FHOST_PROF_MCAST :
        if(rate < 500 && rate >= 50)
        {
            // sleep for 100 ms
            *sleep_time = 100000;
            throttled_rate_int = NET_MCAST_FRATE;
        }
        else
        {   // rate < 50
            *sleep_time = 100000;
            throttled_rate_int = rate;
        }
        break;

        case FHOST_PROF_IPTV :
        case FHOST_PROF_FILE_TX :
        if (rate > 50)
        {
        /*
         * this sleep_time indeed is now being used for time period
         * to send packets in the throttled Rate.
         * The idea here is that in each fixed 20 millisecond period,
         * The device will send rate/50 (rate = packets / second),
         * then go sleep for rest of time.
         */
            *sleep_time = 20000; /* fixed 20 milliseconds */
            throttled_rate_int = rate / 50;
        }
        else if (rate == 0)
        {
            *sleep_time = 20000; /* fixed 20 milliseconds */
            throttled_rate_int = 10000 / 50;
        }
        else if (rate > 0 && rate <= 50) /* typically for voice */
        {
            *sleep_time = 1000000 / rate;
            throttled_rate_int = 1;
        }
        break;
        #endif // NX_TG
        // Ping command profile @ref fhost_ping.h
        case FHOST_PROF_PING :
        throttled_rate_int = 1;
        if (rate > 50)
        {
            // We set the maximum rate at 50 pkts / s
            *sleep_time = 20000;
        }
        else if (rate > 0 && rate <= 50)
        {
            *sleep_time = 1000000 / rate;
        }
        else if (rate == 0)
        {
            *sleep_time = 1000000;
        }
        break;

        default:
            TRACE("NET_TG_AL : SLEEP TIME ERR Incorrect profile");
        break;
    }

    if (throttled_rate)
    {
        *throttled_rate = throttled_rate_int;
    }
}

/**
 ****************************************************************************************
 * @brief Calculate the time difference
 *
 * @param[in] t1  TG time structure
 * @param[in] t2  TG time structure
 *
 * @return the time difference t2 - t1 (could be negative)
 ****************************************************************************************
 **/
static int net_time_diff(struct fhost_tg_time *t1, struct fhost_tg_time *t2)
{
    int dtime;
    int sec = t2->sec - t1->sec;
    int usec = t2->usec - t1->usec;

    if (usec < 0)
    {
        sec -=1;
        usec += 1000000;
    }

    dtime = sec * 1000000 + usec;
    return dtime;
}
#endif /* PLF_PING */

#if NX_TG
/**
 ****************************************************************************************
 * @brief Callback function called when we free the pbuf_custom of TG header
 * Currently it does nothing.
 *
 * @param[in] p              pointer to a pbuf_custom buffer to free
 ****************************************************************************************
 **/
static void net_tg_pbuf_custom_header_free_cb(void *p)
{
}

/**
 ****************************************************************************************
 * @brief Callback function called when we free the pbuf_custom of TG payload
 * It will increase credit and set flag to 0.
 *
 * @param[in] p              pointer to a pbuf_custom buffer to free
 ****************************************************************************************
 **/
static void net_tg_pbuf_custom_payload_free_cb(void *p)
{
    struct net_tg_send_buf_tag *buf = p;
    struct fhost_tg_stream *my_stream = buf->info.my_stream;
    rtos_mutex m = my_stream->tg_mutex;
    // Avoid sending process to modify it in the same time
    rtos_mutex_lock(m);
    buf->info.flag = 0;
    my_stream->credits += 1;
    rtos_mutex_unlock(m);
    // Send a signal to sending process that we have a new credit
    rtos_semaphore_signal(my_stream->net_tg_semaphore, false);
}

/**
 ****************************************************************************************
 * @brief Initialize the pool of TG send buffers according to TG stream
 * It will also initialize part of TG header message.
 *
 * @param[in] my_stream      pointer to TG stream for which we initialize its pool
 ****************************************************************************************
 **/
static void net_tg_send_buf_init(struct fhost_tg_stream *my_stream)
{
    int i, j;

    i = my_stream->id;
    memset(net_tg_send_buf_mem[i], 0, sizeof(struct net_tg_send_buf_tag)
            * FHOST_TG_SEND_BUF_CNT);
    for (j = 0; j < FHOST_TG_SEND_BUF_CNT; j++)
    {
        // Initialize callback function for its pbuf custom
        net_tg_send_buf_mem[i][j].h.custom_free_function =
                (pbuf_free_custom_fn)net_tg_pbuf_custom_header_free_cb;
        net_tg_send_buf_mem[i][j].p.custom_free_function =
                (pbuf_free_custom_fn)net_tg_pbuf_custom_payload_free_cb;
        // Pointer to TG stream
        net_tg_send_buf_mem[i][j].info.my_stream = my_stream;
        // Initialize header message
        memcpy(&net_tg_send_buf_mem[i][j].hdr, "1345678", 8);
    }
}

/**
 ****************************************************************************************
 * @brief Find a free TG send buffer in the pool according to TG stream
 * We check if its flag is 0 or not.
 *
 * @param[in] my_stream      pointer to TG stream for which we search its pool
 *
 * @return pointer to the free TG send buffer, NULL if all occupied
 ****************************************************************************************
 **/
static struct net_tg_send_buf_tag *net_tg_find_free_send_buf(struct fhost_tg_stream *my_stream)
{
    int i, j;

    i = my_stream->id;
    for (j = 0; j < FHOST_TG_SEND_BUF_CNT; j++)
    {
        if((net_tg_send_buf_mem[i][j]).info.flag == 0)
        {
            (net_tg_send_buf_mem[i][j]).info.flag = 1;
            return &net_tg_send_buf_mem[i][j];
        }
    }
    return NULL;
}

/**
 ****************************************************************************************
 * @brief Calculate the throughput of traffic sending
 *
 * @param[in] init      start transmission timestamp
 * @param[in] actual    actual transmission timestamp
 * @param[in] tx_bytes  Number of TX buffer bytes sent
 *
 * @return the throughput of traffic sending (bps), -1 if incorrect duration
 ****************************************************************************************
 **/
static int net_cal_throughput(struct fhost_tg_time *init, struct fhost_tg_time *actual,
        u32_t tx_bytes)
{
    int diff_time;
    int throughput;

    diff_time = net_time_diff(init, actual);
    if (diff_time < NET_TG_MIN_SEND_TIME || diff_time > NET_TG_MAX_SEND_TIME)
    {
        // Duration too short or too long for sending process
        return -1;
    }
    // For better precision compute the throughput per ms, then multiply by 1000
    throughput = 8 * 1000 * (tx_bytes / (diff_time / 1000));
    return throughput;
}

/**
 ****************************************************************************************
 * @brief Callback function for udp_recv() of @ref net_tg_recv_start
 * This callback will be called when receiving a datagram from the pcb.
 *
 * ATTENTION: Be aware that 'addr' might point into the pbuf 'p' so freeing this pbuf
 *            can make 'addr' invalid, too.
 *
 * @param[in] arg  user supplied argument (udp_pcb.recv_arg)
 * @param[in] pcb  the udp_pcb which received data
 * @param[in] p    the packet buffer that was received
 * @param[in] addr the remote IP address from which the packet was received
 * @param[in] port the remote port from which the packet was received
 ****************************************************************************************
 **/
static void net_tg_recv_cb(void *arg, struct udp_pcb *pcb, struct pbuf *p,
        const ip_addr_t *addr, u16_t port)
{
    if (p != NULL)
    {
        u32_t c;
        char *c_p;

        struct fhost_tg_stream *my_stream = arg;

        (my_stream->stats.rx_frames)++;
        (my_stream->stats.rx_bytes) += p->tot_len;
        (my_stream->stats.counter_recv)++;

        // Get the counter in the received buffer (normally equal to counter_send)
        // Pointer pointed to counter_send in payload
        c_p = p->payload + 8;
        // Copy 4 bytes of data (counter_send) and make it an unsigned int
        memcpy(&c, c_p, 4);
        // Convert network format to host format
        c = co_ntohl(c);

        if (my_stream->stats.counter_recv == c)
        {
            (my_stream->stats.expected)++;
        }
        else if (my_stream->stats.counter_recv < c)
        {
            (my_stream->stats.lost) += c - my_stream->stats.counter_recv;
            my_stream->stats.counter_recv = c;
        }
        else
        {
            /// counter_recv > c
            (my_stream->stats.unordered)++;
            (my_stream->stats.counter_recv)--;
        }

        pbuf_free(p);
    }
}

/**
 ****************************************************************************************
 * @brief Callback function for udp_recv() of @ref net_tg_recv_transc_start
 * This callback will be called when receiving a datagram from the pcb. It will send a
 * response to the sender every time called.
 *
 * ATTENTION: Be aware that 'addr' might point into the pbuf 'p' so freeing this pbuf
 *            can make 'addr' invalid, too.
 *
 * @param[in] arg  user supplied argument (udp_pcb.recv_arg)
 * @param[in] pcb  the udp_pcb which received data
 * @param[in] p    the packet buffer that was received
 * @param[in] addr the remote IP address from which the packet was received
 * @param[in] port the remote port from which the packet was received
 ****************************************************************************************
 **/
static void net_tg_recv_transc_cb(void *arg, struct udp_pcb *pcb, struct pbuf *p,
        const ip_addr_t *addr, u16_t port)
{
    if (p != NULL)
    {
        uint16_t tot_len = p->tot_len;
        err_t err_log;
        struct pbuf *p_send, *h_send;

        struct fhost_tg_stream *my_stream = arg;
        char *hdr;

        u32_t sec_nl, usec_nl;
        struct fhost_tg_time actual;

        pbuf_free(p);
        aic_time_get(SINCE_EPOCH, &actual.sec, &actual.usec);

        (my_stream->stats.rx_frames)++;
        (my_stream->stats.rx_bytes) += tot_len;

        // Allocation of response buffer
        h_send = pbuf_alloc(PBUF_TRANSPORT, NET_TG_HEADER_SIZE, PBUF_RAM);
        // If there's no more memory to allocate pbuf, we don't send the response to sender
        if (h_send == NULL)
        {
            return;
        }
        p_send = pbuf_alloc(PBUF_RAW, tot_len - NET_TG_HEADER_SIZE, PBUF_ROM);
        if (p_send == NULL)
        {
            pbuf_free(h_send);
            return;
        }

        pbuf_cat(h_send, p_send);
        p_send->payload = net_udp_send_nocopy_buf;

        hdr = h_send->payload;

        // For a transaction receiver, it just needs to send the local time back
        sec_nl = co_htonl(actual.sec);
        usec_nl = co_htonl(actual.usec);
        memcpy(&hdr[12], &sec_nl, 4);
        memcpy(&hdr[16], &usec_nl, 4);

        err_log = udp_send(pcb, h_send);

        if (err_log == ERR_OK)
        {
            (my_stream->stats.tx_frames)++;
            my_stream->stats.tx_bytes += tot_len;
        }
        else
        {
            TRACE("NET_TG_AL : RECV TRANSC CB ERR udp_sendto : %ld", TR_32(err_log));
        }

        pbuf_free(h_send);
    }
}

/**
 ****************************************************************************************
 * @brief Callback function for udp_recv() of @ref net_tg_send_transc_start
 * This callback will be called when receiving a datagram from the pcb. It will calculate
 * the RTT and send a signal to TG send thread every time called.
 *
 * ATTENTION: Be aware that 'addr' might point into the pbuf 'p' so freeing this pbuf
 *            can make 'addr' invalid, too.
 *
 * @param[in] arg  user supplied argument (udp_pcb.recv_arg)
 * @param[in] pcb  the udp_pcb which received data
 * @param[in] p    the packet buffer that was received
 * @param[in] addr the remote IP address from which the packet was received
 * @param[in] port the remote port from which the packet was received
 ****************************************************************************************
 **/
static void net_tg_send_transc_cb(void *arg, struct udp_pcb *pcb, struct pbuf *p,
        const ip_addr_t *addr, u16_t port)
{
    if (p != NULL)
    {
        struct fhost_tg_stream *my_stream = arg;
        int diff_time;
        struct fhost_tg_time recv;

        aic_time_get(SINCE_EPOCH, &recv.sec, &recv.usec);

        // Calculate RTT as diff_time
        diff_time = net_time_diff(&(my_stream->transc_timestamp), &recv);
        // Sanity check - diff_time should never be negative,
        // because we send before we receive the response
        ASSERT_ERR(diff_time > 0);
        // Calculate the average to obtain the approximation of RTT
        my_stream->stats.rt_time = (my_stream->stats.rt_time + diff_time) / 2;

        (my_stream->stats.rx_frames)++;
        (my_stream->stats.rx_bytes) += p->tot_len;

        // Send a signal to net_tg_send_transc_start() to indicate we receive the response
        rtos_semaphore_signal(my_stream->net_tg_semaphore, false);

        pbuf_free(p);
    }
}

/**
 ****************************************************************************************
 * @brief Configuration of PCB for TG sending process
 *
 * @param[in] pcb          pointer to udp_pcb to which we send data
 * @param[in] my_stream    pointer to TG stream which contains configuration information
 *
 * @return 0 on success and != 0 if error occurred.
 ****************************************************************************************
 **/
static int net_tg_pcb_config(struct udp_pcb *pcb, struct fhost_tg_stream *my_stream)
{
    u32_t ip;
    ip_addr_t rip;
    ip_addr_t lip;

    ip = (my_stream->prof).src_ip;
    IP4_ADDR(&lip,  ip & 0xff, (ip >> 8) & 0xff,
            (ip >> 16) & 0xff, (ip >> 24) & 0xff);

    if (udp_bind(pcb, &lip, my_stream->prof.src_port) != ERR_OK)
    {
        TRACE("NET_TG_AL : PCB CONFIG ERR udp_bind failed");
        return 1;
    }

    ip = (my_stream->prof).dst_ip;
    IP4_ADDR(&rip,  ip & 0xff, (ip >> 8) & 0xff,
            (ip >> 16) & 0xff, (ip >> 24) & 0xff);

    // Only for MCAST profile
    if(my_stream->prof.prof_id == FHOST_PROF_MCAST)
    {
#if LWIP_IGMP
        ip_addr_t allsystems;
        IP4_ADDR(&allsystems, 224, 0, 0, 1);

        // If the remote address (which is a group address) is not the group address
        // for all system (224.0.0.1), we should join our local address to
        // this remote address
        if (!ip4_addr_cmp(&allsystems, &rip))
        {
            err_t err_log;
            // Normally, lip is local IP address of DUT and rip is group address
            err_log = igmp_joingroup(&lip, &rip);
            if (err_log != ERR_OK)
            {
                return 1;
            }
        }
#endif  // LWIP_IGMP
        if (my_stream->prof.direction == FHOST_TG_DIRECT_SEND)
        {
            // TODO : need something more robust than hardcoded value "wl1"
            net_if_t *netif = net_if_find_from_name("wl1");

            ip4_set_default_multicast_netif(netif);
            // Connect to the group address for TX process
            if (udp_connect(pcb, &rip, my_stream->prof.dst_port) != ERR_OK)
            {
                TRACE("NET_TG_AL : PCB CONFIG ERR udp_connect failed");
                return 1;
            }
        }
        else if (my_stream->prof.direction == FHOST_TG_DIRECT_RECV)
        {
            // Connect to the address 0.0.0.0 for RX process
            IP4_ADDR(&rip,  0, 0, 0, 0);
            if (udp_connect(pcb, &rip, my_stream->prof.dst_port) != ERR_OK)
            {
                TRACE("NET_TG_AL : PCB CONFIG ERR udp_connect failed");
                return 1;
            }
        }
    }
    // For other profiles
    else
    {
        if (udp_connect(pcb, &rip, my_stream->prof.dst_port) != ERR_OK)
        {
            TRACE("NET_TG_AL : PCB CONFIG ERR udp_connect failed");
            return 1;
        }
    }

    pcb->tos = my_stream->prof.tos;
    return 0;
}

/**
 ****************************************************************************************
 * @brief Initialize TG process
 *
 * @param[in] my_stream    pointer to TG stream which contains configuration information
 * @param[in] recv    callback function pointer used for @ref udp_recv
 *
 * @return pointer to udp_pcb configured on success and NULL if error occurred.
 ****************************************************************************************
 **/
static struct udp_pcb *net_tg_init(struct fhost_tg_stream *my_stream, udp_recv_fn recv)
{
    struct udp_pcb * pcb = NULL;

    LOCK_TCPIP_CORE();
    pcb = udp_new();
    if (pcb == NULL)
    {
        TRACE("NET_TG_AL : TG INIT ERR udp_new failed");
        UNLOCK_TCPIP_CORE();
        return NULL;
    }

    if (net_tg_pcb_config(pcb, my_stream))
    {
        UNLOCK_TCPIP_CORE();
        return NULL;
    }

    my_stream->arg = pcb;
    if (recv != NULL)
    {
        udp_recv(pcb, recv, my_stream);
    }
    UNLOCK_TCPIP_CORE();

    return pcb;
}
#endif // NX_TG

#if PLF_PING
/**
 ****************************************************************************************
 * @brief Configuration of PCB for ping process
 *
 * @param[in] pcb          pointer to raw_pcb to which we send data
 * @param[in] my_stream    pointer to ping stream which contains configuration information
 *
 * @return 0 on success and != 0 if error occurred.
 ****************************************************************************************
 **/
static int net_ping_pcb_config(struct raw_pcb *pcb, struct fhost_ping_stream *my_stream)
{
    u32_t ip;
    ip_addr_t rip;

    if (raw_bind(pcb, IP_ADDR_ANY) != ERR_OK)
    {
        TRACE("NET_TG_AL : PING PCB CONFIG ERR raw_bind failed");
        return 1;
    }

    ip = (my_stream->prof).dst_ip;
    IP4_ADDR(&rip,  ip & 0xff, (ip >> 8) & 0xff,
            (ip >> 16) & 0xff, (ip >> 24) & 0xff);

    if (raw_connect(pcb, &rip) != ERR_OK)
    {
        TRACE("NET_TG_AL : PING PCB CONFIG ERR raw_connect failed");
        return 1;
    }

    pcb->tos = my_stream->prof.tos;
    return 0;
}

/**
 ****************************************************************************************
 * @brief Initialize ping process
 *
 * @param[in] my_stream    pointer to ping stream which contains configuration information
 * @param[in] ping_recv    callback function pointer used for @ref raw_recv
 *
 * @return pointer to raw_pcb configured on success and NULL if error occurred.
 ****************************************************************************************
 **/
static struct raw_pcb *net_ping_init(struct fhost_ping_stream *my_stream,
        raw_recv_fn ping_recv)
{
    struct raw_pcb *pcb;

    LOCK_TCPIP_CORE();
    pcb = raw_new(IP_PROTO_ICMP);
    if (pcb == NULL)
    {
        TRACE("NET_TG_AL : TG PING INIT ERR raw_new failed");
        UNLOCK_TCPIP_CORE();
        return NULL;
    }

    if (net_ping_pcb_config(pcb, my_stream))
    {
        UNLOCK_TCPIP_CORE();
        return NULL;
    }

    my_stream->arg = pcb;

    raw_recv(pcb, ping_recv, my_stream);
    UNLOCK_TCPIP_CORE();

    return pcb;
}

/**
 ****************************************************************************************
 * @brief Callback function for raw_recv() of @ref net_ping_send
 * This callback will be called when receiving a datagram from the pcb.
 *
 * @param[in] arg       user supplied argument (raw_pcb.recv_arg)
 * @param[in] pcb       the raw_pcb which received data
 * @param[in] p         the packet buffer that was received
 * @param[in] addr      the remote IP address from which the packet was received
 *
 * @return 1 if the packet was 'eaten' (aka. deleted),
 *         0 if the packet lives on
 * If returning 1, the callback is responsible for freeing the pbuf
 * if it's not used any more.
 ****************************************************************************************
 **/
static u8_t net_ping_recv_cb(void *arg, struct raw_pcb *pcb,
        struct pbuf *p, ip_addr_t *addr)
{
    struct fhost_ping_stream *my_stream = arg;
    struct icmp_echo_hdr *iecho;
    size_t hdr_len = NET_TG_PING_HDR_LEN;
    char *sec_p, *usec_p;

    int diff_time;
    struct fhost_tg_time recv, send;
    // Sanity check - If callback function called, then p should never be NULL
    ASSERT_ERR(p != NULL);

    // Adjusts the ->payload pointer so that IP header disappears in the pbuf payload.
    if (pbuf_header(p, -PBUF_IP_HLEN) == 0)
    {
        iecho = (struct icmp_echo_hdr *)p->payload;

        #if (PLF_HW_PXP != 1)
        if ((iecho->id == NET_TG_PING_ID + my_stream->id) &&
                (iecho->seqno == co_htons(my_stream->ping_seq_num)) &&
                ip_addr_cmp(addr, &pcb->remote_ip))
        #else /* PLF_HW_PXP */
        if((iecho->id == NET_TG_PING_ID + my_stream->id) &&
                               (iecho->type == ICMP_ER) &&
                             ip_addr_cmp(addr, &pcb->remote_ip))
        #endif /* PLF_HW_PXP */
        {

            #if NX_CSI
            csi_stop();
            #endif /* NX_CSI */
            aic_time_get(SINCE_EPOCH, &recv.sec, &recv.usec);
            // Get the timestamp in the received buffer
            sec_p = (p->payload + hdr_len);
            usec_p = (p->payload + hdr_len + 4);
            memcpy(&send.sec, sec_p, 4);
            memcpy(&send.usec, usec_p, 4);
            // Convert network format to host format
            send.sec = co_ntohl(send.sec);
            send.usec = co_ntohl(send.usec);
            // Calculate RTT as diff_time
            diff_time = net_time_diff(&send, &recv);
            // Print traces at IPC layer
            dbg("%d bytes from: %s: icmp_req=%d ttl=%d time=%d us\n",
                        p->tot_len,
                        ipaddr_ntoa(&pcb->remote_ip),
                        co_ntohs(iecho->seqno),
                        pcb->ttl,
                        diff_time);
            // Sanity check - diff_time should never be negative,
            // because we send before we receive the response
            ASSERT_ERR(diff_time > 0);
            // Calculate the cumulative value of RTT
            my_stream->stats.rt_time += diff_time;
            (my_stream->stats.rx_frames)++;
            (my_stream->stats.rx_bytes) += p->tot_len;

            pbuf_free(p);
            return 1; // eat the packet
        }
        else
        {   // Restore ->payload pointer position if this buffer is not
            // the corresponding response
            pbuf_header_force(p, PBUF_IP_HLEN);
        }
    }
    return 0; // don't eat the packet
}

/**
 ****************************************************************************************
 * @brief Configure ICMP ECHO packet to be sent to the remote IP address, used for
 * @ref net_ping_send
 * Here is the structure of ICMP ECHO packet :
 *
 *            | 8 bytes |    8 bytes     |            data_len           |
 *            ************************************************************
 *            |   hdr   |   timestamp    |             DATA              |
 *            ************************************************************
 *
 * @param[in] iecho       pointer to ICMP ECHO header
 * @param[in] len         total length of packet to be sent
 * @param[in] my_stream   pointer to ping stream which contains configuration information
 ****************************************************************************************
 **/
static void net_ping_prepare_echo(struct icmp_echo_hdr *iecho, u16_t len,
        struct fhost_ping_stream *my_stream)
{
    struct fhost_tg_time send;
    u32_t sec_nl, usec_nl;
    size_t i;
    size_t timestamp_len = NET_TG_PING_TIMESTAMP_LEN;
    size_t hdr_len = NET_TG_PING_HDR_LEN;
    // 8 bytes for size of timestamp
    size_t data_len = len - hdr_len - timestamp_len;
    char *timestamp = (char *)iecho + hdr_len;

    ICMPH_TYPE_SET(iecho, ICMP_ECHO);
    ICMPH_CODE_SET(iecho, 0);
    iecho->chksum = 0;
    iecho->id     = NET_TG_PING_ID + my_stream->id;
    iecho->seqno  = co_htons(++(my_stream->ping_seq_num));

    aic_time_get(SINCE_EPOCH, &send.sec, &send.usec);
    // Fill in the payload with timestamp
    // Convert unsigned int of host format to network format
    sec_nl = co_htonl(send.sec);
    usec_nl = co_htonl(send.usec);
    memcpy(&timestamp[0], &sec_nl, 4);
    memcpy(&timestamp[4], &usec_nl, 4);

    /* fill the additional data buffer with some data */
    for(i = 0; i < data_len; i++) {
        ((char *)iecho)[hdr_len + timestamp_len + i] = (char)i;
    }

    iecho->chksum = inet_chksum(iecho, len);
}
#endif /* PLF_PING*/

#if NX_TG
int net_tg_send_transc(struct fhost_tg_stream *my_stream)
{
    struct udp_pcb * pcb = NULL;
    net_buf_tx_t *h = NULL;
    net_buf_tx_t *p = NULL;
    err_t err_log;
    struct fhost_tg_time send, init;
    u32_t pack_len = my_stream->prof.pksize;
    int duration;
    // current duration of TG sending process
    int duration_cur = 0;

    if (pack_len > NET_MAX_UDP_LEN)
        pack_len = NET_MAX_UDP_LEN;

    if (my_stream->prof.duration == 0)
        duration = 30 * 1000000;
    else
        duration = my_stream->prof.duration * 1000000;

    if (duration > NET_TG_MAX_SEND_TIME)
    {
        duration = NET_TG_MAX_SEND_TIME;
    }

    pcb = net_tg_init(my_stream, net_tg_send_transc_cb);
    if (pcb == NULL)
    {
        TRACE("NET_TG_AL : SEND TRANSC ERR pcb null");
        return 1;
    }

    // estimated value : 2000 us for RTT to initialize
    my_stream->stats.rt_time = 2000;

    aic_time_get(SINCE_EPOCH, &init.sec, &init.usec);
    while (my_stream->active && duration_cur < duration)
    {
        h = pbuf_alloc(PBUF_TRANSPORT, NET_TG_HEADER_SIZE, PBUF_RAM);
        if (h == NULL)
        {
            TRACE("NET_TG_AL : SEND TRANSC ERR h null");
            rtos_task_suspend(1);
            continue;
        }
        p = pbuf_alloc(PBUF_RAW, pack_len - NET_TG_HEADER_SIZE, PBUF_ROM);
        if (p == NULL)
        {
            pbuf_free(h);
            TRACE("NET_TG_AL : SEND TRANSC ERR p null");
            rtos_task_suspend(1);
            continue;
        }
        // Sanity check - If buf_tag is not NULL, then h and p should never be NULL
        ASSERT_ERR((h != NULL) && (p != NULL));

        pbuf_cat(h, p);
        p->payload = net_udp_send_nocopy_buf;

        aic_time_get(SINCE_EPOCH, &send.sec, &send.usec);
        // Store the timestamp of sending
        my_stream->transc_timestamp = send;

        LOCK_TCPIP_CORE();
        err_log = udp_send(pcb, h);
        UNLOCK_TCPIP_CORE();

        pbuf_free(h);

        // Calculate the current duration of TG transaction sending process
        duration_cur = net_time_diff(&init, &send);

        if (err_log == ERR_OK)
        {
            (my_stream->stats.tx_frames)++;
            my_stream->stats.tx_bytes += pack_len;
        }
        else
        {
            TRACE("NET_TG_AL : SEND TRANSC ERR udp_sendto : %ld", TR_32(err_log));
            return 1;
        }

        if (rtos_semaphore_wait(my_stream->net_tg_semaphore, 20))
        {   // 20 ms timeout expired without the semaphore becoming available
            // TG send thread has sent a packet without receiving the response
            (my_stream->stats.lost)++;
        }
        // else the response was received
    }

    LOCK_TCPIP_CORE();
    udp_remove(pcb);
    UNLOCK_TCPIP_CORE();

    return 0;
}

int net_tg_send(struct fhost_tg_stream *my_stream)
{
    struct udp_pcb * pcb = NULL;
    net_buf_tx_t *h = NULL;
    net_buf_tx_t *p = NULL;
    char *hdr;
    struct net_tg_send_buf_tag *buf_tag = NULL;
    int status = 0;
    err_t err_log;
    struct fhost_tg_time before, after, actual, init;
    int diff_time;
    u32_t sleep_time = 0;
    u32_t throttled_rate = 0;
    // estimated value : 500 us
    int adj_latency = 500;
    u32_t sec_nl, usec_nl, counter_nl;
    u32_t pack_len = my_stream->prof.pksize;
    int duration;
    // current duration of TG sending process
    int duration_cur = 0;

    if (pack_len > NET_MAX_UDP_LEN)
        pack_len = NET_MAX_UDP_LEN;

    if (my_stream->prof.duration == 0)
        duration = 30 * 1000000;
    else
        duration = my_stream->prof.duration * 1000000;

    if (duration > NET_TG_MAX_SEND_TIME)
    {
        duration = NET_TG_MAX_SEND_TIME;
    }

    pcb = net_tg_init(my_stream, NULL);
    if (pcb == NULL)
    {
        TRACE("NET_TG_AL : SEND ERR udp_new failed");
        return 1;
    }

    my_stream->stats.counter_send = 0;
    // Initialize TG send buffer pool
    net_tg_send_buf_init(my_stream);

    net_sleep_time(my_stream->prof.prof_id, my_stream->prof.rate,
            &sleep_time, &throttled_rate);

    aic_time_get(SINCE_EPOCH, &init.sec, &init.usec);

    while (my_stream->active && duration_cur < duration)
    {
        // At least 1 credit
        if (my_stream->credits > 0)
        {
            // Avoid callback function of pbuf_custom to modify it in the same time
            rtos_mutex_lock(my_stream->tg_mutex);
            // Retrieve a free buffer from buffer pool
            buf_tag = net_tg_find_free_send_buf(my_stream);

            if (buf_tag == NULL)
            {
                TRACE("NET_TG_AL : SEND ERR buf_tag NULL");
                rtos_mutex_unlock(my_stream->tg_mutex);
                return 1;
            }
            // Set the pbuf custom flag on
            h = pbuf_alloced_custom(PBUF_TRANSPORT, NET_TG_HEADER_SIZE, PBUF_RAM,
                    &(buf_tag->h), buf_tag->hdr, NET_TG_HEADER_TOTAL_SIZE);

            p = pbuf_alloced_custom(PBUF_RAW, pack_len - NET_TG_HEADER_SIZE, PBUF_ROM,
                    &(buf_tag->p), net_udp_send_nocopy_buf, pack_len - NET_TG_HEADER_SIZE);
            // Sanity check - If buf_tag is not NULL, then h and p should never be NULL
            ASSERT_ERR((h != NULL) && (p != NULL));

            my_stream->credits--;

            rtos_mutex_unlock(my_stream->tg_mutex);
        } // We have to wait at least one free token if all are used
        else
        {
            rtos_semaphore_wait(my_stream->net_tg_semaphore, -1);
            continue;
        }

        pbuf_cat(h, p);
        hdr = h->payload;

        (my_stream->stats.counter_send)++;

        if (my_stream->stats.counter_send == 1)
        {
            aic_time_get(SINCE_EPOCH, &before.sec, &before.usec);

            before.usec += sleep_time;
            if (before.usec > 1000000)
            {
                before.usec -= 1000000;
                before.sec +=1;
            }
        }

        // Fill in the payload of header by counter and time
        // Convert unsigned int of host format to network format
        counter_nl = co_htonl(my_stream->stats.counter_send);
        // Store unsigned int in the table of char
        memcpy(&hdr[8], &counter_nl, 4);
        aic_time_get(SINCE_EPOCH, &actual.sec, &actual.usec);
        sec_nl = co_htonl(actual.sec);
        usec_nl = co_htonl(actual.usec);
        memcpy(&hdr[12], &sec_nl, 4);
        memcpy(&hdr[16], &usec_nl, 4);

        LOCK_TCPIP_CORE();
        err_log = udp_send(pcb, h);
        UNLOCK_TCPIP_CORE();
        pbuf_free(h);

        // Calculate the current duration of TG sending process
        duration_cur = net_time_diff(&init, &actual);

        if (err_log == ERR_OK)
        {
            (my_stream->stats.tx_frames)++;
            my_stream->stats.tx_bytes += pack_len;
            status = 0;
        }
        else
        {
            TRACE("NET_TG_AL : SEND ERR udp_sendto : %ld", TR_32(err_log));
            status = 1;
            break;
        }

        if (throttled_rate != 0)
        {
            if (my_stream->stats.counter_send % throttled_rate == 0)
            {
                aic_time_get(SINCE_EPOCH, &after.sec, &after.usec);
                diff_time = net_time_diff(&after, &before);
                // It means that the rate is too high (> 2000 pkt/s)
                if (diff_time > adj_latency)
                {
                    // too much time left, go sleep
                    rtos_task_suspend((diff_time - adj_latency) / 1000);
                }

                before.usec += sleep_time;
                if (before.usec > 1000000)
                {
                    before.usec -= 1000000;
                    before.sec +=1;
                }
            }
        } // otherwise, it floods
    }
    // Wait until all of pbuf are freed
    while (my_stream->credits < FHOST_TG_SEND_BUF_CNT)
    {
        rtos_semaphore_wait(my_stream->net_tg_semaphore, -1);
    }

    my_stream->stats.throughput = net_cal_throughput(&init, &actual,
            (my_stream->stats.tx_bytes));

    LOCK_TCPIP_CORE();
    udp_remove(pcb);
    UNLOCK_TCPIP_CORE();

    return status;
}

int net_tg_recv_start(struct fhost_tg_stream *my_stream)
{
    if (net_tg_init(my_stream, net_tg_recv_cb) == NULL)
        return 1;
    else
        return 0;
}

int net_tg_recv_transc_start(struct fhost_tg_stream *my_stream)
{
    if (net_tg_init(my_stream, net_tg_recv_transc_cb) == NULL)
        return 1;
    else
        return 0;
}

void net_tg_recv_stop(struct fhost_tg_stream *my_stream)
{
    LOCK_TCPIP_CORE();
    udp_remove(my_stream->arg);
    UNLOCK_TCPIP_CORE();
}
#endif // NX_TG

#if PLF_PING
int net_ping_send(struct fhost_ping_stream *my_stream)
{
    struct raw_pcb * pcb = NULL;
    net_buf_tx_t *p = NULL;
    struct icmp_echo_hdr *iecho;
    // Duration unit : microseconds
    int duration;
    err_t err_log;
    u32_t sleep_time = 0;
    size_t pack_len;

    // Set configuration information to default value if it's 0
    if (my_stream->prof.pksize == 0 ||
            my_stream->prof.pksize < NET_TG_PING_HDR_LEN + NET_TG_PING_TIMESTAMP_LEN)
        pack_len = 100;
    else
        pack_len = my_stream->prof.pksize;

    if (my_stream->prof.duration == 0)
        duration = 30 * 1000000;
    else
        duration = my_stream->prof.duration * 1000000;

    if (my_stream->prof.rate == 0)
        my_stream->prof.rate = 1;

    if (pack_len > NET_MAX_PING_LEN)
    {
        pack_len = NET_MAX_PING_LEN;
    }
    if (duration > NET_TG_MAX_PING_TIME)
    {
        duration = NET_TG_MAX_PING_TIME;
    }

    pcb = net_ping_init(my_stream, (raw_recv_fn)net_ping_recv_cb);
    if (pcb == NULL)
    {
        TRACE("NET_TG_AL : SEND PING ERR pcb null");
        return 1;
    }

    // Initialize the ping sequence number and RTT
    my_stream->ping_seq_num = 0;
    my_stream->stats.rt_time = 0;

    net_sleep_time(FHOST_PROF_PING, my_stream->prof.rate,
            &sleep_time, NULL);

    while (my_stream->active && duration > 0)
    {
        p = pbuf_alloc(PBUF_IP, (u16_t)pack_len, PBUF_RAM);
        if (p == NULL)
        {
            TRACE("NET_TG_AL : SEND PING ERR p null");
            return 1;
        }

        if ((p->len == p->tot_len) && (p->next == NULL))
        {
            iecho = (struct icmp_echo_hdr *)p->payload;
            // Configure ICMP ECHO packet before sending it
            net_ping_prepare_echo(iecho, (u16_t)pack_len, my_stream);

            LOCK_TCPIP_CORE();
            err_log = raw_send(pcb, p);
            UNLOCK_TCPIP_CORE();

            pbuf_free(p);

            if (err_log == ERR_OK)
            {
                (my_stream->stats.tx_frames)++;
                my_stream->stats.tx_bytes += pack_len;
            }

            #if NX_CSI
            csi_start();
            #endif /* NX_CSI */
        }

        // Update the remaining time
        duration -= sleep_time;
        rtos_task_suspend(sleep_time / 1000);
    }

    // If no ICMP ECHO response, we set RTT to -1
    if (my_stream->stats.rt_time == 0 || my_stream->stats.rx_frames == 0)
        my_stream->stats.rt_time = -1;
    else
        my_stream->stats.rt_time /= my_stream->stats.rx_frames;

    LOCK_TCPIP_CORE();
    raw_remove(pcb);
    UNLOCK_TCPIP_CORE();

    return 0;
}
#endif /* PLF_PING */
