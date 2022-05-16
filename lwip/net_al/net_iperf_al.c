/**
 ****************************************************************************************
 *
 * @file net_iperf_al.c
 *
 * @brief Definition of the networking stack abstraction layer used for iperf.
 *
 * Copyright (C) RivieraWaves 2017-2018
 *
 ****************************************************************************************
 */

/*
 * INCLUDE FILES
 ****************************************************************************************
 */

#include "lwip/tcp.h"
#include "lwip/udp.h"
#include "lwip/sys.h"
#include "lwip/opt.h"
#include "lwip/ip_addr.h"
#include "lwip/raw.h"
#include "lwip/icmp.h"
#include "lwip/igmp.h"
#include "lwip/inet_chksum.h"

#include "fhost.h"
#include "fhost_iperf.h"
#include "net_iperf_al.h"
#include "co_endian.h"
#include "time_api.h"
#include "lwip/etharp.h"

#if PLF_IPERF

/*
 * DEFINITIONS
 ****************************************************************************************
 */
/// IPERF buffer len for TCP and UDP transfers
#define IPERF_BUFFER_LEN 1500 - UDP_HLEN - IP_HLEN

#define IPERF_UDP_BURST_WAIT_MS       10
/// IPERF frame header size
#define NET_IPERF_HEADER_SIZE         20
/// IPERF frame total header size
#define NET_IPERF_HEADER_TOTAL_SIZE   LWIP_MEM_ALIGN_SIZE( \
        NET_IPERF_HEADER_SIZE + PBUF_LINK_ENCAPSULATION_HLEN + PBUF_LINK_HLEN + \
        PBUF_IP_HLEN + PBUF_TRANSPORT_HLEN)
/// ARP reply message timeout  (in milliseconds)
#if (PLF_HW_PXP == 1)
#define ARP_REPLY_TO                  50 // 500ms
#else /* PLF_HW_PXP */
#define ARP_REPLY_TO                  500
#endif /* PLF_HW_PXP */
/// IPERF maximum number of polling attempts before closing TCP connection
#define IPERF_TCP_MAX_IDLE_SEC        10

/* IPERF version (2.0.9)*/
/// Iperf Major version (version 2)
#define IPERF_HDR_VER_MAJORHEX 0x00020000
/// Iperf Minor version (version 0.9)
#define IPERF_HDR_VER_MINORHEX 0x000D0000

/// IPERF Client/Server header mask definitions
/// IPERF Header extend type mask
#define IPERF_HDR_EXTEND_TYPE  0x1
/// IPERF Header version 1 mask
#define IPERF_HDR_VER1         0x80000000
/// IPERF Header extend mask
#define IPERF_HDR_EXTEND       0x40000000
/// IPERF Header udp tests mask
#define IPERF_HDR_UDPTESTS     0x20000000
/// IPERF Header timestamp mask
#define IPERF_HDR_TIMESTAMP    0x10000000
/// IPERF Header run now mask
#define IPERF_HDR_RUN_NOW      0x00000001


/// Stateless UDP Client Header (without handshake)
/// This is used for UDP tests that don't require
/// any handshake, i.e they are stateless
struct client_hdr_udp_tests {
    uint16_t testflags;
    uint16_t tlvoffset;
    uint32_t version_u;
    uint32_t version_l;
};

/// Extended UDP Client Header (with handshake)
/// This is used for tests that require
/// the initial handshake
struct client_hdrext {
    uint32_t type;
    uint32_t len;
    uint32_t flags;
    uint32_t version_u;
    uint32_t version_l;
    uint32_t reserved;
    uint32_t rate;
    uint32_t DP_rate_units;
    uint32_t real_time;
};

/// UDP server report
struct server_hdr
{
    uint32_t flags;
    uint32_t total_len1;
    uint32_t total_len2;
    uint32_t stop_sec;
    uint32_t stop_usec;
    uint32_t error_cnt;
    uint32_t outorder_cnt;
    uint32_t datagrams;
    uint32_t jitter1;
    uint32_t jitter2;
};

/// TCP Client Header Base (version 1)
struct client_hdr_v1
{
    uint32_t flags;
    uint32_t num_threads;
    uint32_t port;
    uint32_t bufferlen;
    uint32_t win_band;
    uint32_t amount;
};

/// Top TCP Client Header
struct client_hdr
{
    struct client_hdr_v1 base;
    union {
        struct client_hdrext extend;
        struct client_hdr_udp_tests udp;
    };
};

/// Structure containing the information about the IPERF sending buffer
struct net_iperf_send_info
{
    /// Pointer to IPERF stream
    struct fhost_iperf_stream *stream;
    /// Flag to describe if this buffer is occupied : 1 for occupied, 0 for free
    int flag;
};

/// IPERF sending process environment structure
struct net_iperf_send_buf_tag
{
    /// Network stack buffer element for IPERF payload
    struct pbuf_custom p;
    /// Structure containing the information about the IPERF sending buffer
    struct net_iperf_send_info info;
    /// Network stack buffer element for TG header
    struct pbuf_custom h;
    /// IPERF payload
    char hdr[NET_IPERF_HEADER_TOTAL_SIZE];
};

/// IPERF TCP States
enum net_iperf_tcp_states
{
    IPERF_TCP_NONE = 0,
    IPERF_TCP_ACCEPTED,
    IPERF_TCP_RCV_HDR,
    IPERF_TCP_RECEIVED
};

/// IPERF TCP connection info
struct net_iperf_tcp_info
{
    /// Current state
    u8_t state;
    /// Polling counter
    u8_t poll_count;
    /// Client hdr length
    u8_t client_hdr_len;
    /// Pointer to TCP connection pcb
    struct tcp_pcb *pcb;
    /// Client header
    struct client_hdr client_hdr;
};

/*
 * GLOBAL VARIABLES
 ****************************************************************************************
 */
/// Payload to send (no copy memory) which is pointed by pbuf->payload
static char net_iperf_nocopy_buf[IPERF_BUFFER_LEN] __SHAREDRAM;
/// Pool of IPERF send buffers
static struct net_iperf_send_buf_tag
net_iperf_send_buf_mem[FHOST_IPERF_MAX_STREAMS][FHOST_IPERF_SEND_BUF_CNT] __SHAREDRAM;

struct fhost_iperf_settings;

/*
 * FUNCTIONS
 ****************************************************************************************
 */
static err_t net_iperf_tcp_server_accept(void * arg, struct tcp_pcb *newpcb, err_t err);

/**
 ****************************************************************************************
 * @brief Callback function called when we free the pbuf_custom of IPERF header
 * Currently it does nothing.
 *
 * @param[in] p              pointer to a pbuf_custom buffer to free
 ****************************************************************************************
 **/
static void net_iperf_pbuf_custom_header_free_cb(void *p)
{
}

/**
 ****************************************************************************************
 * @brief Callback function called when we free the pbuf_custom of IPERF UDP payload
 * It increases credit and set flag to 0.
 *
 * @param[in] p              pointer to a pbuf_custom buffer to free
 ****************************************************************************************
 **/
static void net_iperf_pbuf_custom_payload_free_cb(void *p)
{
    struct net_iperf_send_buf_tag *buf = p;
    struct fhost_iperf_stream *stream = buf->info.stream;
    // Avoid sending process to modify it in the same time
    rtos_mutex_lock(stream->iperf_mutex, -1);
    buf->info.flag = 0;
    rtos_mutex_unlock(stream->iperf_mutex);
    // Send a signal to sending process that we have a new credit
    rtos_semaphore_signal(stream->send_buf_semaphore, false);
}

/**
 ****************************************************************************************
 * @brief Print initial header for TCP/UDP Client and Server
 *
 * @param[in] iperf_settings   Pointer to iperf settings
 ****************************************************************************************
 **/
