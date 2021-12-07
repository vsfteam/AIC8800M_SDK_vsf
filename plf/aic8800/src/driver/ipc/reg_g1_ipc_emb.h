#ifndef _REG_G1_IPC_EMB_H_
#define _REG_G1_IPC_EMB_H_

#include <stdint.h>
#include "compiler.h"
#include "arch.h"
#include "reg_access.h"

#define REG_G1_IPC_EMB_COUNT 8

#define REG_G1_IPC_EMB_DECODING_MASK 0x0000001F

/**
 * @brief G1_EMB2APP_TRIGGER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:00   G1_EMB2APP_TRIGGER   0x0
 * </pre>
 */
#define IPC_G1_EMB2APP_TRIGGER_ADDR   0x40044300
#define IPC_G1_EMB2APP_TRIGGER_OFFSET 0x00000000
#define IPC_G1_EMB2APP_TRIGGER_INDEX  0x00000000
#define IPC_G1_EMB2APP_TRIGGER_RESET  0x00000000

__INLINE uint32_t ipc_g1_emb2app_trigger_get(void)
{
    return REG_PL_RD(IPC_G1_EMB2APP_TRIGGER_ADDR);
}

__INLINE void ipc_g1_emb2app_trigger_set(uint32_t value)
{
    REG_PL_WR(IPC_G1_EMB2APP_TRIGGER_ADDR, value);
}

// field definitions
#define IPC_G1_EMB2APP_TRIGGER_MASK   ((uint32_t)0xFFFFFFFF)
#define IPC_G1_EMB2APP_TRIGGER_LSB    0
#define IPC_G1_EMB2APP_TRIGGER_WIDTH  ((uint32_t)0x00000020)

#define IPC_G1_EMB2APP_TRIGGER_RST    0x0

__INLINE uint32_t ipc_g1_emb2app_trigger_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_EMB2APP_TRIGGER_ADDR);
    return (localVal >> 0);
}

__INLINE void ipc_g1_emb2app_trigger_setf(uint32_t g1emb2apptrigger)
{
    REG_PL_WR(IPC_G1_EMB2APP_TRIGGER_ADDR, (uint32_t)g1emb2apptrigger << 0);
}

/**
 * @brief G1_APP2EMB_RAWSTATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:00   G1_APP2EMB_RAWSTATUS   0x0
 * </pre>
 */
#define IPC_G1_APP2EMB_RAWSTATUS_ADDR   0x40044304
#define IPC_G1_APP2EMB_RAWSTATUS_OFFSET 0x00000004
#define IPC_G1_APP2EMB_RAWSTATUS_INDEX  0x00000001
#define IPC_G1_APP2EMB_RAWSTATUS_RESET  0x00000000

__INLINE uint32_t ipc_g1_app2emb_rawstatus_get(void)
{
    return REG_PL_RD(IPC_G1_APP2EMB_RAWSTATUS_ADDR);
}

// field definitions
#define IPC_G1_APP2EMB_RAWSTATUS_MASK   ((uint32_t)0xFFFFFFFF)
#define IPC_G1_APP2EMB_RAWSTATUS_LSB    0
#define IPC_G1_APP2EMB_RAWSTATUS_WIDTH  ((uint32_t)0x00000020)

#define IPC_G1_APP2EMB_RAWSTATUS_RST    0x0

__INLINE uint32_t ipc_g1_app2emb_rawstatus_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_APP2EMB_RAWSTATUS_ADDR);
    return (localVal >> 0);
}

/**
 * @brief G1_APP2EMB_ACK register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:00       G1_APP2EMB_ACK   0x0
 * </pre>
 */
#define IPC_G1_APP2EMB_ACK_ADDR   0x40044308
#define IPC_G1_APP2EMB_ACK_OFFSET 0x00000008
#define IPC_G1_APP2EMB_ACK_INDEX  0x00000002
#define IPC_G1_APP2EMB_ACK_RESET  0x00000000

__INLINE uint32_t ipc_g1_app2emb_ack_get(void)
{
    return REG_PL_RD(IPC_G1_APP2EMB_ACK_ADDR);
}

__INLINE void ipc_g1_app2emb_ack_clear(uint32_t value)
{
    REG_PL_WR(IPC_G1_APP2EMB_ACK_ADDR, value);
}

// field definitions
#define IPC_G1_APP2EMB_ACK_MASK   ((uint32_t)0xFFFFFFFF)
#define IPC_G1_APP2EMB_ACK_LSB    0
#define IPC_G1_APP2EMB_ACK_WIDTH  ((uint32_t)0x00000020)

#define IPC_G1_APP2EMB_ACK_RST    0x0

__INLINE uint32_t ipc_g1_app2emb_ack_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_APP2EMB_ACK_ADDR);
    return (localVal >> 0);
}

__INLINE void ipc_g1_app2emb_ack_clearf(uint32_t g1app2emback)
{
    REG_PL_WR(IPC_G1_APP2EMB_ACK_ADDR, (uint32_t)g1app2emback << 0);
}

/**
 * @brief G1_APP2EMB_UNMASK_SET register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:00    G1_APP2EMB_UNMASK   0x0
 * </pre>
 */
#define IPC_G1_APP2EMB_UNMASK_SET_ADDR   0x4004430C
#define IPC_G1_APP2EMB_UNMASK_SET_OFFSET 0x0000000C
#define IPC_G1_APP2EMB_UNMASK_SET_INDEX  0x00000003
#define IPC_G1_APP2EMB_UNMASK_SET_RESET  0x00000000

__INLINE uint32_t ipc_g1_app2emb_unmask_get(void)
{
    return REG_PL_RD(IPC_G1_APP2EMB_UNMASK_SET_ADDR);
}

__INLINE void ipc_g1_app2emb_unmask_set(uint32_t value)
{
    REG_PL_WR(IPC_G1_APP2EMB_UNMASK_SET_ADDR, value);
}

