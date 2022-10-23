#ifndef _AIC1000AUD_AUD_CODEC_H_
#define _AIC1000AUD_AUD_CODEC_H_

#include "chip.h"

// =============================================================================
//  MACROS
// =============================================================================

// =============================================================================
//  TYPES
// =============================================================================

// ============================================================================
// AIC1000AUD_AUD_CODEC_T
// -----------------------------------------------------------------------------
///
// =============================================================================
#define REG_AIC1000AUD_AUD_CODEC_BASE 0x5001D000

typedef struct {
    __IO uint32_t                          core_ctrl0;                   //0x00000000
    __IO uint32_t                          core_ctrl1;                   //0x00000004
    __IO uint32_t                          intf_ctrl;                    //0x00000008
    __IO uint32_t                          clk_ctrl;                     //0x0000000C
    __IO uint32_t                          dac_sdm_ctrl;                 //0x00000010
    __IO uint32_t                          delay_ctrl;                   //0x00000014
    __IO uint32_t                          dmic_ctrl;                    //0x00000018
    __IO uint32_t                          Reserved_0000001C;            //0x0000001C
    __IO uint32_t                          iis_ctrl0;                    //0x00000020
    __IO uint32_t                          iis_ctrl1;                    //0x00000024
    __IO uint32_t                          mem_ctrl;                     //0x00000028
    __IO uint32_t                          aud_cfg_sync;                 //0x0000002C
    __IO uint32_t                          flt3b_01;                     //0x00000030
    __IO uint32_t                          flt3b_23;                     //0x00000034
    __IO uint32_t                          flt3b_45;                     //0x00000038
    __IO uint32_t                          flt3b_67;                     //0x0000003C
    __IO uint32_t                          flt3b_89;                     //0x00000040
    __IO uint32_t                          flt3b_ab;                     //0x00000044
    __IO uint32_t                          flt3b_cd;                     //0x00000048
    __IO uint32_t                          flt3b_e;                      //0x0000004C
    __IO uint32_t                          mem_ctrl1;                    //0x00000050
    __IO uint32_t                          mem_ctrl2;                    //0x00000054
    __IO uint32_t                          mem_ctrl3;                    //0x00000058
    __IO uint32_t                          mem_ctrl4;                    //0x0000005C
    __IO uint32_t                          dac_calib0;                   //0x00000060
    __IO uint32_t                          dac_calib1;                   //0x00000064
    __IO uint32_t                          dac_calib2;                   //0x00000068
    __IO uint32_t                          ana_clk1;                     //0x0000006C
    __IO uint32_t                          mic_dc_ctrl;                  //0x00000070
    __IO uint32_t                          mic_idc0;                     //0x00000074
    __IO uint32_t                          mic_idc1;                     //0x00000078
    __IO uint32_t                          mic_idc2;                     //0x0000007C
    __IO uint32_t                          vad_idc0;                     //0x00000080
    __IO uint32_t                          mic_odc0;                     //0x00000084
    __IO uint32_t                          mic_odc1;                     //0x00000088
    __IO uint32_t                          mic_odc2;                     //0x0000008C
    __IO uint32_t                          spk_dc0;                      //0x00000090
    __IO uint32_t                          spk_dc1;                      //0x00000094
    __IO uint32_t                          spk_gain;                     //0x00000098
    __IO uint32_t                          mic_gain;                     //0x0000009C
    __IO uint32_t                          abb_reserved;                 //0x000000A0
    __IO uint32_t                          abb_ivref;                    //0x000000A4
    __IO uint32_t                          abb_micbias;                  //0x000000A8
    __IO uint32_t                          abb_vad;                      //0x000000AC
    __IO uint32_t                          abb_micpga_1;                 //0x000000B0
    __IO uint32_t                          abb_micpga_2;                 //0x000000B4
    __IO uint32_t                          abb_micpga_3;                 //0x000000B8
    __IO uint32_t                          abb_sdm_adc_cal;              //0x000000BC
    __IO uint32_t                          abb_sdm_adc0;                 //0x000000C0
    __IO uint32_t                          abb_sdm_dac1;                 //0x000000C4
    __IO uint32_t                          abb_hp_os;                    //0x000000C8
    __IO uint32_t                          abb_hp_l;                     //0x000000CC
    __IO uint32_t                          abb_hp_r;                     //0x000000D0
} HWP_AIC1000AUD_AUD_CODEC_T;

static HWP_AIC1000AUD_AUD_CODEC_T* const aic1000audAudCodec = ((HWP_AIC1000AUD_AUD_CODEC_T*)REG_AIC1000AUD_AUD_CODEC_BASE);

//core_ctrl0
#define AIC1000AUD_AUD_CODEC_MIC_ADC_EN(n) (((n)&7)<<0)
#define AIC1000AUD_AUD_CODEC_MIC_ANC_EN(n) (((n)&3)<<4)
#define AIC1000AUD_AUD_CODEC_MIC_TRA_EN(n) (((n)&3)<<6)
#define AIC1000AUD_AUD_CODEC_MIC_D36_EN(n) (((n)&3)<<8)
#define AIC1000AUD_AUD_CODEC_SPK_DAC_EN(n) (((n)&3)<<16)
#define AIC1000AUD_AUD_CODEC_SPK_ANC_EN(n) (((n)&3)<<18)
#define AIC1000AUD_AUD_CODEC_ADDA_DLY_EN (1<<20)
#define AIC1000AUD_AUD_CODEC_ADDA_DLY_BSPK (1<<21)
#define AIC1000AUD_AUD_CODEC_ADDA_DLY_BMIC (1<<22)
#define AIC1000AUD_AUD_CODEC_SPK_SYNC_EN (1<<23)
#define AIC1000AUD_AUD_CODEC_AUD_CFG_CHG_CLR (1<<30)
#define AIC1000AUD_AUD_CODEC_AUD_CFG_POS (1<<31)

