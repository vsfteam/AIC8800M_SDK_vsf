#ifndef _CODEC_AIC1000_H_
#define _CODEC_AIC1000_H_

#include <stdint.h>

typedef enum {
    AIC1000_MIC_NORMAL_MODE = 0,
    AIC1000_MIC_ICL_MODE,
} AIC1000_MIC_CAP_MODE;

typedef enum {
    AIC1000_MIC_SE_MODE = 0,
    AIC1000_MIC_DIFF_MODE,
} AIC1000_MIC_SIGNAL_MODE;

typedef enum {
    AIC1000_HP_SE_MODE = 0,
    AIC1000_HP_DIFF_MODE,
} AIC1000_HP_SIGNAL_MODE;

typedef struct {
    //采样率，如44.1K、48K
    uint32_t sample_rate;
    //位深，如16bit、24bit
    uint8_t bits;
    //声道数目，如AUD_CH_NUM_1（单声道）、AUD_CH_NUM_2（双声道）、AUD_CH_NUM_3（三声道）
    uint8_t ch_num;
    //声道组合，与ch_num配合使用
    //ch_num = 1, ch_map = AUD_CH_MAP_CH_1，对于播放，使用DAC1，对于录音，使用ADC1
    //ch_num = 2, ch_map = (AUD_CH_MAP_CH_0 | AUD_CH_MAP_CH_1)，对于播放，使用DAC0+DAC1，对于录音，使用ADC0+ADC1。
    //ch_num = 2, ch_map = (AUD_CH_MAP_CH_1 | AUD_CH_MAP_CH_2)，对于播放，错误，不存在DAC2，对于录音，使用ADC1+ADC2。
    uint8_t ch_map;
} aic1000_cfg_t;

/*
 * 以下函数中，如不需要用到入参aic1000_cfg_t *cfg，可不予处理。
 * 标注“可选”的函数，可以不实现。
 */

void aic1000_dbg_mask_set(uint16_t mask);
uint16_t aic1000_dbg_mask_get(void);

void aic1000_pu(void);
void aic1000_pd(void);
void aic1000_wait_pu_done(int ms);
void aic1000_pu_done(void);

void aic1000_iomux_config(void);
void aic1000_clk_cfg(void);
void aic1000_ana_cfg(void);
void aic1000_mic_matix_config(uint8_t type);

//打开，做一些通用的初始化（可选）
void aic1000_dac_open(aic1000_cfg_t *cfg);
void aic1000_adc_open(aic1000_cfg_t *cfg);

//配置，根据采样率、位深、声道参数配置DAC和ADC
void aic1000_dac_config(aic1000_cfg_t *cfg);
void aic1000_adc_config(aic1000_cfg_t *cfg);

//开始工作
void aic1000_dac_start(aic1000_cfg_t *cfg);
void aic1000_adc_start(aic1000_cfg_t *cfg);

//停止工作
void aic1000_dac_stop(aic1000_cfg_t *cfg);
void aic1000_adc_stop(aic1000_cfg_t *cfg);

//关闭（可选）
void aic1000_dac_close(aic1000_cfg_t *cfg);
void aic1000_adc_close(aic1000_cfg_t *cfg);

/*
 * @brief set adc digital gain base, this api is NOT for user
 *
 * @param gain, adc digital gain base in raw value
 *
 */
void aic1000_adc_dig_gain_base_config(uint8_t gain);

/*
 * @brief set adc digital gain, this api is NOT for user
 *
 * @param ch_map, adc channels, combination of AUD_CH_MAP_CH0, AUD_CH_MAP_CH1 and AUD_CH_MAP_CH2
 * @param gain, 15bits
 *
 */
void aic1000_adc_dig_gain_config(uint8_t ch_map, uint8_t gain);

/*
 * @brief set adc digital gain
 *
 * @param ch_map, adc channels, combination of AUD_CH_MAP_CH0, AUD_CH_MAP_CH1 and AUD_CH_MAP_CH2
 * @param gain_db, adc digital gain in dB, range from -30dB to +18dB
 *
 */
void aic1000_adc_dig_gain_db_config(uint8_t ch_map, float gain_db);



/*
 * @brief set adc pga gain1
 *
 * @param ch_map, adc channels, combination of AUD_CH_MAP_CH0, AUD_CH_MAP_CH1 and AUD_CH_MAP_CH2
 * @param gain, 2bits
 *
 * |----|---------------|---------------|
 * |    |  normal mode  |    icl mode   |
 * |----|---------------|---------------|
 * | 00 |      0dB      |      0dB      |
 * |----|---------------|---------------|
 * | 01 |      9dB      |      9.5dB    |
 * |----|---------------|---------------|
 * | 10 |      21dB     |      21dB     |
 * |----|---------------|---------------|
 * | 11 |      30dB     |      30dB     |
 * |----|---------------|---------------|
 */
