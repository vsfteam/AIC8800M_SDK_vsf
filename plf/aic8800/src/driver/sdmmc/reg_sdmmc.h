#ifndef _REG_SDMMC_H_
#define _REG_SDMMC_H_

#include "chip.h"

/* ================================================================================ */
/* ================                      SDMMC                     ================ */
/* ================================================================================ */
typedef struct {
    __IO uint32_t CTLR;                 /* 0x000 (R/W) : Control Register */
    __I  uint32_t RESERVED0;            /* 0x004 (R)   : Reserved */
    __O  uint32_t DWRR;                 /* 0x008 (W)   : Data Write Register */
    __I  uint32_t DRDR;                 /* 0x00C (R)   : Data Read Register */
    __I  uint32_t RESERVED1[508];       /* 0x010 (R)   : Reserved */
    __IO uint32_t CFGR;                 /* 0x800 (R/W) : Configure Register */
    __I  uint32_t GSR;                  /* 0x804 (R)   : General Status Register */
    __IO uint32_t CMDR;                 /* 0x808 (R/W) : Command Regiseter */
    __IO uint32_t ARGR;                 /* 0x80C (R/W) : Argument Register */
    __I  uint32_t RESERVED2;            /* 0x810 (R)   : Reserved */
    __I  uint32_t R3R;                  /* 0x814 (R)   : Response[3] Register */
    __I  uint32_t R2R;                  /* 0x818 (R)   : Response[2] Register */
    __I  uint32_t R1R;                  /* 0x81C (R)   : Response[1] Register */
    __I  uint32_t R0R;                  /* 0x820 (R)   : Response[0] Register */
    __IO uint32_t DBWR;                 /* 0x824 (R/W) : Data Bus Width Register */
    __IO uint32_t DBLR;                 /* 0x828 (R/W) : Data Block Length Register */
    __IO uint32_t DBCR;                 /* 0x82C (R/W) : Data Block Count Register */
    __I  uint32_t ISR;                  /* 0x830 (R)   : Interrupt Status Register */
    __IO uint32_t IER;                  /* 0x834 (R/W) : Interrupt Enable Register */
    __O  uint32_t ICR;                  /* 0x838 (W)   : Interrupt Clear Register */
    __IO uint32_t CDR;                  /* 0x83C (R/W) : Clock Divisor Register */
    __IO uint32_t CCR;                  /* 0x840 (R/W) : Clock Configure Register */
    __I  uint32_t DSR;                  /* 0x844 (R)   : Data r/w Status Register */
} AIC_SDMMC_TypeDef;

static AIC_SDMMC_TypeDef * const AIC_SDMMC = ((AIC_SDMMC_TypeDef *)AIC_SDMMC_BASE);

/* Control Register */
#define SDMMC_DATAWR_TRIGTH(n)      (((n)&0x0FUL)<<16)
#define SDMMC_DATARD_TRIGTH(n)      (((n)&0x0FUL)<<8)
#define SDMMC_DATAWR_TRIGEN         (0x01UL<<5)
#define SDMMC_DATARD_TRIGEN         (0x01UL<<4)
#define SDMMC_RESET_N               (0x01UL<<3)
#define SDMMC_ENDIAN_TYPE(n)        (((n)&0x07UL)<<0)

/* Configure Register */
#define SDMMC_AUTOCMD12_ENABLE      (0x01UL<<16)
#define SDMMC_MULTI_BLCOK_MODE      (0x01UL<<10)
#define SDMMC_WRITE_MODE            (0x01UL<<9)
#define SDMMC_RW_ENABLE             (0x01UL<<8)
#define SDMMC_RESPONSE_CONFIG(n)    (((n)&0x03UL)<<5)
#define SDMMC_CONFIG_Rx             SDMMC_RESPONSE_CONFIG(0)
#define SDMMC_CONFIG_R3             SDMMC_RESPONSE_CONFIG(1)
#define SDMMC_CONFIG_R2             SDMMC_RESPONSE_CONFIG(2)
#define SDMMC_RESPONSE_ENABLE       (0x01UL<<4)
#define SDMMC_COMMAND_START         (0x01UL<<0)

/* General Status Register */
#define SDMMC_DATA_CRCERROR_LSB     (16)
#define SDMMC_RESPONSE_NONE_ERROR   (0x01UL<<9)
#define SDMMC_RESPONSE_CRC_ERROR    (0x01UL<<8)
#define SDMMC_DATABUS_BUSY          (0x01UL<<2)
#define SDMMC_HOST_BUSY             (0x01UL<<1)
#define SDMMC_COMMAND_NOT_OVER      (0x01UL<<0)

/* Command Regiseter */
#define SDMMC_COMMAND_INDEX(n)      (((n)&0x3FUL)<<0)

/* Interrupt Status Register */
#define SDMMC_DATA_DONE_FLAG        (0x01UL<<4)

/* Interrupt Clear Register */
#define SDMMC_DATA_DONE_CLEAR       (0x01UL<<4)

/* Clock Configure Register */
#define SDMMC_CLOCK_INVERT_ENABLE   (0x01UL<<4)

/* Data r/w Status Register */
#define SDMMC_DATAWR_COUNT_LSB      (16)
#define SDMMC_DATARD_COUNT_LSB      (8)

#endif /* _REG_SDMMC_H_ */
