#ifndef _REG_G1_IPC_APP_H_
#define _REG_G1_IPC_APP_H_

#include <stdint.h>
#include "compiler.h"
#include "arch.h"
#include "reg_access.h"

#define REG_G1_IPC_APP_COUNT 8

#define REG_G1_IPC_APP_DECODING_MASK 0x0000001F

/**
 * @brief G1_APP2EMB_TRIGGER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:00   G1_APP2EMB_TRIGGER   0x0
 * </pre>
 */
#define IPC_G1_APP2EMB_TRIGGER_ADDR   0x40044200
#define IPC_G1_APP2EMB_TRIGGER_OFFSET 0x00000000
#define IPC_G1_APP2EMB_TRIGGER_INDEX  0x00000000
#define IPC_G1_APP2EMB_TRIGGER_RESET  0x00000000

__INLINE uint32_t ipc_g1_app2emb_trigger_get(void)
{
    return REG_PL_RD(IPC_G1_APP2EMB_TRIGGER_ADDR);
}

__INLINE void ipc_g1_app2emb_trigger_set(uint32_t value)
{
    REG_PL_WR(IPC_G1_APP2EMB_TRIGGER_ADDR, value);
}

// field definitions
#define IPC_G1_APP2EMB_TRIGGER_MASK   ((uint32_t)0xFFFFFFFF)
#define IPC_G1_APP2EMB_TRIGGER_LSB    0
#define IPC_G1_APP2EMB_TRIGGER_WIDTH  ((uint32_t)0x00000020)

#define IPC_G1_APP2EMB_TRIGGER_RST    0x0

__INLINE uint32_t ipc_g1_app2emb_trigger_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_APP2EMB_TRIGGER_ADDR);
    return (localVal >> 0);
}

__INLINE void ipc_g1_app2emb_trigger_setf(uint32_t g1app2embtrigger)
{
    REG_PL_WR(IPC_G1_APP2EMB_TRIGGER_ADDR, (uint32_t)g1app2embtrigger << 0);
}

/**
 * @brief G1_EMB2APP_RAWSTATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:00   G1_EMB2APP_RAWSTATUS   0x0
 * </pre>
 */
#define IPC_G1_EMB2APP_RAWSTATUS_ADDR   0x40044204
#define IPC_G1_EMB2APP_RAWSTATUS_OFFSET 0x00000004
#define IPC_G1_EMB2APP_RAWSTATUS_INDEX  0x00000001
#define IPC_G1_EMB2APP_RAWSTATUS_RESET  0x00000000

__INLINE uint32_t ipc_g1_emb2app_rawstatus_get(void)
{
    return REG_PL_RD(IPC_G1_EMB2APP_RAWSTATUS_ADDR);
}

// field definitions
#define IPC_G1_EMB2APP_RAWSTATUS_MASK   ((uint32_t)0xFFFFFFFF)
#define IPC_G1_EMB2APP_RAWSTATUS_LSB    0
#define IPC_G1_EMB2APP_RAWSTATUS_WIDTH  ((uint32_t)0x00000020)

#define IPC_G1_EMB2APP_RAWSTATUS_RST    0x0

__INLINE uint32_t ipc_g1_emb2app_rawstatus_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_EMB2APP_RAWSTATUS_ADDR);
    return (localVal >> 0);
}

/**
 * @brief G1_EMB2APP_ACK register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:00       G1_EMB2APP_ACK   0x0
 * </pre>
 */
#define IPC_G1_EMB2APP_ACK_ADDR   0x40044208
#define IPC_G1_EMB2APP_ACK_OFFSET 0x00000008
#define IPC_G1_EMB2APP_ACK_INDEX  0x00000002
#define IPC_G1_EMB2APP_ACK_RESET  0x00000000

__INLINE uint32_t ipc_g1_emb2app_ack_get(void)
{
    return REG_PL_RD(IPC_G1_EMB2APP_ACK_ADDR);
}

__INLINE void ipc_g1_emb2app_ack_clear(uint32_t value)
{
    REG_PL_WR(IPC_G1_EMB2APP_ACK_ADDR, value);
}

// field definitions
#define IPC_G1_EMB2APP_ACK_MASK   ((uint32_t)0xFFFFFFFF)
#define IPC_G1_EMB2APP_ACK_LSB    0
#define IPC_G1_EMB2APP_ACK_WIDTH  ((uint32_t)0x00000020)

#define IPC_G1_EMB2APP_ACK_RST    0x0

__INLINE uint32_t ipc_g1_emb2app_ack_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_EMB2APP_ACK_ADDR);
    return (localVal >> 0);
}

__INLINE void ipc_g1_emb2app_ack_clearf(uint32_t g1emb2appack)
{
    REG_PL_WR(IPC_G1_EMB2APP_ACK_ADDR, (uint32_t)g1emb2appack << 0);
}

/**
 * @brief G1_EMB2APP_UNMASK_SET register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:00    G1_EMB2APP_UNMASK   0x0
 * </pre>
 */
#define IPC_G1_EMB2APP_UNMASK_SET_ADDR   0x4004420C
#define IPC_G1_EMB2APP_UNMASK_SET_OFFSET 0x0000000C
#define IPC_G1_EMB2APP_UNMASK_SET_INDEX  0x00000003
#define IPC_G1_EMB2APP_UNMASK_SET_RESET  0x00000000

__INLINE uint32_t ipc_g1_emb2app_unmask_get(void)
{
    return REG_PL_RD(IPC_G1_EMB2APP_UNMASK_SET_ADDR);
}

__INLINE void ipc_g1_emb2app_unmask_set(uint32_t value)
{
    REG_PL_WR(IPC_G1_EMB2APP_UNMASK_SET_ADDR, value);
}

// field definitions
#define IPC_G1_EMB2APP_UNMASK_MASK   ((uint32_t)0xFFFFFFFF)
#define IPC_G1_EMB2APP_UNMASK_LSB    0
#define IPC_G1_EMB2APP_UNMASK_WIDTH  ((uint32_t)0x00000020)

