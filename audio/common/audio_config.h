#ifndef _AUDIO_CONFIG_H_
#define _AUDIO_CONFIG_H_

#include <stdint.h>
#include <stdbool.h>
#include "plf.h"
#include "pinname.h"

#if PLF_PMIC_VER_AUD
#define AUDIO_CFG_DEVICE                    AUD_DEVICE_INT_AIC1000
#elif PLF_EXT_AIC1000
#define AUDIO_CFG_DEVICE                    AUD_DEVICE_EXT_AIC1000

#define AUDIO_CFG_EXT_AIC1000_RESET_PIN     PB_5
#define AUDIO_CFG_EXT_AIC1000_SCL_PIN       PB_4
#define AUDIO_CFG_EXT_AIC1000_SDA_PIN       PB_13

#define AUDIO_CFG_EXT_AIC1000_I2S_IDX       0
#else
#if (CFG_CODEC_BOARD_VER == 0)
// 0 indicates no codec, user can also modify it, but remember TLV320AIC32_UESD must be 0 if codec is not tlv320aic32
#define AUDIO_CFG_DEVICE                    AUD_DEVICE_NONE
#elif (CFG_CODEC_BOARD_VER == 1)
#define AUDIO_CFG_DEVICE                    AUD_DEVICE_EXT_CODEC_I2S0

#define AUDIO_CFG_TLV320AIC32_RESET_PIN     PA_14
#define AUDIO_CFG_TLV320AIC32_UESD          1
#elif (CFG_CODEC_BOARD_VER == 2)
#define AUDIO_CFG_DEVICE                    AUD_DEVICE_EXT_CODEC_I2S1

#define AUDIO_CFG_TLV320AIC32_RESET_PIN     PA_13
#define AUDIO_CFG_TLV320AIC32_UESD          1
#else
#error "Invalid CODEC_BOARD_VER"
#endif
#endif

#ifndef AUDIO_CFG_TLV320AIC32_UESD
#define AUDIO_CFG_TLV320AIC32_UESD          0
#endif

#ifndef AUDIO_CFG_TLV320AIC32_RESET_PIN
#define AUDIO_CFG_TLV320AIC32_RESET_PIN     PIN_NC
#endif

#ifndef AUDIO_CFG_EXT_AIC1000_RESET_PIN
#define AUDIO_CFG_EXT_AIC1000_RESET_PIN     PIN_NC
#endif

#ifndef AUDIO_CFG_EXT_AIC1000_SCL_PIN
#define AUDIO_CFG_EXT_AIC1000_SCL_PIN       PIN_NC
#endif

#ifndef AUDIO_CFG_EXT_AIC1000_SDA_PIN
#define AUDIO_CFG_EXT_AIC1000_SDA_PIN       PIN_NC
#endif

#ifndef AUDIO_CFG_EXT_AIC1000_I2S_IDX
#define AUDIO_CFG_EXT_AIC1000_I2S_IDX       0xFF
#endif

uint16_t audio_config_tlv320aic32_reset_pin_get(void);
uint16_t audio_config_ext_aic1000_reset_pin_get(void);
uint16_t audio_config_ext_aic1000_scl_pin_get(void);
uint16_t audio_config_ext_aic1000_sda_pin_get(void);
uint8_t audio_config_ext_aic1000_i2s_idx_get(void);
uint8_t audio_config_device_get(void);

#endif
