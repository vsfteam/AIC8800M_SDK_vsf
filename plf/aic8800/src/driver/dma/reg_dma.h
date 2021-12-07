#ifndef _REG_DMA_H_
#define _REG_DMA_H_

#include "chip.h"
#include "compiler.h"
#include "dbg_assert.h"

/* ========================================================================== */
/* ================         Direct Memory Access (DMA)       ================ */
/* ========================================================================== */
typedef struct {
    __I  uint32_t RESERVED0[6];         /* 0x000 (R)   : Reserved */
    __I  uint32_t RSR;                  /* 0x018 (R)   : Req St Reg */
    __I  uint32_t RESERVED1[1017];      /* 0x01C (R)   : Reserved */

    struct {
        __IO uint32_t HLTR;             /* 0x000 (R/W) : Hlt Reg */
        __IO uint32_t RQR;              /* 0x004 (R/W) : ReQ Reg */
        __IO uint32_t CTLR;             /* 0x008 (R/W) : Ctrl Reg */
        __IO uint32_t ICSR;             /* 0x00C (R/W) : Int Ctrl & St Reg */
        __IO uint32_t SAR;              /* 0x010 (R/W) : Src Addr Reg */
        __IO uint32_t DAR;              /* 0x014 (R/W) : Dest Addr Reg */
        __IO uint32_t TBL0CR;           /* 0x018 (R/W) : Trans Blk Lvl-0 Cnt Reg */
        __IO uint32_t TBL1CR;           /* 0x01C (R/W) : Trans Blk Lvl-1 Cnt Reg */
        __IO uint32_t TBL2CR;           /* 0x020 (R/W) : Trans Blk Lvl-2 Cnt Reg */
        __IO uint32_t TSR;              /* 0x024 (R/W) : Trans Sz Reg */
        __IO uint32_t WMAR;             /* 0x028 (R/W) : Wrp Match Addr Reg */
        __IO uint32_t WJAR;             /* 0x02C (R/W) : Wrp Jump Addr Reg */
        __IO uint32_t LNAR;             /* 0x030 (R/W) : Lli Node Addr Reg (DWord Align) */
        __IO uint32_t TBL0SR;           /* 0x034 (R/W) : Trans Blk Lvl-0 Sz Reg */
        __IO uint32_t TBL1SSR;          /* 0x038 (R/W) : Trans Blk Lvl-1 Src Sz Reg */
        __IO uint32_t TBL1DSR;          /* 0x03C (R/W) : Trans Blk Lvl-1 Dest Sz Reg */
    } CH[14];
    __I  uint32_t RESERVED3[800];       /* 0x380 (R)   : Reserved */

    __IO uint32_t ERQCSR[24];           /* 0x000 (R/W) : Ex ReQ Ch Sel Reg */
    __I  uint32_t RESERVED4[40];        /* 0x060 (R)   : Reserved */

    struct {
        __I  uint32_t RDMR;             /* 0x100 (R)   : Rd Mon Reg */
        __I  uint32_t WRMR;             /* 0x104 (R)   : Wr Mon Reg */
    } CH_ADDR[14];

    __I  uint32_t RESERVED5[36];        /* 0x170 (R)   : Reserved */
    __IO uint32_t LLINCR[14];           /* 0x200 (R/W) : LLI Node Cnt Reg */
} AIC_DMA_TypeDef;

/* ========================================================================== */
/* ====================         Crypto Engine (CE)       ==================== */
/* ========================================================================== */
typedef struct {
    __IO uint32_t AES_KEY_0_ADDR;       /* 0x044 (R/W) : */
    __IO uint32_t AES_KEY_1_ADDR;       /* 0x048 (R/W) : */
    __IO uint32_t AES_KEY_2_ADDR;       /* 0x04C (R/W) : */
    __IO uint32_t AES_KEY_3_ADDR;       /* 0x050 (R/W) : */
    __IO uint32_t AES_KEY_4_ADDR;       /* 0x054 (R/W) : */
    __IO uint32_t AES_KEY_5_ADDR;       /* 0x058 (R/W) : */
    __IO uint32_t AES_KEY_6_ADDR;       /* 0x05C (R/W) : */
    __IO uint32_t AES_KEY_7_ADDR;       /* 0x060 (R/W) : */
    __IO uint32_t AES_IV_0_ADDR;        /* 0x064 (R/W) : */
    __IO uint32_t AES_IV_1_ADDR;        /* 0x068 (R/W) : */
    __IO uint32_t AES_IV_2_ADDR;        /* 0x06C (R/W) : */
    __IO uint32_t AES_IV_3_ADDR;        /* 0x070 (R/W) : */
    __IO uint32_t AES_PLAIN_LEN_H_ADDR; /* 0x074 (R/W) : */
    __IO uint32_t AES_PLAIN_LEN_L_ADDR; /* 0x078 (R/W) : */
    __IO uint32_t AES_A_LEN_H_ADDR;     /* 0x07C (R/W) : */
    __IO uint32_t AES_A_LEN_L_ADDR;     /* 0x080 (R/W) : */
    __IO uint32_t CE_CTRL_ADDR;         /* 0x084 (R/W) : */
    __IO uint32_t PKA_REG0_ADDR;        /* 0x088 (R/W) : */
    __IO uint32_t CE_CLOCK_GATE_CTRL;   /* 0x08C (R/W) : */
    __I  uint32_t RESERVED0[3];         /* 0x090 (R)   : */
    __IO uint32_t DMA_MON_SEL;          /* 0x09C (R/W) : */
    __I  uint32_t RESERVED1[6];         /* 0x0A0 (R)   : */
    __IO uint32_t CHKSUM_CTRL_ADDR;     /* 0x0B8 (R/W) : */
    __IO uint32_t CHKSUM_RES_ADDR;      /* 0x0BC (R/W) : */
    __IO uint32_t HASH_LEN_ADDR;        /* 0x0C0 (R/W) : */
    __IO uint32_t CE_CTRL2_ADDR;        /* 0x0C4 (R/W) : */
} AIC_CE_TypeDef;

