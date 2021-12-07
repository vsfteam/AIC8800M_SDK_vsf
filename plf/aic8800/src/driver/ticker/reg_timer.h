#ifndef _REG_TIMER_H_
#define _REG_TIMER_H_

#include "chip.h"

/**
 * Timer registers
 */
typedef struct {
  struct {
    __IO uint32_t CTL;          /* 0x000: Control */
    __IO uint32_t TC;           /* 0x004: Timer Counter */
    __IO uint32_t PR;           /* 0x008: Prescale */
    __IO uint32_t PC;           /* 0x00C: Prescale Counter */
    __IO uint32_t MR;           /* 0x010: Match Register */
    __IO uint32_t TD;           /* 0x014: Tick Divider */
    __IO uint32_t IC;           /* 0x018: Interrupt Control */
    __I  uint32_t IS;           /* 0x01C: Interrupt Status */
  } TMR[3];
} AIC_TIM_TypeDef;

typedef struct {
  __IO uint32_t CTL;            /* 0x000: Control */
  __IO uint32_t TD;             /* 0x004: Tick Divider */
  __IO uint32_t IC;             /* 0x008: Interrupt Control */
  __I  uint32_t IS;             /* 0x00C: Interrupt Status */
  __IO uint32_t TCL;            /* 0x010: Timer Counter low-32bit */
  __IO uint32_t TCH;            /* 0x014: Timer Counter high-16bit */
       uint32_t RESERVED0[2U];
  struct {
    __IO uint32_t L;            /* 0x020: Match Register low-32bit */
    __IO uint32_t H;            /* 0x024: Match Register high-16bit */
  } MR[4];
} AIC_AONTIM_TypeDef;

/**
 * Timer Peripherals
 */
static AIC_TIM_TypeDef    * const AIC_TIM0 = ((AIC_TIM_TypeDef    *)AIC_TIM0_BASE);
static AIC_TIM_TypeDef    * const AIC_TIM1 = ((AIC_TIM_TypeDef    *)AIC_TIM1_BASE);
static AIC_AONTIM_TypeDef * const AIC_TIM2 = ((AIC_AONTIM_TypeDef *)AIC_TIM2_BASE);

#endif /* _REG_TIMER_H_ */