#define IPC_G1_EMB2APP_UNMASK_RST    0x0

__INLINE uint32_t ipc_g1_emb2app_unmask_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_EMB2APP_UNMASK_SET_ADDR);
    return (localVal >> 0);
}

__INLINE void ipc_g1_emb2app_unmask_setf(uint32_t g1emb2appunmask)
{
    REG_PL_WR(IPC_G1_EMB2APP_UNMASK_SET_ADDR, (uint32_t)g1emb2appunmask << 0);
}

/**
 * @brief G1_EMB2APP_UNMASK_CLEAR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:00    G1_EMB2APP_UNMASK   0x0
 * </pre>
 */
#define IPC_G1_EMB2APP_UNMASK_CLEAR_ADDR   0x40044210
#define IPC_G1_EMB2APP_UNMASK_CLEAR_OFFSET 0x00000010
#define IPC_G1_EMB2APP_UNMASK_CLEAR_INDEX  0x00000004
#define IPC_G1_EMB2APP_UNMASK_CLEAR_RESET  0x00000000

__INLINE void ipc_g1_emb2app_unmask_clear(uint32_t value)
{
    REG_PL_WR(IPC_G1_EMB2APP_UNMASK_CLEAR_ADDR, value);
}

// fields defined in symmetrical set/clear register
__INLINE void ipc_g1_emb2app_unmask_clearf(uint32_t g1emb2appunmask)
{
    REG_PL_WR(IPC_G1_EMB2APP_UNMASK_CLEAR_ADDR, (uint32_t)g1emb2appunmask << 0);
}

/**
 * @brief G1_EMB2APP_LINE_SEL_LOW register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:30     G1_EMB2APP15_SEL   0x0
 *  29:28     G1_EMB2APP14_SEL   0x0
 *  27:26     G1_EMB2APP13_SEL   0x0
 *  25:24     G1_EMB2APP12_SEL   0x0
 *  23:22     G1_EMB2APP11_SEL   0x0
 *  21:20     G1_EMB2APP10_SEL   0x0
 *  19:18      G1_EMB2APP9_SEL   0x0
 *  17:16      G1_EMB2APP8_SEL   0x0
 *  15:14      G1_EMB2APP7_SEL   0x0
 *  13:12      G1_EMB2APP6_SEL   0x0
 *  11:10      G1_EMB2APP5_SEL   0x0
 *  09:08      G1_EMB2APP4_SEL   0x0
 *  07:06      G1_EMB2APP3_SEL   0x0
 *  05:04      G1_EMB2APP2_SEL   0x0
 *  03:02      G1_EMB2APP1_SEL   0x0
 *  01:00      G1_EMB2APP0_SEL   0x0
 * </pre>
 */
#define IPC_G1_EMB2APP_LINE_SEL_LOW_ADDR   0x40044214
#define IPC_G1_EMB2APP_LINE_SEL_LOW_OFFSET 0x00000014
#define IPC_G1_EMB2APP_LINE_SEL_LOW_INDEX  0x00000005
#define IPC_G1_EMB2APP_LINE_SEL_LOW_RESET  0x00000000

__INLINE uint32_t ipc_g1_emb2app_line_sel_low_get(void)
{
    return REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_LOW_ADDR);
}

__INLINE void ipc_g1_emb2app_line_sel_low_set(uint32_t value)
{
    REG_PL_WR(IPC_G1_EMB2APP_LINE_SEL_LOW_ADDR, value);
}

// field definitions
#define IPC_G1_EMB2APP15_SEL_MASK   ((uint32_t)0xC0000000)
#define IPC_G1_EMB2APP15_SEL_LSB    30
#define IPC_G1_EMB2APP15_SEL_WIDTH  ((uint32_t)0x00000002)
#define IPC_G1_EMB2APP14_SEL_MASK   ((uint32_t)0x30000000)
#define IPC_G1_EMB2APP14_SEL_LSB    28
#define IPC_G1_EMB2APP14_SEL_WIDTH  ((uint32_t)0x00000002)
#define IPC_G1_EMB2APP13_SEL_MASK   ((uint32_t)0x0C000000)
#define IPC_G1_EMB2APP13_SEL_LSB    26
#define IPC_G1_EMB2APP13_SEL_WIDTH  ((uint32_t)0x00000002)
#define IPC_G1_EMB2APP12_SEL_MASK   ((uint32_t)0x03000000)
#define IPC_G1_EMB2APP12_SEL_LSB    24
#define IPC_G1_EMB2APP12_SEL_WIDTH  ((uint32_t)0x00000002)
#define IPC_G1_EMB2APP11_SEL_MASK   ((uint32_t)0x00C00000)
#define IPC_G1_EMB2APP11_SEL_LSB    22
#define IPC_G1_EMB2APP11_SEL_WIDTH  ((uint32_t)0x00000002)
#define IPC_G1_EMB2APP10_SEL_MASK   ((uint32_t)0x00300000)
#define IPC_G1_EMB2APP10_SEL_LSB    20
#define IPC_G1_EMB2APP10_SEL_WIDTH  ((uint32_t)0x00000002)
#define IPC_G1_EMB2APP9_SEL_MASK    ((uint32_t)0x000C0000)
#define IPC_G1_EMB2APP9_SEL_LSB     18
#define IPC_G1_EMB2APP9_SEL_WIDTH   ((uint32_t)0x00000002)
#define IPC_G1_EMB2APP8_SEL_MASK    ((uint32_t)0x00030000)
#define IPC_G1_EMB2APP8_SEL_LSB     16
#define IPC_G1_EMB2APP8_SEL_WIDTH   ((uint32_t)0x00000002)
#define IPC_G1_EMB2APP7_SEL_MASK    ((uint32_t)0x0000C000)
#define IPC_G1_EMB2APP7_SEL_LSB     14
#define IPC_G1_EMB2APP7_SEL_WIDTH   ((uint32_t)0x00000002)
#define IPC_G1_EMB2APP6_SEL_MASK    ((uint32_t)0x00003000)
#define IPC_G1_EMB2APP6_SEL_LSB     12
#define IPC_G1_EMB2APP6_SEL_WIDTH   ((uint32_t)0x00000002)
#define IPC_G1_EMB2APP5_SEL_MASK    ((uint32_t)0x00000C00)
#define IPC_G1_EMB2APP5_SEL_LSB     10
#define IPC_G1_EMB2APP5_SEL_WIDTH   ((uint32_t)0x00000002)
#define IPC_G1_EMB2APP4_SEL_MASK    ((uint32_t)0x00000300)
#define IPC_G1_EMB2APP4_SEL_LSB     8
#define IPC_G1_EMB2APP4_SEL_WIDTH   ((uint32_t)0x00000002)
#define IPC_G1_EMB2APP3_SEL_MASK    ((uint32_t)0x000000C0)
#define IPC_G1_EMB2APP3_SEL_LSB     6
#define IPC_G1_EMB2APP3_SEL_WIDTH   ((uint32_t)0x00000002)
#define IPC_G1_EMB2APP2_SEL_MASK    ((uint32_t)0x00000030)
#define IPC_G1_EMB2APP2_SEL_LSB     4
#define IPC_G1_EMB2APP2_SEL_WIDTH   ((uint32_t)0x00000002)
#define IPC_G1_EMB2APP1_SEL_MASK    ((uint32_t)0x0000000C)
#define IPC_G1_EMB2APP1_SEL_LSB     2
#define IPC_G1_EMB2APP1_SEL_WIDTH   ((uint32_t)0x00000002)
#define IPC_G1_EMB2APP0_SEL_MASK    ((uint32_t)0x00000003)
#define IPC_G1_EMB2APP0_SEL_LSB     0
#define IPC_G1_EMB2APP0_SEL_WIDTH   ((uint32_t)0x00000002)

