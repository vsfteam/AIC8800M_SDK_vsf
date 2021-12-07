/**
 ****************************************************************************************
 *
 * @file fhost.h
 *
 * @brief Definitions of the fully hosted module.
 *
 * Copyright (C) RivieraWaves 2017-2019
 *
 ****************************************************************************************
 */

#ifndef _FHOST_H_
#define _FHOST_H_

/**
 ****************************************************************************************
 * @defgroup FHOST FHOST
 * @ingroup MACSW
 * @brief Fully Hosted module implementation.
 * This module creates different RTOS tasks that will be used to handle the operations
 * of the fully-hosted FW
 * @{
 ****************************************************************************************
 */

/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include <string.h>
#include "co_list.h"
#include "rtos.h"
#ifdef CONFIG_RWNX_LWIP
#include "net_al.h"
#endif /* CONFIG_RWNX_LWIP */
#include "mac.h"
#include "fhost_api.h"
#include "plf.h"

/*
 * DEFINITIONS
 ****************************************************************************************
 */
#define STA_MAX (NX_REMOTE_STA_MAX + NX_VIRT_DEV_MAX)

#define BROADCAST_STA_IDX_MIN NX_REMOTE_STA_MAX
#define VIF_TO_BCMC_IDX(idx)    (BROADCAST_STA_IDX_MIN + (idx))

#define TRACE_FHOST(fmt, ...)  dbg(fmt, ## __VA_ARGS__)

#ifdef CFG_AIC_HSU_CHKSUM
/// Macro used to lock the checksum mutex
#define FHOST_CHECKSUM_LOCK()    rtos_mutex_lock(checksum_lock, -1)
/// Macro used to unlock the TX mutex
#define FHOST_CHECKSUM_UNLOCK()  rtos_mutex_unlock(checksum_lock)

extern rtos_semaphore checksum_lock;
#endif /* CFG_AIC_HSU_CHKSUM */

/// Type of messages sent using @ref fhost_msg structure
enum fhost_msg_type {
    /**
     * Message received from IPC layer (for test/development only)
     */
    FHOST_MSG_IPC,
    /**
     * Messages received from WIFI stack
     */
    FHOST_MSG_KE_WIFI,
    /**
     * Configuration/control messages received from supplicant application
     */
    FHOST_MSG_CFGRWNX,
    /**
     * Message received from console layer (for test/development only)
     */
    FHOST_MSG_CONSOLE,
    /**
     * Messages received from tx cfm callback (for 802.11 frame)
     */
    FHOST_MSG_TXCFM_CB,
};

/*
 * TYPE DEFINITIONS
 ****************************************************************************************
 */

/// STA Info Table
struct sta_info_tag
{
    /// linked list header
    struct co_list_hdr list_hdr;
    /**
     * Beacon Interval used by peer AP or peer Mesh STA (in microseconds).
     * Used only for a VIF of type STA or MP
     */
    uint32_t bcn_int;
    /// maximum size of HE A-MPDUs supported by the STA
    uint32_t ampdu_size_max_he;
    /// maximum size of VHT A-MPDUs supported by the STA
    uint32_t ampdu_size_max_vht;
    /// maximum size of HT A-MPDUs supported by the STA
    uint16_t ampdu_size_max_ht;
    /// PartialAid/GroupId to be put in the THD when transmitting to this STA
    uint32_t paid_gid;
    /// Minimal spacing to be inserted when transmitting to this STA
    uint8_t ampdu_spacing_min;

    uint32_t cipher_suite;
    uint8_t  key_added;
    #if (NX_POWERSAVE)
    /**
     * Maximum drift on one beacon period
     * Used only for a VIF of type STA or MP
     */
    uint16_t drift;
    #endif //(NX_POWERSAVE)
    /// AID of the station
    uint16_t aid;
    /// Interface the station belongs to
    uint8_t inst_nbr;
    /// Station index
    uint8_t staid;
    /// Power save state of the associated STA
    uint8_t ps_state;
    /// Flag indicating if the STA entry is valid or not
    bool valid;
    /// MAC address of the STA
    struct mac_addr mac_addr;

