#ifndef _ASIO_DSD_H_
#define _ASIO_DSD_H_
#include <stdint.h>
#include <stdbool.h>


#define AUD_ADC_SRC_CHECK_SIZE      1//sync value about buffer size
#define AUD_ADC_SRC_ONE_BYTE_TIME   1//time(us) of one byte of data
typedef void (*AIC_ASIO_DSD_HANDLER_T)(void* param);



void asio_dsd_out(uint8_t idx,unsigned int *rx);
void asio_dsd_tx_cb_register(uint8_t idx,AIC_ASIO_DSD_HANDLER_T cb);
void asio_dsd_rx_cb_register(uint8_t idx,AIC_ASIO_DSD_HANDLER_T cb);
void asio_dsd_cnt_clean(void);
void asio_dsd_init(unsigned int *adc_tx_0,unsigned int *adc_tx_1,unsigned int *dac_tx_0,unsigned int *dac_tx_1);

#endif