// field definitions
#define IPC_G1_APP2EMB_UNMASK_MASK   ((uint32_t)0xFFFFFFFF)
#define IPC_G1_APP2EMB_UNMASK_LSB    0
#define IPC_G1_APP2EMB_UNMASK_WIDTH  ((uint32_t)0x00000020)

#define IPC_G1_APP2EMB_UNMASK_RST    0x0

__INLINE uint32_t ipc_g1_app2emb_unmask_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_APP2EMB_UNMASK_SET_ADDR);
    return (localVal >> 0);
}

__INLINE void ipc_g1_app2emb_unmask_setf(uint32_t g1app2embunmask)
{
    REG_PL_WR(IPC_G1_APP2EMB_UNMASK_SET_ADDR, (uint32_t)g1app2embunmask << 0);
}

/**
 * @brief G1_APP2EMB_UNMASK_CLEAR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:00    G1_APP2EMB_UNMASK   0x0
 * </pre>
 */
#define IPC_G1_APP2EMB_UNMASK_CLEAR_ADDR   0x40044310
#define IPC_G1_APP2EMB_UNMASK_CLEAR_OFFSET 0x00000010
#define IPC_G1_APP2EMB_UNMASK_CLEAR_INDEX  0x00000004
#define IPC_G1_APP2EMB_UNMASK_CLEAR_RESET  0x00000000

__INLINE void ipc_g1_app2emb_unmask_clear(uint32_t value)
{
    REG_PL_WR(IPC_G1_APP2EMB_UNMASK_CLEAR_ADDR, value);
}

// fields defined in symmetrical set/clear register
__INLINE void ipc_g1_app2emb_unmask_clearf(uint32_t g1app2embunmask)
{
    REG_PL_WR(IPC_G1_APP2EMB_UNMASK_CLEAR_ADDR, (uint32_t)g1app2embunmask << 0);
}

/**
 * @brief G1_APP2EMB_LINE_SEL_LOW register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:30     G1_APP2EMB15_SEL   0x0
 *  29:28     G1_APP2EMB14_SEL   0x0
 *  27:26     G1_APP2EMB13_SEL   0x0
 *  25:24     G1_APP2EMB12_SEL   0x0
 *  23:22     G1_APP2EMB11_SEL   0x0
 *  21:20     G1_APP2EMB10_SEL   0x0
 *  19:18      G1_APP2EMB9_SEL   0x0
 *  17:16      G1_APP2EMB8_SEL   0x0
 *  15:14      G1_APP2EMB7_SEL   0x0
 *  13:12      G1_APP2EMB6_SEL   0x0
 *  11:10      G1_APP2EMB5_SEL   0x0
 *  09:08      G1_APP2EMB4_SEL   0x0
 *  07:06      G1_APP2EMB3_SEL   0x0
 *  05:04      G1_APP2EMB2_SEL   0x0
 *  03:02      G1_APP2EMB1_SEL   0x0
 *  01:00      G1_APP2EMB0_SEL   0x0
 * </pre>
 */
#define IPC_G1_APP2EMB_LINE_SEL_LOW_ADDR   0x40044314
#define IPC_G1_APP2EMB_LINE_SEL_LOW_OFFSET 0x00000014
#define IPC_G1_APP2EMB_LINE_SEL_LOW_INDEX  0x00000005
#define IPC_G1_APP2EMB_LINE_SEL_LOW_RESET  0x00000000

__INLINE uint32_t ipc_g1_app2emb_line_sel_low_get(void)
{
    return REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_LOW_ADDR);
}

__INLINE void ipc_g1_app2emb_line_sel_low_set(uint32_t value)
{
    REG_PL_WR(IPC_G1_APP2EMB_LINE_SEL_LOW_ADDR, value);
}

// field definitions
#define IPC_G1_APP2EMB15_SEL_MASK   ((uint32_t)0xC0000000)
#define IPC_G1_APP2EMB15_SEL_LSB    30
#define IPC_G1_APP2EMB15_SEL_WIDTH  ((uint32_t)0x00000002)
#define IPC_G1_APP2EMB14_SEL_MASK   ((uint32_t)0x30000000)
#define IPC_G1_APP2EMB14_SEL_LSB    28
#define IPC_G1_APP2EMB14_SEL_WIDTH  ((uint32_t)0x00000002)
#define IPC_G1_APP2EMB13_SEL_MASK   ((uint32_t)0x0C000000)
#define IPC_G1_APP2EMB13_SEL_LSB    26
#define IPC_G1_APP2EMB13_SEL_WIDTH  ((uint32_t)0x00000002)
#define IPC_G1_APP2EMB12_SEL_MASK   ((uint32_t)0x03000000)
#define IPC_G1_APP2EMB12_SEL_LSB    24
#define IPC_G1_APP2EMB12_SEL_WIDTH  ((uint32_t)0x00000002)
#define IPC_G1_APP2EMB11_SEL_MASK   ((uint32_t)0x00C00000)
#define IPC_G1_APP2EMB11_SEL_LSB    22
#define IPC_G1_APP2EMB11_SEL_WIDTH  ((uint32_t)0x00000002)
#define IPC_G1_APP2EMB10_SEL_MASK   ((uint32_t)0x00300000)
#define IPC_G1_APP2EMB10_SEL_LSB    20
#define IPC_G1_APP2EMB10_SEL_WIDTH  ((uint32_t)0x00000002)
#define IPC_G1_APP2EMB9_SEL_MASK    ((uint32_t)0x000C0000)
#define IPC_G1_APP2EMB9_SEL_LSB     18
#define IPC_G1_APP2EMB9_SEL_WIDTH   ((uint32_t)0x00000002)
#define IPC_G1_APP2EMB8_SEL_MASK    ((uint32_t)0x00030000)
#define IPC_G1_APP2EMB8_SEL_LSB     16
#define IPC_G1_APP2EMB8_SEL_WIDTH   ((uint32_t)0x00000002)
#define IPC_G1_APP2EMB7_SEL_MASK    ((uint32_t)0x0000C000)
#define IPC_G1_APP2EMB7_SEL_LSB     14
#define IPC_G1_APP2EMB7_SEL_WIDTH   ((uint32_t)0x00000002)
#define IPC_G1_APP2EMB6_SEL_MASK    ((uint32_t)0x00003000)
#define IPC_G1_APP2EMB6_SEL_LSB     12
#define IPC_G1_APP2EMB6_SEL_WIDTH   ((uint32_t)0x00000002)
#define IPC_G1_APP2EMB5_SEL_MASK    ((uint32_t)0x00000C00)
#define IPC_G1_APP2EMB5_SEL_LSB     10
#define IPC_G1_APP2EMB5_SEL_WIDTH   ((uint32_t)0x00000002)
#define IPC_G1_APP2EMB4_SEL_MASK    ((uint32_t)0x00000300)
#define IPC_G1_APP2EMB4_SEL_LSB     8
#define IPC_G1_APP2EMB4_SEL_WIDTH   ((uint32_t)0x00000002)
#define IPC_G1_APP2EMB3_SEL_MASK    ((uint32_t)0x000000C0)
#define IPC_G1_APP2EMB3_SEL_LSB     6
#define IPC_G1_APP2EMB3_SEL_WIDTH   ((uint32_t)0x00000002)
#define IPC_G1_APP2EMB2_SEL_MASK    ((uint32_t)0x00000030)
#define IPC_G1_APP2EMB2_SEL_LSB     4
#define IPC_G1_APP2EMB2_SEL_WIDTH   ((uint32_t)0x00000002)
#define IPC_G1_APP2EMB1_SEL_MASK    ((uint32_t)0x0000000C)
#define IPC_G1_APP2EMB1_SEL_LSB     2
#define IPC_G1_APP2EMB1_SEL_WIDTH   ((uint32_t)0x00000002)
#define IPC_G1_APP2EMB0_SEL_MASK    ((uint32_t)0x00000003)
#define IPC_G1_APP2EMB0_SEL_LSB     0
#define IPC_G1_APP2EMB0_SEL_WIDTH   ((uint32_t)0x00000002)

