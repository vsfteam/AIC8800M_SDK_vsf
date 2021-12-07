#ifndef _REG_IPC_COMREG_H_
#define _REG_IPC_COMREG_H_

#include "reg_access.h"
#include "chip.h"

/**
 * IPC_COMREG registers
 */
#define IPC_COMREG_BASE_ADDR   (AIC_IPCAPP_BASE + 0x0080)

__STATIC_INLINE uint32_t ipc_comreg_get(int idx)
{
    return REG_PL_RD(IPC_COMREG_BASE_ADDR + (idx << 2));
}

__STATIC_INLINE void ipc_comreg_set(int idx, uint32_t value)
{
    REG_PL_WR(IPC_COMREG_BASE_ADDR + (idx << 2), value);
}

/**
 * IPC_COMREG register index definition
 */
enum {
    IPC_COMREG_STATE    = 0,
    IPC_COMREG_LOWPOWER = 1,
    IPC_COMREG_WCN_PTA  = 2,
    IPC_COMREG_TWS_HS   = 3,
    IPC_COMREG_TWS_HUS  = 4,
    IPC_COMREG_5        = 5,
    IPC_COMREG_6        = 6,
    IPC_COMREG_7        = 7,
    IPC_COMREG_MAX
};

/**
 * IPC COMREG STATE register bit definition
 */
#define ICR_STATE_UART0_INITED_POS              (0)
#define ICR_STATE_UART0_INITED_BIT              (0x01UL << ICR_STATE_UART0_INITED_POS)
#define ICR_STATE_UART1_INITED_POS              (1)
#define ICR_STATE_UART1_INITED_BIT              (0x01UL << ICR_STATE_UART1_INITED_POS)
#define ICR_STATE_UART2_INITED_POS              (2)
#define ICR_STATE_UART2_INITED_BIT              (0x01UL << ICR_STATE_UART2_INITED_POS)
#define ICR_STATE_WIFI_IPCSHDENV_ZI_POS         (3)
#define ICR_STATE_WIFI_IPCSHDENV_ZI_BIT         (0x01UL << ICR_STATE_WIFI_IPCSHDENV_ZI_POS)
#define ICR_STATE_WIFI_IPCSHDENV_ZI_DONE_POS    (4)
#define ICR_STATE_WIFI_IPCSHDENV_ZI_DONE_BIT    (0x01UL << ICR_STATE_WIFI_IPCSHDENV_ZI_DONE_POS)

__STATIC_INLINE uint8_t ipccomreg_state_uart0inited_getb(void)
{
    return (ipc_comreg_get(IPC_COMREG_STATE) & ICR_STATE_UART0_INITED_BIT) >> ICR_STATE_UART0_INITED_POS;
}

__STATIC_INLINE void ipccomreg_state_uart0inited_setb(void)
{
    ipc_comreg_set(IPC_COMREG_STATE, ipc_comreg_get(IPC_COMREG_STATE) |  ICR_STATE_UART0_INITED_BIT);
}

__STATIC_INLINE void ipccomreg_state_uart0inited_clrb(void)
{
    ipc_comreg_set(IPC_COMREG_STATE, ipc_comreg_get(IPC_COMREG_STATE) & ~ICR_STATE_UART0_INITED_BIT);
}

__STATIC_INLINE uint8_t ipccomreg_state_uart1inited_getb(void)
{
    return (ipc_comreg_get(IPC_COMREG_STATE) & ICR_STATE_UART1_INITED_BIT) >> ICR_STATE_UART1_INITED_POS;
}

__STATIC_INLINE void ipccomreg_state_uart1inited_setb(void)
{
    ipc_comreg_set(IPC_COMREG_STATE, ipc_comreg_get(IPC_COMREG_STATE) |  ICR_STATE_UART1_INITED_BIT);
}

__STATIC_INLINE void ipccomreg_state_uart1inited_clrb(void)
{
    ipc_comreg_set(IPC_COMREG_STATE, ipc_comreg_get(IPC_COMREG_STATE) & ~ICR_STATE_UART1_INITED_BIT);
}

__STATIC_INLINE uint8_t ipccomreg_state_uart2inited_getb(void)
{
    return (ipc_comreg_get(IPC_COMREG_STATE) & ICR_STATE_UART2_INITED_BIT) >> ICR_STATE_UART2_INITED_POS;
}