static void net_iperf_print_header(const struct fhost_iperf_settings *iperf_settings)
{
    dbg( "------------------------------------------------------------\n");
    if (iperf_settings->flags.is_server)
    {
        net_if_t *n = &(fhost_env.vif[0].net_if);
        uint32_t ip;

        if (iperf_settings->flags.is_udp)
        {
            dbg( "Server listening on UDP port %d\n",
                    iperf_settings->port);
        }
        else
        {
            dbg( "Server listening on TCP port %d\n",
                    iperf_settings->port);
        }
        // Bind Server IP address and port to pcb
        net_if_get_ip(n, &ip, NULL, NULL);

        dbg( "IP address : %d.%d.%d.%d\n",
                ip & 0xff, (ip >> 8) & 0xff, (ip >> 16) & 0xff, (ip >> 24) & 0xff);
    }
    else
    {
        if (iperf_settings->flags.is_udp)
        {
            dbg( "Client connecting to %s, UDP port %d\n",
                        inet_ntoa(iperf_settings->host_ip), iperf_settings->port);
        }
        else
        {
            dbg( "Client connecting to %s, TCP port %d\n",
                        inet_ntoa(iperf_settings->host_ip), iperf_settings->port);
        }

        dbg( "Sending %d byte datagrams\n", iperf_settings->buf_len);
    }

    dbg( "------------------------------------------------------------\n");
}

/**
 ****************************************************************************************
 * @brief Initialize iperf buffers
 *
 * @param[in] stream   Pointer to iperf stream
 ****************************************************************************************
 **/
static void net_iperf_buf_init(struct fhost_iperf_stream* stream)
{
    uint32_t i, j, k;

    i = stream->id;
    memset(net_iperf_send_buf_mem[i], 0, sizeof(struct net_iperf_send_buf_tag)
            * FHOST_IPERF_SEND_BUF_CNT);
    for (j = 0; j < FHOST_IPERF_SEND_BUF_CNT; j++)
    {
        // Initialize callback function for its pbuf custom
        net_iperf_send_buf_mem[i][j].h.custom_free_function =
                (pbuf_free_custom_fn)net_iperf_pbuf_custom_header_free_cb;
        // Initialize callback function for its pbuf custom
        net_iperf_send_buf_mem[i][j].p.custom_free_function =
                (pbuf_free_custom_fn)net_iperf_pbuf_custom_payload_free_cb;
        // Pointer to IPERF stream
        net_iperf_send_buf_mem[i][j].info.stream = stream;
    }

    // Initialize constant buffer
    for (k = 0; k < sizeof(net_iperf_nocopy_buf); k++)
        {
        net_iperf_nocopy_buf[k] = 0x30 + k % 10;
    }
}

/**
 ****************************************************************************************
 * @brief Look for a free iperf buffer, set its flag to 1 and return it
 *
 * @param[in] stream   Pointer to iperf stream
 * @return  free iperf buffer, NULL if there is none
 ****************************************************************************************
 **/
static struct net_iperf_send_buf_tag *net_iperf_find_free_send_buf(const struct fhost_iperf_stream *stream,
                                                                   int to_time_ms)
{
    int i, j;

    i = stream->id;

    if (rtos_semaphore_wait(stream->send_buf_semaphore, to_time_ms))
    {
        //timeout
        return NULL;
    }

    // Protect net_iperf_send_buf_mem
    rtos_mutex_lock(stream->iperf_mutex, -1);
    for (j = 0; j < FHOST_IPERF_SEND_BUF_CNT; j++)
    {
        if((net_iperf_send_buf_mem[i][j]).info.flag == 0)
        {
            (net_iperf_send_buf_mem[i][j]).info.flag = 1;
            rtos_mutex_unlock(stream->iperf_mutex);
            return &net_iperf_send_buf_mem[i][j];
        }
    }
    rtos_mutex_unlock(stream->iperf_mutex);

    return NULL;
}

/**
 ****************************************************************************************
 * @brief Handle UDP packet and update statistics.
 *
 * @param[in] stream         Pointer to iperf stream
 * @param[in] udp_datagram   Pointer to UDP datagram
 * @return ERR_OK if successful
 ****************************************************************************************
 **/
static err_t net_iperf_udp_handle_packet(struct fhost_iperf_stream* stream,
                                       struct iperf_UDP_datagram* udp_datagram)
{
    struct iperf_report *report;
    int packet_id = co_ntohl(udp_datagram->id);

    report = &stream->report;
    report->stats.nb_datagrams++;
    report->sent_time.sec = co_ntohl(udp_datagram->sec);
    report->sent_time.usec = co_ntohl(udp_datagram->usec);
    if (packet_id < 0)
    {
        //For UDP server, set packet id as positive
        packet_id = -packet_id;
    }

    if (packet_id != 0)
    {
        struct iperf_time transit, delta_transit;
        int delta_transit_us;
        /* Compute jitter
        // from RFC 1889, Real Time Protocol (RTP)
        // J = J + ( | D(i-1,i) | - J ) / 16 */

        // Check if RX time < TX time. The client's and server's clocks do not need to be synchronized
        if (iperf_timerbefore(&report->sent_time, &report->packet_time))
            iperf_timersub(&report->packet_time, &report->sent_time, &transit);
        else
            iperf_timersub(&report->sent_time, &report->packet_time, &transit);

        if ( report->last_transit.sec != 0 || report->last_transit.usec != 0 ) {
            if (iperf_timerbefore(&transit, &report->last_transit))
                iperf_timersub(&report->last_transit, &transit, &delta_transit);
            else
                iperf_timersub(&transit, &report->last_transit, &delta_transit);

            delta_transit_us = iperf_timerusec(&delta_transit);
            report->stats.jitter_us += (int)(delta_transit_us - report->stats.jitter_us) / 16;
        }
        report->last_transit = transit;

        //Check for packet loss (expected packet ID + 1 != RX packet ID)
        if (packet_id != report->packet_id + 1) {
            if (packet_id < report->packet_id + 1) {
                // If RX packet ID < expected packet ID + 1, then,
                // in the past, we received a packet with ID > expected packet ID
                report->stats.nb_out_of_orded++;
            }
            else
            {
                // If RX packet ID > expected packet ID, then missing packets might have been
                // lost, or will be received in the future (out-of-order).
                report->stats.nb_error += packet_id - report->packet_id - 1;
            }
        }

        //Update expected packet ID every time RX packet ID is greater than expected packet ID
        if (packet_id > report->packet_id)
            report->packet_id = packet_id;
    }
    else
    {
        //Error
        TRACE("Error Packet ID == 0");
        return ERR_VAL;
    }
    return ERR_OK;
}

void net_iperf_tcp_close(struct fhost_iperf_stream *stream)
{
    struct iperf_time now;
    struct iperf_time zero_time = {.sec = 0, .usec = 0};
    struct net_iperf_tcp_info *info = (struct net_iperf_tcp_info*) stream->arg;
    struct iperf_report *report = (struct iperf_report *) &(stream->report);

    if (stream->arg == NULL)
        goto end;

    tcp_arg(info->pcb, NULL);
    tcp_sent(info->pcb, NULL);
    tcp_recv(info->pcb, NULL);
    tcp_poll(info->pcb, NULL, 0);
    tcp_err(info->pcb, NULL);
    if (tcp_close(info->pcb) != ERR_OK)
    {
        tcp_abort(info->pcb);
    }

    aic_time_get(SINCE_EPOCH, &now.sec, &now.usec);
    iperf_timersub(&now, &report->start_time, &report->end_time);
    if (!report->last_stats.bytes)
    {
        dbg("[ ID]  Interval      Transfer     Bandwidth\n");
    }

    //Print final stats
    fhost_iperf_print_stats(stream, &zero_time, &report->end_time, &report->stats);

    //Delete tcp info
    info->pcb = NULL;
    rtos_free(info);
    stream->arg = NULL;

  end:
    if (!stream->iperf_settings.flags.is_server || !stream->active)
    {
        // Wakeup IPERF task
        rtos_semaphore_signal(stream->iperf_task_semaphore, false);
    }
}

/**
 ****************************************************************************************
 * @brief Error callback, iperf tcp session aborted
 *
 * @param[in] arg       Pointer to iperf stream
 * @param[in] err       Error value
 ****************************************************************************************
 **/
static void net_iperf_tcp_err(void *arg, err_t err)
{
    struct fhost_iperf_stream *stream = (struct fhost_iperf_stream *) arg;

    dbg("Abort TCP (error %d)\n", err);
    net_iperf_tcp_close(stream);
}

/**
 ****************************************************************************************
 * @brief Write TCP/UDP client header to a buffer
 *
 * @param[in] hdr       Pointer to client header
 * @param[in] settings  Pointer to iperf settings
 * @return Client Header flags field
 ****************************************************************************************
 **/
