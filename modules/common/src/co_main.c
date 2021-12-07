/**
 ****************************************************************************************
 *
 * @file app_main.c
 *
 ****************************************************************************************
 */

/**
 ****************************************************************************************
 * @addtogroup APP_MAIN
 * @{
 ****************************************************************************************
 */
/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include <stdlib.h>
#include <string.h>
#include "rtos.h"
#include "dbg_assert.h"
#include "co_main.h"
#include "sleep_api.h"
#include "reg_sysctrl.h"
#include "sysctrl_api.h"
#include "gpadc_api.h"
#include "pwrkey_api.h"

#define COTIMER_DEBUG_PRINTF(fmt, ...)       //dbg(fmt, ##__VA_ARGS__)
#define MAX_LOCAL_BATT_VAULE                 4200//mV
#define MIN_LOCAL_BATT_VAULE                 3300//mV
#define CO_BATT_CHECK_TIME_IN_ACTIVE         10000//10s
#define CO_BATT_CHECK_TIME_IN_SLEEP          30000//30s
#define CO_BATT_REG_CALLBACK_NUM             4

#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif /* max */

#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif /* min */


static TimerHandle_t co_main_timer = NULL;
static struct co_list co_main_time_list;
static rtos_task_handle co_main_task_handle = NULL;
static rtos_queue co_main_evt_queue = NULL;
static CO_EVT_HANDLER_T evt_handler[CO_MODUAL_NUM] = {NULL,};
#if CO_MAIN_AUTO_POWER_DOWEN
static co_timer *co_batt_check_timer = NULL;
static co_main_batt_reg_cb_t co_batt_reg_cb[CO_BATT_REG_CALLBACK_NUM] = {NULL,};
static uint8_t co_batt_reg_cb_num = 0;
#endif
int co_event_send(CO_MODUAL_EVENT *msg_src, bool isr)
{
    int res = 0;
    if(!co_main_evt_queue)
        return 1;
    res = rtos_queue_write(co_main_evt_queue, msg_src, 0, isr);
    if (res) {
        return -1;
    }
    return 0;
}

int co_event_get(CO_MODUAL_EVENT* msg_p)
{
    int res = rtos_queue_read(co_main_evt_queue, msg_p, -1, false);
    if (res) {
        return -1;
    }
    return 0;
}

static RTOS_TASK_FCT(co_main_task)
{
    if (pwrctrl_pwrmd_cpusys_sw_record_getf() >= CPU_SYS_POWER_DOWN) {
        #if PLF_AON_SUPPORT
        co_timer_restore();
        #endif
    }
    while (1) {
        CO_MODUAL_EVENT msg;
        int res = co_event_get(&msg);
        if (res == 0) {
            if(msg.mod_id < CO_MODUAL_NUM){
                if (evt_handler[msg.mod_id]){
                    evt_handler[msg.mod_id](&(msg.mod_evt));
                }
            }
        } else {
            dbg("co_main_task mbox get err\n");
        }
    }
}
/**
 ****************************************************************************************
 * @brief * basic timer function for  co_timer .Users don't have to pay attention to it
 ****************************************************************************************
 */
void co_main_timer_start(uint32_t t)
{
    rtos_timer_change_period(co_main_timer, t, 0);
}
/**
 ****************************************************************************************
 * @brief * basic timer function for  co_timer .Users don't have to pay attention to it
 ****************************************************************************************
 */
void co_main_timer_cancel(void)
{
    rtos_timer_stop(co_main_timer,0);
}
/**
 ****************************************************************************************
 * @brief * basic timer function for  co_timer .Users don't have to pay attention to it
 ****************************************************************************************
 */
static void co_main_timer_notify(void)
{
    CO_MODUAL_EVENT msg;
    int res = 0;
    msg.mod_id = CO_MODUAL_TIMER;
    res = co_event_send(&msg, false);
    ASSERT_ERR(res == 0 || res == 1);
}
/**
 ****************************************************************************************
 * @brief * basic timer function for  co_timer .Users don't have to pay attention to it
 ****************************************************************************************
 */
static void co_main_timer_cb( TimerHandle_t xTimer )
{
    co_main_timer_notify();
}
/**
 ****************************************************************************************
 * @brief * basic timer function for  co_timer .Users don't have to pay attention to it
 ****************************************************************************************
 */