    /// Logical port state
    uint8_t ctrl_port_state;

    #if (NX_UMAC_PRESENT)
    /// PS/UAPSD traffic availability on host and/or internally
    enum sta_ps_traffic traffic_avail;
    /// PS/UAPSD service period status
    enum sta_ps_sp ps_service_period;
    /// control port protocol
    uint16_t ctrl_port_ethertype;
    /// STA Security Information
    struct sta_mgmt_sec_info sta_sec_info;
    /// Generic station information
    struct sta_capa_info info;
    /// Per-TID sequence numbers
    uint16_t seq_nbr[TID_MAX];
    /// TX policy table control
    struct sta_pol_tbl_cntl pol_tbl;
    #endif //(NX_UMAC_PRESENT)

    #if (NX_AMPDU_TX)
    /// For TX BA agreements per TID
    //struct ba_agmt ba_agmts_tx[TID_MAX];
    #endif //(NX_AMPDU_TX && !NX_UMAC_PRESENT)

    #if (NX_REORD)
    /// For RX BA agreements per TID
    //struct rxu_cntrl_reord *ba_agmts_rx[TID_MAX];
    #endif //(NX_REORD)

    #if (NX_UMAC_PRESENT)
    /// UMAC information related to the TX block ack agreements established
    struct sta_mgmt_ba_info ba_info[TID_MAX];
    /// Duplicate Detection Status (non-QoS data frames)
    uint16_t rx_nqos_last_seqcntl;
    /// Duplicate Detection Status (QoS data frames)
    uint16_t rx_qos_last_seqcntl[TID_MAX];
    #endif //(NX_UMAC_PRESENT)

    #if (NX_TX_FRAME)
    /// List of TX descriptor whose transmission has been postponed
    struct co_list tx_desc_post;
    #endif //(NX_TX_FRAME)

    #if (RW_MESH_EN)
    /// Mesh Link Index
    uint8_t mlink_idx;
    #endif //(RW_MESH_EN)

    #if (NX_TDLS)
    /// TDLS specific information
    struct tdls_info_tag tdls;
    /// Flag indicating if the station is a TDLS station
    bool is_tdls;
    #endif

    uint32_t last_active_time_us;;
};
/// Information related to the BSS a VIF is linked to
struct me_bss_info
{
    /// Network BSSID.
    struct mac_addr bssid;
};
/// VIF Info Table
struct vif_info_tag
{
    /// linked list header
    //struct co_list_hdr list_hdr;
    /// Bitfield indicating if this VIF currently allows sleep or not
    uint32_t prevent_sleep;
    /// EDCA parameters of the different TX queues for this VIF
    uint32_t txq_params[AC_MAX];

    #if (NX_MULTI_ROLE || NX_CHNL_CTXT || (NX_P2P_GO && NX_POWERSAVE))
    /// TBTT timer structure
    struct mm_timer_tag tbtt_timer;
    #endif //(NX_MULTI_ROLE || NX_CHNL_CTXT || (NX_P2P_GO && NX_POWERSAVE))

    #if (NX_P2P || NX_CHNL_CTXT)
    /// Timer used for Beacon Reception Timeout
    struct mm_timer_tag tmr_bcn_to;
    #endif //(NX_P2P || NX_CHNL_CTXT)

    #if (NX_MULTI_ROLE || NX_TDLS)
    /// BSSID this VIF belongs to
    struct mac_addr bssid;
    #endif //(NX_MULTI_ROLE)

    #if (NX_CHNL_CTXT)
    /// Channel context on which this VIF is attached
    struct chan_ctxt_tag *chan_ctxt;
    /// TBTT Switch Information
    struct chan_tbtt_tag tbtt_switch;
    #endif //(NX_CHNL_CTXT)

    /// MAC address of the VIF
    struct mac_addr mac_addr;

