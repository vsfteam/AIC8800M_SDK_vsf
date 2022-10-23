#ifndef _AIC1000AUD_LED_PWM_H_
#define _AIC1000AUD_LED_PWM_H_

#include "chip.h"

// =============================================================================
//  MACROS
// =============================================================================

// =============================================================================
//  TYPES
// =============================================================================

// =============================================================================
// AIC1000AUD_LED_PWM_T
// -----------------------------------------------------------------------------
///
// =============================================================================
#define REG_AIC1000AUD_LED_PWM_BASE 0x50014000

typedef struct {
    __IO uint32_t               tmr0_ld_value;              //0x00000000
    __IO uint32_t Reserved_00000004;            //0x00000004
    __IO uint32_t               tmr0_cnt_value;             //0x00000008
    __IO uint32_t Reserved_0000000C;            //0x0000000C
    __IO uint32_t               tmr0_cfg;                   //0x00000010
    __IO uint32_t               tmr0_int_ctrl;              //0x00000014
    __IO uint32_t               tmr0_cnt_read;              //0x00000018
    __IO uint32_t Reserved_0000001C;            //0x0000001C
    __IO uint32_t               tmr1_ld_value;              //0x00000020
    __IO uint32_t Reserved_00000024;            //0x00000024
    __IO uint32_t               tmr1_cnt_value;             //0x00000028
    __IO uint32_t Reserved_0000002C;            //0x0000002C
    __IO uint32_t               tmr1_cfg;                   //0x00000030
    __IO uint32_t               tmr1_int_ctrl;              //0x00000034
    __IO uint32_t               tmr1_cnt_read;              //0x00000038
    __IO uint32_t Reserved_0000003C[49];        //0x0000003C
    __IO uint32_t               pwm0_sta_val;               //0x00000100
    __IO uint32_t               pwm0_end_val;               //0x00000104
    __IO uint32_t               pwm0_step_cfg0;             //0x00000108
    __IO uint32_t               pwm0_step_cfg1;             //0x0000010C
    __IO uint32_t               pwm0_cfg;                   //0x00000110
    __IO uint32_t               pwm0_int_ctrl;              //0x00000114
    __IO uint32_t               pwm0_end_val_use;           //0x00000118
    __IO uint32_t               pwm0_step_cnt;              //0x0000011C
    __IO uint32_t               pwm1_sta_val;               //0x00000120
    __IO uint32_t               pwm1_end_val;               //0x00000124
    __IO uint32_t               pwm1_step_cfg0;             //0x00000128
    __IO uint32_t               pwm1_step_cfg1;             //0x0000012C
    __IO uint32_t               pwm1_cfg;                   //0x00000130
    __IO uint32_t               pwm1_int_ctrl;              //0x00000134
    __IO uint32_t               pwm1_end_val_use;           //0x00000138
    __IO uint32_t               pwm1_step_cnt;              //0x0000013C
} HWP_AIC1000AUD_LED_PWM_T;

static HWP_AIC1000AUD_LED_PWM_T * const aic1000audLedPwm = ((HWP_AIC1000AUD_LED_PWM_T *)REG_AIC1000AUD_LED_PWM_BASE);


//tmr0_ld_value
#define AIC1000AUD_LED_PWM_TMR_LD_VALUE(n) (((n)&0xFFFFFFFF)<<0)

//tmr0_cnt_value
#define AIC1000AUD_LED_PWM_TMR_CNT_VALUE(n) (((n)&0xFFFFFFFF)<<0)

//tmr0_cfg
#define AIC1000AUD_LED_PWM_TMR_MODE (1<<0)
#define AIC1000AUD_LED_PWM_TMR_RUN (1<<1)

//tmr0_int_ctrl
#define AIC1000AUD_LED_PWM_TMR_INT_EN (1<<0)
#define AIC1000AUD_LED_PWM_TMR_INT_RAW (1<<1)
#define AIC1000AUD_LED_PWM_TMR_INT_STATUS (1<<2)
#define AIC1000AUD_LED_PWM_TMR_INT_CLR (1<<3)

//tmr0_cnt_read
#define AIC1000AUD_LED_PWM_TMR_CNT_READ(n) (((n)&0xFFFFFFFF)<<0)

//tmr1_ld_value
//#define AIC1000AUD_LED_PWM_TMR_LD_VALUE(n) (((n)&0xFFFFFFFF)<<0)

//tmr1_cnt_value
//#define AIC1000AUD_LED_PWM_TMR_CNT_VALUE(n) (((n)&0xFFFFFFFF)<<0)

//tmr1_cfg
//#define AIC1000AUD_LED_PWM_TMR_MODE (1<<0)
//#define AIC1000AUD_LED_PWM_TMR_RUN (1<<1)

