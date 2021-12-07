/**
 ****************************************************************************************
 *
 * @file sysctrl_api.h
 *
 * @brief SYSCTRL utility functions
 *
 ****************************************************************************************
 */

#ifndef _SYSCTRL_API_H_
#define _SYSCTRL_API_H_

/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include "reg_sysctrl.h"

#define DEF_CLK_FREQUENCY_52M       ( 52000000UL)
#define DEF_CLK_FREQUENCY_26M       ( 26000000UL)
#define SYS_CLK_FREQUENCY_40M       ( 40000000UL)

enum {
    SYS_FCLK = 0,
    SYS_HCLK,
    SYS_PCLK,
    PER_UART0,
    PER_UART1,
    PER_UART2,
    PER_PSRAM,
    PER_FLASH,
    PER_PWM,
};

enum {
    CLK_CFG_D480S240P120F120 = 0,
    CLK_CFG_D480S240P120F80,
    CLK_CFG_D480S240P120F60,
    CLK_CFG_D480S240P60F120,
    CLK_CFG_D480S240P60F80,
    CLK_CFG_D480S240P60F60,
    CLK_CFG_D240S240P120F120,
    CLK_CFG_D240S240P120F60,
    CLK_CFG_D240S240P60F60,
    CLK_CFG_D240S120P60F120,
    CLK_CFG_D240S120P60F60,
    CLK_CFG_D240S120P30F60,
    CLK_CFG_D120S120P60F60,
    CLK_CFG_D120S120P30F60,
    CLK_CFG_D80S80P40F40,
    CLK_CFG_D52S52P26F26,
    CLK_CFG_MAX,
};

enum {
    PLL_CFG_OFF = 0,
    PLL_CFG_320,
    PLL_CFG_480,
    PLL_CFG_320_480,
};

/*
 * cpu_sys pwr_ctrl_mode
 *  1) set by host idle task
 *  2) get by fw/host other task
 */
enum {
    CPU_SYS_POWER_ON_RESET  = 0x00,
    CPU_SYS_CLOCK_GATE      = 0x01,
    CPU_SYS_POWER_DOWN      = 0x02,
    CPU_SYS_HIBERNATE       = 0x03
};

/*
 * wifi_core sw_ctrl_mode
 *  1) set by fw/aon
 *  2) get by fw/aon
 */
enum {
    WIFI_CORE_CONTROLLED_BY_FW  = 0x00,
    WIFI_CORE_RELEASED_BY_FW    = 0x01,
    WIFI_CORE_CONTROLLED_BY_AON = 0x02,
    WIFI_CORE_RELEASED_BY_AON   = 0x03
};

/*
 * bt_core sw_ctrl_mode
 *  1) set by fw/aon
 *  2) get by fw/aon
 */
enum {
    BT_CORE_CONTROLLED_BY_FW    = 0x00,
    BT_CORE_RELEASED_BY_FW      = 0x01,
    BT_CORE_CONTROLLED_BY_AON   = 0x02,
    BT_CORE_RELEASED_BY_AON     = 0x03
};

enum {
    PWRCTRL_POWERUP = 0,
    PWRCTRL_POWERDOWN,
};

/**
 * get HCLK/PCLK/PER_CLK
 */
uint32_t sysctrl_clock_get(int sys_per);

/**
 * cfg DSP_CLK/SYS_CLK/PERI_CLK/FLSH_CLK
 */
void sysctrl_clock_cfg(int cfg);

/**
 * cfg pll
 */
void sysctrl_pll_cfg(int cfg);

/**
 * set wifi power up/down
 */
void pwrctrl_wifi_set(int ctrl);

/**
 * set mmsys power up/down
 */
void pwrctrl_mmsys_set(int ctrl);

#endif /* _SYSCTRL_API_H_ */