static void co_main_timer_init(void)
{
    if (co_main_timer == NULL)
        co_main_timer = rtos_timer_create("co_main_timer",\
                        10000,pdFALSE,NULL,co_main_timer_cb);
    co_list_init(&co_main_time_list);
}
/**
 ****************************************************************************************
 * @brief * basic timer function for  co_timer .Users don't have to pay attention to it
 ****************************************************************************************
 */
static void co_timer_list_reset(void)
{
    uint16_t list_len = 0;
    uint32_t elapsed_time;
    uint32_t min_duration = (uint32_t)(-1);
    struct co_list_hdr *element = NULL;
    co_timer *current_timer;
    uint32_t time_now = rtos_now(false);

    list_len = co_list_size(&co_main_time_list);
    if(list_len){
        element = co_main_time_list.first;
        while(element != NULL){
            current_timer = (co_timer *)element;
            elapsed_time = time_now - current_timer->time_start;
            if(elapsed_time < current_timer->time_duration){
                min_duration = min(min_duration,(current_timer->time_duration - elapsed_time));
            }
            element = element->next;
        }
    }
    COTIMER_DEBUG_PRINTF("duration %d ,now 0x%x\n",min_duration,time_now);
    if(min_duration < (uint32_t)(-1)){
        co_main_timer_start(min_duration);
    }else{
        co_main_timer_cancel();
    }
}
/**
 ****************************************************************************************
 *           co_timer_start
 *
 * @brief * It is described by co_main.h
 *
 ****************************************************************************************
 */
void co_timer_start(co_timer **timer, uint32_t duration, void *cb_param, co_timer_callback cb, uint32_t is_period)
{
    co_timer *tmp_timer = NULL;
    uint16_t list_len = 0;
    uint8_t is_in_list = 0;
    if(timer == NULL || cb == NULL){
        COTIMER_DEBUG_PRINTF("co_timer error\n");
        ASSERT_ERR(0);
        return;
    }
    COTIMER_DEBUG_PRINTF("%s timer 0x%x\n",__func__,timer);
    list_len = co_list_size(&co_main_time_list);
    if(list_len){
        struct co_list_hdr *tmp_list_hdr = co_main_time_list.first;
        while(tmp_list_hdr != NULL){
            co_timer *_cur_timer = (co_timer *)tmp_list_hdr;
            COTIMER_DEBUG_PRINTF("%s timer 0x%x ,timer_addr 0x%x\n",__func__,_cur_timer,_cur_timer->timer_addr);
            if(_cur_timer->timer_addr == (uint32_t)timer){
                is_in_list = 1;
                COTIMER_DEBUG_PRINTF("%s timer is in list\n",__func__);
            }
            tmp_list_hdr = tmp_list_hdr->next;
        }
    }
    if(is_in_list == 0){
        tmp_timer = (co_timer *)rtos_malloc(sizeof(co_timer));
        COTIMER_DEBUG_PRINTF("%s tmp_timer alloc 0x%x,cb 0x%x\n",__func__,tmp_timer,cb);
        if(tmp_timer){
            *timer = tmp_timer;
            tmp_timer->cb = cb;
            tmp_timer->cb_param = cb_param;
            tmp_timer->timer_addr = (uint32_t)timer;
            tmp_timer->time_duration = duration;
            tmp_timer->time_start = rtos_now(false);
            tmp_timer->is_period = is_period;
        }else{
            COTIMER_DEBUG_PRINTF("co_timer malloc error\n");
            ASSERT_ERR(0);
            return;
        }
        co_list_push_back(&co_main_time_list,&tmp_timer->node);
    }
    co_timer_list_reset();
}
/**
 ****************************************************************************************
 *           co_timer_stop
 *
 * @brief * It is described by co_main.h
 *
 ****************************************************************************************
 */
void co_timer_stop(co_timer *timer)
{
    co_timer *current_timer;
    struct co_list_hdr *prev_element = NULL;
    struct co_list_hdr *element = NULL;
    uint16_t list_len = 0;
    if(timer == NULL ){
        COTIMER_DEBUG_PRINTF("co_timer stop error\n");
        ASSERT_ERR(0);
        return;
    }

    list_len = co_list_size(&co_main_time_list);
    if(list_len){
        element = co_main_time_list.first;
        while(element != NULL){
            current_timer = (co_timer *)element;
            if(current_timer == timer){
                co_list_remove(&co_main_time_list,prev_element,element);
                rtos_free(current_timer);
                COTIMER_DEBUG_PRINTF("%s tmp_timer free 0x%x\n",__func__,current_timer);
                co_timer_list_reset();
                break;
            }
            prev_element = element;
            element = element->next;
        }
    }
}
/**
 ****************************************************************************************
 * @brief * basic timer function for  co_timer .Users don't have to pay attention to it
 ****************************************************************************************
 */
