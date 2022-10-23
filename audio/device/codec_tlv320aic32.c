#include <stdlib.h>
#include <stdint.h>
#include "codec_tlv320aic32.h"
#include "chip.h"
#include "reg_i2cm.h"
#include "dbg.h"
#include "dbg_assert.h"
#include "pinname.h"
#include "reg_iomux.h"
#include "gpio_api.h"
#include "plf.h"
#include "sysctrl_api.h"
#include "audio_config.h"

#define CODEC_DEBUG 0

#define TLV320AIC32_ADDR    0x18

#define I2C_CLK 200000

#define FSREF_DIV_NB    11

// convert div from float to uint8_t by multiply 10
const uint8_t fsref_div_tbl[FSREF_DIV_NB] = {
    10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60
};

static tlv320aic32_cfg_t last_cfg;

#if 0
const unsigned char codec_initial_data_buf[] = {
/*Register 0 = */0x0
/*Register 1 = */,0x80    //reset
/*Register 2 = */,0x00    //ADC Fs=Fsref/1, DAC Fs=Fsref/1
/*Register 3 = */,0x11    //PLL Disable, Q=2, P=1
/*Register 4 = */,0x04    //J=1
/*Register 5 = */,0x00    //D[13:6]=0
/*Register 6 = */,0x00    //D[5:0]=0
/*Register 7 = */,0x0A    //Fsref=48KHz, Left DAC datapath plays left channel input data, Right plays right
///*Register 8 = */,0xD0    //BCK & LRCK master mode(output), BCK & LRCK continue output when codec powered down
/*Register 8 = */,0x00    //BCK & LRCK slave mode(input), BCK & LRCK continue output when codec powered down
/*Register 9 = */,0x20    // I2S mode, 24 bit mode
///*Register 9 = */,0xE0    // left-justified mode, 24 bit mode
///*Register 9 = */,0x00    // I2S mode, 16 bits
///*Register 9 = */,0xC0    // left-justified mode, 16 bits
/*Register 10 = */,0x00   //Audio Serial Data Word Offset
/*Register 11 = */,0x01   //R=1
/*Register 12 = */,0x00   //ADC highpass filter disable, DAC digital effects filter disable, DAC de-emphasis filter disable
/*Register 13 = */,0x00   //Reserved, write only 0x00
///*Register 14 = */,0x00
/*Register 14 = */,0x08   //Headset is set as stereo pseudo-differential output

///*Register 15 = */,0x7F   //ADCL PGA not muted, gain 59.5dB
///*Register 16 = */,0x7F   //ADCR PGA not muted, gain 59.5dB
/*Register 15 = */,0x00   //ADCL PGA not muted, gain 0dB
/*Register 16 = */,0x00   //ADCR PGA not muted, gain 0dB

///*Register 17 = */,0x0F   //MIC3L to ADCL PGA gain 0dB, MIC3R not connected to ADCL PGA
/*Register 17 = */,0xFF   //MIC3L not connected to ADCL PGA, MIC3R not connected to ADCL PGA
///*Register 18 = */,0xF0   //MIC3R to ADCR PGA gain 0dB, MIC3L not connected to ADCR PGA
/*Register 18 = */,0xFF   //MIC3R not connected to ADCL PGA, MIC3L not connected to ADCR PGA

/*Register 19 = */,0x04   //LINE1L to ADCL PGA gain 0dB, ADCL is powered up
///*Register 19 = */,0x7C   //LINE1L not connected to ADCL PGA, ADCL is powered up
/*Register 20 = */,0x78   //LINE2L not connected to ADCL PGA
//*Register 20 = */,0x00   //LINE2L to ADCL PGA gain 0dB

/*Register 21 = */,0x78   //LINE1R not connected to ADCL PGA

/*Register 22 = */,0x04   //LINE1R to ADCR PGA gain 0dB, ADCR is powered up
///*Register 22 = */,0x7C   //LINE1R not connected to ADCR PGA, ADCR is powered up
/*Register 23 = */,0x78   //LINE2R not connected to ADCR PGA
///*Register 23 = */,0x00   //LINE2R to ADCR PGA gain 0dB

/*Register 24 = */,0x78   //LINE1L not connected to ADCR PGA

/*Register 25 = */,0x40   //MICBIAS output is powered to 2.0V
///*Register 25 = */,0x80   //MICBIAS output is powered to 2.5V

///*Register 26 = */,0x00   //Left AGC Disable
/*Register 26 = */,0x80   //Left AGC Enable

/*Register 27 = */,0x40   //Left AGC max gain 32dB
/*Register 28 = */,0x00   //Left AGC Noise Gate Hysteresis disable, Noise/Silence Detection disable, Clip Stepping disable

///*Register 29 = */,0x00   //Right AGC Disable
/*Register 29 = */,0x80   //Right AGC Enable

/*Register 30 = */,0x40   //Right AGC max gain 32dB
/*Register 31 = */,0x00   //Right AGC Noise Gate Hysteresis disable, Noise/Silence Detection disable, Clip Stepping disable
/*Register 32 = */,0x00   //Left Channel Gain Applied by AGC Algorithm 0dB
/*Register 33 = */,0x00   //Right Channel Gain Applied by AGC Algorithm 0dB
/*Register 34 = */,0x00   //Left AGC Noise Detection Debounce 0ms, Signal Detection Debounce 0ms
/*Register 35 = */,0x00   //Right AGC Noise Detection Debounce 0ms, Signal Detection Debounce 0ms
/*Register 36 = */,0x00   //ADC Flag register, DO NOT WRITE

///*Register 37 = */,0xC0   //DACL power up, DACR power up, HPLCOM configured as differential of HPLOUT
///*Register 38 = */,0x00   //HPRCOM configured as differential of HPROUT
/*Register 37 = */,0xD0   //DACL power up, DACR power up, HPLCOM configured as constant VCM output
/*Register 38 = */,0x08   //HPRCOM configured as constant VCM output

/*Register 39 = */,0x00   //Reserved, DO NOT WRITE
/*Register 40 = */,0x00   //Output common-mode Voltage=1.35V, LINE2L bypass disable, LINE2R bypass disable
/*Register 41 = */,0x00   //DACL output selects DAC_L1 path, DACR output selects DAC_R1 path, Left and Right DAC channel volume independent
/*Register 42 = */,0x6C   //Output Driver power-on time 100ms, ramp-up step time 4ms
/*Register 43 = */,0x00   //DACL not muted, volume gain 0dB
/*Register 44 = */,0x00   //DACR not muted, volume gain 0dB
/*Register 45 = */,0x00   //LINE2L not routed to HPLOUT
/*Register 46 = */,0x00   //PGA_L not routed to HPLOUT

///*Register 47 = */,0x00   //DAC_L1 not routed to HPLOUT
/*Register 47 = */,0x80   //DAC_L1 routed to HPLOUT, analog volume 0dB

/*Register 48 = */,0x00   //LINE2R not routed to HPLOUT
/*Register 49 = */,0x00   //PGA_R not routed to HPLOUT
/*Register 50 = */,0x00   //DAC_R1 not routed to HPLOUT

///*Register 51 = */,0x06   //HPLOUT output level 0dB, HPLOUT muted, tri-stated with powered down, not fully powered up
/*Register 51 = */,0x0F   //HPLOUT output level 0dB, HPLOUT not muted, tri-stated with powered down, fully powered up

/*Register 52 = */,0x00   //LINE2L not routed to HPLCOM
/*Register 53 = */,0x00   //PGA_L not routed to HPLCOM
/*Register 54 = */,0x00   //DAC_L1 not routed to HPLCOM
/*Register 55 = */,0x00   //LINE2R not routed to HPLCOM
/*Register 56 = */,0x00   //PGA_R not routed to HPLCOM
/*Register 57 = */,0x00   //DAC_R1 not routed to HPLCOM

///*Register 58 = */,0x0F   //HPLCOM output level 0dB, HPLCOM not muted, tri-stated with powered down, fully powered up
/*Register 58 = */,0x06   //HPLCOM output level 0dB, HPLCOM muted, tri-stated with powered down, fully powered up

/*Register 59 = */,0x00   //LINE2L not routed to HPROUT
/*Register 60 = */,0x00   //PGA_L not routed to HPROUT
/*Register 61 = */,0x00   //DAC_L1 not routed to HPROUT
/*Register 62 = */,0x00   //LINE2R not routed to HPROUT
/*Register 63 = */,0x00   //PGA_R not routed to HPROUT

///*Register 64 = */,0x00   //DAC_R1 not routed to HPROUT
/*Register 64 = */,0x80   //DAC_R1 routed to HPROUT, analog volume 0dB

///*Register 65 = */,0x00   //HPROUT output level 0dB, HPLOUT muted, common-mode with powered down, not fully powered up
/*Register 65 = */,0x0F   //HPROUT output level 0dB, HPLOUT not muted, tri-stated with powered down, fully powered up

/*Register 66 = */,0x00   //LINE2L not routed to HPRCOM
/*Register 67 = */,0x00   //PGA_L not routed to HPRCOM
/*Register 68 = */,0x00   //DAC_L1 not routed to HPRCOM
/*Register 69 = */,0x00   //LINE2R not routed to HPRCOM
/*Register 70 = */,0x00   //PGA_R not routed to HPRCOM
/*Register 71 = */,0x00   //DAC_R1 not routed to HPRCOM
/*Register 72 = */,0x06   ///HPRCOM output level 0dB, HPRCOM muted, tri-stated with powered down, not fully powered up
/*Register 73 = */,0x00   //Reserved, write only 0x00
/*Register 74 = */,0x00   //Reserved, write only 0x00
/*Register 75 = */,0x00   //Reserved, write only 0x00
/*Register 76 = */,0x00   //Reserved, write only 0x00
/*Register 77 = */,0x00   //Reserved, write only 0x00
/*Register 78 = */,0x00   //Reserved, write only 0x00
/*Register 79 = */,0x02   //Reserved, write only 0x02

/*Register 80 = */,0x00   //LINE2L not routed to LEFT_LOP/M
///*Register 80 = */,0x80   //LINE2L routed to LEFT_LOP/M, analog volume 0dB

/*Register 81 = */,0x00   //PGA_L not routed to LEFT_LOP/M

/*Register 82 = */,0x80   //DAC_L1 routed to LEFT_LOP/M, analog volume 0dB
///*Register 82 = */,0x00   //DAC_L1 not routed to LEFT_LOP/M

/*Register 83 = */,0x00   //LINE2R not routed to LEFT_LOP/M
/*Register 84 = */,0x00   //PGA_R not routed to LEFT_LOP/M
/*Register 85 = */,0x00   //DAC_R1 not routed to LEFT_LOP/M
/*Register 86 = */,0x0B   //LEFT_LOP/M output level 0dB, LEFT_LOP/M not muted, fully powered up
/*Register 87 = */,0x00   //LINE2L not routed to RIGHT_LOP/M
/*Register 88 = */,0x00   //PGA_L not routed to RIGHT_LOP/M
/*Register 89 = */,0x00   //DAC_L1 not routed to RIGHT_LOP/M

/*Register 90 = */,0x00   //LINE2R not routed to RIGHT_LOP/M
///*Register 90 = */,0x80   //LINE2R routed to RIGHT_LOP/M, analog volume 0dB

/*Register 91 = */,0x00   //PGA_R not routed to RIGHT_LOP/M

/*Register 92 = */,0x80   //DAC_R1 routed to RIGHT_LOP/M, analog volume 0dB
///*Register 92 = */,0x00   //DAC_R1 not routed to RIGHT_LOP/M

/*Register 93 = */,0x0B   //RIGHT_LOP/M output level 0dB, RIGHT_LOP/M not muted, fully powered up

/*Register 94 = */,0x00   //Module Power Status
/*Register 95 = */,0x00   //Output Driver Short Circuit Detection Status
/*Register 96 = */,0x00   //Sticky Interrupt Flags
/*Register 97 = */,0x00   //Real-time Interrupt Flags
/*Register 98 = */,0x00   //Reserved, write only 0x00
/*Register 99 = */,0x00   //Reserved, write only 0x00
/*Register 100 = */,0x00  //Reserved, write only 0x00
/*Register 101 = */,0x01  //CODEC_CLKIN uses CLKDIV_OUT
/*Register 102 = */,0x02  //CLKDIV_IN uses MCLK, PLLCLK_IN uses MCLK

/* Register 103 ~ 127, Reserved, DO NOT WRITE */
/*Register 103 = */,0x00
/*Register 104 = */,0x00
/*Register 105 = */,0x00
/*Register 106 = */,0x00
/*Register 107 = */,0x00
/*Register 108 = */,0x00
/*Register 109 = */,0x00
/*Register 110 = */,0x00
/*Register 111 = */,0x00
/*Register 112 = */,0x00
/*Register 113 = */,0x00
/*Register 114 = */,0x00
/*Register 115 = */,0x00
/*Register 116 = */,0x00
/*Register 117 = */,0x00
/*Register 118 = */,0x00
/*Register 119 = */,0x00
/*Register 120 = */,0x00
/*Register 121 = */,0x00
/*Register 122 = */,0x00
/*Register 123 = */,0x00
/*Register 124 = */,0x00
/*Register 125 = */,0x00
/*Register 126 = */,0x00
/*Register 127 = */,0x00
};
#endif


