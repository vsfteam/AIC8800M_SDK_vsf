/**
 ****************************************************************************************
 *
 * @file fhost_smartconf.h
 *
 * @brief implementation of smart config for Fully Hosted firmware.
 *
 * Copyright (C) RivieraWaves 2017-2019
 *
 ****************************************************************************************
 */
#ifndef _FHOST_SMARTCONF_H_
#define _FHOST_SMARTCONF_H_

/**
 ****************************************************************************************
 * @defgroup FHOST_SMARTCONF FHOST_SMARTCONF
 * @ingroup FHOST
 * @brief Fully Hosted smart config implementation.
 *
 * @{
 ****************************************************************************************
 */
/*
 * INCLUDE FILES
 ****************************************************************************************
 */

#include "co_int.h"
#include "co_bool.h"
#include "msg.h"
#include "mac.h"
#include "rtos_al.h"

/*
 * TYPE DEFINITIONS
 ****************************************************************************************
 */
/// WPA message queue size
#define FHOST_SMARTCONF_QUEUE_WPA_MSG 5
/// Max buffer size used for WPA msg
#define FHOST_SMARTCONF_WPA_CTRL_BUF 256
/// Max ssid/pwd size
#define DATA_BUF_SIZE 32

#define MACDBG                          "%02x:%02x:%02x:%02x:%02x:%02x"
#define MAC2STRDBG(ea)                  (ea)[0], (ea)[1], (ea)[2], (ea)[3], (ea)[4], (ea)[5]

/// Types of encryption
typedef enum _encryption_mode {
    /// Encryption has not yet been determined
    UNKOWN_ENCRY = 0,
    /// Open Network (no security at all)
    ENCRY_NONE,
    /// WPA/WPA2 + AES
    ENCRY_CCMP,
    /// WPA/WPA2 + TKIP
    ENCRY_TKIP,
    /// WEP encryption
    ENCRY_WEP,
} ENCYTPTION_MODE;

/// smartconfig status
typedef enum sc_status {
    /// Sniffing the different scan result channels
    SC_STATUS_WAIT = 0,
    /// Target channel is found
    SC_STATUS_CHANNEL_FOUND,
    /// SSID and PWD are found
    SC_STATUS_SSID_PSWD_FOUND,
    /// connected
    SC_STATUS_CONNECTED
} SC_STATUS;

/// Structure for the scan results
struct fhost_smart_scan_res {
    /// Channel definition
    struct mac_chan_def *chan[SCAN_CHANNEL_MAX];
    /// Number of channels
    uint16_t cnt;
};

/// smartconf configuration structure
struct fhost_smart_conf {
    /// vif idx
    uint8_t idx;
    /// Handle of smartconf task
    rtos_task_handle smart_handle;
    /// Smartconf semaphore used for synchronization
    rtos_semaphore semaphore;
    /// Keyphrase
    char pwd[DATA_BUF_SIZE];
    /// SSID
    char ssid[DATA_BUF_SIZE];
    /// Encryption protocol
    uint8_t encryption_mode;
    /// Smartconfig status
    uint8_t status;
    /// Packet source address
    uint16_t src_mac_addr[MAC_ADDR_LEN / 2];
    /// Packet destination address
    uint16_t dst_mac_addr[MAC_ADDR_LEN / 2];
    /// bssid mac address
    uint16_t bssid_mac_addr[MAC_ADDR_LEN / 2];
    /// Guide pattern index
    uint8_t pattern_idx;
    /// CFGRWNX queue and sockets
    struct fhost_cntrl_link *link_params;
    /// Whether CFGRWNX link must be close when task exit
    bool local_link;
    /// Frequency on which the smartconfig algorithm is currently running
    uint16_t freq;
    /// Mac address is found (supported frame)
    bool mac_addr_is_found;

    struct smartconfig_t *sc;
};

/// smartconf configuration
extern struct fhost_smart_conf smart_conf;

/// Encryption offset for supported frame
extern uint16_t rx_encry_offset[];
/// Number of rx encryption types
extern uint8_t rx_encry_size;

/// Encryption offset for unsupported frame
extern uint16_t uf_encry_offset[];
// Number of uf encryption types
extern uint8_t uf_encry_size;

/*
 * FUNCTIONS
 ****************************************************************************************
 */
/**
 ****************************************************************************************
 * @brief Create the smartconf task and the different queues associated to this task.
 *
 * @param[in] idx   Index of the FHOST interface
 * @param[in] link  A CFGRWNX link. If NULL, a new link will be created.
 *
 * @return 0 on success and != 0 if error occurred.
 ****************************************************************************************
 */
int fhost_smartconf_start(int idx, struct fhost_cntrl_link *link);
int fhost_smartconf_stop(void);

/**
 * @}
 */
#endif /* _FHOST_SMARTCONF_H_ */
