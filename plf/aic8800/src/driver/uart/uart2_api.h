/**
 ****************************************************************************************
 *
 * @file uart2_api.h
 *
 * @brief UART2 Driver APIs.
 *
 ****************************************************************************************
 */

#ifndef _UART2_API_H_
#define _UART2_API_H_

/**
 ****************************************************************************************
 * @defgroup UART UART
 * @ingroup DRIVERS
 * @brief UART driver
 *
 * @{
 *
 ****************************************************************************************
 */

/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include <stdbool.h>          // standard boolean definitions
#include <stdint.h>           // standard integer functions
#include "reg_uart2.h"   // uart register
#include "reg_ipc_mutex.h"
#include "chip.h"

/// 3-part macro to function/variable/enum string
#define M2STR_P3_I(p0,p1,p2)    p0##p1##p2
#define M2STR_P3(p0,p1,p2)      M2STR_P3_I(p0, p1, p2)

/// Replace WEAK function in startup.S
#define uart2_isr      M2STR_P3(UART, UART2_INDEX, _IRQHandler)

typedef void (*uart2_rx_func_t)(void);

extern int uart2_inited;

/*
 * FUNCTION DECLARATIONS
 ****************************************************************************************
 */

void uart2_init(void);
uint32_t uart2_baud_get(void);
void uart2_baud_set(uint32_t baud);
void uart2_format_get(uint32_t *bits, uint32_t *parity, uint32_t *stop);
void uart2_format_set(uint32_t bits, uint32_t parity, uint32_t stop);
void uart2_putc(char ch);
char uart2_getc(void);
int  uart2_get_rx_count(void);
void register_uart2_rx_function(uart2_rx_func_t func);
void uart2_isr(void);

/// @} UART2
#endif /* _UART2_API_H_ */
