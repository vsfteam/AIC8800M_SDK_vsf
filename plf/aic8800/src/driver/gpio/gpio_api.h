#ifndef _GPIO_API_H_
#define _GPIO_API_H_

#include <stdint.h>
#include "plf.h"

#define GPIOA_IDX_MAX   (16)
#define GPIOB_IDX_MAX   (16)

#define GPIOIRQ_CB_PARAM(idx,evt)   (((idx) << 16) | evt)
#define GPIOIRQ_CB_EVENT(param)     ((param) & 0xFFFF)
#define GPIOIRQ_CB_INDEX(param)     ((param) >> 16)

enum {
    GPIODIR_INPUT = 0,
    GPIODIR_OUTPUT
};

enum {
    GPIOVAL_LOW = 0,
    GPIOVAL_HIGH
};

enum {
    GPIOIRQ_TYPE_EDGE_RISE = 0,
    GPIOIRQ_TYPE_EDGE_FALL,
    GPIOIRQ_TYPE_EDGE_BOTH
};

enum {
    GPIOIRQ_EVENT_EDGE_RISE = 0,
    GPIOIRQ_EVENT_EDGE_FALL,
    GPIOIRQ_EVENT_EDGE_BOTH
};

typedef void (*gpio_irq_handler_t)(int event);

// Simple APIs
void gpio_init  (int gpidx);
void gpio_deinit(int gpidx);
void gpio_dir_in(int gpidx);
void gpio_dir_out(int gpidx);
void gpio_set   (int gpidx);
void gpio_clr   (int gpidx);
int  gpio_get   (int gpidx);
void gpio_force_pull_up_enable(int gpidx);
void gpio_force_pull_dn_enable(int gpidx);
void gpio_force_pull_none_enable(int gpidx);
void gpio_force_pull_up_dn_disable(int gpidx);
void gpio_irq_en_set(int gpidx, int enable);
void gpio_irq_init(int gpidx, int type, gpio_irq_handler_t handler);

#if PLF_PMIC
void gpiob_init  (int gpidx);
void gpiob_deinit(int gpidx);
void gpiob_dir_in(int gpidx);
void gpiob_dir_out(int gpidx);
void gpiob_set   (int gpidx);
void gpiob_clr   (int gpidx);
int  gpiob_get   (int gpidx);
void gpiob_force_pull_up_enable(int gpidx);
void gpiob_force_pull_dn_enable(int gpidx);
void gpiob_force_pull_none_enable(int gpidx);
void gpiob_force_pull_up_dn_disable(int gpidx);
void pmic_clock_set_for_gpiob(void);
void GPIOB_IRQHandler(void);
void gpiob_irq_history_set(uint32_t gpidx_bit);
void gpiob_irq_history_clear(uint32_t gpidx_bit);
uint32_t gpiob_irq_history_get(void);
void gpiob_irq_init(int gpidx, int type, gpio_irq_handler_t handler, int filter);
#endif

#endif /* _GPIO_API_H_ */
