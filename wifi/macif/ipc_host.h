/**
 ****************************************************************************************
 *
 * @file ipc_host.h
 *
 * @brief IPC module.
 *
 * Copyright (C) RivieraWaves 2011-2019
 *
 ****************************************************************************************
 */
#ifndef _IPC_HOST_H_
#define _IPC_HOST_H_

/** @addtogroup IPC
 *  @{
 */

/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include "ipc_shared.h"
#if defined(CFG_DEVICE_IPC)
#include "devipc_cmd.h"
#endif

/*
 * ENUMERATION
 ****************************************************************************************
 */

enum ipc_host_desc_status
{
    /// Descriptor is IDLE
    IPC_HOST_DESC_IDLE      = 0,
    /// Data can be forwarded
    IPC_HOST_DESC_FORWARD,
    /// Data has to be kept in UMAC memory
    IPC_HOST_DESC_KEEP,
    /// Delete stored packet
    IPC_HOST_DESC_DELETE,
    /// Update Frame Length status
    IPC_HOST_DESC_LEN_UPDATE,
    /// Update Frame Length + Length field inside Ethernet Header status
    IPC_HOST_DESC_ETH_LEN_UPDATE,
};

/*
 * TYPE DECLARATION
 ****************************************************************************************
 */

/**
 ****************************************************************************************
 * @brief This structure is used to initialize the MAC SW
 *
 * The WLAN device driver provides functions call-back with this structure
 ****************************************************************************************
 */
struct ipc_irq_elem
{
    uint32_t    status;     ///< Status of the irq
    uint32_t    param;     ///< param of the irq
};

struct ipc_txcfm
{
    uint32_t    hostid;     ///< Pre-allocated packet ID from the OS (skbuff on Linux)
    uint32_t    status;     ///< Status of the transmission
};

struct ipc_host_cb_tag
{
    /// WLAN driver call-back function: send_data_cfm
    int (*send_data_cfm)(void *pthis, void* host_id);

    /// WLAN driver call-back function: recv_data_ind
    uint8_t (*recv_data_ind)(void *pthis, void* host_id);

    /// WLAN driver call-back function: recv_msg_ind
    int8_t (*recv_msg_ind)(void *pthis, void* host_id);

#if NX_UF_EN
    /// WLAN driver call-back function: recv_unsup_rx_vec_ind
    uint8_t (*recv_unsup_rx_vec_ind)(void *pthis, void *host_id);
#endif /* NX_UF_EN */

    /// WLAN driver call-back function: recv_msgack_ind
    uint8_t (*recv_msgack_ind)(void *pthis, void* host_id);

    /// WLAN driver call-back function: recv_dbg_ind
    //uint8_t (*recv_dbg_ind)(void *pthis, uint32_t host_id);

    /// WLAN driver call-back function: prim_tbtt_ind
    //void (*prim_tbtt_ind)(void *pthis);

    /// WLAN driver call-back function: sec_tbtt_ind
    //void (*sec_tbtt_ind)(void *pthis);

};

/*
 * Struct used to store information about host buffers (DMA Address and local pointer)
 */
struct ipc_hostbuf
{
    uint32_t hostid;      ///< ptr to hostbuf client (ipc_host client) structure
    uint32_t dma_addr;    ///< ptr to real hostbuf dma address
};

/*
 * Struct used to store information about host descriptors (DMA Address and local pointer)
 */
struct ipc_hostdesc
{
    uint32_t dma_addr;    ///< ptr to real hostbuf dma address
};

/// Definition of the IPC Host environment structure.
struct ipc_host_env_tag
{
    /// Structure containing the callback pointers
    struct ipc_host_cb_tag cb;

    /// Pointer to the shared environment
    struct ipc_shared_env_tag *shared;

    // Store the number of E2A MSG buffers
    uint32_t ipc_e2amsg_bufnb;
    // Store the size of the E2A MSG buffers
    uint32_t ipc_e2amsg_bufsz;

    /// E2A ACKs of A2E MSGs
    uint8_t msga2e_cnt;
    uint32_t msga2e_hostid;

    uint32_t ipc_tx_offset;
    /// Pointer to the attached object (used in callbacks and register accesses)
    void *pthis;
};

/**
 ****************************************************************************************
 * @brief Initialize the IPC running on the Application CPU.
 *
 * This function:
 *   - initializes the IPC software environments
 *   - enables the interrupts in the IPC block
 *
 * @param[in]   env   Pointer to the IPC host environment
 *
 * @warning Since this function resets the IPC Shared memory, it must be called before
 * the LMAC FW is launched because LMAC sets some init values in IPC Shared memory at boot.
 *
 ****************************************************************************************
 */
void ipc_host_init(struct ipc_host_env_tag *env,
                  struct ipc_host_cb_tag *cb,
                  struct ipc_shared_env_tag *shared_env_ptr,
                  void *pthis);


/**
 ****************************************************************************************
 * @brief Retrieve a new free Tx descriptor (host side).
 *
 * This function returns a pointer to the next Tx descriptor available from the queue
 * queue_idx to the host driver. The driver will have to fill it with the
 * appropriate endianness and to send it to the
 * emb side with ipc_host_txdesc_push().
 *
 * This function should only be called once until ipc_host_txdesc_push() is called.
 *
 * This function will return NULL if the queue is full.
 *
 * @param[in]   env   Pointer to the IPC host environment
 * @param[in]   queue_idx   Queue index. The index can be inferred from the user priority
 *                          of the incoming packet.
 * @return                  Pointer to the next Tx descriptor free. This can point to
 *                          the host memory or to shared memory, depending on IPC
 *                          implementation.
 *
 ****************************************************************************************
 */
