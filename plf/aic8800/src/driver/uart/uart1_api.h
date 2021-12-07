/**
 ****************************************************************************************
 *
 * @file uart1_api.h
 *
 * @brief UART1 Driver APIs.
 *
 ****************************************************************************************
 */

#ifndef _UART1_API_H_
#define _UART1_API_H_

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
#include "reg_uart1.h"   // uart register
#include "reg_ipc_mutex.h"
#include "chip.h"

/// 3-part macro to function/variable/enum string
#define M2STR_P3_I(p0,p1,p2)    p0##p1##p2
#define M2STR_P3(p0,p1,p2)      M2STR_P3_I(p0, p1, p2)

/// Replace WEAK function in startup.S
#define uart1_isr      M2STR_P3(UART, UART1_INDEX, _IRQHandler)

typedef void (*uart1_rx_func_t)(void);

extern int uart1_inited;

/*
 * FUNCTION DECLARATIONS
 ****************************************************************************************
 */

void uart1_init(void);
uint32_t uart1_baud_get(void);
void uart1_baud_set(uint32_t baud);
void uart1_format_get(uint32_t *bits, uint32_t *parity, uint32_t *stop);
void uart1_format_set(uint32_t bits, uint32_t parity, uint32_t stop);
void uart1_putc(char ch);
void uart1_puts(char *str);
char uart1_getc(void);
bool uart1_tstc(void);
int  uart1_get_rx_count(void);
void register_uart1_rx_function(uart1_rx_func_t func);
void uart1_isr(void);

/// @} UART1
#endif /* _UART1_API_H_ */
