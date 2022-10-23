#ifndef _AUD_PROC_H_
#define _AUD_PROC_H_

#include "chip.h"

// =============================================================================
//  MACROS
// =============================================================================

// =============================================================================
//  TYPES
// =============================================================================

// ============================================================================
// AUD_PROC_T
// -----------------------------------------------------------------------------
///
// =============================================================================
#define REG_AUD_PROC_BASE          0x40061000

typedef volatile struct
{
    __IO uint32_t               aud_proc_function_id;         //0x00000000
    __IO uint32_t               aud_proc_cfg;                 //0x00000004
    __IO uint32_t               aud_proc_tx_cfg_ch0;          //0x00000008
    __IO uint32_t               aud_proc_tx_cfg_ch1;          //0x0000000C
    __IO uint32_t               aud_proc_tx_cfg_ch2;          //0x00000010
    __IO uint32_t               aud_proc_tx_cfg_ch3;          //0x00000014
    __IO uint32_t               aud_proc_rx_cfg_ch01;         //0x00000018
    __IO uint32_t               aud_proc_rx_cfg_ch23;         //0x0000001C
    __IO uint32_t               aud_proc_dac_cfg1;            //0x00000020
    __IO uint32_t               aud_proc_dac_cfg2;            //0x00000024
    __IO uint32_t               aud_proc_adc_cfg1;            //0x00000028
    __IO uint32_t               aud_proc_adc_cfg2;            //0x0000002C
    __IO uint32_t               aud_proc_txrx_cfg_ch0;        //0x00000030
    __IO uint32_t               aud_proc_txrx_cfg_ch1;        //0x00000034
    __IO uint32_t               aud_proc_rxtx_cfg_ch0;        //0x00000038
    __IO uint32_t               aud_proc_rxtx_cfg_ch1;        //0x0000003C
    __IO uint32_t               aud_proc_frac_src;            //0x00000040
    __IO uint32_t               aud_proc_dac_trig;            //0x00000044
    __IO uint32_t               aud_proc_dac_strb;            //0x00000048
    __IO uint32_t               aud_proc_irq;                 //0x0000004C
    __IO uint32_t               bt_clk_lo_cnt;                //0x00000050
    __IO uint32_t               bt_clk_hi_cnt;                //0x00000054
    __IO uint32_t               bt_clk_lo_cnt_latch;          //0x00000058
    __IO uint32_t               bt_clk_hi_cnt_latch;          //0x0000005C
    __IO uint32_t               dac_src_strb_lo_cnt;          //0x00000060
    __IO uint32_t               dac_src_strb_hi_cnt;          //0x00000064
    __IO uint32_t               dpll_alfa1_cfg;               //0x00000068
    __IO uint32_t               dpll_k1_k2_cfg;               //0x0000006C
    __IO uint32_t               dpll_alfa2_cfg;               //0x00000070
    __IO uint32_t               dpll_other_cfg1;              //0x00000074
    __IO uint32_t Reserved_00000078;            //0x00000078
    __IO uint32_t               dpll_trig_cfg;                //0x0000007C
    __IO uint32_t               frac_rate_adj_up_th;          //0x00000080
    __IO uint32_t               frac_rate_adj_dn_th;          //0x00000084
    __IO uint32_t               frac_rate_adj_hw;             //0x00000088
    __IO uint32_t               aud_intf_i2s_cfg0;            //0x0000008C
    __IO uint32_t               aud_intf_i2s_cfg1;            //0x00000090
    __IO uint32_t               pcm_cfg_0;                    //0x00000094
    __IO uint32_t               pcm_cfg_1;                    //0x00000098
    __IO uint32_t               spdif_userdata_0;             //0x0000009C
    __IO uint32_t               spdif_userdata_1;             //0x000000A0
    __IO uint32_t               spdif_userdata_2;             //0x000000A4
    __IO uint32_t               spdif_userdata_3;             //0x000000A8
    __IO uint32_t               spdif_userdata_4;             //0x000000AC
    __IO uint32_t               spdif_userdata_5;             //0x000000B0
    __IO uint32_t               spdif_channel_stat_0;         //0x000000B4
    __IO uint32_t               spdif_channel_stat_1;         //0x000000B8
    __IO uint32_t               spdif_channel_stat_2;         //0x000000BC
    __IO uint32_t               spdif_channel_stat_3;         //0x000000C0
    __IO uint32_t               spdif_channel_stat_4;         //0x000000C4
    __IO uint32_t               spdif_channel_stat_5;         //0x000000C8
    __IO uint32_t               spdif_output_cfg;             //0x000000CC
    __IO uint32_t               spdif_input_cfg;              //0x000000D0
    __IO uint32_t               spdif_input_stat1;            //0x000000D4
    __IO uint32_t               spdif_input_stat2;            //0x000000D8
    __IO uint32_t               aud_drc_cfg0;                 //0x000000DC
    __IO uint32_t Reserved_000000E0[8];         //0x000000E0
    __IO uint32_t               eq_stereo_coef_ram_cfg0;      //0x00000100
    __IO uint32_t               eq_stereo_coef_ram_cfg1;      //0x00000104
    __IO uint32_t               eq_mono_coef_ram_cfg0;        //0x00000108
    __IO uint32_t               eq_mono_coef_ram_cfg1;        //0x0000010C
    __IO uint32_t               aud_drc_ram_cfg0;             //0x00000110
    __IO uint32_t               aud_drc_ram_cfg1;             //0x00000114
    __IO uint32_t               aud_drc_ram_cfg2;             //0x00000118
    __IO uint32_t               aud_src_ctrl0;                //0x0000011C
    __IO uint32_t               aud_src_ctrl1;                //0x00000120
    __IO uint32_t               aud_src_ctrl2;                //0x00000124
} HWP_AUD_PROC_T;

