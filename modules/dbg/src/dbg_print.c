/**
 ****************************************************************************************
 *
 * @file dbg_print.c
 *
 * @brief Implementation of the print functions used for debug
 *
 ****************************************************************************************
 */

/**
 ****************************************************************************************
 * @addtogroup DBG_PRINT
 * @{
 ****************************************************************************************
 */

/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include <stdarg.h>

#include "plf.h"
#include "dbg_assert.h"
//#include "co_math.h"

#include "dbg.h"

#ifndef NULL
#define NULL (void *)0
#endif
#define co_min(A, B)                (((A) < (B)) ? (A) : (B))
#define CO_BIT(pos)                 (1UL<<(pos))

#include "stdio_uart.h"
#include "reg_ipc_mutex.h"

#ifdef CFG_RTOS
#include "rtos_al.h"
#endif

#define FLAG_SHORT_SUPPORTED
#define SUPPORT_LOWER_CASE_HEX

/// States values
enum
{
    S_COPY,         // Initial state; copy chars of the format str
    S_PERCENT,      // just read '%'
    S_FLAGS,        // just read flag character
    S_WIDTH,        // just read width specifier
    S_DOT,          // just read '.'
    S_PRECIS,       // just read field_precision specifier
    S_SIZE,         // just read size specifier
    S_TYPE,         // just read type specifier
    S_MAX
};

/// character type values
enum
{
    C_OTHER,        // character with no special meaning
    C_PERCENT,      // '%'
    C_DOT,          // '.'
    C_ZERO,         // '0'
    C_DIGIT,        // '1'..'9'
    C_FLAG,         // ' ', '+', '-',
    C_SIZE,         // 'h', 'l', 'L'
    C_TYPE,         // type specifying character
    C_MAX
};


/// field_flags used to store the format information
enum
{
    FLAG_SHORT      = (1 << 0),   // short value
    FLAG_LONG       = (1 << 1),   // long value
    FLAG_SIGNED     = (1 << 2),   // signed value
    FLAG_SIGN       = (1 << 3),   // Add a - or + in the front of the field
    FLAG_SIGN_SPACE = (1 << 4),   // Add a space or - in the front of the field
    FLAG_LEFT       = (1 << 5),   // left justify
    FLAG_LEAD_ZERO  = (1 << 6),   // padding with 0
    FLAG_NEGATIVE   = (1 << 7),   // the value is negative
};


/// Transition table
static const uint8_t transition_table[S_MAX][C_MAX] =
{   //              OTHER       PERCENT     DOT         ZERO        DIGIT       FLAG        SIZE        TYPE
/*  S_COPY    */  { S_COPY,     S_PERCENT,  S_COPY,     S_COPY,     S_COPY,     S_COPY,     S_COPY,     S_COPY  },
/*  S_PERCENT */  { S_COPY,     S_COPY,     S_DOT,      S_FLAGS ,   S_WIDTH,    S_FLAGS ,   S_SIZE,     S_TYPE  },
/*  S_FLAGS   */  { S_COPY,     S_COPY,     S_DOT,      S_FLAGS,    S_WIDTH,    S_FLAGS,    S_SIZE,     S_TYPE  },
/*  S_WIDTH   */  { S_COPY,     S_COPY,     S_DOT,      S_WIDTH,    S_WIDTH,    S_COPY,     S_SIZE,     S_TYPE  },
/*  S_DOT     */  { S_COPY,     S_COPY,     S_COPY,     S_PRECIS,   S_PRECIS,   S_COPY,     S_SIZE,     S_TYPE  },
/*  S_PRECIS  */  { S_COPY,     S_COPY,     S_COPY,     S_PRECIS,   S_PRECIS,   S_COPY,     S_SIZE,     S_TYPE  },
/*  S_SIZE    */  { S_COPY,     S_COPY,     S_COPY,     S_COPY,     S_COPY,     S_COPY,     S_COPY,     S_TYPE  },
/*  S_TYPE    */  { S_COPY,     S_PERCENT,  S_COPY,     S_COPY,     S_COPY,     S_COPY,     S_COPY,     S_COPY  },
};


