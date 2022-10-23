#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include "audio_types.h"
#include "codec_aic1000.h"
#include "pmic_api.h"
#include "aic1000Aud_iomux.h"
#include "aic1000Aud_aud_codec.h"
#include "aic1000Aud_aud_ctrl_reg.h"
#include "aic1000Aud_rtc_core.h"
#include "aic1000Aud_wdg.h"
#include "aud_proc.h"
#include "reg_iomux.h"
#include "reg_sysctrl.h"
#include "dbg_assert.h"
#include "dbg.h"
#include "ll.h"

/*
 *++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *+                                                      Fs=48K          +
 *+ TX01--->SRC--->MUX--->VOL_CTRL--->MIX--->EQ--->DRC--->I2S0--->DAC0+1 +
 *+                 ^                                              48K   +
 *+ TX23------------|                                                    +
 *++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *+                                                      Fs=48K          +
 *+                     RX01<---SRC<---EQ<---VOL_CTRL<---I2S0<---ADC2    +
 *+                                                            8/16/48K  +
 *++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *+                                                    Fs=8/16/48K       +
 *+                            RX23<---EQ<---VOL_CTRL<---I2S1<---ADC0+1  +
 *+                                                             8/16/48K +
 *++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *+ for ADC2 to RX01, SRC can be bypassed                                +
 *++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 */

#define AIC1000AUD_FPGA            0
#define AIC1000AUD_LOOPBACK        0
#define AIC1000AUD_CHECK_STATUS    0
#define AIC1000AUD_DBG             0

#define I2S_CDIV        14
#define I2S_HCYC_8K     149
#define I2S_HCYC_16K    74
#define I2S_HCYC_48K    24

#define AIC1000_DBG_COMMON           (0x01UL << 0)
#define AIC1000_DBG_DAC_COMMON       (0x01UL << 1)
#define AIC1000_DBG_DAC_CFG          (0x01UL << 2)
#define AIC1000_DBG_ADC_COMMON       (0x01UL << 3)
#define AIC1000_DBG_ADC_CFG          (0x01UL << 4)

static uint8_t dac_ch_en = 0;
static uint8_t adc_ch_en = 0;
static uint8_t adc_ch_d36_en = 0;
static uint8_t adc_ch_d36_d3 = 0;

static uint8_t dac_ch_ana_pu = 0;
static uint8_t adc_ch_ana_pu = 0;

static bool dac_mem_cleared = false;
static bool adc_mem_cleared = false;

static uint8_t mic_matrix_type = 0;

static const uint8_t mic_matrix_tbl[6][3] = {
    {0, 1, 2},
    {0, 2, 1},
    {1, 0, 2},
    {1, 2, 0},
    {2, 0, 1},
    {2, 1, 0}
};

static uint16_t dac_dig_gain_base = 0x347;
static uint8_t adc_dig_gain_base = 0x20;

static uint16_t aic1000_dbg_mask = 0;

void aic1000_dbg_mask_set(uint16_t mask)
{
    aic1000_dbg_mask = mask;
}

uint16_t aic1000_dbg_mask_get(void)
{
    return aic1000_dbg_mask;
}

void aic1000_iomux_config(void)
{
    //I2S0 LRCK
    iomux_agpio_config_sel_setf(7,5);
    //I2S0 BCK
    iomux_agpio_config_sel_setf(6,5);
    //I2S0 DIN
    iomux_agpio_config_sel_setf(1,5);
    //I2S0 DOUT
    iomux_agpio_config_sel_setf(5,5);

    //I2S1 LRCK
    iomux_agpio_config_sel_setf(4,5);
    //I2S1 BCK
    iomux_agpio_config_sel_setf(3,5);
    //I2S1 DIN
    iomux_agpio_config_sel_setf(2,5);
    //I2S1 DOUT
    iomux_agpio_config_sel_setf(0,5);

    // set spk/mic IO to Hi-Z
    PMIC_MEM_WRITE((unsigned int)&(aic1000audIomux->GPCFG[15]), 0x00010000);
    PMIC_MEM_WRITE((unsigned int)&(aic1000audIomux->GPCFG[14]), 0x00010000);
    PMIC_MEM_WRITE((unsigned int)&(aic1000audIomux->GPCFG[13]), 0x00010000);
    PMIC_MEM_WRITE((unsigned int)&(aic1000audIomux->GPCFG[12]), 0x00010000);
    PMIC_MEM_WRITE((unsigned int)&(aic1000audIomux->GPCFG[11]), 0x00010000);
    PMIC_MEM_WRITE((unsigned int)&(aic1000audIomux->GPCFG[10]), 0x00010000);
    PMIC_MEM_WRITE((unsigned int)&(aic1000audIomux->GPCFG[9]), 0x00010000);
    PMIC_MEM_WRITE((unsigned int)&(aic1000audIomux->GPCFG[8]), 0x00010000);
    PMIC_MEM_WRITE((unsigned int)&(aic1000audIomux->GPCFG[7]), 0x00010000);
    PMIC_MEM_WRITE((unsigned int)&(aic1000audIomux->GPCFG[6]), 0x00010000);
}

void aic1000_clk_cfg(void)
{
#if (AIC1000AUD_FPGA)
    // tports 26M
    AIC_CPUSYSCTRL->TPSEL = 0x1800;
    iomux_gpio_config_sel_setf(2, 5);

    // tports sel
    PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->intf_ctrl),
        (AIC1000AUD_AUD_CODEC_TPORTS_SEL(0x01)),
        (AIC1000AUD_AUD_CODEC_TPORTS_SEL(0x3F)));

    //dbg mux
    PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audRtcCore->rtc_rg_int_irq),
        (AIC1000AUD_RTC_CORE_RTC_RG_DBG_MUX(0x06)),
        (AIC1000AUD_RTC_CORE_RTC_RG_DBG_MUX(0x1F)));
#endif

    //audio pll cfg0
    PMIC_MEM_WRITE((unsigned int)&(aic1000audAudCtrlReg->aud_pll_cfg0),
        (AIC1000AUD_AUD_CTRL_REG_CFG_AUPLL_SDM_CLK_SEL    |
        AIC1000AUD_AUD_CTRL_REG_CFG_AUPLL_REG_VBIT(0xc)   |
        AIC1000AUD_AUD_CTRL_REG_CFG_AUPLL_CP_IBIT(0x3)    |
        AIC1000AUD_AUD_CTRL_REG_CFG_AUPLL_PU_BIT(0x3)     |
        AIC1000AUD_AUD_CTRL_REG_CFG_AUPLL_DIV_SEL(0x0)));

    //audio pll cfg1
    PMIC_MEM_WRITE((unsigned int)&(aic1000audAudCtrlReg->aud_pll_cfg1),
        (AIC1000AUD_AUD_CTRL_REG_CFG_AUDPLL_SDM_FREQ_CFG(0x2C4EC4F)));
    PMIC_MEM_WRITE((unsigned int)&(aic1000audAudCtrlReg->aud_pll_cfg1),
        (AIC1000AUD_AUD_CTRL_REG_CFG_AUDPLL_SDM_FREQ_CFG(0x2C4EC4F) | AIC1000AUD_AUD_CTRL_REG_CFG_AUDPLL_SDM_FREQ_TOGGLE));

    //pu audio pll
    PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCtrlReg->aud_pll_cfg0),
        (AIC1000AUD_AUD_CTRL_REG_CFG_PU_AUPLL),
        (AIC1000AUD_AUD_CTRL_REG_CFG_PU_AUPLL));

    //delay wait pll fre ok
    //unsigned int pll_lock_ok =0;
    //while(pll_lock_ok==0)
    //{
    //    pll_lock_ok = ((PMIC_MEM_READ((unsigned int)&(aic1000audAudCtrlReg->aud_pll_cfg0))) & AIC1000AUD_AUD_CTRL_REG_CFG_AUPLL_LOCK) == AIC1000AUD_AUD_CTRL_REG_CFG_AUPLL_LOCK;
    //}

    //audio pll clock gate
    PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCtrlReg->aud_pll_cfg0),
        (AIC1000AUD_AUD_CTRL_REG_CFG_AUPLL_CLK96M_EN |
        AIC1000AUD_AUD_CTRL_REG_CFG_AUPLL_CLK12M_EN  |
        AIC1000AUD_AUD_CTRL_REG_CFG_AUPLL_CLK24M_EN),
        (AIC1000AUD_AUD_CTRL_REG_CFG_AUPLL_CLK96M_EN |
        AIC1000AUD_AUD_CTRL_REG_CFG_AUPLL_CLK12M_EN  |
        AIC1000AUD_AUD_CTRL_REG_CFG_AUPLL_CLK24M_EN));

    //audio aud_clk_ctrl0
    PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCtrlReg->aud_clk_ctrl0),
        (AIC1000AUD_AUD_CTRL_REG_I_REG_CLK_AUPLL2DIG_12M_GATE_EN |
        AIC1000AUD_AUD_CTRL_REG_I_REG_CLK_AUPLL2DIG_24M_GATE_EN  |
        AIC1000AUD_AUD_CTRL_REG_I_REG_CLK_AUPLL2DIG_96M_GATE_EN),
        (AIC1000AUD_AUD_CTRL_REG_I_REG_CLK_AUPLL2DIG_12M_GATE_EN |
        AIC1000AUD_AUD_CTRL_REG_I_REG_CLK_AUPLL2DIG_24M_GATE_EN  |
        AIC1000AUD_AUD_CTRL_REG_I_REG_CLK_AUPLL2DIG_96M_GATE_EN));

    //i2s clk, bck = 72M / (2 * (14 + 1)) = 2.4M, lrck0 = 2.4M / (2 * (24 + 1)) = 48K, lrck1 = 2.4M / (2 * (74)) = 16K
    PMIC_MEM_WRITE((unsigned int)&(aic1000audAudCodec->iis_ctrl0),
        (AIC1000AUD_AUD_CODEC_CLKD_FSN(5)            |
        AIC1000AUD_AUD_CODEC_CLKD_FSN_LD             |
        AIC1000AUD_AUD_CODEC_CDIV_IIS(I2S_CDIV)      |
        AIC1000AUD_AUD_CODEC_HCYC_IIS0(I2S_HCYC_48K) |
        AIC1000AUD_AUD_CODEC_HCYC_IIS1(I2S_HCYC_16K)));

    PMIC_MEM_WRITE((unsigned int)&(aic1000audWdg->WDG_CTRL), 0x00000000);
}