__STATIC_INLINE void ipccomreg_state_uart2inited_setb(void)
{
    ipc_comreg_set(IPC_COMREG_STATE, ipc_comreg_get(IPC_COMREG_STATE) |  ICR_STATE_UART2_INITED_BIT);
}

__STATIC_INLINE void ipccomreg_state_uart2inited_clrb(void)
{
    ipc_comreg_set(IPC_COMREG_STATE, ipc_comreg_get(IPC_COMREG_STATE) & ~ICR_STATE_UART2_INITED_BIT);
}

__STATIC_INLINE uint8_t ipccomreg_state_wifi_ipcshdenv_zi_getb(void)
{
    return (ipc_comreg_get(IPC_COMREG_STATE) & ICR_STATE_WIFI_IPCSHDENV_ZI_BIT) >> ICR_STATE_WIFI_IPCSHDENV_ZI_POS;
}

__STATIC_INLINE void ipccomreg_state_wifi_ipcshdenv_zi_setb(void)
{
    ipc_comreg_set(IPC_COMREG_STATE, ipc_comreg_get(IPC_COMREG_STATE) |  ICR_STATE_WIFI_IPCSHDENV_ZI_BIT);
}

__STATIC_INLINE void ipccomreg_state_wifi_ipcshdenv_zi_clrb(void)
{
    ipc_comreg_set(IPC_COMREG_STATE, ipc_comreg_get(IPC_COMREG_STATE) & ~ICR_STATE_WIFI_IPCSHDENV_ZI_BIT);
}

__STATIC_INLINE uint8_t ipccomreg_state_wifi_ipcshdenv_zi_done_getb(void)
{
    return (ipc_comreg_get(IPC_COMREG_STATE) & ICR_STATE_WIFI_IPCSHDENV_ZI_DONE_BIT) >> ICR_STATE_WIFI_IPCSHDENV_ZI_DONE_POS;
}

__STATIC_INLINE void ipccomreg_state_wifi_ipcshdenv_zi_done_setb(void)
{
    ipc_comreg_set(IPC_COMREG_STATE, ipc_comreg_get(IPC_COMREG_STATE) |  ICR_STATE_WIFI_IPCSHDENV_ZI_DONE_BIT);
}

__STATIC_INLINE void ipccomreg_state_wifi_ipcshdenv_zi_done_clrb(void)
{
    ipc_comreg_set(IPC_COMREG_STATE, ipc_comreg_get(IPC_COMREG_STATE) & ~ICR_STATE_WIFI_IPCSHDENV_ZI_DONE_BIT);
}

/**
 * IPC COMREG LOWPOWER register bit definition
 */
#define ICR_LOWPOWER_WIFI_FW_IDLE_POS       (0)
#define ICR_LOWPOWER_WIFI_FW_IDLE_BIT       (0x01UL << ICR_LOWPOWER_WIFI_FW_IDLE_POS)
#define ICR_LOWPOWER_BT_FW_IDLE_POS         (1)
#define ICR_LOWPOWER_BT_FW_IDLE_BIT         (0x01UL << ICR_LOWPOWER_BT_FW_IDLE_POS)
#define ICR_LOWPOWER_HOST_IDLE_POS          (2)
#define ICR_LOWPOWER_HOST_IDLE_BIT          (0x01UL << ICR_LOWPOWER_HOST_IDLE_POS)
#define ICR_LOWPOWER_BT_FW_INIT_DONE_POS    (3)
#define ICR_LOWPOWER_BT_FW_INIT_DONE_BIT    (0x01UL << ICR_LOWPOWER_BT_FW_INIT_DONE_POS)
#define ICR_LOWPOWER_BT_TASK_READY_POS      (4)
#define ICR_LOWPOWER_BT_TASK_READY_BIT      (0x01UL << ICR_LOWPOWER_BT_TASK_READY_POS)
#define ICR_LOWPOWER_BT_FW_INIT_START_POS   (5)
#define ICR_LOWPOWER_BT_FW_INIT_START_BIT   (0x01UL << ICR_LOWPOWER_BT_FW_INIT_START_POS)
#define ICR_LOWPOWER_DSP_IDLE_POS           (6)
#define ICR_LOWPOWER_DSP_IDLE_BIT           (0x01UL << ICR_LOWPOWER_DSP_IDLE_POS)
#define ICR_LOWPOWER_DSP_INIT_DONE_POS      (7)
#define ICR_LOWPOWER_DSP_INIT_DONE_BIT      (0x01UL << ICR_LOWPOWER_DSP_INIT_DONE_POS)

