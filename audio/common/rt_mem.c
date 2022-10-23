/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2008-7-12      Bernard      the first version
 * 2010-06-09     Bernard      fix the end stub of heap
 *                             fix memory check in rt_realloc function
 * 2010-07-13     Bernard      fix RT_ALIGN issue found by kuronca
 * 2010-10-14     Bernard      fix rt_realloc issue when realloc a NULL pointer.
 * 2017-07-14     armink       fix rt_realloc issue when new size is 0
 */

/*
 * Copyright (c) 2001-2004 Swedish Institute of Computer Science.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
 * SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 *
 * This file is part of the lwIP TCP/IP stack.
 *
 * Author: Adam Dunkels <adam@sics.se>
 *         Simon Goldschmidt
 *
 */

#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include "rt_mem.h"
#include "rtos.h"
#include "dbg.h"
#include "dbg_assert.h"
#include "ll.h"


/* #define RT_MEM_DEBUG */
#define RT_MEM_STATS
#define RT_USING_HEAP
#define RT_USING_SMALL_MEM
//#define RT_MEM_INFO

#if defined (RT_USING_HEAP) && defined (RT_USING_SMALL_MEM)
#ifdef RT_USING_HOOK
static void (*rt_malloc_hook)(void *ptr, rt_size_t size);
static void (*rt_free_hook)(void *ptr);

/**
 * @addtogroup Hook
 */

/**@{*/

/**
 * This function will set a hook function, which will be invoked when a memory
 * block is allocated from heap memory.
 *
 * @param hook the hook function
 */
void rt_malloc_sethook(void (*hook)(void *ptr, rt_size_t size))
{
    rt_malloc_hook = hook;
}

/**
 * This function will set a hook function, which will be invoked when a memory
 * block is released to heap memory.
 *
 * @param hook the hook function
 */
void rt_free_sethook(void (*hook)(void *ptr))
{
    rt_free_hook = hook;
}

/**@}*/

#endif

#ifdef RT_USING_HOOK
#define RT_OBJECT_HOOK_CALL(func, argv) \
    do { if ((func) != NULL) func argv; } while (0)
#else
#define RT_OBJECT_HOOK_CALL(func, argv)
#endif

#define HEAP_MAGIC 0x1ea0
struct heap_mem
{
    /* magic and used flag */
    rt_uint16_t magic;
    rt_uint16_t used;

    rt_size_t next, prev;

#ifdef RT_USING_MEMTRACE
    rt_uint8_t thread[4];   /* thread name */
#endif
};

/** pointer to the heap: for alignment, heap_ptr is now a pointer instead of an array */
static rt_uint8_t *heap_ptr;

/** the last entry, always unused! */
static struct heap_mem *heap_end;

#define RT_ALIGN(size, align)           (((size) + (align) - 1) & ~((align) - 1))
#define RT_ALIGN_DOWN(size, align)      ((size) & ~((align) - 1))
#define RT_ALIGN_SIZE 4
#define MIN_SIZE 4//12
#define MIN_SIZE_ALIGNED     RT_ALIGN(MIN_SIZE, RT_ALIGN_SIZE)
#define SIZEOF_STRUCT_MEM    RT_ALIGN(sizeof(struct heap_mem), RT_ALIGN_SIZE)

#define RT_ASSERT ASSERT_ERR
#define RT_DEBUG_NOT_IN_INTERRUPT

static struct heap_mem *lfree;   /* pointer to the lowest free block */

static rtos_semaphore heap_sem;
static rt_size_t mem_size_aligned;

#ifdef RT_MEM_STATS
static rt_size_t used_mem, max_mem;
#endif
#ifdef RT_USING_MEMTRACE
__STATIC_FORCEINLINE void rt_mem_setname(struct heap_mem *mem, const char *name)
{
    int index;
    for (index = 0; index < sizeof(mem->thread); index ++)
    {
        if (name[index] == '\0') break;
        mem->thread[index] = name[index];
    }

    for (; index < sizeof(mem->thread); index ++)
    {
        mem->thread[index] = ' ';
    }
}
#endif

