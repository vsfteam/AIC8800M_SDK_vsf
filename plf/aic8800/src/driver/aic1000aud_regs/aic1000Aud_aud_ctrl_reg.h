#ifndef _AIC1000AUD_AUD_CTRL_REG_H_
#define _AIC1000AUD_AUD_CTRL_REG_H_

#include "chip.h"

// =============================================================================
//  MACROS
// =============================================================================

// =============================================================================
//  TYPES
// =============================================================================

// ============================================================================
// AIC1000AUD_AUD_CTRL_REG_T
// -----------------------------------------------------------------------------
///
// =============================================================================
#define REG_AIC1000AUD_AUD_CTRL_REG_BASE 0x5001DC00

typedef struct {
    __IO uint32_t                          aud_clk_ctrl0;                //0x00000000
    __IO uint32_t                          aud_clk_ctrl1;                //0x00000004
    __IO uint32_t                          aud_rstn_ctrl;                //0x00000008
    __IO uint32_t                          aud_pll_cfg0;                 //0x0000000C
    __IO uint32_t                          aud_pll_cfg1;                 //0x00000010
    __IO uint32_t                          aud_pll_cfg2;                 //0x00000014
} HWP_AIC1000AUD_AUD_CTRL_REG_T;

static HWP_AIC1000AUD_AUD_CTRL_REG_T* const aic1000audAudCtrlReg =  ((HWP_AIC1000AUD_AUD_CTRL_REG_T*)REG_AIC1000AUD_AUD_CTRL_REG_BASE);

//aud_clk_ctrl0
#define AIC1000AUD_AUD_CTRL_REG_I_REG_AUDIO_CLK_MANUAL_ENABLE(n) (((n)&0x3FF)<<0)
#define AIC1000AUD_AUD_CTRL_REG_I_REG_AUDIO_CLK_MODE(n) (((n)&0x3FF)<<10)
#define AIC1000AUD_AUD_CTRL_REG_I_REG_AUD_CLK_DIV_SEL (1<<20)
#define AIC1000AUD_AUD_CTRL_REG_I_REG_AUD_VAD_CLK_DIV_SEL (1<<21)
#define AIC1000AUD_AUD_CTRL_REG_I_REG_AUD_PLL_CLK_SEL (1<<22)
#define AIC1000AUD_AUD_CTRL_REG_I_REG_CLK_AUPLL2DIG_12M_GATE_EN (1<<23)
#define AIC1000AUD_AUD_CTRL_REG_I_REG_CLK_AUPLL2DIG_24M_GATE_EN (1<<24)
#define AIC1000AUD_AUD_CTRL_REG_I_REG_CLK_AUPLL2DIG_96M_GATE_EN (1<<25)
#define AIC1000AUD_AUD_CTRL_REG_I_REG_CLK_DAC_ANA_INV (1<<26)
#define AIC1000AUD_AUD_CTRL_REG_I_REG_CLK_ADC_ANA_INV (1<<27)
#define AIC1000AUD_AUD_CTRL_REG_AUD_ANC_VAD_RAM_SEL (1<<28)
#define AIC1000AUD_AUD_CTRL_REG_I_REG_MCLK_DIV_GATE_EN (1<<29)
#define AIC1000AUD_AUD_CTRL_REG_I_REG_CLK_VAD_DIG_SEL (1<<30)
#define AIC1000AUD_AUD_CTRL_REG_I_REG_CLK_VAD_DIG_INV (1<<31)

//aud_clk_ctrl1
#define AIC1000AUD_AUD_CTRL_REG_I_REG_AUD_ANC_CLK_GATE0_BYPASS (1<<0)
#define AIC1000AUD_AUD_CTRL_REG_I_REG_AUD_ANC_CLK_GATE1_BYPASS (1<<1)
#define AIC1000AUD_AUD_CTRL_REG_I_REG_AUDIO_PLL_DIV_DENOM(n) (((n)&0x3F)<<2)
#define AIC1000AUD_AUD_CTRL_REG_I_REG_AUDIO_PLL_DIV_UPDATE (1<<8)
#define AIC1000AUD_AUD_CTRL_REG_I_REG_AUDIO_6P5M_DIV_DENOM(n) (((n)&0xFF)<<9)
#define AIC1000AUD_AUD_CTRL_REG_I_REG_AUDIO_6P5M_DIV_UPDATE (1<<17)
#define AIC1000AUD_AUD_CTRL_REG_I_REG_AUDIO_MCLK_DIV_DENOM(n) (((n)&0xFF)<<18)
#define AIC1000AUD_AUD_CTRL_REG_I_REG_AUDIO_MCLK_DIV_UPDATE (1<<26)
#define AIC1000AUD_AUD_CTRL_REG_I_REG_AUD_6P5M_CLK_SEL (1<<27)
#define AIC1000AUD_AUD_CTRL_REG_I_REG_CLK_ADC_ANA_SEL (1<<28)
#define AIC1000AUD_AUD_CTRL_REG_I_REG_CLK_AUD_26M_GATE_EN (1<<29)
#define AIC1000AUD_AUD_CTRL_REG_I_REG_CLK_AUD_6P5M_GATE_EN (1<<30)
#define AIC1000AUD_AUD_CTRL_REG_I_REG_CODEC_PCLK_AON (1<<31)

