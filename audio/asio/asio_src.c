#include <string.h>
#include "plf.h"
#include "rtos.h"
#include "dbg.h"
#include "dbg_assert.h"
#include "asio.h"
#include "aud_proc.h"
#include "reg_iomux.h"
#include "reg_sysctrl.h"
#include "gpio_api.h"
#if PLF_PMIC
#include "pmic_api.h"
#endif
#include "asio_src.h"
#include "lp_ticker_api.h"
#include "audio_config.h"
#include "trigger_ticker_api.h"


#define STRB_DBG 0

__STATIC_INLINE void aud_dac_sync_iomux_config(void)
{
    iomux_agpio_config_sel_setf(11, 1);
}

#define AUD_DPLL_44100_SAMP_TETAL                    157
#define SAMP_TIME_TAB_NUM                            21
static const int aud_dpll_44100_samp_time_tab[SAMP_TIME_TAB_NUM][2] = {
    {AUD_DPLL_MIN_SAMP_TIME,22677306},
    {-900 ,22677149},
    {-800 ,22676992},
    {-700 ,22676835},
    {-600 ,22676679},
    {-500 ,22676522},
    {-400 ,22676365},
    {-300 ,22676208},
    {-200 ,22676051},
    {-100 ,22675894},
    {0    ,22675737},
    {100  ,22675580},
    {200  ,22675423},
    {300  ,22675266},
    {400  ,22675109},
    {500  ,22674952},
    {600  ,22674795},
    {700  ,22674639},
    {800  ,22674482},
    {900  ,22674325},
    {AUD_DPLL_MAX_SAMP_TIME ,22674168},
};

#define AUD_DPLL_48000_SAMP_TETAL                    132
static const int aud_dpll_48000_samp_time_tab[SAMP_TIME_TAB_NUM][2] = {
    {AUD_DPLL_MIN_SAMP_TIME,20834659},
    {-900 ,20834526},
    {-800 ,20834394},
    {-700 ,20834261},
    {-600 ,20834128},
    {-500 ,20833996},
    {-400 ,20833863},
    {-300 ,20833731},
    {-200 ,20833598},
    {-100 ,20833466},
    {0    ,20833333},
    {100  ,20833201},
    {200  ,20833068},
    {300  ,20832936},
    {400  ,20832803},
    {500  ,20832671},
    {600  ,20832538},
    {700  ,20832406},
    {800  ,20832273},
    {900  ,20832141},
    {AUD_DPLL_MAX_SAMP_TIME ,20832008},
};

#if DPLL_SOFTWARE_MODE == 1
unsigned int alfa1=2482; //S14.12
unsigned int alfa2=3465;//S14.12
unsigned int k1=229; //S14.12
unsigned int k2=234; //S14.2
unsigned int k_src=419; //S14.8

volatile signed int y1_d=0;   //clean it when reset
volatile signed int y2_d=0;   //clean it when reset
volatile signed int y3_d=0;   //clean it when reset
volatile signed int y4_d=0;   //clean it when reset
#endif
ASIO_SRC_PARAM_T asio_src_param;

void asio_src_dpll_clear(void)
{
#if (DPLL_HARDWARE_MODE)
    hwp_audProc->dpll_trig_cfg = 0;
#endif
}

void asio_src_param_clear(void)
{
    asio_src_param.audio_dpll_mode = AUD_DPLL_NORMAL;
    asio_src_param.src_trigger_state = false;
    asio_src_param.strb_check_samplenum = false;
    asio_src_param.strb_num_counter = 0;
    asio_src_param.input_samp_num_counter = 0;
    asio_src_param.samplerate_delta = 0;
}

AUD_DPLL_MODE asio_src_get_dpll_mode(void)
{
    return asio_src_param.audio_dpll_mode;
}

void asio_src_set_dpll_param_in_diffmode(AUD_DPLL_MODE mode)
{
    unsigned int hw_alfa1=2482; //S14.12
    unsigned int hw_alfa2=3465;//S14.12
    unsigned int hw_k1=229; //S14.12
    unsigned int hw_k2=234; //S14.2
    unsigned int hw_k_src=419; //S14.8

    asio_src_param.audio_dpll_mode = mode;
    switch(mode){
        case AUD_DPLL_NORMAL:
            hw_alfa1=4039; //S14.12
            hw_alfa2=4039;//S14.12
            hw_k1=3; //S14.12
            hw_k2=6226; //S14.2
            hw_k_src=115; //S14.8
            TRACE("AUDIO: dpll_normal_mode\n");
            break;
        case AUD_DPLL_TWS:
            hw_alfa1=3957;//2482; //S14.12
            hw_alfa2=1827;//3465;//S14.12
            hw_k1=125;//229; //S14.12
            hw_k2=963;//234; //S14.2
            hw_k_src=512;//419; //S14.8
            TRACE("AUDIO: dpll_tws_mode\n");
            break;
        default:
            break;
    }
#if DPLL_HARDWARE_MODE == 1
    hwp_audProc->dpll_alfa1_cfg = AUD_PROC_DPLL_ALFA1(hw_alfa1) | AUD_PROC_DPLL_1_SUB_ALFA1((1<<12)-hw_alfa1);
    hwp_audProc->dpll_k1_k2_cfg = AUD_PROC_DPLL_K2(hw_k2) | AUD_PROC_DPLL_K1(hw_k1);
    hwp_audProc->dpll_alfa2_cfg = AUD_PROC_DPLL_1_SUB_ALFA2((1<<12)-hw_alfa2) | AUD_PROC_DPLL_ALFA2(hw_alfa2);
    hwp_audProc->dpll_other_cfg1 = AUD_PROC_DPLL_GAIN(hw_k_src);
#endif
}

