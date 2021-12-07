#ifndef _AIC1000LITE_MSADC_H_
#define _AIC1000LITE_MSADC_H_

#include "chip.h"

// =============================================================================
//  MACROS
// =============================================================================

// =============================================================================
//  TYPES
// =============================================================================

// =============================================================================
// AIC1000LITE_MSADC_T
// -----------------------------------------------------------------------------
///
// =============================================================================
#define REG_AIC1000LITE_MSADC_BASE 0x5001B000

typedef struct {
  __IO uint32_t                          cfg_msadc_mode;               //0x00000000
  __IO uint32_t                          cfg_msadc_sw_ctrl0;           //0x00000004
  __IO uint32_t                          cfg_msadc_sw_ctrl1;           //0x00000008
  __IO uint32_t                          cfg_msadc_ana_ctrl0;          //0x0000000C
  __IO uint32_t                          cfg_msadc_ro_acc;             //0x00000010
  __IO uint32_t                          cfg_msadc_ro_test_acc_0;      //0x00000014
  __IO uint32_t                          cfg_msadc_ro_test_acc_1;      //0x00000018
  __IO uint32_t                          cfg_msadc_int_raw;            //0x0000001C
  __IO uint32_t                          cfg_msadc_int_status;         //0x00000020
  __IO uint32_t                          cfg_msadc_int_mask;           //0x00000024
} HWP_AIC1000LITE_MSADC_T;

static HWP_AIC1000LITE_MSADC_T * const aic1000liteMsadc = ((HWP_AIC1000LITE_MSADC_T *)REG_AIC1000LITE_MSADC_BASE);


//cfg_msadc_mode
#define AIC1000LITE_MSADC_CFG_MSADC_MODE (1<<0)
#define AIC1000LITE_MSADC_CFG_MSADC_HW_TEST_CHANNEL (1<<1)

//cfg_msadc_sw_ctrl0
#define AIC1000LITE_MSADC_CFG_MSADC_SW_START_PULSE (1<<0)
#define AIC1000LITE_MSADC_CFG_MSADC_SW_STOP_PULSE (1<<1)
#define AIC1000LITE_MSADC_CFG_MSADC_SW_CLEAR_PULSE (1<<2)

//cfg_msadc_sw_ctrl1
#define AIC1000LITE_MSADC_CFG_MSADC_SW_MUX_BITS(n) (((n)&15)<<0)
#define AIC1000LITE_MSADC_CFG_MSADC_TEST_0_MUX_BITS(n) (((n)&15)<<4)
#define AIC1000LITE_MSADC_CFG_MSADC_TEST_1_MUX_BITS(n) (((n)&15)<<8)
#define AIC1000LITE_MSADC_CFG_MSADC_WAIT_CNT(n) (((n)&15)<<12)
#define AIC1000LITE_MSADC_CFG_MSADC_WINDOW(n) (((n)&0xFFF)<<16)
#define AIC1000LITE_MSADC_CFG_MSADC_SW_DIFF_MODE (1<<28)

//cfg_msadc_ana_ctrl0
#define AIC1000LITE_MSADC_CFG_ANA_MSADC_CHNP_SEL (1<<0)
#define AIC1000LITE_MSADC_CFG_ANA_MSADC_CMP_BIT (1<<1)
#define AIC1000LITE_MSADC_CFG_ANA_MSADC_VBE_CAL_BIT(n) (((n)&0x7F)<<2)
#define AIC1000LITE_MSADC_CFG_ANA_MSADC_TS_MODE (1<<9)
#define AIC1000LITE_MSADC_CFG_ANA_MSADC_SDM_MODE (1<<10)
#define AIC1000LITE_MSADC_CFG_ANA_MSADC_TEST_MODE (1<<11)
#define AIC1000LITE_MSADC_CFG_ANA_MSADC_IBIAS_BIT(n) (((n)&7)<<12)
#define AIC1000LITE_MSADC_CFG_ANA_MSADC_CHOP_EN (1<<15)
#define AIC1000LITE_MSADC_CFG_ANA_MSADC_SDM_GAIN_BIT (1<<16)
#define AIC1000LITE_MSADC_CFG_ANA_MSADC_DEM_EN(n) (((n)&3)<<17)
#define AIC1000LITE_MSADC_CFG_ANA_MSADC_ADC_FF_EN (1<<19)

//cfg_msadc_ro_acc
#define AIC1000LITE_MSADC_RO_MSADC_DAT_ACC(n) (((n)&0x3FFFFF)<<0)

//cfg_msadc_ro_test_acc_0
#define AIC1000LITE_MSADC_RO_MSADC_TEST_ACC_0(n) (((n)&0x3FFFFF)<<0)

//cfg_msadc_ro_test_acc_1
#define AIC1000LITE_MSADC_RO_MSADC_TEST_ACC_1(n) (((n)&0x3FFFFF)<<0)

//cfg_msadc_int_raw
#define AIC1000LITE_MSADC_MASDC_INT_RAW (1<<0)

//cfg_msadc_int_status
#define AIC1000LITE_MSADC_MSADC_INT_STATUS (1<<0)

//cfg_msadc_int_mask
#define AIC1000LITE_MSADC_CFG_MSADC_INT_MASK (1<<0)

#endif