//core_ctrl1
#define AIC1000AUD_AUD_CODEC_MIC_CD50_STG(n) (((n)&3)<<0)
#define AIC1000AUD_AUD_CODEC_MIC_ADC_P0(n) (((n)&3)<<2)
#define AIC1000AUD_AUD_CODEC_MIC_ADC_P1(n) (((n)&3)<<4)
#define AIC1000AUD_AUD_CODEC_MIC_ADC_P2(n) (((n)&3)<<6)
#define AIC1000AUD_AUD_CODEC_MIC_ANC_P0(n) (((n)&3)<<8)
#define AIC1000AUD_AUD_CODEC_MIC_ANC_P1(n) (((n)&3)<<10)
#define AIC1000AUD_AUD_CODEC_MIC_TRA_P0(n) (((n)&3)<<12)
#define AIC1000AUD_AUD_CODEC_MIC_TRA_P1(n) (((n)&3)<<14)
#define AIC1000AUD_AUD_CODEC_SPK_SIN_EN (1<<23)
#define AIC1000AUD_AUD_CODEC_VAD_EN (1<<28)
#define AIC1000AUD_AUD_CODEC_MIC_CDN5_STG(n) (((n)&3)<<29)
#define AIC1000AUD_AUD_CODEC_MIC_D36_D3 (1<<31)

//intf_ctrl
#define AIC1000AUD_AUD_CODEC_ANA_DAC_RSTN (1<<0)
#define AIC1000AUD_AUD_CODEC_CLKEDGE_ADCIF (1<<1)
#define AIC1000AUD_AUD_CODEC_LOOP_EN(n) (((n)&3)<<2)
#define AIC1000AUD_AUD_CODEC_ADC_FIFO_RDTH(n) (((n)&7)<<4)
#define AIC1000AUD_AUD_CODEC_SPK_INTF_FIX (1<<7)
#define AIC1000AUD_AUD_CODEC_TPORTS_SEL(n) (((n)&0x3F)<<8)
#define AIC1000AUD_AUD_CODEC_LOOP_EN_S2M(n) (((n)&3)<<14)
#define AIC1000AUD_AUD_CODEC_ADDA_DLY_NUM(n) (((n)&0x7FF)<<16)

//clk_ctrl
#define AIC1000AUD_AUD_CODEC_CGEN_VAL(n) (((n)&0xFFFF)<<0)
#define AIC1000AUD_AUD_CODEC_CGEN_FIX(n) (((n)&0xFFFF)<<16)

//dac_sdm_ctrl
#define AIC1000AUD_AUD_CODEC_DITHER_GAIN0(n) (((n)&15)<<0)
#define AIC1000AUD_AUD_CODEC_DITHER_EN0 (1<<4)
#define AIC1000AUD_AUD_CODEC_DWA_EN0 (1<<5)
#define AIC1000AUD_AUD_CODEC_MASH_MUTE0(n) (((n)&3)<<6)
#define AIC1000AUD_AUD_CODEC_DITHER_GAIN1(n) (((n)&15)<<8)
#define AIC1000AUD_AUD_CODEC_DITHER_EN1 (1<<12)
#define AIC1000AUD_AUD_CODEC_DWA_EN1 (1<<13)
#define AIC1000AUD_AUD_CODEC_MASH_MUTE1(n) (((n)&3)<<14)
#define AIC1000AUD_AUD_CODEC_DAC_SDM_MUX (1<<20)
#define AIC1000AUD_AUD_CODEC_DAC_48K_MUX (1<<21)
#define AIC1000AUD_AUD_CODEC_MIC_TRA_MUX (1<<22)
#define AIC1000AUD_AUD_CODEC_MIC_ANC_MUX (1<<23)
#define AIC1000AUD_AUD_CODEC_SPK_SRC_DLY (1<<24)

//delay_ctrl
#define AIC1000AUD_AUD_CODEC_NDONE_SPK_FDN5(n) (((n)&15)<<0)
#define AIC1000AUD_AUD_CODEC_NDONE_MIC_CD50(n) (((n)&0x3F)<<4)
#define AIC1000AUD_AUD_CODEC_NDONE_MIC_CDN5(n) (((n)&31)<<10)
#define AIC1000AUD_AUD_CODEC_MIC_FDN5_NOUT(n) (((n)&0xFF)<<16)
#define AIC1000AUD_AUD_CODEC_MIC_CDN5_NOUT(n) (((n)&31)<<24)
#define AIC1000AUD_AUD_CODEC_NDONE_MIC_CD36 (1<<31)

//dmic_ctrl
#define AIC1000AUD_AUD_CODEC_DMIC_CDIV(n) (((n)&0x3F)<<0)
#define AIC1000AUD_AUD_CODEC_DMIC_SMPN0(n) (((n)&0x3F)<<6)
#define AIC1000AUD_AUD_CODEC_DMIC_SMPN1(n) (((n)&0x3F)<<12)
#define AIC1000AUD_AUD_CODEC_DMIC_SMPN2(n) (((n)&0x3F)<<18)
#define AIC1000AUD_AUD_CODEC_DMIC_EN(n) (((n)&7)<<24)
#define AIC1000AUD_AUD_CODEC_DMIC_ALIGN (1<<27)
#define AIC1000AUD_AUD_CODEC_DMIC_U12D (1<<28)

//iis_ctrl0
#define AIC1000AUD_AUD_CODEC_CDIV_IIS(n) (((n)&0xFF)<<0)
#define AIC1000AUD_AUD_CODEC_HCYC_IIS0(n) (((n)&0xFF)<<8)
#define AIC1000AUD_AUD_CODEC_HCYC_IIS1(n) (((n)&0xFF)<<16)
#define AIC1000AUD_AUD_CODEC_CLKD_FSN(n) (((n)&15)<<24)
#define AIC1000AUD_AUD_CODEC_CLKD_FSN_LD (1<<28)
#define AIC1000AUD_AUD_CODEC_IIS_EN (1<<29)
#define AIC1000AUD_AUD_CODEC_ANC_240K (1<<30)
#define AIC1000AUD_AUD_CODEC_AUD_240K (1<<31)