/*
 * This table is used for codec initialization by tlv320aic32_init
 * After this, the codec is configured in follwing mode.
 *
 * I2S Mode, 24bit (the output of audio_proc is 24bit)
 * Fsref 48K, Fsref divider 1, dual rate mode is disabled
 * PLL is used, MCLK comes from external device and is 12.288M
 * MCLK--->PLL_CLKIN---> J.D * R / P ---> 1 / 8 --->PLLDIV_OUT--->CODEC_CLK = 256 * Fsref
 * J = 8, P = 1, R = 1, D = 0
 * MICBIAS 2.0V
 * DAC_L1--->HPLOUT    DAC_R1--->HPROUT
 * DAC_L1--->LEFT_LOP/M    RAC_R1--->RIGHT_LOP/M
 * LINE1L--->ADCL    LINE1R--->ADCR
 *
 */
const unsigned char codec_initial_data_buf[][2] =
{
    //{0,0x00},    //Page Select
    //{1,0x80},    //reset
    //{2,0x00},    //ADC Fs=Fsref/1, DAC Fs=Fsref/1 (configure in tlv320aic32_config)
    //{3,0x10},    //PLL Disable, Q=2, P=8(DFT)
    {3,0x91},    //PLL Enable, Q=2, P=1
    //{4,0x04},    //J=1(DFT)
    {4,0x20},    //J=8
    //{5,0x00},    //D[13:6]=0(DFT)
    //{6,0x00},    //D[5:0]=0(DFT)
    {7,0x0A},    //Fsref=48KHz, Single rate mode, Left DAC datapath plays left channel input data, Right plays right(configure in tlv320aic32_config)
    //{8,0xD0},    //BCK & LRCK master mode(output), BCK & LRCK continue output when codec powered down(configure in tlv320aic32_config)
    //{8,0x00},    //BCK & LRCK slave mode(input), BCK & LRCK continue output when codec powered down(configure in tlv320aic32_config)
    {9,0x20},    // I2S mode, 24 bit mode
    //{9,0xE0},    // left-justified mode, 24 bit mode
    //{9,0x00},    // I2S mode, 16 bits
    //{9,0xC0},    // left-justified mode, 16 bits
    //{10,0x00},   //Audio Serial Data Word Offset(DFT)
    //{11,0x01},   //R=1(DFT)
    //{12,0x00},   //ADC highpass filter disable, DAC digital effects filter disable, DAC de-emphasis filter disable(DFT)
    //{13,0x00},   //Reserved, write only 0x00(DFT)
    {14,0x08},   //Headset is set as stereo pseudo-differential output
    //{15,0x7F},   //ADCL PGA not muted, gain 59.5dB
    //{16,0x7F},   //ADCR PGA not muted, gain 59.5dB
    {15,0x00},   //ADCL PGA not muted, gain 0dB
    {16,0x00},   //ADCR PGA not muted, gain 0dB

    //{17,0x0F},   //MIC3L to ADCL PGA gain 0dB, MIC3R not connected to ADCL PGA
    //{17,0xFF},   //MIC3L not connected to ADCL PGA, MIC3R not connected to ADCL PGA(DFT)
    //{18,0xF0},   //MIC3R to ADCR PGA gain 0dB, MIC3L not connected to ADCR PGA
    //{18,0xFF},   //MIC3R not connected to ADCL PGA, MIC3L not connected to ADCR PGA(DFT)

    {19,0x04},   //LINE1L to ADCL PGA gain 0dB, ADCL is powered up
    //{19,0x7C},   //LINE1L not connected to ADCL PGA, ADCL is powered up
    //{20,0x78},   //LINE2L not connected to ADCL PGA(DFT)
    //{20,0x00},   //LINE2L to ADCL PGA gain 0dB

    //{21,0x78},   //LINE1R not connected to ADCL PGA(DFT)

    {22,0x04},   //LINE1R to ADCR PGA gain 0dB, ADCR is powered up
    //{22,0x7C},   //LINE1R not connected to ADCR PGA, ADCR is powered up
    //{23,0x78},   //LINE2R not connected to ADCR PGA(DFT)
    //{23,0x00},   //LINE2R to ADCR PGA gain 0dB

    //{24,0x78},   //LINE1L not connected to ADCR PGA(DFT)

    {25,0x40},   //MICBIAS output is powered to 2.0V
    //{25,0x80},   //MICBIAS output is powered to 2.5V

    //{26,0x00},   //Left AGC Disable(DFT)
    {26,0x80},   //Left AGC Enable

    {27,0x40},   //Left AGC max gain 32dB
    //{28,0x00},   //Left AGC Noise Gate Hysteresis disable, Noise/Silence Detection disable, Clip Stepping disable(DFT)

    //{29,0x00},   //Right AGC Disable(DFT)
    {29,0x80},   //Right AGC Enable

    {30,0x40},   //Right AGC max gain 32dB
    //{31,0x00},   //Right AGC Noise Gate Hysteresis disable, Noise/Silence Detection disable, Clip Stepping disable(DFT)
    //{32,0x00},   //Left Channel Gain Applied by AGC Algorithm 0dB(DFT)
    //{33,0x00},   //Right Channel Gain Applied by AGC Algorithm 0dB(DFT)
    //{34,0x00},   //Left AGC Noise Detection Debounce 0ms, Signal Detection Debounce 0ms(DFT)
    //{35,0x00},   //Right AGC Noise Detection Debounce 0ms, Signal Detection Debounce 0ms(DFT)
    //{36,0x00},   //ADC Flag register, DO NOT WRITE(DFT)

    //{37,0xC0},   //DACL power up, DACR power up, HPLCOM configured as differential of HPLOUT
    //{38,0x00},   //HPRCOM configured as differential of HPROUT
    {37,0xD0},   //DACL power up, DACR power up, HPLCOM configured as constant VCM output
    {38,0x08},   //HPRCOM configured as constant VCM output

    //{39,0x00},   //Reserved, DO NOT WRITE(DFT)
    //{40,0x00},   //Output common-mode Voltage=1.35V, LINE2L bypass disable, LINE2R bypass disable(DFT)
    //{41,0x00},   //DACL output selects DAC_L1 path, DACR output selects DAC_R1 path, Left and Right DAC channel volume independent(DFT)
    {42,0x6C},   //Output Driver power-on time 100ms, ramp-up step time 4ms
    {43,0x00},   //DACL not muted, volume gain 0dB
    {44,0x00},   //DACR not muted, volume gain 0dB
    //{45,0x00},   //LINE2L not routed to HPLOUT(DFT)
    //{46,0x00},   //PGA_L not routed to HPLOUT(DFT)

    //{47,0x00},   //DAC_L1 not routed to HPLOUT(DFT)
    {47,0x80},   //DAC_L1 routed to HPLOUT, analog volume 0dB

    //{48,0x00},   //LINE2R not routed to HPLOUT(DFT)
    //{49,0x00},   //PGA_R not routed to HPLOUT(DFT)
    //{50,0x00},   //DAC_R1 not routed to HPLOUT(DFT)

    //{51,0x06},   //HPLOUT output level 0dB, HPLOUT muted, tri-stated with powered down, not fully powered up(DFT)
    {51,0x0F},   //HPLOUT output level 0dB, HPLOUT not muted, tri-stated with powered down, fully powered up

    //{52,0x00},   //LINE2L not routed to HPLCOM(DFT)
    //{53,0x00},   //PGA_L not routed to HPLCOM(DFT)
    //{54,0x00},   //DAC_L1 not routed to HPLCOM(DFT)
    //{55,0x00},   //LINE2R not routed to HPLCOM(DFT)
    //{56,0x00},   //PGA_R not routed to HPLCOM(DFT)
    //{57,0x00},   //DAC_R1 not routed to HPLCOM(DFT)

    //{58,0x0F},   //HPLCOM output level 0dB, HPLCOM not muted, tri-stated with powered down, fully powered up
    //{58,0x06},   //HPLCOM output level 0dB, HPLCOM muted, tri-stated with powered down, fully powered up(DFT)

    //{59,0x00},   //LINE2L not routed to HPROUT(DFT)
    //{60,0x00},   //PGA_L not routed to HPROUT(DFT)
    //{61,0x00},   //DAC_L1 not routed to HPROUT(DFT)
    //{62,0x00},   //LINE2R not routed to HPROUT(DFT)
    //{63,0x00},   //PGA_R not routed to HPROUT(DFT)

    //{64,0x00},   //DAC_R1 not routed to HPROUT(DFT)
    {64,0x80},   //DAC_R1 routed to HPROUT, analog volume 0dB

    //{65,0x00},   //HPROUT output level 0dB, HPROUT muted, common-mode with powered down, not fully powered up
    {65,0x0F},   //HPROUT output level 0dB, HPROUT not muted, tri-stated with powered down, fully powered up

    //{66,0x00},   //LINE2L not routed to HPRCOM(DFT)
    //{67,0x00},   //PGA_L not routed to HPRCOM(DFT)
    //{68,0x00},   //DAC_L1 not routed to HPRCOM(DFT)
    //{69,0x00},   //LINE2R not routed to HPRCOM(DFT)
    //{70,0x00},   //PGA_R not routed to HPRCOM(DFT)
    //{71,0x00},   //DAC_R1 not routed to HPRCOM(DFT)
    //{72,0x06},   //HPRCOM output level 0dB, HPRCOM muted, tri-stated with powered down, not fully powered up(DFT)
    //{73,0x00},   //Reserved, write only 0x00(DFT)
    //{74,0x00},   //Reserved, write only 0x00(DFT)
    //{75,0x00},   //Reserved, write only 0x00(DFT)
    //{76,0x00},   //Reserved, write only 0x00(DFT)
    //{77,0x00},   //Reserved, write only 0x00(DFT)
    //{78,0x00},   //Reserved, write only 0x00(DFT)
    //{79,0x02},   //Reserved, write only 0x02(DFT)

    //{80,0x00},   //LINE2L not routed to LEFT_LOP/M(DFT)
    //{80,0x80},   //LINE2L routed to LEFT_LOP/M, analog volume 0dB

    //{81,0x00},   //PGA_L not routed to LEFT_LOP/M(DFT)

    {82,0x80},   //DAC_L1 routed to LEFT_LOP/M, analog volume 0dB
    //{82,0x00},   //DAC_L1 not routed to LEFT_LOP/M(DFT)

    //{83,0x00},   //LINE2R not routed to LEFT_LOP/M(DFT)
    //{84,0x00},   //PGA_R not routed to LEFT_LOP/M(DFT)
    //{85,0x00},   //DAC_R1 not routed to LEFT_LOP/M(DFT)
    {86,0x0B},   //LEFT_LOP/M output level 0dB, LEFT_LOP/M not muted, fully powered up
    //{87,0x00},   //LINE2L not routed to RIGHT_LOP/M(DFT)
    //{88,0x00},   //PGA_L not routed to RIGHT_LOP/M(DFT)
    //{89,0x00},   //DAC_L1 not routed to RIGHT_LOP/M(DFT)

    //{90,0x00},   //LINE2R not routed to RIGHT_LOP/M(DFT)
    //{90,0x80},   //LINE2R routed to RIGHT_LOP/M, analog volume 0dB

    //{91,0x00},   //PGA_R not routed to RIGHT_LOP/M(DFT)

    {92,0x80},   //DAC_R1 routed to RIGHT_LOP/M, analog volume 0dB
    //{92,0x00},   //DAC_R1 not routed to RIGHT_LOP/M(DFT)

    {93,0x0B},   //RIGHT_LOP/M output level 0dB, RIGHT_LOP/M not muted, fully powered up

    //{94,0x00},   //Module Power Status(DFT)
    //{95,0x00},   //Output Driver Short Circuit Detection Status(DFT)
    //{96,0x00},   //Sticky Interrupt Flags(DFT)
    //{97,0x00},   //Real-time Interrupt Flags(DFT)
    //{98,0x00},   //Reserved, write only 0x00(DFT)
    //{99,0x00},   //Reserved, write only 0x00(DFT)
    //{100,0x00},   //Reserved, write only 0x00(DFT)
    //{101,0x00},   //CODEC_CLKIN uses PLLDIV_OUT(DFT)
    //{102,0x02},   //CLKDIV_IN uses MCLK, PLLCLK_IN uses MCLK(DFT)
};