static uint32_t net_iperf_write_hdr(struct client_hdr *hdr, struct fhost_iperf_settings *settings)
{
    uint32_t flags = 0;
    struct fhost_iperf_flags *settings_flags = &settings->flags;
    if (settings_flags->is_peer_ver ||
       (settings->test_mode != FHOST_IPERF_TEST_NORMAL && settings_flags->is_bw_set))
    {
        flags |= IPERF_HDR_EXTEND;
    }
    if (settings->test_mode != FHOST_IPERF_TEST_NORMAL)
    {
        flags |= IPERF_HDR_VER1;

        // Set buffer len
        if (settings_flags->is_buf_len_set)
        {
            hdr->base.bufferlen = co_htonl(settings->buf_len);
        }
        else
        {
            hdr->base.bufferlen = 0;
        }

        // Set port
        if (settings->listen_port != 0)
        {
            hdr->base.port = co_htonl(settings->listen_port);
        }
        else
        {
            hdr->base.port = co_htonl(settings->port);
        }

        //Single thread
        hdr->base.num_threads = co_htonl(1);

        // Set amount
        if(settings_flags->is_time_mode)
        {
            hdr->base.amount = co_htonl(-(long) settings->amount);
        }
        else
        {
            hdr->base.amount = co_htonl((long) settings->amount);
            hdr->base.amount &= co_htonl(0x7FFFFFFF);
        }

        if (settings->test_mode == FHOST_IPERF_TEST_DUALTEST)
        {
            flags |= IPERF_HDR_RUN_NOW;
        }
    }

    if (settings_flags->is_udp)
    {
        TRACE("TODO: missing write hdr for UDP");
    }

    //Update header flags
    hdr->base.flags = co_htonl(flags);

    if (flags & IPERF_HDR_EXTEND)
    {
        TRACE("EXTEND");

        if (settings_flags->is_bw_set)
        {
            hdr->extend.rate = co_htonl(settings->udprate);
        }
        //TODO: Add PPS

        hdr->extend.type = co_htonl(IPERF_HDR_EXTEND_TYPE);
        hdr->extend.len = co_htonl(
                (sizeof(struct client_hdrext) - sizeof(hdr->extend.type) - sizeof(hdr->extend.len)));
        hdr->extend.reserved = 0;
        hdr->extend.version_u = co_htonl(IPERF_HDR_VER_MAJORHEX);
        hdr->extend.version_l = co_htonl(IPERF_HDR_VER_MINORHEX);
        hdr->extend.flags = co_htonl(0);
    }

    return flags;
}

/**
 ****************************************************************************************
 * @brief Read TCP client header
 *
 * @param[in] p         Packet buffer to read header from
 * @param[in] stream    Pointer to iperf stream
 * @return ERR_OK if successful
 ****************************************************************************************
 **/
static err_t net_iperf_tcp_read_client_hdr(struct pbuf *p, struct fhost_iperf_stream* stream)
{
    struct net_iperf_tcp_info *info = (struct net_iperf_tcp_info*) stream->arg;
    uint32_t *flags = &info->client_hdr.base.flags;
    err_t ret = ERR_OK;

    //Check if flags have been already received
    if (info->client_hdr_len <= sizeof(info->client_hdr.base.flags))
    {
        if (pbuf_copy_partial(p, flags, sizeof(info->client_hdr.base.flags), 0)
                    != sizeof(info->client_hdr.base.flags))
        {
            dbg("TCP RX: too short packet (%d < %d)\n",
                        p->tot_len, sizeof(struct client_hdr_v1));
            //net_iperf_tcp_close(stream);
            //pbuf_free(p);
            ret = ERR_VAL;
            goto end;
        }

        *flags = co_ntohl(*flags);
        info->client_hdr_len = sizeof(struct client_hdr_v1);
        if ((*flags & IPERF_HDR_EXTEND) != 0)
        {
            dbg("TODO: Header extended\n");
            info->client_hdr_len  = sizeof(struct client_hdr);
        }
        else if ((*flags & IPERF_HDR_VER1) != 0)
        {
            dbg("TODO: Header version 1 => Client requested parallel transmission test\n");
            info->client_hdr_len = sizeof(struct client_hdr_v1);
        }
        else if ((*flags & IPERF_HDR_TIMESTAMP) != 0)
        {
            dbg("TODO: Timestamp Client header\n");
            ret = ERR_VAL;
            goto end;
        }
    }

    // Flags already received, check if client hdr has been received
    if (pbuf_copy_partial(p, &info->client_hdr, info->client_hdr_len, 0)
            != info->client_hdr_len)
    {
        //net_iperf_tcp_close(stream);
        //pbuf_free(p);
        ret = ERR_VAL;
        goto end;
    }

    if ((*flags & IPERF_HDR_EXTEND) != 0)
    {
        dbg("Extended Client HDR => require an ACK back to the client");
        //net_iperf_tcp_close(stream);
        //pbuf_free(p);
        ret = ERR_VAL;
        goto end;
    }
end:
    return ret;
}

/**
 ****************************************************************************************
 * @brief TCP packet reception callback
 *
 * @param[in] arg       Pointer to iperf stream
 * @param[in] newpcb    Pointer to TCP Protocol Process Block
 * @param[in] p         Received packet buffer
 * @param[in] err       different from ERR_OK if error occurred
 * @return ERR_OK if successful
 ****************************************************************************************
 **/
static err_t net_iperf_tcp_recv_cb(void * arg, struct tcp_pcb *newpcb,
                                   struct pbuf *p, err_t err)
{
    struct fhost_iperf_stream *stream = (struct fhost_iperf_stream*) arg;
    struct net_iperf_tcp_info *info = (struct net_iperf_tcp_info*) stream->arg;
    struct iperf_stats interval_stats;
    struct iperf_report *report = &stream->report;
    struct fhost_iperf_settings *iperf_settings = &stream->iperf_settings;
    struct iperf_time start_interval, end_interval;
    err_t ret = ERR_OK;

    if (err != ERR_OK || !stream->active)
    {
        net_iperf_tcp_close(stream);
        ret = ERR_OK;
        goto end;
    }

    // We receive an empty frame from client=> close connection
    if (p == NULL)
    {
        //TODO: Client requested transmission after end of test
        net_iperf_tcp_close(stream);
        return ERR_OK;
    }
    aic_time_get(SINCE_EPOCH, &report->packet_time.sec, &report->packet_time.usec);

    info->poll_count = 0;
    report->stats.bytes += p->tot_len;

    // If waiting for TCP settings or TX bytes multiple of 128KBytes
    if (info->state == IPERF_TCP_ACCEPTED)
    {
        if (net_iperf_tcp_read_client_hdr(p, stream) != ERR_OK)
        {
            net_iperf_tcp_close(stream);
            ret = ERR_VAL;
            goto end;
        }
        info->state = IPERF_TCP_RECEIVED;
        report->start_time = report->packet_time;
        if (iperf_settings->interval.sec != 0 || iperf_settings->interval.usec != 0)
        {
            iperf_timeradd(&report->start_time, &iperf_settings->interval, &report->interval_target);
            report->last_interval = report->start_time;
        }
    }

    // Interval
    if (iperf_settings->interval.sec > 0 || iperf_settings->interval.usec > 0)
    {
        if (!iperf_timerbefore(&report->packet_time, &report->interval_target))
        {
            if (!report->last_stats.bytes)
            {
                dbg("[ ID]  Interval      Transfer     Bandwidth\n");
            }

            iperf_timersub(&report->last_interval, &report->start_time, &start_interval);
            iperf_timersub(&report->packet_time, &report->start_time, &end_interval);
            interval_stats.bytes = report->stats.bytes - report->last_stats.bytes;
            fhost_iperf_print_stats(stream, &start_interval, &end_interval, &interval_stats);
            report->last_stats = report->stats;
            report->last_interval = report->packet_time;
            iperf_timeradd(&iperf_settings->interval, &report->interval_target, &report->interval_target);
        }
    }

    // Acknowledgement
    tcp_recved(newpcb, p->tot_len);
end:
    pbuf_free(p);
    return ret;
}

/**
 ****************************************************************************************
 * @brief Send data on an iperf tcp session
 *
 * @param[in] pcb       Pointer to tcp Protocol Control Block
 * @param[in] stream    Pointer to iperf stream
 * @param[in] settings  Pointer to iperf settings
 ****************************************************************************************
 **/
