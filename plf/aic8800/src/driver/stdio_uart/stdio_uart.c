#include <stddef.h>     // standard definition
#include "stdio_uart.h"
#include "reg_iomux.h"
#include "sysctrl_api.h"
#include "reg_ipc_comreg.h"

#define PERCLK_INDEX        (PER_UART0 + UART_INDEX)
#define UART_INITED_SET     M2STR_P3(ipccomreg_state_uart, UART_INDEX, inited_setb)

#if (PLF_HW_PXP == 1)
#define MAX_BAUD_RATE       1
#else
#define MAX_BAUD_RATE       0
#endif

/// UART BAUDRATE 921600bps
#if (PLF_HW_ASIC == 1)
#define UART_BAUDRATE       921600
#else
#define UART_BAUDRATE       3250000
#endif

/// UART Interrupt ID bits
#define UART_MODEM_INT       0x00
#define UART_NO_INT          0x01
#define UART_TX_INT          0x02
#define UART_RX_INT          0x04
#define UART_RX_ERROR_INT    0x06
#define UART_TIMEOUT_INT     0x0C
#define UART_ID_MASK         0x0F

int stdio_uart_inited = 0;
uint32_t stdio_uart_baudrate = 0;
stdio_uart_rx_func_t stdio_uart_rx_func = NULL;

void stdio_uart_init(void)
{
    while(!ipc_mutex_get(IPC_MUTEX_UART_OUTPUT));   // lock mutex

    stdio_uart_dbufcfg_pack(0,  //tx data buf reset
                            0,  //rx data buf reset
                            0); //data buf disable

    stdio_uart_irqctl_pack(0,  //
                           0,  //
                           0,  //Line Status irq disable
                           0,  //Tx irq disable
                           0); //Rx irq disable

    stdio_uart_dbufth_pack(0,  //tx data buffer trigger threshold
                           1); //rx data buffer trigger threshold

    stdio_uart_clk_p_setf(1);  //uart clk 0 = 24M, 1 = 48M

    stdio_uart_format_set(8, 0, 1);

    stdio_uart_baud_set(UART_BAUDRATE);

    #if UART_INDEX == 2
        /* IOMUX UART2_RX = GPIO22    UART2_TX = GPIO23 */
        iomux_gpio_config_sel_setf(22, 0x02);
        iomux_gpio_config_sel_setf(23, 0x02);
    #endif

    stdio_uart_dbufcfg_pack(1,  //tx data buf reset
                            1,  //rx data buf reset
                            1); //data buf enable

    stdio_uart_rxirqen_setf(1); //enable rx interrupt

    ipc_mutex_set(IPC_MUTEX_UART_OUTPUT, 1);    // unlock mutex

    NVIC_SetPriority(UART_IRQn, __NVIC_PRIO_LOWEST);
    NVIC_EnableIRQ(UART_IRQn);

    stdio_uart_inited = 1;
    UART_INITED_SET();
}

uint32_t stdio_uart_baud_get(void)
{
    return stdio_uart_baudrate;
}

void stdio_uart_baud_set(uint32_t baud)
{
    if (stdio_uart_baudrate != baud) {
        uint32_t div0, div1, div2;
        #if (!MAX_BAUD_RATE)
        uint32_t clk, div;
        #endif
        stdio_uart_baudrate = baud;
        #if (MAX_BAUD_RATE)
        div0 = 0x01UL;
        div1 = div2 = 0x00UL;
        #else
        #if (PLF_HW_FPGA == 1)
        clk = DEF_CLK_FREQUENCY_52M;
        #else
        clk = sysctrl_clock_get(PERCLK_INDEX);
        #endif
        div  = clk / stdio_uart_baudrate;
        div0 = 0xFFUL & (div >> 4);
        div1 = 0xFFUL & (div >> 12);
        div2 = (0x01UL & div) + (0x07UL & (div >> 1)) + (0x70UL & (div << 3));
        #endif
        stdio_uart_divae_setf(1);  //div reg access enable
        stdio_uart_div0_set(div0);
        stdio_uart_div1_set(div1);
        stdio_uart_div2_set(div2);
        stdio_uart_divae_setf(0);  //div reg access disable
    }
}

void stdio_uart_format_get(uint32_t *bits, uint32_t *parity, uint32_t *stop)
{
    *bits = stdio_uart_dls_getf() + 5;
    *parity = stdio_uart_eps_getf() | (stdio_uart_pen_getf() << 1);
    *stop = stdio_uart_stop_getf() + 1;
}

void stdio_uart_format_set(uint32_t bits, uint32_t parity, uint32_t stop)
{
    uint8_t data_bits = (uint8_t)(bits - 5);
    uint8_t even_bit = (uint8_t)(parity & 0x01UL);
    uint8_t pari_bit = (uint8_t)((parity >> 1) & 0x01UL);
    uint8_t stop_bit = (uint8_t)(stop - 1);
    stdio_uart_dfmtcfg_pack(0,  //div mode sel
                            0,  //divisor register access enable  0 = disable 1 = enable
                            0,  //break
                            even_bit,   //parity, 1 for even
                            pari_bit,   //parity enable
                            stop_bit,   //stop bits 0 = 1 bit, 1 = 2 bits
                            data_bits); //data bits 0 = 5 bits, 1 = 6 bits, 2 = 7 bits, 3 = 8 bits
}

void stdio_uart_putc(char ch)
{
    while (stdio_uart_tx_dbuf_full_getf());
    stdio_uart_txdata_setf(ch);
}

char stdio_uart_getc(void)
{
    while (stdio_uart_rx_dbuf_empty_getf());
    return ((char)stdio_uart_rxdata_getf());
}

bool stdio_uart_tstc(void)
{
    return stdio_uart_dr_getf();
}

int stdio_uart_get_rx_count(void)
{
    return (stdio_uart_rx_count_getf());
}

void register_stdio_uart_rx_function(stdio_uart_rx_func_t func)
{
    stdio_uart_rx_func = func;
}

void stdio_uart_isr(void)
{
    switch (stdio_uart_irqtyp_getf())
    {
        case UART_RX_ERROR_INT://RX Error Interrupt, highest priority
            stdio_uart_irqsts_get();
            break;
        case UART_RX_INT://RX Data Ready Interrupt, second priority
            if (stdio_uart_rx_func) {
                stdio_uart_rx_func();
            } else {
                stdio_uart_rxdata_getf();
            }
            break;
        case UART_TIMEOUT_INT://Char Timeout Interrupt, second priority
            stdio_uart_rxdata_getf();
            break;
        case UART_TX_INT://TX Empty Interrupt, third priority
            break;
        case UART_MODEM_INT://Modem Interrupt, forth priority
            stdio_uart_mdmsts_get();
            break;
        case UART_NO_INT://No Interrupt
            break;
        default:
            break;
    }
}

