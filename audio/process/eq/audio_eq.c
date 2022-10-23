#include <stdint.h>
#include "dbg.h"
#include "dbg_assert.h"
#include "audio_eq.h"
#include "aud_proc.h"
#include "ll.h"

static EQ_TYPE_T dac_eq_type = EQ_NONE;

static EQ_TYPE_T adc_eq_type = EQ_NONE;
static EQ_CH_T adc_eq_ch = EQ_CH_NONE;

/* ISO center freqs
 * [31.5 64 125 250 500 1000 2000 4000 8000 16000]
 */

const int eq_preset[EQ_NUM][EQ_BANDS][EQ_COEFS_NUM] = {
    /* NONE [0 0 0 0 0 0 0 0 0 0] */
    {
        {2097152, -4174866, 4174866, 2077804, -2077804},
        {2097152, -4180652, 4180652, 2083674, -2083674},
        {2097152, -4167398, 4167398, 2070907, -2070907},
        {2097152, -4139511, 4139511, 2044986, -2044986},
        {2097152, -4080862, 4080862, 1994087, -1994087},
        {2097152, -3952536, 3952536, 1895843, -1895843},
        {2097152, -3655630, 3655630, 1712084, -1712084},
        {2097152, -2932422, 2932422, 1385728, -1385728},
        {2097152, -1228520, 1228520, 843509,  -843509 },
        {2097152, 117280,   -117280, 360974,  -360974 },
    },
    /* Pop [-1 -1 0 1 4 3 1 0 -1 1] */
    {
        {2096594, -4174306, 4174301, 2077796, -2077244},
        {2096475, -4179960, 4179960, 2083659, -2082982},
        {2097152, -4167398, 4167398, 2070907, -2070907},
        {2098109, -4140447, 4140447, 2044966, -2045923},
        {2118258, -4099325, 4099325, 1991491, -2012597},
        {2123580, -3975822, 3975822, 1892940, -1919368},
        {2107978, -3664933, 3664933, 1710953, -1721779},
        {2097152, -2932422, 2932422, 1385728, -1385728},
        {2015147, -1203700, 1203700, 866102,  -784098 },
        {2243256, 34441,    -202257, 384975,  -363264 },
    },
    /* Jazz [3 3 1 2 -1 -1 0 1 2 4] */
    {
        {2098858, -4176481, 4176497, 2077730, -2079421},
        {2099005, -4182372, 4182372, 2083541, -2085394},
        {2097293, -4167538, 4167538, 2070906, -2071047},
        {2103575, -4145462, 4145462, 2044518, -2050941},
        {2089654, -4073301, 4073301, 1994005, -1986506},
        {2086903, -3942631, 3942631, 1896086, -1885837},
        {2097152, -3655630, 3655630, 1712084, -1712084},
        {2128289, -2953718, 2953718, 1379885, -1411022},
        {2208259, -1259660, 1259660, 806939,  -918047 },
        {2626214, -208990,  -400265, 453528,  -373335 },
    },
    /* Rock [4 3 3 1 0 -1 0 1 2 4] */
    {
        {2099615, -4177150, 4177173, 2077650, -2080090},
        {2098502, -4181930, 4181930, 2083602, -2084952},
        {2100824, -4170793, 4170793, 2070630, -2074302},
        {2098640, -4140959, 4140959, 2044947, -2046435},
        {2097152, -4080862, 4080862, 1994087, -1994087},
        {2084680, -3940418, 3940418, 1896073, -1883601},
        {2097152, -3655630, 3655630, 1712084, -1712084},
        {2128226, -2953676, 2953676, 1379898, -1410973},
        {2208240, -1259654, 1259654, 806947,  -918034 },
        {2626221, -208995,  -400268, 453529,  -373335 },
    },
    /* Classic [4 4 3 2 -1 -1 0 1 3 4] */
    {
        {2099459, -4177015, 4177036, 2077669, -2079955},
        {2099348, -4182664, 4182664, 2083489, -2085685},
        {2100229, -4170277, 4170277, 2070709, -2073787},
        {2102430, -4144458, 4144458, 2044658, -2049936},
        {2089635, -4073281, 4073281, 1994004, -1986486},
        {2086851, -3942580, 3942580, 1896086, -1885785},
        {2097152, -3655630, 3655630, 1712084, -1712084},
        {2121357, -2949058, 2949058, 1381283, -1405488},
        {2289384, -1280706, 1280706, 776193,  -968425 },
        {2606133, -195358,  -390661, 449731,  -372693 },
    },
    /* Blues [2 6 4 0 -2 -1 2 2 1 3] */
    {
        {2097726, -4175427, 4175432, 2077796, -2078364},
        {2101273, -4184146, 4184146, 2083047, -2087168},
        {2101723, -4171547, 4171547, 2070486, -2075057},
        {2097152, -4139511, 4139511, 2044986, -2044986},
        {2085089, -4068438, 4068438, 1993695, -1981631},
        {2084729, -3940467, 3940467, 1896074, -1883651},
        {2141192, -3691847, 3691847, 1705784, -1749823},
        {2163533, -2976703, 2976703, 1371941, -1438322},
        {2118934, -1234845, 1234845, 836866,  -858649 },
        {2496476, -122542,  -336790, 429391,  -369383 },
    },
    /* Country [0 2 3 0 0 2 3 1 0 0] */
    {
        {2097152, -4174866, 4174866, 2077804, -2077804},
        {2098295, -4181742, 4181742, 2083622, -2084764},
        {2101243, -4171148, 4171148, 2070567, -2074658},
        {2097152, -4139511, 4139511, 2044986, -2044986},
        {2097152, -4080862, 4080862, 1994087, -1994087},
        {2114413, -3968109, 3968109, 1894314, -1911575},
        {2156666, -3703567, 3703567, 1702521, -1762036},
        {2115062, -2944787, 2944787, 1382504, -1400414},
        {2097152, -1228520, 1228520, 843509,  -843509 },
        {2097152, 117280,   -117280, 360974,  -360974 },
    },
    /* Dance [4 5 7 0 1 3 4 4 3 0] */
    {
        {2099373, -4176939, 4176960, 2077679, -2079879},
        {2099530, -4182815, 4182815, 2083458, -2085837},
        {2106720, -4175229, 4175229, 2069171, -2078739},
        {2097152, -4139511, 4139511, 2044986, -2044986},
        {2098447, -4082114, 4082114, 1994047, -1995342},
        {2123428, -3975698, 3975698, 1892966, -1919242},
        {2163979, -3708928, 3708928, 1700796, -1767623},
        {2223054, -3012920, 3012920, 1355435, -1481337},
        {2258333, -1272812, 1272812, 788348,  -949529 },
        {2097152, 117280,   -117280, 360974,  -360974 },
    },
    /* ACG [4 6 3 0 0 2 5 1 1 4] */
    {
        {2099144, -4176738, 4176756, 2077703, -2079677},
        {2101065, -4183998, 4183998, 2083107, -2087020},
        {2100001, -4170076, 4170076, 2070736, -2073585},
        {2097152, -4139511, 4139511, 2044986, -2044986},
        {2097152, -4080862, 4080862, 1994087, -1994087},
        {2109991, -3964251, 3964251, 1894839, -1907678},
        {2206744, -3738102, 3738102, 1688430, -1798022},
        {2094072, -2930264, 2930264, 1386245, -1383165},
        {2128473, -1237580, 1237580, 833875,  -865196 },
        {2647589, -223599,  -410403, 457593,  -374029 },
    }
};

