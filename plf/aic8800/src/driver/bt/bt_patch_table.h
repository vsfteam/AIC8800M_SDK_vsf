#ifndef _BT_PATCH_TABLE_H_
#define _BT_PATCH_TABLE_H_

#include <stdint.h>

typedef struct {
    uint32_t dimension;
    uint32_t *ptr;
    uint32_t size;
} bt_patch_tbl_t;

typedef void(*bt_patch_cb_t)(void);

extern uint32_t fw_patch_extra_addr;
extern uint32_t minisys_patch_extra_addr;

extern bt_patch_tbl_t *bt_patch_tbl_a1;
extern bt_patch_tbl_t *bt_patch_tbl_a2;

extern bt_patch_tbl_t *bt_patch_tbl_b1;
extern bt_patch_tbl_t *bt_patch_tbl_b2;

extern bt_patch_tbl_t *bt_patch_tbl_c1;
extern bt_patch_tbl_t *bt_patch_tbl_c2;

extern bt_patch_tbl_t *bt_patch_tbl_d1;
extern bt_patch_tbl_t *bt_patch_tbl_d2;

extern uint32_t bt_patch_tbl_a1_size;
extern uint32_t bt_patch_tbl_a2_size;
extern uint32_t bt_patch_tbl_b1_size;
extern uint32_t bt_patch_tbl_b2_size;
extern uint32_t bt_patch_tbl_c1_size;
extern uint32_t bt_patch_tbl_c2_size;
extern uint32_t bt_patch_tbl_d1_size;
extern uint32_t bt_patch_tbl_d2_size;

void bt_patch_prepare(void);

#endif