void aic1000_ana_cfg(void)
{
    PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->ana_clk1),
        (AIC1000AUD_AUD_CODEC_HIGH_SDM_DAC_RFRSH(0x32) |
        0                                              |
        AIC1000AUD_AUD_CODEC_CDIV_SDM_DAC_RFRSH(4)     |
        0                                              |
        AIC1000AUD_AUD_CODEC_CDIV_MIC_PGA(1)           |
        0                                              |
        AIC1000AUD_AUD_CODEC_CDIV_VAD_PGA_CHOP(3)      |
        0                                              |
        AIC1000AUD_AUD_CODEC_CDIV_VAD_PGA_RFRSH(3)),
        (AIC1000AUD_AUD_CODEC_HIGH_SDM_DAC_RFRSH(0x7F) |
        AIC1000AUD_AUD_CODEC_CGEN_SDM_DAC_RFRSH        |
        AIC1000AUD_AUD_CODEC_CDIV_SDM_DAC_RFRSH(0x7)   |
        AIC1000AUD_AUD_CODEC_CGEN_MIC_PGA              |
        AIC1000AUD_AUD_CODEC_CDIV_MIC_PGA(0x7)         |
        AIC1000AUD_AUD_CODEC_CGEN_VAD_PGA_CHOP         |
        AIC1000AUD_AUD_CODEC_CDIV_VAD_PGA_CHOP(0x7)    |
        AIC1000AUD_AUD_CODEC_CGEN_VAD_PGA_RFRSH        |
        AIC1000AUD_AUD_CODEC_CDIV_VAD_PGA_RFRSH(0x7)));

    PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->abb_ivref),
        (0                                               |
        AIC1000AUD_AUD_CODEC_ABB_IVREF_IBIAS_BIT(2)      |
        0                                                |
        0                                                |
        AIC1000AUD_AUD_CODEC_ABB_IVREF_VREFLN_IBIT(8)    |
        AIC1000AUD_AUD_CODEC_ABB_IVREF_VREFLN_VBIT(8)    |
        AIC1000AUD_AUD_CODEC_ABB_IVREF_VCOM_MODE(2)      |
        AIC1000AUD_AUD_CODEC_ABB_IVREF_VCOM_SEL(9)       |
        0                                                |
        0                                                |
        AIC1000AUD_AUD_CODEC_ABB_PU_IVREF_VREFLN         |
        AIC1000AUD_AUD_CODEC_ABB_PU_IVREF_IREFLN         |
        AIC1000AUD_AUD_CODEC_ABB_PU_IVREF_VREFB          |
        AIC1000AUD_AUD_CODEC_ABB_PU_IVREF_IBIAS          |
        AIC1000AUD_AUD_CODEC_ABB_PU_IVREF_BG),
        (AIC1000AUD_AUD_CODEC_ABB_IVREF_VREFLP_IBIT      |
        AIC1000AUD_AUD_CODEC_ABB_IVREF_IBIAS_BIT(0x3)    |
        AIC1000AUD_AUD_CODEC_ABB_IVREF_IBIAS_MODE        |
        AIC1000AUD_AUD_CODEC_ABB_IVREF_VCOM_BIT          |
        AIC1000AUD_AUD_CODEC_ABB_IVREF_VREFLN_IBIT(0xF)  |
        AIC1000AUD_AUD_CODEC_ABB_IVREF_VREFLN_VBIT(0xF)  |
        AIC1000AUD_AUD_CODEC_ABB_IVREF_VCOM_MODE(0x7)    |
        AIC1000AUD_AUD_CODEC_ABB_IVREF_VCOM_SEL(0xF)     |
        AIC1000AUD_AUD_CODEC_ABB_PU_IVREF_VCOM_LP        |
        AIC1000AUD_AUD_CODEC_ABB_PU_IVREF_VREF_LP        |
        AIC1000AUD_AUD_CODEC_ABB_PU_IVREF_VREFLN         |
        AIC1000AUD_AUD_CODEC_ABB_PU_IVREF_IREFLN         |
        AIC1000AUD_AUD_CODEC_ABB_PU_IVREF_VREFB          |
        AIC1000AUD_AUD_CODEC_ABB_PU_IVREF_IBIAS          |
        AIC1000AUD_AUD_CODEC_ABB_PU_IVREF_BG));

    PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->abb_micpga_1),
        (AIC1000AUD_AUD_CODEC_ABB_MICPGA_1_INSEL(0x12)  |
        AIC1000AUD_AUD_CODEC_ABB_MICPGA_1_IBIT(1)       |
        AIC1000AUD_AUD_CODEC_ABB_MICPGA_1_INBIAS_P(0)   |
        AIC1000AUD_AUD_CODEC_ABB_MICPGA_1_INBIAS_N(0)   |
        AIC1000AUD_AUD_CODEC_ABB_MICPGA_1_ICL_HPF_BIT   |
        0                                               |
        AIC1000AUD_AUD_CODEC_ABB_MICPGA_1_GAIN(2)       |
        AIC1000AUD_AUD_CODEC_ABB_MICPGA_1_RSTN),
        (AIC1000AUD_AUD_CODEC_ABB_MICPGA_1_INSEL(0x3F)  |
        AIC1000AUD_AUD_CODEC_ABB_MICPGA_1_IBIT(0x3)     |
        AIC1000AUD_AUD_CODEC_ABB_MICPGA_1_INBIAS_P(0xF) |
        AIC1000AUD_AUD_CODEC_ABB_MICPGA_1_INBIAS_N(0xF) |
        AIC1000AUD_AUD_CODEC_ABB_MICPGA_1_ICL_HPF_BIT   |
        AIC1000AUD_AUD_CODEC_ABB_MICPGA_1_ICL_MODE      |
        AIC1000AUD_AUD_CODEC_ABB_MICPGA_1_GAIN(0x3)     |
        AIC1000AUD_AUD_CODEC_ABB_MICPGA_1_RSTN));

    PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->abb_micpga_2),
        (AIC1000AUD_AUD_CODEC_ABB_MICPGA_2_INSEL(0x12)  |
        AIC1000AUD_AUD_CODEC_ABB_MICPGA_2_IBIT(1)       |
        AIC1000AUD_AUD_CODEC_ABB_MICPGA_2_INBIAS_P(0)   |
        AIC1000AUD_AUD_CODEC_ABB_MICPGA_2_INBIAS_N(0)   |
        AIC1000AUD_AUD_CODEC_ABB_MICPGA_2_ICL_HPF_BIT   |
        0                                               |
        AIC1000AUD_AUD_CODEC_ABB_MICPGA_2_GAIN(2)       |
        AIC1000AUD_AUD_CODEC_ABB_MICPGA_2_RSTN),
        (AIC1000AUD_AUD_CODEC_ABB_MICPGA_2_INSEL(0x3F)  |
        AIC1000AUD_AUD_CODEC_ABB_MICPGA_2_IBIT(0x3)     |
        AIC1000AUD_AUD_CODEC_ABB_MICPGA_2_INBIAS_P(0xF) |
        AIC1000AUD_AUD_CODEC_ABB_MICPGA_2_INBIAS_N(0xF) |
        AIC1000AUD_AUD_CODEC_ABB_MICPGA_2_ICL_HPF_BIT   |
        AIC1000AUD_AUD_CODEC_ABB_MICPGA_2_ICL_MODE      |
        AIC1000AUD_AUD_CODEC_ABB_MICPGA_2_GAIN(0x3)     |
        AIC1000AUD_AUD_CODEC_ABB_MICPGA_2_RSTN));

    PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->abb_micpga_3),
        (AIC1000AUD_AUD_CODEC_ABB_MICPGA_3_INSEL(0x12)  |
        AIC1000AUD_AUD_CODEC_ABB_MICPGA_3_IBIT(1)       |
        AIC1000AUD_AUD_CODEC_ABB_MICPGA_3_INBIAS_P(0)   |
        AIC1000AUD_AUD_CODEC_ABB_MICPGA_3_INBIAS_N(0)   |
        AIC1000AUD_AUD_CODEC_ABB_MICPGA_3_ICL_HPF_BIT   |
        0                                               |
        AIC1000AUD_AUD_CODEC_ABB_MICPGA_3_GAIN(2)       |
        AIC1000AUD_AUD_CODEC_ABB_MICPGA_3_RSTN),
        (AIC1000AUD_AUD_CODEC_ABB_MICPGA_3_INSEL(0x3F)  |
        AIC1000AUD_AUD_CODEC_ABB_MICPGA_3_IBIT(0x3)     |
        AIC1000AUD_AUD_CODEC_ABB_MICPGA_3_INBIAS_P(0xF) |
        AIC1000AUD_AUD_CODEC_ABB_MICPGA_3_INBIAS_N(0xF) |
        AIC1000AUD_AUD_CODEC_ABB_MICPGA_3_ICL_HPF_BIT   |
        AIC1000AUD_AUD_CODEC_ABB_MICPGA_3_ICL_MODE      |
        AIC1000AUD_AUD_CODEC_ABB_MICPGA_3_GAIN(0x3)     |
        AIC1000AUD_AUD_CODEC_ABB_MICPGA_3_RSTN));

    PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->abb_micbias),
        (AIC1000AUD_AUD_CODEC_ABB_MUX2MSADC_BIT(0)     |
        0                                              |
        AIC1000AUD_AUD_CODEC_ABB_MICBIAS_CAL_BIT(4)    |
        AIC1000AUD_AUD_CODEC_ABB_MICBIAS_CC_BIT(3)     |
        0                                              |
        0                                              |
        0                                              |
        AIC1000AUD_AUD_CODEC_ABB_MICBIAS_VBIT(1)       |
        AIC1000AUD_AUD_CODEC_ABB_VAD_PGA_INBIAS_P(0)   |
        AIC1000AUD_AUD_CODEC_ABB_VAD_PGA_INBIAS_N(0)   |
        AIC1000AUD_AUD_CODEC_ABB_VAD_MICBIAS_BYP),
        (AIC1000AUD_AUD_CODEC_ABB_MUX2MSADC_BIT(0xF)   |
        AIC1000AUD_AUD_CODEC_ABB_PU_MUX2MSADC          |
        AIC1000AUD_AUD_CODEC_ABB_MICBIAS_CAL_BIT(0x7)  |
        AIC1000AUD_AUD_CODEC_ABB_MICBIAS_CC_BIT(0x3)   |
        AIC1000AUD_AUD_CODEC_ABB_MICBIAS_HIZ_MODE      |
        AIC1000AUD_AUD_CODEC_ABB_MICBIAS_LP_MODE       |
        AIC1000AUD_AUD_CODEC_ABB_MICBIAS_LPF_MODE      |
        AIC1000AUD_AUD_CODEC_ABB_MICBIAS_VBIT(0x3)     |
        AIC1000AUD_AUD_CODEC_ABB_VAD_PGA_INBIAS_P(0xF) |
        AIC1000AUD_AUD_CODEC_ABB_VAD_PGA_INBIAS_N(0xF) |
        AIC1000AUD_AUD_CODEC_ABB_VAD_MICBIAS_BYP));

    PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->abb_sdm_adc0),
        (AIC1000AUD_AUD_CODEC_ABB_SDM_ADC_OP_IBIT(1)      |
        AIC1000AUD_AUD_CODEC_ABB_SDM_ADC_BIAS_IBIT(2)     |
        AIC1000AUD_AUD_CODEC_ABB_SDM_ADC_DLY_BIT(2)       |
        AIC1000AUD_AUD_CODEC_ABB_SDM_ADC_DWA_EN           |
        AIC1000AUD_AUD_CODEC_ABB_SDM_ADC_VHI_BIT(3)       |
        AIC1000AUD_AUD_CODEC_ABB_SDM_ADC_VLO_BIT(3)       |
        AIC1000AUD_AUD_CODEC_ABB_SDM_ADC_VPS_BIT(2)       |
        0                                                 |
        0                                                 |
        AIC1000AUD_AUD_CODEC_ABB_SDM_ADC_1_GAIN_BIT(2)    |
        AIC1000AUD_AUD_CODEC_ABB_SDM_ADC_2_GAIN_BIT(2)    |
        AIC1000AUD_AUD_CODEC_ABB_SDM_ADC_3_GAIN_BIT(2)    |
        AIC1000AUD_AUD_CODEC_ABB_SDM_ADC_ANA_RSTN         |
        AIC1000AUD_AUD_CODEC_ABB_SDM_ADC_DIG_RSTN),
        (AIC1000AUD_AUD_CODEC_ABB_SDM_ADC_OP_IBIT(0x3)    |
        AIC1000AUD_AUD_CODEC_ABB_SDM_ADC_BIAS_IBIT(0x3)   |
        AIC1000AUD_AUD_CODEC_ABB_SDM_ADC_DLY_BIT(0x3)     |
        AIC1000AUD_AUD_CODEC_ABB_SDM_ADC_DWA_EN           |
        AIC1000AUD_AUD_CODEC_ABB_SDM_ADC_VHI_BIT(0x7)     |
        AIC1000AUD_AUD_CODEC_ABB_SDM_ADC_VLO_BIT(0x7)     |
        AIC1000AUD_AUD_CODEC_ABB_SDM_ADC_VPS_BIT(0x3)     |
        AIC1000AUD_AUD_CODEC_ABB_SDM_ADC_VPS_DIS          |
        AIC1000AUD_AUD_CODEC_ABB_SDM_ADC_VREG_BYPASS      |
        AIC1000AUD_AUD_CODEC_ABB_SDM_ADC_1_GAIN_BIT(0x7)  |
        AIC1000AUD_AUD_CODEC_ABB_SDM_ADC_2_GAIN_BIT(0x7)  |
        AIC1000AUD_AUD_CODEC_ABB_SDM_ADC_3_GAIN_BIT(0x7)  |
        AIC1000AUD_AUD_CODEC_ABB_SDM_ADC_ANA_RSTN         |
        AIC1000AUD_AUD_CODEC_ABB_SDM_ADC_DIG_RSTN));

    // gain for differential mode
    PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->abb_sdm_dac1),
        (AIC1000AUD_AUD_CODEC_ABB_SDM_DAC_RDAC_MODE     |
        0                                               |
        0                                               |
        AIC1000AUD_AUD_CODEC_ABB_SDM_DAC_IBIAS_BIT(2)   |
        AIC1000AUD_AUD_CODEC_ABB_SDM_DAC_VINT_BIT(2)    |
        AIC1000AUD_AUD_CODEC_ABB_SDM_DAC_VHI_BIT(6)     |
        AIC1000AUD_AUD_CODEC_ABB_SDM_DAC_VLO_BIT(1)     |
        0                                               |
        0                                               |
        AIC1000AUD_AUD_CODEC_ABB_SDM_DAC_GAIN_BIT2(10)  |
        AIC1000AUD_AUD_CODEC_ABB_SDM_DAC_GAIN_BIT1(11)  |
        0                                               |
        0                                               |
        0                                               |
        AIC1000AUD_AUD_CODEC_ABB_SDM_DAC_ANA_RSTN       |
        AIC1000AUD_AUD_CODEC_ABB_SDM_DAC_DIG_RSTN),
        (AIC1000AUD_AUD_CODEC_ABB_SDM_DAC_RDAC_MODE     |
        AIC1000AUD_AUD_CODEC_ABB_SDM_DAC_RFRSH_EN       |
        AIC1000AUD_AUD_CODEC_ABB_SDM_DAC_VCAL_EN        |
        AIC1000AUD_AUD_CODEC_ABB_SDM_DAC_IBIAS_BIT(0x3) |
        AIC1000AUD_AUD_CODEC_ABB_SDM_DAC_VINT_BIT(0x3)  |
        AIC1000AUD_AUD_CODEC_ABB_SDM_DAC_VHI_BIT(0x7)   |
        AIC1000AUD_AUD_CODEC_ABB_SDM_DAC_VLO_BIT(0x7)   |
        AIC1000AUD_AUD_CODEC_ABB_SDM_DAC_VREG_BYPASS    |
        AIC1000AUD_AUD_CODEC_ABB_SDM_DAC_CLK_EDGE_SEL   |
        AIC1000AUD_AUD_CODEC_ABB_SDM_DAC_GAIN_BIT2(0xF) |
        AIC1000AUD_AUD_CODEC_ABB_SDM_DAC_GAIN_BIT1(0xF) |
        AIC1000AUD_AUD_CODEC_ABB_SDM_DAC_L_SE_MODE      |
        AIC1000AUD_AUD_CODEC_ABB_SDM_DAC_R_SE_MODE      |
        AIC1000AUD_AUD_CODEC_ABB_SDM_DAC_SE_MODE_DR     |
        AIC1000AUD_AUD_CODEC_ABB_SDM_DAC_ANA_RSTN       |
        AIC1000AUD_AUD_CODEC_ABB_SDM_DAC_DIG_RSTN));

    PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->abb_hp_l),
        (AIC1000AUD_AUD_CODEC_ABB_HP_L_DACIN_SEL     |
        AIC1000AUD_AUD_CODEC_ABB_HP_L_IBIT(10)       |
        AIC1000AUD_AUD_CODEC_ABB_HP_L_GAIN_BIT(5)    |
        AIC1000AUD_AUD_CODEC_ABB_HP_L_DIFF_MODE),
        (AIC1000AUD_AUD_CODEC_ABB_HP_L_DACIN_SEL     |
        AIC1000AUD_AUD_CODEC_ABB_HP_L_IBIT(0x1F)     |
        AIC1000AUD_AUD_CODEC_ABB_HP_L_GAIN_BIT(0x7)  |
        AIC1000AUD_AUD_CODEC_ABB_HP_L_DIFF_MODE));

    PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->abb_hp_r),
        (AIC1000AUD_AUD_CODEC_ABB_HP_R_DACIN_SEL     |
        AIC1000AUD_AUD_CODEC_ABB_HP_R_IBIT(10)       |
        AIC1000AUD_AUD_CODEC_ABB_HP_R_GAIN_BIT(5)    |
        AIC1000AUD_AUD_CODEC_ABB_HP_R_DIFF_MODE),
        (AIC1000AUD_AUD_CODEC_ABB_HP_R_DACIN_SEL     |
        AIC1000AUD_AUD_CODEC_ABB_HP_R_IBIT(0x1F)     |
        AIC1000AUD_AUD_CODEC_ABB_HP_R_GAIN_BIT(0x7)  |
        AIC1000AUD_AUD_CODEC_ABB_HP_R_DIFF_MODE));

    PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->spk_gain),
        (AIC1000AUD_AUD_CODEC_SPK_GAIN0(0x0340)  |
        AIC1000AUD_AUD_CODEC_SPK_GAIN1(0x0340)),
        (AIC1000AUD_AUD_CODEC_SPK_GAIN0(0x7FFF) |
        AIC1000AUD_AUD_CODEC_SPK_GAIN1(0x7FFF)));
}

