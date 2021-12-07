#ifndef _REG_PWM_H_
#define _REG_PWM_H_

#include "chip.h"

/* ========================================================================== */
/* ====================    Pulse Width Modulation (PWM)   =================== */
/* ========================================================================== */
typedef volatile struct
{
    /// PWM ctrl
    __IO uint32_t                          PWM_CTRL;                     //0x00000000
    /// PWM prescale coefficient
    __IO uint32_t                          PWM0_PRESCALE;                //0x00000004
    /// PWM counter
    __IO uint32_t                          PWM0_CNT;                     //0x00000008
    __IO uint32_t Reserved_0000000C[2];                 //0x0000000C
    /// PWM prescale coefficient
    __IO uint32_t                          PWM1_PRESCALE;                //0x00000014
    /// PWM counter
    __IO uint32_t                          PWM1_CNT;                     //0x00000018
    __IO uint32_t Reserved_0000001C[2];                 //0x0000001C
    /// PWM prescale coefficient
    __IO uint32_t                          PWM2_PRESCALE;                //0x00000024
    /// PWM counter
    __IO uint32_t                          PWM2_CNT;                     //0x00000028
} AIC_PWM_TypeDef;

static AIC_PWM_TypeDef * const AIC_PWM = ((AIC_PWM_TypeDef *)AIC_PWM_BASE);

//PWM_CTRL
#define PWM_PWM0_RUN               (1<<0)
#define PWM_PWM0_MODE_SEL          (1<<1)
#define PWM_PWM1_RUN               (1<<4)
#define PWM_PWM1_MODE_SEL          (1<<5)
#define PWM_PWM2_RUN               (1<<9)
#define PWM_PWM2_MODE_SEL          (1<<10)

//PWM0_PRESCALE
#define PWM_PWM_PRESCALE(n)        (((n)&0xFF)<<0)
#define PWM_PWM_BUSY               (1<<15)

//PWM0_CNT
#define PWM_PWM0_DUTY(n)           (((n)&0xFF)<<0)
#define PWM_PWM0_MOD(n)            (((n)&0xFF)<<8)

//PWM1_PRESCALE
#define PWM_PWM1_PRESCALE(n)       (((n)&0xFF)<<0)
#define PWM_PWM1_BUSY              (1<<15)

//PWM1_CNT
#define PWM_PWM1_DUTY(n)           (((n)&0xFF)<<0)
#define PWM_PWM1_MOD(n)            (((n)&0xFF)<<8)

//PWM2_PRESCALE
#define PWM_PWM2_PRESCALE(n)       (((n)&0xFF)<<0)
#define PWM_PWM2_BUSY              (1<<15)

//PWM2_CNT
#define PWM_PWM2_DUTY(n)           (((n)&0xFF)<<0)
#define PWM_PWM2_MOD(n)            (((n)&0xFF)<<8)

#endif /* _REG_PWM_H_ */
