#ifndef _ASIO_SRC_H_
#define _ASIO_SRC_H_
#include <stdint.h>
#include <stdbool.h>
#include "audio_types.h"
#include "audio_tws.h"


#define DPLL_HARDWARE_MODE       1  //always enable
#define DPLL_SOFTWARE_MODE       1

#define DEFAULT_SRC_DPLL_OFFSET     0//0x1000000-1000//:(-3Hz)//-333+0x1000000//:(-1Hz)
#define AUD_DPLL_MAX_SAMP_TIME      1000
#define AUD_DPLL_MIN_SAMP_TIME      -1000
#define AUD_DIE_MAX_TIME             200 //us
#define AUD_DIE_MIN_TIME            -200 //us

#define AUD_ADC_SRC_CHECK_SIZE      1//sync value about buffer size
#define AUD_ADC_SRC_ONE_BYTE_TIME   1//time(us) of one byte of data
typedef void (*AIC_ASIO_DSD_HANDLER_T)(void* param);

typedef struct {
    AUD_DPLL_MODE audio_dpll_mode;
#if DPLL_SOFTWARE_MODE == 1
    AUD_DPLL_MODE audio_sft_dpll_mode;
#endif
    bool src_trigger_state;
    bool strb_check_samplenum;
    uint32_t strb_num_counter;
    uint32_t input_samp_num_counter;
    int samplerate_delta;
} ASIO_SRC_PARAM_T;

void asio_src_param_clear();
AUD_DPLL_MODE asio_src_get_dpll_mode(void);
void asio_src_set_dpll_param_in_diffmode(AUD_DPLL_MODE mode);
bool asio_src_get_trigger_status(void);
void asio_src_set_check_samplenum(bool state);
void asio_src_set_input_sample_num(uint32_t sample_num);
void asio_src_change_samplerate_delta(int delta);
int asio_src_strb_init(AUD_STREAM_T stream, AUD_SAMPRATE_T samp_rate, AUD_SAMPRATE_T src_samp_rate);
int asio_src_strb_clear(void);
void asio_src_frac_src_init(void);
void asio_src_frac_src_clear(void);
int asio_src_trigger_init(uint32_t trigger_cnt,uint32_t trigger_delta);
int asio_src_trigger_clear(void);
void asio_src_clear();
void asio_adc_src_init(void);
void asio_adc_src_clear(void);
void asio_adc_src_change_samplerate_delta(int delta);
void asio_adc_src_process(uint16_t buff_size ,int sync_size);
void asio_dac_src_process(uint16_t buff_size ,int sync_size);
signed int dpll_task(signed int din);
#if DPLL_SOFTWARE_MODE == 1
void asio_src_sft_dpll_clear(void);
void asio_src_set_sft_dpll_param_in_diffmode(AUD_DPLL_MODE mode);
signed int dpll_task_sft(signed int din);
#endif
#if (PLF_BT_STACK)
void asio_src_handle_sync_param(MediaSyncParamStruct * sync_param);
#endif
#endif
