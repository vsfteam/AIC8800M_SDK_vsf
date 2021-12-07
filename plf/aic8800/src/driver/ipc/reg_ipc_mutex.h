#ifndef _REG_IPC_MUTEX_H_
#define _REG_IPC_MUTEX_H_

#include "reg_access.h"
#include "chip.h"

/**
 * IPC_MUTEX registers
 */
#define IPC_MUTEX_BASE_ADDR   (AIC_IPCAPP_BASE + 0x0040)

__INLINE uint32_t ipc_mutex_get(int idx)
{
    return REG_PL_RD(IPC_MUTEX_BASE_ADDR + (idx << 2));
}

__INLINE void ipc_mutex_set(int idx, uint32_t value)
{
    REG_PL_WR(IPC_MUTEX_BASE_ADDR + (idx << 2), value);
}

/**
 * IPC_MUTEX ID definition
 */
enum {
    IPC_MUTEX_ID_UART0_OUTPUT   = 0,
    IPC_MUTEX_ID_UART1_OUTPUT   = 1,
    IPC_MUTEX_ID_UART2_OUTPUT   = 2,
    IPC_MUTEX_ID_WIFI_A2E_TX    = 3,
    IPC_MUTEX_ID_WIFI_E2A_MSG   = 4,
    IPC_MUTEX_ID_WIFI_E2A_RX    = 5,
    IPC_MUTEX_ID_WIFI_E2A_UF    = 6,
    IPC_MUTEX_ID_7              = 7,
    IPC_MUTEX_ID_MAX
};

#endif /* _REG_IPC_MUTEX_H_ */