#define IPC_G1_APP2EMB15_SEL_RST    0x0
#define IPC_G1_APP2EMB14_SEL_RST    0x0
#define IPC_G1_APP2EMB13_SEL_RST    0x0
#define IPC_G1_APP2EMB12_SEL_RST    0x0
#define IPC_G1_APP2EMB11_SEL_RST    0x0
#define IPC_G1_APP2EMB10_SEL_RST    0x0
#define IPC_G1_APP2EMB9_SEL_RST     0x0
#define IPC_G1_APP2EMB8_SEL_RST     0x0
#define IPC_G1_APP2EMB7_SEL_RST     0x0
#define IPC_G1_APP2EMB6_SEL_RST     0x0
#define IPC_G1_APP2EMB5_SEL_RST     0x0
#define IPC_G1_APP2EMB4_SEL_RST     0x0
#define IPC_G1_APP2EMB3_SEL_RST     0x0
#define IPC_G1_APP2EMB2_SEL_RST     0x0
#define IPC_G1_APP2EMB1_SEL_RST     0x0
#define IPC_G1_APP2EMB0_SEL_RST     0x0

__INLINE void ipc_g1_app2emb_line_sel_low_pack(uint8_t g1app2emb15sel, uint8_t g1app2emb14sel, uint8_t g1app2emb13sel, uint8_t g1app2emb12sel, uint8_t g1app2emb11sel, uint8_t g1app2emb10sel, uint8_t g1app2emb9sel, uint8_t g1app2emb8sel, uint8_t g1app2emb7sel, uint8_t g1app2emb6sel, uint8_t g1app2emb5sel, uint8_t g1app2emb4sel, uint8_t g1app2emb3sel, uint8_t g1app2emb2sel, uint8_t g1app2emb1sel, uint8_t g1app2emb0sel)
{
    REG_PL_WR(IPC_G1_APP2EMB_LINE_SEL_LOW_ADDR,  ((uint32_t)g1app2emb15sel << 30) | ((uint32_t)g1app2emb14sel << 28) | ((uint32_t)g1app2emb13sel << 26) | ((uint32_t)g1app2emb12sel << 24) | ((uint32_t)g1app2emb11sel << 22) | ((uint32_t)g1app2emb10sel << 20) | ((uint32_t)g1app2emb9sel << 18) | ((uint32_t)g1app2emb8sel << 16) | ((uint32_t)g1app2emb7sel << 14) | ((uint32_t)g1app2emb6sel << 12) | ((uint32_t)g1app2emb5sel << 10) | ((uint32_t)g1app2emb4sel << 8) | ((uint32_t)g1app2emb3sel << 6) | ((uint32_t)g1app2emb2sel << 4) | ((uint32_t)g1app2emb1sel << 2) | ((uint32_t)g1app2emb0sel << 0));
}

__INLINE void ipc_g1_app2emb_line_sel_low_unpack(uint8_t* g1app2emb15sel, uint8_t* g1app2emb14sel, uint8_t* g1app2emb13sel, uint8_t* g1app2emb12sel, uint8_t* g1app2emb11sel, uint8_t* g1app2emb10sel, uint8_t* g1app2emb9sel, uint8_t* g1app2emb8sel, uint8_t* g1app2emb7sel, uint8_t* g1app2emb6sel, uint8_t* g1app2emb5sel, uint8_t* g1app2emb4sel, uint8_t* g1app2emb3sel, uint8_t* g1app2emb2sel, uint8_t* g1app2emb1sel, uint8_t* g1app2emb0sel)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_LOW_ADDR);

    *g1app2emb15sel = (localVal & ((uint32_t)0xC0000000)) >> 30;
    *g1app2emb14sel = (localVal & ((uint32_t)0x30000000)) >> 28;
    *g1app2emb13sel = (localVal & ((uint32_t)0x0C000000)) >> 26;
    *g1app2emb12sel = (localVal & ((uint32_t)0x03000000)) >> 24;
    *g1app2emb11sel = (localVal & ((uint32_t)0x00C00000)) >> 22;
    *g1app2emb10sel = (localVal & ((uint32_t)0x00300000)) >> 20;
    *g1app2emb9sel = (localVal & ((uint32_t)0x000C0000)) >> 18;
    *g1app2emb8sel = (localVal & ((uint32_t)0x00030000)) >> 16;
    *g1app2emb7sel = (localVal & ((uint32_t)0x0000C000)) >> 14;
    *g1app2emb6sel = (localVal & ((uint32_t)0x00003000)) >> 12;
    *g1app2emb5sel = (localVal & ((uint32_t)0x00000C00)) >> 10;
    *g1app2emb4sel = (localVal & ((uint32_t)0x00000300)) >> 8;
    *g1app2emb3sel = (localVal & ((uint32_t)0x000000C0)) >> 6;
    *g1app2emb2sel = (localVal & ((uint32_t)0x00000030)) >> 4;
    *g1app2emb1sel = (localVal & ((uint32_t)0x0000000C)) >> 2;
    *g1app2emb0sel = (localVal & ((uint32_t)0x00000003)) >> 0;
}