static void plug_holes(struct heap_mem *mem)
{
    struct heap_mem *nmem;
    struct heap_mem *pmem;

    RT_ASSERT((rt_uint8_t *)mem >= heap_ptr);
    RT_ASSERT((rt_uint8_t *)mem < (rt_uint8_t *)heap_end);
    RT_ASSERT(mem->used == 0);

    /* plug hole forward */
    nmem = (struct heap_mem *)&heap_ptr[mem->next];
    if (mem != nmem &&
        nmem->used == 0 &&
        (rt_uint8_t *)nmem != (rt_uint8_t *)heap_end)
    {
        /* if mem->next is unused and not end of heap_ptr,
         * combine mem and mem->next
         */
        if (lfree == nmem)
        {
            lfree = mem;
        }
        mem->next = nmem->next;
        ((struct heap_mem *)&heap_ptr[nmem->next])->prev = (rt_uint8_t *)mem - heap_ptr;
    }

    /* plug hole backward */
    pmem = (struct heap_mem *)&heap_ptr[mem->prev];
    if (pmem != mem && pmem->used == 0)
    {
        /* if mem->prev is unused, combine mem and mem->prev */
        if (lfree == mem)
        {
            lfree = pmem;
        }
        pmem->next = mem->next;
        ((struct heap_mem *)&heap_ptr[mem->next])->prev = (rt_uint8_t *)pmem - heap_ptr;
    }
}

/**
 * @ingroup SystemInit
 *
 * This function will initialize system heap memory.
 *
 * @param begin_addr the beginning address of system heap memory.
 * @param end_addr the end address of system heap memory.
 */
void rt_system_heap_init(void *begin_addr, void *end_addr)
{
    struct heap_mem *mem;
    rt_uint32_t begin_align = RT_ALIGN((rt_uint32_t)begin_addr, RT_ALIGN_SIZE);
    rt_uint32_t end_align = RT_ALIGN_DOWN((rt_uint32_t)end_addr, RT_ALIGN_SIZE);

    RT_DEBUG_NOT_IN_INTERRUPT;

    /* alignment addr */
    if ((end_align > (2 * SIZEOF_STRUCT_MEM)) &&
        ((end_align - 2 * SIZEOF_STRUCT_MEM) >= begin_align))
    {
        /* calculate the aligned memory size */
        mem_size_aligned = end_align - begin_align - 2 * SIZEOF_STRUCT_MEM;
    }
    else
    {
        dbg("%s, error begin address 0x%x, and end address 0x%x\n",
                   __func__, (rt_uint32_t)begin_addr, (rt_uint32_t)end_addr);

        return;
    }

    /* point to begin address of heap */
    heap_ptr = (rt_uint8_t *)begin_align;

    dbg("%s, heap begin address 0x%x, size %d\n",
                                __func__, (rt_uint32_t)heap_ptr, mem_size_aligned);

    /* initialize the start of the heap */
    mem        = (struct heap_mem *)heap_ptr;
    mem->magic = HEAP_MAGIC;
    mem->next  = mem_size_aligned + SIZEOF_STRUCT_MEM;
    mem->prev  = 0;
    mem->used  = 0;
#ifdef RT_USING_MEMTRACE
    rt_mem_setname(mem, "INIT");
#endif

    /* initialize the end of the heap */
    heap_end        = (struct heap_mem *)&heap_ptr[mem->next];
    heap_end->magic = HEAP_MAGIC;
    heap_end->used  = 1;
    heap_end->next  = mem_size_aligned + SIZEOF_STRUCT_MEM;
    heap_end->prev  = mem_size_aligned + SIZEOF_STRUCT_MEM;
#ifdef RT_USING_MEMTRACE
    rt_mem_setname(heap_end, "INIT");
#endif

    int res = rtos_semaphore_create(&heap_sem, 1, 1);
    ASSERT_ERR(res == 0);

    /* initialize the lowest-free pointer to the start of the heap */
    lfree = (struct heap_mem *)heap_ptr;
}

/**
 * @addtogroup MM
 */

/**@{*/

/**
 * Allocate a block of memory with a minimum of 'size' bytes.
 *
 * @param size is the minimum size of the requested block in bytes.
 *
 * @return pointer to allocated memory or NULL if no free memory was found.
 */
