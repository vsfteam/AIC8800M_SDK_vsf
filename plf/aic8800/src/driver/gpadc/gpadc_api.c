/**
 ****************************************************************************************
 *
 * @file gpadc_api.c
 *
 * @brief GPADC API functions
 *
 ****************************************************************************************
 */

/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include "../gpio/gpio_api.h"
#include "gpadc_api.h"
#include "arch.h"
#if PLF_PMIC
#include "pmic_api.h"

void gpadc_init(int gpbidx)
{
    if (((gpbidx >= 0) && (gpbidx <= 5)) || (gpbidx == 13)) {
        #if PLF_PMIC_VER_LITE
        // sw mode
        PMIC_MEM_WRITE((unsigned int)(&aic1000liteMsadc->cfg_msadc_mode), 0);
        // mux_en
        if ((gpbidx <= 1) || (gpbidx == 13)) {
            PMIC_MEM_MASK_WRITE((unsigned int)(&aic1000liteAnalogReg->gpio_ctrl1),
                (0x01 << gpbidx), (0x01 << gpbidx));//AIC1000LITE_ANALOG_REG_CFG_ANA_GPIO01_MUX0_EN,AIC1000LITE_ANALOG_REG_CFG_ANA_GPIO8D_MUX0_EN
        } else {
            PMIC_MEM_MASK_WRITE((unsigned int)(&aic1000liteRtcCore->rtc_rg_por_ctrl_cfg2),
                AIC1000LITE_RTC_CORE_RTC_RG_GPIO27_MUX0_EN(0x01 << (gpbidx - 2)),
                AIC1000LITE_RTC_CORE_RTC_RG_GPIO27_MUX0_EN(0x01 << (gpbidx - 2)));
        }
        #endif
        #if PLF_PMIC_VER_AUD
        // sw mode
        PMIC_MEM_WRITE((unsigned int)(&aic1000audMsadc->cfg_msadc_mode), 0);
        // mux_en
        if ((gpbidx <= 4) && (gpbidx >= 0)) {
            PMIC_MEM_MASK_WRITE((unsigned int)(&aic1000audAnalogReg->gpio_ctrl2),
                (0x01 << gpbidx), (0x01 << gpbidx));
        }
        #endif
        // mux gpio
        gpiob_init(gpbidx);
        gpiob_dir_in(gpbidx);
        gpiob_force_pull_none_enable(gpbidx);
    }
}

void gpadc_samplerate_set(int rate)
{
    #if PLF_PMIC_VER_LITE
    PMIC_MEM_WRITE((unsigned int)(&aic1000liteSysctrl->msadc_clk_div),
        AIC1000LITE_SYS_CTRL_CFG_CLK_MSADC_DIV_DENOM(rate) | AIC1000LITE_SYS_CTRL_CFG_CLK_MSADC_DIV_UPDATE);
    #endif
}

void gpadc_free(int gpbidx)
{
    if (((gpbidx >= 0) && (gpbidx <= 5)) || (gpbidx == 13)) {
        #if PLF_PMIC_VER_LITE
        // mux_en
        if ((gpbidx <= 1) || (gpbidx == 13)) {
            PMIC_MEM_MASK_WRITE((unsigned int)(&aic1000liteAnalogReg->gpio_ctrl1),
                0, (0x01 << gpbidx));//AIC1000LITE_ANALOG_REG_CFG_ANA_GPIO01_MUX0_EN,AIC1000LITE_ANALOG_REG_CFG_ANA_GPIO8D_MUX0_EN
        } else {
            PMIC_MEM_MASK_WRITE((unsigned int)(&aic1000liteRtcCore->rtc_rg_por_ctrl_cfg2),
                0, AIC1000LITE_RTC_CORE_RTC_RG_GPIO27_MUX0_EN(0x01 << (gpbidx - 2)));
        }
        #endif
        #if PLF_PMIC_VER_AUD
        // mux_disable
        if ((gpbidx <= 4) && (gpbidx >= 0)) {
            PMIC_MEM_MASK_WRITE((unsigned int)(&aic1000audAnalogReg->gpio_ctrl2),
                0, (0x01 << gpbidx));
        }
        #endif
        gpiob_deinit(gpbidx);
    }
}

