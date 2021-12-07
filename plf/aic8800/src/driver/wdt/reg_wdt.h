#ifndef _REG_WDT_H_
#define _REG_WDT_H_

#include "chip.h"

typedef volatile struct
{
  __IO uint32_t LOAD;                       //0x00000000
  __IO uint32_t VALUE;                      //0x00000004
  __IO uint32_t CTRL;                       //0x00000008
  __O  uint32_t INT_CLR;                    //0x0000000C
  __I  uint32_t INT_RAW;                    //0x00000010
  __IO uint32_t INT_MASK;                   //0x00000014
  __I  uint32_t RESERVED0[762];
  __IO uint32_t LOCK;                       //0x00000C00
} AIC_WDT_TypeDef;

static AIC_WDT_TypeDef * const AIC_WDT0 = ((AIC_WDT_TypeDef *)AIC_WDT0_BASE);
static AIC_WDT_TypeDef * const AIC_WDT1 = ((AIC_WDT_TypeDef *)AIC_WDT1_BASE);
static AIC_WDT_TypeDef * const AIC_WDT2 = ((AIC_WDT_TypeDef *)AIC_WDT2_BASE);
static AIC_WDT_TypeDef * const AIC_WDT3 = ((AIC_WDT_TypeDef *)AIC_WDT3_BASE);

#endif /* _REG_TRNG_H_ */
