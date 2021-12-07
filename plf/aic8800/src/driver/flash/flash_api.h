#ifndef _FLASH_API_H_
#define _FLASH_API_H_
#include <stdint.h>
#include "plf.h"

#ifdef CFG_BLE_STACK
#include "gap.h"
#include "gapc_task.h"
#include "co_bt_defines.h"
#endif //CFG_BLE_STACK

#if PLF_BT_STACK == 1
#include "target_config.h"
#include "bt_types_def.h"
#define MAX_BD_MUN    5
#endif

/**
 * Structs
 */
/* calib info */
typedef struct {
    unsigned char cap;
    unsigned char cap_fine;
    unsigned char PADDING0[2];
} xtal_cap_info_t;

typedef struct {
    signed char dsss_txpwr_ofst;
    signed char ofdm_txpwr_ofst;
    unsigned char PADDING0[2];
} wifi_txpwr_info_t;

typedef struct {
    unsigned int magic_num; /* "CALI" */
    unsigned int info_flag;
    unsigned int RESERVED_08;
    unsigned int RESERVED_0C;
    xtal_cap_info_t xtal;
    wifi_txpwr_info_t wifi2g4_txpwr[3]; // for chan 1/7/13
    wifi_txpwr_info_t wifi5g_txpwr[5];  // for chan 36/68/100/132/164
} calib_info_t;

/* wifi info */
typedef struct {
    char ssid[48];
    char passwd[64];
} wifi_ssidpw_t;

typedef struct {
    unsigned int  config;
    unsigned char mac_addr[6];
    unsigned char PADDING0[2];
    wifi_ssidpw_t ssidpw;
    //unsigned char pmk[32];
} wifi_sta_info_t;

typedef struct {
    unsigned int  config;
    unsigned char mac_addr[6];
    unsigned char PADDING0[2];
    wifi_ssidpw_t ssidpw;
    unsigned int channel;
} wifi_ap_info_t;

typedef struct {
    unsigned int lease_time;
    unsigned int dhcp_start;
    unsigned int dhcp_end;
} wifi_lwip_dhcps_t;

typedef struct {
    signed int   time_zone;
} wifi_lwip_sntp_t;

typedef struct {
    unsigned int config;
    wifi_lwip_dhcps_t dhcps;
    unsigned int dns_server;
    wifi_lwip_sntp_t sntp;
} wifi_lwip_info_t;

/* wifi sta config */
#define WIFI_STA_CONFIG_STA_AUTO_CONNECT_EN             CO_BIT(0)

/* wifi ap config */
#define WIFI_AP_CONFIG_FORCED_AP_MODE_EN                CO_BIT(0)

/* wifi lwip config */
#define WIFI_LWIP_CONFIG_SNTP_CLIENT_AUTO_CONNECT_EN    CO_BIT(0)

typedef struct {
    unsigned int magic_num; /* "WIFI" */
    unsigned int info_flag;
    unsigned int RESERVED_08;
    unsigned int RESERVED_0C;
    wifi_sta_info_t  sta_info;
    wifi_ap_info_t   ap_info;
    wifi_lwip_info_t lwip_info;
} wifi_info_t;

/* btdm info */
typedef struct
{
    uint8_t bt_flash_erased;
    uint8_t factory_mode_setting;
    uint8_t local_bt_addr[6];
    uint8_t local_ble_addr[6];
    uint16_t reserved;
    char local_dev_name[32];
    uint8_t pincode[16];
} bt_factory_info_t;

#if PLF_BT_STACK == 1
#ifndef BTDEVRECORD
#define BTDEVRECORD
typedef struct _BtDeviceRecord
{
    BT_ADDR  bdAddr;
    bool        trusted;
    uint8_t     linkKey[16];
    uint8_t     keyType;
    uint8_t     pinLen;
} BtDeviceRecord;
#endif
typedef struct list_node_t {
  struct list_node_t *prev;
  struct list_node_t *next;
  void *data;
} list_node_t;

typedef struct {
  list_node_t *head;
  uint8_t length;
} bt_dev_list;

typedef  struct {
    bool hf_state;
    bool a2dp_state;
    uint8_t a2dp_role;
    uint8_t a2dp_codectype;
    int8_t peer_a2dp_vol;
    int8_t peer_hfp_vol;
    uint32_t cod;
}btdev_info;

