#include <stdint.h>
#include <stdbool.h>
#include "reg_iomux.h"
#include "reg_gpio.h"
#include "gpio_api.h"
#include "audio_config.h"
#include "dbg.h"
#include "dbg_assert.h"

static bool psi_inited = false;
static PinName scl_pin;
static PinName sda_pin;

__STATIC_INLINE void psi_op_delay(unsigned int delay_num)
{
    unsigned int i;
    for (i=0; i<delay_num; i++) {
        __NOP();
    }
}

void psi_io_init(void)
{
    scl_pin = audio_config_ext_aic1000_scl_pin_get();
    sda_pin = audio_config_ext_aic1000_sda_pin_get();

    uint8_t scl_pin_type = PIN_TYPE(scl_pin);
    uint8_t sda_pin_type = PIN_TYPE(sda_pin);
    uint8_t scl_pin_idx = PIN_IDX(scl_pin);
    uint8_t sda_pin_idx = PIN_IDX(sda_pin);
    ASSERT_ERR(((scl_pin_type == PIN_TYPE_A) || (scl_pin_type == PIN_TYPE_B)) && ((sda_pin_type == PIN_TYPE_A) || (sda_pin_type == PIN_TYPE_B)));

    if (scl_pin_type == PIN_TYPE_A) {
        gpio_init(scl_pin_idx);
    } else {
        gpiob_init(scl_pin_idx);
    }
    if (sda_pin_type == PIN_TYPE_A) {
        gpio_init(sda_pin_idx);
    } else {
        gpiob_init(sda_pin_idx);
    }

    psi_inited = true;
}

__STATIC_INLINE void psi_io_output(PinName pin)
{
    uint8_t pin_type = PIN_TYPE(pin);
    uint8_t pin_idx = PIN_IDX(pin);

    if (pin_type == PIN_TYPE_A) {
        gpio_dir_out(pin_idx);
    } else {
        gpiob_dir_out(pin_idx);
    }
}

__STATIC_INLINE void psi_io_input(PinName pin)
{
    uint8_t pin_type = PIN_TYPE(pin);
    uint8_t pin_idx = PIN_IDX(pin);

    if (pin_type == PIN_TYPE_A) {
        gpio_dir_in(pin_idx);
    } else {
        gpiob_dir_in(pin_idx);
    }
}

__STATIC_INLINE void psi_io_set_low(PinName pin)
{
    uint8_t pin_type = PIN_TYPE(pin);
    uint8_t pin_idx = PIN_IDX(pin);

    if (pin_type == PIN_TYPE_A) {
        gpio_clr(pin_idx);
    } else {
        gpiob_clr(pin_idx);
    }
}

__STATIC_INLINE unsigned char psi_io_get(PinName pin)
{
    unsigned char psi_io_data;
    uint8_t pin_type = PIN_TYPE(pin);
    uint8_t pin_idx = PIN_IDX(pin);

    if (pin_type == PIN_TYPE_A) {
        psi_io_data = gpio_get(pin_idx);
    } else {
        psi_io_data = gpiob_get(pin_idx);
    }

    return psi_io_data;
}

__STATIC_INLINE void psi_io_set_high(PinName pin)
{
    uint8_t pin_type = PIN_TYPE(pin);
    uint8_t pin_idx = PIN_IDX(pin);

    if (pin_type == PIN_TYPE_A) {
        gpio_set(pin_idx);
    } else {
        gpiob_set(pin_idx);
    }
}

__STATIC_INLINE void psi_write_header(void)
{
    psi_io_set_low(scl_pin);                // SCL=0
    psi_io_set_low(sda_pin);                // SDA=0
    unsigned char psi_header = 0x2;
    unsigned char i= 3;
    while (i--) {
        psi_op_delay(1);
        psi_io_set_high(scl_pin);            // SCL=1
        psi_op_delay(1);
        psi_io_set_low(scl_pin);            // SCL=0
    }
    i= 3;
    while (i--) {
        if(psi_header & (1<<2))                    // MSB(i2c_buff)==1
            psi_io_set_high(sda_pin);        // SDA=1
        else
            psi_io_set_low(sda_pin);        // SDA=0
        psi_op_delay(1);
        psi_io_set_high(scl_pin);            // SCL=1
        psi_op_delay(1);
        psi_io_set_low(scl_pin);            // SCL=0
        psi_header = psi_header<<1;    // move to the next MSB(from MSB to LEB)
    }
}

__STATIC_INLINE void psi_write_addr(unsigned int waddr,unsigned char rdwr)
{
    psi_io_set_low(scl_pin);    // SCL=0
    psi_io_set_low(sda_pin);                // SDA=0
    unsigned int psi_waddr_buff = (waddr>>1) | rdwr;
    unsigned char i= 30+1;
    while (i--) {
        if(psi_waddr_buff & (0x1<<30))                    // MSB(i2c_buff)==1
            psi_io_set_high(sda_pin);        // SDA=1
        else
            psi_io_set_low(sda_pin);        // SDA=0
        psi_op_delay(1);
        psi_io_set_high(scl_pin);            // SCL=1
        psi_op_delay(1);
        psi_io_set_low(scl_pin);            // SCL=0
        psi_waddr_buff = psi_waddr_buff<<1;    // move to the next MSB(from MSB to LEB)
    }
}

