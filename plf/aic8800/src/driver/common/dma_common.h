#ifndef _DMA_COMMON_H_
#define _DMA_COMMON_H_

#include <stdbool.h>

#define DMA_PAUSE_OFFSET           0
#define DMA_PAUSE_STATUS_OFFSET    16

#define DMA_PAUSE_SET              (0x01UL << DMA_PAUSE_OFFSET)
#define DMA_PAUSE_STATUS_SET       (0x01UL << DMA_PAUSE_STATUS_OFFSET)


#define DMA_FRAG_WAIT_OFFSET      0
#define DMA_SR_AHB_FREQ_OFFSET    16
#define DMA_OUT_ENDIAN_OFFSET     28


/* CH_HLTR */
#define DMA_CH_HALT_SET_OFFSET          0
#define DMA_CH_HALT_STAT_OFFSET         16

#define DMA_CH_HALT_SET_SET             (0x01UL << DMA_CH_HALT_SET_OFFSET)
#define DMA_CH_HALT_STAT_SET            (0x01UL << DMA_CH_HALT_STAT_OFFSET)

/* CH_RQR */
#define DMA_CH_SRQ_OFFSET               0
#define DMA_CH_ERQM_OFFSET              1

#define DMA_CH_SRQ_SET                  (0x01UL << DMA_CH_SRQ_OFFSET)

/* CH_CTLR */
#define DMA_CH_CHENA_OFFSET             0
#define ASDMA_CH_AUTO_CLOSE_EN_OFFSET   2//ASDMA Only
#define DMA_CH_LSTENA_OFFSET            4
#define ASDMA_CH_TBL0_CNT_SEL_OFFSET    5//ASDMA Only
#define DMA_CH_LSTCV_OFFSET             8
#define DMA_CH_RQPLVL_OFFSET            12
#define DMA_CH_BUSBU_OFFSET             16

#define DMA_CH_CHENA_SET                (0x01UL << DMA_CH_CHENA_OFFSET)
#define ASDMA_CH_AUTO_CLOSE_EN_SET      (0x01UL << ASDMA_CH_AUTO_CLOSE_EN_OFFSET)//ASDMA Only
#define DMA_CH_LSTENA_SET               (0x01UL << DMA_CH_LSTENA_OFFSET)
#define DMA_CH_LSTCV_SET                (0x01UL << DMA_CH_LSTCV_OFFSET)

/* CH_ICSR */
#define DMA_CH_TBL0_IENA_OFFSET         0
#define DMA_CH_TBL1_IENA_OFFSET         1
#define DMA_CH_TBL2_IENA_OFFSET         2
#define DMA_CH_TLL_IENA_OFFSET          3
#define DMA_CH_CE_IENA_OFFSET           4
#define DMA_CH_TBL0_IRST_OFFSET         8
#define DMA_CH_TBL1_IRST_OFFSET         9
#define DMA_CH_TBL2_IRST_OFFSET         10
#define DMA_CH_TLL_IRST_OFFSET          11
#define DMA_CH_CE_IRST_OFFSET           12
#define DMA_CH_TBL0_IMST_OFFSET         16
#define DMA_CH_TBL1_IMST_OFFSET         17
#define DMA_CH_TBL2_IMST_OFFSET         18
#define DMA_CH_TLL_IMST_OFFSET          19
#define DMA_CH_CE_IMST_OFFSET           20
#define DMA_CH_TBL0_ICLR_OFFSET         24
#define DMA_CH_TBL1_ICLR_OFFSET         25
#define DMA_CH_TBL2_ICLR_OFFSET         26
#define DMA_CH_TLL_ICLR_OFFSET          27
#define DMA_CH_CE_ICLR_OFFSET           28

