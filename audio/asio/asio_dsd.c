#include "dbg.h"
#include <stdint.h>
#include "string.h"
#include "aud_proc.h"
#include "rtos.h"
#include "reg_sysctrl.h"
#include "dma_api.h"
#include "asio_src.h"
#include "dma_api_bt.h"

#define CONFIG_aud_src_48k_in_48k_out
#define CONFIG_aud_src_lr_16bit_mode

#ifdef  CONFIG_aud_src_44p1k_in_16k_out
    #ifdef  CONFIG_aud_src_lr_24bit_mode
    #define  aud_src_tx_len 48*2*4
    #define  aud_src_rx_len 48*16*4
    #endif
    #ifdef  CONFIG_aud_src_lr_16bit_mode
    #define  aud_src_tx_len 48*4
    #define  aud_src_rx_len 48*16*4
    #endif
    #ifdef  CONFIG_aud_src_r_24bit_mode
    #define  aud_src_tx_len 48*4
    #define  aud_src_rx_len 48*16*4
    #endif
    #ifdef  CONFIG_aud_src_r_16bit_mode
    #define  aud_src_tx_len 48*4/2
    #define  aud_src_rx_len 48*16*4
    #endif
#endif

#ifdef  CONFIG_aud_src_44p1k_in_8k_out
    #ifdef  CONFIG_aud_src_lr_24bit_mode
    #define  aud_src_tx_len 48*2*4
    #define  aud_src_rx_len  48*16*4
    #endif
    #ifdef  CONFIG_aud_src_lr_16bit_mode
    #define  aud_src_tx_len 48*4
    #define  aud_src_rx_len  48*16*4
    #endif
    #ifdef  CONFIG_aud_src_r_24bit_mode
    #define  aud_src_tx_len 48*4
    #define  aud_src_rx_len  48*16*4
    #endif
    #ifdef  CONFIG_aud_src_r_16bit_mode
    #define  aud_src_tx_len 48*4/2
    #define  aud_src_rx_len  48*16*4
    #endif
#endif

#ifdef  CONFIG_aud_src_48k_in_48k_out
    #ifdef  CONFIG_aud_src_lr_24bit_mode
    #define  aud_src_tx_len 48*2*4
    #define  aud_src_rx_len 48*2
    #endif
    #ifdef  CONFIG_aud_src_lr_16bit_mode
    #define  aud_src_tx_len 48*7
    #define  aud_src_rx_len 48
    #endif
    #ifdef  CONFIG_aud_src_r_24bit_mode
    #define  aud_src_tx_len 48*2*4
    #define  aud_src_rx_len 48*2
    #endif
    #ifdef  CONFIG_aud_src_r_16bit_mode
    #define  aud_src_tx_len 48*2*4
    #define  aud_src_rx_len 48*2
    #endif
#endif

unsigned int *aud_adc_src_data_tx_0;
unsigned int *aud_adc_src_data_tx_1;
unsigned int *aud_dac_src_data_tx_0;
unsigned int *aud_dac_src_data_tx_1;

unsigned volatile int ch0_llist_int_cnt;
unsigned volatile int ch2_llist_int_cnt;
unsigned volatile int ch3_llist_int_cnt;
unsigned volatile int ch6_llist_int_cnt;
unsigned volatile int ch4_llist_int_cnt;
unsigned volatile int ch1_llist_int_cnt;

dma_desc_t dma_desc0, dma_desc1, dma_desc2, dma_desc3;
AIC_ASIO_DSD_HANDLER_T tx_cb[2] = {NULL,NULL};
AIC_ASIO_DSD_HANDLER_T rx_cb[2] = {NULL,NULL};