    /// Type of the interface (@ref VIF_STA, @ref VIF_IBSS, @ref VIF_MESH_POINT or @ref VIF_AP)
    uint8_t type;
    /// Index of the interface
    uint8_t index;
    /// Flag indicating if the VIF is active or not
    bool active;

    /// TX power configured for the interface (dBm)
    int8_t tx_power;

    /// TX power configured for the interface (dBm) by user space
    /// (Taken into account only if lower than regulatory one)
    int8_t user_tx_power;

    union
    {
        /// STA specific parameter structure
        struct
        {
            #if NX_POWERSAVE
            /// Listen interval
            uint16_t listen_interval;
            /// Flag indicating if we are expecting BC/MC traffic or not
            bool dont_wait_bcmc;
            /// Number of error seen during transmission of last NULL frame indicating PS change
            uint8_t ps_retry;
            #endif
            /// Index of the station being the peer AP
            uint8_t ap_id;
            #if NX_UAPSD
            /// Time of last UAPSD transmitted/received frame
            uint32_t uapsd_last_rxtx;
            /// Bitfield indicating which queues are U-APSD enabled
            uint8_t uapsd_queues;
            /// UAPSD highest TID, used in the QoS-NULL trigger frames
            uint8_t uapsd_tid;
            #endif
            #if NX_CONNECTION_MONITOR
            /// Time of last keep-alive frame sent to AP
            uint32_t mon_last_tx;
            /// CRC of last received beacon
            uint32_t mon_last_crc;
            /// Number of beacon losses since last beacon reception
            uint8_t beacon_loss_cnt;
            #endif

            #if (NX_P2P)
            /// Last computed TSF Offset
            int32_t last_tsf_offset;
            /// Addition duration to be added to the CTWindow, due to the TBTT_DELAY + drift value computed in mm_tbtt_compute
            uint32_t ctw_add_dur;
            /// Status indicated if Service Period has been paused due to GO absence
            bool sp_paused;
            #endif //(NX_P2P)

            #if (NX_P2P_GO)
            // Indicate if AP Beacon has been received at least one time
            bool bcn_rcved;
            #endif //(NX_P2P_GO)

            // Current RSSI
            int8_t rssi;
            // RSSI threshold (0=threshold not set)
            int8_t rssi_thold;
            // RSSI hysteresis
            uint8_t rssi_hyst;
            // Current status of RSSI (0=RSSI is high, 1=RSSI is low)
            bool rssi_status;

            /// Current CSA counter
            uint8_t csa_count;
            /// Indicate if channel switch (due to CSA) just happened
            bool csa_occured;

            #if (NX_TDLS)
            /// TDLS station index which requested the channel switch
            uint8_t tdls_chsw_sta_idx;
            #endif
            uint8_t vif_name[33];
        } sta;
        /// AP specific parameter structure
        struct
        {
            uint32_t dummy;
            /// Flag indicating how many connected stations are currently in PS
            uint8_t ps_sta_cnt;
            /// Control port ethertype
            uint16_t ctrl_port_ethertype;
            /// Current CSA counter
            uint8_t csa_count;

            rtos_semaphore csa_semaphore;
        } ap;
    } u;    ///< Union of AP/STA specific parameter structures

    /// List of stations linked to this VIF
    struct co_list sta_list;

    /// Information about the BSS linked to this VIF
    struct me_bss_info bss_info;

    #if NX_MAC_HE
    /// TXOP RTS threshold
    uint16_t txop_dur_rts_thres;
    #endif
    #if (NX_P2P)
    /// Indicate if this interface is configured for P2P operations
    bool p2p;
    /// Index of the linked P2P Information structure
    uint8_t p2p_index;
    /// Contain current number of registered P2P links for the VIF
    uint8_t p2p_link_nb;
    #endif //(NX_P2P)