static HWP_AUD_PROC_T * const hwp_audProc = ((HWP_AUD_PROC_T *)REG_AUD_PROC_BASE);


//aud_proc_function_id
#define AUD_PROC_REV_ID(n)         (((n)&0xFFFF)<<0)
#define AUD_PROC_FUNC_ID(n)        (((n)&0xFFFF)<<16)

//aud_proc_cfg
#define AUD_PROC_AUD_PROC_ENABLE   (1<<0)
#define AUD_PROC_AUD_PROC_ADC_PATH_RESET (1<<1)
#define AUD_PROC_AUD_PROC_DAC_PATH_RESET (1<<2)
#define AUD_PROC_LOOPBACK_MODE     (1<<6)
#define AUD_PROC_HIGH_SPEED_MODE   (1<<7)
#define AUD_PROC_SINE_TONE_EN      (1<<8)
#define AUD_PROC_AUTO_CLOCK_GATING_EN (1<<9)
#define AUD_PROC_RX2TX_LOOP_EN     (1<<10)
#define AUD_PROC_I2S_CHN_OUT_SEL   (1<<12)
#define AUD_PROC_I2S_CHN_IN_SEL    (1<<13)
#define AUD_PROC_TX_LR_FIFO_SHARE_EN(n) (((n)&3)<<14)
#define AUD_PROC_RX_LR_FIFO_SHARE_EN(n) (((n)&3)<<16)
#define AUD_PROC_RXTX_LR_FIFO_SHARE_EN(n) (((n)&3)<<18)
#define AUD_PROC_TXRX_LR_FIFO_SHARE_EN (1<<20)
#define AUD_PROC_TXRX_BURST_MODE   (1<<21)
#define AUD_PROC_RXTX_BURST_MODE   (1<<22)
#define AUD_PROC_TX_BURST_MODE     (1<<23)
#define AUD_PROC_RX_BURST_MODE     (1<<24)
#define AUD_PROC_MONITOR_SEL(n)    (((n)&0x7F)<<25)

//aud_proc_tx_cfg_ch0
#define AUD_PROC_TX_EN_CH_0        (1<<0)
#define AUD_PROC_TX_FIFO_FLUSH_CH_0 (1<<1)
#define AUD_PROC_TX_MODE_CH_0      (1<<2)
#define AUD_PROC_TX_FIFO_STAT_CH_0(n) (((n)&3)<<3)

//aud_proc_tx_cfg_ch1
#define AUD_PROC_TX_EN_CH_1        (1<<0)
#define AUD_PROC_TX_FIFO_FLUSH_CH_1 (1<<1)
#define AUD_PROC_TX_MODE_CH_1      (1<<2)
#define AUD_PROC_TX_FIFO_STAT_CH_1(n) (((n)&3)<<3)