/* ========================================================================== */
/* ========================           TRANS          ======================== */
/* ========================================================================== */
typedef struct {
    __IO uint32_t TRANS_CTRL0_ADDR;     /* 0x090 (R/W) : */
    __IO uint32_t TRANS_CTRL1_ADDR;     /* 0x094 (R/W) : */
    __IO uint32_t TRANS_CLOCK_GATE_CTRL;/* 0x098 (R/W) : */
} AIC_TRANS_TypeDef;

#define AIC_CE_OFST     (0x0044)
#define AIC_TRANS_OFST  (0x0090)

static AIC_DMA_TypeDef   * const AIC_DMA   = ((AIC_DMA_TypeDef   *) AIC_DMA_BASE);
static AIC_CE_TypeDef    * const AIC_CE    = ((AIC_CE_TypeDef    *)(AIC_DMA_BASE + AIC_CE_OFST));
static AIC_TRANS_TypeDef * const AIC_TRANS = ((AIC_TRANS_TypeDef *)(AIC_DMA_BASE + AIC_TRANS_OFST));

/**
 * CH_HLTR
 */

#define DMA_CH_HALT_SET_POS             (0)
#define DMA_CH_HALT_SET_BIT             (0x01UL << DMA_CH_HALT_SET_POS)
#define DMA_CH_HALT_STAT_POS            (16)
#define DMA_CH_HALT_STAT_BIT            (0x01UL << DMA_CH_HALT_STAT_POS)

__STATIC_INLINE uint32_t dma_ch_hltr_halt_set_getb(int ch_idx)
{
    return (AIC_DMA->CH[ch_idx].HLTR & DMA_CH_HALT_SET_BIT);
}

__STATIC_INLINE void dma_ch_hltr_halt_set_setb(int ch_idx)
{
    AIC_DMA->CH[ch_idx].HLTR |= DMA_CH_HALT_SET_BIT;
}

__STATIC_INLINE void dma_ch_hltr_halt_set_clrb(int ch_idx)
{
    AIC_DMA->CH[ch_idx].HLTR &= ~DMA_CH_HALT_SET_BIT;
}

__STATIC_INLINE uint32_t dma_ch_hltr_halt_stat_getb(int ch_idx)
{
    return (AIC_DMA->CH[ch_idx].HLTR & DMA_CH_HALT_STAT_BIT);
}

/**
 * CH_RQR
 */

#define DMA_CH_SRQ_POS                  (0)
#define DMA_CH_SRQ_BIT                  (0x01UL << DMA_CH_SRQ_POS)
#define DMA_CH_ERQM_POS                 (1)
#define DMA_CH_ERQM_BIT                 (0x01UL << DMA_CH_ERQM_POS)
#define DMA_CH_ERQL_POS                 (2)
#define DMA_CH_ERQL_BIT                 (0x01UL << DMA_CH_ERQL_POS)

__STATIC_INLINE uint32_t dma_ch_rqr_srq_getb(int ch_idx)
{
    return (AIC_DMA->CH[ch_idx].RQR & DMA_CH_SRQ_BIT);
}

__STATIC_INLINE void dma_ch_rqr_srq_setb(int ch_idx)
{
    AIC_DMA->CH[ch_idx].RQR |= DMA_CH_SRQ_BIT;
}

__STATIC_INLINE void dma_ch_rqr_srq_clrb(int ch_idx)
{
    AIC_DMA->CH[ch_idx].RQR &= ~DMA_CH_SRQ_BIT;
}

__STATIC_INLINE uint32_t dma_ch_rqr_erqm_getb(int ch_idx)
{
    return (AIC_DMA->CH[ch_idx].RQR & DMA_CH_ERQM_BIT);
}