__INLINE uint8_t ipc_g1_app2emb15_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_LOW_ADDR);
    return ((localVal & ((uint32_t)0xC0000000)) >> 30);
}

__INLINE void ipc_g1_app2emb15_sel_setf(uint8_t g1app2emb15sel)
{
    REG_PL_WR(IPC_G1_APP2EMB_LINE_SEL_LOW_ADDR, (REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_LOW_ADDR) & ~((uint32_t)0xC0000000)) | ((uint32_t)g1app2emb15sel << 30));
}

__INLINE uint8_t ipc_g1_app2emb14_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_LOW_ADDR);
    return ((localVal & ((uint32_t)0x30000000)) >> 28);
}

__INLINE void ipc_g1_app2emb14_sel_setf(uint8_t g1app2emb14sel)
{
    REG_PL_WR(IPC_G1_APP2EMB_LINE_SEL_LOW_ADDR, (REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_LOW_ADDR) & ~((uint32_t)0x30000000)) | ((uint32_t)g1app2emb14sel << 28));
}

__INLINE uint8_t ipc_g1_app2emb13_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_LOW_ADDR);
    return ((localVal & ((uint32_t)0x0C000000)) >> 26);
}

__INLINE void ipc_g1_app2emb13_sel_setf(uint8_t g1app2emb13sel)
{
    REG_PL_WR(IPC_G1_APP2EMB_LINE_SEL_LOW_ADDR, (REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_LOW_ADDR) & ~((uint32_t)0x0C000000)) | ((uint32_t)g1app2emb13sel << 26));
}

__INLINE uint8_t ipc_g1_app2emb12_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_LOW_ADDR);
    return ((localVal & ((uint32_t)0x03000000)) >> 24);
}

__INLINE void ipc_g1_app2emb12_sel_setf(uint8_t g1app2emb12sel)
{
    REG_PL_WR(IPC_G1_APP2EMB_LINE_SEL_LOW_ADDR, (REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_LOW_ADDR) & ~((uint32_t)0x03000000)) | ((uint32_t)g1app2emb12sel << 24));
}

__INLINE uint8_t ipc_g1_app2emb11_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_LOW_ADDR);
    return ((localVal & ((uint32_t)0x00C00000)) >> 22);
}

__INLINE void ipc_g1_app2emb11_sel_setf(uint8_t g1app2emb11sel)
{
    REG_PL_WR(IPC_G1_APP2EMB_LINE_SEL_LOW_ADDR, (REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_LOW_ADDR) & ~((uint32_t)0x00C00000)) | ((uint32_t)g1app2emb11sel << 22));
}

__INLINE uint8_t ipc_g1_app2emb10_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_LOW_ADDR);
    return ((localVal & ((uint32_t)0x00300000)) >> 20);
}

__INLINE void ipc_g1_app2emb10_sel_setf(uint8_t g1app2emb10sel)
{
    REG_PL_WR(IPC_G1_APP2EMB_LINE_SEL_LOW_ADDR, (REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_LOW_ADDR) & ~((uint32_t)0x00300000)) | ((uint32_t)g1app2emb10sel << 20));
}

__INLINE uint8_t ipc_g1_app2emb9_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_LOW_ADDR);
    return ((localVal & ((uint32_t)0x000C0000)) >> 18);
}

__INLINE void ipc_g1_app2emb9_sel_setf(uint8_t g1app2emb9sel)
{
    REG_PL_WR(IPC_G1_APP2EMB_LINE_SEL_LOW_ADDR, (REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_LOW_ADDR) & ~((uint32_t)0x000C0000)) | ((uint32_t)g1app2emb9sel << 18));
}

__INLINE uint8_t ipc_g1_app2emb8_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_LOW_ADDR);
    return ((localVal & ((uint32_t)0x00030000)) >> 16);
}

__INLINE void ipc_g1_app2emb8_sel_setf(uint8_t g1app2emb8sel)
{
    REG_PL_WR(IPC_G1_APP2EMB_LINE_SEL_LOW_ADDR, (REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_LOW_ADDR) & ~((uint32_t)0x00030000)) | ((uint32_t)g1app2emb8sel << 16));
}

__INLINE uint8_t ipc_g1_app2emb7_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_LOW_ADDR);
    return ((localVal & ((uint32_t)0x0000C000)) >> 14);
}

__INLINE void ipc_g1_app2emb7_sel_setf(uint8_t g1app2emb7sel)
{
    REG_PL_WR(IPC_G1_APP2EMB_LINE_SEL_LOW_ADDR, (REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_LOW_ADDR) & ~((uint32_t)0x0000C000)) | ((uint32_t)g1app2emb7sel << 14));
}

__INLINE uint8_t ipc_g1_app2emb6_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_LOW_ADDR);
    return ((localVal & ((uint32_t)0x00003000)) >> 12);
}

__INLINE void ipc_g1_app2emb6_sel_setf(uint8_t g1app2emb6sel)
{
    REG_PL_WR(IPC_G1_APP2EMB_LINE_SEL_LOW_ADDR, (REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_LOW_ADDR) & ~((uint32_t)0x00003000)) | ((uint32_t)g1app2emb6sel << 12));
}

