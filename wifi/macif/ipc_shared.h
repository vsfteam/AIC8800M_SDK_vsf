/**
 ****************************************************************************************
 *
 * @file ipc_shared.h
 *
 * @brief Shared data between both IPC modules.
 *
 * Copyright (C) RivieraWaves 2011-2019
 *
 ****************************************************************************************
 */

#ifndef _IPC_SHARED_H_
#define _IPC_SHARED_H_

/**
 ****************************************************************************************
 * @defgroup IPC IPC
 * @ingroup PLATFORM_DRIVERS
 * @brief Inter Processor Communication module.
 *
 * The IPC module implements the protocol to communicate between the Host CPU
 * and the Embedded CPU.
 *
 * A typical use case of the IPC Tx path API:
 * @msc
 * hscale = "2";
 *
 * a [label=Driver],
 * b [label="IPC host"],
 * c [label="IPC emb"],
 * d [label=Firmware];
 *
 * ---   [label="Tx descriptor queue example"];
 * a=>a  [label="Driver receives a Tx packet from OS"];
 * a=>b  [label="ipc_host_txdesc_get()"];
 * a<<b  [label="struct txdesc_host *"];
 * a=>a  [label="Driver fill the descriptor"];
 * a=>b  [label="ipc_host_txdesc_push()"];
 * ...   [label="(several Tx desc can be pushed)"];
 * b:>c  [label="Tx desc queue filled IRQ"];
 * c=>>d [label="IPC emb Tx desc callback"];
 * ...   [label="(several Tx desc can be popped)"];
 * d=>d  [label="Packets are sent or discarded"];
 * ---   [label="Tx confirm queue example"];
 * c<=d  [label="ipc_emb_txcfm_push()"];
 * c>>d  [label="Request accepted"];
 * ...   [label="(several Tx cfm can be pushed)"];
 * b<:c  [label="Tx cfm queue filled IRQ"];
 * a<<=b [label="Driver's Tx Confirm callback"];
 * a=>b  [label="ipc_host_txcfm_pop()"];
 * a<<b  [label="struct ipc_txcfm"];
 * a<=a  [label="Packets are freed by the driver"];
 * @endmsc
 *
 * A typical use case of the IPC Rx path API:
 * @msc
 * hscale = "2";
 *
 * a [label=Firmware],
 * b [label="IPC emb"],
 * c [label="IPC host"],
 * d [label=Driver];
 *
 * ---   [label="Rx buffer and desc queues usage example"];
 * d=>c  [label="ipc_host_rxbuf_push()"];
 * d=>c  [label="ipc_host_rxbuf_push()"];
 * d=>c  [label="ipc_host_rxbuf_push()"];
 * ...   [label="(several Rx buffer are pushed)"];
 * a=>a  [label=" Frame is received\n from the medium"];
 * a<<b  [label="struct ipc_rxbuf"];
 * a=>a  [label=" Firmware fill the buffer\n with received frame"];
 * a<<b  [label="Push accepted"];
 * ...   [label="(several Rx desc can be pushed)"];
 * b:>c  [label="Rx desc queue filled IRQ"];
 * c=>>d [label="Driver Rx packet callback"];
 * c<=d  [label="ipc_host_rxdesc_pop()"];
 * d=>d  [label="Rx packet is handed \nover to the OS "];
 * ...   [label="(several Rx desc can be poped)"];
 * ---   [label="Rx buffer request exemple"];
 * b:>c  [label="Low Rx buffer count IRQ"];
 * a<<b  [label="struct ipc_rxbuf"];
 * c=>>d [label="Driver Rx buffer callback"];
 * d=>c  [label="ipc_host_rxbuf_push()"];
 * d=>c  [label="ipc_host_rxbuf_push()"];
 * d=>c  [label="ipc_host_rxbuf_push()"];
 * ...   [label="(several Rx buffer are pushed)"];
 * @endmsc
 *
 * @{
 ****************************************************************************************
 */

/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include "co_int.h"
#include "tx_swdesc.h"
#include "rwnx_config.h"

/*
 * DEFINES AND MACROS
 ****************************************************************************************
 */
/// Number of IPC TX queues
#define IPC_TXQUEUE_CNT     NX_TXQ_CNT

/// Number of Host buffers available for Data Rx handling (through DMA)
#ifdef CFG_HS_IPERF
#define IPC_RXBUF_CNT       25
#else
#define IPC_RXBUF_CNT       11
#endif

#define IPC_TXBUF_CNT       32

//memory addr: 0x190800 (30K)
#define IPC_FW_TXBUF_CNT    17

/// Number of shared descriptors available for Data RX handling
#define IPC_RXDESC_CNT      32

/// Number of Host buffers available for Radar events handling (through DMA)
#define IPC_RADARBUF_CNT       16

///Number of Host buffers available for unsupported rx vector handling (through DMA)
#define IPC_UNSUPRXVECBUF_CNT   8

