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
#include "gpio_api.h"
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
        // mux gpio
        gpiob_init(gpbidx);
        gpiob_dir_in(gpbidx);
        #if PLF_PMIC_VER_LITE
        PMIC_MEM_MASK_WRITE((unsigned int)(&aic1000liteIomux->GPCFG[gpbidx]),
            (AIC1000LITE_IOMUX_PAD_GPIO_PULL_FRC),
            (AIC1000LITE_IOMUX_PAD_GPIO_PULL_FRC));
        #endif
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
        volt_mv = ((int)rdata * 1175 / 32896 - 1175) * (neg_flag ? -1 : 1);
    }
    return volt_mv;
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