    #if (RW_UMESH_EN)
    /// Mesh ID - Index of the used mesh_vif_info_tag structure when type is VIF_MESH_POINT
    uint8_t mvif_idx;
    #endif //(RW_UMESH_EN)
};
/// Structure containing the information about the virtual interfaces
struct fhost_vif_tag
{
    /// RTOS network interface structure
    net_if_t net_if;
    /// MAC address of the VIF
    struct mac_addr mac_addr;
    /// Socket for scan events
    int scan_sock;
    /// Socket for connect/disconnect events
    int conn_sock;
    /// Socket for AP
    int ap_sock;
    /// Pointer to the MAC VIF structure
    struct vif_info_tag *mac_vif;
    /// Index of the STA being the AP peer of the device - TODO rework
    uint8_t ap_id;
    /// Parameter to indicate if admission control is mandatory for any access category - TODO rework
    uint8_t acm;
    /// UAPSD queue config for STA interface (bitfield, same format as QoS info)
    uint8_t uapsd_queues;
    /// connect router band
    uint8_t band;
    uint8_t chan_index;
};

/// Structure used for the inter-task communication
struct fhost_env_tag
{
    /// Table of RTOS network interface structures
    struct fhost_vif_tag vif[NX_VIRT_DEV_MAX];
    /// Table linking the MAC VIFs to the FHOST VIFs
    struct fhost_vif_tag *mac2fhost_vif[NX_VIRT_DEV_MAX];
};

/// Generate fhost msg ID from a type and an index
#define FHOST_MSG_ID(type, idx) ((type << 12) | (idx & 0xfff))
/// Extract msg Type from msg ID
#define FHOST_MSG_TYPE(id) ((id >> 12) & 0xf)
/// Extract msg Index from msg ID
#define FHOST_MSG_INDEX(id) (id & 0xfff)

/// Generic Message format
struct fhost_msg {
    /// ID of the message. Id is a combination of a type and an index.
    /// To be set using @ref FHOST_MSG_ID macro
    uint16_t id;
    /// Length, in bytes, of the message
    uint16_t len;
    /// Pointer to the message
    void *data;
};

#define TR_32(a) (uint16_t)((uint32_t)(a) >> 16), (uint16_t)((uint32_t)(a))

/*
 * GLOBAL VARIABLES
 ****************************************************************************************
 */
/// FullHost module environment variable
extern struct fhost_env_tag fhost_env;

/*
 * FUNCTIONS
 ****************************************************************************************
 */
/**
 ****************************************************************************************
 * @brief Get MAC VIF owned by a FHOST VIF.
 *
 * @param[in] fhost_vif_idx Index of the FHOST VIF
 *
 * @return A pointer to the corresponding MAC VIF
 ****************************************************************************************
 */
__INLINE struct vif_info_tag *fhost_to_mac_vif(uint8_t fhost_vif_idx)
{
    struct vif_info_tag *mac_vif = fhost_env.vif[fhost_vif_idx].mac_vif;

    // Sanity check - Currently we consider that when this function is called there shall
    // be a MAC VIF attached to the FHOST VIF. If in the future this has to change then
    // this assertion will be removed
    ASSERT_ERR(mac_vif != NULL);

    return mac_vif;
}

/**
 ****************************************************************************************
 * @brief Get FHOST VIF owner of a MAC VIF.
 *
 * @param[in] mac_vif_idx Index of the MAC VIF
 *
 * @return A pointer to the corresponding FHOST VIF
 ****************************************************************************************
 */
__INLINE struct fhost_vif_tag *fhost_from_mac_vif(uint8_t mac_vif_idx)
{
    struct fhost_vif_tag *fhost_vif;

    // Sanity check - Check that mac_vif_idx is valid
    ASSERT_ERR(mac_vif_idx < NX_VIRT_DEV_MAX);

    fhost_vif = fhost_env.mac2fhost_vif[mac_vif_idx];

    // Sanity check - Currently we consider that when this function is called there shall
    // be a FHOST VIF attached to the MAC VIF. If in the future this has to change then
    // this assertion will be removed
    ASSERT_ERR(fhost_vif != NULL);

    return fhost_vif;
}

