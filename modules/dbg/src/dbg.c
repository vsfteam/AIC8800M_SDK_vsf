/**
 ****************************************************************************************
 *
 * @file dbg.c
 *
 * @brief Definition of the Debug module environment.
 *
 * Copyright (C) RivieraWaves 2011-2019
 *
 ****************************************************************************************
 */

/**
 ****************************************************************************************
 * @addtogroup DEBUG
 * @{
 ****************************************************************************************
 */

/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include "dbg.h"
//#include "dbg_profiling.h"
//#include "dbg_task.h"
//#include "la.h"
//#include "ipc_emb.h"
//#include "rxl_cntrl.h"
//#include "txl_cntrl.h"
//#include "reg_mac_core.h"
//#include "ke_timer.h"
//#include "co_utils.h"
#include <string.h>

#ifdef CFG_RTOS
#include "rtos_al.h"
#endif

/*
 * GLOBAL VARIABLES
 ****************************************************************************************
 */
/// Debug module environment definition. (moved here for host)
struct debug_env_tag dbg_env;

#if defined(CFG_RTOS) && DBG_MUTEX_ENABLED
extern rtos_mutex dbg_mutex;
#endif


void dbg_init(void)
{
    // Reset the environment
    memset(&dbg_env, 0, sizeof(dbg_env));

    // Enable only warnings and more critical per default
    dbg_env.filter_module = DBG_MOD_ALL;
    dbg_env.filter_severity = DBG_SEV_IDX_ERR;
}

#if defined(CFG_RTOS) && DBG_MUTEX_ENABLED
void dbg_rtos_init(void)
{
    if (rtos_mutex_create(&dbg_mutex)) {
        dbg("create dbg_mutex err\n");
    }
}
#endif

/// @} end of group