void *rt_malloc(rt_size_t size)
{
    rt_size_t ptr, ptr2;
    struct heap_mem *mem, *mem2;

    if (size == 0)
        return NULL;

    RT_DEBUG_NOT_IN_INTERRUPT;

#ifdef RT_MEM_INFO
    if (size != RT_ALIGN(size, RT_ALIGN_SIZE))
        dbg("malloc size %d, but align to %d\n",
                                    size, RT_ALIGN(size, RT_ALIGN_SIZE));
    else
        dbg("malloc size %d\n", size);
#endif

    /* alignment size */
    size = RT_ALIGN(size, RT_ALIGN_SIZE);

    if (size > mem_size_aligned)
    {
        dbg("no memory\n");

        return NULL;
    }

    /* every data block must be at least MIN_SIZE_ALIGNED long */
    if (size < MIN_SIZE_ALIGNED)
        size = MIN_SIZE_ALIGNED;

    /* take memory semaphore */
    rtos_semaphore_wait(heap_sem, -1);

    for (ptr = (rt_uint8_t *)lfree - heap_ptr;
         ptr < mem_size_aligned - size;
         ptr = ((struct heap_mem *)&heap_ptr[ptr])->next)
    {
        mem = (struct heap_mem *)&heap_ptr[ptr];

        if ((!mem->used) && (mem->next - (ptr + SIZEOF_STRUCT_MEM)) >= size)
        {
            /* mem is not used and at least perfect fit is possible:
             * mem->next - (ptr + SIZEOF_STRUCT_MEM) gives us the 'user data size' of mem */

            if (mem->next - (ptr + SIZEOF_STRUCT_MEM) >=
                (size + SIZEOF_STRUCT_MEM + MIN_SIZE_ALIGNED))
            {
                /* (in addition to the above, we test if another struct heap_mem (SIZEOF_STRUCT_MEM) containing
                 * at least MIN_SIZE_ALIGNED of data also fits in the 'user data space' of 'mem')
                 * -> split large block, create empty remainder,
                 * remainder must be large enough to contain MIN_SIZE_ALIGNED data: if
                 * mem->next - (ptr + (2*SIZEOF_STRUCT_MEM)) == size,
                 * struct heap_mem would fit in but no data between mem2 and mem2->next
                 * @todo we could leave out MIN_SIZE_ALIGNED. We would create an empty
                 *       region that couldn't hold data, but when mem->next gets freed,
                 *       the 2 regions would be combined, resulting in more free memory
                 */
                ptr2 = ptr + SIZEOF_STRUCT_MEM + size;

                /* create mem2 struct */
                mem2       = (struct heap_mem *)&heap_ptr[ptr2];
                mem2->magic = HEAP_MAGIC;
                mem2->used = 0;
                mem2->next = mem->next;
                mem2->prev = ptr;
#ifdef RT_USING_MEMTRACE
                rt_mem_setname(mem2, "    ");
#endif

                /* and insert it between mem and mem->next */
                mem->next = ptr2;
                mem->used = 1;

                if (mem2->next != mem_size_aligned + SIZEOF_STRUCT_MEM)
                {
                    ((struct heap_mem *)&heap_ptr[mem2->next])->prev = ptr2;
                }
#ifdef RT_MEM_STATS
                used_mem += (size + SIZEOF_STRUCT_MEM);
                if (max_mem < used_mem)
                    max_mem = used_mem;
#endif
            }
            else
            {
                /* (a mem2 struct does no fit into the user data space of mem and mem->next will always
                 * be used at this point: if not we have 2 unused structs in a row, plug_holes should have
                 * take care of this).
                 * -> near fit or excact fit: do not split, no mem2 creation
                 * also can't move mem->next directly behind mem, since mem->next
                 * will always be used at this point!
                 */
                mem->used = 1;
#ifdef RT_MEM_STATS
                used_mem += mem->next - ((rt_uint8_t *)mem - heap_ptr);
                if (max_mem < used_mem)
                    max_mem = used_mem;
#endif
            }
            /* set memory block magic */
            mem->magic = HEAP_MAGIC;
#ifdef RT_USING_MEMTRACE
            if (rtos_get_task_handle())
                rt_mem_setname(mem, rtos_get_task_handle()->pcTaskName);
            else
                rt_mem_setname(mem, "NONE");
#endif

            if (mem == lfree)
            {
                /* Find next free block after mem and update lowest free pointer */
                while (lfree->used && lfree != heap_end)
                    lfree = (struct heap_mem *)&heap_ptr[lfree->next];

                RT_ASSERT(((lfree == heap_end) || (!lfree->used)));
            }

            rtos_semaphore_signal(heap_sem, false);
            RT_ASSERT((rt_uint32_t)mem + SIZEOF_STRUCT_MEM + size <= (rt_uint32_t)heap_end);
            RT_ASSERT((rt_uint32_t)((rt_uint8_t *)mem + SIZEOF_STRUCT_MEM) % RT_ALIGN_SIZE == 0);
            RT_ASSERT((((rt_uint32_t)mem) & (RT_ALIGN_SIZE - 1)) == 0);

#ifdef RT_MEM_INFO
            dbg("allocate memory at 0x%x, size: %d\n",
                          (rt_uint32_t)((rt_uint8_t *)mem + SIZEOF_STRUCT_MEM),
                          (rt_uint32_t)(mem->next - ((rt_uint8_t *)mem - heap_ptr)));
#endif

            RT_OBJECT_HOOK_CALL(rt_malloc_hook,
                                (((void *)((rt_uint8_t *)mem + SIZEOF_STRUCT_MEM)), size));

            /* return the memory data except mem struct */
            return (rt_uint8_t *)mem + SIZEOF_STRUCT_MEM;
        }
    }

    rtos_semaphore_signal(heap_sem, false);

    return NULL;
}