void asio_src_set_trigger_status(bool state)
{
    TRACE("AUDIO: set src_trigger_state = %d\n",state);
    asio_src_param.src_trigger_state = state;
}

bool asio_src_get_trigger_status(void)
{
    //TRACE("AUDIO: get src_trigger_state = %d\n",asio_bt_param.src_trigger_state);
    return asio_src_param.src_trigger_state;
}

void asio_src_set_check_samplenum(bool state)
{
    TRACE("AUDIO: strb_set_check_samplenum = %d\n",state);
    asio_src_param.strb_check_samplenum = state;
}

bool asio_src_get_check_samplenum(void)
{
    return asio_src_param.strb_check_samplenum;
}

void asio_src_add_strb_num_counter(uint32_t strb_one)
{
    asio_src_param.strb_num_counter += strb_one;
}

uint32_t asio_src_get_strb_num_counter(void)
{
    return asio_src_param.strb_num_counter;
}

void asio_src_set_input_sample_num(uint32_t sample_num)
{
    TRACE("asio_src: set_input_sample_num = %d\n",sample_num);
    asio_src_param.input_samp_num_counter = sample_num;
}

uint32_t asio_src_get_input_sample_num(void)
{
    return asio_src_param.input_samp_num_counter;
}

void asio_src_set_samplerate_delta(int samplerate_delta)
{
    //TRACE("asio_src: samplerate_delta = %d\n",samplerate_delta);
    asio_src_param.samplerate_delta = samplerate_delta;
}

int asio_src_get_samplerate_delta(void)
{
    int backup_sample_delta = asio_src_param.samplerate_delta;
    asio_src_param.samplerate_delta = ((backup_sample_delta > 0x800000)? (backup_sample_delta -0x1000000): backup_sample_delta);
    TRACE("asio_src: get samplerate_delta = %d\n",asio_src_param.samplerate_delta);
    return asio_src_param.samplerate_delta;
}

static uint32_t asio_src_get_dpll_sample_delta_value(int samplerate_delta,AUD_SAMPRATE_T samp_rate)
{
    uint32_t samp_calculate_param = 0;

    switch (samp_rate)
    {
        case AUD_SAMPRATE_44100:
            {
                for(uint8_t i = 0;i < SAMP_TIME_TAB_NUM;i++){
                    int offset = aud_dpll_44100_samp_time_tab[i][0] - samplerate_delta;
                    if( offset >= 0 && offset <= 100){
                        samp_calculate_param = (uint32_t)(aud_dpll_44100_samp_time_tab[i][1] + (offset*AUD_DPLL_44100_SAMP_TETAL)/100);
                        break;
                    }
                }
            }
            break;
        case AUD_SAMPRATE_48000:
            {
                for(uint8_t i = 0;i < SAMP_TIME_TAB_NUM;i++){
                    int offset = aud_dpll_48000_samp_time_tab[i][0] - samplerate_delta;
                    if( offset >= 0 && offset <= 100){
                        samp_calculate_param = (uint32_t)(aud_dpll_48000_samp_time_tab[i][1] + (offset*AUD_DPLL_48000_SAMP_TETAL)/100);
                        break;
                    }
                }
            }
            break;
        default:
            TRACE("asio_src:get dpll sample delta error!\n");
            break;
    }
    TRACE("asio_src:get dpll sample delta = %d\n",samp_calculate_param);
    return samp_calculate_param;
}

static uint32_t asio_src_get_samp_calculate_param(AUD_SAMPRATE_T samp_rate)
{
    uint32_t samp_calculate_param = 0;
    int samplerate_delta = asio_src_get_samplerate_delta();
    switch (samp_rate)
    {
        case AUD_SAMPRATE_44100:
            {
                samp_calculate_param = asio_src_get_dpll_sample_delta_value(samplerate_delta,AUD_SAMPRATE_44100);// 1 000 000(us)*1000 *1000 / 44100 = (us)*1000 *1000
            }
            break;
        case AUD_SAMPRATE_48000:
            {
                samp_calculate_param = asio_src_get_dpll_sample_delta_value(samplerate_delta,AUD_SAMPRATE_48000);// 1 000 000(us)*1000 *1000/ 48000 = (us)*1000 *1000
            }
            break;
        case AUD_SAMPRATE_32000:
            samp_calculate_param = 31250000;// 1 000 000(us)*1000 *1000/ 32000 = (us)*1000*1000
            break;
        case AUD_SAMPRATE_16000:
            samp_calculate_param = 62500000;// 1 000 000(us)*1000 *1000/ 16000 = (us)*1000*1000
            break;
        case AUD_SAMPRATE_8000:
            samp_calculate_param = 125000000;// 1 000 000(us)*1000 *1000/ 8000 = (us)*1000*1000
            break;
        default:
            samp_calculate_param = 0;
            break;
    }
    return samp_calculate_param;
}