#define IPC_G1_EMB2APP15_SEL_RST    0x0
#define IPC_G1_EMB2APP14_SEL_RST    0x0
#define IPC_G1_EMB2APP13_SEL_RST    0x0
#define IPC_G1_EMB2APP12_SEL_RST    0x0
#define IPC_G1_EMB2APP11_SEL_RST    0x0
#define IPC_G1_EMB2APP10_SEL_RST    0x0
#define IPC_G1_EMB2APP9_SEL_RST     0x0
#define IPC_G1_EMB2APP8_SEL_RST     0x0
#define IPC_G1_EMB2APP7_SEL_RST     0x0
#define IPC_G1_EMB2APP6_SEL_RST     0x0
#define IPC_G1_EMB2APP5_SEL_RST     0x0
#define IPC_G1_EMB2APP4_SEL_RST     0x0
#define IPC_G1_EMB2APP3_SEL_RST     0x0
#define IPC_G1_EMB2APP2_SEL_RST     0x0
#define IPC_G1_EMB2APP1_SEL_RST     0x0
#define IPC_G1_EMB2APP0_SEL_RST     0x0

__INLINE void ipc_g1_emb2app_line_sel_low_pack(uint8_t g1emb2app15sel, uint8_t g1emb2app14sel, uint8_t g1emb2app13sel, uint8_t g1emb2app12sel, uint8_t g1emb2app11sel, uint8_t g1emb2app10sel, uint8_t g1emb2app9sel, uint8_t g1emb2app8sel, uint8_t g1emb2app7sel, uint8_t g1emb2app6sel, uint8_t g1emb2app5sel, uint8_t g1emb2app4sel, uint8_t g1emb2app3sel, uint8_t g1emb2app2sel, uint8_t g1emb2app1sel, uint8_t g1emb2app0sel)
{
    REG_PL_WR(IPC_G1_EMB2APP_LINE_SEL_LOW_ADDR,  ((uint32_t)g1emb2app15sel << 30) | ((uint32_t)g1emb2app14sel << 28) | ((uint32_t)g1emb2app13sel << 26) | ((uint32_t)g1emb2app12sel << 24) | ((uint32_t)g1emb2app11sel << 22) | ((uint32_t)g1emb2app10sel << 20) | ((uint32_t)g1emb2app9sel << 18) | ((uint32_t)g1emb2app8sel << 16) | ((uint32_t)g1emb2app7sel << 14) | ((uint32_t)g1emb2app6sel << 12) | ((uint32_t)g1emb2app5sel << 10) | ((uint32_t)g1emb2app4sel << 8) | ((uint32_t)g1emb2app3sel << 6) | ((uint32_t)g1emb2app2sel << 4) | ((uint32_t)g1emb2app1sel << 2) | ((uint32_t)g1emb2app0sel << 0));
}

__INLINE void ipc_g1_emb2app_line_sel_low_unpack(uint8_t* g1emb2app15sel, uint8_t* g1emb2app14sel, uint8_t* g1emb2app13sel, uint8_t* g1emb2app12sel, uint8_t* g1emb2app11sel, uint8_t* g1emb2app10sel, uint8_t* g1emb2app9sel, uint8_t* g1emb2app8sel, uint8_t* g1emb2app7sel, uint8_t* g1emb2app6sel, uint8_t* g1emb2app5sel, uint8_t* g1emb2app4sel, uint8_t* g1emb2app3sel, uint8_t* g1emb2app2sel, uint8_t* g1emb2app1sel, uint8_t* g1emb2app0sel)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_LOW_ADDR);

    *g1emb2app15sel = (localVal & ((uint32_t)0xC0000000)) >> 30;
    *g1emb2app14sel = (localVal & ((uint32_t)0x30000000)) >> 28;
    *g1emb2app13sel = (localVal & ((uint32_t)0x0C000000)) >> 26;
    *g1emb2app12sel = (localVal & ((uint32_t)0x03000000)) >> 24;
    *g1emb2app11sel = (localVal & ((uint32_t)0x00C00000)) >> 22;
    *g1emb2app10sel = (localVal & ((uint32_t)0x00300000)) >> 20;
    *g1emb2app9sel = (localVal & ((uint32_t)0x000C0000)) >> 18;
    *g1emb2app8sel = (localVal & ((uint32_t)0x00030000)) >> 16;
    *g1emb2app7sel = (localVal & ((uint32_t)0x0000C000)) >> 14;
    *g1emb2app6sel = (localVal & ((uint32_t)0x00003000)) >> 12;
    *g1emb2app5sel = (localVal & ((uint32_t)0x00000C00)) >> 10;
    *g1emb2app4sel = (localVal & ((uint32_t)0x00000300)) >> 8;
    *g1emb2app3sel = (localVal & ((uint32_t)0x000000C0)) >> 6;
    *g1emb2app2sel = (localVal & ((uint32_t)0x00000030)) >> 4;
    *g1emb2app1sel = (localVal & ((uint32_t)0x0000000C)) >> 2;
    *g1emb2app0sel = (localVal & ((uint32_t)0x00000003)) >> 0;
}

