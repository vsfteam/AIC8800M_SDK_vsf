#include <stddef.h>     // standard definition
#include "uart2_api.h"
#include "reg_iomux.h"
#include "sysctrl_api.h"
#include "reg_ipc_comreg.h"

#define PERCLK_INDEX        (PER_UART0 + UART2_INDEX)
#define UART_INITED_SET     M2STR_P3(ipccomreg_state_uart, UART2_INDEX, inited_setb)

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

int uart2_inited = 0;
uint32_t uart2_baudrate = 0;
uart2_rx_func_t uart2_rx_func = NULL;

void uart2_init(void)
{
    // clk en
    cpusysctrl_hclkme_set(CSC_HCLKME_UART2_EN_BIT);
    cpusysctrl_oclkme_set(CSC_OCLKME_UART2_EN_BIT);

    uart2_dbufcfg_pack(0,  //tx data buf reset
                       0,  //rx data buf reset
                       0); //data buf disable

    uart2_irqctl_pack(0,  //
                      0,  //
                      0,  //Line Status irq disable
                      0,  //Tx irq disable
                      0); //Rx irq disable

    uart2_dbufth_pack(0,  //tx data buffer trigger threshold
                      1); //rx data buffer trigger threshold

    uart2_clk_p_setf(1);  //uart clk 0 = 24M, 1 = 48M

    uart2_format_set(8, 0, 1);

    uart2_baud_set(UART_BAUDRATE);

    /* IOMUX UART2_RX = GPIO6    UART2_TX = GPIO7 */
    iomux_gpio_config_sel_setf(6, 0x02);
    iomux_gpio_config_sel_setf(7, 0x02);

    uart2_dbufcfg_pack(1,  //tx data buf reset
                       1,  //rx data buf reset
                       1); //data buf enable

    uart2_rxirqen_setf(1); //enable rx interrupt

    NVIC_SetPriority(UART2_IRQn, __NVIC_PRIO_LOWEST);
    NVIC_EnableIRQ(UART2_IRQn);

    uart2_inited = 1;
    UART_INITED_SET();
}

uint32_t uart2_baud_get(void)
{
    return uart2_baudrate;
}

void uart2_baud_set(uint32_t baud)
{
    if (uart2_baudrate != baud) {
        uint32_t div0, div1, div2;
        #if (!MAX_BAUD_RATE)
        uint32_t clk, div;
        #endif
        uart2_baudrate = baud;
        #if (MAX_BAUD_RATE)
        div0 = 0x01UL;
        div1 = div2 = 0x00UL;
        #else
        #if (PLF_HW_FPGA == 1)
        clk = DEF_CLK_FREQUENCY_52M;
        #else
        clk = sysctrl_clock_get(PERCLK_INDEX);
        #endif
        div  = clk / uart2_baudrate;
        div0 = 0xFFUL & (div >> 4);
        div1 = 0xFFUL & (div >> 12);
        div2 = (0x01UL & div) + (0x07UL & (div >> 1)) + (0x70UL & (div << 3));
        #endif
        uart2_divae_setf(1);  //div reg access enable
        uart2_div0_set(div0);
        uart2_div1_set(div1);
        uart2_div2_set(div2);
        uart2_divae_setf(0);  //div reg access disable
    }
}

void uart2_format_get(uint32_t *bits, uint32_t *parity, uint32_t *stop)
{
    *bits = uart2_dls_getf() + 5;
    *parity = uart2_eps_getf() | (uart2_pen_getf() << 1);
    *stop = uart2_stop_getf() + 1;
}

void uart2_format_set(uint32_t bits, uint32_t parity, uint32_t stop)
{
    uint8_t data_bits = (uint8_t)(bits - 5);
    uint8_t even_bit = (uint8_t)(parity & 0x01UL);
    uint8_t pari_bit = (uint8_t)((parity >> 1) & 0x01UL);
    uint8_t stop_bit = (uint8_t)(stop - 1);
    uart2_dfmtcfg_pack(0,  //div mode sel
                       0,  //divisor register access enable  0 = disable 1 = enable
                       0,  //break
                       even_bit,   //parity, 1 for even
                       pari_bit,   //parity enable
                       stop_bit,   //stop bits 0 = 1 bit, 1 = 2 bits
                       data_bits); //data bits 0 = 5 bits, 1 = 6 bits, 2 = 7 bits, 3 = 8 bits
}

void uart2_putc(char ch)
{
    while (uart2_tx_dbuf_full_getf());
    uart2_txdata_setf(ch);
}

char uart2_getc(void)
{
    while (uart2_rx_dbuf_empty_getf());
    return ((char)uart2_rxdata_getf());
}

int uart2_get_rx_count(void)
{
    return (uart2_rx_count_getf());
}

void register_uart2_rx_function(uart2_rx_func_t func)
{
    uart2_rx_func = func;
}

void uart2_isr(void)
{
    switch (uart2_irqtyp_getf())
    {
        case UART_RX_ERROR_INT://RX Error Interrupt, highest priority
            uart2_irqsts_get();
            break;
        case UART_RX_INT://RX Data Ready Interrupt, second priority
            if (uart2_rx_func) {
                uart2_rx_func();
            } else {
                uart2_rxdata_getf();
            }
            break;
        case UART_TIMEOUT_INT://Char Timeout Interrupt, second priority
            uart2_rxdata_getf();
            break;
        case UART_TX_INT://TX Empty Interrupt, third priority
            break;
        case UART_MODEM_INT://Modem Interrupt, forth priority
            uart2_mdmsts_get();
            break;
        case UART_NO_INT://No Interrupt
            break;
        default:
            break;
    }
}
