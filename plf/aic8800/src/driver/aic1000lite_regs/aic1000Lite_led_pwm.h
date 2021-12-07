#ifndef _AIC1000LITE_LED_PWM_H_
#define _AIC1000LITE_LED_PWM_H_

#include "chip.h"

// =============================================================================
//  MACROS
// =============================================================================

// =============================================================================
//  TYPES
// =============================================================================

// ============================================================================
// AIC1000LITE_LED_PWM_T
// -----------------------------------------------------------------------------
///
// =============================================================================
#define REG_AIC1000LITE_LED_PWM_BASE 0x50014000

typedef struct {
  __IO uint32_t                          tmr0_ld_value;                //0x00000000
  __IO uint32_t Reserved_00000004;                    //0x00000004
  __IO uint32_t                          tmr0_cnt_value;               //0x00000008
  __IO uint32_t Reserved_0000000C;                    //0x0000000C
  __IO uint32_t                          tmr0_cfg;                     //0x00000010
  __IO uint32_t                          tmr0_int_ctrl;                //0x00000014
  __IO uint32_t                          tmr0_cnt_read;                //0x00000018
  __IO uint32_t Reserved_0000001C;                    //0x0000001C
  __IO uint32_t                          tmr1_ld_value;                //0x00000020
  __IO uint32_t Reserved_00000024;                    //0x00000024
  __IO uint32_t                          tmr1_cnt_value;               //0x00000028
  __IO uint32_t Reserved_0000002C;                    //0x0000002C
  __IO uint32_t                          tmr1_cfg;                     //0x00000030
  __IO uint32_t                          tmr1_int_ctrl;                //0x00000034
  __IO uint32_t                          tmr1_cnt_read;                //0x00000038
  __IO uint32_t Reserved_0000003C;                    //0x0000003C
  __IO uint32_t                          tmr2_ld_value;                //0x00000040
  __IO uint32_t Reserved_00000044;                    //0x00000044
  __IO uint32_t                          tmr2_cnt_value;               //0x00000048
  __IO uint32_t Reserved_0000004C;                    //0x0000004C
  __IO uint32_t                          tmr2_cfg;                     //0x00000050
  __IO uint32_t                          tmr2_int_ctrl;                //0x00000054
  __IO uint32_t                          tmr2_cnt_read;                //0x00000058
  __IO uint32_t Reserved_0000005C[41];                //0x0000005C
  __IO uint32_t                          pwm0_sta_val;                 //0x00000100
  __IO uint32_t                          pwm0_end_val;                 //0x00000104
  __IO uint32_t                          pwm0_step_cfg0;               //0x00000108
  __IO uint32_t                          pwm0_step_cfg1;               //0x0000010C
  __IO uint32_t                          pwm0_cfg;                     //0x00000110
  __IO uint32_t                          pwm0_int_ctrl;                //0x00000114
  __IO uint32_t                          pwm0_end_val_use;             //0x00000118
  __IO uint32_t                          pwm0_step_cnt;                //0x0000011C
  __IO uint32_t                          pwm1_sta_val;                 //0x00000120
  __IO uint32_t                          pwm1_end_val;                 //0x00000124
  __IO uint32_t                          pwm1_step_cfg0;               //0x00000128
  __IO uint32_t                          pwm1_step_cfg1;               //0x0000012C
  __IO uint32_t                          pwm1_cfg;                     //0x00000130
  __IO uint32_t                          pwm1_int_ctrl;                //0x00000134
  __IO uint32_t                          pwm1_end_val_use;             //0x00000138
  __IO uint32_t                          pwm1_step_cnt;                //0x0000013C
  __IO uint32_t                          pwm2_sta_val;                 //0x00000140
  __IO uint32_t                          pwm2_end_val;                 //0x00000144
  __IO uint32_t                          pwm2_step_cfg0;               //0x00000148
  __IO uint32_t                          pwm2_step_cfg1;               //0x0000014C
  __IO uint32_t                          pwm2_cfg;                     //0x00000150
  __IO uint32_t                          pwm2_int_ctrl;                //0x00000154
  __IO uint32_t                          pwm2_end_val_use;             //0x00000158
  __IO uint32_t                          pwm2_step_cnt;                //0x0000015C
  __IO uint32_t                          pwm3_sta_val;                 //0x00000160
  __IO uint32_t                          pwm3_end_val;                 //0x00000164
  __IO uint32_t                          pwm3_step_cfg0;               //0x00000168
  __IO uint32_t                          pwm3_step_cfg1;               //0x0000016C
  __IO uint32_t                          pwm3_cfg;                     //0x00000170
  __IO uint32_t                          pwm3_int_ctrl;                //0x00000174
  __IO uint32_t                          pwm3_end_val_use;             //0x00000178
  __IO uint32_t                          pwm3_step_cnt;                //0x0000017C
  __IO uint32_t                          pwm4_sta_val;                 //0x00000180
  __IO uint32_t                          pwm4_end_val;                 //0x00000184
  __IO uint32_t                          pwm4_step_cfg0;               //0x00000188
  __IO uint32_t                          pwm4_step_cfg1;               //0x0000018C
  __IO uint32_t                          pwm4_cfg;                     //0x00000190
  __IO uint32_t                          pwm4_int_ctrl;                //0x00000194
  __IO uint32_t                          pwm4_end_val_use;             //0x00000198
  __IO uint32_t                          pwm4_step_cnt;                //0x0000019C
  __IO uint32_t                          pwm5_sta_val;                 //0x000001A0
  __IO uint32_t                          pwm5_end_val;                 //0x000001A4
  __IO uint32_t                          pwm5_step_cfg0;               //0x000001A8
  __IO uint32_t                          pwm5_step_cfg1;               //0x000001AC
  __IO uint32_t                          pwm5_cfg;                     //0x000001B0
  __IO uint32_t                          pwm5_int_ctrl;                //0x000001B4
  __IO uint32_t                          pwm5_end_val_use;             //0x000001B8
  __IO uint32_t                          pwm5_step_cnt;                //0x000001BC
} HWP_AIC1000LITE_LED_PWM_T;

