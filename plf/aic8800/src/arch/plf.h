/**
 ****************************************************************************************
 *
 * @file plf.h
 *
 * @brief This file contains the definitions of the macros and functions that are
 * platform dependent.  The implementation of those is implemented in the
 * appropriate platform directory.
 *
 ****************************************************************************************
 */
#ifndef _PLF_H_
#define _PLF_H_

/**
 ****************************************************************************************
 * @defgroup PLF
 * @ingroup DRIVERS
 *
 * @brief Platform register driver
 *
 * @{
 *
 ****************************************************************************************
 */

/*
 * HW Platform
 ****************************************************************************************
 */
#if defined(CFG_HW_PLATFORM) && (CFG_HW_PLATFORM <= 2)
#if   CFG_HW_PLATFORM == 0
#define PLF_HW_PXP          1
#define PLF_HW_FPGA         0
#define PLF_HW_ASIC         0
#elif CFG_HW_PLATFORM == 1
#define PLF_HW_PXP          0
#define PLF_HW_FPGA         1
#define PLF_HW_ASIC         0
#elif CFG_HW_PLATFORM == 2
#define PLF_HW_PXP          0
#define PLF_HW_FPGA         0
#define PLF_HW_ASIC         1
#endif
#else // CFG_HW_PLATFORM
#error "Invalid HW platform"
#endif // CFG_HW_PLATFORM

/*
 * RF Mode
 ****************************************************************************************
 */
#if defined(CFG_RF_MODE) && (CFG_RF_MODE <= 3)
#if   CFG_RF_MODE == 0
#define PLF_RF_MODE_NULL            1
#define PLF_RF_MODE_BT_ONLY         0
#define PLF_RF_MODE_BT_COMBO        0
#define PLF_RF_MODE_BTWIFI_COMBO    0
#elif CFG_RF_MODE == 1
#define PLF_RF_MODE_NULL            0
#define PLF_RF_MODE_BT_ONLY         1
#define PLF_RF_MODE_BT_COMBO        0
#define PLF_RF_MODE_BTWIFI_COMBO    0
#elif CFG_RF_MODE == 2
#define PLF_RF_MODE_NULL            0
#define PLF_RF_MODE_BT_ONLY         0
#define PLF_RF_MODE_BT_COMBO        1
#define PLF_RF_MODE_BTWIFI_COMBO    0
#elif CFG_RF_MODE == 3
#define PLF_RF_MODE_NULL            0
#define PLF_RF_MODE_BT_ONLY         0
#define PLF_RF_MODE_BT_COMBO        0
#define PLF_RF_MODE_BTWIFI_COMBO    1
#endif
#else // CFG_RF_MODE
#error "Invalid RF mode"
#endif // CFG_RF_MODE

/*
 * DAC mixer mode
 ****************************************************************************************
 */
#if defined(CFG_DACL_MIXER_MODE) && (CFG_DACL_MIXER_MODE <= 4)
#define PLF_DACL_MIXER_MODE          CFG_DACL_MIXER_MODE
#else // CFG_DACL_MIXER_MODE
#error "Invalid DACL MIXER MODE"
#endif // CFG_DACL_MIXER_MODE

#if defined(CFG_DACR_MIXER_MODE) && (CFG_DACR_MIXER_MODE <= 4)
#define PLF_DACR_MIXER_MODE          CFG_DACR_MIXER_MODE
#else // CFG_DACR_MIXER_MODE
#error "Invalid DACR MIXER MODE"
#endif // CFG_DACR_MIXER_MODE

/*
 * DEBUG configuration
 ****************************************************************************************
 */
#if defined(CFG_DBG)
#define PLF_DEBUG           1
#else //CFG_DBG
#define PLF_DEBUG           0
#endif //CFG_DBG

/*
 * CONSOLE
 ****************************************************************************************
 */
#ifdef CFG_CONSOLE
#define PLF_CONSOLE         1
#else // CFG_CONSOLE
#define PLF_CONSOLE         0
#endif // CFG_CONSOLE

/*
 * Letter Shell
 ****************************************************************************************
 */
#ifdef CFG_LETTER_SHELL
#define PLF_LETTER_SHELL    1
#else // CFG_LETTER_SHELL
#define PLF_LETTER_SHELL    0
#endif // CFG_LETTER_SHELL

