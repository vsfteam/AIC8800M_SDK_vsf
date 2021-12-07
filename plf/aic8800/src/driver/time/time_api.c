/**
 ****************************************************************************************
 *
 * @file time_api.c
 *
 ****************************************************************************************
 */
/**
 ****************************************************************************************
 * @addtogroup TIME
 * @{
 ****************************************************************************************
 */

#include "time_api.h"

#define USE_LP_TICKER_READ      1
#define USE_RTOS_TICKCOUNT      0

#if USE_LP_TICKER_READ
#include "lp_ticker_api.h"
#elif USE_RTOS_TICKCOUNT
#include "rtos_al.h"
#endif

static uint32_t epoch_sec;
static uint32_t epoch_usec;
#if USE_LP_TICKER_READ
static const ticker_data_t *lp_tick_d = NULL;
#endif /* USE_LP_TICKER_READ */

void aic_time_init(uint32_t sec, uint32_t usec)
{
    epoch_sec = sec;
    epoch_usec = usec;
#if USE_LP_TICKER_READ
    if (lp_tick_d == NULL) {
        lp_tick_d = get_lp_ticker_data();
        ticker_read_us(lp_tick_d);
    }
#endif /* USE_LP_TICKER_READ */
}

void aic_time_update(uint32_t sec, uint32_t usec)
{
#if USE_LP_TICKER_READ
    if (lp_tick_d == NULL) {
        aic_time_init(sec, usec);
    } else {
        uint64_t cur_us = ticker_read_us(lp_tick_d);
        uint64_t epo_us = ((uint64_t)sec) * 1000000 + usec - cur_us;
        uint32_t msb, lsb, _sec, _usec, tmp, fact = 0x8637bd;
        /* 52bits time value is divided in 5 parts 0xABBCCDDDDEEEE
        factor = 0x8637bd = 1 / 1000000 in Q43 = ((1<<43) / 1000000) */
        msb = (uint32_t)(epo_us >> 32);
        lsb = (uint32_t)epo_us;
        tmp = ((msb >> 8) & 0xff) * fact;
        _sec = (tmp >> 3);
        tmp = (msb & 0xff) * fact;
        _sec += (tmp >> 11);
        fact >>= 1;
        tmp = (msb >> 16) * fact;
        _sec += (tmp << 6);
        fact >>= 7;
        tmp = (lsb >> 16) * fact;
        _sec += (tmp >> 19);
        _usec = lsb - (_sec * 1000000);
        epoch_sec = _sec;
        epoch_usec = _usec;
    }
#endif /* USE_LP_TICKER_READ */
}

/**
 ****************************************************************************************
 * @brief Read two part monotic counter 2
 *
 * Read msb twice to detect if counter wrap while reading it.
 *
 * @param[out] msb Updated with msb part of the counter (16bits only)
 * @param[out] lsb Updated with lsb part of the counter (32bits)
 ****************************************************************************************
 */
void aic_time_read(uint32_t *msb, uint32_t *lsb)
{
#if USE_LP_TICKER_READ
    uint64_t cur_us = ticker_read_us(lp_tick_d);
    *msb = (uint32_t)(cur_us >> 32);
    *lsb = (uint32_t)cur_us;
#elif USE_RTOS_TICKCOUNT
    uint64_t cur_us = rtos_now(false) * 1000;
    *msb = (uint32_t)(cur_us >> 32);
    *lsb = (uint32_t)cur_us;
#endif
}