static uint32_t asio_src_get_sync_strb_cnt_cycle(AUD_SAMPRATE_T samp_rate)
{
    uint32_t sync_strb_cnt = 0;
    switch (samp_rate)
    {
        case AUD_SAMPRATE_44100:
            sync_strb_cnt = 44100/10;
            break;
        case AUD_SAMPRATE_48000:
            sync_strb_cnt = 48000/10;
            break;
        case AUD_SAMPRATE_32000:
            sync_strb_cnt = 32000/10;
            break;
        case AUD_SAMPRATE_16000:
            sync_strb_cnt = 16000/10;
            break;
        case AUD_SAMPRATE_8000:
            sync_strb_cnt = 8000/10;
            break;
        default:
            sync_strb_cnt = 100;
            break;
    }
    return sync_strb_cnt;
}

/*********************************************************************************************
@brief:    set src strb calculation param
@param:    after src samp_rate   //ep:44100 >> 48000 ,48000 is the src_sample_rate
@return:   0
**********************************************************************************************/
uint32_t asio_src_set_samplerate_cnt_th(AUD_SAMPRATE_T samp_rate)
{
    uint32_t FRAC_48K_CNT_TH = 0;
    uint32_t FRAC_48K_CNT_TH_L = 0;
    switch (samp_rate)
    {
        case AUD_SAMPRATE_44100:
            FRAC_48K_CNT_TH = 0x0;
            FRAC_48K_CNT_TH_L = 0x93;
            break;
        case AUD_SAMPRATE_48000:
            FRAC_48K_CNT_TH = 0x0;
            FRAC_48K_CNT_TH_L = 0x87;
            break;
        case AUD_SAMPRATE_16000:
            FRAC_48K_CNT_TH = 0x1;
            FRAC_48K_CNT_TH_L = 0x95;
            break;
        case AUD_SAMPRATE_8000:
            FRAC_48K_CNT_TH = 0x3;
            FRAC_48K_CNT_TH_L = 0x2c;
            break;
        default:
            FRAC_48K_CNT_TH = 0x0;
            FRAC_48K_CNT_TH_L = 0x87;
            break;
    }
    hwp_audProc->frac_rate_adj_up_th = AUD_PROC_FRAC_RATE_ADJ_UP_TH(0x7fffff) | AUD_PROC_FRAC_48K_CNT_TH_H(FRAC_48K_CNT_TH);
    hwp_audProc->frac_rate_adj_dn_th = AUD_PROC_FRAC_RATE_ADJ_DN_TH(0X800000) | AUD_PROC_FRAC_48K_CNT_TH_L(FRAC_48K_CNT_TH_L);
    return 0;
}

uint32_t asio_src_ratio_calculate(AUD_SAMPRATE_T samp_rate, AUD_SAMPRATE_T src_samp_rate)
{
    uint32_t strb_samp_rate = 0;
    uint32_t src_ratio = 0;

    src_ratio = src_samp_rate / samp_rate;
    if (src_ratio >= 4) {
        strb_samp_rate = samp_rate * 4;
    } else if (src_ratio >= 2) {
        strb_samp_rate = samp_rate * 2;
    } else {
        strb_samp_rate = samp_rate;
    }
    return strb_samp_rate;
}

int asio_src_strb_init(AUD_STREAM_T stream, AUD_SAMPRATE_T samp_rate, AUD_SAMPRATE_T src_samp_rate)
{
    uint32_t sync_strb_cnt = 0;

    if (stream != AUD_STREAM_PLAYBACK) {
        return -1;
    }

    asio_src_set_samplerate_cnt_th(src_samp_rate);


    sync_strb_cnt = asio_src_get_sync_strb_cnt_cycle(asio_src_ratio_calculate(samp_rate, src_samp_rate));
    TRACE("asio_src_sync_init sync_strb_cnt = %d\n",sync_strb_cnt);

    //================================== added for btsync =============================================================
    GLOBAL_INT_DISABLE();
    NVIC_SetPriority(AUD_PROC_IRQn, __NVIC_PRIO_LOWEST);
    hwp_audProc->aud_proc_irq      &= ~(AUD_PROC_IRQ_AUD_PROC_MASK(0x0F));
    hwp_audProc->aud_proc_irq      |= (AUD_PROC_IRQ_AUD_PROC_MASK(2) | AUD_PROC_IRQ_AUD_PROC_CLR(0xF));
    NVIC_ClearPendingIRQ(AUD_PROC_IRQn);
    hwp_audProc->aud_proc_dac_strb = AUD_PROC_DAC_SRC_STRB_CNT_EN | AUD_PROC_AUD_PROC_DAC_STB_SEL(1) | AUD_PROC_DAC_SRC_STRB_LO_CNT_TH(sync_strb_cnt*2-1);
    NVIC_EnableIRQ(AUD_PROC_IRQn);
    GLOBAL_INT_RESTORE();
    ///================================================================================================================

    return 0;
}

int asio_src_strb_clear(void)
{
    GLOBAL_INT_DISABLE();
    NVIC_DisableIRQ(AUD_PROC_IRQn);
    hwp_audProc->aud_proc_dac_strb = 0;
    hwp_audProc->aud_proc_irq = AUD_PROC_IRQ_AUD_PROC_CLR(0xF);
    GLOBAL_INT_RESTORE();

    return 0;
}

void asio_src_change_samplerate_delta(int delta)
{
    asio_src_set_samplerate_delta(delta);
    hwp_audProc->aud_proc_frac_src = AUD_PROC_FRAC_SRC_EN | AUD_PROC_FRAC_RATE_ADJ_SOFT_EN | AUD_PROC_FRAC_RATE_ADJ_SW(DEFAULT_SRC_DPLL_OFFSET+delta);
}