//aud_proc_tx_cfg_ch2
#define AUD_PROC_TX_EN_CH_2        (1<<0)
#define AUD_PROC_TX_FIFO_FLUSH_CH_2 (1<<1)
#define AUD_PROC_TX_MODE_CH_2      (1<<2)
#define AUD_PROC_TX_FIFO_STAT_CH_2(n) (((n)&3)<<3)

//aud_proc_tx_cfg_ch3
#define AUD_PROC_TX_EN_CH_3        (1<<0)
#define AUD_PROC_TX_FIFO_FLUSH_CH_3 (1<<1)
#define AUD_PROC_TX_MODE_CH_3      (1<<2)
#define AUD_PROC_TX_FIFO_STAT_CH_3(n) (((n)&3)<<3)

//aud_proc_rx_cfg_ch01
#define AUD_PROC_RX_EN_CH_0        (1<<0)
#define AUD_PROC_RX_FIFO_FLUSH_CH_01 (1<<1)
#define AUD_PROC_RX_MODE_CH_01     (1<<2)
#define AUD_PROC_RX_FIFO_STAT_CH_01(n) (((n)&3)<<3)
#define AUD_PROC_RX_EN_CH_1        (1<<5)

//aud_proc_rx_cfg_ch23
#define AUD_PROC_RX_EN_CH_2        (1<<0)
#define AUD_PROC_RX_FIFO_FLUSH_CH_23 (1<<1)
#define AUD_PROC_RX_MODE_CH_23     (1<<2)
#define AUD_PROC_RX_FIFO_STAT_CH_23(n) (((n)&3)<<3)
#define AUD_PROC_RX_EN_CH_3        (1<<5)

//aud_proc_dac_cfg1
#define AUD_PROC_SRC_IN_SEL        (1<<0)
#define AUD_PROC_SRC_MODE(n)       (((n)&15)<<1)
#define AUD_PROC_SRC_FREQ_SEL      (1<<5)
#define AUD_PROC_SRC_CH_EN(n)      (((n)&3)<<6)
#define AUD_PROC_RX_MUX_MODE_L(n)  (((n)&3)<<8)
#define AUD_PROC_TX_MUX_MODE_L(n)  (((n)&3)<<10)
#define AUD_PROC_RX_MUX_MODE_R(n)  (((n)&3)<<12)
#define AUD_PROC_TX_MUX_MODE_R(n)  (((n)&3)<<14)
#define AUD_PROC_DAC_VOLUME_L(n)   (((n)&0xFF)<<16)
#define AUD_PROC_DAC_VOLUME_R(n)   (((n)&0xFF)<<24)

//aud_proc_dac_cfg2
#define AUD_PROC_DAC_MIXER_MODE_L(n) (((n)&7)<<0)
#define AUD_PROC_DAC_MIXER_MODE_R(n) (((n)&7)<<3)
#define AUD_PROC_EQ_CH_EN(n)       (((n)&3)<<6)
#define AUD_PROC_EQ_STAGE(n)       (((n)&15)<<8)
#define AUD_PROC_EQ_CLR_DONE       (1<<12)
#define AUD_PROC_EQ_CLR            (1<<13)
#define AUD_PROC_SRC_CLR           (1<<14)
#define AUD_PROC_TX_SERIAL_DATA_STAT(n) (((n)&3)<<15)
#define AUD_PROC_TX_PARALLEL_DATA_STAT(n) (((n)&3)<<17)
#define AUD_PROC_SRC_FLT_BYPASS(n) (((n)&15)<<19)
#define AUD_PROC_AUD_PROC_DAC_TRIG_EN (1<<23)
#define AUD_PROC_AUD_PROC_TX_I2S_TRIG_EN (1<<24)

//aud_proc_adc_cfg1
#define AUD_PROC_ADC_VOLUME_L(n)   (((n)&15)<<0)
#define AUD_PROC_ADC_VOLUME_R(n)   (((n)&15)<<4)
#define AUD_PROC_ADC1_SOURCE_SEL   (1<<8)
#define AUD_PROC_LOOP_VOLUME(n)    (((n)&15)<<10)
#define AUD_PROC_ADC2_SOURCE_SEL   (1<<14)
#define AUD_PROC_ADC_SYNC_MODE     (1<<15)

