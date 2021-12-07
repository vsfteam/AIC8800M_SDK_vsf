/**
 ****************************************************************************************
 *
 * @file dma_api.h
 *
 * @brief DMA utility functions
 *
 ****************************************************************************************
 */

#ifndef _DMA_API_H_
#define _DMA_API_H_

/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include "arch.h"
#include "dma_generic.h"

/// Structure describing the DMA driver environment
typedef struct {
    /* Last DMA descriptor pushed for each channel */
    volatile dma_desc_t *last_dma[DMA_CHANNEL_MAX];
} dma_env_t;

/// DMA environment structure
extern dma_env_t dma_env;

/**
 ****************************************************************************************
 * @brief Initialization
 ****************************************************************************************
 */
void dma_init(void);

void dma_trsc_init(int channel_idx);

void dma_trsc_trans_start(volatile dma_desc_t *desc, uint32_t len, int channel_idx);

/**
 ****************************************************************************************
 * @brief Chains a chained list of descriptors in the DMA
 *
 * @param[in]   first       : First DMA descriptor of the list (filled by the caller)
 * @param[in]   last        : Last DMA descriptor of the list (filled by the caller)
 * @param[in]   channel_idx : Channel index
 *
 ****************************************************************************************
 */
void dma_push(dma_desc_t *first, dma_desc_t *last, int channel_idx);

/**
 ****************************************************************************************
 * @brief Disable an LLI IRQ.
 *
 * @param[in]   lli LLI IRQ index (must be in range 0..15)
 *
 ****************************************************************************************
 */
__STATIC_INLINE void dma_lli_disable(int lli)
{
    dma_ch_ctlr_chena_clrb(lli);
}

/**
 ****************************************************************************************
 * @brief Enable an LLI IRQ.
 *
 * @param[in]   lli LLI IRQ index (must be in range 0..15)
 *
 ****************************************************************************************
 */
__STATIC_INLINE void dma_lli_enable(int lli)
{
    dma_ch_ctlr_chena_setb(lli);
}

/**
 ****************************************************************************************
 * @brief Poll for an LLI IRQ.
 *
 * @param[in]   lli LLI IRQ index (must be in range 0..15)
 *
 ****************************************************************************************
 */
__STATIC_INLINE void dma_lli_poll(int lli)
{
    while (!(dma_ch_icsr_tll_irst_getb(lli)));
}

__STATIC_INLINE void dma_ch_int_clear(int ch_idx)
{
    uint32_t status = dma_ch_icsr_get(ch_idx);

    if (status & DMA_CH_TBL2_IMST_BIT) {
        dma_ch_icsr_tbl2_iclr_setb(ch_idx);
    }
    if (status & DMA_CH_TLL_IRST_BIT) {
        int irq_active = (__get_IPSR() != 0) ? 1 : 0;
        dma_ch_icsr_tll_iclr_setb(ch_idx);
        if (irq_active) {
            dma_env.last_dma[ch_idx] = 0; // llist done
        } else {
            GLOBAL_INT_DISABLE();
            dma_env.last_dma[ch_idx] = 0; // llist done
            GLOBAL_INT_RESTORE();
        }
    }
}

__STATIC_INLINE void dma_trsc_word_set(int channel_idx, int count)
{
        uint32_t reg_val = 0 ;
//        dma_ch_ctlr_set(channel_idx, (0x01UL << DMA_CH_BUSBU_LSB));
        reg_val  = (count | (REQ_TRSC << DMA_CH_RQTYP_LSB)
                          | (AHB_WORD << DMA_CH_DBUSU_LSB)
                          | ((uint32_t)AHB_WORD << DMA_CH_SBUSU_LSB));
        dma_ch_tbl0cr_set(channel_idx, reg_val);
        dma_ch_tsr_set(channel_idx, (4 << DMA_CH_STRANSZ_LSB) | (4 << DMA_CH_DTRANSZ_LSB));
}

__STATIC_INLINE void dma_trsc_byte_set(int channel_idx)
{
        uint32_t reg_val = 0 ;
//        dma_ch_ctlr_set(channel_idx, (0x01UL << DMA_CH_BUSBU_LSB));
        reg_val  = (0x800 | (REQ_TRSC << DMA_CH_RQTYP_LSB)
                          | (AHB_WORD << DMA_CH_DBUSU_LSB)
                          | ((uint32_t)AHB_BYTE << DMA_CH_SBUSU_LSB));
        dma_ch_tbl0cr_set(channel_idx, reg_val);
        dma_ch_tsr_set(channel_idx, (1 << DMA_CH_STRANSZ_LSB) | (4 << DMA_CH_DTRANSZ_LSB));
}

