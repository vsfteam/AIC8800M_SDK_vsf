#ifndef _WLAN_IF_H_
#define _WLAN_IF_H_

#include "mac.h"

extern uint8_t is_fixed_ip;
extern uint32_t fixed_ip, fixed_gw, fixed_mask;

/* timeout_ms: 0 -> 10000, -1 -> no timeout, (timeout_ms > 0 && bit0 is 1) -> wep 
 * return value: -1:password < 8, -6: dhcp fail
 */
int wlan_start_sta(uint8_t *ssid, uint8_t *pw, int timeout_ms);

int wlan_start_ap(uint8_t band, uint8_t *ssid, uint8_t *pw);

int wlan_disconnect_sta(uint8_t idx);

int wlan_stop_ap(void);

int wlan_start_wps(void);

int wlan_dhcp(net_if_t *net_if);

int wlan_get_connect_status(void);

int wlan_ap_switch_channel(uint8_t chan_num);

int wlan_ap_disassociate_sta(struct mac_addr *macaddr);

/* should be called before 'wlan_start_ap', default (192 | (168 << 8) | (88 << 16) | (1 << 24)) */
void set_ap_ip_addr(uint32_t new_ip_addr);
uint32_t get_ap_ip_addr(void);

/* Default: 255.255.255.0 -> 0x00FFFFFF */
void set_ap_subnet_mask(uint32_t new_mask);
uint32_t get_ap_subnet_mask(void);

/* Beacon interval, default: 100 */
void set_ap_bcn_interval(uint32_t bcn_interval_ms);

void set_ap_channel_num(uint8_t num);

void set_ap_hidden_ssid(uint8_t val);

void set_ap_enable_he_rate(uint8_t en);

void set_ap_allow_sta_inactivity_s(uint8_t s);

uint8_t *get_selected_channel_numbers(uint8_t band);

int wlan_ap_generate_ssid_pw_for_pairing(char *ssid, char *pw);
int wlan_sta_auto_pairing(char *ssid, char *pw, int8_t times);

#if (PLF_BT_STACK || PLF_BLE_STACK) && (PLF_WIFI_STACK)
__WEAK void wb_coex_wifi_on_set(int on);
__WEAK void wb_coex_wifi_connected_set(int connected);
__WEAK int wb_coex_bt_connected_get(void);
__WEAK int wb_coex_bt_a2dp_on_get(void);
__WEAK int wb_coex_bt_sco_on_get(void);
#endif
void set_sta_connect_chan_num(uint32_t chan_num);
uint32_t get_sta_connect_chan_freq(void);

extern uint8_t disconnected_by_user;
#endif /* _WLAN_IF_H_ */