typedef struct {
    list_node_t node;
    BtDeviceRecord record;
    btdev_info device_info;
} bt_dev_info_t;

typedef struct {
    uint8_t addr_type;
    BT_ADDR bleaddr;
} ble_dev_info_t;

typedef struct {
    uint8_t init_need; // need init when value not equal to 0xEE
    uint8_t flush_need;
#if APP_SUPPORT_TWS == 1
    uint8_t flash_tws_role;
    ble_dev_info_t ble_dev_info;
#endif
    bt_dev_list   bt_list;
    bt_dev_info_t bt_dev_info[MAX_BD_MUN];
} bt_flash_info_t;
#endif

#ifdef CFG_BLE_STACK
// Local key length
#define LOC_KEY_LEN           (0x10)
typedef struct gapc_ltk gapc_ltk_t;
#endif // (CFG_BLE_STACK)

typedef struct {
    unsigned int magic_num; /* "BTDM" */
    unsigned int info_flag;
    unsigned int RESERVED_08;
    unsigned int RESERVED_0C;
    bt_factory_info_t bt_factory;
#if PLF_BT_STACK == 1
    bt_flash_info_t bt_info;
#endif
#ifdef CFG_BLE_STACK
    gapc_ltk_t le_ltk;
    uint8_t loc_irk[LOC_KEY_LEN];
    uint8_t bond_status;
    uint16_t ntf_cfg;
    uint8_t ble_rand_add[BD_ADDR_LEN];
#endif
} btdm_info_t;

/**
 * Enums
 */
typedef enum {
    INFO_FLAG_INVALID =  1,
    INFO_READ_DONE    =  0,
    MAGIC_NUM_ERR     = -1,
    INFO_LEN_ERR      = -2,
} INFO_READ_STATUS_T;

/**
 * Get chip size as bytes
 */
unsigned int flash_chip_size_get(void);

/**
 * Erase all flash except for reserved area
 */
void flash_chip_erase(void);

/**
 * Erase flash
 */
int flash_erase(void *a4k, unsigned int len);

/**
 * Write flash
 */
int flash_write(void *adr, unsigned int len, void *buf);

/**
 * Read flash
 */
int flash_read(void *adr, unsigned int len, void *buf);

/**
 * Invalid all flash cache
 */
void flash_cache_invalid_all(void);

/**
 * Invalid the range of flash cache
 */
void flash_cache_invalid_range(void *adr, unsigned int len);
unsigned int flash_crc32(void *adr, unsigned int len);


/**
 * calib info api(read only)
 */
int flash_calib_xtal_cap_read(xtal_cap_info_t *xtal_cap);
int flash_calib_wifi2g4_txpwr_read(wifi_txpwr_info_t *txpwr);
int flash_calib_wifi5g_txpwr_read(wifi_txpwr_info_t *txpwr);

/**
 * wifi info api
 */
int flash_wifi_sta_config_read(unsigned int *config);
void flash_wifi_sta_config_write(unsigned int *config);
int flash_wifi_sta_macaddr_read(unsigned char *addr);
void flash_wifi_sta_macaddr_write(unsigned char *addr);
int flash_wifi_sta_ssidpw_read(char *ssid, char *pass);
void flash_wifi_sta_ssidpw_write(char *ssid, char *pass);
int flash_wifi_ap_config_read(unsigned int *config);
void flash_wifi_ap_config_write(unsigned int *config);
int flash_wifi_ap_macaddr_read(unsigned char *addr);
void flash_wifi_ap_macaddr_write(unsigned char *addr);
int flash_wifi_ap_ssidpw_read(char *ssid, char *pass);
void flash_wifi_ap_ssidpw_write(char *ssid, char *pass);
int flash_wifi_ap_channel_read(unsigned int *channel);
void flash_wifi_ap_channel_write(unsigned int channel);
int flash_wifi_lwip_config_read(unsigned int *config);
void flash_wifi_lwip_config_write(unsigned int *config);
int flash_wifi_lwip_dhcps_read(unsigned int *lease_time, unsigned int *dhcp_start, unsigned int *dhcp_end);
void flash_wifi_lwip_dhcps_write(unsigned int lease_time, unsigned int dhcp_start, unsigned int dhcp_end);
int flash_wifi_lwip_dnsserv_read(unsigned int *dns_server);
void flash_wifi_lwip_dnsserv_write(unsigned int dns_server);
int flash_wifi_lwip_sntp_read(signed int *time_zone);
void flash_wifi_lwip_sntp_write(signed int time_zone);
void flash_wifi_info_remove_all(void);
void flash_wifi_info_remove_ssidpw(void);

