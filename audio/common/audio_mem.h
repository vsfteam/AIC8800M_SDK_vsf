#ifndef _AUDIO_MEM_H_
#define _AUDIO_MEM_H_

#include "rt_mem.h"

#define audio_heap_init(a, b)       rt_system_heap_init(a, b)
#define audio_malloc(a)             rt_malloc(a)
#define audio_free(a)               rt_free(a)
#define audio_realloc(a, b)         rt_realloc(a, b)
#define audio_calloc(a, b)          rt_calloc(a, b)
#define audio_heap_info(a, b, c)    rt_memory_info(a, b, c)

#endif
