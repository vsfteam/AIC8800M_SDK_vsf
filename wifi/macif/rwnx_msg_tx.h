/**
 ****************************************************************************************
 *
 * @file rwnx_msg_tx.h
 *
 * @brief TX function declarations
 *
 * Copyright (C) RivieraWaves 2012-2019
 *
 ****************************************************************************************
 */

#ifndef _RWNX_MSG_TX_H_
#define _RWNX_MSG_TX_H_

#include "rwnx_defs.h"

/*
 * c.f LMAC/src/co/mac/mac_frame.h
 */
#define MAC_RSNIE_CIPHER_WEP40    0x00
#define MAC_RSNIE_CIPHER_TKIP     0x01
#define MAC_RSNIE_CIPHER_CCMP     0x02
#define MAC_RSNIE_CIPHER_WEP104   0x03
#define MAC_RSNIE_CIPHER_SMS4     0x04
#define MAC_RSNIE_CIPHER_AES_CMAC 0x05

int rwnx_send_reset(void);
int rwnx_send_start(struct mm_start_req *start);
int rwnx_send_version_req(struct mm_version_cfm *cfm);
int rwnx_send_add_if(unsigned char *mac, uint8_t iftype, bool p2p, struct mm_add_if_cfm *cfm);
int rwnx_send_remove_if(uint8_t vif_index);
int rwnx_send_me_chan_config_req(struct me_chan_config_req *chan_cfg);
int rwnx_send_me_config_req(struct me_config_req *cfg_req);
int rwnx_set_hw_idle_req(uint8_t idle);
int rwnx_set_disable_agg_req(uint8_t agg_disable, uint8_t sta_idx);
int rwnx_set_coex_config_req(uint8_t disable_coexnull, uint8_t enable_periodic_timer, uint8_t enable_nullcts,
                                    uint8_t coex_timeslot_set, uint32_t param1, uint32_t param2);
int rwnx_set_rf_config_req(void);
int rwnx_set_rf_calib_req(struct mm_set_rf_calib_cfm *cfm);
int rwnx_send_msg_tx(lmac_task_id_t dst_id, lmac_msg_id_t msg_id, uint16_t msg_len, void *msg, int reqcfm, lmac_msg_id_t reqid, void *cfm);

#endif /* _RWNX_MSG_TX_H_ */
