#ifndef _CO_MAIN_H_
#define _CO_MAIN_H_

#include <stdbool.h>
#include "co_list.h"
#include "co_message.h"
#include "pinname.h"

#define CO_EVT_MAX     (30)
#define CO_TIMER_ALLOW_MIN_SLEEP_DURATION 100 //ms
#define CO_MAIN_AUTO_POWER_DOWEN             0

typedef enum {
    CO_TIMER_LP_LEVEL_ACTIVE     = 0,
    CO_TIMER_LP_LEVEL_HIBERNATE,
}CO_TIMER_LP_LEVEL;

typedef enum {
    CO_MODUAL_KEY = 0,
    CO_MODUAL_TIMER,
    CO_MODUAL_LED,
    CO_MODUAL_LIGHT_SENSOR,
    CO_MODUAL_NUM
} CO_MODUAL_ID_T;

typedef struct {
    uint32_t EvtId;
    uint32_t Param;
} CO_EVENT;

typedef struct {
    uint32_t mod_id;
    CO_EVENT mod_evt;
}CO_MODUAL_EVENT;


typedef struct _co_timer_ co_timer;

typedef void (*co_timer_callback)(void*);

typedef struct _co_timer_
{
    struct co_list_hdr node;
    co_timer_callback  cb;
    void*              cb_param;
    uint32_t           time_duration;
    uint32_t           time_start;
    uint32_t           timer_addr;
    uint32_t           is_period;
}co_timer;

typedef bool (*CO_EVT_HANDLER_T)(CO_EVENT *);

typedef int (*co_main_batt_reg_cb_t)(uint32_t vaule);

void co_main_batt_register_cb(co_main_batt_reg_cb_t callback);

void co_main_init(void);

int co_main_evt_handler_rigister(CO_MODUAL_ID_T mod_id, CO_EVT_HANDLER_T handler);

int co_event_send(CO_MODUAL_EVENT *msg_src, bool isr);

int co_event_get(CO_MODUAL_EVENT* msg_p);
/**
 ****************************************************************************************
 * @brief * co_timer_start : co_timer which will be run in DEEP SLEEP POWER DOWEN state .
 *
 * @param[]  timer     : the address of timer handler pointer,used for restore the timer handler pointer after power up from AON.
 *           duration  : duration likes xTicksToWait Specifies the time, in ticks . eg : now ticks step is 1ms,so unit of duration is 1ms.
 *           cb_param  : paramter pointer of co_timer_callback.
 *           cb        : co_timer_callback.
 *           is_period : periodic or not.
 ****************************************************************************************
 */
void co_timer_start(co_timer **timer, uint32_t duration, void *cb_param, co_timer_callback cb, uint32_t is_period);
/**
 ****************************************************************************************
 * @brief * co_timer_stop : cancel and delete co_timer .
 *
 * @param :  timer     : timer handler pointer.
 *
 ****************************************************************************************
 */
void co_timer_stop(co_timer *timer);
#if PLF_AON_SUPPORT
void co_timer_save(void);

void co_timer_restore(void);
#endif
uint32_t get_co_main_timer_min_duration(void);
#endif