int aud_adc_src_out_initial(unsigned int aud_adc_src_rx_addr_sta)
{
    memset(&dma_desc0,0,sizeof(dma_desc_t));
    memset(&dma_desc1,0,sizeof(dma_desc_t));
    ///aud src tx_channel[0]
    dma_desc0.SAR = (unsigned int)aud_adc_src_data_tx_0;
    dma_desc0.DAR = (unsigned int)REG_AUD_PROC_BASE | (0x6<<8 | 0x0<<4);
    dma_desc0.TBL0CR = ((16) | (REQ_TBL0 << DMA_CH_RQTYP_LSB) | (AHB_WORD << DMA_CH_DBUSU_LSB) |
                             (AHB_WORD << DMA_CH_SBUSU_LSB) | DMA_CH_CONSTDA_BIT);
    dma_desc0.TBL1CR = (((aud_src_tx_len) << DMA_CH_TBL1_CNT_LSB) & DMA_CH_TBL1_CNT_MASK);
    dma_desc0.TBL2CR = (((aud_src_tx_len<<2) << DMA_CH_TBL2_CNT_LSB) & DMA_CH_TBL2_CNT_MASK)|DMA_CH_LLI_DEDIC_INT_EN_BIT;
    dma_desc0.TSR = ((4 << DMA_CH_STRANSZ_LSB) | (4 << DMA_CH_DTRANSZ_LSB));
    dma_desc0.LNAR = (unsigned int)(&dma_desc1);

    dma_desc1.SAR = (unsigned int)aud_adc_src_data_tx_1;
    dma_desc1.DAR = (unsigned int)REG_AUD_PROC_BASE | (0x6<<8 | 0x0<<4);
    dma_desc1.TBL0CR = ((16) | (REQ_TBL0 << DMA_CH_RQTYP_LSB) | (AHB_WORD << DMA_CH_DBUSU_LSB) |
                             (AHB_WORD << DMA_CH_SBUSU_LSB) | DMA_CH_CONSTDA_BIT);
    dma_desc1.TBL1CR = (((aud_src_tx_len) << DMA_CH_TBL1_CNT_LSB) & DMA_CH_TBL1_CNT_MASK);
    dma_desc1.TBL2CR = (((aud_src_tx_len<<2) << DMA_CH_TBL2_CNT_LSB) & DMA_CH_TBL2_CNT_MASK)|DMA_CH_LLI_DEDIC_INT_EN_BIT;
    dma_desc1.TSR = ((4 << DMA_CH_STRANSZ_LSB) | (4 << DMA_CH_DTRANSZ_LSB));
    dma_desc1.LNAR = (unsigned int)(&dma_desc0);

    dma_erqcsr_set(REQ_CID_AUD_SRC_TX,DMA_CH_2);
    dma_ch_rqr_erqm_setb(DMA_CH_2);
    dma_ch_rqr_erql_setb(DMA_CH_2);
    dma_ch_icsr_tbl2_iena_setb(DMA_CH_2);
    dma_ch_icsr_tll_iena_setb(DMA_CH_2);
    dma_ch_lnar_set(DMA_CH_2,(unsigned int)&dma_desc0);
    dma_ch_ctlr_set(DMA_CH_2, DMA_CH_CHENA_BIT | DMA_CH_LSTENA_BIT | (0x01UL << DMA_CH_BUSBU_LSB));
    ///aud src txrx_channel
    dma_ch_sar_set(DMA_CH_3,(REG_AUD_PROC_BASE | (0x6<<8 | 0x2<<4)));
    dma_ch_dar_set(DMA_CH_3,aud_adc_src_rx_addr_sta);
    dma_ch_tbl0cr_set(DMA_CH_3, ((16) | (REQ_TBL0 << DMA_CH_RQTYP_LSB) | (AHB_WORD << DMA_CH_DBUSU_LSB) |
                             (AHB_WORD << DMA_CH_SBUSU_LSB) | DMA_CH_CONSTSA_BIT));
    dma_ch_tbl1cr_set(DMA_CH_3,(((aud_src_rx_len) << DMA_CH_TBL1_CNT_LSB) & DMA_CH_TBL1_CNT_MASK));
    dma_ch_tbl2cr_set(DMA_CH_3,(((aud_src_rx_len<<2) << DMA_CH_TBL2_CNT_LSB) & DMA_CH_TBL2_CNT_MASK));
    dma_ch_tsr_set(DMA_CH_3, ((4 << DMA_CH_STRANSZ_LSB) | (4 << DMA_CH_DTRANSZ_LSB)));
    dma_ch_wmar_set(DMA_CH_3, 0);
    dma_ch_wjar_set(DMA_CH_3, 0);
    dma_ch_tbl0sr_set(DMA_CH_3, ((0 << DMA_CH_STBL0SZ_LSB) | (0 << DMA_CH_DTBL0SZ_LSB)));
    dma_ch_tbl1ssr_set(DMA_CH_3, 0);
    dma_ch_tbl1dsr_set(DMA_CH_3, 0);
    dma_erqcsr_set(REQ_CID_AUD_SRC_RX, DMA_CH_3);
    dma_ch_rqr_erqm_setb(DMA_CH_3);
    dma_ch_rqr_erql_setb(DMA_CH_3);
    dma_ch_icsr_tbl2_iena_setb(DMA_CH_3);

    NVIC_EnableIRQ(DMA02_IRQn);
    NVIC_EnableIRQ(DMA03_IRQn);
    return 0;
}