void audio_eq_init(void)
{
    unsigned int val;

    /* Set DAC EQ stage to 10 */
    val = hwp_audProc->aud_proc_dac_cfg2;
    val &= ~(AUD_PROC_EQ_STAGE(0x0F));
    val |= (AUD_PROC_EQ_STAGE(0x0A));
    hwp_audProc->aud_proc_dac_cfg2 = val;

    /* Set ADC EQ stage to 10 */
    val = hwp_audProc->aud_proc_adc_cfg2;
    val &= ~(AUD_PROC_EQ_ADC_STAGE(0x0F));
    val |= (AUD_PROC_EQ_ADC_STAGE(0x0A));
    hwp_audProc->aud_proc_adc_cfg2 = val;
}

void audio_dac_eq_coef_config(int *coef)
{
    GLOBAL_INT_DISABLE();

    hwp_audProc->aud_proc_dac_cfg2 &= ~(AUD_PROC_EQ_CH_EN(0x3));
    hwp_audProc->aud_proc_dac_cfg2 |= AUD_PROC_EQ_CLR;

    //Left Channel
    for (int i = 0; i < EQ_BANDS; i++) {
        for (int j = 0; j < EQ_COEFS_NUM; j++) {
            hwp_audProc->eq_stereo_coef_ram_cfg0 = (AUD_PROC_EQ_STEREO_COEF_WR | AUD_PROC_EQ_STEREO_COEF_ADDR(i * EQ_COEFS_NUM + j) | AUD_PROC_EQ_STEREO_COEF_WDATA(coef[i * EQ_COEFS_NUM + j]));
        }
    }

    //Right Channel
    for (int i = 0; i < EQ_BANDS; i++) {
        for (int j = 0; j < EQ_COEFS_NUM; j++) {
            hwp_audProc->eq_stereo_coef_ram_cfg0 = (AUD_PROC_EQ_STEREO_COEF_WR | AUD_PROC_EQ_STEREO_COEF_ADDR(50 + i * EQ_COEFS_NUM + j) | AUD_PROC_EQ_STEREO_COEF_WDATA(coef[i * EQ_COEFS_NUM + j]));
        }
    }
    hwp_audProc->aud_proc_dac_cfg2 |= (AUD_PROC_EQ_CH_EN(0x3));

    GLOBAL_INT_RESTORE();
}