static void net_iperf_tcp_send(struct tcp_pcb* pcb,
                                struct fhost_iperf_stream *stream,
                                struct fhost_iperf_settings* iperf_settings)
{
    struct iperf_report *report = (struct iperf_report *) &stream->report;
    struct iperf_time packet_time, start_interval, end_interval, interval_tmp;
    struct iperf_stats interval_stats;
    u8_t write_more;
    u32_t len;
    err_t err;

    do
    {
        write_more = 1;
        aic_time_get(SINCE_EPOCH, &packet_time.sec, &packet_time.usec);
        if (iperf_settings->flags.is_time_mode)
        {
            // Time limited
            if(!iperf_timerbefore(&packet_time, &report->end_time))
            {
                // time specified by the client is over -> close the connection
                net_iperf_tcp_close(stream);
                return;
            }
        }
        else
        {
            // Amount limited
            if (iperf_settings->amount <= report->stats.bytes)
            {
                net_iperf_tcp_close(stream);
                return;
            }
        }

        LWIP_ASSERT("TCP_MSS > buffer size", TCP_MSS <= IPERF_BUFFER_LEN);
        // Set the pbuf custom flag on
        len = TCP_MSS;

        do
        {
            // Queue data for sending
            err = tcp_write(pcb, net_iperf_nocopy_buf, len, 0);
            if (err == ERR_MEM)
            {
                len /= 2;
            }
        } while ((err == ERR_MEM) && (len >= (TCP_MSS / 2)));

        if (err == ERR_OK)
        {
            // Keep sending data
            report->stats.bytes += len;
        }
        else
        {
            write_more = 0;
        }

        // Interval
        if (iperf_settings->interval.sec > 0 || iperf_settings->interval.usec > 0)
        {
            if (!iperf_timerbefore(&packet_time, &report->interval_target)) {
                if (!report->last_stats.bytes)
                    dbg("[ ID] Interval       Transfer     Bandwidth\n");
                iperf_timersub(&report->last_interval, &report->start_time, &start_interval);
                iperf_timersub(&packet_time, &report->start_time, &end_interval);
                interval_stats.bytes = report->stats.bytes - report->last_stats.bytes;
                fhost_iperf_print_stats(stream, &start_interval, &end_interval, &interval_stats);
                report->last_stats = report->stats;
                report->last_interval = packet_time;
                iperf_timeradd(&report->interval_target, &iperf_settings->interval, &interval_tmp);
                report->interval_target = interval_tmp;
            }
        }
    } while(write_more);

    tcp_output(pcb);
}

/**
 ****************************************************************************************
 * @brief TCP polling callback. This function is called after a certain period of inactivity.
 * Use @ref tcp_poll to register this callback function.
 *
 * @param[in] arg       Pointer to iperf stream
 * @param[in] pcb       Pointer to TCP Protocol Control Block
 *
 * @return  ERR_OK if successful
 ****************************************************************************************
 **/
static err_t net_iperf_tcp_poll(void *arg, struct tcp_pcb *pcb)
{
    struct fhost_iperf_stream *stream = (struct fhost_iperf_stream *) arg;
    struct net_iperf_tcp_info *info = (struct net_iperf_tcp_info*) stream->arg;

    // Maynot connected
    if(!info)
    {
        dbg("TCP not connect yet.\r\n");
        return ERR_OK;
    }

    if (++info->poll_count >= IPERF_TCP_MAX_IDLE_SEC)
    {
        // Close TCP connection
        net_iperf_tcp_close(stream);
        return ERR_OK;
    }

    // Send more data if we are client
    if (!stream->iperf_settings.flags.is_server)
    {
        net_iperf_tcp_send(pcb, stream, &stream->iperf_settings);
    }
    return ERR_OK;
}

/**
 ****************************************************************************************
 * @brief TCP connection acceptance callback. This function is called while listening on a
 * TCP port to accept a connection to a client.
 * Use @ref tcp_accept to register this callback function.
 *
 * @param[in] arg       Pointer to iperf stream
 * @param[in] newpcb    Pointer to TCP Protocol Control Block
 * @param[in] err       different from ERR_OK if error occurred
 * @return  ERR_OK if successful
 ****************************************************************************************
 **/
static err_t net_iperf_tcp_server_accept(void * arg, struct tcp_pcb *newpcb, err_t err)
{
    struct net_iperf_tcp_info *info;
    struct fhost_iperf_stream *stream = (struct fhost_iperf_stream *) arg;
    err_t ret = ERR_OK;

    if ((err != ERR_OK) || (newpcb == NULL) || (arg == NULL))
    {
        return ERR_VAL;
    }

    if(stream->arg)
    {
        return ERR_VAL;
    }

    tcp_setprio(newpcb, TCP_PRIO_MIN);

    // Create stream TCP info
    info = rtos_malloc(sizeof(struct net_iperf_tcp_info));

    if (info == NULL)
    {
        return ERR_MEM;
    }

    memset(info, 0, sizeof(struct net_iperf_tcp_info));
    info->state = IPERF_TCP_ACCEPTED;
    info->pcb = newpcb;
    stream->arg = info;
    memset(&stream->report, 0, sizeof(struct iperf_report));

    // Set stream as argument for TCP callbacks
    tcp_arg(newpcb, arg);

    // Initialize tcp_recv callback function
    tcp_recv(newpcb, net_iperf_tcp_recv_cb);

    // Initialize tcp_err callback function
    tcp_err(newpcb, net_iperf_tcp_err);

    // Initialize tcp_poll callback function (called every two seconds of inactivity of the TCP connection)
    tcp_poll(newpcb, net_iperf_tcp_poll, 2U);

    return ret;
}

/**
 ****************************************************************************************
 * @brief TCP connected callback.  This function is called when the connection to a TCP server
 * is enstablished. Start sending data.
 * Use @ref tcp_connect to register this callback function.
 *
 * @param[in] arg       Pointer to stream
 * @param[in] pcb       Pointer to TCP Protocol Control Block
 * @param[in] err       Different from ERR_OK if error occurred
 * @return  ERR_OK if successful
 ****************************************************************************************
 **/
static err_t net_iperf_tcp_client_connected(void *arg, struct tcp_pcb *pcb,
        err_t err)
{
    struct fhost_iperf_stream *stream = (struct fhost_iperf_stream *) arg;
    struct iperf_report *report = (struct iperf_report *) &stream->report;
    struct net_iperf_tcp_info *info;
    int flags;

    if ((err != ERR_OK) || (pcb == NULL))
    {
        return ERR_VAL;
    }

    // Create stream TCP info
    info = rtos_malloc(sizeof(struct net_iperf_tcp_info));

    if (info == NULL)
    {
        return ERR_MEM;
    }

    memset(info, 0, sizeof(struct net_iperf_tcp_info));
    info->state = IPERF_TCP_ACCEPTED;
    info->pcb = pcb;
    stream->arg = info;

    flags = net_iperf_write_hdr(&info->client_hdr, &stream->iperf_settings);

    if (flags & IPERF_HDR_EXTEND)
    {
        info->state = IPERF_TCP_RCV_HDR;
    }
    // Send TCP client header message
    err = tcp_write(pcb, &info->client_hdr, sizeof(struct client_hdr), TCP_WRITE_FLAG_COPY);
    LWIP_ASSERT("impossible to send client header", err == ERR_OK);
    tcp_output(pcb);

    aic_time_get(SINCE_EPOCH, &report->start_time.sec, &report->start_time.usec);
    if (stream->iperf_settings.flags.is_time_mode)
    {
        struct iperf_time elapse;
        elapse.sec = (uint32_t) stream->iperf_settings.amount / 10;
        elapse.usec = (uint32_t) 100000 * (stream->iperf_settings.amount - (elapse.sec * 10));
        iperf_timeradd(&report->start_time, &elapse, &report->end_time);
    }

    iperf_timeradd(&report->start_time, &stream->iperf_settings.interval, &report->interval_target);
    report->last_interval = report->start_time;

    return ERR_OK;
}

/**
 ****************************************************************************************
 * @brief TCP data sent callback. This function is called when TCP data
 * has been successfully delivered to the remote host. Send more data
 * Use @ref tcp_sent to register this callback function.
 *
 * @param[in] arg       Pointer to iperf stream
 * @param[in] pcb       Pointer to Process Control Block for which data has been acknowledged
 * @param[in] len       amount of bytes acknowledged
 * @return  ERR_OK if successful
 ****************************************************************************************
 **/