int aud_dac_src_out_initial(unsigned int aud_dac_src_rx_addr_sta)
{
    ///tx_channel[0]
    memset(&dma_desc2,0,sizeof(dma_desc_t));
    memset(&dma_desc3,0,sizeof(dma_desc_t));
    ///aud src tx_channel[0]
    dma_desc2.SAR = (unsigned int)aud_dac_src_data_tx_0;
    dma_desc2.DAR = (unsigned int)REG_AUD_PROC_BASE | (0x4<<8 | 0x0<<4);
    dma_desc2.TBL0CR = ((16) | (REQ_TBL0 << DMA_CH_RQTYP_LSB) | (AHB_WORD << DMA_CH_DBUSU_LSB) |
                             (AHB_WORD << DMA_CH_SBUSU_LSB) | DMA_CH_CONSTDA_BIT);
    dma_desc2.TBL1CR = (((aud_src_tx_len) << DMA_CH_TBL1_CNT_LSB) & DMA_CH_TBL1_CNT_MASK);
    dma_desc2.TBL2CR = (((aud_src_tx_len<<2) << DMA_CH_TBL2_CNT_LSB) & DMA_CH_TBL2_CNT_MASK)|DMA_CH_LLI_DEDIC_INT_EN_BIT;
    dma_desc2.TSR = ((4 << DMA_CH_STRANSZ_LSB) | (4 << DMA_CH_DTRANSZ_LSB));
    dma_desc2.LNAR = (unsigned int)(&dma_desc3);

    dma_desc3.SAR = (unsigned int)aud_dac_src_data_tx_1;
    dma_desc3.DAR = (unsigned int)REG_AUD_PROC_BASE | (0x4<<8 | 0x0<<4);
    dma_desc3.TBL0CR = ((16) | (REQ_TBL0 << DMA_CH_RQTYP_LSB) | (AHB_WORD << DMA_CH_DBUSU_LSB) |
                             (AHB_WORD << DMA_CH_SBUSU_LSB) | DMA_CH_CONSTDA_BIT);
    dma_desc3.TBL1CR = (((aud_src_tx_len) << DMA_CH_TBL1_CNT_LSB) & DMA_CH_TBL1_CNT_MASK);
    dma_desc3.TBL2CR = (((aud_src_tx_len<<2) << DMA_CH_TBL2_CNT_LSB) & DMA_CH_TBL2_CNT_MASK)|DMA_CH_LLI_DEDIC_INT_EN_BIT;
    dma_desc3.TSR = ((4 << DMA_CH_STRANSZ_LSB) | (4 << DMA_CH_DTRANSZ_LSB));
    dma_desc3.LNAR = (unsigned int)(&dma_desc2);

    dma_erqcsr_set(REQ_CID_AUD_PROC_TX0,DMA_CH_4);
    dma_ch_rqr_erqm_setb(DMA_CH_4);
    dma_ch_rqr_erql_setb(DMA_CH_4);
    dma_ch_icsr_tbl2_iena_setb(DMA_CH_4);
    dma_ch_icsr_tll_iena_setb(DMA_CH_4);
    dma_ch_lnar_set(DMA_CH_4,(unsigned int)&dma_desc2);
    dma_ch_ctlr_set(DMA_CH_4, DMA_CH_CHENA_BIT | DMA_CH_LSTENA_BIT | (0x01UL << DMA_CH_BUSBU_LSB));
    ///aud src txrx_channel
    dma_ch_sar_set(DMA_CH_1,(REG_AUD_PROC_BASE | (0x5<<8 | 0x2<<4)));
    dma_ch_dar_set(DMA_CH_1,aud_dac_src_rx_addr_sta);
    dma_ch_tbl0cr_set(DMA_CH_1, ((16) | (REQ_TBL0 << DMA_CH_RQTYP_LSB) | (AHB_WORD << DMA_CH_DBUSU_LSB) |
                             (AHB_WORD << DMA_CH_SBUSU_LSB) | DMA_CH_CONSTSA_BIT));
    dma_ch_tbl1cr_set(DMA_CH_1,(((aud_src_rx_len) << DMA_CH_TBL1_CNT_LSB) & DMA_CH_TBL1_CNT_MASK));
    dma_ch_tbl2cr_set(DMA_CH_1,(((aud_src_rx_len<<2) << DMA_CH_TBL2_CNT_LSB) & DMA_CH_TBL2_CNT_MASK));
    dma_ch_tsr_set(DMA_CH_1, ((4 << DMA_CH_STRANSZ_LSB) | (4 << DMA_CH_DTRANSZ_LSB)));
    dma_ch_wmar_set(DMA_CH_1, 0);
    dma_ch_wjar_set(DMA_CH_1, 0);
    dma_ch_tbl0sr_set(DMA_CH_1, ((0 << DMA_CH_STBL0SZ_LSB) | (0 << DMA_CH_DTBL0SZ_LSB)));
    dma_ch_tbl1ssr_set(DMA_CH_1, 0);
    dma_ch_tbl1dsr_set(DMA_CH_1, 0);
    dma_erqcsr_set(REQ_CID_AUD_PROC_TXRX0, DMA_CH_1);
    dma_ch_rqr_erqm_setb(DMA_CH_1);
    dma_ch_rqr_erql_setb(DMA_CH_1);
    dma_ch_icsr_tbl2_iena_setb(DMA_CH_1);

    NVIC_EnableIRQ(DMA04_IRQn);
    NVIC_EnableIRQ(DMA01_IRQn);

    return 0;
}