static void co_timer_list_check(void)
{
    co_timer *current_timer;
    struct co_list_hdr *prev_element = NULL;
    struct co_list_hdr *element = NULL;
    uint16_t list_len = 0;
    uint8_t time_done = 0;
    uint32_t elapsed_time;
    uint32_t time_now = rtos_now(false);

    list_len = co_list_size(&co_main_time_list);
    if(list_len){
        element = co_main_time_list.first;
        COTIMER_DEBUG_PRINTF("%s 0x%x,0x%x\n",__func__,time_now,element);
        while(element != NULL){
            current_timer = (co_timer *)element;
            elapsed_time = time_now - current_timer->time_start;
            if(elapsed_time >= current_timer->time_duration){
                co_timer_callback cb = current_timer->cb;
                void* cb_param = current_timer->cb_param;
                COTIMER_DEBUG_PRINTF("%s tmp_timer free 0x%x ,cb 0x%x\n",__func__,current_timer,cb);
                if(current_timer->is_period){
                    current_timer->time_start = time_now;
                }else{
                    co_list_remove(&co_main_time_list,prev_element,element);
                    rtos_free(current_timer);
                }
                if(cb){
                    cb(cb_param);
                }
                time_done = 1;
                break;
            }
            prev_element = element;
            element = element->next;
        }
        if(time_done){
            co_main_timer_notify();
            co_timer_list_reset();
        }
    }
}
/**
 ****************************************************************************************
 * @brief * basic timer function for  co_timer .Users don't have to pay attention to it
 ****************************************************************************************
 */
static bool co_timer_handle_process(CO_EVENT *evt)
{
    co_timer_list_check();
    return true;
}

int co_main_evt_handler_rigister(CO_MODUAL_ID_T mod_id, CO_EVT_HANDLER_T handler)
{
    if (mod_id>=CO_MODUAL_NUM) {
        return -1;
    }
    evt_handler[mod_id] = handler;
    return 0;
}
#if CO_MAIN_AUTO_POWER_DOWEN
void co_main_batt_register_cb(co_main_batt_reg_cb_t callback)
{
    uint8_t ret = 0;
    for(uint8_t i = 0; i < CO_BATT_REG_CALLBACK_NUM; i++){
        if(co_batt_reg_cb[i] == NULL &&  callback){
            co_batt_reg_cb[i] = callback;
            co_batt_reg_cb_num++;
            ret = 1;
            break;
        }
    }
    if(ret == 0){
        TRACE("batt cb reg error!\n");
    }
}

static uint8_t co_main_batt_get_lvl(void)
{
    int volt_mv = 0;
    uint8_t batt_level = 0;// batt level will in 0~9,when value is 0 ,it will run power down process.

    volt_mv = gpadc_measure(GPADC_TYPE_VBAT);

    if(volt_mv < MIN_LOCAL_BATT_VAULE){
        return batt_level;
    }
    if(volt_mv >= MAX_LOCAL_BATT_VAULE){
        batt_level = 9;
        return batt_level;
    }
    batt_level = (uint8_t)(((volt_mv-MIN_LOCAL_BATT_VAULE)*10)/(MAX_LOCAL_BATT_VAULE-MIN_LOCAL_BATT_VAULE));
    return batt_level;
}

static void co_main_batt_check_timer(void *cb_param)
{
    uint8_t batt_level = 0;

    batt_level = co_main_batt_get_lvl();
    TRACE("batt_level = %x\n",batt_level);
    co_batt_check_timer = NULL;
    if(batt_level){
        co_timer_start(&co_batt_check_timer,CO_BATT_CHECK_TIME_IN_ACTIVE,NULL,co_main_batt_check_timer,0);
        for(uint8_t i = 0; i < co_batt_reg_cb_num; i++){
            if(co_batt_reg_cb[i]){
                co_batt_reg_cb[i](APP_MSG_BATT|(uint32_t)batt_level);
            }
        }
        // notify some task current batt level.
    }else{
        //need power down or notify some task to do some process before power down.
        if(co_batt_reg_cb_num){
            for(uint8_t i = 0; i < co_batt_reg_cb_num; i++){
                if(co_batt_reg_cb[i]){
                    if(co_batt_reg_cb_num - 1 == i)
                        co_batt_reg_cb[i](APP_MSG_POWER_DOWN|(uint32_t)batt_level);
                    else
                        co_batt_reg_cb[i](APP_MSG_LOW_POWER|(uint32_t)batt_level);
                }
            }
        }else{
            pmic_chip_shutdown();
        }
    }
}

