/**
 ****************************************************************************************
 *
 * @file fhost_ping.h
 *
 * @brief Definitions of the fully hosted ping task.
 *
 * Copyright (C) RivieraWaves 2017-2019
 *
 ****************************************************************************************
 */
#ifndef _FHOST_PING_H_
#define _FHOST_PING_H_

/**
 ****************************************************************************************
 * @defgroup FHOST_PING FHOST_PING
 * @ingroup FHOST
 * @brief Ping task for fully hosted firmware
 * @{
 ****************************************************************************************
 */
/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include "sockets.h"
#include "fhost_tg.h"

/*
 * DEFINITIONS
 ****************************************************************************************
 */
/// Maximum number of ping streams
#define FHOST_PING_MAX_STREAMS 3
/// Profile ID for ping command, @ref net_sleep_time
#define FHOST_PROF_PING 7

/// Ping profile
struct fhost_ping_profile
{
    /// IP address of destination
    uint32_t dst_ip;
    /// Ping rate (pkts /s)
    uint32_t rate;
    /// Packet size
    uint32_t pksize;
    /// Ping duration
    uint32_t duration;
    /// TOS value to be put in the IP header
    uint16_t tos;
};

/// Ping statistics
struct fhost_ping_stats
{
    /// Number of TX frames sent
    uint32_t tx_frames;
    /// Number of RX frames received
    uint32_t rx_frames;
    /// Number of TX buffer bytes
    uint32_t tx_bytes;
    /// Number of RX buffer bytes
    uint32_t rx_bytes;
    /// Round trip time delay of ping command
    uint32_t rt_time;
};

/// Ping configuration structure
struct fhost_ping_stream
{
    /// Ping thread ID
    uint32_t id;
    /// State of ping thread (true for active, false for inactive)
    bool active;
    /// Param pointer for @ref net_tg_al.c
    void *arg;
    /// Ping sequence number
    u16_t ping_seq_num;
    /// Ping semaphore used to synchronize the ping thread and the FHOST IPC one
    rtos_semaphore ping_semaphore;
    /// Handle of ping send task (not used yet)
    rtos_task_handle ping_handle;
    /// Ping timestamp
    struct fhost_tg_time ping_timestamp;
    /// Ping profile
    struct fhost_ping_profile prof;
    /// Ping statistics
    struct fhost_ping_stats stats;
    /// Background task
    bool background;
};

/// Arguments for @ref fhost_ping_start
struct fhost_ping_task_args
{
    ///Destination IP address
    u32_t rip;
    ///Ping rate (pkts / s)
    u32_t rate;
    ///Packet size
    u32_t pksize;
    ///Ping duration
    u32_t duration;
    ///Type of service
    u16_t tos;
    ///Boolean for running ping in background
    bool background;
};

/*
 * GLOBAL VARIABLES
 ****************************************************************************************
 */
/// Table of ping streams
extern struct fhost_ping_stream p_streams[FHOST_PING_MAX_STREAMS];

/*
 * FUNCTIONS
 ****************************************************************************************
 */
/**
 ****************************************************************************************
 * @brief Search ping stream by stream id
 * It will return the ping stream associated to the provided ping stream id.
 *
 * @param[in] ping stream id
 *
 * @return Pointer to ping stream if found, NULL otherwise
 ****************************************************************************************
 **/
struct fhost_ping_stream *fhost_ping_find_stream_profile(u32_t stream_id);

/**
 ****************************************************************************************
 * @brief Start ping command with certain configuration options
 * This function creates the RTOS task dedicated to the ping send processing and return
 * the stream id of ping stream launched.
 *
 * @param[in] args    Pointer to arguments for fhost_ping_start (@ref struct fhost_ping_task_args)
 *
 * @return RTOS task handle of ping task on success, NULL otherwise
 ****************************************************************************************
 */
rtos_task_handle fhost_ping_start(void *args);

/**
 ****************************************************************************************
 * @brief Stop ping process launched
 * This function stops the ping process according to ping stream
 *
 * @param[in] ping_stream Pointer to the ping stream to stop
 ****************************************************************************************
 */
void fhost_ping_stop(struct fhost_ping_stream *ping_stream);


/**
 ****************************************************************************************
 * @brief Ping sigkill handler. Closes connection and ping stream.
 *
 * @param[in] ping_handle      Ping task handle
 *
 * @return FHOST_IPC_SUCCESS if successful, FHOST_IPC_ERROR otherwise
 ****************************************************************************************
 **/
int fhost_ping_sigkill_handler(rtos_task_handle ping_handle);


#if NX_CSI
void csi_start(void);
void csi_stop(void);
#endif /* NX_CSI */

/// @}

#endif // _FHOST_PING_H_
