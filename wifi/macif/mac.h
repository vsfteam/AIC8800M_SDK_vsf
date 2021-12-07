/**
 ****************************************************************************************
 *
 * @file lmac_mac.h
 *
 * @brief MAC related definitions.
 *
 * Copyright (C) RivieraWaves 2011-2019
 *
 ****************************************************************************************
 */

#ifndef _MAC_H_
#define _MAC_H_

/**
 ****************************************************************************************
 * @defgroup MAC MAC
 * @ingroup COMMON
 * @brief  Common defines,structures
 *
 * This module contains defines commonaly used for MAC
 * @{
 ****************************************************************************************
 */

/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include "co_int.h"
#include "co_math.h"
#include "co_utils.h"


/* Sync with lmac_mac.h */

/// Interface types
enum mac_vif_type
{
    /// ESS STA interface
    VIF_STA,
    /// IBSS STA interface
    VIF_IBSS,
    /// AP interface
    VIF_AP,
    /// Mesh Point interface
    VIF_MESH_POINT,
    /// Monitor interface
    VIF_MONITOR,
    /// Unknown type
    VIF_UNKNOWN
};
/// Macro defining an invalid VIF index
#define INVALID_VIF_IDX 0xFF

/// MAC address length in bytes.
#define MAC_ADDR_LEN 6

/// MAC address structure.
struct mac_addr
{
    /// Array of 16-bit words that make up the MAC address.
    uint16_t array[MAC_ADDR_LEN/2];
};

/// SSID maximum length.
#define MAC_SSID_LEN 32

/// SSID.
struct mac_ssid
{
    /// Actual length of the SSID.
    uint8_t length;
    /// Array containing the SSID name.
    uint8_t array[MAC_SSID_LEN];
};

/// BSS type
enum mac_bss_type
{
    INFRASTRUCTURE_MODE = 1,
    INDEPENDENT_BSS_MODE,
    ANY_BSS_MODE
};

/// Channel Band
enum mac_chan_band
{
    /// 2.4GHz Band
    PHY_BAND_2G4,
    /// 5GHz band
    PHY_BAND_5G,
    /// Number of bands
    PHY_BAND_MAX,
};

/// Operating Channel Bandwidth
enum mac_chan_bandwidth
{
    /// 20MHz BW
    PHY_CHNL_BW_20,
    /// 40MHz BW
    PHY_CHNL_BW_40,
    /// 80MHz BW
    PHY_CHNL_BW_80,
    /// 160MHz BW
    PHY_CHNL_BW_160,
    /// 80+80MHz BW
    PHY_CHNL_BW_80P80,
    /// Reserved BW
    PHY_CHNL_BW_OTHER,
};

/// max number of channels in the 2.4 GHZ band
#define MAC_DOMAINCHANNEL_24G_MAX 14

/// max number of channels in the 5 GHZ band
#define MAC_DOMAINCHANNEL_5G_MAX 28

/// Channel Flag
enum mac_chan_flags
{
    /// Cannot initiate radiation on this channel
    CHAN_NO_IR = CO_BIT(0),
    /// Channel is not allowed
    CHAN_DISABLED = CO_BIT(1),
    /// Radar detection required on this channel
    CHAN_RADAR = CO_BIT(2),
};

/// Primary Channel definition
struct mac_chan_def
{
    /// Frequency of the channel (in MHz)
    uint16_t freq;
    /// RF band (@ref mac_chan_band)
    uint8_t band;
    /// Additional information (@ref mac_chan_flags)
    uint8_t flags;
    /// Max transmit power allowed on this channel (dBm)
    int8_t tx_power;
};