volatile struct txdesc_host *ipc_host_txdesc_get(struct ipc_host_env_tag *env,
                                                 const int queue_idx);


/**
 ****************************************************************************************
 * @brief Push a filled Tx descriptor (host side).
 *
 * This function sets the next Tx descriptor available by the host side:
 * - as used for the host side
 * - as available for the emb side.
 * The Tx descriptor must be correctly filled before calling this function.
 *
 * This function may trigger an IRQ to the emb CPU depending on the interrupt
 * mitigation policy and on the push count.
 *
 * @param[in]   queue_idx   Queue index. Same value than ipc_host_txdesc_get()
 *
 ****************************************************************************************
 */
void ipc_host_txdesc_push(const int queue_idx);


/**
 ****************************************************************************************
 * @brief Push a pre-allocated buffer descriptor for Rx packet (host side)
 *
 * This function should be called by the host IRQ handler to supply the embedded
 * side with new empty buffer.
 *
 * @param[in]   env         Pointer to the IPC host environment
 * @param[in]   hostid      Packet ID used by the host (skbuff pointer on Linux)
 * @param[in]   hostbuf     Pointer to the start of the buffer payload in the
 *                          host memory (this may be inferred from the skbuff?)
 *                          The length of this buffer should be predefined
 *                          between host and emb statically (constant needed?).
 *
 ****************************************************************************************
 */
int ipc_host_rxbuf_push(struct ipc_host_env_tag *env, uint32_t hostid, uint32_t hostbuf);


/**
 ****************************************************************************************
 * @brief Push a pre-allocated buffer descriptor for MSGs (host side)
 *
 * This function is only called at Init time since the MSGs will be handled directly and
 * buffer can be re-used as soon as the message is handled, no need to re-allocate new
 * buffers in the meantime.
 *
 * @param[in]   env         Pointer to the IPC host environment
 * @param[in]   hostid      Packet ID used by the host (skbuff pointer on Linux)
 * @param[in]   hostbuf     Pointer to the start of the buffer payload in the
 *                          host memory.
 *                          The length of this buffer should be predefined
 *                          between host and emb statically.
 *
 ****************************************************************************************
 */
int ipc_host_msgbuf_push(struct ipc_host_env_tag *env, void *hostid,
                                                       uint32_t hostbuf);

/**
 ****************************************************************************************
 * @brief Push a pre-allocated buffer descriptor for Debug messages (host side)
 *
 * This function is only called at Init time since the Debug messages will be handled directly and
 * buffer can be re-used as soon as the message is handled, no need to re-allocate new
 * buffers in the meantime.
 *
 * @param[in]   env         Pointer to the IPC host environment
 * @param[in]   hostid      Packet ID used by the host (skbuff pointer on Linux)
 * @param[in]   hostbuf     Pointer to the start of the buffer payload in the
 *                          host memory.
 *                          The length of this buffer should be predefined
 *                          between host and emb statically.
 *
 ****************************************************************************************
 */
int ipc_host_dbgbuf_push(struct ipc_host_env_tag *env, uint32_t hostid,
                                                       uint32_t hostbuf);

/**
 ****************************************************************************************
 * @brief Push the pre-allocated logic analyzer and debug information buffer
 *
 * @param[in]   env         Pointer to the IPC host environment
 * @param[in]   infobuf     Pointer to the start of the buffer payload in the
 *                          host memory.
 *                          The length of this buffer should be predefined
 *                          between host and emb statically.
 *
 ****************************************************************************************
 */
void ipc_host_dbginfobuf_push(struct ipc_host_env_tag *env, uint32_t infobuf);


/**
 ****************************************************************************************
 * @brief Handle all IPC interrupts on the host side.
 *
 * The following interrupts should be handled:
 * Tx confirmation, Rx buffer requests, Rx packet ready and kernel messages
 *
 * @param[in]   env   Pointer to the IPC host environment
 *
 ****************************************************************************************
 */
void ipc_host_irq(struct ipc_host_env_tag *env, struct ipc_irq_elem *elem);

/**
 ****************************************************************************************
 * @brief Handler for kernel message called from general IRQ handler
 *
 * @param[in]   env      pointer to the IPC Host environment
 ****************************************************************************************
 */
void ipc_host_msg_handler(struct ipc_host_env_tag *env);

/**
 ****************************************************************************************
 * @brief Send a message to the embedded side
 *
 * @param[in]   env      Pointer to the IPC host environment
 * @param[in]   msg_buf  Pointer to the message buffer
 * @param[in]   msg_len  Length of the message to be transmitted
 *
 * @return      Non-null value on failure
 *
 ****************************************************************************************
 */
int ipc_host_msg_push(struct ipc_host_env_tag *env, void *msg_buf, uint16_t len);

#if defined(CFG_DEVICE_IPC)
void devipc_custom_msg_push(struct dbg_custom_msg_cfm *cfm);
#endif

/**
 ****************************************************************************************
 * @brief Enable IPC interrupts
 *
 * @param[in]   env  Global ipc_host environment pointer
 * @param[in]   value  Bitfield of the interrupts to enable
 *
 * @warning After calling this function, IPC interrupts can be triggered at any time.
 * Potentially, an interrupt could happen even before returning from the function if
 * there is a request pending from the embedded side.
 *
 ****************************************************************************************
 */
void ipc_host_enable_irq(struct ipc_host_env_tag *env, uint32_t value);

uint32_t ipc_host_get_status(void);
uint32_t ipc_host_get_rawstatus(void);
#if NX_UF_EN
int ipc_host_unsup_rx_vec_buf_push(struct ipc_host_env_tag *env, void *hostid, uint32_t hostbuf);
#endif /* NX_UF_EN */
uint8_t wifi_sleep_level_get(void);

/// @} IPC


#endif // _IPC_HOST_H_
