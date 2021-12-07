#ifndef _REG_GPIO_H_
#define _REG_GPIO_H_

#include "chip.h"

/* ========================================================================== */
/* ================    General Purpose Input/Output (GPIO)   ================ */
/* ========================================================================== */
typedef struct {
    __IO uint32_t VR;           /* 0x000 (R/W) : Val Reg */
    __IO uint32_t MR;           /* 0x004 (R/W) : Msk Reg */
    __IO uint32_t DR;           /* 0x008 (R/W) : Dir Reg */
    __IO uint32_t TELR;         /* 0x00C (R/W) : Trig Edg or Lvl Reg */
    __IO uint32_t TER;          /* 0x010 (R/W) : Trig Edg Reg */
    __IO uint32_t TLR;          /* 0x014 (R/W) : Trig Lvl Reg */
    __IO uint32_t ICR;          /* 0x018 (R/W) : Int Ctrl Reg */
    __I  uint32_t RESERVED0;    /* 0x01C (R)   : Reserved */
    __I  uint32_t ISR;          /* 0x020 (R)   : Int Stat Reg */
    __O  uint32_t IRR;          /* 0x024 (W)   : Int Rm Reg */
    __IO uint32_t TIR;          /* 0x028 (R/W) : Trig In Reg */
    __IO uint32_t FR;           /* 0x02C (R/W) : Fltr Reg */
} AIC_GPIO_TypeDef;

static AIC_GPIO_TypeDef * const AIC_GPIO = ((AIC_GPIO_TypeDef *)AIC_GPIO_BASE);

#endif /* _REG_GPIO_H_ */
