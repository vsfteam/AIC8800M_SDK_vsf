#ifndef _AIC1000AUD_WDG_H_
#define _AIC1000AUD_WDG_H_

#include "chip.h"

// =============================================================================
//  MACROS
// =============================================================================

// =============================================================================
//  TYPES
// =============================================================================

// =============================================================================
// AIC1000AUD_WDG_T
// -----------------------------------------------------------------------------
///
// =============================================================================
#define REG_AIC1000AUD_WDG_BASE    0x50017000

typedef struct {
    __IO uint32_t               WDG_LOAD_VAL;               //0x00000000
    __IO uint32_t               WDG_CNT;                    //0x00000004
    __IO uint32_t               WDG_CTRL;                   //0x00000008
    __IO uint32_t               WDG_INT_CLR;                //0x0000000C
    __IO uint32_t               WDG_INT_RAW;                //0x00000010
    __IO uint32_t               WDG_INT_MASK;               //0x00000014
    __IO uint32_t Reserved_00000018[762];       //0x00000018
    __IO uint32_t               WDG_LOCK;                   //0x00000C00
} HWP_AIC1000AUD_WDG_T;

static HWP_AIC1000AUD_WDG_T * const aic1000audWdg = ((HWP_AIC1000AUD_WDG_T *)REG_AIC1000AUD_WDG_BASE);


//WDG_LOAD_VAL
#define AIC1000AUD_WDG_WDG_LOAD_VAL(n) (((n)&0xFFFFFFFF)<<0)

//WDG_CNT
#define AIC1000AUD_WDG_WDG_CNT(n)  (((n)&0xFFFFFFFF)<<0)

//WDG_CTRL
#define AIC1000AUD_WDG_WDG_IRQ_EN  (1<<0)
#define AIC1000AUD_WDG_WDG_RUN     (1<<1)

//WDG_INT_CLR
#define AIC1000AUD_WDG_WDG_INT_CLR (1<<0)

//WDG_INT_RAW
#define AIC1000AUD_WDG_WDG_INT_RAW (1<<0)
#define AIC1000AUD_WDG_WDG_LD_BUSY (1<<4)

//WDG_INT_MASK
#define AIC1000AUD_WDG_WDG_INT_MASK (1<<0)

//WDG_LOCK
#define AIC1000AUD_WDG_WDG_LOCK(n) (((n)&0xFFFF)<<0)

#endif