static HWP_AIC1000LITE_LED_PWM_T * const aic1000liteLedPwm = ((HWP_AIC1000LITE_LED_PWM_T *)REG_AIC1000LITE_LED_PWM_BASE);


//tmr0_ld_value
#define AIC1000LITE_LED_PWM_TMR_LD_VALUE(n) (((n)&0xFFFFFFFF)<<0)

//tmr0_cnt_value
#define AIC1000LITE_LED_PWM_TMR_CNT_VALUE(n) (((n)&0xFFFFFFFF)<<0)

//tmr0_cfg
#define AIC1000LITE_LED_PWM_TMR_MODE (1<<0)
#define AIC1000LITE_LED_PWM_TMR_RUN (1<<1)

//tmr0_int_ctrl
#define AIC1000LITE_LED_PWM_TMR_INT_EN (1<<0)
#define AIC1000LITE_LED_PWM_TMR_INT_RAW (1<<1)
#define AIC1000LITE_LED_PWM_TMR_INT_STATUS (1<<2)
#define AIC1000LITE_LED_PWM_TMR_INT_CLR (1<<3)

//tmr0_cnt_read
#define AIC1000LITE_LED_PWM_TMR_CNT_READ(n) (((n)&0xFFFFFFFF)<<0)

//tmr1_ld_value
//#define AIC1000LITE_LED_PWM_TMR_LD_VALUE(n) (((n)&0xFFFFFFFF)<<0)

//tmr1_cnt_value
//#define AIC1000LITE_LED_PWM_TMR_CNT_VALUE(n) (((n)&0xFFFFFFFF)<<0)

//tmr1_cfg
//#define AIC1000LITE_LED_PWM_TMR_MODE (1<<0)
//#define AIC1000LITE_LED_PWM_TMR_RUN (1<<1)

//tmr1_int_ctrl
//#define AIC1000LITE_LED_PWM_TMR_INT_EN (1<<0)
//#define AIC1000LITE_LED_PWM_TMR_INT_RAW (1<<1)
//#define AIC1000LITE_LED_PWM_TMR_INT_STATUS (1<<2)
//#define AIC1000LITE_LED_PWM_TMR_INT_CLR (1<<3)

//tmr1_cnt_read
//#define AIC1000LITE_LED_PWM_TMR_CNT_READ(n) (((n)&0xFFFFFFFF)<<0)

//tmr2_ld_value
//#define AIC1000LITE_LED_PWM_TMR_LD_VALUE(n) (((n)&0xFFFFFFFF)<<0)

//tmr2_cnt_value
//#define AIC1000LITE_LED_PWM_TMR_CNT_VALUE(n) (((n)&0xFFFFFFFF)<<0)

//tmr2_cfg
//#define AIC1000LITE_LED_PWM_TMR_MODE (1<<0)
//#define AIC1000LITE_LED_PWM_TMR_RUN (1<<1)