#ifdef CONFIG_RWNX_LWIP
/**
 ****************************************************************************************
 * @brief Get Network interface associated to a FHOST VIF.
 *
 * @param[in] fhost_vif_idx Index of the FHOST VIF
 *
 * @return A pointer to the corresponding network interface
 ****************************************************************************************
 */
__INLINE net_if_t *fhost_to_net_if(uint8_t fhost_vif_idx)
{
    ASSERT_ERR(fhost_vif_idx < NX_VIRT_DEV_MAX);
    return &(fhost_env.vif[fhost_vif_idx].net_if);
}
#endif /* CONFIG_RWNX_LWIP */

/**
 ****************************************************************************************
 * @brief Get FHOST VIF name.
 *
 * Copy name of a FHOST VIF inside provided buffer including a terminating a null byte.
 * If the buffer is not big enough then interface name is truncated and the null byte
 * is not written in the buffer.
 *
 * @param[in] fhost_vif_idx  Index of the FHOST VIF
 * @param[in] name           Buffer to retrieve interface name
 * @param[in] len            Size, in bytes, of the @p name buffer
 *
 * @return < 0 if error occurred, otherwise the number of characters (excluding the
 * terminating null byte) needed to write the interface name. If return value is greater
 * or equal to @p len, it means that the interface name has been truncated.
 ****************************************************************************************
 */
int fhost_vif_name(int fhost_vif_idx, char *name, int len);

/**
 ****************************************************************************************
 * @brief Get FHOST VIF index from its name.
 *
 * @param[in] name Interface name
 *
 * @return index of the fhost vif and < 0 if there is no interface with the provided name
 ****************************************************************************************
 */
int fhost_vif_idx_from_name(const char *name);

/**
 ****************************************************************************************
 * @brief Configure default queues enabled for U-APSD.
 *
 * This configuration is used when an interface configured as STA connects to an AP that
 * supports U-APSD. This can be called at any time, but the configuration will only be
 * applied for the next connections.
 *
 * @param[in] fhost_vif_idx  Index of the FHOST VIF. (Use -1 to configure all interfaces)
 * @param[in] uapsd_queues   AC bitfield as expected in Qos Info field
 *                           (i.e. Bit0=VO, Bit1=VI, Bit2=BK, bit3=BE)
 *
 * @return 0 on success and != 0 if error occurred.
 ****************************************************************************************
 */
int fhost_vif_set_uapsd_queues(int fhost_vif_idx, uint8_t uapsd_queues);

/**
 ****************************************************************************************
 * @brief Initialization of the application.
 *
 * Called during the initialization procedure (i.e. when RTOS scheduler is not yet active).
 * Implementation of this function will depends of the final application and in most
 * cases it will create one of several application tasks and their required communication
 * interface (queue, semaphore, ...)
 *
 * @return 0 on success and != 0 if error occurred.
 ****************************************************************************************
 */
int fhost_application_init(void);

/**
 ****************************************************************************************
 * @brief Create a socket and connect it to loopback address on the specified port
 *
 * @param[in] port UDP port to connect to
 * @return socket file descriptor and <0 if error occurred
 ****************************************************************************************
 */
int fhost_open_loopback_udp_sock(int port);

/**
 ****************************************************************************************
 * @brief Print a pre-formatted string buffer.
 *
 * Implementation of this function will depend of target/application
 *
 * @param[in] handle Task handle of the RTOS task sending the message
 *                   (can be null to indicate current task)
 * @param[in] buf    Formatted string buffer
 *
 * @return 0 on success and != 0 if error occurred.
 ****************************************************************************************
 */
int fhost_print_buf(rtos_task_handle handle, const char *buf);

/**
 ****************************************************************************************
 * @brief Print a message.
 *
 * Implementation of this function will depend of target/application
 *
 * @param[in] handle Task handle of the RTOS task sending the message
 *                   (can be null to indicate current task)
 * @param[in] fmt    Format string
 *
 * @return 0 on success and != 0 if error occurred.
 ****************************************************************************************
 */