void asio_src_frac_src_init(void)
{
    hwp_audProc->aud_proc_frac_src = AUD_PROC_FRAC_SRC_EN | AUD_PROC_FRAC_RATE_ADJ_SOFT_EN | AUD_PROC_FRAC_RATE_ADJ_SW(DEFAULT_SRC_DPLL_OFFSET);
}

void asio_src_frac_src_clear(void)
{
    hwp_audProc->aud_proc_frac_src = 0;
    asio_src_dpll_clear();
}

int asio_src_trigger_init(uint32_t trigger_cnt,uint32_t trigger_delta)
{
    uint32_t adjust_trigger_value = 0;

    if (audio_config_device_get() == AUD_DEVICE_EXT_AIC1000) {
        return 0;
    }

    if(trigger_cnt == 0){
        return 0;
    }

    aud_dac_sync_iomux_config();
    if(trigger_delta){
        uint32_t tmp_value = trigger_ticker_read();
        adjust_trigger_value = (trigger_cnt - ((tmp_value - trigger_delta)<<3));
    }else{
        adjust_trigger_value = trigger_cnt;
    }
    //================================== added for btsync =============================================================
    hwp_audProc->aud_proc_dac_trig  = AUD_PROC_DAC_SRC_TRIG_CNT_TH(adjust_trigger_value) | AUD_PROC_AUD_DAC_TRIG_HW_EN | AUD_PROC_AUD_DAC_TRIG_CFG_UPDATE;
    hwp_audProc->aud_proc_dac_cfg2 |= (AUD_PROC_AUD_PROC_DAC_TRIG_EN | AUD_PROC_AUD_PROC_TX_I2S_TRIG_EN);
    hwp_audProc->aud_proc_adc_cfg2 |= (AUD_PROC_AUD_PROC_RX01_I2S_TRIG_EN | AUD_PROC_AUD_PROC_RX23_I2S_TRIG_EN);

    //================================== added for btsync =============================================================
    TRACE("asio_src_trigger_init trigger_cnt = %x,adj_cnt = %x\n", trigger_cnt,adjust_trigger_value);
    asio_src_set_trigger_status(true);

    return 0;
}

int asio_src_trigger_clear(void)
{
    if (audio_config_device_get() == AUD_DEVICE_EXT_AIC1000) {
        return 0;
    }

    TRACE("asio_src_triger_clear\n");

    //================================== added for btsync =============================================================
    hwp_audProc->aud_proc_dac_trig  = AUD_PROC_AUD_DAC_TRIG_CFG_UPDATE;
    hwp_audProc->aud_proc_dac_cfg2 &= ~(AUD_PROC_AUD_PROC_DAC_TRIG_EN | AUD_PROC_AUD_PROC_TX_I2S_TRIG_EN);
    hwp_audProc->aud_proc_adc_cfg2 &= ~(AUD_PROC_AUD_PROC_RX01_I2S_TRIG_EN | AUD_PROC_AUD_PROC_RX23_I2S_TRIG_EN);

    //================================== added for btsync =============================================================
    asio_src_set_trigger_status(false);

    return 0;
}


void asio_src_clear(void)
{
    asio_src_strb_clear();
    asio_src_frac_src_clear();
    asio_src_trigger_clear();
    asio_src_param_clear();
}

void asio_adc_src_init(void)
{
    hwp_audProc->aud_src_ctrl1 = AUD_PROC_AUD_SRC_FRAC_RATE_ADJ_SW(DEFAULT_SRC_DPLL_OFFSET);
    hwp_audProc->aud_src_ctrl2 |= AUD_PROC_AUD_SRC_FRAC_SRC_EN;
}

void asio_adc_src_clear(void)
{
    hwp_audProc->aud_src_ctrl2 &= ~AUD_PROC_AUD_SRC_FRAC_SRC_EN;
}

void asio_adc_src_change_samplerate_delta(int delta)
{
    hwp_audProc->aud_src_ctrl1 = AUD_PROC_AUD_SRC_FRAC_RATE_ADJ_SW(DEFAULT_SRC_DPLL_OFFSET+delta);
}

void asio_adc_src_process(uint16_t buff_size ,int sync_size)
{
    int size = 0;
    int time_delta = 0;
    int sample_delta = 0;
    int sample_delta_signed = 0;
    static int backup_sample_delta = 0;
    //int sync_size = AUD_ADC_SRC_CHECK_SIZE;

    size = buff_size;
    if(size >= sync_size){
        sample_delta_signed = ((backup_sample_delta > 0x800000)? (backup_sample_delta -0x1000000): backup_sample_delta);
        if(sample_delta_signed < AUD_DPLL_MAX_SAMP_TIME){
            time_delta = (size-sync_size)*AUD_ADC_SRC_ONE_BYTE_TIME/1000;
            if(time_delta > 0xffff)
                time_delta = 0xffff;
        }
        sample_delta = dpll_task_sft(time_delta);
        sample_delta = ((sample_delta > 0x800000)? (sample_delta -0x1000000): sample_delta);
        if(sample_delta > AUD_DPLL_MAX_SAMP_TIME){
            sample_delta = AUD_DPLL_MAX_SAMP_TIME;
        }
    }else{
        sample_delta_signed = ((backup_sample_delta > 0x800000)? (backup_sample_delta -0x1000000): backup_sample_delta);
        if(sample_delta_signed > AUD_DPLL_MIN_SAMP_TIME){
            time_delta = (size-sync_size)*AUD_ADC_SRC_ONE_BYTE_TIME/1000;
            sample_delta = dpll_task_sft(time_delta);
            sample_delta = ((sample_delta > 0x800000)? (sample_delta -0x1000000): sample_delta);
            if(sample_delta < AUD_DPLL_MIN_SAMP_TIME){
                sample_delta = AUD_DPLL_MIN_SAMP_TIME;
            }
        }
    }
    if(sample_delta ){//&& (backup_sample_delta !=  sample_delta)
        backup_sample_delta = sample_delta;
        dbg("%s td = %d ,sd = %d \n",__func__,time_delta,sample_delta);
        asio_adc_src_change_samplerate_delta(sample_delta);
    }
}

