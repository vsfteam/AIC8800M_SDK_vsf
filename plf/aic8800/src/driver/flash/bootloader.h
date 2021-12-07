#ifndef _BOOTLOADER_H_
#define _BOOTLOADER_H_
#include "plf.h"
#include "chip.h"

/**
 * Memory map with bootloader:
 * +--------------+  <--------------- 0x08000000
 * |              |     ^
 * | bootloader   |     |  12KB
 * |              |     v
 * +--------------+  <--------------- 0x08003000
 * |              |     ^
 * | image_info   |     |  4KB
 * |              |     v
 * +--------------+  <--------------- 0x08004000
 * |              |     ^
 * | cur_image    |     |  636KB : current image
 * |              |     v
 * +--------------+  <--------------- 0x080A3000
 * |              |     ^
 * | image_header |     |  4KB
 * |              |     v
 * +--------------+  <--------------- 0x080A4000
 * |              |     ^
 * | bak_image    |     |  636KB : backup image
 * |              |     v
 * +--------------+  <--------------- 0x08143000
 * |              |     ^
 * | image_header |     |  4KB
 * |              |     v
 * +--------------+  <--------------- 0x08144000
 * |              |     ^
 * | upg_image    |     |  636KB : upgrade image
 * |              |     v
 * +--------------+  <--------------- 0x081E3000
 * |              |     ^
 * | user_data    |     |  100KB : user specified
 * |              |     v
 * +--------------+  <--------------- 0x081FC000
 * |              |     ^
 * | bt_ble_info  |     |  4KB
 * |              |     v
 * +--------------+  <--------------- 0x081FD000
 * |              |     ^
 * | wifi_info    |     |  4KB
 * |              |     v
 * +--------------+  <--------------- 0x081FE000
 * |              |     ^
 * | calib_info   |     |  4KB : factory calib(RO)
 * |              |     v
 * +--------------+  <--------------- 0x081FF000
 * |              |     ^
 * | boot_info    |     |  4KB : chip reserved(RO)
 * |              |     v
 * +--------------+  <--------------- 0x08200000
 */

#define IMAGE_INFO_SIZE             0x1000

#define CURRENT_START_ADDR          0x08003000
#define CURRENT_INFO_ADDR           (CURRENT_START_ADDR)
#define CURRENT_IMAGE_ADDR          (CURRENT_START_ADDR + IMAGE_INFO_SIZE)

#define UPGRADE_START_ADDR          0x08143000
#define UPGRADE_INFO_ADDR           (UPGRADE_START_ADDR)
#define UPGRADE_IMAGE_ADDR          (UPGRADE_START_ADDR + IMAGE_INFO_SIZE)

#define BACKUP_START_ADDR           0x080A3000
#define BACKUP_INFO_ADDR            (BACKUP_START_ADDR)
#define BACKUP_IMAGE_ADDR           (BACKUP_START_ADDR + IMAGE_INFO_SIZE)

#define IMAGE_INFO_MAGIC            0x49474D49  // "IMGI"
#define IMAGE_HEADER_MAGIC          0x48474D49  // "IMGH"
#define VER_BYTE_CNT                16

#define FLASH_IMAGE_MAGIC_NUM       0x474D4946  /* "FIMG" */
#define FLASH_IMAGE_INFO_OFFSET     ((NVIC_USER_IRQ_OFFSET + NVIC_USER_IRQ_NUMBER) * 4)

#define IS_FLASH_MEM_VALID(addr)    (((uint32_t)(addr) >> 26) == (AIC_CACHE0_MEM_BASE >> 26))   // 0x08000000 ~ 0x0BFFFFFF

typedef struct {
    unsigned int magic_num;
    unsigned int image_end;
    unsigned int reserved0;
    unsigned int reserved1;
} flash_image_info_t;

struct image_info
{
    uint32_t magic;
    uint32_t addr;
    uint32_t size;
    uint32_t crc32;
    uint8_t  version[VER_BYTE_CNT];
    uint32_t bootaddr;
    uint32_t bootmagic;
};

struct image_header {
    uint32_t magic;
    uint32_t addr;
    uint32_t size;
    uint32_t crc32;
    uint8_t  version[VER_BYTE_CNT];
    uint32_t encrypt_algo;
};

#endif /* _BOOTLOADER_H_ */