void aic1000_mic_matix_config(uint8_t type)
{
    if (aic1000_dbg_mask & AIC1000_DBG_ADC_CFG) {
        TRACE("%s, type:%d\n", __func__, type);
    }

    ASSERT_ERR(type < sizeof(mic_matrix_tbl) / sizeof(mic_matrix_tbl[0]));

    mic_matrix_type = type;

    uint8_t adc_p0 = mic_matrix_tbl[type][0];
    uint8_t adc_p1 = mic_matrix_tbl[type][1];
    uint8_t adc_p2 = mic_matrix_tbl[type][2];

    //@ cfg adc path
    PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->core_ctrl1),
        (AIC1000AUD_AUD_CODEC_MIC_ADC_P0(adc_p0) |
        AIC1000AUD_AUD_CODEC_MIC_ADC_P1(adc_p1)  |
        AIC1000AUD_AUD_CODEC_MIC_ADC_P2(adc_p2)),
        (AIC1000AUD_AUD_CODEC_MIC_ADC_P0(3)      |
        AIC1000AUD_AUD_CODEC_MIC_ADC_P1(3)       |
        AIC1000AUD_AUD_CODEC_MIC_ADC_P2(3)));
}

void aic1000_adc_pu(uint8_t ch_map)
{
    if (aic1000_dbg_mask & AIC1000_DBG_ADC_COMMON) {
        TRACE("%s, adc_ch_ana_pu:%X ch_map:%X\n", __func__, adc_ch_ana_pu, ch_map);
    }

    uint8_t adc1_pu = 0;
    uint8_t adc2_pu = 0;
    uint8_t adc3_pu = 0;

    if (adc_ch_ana_pu == 0) {
        //@ clear adc mem
        PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->mem_ctrl),
            AIC1000AUD_AUD_CODEC_MIC_MEM_CLKSEL,
            AIC1000AUD_AUD_CODEC_MIC_MEM_CLKSEL);
        PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->mem_ctrl),
            AIC1000AUD_AUD_CODEC_MIC_MEM_CLR,
            AIC1000AUD_AUD_CODEC_MIC_MEM_CLR);
        while(!((PMIC_MEM_READ((unsigned int)&(aic1000audAudCodec->mem_ctrl))) & AIC1000AUD_AUD_CODEC_MIC_MEM_CLR_DONE));
        PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->mem_ctrl), 0, AIC1000AUD_AUD_CODEC_MIC_MEM_CLR);
        PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->mem_ctrl), 0, AIC1000AUD_AUD_CODEC_MIC_MEM_CLKSEL);
    }

    if ((adc_ch_ana_pu & ch_map) == ch_map) {
        return;
    }

    if (ch_map & AUD_CH_MAP_CH_0) {
        switch (mic_matrix_tbl[mic_matrix_type][0]) {
        case 0:
            adc1_pu = 1;
            break;
        case 1:
            adc2_pu = 1;
            break;
        case 2:
            adc3_pu = 1;
            break;
        default:
            break;
        }
    }

    if (ch_map & AUD_CH_MAP_CH_1) {
        switch (mic_matrix_tbl[mic_matrix_type][1]) {
        case 0:
            adc1_pu = 1;
            break;
        case 1:
            adc2_pu = 1;
            break;
        case 2:
            adc3_pu = 1;
            break;
        default:
            break;
        }
    }

    if (ch_map & AUD_CH_MAP_CH_2) {
        switch (mic_matrix_tbl[mic_matrix_type][2]) {
        case 0:
            adc1_pu = 1;
            break;
        case 1:
            adc2_pu = 1;
            break;
        case 2:
            adc3_pu = 1;
            break;
        default:
            break;
        }
    }

    PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->abb_micbias),
        AIC1000AUD_AUD_CODEC_ABB_PU_MICBIAS,
        AIC1000AUD_AUD_CODEC_ABB_PU_MICBIAS);

    PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->abb_micpga_1),
        ((AIC1000AUD_AUD_CODEC_ABB_PU_MICPGA_3 * adc3_pu)  |
        (AIC1000AUD_AUD_CODEC_ABB_PU_MICPGA_2 * adc2_pu)   |
        (AIC1000AUD_AUD_CODEC_ABB_PU_MICPGA_1 * adc1_pu)),
        ((AIC1000AUD_AUD_CODEC_ABB_PU_MICPGA_3 * adc3_pu)  |
        (AIC1000AUD_AUD_CODEC_ABB_PU_MICPGA_2 * adc2_pu)   |
        (AIC1000AUD_AUD_CODEC_ABB_PU_MICPGA_1 * adc1_pu)));

    //TODO add 500ns delay

    PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->abb_sdm_adc0),
        ((AIC1000AUD_AUD_CODEC_ABB_PU_SDM_ADC_1 * adc1_pu) |
        (AIC1000AUD_AUD_CODEC_ABB_PU_SDM_ADC_2 * adc2_pu)  |
        (AIC1000AUD_AUD_CODEC_ABB_PU_SDM_ADC_3 * adc3_pu)),
        ((AIC1000AUD_AUD_CODEC_ABB_PU_SDM_ADC_1 * adc1_pu) |
        (AIC1000AUD_AUD_CODEC_ABB_PU_SDM_ADC_2 * adc2_pu)  |
        (AIC1000AUD_AUD_CODEC_ABB_PU_SDM_ADC_3 * adc3_pu)));

    adc_ch_ana_pu |= ch_map;
}