int aic_time_get(enum time_origin_t origin, uint32_t *sec, uint32_t *usec)
{
    uint32_t msb, lsb, _sec, _usec, tmp, fact;

    if (origin > SINCE_EPOCH)
        return -1;

    aic_time_read(&msb, &lsb);

    /* Replace uint64_t / 1000000 (uint48_t in practice)
       by 3 ~fmul (mul + shift).
       Yes this is more complicated but also 20 times faster on cpu without div
       instruction.
       48bits time value is divided in 4 parts 0xAABBCCCCDDDD
       First two parts (A ,B) are only 8bits to allow more bits in the factor
       (merging this two parts with a 16 bits factor doesn't provide enough precision).
       For the third part (C) a factor on 16bits is enough so part is also 16bits.
       Fourth part (D) is always < 1000000 so no need to divide it.
       factor = 0x8637bd = 1 / 1000000 in Q43 = ((1<<43) / 1000000) (truncated on 24bits)
     */
    fact = 0x8637bd;
    tmp = (msb >> 8) * fact;
    _sec = (tmp >> 3);
    tmp = (msb & 0xff) * fact;
    _sec += (tmp >> 11);
    fact >>= 8;
    tmp = (lsb >> 16) * fact;
    _sec += (tmp >> 19);
    _usec = lsb - (_sec * 1000000);

    if (origin == SINCE_EPOCH)
    {
        _sec += epoch_sec;
        _usec += epoch_usec;

    }

    /* Previous computation ensure that loop won't run more than 2 times */
    while (_usec > 1000000)
    {
        _usec -= 1000000;
        _sec ++;
    }

    *sec = _sec;
    *usec = _usec;

    return 0;
}

int aic_time_us_get(enum time_origin_t origin, uint64_t *usec)
{
    uint32_t msb, lsb;
    uint64_t val;

    if (origin > SINCE_EPOCH)
        return -1;

    aic_time_read(&msb, &lsb);
    val = ((uint64_t)msb << 32) + (uint64_t)lsb;

    if (origin == SINCE_EPOCH)
    {
        val += (uint64_t)epoch_usec;
        val += (uint64_t)(epoch_sec * 1000000);
    }

    *usec = val;
    return 0;
}

#if TIME_FUNC_GRP_0_IMPL
#define SECS_DAY       (24L * 60L * 60L)
#define LEAPYEAR(year) (!((year) % 4) && (((year) % 100) || !((year) %400)))
#define YEARSIZE(year) (LEAPYEAR(year) ? 366 : 365)