/// Upper case hexadecimal table
static const char hex_upper_table[] = "0123456789ABCDEF";
#ifdef SUPPORT_LOWER_CASE_HEX
/// Lower case hexadecimal table
static const char hex_lower_table[] = "0123456789abcdef";
#endif

#if defined(CFG_RTOS) && DBG_MUTEX_ENABLED
rtos_mutex dbg_mutex;
#endif


/**
 ****************************************************************************************
 * @brief Function to read a particular character and map its type
 *
 * This function is called to read a particular character and fetch its type
 *
 * @param[in] c Input character
 *
 * @return Type of the character
 ****************************************************************************************
 */
static uint32_t type_get(char c)
{
    uint32_t res;

    switch(c)
    {
    case '%':
        res =  C_PERCENT;
        break;

    case '.':
        res =  C_DOT;
        break;

    case '0':
        res =  C_ZERO;
        break;

    case ' ':
    case '+':
    case '-':
        res =  C_FLAG;
        break;

    case 'h':
    case 'l':
        res =  C_SIZE;
        break;

    case 'x':
    case 'X':
    case 'd':
    case 'b':
    case 'i':
    case 'c':
    case 'u':
    case 's':
    case 'm':
    case 'M':
    case 'a':
    case 'A':
    case 'p':
        res =  C_TYPE;
        break;

    case '*':
        res =  C_DIGIT;
        break;

    default:
        if(('1' <= c) && (c <= '9'))
        {
            res =  C_DIGIT;
        }
        else
        {
            res =  C_OTHER;
        }
        break;
    }

    return res;
}