#define DMA_CH_TBL0_IENA_SET            (0x01UL << DMA_CH_TBL0_IENA_OFFSET)
#define DMA_CH_TBL1_IENA_SET            (0x01UL << DMA_CH_TBL1_IENA_OFFSET)
#define DMA_CH_TBL2_IENA_SET            (0x01UL << DMA_CH_TBL2_IENA_OFFSET)
#define DMA_CH_TLL_IENA_SET             (0x01UL << DMA_CH_TLL_IENA_OFFSET)
#define DMA_CH_CE_IENA_SET              (0x01UL << DMA_CH_CE_IENA_OFFSET)
#define DMA_CH_ALL_IENA_SET             (0x3FUL << DMA_CH_TBL0_IENA_OFFSET)
#define DMA_CH_TBL0_IRST_SET            (0x01UL << DMA_CH_TBL0_IRST_OFFSET)
#define DMA_CH_TBL1_IRST_SET            (0x01UL << DMA_CH_TBL1_IRST_OFFSET)
#define DMA_CH_TBL2_IRST_SET            (0x01UL << DMA_CH_TBL2_IRST_OFFSET)
#define DMA_CH_TLL_IRST_SET             (0x01UL << DMA_CH_TLL_IRST_OFFSET)
#define DMA_CH_CE_IRST_SET              (0x01UL << DMA_CH_CE_IRST_OFFSET)
#define DMA_CH_ALL_IRST_SET             (0x3FUL << DMA_CH_TBL0_IRST_OFFSET)
#define DMA_CH_TBL0_IMST_SET            (0x01UL << DMA_CH_TBL0_IMST_OFFSET)
#define DMA_CH_TBL1_IMST_SET            (0x01UL << DMA_CH_TBL1_IMST_OFFSET)
#define DMA_CH_TBL2_IMST_SET            (0x01UL << DMA_CH_TBL2_IMST_OFFSET)
#define DMA_CH_TLL_IMST_SET             (0x01UL << DMA_CH_TLL_IMST_OFFSET)
#define DMA_CH_CE_IMST_SET              (0x01UL << DMA_CH_CE_IMST_OFFSET)
#define DMA_CH_ALL_IMST_SET             (0x3FUL << DMA_CH_TBL0_IMST_OFFSET)
#define DMA_CH_TBL0_ICLR_SET            (0x01UL << DMA_CH_TBL0_ICLR_OFFSET)
#define DMA_CH_TBL1_ICLR_SET            (0x01UL << DMA_CH_TBL1_ICLR_OFFSET)
#define DMA_CH_TBL2_ICLR_SET            (0x01UL << DMA_CH_TBL2_ICLR_OFFSET)
#define DMA_CH_TLL_ICLR_SET             (0x01UL << DMA_CH_TLL_ICLR_OFFSET)
#define DMA_CH_CE_ICLR_SET              (0x01UL << DMA_CH_CE_ICLR_OFFSET)
#define DMA_CH_ALL_ICLR_SET             (0x3FUL << DMA_CH_TBL0_ICLR_OFFSET)

/* CH_TBL0CR */
#define DMA_CH_TBL0_CNT_OFFSET              0
#define ASDMA_CH_LLI_DEDIC_INT_EN_OFFSET    16//ASDMA Only
#define ASDMA_CH_LLI_DEDIC_COUNT_EN_OFFSET  17//ASDMA Only
#define DMA_CH_TBL1_CNT_RH_OFFSET           17//DAM_CX Only
#define DMA_CH_LASTLLI_OFFSET               19
#define ASDMA_CH_CONSTADDR_OFFSET           20//ASDMA Only
#define DMA_CH_CONSTSA_OFFSET               20//DMA_CX Only
#define DMA_CH_CONSTDA_OFFSET               21//DMA_CX Only
#define DMA_CH_WRPADR_OFFSET                22//DAM_CX Only
#define DMA_CH_WRPDADR_OFFSET               23//DAM_CX Only
#define DMA_CH_RQTYP_OFFSET                 24
#define DMA_CH_SWT_MODE_OFFSET              26
#define DMA_CH_DBUSU_OFFSET                 28
#define DMA_CH_SBUSU_OFFSET                 30

#define ASDMA_CH_LLI_DEDIC_INT_EN_SET       (0x01UL << ASDMA_CH_LLI_DEDIC_INT_EN_OFFSET)//ASDMA Only
#define ASDMA_CH_LLI_DEDIC_COUNT_EN_SET     (0x01UL << ASDMA_CH_LLI_DEDIC_COUNT_EN_OFFSET)//ASDMA Only
#define DMA_CH_LASTLLI_SET                  (0x01UL << DMA_CH_LASTLLI_OFFSET)
#define ASDMA_CH_CONSTADDR_SET              (0x01UL << ASDMA_CH_CONSTADDR_OFFSET)
#define DMA_CH_CONSTSA_SET                  (0x01UL << DMA_CH_CONSTSA_OFFSET)//DMA_CX Only
#define DMA_CH_CONSTDA_SET                  (0x01UL << DMA_CH_CONSTDA_OFFSET)//DMA_CX Only
#define DMA_CH_WRPADR_SET                   (0x01UL << DMA_CH_WRPADR_OFFSET)//DAM_CX Only
#define DMA_CH_WRPDADR_SET                  (0x01UL << DMA_CH_WRPDADR_OFFSET)//DMA_CX Only