__STATIC_INLINE uint8_t ipccomreg_lowpower_wifi_fw_idle_getb(void)
{
    return (ipc_comreg_get(IPC_COMREG_LOWPOWER) & ICR_LOWPOWER_WIFI_FW_IDLE_BIT) >> ICR_LOWPOWER_WIFI_FW_IDLE_POS;
}

__STATIC_INLINE void ipccomreg_lowpower_wifi_fw_idle_setb(void)
{
    ipc_comreg_set(IPC_COMREG_LOWPOWER, ipc_comreg_get(IPC_COMREG_LOWPOWER) |  ICR_LOWPOWER_WIFI_FW_IDLE_BIT);
}

__STATIC_INLINE void ipccomreg_lowpower_wifi_fw_idle_clrb(void)
{
    ipc_comreg_set(IPC_COMREG_LOWPOWER, ipc_comreg_get(IPC_COMREG_LOWPOWER) & ~ICR_LOWPOWER_WIFI_FW_IDLE_BIT);
}

__STATIC_INLINE uint8_t ipccomreg_lowpower_bt_fw_idle_getb(void)
{
    return (ipc_comreg_get(IPC_COMREG_LOWPOWER) & ICR_LOWPOWER_BT_FW_IDLE_BIT) >> ICR_LOWPOWER_BT_FW_IDLE_POS;
}

__STATIC_INLINE void ipccomreg_lowpower_bt_fw_idle_setb(void)
{
    ipc_comreg_set(IPC_COMREG_LOWPOWER, ipc_comreg_get(IPC_COMREG_LOWPOWER) |  ICR_LOWPOWER_BT_FW_IDLE_BIT);
}

__STATIC_INLINE void ipccomreg_lowpower_bt_fw_idle_clrb(void)
{
    ipc_comreg_set(IPC_COMREG_LOWPOWER, ipc_comreg_get(IPC_COMREG_LOWPOWER) & ~ICR_LOWPOWER_BT_FW_IDLE_BIT);
}

__STATIC_INLINE uint8_t ipccomreg_lowpower_host_idle_getb(void)
{
    return (ipc_comreg_get(IPC_COMREG_LOWPOWER) & ICR_LOWPOWER_HOST_IDLE_BIT) >> ICR_LOWPOWER_HOST_IDLE_POS;
}

__STATIC_INLINE void ipccomreg_lowpower_host_idle_setb(void)
{
    ipc_comreg_set(IPC_COMREG_LOWPOWER, ipc_comreg_get(IPC_COMREG_LOWPOWER) |  ICR_LOWPOWER_HOST_IDLE_BIT);
}

__STATIC_INLINE void ipccomreg_lowpower_host_idle_clrb(void)
{
    ipc_comreg_set(IPC_COMREG_LOWPOWER, ipc_comreg_get(IPC_COMREG_LOWPOWER) & ~ICR_LOWPOWER_HOST_IDLE_BIT);
}

__STATIC_INLINE uint8_t ipccomreg_lowpower_bt_fw_init_done_getb(void)
{
    return (ipc_comreg_get(IPC_COMREG_LOWPOWER) & ICR_LOWPOWER_BT_FW_INIT_DONE_BIT) >> ICR_LOWPOWER_BT_FW_INIT_DONE_POS;
}

__STATIC_INLINE void ipccomreg_lowpower_bt_fw_init_done_setb(void)
{
    ipc_comreg_set(IPC_COMREG_LOWPOWER, ipc_comreg_get(IPC_COMREG_LOWPOWER) |  ICR_LOWPOWER_BT_FW_INIT_DONE_BIT);
}

__STATIC_INLINE void ipccomreg_lowpower_bt_fw_init_done_clrb(void)
{
    ipc_comreg_set(IPC_COMREG_LOWPOWER, ipc_comreg_get(IPC_COMREG_LOWPOWER) & ~ICR_LOWPOWER_BT_FW_INIT_DONE_BIT);
}

__STATIC_INLINE uint8_t ipccomreg_lowpower_bt_task_ready_getb(void)
{
    return (ipc_comreg_get(IPC_COMREG_LOWPOWER) & ICR_LOWPOWER_BT_TASK_READY_BIT) >> ICR_LOWPOWER_BT_TASK_READY_POS;
}

__STATIC_INLINE void ipccomreg_lowpower_bt_task_ready_setb(void)
{
    ipc_comreg_set(IPC_COMREG_LOWPOWER, ipc_comreg_get(IPC_COMREG_LOWPOWER) |  ICR_LOWPOWER_BT_TASK_READY_BIT);
}