__INLINE uint8_t ipc_g1_app2emb5_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_LOW_ADDR);
    return ((localVal & ((uint32_t)0x00000C00)) >> 10);
}

__INLINE void ipc_g1_app2emb5_sel_setf(uint8_t g1app2emb5sel)
{
    REG_PL_WR(IPC_G1_APP2EMB_LINE_SEL_LOW_ADDR, (REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_LOW_ADDR) & ~((uint32_t)0x00000C00)) | ((uint32_t)g1app2emb5sel << 10));
}

__INLINE uint8_t ipc_g1_app2emb4_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_LOW_ADDR);
    return ((localVal & ((uint32_t)0x00000300)) >> 8);
}

__INLINE void ipc_g1_app2emb4_sel_setf(uint8_t g1app2emb4sel)
{
    REG_PL_WR(IPC_G1_APP2EMB_LINE_SEL_LOW_ADDR, (REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_LOW_ADDR) & ~((uint32_t)0x00000300)) | ((uint32_t)g1app2emb4sel << 8));
}

__INLINE uint8_t ipc_g1_app2emb3_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_LOW_ADDR);
    return ((localVal & ((uint32_t)0x000000C0)) >> 6);
}

__INLINE void ipc_g1_app2emb3_sel_setf(uint8_t g1app2emb3sel)
{
    REG_PL_WR(IPC_G1_APP2EMB_LINE_SEL_LOW_ADDR, (REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_LOW_ADDR) & ~((uint32_t)0x000000C0)) | ((uint32_t)g1app2emb3sel << 6));
}

__INLINE uint8_t ipc_g1_app2emb2_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_LOW_ADDR);
    return ((localVal & ((uint32_t)0x00000030)) >> 4);
}

__INLINE void ipc_g1_app2emb2_sel_setf(uint8_t g1app2emb2sel)
{
    REG_PL_WR(IPC_G1_APP2EMB_LINE_SEL_LOW_ADDR, (REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_LOW_ADDR) & ~((uint32_t)0x00000030)) | ((uint32_t)g1app2emb2sel << 4));
}

__INLINE uint8_t ipc_g1_app2emb1_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_LOW_ADDR);
    return ((localVal & ((uint32_t)0x0000000C)) >> 2);
}

__INLINE void ipc_g1_app2emb1_sel_setf(uint8_t g1app2emb1sel)
{
    REG_PL_WR(IPC_G1_APP2EMB_LINE_SEL_LOW_ADDR, (REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_LOW_ADDR) & ~((uint32_t)0x0000000C)) | ((uint32_t)g1app2emb1sel << 2));
}

__INLINE uint8_t ipc_g1_app2emb0_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_LOW_ADDR);
    return ((localVal & ((uint32_t)0x00000003)) >> 0);
}

__INLINE void ipc_g1_app2emb0_sel_setf(uint8_t g1app2emb0sel)
{
    REG_PL_WR(IPC_G1_APP2EMB_LINE_SEL_LOW_ADDR, (REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_LOW_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)g1app2emb0sel << 0));
}

/**
 * @brief G1_APP2EMB_LINE_SEL_HIGH register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:30     G1_APP2EMB31_SEL   0x0
 *  29:28     G1_APP2EMB30_SEL   0x0
 *  27:26     G1_APP2EMB29_SEL   0x0
 *  25:24     G1_APP2EMB28_SEL   0x0
 *  23:22     G1_APP2EMB27_SEL   0x0
 *  21:20     G1_APP2EMB26_SEL   0x0
 *  19:18     G1_APP2EMB25_SEL   0x0
 *  17:16     G1_APP2EMB24_SEL   0x0
 *  15:14     G1_APP2EMB23_SEL   0x0
 *  13:12     G1_APP2EMB22_SEL   0x0
 *  11:10     G1_APP2EMB21_SEL   0x0
 *  09:08     G1_APP2EMB20_SEL   0x0
 *  07:06     G1_APP2EMB19_SEL   0x0
 *  05:04     G1_APP2EMB18_SEL   0x0
 *  03:02     G1_APP2EMB17_SEL   0x0
 *  01:00     G1_APP2EMB16_SEL   0x0
 * </pre>
 */
#define IPC_G1_APP2EMB_LINE_SEL_HIGH_ADDR   0x40044318
#define IPC_G1_APP2EMB_LINE_SEL_HIGH_OFFSET 0x00000018
#define IPC_G1_APP2EMB_LINE_SEL_HIGH_INDEX  0x00000006
#define IPC_G1_APP2EMB_LINE_SEL_HIGH_RESET  0x00000000

__INLINE uint32_t ipc_g1_app2emb_line_sel_high_get(void)
{
    return REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_HIGH_ADDR);
}

__INLINE void ipc_g1_app2emb_line_sel_high_set(uint32_t value)
{
    REG_PL_WR(IPC_G1_APP2EMB_LINE_SEL_HIGH_ADDR, value);
}