__STATIC_INLINE void dma_desc_length_set(volatile dma_desc_t *desc, uint32_t len)
{
    desc->TBL0CR = ((len > 0x1000) ? 0x1000 : len) | (REQ_LLIST << DMA_CH_RQTYP_LSB)
                   | (AHB_WORD << DMA_CH_DBUSU_LSB)
                   | ((uint32_t)AHB_WORD << DMA_CH_SBUSU_LSB);
    desc->TBL1CR = (len << DMA_CH_TBL1_CNT_LSB) & DMA_CH_TBL1_CNT_MASK;
    desc->TBL2CR = (len << DMA_CH_TBL2_CNT_LSB) & DMA_CH_TBL2_CNT_MASK;
    desc->TSR    = (4 << DMA_CH_STRANSZ_LSB) | (4 << DMA_CH_DTRANSZ_LSB);
}

__STATIC_INLINE void dma_desc_byte_trans_length_set(volatile dma_desc_t *desc, uint32_t len)
{
    desc->TBL0CR = ((len > 0x1000) ? 0x1000 : len) | (REQ_LLIST << DMA_CH_RQTYP_LSB)
                   | (AHB_WORD << DMA_CH_DBUSU_LSB)
                   | ((uint32_t)AHB_BYTE << DMA_CH_SBUSU_LSB);
    desc->TBL1CR = (len << DMA_CH_TBL1_CNT_LSB) & DMA_CH_TBL1_CNT_MASK;
    desc->TBL2CR = (len << DMA_CH_TBL2_CNT_LSB) & DMA_CH_TBL2_CNT_MASK;
    desc->TSR    = (1 << DMA_CH_STRANSZ_LSB) | (4 << DMA_CH_DTRANSZ_LSB);
}

__STATIC_INLINE void dma_desc_length_set_with_tbl0cnt(volatile dma_desc_t *desc, uint32_t len, uint32_t tbl0_cnt)
{
    desc->TBL0CR = ((tbl0_cnt << DMA_CH_TBL0_CNT_LSB) & DMA_CH_TBL0_CNT_MASK)
                   | (REQ_LLIST << DMA_CH_RQTYP_LSB)
                   | (AHB_WORD << DMA_CH_DBUSU_LSB)
                   | ((uint32_t)AHB_WORD << DMA_CH_SBUSU_LSB);
    desc->TBL1CR = (len << DMA_CH_TBL1_CNT_LSB) & DMA_CH_TBL1_CNT_MASK;
    desc->TBL2CR = (len << DMA_CH_TBL2_CNT_LSB) & DMA_CH_TBL2_CNT_MASK;
    desc->TSR    = (4 << DMA_CH_STRANSZ_LSB) | (4 << DMA_CH_DTRANSZ_LSB);
}

__STATIC_INLINE void dma_desc_lastlli_setb(dma_desc_t *desc)
{
    desc->TBL0CR |= DMA_CH_LASTLLI_BIT;
}

__STATIC_INLINE void dma_desc_lastlli_clrb(volatile dma_desc_t *desc)
{
    desc->TBL0CR &= ~DMA_CH_LASTLLI_BIT;
}

__STATIC_INLINE void dma_desc_dedicated_int_en_setb(volatile dma_desc_t *desc)
{
    desc->TBL2CR |= DMA_CH_LLI_DEDIC_INT_EN_BIT;
}

__STATIC_INLINE void dma_desc_dedicated_int_en_clrb(dma_desc_t *desc)
{
    desc->TBL2CR &= ~DMA_CH_LLI_DEDIC_INT_EN_BIT;
}

__STATIC_INLINE void dma_desc_dedicated_counter_en_setb(volatile dma_desc_t *desc)
{
    desc->TBL2CR |= DMA_CH_LLI_DEDIC_COUNTER_EN_BIT;
}

__STATIC_INLINE void dma_desc_dedicated_counter_en_clrb(volatile dma_desc_t *desc)
{
    desc->TBL2CR &= ~DMA_CH_LLI_DEDIC_COUNTER_EN_BIT;
}

#endif // _DMA_API_H_
