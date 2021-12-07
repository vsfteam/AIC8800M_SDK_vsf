#ifndef _AIC1000LITE_SYS_CTRL_H_
#define _AIC1000LITE_SYS_CTRL_H_

#include "chip.h"

// =============================================================================
//  MACROS
// =============================================================================

// =============================================================================
//  TYPES
// =============================================================================

// ============================================================================
// AIC1000LITE_SYS_CTRL_T
// -----------------------------------------------------------------------------
///
// =============================================================================
#define REG_AIC1000LITE_SYSCTRL_BASE 0x50010000

typedef volatile struct
{
    __IO uint32_t                          chip_id;                      //0x00000000
    __IO uint32_t                          clk_sel;                      //0x00000004
    __IO uint32_t                          hclk_ctrl_mode;               //0x00000008
    __IO uint32_t                          others_clk_ctrl_mode;         //0x0000000C
    __IO uint32_t                          hclk_div;                     //0x00000010
    __IO uint32_t                          msadc_clk_div;                //0x00000014
    __IO uint32_t                          cfg_mem_sram;                 //0x00000018
    __IO uint32_t                          cfg_usb_ctrl;                 //0x0000001C
    __IO uint32_t                          cfg_det_sdio_ctrl0;           //0x00000020
    __IO uint32_t                          cfg_det_sdio_ctrl1;           //0x00000024
    __IO uint32_t                          cfg_det_sdio_ctrl2;           //0x00000028
    __IO uint32_t                          cfg_det_sdio_int_status;      //0x0000002C
    __IO uint32_t                          MISC_CTRL;                    //0x00000030
    __IO uint32_t                          TOUCH_CTRL;                   //0x00000034
    __IO uint32_t                          UART_DET;                     //0x00000038
    __IO uint32_t                          cfg_int_raw;                  //0x0000003C
    __IO uint32_t                          cfg_int_status;               //0x00000040
    __IO uint32_t                          cfg_int_mask;                 //0x00000044
    __IO uint32_t                          cfg_mdll128_cal;              //0x00000048
    __IO uint32_t                          cfg_mdll128_cal_result;       //0x0000004C
    __IO uint32_t                          cfg_mdll128_cal_busy;         //0x00000050
    __IO uint32_t                          mclk_div;                     //0x00000054
    __IO uint32_t                          dcdc_ref_clk_div;             //0x00000058
    __IO uint32_t                          dcdc_ref_clk_ctrl0;           //0x0000005C
    __IO uint32_t                          dcdc_ref_clk_ctrl1;           //0x00000060
    __IO uint32_t                          UART_DET_FILTER;              //0x00000064
    __IO uint32_t                          TPORTS_SEL;                   //0x00000068
} HWP_AIC1000LITE_SYS_CTRL_T;

static HWP_AIC1000LITE_SYS_CTRL_T * const aic1000liteSysctrl = ((HWP_AIC1000LITE_SYS_CTRL_T *)REG_AIC1000LITE_SYSCTRL_BASE);


//chip_id
#define AIC1000LITE_SYS_CTRL_CHIP_ID(n) (((n)&0xFFFF)<<0)
#define AIC1000LITE_SYS_CTRL_METAL_ID(n) (((n)&0xFF)<<16)
#define AIC1000LITE_SYS_CTRL_BOND_ID(n) (((n)&0xFF)<<24)

//clk_sel
#define AIC1000LITE_SYS_CTRL_CFG_FAST_HWEN (1<<0)
#define AIC1000LITE_SYS_CTRL_CFG_FAST_CLK_SEL (1<<1)
#define AIC1000LITE_SYS_CTRL_CFG_CLK_PWM_SEL (1<<2)
#define AIC1000LITE_SYS_CTRL_CFG_CLK_MSADC_SEL (1<<3)
#define AIC1000LITE_SYS_CTRL_CFG_CLK_MSADC_INV_ANA (1<<4)
#define AIC1000LITE_SYS_CTRL_CFG_52M_HWEN (1<<5)
#define AIC1000LITE_SYS_CTRL_CFG_52M_CLK_EN (1<<6)
#define AIC1000LITE_SYS_CTRL_CFG_LPO13M_HWEN (1<<7)
#define AIC1000LITE_SYS_CTRL_CFG_LPO13M_CLK_EN (1<<8)