/**
 * This function will change the previously allocated memory block.
 *
 * @param rmem pointer to memory allocated by rt_malloc
 * @param newsize the required new size
 *
 * @return the changed memory block address
 */
void *rt_realloc(void *rmem, rt_size_t newsize)
{
    rt_size_t size;
    rt_size_t ptr, ptr2;
    struct heap_mem *mem, *mem2;
    void *nmem;

    RT_DEBUG_NOT_IN_INTERRUPT;

    /* alignment size */
    newsize = RT_ALIGN(newsize, RT_ALIGN_SIZE);
    if (newsize > mem_size_aligned)
    {
        dbg("realloc: out of memory\n");

        return NULL;
    }
    else if (newsize == 0)
    {
        rt_free(rmem);
        return NULL;
    }

    /* allocate a new memory block */
    if (rmem == NULL)
        return rt_malloc(newsize);

    rtos_semaphore_wait(heap_sem, -1);

    if ((rt_uint8_t *)rmem < (rt_uint8_t *)heap_ptr ||
        (rt_uint8_t *)rmem >= (rt_uint8_t *)heap_end)
    {
        /* illegal memory */
        rtos_semaphore_signal(heap_sem, false);

        return rmem;
    }

    mem = (struct heap_mem *)((rt_uint8_t *)rmem - SIZEOF_STRUCT_MEM);

    ptr = (rt_uint8_t *)mem - heap_ptr;
    size = mem->next - ptr - SIZEOF_STRUCT_MEM;
    if (size == newsize)
    {
        /* the size is the same as */
        rtos_semaphore_signal(heap_sem, false);

        return rmem;
    }

    if (newsize + SIZEOF_STRUCT_MEM + MIN_SIZE < size)
    {
        /* split memory block */
#ifdef RT_MEM_STATS
        used_mem -= (size - newsize);
#endif

        ptr2 = ptr + SIZEOF_STRUCT_MEM + newsize;
        mem2 = (struct heap_mem *)&heap_ptr[ptr2];
        mem2->magic = HEAP_MAGIC;
        mem2->used = 0;
        mem2->next = mem->next;
        mem2->prev = ptr;
#ifdef RT_USING_MEMTRACE
        rt_mem_setname(mem2, "    ");
#endif
        mem->next = ptr2;
        if (mem2->next != mem_size_aligned + SIZEOF_STRUCT_MEM)
        {
            ((struct heap_mem *)&heap_ptr[mem2->next])->prev = ptr2;
        }

        plug_holes(mem2);

        rtos_semaphore_signal(heap_sem, false);

        return rmem;
    }
    rtos_semaphore_signal(heap_sem, false);

    /* expand memory */
    nmem = rt_malloc(newsize);
    if (nmem != NULL) /* check memory */
    {
        memcpy(nmem, rmem, size < newsize ? size : newsize);
        rt_free(rmem);
    }

    return nmem;
}

/**
 * This function will contiguously allocate enough space for count objects
 * that are size bytes of memory each and returns a pointer to the allocated
 * memory.
 *
 * The allocated memory is filled with bytes of value zero.
 *
 * @param count number of objects to allocate
 * @param size size of the objects to allocate
 *
 * @return pointer to allocated memory / NULL pointer if there is an error
 */
void *rt_calloc(rt_size_t count, rt_size_t size)
{
    void *p;

    /* allocate 'count' objects of size 'size' */
    p = rt_malloc(count * size);

    /* zero the memory */
    if (p)
        memset(p, 0, count * size);

    return p;
}

/**
 * This function will release the previously allocated memory block by
 * rt_malloc. The released memory block is taken back to system heap.
 *
 * @param rmem the address of memory which will be released
 */
