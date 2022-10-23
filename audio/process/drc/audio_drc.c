#include <stdint.h>
#include <stdbool.h>
#include "dbg.h"
#include "dbg_assert.h"
#include "audio_drc.h"
#include "aud_proc.h"
#include "ll.h"

#define DRC_CHECK 0

static bool drc_on = false;

void audio_drc_init(void)
{
    audio_drc_default_config();
}

void audio_drc_on(void)
{
    hwp_audProc->aud_drc_cfg0 |= (AUD_PROC_CFG_AUD_DRC_CHNL_EN(0x3) | AUD_PROC_CFG_DRC_EN);
    drc_on = true;
}

void audio_drc_off(void)
{
    hwp_audProc->aud_drc_cfg0 &= ~(AUD_PROC_CFG_AUD_DRC_CHNL_EN(0x3));
    hwp_audProc->aud_drc_cfg0 |= AUD_PROC_CFG_AUD_DRC_CLR;

    for (int i = 16; i <= 81; i++) {
        hwp_audProc->aud_drc_ram_cfg1 =  0x0;
        hwp_audProc->aud_drc_ram_cfg0 =  AUD_PROC_CFG_AUD_DRC_RAM_WR | AUD_PROC_CFG_AUD_DRC_RAM_ADDR(i) | AUD_PROC_CFG_AUD_DRC_RAM_SEL(0x0);
    }

    drc_on = false;
}

void audio_drc_coef_config(int *coef1, int *coef2, short *coef3)
{
    unsigned volatile int i,j;
    #if (DRC_CHECK)
    uint32_t rdata;
    #endif

    for(i=0;i<4;i++){
        for(j=0;j<4;j++)
        {
            hwp_audProc->aud_drc_ram_cfg1 =  coef1[i * 4 + j];
            hwp_audProc->aud_drc_ram_cfg0 =  AUD_PROC_CFG_AUD_DRC_RAM_WR | AUD_PROC_CFG_AUD_DRC_RAM_ADDR(i*4+j) | AUD_PROC_CFG_AUD_DRC_RAM_SEL(0x0);

            #if (DRC_CHECK)
            ///read check
            hwp_audProc->aud_drc_ram_cfg0 =  AUD_PROC_CFG_AUD_DRC_RAM_RD | AUD_PROC_CFG_AUD_DRC_RAM_ADDR(i*4+j) | AUD_PROC_CFG_AUD_DRC_RAM_SEL(0x0);
            rdata = hwp_audProc->aud_drc_ram_cfg2;
            rdata = hwp_audProc->aud_drc_ram_cfg2;
            if(rdata != coef1[i * 4 + j])
                   dbg("drc crossover coeff configure failed: wr coeff=%x, rd coeff=%x\n",coef1[i * 4 + j],rdata);
            #endif
        }
    }

    for (i=16;i<=81;i++)
    {
            hwp_audProc->aud_drc_ram_cfg1 =  0x0;
            hwp_audProc->aud_drc_ram_cfg0 =  AUD_PROC_CFG_AUD_DRC_RAM_WR | AUD_PROC_CFG_AUD_DRC_RAM_ADDR(i) | AUD_PROC_CFG_AUD_DRC_RAM_SEL(0x0);
    }

    for(i=0;i<4;i++){
        for(j=0;j<16;j++)
        {
            hwp_audProc->aud_drc_ram_cfg1 =  (coef2[i * 16 + j])&0xffffff;
            hwp_audProc->aud_drc_ram_cfg0 =  AUD_PROC_CFG_AUD_DRC_RAM_WR | AUD_PROC_CFG_AUD_DRC_RAM_ADDR(i*16+j) | AUD_PROC_CFG_AUD_DRC_RAM_SEL(0x2);

            #if (DRC_CHECK)
            ///read check
            hwp_audProc->aud_drc_ram_cfg0 =  AUD_PROC_CFG_AUD_DRC_RAM_RD | AUD_PROC_CFG_AUD_DRC_RAM_ADDR(i*16+j) | AUD_PROC_CFG_AUD_DRC_RAM_SEL(0x2);
            rdata = hwp_audProc->aud_drc_ram_cfg2;
            rdata = hwp_audProc->aud_drc_ram_cfg2;
            if(rdata != (coef2[i * 16 + j]&0xffffff))
                   dbg("drc proc coeff configure failed: wr coeff=%x, rd coeff=%x\n",coef2[i * 16 + j]&0xffffff,rdata);
            #endif
        }
    }

    for(i=0;i<=105;i++){
        hwp_audProc->aud_drc_ram_cfg1 =  (coef3[i])&0xfff;
        hwp_audProc->aud_drc_ram_cfg0 =  AUD_PROC_CFG_AUD_DRC_RAM_WR | AUD_PROC_CFG_AUD_DRC_RAM_ADDR(i) | AUD_PROC_CFG_AUD_DRC_RAM_SEL(0x1);

        #if (DRC_CHECK)
        ///read check
        hwp_audProc->aud_drc_ram_cfg0 =  AUD_PROC_CFG_AUD_DRC_RAM_RD | AUD_PROC_CFG_AUD_DRC_RAM_ADDR(i) | AUD_PROC_CFG_AUD_DRC_RAM_SEL(0x1);
        rdata = hwp_audProc->aud_drc_ram_cfg2;
        rdata = hwp_audProc->aud_drc_ram_cfg2;
        if(rdata != (coef3[i]&0xfff))
               dbg("drc proc coeff configure failed: wr coeff=%x, rd coeff=%x\n",coef3[i][j],rdata);
        #endif
    }

    hwp_audProc->aud_drc_cfg0 = AUD_PROC_CFG_DRC_BAND3_MODE(0) | AUD_PROC_CFG_DRC_BAND3_EN | AUD_PROC_CFG_DRC_STAGE_CNT(2) | AUD_PROC_CFG_DRC_BAND2_MODE(0) | AUD_PROC_CFG_DRC_BAND1_MODE(0) | AUD_PROC_CFG_DRC_BAND0_MODE(0);
}