void aic1000_dac_pu(uint8_t ch_map)
{
    if (aic1000_dbg_mask & AIC1000_DBG_DAC_COMMON) {
        TRACE("%s, dac_ch_ana_pu:%X ch_map:%X\n", __func__, dac_ch_ana_pu, ch_map);
    }

    uint8_t l_pu = 0;
    uint8_t r_pu = 0;

    if (dac_ch_ana_pu == 0) {
        //@ clear dac mem
        PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->mem_ctrl),
            AIC1000AUD_AUD_CODEC_SPK_MEM_CLKSEL,
            AIC1000AUD_AUD_CODEC_SPK_MEM_CLKSEL);
        PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->mem_ctrl),
            AIC1000AUD_AUD_CODEC_SPK_MEM_CLR,
            AIC1000AUD_AUD_CODEC_SPK_MEM_CLR);
        while(!((PMIC_MEM_READ((unsigned int)&(aic1000audAudCodec->mem_ctrl))) & AIC1000AUD_AUD_CODEC_SPK_MEM_CLR_DONE));
        PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->mem_ctrl), 0, AIC1000AUD_AUD_CODEC_SPK_MEM_CLR);
        PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->mem_ctrl), 0, AIC1000AUD_AUD_CODEC_SPK_MEM_CLKSEL);
    }

    if ((dac_ch_ana_pu & ch_map) == ch_map) {
        return;
    }

    if (ch_map & AUD_CH_MAP_CH_0) {
        l_pu = 1;
    }
    if (ch_map & AUD_CH_MAP_CH_1) {
        r_pu = 1;
    }

    PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->abb_sdm_dac1),
        (AIC1000AUD_AUD_CODEC_ABB_SDM_DAC_ANA_RSTN      |
        AIC1000AUD_AUD_CODEC_ABB_SDM_DAC_DIG_RSTN       |
        (AIC1000AUD_AUD_CODEC_ABB_PU_SDM_DAC_R * r_pu)  |
        (AIC1000AUD_AUD_CODEC_ABB_PU_SDM_DAC_L * l_pu)),
        (AIC1000AUD_AUD_CODEC_ABB_SDM_DAC_ANA_RSTN      |
        AIC1000AUD_AUD_CODEC_ABB_SDM_DAC_DIG_RSTN       |
        (AIC1000AUD_AUD_CODEC_ABB_PU_SDM_DAC_R * r_pu)  |
        (AIC1000AUD_AUD_CODEC_ABB_PU_SDM_DAC_L * l_pu)));

    //TODO add delay?

    if (l_pu == 1) {
        PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->abb_hp_l),
            (AIC1000AUD_AUD_CODEC_ABB_PU_HP_L_MPATH |
            AIC1000AUD_AUD_CODEC_ABB_PU_HP_L_BIAS),
            (AIC1000AUD_AUD_CODEC_ABB_PU_HP_L_MPATH |
            AIC1000AUD_AUD_CODEC_ABB_PU_HP_L_BIAS));
    }

    if (r_pu == 1) {
        PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->abb_hp_r),
            (AIC1000AUD_AUD_CODEC_ABB_PU_HP_R_MPATH |
            AIC1000AUD_AUD_CODEC_ABB_PU_HP_R_BIAS),
            (AIC1000AUD_AUD_CODEC_ABB_PU_HP_R_MPATH |
            AIC1000AUD_AUD_CODEC_ABB_PU_HP_R_BIAS));
    }

    dac_ch_ana_pu |= ch_map;
}

void aic1000_adc_pd(uint8_t ch_map)
{
    if (aic1000_dbg_mask & AIC1000_DBG_ADC_COMMON) {
        TRACE("%s, adc_ch_ana_pu:%X ch_map:%X\n", __func__, adc_ch_ana_pu, ch_map);
    }

    uint8_t adc1_pd = 0;
    uint8_t adc2_pd = 0;
    uint8_t adc3_pd = 0;

    if ((adc_ch_ana_pu & ch_map) == 0) {
        return;
    }

    if (ch_map & AUD_CH_MAP_CH_0) {
        switch (mic_matrix_tbl[mic_matrix_type][0]) {
        case 0:
            adc1_pd = 1;
            break;
        case 1:
            adc2_pd = 1;
            break;
        case 2:
            adc3_pd = 1;
            break;
        default:
            break;
        }
    }

    if (ch_map & AUD_CH_MAP_CH_1) {
        switch (mic_matrix_tbl[mic_matrix_type][1]) {
        case 0:
            adc1_pd = 1;
            break;
        case 1:
            adc2_pd = 1;
            break;
        case 2:
            adc3_pd = 1;
            break;
        default:
            break;
        }
    }

    if (ch_map & AUD_CH_MAP_CH_2) {
        switch (mic_matrix_tbl[mic_matrix_type][2]) {
        case 0:
            adc1_pd = 1;
            break;
        case 1:
            adc2_pd = 1;
            break;
        case 2:
            adc3_pd = 1;
            break;
        default:
            break;
        }
    }

    PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->abb_sdm_adc0),
        ((AIC1000AUD_AUD_CODEC_ABB_PU_SDM_ADC_1 * (1 - adc1_pd))  |
        (AIC1000AUD_AUD_CODEC_ABB_PU_SDM_ADC_2 * (1 - adc2_pd))   |
        (AIC1000AUD_AUD_CODEC_ABB_PU_SDM_ADC_3 * (1 - adc3_pd))),
        ((AIC1000AUD_AUD_CODEC_ABB_PU_SDM_ADC_1 * adc1_pd)  |
        (AIC1000AUD_AUD_CODEC_ABB_PU_SDM_ADC_2 * adc2_pd)   |
        (AIC1000AUD_AUD_CODEC_ABB_PU_SDM_ADC_3 * adc3_pd)));

    //TODO add delay?

    PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->abb_micpga_1),
        ((AIC1000AUD_AUD_CODEC_ABB_PU_MICPGA_3 * (1 - adc3_pd))  |
        (AIC1000AUD_AUD_CODEC_ABB_PU_MICPGA_2 * (1- adc2_pd))    |
        (AIC1000AUD_AUD_CODEC_ABB_PU_MICPGA_1 * (1 - adc1_pd))),
        ((AIC1000AUD_AUD_CODEC_ABB_PU_MICPGA_3 * adc3_pd)  |
        (AIC1000AUD_AUD_CODEC_ABB_PU_MICPGA_2 * adc2_pd)   |
        (AIC1000AUD_AUD_CODEC_ABB_PU_MICPGA_1 * adc1_pd)));

    adc_ch_ana_pu &= ~ch_map;

    if (adc_ch_ana_pu == 0) {
        PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->abb_micbias),
            0,
            AIC1000AUD_AUD_CODEC_ABB_PU_MICBIAS);
    }
}

void aic1000_dac_pd(uint8_t ch_map)
{
    if (aic1000_dbg_mask & AIC1000_DBG_DAC_COMMON) {
        TRACE("%s, dac_ch_ana_pu:%X ch_map:%X\n", __func__, dac_ch_ana_pu, ch_map);
    }

    uint8_t l_pd = 0;
    uint8_t r_pd = 0;

    if ((dac_ch_ana_pu & ch_map) == 0) {
        return;
    }

    if (ch_map & AUD_CH_MAP_CH_0) {
        l_pd = 1;
    }
    if (ch_map & AUD_CH_MAP_CH_1) {
        r_pd = 1;
    }

    if (l_pd == 1) {
        PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->abb_hp_l),
            (0                                      |
            0),
            (AIC1000AUD_AUD_CODEC_ABB_PU_HP_L_MPATH |
            AIC1000AUD_AUD_CODEC_ABB_PU_HP_L_BIAS));
    }

    if (r_pd == 1) {
        PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->abb_hp_r),
            (0                                      |
            0),
            (AIC1000AUD_AUD_CODEC_ABB_PU_HP_R_MPATH |
            AIC1000AUD_AUD_CODEC_ABB_PU_HP_R_BIAS));
    }

    //TODO add delay?

    PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->abb_sdm_dac1),
        ((AIC1000AUD_AUD_CODEC_ABB_PU_SDM_DAC_R * (1 - r_pd))  |
        (AIC1000AUD_AUD_CODEC_ABB_PU_SDM_DAC_L * (1 - l_pd))),
        ((AIC1000AUD_AUD_CODEC_ABB_PU_SDM_DAC_R * r_pd)  |
        (AIC1000AUD_AUD_CODEC_ABB_PU_SDM_DAC_L * l_pd)));

    dac_ch_ana_pu &= ~ch_map;
}

void aic1000_adc_open(aic1000_cfg_t *cfg)
{
    if (aic1000_dbg_mask & AIC1000_DBG_ADC_COMMON) {
        TRACE("%s, adc_ch_en:%X ch_map:%X\n", __func__, adc_ch_en, cfg->ch_map);
    }

    //@ enable adc ANALOG
    aic1000_adc_pu(cfg->ch_map);

    if (adc_ch_en == 0) {
        if (adc_mem_cleared == false) {
            //@ clear adc mem
            PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->mem_ctrl),
                AIC1000AUD_AUD_CODEC_MIC_MEM_CLKSEL,
                AIC1000AUD_AUD_CODEC_MIC_MEM_CLKSEL);
            PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->mem_ctrl),
                AIC1000AUD_AUD_CODEC_MIC_MEM_CLR,
                AIC1000AUD_AUD_CODEC_MIC_MEM_CLR);
            while(!((PMIC_MEM_READ((unsigned int)&(aic1000audAudCodec->mem_ctrl))) & AIC1000AUD_AUD_CODEC_MIC_MEM_CLR_DONE));
            PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->mem_ctrl), 0, AIC1000AUD_AUD_CODEC_MIC_MEM_CLR);
            PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->mem_ctrl), 0, AIC1000AUD_AUD_CODEC_MIC_MEM_CLKSEL);

            adc_mem_cleared = true;
        }
    }

#if (AIC1000AUD_LOOPBACK)
    // loopback, dac output to adc input
    PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->intf_ctrl),
        AIC1000AUD_AUD_CODEC_LOOP_EN_S2M(0x3),
        AIC1000AUD_AUD_CODEC_LOOP_EN_S2M(0x3));
#endif
}

void aic1000_dac_open(aic1000_cfg_t *cfg)
{
    if (aic1000_dbg_mask & AIC1000_DBG_DAC_COMMON) {
        TRACE("%s, dac_ch_en:%X ch_map:%X\n", __func__, dac_ch_en, cfg->ch_map);
    }

    //@ enable dac ANALOG
    aic1000_dac_pu(cfg->ch_map);

    if (dac_ch_en == 0) {
        if (dac_mem_cleared == false) {
            //@ clear dac mem
            PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->mem_ctrl),
                AIC1000AUD_AUD_CODEC_SPK_MEM_CLKSEL,
                AIC1000AUD_AUD_CODEC_SPK_MEM_CLKSEL);
            PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->mem_ctrl),
                AIC1000AUD_AUD_CODEC_SPK_MEM_CLR,
                AIC1000AUD_AUD_CODEC_SPK_MEM_CLR);
            while(!((PMIC_MEM_READ((unsigned int)&(aic1000audAudCodec->mem_ctrl))) & AIC1000AUD_AUD_CODEC_SPK_MEM_CLR_DONE));
            PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->mem_ctrl), 0, AIC1000AUD_AUD_CODEC_SPK_MEM_CLR);
            PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->mem_ctrl), 0, AIC1000AUD_AUD_CODEC_SPK_MEM_CLKSEL);

            dac_mem_cleared = true;
        }
    }
}

