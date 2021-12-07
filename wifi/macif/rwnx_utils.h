/**
 * rwnx_utils.h
 */
#ifndef _RWNX_UTILS_H_
#define _RWNX_UTILS_H_

#include "ipc_shared.h"
#include "dbg.h"

#if PLF_WIFI_AUDIO
#define FRAMES_11MBPS_ENABLED   (1)
#else
#define FRAMES_11MBPS_ENABLED   (0)
#endif

typedef uint32_t (*patch_tbl_array_t)[2];

extern patch_tbl_array_t patch_tbl;
extern patch_tbl_array_t patch_tbl_func;
extern uint32_t *patch_func;
extern uint32_t patch_tbl_size;
extern uint32_t patch_tbl_func_size;
extern uint32_t patch_func_size;
extern uint32_t aon_patch_start_addr;
extern uint32_t aon_patch_num;
extern uint32_t patch_store_addr;
extern uint32_t fw_patch_addr;

#define TRACE_NONE(fmt, ...)

#define RWNX_DBG TRACE_NONE
#define RWNX_FN_ENTRY_STR ">>> %s()\n", __func__

enum rwnx_dev_flag {
    RWNX_DEV_RESTARTING,
    RWNX_DEV_STACK_RESTARTING,
    RWNX_DEV_STARTED,
};

extern struct co_list rx_buffer_free_list;
enum ipc_rx_buffer_status {
    RX_BUFFER_PUSHED = 0,
    RX_BUFFER_FREE   = 0x5A5A5A5A,
    RX_BUFFER_READY  = RX_DMA_OVER_PATTERN,
    RX_UF_VEC_VALID_PATTERN = 0x0000C0DE,
};

struct rwnx_hw;
typedef uint32_t dma_addr_t;

/// 802.11 Status Code
#define MAC_ST_SUCCESSFUL                   0
#define MAC_ST_FAILURE                      1
#define MAC_ST_RESERVED                     2
#define MAC_ST_CAPA_NOT_SUPPORTED           10
#define MAC_ST_REASSOC_NOT_ASSOC            11
#define MAC_ST_ASSOC_DENIED                 12
#define MAC_ST_AUTH_ALGO_NOT_SUPPORTED      13
#define MAC_ST_AUTH_FRAME_WRONG_SEQ         14
#define MAC_ST_AUTH_CHALLENGE_FAILED        15
#define MAC_ST_AUTH_TIMEOUT                 16
#define MAC_ST_ASSOC_TOO_MANY_STA           17
#define MAC_ST_ASSOC_RATES_NOT_SUPPORTED    18
#define MAC_ST_ASSOC_PREAMBLE_NOT_SUPPORTED 19

#define MAC_ST_ASSOC_SPECTRUM_REQUIRED   22
#define MAC_ST_ASSOC_POWER_CAPA          23
#define MAC_ST_ASSOC_SUPPORTED_CHANNEL   24
#define MAC_ST_ASSOC_SLOT_NOT_SUPPORTED  25

#define MAC_ST_REFUSED_TEMPORARILY       30
#define MAC_ST_INVALID_MFP_POLICY        31

#define MAC_ST_INVALID_IE                40             // draft 7.0 extention
#define MAC_ST_GROUP_CIPHER_INVALID      41             // draft 7.0 extention
#define MAC_ST_PAIRWISE_CIPHER_INVALID   42             // draft 7.0 extention
#define MAC_ST_AKMP_INVALID              43             // draft 7.0 extention
#define MAC_ST_UNSUPPORTED_RSNE_VERSION  44             // draft 7.0 extention
#define MAC_ST_INVALID_RSNE_CAPA         45             // draft 7.0 extention
#define MAC_ST_CIPHER_SUITE_REJECTED     46             // draft 7.0 extention
/** @} */

/**
 * struct rwnx_ipc_elem - Generic IPC buffer of fixed size
 *
 * @addr: Host address of the buffer.
 * @dma_addr: DMA address of the buffer.
 */
struct rwnx_ipc_elem {
    //void *addr;
    dma_addr_t dma_addr;
};
struct rwnx_ipc_host_elem {
    struct co_list_hdr hdr;
    uint32_t addr;
};
/**
 * struct rwnx_ipc_elem_pool - Generic pool of IPC buffers of fixed size
 *
 * @nb: Number of buffers currenlty allocated in the pool
 * @buf: Array of buffers (size of array is @nb)
 * @pool: DMA pool in which buffers have been allocated
 */
struct rwnx_ipc_elem_pool {
    int nb;
    //struct rwnx_ipc_elem *buf;
    struct rwnx_ipc_elem buf[IPC_MSGE2A_BUF_CNT];
    //struct dma_pool *pool;
};

/**
 * struct rwnx_ipc_elem - Generic IPC buffer of variable size
 *
 * @addr: Host address of the buffer.
 * @dma_addr: DMA address of the buffer.
 * @size: Size, in bytes, of the buffer
 */
struct rwnx_ipc_elem_var {
    void *addr;
    dma_addr_t dma_addr;
    size_t size;
};

#if 1//def CONFIG_RWNX_FULLMAC

/**
 * struct rwnx_skb_cb - Control Buffer structure for RX buffer
 *
 * @dma_addr: DMA address of the data buffer
 * @pattern: Known pattern (used to check pointer on skb)
 * @idx: Index in &struct rwnx_hw.rxbuff_table that contains address of this
 * buffer
 */
struct rwnx_skb_cb {
    dma_addr_t dma_addr;
    uint32_t pattern;
    uint32_t idx;
};
#endif /* CONFIG_RWNX_FULLMAC */

void *rwnx_ipc_fw_trace_desc_get(struct rwnx_hw *rwnx_hw);

void rwnx_ipc_deinit(struct rwnx_hw *rwnx_hw);
int rwnx_check_ipc_txbuf(void);
uint32_t rwnx_tx_post_list_cnt(void);

struct ipc_host_env_tag;

int rwnx_ipc_rxbuf_init(struct rwnx_hw *rwnx_hw);

void wifi_aon_launch(void);

#if PLF_RSSI_DATAPKT
int8_t data_pkt_rssi_get(void);
#endif /* PLF_RSSI_DATAPKT */

#ifdef CFG_WIFI_ENGINEERING_MODE
void wifi_engineering_mode_channel_index_set(uint8_t index);
uint8_t wifi_engineering_mode_channel_index_get(void);
bool wifi_engineering_mode_status_get(void);
void wifi_engineering_mode_status_set(bool flag);
#endif /* CFG_WIFI_ENGINEERING_MODE */
#endif /* _RWNX_UTILS_H_ */