//hclk_ctrl_mode
#define AIC1000LITE_SYS_CTRL_CFG_HCLK_MODE(n) (((n)&0xFFFFFFFF)<<0)

//others_clk_ctrl_mode
#define AIC1000LITE_SYS_CTRL_CFG_OTHERS_CLK_MODE(n) (((n)&0xFFFF)<<0)

//hclk_div
#define AIC1000LITE_SYS_CTRL_CFG_HCLK_DIV_DENOM(n) (((n)&0xFF)<<0)
#define AIC1000LITE_SYS_CTRL_CFG_HCLK_DIV_UPDATE (1<<8)

//msadc_clk_div
#define AIC1000LITE_SYS_CTRL_CFG_CLK_MSADC_DIV_DENOM(n) (((n)&0xFF)<<0)
#define AIC1000LITE_SYS_CTRL_CFG_CLK_MSADC_DIV_UPDATE (1<<8)

//cfg_mem_sram
#define AIC1000LITE_SYS_CTRL_CFG_MEM_SRAM(n) (((n)&0xFFFF)<<0)

//cfg_usb_ctrl
#define AIC1000LITE_SYS_CTRL_CFG_USB_CTRL(n) (((n)&0x7FFFFFFF)<<0)
#define AIC1000LITE_SYS_CTRL_RO_ANA_USB_LOCK (1<<31)

//cfg_det_sdio_ctrl0
#define AIC1000LITE_SYS_CTRL_CFG_DET_SDIO_TRIG_CMD_ARGUMENT(n) (((n)&0xFFFFFFFF)<<0)

//cfg_det_sdio_ctrl1
#define AIC1000LITE_SYS_CTRL_CFG_DET_SDIO_TRIG_CMD_ARGUMENT_MASK(n) (((n)&0xFFFFFFFF)<<0)

//cfg_det_sdio_ctrl2
#define AIC1000LITE_SYS_CTRL_CFG_DET_SDIO_INT_EN (1<<0)
#define AIC1000LITE_SYS_CTRL_CFG_DET_SDIO_CLEAR_SD_INT_TO_DEV (1<<1)
#define AIC1000LITE_SYS_CTRL_CFG_DET_SDIO_CMD_EDGE_SEL (1<<2)
#define AIC1000LITE_SYS_CTRL_CFG_DET_SDIO_DEV_IND (1<<3)
#define AIC1000LITE_SYS_CTRL_CFG_DET_SDIO_FUNCTION_ENABLE_REG(n) (((n)&3)<<4)
#define AIC1000LITE_SYS_CTRL_CFG_DET_SDIO_TRIG_CMD_IDEX(n) (((n)&0x3F)<<6)
#define AIC1000LITE_SYS_CTRL_CFG_DET_SDIO_MON_SEL(n) (((n)&3)<<12)
#define AIC1000LITE_SYS_CTRL_CFG_DET_SDIO_PWR_ON (1<<14)
#define AIC1000LITE_SYS_CTRL_CFG_DET_SDIO_PWR_ON_UPDATE (1<<15)

//cfg_det_sdio_int_status
#define AIC1000LITE_SYS_CTRL_RO_DET_SDIO_INT_STATUS(n) (((n)&0xFF)<<0)
#define AIC1000LITE_SYS_CTRL_RO_DET_SDIO_ULINK_HOST_ACK (1<<8)

//MISC_CTRL
#define AIC1000LITE_SYS_CTRL_CFG_USB_IO_USED_FOR_GPIO (1<<0)

//TOUCH_CTRL
#define AIC1000LITE_SYS_CTRL_CFG_CLK_TOUCH_DIV_MODE(n) (((n)&3)<<0)

//UART_DET
#define AIC1000LITE_SYS_CTRL_CFG_UART_DET_TIMEOUT_TH(n) (((n)&0x3FFFFF)<<0)
#define AIC1000LITE_SYS_CTRL_CFG_UART_DET_TH(n) (((n)&0xFF)<<22)
#define AIC1000LITE_SYS_CTRL_CFG_UART_DET_EN (1<<30)

//cfg_int_raw
#define AIC1000LITE_SYS_CTRL_INT_RAW (1<<0)

//cfg_int_status
#define AIC1000LITE_SYS_CTRL_INT_STATUS (1<<0)