//iis_ctrl1
#define AIC1000AUD_AUD_CODEC_IIS0_IDAT_EN (1<<0)
#define AIC1000AUD_AUD_CODEC_IIS0_ODAT_EN (1<<1)
#define AIC1000AUD_AUD_CODEC_IIS0_ODAT_SEL(n) (((n)&3)<<2)
#define AIC1000AUD_AUD_CODEC_IIS0_TRIG_SEL (1<<4)
#define AIC1000AUD_AUD_CODEC_SPK_IIS_PHI(n) (((n)&7)<<5)
#define AIC1000AUD_AUD_CODEC_IIS1_IDAT_EN (1<<8)
#define AIC1000AUD_AUD_CODEC_IIS1_ODAT_EN (1<<9)
#define AIC1000AUD_AUD_CODEC_IIS1_ODAT_SEL(n) (((n)&3)<<10)
#define AIC1000AUD_AUD_CODEC_IIS1_TRIG_SEL (1<<12)
#define AIC1000AUD_AUD_CODEC_IIS1_TRIG_EN (1<<13)
#define AIC1000AUD_AUD_CODEC_IIS0_TRIG_EN (1<<14)
#define AIC1000AUD_AUD_CODEC_IIS_LR_SHORT (1<<15)
#define AIC1000AUD_AUD_CODEC_MUSIC2ANC_DLY0(n) (((n)&31)<<16)
#define AIC1000AUD_AUD_CODEC_SPK240K_DLY0(n) (((n)&7)<<21)
#define AIC1000AUD_AUD_CODEC_MUSIC2ANC_DLY1(n) (((n)&31)<<24)
#define AIC1000AUD_AUD_CODEC_SPK240K_DLY1(n) (((n)&7)<<29)

//mem_ctrl
#define AIC1000AUD_AUD_CODEC_SPK_MEM_CLR (1<<0)
#define AIC1000AUD_AUD_CODEC_SPK_MEM_CLR_DONE (1<<1)
#define AIC1000AUD_AUD_CODEC_MIC_MEM_CLR (1<<2)
#define AIC1000AUD_AUD_CODEC_MIC_MEM_CLR_DONE (1<<3)
#define AIC1000AUD_AUD_CODEC_SPK_MEM_CLKSEL (1<<4)
#define AIC1000AUD_AUD_CODEC_MIC_MEM_CLKSEL (1<<5)
#define AIC1000AUD_AUD_CODEC_SDM_FIFO_WR_EMPTY (1<<12)
#define AIC1000AUD_AUD_CODEC_SDM_FIFO_WR_FULL (1<<13)
#define AIC1000AUD_AUD_CODEC_SDM_FIFO_RD_EMPTY (1<<14)
#define AIC1000AUD_AUD_CODEC_SDM_FIFO_RD_FULL (1<<15)

//aud_cfg_sync
#define AIC1000AUD_AUD_CODEC_MIC_ADC_EN_SYNC(n) (((n)&7)<<0)
#define AIC1000AUD_AUD_CODEC_MIC_ANC_EN_SYNC(n) (((n)&3)<<4)
#define AIC1000AUD_AUD_CODEC_MIC_TRA_EN_SYNC(n) (((n)&3)<<6)
#define AIC1000AUD_AUD_CODEC_MIC_D36_EN_SYNC(n) (((n)&3)<<8)
#define AIC1000AUD_AUD_CODEC_SPK_DAC_EN_SYNC(n) (((n)&3)<<16)
#define AIC1000AUD_AUD_CODEC_SPK_ANC_EN_SYNC(n) (((n)&3)<<18)
#define AIC1000AUD_AUD_CODEC_AUD_CFG_CHG (1<<20)
#define AIC1000AUD_AUD_CODEC_AUD_CFG_CHG_DONE (1<<21)

//flt3b_01
#define AIC1000AUD_AUD_CODEC_FLT3B_1(n) (((n)&0xFFFF)<<0)
#define AIC1000AUD_AUD_CODEC_FLT3B_0(n) (((n)&0xFFFF)<<16)

//flt3b_23
#define AIC1000AUD_AUD_CODEC_FLT3B_3(n) (((n)&0xFFFF)<<0)
#define AIC1000AUD_AUD_CODEC_FLT3B_2(n) (((n)&0xFFFF)<<16)

//flt3b_45
#define AIC1000AUD_AUD_CODEC_FLT3B_5(n) (((n)&0xFFFF)<<0)
#define AIC1000AUD_AUD_CODEC_FLT3B_4(n) (((n)&0xFFFF)<<16)

//flt3b_67
#define AIC1000AUD_AUD_CODEC_FLT3B_7(n) (((n)&0xFFFF)<<0)
#define AIC1000AUD_AUD_CODEC_FLT3B_6(n) (((n)&0xFFFF)<<16)

//flt3b_89
#define AIC1000AUD_AUD_CODEC_FLT3B_9(n) (((n)&0xFFFF)<<0)
#define AIC1000AUD_AUD_CODEC_FLT3B_8(n) (((n)&0xFFFF)<<16)

//flt3b_ab
#define AIC1000AUD_AUD_CODEC_FLT3B_B(n) (((n)&0xFFFF)<<0)
#define AIC1000AUD_AUD_CODEC_FLT3B_A(n) (((n)&0xFFFF)<<16)

//flt3b_cd
#define AIC1000AUD_AUD_CODEC_FLT3B_D(n) (((n)&0xFFFF)<<0)
#define AIC1000AUD_AUD_CODEC_FLT3B_C(n) (((n)&0xFFFF)<<16)

//flt3b_e
#define AIC1000AUD_AUD_CODEC_FLT3B_NUM(n) (((n)&31)<<0)
#define AIC1000AUD_AUD_CODEC_FLT3B_E(n) (((n)&0xFFFF)<<16)

