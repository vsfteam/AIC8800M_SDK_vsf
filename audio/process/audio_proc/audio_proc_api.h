#ifndef _AUDIO_PROC_API_H_
#define _AUDIO_PROC_API_H_

#include <stdint.h>
#include <stdbool.h>

int audio_proc_dac_volume_set(uint8_t volume);
int audio_proc_adc_volume_set(uint8_t volume);
uint8_t audio_proc_dac_volume_get(void);
uint8_t audio_proc_adc_volume_get(void);
uint8_t audio_proc_dac_volume_convert_db_to_reg(float dB);
uint8_t audio_proc_adc_volume_convert_db_to_reg(int8_t dB);
uint8_t audio_proc_dac_volume_step_convert_db_to_reg(float dB);
uint8_t audio_proc_adc_volume_step_convert_db_to_reg(uint8_t dB);
bool audio_proc_dac_volume_up(uint8_t step);
bool audio_proc_dac_volume_down(uint8_t step);
bool audio_proc_adc_volume_up(uint8_t step);
bool audio_proc_adc_volume_down(uint8_t step);
void audio_proc_dac_volume_mute(void);
void audio_proc_adc_volume_mute(void);
void audio_proc_dac_volume_reset(void);
void audio_proc_adc_volume_reset(void);

#endif
