/**
 ****************************************************************************************
 *
 * @file trans_api.h
 *
 * @brief TRANS utility functions
 *
 ****************************************************************************************
 */

#ifndef _TRANS_API_H_
#define _TRANS_API_H_

/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include "arch.h"
#include "trans_common.h"

#define FFT_LENGTH_MAX    512  //512word

void dma_trans_init(dma_trans_t *obj);

void fft_init(dma_trans_t *obj);

void flt_init(dma_trans_t *obj);

void fft_calc(dma_trans_t *trans_obj, fft_state_t *fft_obj, uint32_t *fft_result);

void fltr_calc(dma_trans_t *trans_obj, fltr_state_t *fltr_obj, uint32_t *fltr_result);

void fltr_cof_init(dma_trans_t *trans_obj, fltr_state_t *fltr_obj);

#endif // _TRANS_API_H_
