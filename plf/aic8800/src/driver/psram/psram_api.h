#ifndef _PSRAM_API_H_
#define _PSRAM_API_H_

/**
 * @brief Init psram
 * @param icache_size The size of memory accessed in icache, the remained in dcache
 * Memory mapping (e.g. psram_size=0x00400000):
 * +--------+ <----- cache_addr0(0x0C000000 - icache_size) -> psram_start(0x00000000)
 * |        |   ^
 * | icache |   | icache_size (>=0)
 * |        |   v
 * +--------+ <----- cache_addr1(0x0C000000) ->  psram_addr(icach_size)
 * |        |   ^
 * | dcache |   | remained_size
 * |        |   v
 * +--------+ <----- cache_addr2(0x0C000000 + remained_size) -> psram_end(0x00400000)
 */
void psram_init(unsigned int icache_size);

/**
 * Get psram size
 */
unsigned int psram_size_get(void);

#endif /* _PSRAM_API_H_ */