__STATIC_INLINE void dma_ch_rqr_erqm_setb(int ch_idx)
{
    AIC_DMA->CH[ch_idx].RQR |= DMA_CH_ERQM_BIT;
}

__STATIC_INLINE void dma_ch_rqr_erqm_clrb(int ch_idx)
{
    AIC_DMA->CH[ch_idx].RQR &= ~DMA_CH_ERQM_BIT;
}

__STATIC_INLINE uint32_t dma_ch_rqr_erql_getb(int ch_idx)
{
    return (AIC_DMA->CH[ch_idx].RQR & DMA_CH_ERQL_BIT);
}

__STATIC_INLINE void dma_ch_rqr_erql_setb(int ch_idx)
{
    AIC_DMA->CH[ch_idx].RQR |= DMA_CH_ERQL_BIT;
}

__STATIC_INLINE void dma_ch_rqr_erql_clrb(int ch_idx)
{
    AIC_DMA->CH[ch_idx].RQR &= ~DMA_CH_ERQL_BIT;
}

/**
 * CH_CTLR
 */

#define DMA_CH_CHENA_POS                (0)
#define DMA_CH_CHENA_BIT                (0x01UL << DMA_CH_CHENA_POS)
#define DMA_CH_LSTENA_POS               (4)
#define DMA_CH_LSTENA_BIT               (0x01UL << DMA_CH_LSTENA_POS)
#define DMA_CH_BUSBU_LSB                (16)
#define DMA_CH_BUSBU_WIDTH              (0x02UL)
#define DMA_CH_BUSBU_MASK               (((0x01UL << DMA_CH_BUSBU_WIDTH) - 1) << DMA_CH_BUSBU_LSB)

__STATIC_INLINE uint32_t dma_ch_ctlr_get(int ch_idx)
{
    return (AIC_DMA->CH[ch_idx].CTLR);
}

__STATIC_INLINE void dma_ch_ctlr_set(int ch_idx, uint32_t reg_val)
{
    AIC_DMA->CH[ch_idx].CTLR = reg_val;
}

__STATIC_INLINE uint32_t dma_ch_ctlr_chena_getb(int ch_idx)
{
    return (AIC_DMA->CH[ch_idx].CTLR & DMA_CH_CHENA_BIT);
}

__STATIC_INLINE void dma_ch_ctlr_chena_setb(int ch_idx)
{
    AIC_DMA->CH[ch_idx].CTLR |= DMA_CH_CHENA_BIT;
}

__STATIC_INLINE void dma_ch_ctlr_chena_clrb(int ch_idx)
{
    AIC_DMA->CH[ch_idx].CTLR &= ~DMA_CH_CHENA_BIT;
}

/**
 * CH_ICSR
 */

#define DMA_CH_TBL0_IENA_POS                    (0)
#define DMA_CH_TBL1_IENA_POS                    (1)
#define DMA_CH_TBL2_IENA_POS                    (2)
#define DMA_CH_TLL_IENA_POS                     (3)
#define DMA_CH_CE_IENA_POS                      (4)
#define DMA_CH_TBL0_IRST_POS                    (8)
#define DMA_CH_TBL1_IRST_POS                    (9)
#define DMA_CH_TBL2_IRST_POS                    (10)
#define DMA_CH_TLL_IRST_POS                     (11)
#define DMA_CH_CE_IRST_POS                      (12)
#define DMA_CH_TBL0_IMST_POS                    (16)
#define DMA_CH_TBL1_IMST_POS                    (17)
#define DMA_CH_TBL2_IMST_POS                    (18)
#define DMA_CH_TLL_IMST_POS                     (19)
#define DMA_CH_CE_IMST_POS                      (20)
#define DMA_CH_PKAD_IMST_POS                    (22)
#define DMA_CH_TBL0_ICLR_POS                    (24)
#define DMA_CH_TBL1_ICLR_POS                    (25)
#define DMA_CH_TBL2_ICLR_POS                    (26)
#define DMA_CH_TLL_ICLR_POS                     (27)
#define DMA_CH_CE_ICLR_POS                      (28)
#define DMA_CH_PKAD_ICLR_POS                    (30)

