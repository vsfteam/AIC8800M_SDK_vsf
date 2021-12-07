#ifndef _PMIC_API_H_
#define _PMIC_API_H_

#include "chip.h"
#include "plf.h"

#if PLF_PMIC
#if PLF_PMIC_VER_LITE
#include "aic1000Lite_analog_reg.h"
#include "aic1000Lite_gpio.h"
//#include "aic1000Lite_intc.h"
#include "aic1000Lite_iomux.h"
#include "aic1000Lite_led_pwm.h"
#include "aic1000Lite_msadc.h"
//#include "aic1000Lite_psm.h"
#include "aic1000Lite_rtc_core.h"
#include "aic1000Lite_sys_ctrl.h"
//#include "aic1000Lite_wdg.h"
#elif PLF_PMIC_VER_AUD
#include "aic1000Aud_analog_reg.h"
//#include "aic1000Aud_aud_anc.h"
//#include "aic1000Aud_aud_codec.h"
//#include "aic1000Aud_aud_ctrl_reg.h"
//#include "aic1000Aud_aud_vad.h"
#include "aic1000Aud_gpio.h"
//#include "aic1000Aud_intc.h"
#include "aic1000Aud_iomux.h"
#include "aic1000Aud_led_pwm.h"
#include "aic1000Aud_msadc.h"
//#include "aic1000Aud_psm.h"
//#include "aic1000Aud_rtc_cnt.h"
#include "aic1000Aud_rtc_core.h"
#include "aic1000Aud_sys_ctrl.h"
//#include "aic1000Aud_wdg.h"
#endif
#if PLF_PMIC_ITF_ASDMA
#include "asdma_mst_api.h"
#else
#include "psim_api.h"
#endif

typedef enum {
    #if PLF_PMIC_VER_LITE
    PMIC_ASDMA_IRQn     = 0,
    PMIC_GPIO_IRQn      = 1,
    PMIC_I2CM_IRQn      = 2,
    PMIC_PWM0_IRQn      = 3,
    PMIC_PWM1_IRQn      = 4,
    PMIC_PWM2_IRQn      = 5,
    PMIC_PWM3_IRQn      = 6,
    PMIC_PWM4_IRQn      = 7,
    PMIC_PWM5_IRQn      = 8,
    PMIC_KEYPAD_IRQn    = 9,
    PMIC_WDG_IRQn       = 10,
    PMIC_DET_SDIO_IRQn  = 11,
    PMIC_TOUCH_IRQn     = 12,
    PMIC_PSM_IRQn       = 13,
    PMIC_CALENDAR_IRQn  = 14,
    PMIC_SPI_IRQn       = 15,
    PMIC_UART_DET_IRQn  = 16,
    PMIC_CAL_IRQn       = 17,
    PMIC_RTC_CORE_IRQn  = 18,
    PMIC_PWM_TMR_IRQn   = 19,
    #endif /* PLF_PMIC_VER_LITE */
    #if PLF_PMIC_VER_AUD
    PMIC_GPIO_IRQn      = 0,
    PMIC_PWM0_IRQn      = 1,
    PMIC_PWM1_IRQn      = 2,
    PMIC_AUD_VAD_IRQn   = 3,
    PMIC_AUD_CODEC_IRQn = 4,
    PMIC_AUD_ANC_IRQn   = 5,
    PMIC_WDG_IRQn       = 6,
    PMIC_TOUCH_IRQn     = 7,
    PMIC_PSM_IRQn       = 8,
    PMIC_RTC_CNT_IRQn   = 9,
    PMIC_RTC_CORE_IRQn  = 10,
    PMIC_PWM_TMR0_IRQn  = 11,
    PMIC_PWM_TMR1_IRQn  = 12,
    PMIC_TWS_UART_IRQn  = 13,
    #endif /* PLF_PMIC_VER_AUD */
    PMIC_IRQ_NUMBER
} PMIC_IRQ_T;

typedef void (*pmic_irq_callback_t)(void);

#if PLF_PMIC_ITF_ASDMA
#define PMIC_ITF_INIT(...)          asdma_mst_init(__VA_ARGS__)
#define PMIC_MEM_READ(...)          asdma_reg_rd(__VA_ARGS__)
#define PMIC_MEM_WRITE(...)         asdma_reg_wr(__VA_ARGS__)
#define PMIC_MEM_MASK_WRITE(...)    asdma_reg_mask_wr(__VA_ARGS__)
#else
#define PMIC_ITF_INIT(...)          psim_init(__VA_ARGS__)
#define PMIC_MEM_READ(...)          psim_read(__VA_ARGS__)
#define PMIC_MEM_WRITE(...)         psim_write(__VA_ARGS__)
#define PMIC_MEM_MASK_WRITE(...)    psim_mask_write(__VA_ARGS__)
#endif

void pmic_irq_enable_local(void);
void pmic_irq_callback_register(PMIC_IRQ_T irq_idx, pmic_irq_callback_t callback);
void pmic_irq_enable(uint32_t int_en);
void pmic_irq_process(void);
void pmic_pwm_timer_start(uint32_t ticks_32k);
#if PLF_PMIC_VER_LITE
void pmic_psm_timer_start(uint32_t ticks_32k_hi, uint16_t ticks_32k_lo);
#endif /* PLF_PMIC_VER_LITE */
#if PLF_PMIC_VER_AUD
void pmic_rtccnt_timer_start(uint32_t ticks_32k_hi, uint32_t ticks_32k_lo);
#endif /* PLF_PMIC_VER_AUD */

/**
 * @brief: Enable pwrkey
 * @return: current holding state
 */
int pmic_powerkey_enable(void);

/**
 * @brief: Sw shutdown
 */
void pmic_chip_shutdown(void);

/**
 * @brief: Sw reboot
 */
void pmic_chip_reboot(void);

/**
 * @brief: Config BOR, low VBAT trigger power off
 * @param[in] bor_vbit: vbit-voltage table
 *  +------+------+------+------+------+------+------+------+------+------+------+------+------+
 *  | vbit | 0x4  | 0x5  | 0x6  | 0x7  | 0x8  | 0x9  | 0xA  | 0xB  | 0xC  | 0xD  | 0xE  | 0xF  |
 *  +------+------+------+------+------+------+------+------+------+------+------+------+------+
 *  | Volt | 2.15 | 2.27 | 2.38 | 2.49 | 2.60 | 2.71 | 2.83 | 2.94 | 3.06 | 3.17 | 3.28 | 3.40 |
 *  +------+------+------+------+------+------+------+------+------+------+------+------+------+
 * @param[in] bor_repower: if auto re-power after charging
 */
void pmic_bor_config(uint32_t bor_vbit, int bor_repower);
#endif

#endif /* _PMIC_API_H_ */