void asio_dac_src_process(uint16_t buff_size ,int sync_size)
{
    int size = 0;
    int time_delta = 0;
    int sample_delta = 0;
    int sample_delta_signed = 0;
    static int backup_sample_delta = 0;
    //int sync_size = AUD_ADC_SRC_CHECK_SIZE;

    size = buff_size;
    if(size >= sync_size){
        sample_delta_signed = ((backup_sample_delta > 0x800000)? (backup_sample_delta -0x1000000): backup_sample_delta);
        if(sample_delta_signed < AUD_DPLL_MAX_SAMP_TIME){
            time_delta = (size-sync_size)*AUD_ADC_SRC_ONE_BYTE_TIME/1000;
            if(time_delta > 0xffff)
                time_delta = 0xffff;
        }
        sample_delta = dpll_task(time_delta);
        sample_delta = ((sample_delta > 0x800000)? (sample_delta -0x1000000): sample_delta);
        if(sample_delta > AUD_DPLL_MAX_SAMP_TIME){
            sample_delta = AUD_DPLL_MAX_SAMP_TIME;
        }
    }else{
        sample_delta_signed = ((backup_sample_delta > 0x800000)? (backup_sample_delta -0x1000000): backup_sample_delta);
        if(sample_delta_signed > AUD_DPLL_MIN_SAMP_TIME){
            time_delta = (size-sync_size)*AUD_ADC_SRC_ONE_BYTE_TIME/1000;
            sample_delta = dpll_task(time_delta);
            sample_delta = ((sample_delta > 0x800000)? (sample_delta -0x1000000): sample_delta);
            if(sample_delta < AUD_DPLL_MIN_SAMP_TIME){
                sample_delta = AUD_DPLL_MIN_SAMP_TIME;
            }
        }
    }
    if(sample_delta ){//&& (backup_sample_delta !=  sample_delta)
        backup_sample_delta = sample_delta;
        dbg("%s td = %d ,sd = %d \n",__func__,time_delta,sample_delta);
        asio_src_change_samplerate_delta(sample_delta);
    }
}

#if DPLL_HARDWARE_MODE == 1
signed int dpll_task (signed int din)
{
    signed int dout;
    hwp_audProc->dpll_trig_cfg = AUD_PROC_DPLL_HW_EN | AUD_PROC_DPLL_STEP_TRIG | AUD_PROC_DPLL_DIN(din);
    dout = hwp_audProc->dpll_trig_cfg;
    while((dout & AUD_PROC_DPLL_CAL_FINISH) != AUD_PROC_DPLL_CAL_FINISH)
    {
      dout = hwp_audProc->dpll_trig_cfg;
    }
    dout = hwp_audProc->frac_rate_adj_hw;
    return(dout);
}
#else
signed int dpll_task (signed int din)
{
    return 0;
}
#endif
#if DPLL_SOFTWARE_MODE == 1
void asio_src_sft_dpll_clear(void)
{
    y1_d=0;
    y2_d=0;
    y3_d=0;
    y4_d=0;
}

void asio_src_set_sft_dpll_param_in_diffmode(AUD_DPLL_MODE mode)
{
    asio_src_param.audio_sft_dpll_mode = mode;
    switch(mode){
        case AUD_DPLL_NORMAL:
            alfa1=4039; //S14.12
            alfa2=4039;//S14.12
            k1=3; //S14.12
            k2=6226; //S14.2
            k_src=115; //S14.8
            TRACE("AUDIO: dpll_normal_mode\n");
            break;
        case AUD_DPLL_TWS:
            alfa1=3957;//2482; //S14.12
            alfa2=1827;//3465;//S14.12
            k1=125;//229; //S14.12
            k2=963;//234; //S14.2
            k_src=512;//419; //S14.8
            TRACE("AUDIO: dpll_tws_mode\n");
            break;
        default:
            break;
    }
}

signed int data_sum_sat(signed int din1, signed int din2,unsigned int dout_width, unsigned right_shift)
{
    signed int dout;

    dout = din1 + din2;

    if((din1 >0) && (din2>0)) ///upper overflower
    {
        if(dout<0)
        dout = ((1<<(dout_width-1))-1);
    }

    if((din1 <0) && (din2<0)) ///down overflower
    {
        if(dout>=0)
        dout = -((1<<(dout_width-1)));
    }

    if(dout>=0)
    {
        if(dout>(1<<(dout_width-1+right_shift)))
            dout = ((1<<(dout_width-1))-1);
        else
            dout =  dout>>right_shift;

    }
    else
    {
        if(dout<-(1<<(dout_width-1+right_shift)))
            dout = -((1<<(dout_width-1)));
        else
            dout = dout>>right_shift;
    }
    //rprintf(" din1 =%x, din2 =%x, dout=%x!!!\n", din1, din2, dout);
    return(dout);
}


