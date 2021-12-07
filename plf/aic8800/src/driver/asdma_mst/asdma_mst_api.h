/**
 ****************************************************************************************
 *
 * @file asdma_mst_api.h
 *
 * @brief ASDMA utility functions
 *
 ****************************************************************************************
 */

#ifndef _ASDMA_MST_API_H_
#define _ASDMA_MST_API_H_

/*
 * INCLUDE FILES
 ****************************************************************************************
 */

/*
 * Structs
 ****************************************************************************************
 */

typedef struct {
    unsigned int addr;
    unsigned int data;
} asdma_regw_info_t;

typedef struct {
    unsigned int addr;
    unsigned int data;
    unsigned int mask;
} asdma_regwm_info_t;

typedef struct {
    unsigned int addr;
} asdma_regr_info_t;

typedef struct {
    void *reginfo;
    unsigned int count;
} asdma_func2_info_t;

typedef struct {
    unsigned int  buf_addr;
    unsigned int  tbl0_cnt;
    unsigned int  tbl1_cnt;
    unsigned int  nxt_addr;
} asdma_dma_desc_t __attribute__ ((aligned (8)));

typedef struct
{
    unsigned volatile int *addr;
    unsigned volatile int *data;
    unsigned volatile int *wmask;
    unsigned int count;
} ASDMA_REG_INFO_T;

void asdma_mst_init(void);
unsigned int asdma_reg_rd(unsigned int raddr);
//void asdma_reg_rd_block(asdma_func2_info_t *func2_info, unsigned int *rbuf);
void asdma_reg_wr(unsigned int waddr, unsigned int wdata);
//void asdma_reg_wr_block(asdma_func2_info_t *func2_info);
void asdma_reg_mask_wr(unsigned int waddr, unsigned int wdata, unsigned int wmask);
//void asdma_reg_mask_wr_block(asdma_func2_info_t *func2_info);
void asdma_blk_rd(unsigned int word_count, unsigned int addr,unsigned volatile int *data, unsigned char fix_flag);
void asdma_blk_wr(unsigned int word_count, unsigned int addr, unsigned int *data, unsigned char fix_flag);

void asdma_mst_global_int_enable(void);
void asdma_slv_internal_reg_wr(unsigned int func, unsigned int waddr, unsigned int *wdata, unsigned int byte_count, char incr);
void asdma_mst_enable_slv_global_int (unsigned char int_enable);

void asdma_mst_audio_cfg_frag_len(unsigned short tx_bytes, unsigned short rx_bytes);
void asdma_mst_audio_cfg_slv_fifo_threshold(unsigned short txfifo_th, unsigned short rxfifo_th);
void asdma_mst_audio_init_trig_cnt(unsigned int trig_cnt_init);
void asdma_mst_audio_cfg_trig_threshold (unsigned int trig_th);
void asdma_mst_audio_cfg_trig_enable(void);
void asdma_mst_audio_cfg_trig_disable(void);
void asdma_mst_audio_force_trig(void);

void asdma_slv_audio_soft_reset(void);
void asdma_slv_audio_clear_wrfifo(void);
void asdma_slv_audio_clear_rdfifo(void);
unsigned char asdma_slv_audio_fifo_status_get(void);

#endif /* _ASDMA_MST_API_H_ */
