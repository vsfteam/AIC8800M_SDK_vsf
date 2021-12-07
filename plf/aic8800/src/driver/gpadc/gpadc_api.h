#ifndef _GPADC_API_H_
#define _GPADC_API_H_

#include "plf.h"

enum {
    GPADC_SAMPLERATE_DFLT   = 0x02,
    GPADC_SAMPLERATE_HIGH   = 0x40,
    GPADC_SAMPLERATE_MID    = 0x80,
    GPADC_SAMPLERATE_LOW    = 0xF0,
};

enum {
    GPADC_TYPE_VBAT = 0,
    GPADC_TYPE_VIO,
    GPADC_TYPE_TEMP0,
};

/**
 * @brief       Init gpadc func
 * @param[in]   Gpiob index
 */
void gpadc_init(int gpbidx);

/**
 * @brief       Set smaple rate
 * @param[in]   Rate val
 */
void gpadc_samplerate_set(int rate);

/**
 * @brief       Free gpadc func
 * @param[in]   Gpiob index
 */
void gpadc_free(int gpbidx);

/**
 * @brief       Read voltage from gpiob pin
 * @param[in]   Gpiob index
 * @return      Voltage value, range: 0 ~ 1175mV
 */
int gpadc_read(int gpbidx);

/**
 * @brief       Measure voltage/temperature
 * @param[in]   GPADC type
 * @return      Voltage/temperature value (mV/ C)
 */
int gpadc_measure(int type);

#endif /* _GPADC_API_H_ */