__INLINE uint8_t ipc_g1_emb2app15_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_LOW_ADDR);
    return ((localVal & ((uint32_t)0xC0000000)) >> 30);
}

__INLINE void ipc_g1_emb2app15_sel_setf(uint8_t g1emb2app15sel)
{
    REG_PL_WR(IPC_G1_EMB2APP_LINE_SEL_LOW_ADDR, (REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_LOW_ADDR) & ~((uint32_t)0xC0000000)) | ((uint32_t)g1emb2app15sel << 30));
}

__INLINE uint8_t ipc_g1_emb2app14_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_LOW_ADDR);
    return ((localVal & ((uint32_t)0x30000000)) >> 28);
}

__INLINE void ipc_g1_emb2app14_sel_setf(uint8_t g1emb2app14sel)
{
    REG_PL_WR(IPC_G1_EMB2APP_LINE_SEL_LOW_ADDR, (REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_LOW_ADDR) & ~((uint32_t)0x30000000)) | ((uint32_t)g1emb2app14sel << 28));
}

__INLINE uint8_t ipc_g1_emb2app13_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_LOW_ADDR);
    return ((localVal & ((uint32_t)0x0C000000)) >> 26);
}

__INLINE void ipc_g1_emb2app13_sel_setf(uint8_t g1emb2app13sel)
{
    REG_PL_WR(IPC_G1_EMB2APP_LINE_SEL_LOW_ADDR, (REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_LOW_ADDR) & ~((uint32_t)0x0C000000)) | ((uint32_t)g1emb2app13sel << 26));
}

__INLINE uint8_t ipc_g1_emb2app12_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_LOW_ADDR);
    return ((localVal & ((uint32_t)0x03000000)) >> 24);
}

__INLINE void ipc_g1_emb2app12_sel_setf(uint8_t g1emb2app12sel)
{
    REG_PL_WR(IPC_G1_EMB2APP_LINE_SEL_LOW_ADDR, (REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_LOW_ADDR) & ~((uint32_t)0x03000000)) | ((uint32_t)g1emb2app12sel << 24));
}

__INLINE uint8_t ipc_g1_emb2app11_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_LOW_ADDR);
    return ((localVal & ((uint32_t)0x00C00000)) >> 22);
}

__INLINE void ipc_g1_emb2app11_sel_setf(uint8_t g1emb2app11sel)
{
    REG_PL_WR(IPC_G1_EMB2APP_LINE_SEL_LOW_ADDR, (REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_LOW_ADDR) & ~((uint32_t)0x00C00000)) | ((uint32_t)g1emb2app11sel << 22));
}

__INLINE uint8_t ipc_g1_emb2app10_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_LOW_ADDR);
    return ((localVal & ((uint32_t)0x00300000)) >> 20);
}

__INLINE void ipc_g1_emb2app10_sel_setf(uint8_t g1emb2app10sel)
{
    REG_PL_WR(IPC_G1_EMB2APP_LINE_SEL_LOW_ADDR, (REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_LOW_ADDR) & ~((uint32_t)0x00300000)) | ((uint32_t)g1emb2app10sel << 20));
}

__INLINE uint8_t ipc_g1_emb2app9_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_LOW_ADDR);
    return ((localVal & ((uint32_t)0x000C0000)) >> 18);
}

__INLINE void ipc_g1_emb2app9_sel_setf(uint8_t g1emb2app9sel)
{
    REG_PL_WR(IPC_G1_EMB2APP_LINE_SEL_LOW_ADDR, (REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_LOW_ADDR) & ~((uint32_t)0x000C0000)) | ((uint32_t)g1emb2app9sel << 18));
}

__INLINE uint8_t ipc_g1_emb2app8_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_LOW_ADDR);
    return ((localVal & ((uint32_t)0x00030000)) >> 16);
}

__INLINE void ipc_g1_emb2app8_sel_setf(uint8_t g1emb2app8sel)
{
    REG_PL_WR(IPC_G1_EMB2APP_LINE_SEL_LOW_ADDR, (REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_LOW_ADDR) & ~((uint32_t)0x00030000)) | ((uint32_t)g1emb2app8sel << 16));
}

__INLINE uint8_t ipc_g1_emb2app7_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_LOW_ADDR);
    return ((localVal & ((uint32_t)0x0000C000)) >> 14);
}

__INLINE void ipc_g1_emb2app7_sel_setf(uint8_t g1emb2app7sel)
{
    REG_PL_WR(IPC_G1_EMB2APP_LINE_SEL_LOW_ADDR, (REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_LOW_ADDR) & ~((uint32_t)0x0000C000)) | ((uint32_t)g1emb2app7sel << 14));
}

__INLINE uint8_t ipc_g1_emb2app6_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_LOW_ADDR);
    return ((localVal & ((uint32_t)0x00003000)) >> 12);
}

__INLINE void ipc_g1_emb2app6_sel_setf(uint8_t g1emb2app6sel)
{
    REG_PL_WR(IPC_G1_EMB2APP_LINE_SEL_LOW_ADDR, (REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_LOW_ADDR) & ~((uint32_t)0x00003000)) | ((uint32_t)g1emb2app6sel << 12));
}