void adc_src_rx_dma_start(unsigned int aud_adc_src_rx_addr_sta)
{
    //dbg("src rx dma start !!!\n");
    dma_ch_sar_set(DMA_CH_3,(REG_AUD_PROC_BASE | (0x6<<8 | 0x2<<4)));
    dma_ch_dar_set(DMA_CH_3,aud_adc_src_rx_addr_sta);
    dma_ch_tbl0cr_set(DMA_CH_3, ((16) | (REQ_TBL0 << DMA_CH_RQTYP_LSB) | (AHB_WORD << DMA_CH_DBUSU_LSB) |
                             (AHB_WORD << DMA_CH_SBUSU_LSB) | DMA_CH_CONSTSA_BIT));
    dma_ch_tbl1cr_set(DMA_CH_3,(((aud_src_rx_len) << DMA_CH_TBL1_CNT_LSB) & DMA_CH_TBL1_CNT_MASK));
    dma_ch_tbl2cr_set(DMA_CH_3,(((aud_src_rx_len<<2) << DMA_CH_TBL2_CNT_LSB) & DMA_CH_TBL2_CNT_MASK));
    dma_erqcsr_set(REQ_CID_AUD_SRC_RX, DMA_CH_3);
    dma_ch_ctlr_set(DMA_CH_3, (DMA_CH_CHENA_BIT | (0x01UL << DMA_CH_BUSBU_LSB)));

}

void dac_src_rx_dma_start(unsigned int aud_dac_src_rx_addr_sta)
{
    //dbg("src rx dma start !!!\n");
    dma_ch_sar_set(DMA_CH_1,(REG_AUD_PROC_BASE | (0x5<<8 | 0x2<<4)));
    dma_ch_dar_set(DMA_CH_1,aud_dac_src_rx_addr_sta);
    dma_ch_tbl0cr_set(DMA_CH_1, ((16) | (REQ_TBL0 << DMA_CH_RQTYP_LSB) | (AHB_WORD << DMA_CH_DBUSU_LSB) |
                             (AHB_WORD << DMA_CH_SBUSU_LSB) | DMA_CH_CONSTSA_BIT));
    dma_ch_tbl1cr_set(DMA_CH_1,(((aud_src_rx_len) << DMA_CH_TBL1_CNT_LSB) & DMA_CH_TBL1_CNT_MASK));
    dma_ch_tbl2cr_set(DMA_CH_1,(((aud_src_rx_len<<2) << DMA_CH_TBL2_CNT_LSB) & DMA_CH_TBL2_CNT_MASK));
    dma_erqcsr_set(REQ_CID_AUD_PROC_TXRX0, DMA_CH_1);
    dma_ch_ctlr_set(DMA_CH_1, (DMA_CH_CHENA_BIT | (0x01UL << DMA_CH_BUSBU_LSB)));

}