void audio_drc_default_config(void)
{
    ///==================aud drc crossover filter initial ===================
    const int crossover_filter_coeff[4][4] = {
        {7551  ,428079,-181036,1024},//ll1_b0,ll1_a11,ll1_a21,ll1_shift_coef;
        {435630,428079,-181036,1024},//lh1_b0,lh1_a11,lh1_a21,lh1_shift_coef;
        {88    ,514583,-252616,1024},//ll2_b0,ll2_a11,ll2_a21,ll2_shift_coef;
        {514672,514583,-252616,1024} //lh2_b0,lh2_a11,lh2_a21,lh2_shift_coef;
    };

    ///====================== aud drc coeff initial =================================///
    //drc ram coeff
    //0 Thres_compr S9.4
    //1 Thres_expnd S9.4
    //2 Thres_gate  S9.4
    //3 Out_limit   S9.8
    //4 Out_gate    S9.4
    //5 Ratio_compr U0.8
    //6 Ratio_expnd U6.4
    //7 Knee_compr  U6.4
    //8 MakeupGain  S16.8
    //9 AlphaA      U0.15
    //10 AlphaR     U0.15
    //11 Thres_compr + W/2  //S9.4
    //12 Thres_compr - W/2  //S9.4
    //13 1/(2*Knee_compr)*(Ratio_compr - 1) //U0.15
    //14 xDb    yDb     tmp1
    //15 Gs
    const int drc_proc_coeff[4][16] = {
        {-20<<4,-64<<4,-108<<4,-6<<8,-128<<4,240,23,4<<4,5<<8,30, 7,-18<<4,-22<<4,256,0,0},
        {-20<<4,-64<<4,-108<<4,-6<<8,-128<<4,240,23,4<<4,3<<8,75,15,-18<<4,-22<<4,256,0,0},
        {-20<<4,-64<<4,-108<<4,-6<<8,-128<<4,240,23,4<<4,3<<8,30, 7,-18<<4,-22<<4,256,0,0},
        {-20<<4,-64<<4,-108<<4,-6<<8,-128<<4,240,23,4<<4,3<<8,30, 7,-18<<4,-22<<4,256,0,0}
    };

    ///===================== drc db2linear =============================================///
    const short drc_db2linear_coeff[106] = {
        26,21,16,11,5,0,-5,-11,-16,-21,
        2048,2063,2078,2093,2108,2123,2138,2154,
        2169,2185,2201,2217,2233,2249,2265,2281,
        2298,2314,2331,2348,2365,2382,2399,2417,
        2434,2452,2469,2487,2505,2523,2541,2560,
        2578,2597,2616,2635,2654,2673,2692,2711,
        2731,2751,2771,2791,2811,2831,2852,2872,
        2893,2914,2935,2956,2977,2999,3021,3042,
        3064,3086,3109,3131,3154,3177,3199,3223,
        3246,3269,3293,3317,3341,3365,3389,3414,
        3438,3463,3488,3513,3539,3564,3590,3616,
        3642,3668,3695,3721,3748,3775,3803,3830,
        3858,3886,3914,3942,3970,3999,4028,4057
    };

    audio_drc_coef_config((int *)&crossover_filter_coeff[0][0], (int *)&drc_proc_coeff[0][0], (short *)&drc_db2linear_coeff[0]);
}

