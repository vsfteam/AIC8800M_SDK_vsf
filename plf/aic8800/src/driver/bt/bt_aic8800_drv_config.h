#ifndef __BT_AIC8800_DRV_CONFIG_H__
#define  __BT_AIC8800_DRV_CONFIG_H__
#include "compiler.h"
#include "reg_access.h"

#include "fw_patch_u02.h"
#include "fw_patch_table_u02.h"
#include "fw_patch_u03.h"
#include "fw_patch_table_u03.h"

#define AICBT_CHIP_ID_U02                      0x03
#define AICBT_CHIP_ID_U03                      0x07
#define AICBT_CHIP_ID_U04                      AICBT_CHIP_ID_U03

#ifdef CFG_BT_PATCH_TWS
#define AICBT_PATCH_BASE_ADDR_U02              0x100000
#define AICBT_PATCH_BASE_ADDR_U03              0x100000
#define AICBT_PATCH_BASE_ADDR_U04              AICBT_PATCH_BASE_ADDR_U03
#else
#define AICBT_PATCH_BASE_ADDR_U02              0x16AD64
#define AICBT_PATCH_BASE_ADDR_U03              0x16AD70
#define AICBT_PATCH_BASE_ADDR_U04              AICBT_PATCH_BASE_ADDR_U03
#endif

#define AICBT_ADID_RAM_BASE_ADDR_U02           0x00161928
#define AICBT_ADID_ROM_BASE_ADDR_U02           0x0004d868
#define AICBT_ADID_SIZE_U02                    0x4b4
#define AICBT_PATCH_DATA_PTR_U02               (uint8_t *)(&fw_patch_u02[0])
#define AICBT_PATCH_DATA_SIZE_U02              AICBT_FW_PATCH_U02_SIZE
#define AICBT_PATCH_TABLE_PTR_U02              (uint8_t *)(&fw_patch_table_u02[0])
#define AICBT_PATCH_TABLE_SIZE_U02             AICBT_FW_PATCH_TABLE_U02_SIZE

#define AICBT_ADID_RAM_BASE_ADDR_U03           0x00161928
#define AICBT_ADID_ROM_BASE_ADDR_U03           0x0004d868
#define AICBT_ADID_SIZE_U03                    0x4b8
#define AICBT_PATCH_DATA_PTR_U03               (uint8_t *)(&fw_patch_u03[0])
#define AICBT_PATCH_DATA_SIZE_U03              AICBT_FW_PATCH_U03_SIZE
#define AICBT_PATCH_TABLE_PTR_U03              (uint8_t *)(&fw_patch_table_u03[0])
#define AICBT_PATCH_TABLE_SIZE_U03             AICBT_FW_PATCH_TABLE_U03_SIZE

#define AICBT_ADID_RAM_BASE_ADDR_U04           AICBT_ADID_RAM_BASE_ADDR_U03
#define AICBT_ADID_ROM_BASE_ADDR_U04           AICBT_ADID_ROM_BASE_ADDR_U03
#define AICBT_ADID_SIZE_U04                    AICBT_ADID_SIZE_U03
#define AICBT_PATCH_DATA_PTR_U04               AICBT_PATCH_DATA_PTR_U03
#define AICBT_PATCH_DATA_SIZE_U04              AICBT_PATCH_DATA_SIZE_U03
#define AICBT_PATCH_TABLE_PTR_U04              AICBT_PATCH_TABLE_PTR_U03
#define AICBT_PATCH_TABLE_SIZE_U04             AICBT_PATCH_TABLE_SIZE_U03


#define AICBT_TABLE_TYPE_TRAP_TABLE             0x01
#define AICBT_TABLE_TYPE_PATCH_B4_TABLE         0x02
#define AICBT_TABLE_TYPE_PATCH_BT_MODE          0x03
#define AICBT_TABLE_TYPE_POWER_ON_TABLE         0x04
#define AICBT_TABLE_TYPE_PATCH_AF_TABLE         0x05
#define AICBT_TABLE_TYPE_PATCH_VER_INFO         0x06

typedef struct aicbt_patch_table_desc
{
    char         table_tag[16];
    uint32_t     type;
    uint32_t     len;
    uint32_t     *data;
} APTD;

struct aicbt_patch_table_desc_hdr
{
    APTD desc;
    APTD *next;
};

#define AICBT_PT_TAG_SIZE                   16
#define AICBT_PT_TAG                        "AICBT_PT_TAG"
#define AICBT_PT_TRAP_TAG                   "AICBT_TRAP_T";
#define AICBT_PT_PATCH_TB4_TAG              "AICBT_PATCH_TB4";
#define AICBT_PT_MODE_TAG                   "AICBT_MODE_T";
#define AICBT_PT_PWRON_TAG                  "AICBT_POWER_ON";
#define AICBT_PT_PATCH_TAF_TAG              "AICBT_PATCH_TAF";


struct aicbt_patch_init_desc
{
    uint16_t     chip_id;
    uint16_t     adid_size;
    uint8_t     *adid_ram_base_addr;
    uint8_t     *adid_rom_base_addr;
    uint8_t     *patch_base_addr;
    uint8_t     *patch_data_ptr;
    uint32_t     patch_data_size;
    uint8_t     *patch_table_ptr;
    uint32_t     patch_table_size;
    struct aicbt_patch_table_desc_hdr *head;
};


#endif
