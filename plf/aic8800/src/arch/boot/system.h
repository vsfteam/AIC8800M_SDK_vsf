/**
 ****************************************************************************************
 *
 * @file system.h
 *
 ****************************************************************************************
 */

#ifndef _SYSTEM_H_
#define _SYSTEM_H_

/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include "chip.h"

/*
 * DEFINES
 ****************************************************************************************
 */
typedef struct {
    uint8_t pmic_vcore_ldo_off;
    uint8_t pmic_vcore_dcdc_off;
    uint8_t pmic_vrtc09_ldo_off;
    uint8_t pmic_lpo_512k_sel;
} syscfg_predefined_t;

/*
 * EXPORTED VARIABLE DECLARATION
 ****************************************************************************************
 */

extern uint32_t DSPSysCoreClock;        /*!< DSP System Clock Frequency (Fclk)  */
extern uint32_t SystemCoreClock;        /*!< System Clock Frequency (Hclk)      */
extern uint32_t PeripheralClock;        /*!< Peripheral Clock Frequency (Pclk)  */
extern uint32_t PsramCntrlClock;        /*!< PSRAM Control Clock Frequency      */
extern syscfg_predefined_t const syscfg_predefined;

/*
 * EXPORTED FUNCTION DECLARATION
 ****************************************************************************************
 */

void SystemCoreClockUpdate(void);
void SystemInit(void);
uint8_t ChipIdGet(int ch);
uint8_t ChipRomVerGet(void);

#endif // _SYSTEM_H_
