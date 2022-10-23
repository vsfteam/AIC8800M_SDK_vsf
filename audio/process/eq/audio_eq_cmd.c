#include "plf.h"

#if PLF_CONSOLE
#include "audio_eq.h"
#include "console.h"

static const char *eq_name[EQ_NUM] = {
    "NONE",
    "POP",
    "JAZZ",
    "ROCK",
    "CLASSIC",
    "BLUES",
    "COUNTRY",
    "DANCE",
    "ACG",
};

static const char *eq_ch_name[EQ_CH_NUM] = {
    "NONE",
    "LEFT",
    "RIGHT",
};

int do_dac_eq_off(int argc, char *argv[])
{
    TRACE("%s\n", __func__);

    audio_dac_eq_off();

    TRACE("%s exit\n", __func__);

    return 0;
}

int do_dac_eq_set(int argc, char *argv[])
{
    uint32_t type = 0;

    TRACE("%s\n", __func__);

    if(argc < 2) {
        return -1;
    }

    type = console_cmd_strtoul(argv[1], NULL, 0);

    if (type >= EQ_NUM) {
        TRACE("ERR: EQ type out of range\n");
        return -1;
    } else {
        TRACE("Set EQ to %s\n", eq_name[type]);
    }

    audio_dac_eq_set(type);

    TRACE("%s exit\n", __func__);

    return 0;
}

int do_adc_eq_off(int argc, char *argv[])
{
    TRACE("%s\n", __func__);

    audio_adc_eq_off();

    TRACE("%s exit\n", __func__);

    return 0;
}

int do_adc_eq_set(int argc, char *argv[])
{
    uint32_t type = 0;

    TRACE("%s\n", __func__);

    if(argc < 2) {
        return -1;
    }

    type = console_cmd_strtoul(argv[1], NULL, 0);

    if (type >= EQ_NUM) {
        TRACE("ERR: EQ type out of range\n");
        return -1;
    } else {
        TRACE("Set EQ to %s\n", eq_name[type]);
    }

    audio_adc_eq_set(type);

    TRACE("%s exit\n", __func__);

    return 0;
}

int do_adc_eq_ch_set(int argc, char *argv[])
{
    uint32_t ch = 0;

    TRACE("%s\n", __func__);

    if(argc < 2) {
        return -1;
    }

    ch = console_cmd_strtoul(argv[1], NULL, 0);

    if (ch >= EQ_CH_NUM) {
        TRACE("ERR: EQ ch out of range\n");
        return -1;
    } else {
        TRACE("Set EQ ch to %s\n", eq_ch_name[ch]);
    }

    audio_adc_eq_ch_set(ch);

    TRACE("%s exit\n", __func__);

    return 0;
}


void audio_eq_cmd_init(void)
{
    console_cmd_add("daceqoff", " daceqoff", 1, do_dac_eq_off);
    console_cmd_add("daceq", " daceq type", 2, do_dac_eq_set);
    console_cmd_add("adceqoff", " adceqoff", 1, do_adc_eq_off);
    console_cmd_add("adceq", " adceq type", 2, do_adc_eq_set);
    console_cmd_add("adceqch", " adceqch ch(0:NONE 1:L 2:R)", 2, do_adc_eq_ch_set);
}

#endif