/*
 * Test Case
 ****************************************************************************************
 */
#ifdef CFG_TEST
#define PLF_TEST            1
#else // CFG_TEST
#define PLF_TEST            0
#endif // CFG_TEST

/*
 * Wi-Fi Stack
 ****************************************************************************************
 */
#ifdef CFG_WIFI_STACK
#define PLF_WIFI_STACK      1
#else // CFG_WIFI_STACK
#define PLF_WIFI_STACK      0
#endif // CFG_WIFI_STACK

/*
 * 5G Band
 ****************************************************************************************
 */
#ifdef CFG_BAND5G
#define PLF_BAND5G          1
#else // CFG_BAND5G
#define PLF_BAND5G          0
#endif // CFG_BAND5G

/*
 * Wi-Fi RSSI of data packet
 ****************************************************************************************
 */

#ifdef CFG_RSSI_DATAPKT
#define PLF_RSSI_DATAPKT    1
#else // CFG_RSSI_DATAPKT
#define PLF_RSSI_DATAPKT    0
#endif // CFG_RSSI_DATAPKT

/*
 * Lwip SNTP
 ****************************************************************************************
 */
#ifdef CFG_SNTP
#define PLF_SNTP            1
#else // CFG_SNTP
#define PLF_SNTP            0
#endif // CFG_SNTP

/*
 * Fhost ping
 ****************************************************************************************
 */
#ifdef CFG_PING
#define PLF_PING            1
#else // CFG_PING
#define PLF_PING            0
#endif // CFG_PING

/*
 * Fhost iperf
 ****************************************************************************************
 */
#ifdef CFG_IPERF
#define PLF_IPERF           1
#else // CFG_IPERF
#define PLF_IPERF           0
#endif // CFG_IPERF

/*
 * BT Stack
 ****************************************************************************************
 */
#ifdef CFG_BT_STACK
#define PLF_BT_STACK        1
#else // CFG_BT_STACK
#define PLF_BT_STACK        0
#endif // CFG_BT_STACK

/*
 * BLE Stack
 ****************************************************************************************
 */
#ifdef CFG_BLE_STACK
#define PLF_BLE_STACK       1
#else // CFG_BLE_STACK
#define PLF_BLE_STACK       0
#endif // CFG_BLE_STACK

/*
 * BLE Stack only, not support br task
 ****************************************************************************************
 */
#ifdef CFG_BLE_ONLY
#define PLF_BLE_ONLY       1
#else // CFG_BLE_ONLY
#define PLF_BLE_ONLY       0
#endif // CFG_BLE_ONLY

/*
 * BTDM bt/ble combo
 ****************************************************************************************
 */
#ifdef CFG_BTDM
#define PLF_BTDM            1
#else // CFG_BTDM
#define PLF_BTDM            0
#endif // CFG_BTDM

/*
 * BT Customer
 ****************************************************************************************
 */
#ifdef CFG_BT_USER
#define PLF_BT_USER     1
#else // CFG_BT_USER
#define PLF_BT_USER     0
#endif // CFG_BT_USER

/*
 * BT Ota box
 ****************************************************************************************
 */
#ifdef CFG_BT_OTA
#define PLF_BT_OTA     1
#else // CFG_BT_OTA
#define PLF_BT_OTA     0
#endif // CFG_BT_OTA

/*
 * USB_BT
 ****************************************************************************************
 */
#ifdef CFG_USB_BT
#define PLF_USB_BT     1
#else // CFG_USB_BT
#define PLF_USB_BT     0
#endif // CFG_USB_BT

/*
 * LED support
 ****************************************************************************************
 */
#ifdef CFG_LED_MODULE
#define PLF_LED_MODULE     1
#else // CFG_LED_MODULE
#define PLF_LED_MODULE     0
#endif // CFG_LED_MODULE

/*
 * KEY support
 ****************************************************************************************
 */
#ifdef CFG_KEY_MODULE
#define PLF_KEY_MODULE     1
#else // CFG_LED_MODULE
#define PLF_KEY_MODULE     0
#endif // CFG_LED_MODULE

/*
 * LS support
 ****************************************************************************************
 */
#ifdef CFG_LIGHT_SENSOR
#define PLF_LS_MODULE      1
#else // CFG_LIGHT_SENSOR
#define PLF_LS_MODULE      0
#endif // CFG_LIGHT_SENSOR