void udelay_use(int delaytime)                          // 30us
{
    int i,j;

    for(i=0;i<delaytime;i++) {
        for(j=0;j<1000;j++) {
            __NOP();
        }
    }
}

void mdelay_use(int delaytime)                          // 1ms
{
    int m;

    for(m=0;m<delaytime;m++) {
        udelay_use(1000);
    }
}

void sdelay_use(int delaytime)                          // 1s
{
    int n;

    for(n=0;n<delaytime;n++) {
        mdelay_use(1000);
    }
}

__STATIC_INLINE void i2cm_iomux_config(void)
{
    //SCL
    iomux_gpio_config_sel_setf(6, 1);
    iomux_gpio_config_pull_up_setf(6, 1);
    //SDA
    iomux_gpio_config_sel_setf(7, 1);
    iomux_gpio_config_pull_up_setf(7, 1);
}

void tlv320aic32_i2c_init(void)
{
    uint32_t pclk;
    uint32_t div;//14bit
    uint16_t div0;//[15:0]
    uint16_t div1;//[25:16]

    pclk = sysctrl_clock_get(SYS_PCLK);

    div = pclk / 4 / I2C_CLK;
    div0 = div & 0xFFFF;
    div1 = (div >> 16) & 0x3FF;

    AIC_I2CM0->DR[0] = DR_DIV0_0_FILED(div0) | DR_DIV0_1_FILED(div0);
    AIC_I2CM0->DR[1] = DR_DIV1_0_FILED(div1) | DR_DIV1_1_FIELD(div1);
    AIC_I2CM0->SCR   = 0x200;
}