/**
 ****************************************************************************************
 * @brief Execute a pseudo vsnprintf function
 *
 * @param[out] buffer  Output buffer
 * @param[in]  size    Size of the output buffer
 * @param[in]  offset  Offset of final string at which the writing in buffer should start
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
uint32_t dbg_vsnprintf_offset(char *buffer, uint32_t size, uint32_t offset, const char *fmt, va_list args)
{
     uint32_t    state_current = S_COPY;  // Initial state
     char        c;

     char        *fmt_field_ptr = NULL;
     int         fmt_field_size = 0;

     char        buffer_tmp[64];

     int         field_width = 0;
     char        field_flags = 0;
     int         field_precision = 0;
     int         field_padding = 0;

     int32_t     value;
     char        *tmp_ptr = NULL;

     uint32_t    res = 0, remain;

     #define WRITE_CHAR(_c) if (remain && res >= offset) {*buffer++ = (_c); remain--;} res++

     // Check parameters: If buffer is NULL then size MUST be 0.
     if (buffer == NULL)
         size = 0;

     remain = size;

     // For each char in format string
     while ((c = *fmt++) != 0)
     {
         state_current =  transition_table[state_current][type_get(c)];

         switch (state_current)
         {
         case S_COPY  :
             WRITE_CHAR(c);
             break;

         case S_PERCENT:
             // Assign default value for the conversion parameters
             field_width = 0;
             field_flags = 0;
             field_precision = -1;
             break;

         case S_FLAGS:
             // set flag based on which flag character
             switch(c)
             {
             case '-':
                 // left justify
                 field_flags |= FLAG_LEFT;
                 break;
             case '+':
                 // force sign indicator
                 field_flags |= FLAG_SIGN;
                 break;
             case ' ':
                 // force sign or space
                 field_flags |= FLAG_SIGN_SPACE;
                 break;
             case '0':
                 // pad with leading 0
                 field_flags |= FLAG_LEAD_ZERO;
                 break;
             default:
                 ASSERT_ERR(0);
                 break;
             }
             break;

         case S_WIDTH:
             if (c != '*')
             {
                 // add digit to current field width
                 field_width = field_width * 10 + (c - '0');
             }
             else
             {
                 field_width = (int)va_arg(args, int);
             }
             break;

         case S_DOT:
             // Clear the field_precision variable
             field_precision = 0;
             break;

         case S_PRECIS:
             if (c != '*')
             {
                 // Add digit to field_precision variable
                 field_precision = field_precision * 10 + (c - '0');
             }
             else
             {
                 field_precision = (int)va_arg(args, int);
             }
             break;

         case S_SIZE:
             // currently ignored
             switch (c)
             {
             case 'l':
                 // 'l' => long int
                 field_flags |= FLAG_LONG;
                 break;

             #ifdef FLAG_SHORT_SUPPORTED
             case 'h':
                 // 'h' => short int
                 field_flags |= FLAG_SHORT;
                 break;
             #endif // FLAG_SHORT_SUPPORTED

             default:
                 ASSERT_ERR(0);
                 break;
             }
             break;

         case S_TYPE:

             // Now the options have been decoded
             switch (c)
             {
                 // c
                 case 'c':
                     // Store byte in Tx buffer
                     buffer_tmp[0] = (char)va_arg(args, int);
                     fmt_field_ptr = buffer_tmp;
                     fmt_field_size = 1;
                     break;


                 // String
                 case 's':
                     // Read parameter (pointer on string)
                     fmt_field_ptr =  va_arg(args, char *);
                     fmt_field_size = 0;
                     if (fmt_field_ptr != NULL)
                     {
                         // Compute the length of the string
                         // field_precision is the maximum number of character to be display
                         tmp_ptr =  fmt_field_ptr;
                         while (*tmp_ptr != '\0')
                         {
                             if (field_precision == 0)
                                 break;
                             if (field_precision > 0)
                                 field_precision --;
                             tmp_ptr++;
                             fmt_field_size++;
                         }
                     }
                     break;

                 // MAC address
                 case 'm':
                 case 'M':
                     {
                     int i;
                     fmt_field_ptr   = buffer_tmp;
                     tmp_ptr         = va_arg(args, char *);
                     fmt_field_size  = 17;
                     for(i = 5;;)
                     {
                         value = (unsigned char) *tmp_ptr++;
                         *fmt_field_ptr++ = hex_upper_table[value >> 4];
                         *fmt_field_ptr++ = hex_upper_table[value & 0xF];
                         if (i-- == 0) break;
                         *fmt_field_ptr++ = ':';
                     }
                     fmt_field_ptr = buffer_tmp;
                     break;
                     }

                 case 'a':
                 case 'A':
                     fmt_field_ptr = buffer_tmp;
                     tmp_ptr = va_arg(args, char *);
                     // prevent overflow
                     field_width = co_min(field_width, sizeof(buffer_tmp)/3);
                     // if no width given
                     if (!field_width) field_width = 16;
                     fmt_field_size = field_width * 3 - 1 ;
                     for(;;)
                     {
                         value = (unsigned char) *tmp_ptr++;
                         *fmt_field_ptr++ = hex_upper_table[value >> 4];
                         *fmt_field_ptr++ = hex_upper_table[value & 0xF];
                         if (--field_width == 0) break;
                         // sep . (or : on align)
                         if (3 & (uint32_t) tmp_ptr) *fmt_field_ptr++ = '.';
                         else *fmt_field_ptr++ = ':';
                     }
                     fmt_field_ptr = buffer_tmp;
                     break;

                 case 'i':   // signed decimal
                     c = 'd';
                 case 'd':   // signed decimal
                 case 'u':   // unsigned
                 case 'X':   // hexa
                 case 'x':   // hexa
                 case 'b':   // binary
                 case 'p':   // pointer

                     // Point to the last byte of the buffer (go backward during conversion)
                     fmt_field_ptr = buffer_tmp + sizeof(buffer_tmp);
                     fmt_field_size = 0;

                     // Get the value
                     if (field_flags & FLAG_LONG)
                     {
                         // long
                         value = va_arg(args, uint32_t);
                     }
                     #ifdef FLAG_SHORT_SUPPORTED
                     else if(field_flags & FLAG_SHORT)
                     {
                         if (c == 'd')
                         {
                             // extend the sign
                             value = (int16_t) va_arg(args, int);
                         }
                         else
                         {
                             value = (uint16_t) va_arg(args, int);
                         }
                     }
                     #endif // FLAG_SHORT_SUPPORTED
                     else
                     {
                         // int
                         // extend the sign
                         value = va_arg(args, int);
                     }

                     switch (c)
                     {
                     case 'd':
                             // Separate the sign to display it before the number
                             if (value < 0)
                             {
                                 value =  (uint32_t)(-value);
                                 // remember negative sign
                                 field_flags |= FLAG_NEGATIVE;
                             }

                     case 'u':
                             do
                             {
                                 // go backward
                                 fmt_field_ptr--;
                                 *fmt_field_ptr = ('0'+ ((char) (((uint32_t)value) % 10)));
                                 value = ((uint32_t)value) / 10;
                                 fmt_field_size++;
                             }
                             while (value != 0);

                             // Add the sign
                             if (field_flags & FLAG_NEGATIVE)
                             {   // prefix with a '-'
                                 // go backward
                                 fmt_field_ptr--;

                                 *fmt_field_ptr = '-';
                                 fmt_field_size++;
                             }
                             else if (field_flags & FLAG_SIGN)
                             {   // prefix with a '+' (sign is forced)
                                 // go backward
                                 fmt_field_ptr--;
                                 *fmt_field_ptr = '+';
                                 fmt_field_size++;
                             }
                             else if (field_flags & FLAG_SIGN_SPACE)
                             {   // prefix with a ' ' (used instead of '+')
                                 // go backward
                                 fmt_field_ptr--;
                                 *fmt_field_ptr = ' ';
                                 fmt_field_size++;
                             }
                             break;

                     case 'p':
                         field_width  = sizeof(void *) << 1;
                         field_flags |= FLAG_LEAD_ZERO;
                     case 'x':
                         #ifdef SUPPORT_LOWER_CASE_HEX
                             do
                             {
                                 // go backward
                                 fmt_field_ptr--;
                                 *fmt_field_ptr = hex_lower_table[value & 0XFUL];
                                 value = ((uint32_t) value) >> 4;
                                 fmt_field_size++;
                             }
                             while (value != 0);
                             break;
                         #endif

                     case 'X':
                             do
                             {
                                 // go backward
                                 fmt_field_ptr--;
                                 *fmt_field_ptr = hex_upper_table[value & 0XFUL];
                                 value = ((uint32_t) value) >> 4;
                                 fmt_field_size++;
                             }
                             while (value != 0);
                             break;

                     case 'b':
                             do
                             {
                                 // go backward
                                 fmt_field_ptr--;
                                 *fmt_field_ptr = '0' + ((char) (value & 0x01UL));
                                 value = ((uint32_t) value) >> 1;
                                 fmt_field_size++;
                             }
                             while (value != 0);
                             break;
                     default:
                         //ASSERT_ERR(0);
                         break;
                     } // embedded switch type

                     default:
                         //ASSERT_ERR(0);
                         break;
             } // switch type


             // Add padding
             field_padding = field_width - fmt_field_size;

             // put out the padding, prefix, and text, in the correct order
             if (field_flags & FLAG_LEAD_ZERO)
             {
                 // Add leading zeros
                 while (field_padding > 0)
                 {
                     WRITE_CHAR('0');
                     field_padding--;
                 }
             }
             else if (!(field_flags & FLAG_LEFT))
             {
                 while (field_padding > 0)
                 {
                     WRITE_CHAR(' ');
                     field_padding--;
                 }
             }

             // Copy the formated field
             while (fmt_field_size > 0)
             {
                 WRITE_CHAR(*fmt_field_ptr);
                 fmt_field_ptr++;
                 fmt_field_size--;
             }

             // Add blanks at the rigth (means (field_flags & FLAG_LEFT))
             while ((field_padding > 0))
             {
                 WRITE_CHAR(' ');
                 field_padding--;
             }
             break;

         default:
             ASSERT_ERR(0);
         } // switch state
     } // while

     #undef WRITE_CHAR

     if (remain)
     {
         *buffer = '\0';
     }
     else if (size)
     {
         buffer[-1] = '\0';
     }

     return res;
}

int uart_printf(const char *format, va_list arg)
{
    char buffer[256];
    uint32_t isr_active = __get_IPSR();
    #if defined(CFG_RTOS) && (DBG_MUTEX_ENABLED || DBG_SUSPEND_ENABLED)
    int norm_task = ((__get_CONTROL() & (0x01UL << 1)) && // psp
                     (rtos_get_task_handle() != xTaskGetIdleTaskHandle())) ? 1 : 0;
    #endif
    int size = dbg_vsnprintf(buffer, 256, format, arg);
    if (size > 0) {
        if (!stdio_uart_inited) {
            stdio_uart_init();
        }
        if (!isr_active
            #if defined(CFG_RTOS)
            && norm_task
            #endif
            ) {
            #if defined(CFG_RTOS) && DBG_MUTEX_ENABLED
            rtos_mutex_lock(dbg_mutex, -1);
            #endif
            while(!ipc_mutex_get(IPC_MUTEX_UART_OUTPUT)) {  // lock mutex
                #if defined(CFG_RTOS) && DBG_SUSPEND_ENABLED
                rtos_task_suspend(1);
                #endif
            }
        }
#if 0
        for (int i = 0; i < size; i++) {
            stdio_uart_putc(buffer[i]);
        }
#else
        char stdio_out_prev = '\0';
        for (int i = 0; i < size; i++) {
            if (buffer[i] == '\n' && stdio_out_prev != '\r') {
                stdio_uart_putc('\r');
            }
            stdio_uart_putc(buffer[i]);
            stdio_out_prev = buffer[i];
        }
#endif
        if (!isr_active
            #if defined(CFG_RTOS)
            && norm_task
            #endif
            ) {
            ipc_mutex_set(IPC_MUTEX_UART_OUTPUT, 1);    // unlock mutex
            #if defined(CFG_RTOS) && DBG_MUTEX_ENABLED
            rtos_mutex_unlock(dbg_mutex);
            #endif
        }
    }
    return size;
}

void uart_puts(const char* str)
{
    char stdio_out_prev = '\0';
    while (*str) {
        if (*str == '\n' && stdio_out_prev != '\r') {
            stdio_uart_putc('\r');
        }
        stdio_uart_putc(*str);
        stdio_out_prev = *str;
        str++;
    }
}

void uart_wait_tx_done(void)
{
    while (!stdio_uart_tx_dbuf_empty_getf()) {
        __NOP(); __NOP(); __NOP(); __NOP();
    }
}

/**
 ****************************************************************************************
 * @brief Function formatting a string and sending it to the defined output
 *
 * @param[in] fmt Format string
 *
 ****************************************************************************************
 */