void adc_src_chnl_en(int aud_src_mode)
{
    dbg("set src chnl en !!!\n");
    hwp_audProc->aud_proc_cfg |= AUD_PROC_HIGH_SPEED_MODE | AUD_PROC_AUD_PROC_ENABLE | AUD_PROC_TX_BURST_MODE | AUD_PROC_TXRX_BURST_MODE | AUD_PROC_AUTO_CLOCK_GATING_EN | AUD_PROC_RXTX_BURST_MODE | AUD_PROC_RX_BURST_MODE;
#ifdef  CONFIG_aud_src_lr_24bit_mode
    hwp_audProc->aud_src_ctrl0 = AUD_PROC_AUD_SRC_ENABLE | AUD_PROC_AUD_SRC_TXRX_LR_FIFO_SHARE_EN | AUD_PROC_AUD_SRC_TX_LR_FIFO_SHARE_EN | AUD_PROC_AUD_SRC_TXRX_EN_CH_1 | AUD_PROC_AUD_SRC_TXRX_EN_CH_0 | AUD_PROC_AUD_SRC_TXRX_MODE_CH | AUD_PROC_AUD_SRC_TX_EN_CH_1 | AUD_PROC_AUD_SRC_TX_EN_CH_0 | AUD_PROC_AUD_SRC_TX_MODE_CH | AUD_PROC_AUD_SRC_AUTO_CLOCK_GATING_EN | AUD_PROC_AUD_SRC_TXRX_BURST_MODE | AUD_PROC_AUD_SRC_TX_BURST_MODE;
#endif
#ifdef  CONFIG_aud_src_r_24bit_mode
    hwp_audProc->aud_src_ctrl0 = AUD_PROC_AUD_SRC_ENABLE | AUD_PROC_AUD_SRC_TXRX_EN_CH_0 | AUD_PROC_AUD_SRC_TXRX_MODE_CH | AUD_PROC_AUD_SRC_TX_EN_CH_0 | AUD_PROC_AUD_SRC_TX_MODE_CH | AUD_PROC_AUD_SRC_AUTO_CLOCK_GATING_EN |AUD_PROC_AUD_SRC_TXRX_BURST_MODE | AUD_PROC_AUD_SRC_TX_BURST_MODE;
#endif
#ifdef  CONFIG_aud_src_lr_16bit_mode
    hwp_audProc->aud_src_ctrl0 = AUD_PROC_AUD_SRC_ENABLE | AUD_PROC_AUD_SRC_TXRX_LR_FIFO_SHARE_EN | AUD_PROC_AUD_SRC_TX_LR_FIFO_SHARE_EN | AUD_PROC_AUD_SRC_TXRX_EN_CH_1 | AUD_PROC_AUD_SRC_TXRX_EN_CH_0 | AUD_PROC_AUD_SRC_TX_EN_CH_1 | AUD_PROC_AUD_SRC_TX_EN_CH_0 | AUD_PROC_AUD_SRC_AUTO_CLOCK_GATING_EN | AUD_PROC_AUD_SRC_TXRX_BURST_MODE | AUD_PROC_AUD_SRC_TX_BURST_MODE;
#endif
#ifdef  CONFIG_aud_src_r_16bit_mode
    hwp_audProc->aud_src_ctrl0 = AUD_PROC_AUD_SRC_ENABLE | AUD_PROC_AUD_SRC_TXRX_EN_CH_0 | AUD_PROC_AUD_SRC_AUTO_CLOCK_GATING_EN | AUD_PROC_AUD_SRC_TX_EN_CH_0 | AUD_PROC_AUD_SRC_TXRX_BURST_MODE | AUD_PROC_AUD_SRC_TX_BURST_MODE;
#endif

    unsigned int src_ch_en;
    #ifdef CONFIG_aud_src_lr_24bit_mode
      src_ch_en = 3;
    #endif
    #ifdef CONFIG_aud_src_lr_16bit_mode
      src_ch_en = 3;
    #endif
    #ifdef CONFIG_aud_src_r_24bit_mode
      src_ch_en = 1;
    #endif
    #ifdef CONFIG_aud_src_r_16bit_mode
      src_ch_en = 1;
    #endif

#ifdef CONFIG_aud_src_44p1k_in_16k_out
    hwp_audProc->aud_src_ctrl2 = AUD_PROC_AUD_SRC_FRAC_SRC_EN | AUD_PROC_AUD_SRC_CH_EN(src_ch_en) | AUD_PROC_AUD_SRC_MODE(aud_src_mode) | AUD_PROC_AUD_SRC_FLT_BYPASS(0) | AUD_PROC_AUD_SRC_DECIM24_BYPASS | AUD_PROC_AUD_SRC_DECIM3_SEL;
#endif
#ifdef CONFIG_aud_src_44p1k_in_8k_out
    hwp_audProc->aud_src_ctrl2 = AUD_PROC_AUD_SRC_FRAC_SRC_EN | AUD_PROC_AUD_SRC_CH_EN(src_ch_en) | AUD_PROC_AUD_SRC_MODE(aud_src_mode) | AUD_PROC_AUD_SRC_FLT_BYPASS(0) | AUD_PROC_AUD_SRC_DECIM24_SEL |AUD_PROC_AUD_SRC_DECIM3_SEL;
#endif
#ifdef CONFIG_aud_src_48k_in_48k_out
    hwp_audProc->aud_src_ctrl2 = AUD_PROC_AUD_SRC_FRAC_SRC_EN | AUD_PROC_AUD_SRC_CH_EN(src_ch_en) | AUD_PROC_AUD_SRC_MODE(aud_src_mode) | AUD_PROC_AUD_SRC_FLT_BYPASS(0) | AUD_PROC_AUD_SRC_DECIM24_BYPASS | AUD_PROC_AUD_SRC_DECIM3_BYPASS;
#endif
}

