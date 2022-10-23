#include "plf.h"

#if PLF_CONSOLE
#include "audio_drc.h"
#include "console.h"

int do_drc_on(int argc, char *argv[])
{
    TRACE("%s\n", __func__);

    audio_drc_on();

    TRACE("%s exit\n", __func__);

    return 0;
}

int do_drc_off(int argc, char *argv[])
{
    TRACE("%s\n", __func__);

    audio_drc_off();

    TRACE("%s exit\n", __func__);

    return 0;
}

void audio_drc_cmd_init(void)
{
    console_cmd_add("drcon", " drcon", 1, do_drc_on);
    console_cmd_add("drcoff", " drcoff", 1, do_drc_off);
}

#endif
