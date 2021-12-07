#include "sdmmc_api.h"
#include "dma_generic.h"
#include "reg_iomux.h"
#include "dbg.h"
#include "plf.h"
#include "lp_ticker_api.h"
#include "system.h"

#include "reg_sdmmc.h"
#include "reg_sysctrl.h"

/*
 * MMC Voltage bit defines in OCR register
 */
#define MMC_VDD_165_195     0x00000080  /* VDD voltage 1.65 - 1.95 */
#define MMC_VDD_20_21       0x00000100  /* VDD voltage 2.0 ~ 2.1 */
#define MMC_VDD_21_22       0x00000200  /* VDD voltage 2.1 ~ 2.2 */
#define MMC_VDD_22_23       0x00000400  /* VDD voltage 2.2 ~ 2.3 */
#define MMC_VDD_23_24       0x00000800  /* VDD voltage 2.3 ~ 2.4 */
#define MMC_VDD_24_25       0x00001000  /* VDD voltage 2.4 ~ 2.5 */
#define MMC_VDD_25_26       0x00002000  /* VDD voltage 2.5 ~ 2.6 */
#define MMC_VDD_26_27       0x00004000  /* VDD voltage 2.6 ~ 2.7 */
#define MMC_VDD_27_28       0x00008000  /* VDD voltage 2.7 ~ 2.8 */
#define MMC_VDD_28_29       0x00010000  /* VDD voltage 2.8 ~ 2.9 */
#define MMC_VDD_29_30       0x00020000  /* VDD voltage 2.9 ~ 3.0 */
#define MMC_VDD_30_31       0x00040000  /* VDD voltage 3.0 ~ 3.1 */
#define MMC_VDD_31_32       0x00080000  /* VDD voltage 3.1 ~ 3.2 */
#define MMC_VDD_32_33       0x00100000  /* VDD voltage 3.2 ~ 3.3 */
#define MMC_VDD_33_34       0x00200000  /* VDD voltage 3.3 ~ 3.4 */
#define MMC_VDD_34_35       0x00400000  /* VDD voltage 3.4 ~ 3.5 */
#define MMC_VDD_35_36       0x00800000  /* VDD voltage 3.5 ~ 3.6 */

#define MMC_OCR_VOLTAGE_SUPPORTED   (MMC_VDD_32_33 | MMC_VDD_33_34)

/*
  MMC status in R1, for native mode (SPI bits are different)
  Type
    e : error bit
    s : status bit
    r : detected and set for the actual command response
    x : detected and set during command execution. the host must poll
            the card by sending status command in order to read these bits.
  Clear condition
    a : according to the card state
    b : always related to the previous command. Reception of
            a valid command will clear it (with a delay of one command)
    c : clear by read
 */

#define R1_OUT_OF_RANGE         (1 << 31)   /* er,  c */
#define R1_ADDRESS_ERROR        (1 << 30)   /* erx, c */
#define R1_BLOCK_LEN_ERROR      (1 << 29)   /* er,  c */
#define R1_ERASE_SEQ_ERROR      (1 << 28)   /* er,  c */
#define R1_ERASE_PARAM          (1 << 27)   /* ex,  c */
#define R1_WP_VIOLATION         (1 << 26)   /* erx, c */
#define R1_CARD_IS_LOCKED       (1 << 25)   /* sx,  a */
#define R1_LOCK_UNLOCK_FAILED   (1 << 24)   /* erx, c */
#define R1_COM_CRC_ERROR        (1 << 23)   /* er,  b */
#define R1_ILLEGAL_COMMAND      (1 << 22)   /* er,  b */
#define R1_CARD_ECC_FAILED      (1 << 21)   /* ex,  c */
#define R1_CC_ERROR             (1 << 20)   /* erx, c */
#define R1_ERROR                (1 << 19)   /* erx, c */
#define R1_UNDERRUN             (1 << 18)   /* ex,  c */
#define R1_OVERRUN              (1 << 17)   /* ex,  c */
#define R1_CID_CSD_OVERWRITE    (1 << 16)   /* erx, c, CID/CSD overwrite */
#define R1_WP_ERASE_SKIP        (1 << 15)   /* sx,  c */
#define R1_CARD_ECC_DISABLED    (1 << 14)   /* sx,  a */
#define R1_ERASE_RESET          (1 << 13)   /* sr,  c */
#define R1_STATUS(x)            (x & 0xFFF9A000)
#define R1_CURRENT_STATE(x)     ((x & 0x00001E00) >> 9) /* sx, b (4 bits) */
#define R1_READY_FOR_DATA       (1 << 8)    /* sx,  a */
#define R1_SWITCH_ERROR         (1 << 7)    /* sx,  c */
#define R1_EXCEPTION_EVENT      (1 << 6)    /* sr,  a */
#define R1_APP_CMD              (1 << 5)    /* sr,  c */

#define R1_STATE_IDLE   0
#define R1_STATE_READY  1
#define R1_STATE_IDENT  2
#define R1_STATE_STBY   3
#define R1_STATE_TRAN   4
#define R1_STATE_DATA   5
#define R1_STATE_RCV    6
#define R1_STATE_PRG    7
#define R1_STATE_DIS    8
#define R1_STATE_MASK   0x0FUL

#define _R1_STATE_IDLE  R1_STATE_IDLE
#define _R1_STATE_READY R1_STATE_READY
#define _R1_STATE_IDENT R1_STATE_IDENT
#define _R1_STATE_STBY  R1_STATE_STBY
#define _R1_STATE_TRAN  R1_STATE_TRAN
#define _R1_STATE_DATA  R1_STATE_DATA
#define _R1_STATE_RCV   R1_STATE_RCV
#define _R1_STATE_PRG   R1_STATE_PRG
#define _R1_STATE_DIS   R1_STATE_DIS
#define _R1_STATE_MASK  R1_STATE_MASK

#define R1_CUR_STATE(s) (_ ## s << 9)

#define MMC_RSP_PRESENT (1 << 0)
#define MMC_RSP_136     (1 << 1)    /* 136 bit response */
#define MMC_RSP_CRC     (1 << 2)    /* expect valid crc */
#define MMC_RSP_BUSY    (1 << 3)    /* card may send busy */
#define MMC_RSP_OPCODE  (1 << 4)    /* response contains opcode */

#define MMC_RSP_NONE    (0)
#define MMC_RSP_R1      (MMC_RSP_PRESENT|MMC_RSP_CRC|MMC_RSP_OPCODE)
#define MMC_RSP_R1b     (MMC_RSP_PRESENT|MMC_RSP_CRC|MMC_RSP_OPCODE| MMC_RSP_BUSY)
#define MMC_RSP_R2      (MMC_RSP_PRESENT|MMC_RSP_136|MMC_RSP_CRC)
#define MMC_RSP_R3      (MMC_RSP_PRESENT)
#define MMC_RSP_R4      (MMC_RSP_PRESENT)
#define MMC_RSP_R5      (MMC_RSP_PRESENT|MMC_RSP_CRC|MMC_RSP_OPCODE)
#define MMC_RSP_R6      (MMC_RSP_PRESENT|MMC_RSP_CRC|MMC_RSP_OPCODE)
#define MMC_RSP_R7      (MMC_RSP_PRESENT|MMC_RSP_CRC|MMC_RSP_OPCODE)

/*
 * Card-Specific Data (CSD) register information structure for MMC, SD V1/V2
 */