int fhost_print(rtos_task_handle handle, const char *fmt, ...);


/**
 ****************************************************************************************
 * @brief Compute checksum on a given IP packet
 *
 * Compute IP packet checksum using HSU and fallback to software computation if HSU is
 * unavailable
 *
 * @param[in] dataptr Buffer containing the IP packet
 * @param[in] len     Buffer length (in bytes)
 * @return IP packet checksum
 ****************************************************************************************
 */
uint16_t fhost_ip_chksum(const void *dataptr, int len);


/**
 ****************************************************************************************
 * @brief Connect a STA interface to an AP
 *
 * This is blocking until connection is successful.
 *
 * @param[in] fhost_vif_idx  Fhost VIF index
 * @param[in] cfg            Interface configuration
 *
 * @return 0 on success and != 0 if error occurred.
 ****************************************************************************************
 */
int fhost_sta_cfg(int fhost_vif_idx, struct fhost_vif_sta_cfg *cfg);

/**
 ****************************************************************************************
 * @brief Start an Access Point
 *
 * This is blocking until AP is operational.
 *
 * @param[in] fhost_vif_idx  Fhost VIF index
 * @param[in] cfg            AP configuration
 *
 * @return 0 on success and != 0 if error occurred.
 ****************************************************************************************
 */
int fhost_ap_cfg(int fhost_vif_idx, struct fhost_vif_ap_cfg *cfg);


extern struct vif_info_tag vif_info_tab[NX_VIRT_DEV_MAX];
extern struct sta_info_tag sta_info_tab[STA_MAX + NX_VIRT_DEV_MAX];
extern int wlan_connected;

extern void fhost_data_save(void);
extern void fhost_data_restore(void);
extern void fhost_sta_recover_connection(void);
extern void fhost_sta_ipc_rxbuf_recover(void);
extern uint8_t vif_mgmt_get_staid(const struct vif_info_tag *vif, const struct mac_addr *sta_addr);
extern int fhost_ipc_cntrl_init(uint32_t ipc_irq_prio);
extern int ipc_host_cntrl_start(void);
extern uint8_t vif_mgmt_sta_cnt(void);

extern int ipc_host_fw_init(void);

extern struct co_list free_sta_list;

typedef enum wifi_mac_status    {
    WIFI_MAC_STATUS_DISCONNECTED,
    WIFI_MAC_STATUS_CONNECTED,
}wifi_mac_status_e;
typedef void (*fhost_mac_status_get_func_t)(wifi_mac_status_e st);
void fhost_get_mac_status_register(fhost_mac_status_get_func_t func);

extern fhost_mac_status_get_func_t fhost_mac_status_get_callback;

uint8_t user_limit_sta_num_get(void);
void user_limit_sta_num_set(uint8_t num);


extern fhost_mac_status_get_func_t fhost_reconnect_dhcp_callback;
void fhost_reconnect_dhcp_register(fhost_mac_status_get_func_t func);

int fhost_scan_for_ssid_pwd(struct fhost_cntrl_link *link, int fvif_idx, uint8_t *p_ssid, uint8_t *p_password);

#if defined(CONFIG_RWNX_LWIP) && defined(CFG_HOSTIF)
typedef enum hostif_status
{
    HOSTIF_ST_IDLE,
    HOSTIF_ST_AWAKE,
    HOSTIF_ST_DEEPSLEEP,
}hostif_status_e;
void set_hostif_wlan_status(hostif_status_e st);
hostif_status_e get_hostif_wlan_status(void);
typedef struct ip_packet_filter
{
    uint8_t  used;
    uint8_t  protocol;
    uint16_t destination_port;
}ip_packet_filter_t;
/* filter_num <= 8 */
void set_hostif_user_filter(ip_packet_filter_t *filter, uint8_t filter_num);
ip_packet_filter_t * get_hostif_user_filter(void);
#endif /* CONFIG_RWNX_LWIP && CFG_HOSTIF */

#endif // _FHOST_H_
