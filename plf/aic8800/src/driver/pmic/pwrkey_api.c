/**
 ****************************************************************************************
 *
 * @file pwrkey_api.c
 *
 * @brief PWRKEY API functions
 *
 ****************************************************************************************
 */

/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include "pwrkey_api.h"
#include "lp_ticker_api.h"
#include "ll.h"
#include "dbg.h"

#define PWRKEY_DEBUG_PRINTF(fmt, ...)       do {} while(0) //dbg(fmt, ##__VA_ARGS__)//

pwrkey_irq_handler_t pwrkey_irq_cb = NULL;
int pwrkey_tick_timeout = 0;
int pwrkey_released = 0;
uint32_t pwrkey_down_time_ms = 0;
uint32_t pwrkey_up_time_ms = 0;
uint32_t pwrkey_ponchk_time_ms = 0;

#if PLF_PMIC

void pwrkey_tick_evt_hndlr(uint32_t id)
{
    pwrkey_tick_timeout = 1;
}

void pwrkey_irq_evt_hndlr(int evt)
{
    const ticker_data_t *lp_tick_d = get_lp_ticker_data();
    if (evt == PWRKEY_IRQ_EVENT_KEYDOWN) {
        pwrkey_down_time_ms = ticker_read(lp_tick_d) / 1000;
    } else if (evt == PWRKEY_IRQ_EVENT_KEYUP) {
        pwrkey_up_time_ms = ticker_read(lp_tick_d) / 1000;
    }
    if ((pwrkey_down_time_ms > pwrkey_ponchk_time_ms) && (pwrkey_up_time_ms > pwrkey_down_time_ms) &&
        ((pwrkey_up_time_ms - pwrkey_down_time_ms) > user_pwrkey_poweroff_time_get())) {
        pmic_chip_shutdown();
    }
    PWRKEY_DEBUG_PRINTF("pwrkey:%x\n",evt);
    if ((evt == PWRKEY_IRQ_EVENT_KEYUP) ||
        (evt == PWRKEY_IRQ_EVENT_KEYUP_SINGLE)) {
        pwrkey_released = 1;
    }
}

void pwrkey_init(void)
{
    if (user_pwrkey_enabled()) {
        int key_held = pmic_powerkey_enable();
        if (user_pwrkey_poweron_time_get() && (key_held == 0)) {
            pmic_chip_shutdown(); // pwrkey released
        }
        pmic_irq_enable(0x01UL << PMIC_RTC_CORE_IRQn);
        pwrkey_irq_callback_register(pwrkey_irq_evt_hndlr);
    }
}

void pwrkey_poweron_check(void)
{
    unsigned int user_pon_time_ms = user_pwrkey_poweron_time_get();
    if (user_pwrkey_enabled() && user_pon_time_ms) {
        // start timer, reg timer & pwrkey cb
        const ticker_data_t *lp_tick_d = get_lp_ticker_data();
        ticker_event_t lp_tick_e;
        uint32_t tgt_time_us;
        if (user_pon_time_ms > 400) {
            user_pon_time_ms -= 400;
        }
        ticker_set_handler(lp_tick_d, pwrkey_tick_evt_hndlr);
        tgt_time_us = ticker_read(lp_tick_d) + user_pon_time_ms * 1000;
        ticker_insert_event(lp_tick_d, &lp_tick_e, tgt_time_us, 0);
        while (1) {
            uint32_t cur_time_us;
            __WFI();
            cur_time_us = ticker_read(lp_tick_d);
            critical_section_start();
            pwrkey_ponchk_time_ms = cur_time_us / 1000;
            PWRKEY_DEBUG_PRINTF("tmr=%x,key=%x\n",pwrkey_tick_timeout,pwrkey_released);
            if (pwrkey_tick_timeout) {
                break; // timer irq first, boot to app
            } else if (pwrkey_released) {
                // pwrkey irq first, shutdown
                pmic_chip_shutdown();
            }
            critical_section_end();
        }
    }
}

void pwrkey_irq_handler(int event)
{
    // callback func
    if (pwrkey_irq_cb) {
        pwrkey_irq_cb(event);
    }
}

void pwrkey_irq_callback_register(pwrkey_irq_handler_t callback)
{
    pwrkey_irq_cb = callback;
}

#if 0
void user_secure_shutdown(void)
{
    sleep_level_set(PM_LEVEL_POWER_OFF);
    user_sleep_allow(1);
    user_powerkey_pressed();
}
#endif

__WEAK int user_pwrkey_enabled(void)
{
    return USER_DEFINED_PWRKEY_EN;
}

__WEAK unsigned int user_pwrkey_poweron_time_get(void)
{
    return USER_DEFINED_POWERON_TIME_MS;
}

__WEAK unsigned int user_pwrkey_poweroff_time_get(void)
{
    return USER_DEFINED_POWEROFF_TIME_MS;
}

#endif