int gpadc_read(int gpbidx)
{
    int volt_mv = 0;
    if (((gpbidx >= 0) && (gpbidx <= 5)) || (gpbidx == 13)) {
        int neg_flag = gpbidx & 0x01;
        unsigned int mux_bit = 7 - (gpbidx >> 1);
        unsigned int rdata;
        #if PLF_PMIC_VER_LITE
        PMIC_MEM_MASK_WRITE((unsigned int)(&aic1000liteMsadc->cfg_msadc_ana_ctrl0),
            ((neg_flag ? 0 : AIC1000LITE_MSADC_CFG_ANA_MSADC_CHNP_SEL) |
            AIC1000LITE_MSADC_CFG_ANA_MSADC_SDM_MODE | AIC1000LITE_MSADC_CFG_ANA_MSADC_SDM_GAIN_BIT |
            AIC1000LITE_MSADC_CFG_ANA_MSADC_ADC_FF_EN),
            (AIC1000LITE_MSADC_CFG_ANA_MSADC_CHNP_SEL | AIC1000LITE_MSADC_CFG_ANA_MSADC_TS_MODE |
            AIC1000LITE_MSADC_CFG_ANA_MSADC_SDM_MODE | AIC1000LITE_MSADC_CFG_ANA_MSADC_SDM_GAIN_BIT |
            AIC1000LITE_MSADC_CFG_ANA_MSADC_ADC_FF_EN)); // channel p sel or not
        PMIC_MEM_MASK_WRITE((unsigned int)(&aic1000liteMsadc->cfg_msadc_sw_ctrl1),
            (AIC1000LITE_MSADC_CFG_MSADC_SW_MUX_BITS(mux_bit) | 0),
            (AIC1000LITE_MSADC_CFG_MSADC_SW_MUX_BITS(0xF) | AIC1000LITE_MSADC_CFG_MSADC_SW_DIFF_MODE));
        PMIC_MEM_WRITE((unsigned int)(&aic1000liteMsadc->cfg_msadc_sw_ctrl0),
            AIC1000LITE_MSADC_CFG_MSADC_SW_START_PULSE);
        while(PMIC_MEM_READ((unsigned int)(&aic1000liteMsadc->cfg_msadc_int_raw)) != 0x1);
        PMIC_MEM_WRITE((unsigned int)(&aic1000liteMsadc->cfg_msadc_int_raw), 0x1);
        rdata  = PMIC_MEM_READ((unsigned int)(&aic1000liteMsadc->cfg_msadc_ro_acc));
        #endif
        #if PLF_PMIC_VER_AUD
        PMIC_MEM_MASK_WRITE((unsigned int)(&aic1000audMsadc->cfg_msadc_ana_ctrl0),
            ((neg_flag ? 0 : AIC1000AUD_MSADC_CFG_ANA_MSADC_CHNP_SEL) |
            AIC1000AUD_MSADC_CFG_ANA_MSADC_SDM_MODE | AIC1000AUD_MSADC_CFG_ANA_MSADC_SDM_GAIN_BIT |
            AIC1000AUD_MSADC_CFG_ANA_MSADC_ADC_FF_EN),
            (AIC1000AUD_MSADC_CFG_ANA_MSADC_CHNP_SEL | AIC1000AUD_MSADC_CFG_ANA_MSADC_TS_MODE |
            AIC1000AUD_MSADC_CFG_ANA_MSADC_SDM_MODE | AIC1000AUD_MSADC_CFG_ANA_MSADC_SDM_GAIN_BIT |
            AIC1000AUD_MSADC_CFG_ANA_MSADC_ADC_FF_EN)); // channel p sel or not
        PMIC_MEM_MASK_WRITE((unsigned int)(&aic1000audMsadc->cfg_msadc_sw_ctrl1),
            (AIC1000AUD_MSADC_CFG_MSADC_SW_MUX_BITS(mux_bit) | 0),
            (AIC1000AUD_MSADC_CFG_MSADC_SW_MUX_BITS(0xF) | AIC1000AUD_MSADC_CFG_MSADC_SW_DIFF_MODE));
        PMIC_MEM_WRITE((unsigned int)(&aic1000audMsadc->cfg_msadc_sw_ctrl0),
            AIC1000AUD_MSADC_CFG_MSADC_SW_START_PULSE);
        while(PMIC_MEM_READ((unsigned int)(&aic1000audMsadc->cfg_msadc_int_raw)) != 0x1);
        PMIC_MEM_WRITE((unsigned int)(&aic1000audMsadc->cfg_msadc_int_raw), 0x1);
        rdata  = PMIC_MEM_READ((unsigned int)(&aic1000audMsadc->cfg_msadc_ro_acc));
        #endif
        volt_mv = ((int)rdata * 1175 / 32896 - 1175) * (neg_flag ? -1 : 1);
    }
    return volt_mv;
}

