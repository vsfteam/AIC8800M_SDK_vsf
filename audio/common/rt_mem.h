#ifndef _RT_MEM_H_
#define _RT_MEM_H_

#include <stdint.h>
#include <stddef.h>

typedef uint8_t  rt_uint8_t;
typedef uint16_t rt_uint16_t;
typedef uint32_t rt_uint32_t;
typedef size_t   rt_size_t;

/*
 * heap memory interface
 */
void rt_system_heap_init(void *begin_addr, void *end_addr);

void *rt_malloc(rt_size_t nbytes);
void rt_free(void *ptr);
void *rt_realloc(void *ptr, rt_size_t nbytes);
void *rt_calloc(rt_size_t count, rt_size_t size);

void rt_memory_info(rt_uint32_t *total,
                    rt_uint32_t *used,
                    rt_uint32_t *max_used);

#ifdef RT_USING_HOOK
void rt_malloc_sethook(void (*hook)(void *ptr, rt_size_t size));
void rt_free_sethook(void (*hook)(void *ptr));
#endif

#endif