static err_t net_iperf_tcp_sent(void *arg, struct tcp_pcb *pcb, u16_t len)
{
    struct fhost_iperf_stream *stream = (struct fhost_iperf_stream *) arg;
    struct net_iperf_tcp_info *info = (struct net_iperf_tcp_info*) stream->arg;

    info->poll_count = 0;
    net_iperf_tcp_send(pcb, stream, &stream->iperf_settings);
    return ERR_OK;
}

/**
 ****************************************************************************************
 * @brief UDP Server Report reception callback.
 *
 * @param[in] arg       Pointer to iperf stream
 * @param[in] pcb       Pointer to UDP Process Control Block
 * @param[in] p         Pointer to packet buffer containing server report
 * @param[in] addr      Pointer to Server IP address
 * @param[in] port      Server connected port
 ****************************************************************************************
 **/
static void net_iperf_udp_server_report_recv(void *arg, struct udp_pcb *pcb, struct pbuf *p,
                                             const ip_addr_t *addr, u16_t port)
{
    struct iperf_time now;
    struct fhost_iperf_stream* stream = (struct fhost_iperf_stream*) arg;
    aic_time_get(SINCE_EPOCH, &now.sec, &now.usec);

    if (p != NULL)
    {
        udp_recv(pcb, NULL, NULL);
        if ( p->tot_len >= (int32_t) (sizeof(struct iperf_UDP_datagram) +
                                      sizeof(struct server_hdr)) )
        {
            struct iperf_stats stats;
            struct iperf_time start_time, end_time;
            struct server_hdr* hdr = (struct server_hdr*) ((struct iperf_UDP_datagram*)p->payload + 1);
            struct server_hdr hdr_data;

            if ( !(co_ntohl(hdr->flags) & IPERF_HDR_VER1) )
            {
                TRACE("NET_IPERF_AL: iperf server report version not supported");
                return;
            }

            if ((unsigned int)hdr & 0x03UL) {
                memcpy(&hdr_data, hdr, sizeof(struct server_hdr));
                hdr = &hdr_data;
            }
            start_time.sec = 0;
            start_time.usec = 0;
            end_time.sec = co_ntohl(hdr->stop_sec);
            end_time.usec = co_ntohl(hdr->stop_usec);
            stats.bytes = (((uint64_t) co_ntohl( hdr->total_len1 )) << 32) + co_ntohl( hdr->total_len2 );
            stats.jitter_us =  co_ntohl(hdr->jitter1) * 1000 + co_ntohl(hdr->jitter2);
            stats.nb_error = co_ntohl(hdr->error_cnt);
            stats.nb_datagrams = co_ntohl(hdr->datagrams);

            dbg("Server report:\n");
            dbg("[ ID]  Interval      Transfer     Bandwidth       Jitter   Lost/Total Datagrams\n");
            stream->iperf_settings.flags.is_server = true;
            fhost_iperf_print_stats(stream, &start_time, &end_time, &stats);
            stream->iperf_settings.flags.is_server = false;
        }
        rtos_semaphore_signal(stream->to_semaphore, false);

        pbuf_free(p);
    }
}

/**
 ****************************************************************************************
 * @brief Send last UDP packet and wait for server report
 *
 * @param[in] pcb           Pointer to UDP Process Control Block
 * @param[in] stream        Pointer to iperf stream
 * @param[in] packet_id     Packet ID of the last UDP packet to send
 * @return ERR_OK if successful
 ****************************************************************************************
 **/
static err_t net_iperf_udp_server_report_req(struct udp_pcb *pcb,
                                             struct fhost_iperf_stream *stream,
                                             int32_t packet_id)
{
    struct iperf_report *report = &stream->report;
    struct net_iperf_send_buf_tag *buf_tag;
    uint8_t cnt = 0;
    net_buf_tx_t *h = NULL, *p = NULL;
    char *hdr;
    uint32_t payload_val;
    err_t err_log;

    aic_time_get(SINCE_EPOCH, &report->packet_time.sec, &report->packet_time.usec);
    udp_recv(pcb, (udp_recv_fn) net_iperf_udp_server_report_recv, stream);

    while ( cnt < 10 )
    {
        // Retrieve a free buffer from buffer pool
        buf_tag = net_iperf_find_free_send_buf(stream, -1);

        if (buf_tag == NULL)
        {
            //timeout
            break;
        }

        // Set the pbuf custom flag on
        h = pbuf_alloced_custom(PBUF_TRANSPORT, NET_IPERF_HEADER_SIZE, PBUF_RAM,
                &(buf_tag->h), buf_tag->hdr, NET_IPERF_HEADER_TOTAL_SIZE);

        // Set the pbuf custom flag on
        p = pbuf_alloced_custom(PBUF_RAW, stream->iperf_settings.buf_len - NET_IPERF_HEADER_SIZE,
                PBUF_ROM, &(buf_tag->p), net_iperf_nocopy_buf, IPERF_BUFFER_LEN);

        // Sanity check - If buf_tag is not NULL, then h and p should never be NULL
        ASSERT_ERR(p != NULL);

        cnt++;
        pbuf_cat(h, p);
        hdr = h->payload;

        payload_val = co_htonl(packet_id);
        // Store unsigned int in the table of char
        memcpy(&hdr[0], &payload_val, 4);
        payload_val = co_htonl(report->packet_time.sec);
        memcpy(&hdr[4], &payload_val, 4);
        payload_val = co_htonl(report->packet_time.usec);
        memcpy(&hdr[8], &payload_val, 4);

        LOCK_TCPIP_CORE();
        err_log = udp_send(pcb, h);
        UNLOCK_TCPIP_CORE();
        pbuf_free(h);

        if (err_log != ERR_OK)
        {
            dbg("final NET_IPERF_AL : SEND ERR udp_sendto : %d\r\n", err_log);
            return ERR_VAL;
        }

        if (rtos_semaphore_wait(stream->to_semaphore, 350))
        {
            //timeout occurred
            continue;
        }

        break;
    }
    return ERR_OK;
}

/**
 ****************************************************************************************
 * @brief UDP receive callback after sending server report
 *
 * If a frame is received after sending the server report, assume that this is a report
 * request (since no check is done on the actual content of the buffer) and then trigger
 * IPERF server task to re-send the report.
 *
 * @param[in] arg           Pointer to iperf stream
 * @param[in] pcb           Pointer to UDP Process Control Block
 * @param[in] p             Buffer pointer of the last UDP packet
 * @param[in] addr          Pointer to Server IP address
 * @param[in] port          Server port
 ****************************************************************************************
 **/
static void net_iperf_udp_server_report_resend(void *arg, struct udp_pcb *pcb, struct pbuf *p,
                                               const ip_addr_t *addr, u16_t port)
{
    if (p != NULL)
    {
        struct fhost_iperf_stream* stream = (struct fhost_iperf_stream*) arg;
        rtos_semaphore_signal(stream->to_semaphore, false);
        pbuf_free(p);
    }
}

/**
 ****************************************************************************************
 * @brief Send UDP server report to client
 *
 * @param[in] pcb           Pointer to UDP Process Control Block
 * @param[in] stream        Buffer pointer of the last UDP packet
 ****************************************************************************************
 **/
static void net_iperf_udp_server_report_send(struct udp_pcb *pcb,
                                             struct fhost_iperf_stream *stream)
{
    uint8_t cnt = 0;
    net_buf_tx_t *p = NULL;
    struct server_hdr *hdr;
    struct iperf_UDP_datagram *UDP_buf;
    struct iperf_report *report = &stream->report;

    if (!stream->active)
        return;

    // Open a UDP connection for sending report
    LOCK_TCPIP_CORE();
    udp_connect(pcb, &report->addr, report->port);
    // Set callback for receiving server report requests from client
    udp_recv(pcb, net_iperf_udp_server_report_resend, stream);
    UNLOCK_TCPIP_CORE();