//tmr2_int_ctrl
//#define AIC1000LITE_LED_PWM_TMR_INT_EN (1<<0)
//#define AIC1000LITE_LED_PWM_TMR_INT_RAW (1<<1)
//#define AIC1000LITE_LED_PWM_TMR_INT_STATUS (1<<2)
//#define AIC1000LITE_LED_PWM_TMR_INT_CLR (1<<3)

//tmr2_cnt_read
#define AIC1000LITE_LED_PWM_TMR2_CNT_READ(n) (((n)&0xFFFFFFFF)<<0)

//pwm0_sta_val
#define AIC1000LITE_LED_PWM_PWM_STA_VAL(n) (((n)&0xFFFFFFFF)<<0)

//pwm0_end_val
#define AIC1000LITE_LED_PWM_PWM_END_VAL(n) (((n)&0xFFFFFFFF)<<0)

//pwm0_step_cfg0
#define AIC1000LITE_LED_PWM_PWM_STEP_CYC(n) (((n)&0xFFFF)<<0)
#define AIC1000LITE_LED_PWM_PWM_STEP_NUM(n) (((n)&0xFFFF)<<16)

//pwm0_step_cfg1
#define AIC1000LITE_LED_PWM_PWM_STEP_VALUE(n) (((n)&0xFFFFFFFF)<<0)

//pwm0_cfg
#define AIC1000LITE_LED_PWM_PWM_RUN (1<<0)
#define AIC1000LITE_LED_PWM_PWM_INC_MODE (1<<1)
#define AIC1000LITE_LED_PWM_PWM_DEFAULT_VAL (1<<2)
#define AIC1000LITE_LED_PWM_PWM_TMR_SEL(n) (((n)&3)<<16)
#define AIC1000LITE_LED_PWM_PWM_UPDATE (1<<31)

//pwm0_int_ctrl
#define AIC1000LITE_LED_PWM_PWM_INT_EN (1<<0)
#define AIC1000LITE_LED_PWM_PWM_INT_RAW (1<<1)
#define AIC1000LITE_LED_PWM_PWM_INT_STATUS (1<<2)
#define AIC1000LITE_LED_PWM_PWM_INT_CLR (1<<3)

//pwm0_end_val_use
#define AIC1000LITE_LED_PWM_PWM_END_VAL_USE(n) (((n)&0xFFFFFFFF)<<0)

//pwm0_step_cnt
#define AIC1000LITE_LED_PWM_PWM_STEP_CYC_CNT(n) (((n)&0xFFFF)<<0)
#define AIC1000LITE_LED_PWM_PWM_STEP_NUM_CNT(n) (((n)&0xFFFF)<<16)

//pwm1_sta_val
//#define AIC1000LITE_LED_PWM_PWM_STA_VAL(n) (((n)&0xFFFFFFFF)<<0)

//pwm1_end_val
//#define AIC1000LITE_LED_PWM_PWM_END_VAL(n) (((n)&0xFFFFFFFF)<<0)

//pwm1_step_cfg0
//#define AIC1000LITE_LED_PWM_PWM_STEP_CYC(n) (((n)&0xFFFF)<<0)
//#define AIC1000LITE_LED_PWM_PWM_STEP_NUM(n) (((n)&0xFFFF)<<16)

//pwm1_step_cfg1
//#define AIC1000LITE_LED_PWM_PWM_STEP_VALUE(n) (((n)&0xFFFFFFFF)<<0)

//pwm1_cfg
//#define AIC1000LITE_LED_PWM_PWM_RUN (1<<0)
//#define AIC1000LITE_LED_PWM_PWM_INC_MODE (1<<1)
//#define AIC1000LITE_LED_PWM_PWM_DEFAULT_VAL (1<<2)
//#define AIC1000LITE_LED_PWM_PWM_TMR_SEL(n) (((n)&3)<<16)
//#define AIC1000LITE_LED_PWM_PWM_UPDATE (1<<31)

//pwm1_int_ctrl
//#define AIC1000LITE_LED_PWM_PWM_INT_EN (1<<0)
//#define AIC1000LITE_LED_PWM_PWM_INT_RAW (1<<1)
//#define AIC1000LITE_LED_PWM_PWM_INT_STATUS (1<<2)
//#define AIC1000LITE_LED_PWM_PWM_INT_CLR (1<<3)

//pwm1_end_val_use
//#define AIC1000LITE_LED_PWM_PWM_END_VAL_USE(n) (((n)&0xFFFFFFFF)<<0)

