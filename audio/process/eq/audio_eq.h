#ifndef _AUDIO_EQ_H_
#define _AUDIO_EQ_H_

#define EQ_BANDS        10
#define EQ_COEFS_NUM    5

typedef enum {
    EQ_NONE = 0,
    EQ_POP,
    EQ_JAZZ,
    EQ_ROCK,
    EQ_CLASSIC,
    EQ_BLUES,
    EQ_COUNTRY,
    EQ_DANCE,
    EQ_ACG,
    EQ_NUM
} EQ_TYPE_T;

typedef enum {
    EQ_CH_NONE = 0,
    EQ_CH_L = 1,
    EQ_CH_R = 2,
    EQ_CH_NUM
} EQ_CH_T;

void audio_eq_init(void);
void audio_dac_eq_coef_config(int *coef);
void audio_dac_eq_off(void);
void audio_dac_eq_set(EQ_TYPE_T type);
void audio_dac_eq_reset(void);
void audio_adc_eq_coef_config(int *coef);
void audio_adc_eq_off(void);
void audio_adc_eq_set(EQ_TYPE_T type);
void audio_adc_eq_ch_set(EQ_CH_T ch);
void audio_adc_eq_reset(void);
void audio_eq_cmd_init(void);

#endif