__INLINE uint8_t ipc_g1_emb2app5_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_LOW_ADDR);
    return ((localVal & ((uint32_t)0x00000C00)) >> 10);
}

__INLINE void ipc_g1_emb2app5_sel_setf(uint8_t g1emb2app5sel)
{
    REG_PL_WR(IPC_G1_EMB2APP_LINE_SEL_LOW_ADDR, (REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_LOW_ADDR) & ~((uint32_t)0x00000C00)) | ((uint32_t)g1emb2app5sel << 10));
}

__INLINE uint8_t ipc_g1_emb2app4_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_LOW_ADDR);
    return ((localVal & ((uint32_t)0x00000300)) >> 8);
}

__INLINE void ipc_g1_emb2app4_sel_setf(uint8_t g1emb2app4sel)
{
    REG_PL_WR(IPC_G1_EMB2APP_LINE_SEL_LOW_ADDR, (REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_LOW_ADDR) & ~((uint32_t)0x00000300)) | ((uint32_t)g1emb2app4sel << 8));
}

__INLINE uint8_t ipc_g1_emb2app3_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_LOW_ADDR);
    return ((localVal & ((uint32_t)0x000000C0)) >> 6);
}

__INLINE void ipc_g1_emb2app3_sel_setf(uint8_t g1emb2app3sel)
{
    REG_PL_WR(IPC_G1_EMB2APP_LINE_SEL_LOW_ADDR, (REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_LOW_ADDR) & ~((uint32_t)0x000000C0)) | ((uint32_t)g1emb2app3sel << 6));
}

__INLINE uint8_t ipc_g1_emb2app2_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_LOW_ADDR);
    return ((localVal & ((uint32_t)0x00000030)) >> 4);
}

__INLINE void ipc_g1_emb2app2_sel_setf(uint8_t g1emb2app2sel)
{
    REG_PL_WR(IPC_G1_EMB2APP_LINE_SEL_LOW_ADDR, (REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_LOW_ADDR) & ~((uint32_t)0x00000030)) | ((uint32_t)g1emb2app2sel << 4));
}

__INLINE uint8_t ipc_g1_emb2app1_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_LOW_ADDR);
    return ((localVal & ((uint32_t)0x0000000C)) >> 2);
}

__INLINE void ipc_g1_emb2app1_sel_setf(uint8_t g1emb2app1sel)
{
    REG_PL_WR(IPC_G1_EMB2APP_LINE_SEL_LOW_ADDR, (REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_LOW_ADDR) & ~((uint32_t)0x0000000C)) | ((uint32_t)g1emb2app1sel << 2));
}

__INLINE uint8_t ipc_g1_emb2app0_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_LOW_ADDR);
    return ((localVal & ((uint32_t)0x00000003)) >> 0);
}

__INLINE void ipc_g1_emb2app0_sel_setf(uint8_t g1emb2app0sel)
{
    REG_PL_WR(IPC_G1_EMB2APP_LINE_SEL_LOW_ADDR, (REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_LOW_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)g1emb2app0sel << 0));
}

/**
 * @brief G1_EMB2APP_LINE_SEL_HIGH register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:30     G1_EMB2APP31_SEL   0x0
 *  29:28     G1_EMB2APP30_SEL   0x0
 *  27:26     G1_EMB2APP29_SEL   0x0
 *  25:24     G1_EMB2APP28_SEL   0x0
 *  23:22     G1_EMB2APP27_SEL   0x0
 *  21:20     G1_EMB2APP26_SEL   0x0
 *  19:18     G1_EMB2APP25_SEL   0x0
 *  17:16     G1_EMB2APP24_SEL   0x0
 *  15:14     G1_EMB2APP23_SEL   0x0
 *  13:12     G1_EMB2APP22_SEL   0x0
 *  11:10     G1_EMB2APP21_SEL   0x0
 *  09:08     G1_EMB2APP20_SEL   0x0
 *  07:06     G1_EMB2APP19_SEL   0x0
 *  05:04     G1_EMB2APP18_SEL   0x0
 *  03:02     G1_EMB2APP17_SEL   0x0
 *  01:00     G1_EMB2APP16_SEL   0x0
 * </pre>
 */
#define IPC_G1_EMB2APP_LINE_SEL_HIGH_ADDR   0x40044218
#define IPC_G1_EMB2APP_LINE_SEL_HIGH_OFFSET 0x00000018
#define IPC_G1_EMB2APP_LINE_SEL_HIGH_INDEX  0x00000006
#define IPC_G1_EMB2APP_LINE_SEL_HIGH_RESET  0x00000000

__INLINE uint32_t ipc_g1_emb2app_line_sel_high_get(void)
{
    return REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_HIGH_ADDR);
}

__INLINE void ipc_g1_emb2app_line_sel_high_set(uint32_t value)
{
    REG_PL_WR(IPC_G1_EMB2APP_LINE_SEL_HIGH_ADDR, value);
}