/// Operating Channel
struct mac_chan_op
{
    /// Band (@ref mac_chan_band)
    uint8_t band;
    /// Channel type (@ref mac_chan_bandwidth)
    uint8_t type;
    /// Frequency for Primary 20MHz channel (in MHz)
    uint16_t prim20_freq;
    /// Frequency center of the contiguous channel or center of Primary 80+80 (in MHz)
    uint16_t center1_freq;
    /// Frequency center of the non-contiguous secondary 80+80 (in MHz)
    uint16_t center2_freq;
    /// Max transmit power allowed on this channel (dBm)
    int8_t tx_power;
    /// Additional information (@ref mac_chan_flags)
    uint8_t flags;
};

/// Cipher suites (order is important as it is used by MACHW)
enum mac_cipher_suite
{
    /// 00-0F-AC 1
    MAC_CIPHER_WEP40 = 0,
    /// 00-0F-AC 2
    MAC_CIPHER_TKIP = 1,
    /// 00-0F-AC 4
    MAC_CIPHER_CCMP = 2,
    /// 00-0F-AC 5
    MAC_CIPHER_WEP104 = 3,
    /// 00-14-72 1
    MAC_CIPHER_WPI_SMS4 = 4,
    /// 00-0F-AC 6  (aka AES_CMAC)
    MAC_CIPHER_BIP_CMAC_128 = 5,

    // following cipher are not supported by MACHW
    /// 00-0F-AC 08
    MAC_CIPHER_GCMP_128,
    /// 00-0F-AC 09
    MAC_CIPHER_GCMP_256,
    /// 00-0F-AC 10
    MAC_CIPHER_CCMP_256,
    /// 00-0F-AC 11
    MAC_CIPHER_BIP_GMAC_128,
    /// 00-0F-AC 12
    MAC_CIPHER_BIP_GMAC_256,
    /// 00-0F-AC 13
    MAC_CIPHER_BIP_CMAC_256,

    MAC_CIPHER_INVALID = 0xFF
};

/// Authentication and Key Management suite
enum mac_akm_suite
{
    /// No security
    MAC_AKM_NONE,
    /// Pre RSN (WEP or WPA)
    MAC_AKM_PRE_RSN,
    /// 00-0F-AC 1
    MAC_AKM_8021X,
    /// 00-0F-AC 2
    MAC_AKM_PSK,
    /// 00-0F-AC 3
    MAC_AKM_FT_8021X,
    /// 00-0F-AC 4
    MAC_AKM_FT_PSK,
    /// 00-0F-AC 5
    MAC_AKM_8021X_SHA256,
    /// 00-0F-AC 6
    MAC_AKM_PSK_SHA256,
    /// 00-0F-AC 7
    MAC_AKM_TDLS,
    /// 00-0F-AC 8
    MAC_AKM_SAE,
    /// 00-0F-AC 9
    MAC_AKM_FT_OVER_SAE,
    /// 00-0F-AC 11
    MAC_AKM_8021X_SUITE_B,
    /// 00-0F-AC 12
    MAC_AKM_8021X_SUITE_B_192,
    /// 00-0F-AC 14
    MAC_AKM_FILS_SHA256,
    /// 00-0F-AC 15
    MAC_AKM_FILS_SHA384,
    /// 00-0F-AC 16
    MAC_AKM_FT_FILS_SHA256,
    /// 00-0F-AC 17
    MAC_AKM_FT_FILS_SHA384,
    /// 00-0F-AC 18
    MAC_AKM_OWE,

    /// 00-14-72 1
    MAC_AKM_WAPI_CERT,
    /// 00-14-72 2
    MAC_AKM_WAPI_PSK,
};

/// Scan result element, parsed from beacon or probe response frames.
struct mac_scan_result
{
    /// Scan result is valid
    bool valid_flag;
    /// Network BSSID.
    struct mac_addr bssid;
    /// Network name.
    struct mac_ssid ssid;
    /// Network type (@ref mac_bss_type).
    uint16_t bsstype;
    /// Network channel.
    struct mac_chan_def *chan;
    /// Network beacon period (in TU).
    uint16_t beacon_period;
    /// Capability information
    uint16_t cap_info;
    /// Supported AKM (bit-field of @ref mac_akm_suite)
    uint32_t akm;
    /// Group cipher (bit-field of @ref mac_cipher_suite)
    uint16_t group_cipher;
    /// Group cipher (bit-field of @ref mac_cipher_suite)
    uint16_t pairwise_cipher;
    /// RSSI of the scanned BSS (in dBm)
    uint8_t rssi;
};