struct tm* gmtime_offset_r(const time_t* timer, struct tm *st_time, int offset)
{
    static const int _ytab[2][12] =
    {
        {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    };

    struct tm* ret = st_time;
    time_t secs = *timer + (offset * 60L * 60L);
    unsigned long dayclock, dayno;
    int year = EPOCH_YEAR;

    dayclock = (unsigned long)secs % SECS_DAY;
    dayno    = (unsigned long)secs / SECS_DAY;

    ret->tm_sec  = (int) dayclock % 60;
    ret->tm_min  = (int)(dayclock % 3600) / 60;
    ret->tm_hour = (int) dayclock / 3600;
    ret->tm_wday = (int) (dayno + 4) % 7;        /* day 0 a Thursday */

    while(dayno >= (unsigned long)YEARSIZE(year)) {
        dayno -= YEARSIZE(year);
        year++;
    }

    ret->tm_year = year - YEAR0;
    ret->tm_yday = (int)dayno;
    ret->tm_mon  = 0;

    while(dayno >= (unsigned long)_ytab[LEAPYEAR(year)][ret->tm_mon]) {
        dayno -= _ytab[LEAPYEAR(year)][ret->tm_mon];
        ret->tm_mon++;
    }
    ret->tm_mon++;

    ret->tm_mday  = (int)++dayno;
    ret->tm_isdst = 0;

    return ret;
}

time_t mk_gmtime_offset_r(const struct tm *st_time, int offset)
{
    /* Get year AD. */
    int i4_year = YEAR0 + st_time->tm_year; /* 20xx */
    /* Get month zero-based. */
    int i4_month = st_time->tm_mon;         /* 0..11 */
    uint32_t u4_days;
    uint32_t u4_result;

    u4_days = st_time->tm_mday - 1;    /* 1..31 */

    /* Make March the first month. */
    i4_month -= 2;
    if (i4_month < 0) {
        /* January or February: leap day has yet to come for this year. */
        i4_year--;
        i4_month += 12;
    }

    /* Add the number of days past until this month. */
    u4_days += ((306 * i4_month) + 5) / 10;

    /* Add days past before this year: */
    u4_days +=
        + (i4_year * 365)       /* Every normal year. */
        + (i4_year / 4)         /* Plus a day for every leap year. */
        - (i4_year / 100)       /* Minus the centuries. */
        + (i4_year / 400)       /* Except every fourth century. */
        - ((1970 * 365) + (1970 / 4) - (1970 / 100) + (1970 / 400)) /* Minus the days before 1-1-1970 */
        + (59);                 /* Because 2 months were subtracted. */

    u4_result =
        (u4_days * SECS_DAY) +
        (st_time->tm_hour * (60 * 60)) +
        (st_time->tm_min * 60) +
        st_time->tm_sec - (offset * 60 * 60);

    return u4_result;
}
#endif /* TIME_FUNC_GRP_0_IMPL */

#if TIME_FUNC_GRP_1_IMPL
#define SECONDS_PER_MINUTE      ( 60 )
#define MINUTES_PER_HOUR        ( 60 )
#define HOURS_PER_DAY           ( 24 )
#define SECONDS_PER_HOUR        ( MINUTES_PER_HOUR * SECONDS_PER_MINUTE )
#define SECONDS_PER_DAY         ( HOURS_PER_DAY * SECONDS_PER_HOUR )

/* The first weekday in 'FF_TimeStruct_t' is Sunday. */
#define WEEK_DAY_SUNDAY         0
#define WEEK_DAY_MONNDAY        1
#define WEEK_DAY_TUESDAY        2
#define WEEK_DAY_WEDNESDAY      3
#define WEEK_DAY_THURSDAY       4
#define WEEK_DAY_FRIDAY         5
#define WEEK_DAY_SATURDAY       6

/* Make a bitmask with a '1' for each 31-day month. */
#define _MM(month)              ( 1u << ( month - 1 ) )
#define    MASK_LONG_MONTHS     ( _MM(1) | _MM(3) | _MM(5) | _MM(7) | _MM(8) | _MM(10) | _MM(12) )

#define DAYS_UNTIL_1970         ( ( 1970 * 365 ) + ( 1970 / 4 ) - ( 1970 / 100 ) + ( 1970 / 400 ) )
#define DAYS_BEFORE_MARCH       ( 59 )

__STATIC_INLINE int iIsLeapyear( int iYear )
{
int iReturn;

    if( ( iYear % 4 ) != 0 )
    {
        /* Not a multiple of 4 years. */
        iReturn = 0;
    }
    else if( ( iYear % 400 ) == 0 )
    {
        /* Every 4 centuries there is a leap year */
        iReturn = 1;
    }
    else if( ( iYear % 100 ) == 0 )
    {
        /* Other centuries are not a leap year */
        iReturn = 0;
    }
    else
    {
        /* Otherwise every fourth year. */
        iReturn = 1;
    }

    return iReturn;
}

__STATIC_INLINE unsigned long ulDaysPerYear( int iYear )
{
int iDays;

    if( iIsLeapyear( iYear ) )
    {
        iDays = 366;
    }
    else
    {
        iDays = 365;
    }

    return iDays;
}

static int iDaysPerMonth( int iYear, int iMonth )
{
int iDays;

    /* Month is zero-based, 1 is February. */
    if (iMonth != 1 )
    {
        /* 30 or 31 days? */
        if(  ( MASK_LONG_MONTHS & ( 1u << iMonth ) ) != 0 )
        {
            iDays = 31;
        }
        else
        {
            iDays = 30;
        }
    }
    else if( iIsLeapyear( iYear ) == 0 )
    {
        /* February, non leap year. */
        iDays = 28;
    }
    else
    {
        /* February, leap year. */
        iDays = 29;
    }
    return iDays;
}

FF_TimeStruct_t *FreeRTOS_gmtime_r( const time_t *pxTime, FF_TimeStruct_t *pxTimeBuf )
{
time_t xTime = *pxTime;
unsigned long ulDaySeconds, ulDayNumber;
int iYear = GMTIME_FIRST_YEAR;
int iMonth;

    /* Clear all fields, some might not get set here. */
    memset( ( void * )pxTimeBuf, '\0', sizeof( *pxTimeBuf ) );

    /* Seconds since last midnight. */
    ulDaySeconds = ( unsigned long ) ( xTime % SECONDS_PER_DAY ) ;

    /* Days since 1 Jan 1970. */
    ulDayNumber = ( unsigned long ) ( xTime / SECONDS_PER_DAY ) ;

    /* Today's HH:MM:SS */
    pxTimeBuf->tm_hour = ulDaySeconds / SECONDS_PER_HOUR;
    pxTimeBuf->tm_min = ( ulDaySeconds % SECONDS_PER_HOUR ) / 60;
    pxTimeBuf->tm_sec = ulDaySeconds % 60;

    /* Today's week day, knowing that 1-1-1970 was a THursday. */
    pxTimeBuf->tm_wday = ( ulDayNumber + WEEK_DAY_THURSDAY ) % 7;

    for( ; ; )
    {
        /* Keep subtracting 365 (or 366) days while possible. */
        unsigned long ulDays = ulDaysPerYear( iYear );
        if( ulDayNumber < ulDays )
        {
            break;
        }
        ulDayNumber -= ulDays;
        iYear++;
    }
    /* Subtract 1900. */
    pxTimeBuf->tm_year = iYear - TM_STRUCT_FIRST_YEAR;

    /* The day within this year. */
    pxTimeBuf->tm_yday = ulDayNumber;

    /* Month are counted as 0..11 */
    iMonth = 0;
    for( ; ; )
    {
        unsigned long ulDays = iDaysPerMonth( iYear, iMonth );
        /* Keep subtracting 30 (or 28, 29, or 31) days while possible. */
        if( ulDayNumber < ulDays )
        {
            break;
        }
        ulDayNumber -= ulDays;
        iMonth++;
    }
    pxTimeBuf->tm_mon = iMonth;

    /* Month days are counted as 1..31 */
    pxTimeBuf->tm_mday = ulDayNumber + 1;

    return pxTimeBuf;
}

time_t FreeRTOS_mktime( const FF_TimeStruct_t *pxTimeBuf )
{
/* Get year AD. */
int iYear = 1900 + pxTimeBuf->tm_year;  /* 20xx */
/* Get month zero-based. */
int iMonth = pxTimeBuf->tm_mon;         /* 0..11 */
uint32_t ulDays;
uint32_t ulResult;

    ulDays = pxTimeBuf->tm_mday - 1;    /* 1..31 */

    /* Make March the first month. */
    iMonth -= 2;
    if( iMonth < 0 )
    {
        /* January or February: leap day has yet to come for this year. */
        iYear--;
        iMonth += 12;
    }

    /* Add the number of days past until this month. */
    ulDays += ( ( 306 * iMonth ) + 5 ) / 10;

    /* Add days past before this year: */
    ulDays +=
        + ( iYear * 365 )       /* Every normal year. */
        + ( iYear / 4 )         /* Plus a day for every leap year. */
        - ( iYear / 100 )       /* Minus the centuries. */
        + ( iYear / 400 )       /* Except every fourth century. */
        - ( DAYS_UNTIL_1970 )   /* Minus the days before 1-1-1970 */
        + ( DAYS_BEFORE_MARCH );/* Because 2 months were subtracted. */

    ulResult =
        ( ulDays * SECONDS_PER_DAY ) +
        ( pxTimeBuf->tm_hour * SECONDS_PER_HOUR ) +
        ( pxTimeBuf->tm_min * SECONDS_PER_MINUTE ) +
        pxTimeBuf->tm_sec;

    return ulResult;
}
#endif /* TIME_FUNC_GRP_1_IMPL */

/**
 * @}
 */