// field definitions
#define IPC_G1_EMB2APP31_SEL_MASK   ((uint32_t)0xC0000000)
#define IPC_G1_EMB2APP31_SEL_LSB    30
#define IPC_G1_EMB2APP31_SEL_WIDTH  ((uint32_t)0x00000002)
#define IPC_G1_EMB2APP30_SEL_MASK   ((uint32_t)0x30000000)
#define IPC_G1_EMB2APP30_SEL_LSB    28
#define IPC_G1_EMB2APP30_SEL_WIDTH  ((uint32_t)0x00000002)
#define IPC_G1_EMB2APP29_SEL_MASK   ((uint32_t)0x0C000000)
#define IPC_G1_EMB2APP29_SEL_LSB    26
#define IPC_G1_EMB2APP29_SEL_WIDTH  ((uint32_t)0x00000002)
#define IPC_G1_EMB2APP28_SEL_MASK   ((uint32_t)0x03000000)
#define IPC_G1_EMB2APP28_SEL_LSB    24
#define IPC_G1_EMB2APP28_SEL_WIDTH  ((uint32_t)0x00000002)
#define IPC_G1_EMB2APP27_SEL_MASK   ((uint32_t)0x00C00000)
#define IPC_G1_EMB2APP27_SEL_LSB    22
#define IPC_G1_EMB2APP27_SEL_WIDTH  ((uint32_t)0x00000002)
#define IPC_G1_EMB2APP26_SEL_MASK   ((uint32_t)0x00300000)
#define IPC_G1_EMB2APP26_SEL_LSB    20
#define IPC_G1_EMB2APP26_SEL_WIDTH  ((uint32_t)0x00000002)
#define IPC_G1_EMB2APP25_SEL_MASK   ((uint32_t)0x000C0000)
#define IPC_G1_EMB2APP25_SEL_LSB    18
#define IPC_G1_EMB2APP25_SEL_WIDTH  ((uint32_t)0x00000002)
#define IPC_G1_EMB2APP24_SEL_MASK   ((uint32_t)0x00030000)
#define IPC_G1_EMB2APP24_SEL_LSB    16
#define IPC_G1_EMB2APP24_SEL_WIDTH  ((uint32_t)0x00000002)
#define IPC_G1_EMB2APP23_SEL_MASK   ((uint32_t)0x0000C000)
#define IPC_G1_EMB2APP23_SEL_LSB    14
#define IPC_G1_EMB2APP23_SEL_WIDTH  ((uint32_t)0x00000002)
#define IPC_G1_EMB2APP22_SEL_MASK   ((uint32_t)0x00003000)
#define IPC_G1_EMB2APP22_SEL_LSB    12
#define IPC_G1_EMB2APP22_SEL_WIDTH  ((uint32_t)0x00000002)
#define IPC_G1_EMB2APP21_SEL_MASK   ((uint32_t)0x00000C00)
#define IPC_G1_EMB2APP21_SEL_LSB    10
#define IPC_G1_EMB2APP21_SEL_WIDTH  ((uint32_t)0x00000002)
#define IPC_G1_EMB2APP20_SEL_MASK   ((uint32_t)0x00000300)
#define IPC_G1_EMB2APP20_SEL_LSB    8
#define IPC_G1_EMB2APP20_SEL_WIDTH  ((uint32_t)0x00000002)
#define IPC_G1_EMB2APP19_SEL_MASK   ((uint32_t)0x000000C0)
#define IPC_G1_EMB2APP19_SEL_LSB    6
#define IPC_G1_EMB2APP19_SEL_WIDTH  ((uint32_t)0x00000002)
#define IPC_G1_EMB2APP18_SEL_MASK   ((uint32_t)0x00000030)
#define IPC_G1_EMB2APP18_SEL_LSB    4
#define IPC_G1_EMB2APP18_SEL_WIDTH  ((uint32_t)0x00000002)
#define IPC_G1_EMB2APP17_SEL_MASK   ((uint32_t)0x0000000C)
#define IPC_G1_EMB2APP17_SEL_LSB    2
#define IPC_G1_EMB2APP17_SEL_WIDTH  ((uint32_t)0x00000002)
#define IPC_G1_EMB2APP16_SEL_MASK   ((uint32_t)0x00000003)
#define IPC_G1_EMB2APP16_SEL_LSB    0
#define IPC_G1_EMB2APP16_SEL_WIDTH  ((uint32_t)0x00000002)

#define IPC_G1_EMB2APP31_SEL_RST    0x0
#define IPC_G1_EMB2APP30_SEL_RST    0x0
#define IPC_G1_EMB2APP29_SEL_RST    0x0
#define IPC_G1_EMB2APP28_SEL_RST    0x0
#define IPC_G1_EMB2APP27_SEL_RST    0x0
#define IPC_G1_EMB2APP26_SEL_RST    0x0
#define IPC_G1_EMB2APP25_SEL_RST    0x0
#define IPC_G1_EMB2APP24_SEL_RST    0x0
#define IPC_G1_EMB2APP23_SEL_RST    0x0
#define IPC_G1_EMB2APP22_SEL_RST    0x0
#define IPC_G1_EMB2APP21_SEL_RST    0x0
#define IPC_G1_EMB2APP20_SEL_RST    0x0
#define IPC_G1_EMB2APP19_SEL_RST    0x0
#define IPC_G1_EMB2APP18_SEL_RST    0x0
#define IPC_G1_EMB2APP17_SEL_RST    0x0
#define IPC_G1_EMB2APP16_SEL_RST    0x0

__INLINE void ipc_g1_emb2app_line_sel_high_pack(uint8_t g1emb2app31sel, uint8_t g1emb2app30sel, uint8_t g1emb2app29sel, uint8_t g1emb2app28sel, uint8_t g1emb2app27sel, uint8_t g1emb2app26sel, uint8_t g1emb2app25sel, uint8_t g1emb2app24sel, uint8_t g1emb2app23sel, uint8_t g1emb2app22sel, uint8_t g1emb2app21sel, uint8_t g1emb2app20sel, uint8_t g1emb2app19sel, uint8_t g1emb2app18sel, uint8_t g1emb2app17sel, uint8_t g1emb2app16sel)
{
    REG_PL_WR(IPC_G1_EMB2APP_LINE_SEL_HIGH_ADDR,  ((uint32_t)g1emb2app31sel << 30) | ((uint32_t)g1emb2app30sel << 28) | ((uint32_t)g1emb2app29sel << 26) | ((uint32_t)g1emb2app28sel << 24) | ((uint32_t)g1emb2app27sel << 22) | ((uint32_t)g1emb2app26sel << 20) | ((uint32_t)g1emb2app25sel << 18) | ((uint32_t)g1emb2app24sel << 16) | ((uint32_t)g1emb2app23sel << 14) | ((uint32_t)g1emb2app22sel << 12) | ((uint32_t)g1emb2app21sel << 10) | ((uint32_t)g1emb2app20sel << 8) | ((uint32_t)g1emb2app19sel << 6) | ((uint32_t)g1emb2app18sel << 4) | ((uint32_t)g1emb2app17sel << 2) | ((uint32_t)g1emb2app16sel << 0));
}

