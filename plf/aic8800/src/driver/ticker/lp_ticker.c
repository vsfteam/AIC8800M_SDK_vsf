/* mbed Microcontroller Library
 * Copyright (c) 2018-2019 ARM Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "lp_ticker_api.h"

#if DEVICE_LPTICKER

/*******************************************************************************
 * lp_ticker implementation on this target is mapped on top of the sleep clock counter
 * that is running in the lowest energy modes. The sleep clock counter is 48b running
 * at 32.768KHz. This gives 0.03ms resolution for the low power timer which requires
 * millisecond accuracy.
 *
 ******************************************************************************/

#include "reg_timer.h"
#include "sysctrl_api.h"

static bool lp_ticker_inited = false;

/// 3-part macro to function/variable/enum string
#define LPT_M2STR_P3_I(p0,p1,p2)    p0##p1##p2
#define LPT_M2STR_P3(p0,p1,p2)      LPT_M2STR_P3_I(p0, p1, p2)

#define LP_TICKER_TIMER         AIC_TIM2
#define LP_TICKER_TIMER_MRi     0
#define LP_TICKER_TIMER_IRQn    LPT_M2STR_P3(TIMER2, LP_TICKER_TIMER_MRi, _IRQn)
#define LP_TICKER_ISR_FUNC      LPT_M2STR_P3(TIMER2, LP_TICKER_TIMER_MRi, _IRQHandler)

/// Match interrupt enable set
#define LPT_MINT_ENA_SET_BIT    (0x01UL << LP_TICKER_TIMER_MRi)
/// Wrap interrupt enable set
#define LPT_WINT_ENA_SET_BIT    (0x01UL << 7)
/// Match interrupt enable clear
#define LPT_MINT_ENA_CLR_BIT    (0x01UL << (8 + LP_TICKER_TIMER_MRi))
/// Wrap interrupt enable clear
#define LPT_WINT_ENA_CLR_BIT    (0x01UL << 15)
/// Match interrupt clear bit
#define LPT_MINT_CLR_BIT        (0x01UL << (16 + LP_TICKER_TIMER_MRi))
/// Wrap interrupt clear bit
#define LPT_WINT_CLR_BIT        (0x01UL << 23)
/// Match interrupt status masked bit
#define LPT_MINT_ST_MSK_BIT     (0x01UL << (8 + LP_TICKER_TIMER_MRi))
/// Wrap interrupt status masked bit
#define LPT_WINT_ST_MSK_BIT     (0x01UL << 15)
/// Match enable
#define LPT_MATCH_ENA_BIT       (0x01UL << (12 + LP_TICKER_TIMER_MRi))

const ticker_info_t *lp_ticker_get_info()
{
    static const ticker_info_t info = {
        1000000,    // 1MHz
             32     // 32 bit counter
    };
    return &info;
}

/** LP Ticker Interrupt Handler
 *
 * This function handles the lp ticker interrupt.
 */
void LP_TICKER_ISR_FUNC(void)
{
    uint32_t status = LP_TICKER_TIMER->IS;
    // wrap interrupt
    if (status & LPT_WINT_ST_MSK_BIT) {
        LP_TICKER_TIMER->IC = LPT_WINT_CLR_BIT; // clear interrupt
    }
    // match interrupt
    if (status & LPT_MINT_ST_MSK_BIT) {
        LP_TICKER_TIMER->IC = LPT_MINT_CLR_BIT; // clear interrupt
        lp_ticker_irq_handler();
    }
}