    while ( cnt < 10 )
    {
        // Allocate a pbuf for transmitting the server report
        p = pbuf_alloc(PBUF_TRANSPORT, NET_IPERF_HEADER_TOTAL_SIZE +
                       sizeof(struct iperf_UDP_datagram) + sizeof(struct server_hdr), PBUF_RAM);

        // Sanity check - p should never be NULL
        ASSERT_ERR(p != NULL);

        UDP_buf = (struct iperf_UDP_datagram *) p->payload;
        UDP_buf->id = report->packet_id;
        UDP_buf->sec = report->sent_time.sec;
        UDP_buf->usec = report->sent_time.usec;

        hdr = (struct server_hdr *) (UDP_buf + 1);

        hdr->flags = co_htonl(IPERF_HDR_VER1);
        hdr->total_len1 = co_htonl((long) (report->stats.bytes >> 32));
        hdr->total_len2 = co_htonl((long) (report->stats.bytes & 0xFFFFFFFF));
        hdr->stop_sec = co_htonl((long) report->end_time.sec);
        hdr->stop_usec = co_htonl((long) report->end_time.usec);
        hdr->error_cnt = co_htonl(report->stats.nb_error);
        hdr->outorder_cnt = co_htonl(report->stats.nb_out_of_orded);
        hdr->datagrams = co_htonl(report->stats.nb_datagrams);
        hdr->jitter1 = report->stats.jitter_us / 1000000;
        hdr->jitter2 = co_htonl((long) (report->stats.jitter_us - (hdr->jitter1 * 1000000)));
        hdr->jitter1 = co_htonl((long) hdr->jitter1);
        cnt++;

        LOCK_TCPIP_CORE();
        if (udp_send(pcb, p))
            dbg("NET_IPERF_AL : SEND ERR udp_sendto\n");
        UNLOCK_TCPIP_CORE();
        pbuf_free(p);

        if (rtos_semaphore_wait(stream->to_semaphore, 250))
        {
            //timeout occurred -> Report has been received by the client
            break;
        }
    }

    LOCK_TCPIP_CORE();
    udp_disconnect(pcb);
    UNLOCK_TCPIP_CORE();
}

/**
 ****************************************************************************************
 * @brief UDP packet reception callback
 *
 * @param[in] arg           Pointer to iperf stream
 * @param[in] pcb           Pointer to UDP Process Control Block
 * @param[in] p             Buffer pointer to the received UDP packet
 * @param[in] addr          Pointer to Server IP address
 * @param[in] port          Server port
 ****************************************************************************************
 **/
static void net_iperf_udp_recv_cb(void *arg, struct udp_pcb *pcb, struct pbuf *p,
        const ip_addr_t *addr, u16_t port)
{
    int packetID;
    struct fhost_iperf_stream *stream = arg;
    struct iperf_UDP_datagram *UDP_buf;
    struct iperf_UDP_datagram udp_data; // used if p->payload is not 4-byte aligned
    struct iperf_report *report = &stream->report;
    struct iperf_stats interval_stats;
    struct fhost_iperf_settings *iperf_settings = &stream->iperf_settings;
    struct iperf_time start_interval, end_interval;

    if (p == NULL)
        return;

    if (!stream->active)
        goto end;

    aic_time_get(SINCE_EPOCH, &report->packet_time.sec, &report->packet_time.usec);

    // Get the counter in the received buffer (normally equal to counter_send)
    // Pointer pointed to counter_send in payload
    UDP_buf = p->payload;
    // make sure to get a 4-byte aligned UDP_buf
    if ((unsigned int)UDP_buf & 0x03UL) {
        memcpy(&udp_data, UDP_buf, sizeof(struct iperf_UDP_datagram));
        UDP_buf = &udp_data;
    }
    //Convert network format to host format
    packetID = co_ntohl(UDP_buf->id);

    if (packetID != 0)
    {
        report->stats.bytes += p->tot_len;

        if (net_iperf_udp_handle_packet(stream, UDP_buf))
            goto end;

        //Check interval
        // Interval
        if (iperf_settings->interval.sec > 0 || iperf_settings->interval.usec > 0)
        {
            if (!iperf_timerbefore(&report->packet_time, &report->interval_target))
            {
                if (!report->last_stats.bytes)
                {
                    dbg("[ ID]  Interval      Transfer     Bandwidth       Jitter   Lost/Total Datagrams\n");
                }

                iperf_timersub(&report->last_interval, &report->start_time, &start_interval);
                iperf_timersub(&report->packet_time, &report->start_time, &end_interval);
                interval_stats.bytes = report->stats.bytes - report->last_stats.bytes;
                interval_stats.nb_datagrams = report->stats.nb_datagrams - report->last_stats.nb_datagrams;
                interval_stats.nb_error = report->stats.nb_error- report->last_stats.nb_error;
                interval_stats.nb_out_of_orded = report->stats.nb_out_of_orded - report->last_stats.nb_out_of_orded;
                if (interval_stats.nb_error > interval_stats.nb_out_of_orded)
                    interval_stats.nb_error -= interval_stats.nb_out_of_orded;
                interval_stats.jitter_us = report->stats.jitter_us;
                fhost_iperf_print_stats(stream, &start_interval, &end_interval, &interval_stats);
                report->last_stats = report->stats;
                report->last_interval = report->packet_time;
                iperf_timeradd(&iperf_settings->interval, &report->interval_target, &report->interval_target);
            }
        }

        if (packetID < 0) //End of reception
        {
            struct iperf_time zero_time;
            memset(&zero_time, 0, sizeof(zero_time));
            udp_recv(pcb, NULL, NULL);
            report->stats.nb_datagrams = report->packet_id;
            if (report->stats.nb_error > report->stats.nb_out_of_orded)
                report->stats.nb_error -= report->stats.nb_out_of_orded;

            iperf_timersub(&report->packet_time, &report->start_time, &report->end_time);

            if (!report->last_stats.bytes)
            {
                dbg("[ ID]  Interval      Transfer     Bandwidth       Jitter   Lost/Total Datagrams\n");
            }

            //Print final stats
            fhost_iperf_print_stats(stream, &zero_time, &report->end_time, &report->stats);

            //Prepare packet for UDP client report
            report->packet_id = UDP_buf->id;
            report->port = port;
            report->addr = *addr;
            rtos_semaphore_signal(stream->iperf_task_semaphore, false);
        }
    }
    else
    {
        net_if_t *n = &(fhost_env.vif[0].net_if);
        uint32_t ip;

        net_if_get_ip(n, &ip, NULL, NULL);

        dbg("local %d.%d.%d.%d port %d connected with %d.%d.%d.%d port %d\n",
                ip & 0xff, (ip >> 8) & 0xff, (ip >> 16) & 0xff, (ip >> 24) & 0xff,
                stream->iperf_settings.port, addr->addr & 0xff, (addr->addr >> 8) & 0xff,
                (addr->addr >> 16) & 0xff, (addr->addr >> 24) & 0xff, port);
        aic_time_get(SINCE_EPOCH, &report->start_time.sec, &report->start_time.usec);
        if (iperf_settings->interval.sec != 0 || iperf_settings->interval.usec != 0)
        {
            iperf_timeradd(&report->start_time, &iperf_settings->interval, &report->interval_target);
            report->last_interval = report->start_time;
        }
    }
  end:
    pbuf_free(p);
}

/**
 ****************************************************************************************
 * @brief Configure PCB
 *
 * @param[in] pcb           Pointer Process Control Block (UDP and TCP)
 * @param[in] stream        Pointer to iperf stream
 * @return ERR_OK if successful
 ****************************************************************************************
 **/