signed int data_mult_sat(signed int coef, signed int din, unsigned int dout_width, unsigned int frac_width)
{
    signed int din0,din1,din2,dout;
    din0 = din >=0 ? din>>frac_width : -((-din)>>frac_width);
    din1 = (din0)*coef;
    din2 = ((din - ((din0)*(1<<frac_width)))*coef)>>frac_width;
    dout = data_sum_sat(din1,din2,dout_width,0);
    return(dout);
}

signed int dpll_task_sft(signed int din)
{
    signed int dout;
    signed int y1_1,y1_2,y1_1_sat,y1_2_sat,y1_3,y1_3_sat,y3_1_sat,y_src,y_src_sat;
    signed int y1 =0;
    signed int y2 =0;
    signed int y3 =0;
    signed int y4 =0;
    signed int y3_1_0,y3_1_1,y3_1_1_sat,y3_1_2,y3_1_3,y3_1_3_sat,y4_1_0,y4_1_1,y4_1,y4_2,y4_1_sat,y4_2_sat;
    signed int y3_1 = 0;
    signed int y1_sat,y2_sat,y3_sat,y4_sat;//S30.12
    //rprintf(" din = %x!!!\n",din);
    y1_1_sat = data_mult_sat(k1,din,30,0);//(S14.12 * S17.0) = S30.12
    //rprintf(" y1_1_sat = %x!!!\n",y1_1_sat);
    y1_2_sat = data_mult_sat(((1<<12)-alfa1),y1_1_sat,30,12);//(S14.12 * S17.0)/2^12 = S30.12
    //rprintf(" y1_2_sat = %x!!!\n",y1_2_sat);
    y1_3_sat = data_mult_sat(alfa1,y1_d,30,12);//(S30.12 * S14.12) / 2^12 = S30.12
    //rprintf(" y1_3_sat = %x!!!\n",y1_3_sat);
    y1_sat   = data_sum_sat(y1_2_sat,y1_3_sat,30,0);//S30.12
    //rprintf(" y1_sat = %x!!!\n",y1_sat);
    y1_d=y1_sat;



    y2_sat   = data_sum_sat(y1_sat,y2_d,30,0);//S30.12
    y2_d=y2_sat;//S30.12
    //rprintf(" y2_sat = %x!!!\n",y2_sat);

    //y3_1_0 = y1_sat >=0 ? (y1_sat>>12) : -((-y1_sat)>>12);    //S18.0
    y3_1_0 = y1_sat >=0 ? (y1_sat>>12) : -((-y1_sat)>>12);    //S18.0
    //rprintf(" y3_1_0 = %x!!!\n",y3_1_0);
    y3_1_1_sat = data_mult_sat(k2,y3_1_0,18,2); //(S18.0 * S14.2)/2^2  = S30.0    -->S18.0
    //rprintf(" y3_1_1_sat = %x!!!\n",y3_1_1_sat);
    //y3_1_2 = y3_1_1_sat >=0 ? (y3_1_1_sat<<12) : -((-y3_1_1_sat)<<12);//S18.0-->S30.12
    y3_1_2 = y3_1_1_sat*(1<<12);//S30.12
    //rprintf(" y3_1_2 = %x!!!\n",y3_1_2);

    //y3_1_3 = y1_sat >=0 ? (y1_sat&((1<<12)-1)) : -(((-y1_sat)&((1<<12)-1)));//S13.12
    y3_1_3 = (y1_sat - ((y3_1_0)*(1<<12)));//S13.12
    y3_1_3_sat = data_mult_sat(k2,y3_1_3,24,2); //(S14.2 * S13.12)/2^2 = S24.12
    //rprintf(" y3_1_3_sat = %x!!!\n",y3_1_3_sat);
    y3_1_sat   = data_sum_sat(y3_1_2,y3_1_3_sat,30,0);//S30.12 + S24.12 = S30.12
    //rprintf(" y3_1_sat = %x!!!\n",y3_1_sat);

    y3_sat   = data_sum_sat(y2_sat,y3_1_sat,30,0); //S30.12
    //rprintf(" y3_sat = %x!!!\n",y3_sat);

    y4_1_sat = data_mult_sat(alfa2,y3_sat,30,12);//(S14.12 * S30.12)/2^12 = S32.12
    //rprintf(" y4_1_sat = %x!!!\n",y4_1_sat);
    y4_2_sat = data_mult_sat(((1<<12)-alfa2),y4_d,30,12);//(S14.12 * S30.12)/2^12 = S32.12 ->30.12
    //rprintf(" y4_2_sat = %x!!!\n",y4_2_sat);

    y4_sat   = data_sum_sat(y4_1_sat,y4_2_sat,30,0);//S30.12
    y4_d     = y4_sat; //S30.12
    //rprintf(" y4_sat = %x!!!\n",y4_sat);

    y_src     = data_mult_sat(k_src,y4_sat,30,12);    //(S14.8 * S30.12)/2^12 = S30.8
    y_src_sat = data_sum_sat(y_src,0,22,8);//S22.0
    dout =y_src_sat &0xffffff;
    //rprintf(" dout = %x!!!\n",dout);
    return(dout);
}
#else
signed int dpll_task_sft(signed int din)
{
    return 0;
}
#endif



#if (PLF_BT_STACK)
#if PLF_BLE_ONLY == 0
#include "app_bt_queue.h"

MediaSyncParamStruct tws_audio_sync_data = {0, 0, 0, 0, 0, 0};

