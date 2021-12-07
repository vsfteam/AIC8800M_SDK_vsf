#ifndef _BT_COMMON_CONFIG_H_
#define _BT_COMMON_CONFIG_H_

uint32_t bt_common_get_defalut_fw_addr(void);
/*
 * get bt hci ipc ram base
 * @return bt hci ipc ram base;
 */
uint32_t *bt_common_get_default_ram_base(void);
struct aicbt_patch_init_desc *bt_common_get_patch_init_desc(void);
/*
 * bt_common_change_fw_load_in_ram
 * only used for debug fw in ram addr ,fw in rom will mask this function.
 */
void bt_common_change_fw_load_in_ram(void);

#endif