void dac_src_chnl_en(int aud_src_mode)
{
    dbg("set dac src chnl en !!!\n");
    hwp_audProc->aud_proc_frac_src |= AUD_PROC_FRAC_SRC_EN | AUD_PROC_FRAC_RATE_ADJ_SW(0x0);
   ///add
    hwp_audProc->aud_proc_dac_cfg2 = AUD_PROC_EQ_STAGE(0x0) | AUD_PROC_EQ_CH_EN(0x0) | AUD_PROC_DAC_MIXER_MODE_R(0x2) | AUD_PROC_DAC_MIXER_MODE_L(0x0);

#if (defined CONFIG_aud_src_lr_24bit_mode)
    hwp_audProc->aud_proc_dac_cfg1 = AUD_PROC_SRC_MODE(aud_src_mode) | AUD_PROC_SRC_CH_EN(0x3) | AUD_PROC_DAC_VOLUME_R(0x1a<<1) |  AUD_PROC_DAC_VOLUME_L(0x1a<<1) | AUD_PROC_TX_MUX_MODE_R(0x1) | AUD_PROC_RX_MUX_MODE_R(0x0) | AUD_PROC_TX_MUX_MODE_L(0x0) | AUD_PROC_RX_MUX_MODE_L(0x0) ;
    hwp_audProc->aud_proc_tx_cfg_ch0 = AUD_PROC_TX_EN_CH_0 | AUD_PROC_TX_MODE_CH_0;
    hwp_audProc->aud_proc_txrx_cfg_ch0  = AUD_PROC_TXRX_EN_CH_0 | AUD_PROC_TXRX_MODE_CH_0 | AUD_PROC_TXRX_FIFO_FULL_SEL_CH_0 | AUD_PROC_TXRX_FIFO_AF_TH_CH_0(8) | AUD_PROC_TXRX_FIFO_AE_TH_CH_0(0x3);
    hwp_audProc->aud_proc_adc_cfg1 = AUD_PROC_ADC_VOLUME_L(7) | AUD_PROC_ADC_VOLUME_R(7) ;
    hwp_audProc->aud_proc_cfg = AUD_PROC_TXRX_LR_FIFO_SHARE_EN | AUD_PROC_TX_LR_FIFO_SHARE_EN(0x1) | AUD_PROC_RXTX_LR_FIFO_SHARE_EN(0x1) | AUD_PROC_RX_LR_FIFO_SHARE_EN(0x1) | AUD_PROC_HIGH_SPEED_MODE | AUD_PROC_AUD_PROC_ENABLE | AUD_PROC_TX_BURST_MODE | AUD_PROC_TXRX_BURST_MODE | AUD_PROC_AUTO_CLOCK_GATING_EN | AUD_PROC_RXTX_BURST_MODE | AUD_PROC_RX_BURST_MODE;
#endif
#if (defined CONFIG_aud_src_lr_16bit_mode)
    hwp_audProc->aud_proc_dac_cfg1 = AUD_PROC_SRC_MODE(aud_src_mode) | AUD_PROC_SRC_CH_EN(0x3) | AUD_PROC_DAC_VOLUME_R(0x1a<<1) |  AUD_PROC_DAC_VOLUME_L(0x1a<<1) | AUD_PROC_TX_MUX_MODE_R(0x1) | AUD_PROC_RX_MUX_MODE_R(0x0) | AUD_PROC_TX_MUX_MODE_L(0x0) | AUD_PROC_RX_MUX_MODE_L(0x0) ;
    hwp_audProc->aud_proc_tx_cfg_ch0 = AUD_PROC_TX_EN_CH_0;
    hwp_audProc->aud_proc_txrx_cfg_ch0 = AUD_PROC_TXRX_EN_CH_0 | AUD_PROC_TXRX_FIFO_FULL_SEL_CH_0 | AUD_PROC_TXRX_FIFO_AF_TH_CH_0(32)| AUD_PROC_TXRX_FIFO_AE_TH_CH_0(0x3);
    hwp_audProc->aud_proc_adc_cfg1 = AUD_PROC_ADC_VOLUME_L(7) | AUD_PROC_ADC_VOLUME_R(7);
    hwp_audProc->aud_proc_cfg = AUD_PROC_TXRX_LR_FIFO_SHARE_EN | AUD_PROC_TX_LR_FIFO_SHARE_EN(0x1) | AUD_PROC_RXTX_LR_FIFO_SHARE_EN(0x1) | AUD_PROC_RX_LR_FIFO_SHARE_EN(0x1) | AUD_PROC_HIGH_SPEED_MODE | AUD_PROC_AUD_PROC_ENABLE | AUD_PROC_TX_BURST_MODE | AUD_PROC_TXRX_BURST_MODE | AUD_PROC_AUTO_CLOCK_GATING_EN | AUD_PROC_RXTX_BURST_MODE | AUD_PROC_RX_BURST_MODE;
#endif
#if (defined CONFIG_aud_src_r_24bit_mode)
    hwp_audProc->aud_proc_dac_cfg1 = AUD_PROC_SRC_MODE(aud_src_mode) | AUD_PROC_SRC_CH_EN(0x1) | AUD_PROC_DAC_VOLUME_R(0x1a<<1) |  AUD_PROC_DAC_VOLUME_L(0x1a<<1) | AUD_PROC_TX_MUX_MODE_R(0x1) | AUD_PROC_RX_MUX_MODE_R(0x0) | AUD_PROC_TX_MUX_MODE_L(0x0) | AUD_PROC_RX_MUX_MODE_L(0x0) ;
    hwp_audProc->aud_proc_tx_cfg_ch0 = AUD_PROC_TX_EN_CH_0 | AUD_PROC_TX_MODE_CH_0;
    hwp_audProc->aud_proc_txrx_cfg_ch0 = AUD_PROC_TXRX_EN_CH_0 | AUD_PROC_TX_MODE_CH_0 | AUD_PROC_TXRX_FIFO_FULL_SEL_CH_0 | AUD_PROC_TXRX_FIFO_AF_TH_CH_0(8)| AUD_PROC_TXRX_FIFO_AE_TH_CH_0(0x3);
    hwp_audProc->aud_proc_adc_cfg1 = AUD_PROC_ADC_VOLUME_L(7) | AUD_PROC_ADC_VOLUME_R(7);
    hwp_audProc->aud_proc_cfg = AUD_PROC_HIGH_SPEED_MODE | AUD_PROC_AUD_PROC_ENABLE | AUD_PROC_TX_BURST_MODE | AUD_PROC_TXRX_BURST_MODE | AUD_PROC_AUTO_CLOCK_GATING_EN | AUD_PROC_RXTX_BURST_MODE | AUD_PROC_RX_BURST_MODE;
#endif
#if (defined CONFIG_aud_src_r_16bit_mode)
    hwp_audProc->aud_proc_dac_cfg1 = AUD_PROC_SRC_MODE(aud_src_mode) | AUD_PROC_SRC_CH_EN(0x1) | AUD_PROC_DAC_VOLUME_R(0x1a<<1) |  AUD_PROC_DAC_VOLUME_L(0x1a<<1) | AUD_PROC_TX_MUX_MODE_R(0x1) | AUD_PROC_RX_MUX_MODE_R(0x0) | AUD_PROC_TX_MUX_MODE_L(0x0) | AUD_PROC_RX_MUX_MODE_L(0x0) ;
    hwp_audProc->aud_proc_tx_cfg_ch0 = AUD_PROC_TX_EN_CH_0 ;
    hwp_audProc->aud_proc_txrx_cfg_ch0 = AUD_PROC_TXRX_EN_CH_0 | AUD_PROC_TXRX_FIFO_FULL_SEL_CH_0 | AUD_PROC_TXRX_FIFO_AF_TH_CH_0(8)| AUD_PROC_TXRX_FIFO_AE_TH_CH_0(0x3);
    hwp_audProc->aud_proc_adc_cfg1 = AUD_PROC_ADC_VOLUME_L(7) | AUD_PROC_ADC_VOLUME_R(7);
    hwp_audProc->aud_proc_cfg = AUD_PROC_HIGH_SPEED_MODE | AUD_PROC_AUD_PROC_ENABLE | AUD_PROC_TX_BURST_MODE | AUD_PROC_TXRX_BURST_MODE | AUD_PROC_AUTO_CLOCK_GATING_EN | AUD_PROC_RXTX_BURST_MODE | AUD_PROC_RX_BURST_MODE;
#endif
}