typedef struct {
    uint8_t     structure;      // bit[127:126], CSD structure
    uint8_t     mmca_vsn;       // bit[125:122], system specification version (MMC only)
    uint8_t     taac;           // bit[119:112], data read access-time 1
    uint8_t     nsac;           // bit[111:104], data read access-time 2 in CLK cycles
    uint8_t     tran_speed;     // bit[103:96], max data trabsfer rate
    uint8_t     read_blk_len;   // bit[83:80], max read block length
    uint8_t     c_size_mult;    // bit[49:47], device size multiplier (SD V1 & MMC only)
    uint8_t     erase_grp_size; // bit[46:42], erase group size (MMC only)
    uint8_t     erase_grp_mult; // bit[41:37], erase group size multiplier (MMC only)
    uint8_t     erase_sec_size; // bit[45:39], erase sector size (SD V1/V2 only)
    uint8_t     r2w_factor;     // bit[28:26], write speed factor
    uint8_t     write_blk_len;  // bit[25:22], max write block length
    uint16_t    cmdclass;       // bit[95:84], card command class
    uint32_t    c_size;         // bit[73:62] (SD V1 & MMC), bit[69:48] (SD V2), device size
    uint32_t    capacity;
    //uint16_t    taac_clks;      // calculated CLK cycles based on NSAC
    //uint32_t    taac_ns;        // calculated data access-time based on TAAC
    //uint32_t    max_dtr;        // calculated max data transfer rate based on TRAN_SPEED
    //uint32_t    erase_size;     // calculated erase size based on SECTOR_SIZE+ERASE_BLK_EN (SD V1/V2) &
                                  // ERASE_GRP_SIZE + ERASE_GRP_MULT (MMC)
    uint32_t    read_partial:   1,  // bit[79], partial blocks for read allowed
                write_misalign: 1,  // bit[78], write block misalignment
                read_misalign:  1,  // bit[77], read block misalignment
                dsr_imp:        1,  // bit[76], DSR implemented
                erase_blk_en:   1,  // bit[46], erase single block enable (SD V1/V2 only)
                write_partial:  1;  // bit[21], partial blocks for write allowed
} mmc_csd_t;

#define UNSTUFF_BIT(resp,offset)                                \
    ((resp[(offset) >> 5] >> ((offset) & 0x1F)) & 0x01)
#define UNSTUFF_BITS_SINGLE(resp,start,size)                    \
    ((resp[(start) >> 5] >> ((start) & 0x1F)) & ((0x01 << size) - 1))
#define UNSTUFF_BITS(resp,start,size)                                   \
    ({                                                                  \
        const int32_t  __size = size;                                   \
        const uint32_t __mask = (__size < 32 ? 1 << __size : 0) - 1;    \
        const int32_t  __off = (start) >> 5;                            \
        const int32_t  __shft = (start) & 31;                           \
        uint32_t __res;                                                 \
                                                                        \
        __res = resp[__off] >> __shft;                                  \
        if (__size + __shft > 32)                                       \
            __res |= resp[__off + 1] << ((32 - __shft) % 32);           \
        __res & __mask;                                                 \
    })

/* MMC error code */
#define MMC_ERR_OPNOTSUPP       1   /* Operation not supported */
#define MMC_ERR_TIMEDOUT        2   /* Operation timed out */
#define MMC_ERR_RSPNONE         3   /* Response nothing */
#define MMC_ERR_RSPERROR        4   /* Response error */
#define MMC_ERR_RSPUNEXP        5   /* Response unexpected */
#define MMC_ERR_DATACRCERROR    6   /* Data crc error */
#define MMC_ERR_TRANERROR       7   /* Trans state error */

/* Maximum block size for MMC */
#define MMC_MAX_BLOCK_LEN   512

/* SD card data bus width */
#define SD_BUS_WIDTH_1      0
#define SD_BUS_WIDTH_4      2
#define SD_BUS_WIDTH_8      3

/* SD/MMC version bits; 8 flags, 8 major, 8 minor, 8 change */
#define SD_VERSION_SD   (1U << 31)
#define MMC_VERSION_MMC (1U << 30)

#define MAKE_SDMMC_VERSION(a, b, c) \
    ((((uint32_t)(a)) << 16) | ((uint32_t)(b) << 8) | (uint32_t)(c))
#define MAKE_SD_VERSION(a, b, c) \
    (SD_VERSION_SD | MAKE_SDMMC_VERSION(a, b, c))
#define MAKE_MMC_VERSION(a, b, c) \
    (MMC_VERSION_MMC | MAKE_SDMMC_VERSION(a, b, c))

#define EXTRACT_SDMMC_MAJOR_VERSION(x) \
    (((uint32_t)(x) >> 16) & 0xff)
#define EXTRACT_SDMMC_MINOR_VERSION(x) \
    (((uint32_t)(x) >> 8) & 0xff)
#define EXTRACT_SDMMC_CHANGE_VERSION(x) \
    ((uint32_t)(x) & 0xff)

#define SD_VERSION_3        MAKE_SD_VERSION(3, 0, 0)
#define SD_VERSION_2        MAKE_SD_VERSION(2, 0, 0)
#define SD_VERSION_1_0      MAKE_SD_VERSION(1, 0, 0)
#define SD_VERSION_1_10     MAKE_SD_VERSION(1, 10, 0)

#define MMC_VERSION_UNKNOWN MAKE_MMC_VERSION(0, 0, 0)
#define MMC_VERSION_1_2     MAKE_MMC_VERSION(1, 2, 0)
#define MMC_VERSION_1_4     MAKE_MMC_VERSION(1, 4, 0)
#define MMC_VERSION_2_2     MAKE_MMC_VERSION(2, 2, 0)
#define MMC_VERSION_3       MAKE_MMC_VERSION(3, 0, 0)
#define MMC_VERSION_4       MAKE_MMC_VERSION(4, 0, 0)
#define MMC_VERSION_4_1     MAKE_MMC_VERSION(4, 1, 0)
#define MMC_VERSION_4_2     MAKE_MMC_VERSION(4, 2, 0)
#define MMC_VERSION_4_3     MAKE_MMC_VERSION(4, 3, 0)
#define MMC_VERSION_4_4     MAKE_MMC_VERSION(4, 4, 0)
#define MMC_VERSION_4_41    MAKE_MMC_VERSION(4, 4, 1)
#define MMC_VERSION_4_5     MAKE_MMC_VERSION(4, 5, 0)
#define MMC_VERSION_5_0     MAKE_MMC_VERSION(5, 0, 0)
#define MMC_VERSION_5_1     MAKE_MMC_VERSION(5, 1, 0)

#define IS_SD(x)        ((x) & SD_VERSION_SD)
#define IS_MMC(x)       ((x) & MMC_VERSION_MMC)