#define DMA_CH_TBL0_IENA_BIT                    (0x01UL << DMA_CH_TBL0_IENA_POS             )
#define DMA_CH_TBL1_IENA_BIT                    (0x01UL << DMA_CH_TBL1_IENA_POS             )
#define DMA_CH_TBL2_IENA_BIT                    (0x01UL << DMA_CH_TBL2_IENA_POS             )
#define DMA_CH_TLL_IENA_BIT                     (0x01UL << DMA_CH_TLL_IENA_POS              )
#define DMA_CH_CE_IENA_BIT                      (0x01UL << DMA_CH_CE_IENA_POS               )
#define DMA_CH_TBL0_IRST_BIT                    (0x01UL << DMA_CH_TBL0_IRST_POS     )
#define DMA_CH_TBL1_IRST_BIT                    (0x01UL << DMA_CH_TBL1_IRST_POS     )
#define DMA_CH_TBL2_IRST_BIT                    (0x01UL << DMA_CH_TBL2_IRST_POS     )
#define DMA_CH_TLL_IRST_BIT                     (0x01UL << DMA_CH_TLL_IRST_POS      )
#define DMA_CH_CE_IRST_BIT                      (0x01UL << DMA_CH_CE_IRST_POS       )
#define DMA_CH_TBL0_IMST_BIT                    (0x01UL << DMA_CH_TBL0_IMST_POS     )
#define DMA_CH_TBL1_IMST_BIT                    (0x01UL << DMA_CH_TBL1_IMST_POS     )
#define DMA_CH_TBL2_IMST_BIT                    (0x01UL << DMA_CH_TBL2_IMST_POS     )
#define DMA_CH_TLL_IMST_BIT                     (0x01UL << DMA_CH_TLL_IMST_POS      )
#define DMA_CH_CE_IMST_BIT                      (0x01UL << DMA_CH_CE_IMST_POS       )
#define DMA_CH_PKAD_IMST_BIT                    (0x01UL << DMA_CH_PKAD_IMST_POS     )
#define DMA_CH_TBL0_ICLR_BIT                    (0x01UL << DMA_CH_TBL0_ICLR_POS     )
#define DMA_CH_TBL1_ICLR_BIT                    (0x01UL << DMA_CH_TBL1_ICLR_POS     )
#define DMA_CH_TBL2_ICLR_BIT                    (0x01UL << DMA_CH_TBL2_ICLR_POS     )
#define DMA_CH_TLL_ICLR_BIT                     (0x01UL << DMA_CH_TLL_ICLR_POS      )
#define DMA_CH_CE_ICLR_BIT                      (0x01UL << DMA_CH_CE_ICLR_POS       )
#define DMA_CH_PKAD_ICLR_BIT                    (0x01UL << DMA_CH_PKAD_ICLR_POS     )

__STATIC_INLINE uint32_t dma_ch_icsr_get(int ch_idx)
{
    return (AIC_DMA->CH[ch_idx].ICSR);
}

__STATIC_INLINE void dma_ch_icsr_set(int ch_idx, uint32_t reg_val)
{
    AIC_DMA->CH[ch_idx].ICSR = reg_val;
}

__STATIC_INLINE uint32_t dma_ch_icsr_tbl0_iena_getb(int ch_idx)
{
    return (AIC_DMA->CH[ch_idx].ICSR & DMA_CH_TBL0_IENA_BIT);
}

__STATIC_INLINE void dma_ch_icsr_tbl0_iena_setb(int ch_idx)
{
    AIC_DMA->CH[ch_idx].ICSR |= DMA_CH_TBL0_IENA_BIT;
}

__STATIC_INLINE void dma_ch_icsr_tbl0_iena_clrb(int ch_idx)
{
    AIC_DMA->CH[ch_idx].ICSR &= ~DMA_CH_TBL0_IENA_BIT;
}

__STATIC_INLINE uint32_t dma_ch_icsr_tbl1_iena_getb(int ch_idx)
{
    return (AIC_DMA->CH[ch_idx].ICSR & DMA_CH_TBL1_IENA_BIT);
}

__STATIC_INLINE void dma_ch_icsr_tbl1_iena_setb(int ch_idx)
{
    AIC_DMA->CH[ch_idx].ICSR |= DMA_CH_TBL1_IENA_BIT;
}

__STATIC_INLINE void dma_ch_icsr_tbl1_iena_clrb(int ch_idx)
{
    AIC_DMA->CH[ch_idx].ICSR &= ~DMA_CH_TBL1_IENA_BIT;
}

__STATIC_INLINE uint32_t dma_ch_icsr_tbl2_iena_getb(int ch_idx)
{
    return (AIC_DMA->CH[ch_idx].ICSR & DMA_CH_TBL2_IENA_BIT);
}

__STATIC_INLINE void dma_ch_icsr_tbl2_iena_setb(int ch_idx)
{
    AIC_DMA->CH[ch_idx].ICSR |= DMA_CH_TBL2_IENA_BIT;
}

__STATIC_INLINE void dma_ch_icsr_tbl2_iena_clrb(int ch_idx)
{
    AIC_DMA->CH[ch_idx].ICSR &= ~DMA_CH_TBL2_IENA_BIT;
}

__STATIC_INLINE uint32_t dma_ch_icsr_tll_iena_getb(int ch_idx)
{
    return (AIC_DMA->CH[ch_idx].ICSR & DMA_CH_TLL_IENA_BIT);
}

__STATIC_INLINE void dma_ch_icsr_tll_iena_setb(int ch_idx)
{
    AIC_DMA->CH[ch_idx].ICSR |= DMA_CH_TLL_IENA_BIT;
}