/// Legacy rate 802.11 definitions
enum mac_legacy_rates
{
    /// DSSS/CCK 1Mbps
    MAC_RATE_1MBPS   =   2,
    /// DSSS/CCK 2Mbps
    MAC_RATE_2MBPS   =   4,
    /// DSSS/CCK 5.5Mbps
    MAC_RATE_5_5MBPS =  11,
    /// OFDM 6Mbps
    MAC_RATE_6MBPS   =  12,
    /// OFDM 9Mbps
    MAC_RATE_9MBPS   =  18,
    /// DSSS/CCK 11Mbps
    MAC_RATE_11MBPS  =  22,
    /// OFDM 12Mbps
    MAC_RATE_12MBPS  =  24,
    /// OFDM 18Mbps
    MAC_RATE_18MBPS  =  36,
    /// OFDM 24Mbps
    MAC_RATE_24MBPS  =  48,
    /// OFDM 36Mbps
    MAC_RATE_36MBPS  =  72,
    /// OFDM 48Mbps
    MAC_RATE_48MBPS  =  96,
    /// OFDM 54Mbps
    MAC_RATE_54MBPS  = 108
};

/// BSS Membership Selector definitions
enum mac_bss_membership
{
    /// HT PHY
    MAC_BSS_MEMBERSHIP_HT_PHY = 127,
    /// VHT PHY
    MAC_BSS_MEMBERSHIP_VHT_PHY = 126,
};

/// MAC rateset maximum length
#define MAC_RATESET_LEN 12

/// Structure containing the legacy rateset of a station
struct mac_rateset
{
    /// Number of legacy rates supported
    uint8_t     length;
    /// Array of legacy rates
    uint8_t     array[MAC_RATESET_LEN];
};

/// MAC Security Key maximum length
#define MAC_SEC_KEY_LEN 32  // TKIP keys 256 bits (max length) with MIC keys

/// Structure defining a security key
struct mac_sec_key
{
    /// Key material length
    uint8_t length;
    /// Key material
    uint32_t array[MAC_SEC_KEY_LEN/4];
};

/// Access Category enumeration
enum mac_ac
{
    /// Background
    AC_BK = 0,
    /// Best-effort
    AC_BE,
    /// Video
    AC_VI,
    /// Voice
    AC_VO,
    /// Number of access categories
    AC_MAX
};

/// Traffic ID enumeration
enum mac_tid
{
    /// TID_0. Mapped to @ref AC_BE as per 802.11 standard.
    TID_0,
    /// TID_1. Mapped to @ref AC_BK as per 802.11 standard.
    TID_1,
    /// TID_2. Mapped to @ref AC_BK as per 802.11 standard.
    TID_2,
    /// TID_3. Mapped to @ref AC_BE as per 802.11 standard.
    TID_3,
    /// TID_4. Mapped to @ref AC_VI as per 802.11 standard.
    TID_4,
    /// TID_5. Mapped to @ref AC_VI as per 802.11 standard.
    TID_5,
    /// TID_6. Mapped to @ref AC_VO as per 802.11 standard.
    TID_6,
    /// TID_7. Mapped to @ref AC_VO as per 802.11 standard.
    TID_7,
    /// Non standard Management TID used internally
    TID_MGT,
    /// Number of TID supported
    TID_MAX
};

/// MCS bitfield maximum size (in bytes)
#define MAX_MCS_LEN 16 // 16 * 8 = 128