__STATIC_INLINE void ipccomreg_lowpower_bt_task_ready_clrb(void)
{
    ipc_comreg_set(IPC_COMREG_LOWPOWER, ipc_comreg_get(IPC_COMREG_LOWPOWER) & ~ICR_LOWPOWER_BT_TASK_READY_BIT);
}

__STATIC_INLINE uint8_t ipccomreg_lowpower_bt_fw_init_start_getb(void)
{
    return (ipc_comreg_get(IPC_COMREG_LOWPOWER) & ICR_LOWPOWER_BT_FW_INIT_START_BIT) >> ICR_LOWPOWER_BT_FW_INIT_START_POS;
}

__STATIC_INLINE void ipccomreg_lowpower_bt_fw_init_start_setb(void)
{
    ipc_comreg_set(IPC_COMREG_LOWPOWER, ipc_comreg_get(IPC_COMREG_LOWPOWER) |  ICR_LOWPOWER_BT_FW_INIT_START_BIT);
}

__STATIC_INLINE void ipccomreg_lowpower_bt_fw_init_start_clrb(void)
{
    ipc_comreg_set(IPC_COMREG_LOWPOWER, ipc_comreg_get(IPC_COMREG_LOWPOWER) & ~ICR_LOWPOWER_BT_FW_INIT_START_BIT);
}

__STATIC_INLINE uint8_t ipccomreg_lowpower_dsp_idle_getb(void)
{
    return (ipc_comreg_get(IPC_COMREG_LOWPOWER) & ICR_LOWPOWER_DSP_IDLE_BIT) >> ICR_LOWPOWER_DSP_IDLE_POS;
}

__STATIC_INLINE void ipccomreg_lowpower_dsp_idle_setb(void)
{
    ipc_comreg_set(IPC_COMREG_LOWPOWER, ipc_comreg_get(IPC_COMREG_LOWPOWER) |  ICR_LOWPOWER_DSP_IDLE_BIT);
}

__STATIC_INLINE void ipccomreg_lowpower_dsp_idle_clrb(void)
{
    ipc_comreg_set(IPC_COMREG_LOWPOWER, ipc_comreg_get(IPC_COMREG_LOWPOWER) & ~ICR_LOWPOWER_DSP_IDLE_BIT);
}

__STATIC_INLINE uint8_t ipccomreg_lowpower_dsp_init_done_getb(void)
{
    return (ipc_comreg_get(IPC_COMREG_LOWPOWER) & ICR_LOWPOWER_DSP_INIT_DONE_BIT) >> ICR_LOWPOWER_DSP_INIT_DONE_POS;
}

__STATIC_INLINE void ipccomreg_lowpower_dsp_init_done_setb(void)
{
    ipc_comreg_set(IPC_COMREG_LOWPOWER, ipc_comreg_get(IPC_COMREG_LOWPOWER) |  ICR_LOWPOWER_DSP_INIT_DONE_BIT);
}

__STATIC_INLINE void ipccomreg_lowpower_dsp_init_done_clrb(void)
{
    ipc_comreg_set(IPC_COMREG_LOWPOWER, ipc_comreg_get(IPC_COMREG_LOWPOWER) & ~ICR_LOWPOWER_DSP_INIT_DONE_BIT);
}

/**
 * IPC COMREG WCN PTA register bit definition
 */

__STATIC_INLINE uint32_t ipccomreg_wcn_pta_get(void)
{
    return ipc_comreg_get(IPC_COMREG_WCN_PTA);
}

__STATIC_INLINE void ipccomreg_wcn_pta_set(uint32_t value)
{
    ipc_comreg_set(IPC_COMREG_WCN_PTA, value);
}

__STATIC_INLINE uint32_t ipccomreg_tws_hs_get(void)
{
    return ipc_comreg_get(IPC_COMREG_TWS_HS);
}

__STATIC_INLINE void ipccomreg_tws_hs_set(uint32_t value)
{
    ipc_comreg_set(IPC_COMREG_TWS_HS, value);
}

__STATIC_INLINE uint32_t ipccomreg_tws_hus_get(void)
{
    return ipc_comreg_get(IPC_COMREG_TWS_HUS);
}

__STATIC_INLINE void ipccomreg_tws_hus_set(uint32_t value)
{
    ipc_comreg_set(IPC_COMREG_TWS_HUS, value);
}

#endif /* _REG_IPC_COMREG_H_ */
