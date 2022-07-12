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
 * GPADC diff channel definitions:
 * +------+------+------+
 * | Idx  | Ch_p | Ch_n |
 * +------+------+------+
 * |  0   | gpb0 | gpb1 |
 * +------+------+------+
 * |  1   | gpb2 | gpb3 |
 * +------+------+------+
 * |  2   | gpb4 | gpb5 |
 * +------+------+------+
 * Default (that negflag equals 0) diff voltage value = (vol_p - vol_n)
 */
enum {
    GPADC_DIFF_CH_0 = 0,
    GPADC_DIFF_CH_1,
    GPADC_DIFF_CH_2,
    GPADC_DIFF_CH_NUM,
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
 * @brief       Init gpadc diff chan
 * @param[in]   Gpadc diff chan index
 */
void gpadc_diff_init(int gpbdiffch);

/**
 * @brief       Free gpadc diff chan
 * @param[in]   Gpadc diff chan index
 */
void gpadc_diff_free(int gpbdiffch);

/**
 * @brief       Read voltage from gpadc diff chan
 * @param[in]   Gpadc diff chan index
 * @param[in]   Negtive flag for diff chan, 0: (p - n), 1: (n - p)
 * @return      Voltage value, range: -1175 ~ 1175mV
 */
int gpadc_diff_read(int gpbdiffch, int negflag);

/**
 * @brief       Read voltage from gpadc diff chan in high accuracy mode
 * @param[in]   Gpadc diff chan index
 * @param[in]   Negtive flag for diff chan, 0: (p - n), 1: (n - p)
 * @return      Voltage value, range: -1175.00 ~ 1175.00mV
 */
int gpadc_diff_read_ham(int gpbdiffch, int negflag);

/**
 * @brief       Measure voltage/temperature
 * @param[in]   GPADC type
 * @return      Voltage/temperature value (mV/ C)
 */
int gpadc_measure(int type);

#endif /* _GPADC_API_H_ */