#define IPC_MSGE2A_BUF_CNT      8

/// Length used in APP2EMB MSGs structures
#ifdef CFG_RWTL
#define IPC_A2E_MSG_BUF_SIZE    127 // size in 4-byte words
#else
#define IPC_A2E_MSG_BUF_SIZE    127 // size in 4-byte words
#endif

/// Length required in EMB2APP MSGs structures, for non-TL4 case
#define IPC_E2A_MSG_SIZE_BASE   256//15 // size in 4-byte words

/// Length used in EMB2APP MSGs structures, including the potential overhead for TL4
#ifdef CFG_RWTL
#define IPC_E2A_MSG_PARAM_SIZE   (IPC_E2A_MSG_SIZE_BASE + (IPC_E2A_MSG_SIZE_BASE / 2))
#else
#define IPC_E2A_MSG_PARAM_SIZE   IPC_E2A_MSG_SIZE_BASE
#endif

/// Define used for Rx hostbuf validity.
/// This value should appear only when hostbuf was used for a Reception.
#define RX_DMA_OVER_PATTERN 0xAAAAAA00

/**
 * Define used for MSG buffers validity.
 * This value will be written only when a MSG buffer is used for sending from Emb to App.
 */
#define IPC_MSGE2A_VALID_PATTERN 0xADDEDE2A

/// Message structure for MSGs from Emb to App
struct ipc_e2a_msg
{
    uint16_t id;                ///< Message id.
    uint16_t dummy_dest_id;     ///< Not used
    uint16_t dummy_src_id;      ///< Not used
    uint16_t param_len;         ///< Parameter embedded struct length.

    uint32_t pattern;           ///< Used to stamp a valid MSG buffer
    uint32_t param[IPC_E2A_MSG_PARAM_SIZE];  ///< Parameter embedded struct. Must be word-aligned.
};

/// Message structure for MSGs from App to Emb.
/// Actually a sub-structure will be used when filling the messages.
struct ipc_a2e_msg
{
    uint32_t dummy_word;                ///< used to cope with kernel message structure
    uint32_t msg[IPC_A2E_MSG_BUF_SIZE]; ///< body of the msg
};

/// Information provided by host to indentify RX buffer
struct ipc_shared_rx_buf
{
    /// ptr to hostbuf client (ipc_host client) structure
    uint32_t hostid;
    /// ptr to real hostbuf dma address
    uint32_t dma_addr;
};

/// Information provided by host to indentify RX desc
struct ipc_shared_rx_desc
{
    /// DMA Address
    uint32_t dma_addr;
};

#ifdef CFG_DEVICE_IPC
typedef struct {
    struct co_list_hdr list_hdr;
    uint32_t msg_data[1];
} devipc_custmsg_node_t;
#endif

/*
 * TYPE and STRUCT DEFINITIONS
 ****************************************************************************************
 */
// Indexes are defined in the MIB shared structure
/// Structure describing the IPC data shared with the host CPU
struct ipc_shared_env_tag
{
    ///FW characteristics
    //volatile struct compatibility_tag comp_info;

    /// AP MGMT TX Status
    uint32_t statinfo;

    /// Room for MSG to be sent from App to Emb
    volatile struct ipc_a2e_msg msg_a2e_buf;

    /// Room to build the Emb->App MSGs Xferred
    //volatile struct    ipc_e2a_msg msg_e2a_buf;

    /// Host buffer addresses for Emb->App MSGs DMA Xfers
    struct co_list msg_e2a_hostbuf_free_list;
    struct co_list msg_e2a_hostbuf_post_list;

    #if NX_RADAR_DETECT
    /// Host buffer addresses for the radar events
    volatile uint32_t  radarbuf_hostbuf [IPC_RADARBUF_CNT]; // buffers @ for Radar Events
    #endif

    #if NX_UF_EN
    /// Host buffer addresses for the unsupported rx vectors
    struct co_list uf_e2a_hostbuf_free_list;
    struct co_list uf_e2a_hostbuf_post_list;
    #endif /* NX_UF_EN */

    /// RX Descriptors Array
    //volatile struct ipc_shared_rx_desc host_rxdesc[IPC_RXDESC_CNT];
    /// RX Buffers Array
    struct co_list rx_e2a_hostbuf_free_list;
    struct co_list rx_e2a_hostbuf_post_list;

    struct co_list a2e_tx_mem_free_list;
    struct co_list a2e_tx_mem_post_list;
    volatile uint32_t a2e_adjlen; // adjust len for app2emb pkt buf

    #if defined(CFG_DEVICE_IPC)
    struct co_list e2a_cust_msg_free_list;
    struct co_list e2a_cust_msg_post_list;
    struct co_list a2e_cust_msg_free_list;
    struct co_list a2e_cust_msg_post_list;
    #endif
};