/*
 * I2CM_SFT support
 ****************************************************************************************
 */
#ifdef CFG_I2CM_SFT
#define PLF_I2CM_SFT      1
#else // CFG_I2CM_SFT
#define PLF_I2CM_SFT      0
#endif // CFG_I2CM_SFT

/*
 * AON Support
 ****************************************************************************************
 */
#ifdef CFG_AON
#define PLF_AON_SUPPORT     1
#else // CFG_AON
#define PLF_AON_SUPPORT     0
#endif // CFG_AON

/*
 * HFP AG Support
 ****************************************************************************************
 */
#ifdef CFG_HFP_AG_SUPPORT
#define PLF_HFG_SUPPORT     1
#else // CFG_HFP_AG_SUPPORT
#define PLF_HFG_SUPPORT     0
#endif // CFG_HFP_AG_SUPPORT

/*
 * AIC_VENDOR_ADV Support
 ****************************************************************************************
 */
#ifdef CFG_AIC_VENDOR_ADV
#define PLF_AIC_VENDOR_ADV     1
#else // CFG_AIC_VENDOR_ADV
#define PLF_AIC_VENDOR_ADV     0
#endif // CFG_AIC_VENDOR_ADV
/*
 * Audio
 ****************************************************************************************
 */
#ifdef CFG_AUD_USED
#define PLF_AUD_USED        1
#else
#define PLF_AUD_USED        0
#endif

#ifdef CFG_ASIO
#define PLF_ASIO            1
#else // CFG_ASIO
#define PLF_ASIO            0
#endif // CFG_ASIO

#ifdef CFG_AUDIO
#define PLF_AUDIO           1
#else // CFG_AUDIO
#define PLF_AUDIO           0
#endif // CFG_AUDIO

#ifdef CFG_BT_AUDIO
#define PLF_BT_AUDIO        1
#else // CFG_BT_AUDIO
#define PLF_BT_AUDIO        0
#endif // CFG_BT_AUDIO

#ifdef CFG_BT_PROMPT
#define PLF_BT_PROMPT       1
#else // CFG_BT_PROMPT
#define PLF_BT_PROMPT       0
#endif // CFG_BT_PROMPT

#ifdef CFG_WIFI_AUDIO
#define PLF_WIFI_AUDIO        1
#else // CFG_WIFI_AUDIO
#define PLF_WIFI_AUDIO        0
#endif // CFG_WIFI_AUDIO

#if defined(CFG_AIC1000_MIC_MATRIX) && (CFG_AIC1000_MIC_MATRIX < 6)
#define PLF_AIC1000_MIC_MATRIX    CFG_AIC1000_MIC_MATRIX
#else // CFG_AIC1000_MIC_MATRIX
#error "Invalid AIC1000 MIC MATRIX"
#endif // CFG_AIC1000_MIC_MATRIX

#ifdef CFG_EXT_AIC1000
#define PLF_EXT_AIC1000        1
#else // CFG_EXT_AIC1000
#define PLF_EXT_AIC1000        0
#endif // CFG_EXT_AIC1000

/*
 * PMIC is valid or not
 ****************************************************************************************
 */
#ifdef CFG_PMIC
#define PLF_PMIC            1
#else // CFG_PMIC
#define PLF_PMIC            0
#endif // CFG_PMIC

/*
 * PMIC version
 ****************************************************************************************
 */
#ifdef CFG_PMIC_VER_FULL
#define PLF_PMIC_VER_FULL   1
#define PLF_PMIC_VER_LITE   0
#define PLF_PMIC_VER_AUD    0
#elif defined(CFG_PMIC_VER_LITE)
#define PLF_PMIC_VER_FULL   0
#define PLF_PMIC_VER_LITE   1
#define PLF_PMIC_VER_AUD    0
#else
#define PLF_PMIC_VER_FULL   0
#define PLF_PMIC_VER_LITE   0
#define PLF_PMIC_VER_AUD    1
#endif

/*
 * PMIC interface
 ****************************************************************************************
 */
#ifdef CFG_PMIC_ITF_ASDMA
#define PLF_PMIC_ITF_ASDMA  1
#define PLF_PMIC_ITF_PSIM   0
#else // CFG_PMIC_ITF_ASDMA
#define PLF_PMIC_ITF_ASDMA  0
#define PLF_PMIC_ITF_PSIM   1
#endif // CFG_PMIC_ITF_ASDMA