void audio_dac_eq_off(void)
{
    audio_dac_eq_set(EQ_NONE);
}

void audio_dac_eq_set(EQ_TYPE_T type)
{
    if (type >= EQ_NUM) {
        dbg("ERR: invalid dac eq type %d\n", type);
        return;
    }

#if 0
    hwp_audProc->aud_proc_dac_cfg2 &= ~(AUD_PROC_EQ_CH_EN(0x3));
    hwp_audProc->aud_proc_dac_cfg2 |= AUD_PROC_EQ_CLR;

    if (type != EQ_NONE) {
        GLOBAL_INT_DISABLE();
        //Left Channel
        for (int i = 0; i < EQ_BANDS; i++) {
            for (int j = 0; j < EQ_COEFS_NUM; j++) {
                hwp_audProc->eq_stereo_coef_ram_cfg0 = (AUD_PROC_EQ_STEREO_COEF_WR | AUD_PROC_EQ_STEREO_COEF_ADDR(i * EQ_COEFS_NUM + j) | AUD_PROC_EQ_STEREO_COEF_WDATA(eq_preset[type][i][j]));
            }
        }

        //Right Channel
        for (int i = 0; i < EQ_BANDS; i++) {
            for (int j = 0; j < EQ_COEFS_NUM; j++) {
                hwp_audProc->eq_stereo_coef_ram_cfg0 = (AUD_PROC_EQ_STEREO_COEF_WR | AUD_PROC_EQ_STEREO_COEF_ADDR(50 + i * EQ_COEFS_NUM + j) | AUD_PROC_EQ_STEREO_COEF_WDATA(eq_preset[type][i][j]));
            }
        }
        hwp_audProc->aud_proc_dac_cfg2 |= (AUD_PROC_EQ_CH_EN(0x3));
        GLOBAL_INT_RESTORE();
    }
#else
    if (type != EQ_NONE) {
        audio_dac_eq_coef_config((int *)&eq_preset[type][0][0]);
    } else {
        hwp_audProc->aud_proc_dac_cfg2 &= ~(AUD_PROC_EQ_CH_EN(0x3));
        hwp_audProc->aud_proc_dac_cfg2 |= AUD_PROC_EQ_CLR;
    }
#endif

    dac_eq_type = type;
}

