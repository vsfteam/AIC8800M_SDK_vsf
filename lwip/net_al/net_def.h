/**
 ****************************************************************************************
 *
 * @file net_def.h
 *
 * @brief Definitions related to the networking stack
 *
 * Copyright (C) RivieraWaves 2017-2019
 *
 ****************************************************************************************
 */

#ifndef NET_DEF_H_
#define NET_DEF_H_

/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include "tcpip.h"

/*
 * DEFINITIONS
 ****************************************************************************************
 */
/// Net interface
typedef struct netif        net_if_t;

/// Net buffer
typedef struct pbuf_custom  net_buf_rx_t;

/// Net TX buffer
typedef struct pbuf         net_buf_tx_t;

/// Maximum size of a interface name (including null character)
#define NET_AL_MAX_IFNAME 4

#endif // NET_DEF_H_