//pwm1_step_cnt
//#define AIC1000LITE_LED_PWM_PWM_STEP_CYC_CNT(n) (((n)&0xFFFF)<<0)
//#define AIC1000LITE_LED_PWM_PWM_STEP_NUM_CNT(n) (((n)&0xFFFF)<<16)

//pwm2_sta_val
//#define AIC1000LITE_LED_PWM_PWM_STA_VAL(n) (((n)&0xFFFFFFFF)<<0)

//pwm2_end_val
//#define AIC1000LITE_LED_PWM_PWM_END_VAL(n) (((n)&0xFFFFFFFF)<<0)

//pwm2_step_cfg0
//#define AIC1000LITE_LED_PWM_PWM_STEP_CYC(n) (((n)&0xFFFF)<<0)
//#define AIC1000LITE_LED_PWM_PWM_STEP_NUM(n) (((n)&0xFFFF)<<16)

//pwm2_step_cfg1
//#define AIC1000LITE_LED_PWM_PWM_STEP_VALUE(n) (((n)&0xFFFFFFFF)<<0)

//pwm2_cfg
//#define AIC1000LITE_LED_PWM_PWM_RUN (1<<0)
//#define AIC1000LITE_LED_PWM_PWM_INC_MODE (1<<1)
//#define AIC1000LITE_LED_PWM_PWM_DEFAULT_VAL (1<<2)
//#define AIC1000LITE_LED_PWM_PWM_TMR_SEL(n) (((n)&3)<<16)
//#define AIC1000LITE_LED_PWM_PWM_UPDATE (1<<31)

//pwm2_int_ctrl
//#define AIC1000LITE_LED_PWM_PWM_INT_EN (1<<0)
//#define AIC1000LITE_LED_PWM_PWM_INT_RAW (1<<1)
//#define AIC1000LITE_LED_PWM_PWM_INT_STATUS (1<<2)
//#define AIC1000LITE_LED_PWM_PWM_INT_CLR (1<<3)

//pwm2_end_val_use
//#define AIC1000LITE_LED_PWM_PWM_END_VAL_USE(n) (((n)&0xFFFFFFFF)<<0)

//pwm2_step_cnt
//#define AIC1000LITE_LED_PWM_PWM_STEP_CYC_CNT(n) (((n)&0xFFFF)<<0)
//#define AIC1000LITE_LED_PWM_PWM_STEP_NUM_CNT(n) (((n)&0xFFFF)<<16)

//pwm3_sta_val
//#define AIC1000LITE_LED_PWM_PWM_STA_VAL(n) (((n)&0xFFFFFFFF)<<0)

//pwm3_end_val
//#define AIC1000LITE_LED_PWM_PWM_END_VAL(n) (((n)&0xFFFFFFFF)<<0)

//pwm3_step_cfg0
//#define AIC1000LITE_LED_PWM_PWM_STEP_CYC(n) (((n)&0xFFFF)<<0)
//#define AIC1000LITE_LED_PWM_PWM_STEP_NUM(n) (((n)&0xFFFF)<<16)

//pwm3_step_cfg1
//#define AIC1000LITE_LED_PWM_PWM_STEP_VALUE(n) (((n)&0xFFFFFFFF)<<0)

//pwm3_cfg
//#define AIC1000LITE_LED_PWM_PWM_RUN (1<<0)
//#define AIC1000LITE_LED_PWM_PWM_INC_MODE (1<<1)
//#define AIC1000LITE_LED_PWM_PWM_DEFAULT_VAL (1<<2)
//#define AIC1000LITE_LED_PWM_PWM_TMR_SEL(n) (((n)&3)<<16)
//#define AIC1000LITE_LED_PWM_PWM_UPDATE (1<<31)

//pwm3_int_ctrl
//#define AIC1000LITE_LED_PWM_PWM_INT_EN (1<<0)
//#define AIC1000LITE_LED_PWM_PWM_INT_RAW (1<<1)
//#define AIC1000LITE_LED_PWM_PWM_INT_STATUS (1<<2)
//#define AIC1000LITE_LED_PWM_PWM_INT_CLR (1<<3)

//pwm3_end_val_use
//#define AIC1000LITE_LED_PWM_PWM_END_VAL_USE(n) (((n)&0xFFFFFFFF)<<0)