__INLINE void ipc_g1_emb2app_line_sel_high_unpack(uint8_t* g1emb2app31sel, uint8_t* g1emb2app30sel, uint8_t* g1emb2app29sel, uint8_t* g1emb2app28sel, uint8_t* g1emb2app27sel, uint8_t* g1emb2app26sel, uint8_t* g1emb2app25sel, uint8_t* g1emb2app24sel, uint8_t* g1emb2app23sel, uint8_t* g1emb2app22sel, uint8_t* g1emb2app21sel, uint8_t* g1emb2app20sel, uint8_t* g1emb2app19sel, uint8_t* g1emb2app18sel, uint8_t* g1emb2app17sel, uint8_t* g1emb2app16sel)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_HIGH_ADDR);

    *g1emb2app31sel = (localVal & ((uint32_t)0xC0000000)) >> 30;
    *g1emb2app30sel = (localVal & ((uint32_t)0x30000000)) >> 28;
    *g1emb2app29sel = (localVal & ((uint32_t)0x0C000000)) >> 26;
    *g1emb2app28sel = (localVal & ((uint32_t)0x03000000)) >> 24;
    *g1emb2app27sel = (localVal & ((uint32_t)0x00C00000)) >> 22;
    *g1emb2app26sel = (localVal & ((uint32_t)0x00300000)) >> 20;
    *g1emb2app25sel = (localVal & ((uint32_t)0x000C0000)) >> 18;
    *g1emb2app24sel = (localVal & ((uint32_t)0x00030000)) >> 16;
    *g1emb2app23sel = (localVal & ((uint32_t)0x0000C000)) >> 14;
    *g1emb2app22sel = (localVal & ((uint32_t)0x00003000)) >> 12;
    *g1emb2app21sel = (localVal & ((uint32_t)0x00000C00)) >> 10;
    *g1emb2app20sel = (localVal & ((uint32_t)0x00000300)) >> 8;
    *g1emb2app19sel = (localVal & ((uint32_t)0x000000C0)) >> 6;
    *g1emb2app18sel = (localVal & ((uint32_t)0x00000030)) >> 4;
    *g1emb2app17sel = (localVal & ((uint32_t)0x0000000C)) >> 2;
    *g1emb2app16sel = (localVal & ((uint32_t)0x00000003)) >> 0;
}

__INLINE uint8_t ipc_g1_emb2app31_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_HIGH_ADDR);
    return ((localVal & ((uint32_t)0xC0000000)) >> 30);
}

__INLINE void ipc_g1_emb2app31_sel_setf(uint8_t g1emb2app31sel)
{
    REG_PL_WR(IPC_G1_EMB2APP_LINE_SEL_HIGH_ADDR, (REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_HIGH_ADDR) & ~((uint32_t)0xC0000000)) | ((uint32_t)g1emb2app31sel << 30));
}

__INLINE uint8_t ipc_g1_emb2app30_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_HIGH_ADDR);
    return ((localVal & ((uint32_t)0x30000000)) >> 28);
}

__INLINE void ipc_g1_emb2app30_sel_setf(uint8_t g1emb2app30sel)
{
    REG_PL_WR(IPC_G1_EMB2APP_LINE_SEL_HIGH_ADDR, (REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_HIGH_ADDR) & ~((uint32_t)0x30000000)) | ((uint32_t)g1emb2app30sel << 28));
}

__INLINE uint8_t ipc_g1_emb2app29_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_HIGH_ADDR);
    return ((localVal & ((uint32_t)0x0C000000)) >> 26);
}

__INLINE void ipc_g1_emb2app29_sel_setf(uint8_t g1emb2app29sel)
{
    REG_PL_WR(IPC_G1_EMB2APP_LINE_SEL_HIGH_ADDR, (REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_HIGH_ADDR) & ~((uint32_t)0x0C000000)) | ((uint32_t)g1emb2app29sel << 26));
}

__INLINE uint8_t ipc_g1_emb2app28_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_HIGH_ADDR);
    return ((localVal & ((uint32_t)0x03000000)) >> 24);
}

__INLINE void ipc_g1_emb2app28_sel_setf(uint8_t g1emb2app28sel)
{
    REG_PL_WR(IPC_G1_EMB2APP_LINE_SEL_HIGH_ADDR, (REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_HIGH_ADDR) & ~((uint32_t)0x03000000)) | ((uint32_t)g1emb2app28sel << 24));
}

__INLINE uint8_t ipc_g1_emb2app27_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_HIGH_ADDR);
    return ((localVal & ((uint32_t)0x00C00000)) >> 22);
}

__INLINE void ipc_g1_emb2app27_sel_setf(uint8_t g1emb2app27sel)
{
    REG_PL_WR(IPC_G1_EMB2APP_LINE_SEL_HIGH_ADDR, (REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_HIGH_ADDR) & ~((uint32_t)0x00C00000)) | ((uint32_t)g1emb2app27sel << 22));
}

__INLINE uint8_t ipc_g1_emb2app26_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_HIGH_ADDR);
    return ((localVal & ((uint32_t)0x00300000)) >> 20);
}

__INLINE void ipc_g1_emb2app26_sel_setf(uint8_t g1emb2app26sel)
{
    REG_PL_WR(IPC_G1_EMB2APP_LINE_SEL_HIGH_ADDR, (REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_HIGH_ADDR) & ~((uint32_t)0x00300000)) | ((uint32_t)g1emb2app26sel << 20));
}

__INLINE uint8_t ipc_g1_emb2app25_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_HIGH_ADDR);
    return ((localVal & ((uint32_t)0x000C0000)) >> 18);
}

__INLINE void ipc_g1_emb2app25_sel_setf(uint8_t g1emb2app25sel)
{
    REG_PL_WR(IPC_G1_EMB2APP_LINE_SEL_HIGH_ADDR, (REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_HIGH_ADDR) & ~((uint32_t)0x000C0000)) | ((uint32_t)g1emb2app25sel << 18));
}