/* CH_TBL1CR */
#define DMA_CH_TBL1_CNT_OFFSET              0
#define DMA_CH_TBL1_CNT_RL_OFFSET           17

/* CH_TBL2CR */
#define DMA_CH_TBL2_CNT_OFFSET              0
#define DMA_CH_LLI_DEDIC_INT_EN_OFFSET      28//DMA_CX only
#define DMA_CH_LLI_DEDIC_COUNT_EN_OFFSET    29//DMA_CX Only

#define DMA_CH_LLI_DEDIC_INT_EN_SET         (0x01UL << DMA_CH_LLI_DEDIC_INT_EN_OFFSET)//DMA_CX only
#define DMA_CH_LLI_DEDIC_COUNT_EN_SET       (0x01UL << DMA_CH_LLI_DEDIC_COUNT_EN_OFFSET)//DMA_CX Only

/* CH_TSR */
#define DMA_CH_STRANSZ_OFFSET           0
#define DMA_CH_DTRANSZ_OFFSET           16

/* CH_WMAR */
#define DMA_CH_WRPMADR_OFFSET           0
#define DMA_CH_SAH4_OFFSET              28

/* CH_WJAR */
#define DMA_CH_WRPJADR_OFFSET           0
#define DMA_CH_DAH4_OFFSET              28

/* CH_LNAR */
#define DMA_CH_LLINADR_OFFSET           0

/* CH_TBL0SR */
#define DMA_CH_STBL0SZ_OFFSET           0
#define DMA_CH_DTBL0SZ_OFFSET           16

/* CH_TBL1SSR */
#define DMA_CH_TBL1_SSZ_OFFSET          0
#define DMA_CH_LLINADRH4_OFFSET         28

/* CH_TBL1DSR */
#define DMA_CH_TBL1_DSZ_OFFSET          0

#define DMA_INVALID_ADDR                0xFFFFFFFFUL

typedef enum {
    DMA_CH_0 = 0,
    DMA_CH_1 = 1,
    DMA_CH_2 = 2,
    DMA_CH_3 = 3,
    DMA_CH_4 = 4,
    DMA_CH_5 = 5,
    DMA_CH_6 = 6,
    DMA_CH_7 = 7,
    DMA_CH_8 = 8,
    DMA_CH_9 = 9,
    DMA_CH_10 = 10,
    DMA_CH_11 = 11,
    DMA_CH_12 = 12,
    DMA_CH_13 = 13,
    DMA_CX_CH_QTY = 14,
    DMA_CH_14 = 14,
    DMA_CH_15 = 15,
    DMA_CH_16 = 16,
    DMA_CH_17 = 17,
    DMA_CH_18 = 18,
    DMA_CH_19 = 19,
    DMA_CH_20 = 20,
    DMA_CH_21 = 21,
    DMA_CH_22 = 22,
    DMA_CH_23 = 23,
    DMA_CH_24 = 24,
    DMA_CH_25 = 25,
    DMA_CH_26 = 26,
    DMA_CH_27 = 27,
    DMA_CH_28 = 28,
    DMA_CH_29 = 29,
    DMA_CH_30 = 30,
    DMA_CH_31 = 31,
    ASDMA_CH_QTY = 32,
    DMA_CH_NONE = 0xFF,
} AIC_DMA_CH_ENUM;

typedef enum {
    REQ_CID_UART0_RX       = 0,
    REQ_CID_UART0_TX       = 1,
    REQ_CID_UART1_RX       = 2,
    REQ_CID_UART1_TX       = 3,
    REQ_CID_UART2_RX       = 4,
    REQ_CID_UART2_TX       = 5,
    REQ_CID_I2CM_RX        = 6,
    REQ_CID_I2CM_TX        = 7,
    REQ_CID_SPI_RX         = 8,
    REQ_CID_SPI_TX         = 9,
    REQ_CID_SDMMC_RX       = 10,
    REQ_CID_SDMMC_TX       = 11,
    REQ_CID_AUD_PROC_RX01  = 12,
    REQ_CID_AUD_PROC_RX23  = 13,
    REQ_CID_AUD_PROC_TX0   = 14,
    REQ_CID_AUD_PROC_TX1   = 15,
    REQ_CID_AUD_PROC_TX2   = 16,
    REQ_CID_AUD_PROC_TX3   = 17,
    REQ_CID_AUD_PROC_RXTX0 = 18,
    REQ_CID_AUD_PROC_RXTX1 = 19,
    REQ_CID_AUD_PROC_TXRX0 = 20,
    REQ_CID_AUD_PROC_TXRX1 = 21,
    REQ_CID_AUD_SRC_TX     = 22,
    REQ_CID_AUD_SRC_RX     = 23,
    REQ_CID_QTY            = 24,

    REQ_CID_MEMORY         = 0xFE,
    REQ_CID_NONE           = 0xFF,
} DMA_REQ_CID_ENUM;