/* Standard MMC commands (4.1)               type  argument     response */
typedef enum {
    /* class 1 */
    MMC_CMD_GO_IDLE_STATE           = 0,  /* bc                          */
    MMC_CMD_SEND_OP_COND            = 1,  /* bcr  [31:0] OCR         R3  */
    MMC_CMD_ALL_SEND_CID            = 2,  /* bcr                     R2  */
    MMC_CMD_SET_RELATIVE_ADDR       = 3,  /* ac   [31:16] RCA        R1  */
    MMC_CMD_SET_DSR                 = 4,  /* bc   [31:16] RCA            */
    MMC_CMD_SLEEP_AWAKE             = 5,  /* ac   [31:16] RCA 15:flg R1b */
    MMC_CMD_SWITCH                  = 6,  /* ac   [31:0] See below   R1b */
    MMC_CMD_SELECT_CARD             = 7,  /* ac   [31:16] RCA        R1  */
    MMC_CMD_SEND_EXT_CSD            = 8,  /* adtc                    R1  */
    MMC_CMD_SEND_CSD                = 9,  /* ac   [31:16] RCA        R2  */
    MMC_CMD_SEND_CID                = 10, /* ac   [31:16] RCA        R2  */
    MMC_CMD_READ_DAT_UNTIL_STOP     = 11, /* adtc [31:0] dadr        R1  */
    MMC_CMD_STOP_TRANSMISSION       = 12, /* ac                      R1b */
    MMC_CMD_SEND_STATUS             = 13, /* ac   [31:16] RCA        R1  */
    MMC_CMD_BUS_TEST_R              = 14, /* adtc                    R1  */
    MMC_CMD_GO_INACTIVE_STATE       = 15, /* ac   [31:16] RCA            */
    MMC_CMD_BUS_TEST_W              = 19, /* adtc                    R1  */
    MMC_CMD_SPI_READ_OCR            = 58, /* spi                  spi_R3 */
    MMC_CMD_SPI_CRC_ON_OFF          = 59, /* spi  [0:0] flag      spi_R1 */
    /* class 2 */
    MMC_CMD_SET_BLOCKLEN            = 16, /* ac   [31:0] block len   R1  */
    MMC_CMD_READ_SINGLE_BLOCK       = 17, /* adtc [31:0] data addr   R1  */
    MMC_CMD_READ_MULTIPLE_BLOCK     = 18, /* adtc [31:0] data addr   R1  */
    MMC_CMD_SEND_TUNING_BLOCK       = 19, /* adtc                    R1  */
    MMC_CMD_SEND_TUNING_BLOCK_HS200 = 21, /* adtc                    R1  */
    /* class 3 */
    MMC_CMD_WRITE_DAT_UNTIL_STOP    = 20, /* adtc [31:0] data addr   R1  */
    /* class 4 */
    MMC_CMD_SET_BLOCK_COUNT         = 23, /* adtc [31:0] data addr   R1  */
    MMC_CMD_WRITE_SINGLE_BLOCK      = 24, /* adtc [31:0] data addr   R1  */
    MMC_CMD_WRITE_MULTIPLE_BLOCK    = 25, /* adtc                    R1  */
    MMC_CMD_PROGRAM_CID             = 26, /* adtc                    R1  */
    MMC_CMD_PROGRAM_CSD             = 27, /* adtc                    R1  */
    /* class 6 */
    MMC_CMD_SET_WRITE_PROT          = 28, /* ac   [31:0] data addr   R1b */
    MMC_CMD_CLR_WRITE_PROT          = 29, /* ac   [31:0] data addr   R1b */
    MMC_CMD_SEND_WRITE_PROT         = 30, /* adtc [31:0] wpdata addr R1  */
    /* class 5 */
    MMC_CMD_ERASE_GROUP_START       = 35, /* ac   [31:0] data addr   R1  */
    MMC_CMD_ERASE_GROUP_END         = 36, /* ac   [31:0] data addr   R1  */
    MMC_CMD_ERASE                   = 38, /* ac                      R1b */
    /* class 9 */
    MMC_CMD_FAST_IO                 = 39, /* ac   <Complex>          R4  */
    MMC_CMD_GO_IRQ_STATE            = 40, /* bcr                     R5  */
    /* class 7 */
    MMC_CMD_LOCK_UNLOCK             = 42, /* adtc                    R1b */
    /* class 8 */
    MMC_CMD_APP_CMD                 = 55, /* ac   [31:16] RCA        R1  */
    MMC_CMD_GEN_CMD                 = 56, /* adtc [0] RD/WR          R1  */
    /* class 11 */
    MMC_CMD_QUE_TASK_PARAMS         = 44, /* ac   [20:16] task id    R1  */
    MMC_CMD_QUE_TASK_ADDR           = 45, /* ac   [31:0] data addr   R1  */
    MMC_CMD_EXECUTE_READ_TASK       = 46, /* adtc [20:16] task id    R1  */
    MMC_CMD_EXECUTE_WRITE_TASK      = 47, /* adtc [20:16] task id    R1  */
    MMC_CMD_CMDQ_TASK_MGMT          = 48, /* ac   [20:16] task id    R1b */
} MMC_CMD_IDX_T;

#define SD_CMD_APP_BIT          (0x01U << 8)

/* SD commands                             type  argument     response */
typedef enum {
    /* class 0 */
    SD_CMD_SEND_RELATIVE_ADDR   = 3,    /* bcr                     R6  */
    SD_CMD_SEND_IF_COND         = 8,    /* bcr  [11:0] See below   R7  */
    SD_CMD_SWITCH_UHS18V        = 11,   /* ac                      R1  */
    /* class 10 */
    SD_CMD_SWITCH_FUNC          = 6,    /* adtc [31:0] See below   R1  */
    /* class 5 */
    SD_CMD_ERASE_WR_BLK_START   = 32,   /* ac   [31:0] data addr   R1  */
    SD_CMD_ERASE_WR_BLK_END     = 33,   /* ac   [31:0] data addr   R1  */
    /* Application commands */
    SD_CMD_APP_SET_BUS_WIDTH    = SD_CMD_APP_BIT | 6,   /* ac   [1:0] bus width    R1  */
    SD_CMD_APP_SD_STATUS        = SD_CMD_APP_BIT | 13,  /* adtc                    R1  */
    SD_CMD_APP_SEND_NUM_WR_BLKS = SD_CMD_APP_BIT | 22,  /* adtc                    R1  */
    SD_CMD_APP_SEND_OP_COND     = SD_CMD_APP_BIT | 41,  /* bcr  [31:0] OCR         R3  */
    SD_CMD_APP_SEND_SCR         = SD_CMD_APP_BIT | 51,  /* adtc                    R1  */
} SD_CMD_IDX_T;

typedef struct {
    unsigned int voltages;
    unsigned int bus_width;
} sdmmc_cfg_t;

typedef struct {
    unsigned short cmdidx;
    unsigned short resp_type;
    unsigned int cmdarg;
    unsigned int response[4];
} sdmmc_cmd_t;

typedef struct {
    sdmmc_cfg_t *cfg;
    unsigned int version;
    int high_capacity;
    unsigned int ocr;
    unsigned int rca;
    unsigned int cid[4];
    mmc_csd_t csd;
} sdmmc_t;

//#define CONFIG_SDMMC_DEBUG