//aud_proc_adc_cfg2
#define AUD_PROC_SIDE_TONE_L_INPUT_SEL (1<<0)
#define AUD_PROC_SIDE_TONE_R_INPUT_SEL (1<<1)
#define AUD_PROC_SIDE_TONE_GAIN(n) (((n)&31)<<2)
#define AUD_PROC_SIDE_TONE_MIXER_MODE_L(n) (((n)&7)<<7)
#define AUD_PROC_SIDE_TONE_MIXER_MODE_R(n) (((n)&7)<<10)
#define AUD_PROC_SIDE_TONE_MODE    (1<<13)
#define AUD_PROC_SIDE_TONE_EN      (1<<14)
#define AUD_PROC_AUD_PROC_RX01_I2S_TRIG_EN (1<<15)
#define AUD_PROC_AUD_PROC_RX23_I2S_TRIG_EN (1<<16)
#define AUD_PROC_EQ_ADC_CH_EN(n)   (((n)&3)<<17)
#define AUD_PROC_EQ_ADC_STAGE(n)   (((n)&15)<<19)
#define AUD_PROC_EQ_ADC_CLR_DONE   (1<<23)
#define AUD_PROC_EQ_ADC_CLR        (1<<24)

//aud_proc_txrx_cfg_ch0
#define AUD_PROC_TXRX_EN_CH_0      (1<<0)
#define AUD_PROC_TXRX_FIFO_FLUSH_CH_0 (1<<1)
#define AUD_PROC_TXRX_MODE_CH_0    (1<<2)
#define AUD_PROC_TXRX_FIFO_STAT_CH_0(n) (((n)&3)<<3)
#define AUD_PROC_TXRX_FIFO_AE_TH_CH_0(n) (((n)&0x7F)<<8)
#define AUD_PROC_TXRX_FIFO_FULL_SEL_CH_0 (1<<15)
#define AUD_PROC_TXRX_FIFO_AF_TH_CH_0(n) (((n)&0x7F)<<16)
#define AUD_PROC_TXRX_FIFO_CLR_CH_0 (1<<24)

//aud_proc_txrx_cfg_ch1
#define AUD_PROC_TXRX_EN_CH_1      (1<<0)
#define AUD_PROC_TXRX_FIFO_FLUSH_CH_1 (1<<1)
#define AUD_PROC_TXRX_MODE_CH_1    (1<<2)
#define AUD_PROC_TXRX_FIFO_STAT_CH_1(n) (((n)&3)<<3)

//aud_proc_rxtx_cfg_ch0
#define AUD_PROC_RXTX_EN_CH_0      (1<<0)
#define AUD_PROC_RXTX_FIFO_FLUSH_CH_0 (1<<1)
#define AUD_PROC_RXTX_MODE_CH_0    (1<<2)
#define AUD_PROC_RXTX_FIFO_STAT_CH_0(n) (((n)&3)<<3)
#define AUD_PROC_RXTX_FIFO_CLR_CH_0 (1<<5)
#define AUD_PROC_RXTX_CH01_4MAC_IN_EN (1<<6)

//aud_proc_rxtx_cfg_ch1
#define AUD_PROC_RXTX_EN_CH_1      (1<<0)
#define AUD_PROC_RXTX_FIFO_FLUSH_CH_1 (1<<1)
#define AUD_PROC_RXTX_MODE_CH_1    (1<<2)
#define AUD_PROC_RXTX_FIFO_STAT_CH_1(n) (((n)&3)<<3)
#define AUD_PROC_RXTX_FIFO_CLR_CH_1 (1<<5)

//aud_proc_frac_src
#define AUD_PROC_FRAC_SRC_EN       (1<<0)
#define AUD_PROC_FRAC_RATE_ADJ_SOFT_EN (1<<1)
#define AUD_PROC_FRAC_RATE_SOFT_SET (1<<2)
#define AUD_PROC_FRAC_RATE_ADJ_SW(n) (((n)&0xFFFFFF)<<4)

//aud_proc_dac_trig
#define AUD_PROC_AUD_DAC_TRIG_CFG_UPDATE (1<<0)
#define AUD_PROC_AUD_PROC_DAC_STRB_LRCK_SEL (1<<2)
#define AUD_PROC_DAC_SRC_TRIG_CNT_TH(n) (((n)&0xFFFFFF)<<4)
#define AUD_PROC_AUD_PROC_DAC_STRB_MODE (1<<28)
#define AUD_PROC_AUD_DAC_TRIG_SW_OE (1<<29)
#define AUD_PROC_AUD_DAC_TRIG_SW   (1<<30)
#define AUD_PROC_AUD_DAC_TRIG_HW_EN (1<<31)

