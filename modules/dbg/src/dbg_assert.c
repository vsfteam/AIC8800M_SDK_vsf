/**
 ****************************************************************************************
 *
 * @file dbg_task.c
 *
 * @brief Defines the different debug states and messages handlers used by the debug task
 *
 * Copyright (C) RivieraWaves 2011-2019
 *
 ****************************************************************************************
 */

/**
 ****************************************************************************************
 * @addtogroup ASSERT
 * @{
 ****************************************************************************************
 */

/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include "dbg_assert.h"
#include "dbg.h"
//#include "ke_event.h"
//#include "hal_machw.h"
//#include "reg_sysctrl.h"
#include "arch.h"

/*
 * GLOBAL VARIABLES
 ****************************************************************************************
 */
int dbg_assert_block = 1;

/*
 * FUNCTION DEFINITIONS
 ****************************************************************************************
 */
#if 0
void dbg_assert_rec(const char *condition, const char * file, int line)
{
    // Disable the interrupts
    GLOBAL_INT_DISABLE();

    // Display a trace message showing the error
    TRACE("ASSERT recovery: %F:%d", (line >> 24) , line);
    line = (line & 0xffffff);
    dbg(D_ERR "ASSERT (%s) at %s:%d\n", condition, file, line);

    // Restore the interrupts
    GLOBAL_INT_RESTORE();
}
#endif

void dbg_assert_err(const char *condition, const char * file, int line)
{
    TRACE("ASSERT error: %F:%d", (line >> 24) , line);
    line = (line & 0xffffff);

    // Stop the interrupts
    GLOBAL_INT_STOP();

    // Display a trace message showing the error
    dbg(D_ERR "ASSERT (%s) at %s:%d\n", condition, file, line);

    while(dbg_assert_block);
}

void dbg_assert_warn(const char *condition, const char * file, int line)
{
    TRACE("ASSERT warning: %F:%d", (line >> 24) , line);
    line = (line & 0xffffff);
    dbg(D_ERR "WARNING (%s) at %s:%d\n", condition, file, line);
}


/// @}  // end of group ASSERT
