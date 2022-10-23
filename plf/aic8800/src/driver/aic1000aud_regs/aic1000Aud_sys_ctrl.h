#ifndef _AIC1000AUD_SYS_CTRL_H_
#define _AIC1000AUD_SYS_CTRL_H_

#include "chip.h"

// =============================================================================
//  MACROS
// =============================================================================

// =============================================================================
//  TYPES
// =============================================================================

// =============================================================================
// AIC1000AUD_SYS_CTRL_T
// -----------------------------------------------------------------------------
///
// =============================================================================
#define REG_AIC1000AUD_SYSCTRL_BASE 0x50010000

typedef struct {
    __IO uint32_t               CHIP_ID;                    //0x00000000
    __IO uint32_t               clk_sel;                    //0x00000004
    __IO uint32_t               pclk_ctrl_mode;             //0x00000008
    __IO uint32_t               others_clk_ctrl_mode;       //0x0000000C
    __IO uint32_t               pclk_div;                   //0x00000010
    __IO uint32_t               msadc_clk_div;              //0x00000014
    __IO uint32_t               TOUCH_CTRL;                 //0x00000018
    __IO uint32_t               dcdc_ref_clk_div;           //0x0000001C
    __IO uint32_t               dcdc_ref_clk_ctrl0;         //0x00000020
    __IO uint32_t               dcdc_ref_clk_ctrl1;         //0x00000024
    __IO uint32_t               TPORTS_SEL;                 //0x00000028
    __IO uint32_t               MEM_CFG;                    //0x0000002C
    __IO uint32_t               TPORTS_SEL_2;               //0x00000030
} HWP_AIC1000AUD_SYS_CTRL_T;

static HWP_AIC1000AUD_SYS_CTRL_T * const aic1000audSysctrl = ((HWP_AIC1000AUD_SYS_CTRL_T *)REG_AIC1000AUD_SYSCTRL_BASE);


//CHIP_ID
#define AIC1000AUD_SYS_CTRL_CHIP_ID(n) (((n)&0xFFFF)<<0)
#define AIC1000AUD_SYS_CTRL_METAL_ID(n) (((n)&0xFF)<<16)
#define AIC1000AUD_SYS_CTRL_BOND_ID(n) (((n)&15)<<24)
#define AIC1000AUD_SYS_CTRL_REV_ID(n) (((n)&15)<<28)

//clk_sel
#define AIC1000AUD_SYS_CTRL_CFG_FAST_HWEN (1<<0)
#define AIC1000AUD_SYS_CTRL_CFG_FAST_CLK_SEL (1<<1)
#define AIC1000AUD_SYS_CTRL_CFG_CLK_PWM_SEL (1<<2)
#define AIC1000AUD_SYS_CTRL_CFG_CLK_MSADC_INV_ANA (1<<3)
#define AIC1000AUD_SYS_CTRL_CFG_CLK_26M_SEL (1<<4)

//pclk_ctrl_mode
#define AIC1000AUD_SYS_CTRL_CFG_PCLK_MODE(n) (((n)&0xFFFFFFFF)<<0)

//others_clk_ctrl_mode
#define AIC1000AUD_SYS_CTRL_CFG_OTHERS_CLK_MODE(n) (((n)&0xFFFF)<<0)

//pclk_div
#define AIC1000AUD_SYS_CTRL_CFG_PCLK_DIV_DENOM(n) (((n)&0xFF)<<0)
#define AIC1000AUD_SYS_CTRL_CFG_PCLK_DIV_UPDATE (1<<8)

//msadc_clk_div
#define AIC1000AUD_SYS_CTRL_CFG_CLK_MSADC_DIV_DENOM(n) (((n)&0xFF)<<0)
#define AIC1000AUD_SYS_CTRL_CFG_CLK_MSADC_DIV_UPDATE (1<<8)

//TOUCH_CTRL
#define AIC1000AUD_SYS_CTRL_CFG_CLK_TOUCH_DIV_MODE(n) (((n)&3)<<0)

//dcdc_ref_clk_div
#define AIC1000AUD_SYS_CTRL_CFG_DCDC_REF_CLK_DIV_DENOM(n) (((n)&0xFF)<<0)
#define AIC1000AUD_SYS_CTRL_CFG_DCDC_REF_CLK_DIV_UPDATA (1<<8)
#define AIC1000AUD_SYS_CTRL_CFG_DCDC_RF_TX_ON_EN (1<<9)
#define AIC1000AUD_SYS_CTRL_CFG_DCDC_RF_RX_ON_EN (1<<10)
#define AIC1000AUD_SYS_CTRL_CFG_DCDC_PU_MDLL_EN (1<<11)
#define AIC1000AUD_SYS_CTRL_CFG_DCDC_REF_CLK_DIV_DENOM_EXT(n) (((n)&0xFF)<<12)

//dcdc_ref_clk_ctrl0
#define AIC1000AUD_SYS_CTRL_CFG_DCDC_REF_CLK_TRIANGLE_CYCLE(n) (((n)&0xFFFF)<<0)
#define AIC1000AUD_SYS_CTRL_CFG_DCDC_REF_CLK_TRIANGLE_AMP(n) (((n)&3)<<16)
#define AIC1000AUD_SYS_CTRL_CFG_DCDC_REF_CLK_TRIANGLE_EN (1<<18)

//dcdc_ref_clk_ctrl1
#define AIC1000AUD_SYS_CTRL_CFG_DCDC_RF_OFFSET(n) (((n)&15)<<0)
#define AIC1000AUD_SYS_CTRL_CFG_DCDC_PA_OFFSET(n) (((n)&15)<<4)
#define AIC1000AUD_SYS_CTRL_CFG_DCDC_CORE_OFFSET(n) (((n)&15)<<8)
#define AIC1000AUD_SYS_CTRL_CFG_DCDC_RF_CLK_EN (1<<12)
#define AIC1000AUD_SYS_CTRL_CFG_DCDC_PA_CLK_EN (1<<13)
#define AIC1000AUD_SYS_CTRL_CFG_DCDC_CORE_CLK_EN (1<<14)
#define AIC1000AUD_SYS_CTRL_CFG_DCDC_RF_CLK_HWEN (1<<15)
#define AIC1000AUD_SYS_CTRL_CFG_DCDC_PA_CLK_HWEN (1<<16)
#define AIC1000AUD_SYS_CTRL_CFG_DCDC_CORE_CLK_HWEN (1<<17)
#define AIC1000AUD_SYS_CTRL_CFG_DCDC_RF_DIV(n) (((n)&3)<<18)
#define AIC1000AUD_SYS_CTRL_CFG_DCDC_PA_DIV(n) (((n)&3)<<20)
#define AIC1000AUD_SYS_CTRL_CFG_DCDC_CORE_DIV(n) (((n)&3)<<22)

//TPORTS_SEL
#define AIC1000AUD_SYS_CTRL_CFG_TOP_TPORTS_SEL(n) (((n)&0xFF)<<0)
#define AIC1000AUD_SYS_CTRL_CFG_CLK_TPORTS_SEL(n) (((n)&15)<<8)

//MEM_CFG
#define AIC1000AUD_SYS_CTRL_CFG_MEM(n) (((n)&0xFFFF)<<0)

//TPORTS_SEL_2
#define AIC1000AUD_SYS_CTRL_CFG_TOP_TPORTS_SEL_2(n) (((n)&0xFFFFFFFF)<<0)

#endif
