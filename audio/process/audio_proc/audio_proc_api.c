#include <stdint.h>
#include <stdbool.h>
#include "aud_proc.h"
#include "dbg.h"

/*
 * for dac, 8bits
 * if (bit[7:0] != 0) {
 *     volume = bit[5:0] + bit[6] * 6dB + bit[7] * 12dB;
 * } else {
 *     volume = mute;
 * }
 * eg. 8'h33 = -0.5dB + 0 * 6dB + 0 * 12dB = -0.5dB;
 * eg. 8'h74 = 0dB + 1 * 6dB + 0 * 12dB = 6dB;
 * eg. 8'hB5 = 0.5dB + 0 * 6dB + 1 * 12dB = 12.5dB;
 * eg. 8'hff = 5.5dB + 1 * 6dB + 1 * 12dB = 23.5dB;
 *
 * |----------|-------|-------------|
 * | bit[5:0] | 6'h0  | -26dB       |
 * |----------|-------|-------------|
 * | bit[5:0] | 6'h1  | -25.5dB     |
 * |----------|-------|-------------|
 * | bit[5:0] |  ...  | +0.5dB/step |
 * |----------|-------|-------------|
 * | bit[5:0] | 6'h34 |  0dB        |
 * |----------|-------|-------------|
 * | bit[5:0] |  ...  | +0.5dB/step |
 * |----------|-------|-------------|
 * | bit[5:0] | 6'h3e |  5dB        |
 * |----------|-------|-------------|
 * | bit[5:0] | 6'h3f |  5.5dB      |
 * |----------|-------|-------------|
 */
int audio_proc_dac_volume_set(uint8_t volume)
{
    uint32_t val;

    val = hwp_audProc->aud_proc_dac_cfg1;
    val &= ~(AUD_PROC_DAC_VOLUME_L(0xFF) | AUD_PROC_DAC_VOLUME_R(0xFF));
    val |= (AUD_PROC_DAC_VOLUME_L(volume) | AUD_PROC_DAC_VOLUME_R(volume));
    hwp_audProc->aud_proc_dac_cfg1 = val;

    return 0;
}

/*
 * for adc, 4bits
 * |----------|-------|-------------|
 * | bit[3:0] | 4'h0  |  mute       |
 * |----------|-------|-------------|
 * | bit[3:0] | 4'h1  | -12dB       |
 * |----------|-------|-------------|
 * | bit[3:0] |  ...  | +2dB/step   |
 * |----------|-------|-------------|
 * | bit[3:0] | 4'h7  |  0dB        |
 * |----------|-------|-------------|
 * | bit[3:0] |  ...  | +2dB/step   |
 * |----------|-------|-------------|
 * | bit[3:0] | 4'he  |  14dB       |
 * |----------|-------|-------------|
 * | bit[3:0] | 4'hf  |  16dB       |
 * |----------|-------|-------------|
 */
int audio_proc_adc_volume_set(uint8_t volume)
{
    uint32_t val;

    if (volume > 0x0F) {
        dbg("ERR: adc volume out of range\n");
        return -1;
    } else {
        val = hwp_audProc->aud_proc_adc_cfg1;
        val &= ~(AUD_PROC_ADC_VOLUME_L(0xF) | AUD_PROC_ADC_VOLUME_R(0xF));
        val |= (AUD_PROC_ADC_VOLUME_L(volume) | AUD_PROC_ADC_VOLUME_R(volume));
        hwp_audProc->aud_proc_adc_cfg1 = val;
    }

    return 0;
}

uint8_t audio_proc_dac_volume_get(void)
{
    uint8_t vol;

    vol = (uint8_t)((hwp_audProc->aud_proc_dac_cfg1 & AUD_PROC_DAC_VOLUME_L(0xFF)) >> 16);

    return vol;
}

uint8_t audio_proc_adc_volume_get(void)
{
    uint8_t vol;

    vol = (uint8_t)((hwp_audProc->aud_proc_adc_cfg1 & AUD_PROC_ADC_VOLUME_L(0xF)) >> 0);

    return vol;
}

/*
 *
 convert dac volume, from dB to reg valule
 * any value that > +23.5dB is regarded as +23.5dB, any value that < -25.5dB is regarded as mute
 * eg. input:-25dB      output:0x02
 * eg. input:0dB        output:0x34
 * eg. input:+6.5dB     output:0x75
 */
uint8_t audio_proc_dac_volume_convert_db_to_reg(float dB)
{
    uint8_t vol;

    if (dB < -25.5f) {
        vol = 0;
    } else if (dB <= 5.5f) {
        // (dB - (-25.5f)) / 0.5f + 1
        vol = (uint8_t)((int)(dB * 2) + 51) + 1;;
    } else if (dB <= 23.5f) {
        uint8_t vol_frac = 0;
        uint8_t vol_int = 0;

        while (dB >= 6) {
            dB -= 6;
            vol_int += 1;
        }
        vol_frac = (uint8_t)((int)(dB * 2)) + 0x34;
        vol = (vol_int << 6) | vol_frac;
    } else {
        vol = 0xFF;
    }

    return vol;
}