#ifdef CONFIG_SDMMC_DEBUG
#define SDMMC_DBG(fmt,args...) \
    dbg("DBG: %s " fmt,__PRETTY_FUNCTION__,##args)
#define SDMMC_ERR(fmt,args...) \
    dbg("ERR: %s " fmt,__PRETTY_FUNCTION__,##args)
#else
#define SDMMC_DBG(fmt,args...)
#define SDMMC_ERR(fmt,args...) \
    dbg("ERR: %s " fmt,__PRETTY_FUNCTION__,##args)
#endif

#if (PLF_HW_FPGA == 1)
#define CONFIG_SYS_CLOCK_HZ         (40000000)
#define MMC_MAX_CLK                 (20000000)
#define WORKING_CLK_FREQ            (20000000)
#else
#define CONFIG_SYS_CLOCK_HZ         (SystemCoreClock) // hclk
#define MMC_MAX_CLK                 (SystemCoreClock / 2)
#define WORKING_CLK_FREQ            (24000000)
#endif

#define DATARD_TRIG_TH              4
#define DATAWR_TRIG_TH              4

// Check pattern for CMD8
#define SD_CMD8_CHECK_PATTERN       0xAA
// OCR bits
#define SD_ACMD41_ARG_OCR_S18R      (0x01UL << 24)
#define SD_ACMD41_ARG_OCR_HCS       (0x01UL << 30)
#define SD_ACMD41_RSP_OCR_S18A      (0x01UL << 24)
#define SD_ACMD41_RSP_OCR_CCS       (0x01UL << 30)
#define SD_ACMD41_RSP_OCR_BUSY      (0x01UL << 31)
#define MMC_CMD1_RSP_OCR_BUSY       (0x01UL << 31)
#define MMC_OCR_HVOLTAGE_MASK       0x00FF8000  // High voltage
#define MMC_OCR_LVOLTAGE_MASK       0x00007F80  // Low voltage
#define MMC_OCR_DVOLTAGE_MASK       (MMC_OCR_HVOLTAGE_MASK | MMC_OCR_LVOLTAGE_MASK) // Dual voltage
#define MMC_OCR_SECTOR_MODE         0x40000000  // Sector mode
#define MMC_OCR_ACCESS_MODE_MASK    0x60000000  // Access mode

#define MMC_OCR_TIMEOUT_MS          (1000)  // Time to get ocr
#define MMC_CMD_TIMEOUT_MS          (2000)  // Time to wait cmd over
#define MMC_RESP_TIMEOUT_MS         (2000)  // Time to wait resp
#define MMC_TRAN_TIMEOUT_MS         (2000)  // Time to get trans state
#define MMC_READ_TIMEOUT_MS         (5000)  // Time to wait read done
#define MMC_WRITE_TIMEOUT_MS        (5000)  // Time to wait write done

static uint8_t block_rw_in_progress = 0;
static uint8_t data_trans_is_over = 0;

sdmmc_cfg_t sdmmc_cfg = {
    .voltages = MMC_OCR_VOLTAGE_SUPPORTED,
    .bus_width = 4,
};
sdmmc_t sdmmc = {
    .cfg = &sdmmc_cfg,
    .rca = 0x00UL,
};

static unsigned int systime_get_us(void)
{
    return lp_ticker_read();
}

static void delay_us(unsigned int usecs)
{
    unsigned int current_us, previous_us = systime_get_us();
    do {
        __NOP();
        __NOP();
        current_us = systime_get_us();
    } while ((current_us - previous_us) < usecs);
}

static void delay_ms(unsigned int msecs)
{
    delay_us(msecs * 1000);
}

static void mmc_host_open(unsigned int conf)
{
    AIC_SDMMC->IER = 0x00UL;
    AIC_SDMMC->CCR = conf;
}

static void mmc_host_close(void)
{
    AIC_SDMMC->CFGR = 0x00UL;
}

static void mmc_host_clock_set(unsigned int clock)
{
    unsigned int div;
    unsigned int sys_clk = CONFIG_SYS_CLOCK_HZ;
    if (clock > MMC_MAX_CLK) {
        clock = MMC_MAX_CLK;
    }
    // clock = sys_clk/((div + 1) * 2)
    div = ((sys_clk / clock) >> 1) - 1;
    AIC_SDMMC->CDR = div;
    SDMMC_DBG("clk div: 0x%x\n", AIC_SDMMC->CDR);
}

static void mmc_host_buswidth_set(unsigned int bus_width)
{
    AIC_SDMMC->DBWR = bus_width;
}

static int mmc_host_cmd_isover(void)
{
    return ((AIC_SDMMC->GSR & SDMMC_COMMAND_NOT_OVER)) ? 0 : 1;
}

static void mmc_host_trans_config(sdmmc_t *sdmmc, unsigned int block_count)
{
    /* set blocks regs */
    AIC_SDMMC->DBLR = sdmmc->csd.read_blk_len;
    AIC_SDMMC->DBCR = block_count;

    /* set control reg */
    AIC_SDMMC->CTLR = (SDMMC_RESET_N | SDMMC_ENDIAN_TYPE(1) | SDMMC_DATARD_TRIGEN | SDMMC_DATAWR_TRIGEN |
                       SDMMC_DATARD_TRIGTH(DATARD_TRIG_TH) | SDMMC_DATAWR_TRIGTH(DATAWR_TRIG_TH));
    block_rw_in_progress = 1;
}

static int mmc_host_trans_isdone(void)
{
    if (block_rw_in_progress > 0) {
        if((0 == data_trans_is_over) && (AIC_SDMMC->ISR & SDMMC_DATA_DONE_FLAG)) {
            data_trans_is_over = 1;
        }
        if ((1 == data_trans_is_over) && mmc_host_cmd_isover()) {
            AIC_SDMMC->ICR = SDMMC_DATA_DONE_CLEAR;
            block_rw_in_progress = 0;
            data_trans_is_over = 0;
            /* clr data fifo */
            AIC_SDMMC->CTLR = (SDMMC_ENDIAN_TYPE(1) | SDMMC_DATARD_TRIGEN | SDMMC_DATAWR_TRIGEN |
                               SDMMC_DATARD_TRIGTH(DATARD_TRIG_TH) | SDMMC_DATAWR_TRIGTH(DATAWR_TRIG_TH));
            AIC_SDMMC->CTLR = (SDMMC_RESET_N | SDMMC_ENDIAN_TYPE(1) | SDMMC_DATARD_TRIGEN | SDMMC_DATAWR_TRIGEN |
                               SDMMC_DATARD_TRIGTH(DATARD_TRIG_TH) | SDMMC_DATAWR_TRIGTH(DATAWR_TRIG_TH));
            return 1;
        }
    }
    return 0;
}

static void mmc_host_trans_stop(void)
{
    /* clr block regs */
    AIC_SDMMC->DBLR = 0x00UL;
    AIC_SDMMC->DBCR = 0x00UL;

    block_rw_in_progress = 0;

    /* clr data fifo */
    AIC_SDMMC->CTLR = (SDMMC_ENDIAN_TYPE(1) | SDMMC_DATARD_TRIGEN | SDMMC_DATAWR_TRIGEN |
                       SDMMC_DATARD_TRIGTH(DATARD_TRIG_TH) | SDMMC_DATAWR_TRIGTH(DATAWR_TRIG_TH));
    AIC_SDMMC->CTLR = (SDMMC_RESET_N | SDMMC_ENDIAN_TYPE(1) | SDMMC_DATARD_TRIGEN | SDMMC_DATAWR_TRIGEN |
                       SDMMC_DATARD_TRIGTH(DATARD_TRIG_TH) | SDMMC_DATAWR_TRIGTH(DATAWR_TRIG_TH));
}

static int mmc_host_isbusy(void)
{
    return ((AIC_SDMMC->GSR & (SDMMC_COMMAND_NOT_OVER | SDMMC_HOST_BUSY | SDMMC_DATABUS_BUSY)) ? 1 : 0);
}

static unsigned int mmc_host_datacrcerr_get(void)
{
    return AIC_SDMMC->GSR & (0xFFUL << SDMMC_DATA_CRCERROR_LSB);
}

int mmc_send_cmd(sdmmc_t *sdmmc, sdmmc_cmd_t *cmd)
{
    unsigned int cfg, previous_us, card_status, expected_status;
    if (cmd->cmdidx & SD_CMD_APP_BIT) {
        cfg = SDMMC_CONFIG_Rx | SDMMC_RESPONSE_ENABLE | SDMMC_COMMAND_START;
        AIC_SDMMC->CFGR = 0x00UL;
        AIC_SDMMC->CMDR = MMC_CMD_APP_CMD;
        AIC_SDMMC->ARGR = sdmmc->rca;
        AIC_SDMMC->CFGR = cfg;
        previous_us = systime_get_us();
        while (AIC_SDMMC->GSR & SDMMC_COMMAND_NOT_OVER) {
            __NOP();
            if ((systime_get_us() - previous_us) > MMC_CMD_TIMEOUT_MS * 1000) {
                break;
            }
        }
        if (AIC_SDMMC->GSR & SDMMC_COMMAND_NOT_OVER) {
            return -MMC_ERR_TIMEDOUT;
        }
        previous_us = systime_get_us();
        while (AIC_SDMMC->GSR & SDMMC_RESPONSE_NONE_ERROR) {
            //__NOP();
            delay_us(1000);
            if ((systime_get_us() - previous_us) > MMC_RESP_TIMEOUT_MS * 1000) {
                break;
            }
        }
        if (AIC_SDMMC->GSR & SDMMC_RESPONSE_NONE_ERROR) {
            return -MMC_ERR_RSPNONE;
        }
        if (AIC_SDMMC->GSR & SDMMC_RESPONSE_CRC_ERROR) {
            return -MMC_ERR_RSPERROR;
        }
        card_status = AIC_SDMMC->R3R;
        expected_status = R1_APP_CMD;
        if (cmd->cmdidx != SD_CMD_APP_SEND_OP_COND) {
            expected_status |= R1_READY_FOR_DATA;
        }
        if ((card_status & expected_status) != expected_status) {
            return -MMC_ERR_RSPUNEXP;
        }
    }
    cfg = SDMMC_COMMAND_START;
    if (cmd->resp_type != MMC_RSP_NONE) {
        cfg |= SDMMC_RESPONSE_ENABLE;
        if (cmd->resp_type == MMC_RSP_R2) {
            cfg |= SDMMC_CONFIG_R2;
        } else if (cmd->resp_type == MMC_RSP_R3) {
            cfg |= SDMMC_CONFIG_R3;
        } else {
            cfg |= SDMMC_CONFIG_Rx;
        }
        if (cmd->cmdidx == MMC_CMD_READ_SINGLE_BLOCK) {
            cfg |= (SDMMC_RW_ENABLE);
        } else if (cmd->cmdidx == MMC_CMD_READ_MULTIPLE_BLOCK) {
            cfg |= (SDMMC_RW_ENABLE | SDMMC_MULTI_BLCOK_MODE | SDMMC_AUTOCMD12_ENABLE);
        } else if (cmd->cmdidx == MMC_CMD_WRITE_SINGLE_BLOCK) {
            cfg |= (SDMMC_RW_ENABLE | SDMMC_WRITE_MODE);
        } else if (cmd->cmdidx == MMC_CMD_WRITE_MULTIPLE_BLOCK) {
            cfg |= (SDMMC_RW_ENABLE | SDMMC_WRITE_MODE | SDMMC_MULTI_BLCOK_MODE | SDMMC_AUTOCMD12_ENABLE);
        }
    }
    AIC_SDMMC->CFGR = 0x00UL;
    SDMMC_DBG("arg=%x,cfg=%x\n",cmd->cmdarg,cfg);
    AIC_SDMMC->CMDR = SDMMC_COMMAND_INDEX(cmd->cmdidx);
    AIC_SDMMC->ARGR = cmd->cmdarg;
    AIC_SDMMC->CFGR = cfg;
    previous_us = systime_get_us();
    while (AIC_SDMMC->GSR & SDMMC_COMMAND_NOT_OVER) {
        __NOP();
        if ((systime_get_us() - previous_us) > MMC_CMD_TIMEOUT_MS * 1000) {
            break;
        }
    }
    if (AIC_SDMMC->GSR & SDMMC_COMMAND_NOT_OVER) {
        return -MMC_ERR_TIMEDOUT;
    }
    if (cmd->resp_type != MMC_RSP_NONE) {
        previous_us = systime_get_us();
        while (AIC_SDMMC->GSR & SDMMC_RESPONSE_NONE_ERROR) {
            __NOP();
            if ((systime_get_us() - previous_us) > MMC_RESP_TIMEOUT_MS * 1000) {
                break;
            }
        }
        if (AIC_SDMMC->GSR & SDMMC_RESPONSE_NONE_ERROR) {
            return -MMC_ERR_RSPNONE;
        }
        if (AIC_SDMMC->GSR & SDMMC_RESPONSE_CRC_ERROR) {
            return -MMC_ERR_RSPERROR;
        }
        if (cmd->resp_type & MMC_RSP_136) {
            cmd->response[0] = AIC_SDMMC->R0R << 1;
            cmd->response[1] = AIC_SDMMC->R1R;
            cmd->response[2] = AIC_SDMMC->R2R;
            cmd->response[3] = AIC_SDMMC->R3R;
        } else {
            cmd->response[0] = AIC_SDMMC->R3R;
        }
    }
    return 0;
}

static int mmc_poll_for_transtate(sdmmc_t *sdmmc)
{
    int err;
    int timeout = MMC_TRAN_TIMEOUT_MS;
    sdmmc_cmd_t cmd;
    unsigned int card_status;
    // Send status
    cmd.cmdidx = MMC_CMD_SEND_STATUS;
    cmd.cmdarg = sdmmc->rca;
    cmd.resp_type = MMC_RSP_R1;
    while (1) {
        SDMMC_DBG("CMD13\n");
        err = mmc_send_cmd(sdmmc, &cmd);
        if (err) {
            SDMMC_ERR("err=%d\n",err);
            return err;
        }
        card_status = cmd.response[0];
        if ((card_status & (R1_READY_FOR_DATA | R1_CUR_STATE(R1_STATE_MASK))) ==
            (R1_READY_FOR_DATA | R1_CUR_STATE(R1_STATE_TRAN))) {
            break;
        }
        if (timeout-- <= 0) {
            return -MMC_ERR_TIMEDOUT;
        }
        SDMMC_DBG("card_status=%x\n",card_status);
        delay_us(1000);
    }
    return 0;
}

int mmc_go_idle(sdmmc_t *sdmmc)
{
    sdmmc_cmd_t cmd;
    SDMMC_DBG("CMD0\n");
    delay_us(1000);
    // Reset the device to idle state
    cmd.cmdidx = MMC_CMD_GO_IDLE_STATE;
    cmd.cmdarg = 0;
    cmd.resp_type = MMC_RSP_NONE;
    return mmc_send_cmd(sdmmc, &cmd);
}

int mmc_send_if_cond(sdmmc_t *sdmmc)
{
    int err;
    sdmmc_cmd_t cmd;
    SDMMC_DBG("CMD8\n");
    // SD V2 detect, r7 expected
    cmd.cmdidx = SD_CMD_SEND_IF_COND;
    cmd.cmdarg = ((sdmmc->cfg->voltages & MMC_OCR_HVOLTAGE_MASK) ? (0x01UL << 8) : 0x00UL) | SD_CMD8_CHECK_PATTERN;
    cmd.resp_type = MMC_RSP_R7;
    err = mmc_send_cmd(sdmmc, &cmd);
    if (err) {
        return err;
    }
    if ((cmd.response[0] & 0xFFUL) !=  SD_CMD8_CHECK_PATTERN) {
        return -MMC_ERR_OPNOTSUPP;
    } else {
        sdmmc->version = SD_VERSION_2;
    }
    return 0;
}

int sd_send_op_cond(sdmmc_t *sdmmc, int uhs_en)
{
    int timeout = MMC_OCR_TIMEOUT_MS;
    int err;
    sdmmc_cmd_t cmd;
    cmd.cmdidx = SD_CMD_APP_SEND_OP_COND;
    cmd.cmdarg = sdmmc->cfg->voltages & MMC_OCR_HVOLTAGE_MASK;
    if (sdmmc->version == SD_VERSION_2) {
        cmd.cmdarg |= SD_ACMD41_ARG_OCR_HCS;
    }
    if (uhs_en) {
        cmd.cmdarg |= SD_ACMD41_ARG_OCR_S18R;
    }
    cmd.resp_type = MMC_RSP_R3;
    while (1) {
        SDMMC_DBG("ACMD41, response r3\n");
        err = mmc_send_cmd(sdmmc, &cmd);
        if (err == -MMC_ERR_RSPNONE) {
            SDMMC_ERR("ACMD41, No Response, MMC Card?\n");
            return -MMC_ERR_TIMEDOUT;
        }
        SDMMC_DBG("ACMD41 Done, response = 0x%8x\n", cmd.response[0]);

        if (cmd.response[0] & SD_ACMD41_RSP_OCR_BUSY) {
            break;
        }
        if (timeout-- <= 0) {
            return -MMC_ERR_OPNOTSUPP;
        }
        delay_us(1000);
    }
    if (sdmmc->version != SD_VERSION_2) {
        sdmmc->version = SD_VERSION_1_0;
    }
    sdmmc->ocr = cmd.response[0];
    sdmmc->high_capacity = (cmd.response[0] & SD_ACMD41_RSP_OCR_CCS) ? 1 : 0;
    sdmmc->rca = 0x00UL;
    return 0;
}

int mmc_send_op_cond(sdmmc_t *sdmmc)
{
    int timeout = MMC_OCR_TIMEOUT_MS;
    int err;
    sdmmc_cmd_t cmd;
    /* Some cards seem to need this */
    mmc_go_idle(sdmmc);
    cmd.cmdidx = MMC_CMD_SEND_OP_COND;
    cmd.cmdarg = 0;
    cmd.resp_type = MMC_RSP_R3;
    while (1) {
        SDMMC_DBG("CMD1, response r3\n");
        err = mmc_send_cmd(sdmmc, &cmd);
        if (err == -MMC_ERR_RSPNONE) {
            SDMMC_ERR("CMD1, No Response\n");
            return -MMC_ERR_TIMEDOUT;
        }
        SDMMC_DBG("CMD1 Done, response = 0x%8x\n", cmd.response[0]);

        sdmmc->ocr = cmd.response[0];
        if (cmd.response[0] & MMC_CMD1_RSP_OCR_BUSY) {
            break;
        }
        if (timeout == MMC_OCR_TIMEOUT_MS) {
            cmd.cmdarg = (sdmmc->cfg->voltages & sdmmc->ocr & MMC_OCR_DVOLTAGE_MASK) | (sdmmc->ocr & MMC_OCR_ACCESS_MODE_MASK);
        }
        if (timeout-- <= 0) {
            return -MMC_ERR_OPNOTSUPP;
        }
        delay_us(1000);
    }
    sdmmc->version = MMC_VERSION_UNKNOWN;
    sdmmc->high_capacity = ((sdmmc->ocr & MMC_OCR_ACCESS_MODE_MASK) == MMC_OCR_SECTOR_MODE) ? 1 : 0;
    sdmmc->rca = 0x01UL << 16;
    return 0;
}

int mmc_all_send_cid(sdmmc_t *sdmmc)
{
    int err;
    sdmmc_cmd_t cmd;
    SDMMC_DBG("CMD2\n");
    // Get CID
    cmd.cmdidx = MMC_CMD_ALL_SEND_CID;
    cmd.cmdarg = 0;
    cmd.resp_type = MMC_RSP_R2;
    err = mmc_send_cmd(sdmmc, &cmd);
    if (err) {
        return err;
    }
    sdmmc->cid[0] = cmd.response[0];
    sdmmc->cid[1] = cmd.response[1];
    sdmmc->cid[2] = cmd.response[2];
    sdmmc->cid[3] = cmd.response[3];
    return 0;
}

int mmc_send_relative_addr(sdmmc_t *sdmmc)
{
    int err;
    sdmmc_cmd_t cmd;
    SDMMC_DBG("CMD3\n");
    /*
     * For MMC cards, set the Relative Address.
     * For SD cards, get the Relatvie Address.
     * This also puts the cards into Standby State
     */
    cmd.cmdidx = IS_MMC(sdmmc->version) ? MMC_CMD_SET_RELATIVE_ADDR : SD_CMD_SEND_RELATIVE_ADDR;
    cmd.cmdarg = sdmmc->rca;
    cmd.resp_type = IS_MMC(sdmmc->version) ? MMC_RSP_R1 : MMC_RSP_R6;
    err = mmc_send_cmd(sdmmc, &cmd);
    if (err) {
        return err;
    }
    if (IS_SD(sdmmc->version)) {
        sdmmc->rca = cmd.response[0] & 0xFFFF0000UL;
    }
    SDMMC_DBG("resp[0]=%x, rca=%x\n",cmd.response[0],sdmmc->rca);
    return 0;
}

void mmc_decode_csd(sdmmc_t *sdmmc, unsigned int* csd_raw)
{
    mmc_csd_t* csd = &sdmmc->csd;
    if (IS_MMC(sdmmc->version)) {
        csd->mmca_vsn = UNSTUFF_BITS_SINGLE(csd_raw, 122, 4);
        switch (sdmmc->csd.mmca_vsn) {
        case 0:
            sdmmc->version = MMC_VERSION_1_2;
            break;
        case 1:
            sdmmc->version = MMC_VERSION_1_4;
            break;
        case 2:
            sdmmc->version = MMC_VERSION_2_2;
            break;
        case 3:
            sdmmc->version = MMC_VERSION_3;
            break;
        case 4:
            sdmmc->version = MMC_VERSION_4;
            break;
        default:
            sdmmc->version = MMC_VERSION_1_2;
            break;
        }
    } else {
        csd->erase_sec_size = (uint8_t)UNSTUFF_BITS_SINGLE(csd_raw, 39, 7);
        csd->erase_blk_en   = UNSTUFF_BIT(csd_raw, 46);
    }
    csd->structure      = (uint8_t)UNSTUFF_BITS_SINGLE(csd_raw, 126, 2);
    csd->taac           = (uint8_t)UNSTUFF_BITS_SINGLE(csd_raw, 112, 8);
    csd->nsac           = (uint8_t)UNSTUFF_BITS_SINGLE(csd_raw, 104, 8);
    csd->tran_speed     = (uint8_t)UNSTUFF_BITS_SINGLE(csd_raw, 96, 8);
    csd->cmdclass       = (uint8_t)UNSTUFF_BITS_SINGLE(csd_raw, 84, 12);
    csd->dsr_imp        = UNSTUFF_BIT(csd_raw, 76);
    if ((IS_MMC(sdmmc->version)) || (csd->structure == 0)) { // MMC & SD V1
        csd->read_blk_len   = (uint8_t)UNSTUFF_BITS_SINGLE(csd_raw, 80, 4);
        csd->c_size_mult    = (uint8_t)UNSTUFF_BITS_SINGLE(csd_raw, 47, 3);
        csd->r2w_factor     = (uint8_t)UNSTUFF_BITS_SINGLE(csd_raw, 26, 3);
        csd->write_blk_len  = (uint8_t)UNSTUFF_BITS_SINGLE(csd_raw, 22, 4);
        csd->read_partial   = UNSTUFF_BIT(csd_raw, 79);
        csd->write_misalign = UNSTUFF_BIT(csd_raw, 78);
        csd->read_misalign  = UNSTUFF_BIT(csd_raw, 77);
        csd->write_partial  = UNSTUFF_BIT(csd_raw, 21);
        csd->c_size         = UNSTUFF_BITS(csd_raw, 62, 12);
        csd->capacity       = (csd->c_size + 1) << (csd->c_size_mult + 2);
    } else { // SD V2
        csd->read_blk_len   = 9;
        csd->c_size_mult    = 0;
        csd->r2w_factor     = 4;
        csd->write_blk_len  = 9;
        csd->read_partial   = 0;
        csd->write_misalign = 0;
        csd->read_misalign  = 0;
        csd->write_partial  = 0;
        csd->c_size         = UNSTUFF_BITS(csd_raw, 48, 22);
        csd->capacity       = (csd->c_size + 1) << 10;
    }
    SDMMC_DBG("version=%x,structure=%x,c_size=%d,c_size_mult=%d\n",sdmmc->version,csd->structure,csd->c_size,csd->c_size_mult);
}

int mmc_send_csd(sdmmc_t *sdmmc)
{
    int err;
    sdmmc_cmd_t cmd;
    SDMMC_DBG("CMD9\n");
    // Get CSD
    cmd.cmdidx = MMC_CMD_SEND_CSD;
    cmd.cmdarg = sdmmc->rca;
    cmd.resp_type = MMC_RSP_R2;
    err = mmc_send_cmd(sdmmc, &cmd);
    if (err) {
        return err;
    }
    mmc_decode_csd(sdmmc, cmd.response);
    return 0;
}

int mmc_set_dsr(sdmmc_t *sdmmc)
{
    sdmmc_cmd_t cmd;
    SDMMC_DBG("CMD4\n");
    // Reset the device to idle state
    cmd.cmdidx = MMC_CMD_SET_DSR;
    cmd.cmdarg = 0; // to be confirmed
    cmd.resp_type = MMC_RSP_NONE;
    return mmc_send_cmd(sdmmc, &cmd);
}

int mmc_select_card(sdmmc_t *sdmmc)
{
    int err;
    sdmmc_cmd_t cmd;
    unsigned int card_status;
    SDMMC_DBG("CMD7\n");
    // Select card
    cmd.cmdidx = MMC_CMD_SELECT_CARD;
    cmd.cmdarg = sdmmc->rca;
    cmd.resp_type = MMC_RSP_R1;
    err = mmc_send_cmd(sdmmc, &cmd);
    if (err) {
        return err;
    }
    card_status = cmd.response[0];
    if (!(card_status & R1_READY_FOR_DATA)) {
        return -MMC_ERR_RSPUNEXP;
    }
    return 0;
}

int sd_set_bus_width(sdmmc_t *sdmmc)
{
    int err;
    sdmmc_cmd_t cmd;
    unsigned int card_status;
    SDMMC_DBG("ACMD6\n");
    // Select card
    cmd.cmdidx = SD_CMD_APP_SET_BUS_WIDTH;
    cmd.cmdarg = (sdmmc->cfg->bus_width == 4) ? SD_BUS_WIDTH_4 : SD_BUS_WIDTH_1;
    cmd.resp_type = MMC_RSP_R1;
    err = mmc_send_cmd(sdmmc, &cmd);
    if (err) {
        return err;
    }
    card_status = cmd.response[0];
    // That command returns the card status, in tran state ?
    if ((card_status & (R1_APP_CMD | R1_READY_FOR_DATA | R1_CUR_STATE(R1_STATE_MASK))) !=
        (R1_APP_CMD | R1_READY_FOR_DATA | R1_CUR_STATE(R1_STATE_TRAN))) {
        return -MMC_ERR_RSPUNEXP;
    }
    mmc_host_buswidth_set(sdmmc->cfg->bus_width);
    return 0;
}

int mmc_set_blocklen(sdmmc_t *sdmmc)
{
    int err;
    unsigned int blocklen;
    sdmmc_cmd_t cmd;
    unsigned int card_status;
    SDMMC_DBG("CMD16\n");
    // Select card
    cmd.cmdidx = MMC_CMD_SET_BLOCKLEN;
    blocklen = 0x01UL << sdmmc->csd.read_blk_len;
    cmd.cmdarg = (blocklen > MMC_MAX_BLOCK_LEN) ? MMC_MAX_BLOCK_LEN : blocklen;
    cmd.resp_type = MMC_RSP_R1;
    err = mmc_send_cmd(sdmmc, &cmd);
    if (err) {
        return err;
    }
    card_status = cmd.response[0];
    if ((card_status & (R1_READY_FOR_DATA | R1_CUR_STATE(R1_STATE_MASK))) !=
        (R1_READY_FOR_DATA | R1_CUR_STATE(R1_STATE_TRAN))) {
        return -MMC_ERR_RSPUNEXP;
    }
    return 0;
}

int mmc_start(sdmmc_t *sdmmc)
{
    int err;
    int uhs_en = 0;
    mmc_csd_t *pcsd = &sdmmc->csd;

    //mmc_host_open(SDMMC_CLOCK_INVERT_ENABLE); // clk_inv (disabled, cause data read err if hclk=52MHz)
    mmc_host_open(0x00UL);

    /* Config 400KHz for initiation */
    mmc_host_clock_set(400000);

    /* Reset the card */
    err = mmc_go_idle(sdmmc);
    if (err) {
        SDMMC_ERR("No card, err=%d\n", err);
        mmc_host_close();
        return err;
    }

    /* Test for SD V2 */
    err = mmc_send_if_cond(sdmmc);
    if (err) {
        SDMMC_ERR("SD V2 detect fail, err=%d\n", err);
    }

    /* Get the SD card's operating condition */
    err = sd_send_op_cond(sdmmc, uhs_en);

    /* If the command timed out, we check for an MMC card */
    if (err == -MMC_ERR_TIMEDOUT) {
        SDMMC_DBG("MMC Card, high_capacity=%x\n",sdmmc->high_capacity);
        err = mmc_send_op_cond(sdmmc);
        if (err) {
            SDMMC_ERR("MMC Card check fail, err=%d\n", err);
            mmc_host_close();
            return err;
        }
    } else {
        SDMMC_DBG("SD Card, high_capacity=%x\n",sdmmc->high_capacity);
    }

    // Get cid
    err = mmc_all_send_cid(sdmmc);
    if (err) {
        SDMMC_ERR("get cid Fail, err=%d\n", err);
        mmc_host_close();
        return err;
    }

    // Set or get rca
    err = mmc_send_relative_addr(sdmmc);
    if (err) {
        SDMMC_ERR("Send relative addr fail, err=%d\n", err);
        mmc_host_close();
        return err;
    }

    // Get csd
    err = mmc_send_csd(sdmmc);
    if (err) {
        SDMMC_ERR("Get CSD fail, err=%d\n", err);
        mmc_host_close();
        return err;
    }

    // Set DSR
    if (pcsd->dsr_imp) {
        err = mmc_set_dsr(sdmmc);
        if (err) {
            SDMMC_ERR("Set DSR fail, err=%d\n", err);
            mmc_host_close();
            return err;
        }
    }

    // Select card
    err = mmc_select_card(sdmmc);
    if (err) {
        SDMMC_ERR("Select card fail, err=%d\n", err);
        mmc_host_close();
        return err;
    }

    // Set data bus width
    if (IS_SD(sdmmc->version)) {
        err = sd_set_bus_width(sdmmc);
        if (err) {
            SDMMC_ERR("Set bus width fail, err=%d\n", err);
            mmc_host_close();
            return err;
        }
    } else {
        /// TBD
    }

    // Set block length
    err = mmc_set_blocklen(sdmmc);
    if (err) {
        SDMMC_ERR("Set block length fail, err=%d\n", err);
        mmc_host_close();
        return err;
    }

    // Set clock to transfer data
    mmc_host_clock_set(WORKING_CLK_FREQ);

    delay_ms(1);

    return 0;
}

void mmc_stop(void)
{
    if (mmc_host_isbusy()) {
        SDMMC_ERR("Host is busy, stop fail\n");
        return;
    }
    // Transfer stop
    mmc_host_trans_stop();
    // Close sdmmc host
    mmc_host_close();
}

#define SDMMC_USE_DMA

static int mmc_read_multi_block(sdmmc_t *sdmmc, unsigned char *buff_rd, unsigned int block_start, unsigned int block_count)
{
    int err;
    unsigned int card_status;
    sdmmc_cmd_t cmd;
    cmd.cmdidx = (block_count > 1) ? MMC_CMD_READ_MULTIPLE_BLOCK : MMC_CMD_READ_SINGLE_BLOCK;
    cmd.cmdarg = (sdmmc->high_capacity) ? block_start : (block_start << 9);
    cmd.resp_type = MMC_RSP_R1;

    uint64_t previous_us;
    uint32_t byte_cnt;
    #ifndef SDMMC_USE_DMA
    uint32_t buff_idx;
    #else
    const int ch = DMA_CHANNEL_SDMMC_RX;
    #endif

    // Config transfer regs
    mmc_host_trans_config(sdmmc, block_count);

    #if defined(SDMMC_USE_DMA)
    byte_cnt = block_count << 9;    // byte count
    dma_erqcsr_set(REQ_CID_SDMMC_RX, ch);
    dma_ch_rqr_erql_setb(ch);
    dma_ch_dar_set(ch, (unsigned int)buff_rd);
    dma_ch_sar_set(ch, (unsigned int)(&AIC_SDMMC->DRDR));
    dma_ch_tbl0cr_set(ch, ((4 * DATARD_TRIG_TH) | (REQ_FRAG << DMA_CH_RQTYP_LSB) | (AHB_WORD << DMA_CH_DBUSU_LSB) |
                             (AHB_WORD << DMA_CH_SBUSU_LSB) | DMA_CH_CONSTSA_BIT));
    dma_ch_tbl1cr_set(ch, byte_cnt);
    dma_ch_tbl2cr_set(ch, byte_cnt);
    dma_ch_tsr_set(ch, ((4 << DMA_CH_STRANSZ_LSB) | (4 << DMA_CH_DTRANSZ_LSB)));
    dma_ch_wmar_set(ch, 0);
    dma_ch_wjar_set(ch, 0);
    dma_ch_tbl0sr_set(ch, ((0 << DMA_CH_STBL0SZ_LSB) | (0 << DMA_CH_DTBL0SZ_LSB)));
    dma_ch_tbl1ssr_set(ch, 0);
    dma_ch_tbl1dsr_set(ch, 0);
    //dma_ch_ctlr_set(ch, (DMA_CH_CHENA_BIT | (0x01UL << DMA_CH_BUSBU_LSB)));
    #endif

    SDMMC_DBG("CMD%d, cnt=%d\n", cmd.cmdidx, block_count);
    err = mmc_send_cmd(sdmmc, &cmd);

    #if defined(SDMMC_USE_DMA)
    dma_ch_ctlr_set(ch, (DMA_CH_CHENA_BIT | (0x01UL << DMA_CH_BUSBU_LSB)));
    #endif

    if (err) {
        mmc_host_trans_stop();
        return err;
    }
    card_status = cmd.response[0];
    if ((card_status & (R1_READY_FOR_DATA | R1_CUR_STATE(R1_STATE_MASK))) !=
        (R1_READY_FOR_DATA | R1_CUR_STATE(R1_STATE_TRAN))) {
        mmc_host_trans_stop();
        return -MMC_ERR_RSPUNEXP;
    }

    #ifdef SDMMC_USE_DMA
    while (dma_ch_icsr_tbl2_irst_getb(ch) == 0);
    dma_ch_icsr_set(ch, (dma_ch_icsr_get(ch) | DMA_CH_TBL0_ICLR_BIT |
                         DMA_CH_TBL1_ICLR_BIT | DMA_CH_TBL2_ICLR_BIT));
    SDMMC_DBG("dma trsc done\n");
    #endif

    #ifndef SDMMC_USE_DMA
    byte_cnt = block_count << 9;    // byte count
    buff_idx = 0;
    while (buff_idx < byte_cnt) {
        previous_us = systime_get_us();
        while (!(AIC_SDMMC->DSR & (0x0FUL << SDMMC_DATARD_COUNT_LSB))) {
            __NOP();
            if ((systime_get_us() - previous_us) > (MMC_CMD_TIMEOUT_MS * 1000)) {
                mmc_host_trans_stop();
                return -MMC_ERR_TIMEDOUT;
            }
        }
        *((unsigned int *)(&(buff_rd[buff_idx]))) = AIC_SDMMC->DRDR;
        buff_idx += 4;
    }
    #endif

    // wait transfer done
    previous_us = systime_get_us();
    while (!mmc_host_trans_isdone()) {
        if (systime_get_us() - previous_us > (MMC_READ_TIMEOUT_MS * 1000 * block_count)) {
            mmc_host_trans_stop();  // transfer abort
            return -MMC_ERR_TIMEDOUT;
        }
    }

    SDMMC_DBG("transfer done\n");

    if (mmc_host_datacrcerr_get()) {
        return -MMC_ERR_DATACRCERROR;
    }

    // Must be in tran state
    if (mmc_poll_for_transtate(sdmmc)) {
        return -MMC_ERR_TRANERROR;
    }

    return 0;
}

static int mmc_write_multi_block(sdmmc_t *sdmmc, unsigned char *buff_wr, unsigned int block_start, unsigned int block_count)
{
    int err;
    unsigned int card_status, previous_us;
    sdmmc_cmd_t cmd;
    cmd.cmdidx = (block_count > 1) ? MMC_CMD_WRITE_MULTIPLE_BLOCK : MMC_CMD_WRITE_SINGLE_BLOCK;
    cmd.cmdarg = (sdmmc->high_capacity) ? block_start : (block_start << 9);
    cmd.resp_type = MMC_RSP_R1;

    #if !defined(SDMMC_USE_DMA)
    uint32_t *p4_buff = (uint32_t *)buff_wr;
    uint32_t word_cnt;
    uint32_t buff_idx;
    #else
    uint32_t byte_cnt;
    const int ch = DMA_CHANNEL_SDMMC_TX;
    #endif

    // Config transfer regs
    mmc_host_trans_config(sdmmc, block_count);

    SDMMC_DBG("CMD%d, cnt=%d\n", cmd.cmdidx, block_count);

    #if defined(SDMMC_USE_DMA)
    byte_cnt = block_count << 9;    // byte count
    dma_erqcsr_set(REQ_CID_SDMMC_TX, ch);
    dma_ch_rqr_erql_setb(ch);
    dma_ch_dar_set(ch, (unsigned int)(&AIC_SDMMC->DWRR));
    dma_ch_sar_set(ch, (unsigned int)buff_wr);
    dma_ch_tbl0cr_set(ch, ((4 * DATAWR_TRIG_TH) | (REQ_FRAG << DMA_CH_RQTYP_LSB) | (AHB_WORD << DMA_CH_DBUSU_LSB) |
                             (AHB_WORD << DMA_CH_SBUSU_LSB) | DMA_CH_CONSTDA_BIT));
    dma_ch_tbl1cr_set(ch, byte_cnt);
    dma_ch_tbl2cr_set(ch, byte_cnt);
    dma_ch_tsr_set(ch, ((4 << DMA_CH_STRANSZ_LSB) | (4 << DMA_CH_DTRANSZ_LSB)));
    dma_ch_wmar_set(ch, 0);
    dma_ch_wjar_set(ch, 0);
    dma_ch_tbl0sr_set(ch, ((0 << DMA_CH_STBL0SZ_LSB) | (0 << DMA_CH_DTBL0SZ_LSB)));
    dma_ch_tbl1ssr_set(ch, 0);
    dma_ch_tbl1dsr_set(ch, 0);
    dma_ch_ctlr_set(ch, (DMA_CH_CHENA_BIT | (0x01UL << DMA_CH_BUSBU_LSB)));

    err = mmc_send_cmd(sdmmc, &cmd);
    if (err) {
        mmc_host_trans_stop();
        return err;
    }
    card_status = cmd.response[0];
    if ((card_status & (R1_READY_FOR_DATA | R1_CUR_STATE(R1_STATE_MASK))) !=
        (R1_READY_FOR_DATA | R1_CUR_STATE(R1_STATE_TRAN))) {
        mmc_host_trans_stop();
        return -MMC_ERR_RSPUNEXP;
    }

    while (dma_ch_icsr_tbl2_irst_getb(ch) == 0);
    dma_ch_icsr_set(ch, (dma_ch_icsr_get(ch) | DMA_CH_TBL0_ICLR_BIT |
                         DMA_CH_TBL1_ICLR_BIT | DMA_CH_TBL2_ICLR_BIT));
    #endif

    #if !defined(SDMMC_USE_DMA)
    word_cnt = block_count << 7;    // word count
    buff_idx = 0;
    while (buff_idx < word_cnt) {
        previous_us = systime_get_us();
        while (!(AIC_SDMMC->DSR & (0x0FUL << SDMMC_DATAWR_COUNT_LSB))) {
            __NOP();
            if ((systime_get_us() - previous_us) > (MMC_CMD_TIMEOUT_MS * 1000)) {
                mmc_host_trans_stop();
                return -MMC_ERR_TIMEDOUT;
            }
        }
        AIC_SDMMC->DWRR = *(p4_buff + buff_idx);
        buff_idx++;
        if(buff_idx == 4) {
            err = mmc_send_cmd(sdmmc, &cmd);
            if (err) {
                mmc_host_trans_stop();
                return err;
            }
            card_status = cmd.response[0];
            if ((card_status & (R1_READY_FOR_DATA | R1_CUR_STATE(R1_STATE_MASK))) !=
                (R1_READY_FOR_DATA | R1_CUR_STATE(R1_STATE_TRAN))) {
                mmc_host_trans_stop();
                return -MMC_ERR_RSPUNEXP;
            }
        }
    }
    #endif

    // wait transfer done
    previous_us = systime_get_us();
    while (!mmc_host_trans_isdone()) {
        if (systime_get_us() - previous_us > (MMC_WRITE_TIMEOUT_MS * 1000 * block_count)) {
            mmc_host_trans_stop();  // transfer abort
            return -MMC_ERR_TIMEDOUT;
        }
    }

    SDMMC_DBG("transfer done\n");

    if (mmc_host_datacrcerr_get()) {
        return -MMC_ERR_DATACRCERROR;
    }

    // Must be in tran state
    if (mmc_poll_for_transtate(sdmmc)) {
        return -MMC_ERR_TRANERROR;
    }
    return 0;
}

void sdmmc_init(void)
{
    // clk en
    #ifdef SDMMC_USE_DMA
    cpusysctrl_hclkme_set(CSC_HCLKME_DMA_EN_BIT);
    #endif /* SDMMC_USE_DMA */
    cpusysctrl_oclkme_set(CSC_OCLKME_SDMMC_EN_BIT);
    cpusysctrl_hclk1me_set(CSC_HCLK1ME_SDMMC_EN_BIT | CSC_HCLK1ME_SDMMC_ALWAYS_EN_BIT);
    // iomux for sdmmc
    iomux_gpio_config_sel_setf(10, 6);
    iomux_gpio_config_sel_setf(11, 6);
    iomux_gpio_config_sel_setf(12, 6);
    iomux_gpio_config_sel_setf(13, 6);
    iomux_gpio_config_sel_setf(14, 6);
    iomux_gpio_config_sel_setf(15, 6);
}

int32_t sdmmc_open(void)
{
    /* mmc start */
    return mmc_start(&sdmmc);
}

void sdmmc_close(void)
{
    /* mmc stop */
    mmc_stop();
}

int32_t sdmmc_read_blocks(uint8_t* buffer, uint32_t block_start, uint32_t block_num)
{
    return mmc_read_multi_block(&sdmmc, buffer, block_start, block_num);
}

int32_t sdmmc_write_blocks(uint8_t* buffer, uint32_t block_start, uint32_t block_num)
{
    return mmc_write_multi_block(&sdmmc, buffer, block_start, block_num);
}

void sdmmc_info(uint32_t *sector_count, uint32_t *sector_size)
{
    if (sector_count && sector_size) {
        mmc_csd_t * const p_csd = &sdmmc.csd;
        switch(p_csd->structure) {
            case 0:
                *sector_count = p_csd->capacity / 512;
                *sector_size = 512;
                SDMMC_DBG("\nSDCard\nsectors: %d\n", *sector_count);
                break;

            case 1:
                *sector_count = p_csd->capacity;
                *sector_size = 1;
                SDMMC_DBG("\nSDHC Card \nsectors: %d\n", *sector_count);
                break;

            default:
                *sector_count = 0;
                SDMMC_DBG("CSD struct unsupported\n");
        }
    }
}