void tlv320aic32_reg_wr(unsigned char waddr,unsigned char wdata)
{
    unsigned int rdata;

    //TRACE("i2cm byte write start !!!\n");
    AIC_I2CM0->SAR = SAR_SLAVE_ADDR_FILED(TLV320AIC32_ADDR);
    AIC_I2CM0->OR  = waddr;
    AIC_I2CM0->OR  = wdata;
    AIC_I2CM0->LR  = 2;
    AIC_I2CM0->CR  = CR_OMO_ENABLE_BIT | CR_START_BIT | CR_ENABLE_BIT | CR_DE_TH_FILED(0x1) | CR_DF_TH_FILED(0x1);
    __NOP();__NOP();__NOP();__NOP();

    rdata = AIC_I2CM0->SR;
    while((rdata & SR_BUSY_BIT) == SR_BUSY_BIT)
    {
        rdata = AIC_I2CM0->SR;
        //TRACE("i2cm byte write status =%x!!!\n", rdata);
    }
    AIC_I2CM0->CR  = 0;
    AIC_I2CM0->RR = RR_RST_BIT;
}

unsigned char tlv320aic32_reg_rd(unsigned char raddr)
{
    unsigned int rdata;

    AIC_I2CM0->SAR = SAR_SLAVE_ADDR_FILED(TLV320AIC32_ADDR);
    AIC_I2CM0->OR  = raddr;
    AIC_I2CM0->LR  = 1;
    AIC_I2CM0->CR  = CR_OMO_ENABLE_BIT | CR_START_BIT | CR_ENABLE_BIT | CR_DE_TH_FILED(0x1) | CR_DF_TH_FILED(0x1) | CR_RESTART_BIT ;
    __NOP();__NOP();__NOP();__NOP();

    rdata =  AIC_I2CM0->SR;
    while((rdata & SR_BUSY_BIT) == SR_BUSY_BIT)
    {
        rdata = AIC_I2CM0->SR;
        //TRACE("i2cm byte read status0 =%x!!!\n", rdata);
    }
    //TRACE("i2cm byte read start !!!\n");
    AIC_I2CM0->LR = 1;
    AIC_I2CM0->CR   = CR_OMO_ENABLE_BIT | CR_START_BIT | CR_ENABLE_BIT | CR_DE_TH_FILED(0x1) | CR_DF_TH_FILED(0x1) | CR_READ_BIT;
    __NOP();__NOP();__NOP();__NOP();

    rdata = AIC_I2CM0->SR;
    while((rdata & SR_BUSY_BIT) == SR_BUSY_BIT)
    {
        rdata =  AIC_I2CM0->SR;
        //TRACE("i2cm byte read status1 =%x!!!\n", rdata);
    }
    rdata = AIC_I2CM0->IR;
    AIC_I2CM0->CR  = 0;
    return((rdata)&0xff);
}

