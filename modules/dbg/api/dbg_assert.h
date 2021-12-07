/**
 ****************************************************************************************
 *
 * @file dbg_assert.h
 *
 * @brief File containing the definitions of the assertion macros.
 *
 ****************************************************************************************
 */

#ifndef _DBG_ASSERT_H_
#define _DBG_ASSERT_H_

/**
 ****************************************************************************************
 * @defgroup ASSERT ASSERT
 * @ingroup DEBUG
 * @brief Assertion management module
 * @{
 ****************************************************************************************
 */

/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include "plf.h"
#include "compiler.h"
#include "ll.h"

/*
 * DEFINES
 ****************************************************************************************
 */
#if 0 //NX_TRACE
/// Line number: Include file id if trace is enabled
#define LINE_NB ((TRACE_FILE_ID << 24) + (__LINE__ & 0xffffff))
#else
/// Line number
#define LINE_NB __LINE__
#endif

/*
 * ASSERTION CHECK
 ****************************************************************************************
 */

extern int dbg_assert_block;

/**
 ****************************************************************************************
 * @brief Print the assertion error reason and trigger the recovery procedure.
 *
 * @param[in] condition C string containing the condition.
 * @param[in] file C string containing file where the assertion is located.
 * @param[in] line Line number in the file where the assertion is located.
 ****************************************************************************************
 */
void dbg_assert_rec(const char *condition, const char * file, int line);

/**
 ****************************************************************************************
 * @brief Print the assertion error reason and loop forever.
 *
 * @param[in] condition C string containing the condition.
 * @param[in] file C string containing file where the assertion is located.
 * @param[in] line Line number in the file where the assertion is located.
 ****************************************************************************************
 */
void dbg_assert_err(const char *condition, const char * file, int line);

/**
 ****************************************************************************************
 * @brief Print the assertion warning reason.
 *
 * @param[in] condition C string containing the condition.
 * @param[in] file C string containing file where the assertion is located.
 * @param[in] line Line number in the file where the assertion is located.
 ****************************************************************************************
 */
void dbg_assert_warn(const char *condition, const char * file, int line);

/// Macro defining the format of the assertion calls
#ifdef CFG_DBG
#define DBG_ASSERT(type, cond) dbg_assert_##type(cond, __MODULE__, LINE_NB)
#else
#define DBG_ASSERT(type, cond) dbg_assert_##type("", "", 0)
#endif

#ifdef CFG_DBG
/// Assertions showing a critical error that could require a full system reset
#define ASSERT_ERR(cond)                                                                 \
    do {                                                                                 \
        if (!(cond)) {                                                                   \
            DBG_ASSERT(err, #cond);                                                          \
        }                                                                                \
    } while(0)

/// Assertions showing a critical error that could require a full system reset

#define ASSERT_ERR2B(fmt, ...) dbg_test_print(fmt, ##__VA_ARGS__)

#define ASSERT_ERR2A(fmt, ...) \
    do { \
        GLOBAL_INT_STOP(); \
        ASSERT_ERR2B(fmt, ##__VA_ARGS__); \
        while (dbg_assert_block); \
    } while (0)

#define ASSERT_ERR2(cond, fmt, ...) \
    do { \
        if (!(cond)) { \
            ASSERT_ERR2A(D_ERR "ASSERT_ERR (%s) at %s:%d "fmt, #cond, __MODULE__, LINE_NB, ##__VA_ARGS__); \
        } \
    } while (0)

/// Assertions showing a non-critical problem that has to be fixed by the SW
#define ASSERT_WARN(cond)                                                                \
    do {                                                                                 \
        if (!(cond)) {                                                                   \
            DBG_ASSERT(warn, #cond);                                                         \
        }                                                                                \
    } while(0)

#ifdef CFG_BLE_STACK
#define ASSERT_INFO(cond, param0, param1)            { if (!(cond)) { TRACE("line is %d file is %s\r\n", __LINE__, __FILE__);} }
#else
#define ASSERT_INFO(cond, param0, param1)            { if (!(cond)) { TRACE("line is %d file is %s", __LINE__, __FILE__); ASSERT_ERR(0);} }
#endif

#else
/// Assertions showing a critical error that could require a full system reset
#define ASSERT_ERR(cond)
/// Assertions showing a critical error that could require a full system reset
#define ASSERT_ERR2(cond, fmt, ...)
/// Assertions showing a non-critical problem that has to be fixed by the SW
#define ASSERT_WARN(cond)
#define ASSERT_INFO(cond, param0, param1)
#endif

#if 0
/// Assertions that trigger the automatic recovery mechanism and return void
#define ASSERT_REC(cond)                                                                 \
    ({                                                                                   \
        if (!(cond)) {                                                                   \
            ASSERT(rec, #cond);                                                          \
            return;                                                                      \
        }                                                                                \
    })

/// Assertions that trigger the automatic recovery mechanism and return a value
#define ASSERT_REC_VAL(cond, ret)                                                        \
    ({                                                                                   \
        if (!(cond)) {                                                                   \
            ASSERT(rec, #cond);                                                          \
            return (ret);                                                                \
        }                                                                                \
    })

/// Assertions that trigger the automatic recovery mechanism and do not return
#define ASSERT_REC_NO_RET(cond)                                                          \
    ({                                                                                   \
        if (!(cond)) {                                                                   \
            ASSERT(rec, #cond);                                                          \
        }                                                                                \
    })
#else
/// Assertions that trigger the automatic recovery mechanism and return void
#define ASSERT_REC(cond)             ASSERT_ERR(cond)

/// Assertions that trigger the automatic recovery mechanism and return a value
#define ASSERT_REC_VAL(cond, ret)    ASSERT_ERR(cond)

/// Assertions that trigger the automatic recovery mechanism and do not return
#define ASSERT_REC_NO_RET(cond)      ASSERT_ERR(cond)
#endif


/// @}  // end of group ASSERT

#endif // _DBG_ASSERT_H_
