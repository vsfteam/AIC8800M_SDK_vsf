#ifndef _CODEC_TLV320AIC32_H_
#define _CODEC_TLV320AIC32_H_

#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint32_t samp_rate;
    uint8_t bits;
    uint8_t ch_num;
    bool codec_master;
} tlv320aic32_cfg_t;

void tlv320aic32_i2c_init(void);
void tlv320aic32_reg_wr(unsigned char waddr,unsigned char wdata);
unsigned char tlv320aic32_reg_rd(unsigned char raddr);
void tlv320aic32_reset(void);
void tlv320aic32_init(void);
void tlv320aic32_config(tlv320aic32_cfg_t *cfg);
void tlv320aic32_deinit(void);

#endif /* _CODEC_TLV320AIC32_H_ */