void lp_ticker_init()
{
    if (lp_ticker_inited) {
        /* calling init again should cancel current interrupt */
        lp_ticker_disable_interrupt();
        return;
    }
    lp_ticker_inited = true;

    if (pwrctrl_pwrmd_cpusys_sw_record_getf() == CPU_SYS_POWER_ON_RESET) {
        uint32_t reg = LP_TICKER_TIMER->CTL;
        if ((reg & 0x01UL) == 0x00UL) { // Init if disabled
            const uint32_t tick_sel = 0x01UL;   // div2(64KHz)
            LP_TICKER_TIMER->TCL = 0x00UL;      // time counter
            LP_TICKER_TIMER->TCH = 0x00UL;
            LP_TICKER_TIMER->TD =  tick_sel | (0x01UL << 4);
            reg &= ~(0x03UL << 8);
            reg |=  (0x01UL | (0x01UL << 5) | (tick_sel << 8)); // enable timer, ignore MR high-16bit, set tick freq
            LP_TICKER_TIMER->CTL = reg;
        }
        if ((reg & LPT_MATCH_ENA_BIT) == 0x00UL) {
            LP_TICKER_TIMER->CTL = reg | LPT_MATCH_ENA_BIT;  // enable match
        }
    }

    NVIC_SetPriority(LP_TICKER_TIMER_IRQn, __NVIC_PRIO_LOWEST);
    NVIC_EnableIRQ(LP_TICKER_TIMER_IRQn);
}

void lp_ticker_free()
{
    LP_TICKER_TIMER->CTL &= ~LPT_MATCH_ENA_BIT;    // disable match
    LP_TICKER_TIMER->IC = LPT_MINT_ENA_CLR_BIT;
    NVIC_DisableIRQ(LP_TICKER_TIMER_IRQn);
}

void lp_ticker_set_interrupt(timestamp_t timestamp)
{
    // set match value
    LP_TICKER_TIMER->MR[LP_TICKER_TIMER_MRi].L = (uint32_t)timestamp;
    // enable match interrupt
    LP_TICKER_TIMER->IC = LPT_MINT_ENA_SET_BIT;
}

void lp_ticker_fire_interrupt(void)
{
    NVIC_SetPendingIRQ(LP_TICKER_TIMER_IRQn);
}

void lp_ticker_disable_interrupt()
{
    LP_TICKER_TIMER->IC = LPT_MINT_ENA_CLR_BIT;
}

void lp_ticker_clear_interrupt()
{
    LP_TICKER_TIMER->IC = LPT_MINT_CLR_BIT;
}

timestamp_t lp_ticker_read()
{
    // Read forever until reaching two of the same
    volatile unsigned long long read_previous, read_current;
    do {
        read_previous = LP_TICKER_TIMER->TCL;
        read_current = LP_TICKER_TIMER->TCL;
    } while (read_previous != read_current);

    return read_current;
}

void lp_ticker_read_time(uint32_t *msb, uint32_t *lsb)
{
    uint32_t _msb, _msb_r, _lsb;
    _msb = LP_TICKER_TIMER->TCH;
    _lsb = LP_TICKER_TIMER->TCL;
    _msb_r = LP_TICKER_TIMER->TCH;

    if (_msb_r != _msb)
    {
        _lsb = LP_TICKER_TIMER->TCL;
    }
    *msb = _msb_r;
    *lsb = _lsb;
}

void lp_ticker_set_match_time(uint32_t msb, uint32_t lsb)
{
    // set match value
    LP_TICKER_TIMER->MR[LP_TICKER_TIMER_MRi].H = msb;
    LP_TICKER_TIMER->MR[LP_TICKER_TIMER_MRi].L = lsb;
    // enable match interrupt
    LP_TICKER_TIMER->IC = LPT_MINT_ENA_SET_BIT;
}

void lp_ticker_set_match_time_lo(uint32_t time)
{
    LP_TICKER_TIMER->MR[LP_TICKER_TIMER_MRi].L = time; // set match value
    LP_TICKER_TIMER->IC = LPT_MINT_ENA_SET_BIT; // enable match interrupt
}


void lp_ticker_set_ignore_tc_hi(int ignore)
{
    if (ignore) {
        LP_TICKER_TIMER->CTL |=  (0x01UL << 5);
    } else {
        LP_TICKER_TIMER->CTL &= ~(0x01UL << 5);
    }
}

bool lp_ticker_time_cmp(uint32_t time1, uint32_t time2)
{
    uint32_t diff = time1 - time2;
    return (((int32_t)diff) < 0);
}

bool lp_ticker_time_past(uint32_t time)
{
    uint32_t _lsb = LP_TICKER_TIMER->TCL;
    return (lp_ticker_time_cmp(time, _lsb));
}

#endif /* DEVICE_LPTICKER */