/// IPC Shared environment
extern struct ipc_shared_env_tag ipc_shared_env;

///
struct rxdesc_tag
{
    /// Host Buffer Address
    uint32_t host_id;
    /// Length
    uint32_t frame_len;
    /// Status
    uint16_t status;
};

/*
 * TYPE and STRUCT DEFINITIONS
 ****************************************************************************************
 */
/// @name APP2EMB IPC interrupt definitions
/// @{

/// Interrupts bits used for the TX descriptors of the AC queues
/// IPC TX descriptor interrupt mask
#define IPC_IRQ_A2E_TXDESC          0x0F00

/// IPC APP2EMB power down request interrupt bit
#define IPC_IRQ_A2E_PWRDN_REQ       CO_BIT(31)
/// IPC APP2EMB clock gate request interrupt bit
#define IPC_IRQ_A2E_CLKGATE_REQ     CO_BIT(30)

#if defined(CFG_DEVICE_IPC)
/// IPC APP2EMB customer message
#define IPC_IRQ_A2E_CUSTOM_MSG      CO_BIT(13)
#endif

/// First of the IPC TX descriptor interrupts, bit8 ~ bit11
#define IPC_IRQ_A2E_TXDESC_FIRSTBIT (8)
/// IPC RX buffer allocation interrupt bit
#define IPC_IRQ_A2E_RXBUF_BACK      CO_BIT(5)
/// IPC APP2EMB message interrupt bit
#define IPC_IRQ_A2E_MSG             CO_BIT(1)
/// IPC global interrupt mask
#define IPC_IRQ_A2E_ALL             (IPC_IRQ_A2E_TXDESC|IPC_IRQ_A2E_MSG)

/// @}

/// @name EMB2APP IPC interrupt definitions
/// IPC EMB2APP not allow low power interrupt
#define IPC_IRQ_E2A_LOWPWR_NOT_ALLOW    CO_BIT(31)
/// IPC EMB2APP allow low power interrupt
#define IPC_IRQ_E2A_LOWPWR_ALLOW        CO_BIT(30)

#if defined(CFG_DEVICE_IPC)
/// IPC EMB2APP customer message
#define IPC_IRQ_E2A_CUSTOM_MSG          CO_BIT(10)
#endif

/// IPC EMB2APP wifi fw idle indication interrupt
#define IPC_IRQ_E2A_WIFI_FW_IDLE_IND    CO_BIT(9)
/// IPC mgmt tx cfm interrupt
#define IPC_IRQ_E2A_MGMT_CFM     CO_BIT(8)
/// IPC unsupported rx vector interrupt
#define IPC_IRQ_E2A_UNSUP_RX_VEC CO_BIT(7)
/// IPC secondary TBTT interrupt
#define IPC_IRQ_E2A_TBTT_SEC     CO_BIT(5)
/// IPC primary TBTT interrupt
#define IPC_IRQ_E2A_TBTT_PRIM    CO_BIT(4)
/// IPC RX descriptor interrupt
#define IPC_IRQ_E2A_RXDESC       CO_BIT(3)
/// IPC APP2EMB message acknowledgment interrupt
#define IPC_IRQ_E2A_MSG_ACK      CO_BIT(2)
/// IPC EMB2APP message interrupt
#define IPC_IRQ_E2A_MSG          CO_BIT(1)
/// IPC EMB2APP ready interrupt
#define IPC_IRQ_EMB_READY        CO_BIT(0)
/// IPC EMB2APP global interrupt mask
#if defined(CFG_DEVICE_IPC)
#define IPC_IRQ_WIFI_E2A_ALL    ( IPC_IRQ_E2A_RXDESC        \
                                | IPC_IRQ_E2A_MSG_ACK       \
                                | IPC_IRQ_E2A_MSG           \
                                | IPC_IRQ_EMB_READY         \
                                | IPC_IRQ_E2A_MGMT_CFM      \
                                | IPC_IRQ_E2A_UNSUP_RX_VEC  \
                                | IPC_IRQ_E2A_WIFI_FW_IDLE_IND \
                                | IPC_IRQ_E2A_CUSTOM_MSG    \
                                | IPC_IRQ_E2A_LOWPWR_ALLOW)
#else
#define IPC_IRQ_WIFI_E2A_ALL    ( IPC_IRQ_E2A_RXDESC        \
                                | IPC_IRQ_E2A_MSG_ACK       \
                                | IPC_IRQ_E2A_MSG           \
                                | IPC_IRQ_EMB_READY         \
                                | IPC_IRQ_E2A_MGMT_CFM      \
                                | IPC_IRQ_E2A_UNSUP_RX_VEC  \
                                | IPC_IRQ_E2A_WIFI_FW_IDLE_IND \
                                | IPC_IRQ_E2A_LOWPWR_ALLOW)
#endif

#endif // _IPC_SHARED_H_