void aic1000_adc_config(aic1000_cfg_t *cfg)
{
    if (aic1000_dbg_mask & AIC1000_DBG_ADC_COMMON) {
        TRACE("%s, adc_ch_en:%X ch_map:%X\n", __func__, adc_ch_en, cfg->ch_map);
    }

    uint8_t d36_en = 0, d36_d3 = 0;
    uint8_t i2s1_hcyc = 0;

    if ((adc_ch_en & cfg->ch_map) != 0) {
        return;
    }

    if (cfg->sample_rate != AUD_SAMPRATE_48000) {
        adc_ch_d36_en |= cfg->ch_map;
        if (cfg->sample_rate == AUD_SAMPRATE_16000) {
            adc_ch_d36_d3 |= cfg->ch_map;
        } else {
            adc_ch_d36_d3 &= ~cfg->ch_map;
        }
    } else {
        adc_ch_d36_en &= ~cfg->ch_map;
    }

    if (adc_ch_d36_d3 != 0) {
        d36_d3 = 1;
    } else {
        d36_d3 = 0;
    }

    switch (adc_ch_d36_en) {
    case 0:
        d36_en = 0;
        break;
    case AUD_CH_MAP_CH_0:
        d36_en = 1;
        break;
    case AUD_CH_MAP_CH_0 | AUD_CH_MAP_CH_1:
        d36_en = 3;
        break;
    case AUD_CH_MAP_CH_0 | AUD_CH_MAP_CH_1 | AUD_CH_MAP_CH_2:
        d36_en = 2;
        break;
    default:
        ASSERT_ERR(0);
        break;
    }

    //@ cfg adc path
    if ((adc_ch_en | cfg->ch_map) == (AUD_CH_MAP_CH_0 | AUD_CH_MAP_CH_1 | AUD_CH_MAP_CH_2)) {
        PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->core_ctrl1),
            (AIC1000AUD_AUD_CODEC_MIC_ANC_P0(2) |
            AIC1000AUD_AUD_CODEC_MIC_ANC_P1(2)),
            (AIC1000AUD_AUD_CODEC_MIC_ANC_P0(3) |
            AIC1000AUD_AUD_CODEC_MIC_ANC_P1(3)));
    }
    PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->core_ctrl1),
        (AIC1000AUD_AUD_CODEC_MIC_D36_D3 * d36_d3),
        AIC1000AUD_AUD_CODEC_MIC_D36_D3);
    PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->core_ctrl0),
        (AIC1000AUD_AUD_CODEC_AUD_CFG_POS |
        AIC1000AUD_AUD_CODEC_MIC_D36_EN(d36_en)),
        (AIC1000AUD_AUD_CODEC_AUD_CFG_POS |
        AIC1000AUD_AUD_CODEC_MIC_D36_EN(3)));

    //@ cfg iis for adc
    if ((cfg->ch_map & (AUD_CH_MAP_CH_0 | AUD_CH_MAP_CH_1)) != 0) {
        switch (cfg->sample_rate) {
        case AUD_SAMPRATE_8000:
            i2s1_hcyc = I2S_HCYC_8K;
            break;
        case AUD_SAMPRATE_16000:
            i2s1_hcyc = I2S_HCYC_16K;
            break;
        case AUD_SAMPRATE_48000:
            i2s1_hcyc = I2S_HCYC_48K;
            break;
        default:
            ASSERT_ERR(0);
            break;
        }
        PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->iis_ctrl0),
            AIC1000AUD_AUD_CODEC_HCYC_IIS1(i2s1_hcyc),
            AIC1000AUD_AUD_CODEC_HCYC_IIS1(0xFF));
        PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->iis_ctrl1),
            AIC1000AUD_AUD_CODEC_IIS1_ODAT_SEL(2),
            AIC1000AUD_AUD_CODEC_IIS1_ODAT_SEL(3));
    }
    if ((cfg->ch_map & AUD_CH_MAP_CH_2) != 0) {
        PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->iis_ctrl1),
            AIC1000AUD_AUD_CODEC_IIS0_ODAT_SEL(3),
            AIC1000AUD_AUD_CODEC_IIS0_ODAT_SEL(3));
    }
}

void aic1000_dac_config(aic1000_cfg_t *cfg)
{
    if (aic1000_dbg_mask & AIC1000_DBG_DAC_COMMON) {
        TRACE("%s, dac_ch_en:%X ch_map:%X\n", __func__, dac_ch_en, cfg->ch_map);
    }

    if ((dac_ch_en & cfg->ch_map) != 0) {
        return;
    }

    //@ cfg dac path
    if ((cfg->ch_num == AUD_CH_NUM_1) && (cfg->ch_map == AUD_CH_MAP_CH_1)) {
        PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->dac_sdm_ctrl),
            AIC1000AUD_AUD_CODEC_DAC_SDM_MUX,
            AIC1000AUD_AUD_CODEC_DAC_SDM_MUX);
    } else {
        PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->dac_sdm_ctrl),
            0,
            AIC1000AUD_AUD_CODEC_DAC_SDM_MUX);
    }
}

void aic1000_adc_start(aic1000_cfg_t *cfg)
{
    if (aic1000_dbg_mask & AIC1000_DBG_ADC_COMMON) {
        TRACE("%s, adc_ch_en:%X ch_map:%X\n", __func__, adc_ch_en, cfg->ch_map);
    }

    uint8_t adc_en = 0, anc_en = 0, tra_en = 0;
    uint8_t i2s0_en = 0, i2s1_en = 0;
    uint8_t i2s0_odata_en = 0, i2s1_odata_en = 0;
    uint8_t i2s0_trig_sel = 0, i2s1_trig_sel = 0;
#if (AIC1000AUD_CHECK_STATUS)
    uint32_t status;
#endif

    if ((adc_ch_en & cfg->ch_map) == cfg->ch_map) {
        return;
    }

    switch (adc_ch_en | cfg->ch_map) {
    case AUD_CH_MAP_CH_0:
        adc_en = 1;
        tra_en = 1;
        anc_en = 0;
        i2s0_en = 0;
        i2s1_en = 1;
        i2s0_odata_en = 0;
        i2s1_odata_en = 1;
        break;
    case AUD_CH_MAP_CH_0 | AUD_CH_MAP_CH_1:
        adc_en = 3;
        tra_en = 3;
        anc_en = 0;
        i2s0_en = 0;
        i2s1_en = 1;
        i2s0_odata_en = 0;
        i2s1_odata_en = 1;
        break;
    case AUD_CH_MAP_CH_0 | AUD_CH_MAP_CH_1 | AUD_CH_MAP_CH_2:
        adc_en = 7;
        tra_en = 3;
        anc_en = 1;
        i2s0_en = 1;
        i2s1_en = 1;
        i2s0_odata_en = 1;
        i2s1_odata_en = 1;
        break;
    default:
        ASSERT_ERR(0);
        break;
    }

    if (dac_ch_en != 0) {
        i2s0_en = 1;
        i2s0_trig_sel = (PMIC_MEM_READ((unsigned int)&(aic1000audAudCodec->iis_ctrl1)) & AIC1000AUD_AUD_CODEC_IIS0_TRIG_SEL) ? 1 : 0;
    }

    if (adc_mem_cleared == false) {
        //@ clear adc mem
        PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->mem_ctrl),
            AIC1000AUD_AUD_CODEC_MIC_MEM_CLKSEL,
            AIC1000AUD_AUD_CODEC_MIC_MEM_CLKSEL);
        PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->mem_ctrl),
            AIC1000AUD_AUD_CODEC_MIC_MEM_CLR,
            AIC1000AUD_AUD_CODEC_MIC_MEM_CLR);
        while(!((PMIC_MEM_READ((unsigned int)&(aic1000audAudCodec->mem_ctrl))) & AIC1000AUD_AUD_CODEC_MIC_MEM_CLR_DONE));
        PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->mem_ctrl), 0, AIC1000AUD_AUD_CODEC_MIC_MEM_CLR);
        PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->mem_ctrl), 0, AIC1000AUD_AUD_CODEC_MIC_MEM_CLKSEL);

        adc_mem_cleared = true;
    }

    //@ enable adc
    PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->core_ctrl0),
        (AIC1000AUD_AUD_CODEC_AUD_CFG_POS       |
        AIC1000AUD_AUD_CODEC_MIC_ADC_EN(adc_en) |
        AIC1000AUD_AUD_CODEC_MIC_ANC_EN(anc_en) |
        AIC1000AUD_AUD_CODEC_MIC_TRA_EN(tra_en) |
        0),
        (AIC1000AUD_AUD_CODEC_AUD_CFG_POS  |
        AIC1000AUD_AUD_CODEC_MIC_ADC_EN(7) |
        AIC1000AUD_AUD_CODEC_MIC_ANC_EN(3) |
        AIC1000AUD_AUD_CODEC_MIC_TRA_EN(3) |
        AIC1000AUD_AUD_CODEC_ADDA_DLY_EN));
    //@ enable iis
    PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->iis_ctrl1),
        ((AIC1000AUD_AUD_CODEC_IIS0_ODAT_EN * i2s0_odata_en) |
        (AIC1000AUD_AUD_CODEC_IIS0_TRIG_SEL * i2s0_trig_sel) |
        (AIC1000AUD_AUD_CODEC_IIS1_ODAT_EN * i2s1_odata_en)  |
        (AIC1000AUD_AUD_CODEC_IIS1_TRIG_SEL * i2s1_trig_sel) |
        (AIC1000AUD_AUD_CODEC_IIS1_TRIG_EN * i2s1_en)        |
        (AIC1000AUD_AUD_CODEC_IIS0_TRIG_EN * i2s0_en)),
        (AIC1000AUD_AUD_CODEC_IIS0_ODAT_EN |
        AIC1000AUD_AUD_CODEC_IIS0_TRIG_SEL |
        AIC1000AUD_AUD_CODEC_IIS1_ODAT_EN  |
        AIC1000AUD_AUD_CODEC_IIS1_TRIG_SEL |
        AIC1000AUD_AUD_CODEC_IIS1_TRIG_EN  |
        AIC1000AUD_AUD_CODEC_IIS0_TRIG_EN));
    PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->iis_ctrl0),
        AIC1000AUD_AUD_CODEC_IIS_EN,
        AIC1000AUD_AUD_CODEC_IIS_EN);
    // force bck enable
    PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->clk_ctrl),
        (AIC1000AUD_AUD_CODEC_CGEN_FIX(0x80) |
        AIC1000AUD_AUD_CODEC_CGEN_VAL(0x80)),
        (AIC1000AUD_AUD_CODEC_CGEN_FIX(0x80) |
        AIC1000AUD_AUD_CODEC_CGEN_VAL(0x80)));

    //@ check status
#if (AIC1000AUD_CHECK_STATUS)
    status = PMIC_MEM_READ((unsigned int)&(aic1000audAudCodec->aud_cfg_sync));
    ASSERT_ERR2((status & AIC1000AUD_AUD_CODEC_MIC_ADC_EN_SYNC(7)) == AIC1000AUD_AUD_CODEC_MIC_ADC_EN_SYNC(adc_en),
        "read:%X write:%X\n", (status & AIC1000AUD_AUD_CODEC_MIC_ADC_EN_SYNC(7)), AIC1000AUD_AUD_CODEC_MIC_ADC_EN_SYNC(adc_en));
#endif

    adc_ch_en |= cfg->ch_map;
}