void gpadc_diff_init(int gpbdiffch)
{
    if (gpbdiffch < GPADC_DIFF_CH_NUM) {
        int gpidx_p = gpbdiffch * 2;
        int gpidx_n = gpidx_p + 1;
        gpadc_init(gpidx_p);
        gpadc_init(gpidx_n);
    }
}

void gpadc_diff_free(int gpbdiffch)
{
    if (gpbdiffch < GPADC_DIFF_CH_NUM) {
        int gpidx_p = gpbdiffch * 2;
        int gpidx_n = gpidx_p + 1;
        gpadc_free(gpidx_p);
        gpadc_free(gpidx_n);
    }
}

int gpadc_diff_read(int gpbdiffch, int negflag)
{
    int volt_mv = 0;
    if (gpbdiffch < GPADC_DIFF_CH_NUM) {
        unsigned int mux_bit = 7 - gpbdiffch;
        unsigned int rdata;
        #if PLF_PMIC_VER_LITE
        PMIC_MEM_MASK_WRITE((unsigned int)(&aic1000liteMsadc->cfg_msadc_ana_ctrl0),
            (AIC1000LITE_MSADC_CFG_ANA_MSADC_SDM_MODE | AIC1000LITE_MSADC_CFG_ANA_MSADC_SDM_GAIN_BIT |
            AIC1000LITE_MSADC_CFG_ANA_MSADC_ADC_FF_EN),
            (AIC1000LITE_MSADC_CFG_ANA_MSADC_TS_MODE |
            AIC1000LITE_MSADC_CFG_ANA_MSADC_SDM_MODE | AIC1000LITE_MSADC_CFG_ANA_MSADC_SDM_GAIN_BIT |
            AIC1000LITE_MSADC_CFG_ANA_MSADC_ADC_FF_EN));
        PMIC_MEM_MASK_WRITE((unsigned int)(&aic1000liteMsadc->cfg_msadc_sw_ctrl1),
            (AIC1000LITE_MSADC_CFG_MSADC_SW_MUX_BITS(mux_bit) | AIC1000LITE_MSADC_CFG_MSADC_SW_DIFF_MODE),
            (AIC1000LITE_MSADC_CFG_MSADC_SW_MUX_BITS(0xF) | AIC1000LITE_MSADC_CFG_MSADC_SW_DIFF_MODE));
        PMIC_MEM_WRITE((unsigned int)(&aic1000liteMsadc->cfg_msadc_sw_ctrl0),
            AIC1000LITE_MSADC_CFG_MSADC_SW_START_PULSE);
        while(PMIC_MEM_READ((unsigned int)(&aic1000liteMsadc->cfg_msadc_int_raw)) != 0x1);
        PMIC_MEM_WRITE((unsigned int)(&aic1000liteMsadc->cfg_msadc_int_raw), 0x1);
        rdata  = PMIC_MEM_READ((unsigned int)(&aic1000liteMsadc->cfg_msadc_ro_acc));
        #endif
        #if PLF_PMIC_VER_AUD
        PMIC_MEM_MASK_WRITE((unsigned int)(&aic1000audMsadc->cfg_msadc_ana_ctrl0),
            (AIC1000AUD_MSADC_CFG_ANA_MSADC_SDM_MODE | AIC1000AUD_MSADC_CFG_ANA_MSADC_SDM_GAIN_BIT |
            AIC1000AUD_MSADC_CFG_ANA_MSADC_ADC_FF_EN),
            (AIC1000AUD_MSADC_CFG_ANA_MSADC_TS_MODE |
            AIC1000AUD_MSADC_CFG_ANA_MSADC_SDM_MODE | AIC1000AUD_MSADC_CFG_ANA_MSADC_SDM_GAIN_BIT |
            AIC1000AUD_MSADC_CFG_ANA_MSADC_ADC_FF_EN));
        PMIC_MEM_MASK_WRITE((unsigned int)(&aic1000audMsadc->cfg_msadc_sw_ctrl1),
            (AIC1000AUD_MSADC_CFG_MSADC_SW_MUX_BITS(mux_bit) | AIC1000AUD_MSADC_CFG_MSADC_SW_DIFF_MODE),
            (AIC1000AUD_MSADC_CFG_MSADC_SW_MUX_BITS(0xF) | AIC1000AUD_MSADC_CFG_MSADC_SW_DIFF_MODE));
        PMIC_MEM_WRITE((unsigned int)(&aic1000audMsadc->cfg_msadc_sw_ctrl0),
            AIC1000AUD_MSADC_CFG_MSADC_SW_START_PULSE);
        while(PMIC_MEM_READ((unsigned int)(&aic1000audMsadc->cfg_msadc_int_raw)) != 0x1);
        PMIC_MEM_WRITE((unsigned int)(&aic1000audMsadc->cfg_msadc_int_raw), 0x1);
        rdata  = PMIC_MEM_READ((unsigned int)(&aic1000audMsadc->cfg_msadc_ro_acc));
        #endif
        volt_mv = ((int)rdata * 1175 / 32896 - 1175) * (negflag ? -1 : 1);
    }
    return volt_mv;
}