/*
 *
 convert adc volume, from dB to reg valule
 * any value that > +16dB is regarded as +16dB, any value that < -12dB is regarded as mute
 * eg. input:-12dB      output:0x01
 * eg. input:0dB        output:0x07
 * eg. input:+12dB      output:0x0D
 */
uint8_t audio_proc_adc_volume_convert_db_to_reg(int8_t dB)
{
    uint8_t vol;

    if (dB < -12) {
        vol = 0;
    } else if (dB > 16) {
        vol = 0x0F;
    } else {
        vol = (uint8_t)(dB + 12) / 2 + 1;
    }

    return vol;
}

/*
 *
 convert dac volume step, from dB to reg valule, dB must be multiple of 0.5dB
 * eg. input:0.5dB    output:1
 * eg. input:1dB      output:2
 * eg. input:3dB      output:6
 */
uint8_t audio_proc_dac_volume_step_convert_db_to_reg(float dB)
{
    uint8_t step;

    if (dB < 0) {
        dB = 0.0f - dB;
    }

    if (dB > 49.5f) {
        step = 99;
    } else {
        step = (uint8_t)(dB * 2);
    }

    return step;
}

/*
 *
 convert adc volume step, from dB to reg valule, dB must be multiple of 2dB
 * eg. input:2dB    output:1
 * eg. input:4dB    output:2
 * eg. input:6dB    output:3
 */
uint8_t audio_proc_adc_volume_step_convert_db_to_reg(uint8_t dB)
{
    uint8_t step;

    if (dB > 28) {
        step = 15;
    } else {
        step = dB / 2;
    }

    return step;
}

/*
 * for dac, 1 step is 0.5dB
 */
bool audio_proc_dac_volume_up(uint8_t step)
{
    uint8_t vol;
    uint8_t vol_frac;
    uint8_t vol_int;
    bool max_vol = false;

    vol = audio_proc_dac_volume_get();
    vol_frac = vol & 0x3F;
    vol_int = (vol & 0xC0) >> 6;

    while (step > 0) {
        if (step >= 0xC) {
            vol_frac += 0xC;
            step -= 0xC;
        } else {
            vol_frac += step;
            step = 0;
        }

        if (vol_frac > 0x3F) {
            vol_int += 1;
            vol_frac = (vol_frac & 0x3F) + 0x34;
        }

        if ((vol_int > 3) || ((vol_int == 3) && (vol_frac == 0x3F))) {
            max_vol = true;
            break;
        }
    }

    if (max_vol == true) {
        vol_int = 0x03;
        vol_frac =0x3F;
    }

    vol = (vol_int << 6) | vol_frac;

    audio_proc_dac_volume_set(vol);

    return max_vol;
}

/*
 * for dac, 1 step is 0.5dB
 */
bool audio_proc_dac_volume_down(uint8_t step)
{
    uint8_t vol;
    uint8_t vol_frac;
    uint8_t vol_int;
    bool min_vol = false;

    vol = audio_proc_dac_volume_get();
    vol_frac = vol & 0x3F;
    vol_int = (vol & 0xC0) >> 6;

    while (step > 0) {
        if (step >= 0xC) {
            if (vol_int > 0) {
                vol_int -= 1;
                step -= 0x0C;
            } else {
                if (vol_frac > step) {
                    vol_frac -= step;
                } else {
                    min_vol = true;
                }
                step = 0;
            }
        } else {
            // if vol_int > 0, vol_frac must >= 0x34, else vol_frac must <= 0x3F
            if (vol_int > 0) {
                vol_frac -= step;
                if (vol_frac < 0x34) {
                    vol_int -= 1;
                    vol_frac += 0x0C;
                }
            } else {
                if (vol_frac > step) {
                    vol_frac -= step;
                } else {
                    min_vol = true;
                }
            }
            step = 0;
        }
    }

    if (min_vol == true) {
        vol_int = 0;
        vol_frac = 0;
    }

    vol = (vol_int << 6) | vol_frac;

    audio_proc_dac_volume_set(vol);

    return min_vol;
}

/*
 * for adc, 1 step is 2dB
 */
bool audio_proc_adc_volume_up(uint8_t step)
{
    uint8_t vol;
    bool max_vol = false;

    vol = audio_proc_adc_volume_get();

    vol += step;
    if (vol >= 0x0F) {
        max_vol = true;
        vol = 0x0F;
    }

    audio_proc_adc_volume_set(vol);

    return max_vol;
}

/*
 * for adc, 1 step is 2dB
 */
bool audio_proc_adc_volume_down(uint8_t step)
{
    uint8_t vol;
    bool min_vol = false;

    vol = audio_proc_adc_volume_get();

    if (vol > step) {
        vol -= step;
    } else {
        min_vol = true;
        vol = 0;
    }

    audio_proc_adc_volume_set(vol);

    return min_vol;
}

void audio_proc_dac_volume_mute(void)
{
    audio_proc_dac_volume_set(0);
}

void audio_proc_adc_volume_mute(void)
{
    audio_proc_adc_volume_set(0);
}

/*
 * reset dac volume to 0dB
 */
void audio_proc_dac_volume_reset(void)
{
    audio_proc_dac_volume_set(0x34);
}

/*
 * reset adc volume to 0dB
 */
void audio_proc_adc_volume_reset(void)
{
    audio_proc_adc_volume_set(0x07);
}