//aud_rstn_ctrl
#define AIC1000AUD_AUD_CTRL_REG_CFG_PCLK_SOFT_RESETN(n) (((n)&0xFF)<<0)
#define AIC1000AUD_AUD_CTRL_REG_CFG_AUDIO_CLK_SOFT_RESETN(n) (((n)&0xFF)<<8)
#define AIC1000AUD_AUD_CTRL_REG_I_REG_CLK_TPORTS_SEL(n) (((n)&15)<<16)
#define AIC1000AUD_AUD_CTRL_REG_I_REG_CLK_VAD_DIV_TH(n) (((n)&0x3F)<<20)

//aud_pll_cfg0
#define AIC1000AUD_AUD_CTRL_REG_CFG_PU_AUPLL (1<<0)
#define AIC1000AUD_AUD_CTRL_REG_CFG_AUPLL_SDM_CLK_SEL (1<<1)
#define AIC1000AUD_AUD_CTRL_REG_CFG_AUPLL_CLK96M_EN (1<<2)
#define AIC1000AUD_AUD_CTRL_REG_CFG_AUPLL_BAND_SEL (1<<3)
#define AIC1000AUD_AUD_CTRL_REG_CFG_AUPLL_REF_MULTI2_EN (1<<4)
#define AIC1000AUD_AUD_CTRL_REG_CFG_AUPLL_PFD_RST_DLY_BIT(n) (((n)&7)<<5)
#define AIC1000AUD_AUD_CTRL_REG_CFG_AUPLL_CLK12M_EN (1<<8)
#define AIC1000AUD_AUD_CTRL_REG_CFG_AUPLL_REG_VBIT(n) (((n)&15)<<9)
#define AIC1000AUD_AUD_CTRL_REG_CFG_AUPLL_CP_IBIT(n) (((n)&7)<<13)
#define AIC1000AUD_AUD_CTRL_REG_CFG_AUPLL_PCON_MODEB (1<<16)
#define AIC1000AUD_AUD_CTRL_REG_CFG_AUPLL_LOCK (1<<17)
#define AIC1000AUD_AUD_CTRL_REG_CFG_AUPLL_CLK24M_EN (1<<21)
#define AIC1000AUD_AUD_CTRL_REG_CFG_AUPLL_TEST_EN (1<<22)
#define AIC1000AUD_AUD_CTRL_REG_CFG_AUPLL_PU_BIT(n) (((n)&3)<<23)
#define AIC1000AUD_AUD_CTRL_REG_CFG_AUPLL_DIV_SEL(n) (((n)&3)<<25)

//aud_pll_cfg1
#define AIC1000AUD_AUD_CTRL_REG_CFG_AUDPLL_SDM_FREQ_CFG(n) (((n)&0xFFFFFFF)<<0)
#define AIC1000AUD_AUD_CTRL_REG_CFG_AUDPLL_SDM_FREQ_TOGGLE (1<<31)

//aud_pll_cfg2
#define AIC1000AUD_AUD_CTRL_REG_CFG_AUDPLL_SDM_DITHER_BYPASS (1<<0)
#define AIC1000AUD_AUD_CTRL_REG_CFG_AUDPLL_SDM_INTDEC_SEL(n) (((n)&7)<<1)
#define AIC1000AUD_AUD_CTRL_REG_CFG_AUDPLL_SDM_SS_EN (1<<12)
#define AIC1000AUD_AUD_CTRL_REG_CFG_AUDPLL_SDM_AMP_CT(n) (((n)&7)<<13)
#define AIC1000AUD_AUD_CTRL_REG_CFG_AUDPLL_SDM_CYC_CT(n) (((n)&3)<<16)

#endif
