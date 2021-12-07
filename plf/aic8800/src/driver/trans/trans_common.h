/**
 ****************************************************************************************
 *
 * @file trans_common.h
 *
 * @brief TRANS common header file
 *
 ****************************************************************************************
 */

#ifndef _TRANS_COMMON_H_
#define _TRANS_COMMON_H_

/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include "reg_dma.h"
#include "dma_api.h"

#define TRANS_RESULT_UNREADY         0x00
#define TRANS_RESULT_WAIT_OUT        0x01
#define TRANS_RESULT_READY           0x02

typedef enum {
    FFT_MODE     = 0x00,
    FLT_MODE     = 0x01
} DMA_TRANS_MOD_T;

typedef enum {
    FFT64_MODE     = 0x00,
    FFT128_MODE    = 0x01,
    FFT256_MODE    = 0x02,
    FFT512_MODE    = 0x03
} DMA_TRANS_FFT_LEN_T;

typedef enum {
    FFT_DIR     = 0x00,
    IFFT_DIR    = 0x01
} DMA_TRANS_FFT_DIR_T;

typedef enum {
    FFT_IN_13B_HIGH    = 0x00,
    FFT_IN_13B_LOW     = 0x01
} DMA_TRANS_IN_FFT_FORMAT_T;

typedef enum {
    FFT_OUT_13B_HIGH   = 0x00,
    FFT_OUT_13B_LOW    = 0x01
} DMA_TRANS_OUT_FFT_FORMAT_T;

typedef struct {
    uint32_t length_byte;
    uint32_t *fft_data;
} fft_state_t;

typedef struct {
    uint32_t length_byte;
    uint32_t *fltr_data;
} fltr_state_t;

typedef enum {
    FLT_COFFSHW_NO_UPD    = 0x00,
    FLT_COFFSHW_UPD       = 0x01
} DMA_TRANS_COFFSHW_UPD_T;

typedef enum {
    FLT_COFFCOS_NO_UPD    = 0x00,
    FLT_COFFCOS_UPD       = 0x01
} DMA_TRANS_COFFCOS_UPD_T;

typedef enum {
    FLT_MODE_EN           = 0x00,
    SBC_MODE_EN           = 0x01
} DMA_TRANS_SBC_MODE_T;

typedef enum {
    SBC_COFF_40         = 0x00,
    SBC_COFF_80         = 0x01
} DMA_TRANS_COFF_LEN_T;

typedef enum {
    FLT_COF_INIT_WITHDATA   = 0x00,
    FLT_COF_INIT_ONLY       = 0x01
} DMA_TRANS_COFFINIT_SEL_T;

typedef enum {
    FLT_SBC_CHN0_VLD       = 0x00,
    FLT_SBC_CHN1_VLD       = 0x01
} DMA_TRANS_CHN_SEL_T;

typedef enum {
    FLTR_IN_17B_HIGH    = 0x00,
    FLTR_IN_17B_LOW     = 0x01
} DMA_TRANS_IN_FLT_FORMAT_T;

typedef enum {
    FLTR_OUT_17B_HIGH   = 0x00,
    FLTR_OUT_17B_LOW    = 0x01
} DMA_TRANS_OUT_FLT_FORMAT_T;

typedef enum {
    SBC_NO_SSAT         = 0x00,
    SBC_SSAT_EN         = 0x01
} DMA_TRANS_SBC_SSAT_EN_T;

typedef struct {
    DMA_TRANS_MOD_T            dma_trans_mode;
    uint8_t                    trans_chn;
    DMA_TRANS_FFT_LEN_T        fft_len;
    DMA_TRANS_FFT_DIR_T        fft_dir;
    uint8_t                    fft_scale;
    DMA_TRANS_IN_FFT_FORMAT_T  fft_in_format_sel;
    DMA_TRANS_OUT_FFT_FORMAT_T fft_out_format_sel;
    DMA_TRANS_COFFSHW_UPD_T    flt_cofshw_upd_en;
    DMA_TRANS_COFFCOS_UPD_T    flt_cofcos_upd_en;
    DMA_TRANS_SBC_MODE_T       flt_sbc_mode_en;
    DMA_TRANS_COFF_LEN_T       flt_sbc_coflen;
    uint16_t                   flt_len_without_coff;
    uint8_t                    flt_order;
    DMA_TRANS_COFFINIT_SEL_T   flt_cof_init_sel;
    DMA_TRANS_CHN_SEL_T        flt_sbc_chn_sel;
    DMA_TRANS_IN_FLT_FORMAT_T  fltr_in_format_sel;
    DMA_TRANS_OUT_FLT_FORMAT_T fltr_out_format_sel;
    DMA_TRANS_SBC_SSAT_EN_T    sbc_ssat_en;
} dma_trans_t;

#endif // _TRANS_COMMON_H_
