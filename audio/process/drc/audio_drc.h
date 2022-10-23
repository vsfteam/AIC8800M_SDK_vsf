#ifndef _AUDIO_DRC_H_
#define _AUDIO_DRC_H_

void audio_drc_init(void);
void audio_drc_on(void);
void audio_drc_off(void);
void audio_drc_coef_config(int *coef1, int *coef2, short *coef3);
void audio_drc_default_config(void);
void audio_drc_cmd_init(void);

#endif