//mem_ctrl1
#define AIC1000AUD_AUD_CODEC_BUS_MEM_AA(n) (((n)&0xFF)<<0)
#define AIC1000AUD_AUD_CODEC_BUS_MEM_WE (1<<8)
#define AIC1000AUD_AUD_CODEC_BUS_MEM_RE (1<<9)
#define AIC1000AUD_AUD_CODEC_BUS_MEM_EN (1<<10)

//mem_ctrl2
#define AIC1000AUD_AUD_CODEC_BUS_MEM_D0(n) (((n)&0xFFFFFFFF)<<0)

//mem_ctrl3
#define AIC1000AUD_AUD_CODEC_BUS_MEM_Q1(n) (((n)&0x1FFF)<<0)
#define AIC1000AUD_AUD_CODEC_BUS_MEM_D1(n) (((n)&0x1FFF)<<16)

//mem_ctrl4
#define AIC1000AUD_AUD_CODEC_BUS_MEM_Q0(n) (((n)&0xFFFFFFFF)<<0)

//dac_calib0
#define AIC1000AUD_AUD_CODEC_DAC_CALIB_CLKEN (1<<0)
#define AIC1000AUD_AUD_CODEC_DIV_SPK_DCCAL(n) (((n)&7)<<1)
#define AIC1000AUD_AUD_CODEC_SPK0_DCCAL_EN_POS (1<<4)
#define AIC1000AUD_AUD_CODEC_SPK0_DCCAL_SEL (1<<5)
#define AIC1000AUD_AUD_CODEC_SPK1_DCCAL_EN_POS (1<<6)
#define AIC1000AUD_AUD_CODEC_SPK1_DCCAL_SEL (1<<7)
#define AIC1000AUD_AUD_CODEC_SPK_HP_AUX_UPEN (1<<8)
#define AIC1000AUD_AUD_CODEC_SPK_HP_AUX_DNEN (1<<9)
#define AIC1000AUD_AUD_CODEC_SPK_HP_DAC_UPEN (1<<10)
#define AIC1000AUD_AUD_CODEC_SPK_HP_DAC_DNEN (1<<11)
#define AIC1000AUD_AUD_CODEC_SPK_HP_AUX_DIV(n) (((n)&15)<<12)
#define AIC1000AUD_AUD_CODEC_SPK_HP_DAC_DIV(n) (((n)&15)<<16)
#define AIC1000AUD_AUD_CODEC_ADC_DTH_CLKEN (1<<20)

//dac_calib1
#define AIC1000AUD_AUD_CODEC_SPK0_DCCAL_BIT(n) (((n)&0x3F)<<0)
#define AIC1000AUD_AUD_CODEC_HP_L_OS_CAL_DOUT (1<<7)
#define AIC1000AUD_AUD_CODEC_SPK1_DCCAL_BIT(n) (((n)&0x3F)<<8)
#define AIC1000AUD_AUD_CODEC_HP_R_OS_CAL_DOUT (1<<15)
#define AIC1000AUD_AUD_CODEC_SPK0_DCCAL_VAL(n) (((n)&0x3F)<<16)
#define AIC1000AUD_AUD_CODEC_SPK0_DCCAL_ING (1<<23)
#define AIC1000AUD_AUD_CODEC_SPK1_DCCAL_VAL(n) (((n)&0x3F)<<24)
#define AIC1000AUD_AUD_CODEC_SPK1_DCCAL_ING (1<<31)

//dac_calib2
#define AIC1000AUD_AUD_CODEC_SPK_HP_AUX_UP_END(n) (((n)&0x3FF)<<0)
#define AIC1000AUD_AUD_CODEC_SPK_HP_AUX_DN_END(n) (((n)&0x3FF)<<16)

//ana_clk1
#define AIC1000AUD_AUD_CODEC_CDIV_VAD_PGA_RFRSH(n) (((n)&7)<<0)
#define AIC1000AUD_AUD_CODEC_CGEN_VAD_PGA_RFRSH (1<<3)
#define AIC1000AUD_AUD_CODEC_CDIV_VAD_PGA_CHOP(n) (((n)&7)<<4)
#define AIC1000AUD_AUD_CODEC_CGEN_VAD_PGA_CHOP (1<<7)
#define AIC1000AUD_AUD_CODEC_CDIV_MIC_PGA(n) (((n)&7)<<8)
#define AIC1000AUD_AUD_CODEC_CGEN_MIC_PGA (1<<11)
#define AIC1000AUD_AUD_CODEC_CDIV_SDM_DAC_RFRSH(n) (((n)&7)<<12)
#define AIC1000AUD_AUD_CODEC_CGEN_SDM_DAC_RFRSH (1<<15)
#define AIC1000AUD_AUD_CODEC_HIGH_SDM_DAC_RFRSH(n) (((n)&0x7F)<<16)

//mic_dc_ctrl
#define AIC1000AUD_AUD_CODEC_MIC_DC_EST_POS (1<<0)
#define AIC1000AUD_AUD_CODEC_MIC_DC_EST_WIN(n) (((n)&3)<<1)

//mic_idc0
#define AIC1000AUD_AUD_CODEC_MIC_IDC0_VAL(n) (((n)&0xFFFFFF)<<0)
#define AIC1000AUD_AUD_CODEC_MIC_IDC0_VLD (1<<24)

//mic_idc1
#define AIC1000AUD_AUD_CODEC_MIC_IDC1_VAL(n) (((n)&0xFFFFFF)<<0)
#define AIC1000AUD_AUD_CODEC_MIC_IDC1_VLD (1<<24)

//mic_idc2
#define AIC1000AUD_AUD_CODEC_MIC_IDC2_VAL(n) (((n)&0xFFFFFF)<<0)
#define AIC1000AUD_AUD_CODEC_MIC_IDC2_VLD (1<<24)

//vad_idc0
#define AIC1000AUD_AUD_CODEC_VAD_IDC0_VAL(n) (((n)&0x7FFFF)<<0)
#define AIC1000AUD_AUD_CODEC_VAD_IDC0_VLD (1<<24)