void asio_src_delay_us(uint32_t xus)
{
    uint32_t delta_us = xus;
    delta_us = delta_us*42;//240M 42 ~= 1us
    for (int idx = 0; idx < delta_us; idx++) {
        __NOP();
    }
}

uint32_t asio_src_check_sync_clock_delayUS(uint32_t clk1,uint32_t bt_counter1,uint32_t clk2,uint32_t bt_counter2)
{
    return ((clk1 - clk2)*625 + bt_counter1 - bt_counter2)/2;
}

uint32_t asio_src_check_sync_counter_delayUS(uint32_t bt_counter1,uint32_t bt_counter2)
{
    return (bt_counter1 - bt_counter2)/2;
}

uint32_t asio_src_check_sync_clockoffset_delayUS(uint32_t offset1,uint32_t bt_counter1,uint32_t offset2,uint32_t bt_counter2)
{
    return ((offset1 - offset2)*2 + bt_counter1 - bt_counter2)/2;
}


void asio_src_handle_sync_param(MediaSyncParamStruct * sync_param)
{
#if PLF_BT_STACK == 1
    signed int time_delta = 0;
    signed int sample_delta = 0;
    MediaSyncParamStruct tws_slave_audio_sync_data = {0,0,0,0,0};

    tws_slave_audio_sync_data.counterNum = tws_audio_sync_data.counterNum;
    tws_slave_audio_sync_data.current_clk = tws_audio_sync_data.current_clk;
    if(tws_audio_sync_data.current_bt_counter*1000 >= tws_audio_sync_data.master_current_samplerate){
        tws_slave_audio_sync_data.current_bt_counter = (tws_audio_sync_data.current_bt_counter*1000 - tws_audio_sync_data.master_current_samplerate)/1000;
    }else{
        tws_slave_audio_sync_data.current_bt_counter = 625 - ((tws_audio_sync_data.master_current_samplerate - tws_audio_sync_data.current_bt_counter*1000)/1000);
        tws_slave_audio_sync_data.current_clk  = CLK_SUB(tws_slave_audio_sync_data.current_clk,1);
    }

    if(sync_param->counterNum == tws_slave_audio_sync_data.counterNum){
        if(sync_param->strb_cycle_offset){
            uint32_t bt_clk_offset = 0;
            uint32_t master_clk_plus_counter = 0;
            uint32_t slave_clk_plus_counter = 0;
            bt_clk_offset = ((tws_slave_audio_sync_data.current_clk - sync_param->current_clk)*625)*500;
            master_clk_plus_counter = (sync_param->strb_cycle_offset + sync_param->current_bt_counter*500);
            slave_clk_plus_counter = (bt_clk_offset + tws_slave_audio_sync_data.current_bt_counter*500);
            //TRACE("asio_src: bt_clk_offset = %d,master_clk_plus_counter =%d,slave_clk_plus_counter = %d\n",bt_clk_offset,master_clk_plus_counter,slave_clk_plus_counter);
            if(master_clk_plus_counter > slave_clk_plus_counter){
                time_delta = 0 - (signed int)(master_clk_plus_counter - slave_clk_plus_counter)/1000;
                sample_delta = dpll_task(time_delta);
            }else if(master_clk_plus_counter < slave_clk_plus_counter){
                time_delta = (slave_clk_plus_counter-master_clk_plus_counter)/1000;
                sample_delta = dpll_task(time_delta);
            }else{
                sample_delta = dpll_task(0);
            }
        }else{
            if(sync_param->current_clk > tws_slave_audio_sync_data.current_clk){
                time_delta = 0 - (signed int)asio_src_check_sync_clock_delayUS(sync_param->current_clk ,sync_param->current_bt_counter, tws_slave_audio_sync_data.current_clk,tws_slave_audio_sync_data.current_bt_counter);
                sample_delta = dpll_task(time_delta);
            }else if(sync_param->current_clk < tws_slave_audio_sync_data.current_clk){
                time_delta = asio_src_check_sync_clock_delayUS(tws_slave_audio_sync_data.current_clk ,tws_slave_audio_sync_data.current_bt_counter, sync_param->current_clk,sync_param->current_bt_counter);
                sample_delta = dpll_task(time_delta);
            }else{
                if((sync_param->current_bt_counter) > (tws_slave_audio_sync_data.current_bt_counter))
                {
                    time_delta = 0 - (signed int)asio_src_check_sync_counter_delayUS((sync_param->current_bt_counter) , (tws_slave_audio_sync_data.current_bt_counter));
                    sample_delta = dpll_task(time_delta);
                }
                else if((sync_param->current_bt_counter) < (tws_slave_audio_sync_data.current_bt_counter))
                {
                    time_delta = asio_src_check_sync_counter_delayUS((tws_slave_audio_sync_data.current_bt_counter), (sync_param->current_bt_counter));
                    sample_delta = dpll_task(time_delta);
                }
                else{
                    sample_delta = dpll_task(0);
                }
            }
        }

        TRACE("asio_src:td %d ,sd %d\n",time_delta,sample_delta);
        asio_src_change_samplerate_delta(sample_delta);
        if(time_delta > AUD_DIE_MAX_TIME || time_delta < AUD_DIE_MIN_TIME){
            app_bt_send_bt_audio_restart();
        }
    }
#endif
}