void aic1000_dac_start(aic1000_cfg_t *cfg)
{
    if (aic1000_dbg_mask & AIC1000_DBG_DAC_COMMON) {
        TRACE("%s, dac_ch_en:%X ch_map:%X\n", __func__, dac_ch_en, cfg->ch_map);
    }

    uint8_t dac_en;
    uint8_t spk_sync_en = 0;
    uint8_t i2s0_trig_sel = 0;
#if (AIC1000AUD_CHECK_STATUS)
    uint32_t status;
#endif

    if ((dac_ch_en & cfg->ch_map) == cfg->ch_map) {
        return;
    }

    dac_en = cfg->ch_num == AUD_CH_NUM_1 ? 1 : 3;

    if (hwp_audProc->aud_proc_dac_trig & AUD_PROC_AUD_DAC_TRIG_HW_EN) {
        spk_sync_en = 1;
    }

    if ((adc_ch_en & AUD_CH_MAP_CH_2) == 0) {
        i2s0_trig_sel = 1;
    }

    if (dac_mem_cleared == false) {
        //@ clear dac mem
        PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->mem_ctrl),
            AIC1000AUD_AUD_CODEC_SPK_MEM_CLKSEL,
            AIC1000AUD_AUD_CODEC_SPK_MEM_CLKSEL);
        PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->mem_ctrl),
            AIC1000AUD_AUD_CODEC_SPK_MEM_CLR,
            AIC1000AUD_AUD_CODEC_SPK_MEM_CLR);
        while(!((PMIC_MEM_READ((unsigned int)&(aic1000audAudCodec->mem_ctrl))) & AIC1000AUD_AUD_CODEC_SPK_MEM_CLR_DONE));
        PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->mem_ctrl), 0, AIC1000AUD_AUD_CODEC_SPK_MEM_CLR);
        PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->mem_ctrl), 0, AIC1000AUD_AUD_CODEC_SPK_MEM_CLKSEL);

        dac_mem_cleared = true;
    }

    //@ enable dac
    PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->core_ctrl0),
        (AIC1000AUD_AUD_CODEC_AUD_CFG_POS                |
        AIC1000AUD_AUD_CODEC_SPK_DAC_EN(dac_en)          |
        (AIC1000AUD_AUD_CODEC_SPK_SYNC_EN * spk_sync_en) |
        0),
        (AIC1000AUD_AUD_CODEC_AUD_CFG_POS  |
        AIC1000AUD_AUD_CODEC_SPK_DAC_EN(3) |
        AIC1000AUD_AUD_CODEC_SPK_SYNC_EN   |
        AIC1000AUD_AUD_CODEC_ADDA_DLY_EN));
    //@ enable iis
    PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->iis_ctrl1),
        (AIC1000AUD_AUD_CODEC_IIS0_IDAT_EN                   |
        (AIC1000AUD_AUD_CODEC_IIS0_TRIG_SEL * i2s0_trig_sel) |
        AIC1000AUD_AUD_CODEC_IIS0_TRIG_EN),
        (AIC1000AUD_AUD_CODEC_IIS0_IDAT_EN                   |
        AIC1000AUD_AUD_CODEC_IIS0_TRIG_SEL                   |
        AIC1000AUD_AUD_CODEC_IIS0_TRIG_EN));
    PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->iis_ctrl0),
        AIC1000AUD_AUD_CODEC_IIS_EN,
        AIC1000AUD_AUD_CODEC_IIS_EN);
    // force bck enable
    PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->clk_ctrl),
        (AIC1000AUD_AUD_CODEC_CGEN_FIX(0x80) |
        AIC1000AUD_AUD_CODEC_CGEN_VAL(0x80)),
        (AIC1000AUD_AUD_CODEC_CGEN_FIX(0x80) |
        AIC1000AUD_AUD_CODEC_CGEN_VAL(0x80)));

    //@ check status
#if (AIC1000AUD_CHECK_STATUS)
    status = PMIC_MEM_READ((unsigned int)&(aic1000audAudCodec->aud_cfg_sync));
    ASSERT_ERR2((status & AIC1000AUD_AUD_CODEC_SPK_DAC_EN(3)) == AIC1000AUD_AUD_CODEC_SPK_DAC_EN(dac_en),
        "read:%X write:%X\n", (status & AIC1000AUD_AUD_CODEC_SPK_DAC_EN(3)), AIC1000AUD_AUD_CODEC_SPK_DAC_EN(dac_en));
#endif

    dac_ch_en |= cfg->ch_map;
}

void aic1000_adc_stop(aic1000_cfg_t *cfg)
{
    if (aic1000_dbg_mask & AIC1000_DBG_ADC_COMMON) {
        TRACE("%s, adc_ch_en:%X ch_map:%X\n", __func__, adc_ch_en, cfg->ch_map);
    }

    uint8_t adc_en = 0, anc_en = 0, tra_en = 0;
    uint8_t i2s0_en = 0, i2s1_en = 0;
    uint8_t i2s0_odata_en = 0, i2s1_odata_en = 0;
    uint8_t i2s0_trig_sel = 0, i2s1_trig_sel = 0;
#if (AIC1000AUD_CHECK_STATUS)
    uint32_t status;
#endif

    if ((adc_ch_en & cfg->ch_map) == 0) {
        return;
    }

    switch (adc_ch_en & (~cfg->ch_map)) {
    case 0:
        adc_en = 0;
        anc_en = 0;
        tra_en = 0;
        i2s0_en = 0;
        i2s1_en = 0;
        i2s0_odata_en = 0;
        i2s1_odata_en = 0;
        break;
    case AUD_CH_MAP_CH_0 | AUD_CH_MAP_CH_1:
        adc_en = 3;
        anc_en = 0;
        tra_en = 3;
        i2s0_en = 0;
        i2s1_en = 1;
        i2s0_odata_en = 0;
        i2s1_odata_en = 1;
        break;
    default:
        ASSERT_ERR(0);
        break;
    }

    if (dac_ch_en != 0) {
        i2s0_en = 1;
        i2s0_trig_sel = 1;
    }

    //@ disable iis
    PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->iis_ctrl1),
        ((AIC1000AUD_AUD_CODEC_IIS0_ODAT_EN * i2s0_odata_en) |
        (AIC1000AUD_AUD_CODEC_IIS0_TRIG_SEL * i2s0_trig_sel) |
        (AIC1000AUD_AUD_CODEC_IIS1_ODAT_EN * i2s1_odata_en)  |
        (AIC1000AUD_AUD_CODEC_IIS1_TRIG_SEL * i2s1_trig_sel) |
        (AIC1000AUD_AUD_CODEC_IIS1_TRIG_EN * i2s1_en)        |
        (AIC1000AUD_AUD_CODEC_IIS0_TRIG_EN * i2s0_en)),
        (AIC1000AUD_AUD_CODEC_IIS0_ODAT_EN |
        AIC1000AUD_AUD_CODEC_IIS0_TRIG_SEL |
        AIC1000AUD_AUD_CODEC_IIS1_ODAT_EN  |
        AIC1000AUD_AUD_CODEC_IIS1_TRIG_SEL |
        AIC1000AUD_AUD_CODEC_IIS1_TRIG_EN  |
        AIC1000AUD_AUD_CODEC_IIS0_TRIG_EN));

    if ((i2s0_en == 0) && (i2s1_en == 0)) {
        PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->iis_ctrl0), 0, AIC1000AUD_AUD_CODEC_IIS_EN);
        // force bck disable
        PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->clk_ctrl),
            (AIC1000AUD_AUD_CODEC_CGEN_FIX(0) |
            AIC1000AUD_AUD_CODEC_CGEN_VAL(0)),
            (AIC1000AUD_AUD_CODEC_CGEN_FIX(0x80) |
            AIC1000AUD_AUD_CODEC_CGEN_VAL(0x80)));
    }

    //@ disable adc
    PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->core_ctrl0),
        (AIC1000AUD_AUD_CODEC_AUD_CFG_POS       |
        AIC1000AUD_AUD_CODEC_MIC_ADC_EN(adc_en) |
        AIC1000AUD_AUD_CODEC_MIC_ANC_EN(anc_en) |
        AIC1000AUD_AUD_CODEC_MIC_TRA_EN(tra_en) |
        0),
        (AIC1000AUD_AUD_CODEC_AUD_CFG_POS  |
        AIC1000AUD_AUD_CODEC_MIC_ADC_EN(7) |
        AIC1000AUD_AUD_CODEC_MIC_ANC_EN(3) |
        AIC1000AUD_AUD_CODEC_MIC_TRA_EN(3) |
        AIC1000AUD_AUD_CODEC_ADDA_DLY_EN));

    //@ check status
#if (AIC1000AUD_CHECK_STATUS)
    status = PMIC_MEM_READ((unsigned int)&(aic1000audAudCodec->aud_cfg_sync));
    ASSERT_ERR((status & AIC1000AUD_AUD_CODEC_MIC_ADC_EN_SYNC(7)) == AIC1000AUD_AUD_CODEC_MIC_ADC_EN_SYNC(adc_en));
#endif

    adc_ch_en &= ~cfg->ch_map;
    adc_ch_d36_en &= ~cfg->ch_num;
    adc_ch_d36_d3 &= ~cfg->ch_num;

    if (adc_ch_en == 0) {
        adc_mem_cleared = false;
    }
}

void aic1000_dac_stop(aic1000_cfg_t *cfg)
{
    if (aic1000_dbg_mask & AIC1000_DBG_DAC_COMMON) {
        TRACE("%s, dac_ch_en:%X ch_map:%X\n", __func__, dac_ch_en, cfg->ch_map);
    }

    uint8_t i2s0_en = 0;
    uint8_t i2s0_trig_sel = 0;
#if (AIC1000AUD_CHECK_STATUS)
    uint32_t status;
#endif

    if ((dac_ch_en & cfg->ch_map) == 0) {
        return;
    }

    //@ disable iis
    if ((adc_ch_en & AUD_CH_MAP_CH_2) == 0) {
        i2s0_en = 0;
    } else {
        i2s0_en = 1;
    }
    PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->iis_ctrl1),
        (0                                                   |
        (AIC1000AUD_AUD_CODEC_IIS0_TRIG_SEL * i2s0_trig_sel) |
        (AIC1000AUD_AUD_CODEC_IIS0_TRIG_EN * i2s0_en)),
        (AIC1000AUD_AUD_CODEC_IIS0_IDAT_EN                   |
        AIC1000AUD_AUD_CODEC_IIS0_TRIG_SEL                   |
        AIC1000AUD_AUD_CODEC_IIS0_TRIG_EN));
    if (adc_ch_en == 0) {
        PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->iis_ctrl0), 0, AIC1000AUD_AUD_CODEC_IIS_EN);
        // force bck disable
        PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->clk_ctrl),
            (AIC1000AUD_AUD_CODEC_CGEN_FIX(0) |
            AIC1000AUD_AUD_CODEC_CGEN_VAL(0)),
            (AIC1000AUD_AUD_CODEC_CGEN_FIX(0x80) |
            AIC1000AUD_AUD_CODEC_CGEN_VAL(0x80)));
    }
    //@ disable dac
    PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->core_ctrl0),
       (AIC1000AUD_AUD_CODEC_AUD_CFG_POS  |
       AIC1000AUD_AUD_CODEC_SPK_DAC_EN(0) |
       0                                  |
       0),
       (AIC1000AUD_AUD_CODEC_AUD_CFG_POS  |
       AIC1000AUD_AUD_CODEC_SPK_DAC_EN(3) |
       AIC1000AUD_AUD_CODEC_SPK_SYNC_EN   |
       AIC1000AUD_AUD_CODEC_ADDA_DLY_EN));

    //@ check status
#if (AIC1000AUD_CHECK_STATUS)
    status = PMIC_MEM_READ((unsigned int)&(aic1000audAudCodec->aud_cfg_sync));
    ASSERT_ERR((status & AIC1000AUD_AUD_CODEC_SPK_DAC_EN_SYNC(3)) == 0);
#endif

    //@ clear inner ff
    PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->clk_ctrl),
        (AIC1000AUD_AUD_CODEC_CGEN_FIX(0x0c60) |
        AIC1000AUD_AUD_CODEC_CGEN_VAL(0x0c60)),
        (AIC1000AUD_AUD_CODEC_CGEN_FIX(0x0c60) |
        AIC1000AUD_AUD_CODEC_CGEN_VAL(0x0c60)));
    PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->clk_ctrl),
        (AIC1000AUD_AUD_CODEC_CGEN_FIX(0) |
        AIC1000AUD_AUD_CODEC_CGEN_VAL(0)),
        (AIC1000AUD_AUD_CODEC_CGEN_FIX(0x0c60) |
        AIC1000AUD_AUD_CODEC_CGEN_VAL(0x0c60)));

    dac_ch_en &= ~cfg->ch_map;

    dac_mem_cleared = false;
}

void aic1000_adc_close(aic1000_cfg_t *cfg)
{
    if (aic1000_dbg_mask & AIC1000_DBG_ADC_COMMON) {
        TRACE("%s, adc_ch_en:%X ch_map:%X\n", __func__, adc_ch_en, cfg->ch_map);
    }

    aic1000_adc_pd(cfg->ch_map);
}