/// MAC HT capability information element
struct mac_htcapability
{
    /// HT capability information
    uint16_t       ht_capa_info;
    /// A-MPDU parameters
    uint8_t        a_mpdu_param;
    /// Supported MCS
    uint8_t        mcs_rate[MAX_MCS_LEN];
    /// HT extended capability information
    uint16_t       ht_extended_capa;
    /// Beamforming capability information
    uint32_t       tx_beamforming_capa;
    /// Antenna selection capability information
    uint8_t        asel_capa;
};

/// MAC VHT capability information element
struct mac_vhtcapability
{
    /// VHT capability information
    uint32_t       vht_capa_info;
    /// RX MCS map
    uint16_t       rx_mcs_map;
    /// RX highest data rate
    uint16_t       rx_highest;
    /// TX MCS map
    uint16_t       tx_mcs_map;
    /// TX highest data rate
    uint16_t       tx_highest;
};

/// Length (in bytes) of the MAC HE capability field
#define MAC_HE_MAC_CAPA_LEN 6
/// Length (in bytes) of the PHY HE capability field
#define MAC_HE_PHY_CAPA_LEN 11
/// Maximum length (in bytes) of the PPE threshold data
#define MAC_HE_PPE_THRES_MAX_LEN 25

/// Structure listing the per-NSS, per-BW supported MCS combinations
struct mac_he_mcs_nss_supp
{
    /// per-NSS supported MCS in RX, for BW <= 80MHz
    uint16_t rx_mcs_80;
    /// per-NSS supported MCS in TX, for BW <= 80MHz
    uint16_t tx_mcs_80;
    /// per-NSS supported MCS in RX, for BW = 160MHz
    uint16_t rx_mcs_160;
    /// per-NSS supported MCS in TX, for BW = 160MHz
    uint16_t tx_mcs_160;
    /// per-NSS supported MCS in RX, for BW = 80+80MHz
    uint16_t rx_mcs_80p80;
    /// per-NSS supported MCS in TX, for BW = 80+80MHz
    uint16_t tx_mcs_80p80;
};

/// MAC HE capability information element
struct mac_hecapability
{
    /// MAC HE capabilities
    uint8_t mac_cap_info[MAC_HE_MAC_CAPA_LEN];
    /// PHY HE capabilities
    uint8_t phy_cap_info[MAC_HE_PHY_CAPA_LEN];
    /// Supported MCS combinations
    struct mac_he_mcs_nss_supp mcs_supp;
    /// PPE Thresholds data
    uint8_t ppe_thres[MAC_HE_PPE_THRES_MAX_LEN];
};

/// Station flags
enum mac_sta_flags
{
    /// Bit indicating that a STA has QoS (WMM) capability
    STA_QOS_CAPA = 1 << 0,
    /// Bit indicating that a STA has HT capability
    STA_HT_CAPA = 1 << 1,
    /// Bit indicating that a STA has VHT capability
    STA_VHT_CAPA = 1 << 2,
    /// Bit indicating that a STA has MFP capability
    STA_MFP_CAPA = 1 << 3,
    /// Bit indicating that the STA included the Operation Notification IE
    STA_OPMOD_NOTIF = 1 << 4,
    /// Bit indicating that a STA has HE capability
    STA_HE_CAPA = 1 << 5,
};

/// Connection flags
enum mac_connection_flags
{
    /// Flag indicating whether the control port is controlled by host or not
    CONTROL_PORT_HOST = 1 << 0,
    /// Flag indicating whether the control port frame shall be sent unencrypted
    CONTROL_PORT_NO_ENC = 1 << 1,
    /// Flag indicating whether HT and VHT shall be disabled or not
    DISABLE_HT = 1 << 2,
    /// Flag indicating whether WPA or WPA2 authentication is in use
    WPA_WPA2_IN_USE = 1 << 3,
    /// Flag indicating whether MFP is in use
    MFP_IN_USE = 1 << 4,
};


/* Sync with mac.h */

/*
 * DEFINES
 ****************************************************************************************
 */
/// duration of a Time Unit in microseconds
#define TU_DURATION                     1024

