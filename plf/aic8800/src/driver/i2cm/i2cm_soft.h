#ifndef _I2CM_SOFT_H_
#define _I2CM_SOFT_H_

#include "pinname.h"

typedef enum {
    I2C = 0,
    SCCB,
}IIC_type;

void i2cm_soft_write_reg(uint8_t dev_add, uint8_t reg, uint8_t dat);

uint8_t i2cm_soft_read_reg(uint8_t dev_add, uint8_t reg, IIC_type type);

void i2cm_soft_read_regs(uint8_t dev_add, uint8_t reg, uint8_t *dat_add, uint8_t num, IIC_type type);

void i2cm_soft_init(int scl_pin_name, int sda_pin_name);

#endif /*_I2CM_SOFT_H_*/