//aud_proc_dac_strb
#define AUD_PROC_DAC_SRC_STRB_LO_CNT_TH(n) (((n)&0xFFFFFF)<<0)
#define AUD_PROC_AUD_PROC_DAC_STB_SEL(n) (((n)&3)<<28)
#define AUD_PROC_BT_CLK_STRB_INV   (1<<30)
#define AUD_PROC_DAC_SRC_STRB_CNT_EN (1<<31)

//aud_proc_irq
#define AUD_PROC_IRQ_AUD_PROC_MASKED(n) (((n)&15)<<0)
#define AUD_PROC_IRQ_AUD_PROC_RAW(n) (((n)&15)<<4)
#define AUD_PROC_IRQ_AUD_PROC_MASK(n) (((n)&15)<<16)
#define AUD_PROC_IRQ_AUD_PROC_CLR(n) (((n)&15)<<20)

//bt_clk_lo_cnt
#define AUD_PROC_BT_CLK_LO_CNT(n)  (((n)&0xFFFFFF)<<0)

//bt_clk_hi_cnt
#define AUD_PROC_BT_CLK_HI_CNT(n)  (((n)&0xFFFFFFFF)<<0)

//bt_clk_lo_cnt_latch
#define AUD_PROC_BT_CLK_LO_CNT_LATCH(n) (((n)&0xFFFFFF)<<0)
#define AUD_PROC_BT_CLK_LO_FRAC_CNT_LATCH(n) (((n)&0x3F)<<24)

//bt_clk_hi_cnt_latch
#define AUD_PROC_BT_CLK_HI_CNT_LATCH(n) (((n)&0xFFFFFFFF)<<0)

//dac_src_strb_lo_cnt
#define AUD_PROC_DAC_SRC_STRB_LO_CNT(n) (((n)&0xFFFFFF)<<0)
#define AUD_PROC_SRC_FRAC_STRB_LATCH(n) (((n)&0xFF)<<24)

//dac_src_strb_hi_cnt
#define AUD_PROC_DAC_SRC_STRB_HI_CNT(n) (((n)&0xFFFFFFFF)<<0)

//dpll_alfa1_cfg
#define AUD_PROC_DPLL_1_SUB_ALFA1(n) (((n)&0x3FFF)<<0)
#define AUD_PROC_DPLL_ALFA1(n)     (((n)&0x3FFF)<<16)

//dpll_k1_k2_cfg
#define AUD_PROC_DPLL_K2(n)        (((n)&0x3FFF)<<0)
#define AUD_PROC_DPLL_K1(n)        (((n)&0x3FFF)<<16)

//dpll_alfa2_cfg
#define AUD_PROC_DPLL_1_SUB_ALFA2(n) (((n)&0x3FFF)<<0)
#define AUD_PROC_DPLL_ALFA2(n)     (((n)&0x3FFF)<<16)

//dpll_other_cfg1
#define AUD_PROC_DPLL_GAIN(n)      (((n)&0x3FFF)<<0)

//dpll_trig_cfg
#define AUD_PROC_DPLL_STEP_TRIG    (1<<0)
#define AUD_PROC_DPLL_HW_EN        (1<<1)
#define AUD_PROC_DPLL_DIN(n)       (((n)&0x1FFFF)<<2)
#define AUD_PROC_DPLL_CAL_FINISH   (1<<19)

//frac_rate_adj_up_th
#define AUD_PROC_FRAC_RATE_ADJ_UP_TH(n) (((n)&0xFFFFFF)<<0)
#define AUD_PROC_FRAC_48K_CNT_TH_H(n) (((n)&31)<<24)

//frac_rate_adj_dn_th
#define AUD_PROC_FRAC_RATE_ADJ_DN_TH(n) (((n)&0xFFFFFF)<<0)
#define AUD_PROC_FRAC_48K_CNT_TH_L(n) (((n)&0xFF)<<24)

//frac_rate_adj_hw
#define AUD_PROC_FRAC_RATE_ADJ_HW(n) (((n)&0xFFFFFF)<<0)

