#include <stdint.h>
#include <stdbool.h>
#include "plf.h"
#include "audio_types.h"
#include "audio_config.h"

uint16_t audio_config_tlv320aic32_reset_pin_get(void)
{
    return AUDIO_CFG_TLV320AIC32_RESET_PIN;
}

uint16_t audio_config_ext_aic1000_reset_pin_get(void)
{
    return AUDIO_CFG_EXT_AIC1000_RESET_PIN;
}

uint16_t audio_config_ext_aic1000_scl_pin_get(void)
{
    return AUDIO_CFG_EXT_AIC1000_SCL_PIN;
}

uint16_t audio_config_ext_aic1000_sda_pin_get(void)
{
    return AUDIO_CFG_EXT_AIC1000_SDA_PIN;
}

uint8_t audio_config_ext_aic1000_i2s_idx_get(void)
{
    return AUDIO_CFG_EXT_AIC1000_I2S_IDX;
}

uint8_t audio_config_device_get(void)
{
    return AUDIO_CFG_DEVICE;
}