//mic_odc0
#define AIC1000AUD_AUD_CODEC_MIC_ODC0_VAL(n) (((n)&0xFFFFFF)<<0)
#define AIC1000AUD_AUD_CODEC_MIC_ODC0_VLD (1<<24)

//mic_odc1
#define AIC1000AUD_AUD_CODEC_MIC_ODC1_VAL(n) (((n)&0xFFFFFF)<<0)
#define AIC1000AUD_AUD_CODEC_MIC_ODC1_VLD (1<<24)

//mic_odc2
#define AIC1000AUD_AUD_CODEC_MIC_ODC2_VAL(n) (((n)&0xFFFFFF)<<0)
#define AIC1000AUD_AUD_CODEC_MIC_ODC2_VLD (1<<24)

//spk_dc0
#define AIC1000AUD_AUD_CODEC_SPK_DC0_VAL(n) (((n)&0xFFFFFF)<<0)
#define AIC1000AUD_AUD_CODEC_SPK_DC0_VLD (1<<24)
#define AIC1000AUD_AUD_CODEC_SPK_ANC0_VLD (1<<25)
#define AIC1000AUD_AUD_CODEC_SPK_DAT0_VLD (1<<26)

//spk_dc1
#define AIC1000AUD_AUD_CODEC_SPK_DC1_VAL(n) (((n)&0xFFFFFF)<<0)
#define AIC1000AUD_AUD_CODEC_SPK_DC1_VLD (1<<24)
#define AIC1000AUD_AUD_CODEC_SPK_ANC1_VLD (1<<25)
#define AIC1000AUD_AUD_CODEC_SPK_DAT1_VLD (1<<26)

//spk_gain
#define AIC1000AUD_AUD_CODEC_SPK_GAIN0(n) (((n)&0x7FFF)<<0)
#define AIC1000AUD_AUD_CODEC_SPK_GAIN1(n) (((n)&0x7FFF)<<16)

//mic_gain
#define AIC1000AUD_AUD_CODEC_MIC_GAIN0(n) (((n)&0xFF)<<0)
#define AIC1000AUD_AUD_CODEC_MIC_GAIN1(n) (((n)&0xFF)<<8)
#define AIC1000AUD_AUD_CODEC_MIC_GAIN2(n) (((n)&0xFF)<<16)

//abb_reserved
#define AIC1000AUD_AUD_CODEC_ABB_RSVD_IN(n) (((n)&0xFFFF)<<0)
#define AIC1000AUD_AUD_CODEC_ABB_RSVD_OUT(n) (((n)&15)<<16)
#define AIC1000AUD_AUD_CODEC_ABB_ISO_EN (1<<20)

//abb_ivref
#define AIC1000AUD_AUD_CODEC_ABB_PU_IVREF_BG (1<<0)
#define AIC1000AUD_AUD_CODEC_ABB_PU_IVREF_IBIAS (1<<1)
#define AIC1000AUD_AUD_CODEC_ABB_PU_IVREF_VREFB (1<<2)
#define AIC1000AUD_AUD_CODEC_ABB_PU_IVREF_IREFLN (1<<3)
#define AIC1000AUD_AUD_CODEC_ABB_PU_IVREF_VREFLN (1<<4)
#define AIC1000AUD_AUD_CODEC_ABB_PU_IVREF_VREF_LP (1<<5)
#define AIC1000AUD_AUD_CODEC_ABB_PU_IVREF_VCOM_LP (1<<6)
#define AIC1000AUD_AUD_CODEC_ABB_IVREF_VCOM_SEL(n) (((n)&15)<<7)
#define AIC1000AUD_AUD_CODEC_ABB_IVREF_VCOM_MODE(n) (((n)&7)<<11)
#define AIC1000AUD_AUD_CODEC_ABB_IVREF_VREFLN_VBIT(n) (((n)&15)<<14)
#define AIC1000AUD_AUD_CODEC_ABB_IVREF_VREFLN_IBIT(n) (((n)&15)<<18)
#define AIC1000AUD_AUD_CODEC_ABB_IVREF_VCOM_BIT (1<<22)
#define AIC1000AUD_AUD_CODEC_ABB_IVREF_IBIAS_MODE (1<<23)
#define AIC1000AUD_AUD_CODEC_ABB_IVREF_IBIAS_BIT(n) (((n)&3)<<24)
#define AIC1000AUD_AUD_CODEC_ABB_IVREF_VREFLP_IBIT (1<<26)

//abb_micbias
#define AIC1000AUD_AUD_CODEC_ABB_VAD_MICBIAS_BYP (1<<0)
#define AIC1000AUD_AUD_CODEC_ABB_VAD_PGA_INBIAS_N(n) (((n)&15)<<4)
#define AIC1000AUD_AUD_CODEC_ABB_VAD_PGA_INBIAS_P(n) (((n)&15)<<8)
#define AIC1000AUD_AUD_CODEC_ABB_PU_MICBIAS (1<<12)
#define AIC1000AUD_AUD_CODEC_ABB_MICBIAS_VBIT(n) (((n)&3)<<13)
#define AIC1000AUD_AUD_CODEC_ABB_MICBIAS_LPF_MODE (1<<15)
#define AIC1000AUD_AUD_CODEC_ABB_MICBIAS_LP_MODE (1<<16)
#define AIC1000AUD_AUD_CODEC_ABB_MICBIAS_HIZ_MODE (1<<17)
#define AIC1000AUD_AUD_CODEC_ABB_MICBIAS_CC_BIT(n) (((n)&3)<<18)
#define AIC1000AUD_AUD_CODEC_ABB_MICBIAS_CAL_BIT(n) (((n)&7)<<20)
#define AIC1000AUD_AUD_CODEC_ABB_PU_MUX2MSADC (1<<24)
#define AIC1000AUD_AUD_CODEC_ABB_MUX2MSADC_BIT(n) (((n)&15)<<28)

