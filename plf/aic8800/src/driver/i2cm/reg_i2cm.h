#ifndef _REG_I2CM_H_
#define _REG_I2CM_H_

#include "chip.h"

/* ========================================================================== */
/* ===============       Inter-Integrated Circuit (I2C)       =============== */
/* ========================================================================== */
typedef struct {
    __IO uint32_t CR;                   /* 0x000 (R/W) : Cfg Register */
    __IO uint32_t SAR;                  /* 0x004 (R/W) : Slave Addr Register */
    __IO uint32_t LR;                   /* 0x008 (R/W) : Len Register */
    __I  uint32_t IR;                   /* 0x00C (R)   : In Register */
    __O  uint32_t OR;                   /* 0x010 (W)   : Out Register */
    __IO uint32_t SR;                   /* 0x014 (R)   : Stat Regisetr */
    __I  uint32_t RESERVED0[2];         /* 0x018 (R)   : Reserved */
    __IO uint32_t DR[2];                /* 0x020 (R/W) : Div Register */
    __IO uint32_t SCR;                  /* 0x028 (R/W) : St Cnt Register */
    __IO uint32_t RR;                   /* 0x02C (R/W) : Rst Register */
} AIC_I2CM_TypeDef;

static AIC_I2CM_TypeDef * const AIC_I2CM0 = ((AIC_I2CM_TypeDef *)AIC_I2CM0_BASE);

/* CR */
#define CR_START_BIT                (0x01UL /*<< 0*/)
#define CR_INT_ENABLE_BIT           (0x01UL << 1)
#define CR_ENABLE_BIT               (0x01UL << 2)
#define CR_READ_BIT                 (0x01UL << 3)
#define CR_OMO_ENABLE_BIT           (0x01UL << 7)
#define CR_DE_TH_FILED(f)           (((f) & 0x0FUL) << 12)
#define CR_DF_TH_FILED(f)           (((f) & 0x0FUL) << 16)
#define CR_RESTART_BIT              (0x01UL << 21)

/* SAR */
#define SAR_SLAVE_ADDR_FILED(f)     (((f) & 0x007FUL) << 1)

/* SR */
#define SR_BUSY_BIT                 (0x01UL /*<< 0*/)
#define SR_INT_BIT                  (0x01UL << 2)

/* DR[0] */
#define DR_DIV0_0_FILED(f)          (((f) & 0x0000FFFFUL) /*<< 0*/)
#define DR_DIV0_1_FILED(f)          (((f) & 0x0000FFFFUL) << 16)

/* DR[1] */
#define DR_DIV1_0_FILED(f)          (((f) & 0x03FFUL) /*<< 0*/)
#define DR_DIV1_1_FIELD(f)          (((f) & 0x03FFUL) << 16)

/* RR */
#define RR_RST_BIT                  (0x01UL /*<< 0*/)

#endif /* _REG_I2CM_H_ */