#if 0
void audio_drc_default_config(void)
{

    ///==================aud drc crossover filter initial ===================
    const int crossover_filter_coeff[4][4] = {
        {7551  ,428079,-181036,1024},//ll1_b0,ll1_a11,ll1_a21,ll1_shift_coef;
        {435630,428079,-181036,1024},//lh1_b0,lh1_a11,lh1_a21,lh1_shift_coef;
        {88    ,514583,-252616,1024},//ll2_b0,ll2_a11,ll2_a21,ll2_shift_coef;
        {514672,514583,-252616,1024} //lh2_b0,lh2_a11,lh2_a21,lh2_shift_coef;
    };

    unsigned volatile int i,j;
    #if (DRC_CHECK)
    uint32_t rdata;
    #endif

    for(i=0;i<4;i++){
        for(j=0;j<4;j++)
        {
            hwp_audProc->aud_drc_ram_cfg1 =  crossover_filter_coeff[i][j];
            hwp_audProc->aud_drc_ram_cfg0 =  AUD_PROC_CFG_AUD_DRC_RAM_WR | AUD_PROC_CFG_AUD_DRC_RAM_ADDR(i*4+j) | AUD_PROC_CFG_AUD_DRC_RAM_SEL(0x0);

            #if (DRC_CHECK)
            ///read check
            hwp_audProc->aud_drc_ram_cfg0 =  AUD_PROC_CFG_AUD_DRC_RAM_RD | AUD_PROC_CFG_AUD_DRC_RAM_ADDR(i*4+j) | AUD_PROC_CFG_AUD_DRC_RAM_SEL(0x0);
            rdata = hwp_audProc->aud_drc_ram_cfg2;
            rdata = hwp_audProc->aud_drc_ram_cfg2;
            if(rdata != crossover_filter_coeff[i][j])
                   dbg("drc crossover coeff configure failed: wr coeff=%x, rd coeff=%x\n",crossover_filter_coeff[i][j],rdata);
            #endif
        }
    }

    for (i=16;i<=81;i++)
    {
            hwp_audProc->aud_drc_ram_cfg1 =  0x0;
            hwp_audProc->aud_drc_ram_cfg0 =  AUD_PROC_CFG_AUD_DRC_RAM_WR | AUD_PROC_CFG_AUD_DRC_RAM_ADDR(i) | AUD_PROC_CFG_AUD_DRC_RAM_SEL(0x0);
    }

    ///====================== aud drc coeff initial =================================///
    //drc ram coeff
    //0 Thres_compr S9.4
    //1 Thres_expnd S9.4
    //2 Thres_gate  S9.4
    //3 Out_limit   S9.8
    //4 Out_gate    S9.4
    //5 Ratio_compr U0.8
    //6 Ratio_expnd U6.4
    //7 Knee_compr  U6.4
    //8 MakeupGain  S16.8
    //9 AlphaA      U0.15
    //10 AlphaR     U0.15
    //11 Thres_compr + W/2  //S9.4
    //12 Thres_compr - W/2  //S9.4
    //13 1/(2*Knee_compr)*(Ratio_compr - 1) //U0.15
    //14 xDb    yDb     tmp1
    //15 Gs
    const int drc_proc_coeff[4][16] = {
        {-20<<4,-64<<4,-108<<4,-6<<8,-128<<4,240,23,4<<4,5<<8,30, 7,-18<<4,-22<<4,256,0,0},
        {-20<<4,-64<<4,-108<<4,-6<<8,-128<<4,240,23,4<<4,3<<8,75,15,-18<<4,-22<<4,256,0,0},
        {-20<<4,-64<<4,-108<<4,-6<<8,-128<<4,240,23,4<<4,3<<8,30, 7,-18<<4,-22<<4,256,0,0},
        {-20<<4,-64<<4,-108<<4,-6<<8,-128<<4,240,23,4<<4,3<<8,30, 7,-18<<4,-22<<4,256,0,0}
    };
    for(i=0;i<4;i++){
        for(j=0;j<16;j++)
        {
            hwp_audProc->aud_drc_ram_cfg1 =  (drc_proc_coeff[i][j])&0xffffff;
            hwp_audProc->aud_drc_ram_cfg0 =  AUD_PROC_CFG_AUD_DRC_RAM_WR | AUD_PROC_CFG_AUD_DRC_RAM_ADDR(i*16+j) | AUD_PROC_CFG_AUD_DRC_RAM_SEL(0x2);

            #if (DRC_CHECK)
            ///read check
            hwp_audProc->aud_drc_ram_cfg0 =  AUD_PROC_CFG_AUD_DRC_RAM_RD | AUD_PROC_CFG_AUD_DRC_RAM_ADDR(i*16+j) | AUD_PROC_CFG_AUD_DRC_RAM_SEL(0x2);
            rdata = hwp_audProc->aud_drc_ram_cfg2;
            rdata = hwp_audProc->aud_drc_ram_cfg2;
            if(rdata != (drc_proc_coeff[i][j]&0xffffff))
                   dbg("drc proc coeff configure failed: wr coeff=%x, rd coeff=%x\n",drc_proc_coeff[i][j]&0xffffff,rdata);
            #endif
        }
    }

    ///===================== drc db2linear =============================================///
    const short drc_db2linear_coeff[106] = {
        26,21,16,11,5,0,-5,-11,-16,-21,
        2048,2063,2078,2093,2108,2123,2138,2154,
        2169,2185,2201,2217,2233,2249,2265,2281,
        2298,2314,2331,2348,2365,2382,2399,2417,
        2434,2452,2469,2487,2505,2523,2541,2560,
        2578,2597,2616,2635,2654,2673,2692,2711,
        2731,2751,2771,2791,2811,2831,2852,2872,
        2893,2914,2935,2956,2977,2999,3021,3042,
        3064,3086,3109,3131,3154,3177,3199,3223,
        3246,3269,3293,3317,3341,3365,3389,3414,
        3438,3463,3488,3513,3539,3564,3590,3616,
        3642,3668,3695,3721,3748,3775,3803,3830,
        3858,3886,3914,3942,3970,3999,4028,4057
    };

    for(i=0;i<=105;i++){
            hwp_audProc->aud_drc_ram_cfg1 =  (drc_db2linear_coeff[i])&0xfff;
            hwp_audProc->aud_drc_ram_cfg0 =  AUD_PROC_CFG_AUD_DRC_RAM_WR | AUD_PROC_CFG_AUD_DRC_RAM_ADDR(i) | AUD_PROC_CFG_AUD_DRC_RAM_SEL(0x1);

            #if (DRC_CHECK)
            ///read check
            hwp_audProc->aud_drc_ram_cfg0 =  AUD_PROC_CFG_AUD_DRC_RAM_RD | AUD_PROC_CFG_AUD_DRC_RAM_ADDR(i) | AUD_PROC_CFG_AUD_DRC_RAM_SEL(0x1);
            rdata = hwp_audProc->aud_drc_ram_cfg2;
            rdata = hwp_audProc->aud_drc_ram_cfg2;
            if(rdata != (drc_db2linear_coeff[i]&0xfff))
                   dbg("drc proc coeff configure failed: wr coeff=%x, rd coeff=%x\n",drc_proc_coeff[i][j],rdata);
            #endif
    }

    hwp_audProc->aud_drc_cfg0 = AUD_PROC_CFG_DRC_BAND3_MODE(0) | AUD_PROC_CFG_DRC_BAND3_EN | AUD_PROC_CFG_DRC_STAGE_CNT(2) | AUD_PROC_CFG_DRC_BAND2_MODE(0) | AUD_PROC_CFG_DRC_BAND1_MODE(0) | AUD_PROC_CFG_DRC_BAND0_MODE(0);
}
#endif