//aud_intf_i2s_cfg0
#define AUD_PROC_SWAP_CHLR_0(n)    (((n)&3)<<0)
#define AUD_PROC_LOOP_BACK_0       (1<<2)
#define AUD_PROC_LSB_0             (1<<3)
#define AUD_PROC_RIGHT_JUSTIFIED_0 (1<<4)
#define AUD_PROC_BCK_LRCK_0(n)     (((n)&31)<<5)
#define AUD_PROC_WLEN_0(n)         (((n)&3)<<10)
#define AUD_PROC_LRCK_POL_0        (1<<12)
#define AUD_PROC_BCK_POL_0         (1<<13)
#define AUD_PROC_BCKOUT_GATE_0     (1<<14)
#define AUD_PROC_RX_HALF_CYCLE_DLY_0 (1<<15)
#define AUD_PROC_TX_HALF_CYCLE_DLY_0 (1<<16)
#define AUD_PROC_RX_DLY_0(n)       (((n)&3)<<17)
#define AUD_PROC_TX_DLY_S_0        (1<<19)
#define AUD_PROC_TX_DLY_0          (1<<20)
#define AUD_PROC_MASTER_MODE_0     (1<<21)
#define AUD_PROC_RX_SERIAL_MODE_0(n) (((n)&7)<<22)
#define AUD_PROC_TX_SERIAL_MODE_0(n) (((n)&7)<<25)
#define AUD_PROC_TX_OFF_0          (1<<28)
#define AUD_PROC_TX_MODE_0(n)      (((n)&3)<<29)
#define AUD_PROC_I2S_ENABLE_0      (1<<31)

//aud_intf_i2s_cfg1
#define AUD_PROC_SWAP_CHLR_1(n)    (((n)&3)<<0)
#define AUD_PROC_LOOP_BACK_1       (1<<2)
#define AUD_PROC_LSB_1             (1<<3)
#define AUD_PROC_RIGHT_JUSTIFIED_1 (1<<4)
#define AUD_PROC_BCK_LRCK_1(n)     (((n)&31)<<5)
#define AUD_PROC_WLEN_1(n)         (((n)&3)<<10)
#define AUD_PROC_LRCK_POL_1        (1<<12)
#define AUD_PROC_BCK_POL_1         (1<<13)
#define AUD_PROC_BCKOUT_GATE_1     (1<<14)
#define AUD_PROC_RX_HALF_CYCLE_DLY_1 (1<<15)
#define AUD_PROC_TX_HALF_CYCLE_DLY_1 (1<<16)
#define AUD_PROC_RX_DLY_1(n)       (((n)&3)<<17)
#define AUD_PROC_TX_DLY_S_1        (1<<19)
#define AUD_PROC_TX_DLY_1          (1<<20)
#define AUD_PROC_MASTER_MODE_1     (1<<21)
#define AUD_PROC_RX_SERIAL_MODE_1(n) (((n)&7)<<22)
#define AUD_PROC_TX_SERIAL_MODE_1(n) (((n)&7)<<25)
#define AUD_PROC_TX_OFF_1          (1<<28)
#define AUD_PROC_TX_MODE_1(n)      (((n)&3)<<29)
#define AUD_PROC_I2S_ENABLE_1      (1<<31)

//pcm_cfg_0
#define AUD_PROC_SLOTNUM_0(n)      (((n)&0xFF)<<0)
#define AUD_PROC_LONGSYNC_0        (1<<8)
#define AUD_PROC_TX_BIT_MODE_0     (1<<9)
#define AUD_PROC_RX_BIT_MODE_0     (1<<10)
#define AUD_PROC_LRCK_M_DLY_0      (1<<11)
#define AUD_PROC_TX_SYNC_MODE_0    (1<<12)

//pcm_cfg_1
#define AUD_PROC_SLOTNUM_1(n)      (((n)&0xFF)<<0)
#define AUD_PROC_LONGSYNC_1        (1<<8)
#define AUD_PROC_TX_BIT_MODE_1     (1<<9)
#define AUD_PROC_RX_BIT_MODE_1     (1<<10)
#define AUD_PROC_LRCK_M_DLY_1      (1<<11)
#define AUD_PROC_TX_SYNC_MODE_1    (1<<12)

//spdif_userdata_0
#define AUD_PROC_SPDIF_USERDATA_0(n) (((n)&0xFFFFFFFF)<<0)

//spdif_userdata_1
#define AUD_PROC_SPDIF_USERDATA_1(n) (((n)&0xFFFFFFFF)<<0)