void AUD_PROC_IRQHandler(void)
{
    unsigned int rdata;

#if PLF_BT_STACK == 1
#ifndef CFG_TEST_AF
#ifndef CFG_TEST_SDCARD_AUDIO
    {
        unsigned int strb_lo_cnt;
        unsigned int strb_hi_cnt;
        unsigned int bt_clk_lo;
        unsigned int bt_clk_hi;
        unsigned int bt_clk_lo_offset;
        static unsigned int last_bt_clk_hi = 0xffffffff;//add for debug reg update later.

        uint32_t ret = 0;
        uint32_t samplerate = 0;
        uint32_t sample_num_offset = 0;
        ASIO_STREAM_CFG_T *stream_cfg = NULL;
        TWS_BT_CLK_INFO_Type bt_offset;
        asio_src_delay_us(1);
        do{
            strb_lo_cnt = ((hwp_audProc->dac_src_strb_lo_cnt)& AUD_PROC_SRC_FRAC_STRB_LATCH(0xff))>>24;
            strb_hi_cnt = hwp_audProc->dac_src_strb_hi_cnt;
            bt_clk_lo = 624 - (hwp_audProc->bt_clk_lo_cnt_latch & AUD_PROC_BT_CLK_LO_CNT_LATCH(0xffffff));
            bt_clk_hi = hwp_audProc->bt_clk_hi_cnt_latch;
            bt_clk_lo_offset = (hwp_audProc->bt_clk_lo_cnt_latch>>24) & (0x3f);
        }while(last_bt_clk_hi == bt_clk_hi);

        last_bt_clk_hi = bt_clk_hi;

        bt_offset = rwip_clk_offset_read();
        bt_clk_hi = CLK_ADD_2(bt_clk_hi,bt_offset.clk_off_hs);

        if(bt_clk_lo >= bt_offset.clk_off_hus)
            bt_clk_lo = bt_clk_lo - bt_offset.clk_off_hus;
        else
        {
            bt_clk_lo = 625 - (bt_offset.clk_off_hus - bt_clk_lo);
            bt_clk_hi  = CLK_SUB(bt_clk_hi,1);
        }

        if(bt_offset.clk_off_hus || bt_offset.clk_off_hs ){
            bt_clk_lo += 20;
        }

        if(bt_clk_lo >= 625)
        {
            bt_clk_lo -= 625;
            bt_clk_hi  = CLK_ADD_2(bt_clk_hi,1);
        }

        ret = asio_stream_config_ptr_get(AUD_STREAM_GROUP_0, AUD_STREAM_PLAYBACK, &stream_cfg, false);
        if(ret == 0){
            samplerate = (uint32_t)asio_src_ratio_calculate(stream_cfg->samp_rate, stream_cfg->src_samp_rate);
            asio_src_add_strb_num_counter(1);
            if(asio_src_get_check_samplenum()){
                uint32_t ratio = 1;
                uint32_t input_s_n = asio_src_get_input_sample_num();
                uint32_t strb_n = asio_src_get_strb_num_counter()*asio_src_get_sync_strb_cnt_cycle(samplerate);
                uint32_t samp_calculate_param_int = (asio_src_get_samp_calculate_param(samplerate)/1000);
                uint32_t samp_calculate_param_dec = (asio_src_get_samp_calculate_param(samplerate)%1000);

                asio_src_set_check_samplenum(false);
                ratio = samplerate/stream_cfg->samp_rate;
                input_s_n = input_s_n*ratio;
                sample_num_offset = (samp_calculate_param_int*(input_s_n - strb_n)+ (samp_calculate_param_dec*(input_s_n - strb_n))/1000)/1000;
                TRACE("strb:param_int %d ,param_dec %d,sno %d,snc %d,ro %d\n",samp_calculate_param_int,samp_calculate_param_dec,\
                    sample_num_offset,asio_src_get_strb_num_counter(),ratio);//sno:sample_num_offset ; snc: strb_num_counter
            }

            tws_audio_sync_data.current_clk = bt_clk_hi;
            tws_audio_sync_data.counterNum = strb_hi_cnt;
            tws_audio_sync_data.master_current_samplerate = ((strb_lo_cnt *4166666)/samplerate);// ((1/240)*1000*1000)(us)*1000 = 4166666
            tws_audio_sync_data.current_bt_counter = bt_clk_lo;
            tws_audio_sync_data.current_bt_counter_offset = bt_clk_lo_offset;
            app_bt_send_audio_sync_param(bt_clk_hi,strb_hi_cnt,tws_audio_sync_data.master_current_samplerate,bt_clk_lo,bt_clk_lo_offset,sample_num_offset);
            //timer20prit();
            //TRACE("AUD_TWS:dac h= %d,bt clk l =%d, h=0x%x strb_lo = %d",strb_hi_cnt, bt_clk_lo, bt_clk_hi,strb_lo_cnt);
            //TRACE(",samplerate = %d,strb_lo1=%d \n",samplerate, tws_audio_sync_data.master_current_samplerate);
#if STRB_DBG
            TRACE("strb %05d,%03d,%05d,bt 0x%06x,%03d,%02d,%d,%x,%d\n",strb_hi_cnt, strb_lo_cnt,tws_audio_sync_data.master_current_samplerate,
            bt_clk_hi,bt_clk_lo,bt_clk_lo_offset,samplerate,bt_offset.clk_off_hs,bt_offset.clk_off_hus);
#endif
        }
    }
#endif
#endif
#endif
    rdata = hwp_audProc->aud_proc_irq;
    hwp_audProc->aud_proc_irq |= AUD_PROC_IRQ_AUD_PROC_CLR((rdata & AUD_PROC_IRQ_AUD_PROC_MASKED(0x3)));
}
#endif
#endif