__STATIC_INLINE void dma_ch_icsr_tll_iena_clrb(int ch_idx)
{
    AIC_DMA->CH[ch_idx].ICSR &= ~DMA_CH_TLL_IENA_BIT;
}

__STATIC_INLINE uint32_t dma_ch_icsr_ce_iena_getb(int ch_idx)
{
    return (AIC_DMA->CH[ch_idx].ICSR & DMA_CH_CE_IENA_BIT);
}

__STATIC_INLINE void dma_ch_icsr_ce_iena_setb(int ch_idx)
{
    AIC_DMA->CH[ch_idx].ICSR |= DMA_CH_CE_IENA_BIT;
}

__STATIC_INLINE void dma_ch_icsr_ce_iena_clrb(int ch_idx)
{
    AIC_DMA->CH[ch_idx].ICSR &= ~DMA_CH_CE_IENA_BIT;
}

__STATIC_INLINE uint32_t dma_ch_icsr_tbl0_irst_getb(int ch_idx)
{
    return (AIC_DMA->CH[ch_idx].ICSR & DMA_CH_TBL0_IRST_BIT);
}

__STATIC_INLINE uint32_t dma_ch_icsr_tbl1_irst_getb(int ch_idx)
{
    return (AIC_DMA->CH[ch_idx].ICSR & DMA_CH_TBL1_IRST_BIT);
}

__STATIC_INLINE uint32_t dma_ch_icsr_tbl2_irst_getb(int ch_idx)
{
    return (AIC_DMA->CH[ch_idx].ICSR & DMA_CH_TBL2_IRST_BIT);
}

__STATIC_INLINE uint32_t dma_ch_icsr_tll_irst_getb(int ch_idx)
{
    return (AIC_DMA->CH[ch_idx].ICSR & DMA_CH_TLL_IRST_BIT);
}

__STATIC_INLINE uint32_t dma_ch_icsr_ce_irst_getb(int ch_idx)
{
    return (AIC_DMA->CH[ch_idx].ICSR & DMA_CH_CE_IRST_BIT);
}

__STATIC_INLINE uint32_t dma_ch_icsr_tbl0_imst_getb(int ch_idx)
{
    return (AIC_DMA->CH[ch_idx].ICSR & DMA_CH_TBL0_IMST_BIT);
}

__STATIC_INLINE uint32_t dma_ch_icsr_tbl1_imst_getb(int ch_idx)
{
    return (AIC_DMA->CH[ch_idx].ICSR & DMA_CH_TBL1_IMST_BIT);
}

__STATIC_INLINE uint32_t dma_ch_icsr_tbl2_imst_getb(int ch_idx)
{
    return (AIC_DMA->CH[ch_idx].ICSR & DMA_CH_TBL2_IMST_BIT);
}

__STATIC_INLINE uint32_t dma_ch_icsr_tll_imst_getb(int ch_idx)
{
    return (AIC_DMA->CH[ch_idx].ICSR & DMA_CH_TLL_IMST_BIT);
}

__STATIC_INLINE uint32_t dma_ch_icsr_cfgerr_int_mask_status_getb(int ch_idx)
{
    return (AIC_DMA->CH[ch_idx].ICSR & DMA_CH_CE_IMST_BIT);
}

__STATIC_INLINE uint32_t dma_ch_icsr_pkad_imst_getb(int ch_idx)
{
    return (AIC_DMA->CH[ch_idx].ICSR & DMA_CH_PKAD_IMST_BIT);
}

__STATIC_INLINE void dma_ch_icsr_tbl0_iclr_setb(int ch_idx)
{
    AIC_DMA->CH[ch_idx].ICSR |= DMA_CH_TBL0_ICLR_BIT;
}

__STATIC_INLINE void dma_ch_icsr_tbl1_iclr_setb(int ch_idx)
{
    AIC_DMA->CH[ch_idx].ICSR |= DMA_CH_TBL1_ICLR_BIT;
}

__STATIC_INLINE void dma_ch_icsr_tbl2_iclr_setb(int ch_idx)
{
    AIC_DMA->CH[ch_idx].ICSR |= DMA_CH_TBL2_ICLR_BIT;
}

__STATIC_INLINE void dma_ch_icsr_tll_iclr_setb(int ch_idx)
{
    AIC_DMA->CH[ch_idx].ICSR |= DMA_CH_TLL_ICLR_BIT;
}

__STATIC_INLINE void dma_ch_icsr_ce_iclr_setb(int ch_idx)
{
    AIC_DMA->CH[ch_idx].ICSR |= DMA_CH_CE_ICLR_BIT;
}

__STATIC_INLINE void dma_ch_icsr_pkad_iclr_setb(int ch_idx)
{
    AIC_DMA->CH[ch_idx].ICSR |= DMA_CH_PKAD_ICLR_BIT;
}