///aud proc tx

///aud src tx
void aud_adc_src_tx_handler(uint8_t dma_type, uint8_t ch, uint32_t int_status)
{
    ch2_llist_int_cnt ++;
    //dbg("int aud_adc_src tx ch_llist_int_cnt is =%d\n",ch2_llist_int_cnt);
    if(tx_cb[0]){
        tx_cb[0](NULL);
    }
}

///aud src rx
void aud_adc_src_rx_handler(uint8_t dma_type, uint8_t ch, uint32_t int_status)
{
    ch3_llist_int_cnt ++;
    //dbg("int aud_adc_src rx ch_llist_int_cnt is =%d\n",ch3_llist_int_cnt);
    if(rx_cb[0]){
        rx_cb[0](NULL);
    }
}

///aud src tx
void aud_dac_src_tx_handler(uint8_t dma_type, uint8_t ch, uint32_t int_status)
{
    ch4_llist_int_cnt ++;
    //dbg("int aud_adc_src tx ch_llist_int_cnt is =%d\n",ch2_llist_int_cnt);
    if(tx_cb[1]){
        tx_cb[1](NULL);
    }
}

///aud src rx
void aud_dac_src_rx_handler(uint8_t dma_type, uint8_t ch, uint32_t int_status)
{
    ch1_llist_int_cnt ++;
    //dbg("int aud_adc_src rx ch_llist_int_cnt is =%d\n",ch3_llist_int_cnt);
    if(rx_cb[1]){
        rx_cb[1](NULL);
    }
}