//abb_vad
#define AIC1000AUD_AUD_CODEC_ABB_PU_VAD_PGA (1<<0)
#define AIC1000AUD_AUD_CODEC_ABB_PU_VAD_ADC (1<<1)
#define AIC1000AUD_AUD_CODEC_ABB_VAD_ADC_CLK_EDGE_SEL (1<<2)
#define AIC1000AUD_AUD_CODEC_ABB_VAD_ADC_DLY_BIT(n) (((n)&0x3F)<<3)
#define AIC1000AUD_AUD_CODEC_ABB_VAD_ADC_CMP_IBIT(n) (((n)&3)<<9)
#define AIC1000AUD_AUD_CODEC_ABB_VAD_ADC_VREF_SEL(n) (((n)&7)<<11)
#define AIC1000AUD_AUD_CODEC_ABB_VAD_ADC_INSEL(n) (((n)&3)<<14)
#define AIC1000AUD_AUD_CODEC_ABB_VAD_PGA_RSTN (1<<16)
#define AIC1000AUD_AUD_CODEC_ABB_VAD_PGA_TEST_MODE (1<<17)
#define AIC1000AUD_AUD_CODEC_ABB_VAD_PGA_CHOP_EN (1<<18)
#define AIC1000AUD_AUD_CODEC_ABB_VAD_PGA_RFRSH_EN (1<<19)
#define AIC1000AUD_AUD_CODEC_ABB_VAD_PGA_RFRSH_BIT (1<<20)
#define AIC1000AUD_AUD_CODEC_ABB_VAD_PGA_INSEL(n) (((n)&15)<<21)

//abb_micpga_1
#define AIC1000AUD_AUD_CODEC_ABB_MICPGA_1_RSTN (1<<0)
#define AIC1000AUD_AUD_CODEC_ABB_MICPGA_1_GAIN(n) (((n)&3)<<1)
#define AIC1000AUD_AUD_CODEC_ABB_MICPGA_1_MICDAC_MODE (1<<3)
#define AIC1000AUD_AUD_CODEC_ABB_MICPGA_1_ICL_MODE (1<<4)
#define AIC1000AUD_AUD_CODEC_ABB_MICPGA_1_ICL_HPF_BIT (1<<5)
#define AIC1000AUD_AUD_CODEC_ABB_MICPGA_1_INBIAS_N(n) (((n)&15)<<8)
#define AIC1000AUD_AUD_CODEC_ABB_MICPGA_1_INBIAS_P(n) (((n)&15)<<12)
#define AIC1000AUD_AUD_CODEC_ABB_MICPGA_1_IBIT(n) (((n)&3)<<16)
#define AIC1000AUD_AUD_CODEC_ABB_MICPGA_1_INSEL(n) (((n)&0x3F)<<18)
#define AIC1000AUD_AUD_CODEC_ABB_PU_MICPGA_1 (1<<24)
#define AIC1000AUD_AUD_CODEC_ABB_PU_MICPGA_2 (1<<25)
#define AIC1000AUD_AUD_CODEC_ABB_PU_MICPGA_3 (1<<26)

//abb_micpga_2
#define AIC1000AUD_AUD_CODEC_ABB_MICPGA_2_RSTN (1<<0)
#define AIC1000AUD_AUD_CODEC_ABB_MICPGA_2_GAIN(n) (((n)&3)<<1)
#define AIC1000AUD_AUD_CODEC_ABB_MICPGA_2_MICDAC_MODE (1<<3)
#define AIC1000AUD_AUD_CODEC_ABB_MICPGA_2_ICL_MODE (1<<4)
#define AIC1000AUD_AUD_CODEC_ABB_MICPGA_2_ICL_HPF_BIT (1<<5)
#define AIC1000AUD_AUD_CODEC_ABB_MICPGA_2_INBIAS_N(n) (((n)&15)<<8)
#define AIC1000AUD_AUD_CODEC_ABB_MICPGA_2_INBIAS_P(n) (((n)&15)<<12)
#define AIC1000AUD_AUD_CODEC_ABB_MICPGA_2_IBIT(n) (((n)&3)<<16)
#define AIC1000AUD_AUD_CODEC_ABB_MICPGA_2_INSEL(n) (((n)&0x3F)<<18)

//abb_micpga_3
#define AIC1000AUD_AUD_CODEC_ABB_MICPGA_3_RSTN (1<<0)
#define AIC1000AUD_AUD_CODEC_ABB_MICPGA_3_GAIN(n) (((n)&3)<<1)
#define AIC1000AUD_AUD_CODEC_ABB_MICPGA_3_MICDAC_MODE (1<<3)
#define AIC1000AUD_AUD_CODEC_ABB_MICPGA_3_ICL_MODE (1<<4)
#define AIC1000AUD_AUD_CODEC_ABB_MICPGA_3_ICL_HPF_BIT (1<<5)
#define AIC1000AUD_AUD_CODEC_ABB_MICPGA_3_INBIAS_N(n) (((n)&15)<<8)
#define AIC1000AUD_AUD_CODEC_ABB_MICPGA_3_INBIAS_P(n) (((n)&15)<<12)
#define AIC1000AUD_AUD_CODEC_ABB_MICPGA_3_IBIT(n) (((n)&3)<<16)
#define AIC1000AUD_AUD_CODEC_ABB_MICPGA_3_INSEL(n) (((n)&0x3F)<<18)

//abb_sdm_adc_cal
#define AIC1000AUD_AUD_CODEC_ABB_SDM_ADC_RC_BIT(n) (((n)&7)<<0)
#define AIC1000AUD_AUD_CODEC_ABB_SDM_ADC_VCAL_EN (1<<3)
#define AIC1000AUD_AUD_CODEC_ABB_SDM_ADC_VCAL_BIT(n) (((n)&15)<<4)
#define AIC1000AUD_AUD_CODEC_ABB_SDM_ADC_AUXIN_EN(n) (((n)&7)<<8)
#define AIC1000AUD_AUD_CODEC_ABB_SDM_ADC_AUXIN_SEL(n) (((n)&3)<<11)
#define AIC1000AUD_AUD_CODEC_ABB_SDM_ADC_TEST_EN (1<<13)
#define AIC1000AUD_AUD_CODEC_ABB_SDM_ADC_TEST_BIT(n) (((n)&7)<<14)

