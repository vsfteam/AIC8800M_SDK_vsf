/**
 ****************************************************************************************
 * @file dbg.h
 *
 * @brief Declaration of the Debug module environment.
 *
 ****************************************************************************************
 */
#ifndef _DBG_H_
#define _DBG_H_

/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include "plf.h"
#include "compiler.h"
#include <stdint.h>
#include <stdarg.h>

/**
 ****************************************************************************************
 * @defgroup DEBUG DEBUG
 * @ingroup MACSW
 * @brief Description of the Debug module.
 * @{
 ****************************************************************************************
 */

/**
 ****************************************************************************************
 * @defgroup DBG_PRINT DBG_PRINT
 * @ingroup DEBUG
 * @brief Print Debug feature
 * @{
 ****************************************************************************************
 */

/*
 * DEFINES
 ****************************************************************************************
 */

#define TRACE(fmt, ...) dbg(fmt, ##__VA_ARGS__)

/**
 * @name Debug Print definitions
 * @{
 ****************************************************************************************
 */
// Possibles values for NX_PRINT
#define NX_PRINT_NONE       0   ///< All print macro are discarded
#define NX_PRINT_IPC        1   ///< Print are sent to IPC
#define NX_PRINT_PRINTF     2   ///< Print are sent to standard printf
#define NX_PRINT_PRINTK     3   ///< Print are sent to Linux printk
#define NX_PRINT_UART       4   ///< Print are sent to stdio uart

// Prefix used for module filtering
// If you modify any value, modify also DBG_MOD_ macros below
#define D_KE        "\x80"   ///< Prefix for Kernel
#define D_DBG       "\x81"   ///< Prefix for DBG
#define D_IPC       "\x82"   ///< Prefix for IPC
#define D_DMA       "\x83"   ///< Prefix for DMA
#define D_MM        "\x84"   ///< Prefix for LMAC management
#define D_TX        "\x85"   ///< Prefix for Tx path
#define D_RX        "\x86"   ///< Prefix for Rx path
#define D_PHY       "\x87"   ///< Prefix for Modem / RF
#define D_UTM       "\x88"   ///< Prefix for UTM
#define D_XX1       "\x89"   ///< Prefix unused
#define D_XX2       "\x8A"   ///< Prefix unused
#define D_XX3       "\x8B"   ///< Prefix unused
#define D_XX4       "\x8C"   ///< Prefix unused

// Prefix used for severity filtering
// If you modify any value, modify also DBG_SEV_ macros below
#define D_CRT       "\x9A"   ///< Prefix for critical
#define D_ERR       "\x9B"   ///< Prefix for error
#define D_WRN       "\x9C"   ///< Prefix for warning
#define D_INF       "\x9D"   ///< Prefix for info
#define D_VRB       "\x9E"   ///< Prefix for verbose debug

/// Module filtering macros, used only by debug module
enum dbg_mod_tag
{
    DBG_MOD_IDX_KE = 0,   ///< Bit index for Kernel
    DBG_MOD_IDX_DBG,      ///< Bit index for debug
    DBG_MOD_IDX_IPC,      ///< Bit index for IPC
    DBG_MOD_IDX_DMA,      ///< Bit index for DMA
    DBG_MOD_IDX_MM,       ///< Bit index for LMAC management
    DBG_MOD_IDX_TX,       ///< Bit index for Tx path
    DBG_MOD_IDX_RX,       ///< Bit index for Rx path
    DBG_MOD_IDX_PHY,      ///< Bit index for Modem / RF
    DBG_MOD_IDX_UTM,      ///< Bit index for UTM
    DBG_MOD_IDX_MAX,      ///< Number of modules
};

#define DBG_MOD_MIN     0x80
#define DBG_MOD_MAX     (DBG_MOD_MIN + DBG_MOD_IDX_MAX)

#define DBG_MOD_ALL         0xFFFFFFFF


/// Severity filtering macros, used only by debug module
enum dbg_sev_tag
{
    DBG_SEV_IDX_NONE = 0,   ///< No print allowed
    DBG_SEV_IDX_CRT,        ///< Critical and unspecified allowed only
    DBG_SEV_IDX_ERR,        ///< Error allowed and above
    DBG_SEV_IDX_WRN,        ///< Warning allowed and above
    DBG_SEV_IDX_INF,        ///< Info allowed and above
    DBG_SEV_IDX_VRB,        ///< All allowed
    DBG_SEV_IDX_MAX,        ///< Number of severity levels
    DBG_SEV_ALL             ///< Convenient macro
};

#define DBG_SEV_MIN     0x9A
#define DBG_SEV_MAX     0xA0


#ifdef CFG_DBG
    void dbg_test_print(const char *fmt, ...);
    #define dbg(fmt, ...)   dbg_test_print(fmt, ## __VA_ARGS__)

#else
    #define dbg(fmt, ...)   do {} while (0)
#endif

void uart_puts(const char* str);
void uart_wait_tx_done(void);
uint32_t dbg_snprintf(char *buffer, uint32_t size, const char *fmt, ...);
uint32_t dbg_vsnprintf_offset(char *buffer, uint32_t size, uint32_t offset, const char *fmt, va_list args);

/**
 ****************************************************************************************
 * @brief Execute a pseudo vsnprintf function
 *
 * @param[out] buffer  Output buffer
 * @param[in]  size    Size of the output buffer
 * @param[in]  fmt     Format string
 * @param[in]  args    Variable list of arguments
 *
 * @return Upon successful return, returns the number of characters printed (excluding the
 * null byte used to end output to strings). If the output was truncated due to the size limit,
 * then the return  value  is  the  number  of  characters (excluding  the  terminating
 * null byte) which would have been written to the final string if enough space had been
 * available.  Thus, a return value of size or more means that the output was truncated.
 *
 ****************************************************************************************
 */
#define dbg_vsnprintf(buffer, size, fmt, args) dbg_vsnprintf_offset(buffer, size, 0, fmt, args)


#define PROF_RTOS_TASK_SET(taskid)
#define DBG_CPU_SLEEP_START()
#define DBG_CPU_SLEEP_END()


/**
 *****************************************************************************************
 * @brief Declaration of DEBUG environment.
 * Any module or task will retrieve the DEBUG environment on its own, it is
 * not passed anymore as a parameter to the function handlers
 * of the Debug task.  If an other module wants to make use of the
 * environment of debug, it simply needs to include this file and use
 * the extern global variable.
 *****************************************************************************************
 */
struct debug_env_tag
{
    /// User trace filter (bit set means traces enabled)
    uint32_t    filter_module;
    /// Severity of filter
    uint32_t    filter_severity;
};

/// DEBUG module environment declaration.
extern struct debug_env_tag dbg_env;

/**
 ****************************************************************************************
 * @brief Initialize the debug module
 ****************************************************************************************
 */
void dbg_init(void);

#ifdef CFG_RTOS
#define DBG_MUTEX_ENABLED   0
#define DBG_SUSPEND_ENABLED 1
#if DBG_MUTEX_ENABLED && DBG_SUSPEND_ENABLED
#error "dbg cfg err"
#endif

#if DBG_MUTEX_ENABLED
void dbg_rtos_init(void);
#endif
#endif


/// @} end of group

#endif // _DBG_H_