void asio_dsd_out(uint8_t idx,unsigned int *rx)
{
    if(idx == 1){
        ch0_llist_int_cnt ++;
        if (ch0_llist_int_cnt==1) {
            dac_src_chnl_en(8);
        }
        dac_src_rx_dma_start((unsigned int)rx);
        //dbg("int aud_proc tx ch_llist_int_cnt is =%d\n",ch0_llist_int_cnt);
    }else if(idx == 0){
        ch6_llist_int_cnt ++;
        if (ch6_llist_int_cnt==1) {
            adc_src_chnl_en(8);
        }
        adc_src_rx_dma_start((unsigned int)rx);
        //dbg("int aud_proc tx ch_llist_int_cnt is =%d\n",ch0_llist_int_cnt);
    }else{
        ASSERT_ERR(0);
    }
}

void asio_dsd_tx_cb_register(uint8_t idx,AIC_ASIO_DSD_HANDLER_T cb)
{
    ASSERT_ERR(idx == 0||idx == 1);
    tx_cb[idx] = cb;
}

void asio_dsd_rx_cb_register(uint8_t idx,AIC_ASIO_DSD_HANDLER_T cb)
{
    ASSERT_ERR(idx == 0||idx == 1);
    rx_cb[idx] = cb;
}

void asio_dsd_cnt_clean(void)
{
    ch0_llist_int_cnt  = 0;
    ch2_llist_int_cnt  = 0;
    ch3_llist_int_cnt  = 0;
    ch4_llist_int_cnt  = 0;
    ch1_llist_int_cnt  = 0;
    ch6_llist_int_cnt  = 0;
}

void asio_dsd_init(unsigned int *adc_tx_0,unsigned int *adc_tx_1,unsigned int *dac_tx_0,unsigned int *dac_tx_1)
{
    cpusysctrl_hclkme_set(CSC_HCLKME_DMA_EN_BIT | CSC_HCLKME_VPC_EN_BIT);
    ///src start 2 ping/pong buffer

    ch0_llist_int_cnt  = 0;
    ch2_llist_int_cnt  = 0;
    ch3_llist_int_cnt  = 0;
    ch4_llist_int_cnt  = 0;
    ch1_llist_int_cnt  = 0;
    ch6_llist_int_cnt  = 0;

    aud_adc_src_data_tx_0 = adc_tx_0;
    aud_adc_src_data_tx_1 = adc_tx_1;
    aud_dac_src_data_tx_0 = dac_tx_0;
    aud_dac_src_data_tx_0 = dac_tx_1;
    dbg("aud src data_tx address is=%x ,%x,%x,%x!!!\n",aud_adc_src_data_tx_0,aud_adc_src_data_tx_1,
                                                       aud_dac_src_data_tx_0,aud_dac_src_data_tx_1);
    dma_cx_handler_register(DMA_CH_2,aud_adc_src_tx_handler);
    dma_cx_handler_register(DMA_CH_3,aud_adc_src_rx_handler);
    dma_cx_handler_register(DMA_CH_4,aud_dac_src_tx_handler);
    dma_cx_handler_register(DMA_CH_1,aud_dac_src_rx_handler);

#ifdef CONFIG_aud_src_44p1k_in_16k_out
    dbg("start src_share_44p1k_in_16k_out !!!\n");
    aud_adc_src_out_initial((unsigned int)aud_adc_src_data_tx_0);
    aud_dac_src_out_initial((unsigned int)aud_dac_src_data_tx_0);
#endif

#ifdef CONFIG_aud_src_44p1k_in_8k_out
    dbg("start src_share_44p1k_in_8k_out !!!\n");
    aud_adc_src_out_initial((unsigned int)aud_adc_src_data_tx_0);
    aud_dac_src_out_initial((unsigned int)aud_dac_src_data_tx_0);
#endif

#ifdef   CONFIG_aud_src_48k_in_48k_out
    dbg("start src_share_48k_in_48k_out !!!\n");
    aud_adc_src_out_initial((unsigned int)aud_adc_src_data_tx_0);
    aud_dac_src_out_initial((unsigned int)aud_dac_src_data_tx_0);
#endif
}
