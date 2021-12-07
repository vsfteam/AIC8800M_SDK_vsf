/* mbed Microcontroller Library
 * Copyright (c) 2006-2013 ARM Limited
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
#include "reg_timer.h"
#include "us_ticker_api.h"
#include "sysctrl_api.h"

static bool us_ticker_inited = false;

#define US_TICKER_TIMER         (&(AIC_TIM0->TMR[2]))
#define US_TICKER_TIMER_IRQn    TIMER02_IRQn
#define US_TICKER_ISR_FUNC      TIMER02_IRQHandler
//#define US_TICKER_TIMER         (&(AIC_TIM0->TMR[0]))
//#define US_TICKER_TIMER_IRQn    TIMER00_IRQn
#define US_TICKER_CLOCK_SOURCE  (26000000U)
#define US_TICKER_HZ            (1000000U)

const ticker_info_t* us_ticker_get_info()
{
    static const ticker_info_t info = {
        1000000,    // 1 MHz
             32     // 32 bit counter
    };
    return &info;
}

/** US Ticker Interrupt Handler
 *
 * This function handles the us ticker interrupt.
 */
void US_TICKER_ISR_FUNC(void)
{
    uint32_t status = US_TICKER_TIMER->IS;
    // wrap interrupt
    if (status & (0x01UL << 2)) {
        US_TICKER_TIMER->IC = (0x01UL << 17); // clear interrupt
    }
    // match interrupt
    if (status & (0x01UL /*<< 0*/)) {
        US_TICKER_TIMER->IC = (0x01UL << 16); // clear interrupt
        us_ticker_irq_handler();
    }
}

void us_ticker_init(void) {
    if (us_ticker_inited) {
        /* calling init again should cancel current interrupt */
        us_ticker_disable_interrupt();
        return;
    }
    us_ticker_inited = true;

    // clk en
    cpusysctrl_pclkme_set(CSC_PCLKME_TIMER0_EN_BIT);
    cpusysctrl_oclkme_set(CSC_OCLKME_TIMER02_EN_BIT);
    US_TICKER_TIMER->CTL &= ~0x01UL;    // disable us ticker
    US_TICKER_TIMER->TD = 0x0CUL | (0x01UL << 4); // div13
    US_TICKER_TIMER->PR = US_TICKER_CLOCK_SOURCE / 13 / US_TICKER_HZ - 1; // default to 1MHz (1 us ticks)
    US_TICKER_TIMER->CTL |=  0x01UL;    // enable us ticker

    NVIC_SetPriority(US_TICKER_TIMER_IRQn, __NVIC_PRIO_LOWEST);
    NVIC_EnableIRQ(US_TICKER_TIMER_IRQn);
}

uint32_t us_ticker_read() {
    return US_TICKER_TIMER->TC;
}

void us_ticker_set_interrupt(timestamp_t timestamp) {
    // set match value
    US_TICKER_TIMER->MR = (uint32_t)timestamp;
    // enable match interrupt
    US_TICKER_TIMER->IC = 0x01UL;
}

void us_ticker_fire_interrupt(void)
{
    NVIC_SetPendingIRQ(US_TICKER_TIMER_IRQn);
}

void us_ticker_disable_interrupt(void) {
    US_TICKER_TIMER->IC = (0x01UL << 8);
}

void us_ticker_clear_interrupt(void) {
    US_TICKER_TIMER->IC = (0x01UL << 16);
}

void us_ticker_free(void)
{
    US_TICKER_TIMER->CTL &= ~0x01UL;    // disable us ticker

    US_TICKER_TIMER->IC = (0x01UL << 8);
    NVIC_DisableIRQ(US_TICKER_TIMER_IRQn);
}