void tlv320aic32_reset(void)
{
    uint8_t reset_pin_type = PIN_TYPE(audio_config_tlv320aic32_reset_pin_get());
    uint8_t reset_pin_idx = PIN_IDX(audio_config_tlv320aic32_reset_pin_get());

#if (PLF_HW_ASIC == 1)
    if (reset_pin_type == PIN_TYPE_A) {
        gpioa_clr(reset_pin_idx);
    }
#if PLF_PMIC
    else if (reset_pin_type == PIN_TYPE_B) {
        gpiob_clr(reset_pin_idx);
    }
#endif

    mdelay_use(1);

    if (reset_pin_type == PIN_TYPE_A) {
        gpioa_set(reset_pin_idx);
    }
#if PLF_PMIC
    else if (reset_pin_type == PIN_TYPE_B) {
        gpiob_set(reset_pin_idx);
    }
#endif
#endif
    TRACE("codec reset\n");
}

void tlv320aic32_init(void)
{
    TRACE("codec init start\n");
    unsigned int i;
#if (CODEC_DEBUG)
    unsigned char rdata;
#endif

    i2cm_iomux_config();

    uint8_t reset_pin_type = PIN_TYPE(audio_config_tlv320aic32_reset_pin_get());
    uint8_t reset_pin_idx = PIN_IDX(audio_config_tlv320aic32_reset_pin_get());

    if (reset_pin_type == PIN_TYPE_A) {
        gpioa_init(reset_pin_idx);
        gpioa_dir_out(reset_pin_idx);
    }
#if PLF_PMIC
    else if (reset_pin_type == PIN_TYPE_B) {
        gpiob_init(reset_pin_idx);
        gpiob_dir_out(reset_pin_idx);
    }
#endif

    tlv320aic32_reset();
    tlv320aic32_i2c_init();
    tlv320aic32_reg_wr(0x0,0x0);
    tlv320aic32_reg_wr(0x1,0x80);
    tlv320aic32_reg_wr(0x0,0x0);

    uint32_t reg_count = sizeof(codec_initial_data_buf) / sizeof(codec_initial_data_buf[0]);
    for (i = 0; i < reg_count; i++) {
        tlv320aic32_reg_wr(codec_initial_data_buf[i][0], codec_initial_data_buf[i][1]);
#if (CODEC_DEBUG)
        rdata = tlv320aic32_reg_rd(codec_initial_data_buf[i][0]);
        TRACE("addr=%X, wr=%X, rd=%X\n", codec_initial_data_buf[i][0], codec_initial_data_buf[i][1], rdata);
#endif
    }

    TRACE("codec init done\n");
}