__STATIC_INLINE void psi_write_data(unsigned int wdata)
{
    psi_io_set_low(scl_pin);                // SCL=0
    psi_io_set_low(sda_pin);                // SDA=0
    unsigned int psi_wdata_buff = wdata;
    unsigned char i= 32;
    while (i--) {
        if(psi_wdata_buff & (0x1<<31))    // MSB(i2c_buff)==1
            psi_io_set_high(sda_pin);    // SDA=1
        else
            psi_io_set_low(sda_pin);    // SDA=0
        psi_op_delay(1);
        psi_io_set_high(scl_pin);    // SCL=1
        psi_op_delay(1);
        psi_io_set_low(scl_pin);    // SCL=0
        psi_wdata_buff = psi_wdata_buff<<1;    // move to the next MSB(from MSB to LEB)
    }
}

__STATIC_INLINE unsigned int psi_read_data(void)
{
    psi_io_set_low(scl_pin);    // SCL=0
    unsigned int psi_rdata_buff = 0x0;
    unsigned char i= 32;
    uint8_t loop_cnt = 0;
    psi_op_delay(1);
    psi_io_set_high(scl_pin);    // SCL=1
    psi_op_delay(1);
    psi_io_set_low(scl_pin);    // SCL=1
    while (psi_io_get(sda_pin)!= 0x1) { ///1
        psi_op_delay(1);
        psi_io_set_high(scl_pin);    // SCL=1
        psi_op_delay(1);
        psi_io_set_low(scl_pin);    // SCL=1
        loop_cnt++;
        if (loop_cnt >= 10) {
            dbg("read timeout\n");
            loop_cnt = 0;
            break;
        }
    }
    while (psi_io_get(sda_pin)!=0x0) { ///0
        psi_op_delay(1);
        psi_io_set_high(scl_pin);    // SCL=1
        psi_op_delay(1);
        psi_io_set_low(scl_pin);    // SCL=1
        loop_cnt++;
        if (loop_cnt >= 10) {
            dbg("read timeout\n");
            loop_cnt = 0;
            break;
        }
    }
    while (psi_io_get(sda_pin)!=0x1) { ///1
        psi_op_delay(1);
        psi_io_set_high(scl_pin);    // SCL=1
        psi_op_delay(1);
        psi_io_set_low(scl_pin);    // SCL=1
        loop_cnt++;
        if (loop_cnt >= 10) {
            dbg("read timeout\n");
            loop_cnt = 0;
            break;
        }
    }

    psi_op_delay(1);
    psi_io_set_high(scl_pin);    // SCL=1
    while (i--) {
        psi_op_delay(1);
        psi_io_set_low(scl_pin);    // SCL=0
        if(psi_io_get(sda_pin)==0x1)
            psi_rdata_buff |= 0x1<<i;
        else
            psi_rdata_buff  = psi_rdata_buff;
        psi_op_delay(1);
        psi_io_set_high(scl_pin);    // SCL=1
    }
    psi_op_delay(1);
    psi_io_set_low(scl_pin);    // SCL=0
    return  psi_rdata_buff;
}

__STATIC_INLINE void psi_write_dummy(void)
{
    psi_io_set_low(scl_pin);    // SCL=0
    psi_io_set_low(sda_pin);    // SDA=0
    unsigned char i= 4;
    while (i--) {
        psi_io_set_low(sda_pin);    // SDA=0
        psi_op_delay(1);
        psi_io_set_high(scl_pin);    // SCL=1
        psi_op_delay(1);
        psi_io_set_low(scl_pin);    // SCL=0
    }
}

void psi_write_op(unsigned int waddr,unsigned int wdata)
{
    if (psi_inited == false) {
        psi_io_init();
    }

    psi_io_output(scl_pin);
    psi_io_output(sda_pin);
    psi_write_header();
    psi_write_addr(waddr,0x0);
    psi_write_data(wdata);
    psi_write_dummy();
    psi_op_delay(10);
}

unsigned int psi_read_op(unsigned int raddr)
{
    if (psi_inited == false) {
        psi_io_init();
    }

    unsigned int rdata;
    psi_io_output(scl_pin);
    psi_io_output(sda_pin);
    psi_write_header();
    psi_write_addr(raddr,0x1);
    psi_io_input(sda_pin);
    rdata = psi_read_data();
    psi_io_output(sda_pin);
    psi_write_dummy();
    psi_op_delay(10);

    return rdata;
}

void psi_mask_write_op(unsigned int waddr,unsigned int wdata,unsigned int mask)
{
    unsigned int rdata;
    rdata = psi_read_op(waddr);
    wdata = (wdata & mask) | (rdata & ~mask);
    psi_write_op(waddr, wdata);
}