/**
 * CH_SAR
 */

__STATIC_INLINE uint32_t dma_ch_sar_get(int ch_idx)
{
    return (AIC_DMA->CH[ch_idx].SAR);
}

__STATIC_INLINE void dma_ch_sar_set(int ch_idx, uint32_t reg_val)
{
    AIC_DMA->CH[ch_idx].SAR = reg_val;
}

/**
 * CH_DAR
 */

__STATIC_INLINE uint32_t dma_ch_dar_get(int ch_idx)
{
    return (AIC_DMA->CH[ch_idx].DAR);
}

__STATIC_INLINE void dma_ch_dar_set(int ch_idx, uint32_t reg_val)
{
    AIC_DMA->CH[ch_idx].DAR = reg_val;
}

/**
 * CH_TBL0CR
 */

#define DMA_CH_TBL0_CNT_LSB         (0)
#define DMA_CH_TBL0_CNT_WIDTH       (0x11UL)
#define DMA_CH_TBL0_CNT_MASK        (((0x01UL << DMA_CH_TBL0_CNT_WIDTH) - 1) << DMA_CH_TBL0_CNT_LSB)
#define DMA_CH_LASTLLI_POS          (19)
#define DMA_CH_LASTLLI_BIT          (0x01UL << DMA_CH_LASTLLI_POS)
#define DMA_CH_CONSTSA_POS          (20)
#define DMA_CH_CONSTSA_BIT          (0x01UL << DMA_CH_CONSTSA_POS)
#define DMA_CH_CONSTDA_POS          (21)
#define DMA_CH_CONSTDA_BIT          (0x01UL << DMA_CH_CONSTDA_POS)
#define DMA_CH_RQTYP_LSB            (24)
#define DMA_CH_RQTYP_WIDTH          (0x02UL)
#define DMA_CH_RQTYP_MASK           (((0x01UL << DMA_CH_RQTYP_WIDTH) - 1) << DMA_CH_RQTYP_LSB)
#define DMA_CH_DBUSU_LSB            (28)
#define DMA_CH_DBUSU_WIDTH          (0x02UL)
#define DMA_CH_DBUSU_MASK           (((0x01UL << DMA_CH_DBUSU_WIDTH) - 1) << DMA_CH_DBUSU_LSB)
#define DMA_CH_SBUSU_LSB            (30)
#define DMA_CH_SBUSU_WIDTH          (0x02UL)
#define DMA_CH_SBUSU_MASK           (((0x01UL << DMA_CH_SBUSU_WIDTH) - 1) << DMA_CH_SBUSU_LSB)

__STATIC_INLINE uint32_t dma_ch_tbl0cr_get(int ch_idx)
{
    return (AIC_DMA->CH[ch_idx].TBL0CR);
}

__STATIC_INLINE void dma_ch_tbl0cr_set(int ch_idx, uint32_t reg_val)
{
    AIC_DMA->CH[ch_idx].TBL0CR = reg_val;
}

__STATIC_INLINE uint32_t dma_ch_tbl0cr_tbl0_cnt_getf(int ch_idx)
{
    return ((AIC_DMA->CH[ch_idx].TBL0CR & DMA_CH_TBL0_CNT_MASK) >> DMA_CH_TBL0_CNT_LSB);
}

__STATIC_INLINE void dma_ch_tbl0cr_tbl0_cnt_setf(int ch_idx, uint32_t cnt)
{
    uint32_t local_val;
    local_val = AIC_DMA->CH[ch_idx].TBL0CR & ~DMA_CH_TBL0_CNT_MASK;
    AIC_DMA->CH[ch_idx].TBL0CR = local_val | ((cnt << DMA_CH_TBL0_CNT_LSB) & DMA_CH_TBL0_CNT_MASK);
}

__STATIC_INLINE uint32_t dma_ch_tbl0cr_lastlli_getb(int ch_idx)
{
    return (AIC_DMA->CH[ch_idx].TBL0CR & DMA_CH_LASTLLI_BIT);
}

__STATIC_INLINE void dma_ch_tbl0cr_lastlli_setb(int ch_idx)
{
    AIC_DMA->CH[ch_idx].TBL0CR |= DMA_CH_LASTLLI_BIT;
}

__STATIC_INLINE void dma_ch_tbl0cr_lastlli_clrb(int ch_idx)
{
    AIC_DMA->CH[ch_idx].TBL0CR &= ~DMA_CH_LASTLLI_BIT;
}

/**
 * CH_TBL1CR
 */

#define DMA_CH_TBL1_CNT_LSB             (0)
#define DMA_CH_TBL1_CNT_WIDTH           (0x11UL)
#define DMA_CH_TBL1_CNT_MASK            (((0x01UL << DMA_CH_TBL1_CNT_WIDTH) - 1) << DMA_CH_TBL1_CNT_LSB)