typedef enum {
    DMA_LITTLE_ENDIAN  = 0,
    DMA_BIG_ENDIAN     = 1,
} DMA_OUT_ENDIAN_ENUM;

typedef enum {
    EXREQ_FALLING_EDGE = 0,
    EXREQ_LOW_LEVEL    = 1,
    EXREQ_RISING_EDGE  = 2,
    EXREQ_HIGH_LEVEL   = 3,
} DMA_EXREQ_TYPE_ENUM;

typedef enum {
    DMA_PRIO_LOWEST  = 0,
    DMA_PRIO_LOW     = 1,
    DMA_PRIO_HIGH    = 2,
    DMA_PRIO_HIGHEST = 3,
} DMA_PRIORITY_ENUM;

typedef enum {
    AHB_BURST_INCR8  = 0,
    AHB_BURST_INCR4  = 1,
    AHB_BURST_INCR16 = 2,
} DMA_AHB_BURST_SEL_ENUM;

typedef enum {
    /* bit[0] fix on src enable
     * bit[1] fix on dest enable
     */
    FIX_ON_NONE = 0,
    FIX_ON_SRC  = 1,
    FIX_ON_DEST = 2,
    FIX_ON_BOTH = 3,
} DMA_ADDR_FIX_TYPE_ENUM;

typedef enum {
    WRAP_ON_NONE = 0,
    WRAP_ON_SRC  = 1,
    WRAP_ON_DEST = 3,
} DMA_ADDR_WRAP_TYPE_ENUM;

typedef enum {
    REQ_FRAG  = 0,
    REQ_BLK   = 1,
    REQ_TRSC  = 2,
    REQ_LLIST = 3,
    REQ_TBL0  = 0,
    REQ_TBL1  = 1,
    REQ_TBL2  = 2,
    REQ_LLI   = 3,
} DMA_REQ_MODE_ENUM;

typedef enum {
    SWT_ABCD_ABCD = 0,
    SWT_ABCD_DCBA = 1,
    SWT_ABCD_BADC = 2,
    SWT_ABCD_CDBA = 3,
} DMA_SWT_MODE_ENUM;

typedef enum {
    AHB_BYTE  = 0,
    AHB_HWORD = 1,
    AHB_WORD  = 2,
    AHB_DWORD = 3,
} DMA_AHB_SIZE_ENUM;

typedef enum {
    DMA_CX    = 0,
    ASDMA     = 1,
} DMA_TYPE_ENUM;

typedef enum {
    DMA_UART0_RX          = 0,
    DMA_UART0_TX          = 1,
    DMA_UART1_RX          = 2,
    DMA_UART1_TX          = 3,
    DMA_UART2_RX          = 4,
    DMA_UART2_TX          = 5,
    DMA_I2CM_RX           = 6,
    DMA_I2CM_TX           = 7,
    DMA_SPI_RX            = 8,
    DMA_SPI_TX            = 9,
    DMA_SDMMC_RX          = 10,
    DMA_SDMCC_TX          = 11,
    DMA_AUD_PROC_RX01     = 12,
    DMA_AUD_PROC_RX23     = 13,
    DMA_AUD_PROC_TX0      = 14,
    DMA_AUD_PROC_TX1      = 15,
    DMA_AUD_PROC_TX2      = 16,
    DMA_AUD_PROC_TX3      = 17,
    DMA_AUD_PROC_RXTX0    = 18,
    DMA_AUD_PROC_RXTX1    = 19,
    DMA_AUD_PROC_TXRX0    = 20,
    DMA_AUD_PROC_TXRX1    = 21,
    DMA_AUD_SRC_TX        = 22,
    DMA_AUD_SRC_RX        = 23,
    DMA_CX_PERIPH_QTY     = 24,

    DMA_MEMORY            = 0xFE,
    DMA_PERIPH_NONE       = 0xFF,
} DMA_CX_PERIPH_ENUM;