void aic1000_dac_close(aic1000_cfg_t *cfg)
{
    if (aic1000_dbg_mask & AIC1000_DBG_DAC_COMMON) {
        TRACE("%s, dac_ch_en:%X ch_map:%X\n", __func__, dac_ch_en, cfg->ch_map);
    }

    aic1000_dac_pd(cfg->ch_map);
}

void aic1000_adc_dig_gain_base_config(uint8_t gain)
{
    if (aic1000_dbg_mask & AIC1000_DBG_ADC_CFG) {
        TRACE("%s, gain:%X\n", __func__, gain);
    }

    adc_dig_gain_base = gain;
}

void aic1000_adc_dig_gain_config(uint8_t ch_map, uint8_t gain)
{
    if (aic1000_dbg_mask & AIC1000_DBG_ADC_CFG) {
        TRACE("%s, ch_map:%X gain:%X\n", __func__, ch_map, gain);
    }

    uint8_t adc_1 = 0;
    uint8_t adc_2 = 0;
    uint8_t adc_3 = 0;

    if (gain > 0xFF) {
        gain = 0xFF;
    }

    if (ch_map & AUD_CH_MAP_CH_0) {
        adc_1 = 1;
    }
    if (ch_map & AUD_CH_MAP_CH_1) {
        adc_2 = 1;
    }
    if (ch_map & AUD_CH_MAP_CH_2) {
        adc_3 = 1;
    }

    PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->mic_gain),
        ((adc_1 * AIC1000AUD_AUD_CODEC_MIC_GAIN0(gain)) |
        (adc_2 * AIC1000AUD_AUD_CODEC_MIC_GAIN1(gain))  |
        (adc_3 * AIC1000AUD_AUD_CODEC_MIC_GAIN2(gain))),
        ((adc_1 * AIC1000AUD_AUD_CODEC_MIC_GAIN0(gain)) |
        (adc_2 * AIC1000AUD_AUD_CODEC_MIC_GAIN1(gain))  |
        (adc_3 * AIC1000AUD_AUD_CODEC_MIC_GAIN2(gain))));
}

void aic1000_adc_dig_gain_db_config(uint8_t ch_map, float gain_db)
{
    if (aic1000_dbg_mask & AIC1000_DBG_ADC_CFG) {
        int gain_int = (int)gain_db;
        int gain_frac = (int)((gain_db - gain_int) * 10);
        if (gain_frac < 0) {
            gain_frac = -gain_frac;
        }
        TRACE("%s, ch_map:%X gain_db:%d.%d\n", __func__, ch_map, gain_int, gain_frac);
    }

    uint8_t adc_1 = 0;
    uint8_t adc_2 = 0;
    uint8_t adc_3 = 0;

    uint32_t gain = (uint32_t)((float)adc_dig_gain_base * powf(10, gain_db / 20));

    if (gain > 0xFF) {
        gain = 0xFF;
    }

    if (ch_map & AUD_CH_MAP_CH_0) {
        adc_1 = 1;
    }
    if (ch_map & AUD_CH_MAP_CH_1) {
        adc_2 = 1;
    }
    if (ch_map & AUD_CH_MAP_CH_2) {
        adc_3 = 1;
    }

    PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->mic_gain),
        ((adc_1 * AIC1000AUD_AUD_CODEC_MIC_GAIN0(gain)) |
        (adc_2 * AIC1000AUD_AUD_CODEC_MIC_GAIN1(gain))  |
        (adc_3 * AIC1000AUD_AUD_CODEC_MIC_GAIN2(gain))),
        ((adc_1 * AIC1000AUD_AUD_CODEC_MIC_GAIN0(gain)) |
        (adc_2 * AIC1000AUD_AUD_CODEC_MIC_GAIN1(gain))  |
        (adc_3 * AIC1000AUD_AUD_CODEC_MIC_GAIN2(gain))));
}

void aic1000_adc_pga_gain_1_config(uint8_t ch_map, uint8_t gain)
{
    if (aic1000_dbg_mask & AIC1000_DBG_ADC_CFG) {
        TRACE("%s, ch_map:%X gain:%X\n", __func__, ch_map, gain);
    }

    bool adc_1 = false;
    bool adc_2 = false;
    bool adc_3 = false;

    if (ch_map & AUD_CH_MAP_CH_0) {
        switch (mic_matrix_tbl[mic_matrix_type][0]) {
        case 0:
            adc_1 = true;
            break;
        case 1:
            adc_2 = true;
            break;
        case 2:
            adc_3 = true;
            break;
        default:
            break;
        }
    }

    if (ch_map & AUD_CH_MAP_CH_1) {
        switch (mic_matrix_tbl[mic_matrix_type][1]) {
        case 0:
            adc_1 = true;
            break;
        case 1:
            adc_2 = true;
            break;
        case 2:
            adc_3 = true;
            break;
        default:
            break;
        }
    }

    if (ch_map & AUD_CH_MAP_CH_2) {
        switch (mic_matrix_tbl[mic_matrix_type][2]) {
        case 0:
            adc_1 = true;
            break;
        case 1:
            adc_2 = true;
            break;
        case 2:
            adc_3 = true;
            break;
        default:
            break;
        }
    }

    if (adc_1) {
        PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->abb_micpga_1),
            AIC1000AUD_AUD_CODEC_ABB_MICPGA_1_GAIN(gain),
            AIC1000AUD_AUD_CODEC_ABB_MICPGA_1_GAIN(0x3));
    }
    if (adc_2) {
        PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->abb_micpga_2),
            AIC1000AUD_AUD_CODEC_ABB_MICPGA_2_GAIN(gain),
            AIC1000AUD_AUD_CODEC_ABB_MICPGA_2_GAIN(0x3));
    }
    if (adc_3) {
        PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->abb_micpga_3),
            AIC1000AUD_AUD_CODEC_ABB_MICPGA_3_GAIN(gain),
            AIC1000AUD_AUD_CODEC_ABB_MICPGA_3_GAIN(0x3));
    }
}

void aic1000_adc_pga_gain_2_config(uint8_t ch_map, uint8_t gain)
{
    if (aic1000_dbg_mask & AIC1000_DBG_ADC_CFG) {
        TRACE("%s, ch_map:%X gain:%X\n", __func__, ch_map, gain);
    }

    bool adc_1 = false;
    bool adc_2 = false;
    bool adc_3 = false;

    if (ch_map & AUD_CH_MAP_CH_0) {
        switch (mic_matrix_tbl[mic_matrix_type][0]) {
        case 0:
            adc_1 = true;
            break;
        case 1:
            adc_2 = true;
            break;
        case 2:
            adc_3 = true;
            break;
        default:
            break;
        }
    }

    if (ch_map & AUD_CH_MAP_CH_1) {
        switch (mic_matrix_tbl[mic_matrix_type][1]) {
        case 0:
            adc_1 = true;
            break;
        case 1:
            adc_2 = true;
            break;
        case 2:
            adc_3 = true;
            break;
        default:
            break;
        }
    }

    if (ch_map & AUD_CH_MAP_CH_2) {
        switch (mic_matrix_tbl[mic_matrix_type][2]) {
        case 0:
            adc_1 = true;
            break;
        case 1:
            adc_2 = true;
            break;
        case 2:
            adc_3 = true;
            break;
        default:
            break;
        }
    }

    if (adc_1) {
        PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->abb_sdm_adc0),
            AIC1000AUD_AUD_CODEC_ABB_SDM_ADC_1_GAIN_BIT(gain),
            AIC1000AUD_AUD_CODEC_ABB_SDM_ADC_1_GAIN_BIT(0x7));
    }
    if (adc_2) {
        PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->abb_sdm_adc0),
            AIC1000AUD_AUD_CODEC_ABB_SDM_ADC_2_GAIN_BIT(gain),
            AIC1000AUD_AUD_CODEC_ABB_SDM_ADC_2_GAIN_BIT(0x7));
    }
    if (adc_3) {
        PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->abb_sdm_adc0),
            AIC1000AUD_AUD_CODEC_ABB_SDM_ADC_3_GAIN_BIT(gain),
            AIC1000AUD_AUD_CODEC_ABB_SDM_ADC_3_GAIN_BIT(0x7));
    }
}

void aic1000_adc_mic_bias_config(uint8_t bias)
{
    if (aic1000_dbg_mask & AIC1000_DBG_ADC_CFG) {
        TRACE("%s, bias:%X\n", __func__, bias);
    }

    PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->abb_micbias),
        AIC1000AUD_AUD_CODEC_ABB_MICBIAS_VBIT(bias),
        AIC1000AUD_AUD_CODEC_ABB_MICBIAS_VBIT(0x3));
}

void aic1000_adc_mic_cap_mode_config(uint8_t mode)
{
    if (aic1000_dbg_mask & AIC1000_DBG_ADC_CFG) {
        TRACE("%s, mode:%X\n", __func__, mode);
    }

    if (mode == AIC1000_MIC_NORMAL_MODE) {
        PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->abb_micpga_1),
            (0                                              |
            AIC1000AUD_AUD_CODEC_ABB_MICPGA_1_ICL_HPF_BIT   |
            AIC1000AUD_AUD_CODEC_ABB_MICPGA_1_INBIAS_N(0)   |
            AIC1000AUD_AUD_CODEC_ABB_MICPGA_1_INBIAS_P(0)),
            (AIC1000AUD_AUD_CODEC_ABB_MICPGA_1_ICL_MODE     |
            AIC1000AUD_AUD_CODEC_ABB_MICPGA_1_ICL_HPF_BIT   |
            AIC1000AUD_AUD_CODEC_ABB_MICPGA_1_INBIAS_N(0xF) |
            AIC1000AUD_AUD_CODEC_ABB_MICPGA_1_INBIAS_P(0xF)));
        PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->abb_micpga_2),
            (0                                              |
            AIC1000AUD_AUD_CODEC_ABB_MICPGA_2_ICL_HPF_BIT   |
            AIC1000AUD_AUD_CODEC_ABB_MICPGA_2_INBIAS_N(0)   |
            AIC1000AUD_AUD_CODEC_ABB_MICPGA_2_INBIAS_P(0)),
            (AIC1000AUD_AUD_CODEC_ABB_MICPGA_2_ICL_MODE     |
            AIC1000AUD_AUD_CODEC_ABB_MICPGA_2_ICL_HPF_BIT   |
            AIC1000AUD_AUD_CODEC_ABB_MICPGA_2_INBIAS_N(0xF) |
            AIC1000AUD_AUD_CODEC_ABB_MICPGA_2_INBIAS_P(0xF)));
        PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->abb_micpga_3),
            (0                                              |
            AIC1000AUD_AUD_CODEC_ABB_MICPGA_3_ICL_HPF_BIT   |
            AIC1000AUD_AUD_CODEC_ABB_MICPGA_3_INBIAS_N(0)   |
            AIC1000AUD_AUD_CODEC_ABB_MICPGA_3_INBIAS_P(0)),
            (AIC1000AUD_AUD_CODEC_ABB_MICPGA_3_ICL_MODE     |
            AIC1000AUD_AUD_CODEC_ABB_MICPGA_3_ICL_HPF_BIT   |
            AIC1000AUD_AUD_CODEC_ABB_MICPGA_3_INBIAS_N(0xF) |
            AIC1000AUD_AUD_CODEC_ABB_MICPGA_3_INBIAS_P(0xF)));
        PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->ana_clk1),
            (AIC1000AUD_AUD_CODEC_CDIV_MIC_PGA(1)           |
            0),
            (AIC1000AUD_AUD_CODEC_CDIV_MIC_PGA(0x7)         |
            AIC1000AUD_AUD_CODEC_CGEN_MIC_PGA));
    } else {
        PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->abb_micpga_1),
            (AIC1000AUD_AUD_CODEC_ABB_MICPGA_1_ICL_MODE     |
            AIC1000AUD_AUD_CODEC_ABB_MICPGA_1_ICL_HPF_BIT   |
            AIC1000AUD_AUD_CODEC_ABB_MICPGA_1_INBIAS_N(2)   |
            AIC1000AUD_AUD_CODEC_ABB_MICPGA_1_INBIAS_P(1)),
            (AIC1000AUD_AUD_CODEC_ABB_MICPGA_1_ICL_MODE     |
            AIC1000AUD_AUD_CODEC_ABB_MICPGA_1_ICL_HPF_BIT   |
            AIC1000AUD_AUD_CODEC_ABB_MICPGA_1_INBIAS_N(0xF) |
            AIC1000AUD_AUD_CODEC_ABB_MICPGA_1_INBIAS_P(0xF)));
        PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->abb_micpga_2),
            (AIC1000AUD_AUD_CODEC_ABB_MICPGA_2_ICL_MODE     |
            AIC1000AUD_AUD_CODEC_ABB_MICPGA_2_ICL_HPF_BIT   |
            AIC1000AUD_AUD_CODEC_ABB_MICPGA_2_INBIAS_N(2)   |
            AIC1000AUD_AUD_CODEC_ABB_MICPGA_2_INBIAS_P(1)),
            (AIC1000AUD_AUD_CODEC_ABB_MICPGA_2_ICL_MODE     |
            AIC1000AUD_AUD_CODEC_ABB_MICPGA_2_ICL_HPF_BIT   |
            AIC1000AUD_AUD_CODEC_ABB_MICPGA_2_INBIAS_N(0xF) |
            AIC1000AUD_AUD_CODEC_ABB_MICPGA_2_INBIAS_P(0xF)));
        PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->abb_micpga_3),
            (AIC1000AUD_AUD_CODEC_ABB_MICPGA_3_ICL_MODE     |
            AIC1000AUD_AUD_CODEC_ABB_MICPGA_3_ICL_HPF_BIT   |
            AIC1000AUD_AUD_CODEC_ABB_MICPGA_3_INBIAS_N(2)   |
            AIC1000AUD_AUD_CODEC_ABB_MICPGA_3_INBIAS_P(1)),
            (AIC1000AUD_AUD_CODEC_ABB_MICPGA_3_ICL_MODE     |
            AIC1000AUD_AUD_CODEC_ABB_MICPGA_3_ICL_HPF_BIT   |
            AIC1000AUD_AUD_CODEC_ABB_MICPGA_3_INBIAS_N(0xF) |
            AIC1000AUD_AUD_CODEC_ABB_MICPGA_3_INBIAS_P(0xF)));
        PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->ana_clk1),
            (AIC1000AUD_AUD_CODEC_CDIV_MIC_PGA(1)           |
            AIC1000AUD_AUD_CODEC_CGEN_MIC_PGA),
            (AIC1000AUD_AUD_CODEC_CDIV_MIC_PGA(0x7)         |
            AIC1000AUD_AUD_CODEC_CGEN_MIC_PGA));
    }
}