static void co_main_batt_timer_change(uint8_t is_sleep)
{
    uint32_t duration = 0;

    if(is_sleep)
        duration = CO_BATT_CHECK_TIME_IN_SLEEP;
    else
        duration = CO_BATT_CHECK_TIME_IN_ACTIVE;

    if(co_batt_check_timer){
        co_timer_stop(co_batt_check_timer);
        co_batt_check_timer = NULL;
        co_timer_start(&co_batt_check_timer,duration,NULL,co_main_batt_check_timer,0);
    }
}

static void co_main_batt_timer_init(void)
{
    uint32_t pwrmd = pwrctrl_pwrmd_cpusys_sw_record_getf();

    if (pwrmd == CPU_SYS_POWER_ON_RESET) {
        if(co_batt_check_timer == NULL){
            co_timer_start(&co_batt_check_timer,CO_BATT_CHECK_TIME_IN_ACTIVE,NULL,co_main_batt_check_timer,0);
        }
    }
}
#endif

#if PLF_AON_SUPPORT
static uint32_t co_main_timer_min_duration = (uint32_t)-1;
#define TIMER_LIST_SLEEP_ENTRY_MAX                     5
co_timer co_timer_list_sleep_entry[TIMER_LIST_SLEEP_ENTRY_MAX];
PRIVATE_HOST_ARRAY_DECLARE(G0RTOS, co_timer, TIMER_LIST_SLEEP_ENTRY_MAX, co_timer_list_sleep_entry);

uint8_t co_timer_lp_level = CO_TIMER_LP_LEVEL_HIBERNATE;

void co_timer_save(void)
{
    uint16_t list_len = 0;
    list_len = co_list_size(&co_main_time_list);

    COTIMER_DEBUG_PRINTF("%s list_len 0x%x\n",__func__,list_len);
    memset(&co_timer_list_sleep_entry[0],0,sizeof(co_timer_list_sleep_entry));
    if(list_len){
        uint8_t i = 0;
        struct co_list_hdr *element = NULL;
        co_timer *current_timer;
        element = co_main_time_list.first;
        COTIMER_DEBUG_PRINTF("%s element 0x%x\n",__func__,element);
        while(element != NULL){
            current_timer = (co_timer *)element;
            memcpy(&co_timer_list_sleep_entry[i++],current_timer,sizeof(co_timer));
            element = element->next;
            if(i == TIMER_LIST_SLEEP_ENTRY_MAX){
                break;
            }
        }
    }
    memcpy(&backup_co_timer_list_sleep_entry[0], &co_timer_list_sleep_entry[0], sizeof(co_timer_list_sleep_entry));
}

void co_timer_restore(void)
{
    co_timer *tmp_timer = NULL;
    co_timer *cur_timer = NULL;

    memcpy(&co_timer_list_sleep_entry[0], &backup_co_timer_list_sleep_entry[0], sizeof(co_timer_list_sleep_entry));
    for(uint8_t i = 0; i < TIMER_LIST_SLEEP_ENTRY_MAX; i++){
        COTIMER_DEBUG_PRINTF("%s timer_addr 0x%x\n",__func__,co_timer_list_sleep_entry[i].timer_addr);
        if(co_timer_list_sleep_entry[i].timer_addr){
            cur_timer = &co_timer_list_sleep_entry[i];
            tmp_timer = (co_timer *)rtos_malloc(sizeof(co_timer));
            COTIMER_DEBUG_PRINTF("%s tmp_timer alloc 0x%x\n",__func__,tmp_timer);
            if(tmp_timer){
                *((co_timer **)cur_timer->timer_addr) = tmp_timer;
                tmp_timer->cb = cur_timer->cb;
                tmp_timer->cb_param = cur_timer->cb_param;
                tmp_timer->timer_addr = cur_timer->timer_addr;
                tmp_timer->time_duration = cur_timer->time_duration;
                tmp_timer->time_start = cur_timer->time_start;
                tmp_timer->is_period = cur_timer->is_period;
                COTIMER_DEBUG_PRINTF("%d,  0x%x, 0x%x\n",tmp_timer->time_duration,tmp_timer->time_start,tmp_timer->cb);
            }else{
                COTIMER_DEBUG_PRINTF("co_timer malloc error\n");
                ASSERT_ERR(0);
                return;
            }
            co_list_push_back(&co_main_time_list,&tmp_timer->node);
            //co_timer_lp_level = CO_TIMER_LP_LEVEL_ACTIVE;
        }
    }
    co_main_timer_notify();
}