#if 0
///drc proc
void drc_data_proc(bool drc_en)
{

    ///==================aud drc crossover filter initial ===================
    const int crossover_filter_coeff[4][4] = {
        {11335, 404520,-165047,1024},//ll1_b0,ll1_a11,ll1_a21,ll1_shift_coef;
        {415855,404520,-165047,1024},//lh1_b0,lh1_a11,lh1_a21,lh1_shift_coef;
        {346,   504885,-243434,1024},//ll2_b0,ll2_a11,ll2_a21,ll2_shift_coef;
        {505232,504885,-243434,1024} //lh2_b0,lh2_a11,lh2_a21,lh2_shift_coef;
    };

    unsigned volatile int i,j,rdata;

    for(i=0;i<4;i++){
        for(j=0;j<4;j++)
        {
            hwp_audProc->aud_drc_ram_cfg1 =  crossover_filter_coeff[i][j];
            hwp_audProc->aud_drc_ram_cfg0 =  AUD_PROC_CFG_AUD_DRC_RAM_WR | AUD_PROC_CFG_AUD_DRC_RAM_ADDR(i*4+j) | AUD_PROC_CFG_AUD_DRC_RAM_SEL(0x0);

            #if 0
            ///read check
            hwp_audProc->aud_drc_ram_cfg0 =  AUD_PROC_CFG_AUD_DRC_RAM_RD | AUD_PROC_CFG_AUD_DRC_RAM_ADDR(i*4+j) | AUD_PROC_CFG_AUD_DRC_RAM_SEL(0x0);
            rdata = hwp_audProc->aud_drc_ram_cfg2;
            rdata = hwp_audProc->aud_drc_ram_cfg2;
            if(rdata != crossover_filter_coeff[i][j])
                   dbg("drc crossover coeff configure failed: wr coeff=%x, rd coeff=%x\n",crossover_filter_coeff[i][j],rdata);
            #endif
        }
    }

    for (i=16;i<=81;i++)
    {
            hwp_audProc->aud_drc_ram_cfg1 =  0x0;
            hwp_audProc->aud_drc_ram_cfg0 =  AUD_PROC_CFG_AUD_DRC_RAM_WR | AUD_PROC_CFG_AUD_DRC_RAM_ADDR(i) | AUD_PROC_CFG_AUD_DRC_RAM_SEL(0x0);
    }

    ///====================== aud drc coeff initial =================================///
    //drc ram coeff
    //0 Thres_compr S9.4
    //1 Thres_expnd S9.4
    //2 Thres_gate  S9.4
    //3 Out_limit   S9.8
    //4 Out_gate    S9.4
    //5 Ratio_compr U0.8
    //6 Ratio_expnd U6.4
    //7 Knee_compr  U6.4
    //8 MakeupGain  S16.8
    //9 AlphaA      U0.15
    //10 AlphaR     U0.15
    //11 Thres_compr + W/2  //S9.4
    //12 Thres_compr - W/2  //S9.4
    //13 1/(2*Knee_compr)*(Ratio_compr - 1) //U0.15
    //14 xDb    yDb     tmp1
    //15 Gs
    const int drc_proc_coeff[4][16] = {
        {-10<<4,-50<<4,-80<<4,-3<<8,-128<<4,64,2<<4,10<<4,2<<8,30, 7,-5<<4,-15<<4,1228,0,0},
        {-10<<4,-50<<4,-80<<4,-3<<8,-128<<4,64,2<<4,10<<4,2<<8,75,15,-5<<4,-15<<4,1228,0,0},
        {-10<<4,-50<<4,-80<<4,-3<<8,-128<<4,64,2<<4,10<<4,2<<8,30, 7,-5<<4,-15<<4,1228,0,0},
        {-10<<4,-50<<4,-80<<4,30<<8,-128<<4,64,2<<4,10<<4,0<<8,30, 7,-5<<4,-15<<4,1228,0,0}
    };
    for(i=0;i<4;i++){
        for(j=0;j<16;j++)
        {
            hwp_audProc->aud_drc_ram_cfg1 =  (drc_proc_coeff[i][j])&0xffffff;
            hwp_audProc->aud_drc_ram_cfg0 =  AUD_PROC_CFG_AUD_DRC_RAM_WR | AUD_PROC_CFG_AUD_DRC_RAM_ADDR(i*16+j) | AUD_PROC_CFG_AUD_DRC_RAM_SEL(0x2);

            #if 0
            ///read check
            hwp_audProc->aud_drc_ram_cfg0 =  AUD_PROC_CFG_AUD_DRC_RAM_RD | AUD_PROC_CFG_AUD_DRC_RAM_ADDR(i*16+j) | AUD_PROC_CFG_AUD_DRC_RAM_SEL(0x2);
            rdata = hwp_audProc->aud_drc_ram_cfg2;
            rdata = hwp_audProc->aud_drc_ram_cfg2;
            if(rdata != (drc_proc_coeff[i][j]&0xffffff))
                   dbg("drc proc coeff configure failed: wr coeff=%x, rd coeff=%x\n",drc_proc_coeff[i][j]&0xffffff,rdata);
            #endif
        }
    }

    ///===================== drc db2linear =============================================///
    const short drc_db2linear_coeff[106] = {
        26,21,16,11,5,0,-5,-11,-16,-21,
        2048,2063,2078,2093,2108,2123,2138,2154,
        2169,2185,2201,2217,2233,2249,2265,2281,
        2298,2314,2331,2348,2365,2382,2399,2417,
        2434,2452,2469,2487,2505,2523,2541,2560,
        2578,2597,2616,2635,2654,2673,2692,2711,
        2731,2751,2771,2791,2811,2831,2852,2872,
        2893,2914,2935,2956,2977,2999,3021,3042,
        3064,3086,3109,3131,3154,3177,3199,3223,
        3246,3269,3293,3317,3341,3365,3389,3414,
        3438,3463,3488,3513,3539,3564,3590,3616,
        3642,3668,3695,3721,3748,3775,3803,3830,
        3858,3886,3914,3942,3970,3999,4028,4057
    };

    for(i=0;i<=105;i++){
            hwp_audProc->aud_drc_ram_cfg1 =  (drc_db2linear_coeff[i])&0xfff;
            hwp_audProc->aud_drc_ram_cfg0 =  AUD_PROC_CFG_AUD_DRC_RAM_WR | AUD_PROC_CFG_AUD_DRC_RAM_ADDR(i) | AUD_PROC_CFG_AUD_DRC_RAM_SEL(0x1);

            #if 0
            ///read check
            hwp_audProc->aud_drc_ram_cfg0 =  AUD_PROC_CFG_AUD_DRC_RAM_RD | AUD_PROC_CFG_AUD_DRC_RAM_ADDR(i) | AUD_PROC_CFG_AUD_DRC_RAM_SEL(0x1);
            rdata = hwp_audProc->aud_drc_ram_cfg2;
            rdata = hwp_audProc->aud_drc_ram_cfg2;
            if(rdata != (drc_db2linear_coeff[i]&0xfff))
                   dbg("drc proc coeff configure failed: wr coeff=%x, rd coeff=%x\n",drc_proc_coeff[i][j],rdata);
            #endif
    }

    hwp_audProc->aud_drc_cfg0 = (drc_en ? AUD_PROC_CFG_AUD_DRC_CHNL_EN(0x3) : 0) | AUD_PROC_CFG_DRC_BAND3_MODE(0) | (drc_en ?AUD_PROC_CFG_DRC_BAND3_EN : 0)
    | AUD_PROC_CFG_DRC_STAGE_CNT(2) | AUD_PROC_CFG_DRC_BAND2_MODE(0) | AUD_PROC_CFG_DRC_BAND1_MODE(0) | (drc_en ? AUD_PROC_CFG_DRC_EN : 0);
}
#endif