void aic1000_adc_pga_gain_1_config(uint8_t ch_map, uint8_t gain);

/*
 * @brief set adc pga gain2
 *
 * @param ch_map, adc channels, combination of AUD_CH_MAP_CH0, AUD_CH_MAP_CH1 and AUD_CH_MAP_CH2
 * @param gain, 3bits
 *
 * |-----|---------------|---------------|
 * |     |  normal mode  |    icl mode   |
 * |-----|---------------|---------------|
 * | 000 |     bypass    |     bypass    |
 * |-----|---------------|---------------|
 * | 001 |    -1.5dB     |    -1.5dB     |
 * |-----|---------------|---------------|
 * | 010 |      0dB      |      0dB      |
 * |-----|---------------|---------------|
 * | 011 |      3dB      |      3dB      |
 * |-----|---------------|---------------|
 * | 100 |      6dB      |      6dB      |
 * |-----|---------------|---------------|
 * | 101 |      9dB      |      9dB      |
 * |-----|---------------|---------------|
 * | 110 |     12dB      |     12dB      |
 * |-----|---------------|---------------|
 * | 111 |     15dB      |     15dB      |
 * |-----|---------------|---------------|
 */
void aic1000_adc_pga_gain_2_config(uint8_t ch_map, uint8_t gain);

/*
 * @brief set adc mic bias
 *
 * @param bias, 2bits
 *
 * |----|----------|
 * | 00 |   1.85V  |
 * |----|----------|
 * | 01 |    2V    |
 * |----|----------|
 * | 10 |   2.15V  |
 * |----|----------|
 * | 11 |   2.3V   |
 * |----|----------|
 */
void aic1000_adc_mic_bias_config(uint8_t bias);

/*
 * @brief set adc mic capacitor mode
 *
 * @param mode, AIC1000_MIC_NORMAL_MODE or AIC1000_MIC_ICL_MODE
 */
void aic1000_adc_mic_cap_mode_config(uint8_t mode);

/*
 * @brief set adc mic signal mode
 *
 * @param mode, AIC1000_MIC_SE_MODE or AIC1000_MIC_DIFF_MODE
 */
void aic1000_adc_mic_signal_mode_config(uint8_t mode);

/*
 * @brief set dac digital gain base, this api is NOT for user
 *
 * @param gain, dac digital gain base in raw value
 *
 */
void aic1000_dac_dig_gain_base_config(uint8_t gain);

/*
 * @brief set dac digital gain, this api is NOT for user
 *
 * @param ch_map, adc channels, combination of AUD_CH_MAP_CH0, AUD_CH_MAP_CH1
 * @param gain, 8bits
 *
 */
void aic1000_dac_dig_gain_config(uint8_t ch_map, uint16_t gain);

/*
 * @brief set dac digital gain
 *
 * @param ch_map, dac channels, combination of AUD_CH_MAP_CH0, AUD_CH_MAP_CH1
 * @param gain_db, dac digital gain in dB, range from -58dB to +31dB
 *
 */
void aic1000_dac_dig_gain_db_config(uint8_t ch_map, float gain_db);

/*
 * @brief set dac gain1, this api is NOT for user
 *
 * @param gain, 4bits
 *
 */
void aic1000_dac_gain1_config(uint8_t gain);

/*
 * @brief set dac gain2, this api is NOT for user
 *
 * @param gain, 4bits
 *
 */
void aic1000_dac_gain2_config(uint8_t gain);

/*
 * @brief set dac hp gain, this api is NOT for user
 *
 * @param ch_map, dac channels, combination of AUD_CH_MAP_CH0, AUD_CH_MAP_CH1
 * @param gain, 3bits
 *
 * |-----|---------------|---------------|
 * |     |    SE mode    |   DIFF mode   |
 * |-----|---------------|---------------|
 * | 000 |     -15dB     |     -21dB     |
 * |-----|---------------|---------------|
 * | 001 |     -12dB     |     -18dB     |
 * |-----|---------------|---------------|
 * | 010 |     -9dB      |     -15dB     |
 * |-----|---------------|---------------|
 * | 011 |     -6dB      |     -12dB     |
 * |-----|---------------|---------------|
 * | 100 |     -3dB      |     -9dB      |
 * |-----|---------------|---------------|
 * | 101 |      0dB      |     -6dB      |
 * |-----|---------------|---------------|
 * | 110 |      3dB      |     -3dB      |
 * |-----|---------------|---------------|
 * | 111 |      6dB      |      0dB      |
 * |-----|---------------|---------------|
 */
void aic1000_dac_hp_gain_config(uint8_t ch_map, uint8_t gain);

/*
 * @brief set dac hp signal mode
 *
 * @param mode, AIC1000_HP_SE_MODE or AIC1000_HP_DIFF_MODE
 */
void aic1000_dac_hp_signal_mode_config(uint8_t mode);

#endif