//pwm3_step_cnt
//#define AIC1000LITE_LED_PWM_PWM_STEP_CYC_CNT(n) (((n)&0xFFFF)<<0)
//#define AIC1000LITE_LED_PWM_PWM_STEP_NUM_CNT(n) (((n)&0xFFFF)<<16)

//pwm4_sta_val
//#define AIC1000LITE_LED_PWM_PWM_STA_VAL(n) (((n)&0xFFFFFFFF)<<0)

//pwm4_end_val
//#define AIC1000LITE_LED_PWM_PWM_END_VAL(n) (((n)&0xFFFFFFFF)<<0)

//pwm4_step_cfg0
//#define AIC1000LITE_LED_PWM_PWM_STEP_CYC(n) (((n)&0xFFFF)<<0)
//#define AIC1000LITE_LED_PWM_PWM_STEP_NUM(n) (((n)&0xFFFF)<<16)

//pwm4_step_cfg1
//#define AIC1000LITE_LED_PWM_PWM_STEP_VALUE(n) (((n)&0xFFFFFFFF)<<0)

//pwm4_cfg
//#define AIC1000LITE_LED_PWM_PWM_RUN (1<<0)
//#define AIC1000LITE_LED_PWM_PWM_INC_MODE (1<<1)
//#define AIC1000LITE_LED_PWM_PWM_DEFAULT_VAL (1<<2)
//#define AIC1000LITE_LED_PWM_PWM_TMR_SEL(n) (((n)&3)<<16)
//#define AIC1000LITE_LED_PWM_PWM_UPDATE (1<<31)

//pwm4_int_ctrl
//#define AIC1000LITE_LED_PWM_PWM_INT_EN (1<<0)
//#define AIC1000LITE_LED_PWM_PWM_INT_RAW (1<<1)
//#define AIC1000LITE_LED_PWM_PWM_INT_STATUS (1<<2)
//#define AIC1000LITE_LED_PWM_PWM_INT_CLR (1<<3)

//pwm4_end_val_use
//#define AIC1000LITE_LED_PWM_PWM_END_VAL_USE(n) (((n)&0xFFFFFFFF)<<0)

//pwm4_step_cnt
//#define AIC1000LITE_LED_PWM_PWM_STEP_CYC_CNT(n) (((n)&0xFFFF)<<0)
//#define AIC1000LITE_LED_PWM_PWM_STEP_NUM_CNT(n) (((n)&0xFFFF)<<16)

//pwm5_sta_val
//#define AIC1000LITE_LED_PWM_PWM_STA_VAL(n) (((n)&0xFFFFFFFF)<<0)

//pwm5_end_val
//#define AIC1000LITE_LED_PWM_PWM_END_VAL(n) (((n)&0xFFFFFFFF)<<0)

//pwm5_step_cfg0
//#define AIC1000LITE_LED_PWM_PWM_STEP_CYC(n) (((n)&0xFFFF)<<0)
//#define AIC1000LITE_LED_PWM_PWM_STEP_NUM(n) (((n)&0xFFFF)<<16)

//pwm5_step_cfg1
//#define AIC1000LITE_LED_PWM_PWM_STEP_VALUE(n) (((n)&0xFFFFFFFF)<<0)

//pwm5_cfg
//#define AIC1000LITE_LED_PWM_PWM_RUN (1<<0)
//#define AIC1000LITE_LED_PWM_PWM_INC_MODE (1<<1)
//#define AIC1000LITE_LED_PWM_PWM_DEFAULT_VAL (1<<2)
//#define AIC1000LITE_LED_PWM_PWM_TMR_SEL(n) (((n)&3)<<16)
//#define AIC1000LITE_LED_PWM_PWM_UPDATE (1<<31)

//pwm5_int_ctrl
//#define AIC1000LITE_LED_PWM_PWM_INT_EN (1<<0)
//#define AIC1000LITE_LED_PWM_PWM_INT_RAW (1<<1)
//#define AIC1000LITE_LED_PWM_PWM_INT_STATUS (1<<2)
//#define AIC1000LITE_LED_PWM_PWM_INT_CLR (1<<3)

//pwm5_end_val_use
//#define AIC1000LITE_LED_PWM_PWM_END_VAL_USE(n) (((n)&0xFFFFFFFF)<<0)

//pwm5_step_cnt
//#define AIC1000LITE_LED_PWM_PWM_STEP_CYC_CNT(n) (((n)&0xFFFF)<<0)
//#define AIC1000LITE_LED_PWM_PWM_STEP_NUM_CNT(n) (((n)&0xFFFF)<<16)

#endif
