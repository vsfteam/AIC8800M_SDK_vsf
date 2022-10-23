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
#include "sysctrl_api.h"
#include <stdint.h>
#include "ticker_api.h"

static bool trigger_ticker_inited = false;

#define TG_TICKER_TIMER         (&(AIC_TIM1->TMR[2]))

void trigger_ticker_init(void)
{
    if (trigger_ticker_inited) {
        return;
    }
    trigger_ticker_inited = true;

    // clk en
    cpusysctrl_pclkme_set(CSC_PCLKME_TIMER1_EN_BIT);
    cpusysctrl_oclkme_set(CSC_OCLKME_TIMER12_EN_BIT);
    TG_TICKER_TIMER->CTL &= ~0x01UL;    // disable trigger ticker
    TG_TICKER_TIMER->TD = 0x07UL | (0x01UL << 4); // div8
    TG_TICKER_TIMER->PR = 0;
    TG_TICKER_TIMER->CTL |=  0x01UL;    // enable trigger ticker
}

uint32_t trigger_ticker_read(void)
{
    return TG_TICKER_TIMER->TC;
}

void trigger_ticker_free(void)
{
    trigger_ticker_inited = false;
    TG_TICKER_TIMER->CTL &= ~0x01UL;    // disable trigger ticker
}