__STATIC_INLINE uint32_t dma_ch_tbl1cr_get(int ch_idx)
{
    return (AIC_DMA->CH[ch_idx].TBL1CR);
}

__STATIC_INLINE void dma_ch_tbl1cr_set(int ch_idx, uint32_t reg_val)
{
    AIC_DMA->CH[ch_idx].TBL1CR = reg_val;
}

/**
 * CH_TBL2CR
 */

#define DMA_CH_TBL2_CNT_LSB                 (0)
#define DMA_CH_TBL2_CNT_WIDTH               (0x1CUL)
#define DMA_CH_TBL2_CNT_MASK                (((0x01UL << DMA_CH_TBL2_CNT_WIDTH) - 1) << DMA_CH_TBL2_CNT_LSB)
#define DMA_CH_LLI_DEDIC_INT_EN_POS         (28)
#define DMA_CH_LLI_DEDIC_INT_EN_BIT         (0x01UL << DMA_CH_LLI_DEDIC_INT_EN_POS)
#define DMA_CH_LLI_DEDIC_COUNTER_EN_POS     (29)
#define DMA_CH_LLI_DEDIC_COUNTER_EN_BIT     (0x01UL << DMA_CH_LLI_DEDIC_COUNTER_EN_POS)

__STATIC_INLINE uint32_t dma_ch_tbl2cr_get(int ch_idx)
{
    return (AIC_DMA->CH[ch_idx].TBL2CR);
}

__STATIC_INLINE void dma_ch_tbl2cr_set(int ch_idx, uint32_t reg_val)
{
    AIC_DMA->CH[ch_idx].TBL2CR = reg_val;
}

/**
 * CH_TSR
 */

#define DMA_CH_STRANSZ_LSB          (0)
#define DMA_CH_STRANSZ_WIDTH        (0x10UL)
#define DMA_CH_STRANSZ_MASK         (((0x01UL << DMA_CH_STRANSZ_WIDTH) - 1) << DMA_CH_STRANSZ_LSB)
#define DMA_CH_DTRANSZ_LSB          (16)
#define DMA_CH_DTRANSZ_WIDTH        (0x10UL)
#define DMA_CH_DTRANSZ_MASK         (((0x01UL << DMA_CH_DTRANSZ_WIDTH) - 1) << DMA_CH_DTRANSZ_LSB)

__STATIC_INLINE uint32_t dma_ch_tsr_get(int ch_idx)
{
    return (AIC_DMA->CH[ch_idx].TSR);
}

__STATIC_INLINE void dma_ch_tsr_set(int ch_idx, uint32_t reg_val)
{
    AIC_DMA->CH[ch_idx].TSR = reg_val;
}

/**
 * CH_WMAR
 */

__STATIC_INLINE uint32_t dma_ch_wmar_get(int ch_idx)
{
    return (AIC_DMA->CH[ch_idx].WMAR);
}

__STATIC_INLINE void dma_ch_wmar_set(int ch_idx, uint32_t reg_val)
{
    AIC_DMA->CH[ch_idx].WMAR = reg_val;
}

/**
 * CH_WJAR
 */

__STATIC_INLINE uint32_t dma_ch_wjar_get(int ch_idx)
{
    return (AIC_DMA->CH[ch_idx].WJAR);
}

__STATIC_INLINE void dma_ch_wjar_set(int ch_idx, uint32_t reg_val)
{
    AIC_DMA->CH[ch_idx].WJAR = reg_val;
}

/**
 * CH_LNAR
 */

__STATIC_INLINE uint32_t dma_ch_lnar_get(int ch_idx)
{
    return (AIC_DMA->CH[ch_idx].LNAR);
}

__STATIC_INLINE void dma_ch_lnar_set(int ch_idx, uint32_t reg_val)
{
    AIC_DMA->CH[ch_idx].LNAR = reg_val;
}

/**
 * CH_TBL0SR
 */

#define DMA_CH_STBL0SZ_LSB              (0)
#define DMA_CH_STBL0SZ_WIDTH            (0x10UL)
#define DMA_CH_STBL0SZ_MASK             (((0x01UL << DMA_CH_STBL0SZ_WIDTH) - 1) << DMA_CH_STBL0SZ_LSB)
#define DMA_CH_DTBL0SZ_LSB              (16)
#define DMA_CH_DTBL0SZ_WIDTH            (0x10UL)
#define DMA_CH_DTBL0SZ_MASK             (((0x01UL << DMA_CH_DTBL0SZ_WIDTH) - 1) << DMA_CH_DTBL0SZ_LSB)

__STATIC_INLINE uint32_t dma_ch_tbl0sr_get(int ch_idx)
{
    return (AIC_DMA->CH[ch_idx].TBL0SR);
}

__STATIC_INLINE void dma_ch_tbl0sr_set(int ch_idx, uint32_t reg_val)
{
    AIC_DMA->CH[ch_idx].TBL0SR = reg_val;
}