static err_t net_iperf_pcb_config(void *pcb, struct fhost_iperf_stream *stream)
{
    const struct fhost_iperf_settings *settings = (struct fhost_iperf_settings *) &stream->iperf_settings;
    uint32_t ip;
    ip_addr_t lip;

    if (settings->flags.is_server)
    {
        net_if_t *n = &(fhost_env.vif[0].net_if);
        uint32_t mask;

        // Bind Server IP address and port to pcb
        net_if_get_ip(n, &ip, &mask, NULL);
        ip_addr_set_ip4_u32(&lip,  ip);
        if (settings->flags.is_udp)
        {
            if (udp_bind((struct udp_pcb *) pcb, &lip, settings->port) != ERR_OK)
            {
                TRACE("NET_IPERF_AL: PCB CONFIG ERR udp_bind failed");
                return 1;
            }
        }
        else
        {
            if (tcp_bind((struct tcp_pcb *) pcb, &lip, settings->port))
            {
                TRACE("NET_IPERF_AL: PCB CONFIG ERR tcp_bind failed");
                return 1;
            }
        }

        // Print header
        net_iperf_print_header(settings);
    }
    else
    {
        ip_addr_t rip;

        ip = settings->host_ip;
        ip_addr_set_ip4_u32(&rip,  ip);

        if (settings->flags.is_udp)
        {
            if (udp_bind((struct udp_pcb *) pcb, IP_ANY_TYPE, 0) != ERR_OK)
            {
                TRACE("NET_IPERF_AL : PCB CONFIG ERR udp_bind failed");
                return 1;
            }
            if (udp_connect((struct udp_pcb *) pcb, &rip, settings->port) != ERR_OK)
            {
                TRACE("NET_IPERF_AL : PCB CONFIG ERR udp_connect failed");
                return 1;
            }

            ((struct udp_pcb *) pcb)->tos = settings->tos;
            ((struct udp_pcb *) pcb)->ttl = settings->ttl;
        }
        else
        {
            tcp_arg((struct tcp_pcb *) pcb, stream);
            tcp_sent((struct tcp_pcb *) pcb, net_iperf_tcp_sent);
            tcp_poll((struct tcp_pcb *) pcb, net_iperf_tcp_poll, 2U);
            tcp_err((struct tcp_pcb *) pcb, net_iperf_tcp_err);
            tcp_recv((struct tcp_pcb *) pcb, net_iperf_tcp_recv_cb);

            if (tcp_connect((struct tcp_pcb *) pcb, &rip, settings->port,
                            net_iperf_tcp_client_connected) != ERR_OK)
            {
                TRACE("NET_IPERF_AL : PCB CONFIG ERR tcp_connect failed");
                return 1;
            }
            ((struct tcp_pcb *) pcb)->tos = settings->tos;
            ((struct tcp_pcb *) pcb)->ttl = settings->ttl;
        }
    }
    return 0;
}

/**
 ****************************************************************************************
 * @brief Create UDP Protocol Control Block and configure it
 *
 * @param[in] stream        Pointer to iperf stream
 * @return Active UDP Protocol Control Block
 ****************************************************************************************
 **/
static void* net_iperf_init(struct fhost_iperf_stream* stream)
{
    void* pcb;

    LOCK_TCPIP_CORE();
    if (stream->iperf_settings.flags.is_udp)
    {
        // Create UDP Protocol Control Block
        pcb = udp_new();
        if (pcb == NULL)
        {
            UNLOCK_TCPIP_CORE();
            TRACE("NET_IPERF_AL : IPERF INIT ERR udp_new failed");
            return NULL;
        }
        stream->arg = pcb;
    }
    else
    {
        // Create TCP Protocol Control Block
        pcb = tcp_new();
        if (pcb == NULL)
        {
            UNLOCK_TCPIP_CORE();
            TRACE("NET_IPERF_AL : IPERF INIT ERR tcp_new failed");
            return NULL;
        }
    }

    // Configure pcb
    if (net_iperf_pcb_config(pcb, stream) != ERR_OK)
    {
        UNLOCK_TCPIP_CORE();
        return NULL;
    }
    UNLOCK_TCPIP_CORE();

    if (!stream->iperf_settings.flags.is_server)
    {
        uint32_t ip, tries = 0, found = 0;
        struct eth_addr *eth_ret;
        struct netif *netif;
        const ip4_addr_t *ip_ret;
        ip_addr_t rip;

        ip = stream->iperf_settings.host_ip;
        ip_addr_set_ip4_u32(&rip,  ip);

        /* Don't call ip_route() with IP_ANY_TYPE */
        netif = ip_route(IP46_ADDR_ANY(IP_GET_TYPE(&rip)), &rip);
        found = (etharp_find_addr(netif, &rip, &eth_ret, &ip_ret) != -1);
        if (!found) // Not found -> send ARP request
            etharp_request(netif, &rip);
        while (!found && tries < 3)
        {
            // It is not possible to use a callback for the ARP reply, set a timeout
            rtos_task_suspend(ARP_REPLY_TO);
            tries++;
            found = (etharp_find_addr(netif, &rip, &eth_ret, &ip_ret) != -1);
        }
    }
    return pcb;
}

int net_iperf_udp_server_run(struct fhost_iperf_stream* stream)
{
    struct udp_pcb * pcb = NULL;

    net_iperf_buf_init(stream);
    pcb = net_iperf_init(stream);
    if (pcb == NULL)
    {
        TRACE("NET_IPERF_AL : SEND TRANSC ERR pcb null");
        return -1;
    }

    while(stream->active)
    {
        udp_recv(pcb, net_iperf_udp_recv_cb, stream);

        rtos_semaphore_wait(stream->iperf_task_semaphore, -1);
        net_iperf_udp_server_report_send(pcb, stream);

        dbg("\n");
        memset(&stream->report, 0, sizeof(stream->report));
    }

    LOCK_TCPIP_CORE();
    udp_remove(pcb);
    UNLOCK_TCPIP_CORE();

    return 0;
}