//abb_sdm_adc0
#define AIC1000AUD_AUD_CODEC_ABB_PU_SDM_ADC_3 (1<<0)
#define AIC1000AUD_AUD_CODEC_ABB_PU_SDM_ADC_2 (1<<1)
#define AIC1000AUD_AUD_CODEC_ABB_PU_SDM_ADC_1 (1<<2)
#define AIC1000AUD_AUD_CODEC_ABB_SDM_ADC_DIG_RSTN (1<<3)
#define AIC1000AUD_AUD_CODEC_ABB_SDM_ADC_ANA_RSTN (1<<4)
#define AIC1000AUD_AUD_CODEC_ABB_SDM_ADC_3_GAIN_BIT(n) (((n)&7)<<5)
#define AIC1000AUD_AUD_CODEC_ABB_SDM_ADC_2_GAIN_BIT(n) (((n)&7)<<8)
#define AIC1000AUD_AUD_CODEC_ABB_SDM_ADC_1_GAIN_BIT(n) (((n)&7)<<11)
#define AIC1000AUD_AUD_CODEC_ABB_SDM_ADC_VREG_BYPASS (1<<14)
#define AIC1000AUD_AUD_CODEC_ABB_SDM_ADC_VPS_DIS (1<<15)
#define AIC1000AUD_AUD_CODEC_ABB_SDM_ADC_VPS_BIT(n) (((n)&3)<<16)
#define AIC1000AUD_AUD_CODEC_ABB_SDM_ADC_VLO_BIT(n) (((n)&7)<<18)
#define AIC1000AUD_AUD_CODEC_ABB_SDM_ADC_VHI_BIT(n) (((n)&7)<<21)
#define AIC1000AUD_AUD_CODEC_ABB_SDM_ADC_DWA_EN (1<<24)
#define AIC1000AUD_AUD_CODEC_ABB_SDM_ADC_DLY_BIT(n) (((n)&3)<<25)
#define AIC1000AUD_AUD_CODEC_ABB_SDM_ADC_BIAS_IBIT(n) (((n)&3)<<27)
#define AIC1000AUD_AUD_CODEC_ABB_SDM_ADC_OP_IBIT(n) (((n)&3)<<29)
#define AIC1000AUD_AUD_CODEC_ABB_SDM_ADC_DITHER_EN (1<<31)

//abb_sdm_dac1
#define AIC1000AUD_AUD_CODEC_ABB_PU_SDM_DAC_L (1<<0)
#define AIC1000AUD_AUD_CODEC_ABB_PU_SDM_DAC_R (1<<1)
#define AIC1000AUD_AUD_CODEC_ABB_PU_SDM_DAC_NR (1<<2)
#define AIC1000AUD_AUD_CODEC_ABB_SDM_DAC_DIG_RSTN (1<<3)
#define AIC1000AUD_AUD_CODEC_ABB_SDM_DAC_ANA_RSTN (1<<4)
#define AIC1000AUD_AUD_CODEC_ABB_SDM_DAC_SE_MODE_DR (1<<5)
#define AIC1000AUD_AUD_CODEC_ABB_SDM_DAC_R_SE_MODE (1<<6)
#define AIC1000AUD_AUD_CODEC_ABB_SDM_DAC_L_SE_MODE (1<<7)
#define AIC1000AUD_AUD_CODEC_ABB_SDM_DAC_GAIN_BIT1(n) (((n)&15)<<8)
#define AIC1000AUD_AUD_CODEC_ABB_SDM_DAC_GAIN_BIT2(n) (((n)&15)<<12)
#define AIC1000AUD_AUD_CODEC_ABB_SDM_DAC_CLK_EDGE_SEL (1<<16)
#define AIC1000AUD_AUD_CODEC_ABB_SDM_DAC_VREG_BYPASS (1<<17)
#define AIC1000AUD_AUD_CODEC_ABB_SDM_DAC_VLO_BIT(n) (((n)&7)<<18)
#define AIC1000AUD_AUD_CODEC_ABB_SDM_DAC_VHI_BIT(n) (((n)&7)<<21)
#define AIC1000AUD_AUD_CODEC_ABB_SDM_DAC_VINT_BIT(n) (((n)&3)<<24)
#define AIC1000AUD_AUD_CODEC_ABB_SDM_DAC_IBIAS_BIT(n) (((n)&3)<<26)
#define AIC1000AUD_AUD_CODEC_ABB_SDM_DAC_VCAL_EN (1<<28)
#define AIC1000AUD_AUD_CODEC_ABB_SDM_DAC_RFRSH_EN (1<<29)
#define AIC1000AUD_AUD_CODEC_ABB_SDM_DAC_RDAC_MODE (1<<30)

//abb_hp_os
#define AIC1000AUD_AUD_CODEC_ABB_HP_R_OS_CAL_MODE (1<<0)
#define AIC1000AUD_AUD_CODEC_ABB_HP_R_OS_CAL_DOUT (1<<1)
#define AIC1000AUD_AUD_CODEC_ABB_HP_R_OS_CAL_EN (1<<2)
#define AIC1000AUD_AUD_CODEC_ABB_HP_R_OSMN_BIT(n) (((n)&7)<<3)
#define AIC1000AUD_AUD_CODEC_ABB_HP_R_OS_BIT(n) (((n)&0x3F)<<6)
#define AIC1000AUD_AUD_CODEC_ABB_HP_L_OS_CAL_MODE (1<<12)
#define AIC1000AUD_AUD_CODEC_ABB_HP_L_OS_CAL_DOUT (1<<13)
#define AIC1000AUD_AUD_CODEC_ABB_HP_L_OS_CAL_EN (1<<14)
#define AIC1000AUD_AUD_CODEC_ABB_HP_L_OSMN_BIT(n) (((n)&7)<<15)
#define AIC1000AUD_AUD_CODEC_ABB_HP_L_OS_BIT(n) (((n)&0x3F)<<18)
#define AIC1000AUD_AUD_CODEC_ABB_HP_AUX_BIAS_IBIT(n) (((n)&0x3F)<<24)
#define AIC1000AUD_AUD_CODEC_ABB_HP_DAC_CLK_EDGE_SEL (1<<30)
#define AIC1000AUD_AUD_CODEC_ABB_HP_AUX_CLK_EDGE_SEL (1<<31)

