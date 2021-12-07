#ifndef _REG_SPI_H_
#define _REG_SPI_H_

#include "chip.h"

/* ================================================================================ */
/* ================       Serial Peripheral Interface (SPI)        ================ */
/* ================================================================================ */
/*------------- Serial Peripheral Interface (SPI) ----------------------------*/
typedef struct {
  __IO uint32_t IOR;            /* 0x000 (R/W) : In/Out Reg */
  __IO uint32_t DR;             /* 0x004 (R/W) : Div Reg */
  __IO uint32_t CR[6];          /* 0x008 (R/W) : Cfg Reg */
  __IO uint32_t IER;            /* 0x020 (R/W) : Int En Reg */
  __IO uint32_t ICLR;           /* 0x024 (R/W) : Int Clr Reg */
  __I  uint32_t IRSR;           /* 0x028 (R/W) : Int Raw Stat Reg */
  __I  uint32_t IMSR;           /* 0x02C (R/W) : Int Msk Stat Reg */
  __I  uint32_t RESERVED0;      /* 0x030 (R)   : Reserved */
  __I  uint32_t SR;             /* 0x034 (R)   : Stat Reg */
  __I  uint32_t RESERVED1[5];   /* 0x038 (R)   : Reserved */
  __IO uint32_t MR0;            /* 0x04C (R/W) : Mode Reg 0 */
  __I  uint32_t RESERVED2;      /* 0x050 (R)   : Reserved */
  __IO uint32_t MR1;            /* 0x054 (R/W) : Mode Reg 1 */
  __IO uint32_t OCR;            /* 0x058 (R/W) : Out Cnt Reg */
  __I  uint32_t RESERVED3;      /* 0x05C (R)   : Reserved */
  __IO uint32_t ICR;            /* 0x060 (R/W) : In Cnt Reg */
  __IO uint32_t TCR;            /* 0x064 (R/W) : Trans Ctrl Reg */
} AIC_SPI_TypeDef;

static AIC_SPI_TypeDef * const AIC_SPI0 = ((AIC_SPI_TypeDef *)AIC_SPI0_BASE);

/**
 * SPI DR
 */

#define SPI_DR_DIV_LSB              (0)
#define SPI_DR_DIV_WIDTH            (16)
#define SPI_DR_DIV_MASK             (((0x01UL << SPI_DR_DIV_WIDTH) - 1) << SPI_DR_DIV_LSB)

__STATIC_INLINE uint16_t spi_dr_div_getf(void)
{
    return ((AIC_SPI0->DR & SPI_DR_DIV_MASK) >> SPI_DR_DIV_LSB);
}

__STATIC_INLINE void spi_dr_div_setf(uint16_t div_denom)
{
    uint32_t local_val = AIC_SPI0->DR & ~SPI_DR_DIV_MASK;
    AIC_SPI0->DR = local_val | ((div_denom << SPI_DR_DIV_LSB) & SPI_DR_DIV_MASK);
}

#endif /* _REG_SPI_H_ */