/// Mask to test if it's a basic rate - BIT(7)
#define MAC_BASIC_RATE                  0x80

/// Mask for extracting/checking word alignment
#define WORD_ALIGN                      3

/**
 ****************************************************************************************
 * Compare two MAC addresses.
 * The MAC addresses MUST be 16 bit aligned.
 * @param[in] addr1_ptr Pointer to the first MAC address.
 * @param[in] addr2_ptr Pointer to the second MAC address.
 * @return True if equal, false if not.
 ****************************************************************************************
 */
#define MAC_ADDR_CMP(addr1_ptr, addr2_ptr)                                              \
    ((*(((uint16_t*)(addr1_ptr)) + 0) == *(((uint16_t*)(addr2_ptr)) + 0)) &&            \
     (*(((uint16_t*)(addr1_ptr)) + 1) == *(((uint16_t*)(addr2_ptr)) + 1)) &&            \
     (*(((uint16_t*)(addr1_ptr)) + 2) == *(((uint16_t*)(addr2_ptr)) + 2)))

/**
 ****************************************************************************************
 * Compare two MAC addresses whose alignment is not known.
 * @param[in] __a1 Pointer to the first MAC address.
 * @param[in] __a2 Pointer to the second MAC address.
 * @return True if equal, false if not.
 ****************************************************************************************
 */
#define MAC_ADDR_CMP_PACKED(__a1, __a2)                                                 \
    (memcmp(__a1, __a2, MAC_ADDR_LEN) == 0)

/**
 ****************************************************************************************
 * Copy a MAC address.
 * The MAC addresses MUST be 16 bit aligned.
 * @param[in] addr1_ptr Pointer to the destination MAC address.
 * @param[in] addr2_ptr Pointer to the source MAC address.
 ****************************************************************************************
 */
#define MAC_ADDR_CPY(addr1_ptr, addr2_ptr)                                              \
    *(((uint16_t*)(addr1_ptr)) + 0) = *(((uint16_t*)(addr2_ptr)) + 0);                  \
    *(((uint16_t*)(addr1_ptr)) + 1) = *(((uint16_t*)(addr2_ptr)) + 1);                  \
    *(((uint16_t*)(addr1_ptr)) + 2) = *(((uint16_t*)(addr2_ptr)) + 2)

/**
 ****************************************************************************************
 * Compare two SSID.
 * @param[in] ssid1_ptr Pointer to the first SSID structure.
 * @param[in] ssid2_ptr Pointer to the second SSID structure.
 * @return True if equal, false if not.
 ****************************************************************************************
 */
#define MAC_SSID_CMP(ssid1_ptr,ssid2_ptr)                                               \
    (((ssid1_ptr)->length == (ssid2_ptr)->length) &&                                    \
     (memcmp((&(ssid1_ptr)->array[0]), (&(ssid2_ptr)->array[0]), (ssid1_ptr)->length) == 0))

/**
 ****************************************************************************************
 * Check if MAC address is a group address: test the multicast bit.
 * @param[in] mac_addr_ptr Pointer to the MAC address to be checked.
 * @return 0 if unicast address, 1 otherwise
 ****************************************************************************************
 */
#define MAC_ADDR_GROUP(mac_addr_ptr) ((*((uint8_t *)(mac_addr_ptr))) & 1)

#define MAC_ADDR_VALID(mac_addr_ptr) (mac_addr_ptr[0] | mac_addr_ptr[1] | mac_addr_ptr[2] | mac_addr_ptr[3] | mac_addr_ptr[4] | mac_addr_ptr[5])
/// MAC HT operation element
struct mac_htoprnelmt
{
    /// Primary channel information
    uint8_t     prim_channel;
    /// HT operation information 1
    uint8_t     ht_oper_1;
    /// HT operation information 2
    uint16_t    ht_oper_2;
    /// HT operation information 3
    uint16_t    ht_oper_3;
    /// Basic MCS set
    uint8_t     mcs_rate[MAX_MCS_LEN];

};