/* high accuracy mode */
int gpadc_diff_read_ham(int gpbdiffch, int negflag)
{
    int volt_mv_0 = 0, volt_mv_1 = 0;
    if (gpbdiffch < GPADC_DIFF_CH_NUM) {
        unsigned int mux_bit = 7 - gpbdiffch;
        unsigned int rdata_0, rdata_1;
        #if PLF_PMIC_VER_LITE
        PMIC_MEM_MASK_WRITE((unsigned int)(&aic1000liteMsadc->cfg_msadc_ana_ctrl0),
            (AIC1000LITE_MSADC_CFG_ANA_MSADC_TEST_MODE |
             AIC1000LITE_MSADC_CFG_ANA_MSADC_SDM_MODE | AIC1000LITE_MSADC_CFG_ANA_MSADC_IBIAS_BIT(0x2) |
             AIC1000LITE_MSADC_CFG_ANA_MSADC_CHOP_EN | AIC1000LITE_MSADC_CFG_ANA_MSADC_SDM_GAIN_BIT |
             AIC1000LITE_MSADC_CFG_ANA_MSADC_DEM_EN(0x3) | AIC1000LITE_MSADC_CFG_ANA_MSADC_ADC_FF_EN),
            (AIC1000LITE_MSADC_CFG_ANA_MSADC_TS_MODE | AIC1000LITE_MSADC_CFG_ANA_MSADC_TEST_MODE |
             AIC1000LITE_MSADC_CFG_ANA_MSADC_SDM_MODE | AIC1000LITE_MSADC_CFG_ANA_MSADC_IBIAS_BIT(0x7) |
             AIC1000LITE_MSADC_CFG_ANA_MSADC_CHOP_EN | AIC1000LITE_MSADC_CFG_ANA_MSADC_SDM_GAIN_BIT |
             AIC1000LITE_MSADC_CFG_ANA_MSADC_DEM_EN(0x3) | AIC1000LITE_MSADC_CFG_ANA_MSADC_ADC_FF_EN));
        PMIC_MEM_MASK_WRITE((unsigned int)(&aic1000liteMsadc->cfg_msadc_sw_ctrl1),
            (AIC1000LITE_MSADC_CFG_MSADC_SW_MUX_BITS(mux_bit) |AIC1000LITE_MSADC_CFG_MSADC_WINDOW(0xFC0) |
             AIC1000LITE_MSADC_CFG_MSADC_SW_DIFF_MODE),
            (AIC1000LITE_MSADC_CFG_MSADC_SW_MUX_BITS(0xF) | AIC1000LITE_MSADC_CFG_MSADC_WINDOW(0xFFF)|
             AIC1000LITE_MSADC_CFG_MSADC_SW_DIFF_MODE));
        PMIC_MEM_WRITE((unsigned int)(&aic1000liteMsadc->cfg_msadc_sw_ctrl0),
            AIC1000LITE_MSADC_CFG_MSADC_SW_START_PULSE);
        while(PMIC_MEM_READ((unsigned int)(&aic1000liteMsadc->cfg_msadc_int_raw)) != 0x1);
        PMIC_MEM_WRITE((unsigned int)(&aic1000liteMsadc->cfg_msadc_int_raw), 0x1);
        rdata_0  = PMIC_MEM_READ((unsigned int)(&aic1000liteMsadc->cfg_msadc_ro_acc));
        PMIC_MEM_MASK_WRITE((unsigned int)(&aic1000liteMsadc->cfg_msadc_ana_ctrl0),
            (AIC1000LITE_MSADC_CFG_ANA_MSADC_SDM_MODE | AIC1000LITE_MSADC_CFG_ANA_MSADC_IBIAS_BIT(0x2) |
             AIC1000LITE_MSADC_CFG_ANA_MSADC_CHOP_EN | AIC1000LITE_MSADC_CFG_ANA_MSADC_SDM_GAIN_BIT |
             AIC1000LITE_MSADC_CFG_ANA_MSADC_DEM_EN(0x3) | AIC1000LITE_MSADC_CFG_ANA_MSADC_ADC_FF_EN),
            (AIC1000LITE_MSADC_CFG_ANA_MSADC_TS_MODE | AIC1000LITE_MSADC_CFG_ANA_MSADC_TEST_MODE |
             AIC1000LITE_MSADC_CFG_ANA_MSADC_SDM_MODE | AIC1000LITE_MSADC_CFG_ANA_MSADC_IBIAS_BIT(0x7) |
             AIC1000LITE_MSADC_CFG_ANA_MSADC_CHOP_EN | AIC1000LITE_MSADC_CFG_ANA_MSADC_SDM_GAIN_BIT |
             AIC1000LITE_MSADC_CFG_ANA_MSADC_DEM_EN(0x3) | AIC1000LITE_MSADC_CFG_ANA_MSADC_ADC_FF_EN));
        PMIC_MEM_WRITE((unsigned int)(&aic1000liteMsadc->cfg_msadc_sw_ctrl0),
            AIC1000LITE_MSADC_CFG_MSADC_SW_START_PULSE);
        while(PMIC_MEM_READ((unsigned int)(&aic1000liteMsadc->cfg_msadc_int_raw)) != 0x1);
        PMIC_MEM_WRITE((unsigned int)(&aic1000liteMsadc->cfg_msadc_int_raw), 0x1);
        rdata_1  = PMIC_MEM_READ((unsigned int)(&aic1000liteMsadc->cfg_msadc_ro_acc));
        #endif
        #if PLF_PMIC_VER_AUD
        PMIC_MEM_MASK_WRITE((unsigned int)(&aic1000audMsadc->cfg_msadc_ana_ctrl0),
            (AIC1000AUD_MSADC_CFG_ANA_MSADC_SDM_MODE | AIC1000AUD_MSADC_CFG_ANA_MSADC_SDM_GAIN_BIT |
            AIC1000AUD_MSADC_CFG_ANA_MSADC_ADC_FF_EN),
            (AIC1000AUD_MSADC_CFG_ANA_MSADC_TS_MODE |
            AIC1000AUD_MSADC_CFG_ANA_MSADC_SDM_MODE | AIC1000AUD_MSADC_CFG_ANA_MSADC_SDM_GAIN_BIT |
            AIC1000AUD_MSADC_CFG_ANA_MSADC_ADC_FF_EN));
        PMIC_MEM_MASK_WRITE((unsigned int)(&aic1000audMsadc->cfg_msadc_sw_ctrl1),
            (AIC1000AUD_MSADC_CFG_MSADC_SW_MUX_BITS(mux_bit) | AIC1000AUD_MSADC_CFG_MSADC_WINDOW(0xFC0) |
             AIC1000AUD_MSADC_CFG_MSADC_SW_DIFF_MODE),
            (AIC1000AUD_MSADC_CFG_MSADC_SW_MUX_BITS(0xF) | AIC1000AUD_MSADC_CFG_MSADC_WINDOW(0xFFF) |
             AIC1000AUD_MSADC_CFG_MSADC_SW_DIFF_MODE));
        PMIC_MEM_WRITE((unsigned int)(&aic1000audMsadc->cfg_msadc_sw_ctrl0),
            AIC1000AUD_MSADC_CFG_MSADC_SW_START_PULSE);
        while(PMIC_MEM_READ((unsigned int)(&aic1000audMsadc->cfg_msadc_int_raw)) != 0x1);
        PMIC_MEM_WRITE((unsigned int)(&aic1000audMsadc->cfg_msadc_int_raw), 0x1);
        rdata  = PMIC_MEM_READ((unsigned int)(&aic1000audMsadc->cfg_msadc_ro_acc));
        #endif
        volt_mv_0 = ((int64_t)rdata_0 * 117500 / 2033136 - 117500) * (negflag ? -1 : 1);
        volt_mv_1 = ((int64_t)rdata_1 * 117500 / 2033136 - 117500) * (negflag ? -1 : 1);
    }
    return (volt_mv_1 - volt_mv_0);
}