__INLINE uint8_t ipc_g1_emb2app24_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_HIGH_ADDR);
    return ((localVal & ((uint32_t)0x00030000)) >> 16);
}

__INLINE void ipc_g1_emb2app24_sel_setf(uint8_t g1emb2app24sel)
{
    REG_PL_WR(IPC_G1_EMB2APP_LINE_SEL_HIGH_ADDR, (REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_HIGH_ADDR) & ~((uint32_t)0x00030000)) | ((uint32_t)g1emb2app24sel << 16));
}

__INLINE uint8_t ipc_g1_emb2app23_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_HIGH_ADDR);
    return ((localVal & ((uint32_t)0x0000C000)) >> 14);
}

__INLINE void ipc_g1_emb2app23_sel_setf(uint8_t g1emb2app23sel)
{
    REG_PL_WR(IPC_G1_EMB2APP_LINE_SEL_HIGH_ADDR, (REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_HIGH_ADDR) & ~((uint32_t)0x0000C000)) | ((uint32_t)g1emb2app23sel << 14));
}

__INLINE uint8_t ipc_g1_emb2app22_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_HIGH_ADDR);
    return ((localVal & ((uint32_t)0x00003000)) >> 12);
}

__INLINE void ipc_g1_emb2app22_sel_setf(uint8_t g1emb2app22sel)
{
    REG_PL_WR(IPC_G1_EMB2APP_LINE_SEL_HIGH_ADDR, (REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_HIGH_ADDR) & ~((uint32_t)0x00003000)) | ((uint32_t)g1emb2app22sel << 12));
}

__INLINE uint8_t ipc_g1_emb2app21_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_HIGH_ADDR);
    return ((localVal & ((uint32_t)0x00000C00)) >> 10);
}

__INLINE void ipc_g1_emb2app21_sel_setf(uint8_t g1emb2app21sel)
{
    REG_PL_WR(IPC_G1_EMB2APP_LINE_SEL_HIGH_ADDR, (REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_HIGH_ADDR) & ~((uint32_t)0x00000C00)) | ((uint32_t)g1emb2app21sel << 10));
}

__INLINE uint8_t ipc_g1_emb2app20_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_HIGH_ADDR);
    return ((localVal & ((uint32_t)0x00000300)) >> 8);
}

__INLINE void ipc_g1_emb2app20_sel_setf(uint8_t g1emb2app20sel)
{
    REG_PL_WR(IPC_G1_EMB2APP_LINE_SEL_HIGH_ADDR, (REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_HIGH_ADDR) & ~((uint32_t)0x00000300)) | ((uint32_t)g1emb2app20sel << 8));
}

__INLINE uint8_t ipc_g1_emb2app19_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_HIGH_ADDR);
    return ((localVal & ((uint32_t)0x000000C0)) >> 6);
}

__INLINE void ipc_g1_emb2app19_sel_setf(uint8_t g1emb2app19sel)
{
    REG_PL_WR(IPC_G1_EMB2APP_LINE_SEL_HIGH_ADDR, (REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_HIGH_ADDR) & ~((uint32_t)0x000000C0)) | ((uint32_t)g1emb2app19sel << 6));
}

__INLINE uint8_t ipc_g1_emb2app18_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_HIGH_ADDR);
    return ((localVal & ((uint32_t)0x00000030)) >> 4);
}

__INLINE void ipc_g1_emb2app18_sel_setf(uint8_t g1emb2app18sel)
{
    REG_PL_WR(IPC_G1_EMB2APP_LINE_SEL_HIGH_ADDR, (REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_HIGH_ADDR) & ~((uint32_t)0x00000030)) | ((uint32_t)g1emb2app18sel << 4));
}

__INLINE uint8_t ipc_g1_emb2app17_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_HIGH_ADDR);
    return ((localVal & ((uint32_t)0x0000000C)) >> 2);
}

__INLINE void ipc_g1_emb2app17_sel_setf(uint8_t g1emb2app17sel)
{
    REG_PL_WR(IPC_G1_EMB2APP_LINE_SEL_HIGH_ADDR, (REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_HIGH_ADDR) & ~((uint32_t)0x0000000C)) | ((uint32_t)g1emb2app17sel << 2));
}

__INLINE uint8_t ipc_g1_emb2app16_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_HIGH_ADDR);
    return ((localVal & ((uint32_t)0x00000003)) >> 0);
}

__INLINE void ipc_g1_emb2app16_sel_setf(uint8_t g1emb2app16sel)
{
    REG_PL_WR(IPC_G1_EMB2APP_LINE_SEL_HIGH_ADDR, (REG_PL_RD(IPC_G1_EMB2APP_LINE_SEL_HIGH_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)g1emb2app16sel << 0));
}

/**
 * @brief G1_EMB2APP_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:00    G1_EMB2APP_STATUS   0x0
 * </pre>
 */
#define IPC_G1_EMB2APP_STATUS_ADDR   0x4004421C
#define IPC_G1_EMB2APP_STATUS_OFFSET 0x0000001C
#define IPC_G1_EMB2APP_STATUS_INDEX  0x00000007
#define IPC_G1_EMB2APP_STATUS_RESET  0x00000000

__INLINE uint32_t ipc_g1_emb2app_status_get(void)
{
    return REG_PL_RD(IPC_G1_EMB2APP_STATUS_ADDR);
}

// field definitions
#define IPC_G1_EMB2APP_STATUS_MASK   ((uint32_t)0xFFFFFFFF)
#define IPC_G1_EMB2APP_STATUS_LSB    0
#define IPC_G1_EMB2APP_STATUS_WIDTH  ((uint32_t)0x00000020)

#define IPC_G1_EMB2APP_STATUS_RST    0x0

__INLINE uint32_t ipc_g1_emb2app_status_getf(void)
{
    uint32_t localVal = REG_PL_RD(IPC_G1_EMB2APP_STATUS_ADDR);
    return (localVal >> 0);
}


#endif // _REG_G1_IPC_APP_H_