void dbg_test_print(const char *fmt, ...)
{
    const char *fmt_usr = (const char*) fmt;
    uint32_t severity = 0;

    //printf ("%d %d %d %d\n", fmt_usr[0], fmt_usr[1], DBG_MOD_MAX, DBG_SEV_MIN);

    if (dbg_env.filter_severity == 0) return;

    do
    {
        // Get the prefix
        unsigned char prefix = ((unsigned char)*fmt_usr) & 0xFF;

        // ASCII char, start of the user string
        if (prefix < DBG_MOD_MIN) break;

        if (prefix < DBG_MOD_MAX)
        {
            // test module, if filtered returns
            if (~dbg_env.filter_module & CO_BIT(prefix - DBG_MOD_MIN)) return;
        }
        else
        {
            // must be severity code
            ASSERT_ERR(DBG_SEV_MIN <= prefix && prefix < DBG_SEV_MAX);
            severity = (uint32_t)(prefix - DBG_SEV_MIN);

            // test severity, if filtered returns
            if (dbg_env.filter_severity <= severity) return;
        }

        // Check first and second char
        fmt_usr++;
    }
    while (fmt_usr != fmt + 2);

    // print
    va_list args;
    va_start(args, fmt);

    uart_printf(fmt_usr, args);

    va_end(args);
}

/**
 ****************************************************************************************
 * @brief Execute a pseudo snprintf function
 *
 * @param[out] buffer  Output buffer
 * @param[in]  size    Size of the output buffer
 * @param[in]  fmt     Format string
 *
 * @return Upon successful return, returns the number of characters printed (excluding the
 * null byte used to end output to strings). If the output was truncated due to the size limit,
 * then the return  value  is  the  number  of  characters (excluding  the  terminating
 * null byte) which would have been written to the final string if enough space had been
 * available.  Thus, a return value of size or more means that the output was truncated.
 *
 ****************************************************************************************
 */
uint32_t dbg_snprintf(char *buffer, uint32_t size, const char *fmt, ...)
{
    uint32_t ret;
    const char *fmt_usr = (const char*) fmt;

    // print
    va_list args;
    va_start(args, fmt);

    ret = dbg_vsnprintf(buffer, size, fmt_usr, args);

    va_end(args);

    return ret;
}

/// @}