int gpadc_measure(int type)
{
    int ret = 0;
    if (type == GPADC_TYPE_VBAT) {
        unsigned int rdata;
        #if PLF_PMIC_VER_LITE
        //PU VBAT sense and VRTC sense
        PMIC_MEM_MASK_WRITE((unsigned int)(&aic1000liteRtcCore->rtc_rg_por_ctrl_cfg1),
            (AIC1000LITE_RTC_CORE_RTC_RG_PU_VRTC_SENSE | AIC1000LITE_RTC_CORE_RTC_RG_PU_VBAT_SENSE),
            (AIC1000LITE_RTC_CORE_RTC_RG_PU_VRTC_SENSE | AIC1000LITE_RTC_CORE_RTC_RG_PU_VBAT_SENSE));
        PMIC_MEM_MASK_WRITE((unsigned int)(&aic1000liteMsadc->cfg_msadc_sw_ctrl1),
            (AIC1000LITE_MSADC_CFG_MSADC_SW_MUX_BITS(0xD) | AIC1000LITE_MSADC_CFG_MSADC_SW_DIFF_MODE),
            (AIC1000LITE_MSADC_CFG_MSADC_SW_MUX_BITS(0xF) | AIC1000LITE_MSADC_CFG_MSADC_SW_DIFF_MODE));
        PMIC_MEM_MASK_WRITE((unsigned int)(&aic1000liteMsadc->cfg_msadc_ana_ctrl0),
            (0 | 0 | AIC1000LITE_MSADC_CFG_ANA_MSADC_SDM_MODE | AIC1000LITE_MSADC_CFG_ANA_MSADC_SDM_GAIN_BIT |
            AIC1000LITE_MSADC_CFG_ANA_MSADC_ADC_FF_EN),
            (AIC1000LITE_MSADC_CFG_ANA_MSADC_CHNP_SEL | AIC1000LITE_MSADC_CFG_ANA_MSADC_TS_MODE |
            AIC1000LITE_MSADC_CFG_ANA_MSADC_SDM_MODE | AIC1000LITE_MSADC_CFG_ANA_MSADC_SDM_GAIN_BIT |
            AIC1000LITE_MSADC_CFG_ANA_MSADC_ADC_FF_EN));
        PMIC_MEM_WRITE((unsigned int)(&aic1000liteMsadc->cfg_msadc_sw_ctrl0),
            AIC1000LITE_MSADC_CFG_MSADC_SW_START_PULSE);
        while(PMIC_MEM_READ((unsigned int)(&aic1000liteMsadc->cfg_msadc_int_raw)) != 0x1);
        PMIC_MEM_WRITE((unsigned int)(&aic1000liteMsadc->cfg_msadc_int_raw), 0x1);
        rdata  = PMIC_MEM_READ((unsigned int)(&aic1000liteMsadc->cfg_msadc_ro_acc));
        #endif
        #if PLF_PMIC_VER_AUD
        //PU VBAT sense and VRTC sense
        rdata  = PMIC_MEM_READ((unsigned int)(&aic1000audRtcCore->rtc_rg_por_ctrl_cfg1));
        PMIC_MEM_WRITE((unsigned int)(&aic1000audRtcCore->rtc_rg_por_ctrl_cfg1),
            rdata | AIC1000AUD_RTC_CORE_RTC_RG_PU_VRTC_SENSE | AIC1000AUD_RTC_CORE_RTC_RG_PU_VBAT_SENSE);
        PMIC_MEM_WRITE((unsigned int)(&aic1000audMsadc->cfg_msadc_mode), 0);

        rdata  = PMIC_MEM_READ((unsigned int)(&aic1000audMsadc->cfg_msadc_sw_ctrl1));
        PMIC_MEM_WRITE((unsigned int)(&aic1000audMsadc->cfg_msadc_sw_ctrl1),
            rdata | AIC1000AUD_MSADC_CFG_MSADC_SW_DIFF_MODE | AIC1000AUD_MSADC_CFG_MSADC_SW_MUX_BITS(0xF));

        rdata  = PMIC_MEM_READ((unsigned int)(&aic1000audMsadc->cfg_msadc_sw_ctrl1));
        rdata  = 0xfffffff0 & rdata;
        PMIC_MEM_WRITE((unsigned int)(&aic1000audMsadc->cfg_msadc_sw_ctrl1),
            rdata | AIC1000AUD_MSADC_CFG_MSADC_SW_DIFF_MODE | AIC1000AUD_MSADC_CFG_MSADC_SW_MUX_BITS(0xc));
        PMIC_MEM_WRITE((unsigned int)(&aic1000audMsadc->cfg_msadc_sw_ctrl0),
            AIC1000AUD_MSADC_CFG_MSADC_SW_START_PULSE);
        while(PMIC_MEM_READ((unsigned int)(&aic1000audMsadc->cfg_msadc_int_raw)) != 0x1);
        PMIC_MEM_WRITE((unsigned int)(&aic1000audMsadc->cfg_msadc_int_raw), 0x1);
        rdata  = PMIC_MEM_READ((unsigned int)(&aic1000audMsadc->cfg_msadc_ro_acc));
        #endif
        ret = ((int)rdata * 1175 / 32896 - 1175) * 42 / 10;// Convert to mV
    } else if (type == GPADC_TYPE_VIO) {
        (void)0; //TODO:
    } else if (type == GPADC_TYPE_TEMP0) {
        unsigned int rdata;
        #if PLF_PMIC_VER_LITE
        PMIC_MEM_MASK_WRITE((unsigned int)(&aic1000liteMsadc->cfg_msadc_sw_ctrl1),
            (AIC1000LITE_MSADC_CFG_MSADC_SW_MUX_BITS(0x0) | AIC1000LITE_MSADC_CFG_MSADC_SW_DIFF_MODE),
            (AIC1000LITE_MSADC_CFG_MSADC_SW_MUX_BITS(0xF) | AIC1000LITE_MSADC_CFG_MSADC_SW_DIFF_MODE));
        PMIC_MEM_MASK_WRITE((unsigned int)(&aic1000liteMsadc->cfg_msadc_ana_ctrl0),
            (0 | AIC1000LITE_MSADC_CFG_ANA_MSADC_TS_MODE | 0 | 0 | 0),
            (AIC1000LITE_MSADC_CFG_ANA_MSADC_CHNP_SEL | AIC1000LITE_MSADC_CFG_ANA_MSADC_TS_MODE |
            AIC1000LITE_MSADC_CFG_ANA_MSADC_SDM_MODE | AIC1000LITE_MSADC_CFG_ANA_MSADC_SDM_GAIN_BIT |
            AIC1000LITE_MSADC_CFG_ANA_MSADC_ADC_FF_EN));
        PMIC_MEM_WRITE((unsigned int)(&aic1000liteMsadc->cfg_msadc_sw_ctrl0),
            AIC1000LITE_MSADC_CFG_MSADC_SW_START_PULSE);
        while(PMIC_MEM_READ((unsigned int)(&aic1000liteMsadc->cfg_msadc_int_raw)) != 0x1);
        PMIC_MEM_WRITE((unsigned int)(&aic1000liteMsadc->cfg_msadc_int_raw), 0x1);
        rdata  = PMIC_MEM_READ((unsigned int)(&aic1000liteMsadc->cfg_msadc_ro_acc));
        #endif
        ret = (int)rdata * 659 / 65792 - 281;
    }
    return ret;
}
#endif