// field definitions
#define IPC_G1_APP2EMB31_SEL_MASK   ((uint32_t)0xC0000000)
#define IPC_G1_APP2EMB31_SEL_LSB    30
#define IPC_G1_APP2EMB31_SEL_WIDTH  ((uint32_t)0x00000002)
#define IPC_G1_APP2EMB30_SEL_MASK   ((uint32_t)0x30000000)
#define IPC_G1_APP2EMB30_SEL_LSB    28
#define IPC_G1_APP2EMB30_SEL_WIDTH  ((uint32_t)0x00000002)
#define IPC_G1_APP2EMB29_SEL_MASK   ((uint32_t)0x0C000000)
#define IPC_G1_APP2EMB29_SEL_LSB    26
#define IPC_G1_APP2EMB29_SEL_WIDTH  ((uint32_t)0x00000002)
#define IPC_G1_APP2EMB28_SEL_MASK   ((uint32_t)0x03000000)
#define IPC_G1_APP2EMB28_SEL_LSB    24
#define IPC_G1_APP2EMB28_SEL_WIDTH  ((uint32_t)0x00000002)
#define IPC_G1_APP2EMB27_SEL_MASK   ((uint32_t)0x00C00000)
#define IPC_G1_APP2EMB27_SEL_LSB    22
#define IPC_G1_APP2EMB27_SEL_WIDTH  ((uint32_t)0x00000002)
#define IPC_G1_APP2EMB26_SEL_MASK   ((uint32_t)0x00300000)
#define IPC_G1_APP2EMB26_SEL_LSB    20
#define IPC_G1_APP2EMB26_SEL_WIDTH  ((uint32_t)0x00000002)
#define IPC_G1_APP2EMB25_SEL_MASK   ((uint32_t)0x000C0000)
#define IPC_G1_APP2EMB25_SEL_LSB    18
#define IPC_G1_APP2EMB25_SEL_WIDTH  ((uint32_t)0x00000002)
#define IPC_G1_APP2EMB24_SEL_MASK   ((uint32_t)0x00030000)
#define IPC_G1_APP2EMB24_SEL_LSB    16
#define IPC_G1_APP2EMB24_SEL_WIDTH  ((uint32_t)0x00000002)
#define IPC_G1_APP2EMB23_SEL_MASK   ((uint32_t)0x0000C000)
#define IPC_G1_APP2EMB23_SEL_LSB    14
#define IPC_G1_APP2EMB23_SEL_WIDTH  ((uint32_t)0x00000002)
#define IPC_G1_APP2EMB22_SEL_MASK   ((uint32_t)0x00003000)
#define IPC_G1_APP2EMB22_SEL_LSB    12
#define IPC_G1_APP2EMB22_SEL_WIDTH  ((uint32_t)0x00000002)
#define IPC_G1_APP2EMB21_SEL_MASK   ((uint32_t)0x00000C00)
#define IPC_G1_APP2EMB21_SEL_LSB    10
#define IPC_G1_APP2EMB21_SEL_WIDTH  ((uint32_t)0x00000002)
#define IPC_G1_APP2EMB20_SEL_MASK   ((uint32_t)0x00000300)
#define IPC_G1_APP2EMB20_SEL_LSB    8
#define IPC_G1_APP2EMB20_SEL_WIDTH  ((uint32_t)0x00000002)
#define IPC_G1_APP2EMB19_SEL_MASK   ((uint32_t)0x000000C0)
#define IPC_G1_APP2EMB19_SEL_LSB    6
#define IPC_G1_APP2EMB19_SEL_WIDTH  ((uint32_t)0x00000002)
#define IPC_G1_APP2EMB18_SEL_MASK   ((uint32_t)0x00000030)
#define IPC_G1_APP2EMB18_SEL_LSB    4
#define IPC_G1_APP2EMB18_SEL_WIDTH  ((uint32_t)0x00000002)
#define IPC_G1_APP2EMB17_SEL_MASK   ((uint32_t)0x0000000C)
#define IPC_G1_APP2EMB17_SEL_LSB    2
#define IPC_G1_APP2EMB17_SEL_WIDTH  ((uint32_t)0x00000002)
#define IPC_G1_APP2EMB16_SEL_MASK   ((uint32_t)0x00000003)
#define IPC_G1_APP2EMB16_SEL_LSB    0
#define IPC_G1_APP2EMB16_SEL_WIDTH  ((uint32_t)0x00000002)

#define IPC_G1_APP2EMB31_SEL_RST    0x0
#define IPC_G1_APP2EMB30_SEL_RST    0x0
#define IPC_G1_APP2EMB29_SEL_RST    0x0
#define IPC_G1_APP2EMB28_SEL_RST    0x0
#define IPC_G1_APP2EMB27_SEL_RST    0x0
#define IPC_G1_APP2EMB26_SEL_RST    0x0
#define IPC_G1_APP2EMB25_SEL_RST    0x0
#define IPC_G1_APP2EMB24_SEL_RST    0x0
#define IPC_G1_APP2EMB23_SEL_RST    0x0
#define IPC_G1_APP2EMB22_SEL_RST    0x0
#define IPC_G1_APP2EMB21_SEL_RST    0x0
#define IPC_G1_APP2EMB20_SEL_RST    0x0
#define IPC_G1_APP2EMB19_SEL_RST    0x0
#define IPC_G1_APP2EMB18_SEL_RST    0x0
#define IPC_G1_APP2EMB17_SEL_RST    0x0
#define IPC_G1_APP2EMB16_SEL_RST    0x0

__INLINE void ipc_g1_app2emb_line_sel_high_pack(uint8_t g1app2emb31sel, uint8_t g1app2emb30sel, uint8_t g1app2emb29sel, uint8_t g1app2emb28sel, uint8_t g1app2emb27sel, uint8_t g1app2emb26sel, uint8_t g1app2emb25sel, uint8_t g1app2emb24sel, uint8_t g1app2emb23sel, uint8_t g1app2emb22sel, uint8_t g1app2emb21sel, uint8_t g1app2emb20sel, uint8_t g1app2emb19sel, uint8_t g1app2emb18sel, uint8_t g1app2emb17sel, uint8_t g1app2emb16sel)
{
    REG_PL_WR(IPC_G1_APP2EMB_LINE_SEL_HIGH_ADDR,  ((uint32_t)g1app2emb31sel << 30) | ((uint32_t)g1app2emb30sel << 28) | ((uint32_t)g1app2emb29sel << 26) | ((uint32_t)g1app2emb28sel << 24) | ((uint32_t)g1app2emb27sel << 22) | ((uint32_t)g1app2emb26sel << 20) | ((uint32_t)g1app2emb25sel << 18) | ((uint32_t)g1app2emb24sel << 16) | ((uint32_t)g1app2emb23sel << 14) | ((uint32_t)g1app2emb22sel << 12) | ((uint32_t)g1app2emb21sel << 10) | ((uint32_t)g1app2emb20sel << 8) | ((uint32_t)g1app2emb19sel << 6) | ((uint32_t)g1app2emb18sel << 4) | ((uint32_t)g1app2emb17sel << 2) | ((uint32_t)g1app2emb16sel << 0));
}