unsigned int flash_strlen(unsigned char *str,unsigned char max_len);

/**
 * btdm info api
 */
int flash_btdm_bt_factory_read(void *buf, unsigned int len);
void flash_btdm_bt_factory_write(const void *buf, unsigned int len);

#if PLF_BT_STACK == 1
/**
 ****************************************************************************************
 * @brief * Doubly-linked list initialize .
 *
 * @param Doubly-linked list Entry.
 *
 ****************************************************************************************
 */
void bt_initializeList(list_node_t* list);
/**
 ****************************************************************************************
 * @brief * Doubly-linked list insert node in Tail .
 *
 * @param  tail: Doubly-linked list.   entry: node which want to be inserted in tail of Doubly-linked list
 *
 ****************************************************************************************
 */
void bt_insertTailList(list_node_t* tail, list_node_t* entry);
/**
 ****************************************************************************************
 * @brief * Doubly-linked list insert node in Head .
 *
 * @param  head: Doubly-linked list.   entry: node which want to be inserted in head of Doubly-linked list
 *
 ****************************************************************************************
 */
void bt_insertHeadList(list_node_t* head, list_node_t* entry);
/**
 ****************************************************************************************
 * @brief * remove current Node form a Doubly-linked list .
 *
 * @param   Node.
 *
 ****************************************************************************************
 */
void bt_removeNode(list_node_t* node);
/**
 ****************************************************************************************
 * @brief * remove current Node form a Doubly-linked list ,and return next Node's ptr .
 *
 * @param
 *
 * @return  Node which is next after removed Node.
 ****************************************************************************************
 */
list_node_t* bt_removeHeadNode(list_node_t* head);
/**
 ****************************************************************************************
 * @brief * Get and remove Node form the Head of a Doubly-linked list .
 *
 * @param Doubly-linked list.
 *
 * @return Head of a Doubly-linked list
 ****************************************************************************************
 */
list_node_t* bt_removeHeadList(list_node_t* head);
/**
 ****************************************************************************************
 * @brief * Doubly-linked list is Empty .
 *
 * @param Doubly-linked list.
 *
 * @return true: empty  false: not empty
 ****************************************************************************************
 */
bool bt_listIsEmpty(list_node_t *head);

bt_flash_info_t * flash_btdm_bt_dev_read(void);
void flash_btdm_bt_dev_write(void);
#endif

#ifdef CFG_BLE_STACK
int flash_btdm_le_ltk_read(gapc_ltk_t *le_ltk);
void flash_btdm_le_ltk_write(gapc_ltk_t *le_ltk);
void flash_btdm_le_ltk_remove(void);

int flash_btdm_le_loc_irk_read(uint8_t *loc_irk);
void flash_btdm_le_loc_irk_write(uint8_t *loc_irk);
void flash_btdm_le_loc_irk_remove(void);

int flash_btdm_le_periph_bonded_read(uint8_t *bond_status);
void flash_btdm_le_periph_bonded_write(uint8_t *bond_status);
void flash_btdm_le_periph_bonded_remove(void);

int flash_btdm_le_mouse_ntf_cfg_read(uint8_t *ntf_cfg);
void flash_btdm_le_mouse_ntf_cfg_write(uint8_t *ntf_cfg);
void flash_btdm_le_mouse_ntf_cfg_remove(void);

int flash_btdm_le_rand_addr_read(uint8_t *le_addr);
void flash_btdm_le_rand_addr_write(uint8_t *le_addr);
void flash_btdm_le_rand_addr_remove(void);

void flash_btdm_le_info_remove_all(void);
#endif // CFG_BLE_STACK

int flash_user_data_addr_length_set(unsigned int addr, unsigned int len);
int flash_user_data_read(void *buf, unsigned int len);
int flash_user_data_write(void *buf, unsigned int len);

#endif /* _FLASH_API_H_ */