typedef enum {
    DMA_TRANS_M2M = 0,
    DMA_TRANS_M2P = 1,
    DMA_TRANS_P2M = 2,
    DMA_TRANS_P2P = 3,
} DMA_TRANS_TYPE_ENUM;

typedef enum {
    ASDMA_ID_AIC1000_UART0_RX   = 0,
    ASDMA_ID_AIC1000_UART0_TX   = 1,
    ASDMA_ID_AIC1000_UART1_RX   = 2,
    ASDMA_ID_AIC1000_UART1_TX   = 3,
    ASDMA_ID_AIC1000_UART2_RX   = 4,
    ASDMA_ID_AIC1000_UART2_TX   = 5,
    ASDMA_ID_AIC1000_SPI0_RX    = 6,
    ASDMA_ID_AIC1000_SPI0_TX    = 7,
    ASDMA_ID_AIC1000_SPI1_RX    = 8,
    ASDMA_ID_AIC1000_SPI1_TX    = 9,
    ASDMA_ID_AIC1000_SDMMC_RX   = 10,
    ASDMA_ID_AIC1000_SDMCC_TX   = 11,
    ASDMA_ID_AIC1000_I2CM0_RX   = 12,
    ASDMA_ID_AIC1000_I2CM0_TX   = 13,
    ASDMA_ID_AIC1000_I2CM1_RX   = 14,
    ASDMA_ID_AIC1000_I2CM1_TX   = 15,
    ASDMA_ID_AIC1000_CAMERA_RX  = 16,

    ASDMA_ID_AUDIO_RX           = 28,
    ASDMA_ID_AUDIO_TX           = 29,
    ASDMA_ID_GEN_SOFT_RX        = 30,
    ASDMA_ID_GEN_SOFT_TX        = 31,

    ASDMA_ID_MEMORY             = 0xFE,
    ASDMA_ID_NONE               = 0xFF,
} ASDMA_PERIPH_ID_ENUM;

typedef void (*AIC_DMA_IRQ_HANDLER_T)(uint8_t dma_type, uint8_t ch, uint32_t int_status);

typedef struct {
    DMA_TYPE_ENUM dma_type;
    uint8_t ch;
    DMA_EXREQ_TYPE_ENUM exreq_type;
    bool llist_en;
    bool llist_cfg_valid;
    bool llist_end;
    DMA_PRIORITY_ENUM priority;
    DMA_AHB_BURST_SEL_ENUM ahb_burst_sel;
    uint32_t int_mask;
    uint32_t src_addr;//must be configed as DMA_INVALID_ADDR in ASDMA RX mode
    uint32_t dest_addr;//must be configed as DMA_INVALID_ADDR in ASDMA TX mode
    uint32_t tbl0_cnt;
    uint32_t tbl1_cnt_rh;//DMA_CX Only
    uint32_t tbl1_cnt;
    uint32_t tbl2_cnt;//DMA_CX Only
    uint16_t src_tran_sz;//DMA_CX Only
    uint16_t dest_tran_sz;//DMA_CX Only
    uint32_t wrp_maddr;//DMA_CX Only
    uint32_t wrp_jaddr;//DMA_CX Only
    uint32_t nxt_addr;
    uint16_t src_tbl0_sz;//DMA_CX Only
    uint16_t dest_tbl0_sz;//DMA_CX Only
    uint32_t src_tbl1_sz;//DMA_CX Only
    uint32_t dest_tbl1_sz;//DMA_CX Only
    uint8_t ext_req_cid;//DMA_CX Only
    bool llist_dedicated_int_en;
    DMA_ADDR_FIX_TYPE_ENUM addr_fix_type;
    DMA_ADDR_WRAP_TYPE_ENUM addr_wrap_type;//DMA_CX Only
    DMA_REQ_MODE_ENUM req_mode;
    DMA_SWT_MODE_ENUM swt_mode;
    DMA_AHB_SIZE_ENUM src_size;
    DMA_AHB_SIZE_ENUM dest_size;
    AIC_DMA_IRQ_HANDLER_T handler;
    DMA_CX_PERIPH_ENUM src_periph;
    DMA_CX_PERIPH_ENUM dest_periph;
    DMA_TRANS_TYPE_ENUM trans_type;
    bool ch_en;
} DMA_CFG_T;

#endif
