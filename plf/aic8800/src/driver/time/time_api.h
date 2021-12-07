/**
 ****************************************************************************************
 *
 * @file time_api.h
 *
 ****************************************************************************************
 */

#ifndef _TIME_API_H_
#define _TIME_API_H_

#include "arch.h"

#include <time.h>
#define TIME_FUNC_GRP_0_IMPL    1
#define TIME_FUNC_GRP_1_IMPL    0

/**
 ****************************************************************************************
 * @defgroup TIME TIME
 * @ingroup PLATFORM_DRIVERS
 * @{
 ****************************************************************************************
 */

/**
 * Time origin
 */
enum time_origin_t {
    /** Since boot time */
    SINCE_BOOT,
    /** Since Epoch : 1970-01-01 00:00:00 +0000 (UTC) */
    SINCE_EPOCH,
};

/**
 ****************************************************************************************
 * @brief Initialize time.
 *
 * @param[in] sec  Number of seconds since Epoch when the system started.
 * @param[in] usec Number of microseconds since Epoch when the system started
 *                 (excluding the seconds in sec).
 ****************************************************************************************
 */
void aic_time_init(uint32_t sec, uint32_t usec);

/**
 ****************************************************************************************
 * @brief Update time.
 *
 * @param[in] sec  Number of seconds since Epoch when the system started.
 * @param[in] usec Number of microseconds since Epoch when the system started
 *                 (excluding the seconds in sec).
 ****************************************************************************************
 */
void aic_time_update(uint32_t sec, uint32_t usec);

/**
 ****************************************************************************************
 * @brief Get current time.
 *
 * return the current time, from the selected origin, in a sec/usec split.
 *
 * @param[in]  origin Select the time origin (Since boot or since Epoch)
 * @param[out] sec    Udapted with the number of seconds since the selected origin.
 * @param[out] usec   Updated with the number of microseconds since the selected origin.
 *                   (excluding the seconds in sec)
 *
 * @return 0 on success and != 0 otherwise.
 ****************************************************************************************
 */
int aic_time_get(enum time_origin_t origin, uint32_t *sec, uint32_t *usec);

/**
 ****************************************************************************************
 * @brief Get current time.
 *
 * return the current time, from the selected origin, in usec.
 *
 * @param[in]  origin Select the time origin (Since boot or since Epoch)
 * @param[out] usec   Updated with the number of microseconds since the selected origin.
 *
 * @return 0 on success and != 0 otherwise.
 ****************************************************************************************
 */
int aic_time_us_get(enum time_origin_t origin, uint64_t *usec);

#if TIME_FUNC_GRP_0_IMPL
#if 0
/* user time, and gmtime compatible functions, there is a gmtime
   implementation here that WINCE uses, so really just need some ticks
   since the EPOCH
*/
struct tm {
int tm_sec;     /* seconds after the minute [0-60] */
int tm_min;     /* minutes after the hour [0-59] */
int tm_hour;    /* hours since midnight [0-23] */
int tm_mday;    /* day of the month [1-31] */
int tm_mon;     /* months since January [0-11] */
int tm_year;    /* years since 1900 */
int tm_wday;    /* days since Sunday [0-6] */
int tm_yday;    /* days since January 1 [0-365] */
int tm_isdst;   /* Daylight Savings Time flag */
long    tm_gmtoff;  /* offset from CUT in seconds */
char    *tm_zone;   /* timezone abbreviation */
};
typedef long time_t;
#endif

#define YEAR0          1900
#define EPOCH_YEAR     1970

struct tm* gmtime_offset_r(const time_t* timer, struct tm *st_time, int offset);
time_t mk_gmtime_offset_r(const struct tm *st_time, int offset);
#endif /* TIME_FUNC_GRP_0_IMPL */

#if TIME_FUNC_GRP_1_IMPL
/* _HT_
The following declarations and functions may be moved to a common directory?
 */
typedef struct xTIME_STRUCT
{
    int tm_sec;   /* Seconds */
    int tm_min;   /* Minutes */
    int tm_hour;  /* Hour (0--23) */
    int tm_mday;  /* Day of month (1--31) */
    int tm_mon;   /* Month (0--11) */
    int tm_year;  /* Year (calendar year minus 1900) */
    int tm_wday;  /* Weekday (0--6; Sunday = 0) */
    int tm_yday;  /* Day of year (0--365) */
    int tm_isdst; /* 0 if daylight savings time is not in effect) */
} FF_TimeStruct_t;

#define GMTIME_FIRST_YEAR       ( 1970 )
#define TM_STRUCT_FIRST_YEAR    ( 1900 )

/* Equivalent of gmtime_r() : Fills a 'struct tm'. */
FF_TimeStruct_t *FreeRTOS_gmtime_r( const time_t *pxTime, FF_TimeStruct_t *pxTimeBuf );

/* Equivalent of mktime() : calculates the number of seconds after 1-1-1970. */
time_t FreeRTOS_mktime( const FF_TimeStruct_t *pxTimeBuf );
#endif /* TIME_FUNC_GRP_1_IMPL */

/**
 * @}
 */
#endif /* _TIME_API_H_ */