/// MU EDCA Parameter Set Element
struct mac_mu_edca_param_set
{
    /// Per-AC MU EDCA parameters
    uint32_t        ac_param[AC_MAX];
    /// QoS information
    uint8_t         qos_info;
    /// Parameter set counter
    uint8_t         param_set_cnt;
};

/// EDCA Parameter Set Element
struct mac_edca_param_set
{
    /// Per-AC EDCA parameters
    uint32_t        ac_param[AC_MAX];
    /// QoS information
    uint8_t         qos_info;
    /// Admission Control Mandatory bitfield
    uint8_t         acm;
    /// Parameter set counter
    uint8_t         param_set_cnt;
};

/*
 * GLOBAL VARIABLES
 ****************************************************************************************
 */
/// Array converting a TID to its associated AC
extern const uint8_t mac_tid2ac[];

/// Array converting an AC to its corresponding bit in the QoS Information field
extern const uint8_t mac_ac2uapsd[];

/// Array converting an ACI to its corresponding AC. See Table 9-136 in 802.11-2016
extern const uint8_t mac_aci2ac[];

/// Array converting an AC to its corresponding ACI. See Table 9-136 in 802.11-2016
extern const uint8_t mac_ac2aci[];

/// Array converting a MAC HW rate id into its corresponding standard rate value
extern const uint8_t mac_id2rate[];

/// Constant value corresponding to the Broadcast MAC address
extern const struct mac_addr mac_addr_bcst;


/**
 ****************************************************************************************
 * Get the value of a bit field in the HE MAC capability element.
 * @param[in] he_cap Pointer to the HE capability structure
 * @param[in] field  Bit field to be read
 * @return The value of the field
 ****************************************************************************************
 */
#define HE_MAC_CAPA_VAL_GET(he_cap, field)    co_val_get((he_cap)->mac_cap_info,         \
                                                         HE_MAC_CAPA_##field##_OFT,      \
                                                         HE_MAC_CAPA_##field##_WIDTH)

/**
 ****************************************************************************************
 * Set the value of a bit field in the HE MAC capability element.
 * @param[in] he_cap Pointer to the HE capability structure
 * @param[in] field Bit field to be written
 * @param[in] val The value of the field
 ****************************************************************************************
 */
#define HE_MAC_CAPA_VAL_SET(he_cap, field, val) co_val_set((he_cap)->mac_cap_info,       \
                                                           HE_MAC_CAPA_##field##_OFT,    \
                                                           HE_MAC_CAPA_##field##_WIDTH,  \
                                                           HE_MAC_CAPA_##field##_##val)

/**
 ****************************************************************************************
 * Test if a bit in the HE MAC capability element is set.
 * @param[in] he_cap Pointer to the HE capability structure
 * @param[in] bit    Bit to be set
 * @return true if set, false otherwise
 ****************************************************************************************
 */
#define HE_MAC_CAPA_BIT_IS_SET(he_cap, bit)   co_bit_is_set((he_cap)->mac_cap_info,      \
                                                            HE_MAC_CAPA_##bit##_POS)

/**
 ****************************************************************************************
 * Set a bit in the HE MAC capability element.
 * @param[in] he_cap Pointer to the HE capability structure
 * @param[in] bit    Bit to be set
 ****************************************************************************************
 */
#define HE_MAC_CAPA_BIT_SET(he_cap, bit)      co_bit_set((he_cap)->mac_cap_info,         \
                                                          HE_MAC_CAPA_##bit##_POS)

/**
 ****************************************************************************************
 * Clear a bit in the HE MAC capability element.
 * @param[in] he_cap Pointer to the HE capability structure
 * @param[in] bit    Bit to be cleared
 ****************************************************************************************
 */
#define HE_MAC_CAPA_BIT_CLR(he_cap, bit)      co_bit_clr((he_cap)->mac_cap_info,         \
                                                         HE_MAC_CAPA_##bit##_POS)