__INLINE void ipc_g1_app2emb_line_sel_high_unpack(uint8_t* g1app2emb31sel, uint8_t* g1app2emb30sel, uint8_t* g1app2emb29sel, uint8_t* g1app2emb28sel, uint8_t* g1app2emb27sel, uint8_t* g1app2emb26sel, uint8_t* g1app2emb25sel, uint8_t* g1app2emb24sel, uint8_t* g1app2emb23sel, uint8_t* g1app2emb22sel, uint8_t* g1app2emb21sel, uint8_t* g1app2emb20sel, uint8_t* g1app2emb19sel, uint8_t* g1app2emb18sel, uint8_t* g1app2emb17sel, uint8_t* g1app2emb16sel)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_HIGH_ADDR);

    *g1app2emb31sel = (localVal & ((uint32_t)0xC0000000)) >> 30;
    *g1app2emb30sel = (localVal & ((uint32_t)0x30000000)) >> 28;
    *g1app2emb29sel = (localVal & ((uint32_t)0x0C000000)) >> 26;
    *g1app2emb28sel = (localVal & ((uint32_t)0x03000000)) >> 24;
    *g1app2emb27sel = (localVal & ((uint32_t)0x00C00000)) >> 22;
    *g1app2emb26sel = (localVal & ((uint32_t)0x00300000)) >> 20;
    *g1app2emb25sel = (localVal & ((uint32_t)0x000C0000)) >> 18;
    *g1app2emb24sel = (localVal & ((uint32_t)0x00030000)) >> 16;
    *g1app2emb23sel = (localVal & ((uint32_t)0x0000C000)) >> 14;
    *g1app2emb22sel = (localVal & ((uint32_t)0x00003000)) >> 12;
    *g1app2emb21sel = (localVal & ((uint32_t)0x00000C00)) >> 10;
    *g1app2emb20sel = (localVal & ((uint32_t)0x00000300)) >> 8;
    *g1app2emb19sel = (localVal & ((uint32_t)0x000000C0)) >> 6;
    *g1app2emb18sel = (localVal & ((uint32_t)0x00000030)) >> 4;
    *g1app2emb17sel = (localVal & ((uint32_t)0x0000000C)) >> 2;
    *g1app2emb16sel = (localVal & ((uint32_t)0x00000003)) >> 0;
}

__INLINE uint8_t ipc_g1_app2emb31_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_HIGH_ADDR);
    return ((localVal & ((uint32_t)0xC0000000)) >> 30);
}

__INLINE void ipc_g1_app2emb31_sel_setf(uint8_t g1app2emb31sel)
{
    REG_PL_WR(IPC_G1_APP2EMB_LINE_SEL_HIGH_ADDR, (REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_HIGH_ADDR) & ~((uint32_t)0xC0000000)) | ((uint32_t)g1app2emb31sel << 30));
}

__INLINE uint8_t ipc_g1_app2emb30_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_HIGH_ADDR);
    return ((localVal & ((uint32_t)0x30000000)) >> 28);
}

__INLINE void ipc_g1_app2emb30_sel_setf(uint8_t g1app2emb30sel)
{
    REG_PL_WR(IPC_G1_APP2EMB_LINE_SEL_HIGH_ADDR, (REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_HIGH_ADDR) & ~((uint32_t)0x30000000)) | ((uint32_t)g1app2emb30sel << 28));
}

__INLINE uint8_t ipc_g1_app2emb29_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_HIGH_ADDR);
    return ((localVal & ((uint32_t)0x0C000000)) >> 26);
}

__INLINE void ipc_g1_app2emb29_sel_setf(uint8_t g1app2emb29sel)
{
    REG_PL_WR(IPC_G1_APP2EMB_LINE_SEL_HIGH_ADDR, (REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_HIGH_ADDR) & ~((uint32_t)0x0C000000)) | ((uint32_t)g1app2emb29sel << 26));
}

__INLINE uint8_t ipc_g1_app2emb28_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_HIGH_ADDR);
    return ((localVal & ((uint32_t)0x03000000)) >> 24);
}

__INLINE void ipc_g1_app2emb28_sel_setf(uint8_t g1app2emb28sel)
{
    REG_PL_WR(IPC_G1_APP2EMB_LINE_SEL_HIGH_ADDR, (REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_HIGH_ADDR) & ~((uint32_t)0x03000000)) | ((uint32_t)g1app2emb28sel << 24));
}

__INLINE uint8_t ipc_g1_app2emb27_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_HIGH_ADDR);
    return ((localVal & ((uint32_t)0x00C00000)) >> 22);
}

__INLINE void ipc_g1_app2emb27_sel_setf(uint8_t g1app2emb27sel)
{
    REG_PL_WR(IPC_G1_APP2EMB_LINE_SEL_HIGH_ADDR, (REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_HIGH_ADDR) & ~((uint32_t)0x00C00000)) | ((uint32_t)g1app2emb27sel << 22));
}

__INLINE uint8_t ipc_g1_app2emb26_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_HIGH_ADDR);
    return ((localVal & ((uint32_t)0x00300000)) >> 20);
}

__INLINE void ipc_g1_app2emb26_sel_setf(uint8_t g1app2emb26sel)
{
    REG_PL_WR(IPC_G1_APP2EMB_LINE_SEL_HIGH_ADDR, (REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_HIGH_ADDR) & ~((uint32_t)0x00300000)) | ((uint32_t)g1app2emb26sel << 20));
}

__INLINE uint8_t ipc_g1_app2emb25_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_HIGH_ADDR);
    return ((localVal & ((uint32_t)0x000C0000)) >> 18);
}

__INLINE void ipc_g1_app2emb25_sel_setf(uint8_t g1app2emb25sel)
{
    REG_PL_WR(IPC_G1_APP2EMB_LINE_SEL_HIGH_ADDR, (REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_HIGH_ADDR) & ~((uint32_t)0x000C0000)) | ((uint32_t)g1app2emb25sel << 18));
}

