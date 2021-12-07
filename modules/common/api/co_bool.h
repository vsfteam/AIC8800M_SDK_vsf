/**
 ****************************************************************************************
 *
 * @file co_bool.h
 *
 * @brief This file replaces the need to include stdint or stdbool typical headers,
 *        which may not be available in all toolchains, and adds new types
 *
 * Copyright (C) RivieraWaves 2011-2019
 *
 * $Rev: $
 *
 ****************************************************************************************
 */

#ifndef _CO_BOOL_H_
#define _CO_BOOL_H_


/**
 ****************************************************************************************
 * @addtogroup CO_BOOL
 * @ingroup COMMON
 * @brief Common boolean standard types (removes use of stdbool).
 *
 * @{
 ****************************************************************************************
 */


/*
 * DEFINES
 ****************************************************************************************
 */


//STDBOOL---------------------------------------------------------------------------------
#if defined(CFG_RWTL) || defined(CFG_RWX1)
///Boolean type
typedef unsigned char bool;
///True value
#define true    1
///False value
#define false   0
#else
#include <stdbool.h>
#endif

/// @} CO_BOOL
#endif // _CO_BOOL_H_