/**
 ****************************************************************************************
 * Get the value of a bit field in the HE PHY capability element.
 * @param[in] he_cap Pointer to the HE capability structure
 * @param[in] field  Bit field to be read
 * @return The value of the field
 ****************************************************************************************
 */
#define HE_PHY_CAPA_VAL_GET(he_cap, field)    co_val_get((he_cap)->phy_cap_info,         \
                                                         HE_PHY_CAPA_##field##_OFT,      \
                                                         HE_PHY_CAPA_##field##_WIDTH)

/**
 ****************************************************************************************
 * Set the value of a bit field in the HE PHY capability element.
 * @param[in] he_cap Pointer to the HE capability structure
 * @param[in] field Bit field to be written
 * @param[in] val The value of the field
 ****************************************************************************************
 */
#define HE_PHY_CAPA_VAL_SET(he_cap, field, val) co_val_set((he_cap)->phy_cap_info,       \
                                                           HE_PHY_CAPA_##field##_OFT,    \
                                                           HE_PHY_CAPA_##field##_WIDTH,  \
                                                           HE_PHY_CAPA_##field##_##val)

/**
 ****************************************************************************************
 * Test if a bit in the HE PHY capability element is set.
 * @param[in] he_cap Pointer to the HE capability structure
 * @param[in] bit    Bit to be set
 * @return true if set, false otherwise
 ****************************************************************************************
 */
#define HE_PHY_CAPA_BIT_IS_SET(he_cap, bit)   co_bit_is_set((he_cap)->phy_cap_info,      \
                                                            HE_PHY_CAPA_##bit##_POS)

/**
 ****************************************************************************************
 * Set a bit in the HE PHY capability element.
 * @param[in] he_cap Pointer to the HE capability structure
 * @param[in] bit    Bit to be set
 ****************************************************************************************
 */
#define HE_PHY_CAPA_BIT_SET(he_cap, bit)      co_bit_set((he_cap)->phy_cap_info,         \
                                                         HE_PHY_CAPA_##bit##_POS)

/**
 ****************************************************************************************
 * Clear a bit in the HE PHY capability element.
 * @param[in] he_cap Pointer to the HE capability structure
 * @param[in] bit    Bit to be cleared
 ****************************************************************************************
 */
#define HE_PHY_CAPA_BIT_CLR(he_cap, bit)      co_bit_clr((he_cap)->phy_cap_info,         \
                                                         HE_PHY_CAPA_##bit##_POS)


/* Sync with llc.h */

/** @name LLC field definitions
 * LLC = DSAP + SSAP + CTRL
 * @note: The 0xAA values indicate the presence of the SNAP
 */
#define LLC_LLC_LEN                  3
#define LLC_DSAP                     0xAA
#define LLC_SSAP                     0xAA
#define LLC_CTRL                     0x03

/** @name SNAP field definitions
 * SNAP = OUI + ETHER_TYPE
 */
#define LLC_SNAP_LEN                 5
#define LLC_OUI_LEN                  3

/** @name 802.2 Header definitions
 * The 802.2 Header is the LLC + the SNAP
 */
#define LLC_802_2_HDR_LEN            (LLC_LLC_LEN + LLC_SNAP_LEN)


/** @name 802.2 Ethernet definitions */
/// Ethernet MTU
#define LLC_ETHER_MTU                1500
/// Size of the Ethernet header
#define LLC_ETHER_HDR_LEN            14
/// Size of the Ethernet type
#define LLC_ETHERTYPE_LEN            2
/// Offset of the Ethernet type within the header
#define LLC_ETHERTYPE_LEN_OFT        12
/// Offset of the EtherType in the 802.2 header
#define LLC_802_2_ETHERTYPE_OFT      6
/// Maximum value of the frame length
#define LLC_FRAMELENGTH_MAXVALUE     0x600

