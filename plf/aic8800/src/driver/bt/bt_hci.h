#ifndef _BT_HCI_H_
#define _BT_HCI_H_

#include <stdint.h>
#include <stdbool.h>

typedef enum {
    BT_HCI_CH_0 = 0,
    BT_HCI_CH_NUM
} BT_HCI_CH_T;

typedef enum {
    BT_HCI_PKT_TYPE_HCI_UART = 0,
    BT_HCI_PKT_TYPE_NUM
} BT_HCI_PKT_TYPE_T;

/*
 * @param data ptr
 * @param data length
 * @return length of processed rx data
 */
typedef uint32_t (*BT_HCI_RX_IRQ_HANDLER)(const uint8_t *data, uint32_t len);

/*
 * @param data ptr
 * @param data length
 */
typedef void (*BT_HCI_TX_IRQ_HANDLER)(const uint8_t *data, uint32_t len);

typedef void (*BT_WAKEUP_IND_IRQ_HANDLER)(void);

typedef void (*AON_POWER_ON_CPUS_REQ_IRQ_HANDLER)(void);

/*
 * Open bt hci
 * @param hci channel
 * @param packet type
 * @param rx irq handler
 * @param tx irq handler
 * @param rx blocking mode, if set to true, host can only cache and process a packet , host should always call bt_hci_rx_done after rx_handler
 *  if set to false, host can cache several packets, host should copy data to somewhere else in rx_handler , host should never call bt_hci_rx_done
 * @return 0 on success
 */
int bt_hci_open(BT_HCI_CH_T ch, BT_HCI_PKT_TYPE_T type, BT_HCI_RX_IRQ_HANDLER rx_handler, BT_HCI_TX_IRQ_HANDLER tx_handler, bool rx_blocking);

/*
 * Host start receiving data
 * @param hci channel
 * @return 0 on success
 */
int bt_hci_rx_start(BT_HCI_CH_T ch);

/*
 * Host stop receiving data
 * @param hci channel
 * @return 0 on success
 */
int bt_hci_rx_stop(BT_HCI_CH_T ch);

/*
 * Host complete a reception
 * @param hci channel
 */
void bt_hci_rx_done(BT_HCI_CH_T ch);

/*
 * Check whether host could send data to controller
 * Be careful, do NOT send data even it return true when hci flow control forbid host to send data to controller
 * @param hci channel
 * @return true if host could send data to controller, return false if not, this would happen when controller could not
 *  handle reception in time and cause host sending jam
 */
bool bt_hci_tx_available(BT_HCI_CH_T ch);

/*
 * Host send data to controller
 * @param hci channel
 * @param packet type
 * @param data ptr
 * @param data length
 * @return 0 on success
 */
int bt_hci_tx(BT_HCI_CH_T ch, BT_HCI_PKT_TYPE_T type, const uint8_t *data, uint32_t len);

/*
 * Close bt hci
 * @param hci channel
 * @param packet type
 * @return 0 on success
 */
int bt_hci_close(BT_HCI_CH_T ch, BT_HCI_PKT_TYPE_T type);

/*
 * Host send wakeup request to controller, and disable controller to enter deep sleep again until host send next sleep enable
 */
void host_wakeup_request(void);

/*
 * Host send wakeup request to controller, and controller's sleep enable is not changed, must be called before bt_hci_open
 */
void host_wakeup_request2(void);

/*
 * Register the bt wakeup indication handler, the handler should be registered before bt_hci_open
 * Host received controller's wakeup indication, corresponding to host_wakeup_request
 * @param handler
 *
 */
void bt_wakeup_ind_irq_handler_register(BT_WAKEUP_IND_IRQ_HANDLER handler);

/*
 * Register the bt wakeup indication2 handler, the handler should be registered before bt_hci_open
 * Host received controller's wakeup indication, corresponding to host_wakeup_request2
 * @param handler
 *
 */
void bt_wakeup_ind2_irq_handler_register(BT_WAKEUP_IND_IRQ_HANDLER handler);

/*
 * Initialize interface between host and aon module
 */
void ipc_cpup_aon_init(void);

/*
 * Host request controller to quit aon mode and enter normal mode
 */
void cpup_power_on_cpus_req_send(void);

/*
 * Register the handler when host receives the requeset that controller want to exit aon mode and enter normal mode
 * the handler should be registered before ipc_cpup_aon_init
 * @param handler
 *
 */
void aon_power_on_cpus_req_irq_handler_register(AON_POWER_ON_CPUS_REQ_IRQ_HANDLER handler);

#endif