//tmr1_int_ctrl
//#define AIC1000AUD_LED_PWM_TMR_INT_EN (1<<0)
//#define AIC1000AUD_LED_PWM_TMR_INT_RAW (1<<1)
//#define AIC1000AUD_LED_PWM_TMR_INT_STATUS (1<<2)
//#define AIC1000AUD_LED_PWM_TMR_INT_CLR (1<<3)

//tmr1_cnt_read
//#define AIC1000AUD_LED_PWM_TMR_CNT_READ(n) (((n)&0xFFFFFFFF)<<0)

//pwm0_sta_val
#define AIC1000AUD_LED_PWM_PWM_STA_VAL(n) (((n)&0xFFFFFFFF)<<0)

//pwm0_end_val
#define AIC1000AUD_LED_PWM_PWM_END_VAL(n) (((n)&0xFFFFFFFF)<<0)

//pwm0_step_cfg0
#define AIC1000AUD_LED_PWM_PWM_STEP_CYC(n) (((n)&0xFFFF)<<0)
#define AIC1000AUD_LED_PWM_PWM_STEP_NUM(n) (((n)&0xFFFF)<<16)

//pwm0_step_cfg1
#define AIC1000AUD_LED_PWM_PWM_STEP_VALUE(n) (((n)&0xFFFFFFFF)<<0)

//pwm0_cfg
#define AIC1000AUD_LED_PWM_PWM_RUN (1<<0)
#define AIC1000AUD_LED_PWM_PWM_INC_MODE (1<<1)
#define AIC1000AUD_LED_PWM_PWM_DEFAULT_VAL (1<<2)
#define AIC1000AUD_LED_PWM_PWM_TMR_SEL(n) (((n)&3)<<16)
#define AIC1000AUD_LED_PWM_PWM_UPDATE (1<<31)

//pwm0_int_ctrl
#define AIC1000AUD_LED_PWM_PWM_INT_EN (1<<0)
#define AIC1000AUD_LED_PWM_PWM_INT_RAW (1<<1)
#define AIC1000AUD_LED_PWM_PWM_INT_STATUS (1<<2)
#define AIC1000AUD_LED_PWM_PWM_INT_CLR (1<<3)

//pwm0_end_val_use
#define AIC1000AUD_LED_PWM_PWM_END_VAL_USE(n) (((n)&0xFFFFFFFF)<<0)

//pwm0_step_cnt
#define AIC1000AUD_LED_PWM_PWM_STEP_CYC_CNT(n) (((n)&0xFFFF)<<0)
#define AIC1000AUD_LED_PWM_PWM_STEP_NUM_CNT(n) (((n)&0xFFFF)<<16)

//pwm1_sta_val
//#define AIC1000AUD_LED_PWM_PWM_STA_VAL(n) (((n)&0xFFFFFFFF)<<0)

//pwm1_end_val
//#define AIC1000AUD_LED_PWM_PWM_END_VAL(n) (((n)&0xFFFFFFFF)<<0)

//pwm1_step_cfg0
//#define AIC1000AUD_LED_PWM_PWM_STEP_CYC(n) (((n)&0xFFFF)<<0)
//#define AIC1000AUD_LED_PWM_PWM_STEP_NUM(n) (((n)&0xFFFF)<<16)

//pwm1_step_cfg1
//#define AIC1000AUD_LED_PWM_PWM_STEP_VALUE(n) (((n)&0xFFFFFFFF)<<0)

//pwm1_cfg
//#define AIC1000AUD_LED_PWM_PWM_RUN (1<<0)
//#define AIC1000AUD_LED_PWM_PWM_INC_MODE (1<<1)
//#define AIC1000AUD_LED_PWM_PWM_DEFAULT_VAL (1<<2)
//#define AIC1000AUD_LED_PWM_PWM_TMR_SEL(n) (((n)&3)<<16)
//#define AIC1000AUD_LED_PWM_PWM_UPDATE (1<<31)

//pwm1_int_ctrl
//#define AIC1000AUD_LED_PWM_PWM_INT_EN (1<<0)
//#define AIC1000AUD_LED_PWM_PWM_INT_RAW (1<<1)
//#define AIC1000AUD_LED_PWM_PWM_INT_STATUS (1<<2)
//#define AIC1000AUD_LED_PWM_PWM_INT_CLR (1<<3)

//pwm1_end_val_use
//#define AIC1000AUD_LED_PWM_PWM_END_VAL_USE(n) (((n)&0xFFFFFFFF)<<0)

//pwm1_step_cnt
//#define AIC1000AUD_LED_PWM_PWM_STEP_CYC_CNT(n) (((n)&0xFFFF)<<0)
//#define AIC1000AUD_LED_PWM_PWM_STEP_NUM_CNT(n) (((n)&0xFFFF)<<16)

#endif
