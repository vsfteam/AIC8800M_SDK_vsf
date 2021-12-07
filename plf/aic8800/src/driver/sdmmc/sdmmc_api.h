#ifndef _SDMMC_API_H_
#define _SDMMC_API_H_

#include <stdint.h>

void sdmmc_init(void);
int32_t sdmmc_open(void);
void sdmmc_info(uint32_t *sector_count, uint32_t *sector_size);
int32_t sdmmc_read_blocks(uint8_t* buffer, uint32_t block_start, uint32_t block_num);
int32_t sdmmc_write_blocks(uint8_t* buffer, uint32_t block_start, uint32_t block_num);
void sdmmc_close(void);

#endif /* _SDMMC_API_H_ */