//cfg_int_mask
#define AIC1000LITE_SYS_CTRL_CFG_INT_MASK (1<<0)

//cfg_mdll128_cal
#define AIC1000LITE_SYS_CTRL_CFG_CAL_RG_CYCLE_P0(n) (((n)&0xFFFF)<<0)
#define AIC1000LITE_SYS_CTRL_CFG_CAL_RG_CYCLE_P1(n) (((n)&0xFF)<<16)
#define AIC1000LITE_SYS_CTRL_CFG_CAL_RG_INT_EN (1<<24)
#define AIC1000LITE_SYS_CTRL_CFG_CAL_RG_START_PULSE (1<<25)
#define AIC1000LITE_SYS_CTRL_CFG_CAL_RG_DONE_INT_CLR (1<<26)

//cfg_mdll128_cal_result
#define AIC1000LITE_SYS_CTRL_CFG_CAL_RG_RESULT(n) (((n)&0xFFFFFFFF)<<0)

//cfg_mdll128_cal_busy
#define AIC1000LITE_SYS_CTRL_CFG_CAL_RG_BUSY (1<<0)

//mclk_div
#define AIC1000LITE_SYS_CTRL_CFG_CLK_MCLK_DIV_DENOM(n) (((n)&0xFF)<<0)
#define AIC1000LITE_SYS_CTRL_CFG_CLK_MCLK_DIV_UPDATE (1<<8)

//dcdc_ref_clk_div
#define AIC1000LITE_SYS_CTRL_CFG_DCDC_REF_CLK_DIV_DENOM(n) (((n)&0xFF)<<0)
#define AIC1000LITE_SYS_CTRL_CFG_DCDC_REF_CLK_DIV_UPDATA (1<<8)

//dcdc_ref_clk_ctrl0
#define AIC1000LITE_SYS_CTRL_CFG_DCDC_REF_CLK_TRIANGLE_CYCLE(n) (((n)&0xFFFF)<<0)
#define AIC1000LITE_SYS_CTRL_CFG_DCDC_REF_CLK_TRIANGLE_AMP(n) (((n)&3)<<16)
#define AIC1000LITE_SYS_CTRL_CFG_DCDC_REF_CLK_TRIANGLE_EN (1<<18)

//dcdc_ref_clk_ctrl1
#define AIC1000LITE_SYS_CTRL_CFG_DCDC_RF_OFFSET(n) (((n)&15)<<0)
#define AIC1000LITE_SYS_CTRL_CFG_DCDC_PA_OFFSET(n) (((n)&15)<<4)
#define AIC1000LITE_SYS_CTRL_CFG_DCDC_CORE_OFFSET(n) (((n)&15)<<8)
#define AIC1000LITE_SYS_CTRL_CFG_DCDC_RF_CLK_EN (1<<12)
#define AIC1000LITE_SYS_CTRL_CFG_DCDC_PA_CLK_EN (1<<13)
#define AIC1000LITE_SYS_CTRL_CFG_DCDC_CORE_CLK_EN (1<<14)
#define AIC1000LITE_SYS_CTRL_CFG_DCDC_RF_CLK_HWEN (1<<15)
#define AIC1000LITE_SYS_CTRL_CFG_DCDC_PA_CLK_HWEN (1<<16)
#define AIC1000LITE_SYS_CTRL_CFG_DCDC_CORE_CLK_HWEN (1<<17)
#define AIC1000LITE_SYS_CTRL_CFG_DCDC_RF_DIV(n) (((n)&3)<<18)
#define AIC1000LITE_SYS_CTRL_CFG_DCDC_PA_DIV(n) (((n)&3)<<20)
#define AIC1000LITE_SYS_CTRL_CFG_DCDC_CORE_DIV(n) (((n)&3)<<22)

//UART_DET_FILTER
#define AIC1000LITE_SYS_CTRL_CFG_UART_DET_FILTER_NUM(n) (((n)&7)<<0)

//TPORTS_SEL
#define AIC1000LITE_SYS_CTRL_CFG_TOP_TPORTS_SEL(n) (((n)&0xFF)<<0)
#define AIC1000LITE_SYS_CTRL_CFG_CLK_TPORTS_SEL(n) (((n)&15)<<8)

#endif