void co_timer_sleep_level_set(POWER_MODE_LEVEL_T level)
{
    if (level == PM_LEVEL_ACTIVE) {
        co_timer_lp_level = CO_TIMER_LP_LEVEL_ACTIVE;
    }else{
        co_timer_lp_level = CO_TIMER_LP_LEVEL_HIBERNATE;
    }
}

int co_timer_is_sleep_allowed(void)
{
    int ret = 0;
    uint16_t list_len = 0;
    uint32_t elapsed_time;
    uint32_t min_duration = (uint32_t)(-1);
    struct co_list_hdr *element = NULL;
    co_timer *current_timer;
    uint32_t time_now = rtos_now(false);


    do {
        if (co_timer_lp_level == CO_TIMER_LP_LEVEL_HIBERNATE) {
            list_len = co_list_size(&co_main_time_list);
            if ( list_len == 0 ) {
                ret = 1;
                break;
            } else {
                element = co_main_time_list.first;
                while(element != NULL){
                    current_timer = (co_timer *)element;
                    elapsed_time = time_now - current_timer->time_start;
                    if(elapsed_time < current_timer->time_duration){
                        min_duration = min(min_duration,(current_timer->time_duration - elapsed_time));
                    }
                    element = element->next;
                }

                COTIMER_DEBUG_PRINTF("m_d %d\n",min_duration);
                if(min_duration >= CO_TIMER_ALLOW_MIN_SLEEP_DURATION){
                    ret = 1;
                    co_main_timer_min_duration = min_duration;
                    break;
                }
            }
        }
    } while (0);

    return ret;
}

uint32_t get_co_main_timer_min_duration(void)
{
    return co_main_timer_min_duration;
}

void co_timer_sleep_indicate(POWER_MODE_LEVEL_T level)
{
    //todo
#if CO_MAIN_AUTO_POWER_DOWEN
    co_main_batt_timer_change(1);
#endif
}

void co_timer_wakeup_indicate(void)
{
    //todo
#if CO_MAIN_AUTO_POWER_DOWEN
    co_main_batt_timer_change(0);
#endif
}

void co_timer_sleep_entry_init(void)
{
    uint32_t pwrmd = pwrctrl_pwrmd_cpusys_sw_record_getf();

    if (pwrmd == CPU_SYS_POWER_ON_RESET) {
        sleep_entry_t co_timer_sleep_entry = {
            co_timer_sleep_level_set,
            co_timer_is_sleep_allowed,
            co_timer_sleep_indicate,
            co_timer_wakeup_indicate,
        };
        sleep_entry_register(&co_timer_sleep_entry);
    }
}
#endif /* PLF_AON_SUPPORT */


void co_main_init(void)
{
    co_main_timer_init();
    co_main_evt_handler_rigister(CO_MODUAL_TIMER,co_timer_handle_process);
    #if PLF_AON_SUPPORT
    co_timer_sleep_entry_init();
    #endif
    #if CO_MAIN_AUTO_POWER_DOWEN
    co_main_batt_timer_init();
    #endif
    // create the co main evt queue
    if (rtos_queue_create(sizeof(CO_MODUAL_EVENT), CO_EVT_MAX, &co_main_evt_queue)) {
        dbg("failed to create co_main_mbox\n");
        return;
    }
    // Create the co main task
    if (rtos_task_create(co_main_task, "CO_TASK", CO_TASK,
                         TASK_STACK_SIZE_CO_MAIN, NULL, TASK_PRIORITY_CO_MAIN, &co_main_task_handle)) {
        dbg("failed to create co_main_task\n");
        rtos_queue_delete(co_main_evt_queue);
        co_main_evt_queue = NULL;
        return;
    }
}

