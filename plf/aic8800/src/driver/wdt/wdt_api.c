/**
 ****************************************************************************************
 *
 * @file wdt_api.c
 *
 * @brief WDT API functions
 *
 ****************************************************************************************
 */

/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include "wdt_api.h"
#include "reg_wdt.h"
#include "reg_sysctrl.h"

#define WDT_IRQ_ENABLED         1

void wdt_init(unsigned int seconds)
{
    unsigned int ticks = seconds << 15; // with 32768Hz freq
    cpusysctrl_pclkme_set(CSC_PCLKME_WDG0_EN_BIT);
    cpusysctrl_oclkme_set(CSC_OCLKME_RTC_WDG0_EN_BIT | CSC_OCLKMD_RTC_ALWAYS_DIS_BIT);
    AIC_AONSYSCTRL->WDTRE |= (0x01UL /*<< 0*/); // wdt reset enable
    AIC_WDT0->LOAD = ticks;
    #if (WDT_IRQ_ENABLED == 0)
    AIC_WDT0->CTRL = (0x01UL << 1); // run
    #else
    AIC_WDT0->CTRL = (0x01UL << 1) | (0x01UL /*<< 0*/); // irq_en, run
    /* Enable interrupt */
    NVIC_SetPriority(WDT0_IRQn, __NVIC_PRIO_LOWEST);
    NVIC_EnableIRQ(WDT0_IRQn);
    #endif
}

void wdt_kick(void)
{
    AIC_WDT0->LOAD = AIC_WDT0->LOAD;
}

void wdt_stop(void)
{
    AIC_AONSYSCTRL->WDTRE &= ~(0x01UL /*<< 0*/); // wdt0 reset disable
    AIC_WDT0->CTRL = 0x00UL; // irq_dis, stop
    #if (WDT_IRQ_ENABLED == 1)
    /* Disable interrupt */
    NVIC_DisableIRQ(WDT0_IRQn);
    #endif
}

#if (WDT_IRQ_ENABLED == 1)
void WDT0_IRQHandler(void)
{
    AIC_WDT0->INT_CLR = (0x01UL /*<< 0*/); // int clear
    AIC_WDT0->CTRL = (0x01UL << 1); // stop, reset only if irq_en is false
    AIC_WDT0->LOAD = 0x00UL;
}
#endif