void tlv320aic32_config(tlv320aic32_cfg_t *cfg)
{
    uint8_t div = 0;
    uint8_t fsref_div_idx = 0;
    bool is_48k = false;
    bool dual_rate_mode = false;
    uint8_t addr;
    uint8_t val;
#if (CODEC_DEBUG)
    uint8_t rdata;
#endif
    bool update_codec = false;

    //We don't care about ch_num here, actual data channel number on I2S is is always 2
    if ((cfg->samp_rate != last_cfg.samp_rate) ||
        (cfg->bits != last_cfg.bits) ||
        (cfg->codec_master != last_cfg.codec_master)) {
        update_codec = true;
    }

    if (update_codec == false) {
        TRACE("No need to update codec\n");
        return;
    }

    ASSERT_ERR(cfg->samp_rate <= 96000);

    if (cfg->samp_rate > 48000) {
        dual_rate_mode = true;
    }

    //computer fsref div, multiply by 10 to match fsref_div_tbl
    if (0 == (cfg->samp_rate % 8000)) {
        if (dual_rate_mode) {
            div = 960000 / cfg->samp_rate;
        } else {
            div = 480000 / cfg->samp_rate;
        }
        is_48k = true;
    } else if (0 == (cfg->samp_rate % 11025)) {
        if (dual_rate_mode) {
            div = 882000 / cfg->samp_rate;
        } else {
            div = 441000 / cfg->samp_rate;
        }
        is_48k = false;
    } else {
        ASSERT_ERR2(0, "ERROR: invalid sample rate %d\n", cfg->samp_rate);
    }

    for (fsref_div_idx = 0; fsref_div_idx < FSREF_DIV_NB; fsref_div_idx++) {
        if (fsref_div_tbl[fsref_div_idx] == div) {
            break;
        }
    }
    if (fsref_div_idx >= FSREF_DIV_NB) {
        ASSERT_ERR2(0, "ERROR: invalid divider %d\n", div);
    }

    addr = 0x00;
    val = 0x00;
    tlv320aic32_reg_wr(addr, val);//select page 0
#if (CODEC_DEBUG)
    rdata = tlv320aic32_reg_rd(addr);
    TRACE("addr=%X, wr=%X, rd=%X\n",addr,val, rdata);
#endif

    addr = 0x08;//master/slave select
    if (cfg->codec_master == true) {
        val = 0xD0;
    } else {
        val = 0x00;
    }
    tlv320aic32_reg_wr(addr, val);
#if (CODEC_DEBUG)
    rdata = tlv320aic32_reg_rd(addr);
    TRACE("addr=%X, wr=%X, rd=%X\n", addr, val, rdata);
#endif

    addr = 0x07;//Codec Datapath Setup Register
    val = tlv320aic32_reg_rd(addr);
    //Fsref setting(48K series or 44.1K series)
    if (is_48k) {
        val &= ~(0x01 << 7);
    } else {
        val |= (0x01 << 7);
    }
    //Dual rate control
    if (dual_rate_mode) {
        val |= ((0x01UL << 5) | (0x01UL << 6));
    } else {
        val &= ~((0x01UL << 5) | (0x01UL << 6));
    }
    tlv320aic32_reg_wr(addr, val);
#if (CODEC_DEBUG)
    rdata = tlv320aic32_reg_rd(addr);
    TRACE("addr=%X, wr=%X, rd=%X\n", addr, val, rdata);
#endif

    addr = 0x02;//Codec Sample Rate Select
    val = (fsref_div_idx << 4) | (fsref_div_idx << 0);
    tlv320aic32_reg_wr(addr, val);
#if (CODEC_DEBUG)
    rdata = tlv320aic32_reg_rd(addr);
    TRACE("addr=%X, wr=%X, rd=%X\n", addr, val, rdata);
#endif

    last_cfg = *cfg;
}

void tlv320aic32_deinit(void)
{
    //TODO
}