/**
 * CH_TBL1SSR
 */

__STATIC_INLINE uint32_t dma_ch_tbl1ssr_get(int ch_idx)
{
    return (AIC_DMA->CH[ch_idx].TBL1SSR);
}

__STATIC_INLINE void dma_ch_tbl1ssr_set(int ch_idx, uint32_t reg_val)
{
    AIC_DMA->CH[ch_idx].TBL1SSR = reg_val;
}

/**
 * CH_TBL1DSR
 */

__STATIC_INLINE uint32_t dma_ch_tbl1dsr_get(int ch_idx)
{
    return (AIC_DMA->CH[ch_idx].TBL1DSR);
}

__STATIC_INLINE void dma_ch_tbl1dsr_set(int ch_idx, uint32_t reg_val)
{
    AIC_DMA->CH[ch_idx].TBL1DSR = reg_val;
}

/**
 * ERQCSR
 */

__STATIC_INLINE void dma_erqcsr_set(int erq_idx, int ch_idx)
{
    AIC_DMA->ERQCSR[erq_idx] = ch_idx + 1;
}

/**
 * RSR
 */

__STATIC_INLINE uint32_t dma_req_status_get(int ch_idx)
{
    return (AIC_DMA->RSR & (1 << ch_idx));
}

/**
 * CH_LLINCR
 */

__STATIC_INLINE uint32_t dma_ch_llincr_get(int ch_idx)
{
    return (AIC_DMA->LLINCR[ch_idx]);
}

#define RSA_EN_OFFSET             0
#define ECC_EN_OFFSET             1
#define RSA_MODE_OFFSET           2
#define ECC_MODE_OFFSET           3
#define ECC_A_EQ_P3_EN_OFFSET     6
#define RSA_KEY_LEN_OFFSET        7
#define AES_EN_OFFSET             13
#define AES_ENC_DEC_SEL_OFFEST    14
#define AES_MODE_OFFEST           15
#define AES_KEY_192_OFFEST        18
#define AES_KEY_256_OFFEST        19
#define HASH_EN_OFFSET            20
#define CYPT_CHN_SEL_OFFSET       21
#define HASH_ENDIAN_SEL_OFFSET    28
#define AES_ENDIAN_SEL_OFFSET     29
#define HASH_HW_PAD_EN_OFFSET     0
#define HASH_MODE_SEL_OFFSET      1

#define DMA_RSA_EN_SET            (0x01UL << RSA_EN_OFFSET)
#define DMA_ECC_EN_SET            (0x01UL << ECC_EN_OFFSET)
#define DMA_AES_EN_SET            (0x01UL << AES_EN_OFFSET)
#define DMA_HASH_EN_SET           (0x01UL << HASH_EN_OFFSET)

#define FFT_LEN_OFFSET            0
#define FFT_SCALE_OFFSET          3
#define FFT_DIR_OFFSET            6
#define FFT_EN_OFFSET             7
#define TRANS_CHN_SEL_OFFSET      8
#define FFT_IN_FORMAT_SEL_OFFSET  14
#define FFT_OUT_FORMAT_SEL_OFFSET 15
#define FLT_EN_OFFSET             0
#define FIR_COFSHW_UPD_OFFSET     1
#define SBC_MODE_EN_OFFSET        2
#define FIR_COFCOS_UPD_OFFSET     3
#define FIR_COFLEN_OFFSET         4
#define FLT_LEN_OFFSET            5
#define FLT_ORDER_OFFSET          19
#define FLT_COFINIT_SEL_OFFSET    24
#define FLT_SBC_CHN_SEL_OFFSET    25
#define FLT_IN_FORMAT_SEL_OFFSET  26
#define FLT_OUT_FORMAT_SEL_OFFSET 27
#define SBC_SSAT_EN_OFFSET        28

#define DMA_FFT_EN_SET            (0x01UL << FFT_EN_OFFSET)
#define DMA_FLT_EN_SET            (0x01UL << FLT_EN_OFFSET)

#define CHKSUM_LEN_OFFSET         0
#define CHKSUM_EN_OFFSET          16
#define CHKSUM_CHN_SEL_OFFSET     17
#define CHKSUM_ENDIAN_SEL_OFFSET  23
#define CHKSUM_DEST_BYPASS_OFFSET 24
#define CHKSUM_CLK_GATE_EN        25
#define CHKSUM_CLR_OFFSET         30
#define DMA_CHKSUM_EN_SET          (0x01UL << CHKSUM_EN_OFFSET)
#define DMA_CHKSUM_CLK_GATE_EN_SET (0x01UL << CHKSUM_CLK_GATE_EN)

#define DMA_PKA_CLK_GATE_EN_OFFSET 0
#define DMA_AES_CLK_GATE_EN_OFFSET 1
#define DMA_HASH_CLK_GATE_EN_OFFSET 2
#endif /* _REG_DMA_H_ */
