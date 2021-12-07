/**
 ****************************************************************************************
 *
 * @file fhost_tg.h
 *
 * @brief Definitions of the fully hosted TG (traffic generator) task.
 *
 * Copyright (C) RivieraWaves 2017-2019
 *
 ****************************************************************************************
 */

#ifndef _FHOST_TG_H_
#define _FHOST_TG_H_

/**
 ****************************************************************************************
 * @defgroup FHOST_TG FHOST_TG
 * @ingroup FHOST
 * @brief TG task for fully hosted firmware
 * @{
 ****************************************************************************************
 */

/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include "sockets.h"

/*
 * DEFINITIONS
 ****************************************************************************************
 */
/// Number of traffic stream
#define FHOST_TG_MAX_TRAFFIC_STREAMS 3
/// Number of TG send buffers (credits)
#define FHOST_TG_SEND_BUF_CNT        8

/// Traffic sending direction
#define FHOST_TG_DIRECT_SEND                1
/// Traffic receiving direction
#define FHOST_TG_DIRECT_RECV                2

/// TG profile ID
enum profile_id
{
    /// Profile Types
    /// Large file transfer between endpoints
    FHOST_PROF_FILE_TX = 1,
    /// A group/multicast traffic Real Audio stream
    FHOST_PROF_MCAST,
    /// IPTV stream
    FHOST_PROF_IPTV,
    /// A series of client / server transactions
    FHOST_PROF_TRANSC,
    /// NOT USED
    FHOST_PROF_START_SYNC,
    /// NOT USED
    FHOST_PROF_CALI_RTD = FHOST_PROF_START_SYNC,
    /// NOT USED
    FHOST_PROF_UAPSD,
    /// NOT USED
    FHOST_PROF_LAST
};

/*
 * TYPE DEFINITIONS
 ****************************************************************************************
 */
/// TG Time structure used for TG send process
struct fhost_tg_time
{
    /// second
    uint32_t sec;
    /// microsecond
    uint32_t usec;
};

/// TG profile
struct fhost_tg_profile
{
     /// Profile ID
    enum profile_id prof_id;
    /// Traffic direction
    int direction;
    /// IP address of destination
    uint32_t dst_ip;
    /// Send destination port
    uint32_t dst_port;
    /// IP address of source
    uint32_t src_ip;
    /// Local port
    uint32_t src_port;
    /// Traffic rate (pkts /s)
    uint32_t rate;
    /// Packet size
    uint32_t pksize;
    /// Traffic duration
    uint32_t duration;
    /// TOS value to be put in the IP header
    uint16_t tos;
};

/// TG statistics
struct fhost_tg_stats
{
    /// Number of TX frames sent
    uint32_t tx_frames;
    /// Number of RX frames received
    uint32_t rx_frames;
    /// Counter for send command
    uint32_t counter_send;
    /// Counter for recv command
    uint32_t counter_recv;
    /// Number of TX buffer bytes
    uint32_t tx_bytes;
    /// Number of RX buffer bytes
    uint32_t rx_bytes;
    /// Traffic throughput
    uint32_t throughput;
    /// Number of expected frames
    uint32_t expected;
    /// Number of lost frames
    uint32_t lost;
    /// Number of unordered frames
    uint32_t unordered;
    /// Round trip time delay of transaction
    uint32_t rt_time;
};

/// TG stream
struct fhost_tg_stream
{
    /// Stream ID
    uint32_t id;
    /// State of TG stream (true for active, false for inactive)
    bool active;
    /// TG semaphore used to synchronize the TG thread and the FHOST IPC one
    rtos_semaphore tg_semaphore;
    /// NET_TG Semaphore used to synchronize the process in the net_tg_al layer
    rtos_semaphore net_tg_semaphore;
    /// Handle of TG send task (not used yet)
    rtos_task_handle tg_handle;
    /// TG mutex used when we modify the credits for sending process
    rtos_mutex tg_mutex;
    /// Param pointer for NET TG AL
    void *arg;
    /// Credits for TG sending buffer
    int8_t credits;
    /// Timestamp used for transaction
    struct fhost_tg_time transc_timestamp;
    /// TG profile
    struct fhost_tg_profile prof;
    /// TG statistics
    struct fhost_tg_stats stats;
};

/*
 * GLOBAL VARIABLES
 ****************************************************************************************
 */
/// Table of TG streams
extern struct fhost_tg_stream g_streams[FHOST_TG_MAX_TRAFFIC_STREAMS];

/*
 * FUNCTIONS
 ****************************************************************************************
 */
/**
 ****************************************************************************************
 * @brief Start TG stream configuration
 * This function configures the TG stream with certain characteristics.
 *
 * @param[in] stream_id    TG stream ID
 * @param[in] prof         TG profile ID
 * @param[in] direction    Direction of stream (DIRECT_SEND, DIRECT_RECV)
 * @param[in] rip          Destination IP address
 * @param[in] dst_port     Destination port
 * @param[in] lip          Local IP address
 * @param[in] src_port     Local port
 * @param[in] rate         Traffic rate (pkts / s)
 * @param[in] pksize       Packet size
 * @param[in] duration     Traffic duration
 * @param[in] tos          Type of service
 *
 * @return 0 on success and !=0 otherwise
 ****************************************************************************************
 */
int fhost_tg_config(u32_t stream_id, u32_t prof, int direction, u32_t rip, u32_t dst_port,
        u32_t lip, u32_t src_port, u32_t rate, u32_t pksize, u32_t duration, uint16_t tos);

/**
 ****************************************************************************************
 * @brief Start TG traffic for sending or receiving process according to the direction
 * of TG stream
 * If it's sending direction :
 * This function creates the RTOS task dedicated to the TG send processing.
 * We can send several TG streams at the same time.
 * If it's receiving direction :
 * This function starts the receiving server dedicated to the TG recv processing.
 * We can also receive several TG streams at the same time.
 *
 * @param[in] stream_id    TG stream ID
 *
 * @return 0 on success and !=0 otherwise
 ****************************************************************************************
 */
int fhost_tg_start(u32_t stream_id);

/**
 ****************************************************************************************
 * @brief Start TG stop task
 * This function stops the TG sending or receiving process according to TG stream ID
 * and return the statistics
 *
 * @param[in] stream_id    TG stream ID
 *
 * @return pointer to the statistics structure of stream, NULL if error
 ****************************************************************************************
 */
struct fhost_tg_stats *fhost_tg_stop(u32_t stream_id);

/// @}

#endif // _FHOST_TG_H_