__INLINE uint8_t ipc_g1_app2emb24_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_HIGH_ADDR);
    return ((localVal & ((uint32_t)0x00030000)) >> 16);
}

__INLINE void ipc_g1_app2emb24_sel_setf(uint8_t g1app2emb24sel)
{
    REG_PL_WR(IPC_G1_APP2EMB_LINE_SEL_HIGH_ADDR, (REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_HIGH_ADDR) & ~((uint32_t)0x00030000)) | ((uint32_t)g1app2emb24sel << 16));
}

__INLINE uint8_t ipc_g1_app2emb23_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_HIGH_ADDR);
    return ((localVal & ((uint32_t)0x0000C000)) >> 14);
}

__INLINE void ipc_g1_app2emb23_sel_setf(uint8_t g1app2emb23sel)
{
    REG_PL_WR(IPC_G1_APP2EMB_LINE_SEL_HIGH_ADDR, (REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_HIGH_ADDR) & ~((uint32_t)0x0000C000)) | ((uint32_t)g1app2emb23sel << 14));
}

__INLINE uint8_t ipc_g1_app2emb22_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_HIGH_ADDR);
    return ((localVal & ((uint32_t)0x00003000)) >> 12);
}

__INLINE void ipc_g1_app2emb22_sel_setf(uint8_t g1app2emb22sel)
{
    REG_PL_WR(IPC_G1_APP2EMB_LINE_SEL_HIGH_ADDR, (REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_HIGH_ADDR) & ~((uint32_t)0x00003000)) | ((uint32_t)g1app2emb22sel << 12));
}

__INLINE uint8_t ipc_g1_app2emb21_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_HIGH_ADDR);
    return ((localVal & ((uint32_t)0x00000C00)) >> 10);
}

__INLINE void ipc_g1_app2emb21_sel_setf(uint8_t g1app2emb21sel)
{
    REG_PL_WR(IPC_G1_APP2EMB_LINE_SEL_HIGH_ADDR, (REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_HIGH_ADDR) & ~((uint32_t)0x00000C00)) | ((uint32_t)g1app2emb21sel << 10));
}

__INLINE uint8_t ipc_g1_app2emb20_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_HIGH_ADDR);
    return ((localVal & ((uint32_t)0x00000300)) >> 8);
}

__INLINE void ipc_g1_app2emb20_sel_setf(uint8_t g1app2emb20sel)
{
    REG_PL_WR(IPC_G1_APP2EMB_LINE_SEL_HIGH_ADDR, (REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_HIGH_ADDR) & ~((uint32_t)0x00000300)) | ((uint32_t)g1app2emb20sel << 8));
}

__INLINE uint8_t ipc_g1_app2emb19_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_HIGH_ADDR);
    return ((localVal & ((uint32_t)0x000000C0)) >> 6);
}

__INLINE void ipc_g1_app2emb19_sel_setf(uint8_t g1app2emb19sel)
{
    REG_PL_WR(IPC_G1_APP2EMB_LINE_SEL_HIGH_ADDR, (REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_HIGH_ADDR) & ~((uint32_t)0x000000C0)) | ((uint32_t)g1app2emb19sel << 6));
}

__INLINE uint8_t ipc_g1_app2emb18_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_HIGH_ADDR);
    return ((localVal & ((uint32_t)0x00000030)) >> 4);
}

__INLINE void ipc_g1_app2emb18_sel_setf(uint8_t g1app2emb18sel)
{
    REG_PL_WR(IPC_G1_APP2EMB_LINE_SEL_HIGH_ADDR, (REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_HIGH_ADDR) & ~((uint32_t)0x00000030)) | ((uint32_t)g1app2emb18sel << 4));
}

__INLINE uint8_t ipc_g1_app2emb17_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_HIGH_ADDR);
    return ((localVal & ((uint32_t)0x0000000C)) >> 2);
}

__INLINE void ipc_g1_app2emb17_sel_setf(uint8_t g1app2emb17sel)
{
    REG_PL_WR(IPC_G1_APP2EMB_LINE_SEL_HIGH_ADDR, (REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_HIGH_ADDR) & ~((uint32_t)0x0000000C)) | ((uint32_t)g1app2emb17sel << 2));
}

__INLINE uint8_t ipc_g1_app2emb16_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_HIGH_ADDR);
    return ((localVal & ((uint32_t)0x00000003)) >> 0);
}

__INLINE void ipc_g1_app2emb16_sel_setf(uint8_t g1app2emb16sel)
{
    REG_PL_WR(IPC_G1_APP2EMB_LINE_SEL_HIGH_ADDR, (REG_PL_RD(IPC_G1_APP2EMB_LINE_SEL_HIGH_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)g1app2emb16sel << 0));
}

/**
 * @brief G1_APP2EMB_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:00    G1_APP2EMB_STATUS   0x0
 * </pre>
 */
#define IPC_G1_APP2EMB_STATUS_ADDR   0x4004431C
#define IPC_G1_APP2EMB_STATUS_OFFSET 0x0000001C
#define IPC_G1_APP2EMB_STATUS_INDEX  0x00000007
#define IPC_G1_APP2EMB_STATUS_RESET  0x00000000

__INLINE uint32_t ipc_g1_app2emb_status_get(void)
{
    return REG_PL_RD(IPC_G1_APP2EMB_STATUS_ADDR);
}

// field definitions
#define IPC_G1_APP2EMB_STATUS_MASK   ((uint32_t)0xFFFFFFFF)
#define IPC_G1_APP2EMB_STATUS_LSB    0
#define IPC_G1_APP2EMB_STATUS_WIDTH  ((uint32_t)0x00000020)

#define IPC_G1_APP2EMB_STATUS_RST    0x0

__INLINE uint32_t ipc_g1_app2emb_status_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_APP2EMB_STATUS_ADDR);
    return (localVal >> 0);
}


#endif // _REG_G1_IPC_EMB_H_