//spdif_userdata_2
#define AUD_PROC_SPDIF_USERDATA_2(n) (((n)&0xFFFFFFFF)<<0)

//spdif_userdata_3
#define AUD_PROC_SPDIF_USERDATA_3(n) (((n)&0xFFFFFFFF)<<0)

//spdif_userdata_4
#define AUD_PROC_SPDIF_USERDATA_4(n) (((n)&0xFFFFFFFF)<<0)

//spdif_userdata_5
#define AUD_PROC_SPDIF_USERDATA_5(n) (((n)&0xFFFFFFFF)<<0)

//spdif_channel_stat_0
#define AUD_PROC_SPDIF_CHANNEL_STAT_0(n) (((n)&0xFFFFFFFF)<<0)

//spdif_channel_stat_1
#define AUD_PROC_SPDIF_CHANNEL_STAT_1(n) (((n)&0xFFFFFFFF)<<0)

//spdif_channel_stat_2
#define AUD_PROC_SPDIF_CHANNEL_STAT_2(n) (((n)&0xFFFFFFFF)<<0)

//spdif_channel_stat_3
#define AUD_PROC_SPDIF_CHANNEL_STAT_3(n) (((n)&0xFFFFFFFF)<<0)

//spdif_channel_stat_4
#define AUD_PROC_SPDIF_CHANNEL_STAT_4(n) (((n)&0xFFFFFFFF)<<0)

//spdif_channel_stat_5
#define AUD_PROC_SPDIF_CHANNEL_STAT_5(n) (((n)&0xFFFFFFFF)<<0)

//spdif_output_cfg
#define AUD_PROC_VALIDITY_FLAG     (1<<0)
#define AUD_PROC_VUCZ_MODE(n)      (((n)&3)<<1)
#define AUD_PROC_REQ_POINT(n)      (((n)&31)<<3)
#define AUD_PROC_START_ZEN         (1<<8)

//spdif_input_cfg
#define AUD_PROC_SPDIF_IN_FSDET_EN (1<<0)
#define AUD_PROC_SPDIF_IN_CFG(n)   (((n)&0x1FFF)<<1)
#define AUD_PROC_IAAU_SPDIF_IN(n)  (((n)&0x7FF)<<14)

//spdif_input_stat1
#define AUD_PROC_SPDIF_IN_BIT_WIDTH(n) (((n)&0xFF)<<0)
#define AUD_PROC_STATUS_SPDIF_IN(n) (((n)&0x3FFFFF)<<8)

//spdif_input_stat2
#define AUD_PROC_CHANNEL_SPDIF_IN(n) (((n)&0xFFFFFFFF)<<0)

//aud_drc_cfg0
#define AUD_PROC_CFG_AUD_DRC_CHNL_EN(n) (((n)&3)<<0)
#define AUD_PROC_CFG_AUD_DRC_CLR   (1<<8)
#define AUD_PROC_AUD_DRC_CLR_DONE  (1<<9)
#define AUD_PROC_CFG_DRC_BAND3_MODE(n) (((n)&7)<<10)
#define AUD_PROC_CFG_DRC_BAND3_EN  (1<<13)
#define AUD_PROC_CFG_DRC_EQ_SWAP   (1<<14)
#define AUD_PROC_CFG_DRC_EN        (1<<16)
#define AUD_PROC_CFG_DRC_STAGE_CNT(n) (((n)&3)<<17)
#define AUD_PROC_CFG_DRC_BAND2_MODE(n) (((n)&15)<<20)
#define AUD_PROC_CFG_DRC_BAND1_MODE(n) (((n)&7)<<24)
#define AUD_PROC_CFG_DRC_BAND0_MODE(n) (((n)&7)<<27)

//eq_stereo_coef_ram_cfg0
#define AUD_PROC_EQ_STEREO_COEF_WR (1<<0)
#define AUD_PROC_EQ_STEREO_COEF_ADDR(n) (((n)&0x7F)<<1)
#define AUD_PROC_EQ_STEREO_COEF_WDATA(n) (((n)&0xFFFFFF)<<8)

//eq_stereo_coef_ram_cfg1
#define AUD_PROC_EQ_STEREO_COEF_RD (1<<0)
#define AUD_PROC_EQ_STEREO_COEF_RDATA(n) (((n)&0xFFFFFF)<<8)