void rt_free(void *rmem)
{
    struct heap_mem *mem;

    if (rmem == NULL)
        return;

    RT_DEBUG_NOT_IN_INTERRUPT;

    RT_ASSERT((((rt_uint32_t)rmem) & (RT_ALIGN_SIZE - 1)) == 0);
    RT_ASSERT((rt_uint8_t *)rmem >= (rt_uint8_t *)heap_ptr &&
              (rt_uint8_t *)rmem < (rt_uint8_t *)heap_end);

    RT_OBJECT_HOOK_CALL(rt_free_hook, (rmem));

    if ((rt_uint8_t *)rmem < (rt_uint8_t *)heap_ptr ||
        (rt_uint8_t *)rmem >= (rt_uint8_t *)heap_end)
    {
        dbg("illegal memory\n");

        return;
    }

    /* Get the corresponding struct heap_mem ... */
    mem = (struct heap_mem *)((rt_uint8_t *)rmem - SIZEOF_STRUCT_MEM);

#ifdef RT_MEM_INFO
    dbg("release memory 0x%x, size: %d\n",
                  (rt_uint32_t)rmem,
                  (rt_uint32_t)(mem->next - ((rt_uint8_t *)mem - heap_ptr)));
#endif

    /* protect the heap from concurrent access */
    rtos_semaphore_wait(heap_sem, -1);

    /* ... which has to be in a used state ... */
    if (!mem->used || mem->magic != HEAP_MAGIC)
    {
        dbg("to free a bad data block:\n");
        dbg("mem: 0x%08x, used flag: %d, magic code: 0x%04x\n", mem, mem->used, mem->magic);
    }
    RT_ASSERT(mem->used);
    RT_ASSERT(mem->magic == HEAP_MAGIC);
    /* ... and is now unused. */
    mem->used  = 0;
    mem->magic = HEAP_MAGIC;
#ifdef RT_USING_MEMTRACE
    rt_mem_setname(mem, "    ");
#endif

    if (mem < lfree)
    {
        /* the newly freed struct is now the lowest */
        lfree = mem;
    }

#ifdef RT_MEM_STATS
    used_mem -= (mem->next - ((rt_uint8_t *)mem - heap_ptr));
#endif

    /* finally, see if prev or next are free also */
    plug_holes(mem);
    rtos_semaphore_signal(heap_sem, false);
}

#ifdef RT_MEM_STATS
void rt_memory_info(rt_uint32_t *total,
                    rt_uint32_t *used,
                    rt_uint32_t *max_used)
{
    if (total != NULL)
        *total = mem_size_aligned;
    if (used  != NULL)
        *used = used_mem;
    if (max_used != NULL)
        *max_used = max_mem;
}

void list_mem(void)
{
    dbg("total memory: %d\n", mem_size_aligned);
    dbg("used memory : %d\n", used_mem);
    dbg("maximum allocated memory: %d\n", max_mem);
}

#ifdef RT_USING_MEMTRACE
int memcheck(void)
{
    int position;
    rt_uint32_t level;
    struct heap_mem *mem;
    level = global_irq_lock();
    for (mem = (struct heap_mem *)heap_ptr; mem != heap_end; mem = (struct heap_mem *)&heap_ptr[mem->next])
    {
        position = (rt_uint32_t)mem - (rt_uint32_t)heap_ptr;
        if (position < 0) goto __exit;
        if (position > mem_size_aligned) goto __exit;
        if (mem->magic != HEAP_MAGIC) goto __exit;
        if (mem->used != 0 && mem->used != 1) goto __exit;
    }
    global_irq_unlock(level);

    return 0;
__exit:
    dbg("Memory block wrong:\n");
    dbg("address: 0x%08x\n", mem);
    dbg("  magic: 0x%04x\n", mem->magic);
    dbg("   used: %d\n", mem->used);
    dbg("  size: %d\n", mem->next - position - SIZEOF_STRUCT_MEM);
    global_irq_unlock(level);

    return 0;
}

int memtrace(int argc, char **argv)
{
    struct heap_mem *mem;

    list_mem();

    dbg("\nmemory heap address:\n");
    dbg("heap_ptr: 0x%08x\n", heap_ptr);
    dbg("lfree   : 0x%08x\n", lfree);
    dbg("heap_end: 0x%08x\n", heap_end);

    dbg("\n--memory item information --\n");
    for (mem = (struct heap_mem *)heap_ptr; mem != heap_end; mem = (struct heap_mem *)&heap_ptr[mem->next])
    {
        int position = (rt_uint32_t)mem - (rt_uint32_t)heap_ptr;
        int size;

        dbg("[0x%08x - ", mem);

        size = mem->next - position - SIZEOF_STRUCT_MEM;
        if (size < 1024)
            dbg("%5d", size);
        else if (size < 1024 * 1024)
            dbg("%4dK", size / 1024);
        else
            dbg("%4dM", size / (1024 * 1024));

        dbg("] %c%c%c%c", mem->thread[0], mem->thread[1], mem->thread[2], mem->thread[3]);
        if (mem->magic != HEAP_MAGIC)
            dbg(": ***\n");
        else
            dbg("\n");
    }

    return 0;
}
#endif /* end of RT_USING_MEMTRACE */

#endif

/**@}*/

#endif /* end of RT_USING_HEAP */