int net_iperf_udp_client_run(struct fhost_iperf_stream* stream)
{
    struct fhost_iperf_settings* iperf_settings = &stream->iperf_settings;
    struct iperf_report *report = &stream->report;
    struct udp_pcb * pcb = NULL;
    int32_t payload_val, packet_id, remaining_time_ms, ret = 0;
    struct iperf_time wakeup_time, elapsed_time, tmp_time, last_sleep_time,
                      expected_sleep_time, sleep_time, end_interval, remaining_time;
    struct net_iperf_send_buf_tag *buf_tag = NULL;
    err_t err_log;
    net_buf_tx_t *h = NULL, *p = NULL;
    char *payload;
    uint32_t delay_target, throttled_rate;

    pcb = (struct udp_pcb *) net_iperf_init(stream);
    if (pcb == NULL)
    {
        TRACE("NET_IPERF_AL : SEND TRANSC ERR pcb null");
        return -1;
    }

    /* Connect to UDP Server*/
    net_iperf_buf_init(stream);

    /* Init UDP transmission */
    net_iperf_print_header(iperf_settings);
    aic_time_get(SINCE_EPOCH, &report->start_time.sec, &report->start_time.usec);
    packet_id = 0;
    report->last_stats = report->stats;
    report->packet_time = report->last_interval = last_sleep_time = report->start_time;
    iperf_timeradd(&report->start_time, &iperf_settings->interval, &report->interval_target);
    wakeup_time.sec = wakeup_time.usec = 0;

    //Compute end time if time limited
    if ( iperf_settings->flags.is_time_mode )
    {
        struct iperf_time elapse;
        elapse.sec = (uint32_t) iperf_settings->amount / 10;
        elapse.usec = (uint32_t) 100000 * (iperf_settings->amount - (elapse.sec * 10));
        iperf_timeradd(&report->start_time, &elapse, &report->end_time);
    }

    delay_target = (uint32_t) ((iperf_settings->buf_len) * ((float)(1000000 * 8) / (iperf_settings->udprate)));
    throttled_rate = (IPERF_UDP_BURST_WAIT_MS * 1000) > delay_target ?
                    (IPERF_UDP_BURST_WAIT_MS * 1000) / delay_target : 1;
    expected_sleep_time.sec = 0;
    expected_sleep_time.usec = delay_target * throttled_rate;
    tmp_time.sec = 0;
    tmp_time.usec = 0;
    remaining_time_ms = -1;

    do{
        // Retrieve a free buffer from buffer pool
        buf_tag = net_iperf_find_free_send_buf(stream, remaining_time_ms);

        if (buf_tag == NULL)
        {
            dbg("%s, %d\r\n", __func__, __LINE__);
            break;
        }

        // Set the pbuf custom flag on
        h = pbuf_alloced_custom(PBUF_TRANSPORT, NET_IPERF_HEADER_SIZE, PBUF_RAM,
                &(buf_tag->h), buf_tag->hdr, NET_IPERF_HEADER_TOTAL_SIZE);

        // Set the pbuf custom flag on
        p = pbuf_alloced_custom(PBUF_RAW, stream->iperf_settings.buf_len - NET_IPERF_HEADER_SIZE,
                PBUF_ROM, &(buf_tag->p), net_iperf_nocopy_buf, IPERF_BUFFER_LEN);

        //dbg("%s, h %08x, %08x, p %08x, %08x\r\n", __func__, h, h->payload, p, p->payload);

        pbuf_cat(h, p);

        // Sanity check - If buf_tag is not NULL, then p should never be NULL
        LWIP_ASSERT("Initialized pbuf should not be NULL", p != NULL);

        // Write UDP datagram
        payload = h->payload;
        payload_val = co_htonl(packet_id++);

        memcpy(&payload[0], &payload_val, 4);
        payload_val = co_htonl(report->packet_time.sec);
        memcpy(&payload[4], &payload_val, 4);
        payload_val = co_htonl(report->packet_time.usec);
        memcpy(&payload[8], &payload_val, 4);

        LOCK_TCPIP_CORE();
        // Send UDP frame
        err_log = udp_send(pcb, h);
        UNLOCK_TCPIP_CORE();
        pbuf_free(h);

        if (err_log == ERR_OK)
        {
            // Update statistics
            report->stats.bytes += iperf_settings->buf_len;
            report->stats.nb_datagrams++;
        }
        else
        {
            TRACE("NET_IPERF_AL : SEND ERR\r\n");
            dbg( "NET_IPERF_AL : SEND ERR udp_sendto : %d\r\n", err_log);
            return 1;
        }

        // Check if burst is over
        if (throttled_rate != 0 && report->stats.nb_datagrams % throttled_rate == 0)
        {
            iperf_timersub(&report->packet_time, &last_sleep_time, &elapsed_time);
            // Do we need to skip waiting?
            if (iperf_timerbefore(&elapsed_time, &expected_sleep_time))
            {
                // Check if interval is present
                if (iperf_settings->interval.sec > 0 || iperf_settings->interval.usec > 0)
                {
                    //Check if we do need to print the interval immediately
                    if (!iperf_timerbefore(&report->packet_time, &report->interval_target))
                    {
                        fhost_iperf_udp_print_interv_stats(stream);
                    }

                    // Do we need to sleep?
                    if (iperf_timerbefore(&elapsed_time, &expected_sleep_time))
                    {
                        // We need to sleep - compute wakeup time for next burst transmission
                        // Subtract elapsed time from expected sleep_time
                        iperf_timersub(&expected_sleep_time, &elapsed_time, &sleep_time);
                        // Add spare microseconds from last waiting time
                        iperf_timeradd(&sleep_time, &tmp_time, &sleep_time);
                        // Add time offset to packet time
                        iperf_timeradd(&report->packet_time, &sleep_time, &wakeup_time);

                        //Do we need to wake up to print the interval?
                        if (iperf_timerbefore(&report->interval_target, &wakeup_time))
                        {
                            // Wake up for printing interval
                            iperf_timersub(&report->interval_target, &report->packet_time, &sleep_time);
                            // Sleep before interval printing
                            rtos_task_suspend(sleep_time.usec / 1000);
                            // Keep remaining microseconds for next wait
                            tmp_time.usec = sleep_time.usec % 1000;
                            // Update packet time
                            aic_time_get(SINCE_EPOCH, &report->packet_time.sec, &report->packet_time.usec);
                            // Print statistics
                            fhost_iperf_udp_print_interv_stats(stream);
                            // Wake up for next burst
                            iperf_timersub(&wakeup_time, &report->packet_time, &sleep_time);
                            // Add spare microseconds from last waiting time
                            iperf_timeradd(&sleep_time, &tmp_time, &sleep_time);
                        }
                        // Sleep before next burst
                        rtos_task_suspend(sleep_time.usec / 1000);
                        // Keep remaining microseconds for next wait
                        tmp_time.usec = sleep_time.usec % 1000;
                        // Update time of last sleep
                        aic_time_get(SINCE_EPOCH, &last_sleep_time.sec, &last_sleep_time.usec);
                    }
                }
                else
                {
                    // Subtract elapsed time from expected sleep_time
                    iperf_timersub(&expected_sleep_time, &elapsed_time, &sleep_time);
                    // Add spare microseconds from last waiting time
                    iperf_timeradd(&sleep_time, &tmp_time, &sleep_time);

                    // Sleep before next burst or interval printing
                    rtos_task_suspend(sleep_time.usec / 1000);
                    // Keep remaining microseconds for next wait
                    tmp_time.usec = sleep_time.usec % 1000;
                    // Update time of last sleep
                    aic_time_get(SINCE_EPOCH, &last_sleep_time.sec, &last_sleep_time.usec);
                }
            }
            else
            {
                // Update time of last sleep even if we skipped it
                aic_time_get(SINCE_EPOCH, &last_sleep_time.sec, &last_sleep_time.usec);
            }
        }

        // Update packet time
        aic_time_get(SINCE_EPOCH, &report->packet_time.sec, &report->packet_time.usec);

        // Print Interval if necessary
        if (iperf_settings->interval.sec > 0 || iperf_settings->interval.usec > 0)
        {
            if (!iperf_timerbefore(&report->packet_time, &report->interval_target))
            {
                fhost_iperf_udp_print_interv_stats(stream);
            }
        }

        // Decrement amount of packets to transmit in amount mode
        if ( !iperf_settings->flags.is_time_mode )
        {
            iperf_settings->amount -= iperf_settings->buf_len < iperf_settings->amount ? iperf_settings->buf_len : iperf_settings->amount;
        }

        // Compute remaining time
        iperf_timersub(&report->end_time, &report->packet_time, &remaining_time);
        remaining_time_ms = iperf_timermsec(&remaining_time);

    } while(!((iperf_settings->flags.is_time_mode && iperf_timerbefore(&report->end_time, &report->packet_time)) ||
            (!iperf_settings->flags.is_time_mode && iperf_settings->amount == 0)) &&
            stream->active);

    iperf_timersub(&report->packet_time, &report->start_time, &end_interval);

    if (!report->last_stats.bytes)
        dbg( "[ ID] Interval       Transfer     Bandwidth\n");
    report->start_time.sec = report->start_time.usec = 0;
    fhost_iperf_print_stats(stream, &report->start_time, &end_interval, &report->stats);

    err_log = net_iperf_udp_server_report_req(pcb, stream, -packet_id);
    if (err_log != ERR_OK)
    {
        ret = 1;
    }

    // Wait until all of pbuf are freed
    while (rtos_semaphore_get_count(stream->send_buf_semaphore) < FHOST_IPERF_SEND_BUF_CNT)
    {
        rtos_semaphore_wait(stream->send_buf_semaphore, -1);
        rtos_semaphore_signal(stream->send_buf_semaphore, false);
    }

    LOCK_TCPIP_CORE();
    udp_remove(pcb);
    UNLOCK_TCPIP_CORE();
    return ret;
}

int net_iperf_tcp_client_run(struct fhost_iperf_stream* stream)
{
    struct tcp_pcb *pcb = NULL;

    net_iperf_buf_init(stream);
    pcb = (struct tcp_pcb *) net_iperf_init(stream);
    if (pcb == NULL)
    {
        TRACE("NET_IPERF_AL : SEND TRANSC ERR pcb null");
        return -1;
    }

    // Wait for TCP traffic to end
    rtos_semaphore_wait(stream->iperf_task_semaphore, -1);
    return 0;
}

int net_iperf_tcp_server_run(struct fhost_iperf_stream* stream)
{
    struct tcp_pcb *pcb, *server_pcb;

    // Create and configure TCP Protocol Control Block
    pcb = (struct tcp_pcb *) net_iperf_init(stream);
    if (pcb == NULL)
    {
        TRACE("NET_IPERF_AL : SEND TRANSC ERR pcb null");
        return -1;
    }

    LOCK_TCPIP_CORE();
    // Listening for TCP clients to connect
    server_pcb = tcp_listen_with_backlog(pcb, 1);
    if (server_pcb == NULL)
    {
        dbg("IPERF: Server pcb is NULLs\n");
        if (pcb != NULL)
        {
            tcp_close(pcb);
        }
        UNLOCK_TCPIP_CORE();
        return 0;
    }

    // Register argument for acceptance callback
    tcp_arg(server_pcb, stream);
    tcp_accept(server_pcb, net_iperf_tcp_server_accept);
    UNLOCK_TCPIP_CORE();

    // Wait for TCP traffic to end
    rtos_semaphore_wait(stream->iperf_task_semaphore, -1);
    tcp_close(server_pcb);
    return 0;
}

#endif /* PLF_IPERF */