void aic1000_adc_mic_signal_mode_config(uint8_t mode)
{
    if (aic1000_dbg_mask & AIC1000_DBG_ADC_CFG) {
        TRACE("%s, mode:%X\n", __func__, mode);
    }

    if (mode == AIC1000_MIC_SE_MODE) {
        PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->abb_micpga_1),
            AIC1000AUD_AUD_CODEC_ABB_MICPGA_1_INSEL(0x12),
            AIC1000AUD_AUD_CODEC_ABB_MICPGA_1_INSEL(0x3F));

        PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->abb_micpga_2),
            AIC1000AUD_AUD_CODEC_ABB_MICPGA_2_INSEL(0x12),
            AIC1000AUD_AUD_CODEC_ABB_MICPGA_2_INSEL(0x3F));

        PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->abb_micpga_3),
            AIC1000AUD_AUD_CODEC_ABB_MICPGA_3_INSEL(0x12),
            AIC1000AUD_AUD_CODEC_ABB_MICPGA_3_INSEL(0x3F));
    } else {
        PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->abb_micpga_1),
            AIC1000AUD_AUD_CODEC_ABB_MICPGA_1_INSEL(0x03),
            AIC1000AUD_AUD_CODEC_ABB_MICPGA_1_INSEL(0x3F));

        PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->abb_micpga_2),
            AIC1000AUD_AUD_CODEC_ABB_MICPGA_2_INSEL(0x03),
            AIC1000AUD_AUD_CODEC_ABB_MICPGA_2_INSEL(0x3F));

        PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->abb_micpga_3),
            AIC1000AUD_AUD_CODEC_ABB_MICPGA_3_INSEL(0x03),
            AIC1000AUD_AUD_CODEC_ABB_MICPGA_3_INSEL(0x3F));
    }
}

void aic1000_dac_dig_gain_base_config(uint8_t gain)
{
    if (aic1000_dbg_mask & AIC1000_DBG_DAC_CFG) {
        TRACE("%s, gain:%X\n", __func__, gain);
    }

    dac_dig_gain_base = gain;
}

void aic1000_dac_dig_gain_config(uint8_t ch_map, uint16_t gain)
{
    if (aic1000_dbg_mask & AIC1000_DBG_DAC_CFG) {
        TRACE("%s, ch_map:%X gain:%X\n", __func__, ch_map, gain);
    }

    uint8_t l = 0;
    uint8_t r = 0;

    if (gain > 0x7FFF) {
        gain = 0x7FFF;
    }

    if (ch_map & AUD_CH_MAP_CH_0) {
        l = 1;
    }
    if (ch_map & AUD_CH_MAP_CH_1) {
        r = 1;
    }

    PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->spk_gain),
        ((l * AIC1000AUD_AUD_CODEC_SPK_GAIN0(gain))  |
        (r * AIC1000AUD_AUD_CODEC_SPK_GAIN1(gain))),
        ((l * AIC1000AUD_AUD_CODEC_SPK_GAIN0(0x7FFF)) |
        (r * AIC1000AUD_AUD_CODEC_SPK_GAIN1(0x7FFF))));
}

void aic1000_dac_dig_gain_db_config(uint8_t ch_map, float gain_db)
{
    if (aic1000_dbg_mask & AIC1000_DBG_DAC_CFG) {
        int gain_int = (int)gain_db;
        int gain_frac = (int)((gain_db - gain_int) * 10);
        if (gain_frac < 0) {
            gain_frac = -gain_frac;
        }
        TRACE("%s, ch_map:%X gain_db:%d.%d\n", __func__, ch_map, gain_int, gain_frac);
    }

    uint8_t l = 0;
    uint8_t r = 0;

    uint32_t gain = (uint32_t)((float)dac_dig_gain_base * powf(10, gain_db / 20));

    if (gain > 0x7FFF) {
        gain = 0x7FFF;
    }

    if (ch_map & AUD_CH_MAP_CH_0) {
        l = 1;
    }
    if (ch_map & AUD_CH_MAP_CH_1) {
        r = 1;
    }

    PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->spk_gain),
        ((l * AIC1000AUD_AUD_CODEC_SPK_GAIN0(gain))  |
        (r * AIC1000AUD_AUD_CODEC_SPK_GAIN1(gain))),
        ((l * AIC1000AUD_AUD_CODEC_SPK_GAIN0(0x7FFF)) |
        (r * AIC1000AUD_AUD_CODEC_SPK_GAIN1(0x7FFF))));
}

//11 for DIFF mode, 5 for SE mode.
void aic1000_dac_gain1_config(uint8_t gain)
{
    if (aic1000_dbg_mask & AIC1000_DBG_DAC_CFG) {
        TRACE("%s, gain:%X\n", __func__, gain);
    }

    PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->abb_sdm_dac1),
        AIC1000AUD_AUD_CODEC_ABB_SDM_DAC_GAIN_BIT1(gain),
        AIC1000AUD_AUD_CODEC_ABB_SDM_DAC_GAIN_BIT1(0xF));
}

//10 for DIFF mode, 11 for SE mode.
void aic1000_dac_gain2_config(uint8_t gain)
{
    if (aic1000_dbg_mask & AIC1000_DBG_DAC_CFG) {
        TRACE("%s, gain:%X\n", __func__, gain);
    }

    PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->abb_sdm_dac1),
        AIC1000AUD_AUD_CODEC_ABB_SDM_DAC_GAIN_BIT2(gain),
        AIC1000AUD_AUD_CODEC_ABB_SDM_DAC_GAIN_BIT2(0xF));
}

void aic1000_dac_hp_gain_config(uint8_t ch_map, uint8_t gain)
{
    if (aic1000_dbg_mask & AIC1000_DBG_DAC_CFG) {
        TRACE("%s, ch_map:%X gain:%X\n", __func__, ch_map, gain);
    }

    uint8_t l = 0;
    uint8_t r = 0;

    if (gain > 0x07) {
        gain = 0x07;
    }

    if (ch_map & AUD_CH_MAP_CH_0) {
        l = 1;
    }
    if (ch_map & AUD_CH_MAP_CH_1) {
        r = 1;
    }

    if (l) {
        PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->abb_hp_l),
            AIC1000AUD_AUD_CODEC_ABB_HP_L_GAIN_BIT(gain),
            AIC1000AUD_AUD_CODEC_ABB_HP_L_GAIN_BIT(0x07));
    }
    if (r) {
        PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->abb_hp_r),
            AIC1000AUD_AUD_CODEC_ABB_HP_R_GAIN_BIT(gain),
            AIC1000AUD_AUD_CODEC_ABB_HP_R_GAIN_BIT(0x07));
    }
}

void aic1000_dac_hp_signal_mode_config(uint8_t mode)
{
    if (aic1000_dbg_mask & AIC1000_DBG_DAC_CFG) {
        TRACE("%s, mode:%X\n", __func__, mode);
    }

    if (mode == AIC1000_HP_SE_MODE) {
        PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->abb_hp_l),
            (AIC1000AUD_AUD_CODEC_ABB_HP_L_VREFC_EN |
            AIC1000AUD_AUD_CODEC_ABB_HP_L_SE_MODE   |
            0),
            (AIC1000AUD_AUD_CODEC_ABB_HP_L_VREFC_EN |
            AIC1000AUD_AUD_CODEC_ABB_HP_L_SE_MODE   |
            AIC1000AUD_AUD_CODEC_ABB_HP_L_DIFF_MODE));
        PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->abb_hp_r),
            (AIC1000AUD_AUD_CODEC_ABB_HP_R_VREFC_EN |
            AIC1000AUD_AUD_CODEC_ABB_HP_R_SE_MODE   |
            0),
            (AIC1000AUD_AUD_CODEC_ABB_HP_R_VREFC_EN |
            AIC1000AUD_AUD_CODEC_ABB_HP_R_SE_MODE   |
            AIC1000AUD_AUD_CODEC_ABB_HP_R_DIFF_MODE));
    } else {
        PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->abb_hp_l),
            (0                                      |
            0                                       |
            AIC1000AUD_AUD_CODEC_ABB_HP_L_DIFF_MODE),
            (AIC1000AUD_AUD_CODEC_ABB_HP_L_VREFC_EN |
            AIC1000AUD_AUD_CODEC_ABB_HP_L_SE_MODE   |
            AIC1000AUD_AUD_CODEC_ABB_HP_L_DIFF_MODE));
        PMIC_MEM_MASK_WRITE((unsigned int)&(aic1000audAudCodec->abb_hp_r),
            (0                                      |
            0                                       |
            AIC1000AUD_AUD_CODEC_ABB_HP_R_DIFF_MODE),
            (AIC1000AUD_AUD_CODEC_ABB_HP_R_VREFC_EN |
            AIC1000AUD_AUD_CODEC_ABB_HP_R_SE_MODE   |
            AIC1000AUD_AUD_CODEC_ABB_HP_R_DIFF_MODE));
    }
}