/*
 * PMIC option: Low power mode enable
 ****************************************************************************************
 */
#ifdef CFG_PMIC_LP
#define PLF_PMIC_LP         1
#else // CFG_PMIC_LP
#define PLF_PMIC_LP         0
#endif // CFG_PMIC_LP

/*
 * PMIC option: use ldo/dcdc vcore09 or not
 ****************************************************************************************
 */
#ifdef CFG_PMIC_LDO_VCORE
#define PLF_PMIC_LDO_VCORE  1
#define PLF_PMIC_DCDC_VCORE 0
#define PLF_PMIC_ALL_VCORE  0
#elif defined(CFG_PMIC_DCDC_VCORE)
#define PLF_PMIC_LDO_VCORE  0
#define PLF_PMIC_DCDC_VCORE 1
#define PLF_PMIC_ALL_VCORE  0
#else
#define PLF_PMIC_LDO_VCORE  0
#define PLF_PMIC_DCDC_VCORE 0
#define PLF_PMIC_ALL_VCORE  1
#endif

/*
 * PMIC option: Vcore calibration
 ****************************************************************************************
 */
#ifdef CFG_VCORE_CALIB
#define PLF_VCORE_CALIB     1
#else // CFG_VCORE_CALIB
#define PLF_VCORE_CALIB     0
#endif // CFG_VCORE_CALIB

/*
 * PMIC option: Low power 128k derived from lpo 512k
 ****************************************************************************************
 */
#ifdef CFG_LPO_512K
#define PLF_LPO_512K        1
#else // PLF_LPO_512K
#define PLF_LPO_512K        0
#endif // PLF_LPO_512K

/*
 * PMIC option: Generate I2S MCLK
 ****************************************************************************************
 */
#ifdef CFG_PMIC_MCLK
#define PLF_PMIC_MCLK   1
#else // CFG_PMIC_MCLK
#define PLF_PMIC_MCLK   0
#endif // CFG_PMIC_MCLK

/*
 * PMIC option: voltage drop
 ****************************************************************************************
 */
#ifdef CFG_DCDC_CORE_DROP
#define PLF_DCDC_CORE_DROP   1
#else // CFG_DCDC_CORE_DROP
#define PLF_DCDC_CORE_DROP   0
#endif // CFG_DCDC_CORE_DROP

#ifdef CFG_DCDC_RF_DROP
#define PLF_DCDC_RF_DROP   1
#else // CFG_DCDC_RF_DROP
#define PLF_DCDC_RF_DROP   0
#endif // CFG_DCDC_RF_DROP

#ifdef CFG_LDO_VCORE09_DROP
#define PLF_LDO_VCORE09_DROP   1
#else // CFG_LDO_VCORE09_DROP
#define PLF_LDO_VCORE09_DROP   0
#endif // CFG_LDO_VCORE09_DROP

#ifdef CFG_LDO_VRTC09_DROP
#define PLF_LDO_VRTC09_DROP   1
#else // CFG_LDO_VRTC09_DROP
#define PLF_LDO_VRTC09_DROP   0
#endif // CFG_LDO_VRTC09_DROP

/*
 * Low power code in RAM
 ****************************************************************************************
 */
#ifdef CFG_LPIRAM
#define PLF_LPIRAM          1
#else // CFG_LPIRAM
#define PLF_LPIRAM          0
#endif // CFG_LPIRAM

/*
 * GSENSOR
 ****************************************************************************************
 */
#ifdef CFG_GSENSOR
#define PLF_GSENSOR         1
#else  // CFG_GSENSOR
#define PLF_GSENSOR         0
#endif // CFG_GSENSOR

/*
 * FATFS
 ****************************************************************************************
 */
#ifdef CFG_FATFS
#define PLF_FATFS           1
#else  // CFG_FATFS
#define PLF_FATFS           0
#endif // CFG_FATFS

/*
 * DSP
 ****************************************************************************************
 */
#ifdef CFG_DSP
#define PLF_DSP           1
#else  // CFG_DSP
#define PLF_DSP           0
#endif // CFG_DSP

/*
 * FUNCTION DECLARATIONS
 ****************************************************************************************
 */


/// @} PLF

#endif // _PLF_H_