void audio_dac_eq_reset(void)
{
    audio_dac_eq_set(dac_eq_type);
}

void audio_adc_eq_coef_config(int *coef)
{
    GLOBAL_INT_DISABLE();

    hwp_audProc->aud_proc_adc_cfg2 &= ~(AUD_PROC_EQ_ADC_CH_EN(0x3));
    hwp_audProc->aud_proc_adc_cfg2 |= AUD_PROC_EQ_ADC_CLR;

    //Mono Channel
    for (int i = 0; i < EQ_BANDS; i++) {
        for (int j = 0; j < EQ_COEFS_NUM; j++) {
            hwp_audProc->eq_mono_coef_ram_cfg0 = AUD_PROC_EQ_MONO_COEF_WR | AUD_PROC_EQ_MONO_COEF_ADDR(i * EQ_COEFS_NUM + j) | AUD_PROC_EQ_MONO_COEF_WDATA(coef[i * EQ_COEFS_NUM + j]);
        }
    }
    hwp_audProc->aud_proc_adc_cfg2 |= (AUD_PROC_EQ_ADC_CH_EN(adc_eq_ch));

    GLOBAL_INT_RESTORE();
}

void audio_adc_eq_off(void)
{
    audio_adc_eq_set(EQ_NONE);
}

void audio_adc_eq_set(EQ_TYPE_T type)
{
    if (type >= EQ_NUM) {
        dbg("ERR: invalid adc eq type %d\n", type);
        return;
    }


#if 0
    hwp_audProc->aud_proc_adc_cfg2 &= ~(AUD_PROC_EQ_ADC_CH_EN(0x3));
    hwp_audProc->aud_proc_adc_cfg2 |= AUD_PROC_EQ_ADC_CLR;

    if ((type != EQ_NONE) && (adc_eq_ch != EQ_CH_NONE)) {
        GLOBAL_INT_DISABLE();
        //Mono Channel
        for (int i = 0; i < EQ_BANDS; i++) {
            for (int j = 0; j < EQ_COEFS_NUM; j++) {
                hwp_audProc->eq_mono_coef_ram_cfg0 = AUD_PROC_EQ_MONO_COEF_WR | AUD_PROC_EQ_MONO_COEF_ADDR(i * EQ_COEFS_NUM + j) | AUD_PROC_EQ_MONO_COEF_WDATA(eq_preset[type][i][j]);
            }
        }
        hwp_audProc->aud_proc_adc_cfg2 |= (AUD_PROC_EQ_ADC_CH_EN(adc_eq_ch));
        GLOBAL_INT_RESTORE();
    }
#else
    if (type != EQ_NONE) {
        audio_adc_eq_coef_config((int *)&eq_preset[type][0][0]);
    } else {
        hwp_audProc->aud_proc_adc_cfg2 &= ~(AUD_PROC_EQ_ADC_CH_EN(0x3));
        hwp_audProc->aud_proc_adc_cfg2 |= AUD_PROC_EQ_ADC_CLR;
    }
#endif

    adc_eq_type = type;
}

void audio_adc_eq_ch_set(EQ_CH_T ch)
{
    if (ch >= EQ_CH_NUM) {
        dbg("ERR: invalid adc eq ch %d\n", ch);
        return;
    }

    if (ch != adc_eq_ch) {
        adc_eq_ch = ch;
        audio_adc_eq_reset();
    }
}

void audio_adc_eq_reset(void)
{
    audio_adc_eq_set(adc_eq_type);
}