/** @name Useful EtherType values */
#define LLC_ETHERTYPE_APPLETALK      0x809B
#define LLC_ETHERTYPE_IPX            0x8137
#define LLC_ETHERTYPE_AARP           0x80F3
#define LLC_ETHERTYPE_EAP_T          0x888E
#define LLC_ETHERTYPE_802_1Q         0x8100
#define LLC_ETHERTYPE_IP             0x0800
#define LLC_ETHERTYPE_ARP            0x0806

/** @name 802_1Q VLAN header definitions */
#define LLC_802_1Q_TCI_VID_MASK       0x0FFF
#define LLC_802_1Q_TCI_PRI_MASK       0xE000
#define LLC_802_1Q_TCI_CFI_MASK       0x1000
#define LLC_802_1Q_HDR_LEN            4
#define LLC_802_1Q_VID_NULL           0
#define LLC_OFFSET_ETHERTYPE          12
#define LLC_OFFSET_IPV4_PRIO          15
#define LLC_OFFSET_802_1Q_TCI         14
/// @}


/*
 * TYPES DEFINITION
 ****************************************************************************************
 */

/// LLC/SNAP structure
struct llc_snap_short
{
    /// DSAP + SSAP fieldsr
    uint16_t dsap_ssap;
    /// LLC control + OUI byte 0
    uint16_t control_oui0;
    /// OUI bytes 1 and 2
    uint16_t oui1_2;
};

/// LLC/SNAP structure
struct llc_snap
{
    /// DSAP + SSAP fieldsr
    uint16_t dsap_ssap;
    /// LLC control + OUI byte 0
    uint16_t control_oui0;
    /// OUI bytes 1 and 2
    uint16_t oui1_2;
    /// Protocol
    uint16_t proto_id;
};


/* Sync with phy.h */

/// 5G lower bound freq
#define PHY_FREQ_5G 5000

/// Macro retrieving the channel of the phy channel info
/// @param[in] __x phy channel info 1 value.
#define PHY_INFO_CHAN(__x) (((__x.info1) & 0xFFFF0000) >> 16)
/// Macro retrieving the HT length of the RX vector
/// @param[in] __x RX bytes 12 - 9 of Receive Vector 1.
#define RXVEC_HTLENGTH_0(__x)    (((__x) & 0x0000FFFF))
/// Macro retrieving the modulation format of the RX vector
/// @param[in] __x bytes 4 - 1 of Receive Vector 1.
#define RXVEC_FORMATMOD(__x)   (((__x) & 0x0000000F))

/**
 ****************************************************************************************
 * @brief Compute the channel number from its center frequency and its band
 * @param[in] band  RF band (must be @ref PHY_BAND_2G4 or @ref PHY_BAND_5G)
 * @param[in] freq  Center frequency of the channel
 *
 * @return The channel number
 ****************************************************************************************
 */
__INLINE int phy_freq_to_channel(uint8_t band, uint16_t freq)
{
    int channel = 0;

    do
    {
        //2.4.GHz
        if (band == PHY_BAND_2G4)
        {
            // Check if frequency is in the expected range
            if ((freq < 2412) || (freq > 2484))
                break;

            // Compute the channel number
            if (freq == 2484)
                channel = 14;
            else
                channel = (freq - 2407)/5;
        }
        //5 GHz
        else if (band == PHY_BAND_5G)
        {
            // Check if frequency is in the expected range
            if ((freq < 5005) || (freq > 5825))
                break;

            // Compute the channel number
            channel = (freq - PHY_FREQ_5G)/5;
        }
    } while(0);

    return (channel);
}

__INLINE uint16_t phy_channel_to_freq(uint8_t band, int channel)
{
    if ((band == PHY_BAND_2G4) && (channel >= 1) && (channel <= 14))
    {
        if (channel == 14)
            return 2484;
        else
            return 2407 + channel * 5;
    }
    else if ((band == PHY_BAND_5G) && (channel >= 1) && (channel <= 165))
    {
        return PHY_FREQ_5G + channel * 5;
    }
    return 0;
}

#endif // _MAC_H_