//abb_hp_l
#define AIC1000AUD_AUD_CODEC_ABB_PU_HP_L_BIAS (1<<0)
#define AIC1000AUD_AUD_CODEC_ABB_PU_HP_L_MPATH (1<<1)
#define AIC1000AUD_AUD_CODEC_ABB_HP_L_VREFC_EN (1<<2)
#define AIC1000AUD_AUD_CODEC_ABB_HP_L_SE_MODE (1<<3)
#define AIC1000AUD_AUD_CODEC_ABB_HP_L_DIFF_MODE (1<<4)
#define AIC1000AUD_AUD_CODEC_ABB_HP_L_MUTE (1<<5)
#define AIC1000AUD_AUD_CODEC_ABB_HP_L_GAIN_BIT(n) (((n)&7)<<6)
#define AIC1000AUD_AUD_CODEC_ABB_HP_L_IBIT(n) (((n)&31)<<9)
#define AIC1000AUD_AUD_CODEC_ABB_HP_L_AUXIN_SEL (1<<14)
#define AIC1000AUD_AUD_CODEC_ABB_HP_L_DACIN_SEL (1<<15)
#define AIC1000AUD_AUD_CODEC_ABB_HP_L_TEST_MODE (1<<16)
#define AIC1000AUD_AUD_CODEC_ABB_HP_L_DAC_EN (1<<17)
#define AIC1000AUD_AUD_CODEC_ABB_HP_L_DAC_MODE (1<<18)
#define AIC1000AUD_AUD_CODEC_ABB_HP_L_DAC_BYP (1<<19)
#define AIC1000AUD_AUD_CODEC_ABB_HP_L_SOFT_START_EN (1<<20)
#define AIC1000AUD_AUD_CODEC_ABB_HP_L_DISCHG_RES_EN (1<<21)
#define AIC1000AUD_AUD_CODEC_ABB_HP_L_CHG_RES_EN (1<<22)
#define AIC1000AUD_AUD_CODEC_ABB_HP_L_AUXPATH_EN (1<<23)
#define AIC1000AUD_AUD_CODEC_ABB_PU_HP_L_AUX (1<<24)
#define AIC1000AUD_AUD_CODEC_ABB_HP_L_AUX_CHG_MODE (1<<25)
#define AIC1000AUD_AUD_CODEC_ABB_HP_L_AUX_DISCHG_EN (1<<26)
#define AIC1000AUD_AUD_CODEC_ABB_HP_L_AUX_CHG_EN (1<<27)
#define AIC1000AUD_AUD_CODEC_ABB_HP_L_AUX_RSTN (1<<28)
#define AIC1000AUD_AUD_CODEC_ABB_HP_L_AUX_IBIT(n) (((n)&3)<<29)

//abb_hp_r
#define AIC1000AUD_AUD_CODEC_ABB_PU_HP_R_BIAS (1<<0)
#define AIC1000AUD_AUD_CODEC_ABB_PU_HP_R_MPATH (1<<1)
#define AIC1000AUD_AUD_CODEC_ABB_HP_R_VREFC_EN (1<<2)
#define AIC1000AUD_AUD_CODEC_ABB_HP_R_SE_MODE (1<<3)
#define AIC1000AUD_AUD_CODEC_ABB_HP_R_DIFF_MODE (1<<4)
#define AIC1000AUD_AUD_CODEC_ABB_HP_R_MUTE (1<<5)
#define AIC1000AUD_AUD_CODEC_ABB_HP_R_GAIN_BIT(n) (((n)&7)<<6)
#define AIC1000AUD_AUD_CODEC_ABB_HP_R_IBIT(n) (((n)&31)<<9)
#define AIC1000AUD_AUD_CODEC_ABB_HP_R_AUXIN_SEL (1<<14)
#define AIC1000AUD_AUD_CODEC_ABB_HP_R_DACIN_SEL (1<<15)
#define AIC1000AUD_AUD_CODEC_ABB_HP_R_TEST_MODE (1<<16)
#define AIC1000AUD_AUD_CODEC_ABB_HP_R_DAC_EN (1<<17)
#define AIC1000AUD_AUD_CODEC_ABB_HP_R_DAC_MODE (1<<18)
#define AIC1000AUD_AUD_CODEC_ABB_HP_R_DAC_BYP (1<<19)
#define AIC1000AUD_AUD_CODEC_ABB_HP_R_SOFT_START_EN (1<<20)
#define AIC1000AUD_AUD_CODEC_ABB_HP_R_DISCHG_RES_EN (1<<21)
#define AIC1000AUD_AUD_CODEC_ABB_HP_R_CHG_RES_EN (1<<22)
#define AIC1000AUD_AUD_CODEC_ABB_HP_R_AUXPATH_EN (1<<23)
#define AIC1000AUD_AUD_CODEC_ABB_PU_HP_R_AUX (1<<24)
#define AIC1000AUD_AUD_CODEC_ABB_HP_R_AUX_CHG_MODE (1<<25)
#define AIC1000AUD_AUD_CODEC_ABB_HP_R_AUX_DISCHG_EN (1<<26)
#define AIC1000AUD_AUD_CODEC_ABB_HP_R_AUX_CHG_EN (1<<27)
#define AIC1000AUD_AUD_CODEC_ABB_HP_R_AUX_RSTN (1<<28)
#define AIC1000AUD_AUD_CODEC_ABB_HP_R_AUX_IBIT(n) (((n)&3)<<29)

#endif