//eq_mono_coef_ram_cfg0
#define AUD_PROC_EQ_MONO_COEF_WR   (1<<0)
#define AUD_PROC_EQ_MONO_COEF_RD   (1<<1)
#define AUD_PROC_EQ_MONO_COEF_ADDR(n) (((n)&0x3F)<<2)
#define AUD_PROC_EQ_MONO_COEF_WDATA(n) (((n)&0xFFFFFF)<<8)

//eq_mono_coef_ram_cfg1
#define AUD_PROC_EQ_MONO_COEF_RDATA(n) (((n)&0xFFFFFF)<<8)

//aud_drc_ram_cfg0
#define AUD_PROC_CFG_AUD_DRC_RAM_WR (1<<0)
#define AUD_PROC_CFG_AUD_DRC_RAM_RD (1<<1)
#define AUD_PROC_CFG_AUD_DRC_RAM_ADDR(n) (((n)&0x7F)<<8)
#define AUD_PROC_CFG_AUD_DRC_RAM_SEL(n) (((n)&3)<<16)

//aud_drc_ram_cfg1
#define AUD_PROC_CFG_AUD_DRC_RAM_WDATA(n) (((n)&0xFFFFFFFF)<<0)

//aud_drc_ram_cfg2
#define AUD_PROC_CFG_AUD_DRC_RAM_RDATA(n) (((n)&0xFFFFFFFF)<<0)

//aud_src_ctrl0
#define AUD_PROC_AUD_SRC_ENABLE    (1<<0)
#define AUD_PROC_AUD_SRC_PATH_RESET (1<<1)
#define AUD_PROC_AUD_SRC_TXRX_LR_FIFO_SHARE_EN (1<<2)
#define AUD_PROC_AUD_SRC_TX_LR_FIFO_SHARE_EN (1<<3)
#define AUD_PROC_AUD_SRC_TXRX_EN_CH_1 (1<<4)
#define AUD_PROC_AUD_SRC_TXRX_EN_CH_0 (1<<5)
#define AUD_PROC_AUD_SRC_TXRX_FIFO_FLUSH_CH (1<<6)
#define AUD_PROC_AUD_SRC_TXRX_MODE_CH (1<<7)
#define AUD_PROC_AUD_SRC_TX_EN_CH_1 (1<<8)
#define AUD_PROC_AUD_SRC_TX_EN_CH_0 (1<<9)
#define AUD_PROC_AUD_SRC_TX_FIFO_FLUSH_CH (1<<10)
#define AUD_PROC_AUD_SRC_TX_MODE_CH (1<<11)
#define AUD_PROC_AUD_SRC_AUTO_CLOCK_GATING_EN (1<<12)
#define AUD_PROC_AUD_SRC_ADC_IN_EN (1<<13)
#define AUD_PROC_AUD_SRC_TXRX_BURST_MODE (1<<14)
#define AUD_PROC_AUD_SRC_TX_BURST_MODE (1<<15)
#define AUD_PROC_AUD_SRC_TXRX_CH_STAT(n) (((n)&3)<<16)
#define AUD_PROC_AUD_SRC_TX_CH_STAT(n) (((n)&3)<<18)

//aud_src_ctrl1
#define AUD_PROC_AUD_SRC_FRAC_RATE_ADJ_SW(n) (((n)&0xFFFFFF)<<0)
#define AUD_PROC_AUD_SRC_FRAC_RATE_SOFT_SET (1<<24)

//aud_src_ctrl2
#define AUD_PROC_AUD_SRC_FRAC_SRC_EN (1<<0)
#define AUD_PROC_AUD_SRC_CH_EN(n)  (((n)&3)<<1)
#define AUD_PROC_AUD_SRC_FREQ_SEL  (1<<3)
#define AUD_PROC_AUD_SRC_MODE(n)   (((n)&15)<<4)
#define AUD_PROC_AUD_SRC_CLR       (1<<8)
#define AUD_PROC_AUD_SRC_FLT_BYPASS(n) (((n)&15)<<9)
#define AUD_PROC_AUD_SRC_DECIM24_SEL (1<<13)
#define AUD_PROC_AUD_SRC_DECIM24_BYPASS (1<<14)
#define AUD_PROC_AUD_SRC_DECIM3_SEL (1<<15)
#define AUD_PROC_AUD_SRC_DECIM3_BYPASS (1<<16)





#endif

