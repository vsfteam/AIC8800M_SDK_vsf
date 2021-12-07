/**
 * @file reg_bt_rf.h
 * @brief Definitions of the BT_RF HW block registers and register access functions.
 *
 * @defgroup REG_BT_RF REG_BT_RF
 * @ingroup REG
 * @{
 *
 * @brief Definitions of the BT_RF HW block registers and register access functions.
 */
#ifndef _REG_BT_RF_H_
#define _REG_BT_RF_H_

#include "compiler.h"
#include "arch.h"
#include "reg_access.h"

/** @brief Number of registers in the REG_BT_RF peripheral.
 */
#define REG_BT_RF_COUNT 28

/** @brief Decoding mask of the REG_BT_RF peripheral registers from the CPU point of view.
 */
#define REG_BT_RF_DECODING_MASK 0x0000007F

/**
 * @name BT_DPLL_REG2 register definitions
 * <table>
 * <caption id="BT_DPLL_REG2_BF">BT_DPLL_REG2 bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>20 <td>bt_dpll_fref_sel_rx <td>R <td>R/W <td>0
 * </table>
 *
 * @{
 */

/// Address of the BT_DPLL_REG2 register
#define BT_RF_BT_DPLL_REG2_ADDR   0x40622030
/// Offset of the BT_DPLL_REG2 register from the base address
#define BT_RF_BT_DPLL_REG2_OFFSET 0x00000030
/// Index of the BT_DPLL_REG2 register
#define BT_RF_BT_DPLL_REG2_INDEX  0x0000000C
/// Reset value of the BT_DPLL_REG2 register
#define BT_RF_BT_DPLL_REG2_RESET  0x00000000

/**
 * @brief Returns the current value of the BT_DPLL_REG2 register.
 * The BT_DPLL_REG2 register will be read and its value returned.
 * @return The current value of the BT_DPLL_REG2 register.
 */
__INLINE uint32_t bt_rf_bt_dpll_reg2_get(void)
{
    return REG_PL_RD(BT_RF_BT_DPLL_REG2_ADDR);
}

/**
 * @brief Sets the BT_DPLL_REG2 register to a value.
 * The BT_DPLL_REG2 register will be written.
 * @param value - The value to write.
 */
__INLINE void bt_rf_bt_dpll_reg2_set(uint32_t value)
{
    REG_PL_WR(BT_RF_BT_DPLL_REG2_ADDR, value);
}

// field definitions
/// BT_DPLL_FREF_SEL_RX field bit
#define BT_RF_BT_DPLL_FREF_SEL_RX_BIT    ((uint32_t)0x00100000)
/// BT_DPLL_FREF_SEL_RX field position
#define BT_RF_BT_DPLL_FREF_SEL_RX_POS    20

/// BT_DPLL_FREF_SEL_RX field reset value
#define BT_RF_BT_DPLL_FREF_SEL_RX_RST    0x0

/**
 * @brief Returns the current value of the bt_dpll_fref_sel_rx field in the BT_DPLL_REG2 register.
 *
 * The BT_DPLL_REG2 register will be read and the bt_dpll_fref_sel_rx field's value will be returned.
 *
 * @return The current value of the bt_dpll_fref_sel_rx field in the BT_DPLL_REG2 register.
 */
__INLINE uint8_t bt_rf_bt_dpll_fref_sel_rx_getf(void)
{
    uint32_t localVal = REG_PL_RD(BT_RF_BT_DPLL_REG2_ADDR);
    return (localVal >> 20);
}

/**
 * @brief Sets the bt_dpll_fref_sel_rx field of the BT_DPLL_REG2 register.
 *
 * The BT_DPLL_REG2 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] btdpllfrefselrx - The value to set the field to.
 */
__INLINE void bt_rf_bt_dpll_fref_sel_rx_setf(uint8_t btdpllfrefselrx)
{
    REG_PL_WR(BT_RF_BT_DPLL_REG2_ADDR, (uint32_t)btdpllfrefselrx << 20);
}

/// @}

/**
 * @name MAN_CTRL register definitions
 * <table>
 * <caption id="MAN_CTRL_BF">MAN_CTRL bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>16 <td>              rfon <td>R <td>R/W <td>0
 * </table>
 *
 * @{
 */

/// Address of the MAN_CTRL register
#define BT_RF_MAN_CTRL_ADDR   0x4062204C
/// Offset of the MAN_CTRL register from the base address
#define BT_RF_MAN_CTRL_OFFSET 0x0000004C
/// Index of the MAN_CTRL register
#define BT_RF_MAN_CTRL_INDEX  0x00000013
/// Reset value of the MAN_CTRL register
#define BT_RF_MAN_CTRL_RESET  0x00000000

/**
 * @brief Returns the current value of the MAN_CTRL register.
 * The MAN_CTRL register will be read and its value returned.
 * @return The current value of the MAN_CTRL register.
 */
__INLINE uint32_t bt_rf_man_ctrl_get(void)
{
    return REG_PL_RD(BT_RF_MAN_CTRL_ADDR);
}

/**
 * @brief Sets the MAN_CTRL register to a value.
 * The MAN_CTRL register will be written.
 * @param value - The value to write.
 */
__INLINE void bt_rf_man_ctrl_set(uint32_t value)
{
    REG_PL_WR(BT_RF_MAN_CTRL_ADDR, value);
}

// field definitions
/// RFON field bit
#define BT_RF_RFON_BIT    ((uint32_t)0x00010000)
/// RFON field position
#define BT_RF_RFON_POS    16

/// RFON field reset value
#define BT_RF_RFON_RST    0x0

/**
 * @brief Returns the current value of the rfon field in the MAN_CTRL register.
 *
 * The MAN_CTRL register will be read and the rfon field's value will be returned.
 *
 * @return The current value of the rfon field in the MAN_CTRL register.
 */
__INLINE uint8_t bt_rf_rfon_getf(void)
{
    uint32_t localVal = REG_PL_RD(BT_RF_MAN_CTRL_ADDR);
    return (localVal >> 16);
}

/**
 * @brief Sets the rfon field of the MAN_CTRL register.
 *
 * The MAN_CTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rfon - The value to set the field to.
 */
__INLINE void bt_rf_rfon_setf(uint8_t rfon)
{
    REG_PL_WR(BT_RF_MAN_CTRL_ADDR, (uint32_t)rfon << 16);
}

/// @}

/**
 * @name RXGAIN_MEM_CTRL register definitions
 * <table>
 * <caption id="RXGAIN_MEM_CTRL_BF">RXGAIN_MEM_CTRL bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>11 <td>rxgain_mem_rw_done <td>R <td>R/W <td>0
 * <tr><td>10 <td>    clk_rxgain_sel <td>R <td>R/W <td>0
 * <tr><td>09 <td>     clk_rxgain_en <td>R <td>R/W <td>0
 * <tr><td>08 <td>    rxgain_mem_cfg <td>R <td>R/W <td>0
 * <tr><td>07 <td>rxgain_mem_ren_pulse <td>R <td>R/W <td>0
 * <tr><td>06 <td>rxgain_mem_wen_pulse <td>R <td>R/W <td>0
 * <tr><td>05:00 <td>rxgain_mem_addr_cfg <td>R <td>R/W <td>0x0
 * </table>
 *
 * @{
 */

/// Address of the RXGAIN_MEM_CTRL register
#define BT_RF_RXGAIN_MEM_CTRL_ADDR   0x40622058
/// Offset of the RXGAIN_MEM_CTRL register from the base address
#define BT_RF_RXGAIN_MEM_CTRL_OFFSET 0x00000058
/// Index of the RXGAIN_MEM_CTRL register
#define BT_RF_RXGAIN_MEM_CTRL_INDEX  0x00000016
/// Reset value of the RXGAIN_MEM_CTRL register
#define BT_RF_RXGAIN_MEM_CTRL_RESET  0x00000000

/**
 * @brief Returns the current value of the RXGAIN_MEM_CTRL register.
 * The RXGAIN_MEM_CTRL register will be read and its value returned.
 * @return The current value of the RXGAIN_MEM_CTRL register.
 */
__INLINE uint32_t bt_rf_rxgain_mem_ctrl_get(void)
{
    return REG_PL_RD(BT_RF_RXGAIN_MEM_CTRL_ADDR);
}

/**
 * @brief Sets the RXGAIN_MEM_CTRL register to a value.
 * The RXGAIN_MEM_CTRL register will be written.
 * @param value - The value to write.
 */
__INLINE void bt_rf_rxgain_mem_ctrl_set(uint32_t value)
{
    REG_PL_WR(BT_RF_RXGAIN_MEM_CTRL_ADDR, value);
}

// field definitions
/// RXGAIN_MEM_RW_DONE field bit
#define BT_RF_RXGAIN_MEM_RW_DONE_BIT      ((uint32_t)0x00000800)
/// RXGAIN_MEM_RW_DONE field position
#define BT_RF_RXGAIN_MEM_RW_DONE_POS      11
/// CLK_RXGAIN_SEL field bit
#define BT_RF_CLK_RXGAIN_SEL_BIT          ((uint32_t)0x00000400)
/// CLK_RXGAIN_SEL field position
#define BT_RF_CLK_RXGAIN_SEL_POS          10
/// CLK_RXGAIN_EN field bit
#define BT_RF_CLK_RXGAIN_EN_BIT           ((uint32_t)0x00000200)
/// CLK_RXGAIN_EN field position
#define BT_RF_CLK_RXGAIN_EN_POS           9
/// RXGAIN_MEM_CFG field bit
#define BT_RF_RXGAIN_MEM_CFG_BIT          ((uint32_t)0x00000100)
/// RXGAIN_MEM_CFG field position
#define BT_RF_RXGAIN_MEM_CFG_POS          8
/// RXGAIN_MEM_REN_PULSE field bit
#define BT_RF_RXGAIN_MEM_REN_PULSE_BIT    ((uint32_t)0x00000080)
/// RXGAIN_MEM_REN_PULSE field position
#define BT_RF_RXGAIN_MEM_REN_PULSE_POS    7
/// RXGAIN_MEM_WEN_PULSE field bit
#define BT_RF_RXGAIN_MEM_WEN_PULSE_BIT    ((uint32_t)0x00000040)
/// RXGAIN_MEM_WEN_PULSE field position
#define BT_RF_RXGAIN_MEM_WEN_PULSE_POS    6
/// RXGAIN_MEM_ADDR_CFG field mask
#define BT_RF_RXGAIN_MEM_ADDR_CFG_MASK    ((uint32_t)0x0000003F)
/// RXGAIN_MEM_ADDR_CFG field LSB position
#define BT_RF_RXGAIN_MEM_ADDR_CFG_LSB     0
/// RXGAIN_MEM_ADDR_CFG field width
#define BT_RF_RXGAIN_MEM_ADDR_CFG_WIDTH   ((uint32_t)0x00000006)

/// RXGAIN_MEM_RW_DONE field reset value
#define BT_RF_RXGAIN_MEM_RW_DONE_RST      0x0
/// CLK_RXGAIN_SEL field reset value
#define BT_RF_CLK_RXGAIN_SEL_RST          0x0
/// CLK_RXGAIN_EN field reset value
#define BT_RF_CLK_RXGAIN_EN_RST           0x0
/// RXGAIN_MEM_CFG field reset value
#define BT_RF_RXGAIN_MEM_CFG_RST          0x0
/// RXGAIN_MEM_REN_PULSE field reset value
#define BT_RF_RXGAIN_MEM_REN_PULSE_RST    0x0
/// RXGAIN_MEM_WEN_PULSE field reset value
#define BT_RF_RXGAIN_MEM_WEN_PULSE_RST    0x0
/// RXGAIN_MEM_ADDR_CFG field reset value
#define BT_RF_RXGAIN_MEM_ADDR_CFG_RST     0x0

/**
 * @brief Constructs a value for the RXGAIN_MEM_CTRL register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] rxgainmemrwdone - The value to use for the rxgain_mem_rw_done field.
 * @param[in] clkrxgainsel - The value to use for the clk_rxgain_sel field.
 * @param[in] clkrxgainen - The value to use for the clk_rxgain_en field.
 * @param[in] rxgainmemcfg - The value to use for the rxgain_mem_cfg field.
 * @param[in] rxgainmemrenpulse - The value to use for the rxgain_mem_ren_pulse field.
 * @param[in] rxgainmemwenpulse - The value to use for the rxgain_mem_wen_pulse field.
 * @param[in] rxgainmemaddrcfg - The value to use for the rxgain_mem_addr_cfg field.
 */
__INLINE void bt_rf_rxgain_mem_ctrl_pack(uint8_t rxgainmemrwdone, uint8_t clkrxgainsel, uint8_t clkrxgainen, uint8_t rxgainmemcfg, uint8_t rxgainmemrenpulse, uint8_t rxgainmemwenpulse, uint8_t rxgainmemaddrcfg)
{
    REG_PL_WR(BT_RF_RXGAIN_MEM_CTRL_ADDR,  ((uint32_t)rxgainmemrwdone << 11) | ((uint32_t)clkrxgainsel << 10) | ((uint32_t)clkrxgainen << 9) | ((uint32_t)rxgainmemcfg << 8) | ((uint32_t)rxgainmemrenpulse << 7) | ((uint32_t)rxgainmemwenpulse << 6) | ((uint32_t)rxgainmemaddrcfg << 0));
}

/**
 * @brief Unpacks RXGAIN_MEM_CTRL's fields from current value of the RXGAIN_MEM_CTRL register.
 *
 * Reads the RXGAIN_MEM_CTRL register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] rxgainmemrwdone - Will be populated with the current value of this field from the register.
 * @param[out] clkrxgainsel - Will be populated with the current value of this field from the register.
 * @param[out] clkrxgainen - Will be populated with the current value of this field from the register.
 * @param[out] rxgainmemcfg - Will be populated with the current value of this field from the register.
 * @param[out] rxgainmemrenpulse - Will be populated with the current value of this field from the register.
 * @param[out] rxgainmemwenpulse - Will be populated with the current value of this field from the register.
 * @param[out] rxgainmemaddrcfg - Will be populated with the current value of this field from the register.
 */
__INLINE void bt_rf_rxgain_mem_ctrl_unpack(uint8_t* rxgainmemrwdone, uint8_t* clkrxgainsel, uint8_t* clkrxgainen, uint8_t* rxgainmemcfg, uint8_t* rxgainmemrenpulse, uint8_t* rxgainmemwenpulse, uint8_t* rxgainmemaddrcfg)
{
    uint32_t localVal = REG_PL_RD(BT_RF_RXGAIN_MEM_CTRL_ADDR);

    *rxgainmemrwdone = (localVal & ((uint32_t)0x00000800)) >> 11;
    *clkrxgainsel = (localVal & ((uint32_t)0x00000400)) >> 10;
    *clkrxgainen = (localVal & ((uint32_t)0x00000200)) >> 9;
    *rxgainmemcfg = (localVal & ((uint32_t)0x00000100)) >> 8;
    *rxgainmemrenpulse = (localVal & ((uint32_t)0x00000080)) >> 7;
    *rxgainmemwenpulse = (localVal & ((uint32_t)0x00000040)) >> 6;
    *rxgainmemaddrcfg = (localVal & ((uint32_t)0x0000003F)) >> 0;
}

/**
 * @brief Returns the current value of the rxgain_mem_rw_done field in the RXGAIN_MEM_CTRL register.
 *
 * The RXGAIN_MEM_CTRL register will be read and the rxgain_mem_rw_done field's value will be returned.
 *
 * @return The current value of the rxgain_mem_rw_done field in the RXGAIN_MEM_CTRL register.
 */
__INLINE uint8_t bt_rf_rxgain_mem_rw_done_getf(void)
{
    uint32_t localVal = REG_PL_RD(BT_RF_RXGAIN_MEM_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000800)) >> 11);
}

/**
 * @brief Sets the rxgain_mem_rw_done field of the RXGAIN_MEM_CTRL register.
 *
 * The RXGAIN_MEM_CTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rxgainmemrwdone - The value to set the field to.
 */
__INLINE void bt_rf_rxgain_mem_rw_done_setf(uint8_t rxgainmemrwdone)
{
    REG_PL_WR(BT_RF_RXGAIN_MEM_CTRL_ADDR, (REG_PL_RD(BT_RF_RXGAIN_MEM_CTRL_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)rxgainmemrwdone << 11));
}

/**
 * @brief Returns the current value of the clk_rxgain_sel field in the RXGAIN_MEM_CTRL register.
 *
 * The RXGAIN_MEM_CTRL register will be read and the clk_rxgain_sel field's value will be returned.
 *
 * @return The current value of the clk_rxgain_sel field in the RXGAIN_MEM_CTRL register.
 */
__INLINE uint8_t bt_rf_clk_rxgain_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(BT_RF_RXGAIN_MEM_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000400)) >> 10);
}

/**
 * @brief Sets the clk_rxgain_sel field of the RXGAIN_MEM_CTRL register.
 *
 * The RXGAIN_MEM_CTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] clkrxgainsel - The value to set the field to.
 */
__INLINE void bt_rf_clk_rxgain_sel_setf(uint8_t clkrxgainsel)
{
    REG_PL_WR(BT_RF_RXGAIN_MEM_CTRL_ADDR, (REG_PL_RD(BT_RF_RXGAIN_MEM_CTRL_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)clkrxgainsel << 10));
}

/**
 * @brief Returns the current value of the clk_rxgain_en field in the RXGAIN_MEM_CTRL register.
 *
 * The RXGAIN_MEM_CTRL register will be read and the clk_rxgain_en field's value will be returned.
 *
 * @return The current value of the clk_rxgain_en field in the RXGAIN_MEM_CTRL register.
 */
__INLINE uint8_t bt_rf_clk_rxgain_en_getf(void)
{
    uint32_t localVal = REG_PL_RD(BT_RF_RXGAIN_MEM_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000200)) >> 9);
}

/**
 * @brief Sets the clk_rxgain_en field of the RXGAIN_MEM_CTRL register.
 *
 * The RXGAIN_MEM_CTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] clkrxgainen - The value to set the field to.
 */
__INLINE void bt_rf_clk_rxgain_en_setf(uint8_t clkrxgainen)
{
    REG_PL_WR(BT_RF_RXGAIN_MEM_CTRL_ADDR, (REG_PL_RD(BT_RF_RXGAIN_MEM_CTRL_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)clkrxgainen << 9));
}

/**
 * @brief Returns the current value of the rxgain_mem_cfg field in the RXGAIN_MEM_CTRL register.
 *
 * The RXGAIN_MEM_CTRL register will be read and the rxgain_mem_cfg field's value will be returned.
 *
 * @return The current value of the rxgain_mem_cfg field in the RXGAIN_MEM_CTRL register.
 */
__INLINE uint8_t bt_rf_rxgain_mem_cfg_getf(void)
{
    uint32_t localVal = REG_PL_RD(BT_RF_RXGAIN_MEM_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000100)) >> 8);
}

/**
 * @brief Sets the rxgain_mem_cfg field of the RXGAIN_MEM_CTRL register.
 *
 * The RXGAIN_MEM_CTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rxgainmemcfg - The value to set the field to.
 */
__INLINE void bt_rf_rxgain_mem_cfg_setf(uint8_t rxgainmemcfg)
{
    REG_PL_WR(BT_RF_RXGAIN_MEM_CTRL_ADDR, (REG_PL_RD(BT_RF_RXGAIN_MEM_CTRL_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)rxgainmemcfg << 8));
}

/**
 * @brief Returns the current value of the rxgain_mem_ren_pulse field in the RXGAIN_MEM_CTRL register.
 *
 * The RXGAIN_MEM_CTRL register will be read and the rxgain_mem_ren_pulse field's value will be returned.
 *
 * @return The current value of the rxgain_mem_ren_pulse field in the RXGAIN_MEM_CTRL register.
 */
__INLINE uint8_t bt_rf_rxgain_mem_ren_pulse_getf(void)
{
    uint32_t localVal = REG_PL_RD(BT_RF_RXGAIN_MEM_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000080)) >> 7);
}

/**
 * @brief Sets the rxgain_mem_ren_pulse field of the RXGAIN_MEM_CTRL register.
 *
 * The RXGAIN_MEM_CTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rxgainmemrenpulse - The value to set the field to.
 */
__INLINE void bt_rf_rxgain_mem_ren_pulse_setf(uint8_t rxgainmemrenpulse)
{
    REG_PL_WR(BT_RF_RXGAIN_MEM_CTRL_ADDR, (REG_PL_RD(BT_RF_RXGAIN_MEM_CTRL_ADDR) & ~((uint32_t)0x00000080)) | ((uint32_t)rxgainmemrenpulse << 7));
}

/**
 * @brief Returns the current value of the rxgain_mem_wen_pulse field in the RXGAIN_MEM_CTRL register.
 *
 * The RXGAIN_MEM_CTRL register will be read and the rxgain_mem_wen_pulse field's value will be returned.
 *
 * @return The current value of the rxgain_mem_wen_pulse field in the RXGAIN_MEM_CTRL register.
 */
__INLINE uint8_t bt_rf_rxgain_mem_wen_pulse_getf(void)
{
    uint32_t localVal = REG_PL_RD(BT_RF_RXGAIN_MEM_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000040)) >> 6);
}

/**
 * @brief Sets the rxgain_mem_wen_pulse field of the RXGAIN_MEM_CTRL register.
 *
 * The RXGAIN_MEM_CTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rxgainmemwenpulse - The value to set the field to.
 */
__INLINE void bt_rf_rxgain_mem_wen_pulse_setf(uint8_t rxgainmemwenpulse)
{
    REG_PL_WR(BT_RF_RXGAIN_MEM_CTRL_ADDR, (REG_PL_RD(BT_RF_RXGAIN_MEM_CTRL_ADDR) & ~((uint32_t)0x00000040)) | ((uint32_t)rxgainmemwenpulse << 6));
}

/**
 * @brief Returns the current value of the rxgain_mem_addr_cfg field in the RXGAIN_MEM_CTRL register.
 *
 * The RXGAIN_MEM_CTRL register will be read and the rxgain_mem_addr_cfg field's value will be returned.
 *
 * @return The current value of the rxgain_mem_addr_cfg field in the RXGAIN_MEM_CTRL register.
 */
__INLINE uint8_t bt_rf_rxgain_mem_addr_cfg_getf(void)
{
    uint32_t localVal = REG_PL_RD(BT_RF_RXGAIN_MEM_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x0000003F)) >> 0);
}

/**
 * @brief Sets the rxgain_mem_addr_cfg field of the RXGAIN_MEM_CTRL register.
 *
 * The RXGAIN_MEM_CTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rxgainmemaddrcfg - The value to set the field to.
 */
__INLINE void bt_rf_rxgain_mem_addr_cfg_setf(uint8_t rxgainmemaddrcfg)
{
    REG_PL_WR(BT_RF_RXGAIN_MEM_CTRL_ADDR, (REG_PL_RD(BT_RF_RXGAIN_MEM_CTRL_ADDR) & ~((uint32_t)0x0000003F)) | ((uint32_t)rxgainmemaddrcfg << 0));
}

/// @}

/**
 * @name RXGAIN_MEM_WD register definitions
 * <table>
 * <caption id="RXGAIN_MEM_WD_BF">RXGAIN_MEM_WD bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>31:00 <td>  rxgain_mem_wdata <td>R <td>R/W <td>0x0
 * </table>
 *
 * @{
 */

/// Address of the RXGAIN_MEM_WD register
#define BT_RF_RXGAIN_MEM_WD_ADDR   0x4062205C
/// Offset of the RXGAIN_MEM_WD register from the base address
#define BT_RF_RXGAIN_MEM_WD_OFFSET 0x0000005C
/// Index of the RXGAIN_MEM_WD register
#define BT_RF_RXGAIN_MEM_WD_INDEX  0x00000017
/// Reset value of the RXGAIN_MEM_WD register
#define BT_RF_RXGAIN_MEM_WD_RESET  0x00000000

/**
 * @brief Returns the current value of the RXGAIN_MEM_WD register.
 * The RXGAIN_MEM_WD register will be read and its value returned.
 * @return The current value of the RXGAIN_MEM_WD register.
 */
__INLINE uint32_t bt_rf_rxgain_mem_wd_get(void)
{
    return REG_PL_RD(BT_RF_RXGAIN_MEM_WD_ADDR);
}

/**
 * @brief Sets the RXGAIN_MEM_WD register to a value.
 * The RXGAIN_MEM_WD register will be written.
 * @param value - The value to write.
 */
__INLINE void bt_rf_rxgain_mem_wd_set(uint32_t value)
{
    REG_PL_WR(BT_RF_RXGAIN_MEM_WD_ADDR, value);
}

// field definitions
/// RXGAIN_MEM_WDATA field mask
#define BT_RF_RXGAIN_MEM_WDATA_MASK   ((uint32_t)0xFFFFFFFF)
/// RXGAIN_MEM_WDATA field LSB position
#define BT_RF_RXGAIN_MEM_WDATA_LSB    0
/// RXGAIN_MEM_WDATA field width
#define BT_RF_RXGAIN_MEM_WDATA_WIDTH  ((uint32_t)0x00000020)

/// RXGAIN_MEM_WDATA field reset value
#define BT_RF_RXGAIN_MEM_WDATA_RST    0x0

/**
 * @brief Returns the current value of the rxgain_mem_wdata field in the RXGAIN_MEM_WD register.
 *
 * The RXGAIN_MEM_WD register will be read and the rxgain_mem_wdata field's value will be returned.
 *
 * @return The current value of the rxgain_mem_wdata field in the RXGAIN_MEM_WD register.
 */
__INLINE uint32_t bt_rf_rxgain_mem_wdata_getf(void)
{
    uint32_t localVal = REG_PL_RD(BT_RF_RXGAIN_MEM_WD_ADDR);
    return (localVal >> 0);
}

/**
 * @brief Sets the rxgain_mem_wdata field of the RXGAIN_MEM_WD register.
 *
 * The RXGAIN_MEM_WD register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rxgainmemwdata - The value to set the field to.
 */
__INLINE void bt_rf_rxgain_mem_wdata_setf(uint32_t rxgainmemwdata)
{
    REG_PL_WR(BT_RF_RXGAIN_MEM_WD_ADDR, (uint32_t)rxgainmemwdata << 0);
}

/// @}

/**
 * @name RXGAIN_MEM_RD register definitions
 * <table>
 * <caption id="RXGAIN_MEM_RD_BF">RXGAIN_MEM_RD bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>31:00 <td>  rxgain_mem_rdata <td>R <td>R/W <td>0x0
 * </table>
 *
 * @{
 */

/// Address of the RXGAIN_MEM_RD register
#define BT_RF_RXGAIN_MEM_RD_ADDR   0x40622060
/// Offset of the RXGAIN_MEM_RD register from the base address
#define BT_RF_RXGAIN_MEM_RD_OFFSET 0x00000060
/// Index of the RXGAIN_MEM_RD register
#define BT_RF_RXGAIN_MEM_RD_INDEX  0x00000018
/// Reset value of the RXGAIN_MEM_RD register
#define BT_RF_RXGAIN_MEM_RD_RESET  0x00000000

/**
 * @brief Returns the current value of the RXGAIN_MEM_RD register.
 * The RXGAIN_MEM_RD register will be read and its value returned.
 * @return The current value of the RXGAIN_MEM_RD register.
 */
__INLINE uint32_t bt_rf_rxgain_mem_rd_get(void)
{
    return REG_PL_RD(BT_RF_RXGAIN_MEM_RD_ADDR);
}

/**
 * @brief Sets the RXGAIN_MEM_RD register to a value.
 * The RXGAIN_MEM_RD register will be written.
 * @param value - The value to write.
 */
__INLINE void bt_rf_rxgain_mem_rd_set(uint32_t value)
{
    REG_PL_WR(BT_RF_RXGAIN_MEM_RD_ADDR, value);
}

// field definitions
/// RXGAIN_MEM_RDATA field mask
#define BT_RF_RXGAIN_MEM_RDATA_MASK   ((uint32_t)0xFFFFFFFF)
/// RXGAIN_MEM_RDATA field LSB position
#define BT_RF_RXGAIN_MEM_RDATA_LSB    0
/// RXGAIN_MEM_RDATA field width
#define BT_RF_RXGAIN_MEM_RDATA_WIDTH  ((uint32_t)0x00000020)

/// RXGAIN_MEM_RDATA field reset value
#define BT_RF_RXGAIN_MEM_RDATA_RST    0x0

/**
 * @brief Returns the current value of the rxgain_mem_rdata field in the RXGAIN_MEM_RD register.
 *
 * The RXGAIN_MEM_RD register will be read and the rxgain_mem_rdata field's value will be returned.
 *
 * @return The current value of the rxgain_mem_rdata field in the RXGAIN_MEM_RD register.
 */
__INLINE uint32_t bt_rf_rxgain_mem_rdata_getf(void)
{
    uint32_t localVal = REG_PL_RD(BT_RF_RXGAIN_MEM_RD_ADDR);
    return (localVal >> 0);
}

/**
 * @brief Sets the rxgain_mem_rdata field of the RXGAIN_MEM_RD register.
 *
 * The RXGAIN_MEM_RD register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rxgainmemrdata - The value to set the field to.
 */
__INLINE void bt_rf_rxgain_mem_rdata_setf(uint32_t rxgainmemrdata)
{
    REG_PL_WR(BT_RF_RXGAIN_MEM_RD_ADDR, (uint32_t)rxgainmemrdata << 0);
}

/// @}

/**
 * @name TXGAIN_MEM_CTRL register definitions
 * <table>
 * <caption id="TXGAIN_MEM_CTRL_BF">TXGAIN_MEM_CTRL bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>10 <td>txgain_mem_rw_done <td>R <td>R/W <td>0
 * <tr><td>09 <td>    clk_txgain_sel <td>R <td>R/W <td>0
 * <tr><td>08 <td>     clk_txgain_en <td>R <td>R/W <td>0
 * <tr><td>07 <td>    txgain_mem_cfg <td>R <td>R/W <td>0
 * <tr><td>06 <td>txgain_mem_ren_pulse <td>R <td>R/W <td>0
 * <tr><td>05 <td>txgain_mem_wen_pulse <td>R <td>R/W <td>0
 * <tr><td>04:00 <td>txgain_mem_addr_cfg <td>R <td>R/W <td>0x0
 * </table>
 *
 * @{
 */

/// Address of the TXGAIN_MEM_CTRL register
#define BT_RF_TXGAIN_MEM_CTRL_ADDR   0x40622064
/// Offset of the TXGAIN_MEM_CTRL register from the base address
#define BT_RF_TXGAIN_MEM_CTRL_OFFSET 0x00000064
/// Index of the TXGAIN_MEM_CTRL register
#define BT_RF_TXGAIN_MEM_CTRL_INDEX  0x00000019
/// Reset value of the TXGAIN_MEM_CTRL register
#define BT_RF_TXGAIN_MEM_CTRL_RESET  0x00000000

/**
 * @brief Returns the current value of the TXGAIN_MEM_CTRL register.
 * The TXGAIN_MEM_CTRL register will be read and its value returned.
 * @return The current value of the TXGAIN_MEM_CTRL register.
 */
__INLINE uint32_t bt_rf_txgain_mem_ctrl_get(void)
{
    return REG_PL_RD(BT_RF_TXGAIN_MEM_CTRL_ADDR);
}

/**
 * @brief Sets the TXGAIN_MEM_CTRL register to a value.
 * The TXGAIN_MEM_CTRL register will be written.
 * @param value - The value to write.
 */
__INLINE void bt_rf_txgain_mem_ctrl_set(uint32_t value)
{
    REG_PL_WR(BT_RF_TXGAIN_MEM_CTRL_ADDR, value);
}

// field definitions
/// TXGAIN_MEM_RW_DONE field bit
#define BT_RF_TXGAIN_MEM_RW_DONE_BIT      ((uint32_t)0x00000400)
/// TXGAIN_MEM_RW_DONE field position
#define BT_RF_TXGAIN_MEM_RW_DONE_POS      10
/// CLK_TXGAIN_SEL field bit
#define BT_RF_CLK_TXGAIN_SEL_BIT          ((uint32_t)0x00000200)
/// CLK_TXGAIN_SEL field position
#define BT_RF_CLK_TXGAIN_SEL_POS          9
/// CLK_TXGAIN_EN field bit
#define BT_RF_CLK_TXGAIN_EN_BIT           ((uint32_t)0x00000100)
/// CLK_TXGAIN_EN field position
#define BT_RF_CLK_TXGAIN_EN_POS           8
/// TXGAIN_MEM_CFG field bit
#define BT_RF_TXGAIN_MEM_CFG_BIT          ((uint32_t)0x00000080)
/// TXGAIN_MEM_CFG field position
#define BT_RF_TXGAIN_MEM_CFG_POS          7
/// TXGAIN_MEM_REN_PULSE field bit
#define BT_RF_TXGAIN_MEM_REN_PULSE_BIT    ((uint32_t)0x00000040)
/// TXGAIN_MEM_REN_PULSE field position
#define BT_RF_TXGAIN_MEM_REN_PULSE_POS    6
/// TXGAIN_MEM_WEN_PULSE field bit
#define BT_RF_TXGAIN_MEM_WEN_PULSE_BIT    ((uint32_t)0x00000020)
/// TXGAIN_MEM_WEN_PULSE field position
#define BT_RF_TXGAIN_MEM_WEN_PULSE_POS    5
/// TXGAIN_MEM_ADDR_CFG field mask
#define BT_RF_TXGAIN_MEM_ADDR_CFG_MASK    ((uint32_t)0x0000001F)
/// TXGAIN_MEM_ADDR_CFG field LSB position
#define BT_RF_TXGAIN_MEM_ADDR_CFG_LSB     0
/// TXGAIN_MEM_ADDR_CFG field width
#define BT_RF_TXGAIN_MEM_ADDR_CFG_WIDTH   ((uint32_t)0x00000005)

/// TXGAIN_MEM_RW_DONE field reset value
#define BT_RF_TXGAIN_MEM_RW_DONE_RST      0x0
/// CLK_TXGAIN_SEL field reset value
#define BT_RF_CLK_TXGAIN_SEL_RST          0x0
/// CLK_TXGAIN_EN field reset value
#define BT_RF_CLK_TXGAIN_EN_RST           0x0
/// TXGAIN_MEM_CFG field reset value
#define BT_RF_TXGAIN_MEM_CFG_RST          0x0
/// TXGAIN_MEM_REN_PULSE field reset value
#define BT_RF_TXGAIN_MEM_REN_PULSE_RST    0x0
/// TXGAIN_MEM_WEN_PULSE field reset value
#define BT_RF_TXGAIN_MEM_WEN_PULSE_RST    0x0
/// TXGAIN_MEM_ADDR_CFG field reset value
#define BT_RF_TXGAIN_MEM_ADDR_CFG_RST     0x0

/**
 * @brief Constructs a value for the TXGAIN_MEM_CTRL register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] txgainmemrwdone - The value to use for the txgain_mem_rw_done field.
 * @param[in] clktxgainsel - The value to use for the clk_txgain_sel field.
 * @param[in] clktxgainen - The value to use for the clk_txgain_en field.
 * @param[in] txgainmemcfg - The value to use for the txgain_mem_cfg field.
 * @param[in] txgainmemrenpulse - The value to use for the txgain_mem_ren_pulse field.
 * @param[in] txgainmemwenpulse - The value to use for the txgain_mem_wen_pulse field.
 * @param[in] txgainmemaddrcfg - The value to use for the txgain_mem_addr_cfg field.
 */
__INLINE void bt_rf_txgain_mem_ctrl_pack(uint8_t txgainmemrwdone, uint8_t clktxgainsel, uint8_t clktxgainen, uint8_t txgainmemcfg, uint8_t txgainmemrenpulse, uint8_t txgainmemwenpulse, uint8_t txgainmemaddrcfg)
{
    REG_PL_WR(BT_RF_TXGAIN_MEM_CTRL_ADDR,  ((uint32_t)txgainmemrwdone << 10) | ((uint32_t)clktxgainsel << 9) | ((uint32_t)clktxgainen << 8) | ((uint32_t)txgainmemcfg << 7) | ((uint32_t)txgainmemrenpulse << 6) | ((uint32_t)txgainmemwenpulse << 5) | ((uint32_t)txgainmemaddrcfg << 0));
}

/**
 * @brief Unpacks TXGAIN_MEM_CTRL's fields from current value of the TXGAIN_MEM_CTRL register.
 *
 * Reads the TXGAIN_MEM_CTRL register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] txgainmemrwdone - Will be populated with the current value of this field from the register.
 * @param[out] clktxgainsel - Will be populated with the current value of this field from the register.
 * @param[out] clktxgainen - Will be populated with the current value of this field from the register.
 * @param[out] txgainmemcfg - Will be populated with the current value of this field from the register.
 * @param[out] txgainmemrenpulse - Will be populated with the current value of this field from the register.
 * @param[out] txgainmemwenpulse - Will be populated with the current value of this field from the register.
 * @param[out] txgainmemaddrcfg - Will be populated with the current value of this field from the register.
 */
__INLINE void bt_rf_txgain_mem_ctrl_unpack(uint8_t* txgainmemrwdone, uint8_t* clktxgainsel, uint8_t* clktxgainen, uint8_t* txgainmemcfg, uint8_t* txgainmemrenpulse, uint8_t* txgainmemwenpulse, uint8_t* txgainmemaddrcfg)
{
    uint32_t localVal = REG_PL_RD(BT_RF_TXGAIN_MEM_CTRL_ADDR);

    *txgainmemrwdone = (localVal & ((uint32_t)0x00000400)) >> 10;
    *clktxgainsel = (localVal & ((uint32_t)0x00000200)) >> 9;
    *clktxgainen = (localVal & ((uint32_t)0x00000100)) >> 8;
    *txgainmemcfg = (localVal & ((uint32_t)0x00000080)) >> 7;
    *txgainmemrenpulse = (localVal & ((uint32_t)0x00000040)) >> 6;
    *txgainmemwenpulse = (localVal & ((uint32_t)0x00000020)) >> 5;
    *txgainmemaddrcfg = (localVal & ((uint32_t)0x0000001F)) >> 0;
}

/**
 * @brief Returns the current value of the txgain_mem_rw_done field in the TXGAIN_MEM_CTRL register.
 *
 * The TXGAIN_MEM_CTRL register will be read and the txgain_mem_rw_done field's value will be returned.
 *
 * @return The current value of the txgain_mem_rw_done field in the TXGAIN_MEM_CTRL register.
 */
__INLINE uint8_t bt_rf_txgain_mem_rw_done_getf(void)
{
    uint32_t localVal = REG_PL_RD(BT_RF_TXGAIN_MEM_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000400)) >> 10);
}

/**
 * @brief Sets the txgain_mem_rw_done field of the TXGAIN_MEM_CTRL register.
 *
 * The TXGAIN_MEM_CTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] txgainmemrwdone - The value to set the field to.
 */
__INLINE void bt_rf_txgain_mem_rw_done_setf(uint8_t txgainmemrwdone)
{
    REG_PL_WR(BT_RF_TXGAIN_MEM_CTRL_ADDR, (REG_PL_RD(BT_RF_TXGAIN_MEM_CTRL_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)txgainmemrwdone << 10));
}

/**
 * @brief Returns the current value of the clk_txgain_sel field in the TXGAIN_MEM_CTRL register.
 *
 * The TXGAIN_MEM_CTRL register will be read and the clk_txgain_sel field's value will be returned.
 *
 * @return The current value of the clk_txgain_sel field in the TXGAIN_MEM_CTRL register.
 */
__INLINE uint8_t bt_rf_clk_txgain_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(BT_RF_TXGAIN_MEM_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000200)) >> 9);
}

/**
 * @brief Sets the clk_txgain_sel field of the TXGAIN_MEM_CTRL register.
 *
 * The TXGAIN_MEM_CTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] clktxgainsel - The value to set the field to.
 */
__INLINE void bt_rf_clk_txgain_sel_setf(uint8_t clktxgainsel)
{
    REG_PL_WR(BT_RF_TXGAIN_MEM_CTRL_ADDR, (REG_PL_RD(BT_RF_TXGAIN_MEM_CTRL_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)clktxgainsel << 9));
}

/**
 * @brief Returns the current value of the clk_txgain_en field in the TXGAIN_MEM_CTRL register.
 *
 * The TXGAIN_MEM_CTRL register will be read and the clk_txgain_en field's value will be returned.
 *
 * @return The current value of the clk_txgain_en field in the TXGAIN_MEM_CTRL register.
 */
__INLINE uint8_t bt_rf_clk_txgain_en_getf(void)
{
    uint32_t localVal = REG_PL_RD(BT_RF_TXGAIN_MEM_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000100)) >> 8);
}

/**
 * @brief Sets the clk_txgain_en field of the TXGAIN_MEM_CTRL register.
 *
 * The TXGAIN_MEM_CTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] clktxgainen - The value to set the field to.
 */
__INLINE void bt_rf_clk_txgain_en_setf(uint8_t clktxgainen)
{
    REG_PL_WR(BT_RF_TXGAIN_MEM_CTRL_ADDR, (REG_PL_RD(BT_RF_TXGAIN_MEM_CTRL_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)clktxgainen << 8));
}

/**
 * @brief Returns the current value of the txgain_mem_cfg field in the TXGAIN_MEM_CTRL register.
 *
 * The TXGAIN_MEM_CTRL register will be read and the txgain_mem_cfg field's value will be returned.
 *
 * @return The current value of the txgain_mem_cfg field in the TXGAIN_MEM_CTRL register.
 */
__INLINE uint8_t bt_rf_txgain_mem_cfg_getf(void)
{
    uint32_t localVal = REG_PL_RD(BT_RF_TXGAIN_MEM_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000080)) >> 7);
}

/**
 * @brief Sets the txgain_mem_cfg field of the TXGAIN_MEM_CTRL register.
 *
 * The TXGAIN_MEM_CTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] txgainmemcfg - The value to set the field to.
 */
__INLINE void bt_rf_txgain_mem_cfg_setf(uint8_t txgainmemcfg)
{
    REG_PL_WR(BT_RF_TXGAIN_MEM_CTRL_ADDR, (REG_PL_RD(BT_RF_TXGAIN_MEM_CTRL_ADDR) & ~((uint32_t)0x00000080)) | ((uint32_t)txgainmemcfg << 7));
}

/**
 * @brief Returns the current value of the txgain_mem_ren_pulse field in the TXGAIN_MEM_CTRL register.
 *
 * The TXGAIN_MEM_CTRL register will be read and the txgain_mem_ren_pulse field's value will be returned.
 *
 * @return The current value of the txgain_mem_ren_pulse field in the TXGAIN_MEM_CTRL register.
 */
__INLINE uint8_t bt_rf_txgain_mem_ren_pulse_getf(void)
{
    uint32_t localVal = REG_PL_RD(BT_RF_TXGAIN_MEM_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000040)) >> 6);
}

/**
 * @brief Sets the txgain_mem_ren_pulse field of the TXGAIN_MEM_CTRL register.
 *
 * The TXGAIN_MEM_CTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] txgainmemrenpulse - The value to set the field to.
 */
__INLINE void bt_rf_txgain_mem_ren_pulse_setf(uint8_t txgainmemrenpulse)
{
    REG_PL_WR(BT_RF_TXGAIN_MEM_CTRL_ADDR, (REG_PL_RD(BT_RF_TXGAIN_MEM_CTRL_ADDR) & ~((uint32_t)0x00000040)) | ((uint32_t)txgainmemrenpulse << 6));
}

/**
 * @brief Returns the current value of the txgain_mem_wen_pulse field in the TXGAIN_MEM_CTRL register.
 *
 * The TXGAIN_MEM_CTRL register will be read and the txgain_mem_wen_pulse field's value will be returned.
 *
 * @return The current value of the txgain_mem_wen_pulse field in the TXGAIN_MEM_CTRL register.
 */
__INLINE uint8_t bt_rf_txgain_mem_wen_pulse_getf(void)
{
    uint32_t localVal = REG_PL_RD(BT_RF_TXGAIN_MEM_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000020)) >> 5);
}

/**
 * @brief Sets the txgain_mem_wen_pulse field of the TXGAIN_MEM_CTRL register.
 *
 * The TXGAIN_MEM_CTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] txgainmemwenpulse - The value to set the field to.
 */
__INLINE void bt_rf_txgain_mem_wen_pulse_setf(uint8_t txgainmemwenpulse)
{
    REG_PL_WR(BT_RF_TXGAIN_MEM_CTRL_ADDR, (REG_PL_RD(BT_RF_TXGAIN_MEM_CTRL_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)txgainmemwenpulse << 5));
}

/**
 * @brief Returns the current value of the txgain_mem_addr_cfg field in the TXGAIN_MEM_CTRL register.
 *
 * The TXGAIN_MEM_CTRL register will be read and the txgain_mem_addr_cfg field's value will be returned.
 *
 * @return The current value of the txgain_mem_addr_cfg field in the TXGAIN_MEM_CTRL register.
 */
__INLINE uint8_t bt_rf_txgain_mem_addr_cfg_getf(void)
{
    uint32_t localVal = REG_PL_RD(BT_RF_TXGAIN_MEM_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x0000001F)) >> 0);
}

/**
 * @brief Sets the txgain_mem_addr_cfg field of the TXGAIN_MEM_CTRL register.
 *
 * The TXGAIN_MEM_CTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] txgainmemaddrcfg - The value to set the field to.
 */
__INLINE void bt_rf_txgain_mem_addr_cfg_setf(uint8_t txgainmemaddrcfg)
{
    REG_PL_WR(BT_RF_TXGAIN_MEM_CTRL_ADDR, (REG_PL_RD(BT_RF_TXGAIN_MEM_CTRL_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)txgainmemaddrcfg << 0));
}

/// @}

/**
 * @name TXGAIN_MEM_WD register definitions
 * <table>
 * <caption id="TXGAIN_MEM_WD_BF">TXGAIN_MEM_WD bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>31:00 <td>  txgain_mem_wdata <td>R <td>R/W <td>0x0
 * </table>
 *
 * @{
 */

/// Address of the TXGAIN_MEM_WD register
#define BT_RF_TXGAIN_MEM_WD_ADDR   0x40622068
/// Offset of the TXGAIN_MEM_WD register from the base address
#define BT_RF_TXGAIN_MEM_WD_OFFSET 0x00000068
/// Index of the TXGAIN_MEM_WD register
#define BT_RF_TXGAIN_MEM_WD_INDEX  0x0000001A
/// Reset value of the TXGAIN_MEM_WD register
#define BT_RF_TXGAIN_MEM_WD_RESET  0x00000000

/**
 * @brief Returns the current value of the TXGAIN_MEM_WD register.
 * The TXGAIN_MEM_WD register will be read and its value returned.
 * @return The current value of the TXGAIN_MEM_WD register.
 */
__INLINE uint32_t bt_rf_txgain_mem_wd_get(void)
{
    return REG_PL_RD(BT_RF_TXGAIN_MEM_WD_ADDR);
}

/**
 * @brief Sets the TXGAIN_MEM_WD register to a value.
 * The TXGAIN_MEM_WD register will be written.
 * @param value - The value to write.
 */
__INLINE void bt_rf_txgain_mem_wd_set(uint32_t value)
{
    REG_PL_WR(BT_RF_TXGAIN_MEM_WD_ADDR, value);
}

// field definitions
/// TXGAIN_MEM_WDATA field mask
#define BT_RF_TXGAIN_MEM_WDATA_MASK   ((uint32_t)0xFFFFFFFF)
/// TXGAIN_MEM_WDATA field LSB position
#define BT_RF_TXGAIN_MEM_WDATA_LSB    0
/// TXGAIN_MEM_WDATA field width
#define BT_RF_TXGAIN_MEM_WDATA_WIDTH  ((uint32_t)0x00000020)

/// TXGAIN_MEM_WDATA field reset value
#define BT_RF_TXGAIN_MEM_WDATA_RST    0x0

/**
 * @brief Returns the current value of the txgain_mem_wdata field in the TXGAIN_MEM_WD register.
 *
 * The TXGAIN_MEM_WD register will be read and the txgain_mem_wdata field's value will be returned.
 *
 * @return The current value of the txgain_mem_wdata field in the TXGAIN_MEM_WD register.
 */
__INLINE uint32_t bt_rf_txgain_mem_wdata_getf(void)
{
    uint32_t localVal = REG_PL_RD(BT_RF_TXGAIN_MEM_WD_ADDR);
    return (localVal >> 0);
}

/**
 * @brief Sets the txgain_mem_wdata field of the TXGAIN_MEM_WD register.
 *
 * The TXGAIN_MEM_WD register will be read, modified to contain the new field value, and written.
 *
 * @param[in] txgainmemwdata - The value to set the field to.
 */
__INLINE void bt_rf_txgain_mem_wdata_setf(uint32_t txgainmemwdata)
{
    REG_PL_WR(BT_RF_TXGAIN_MEM_WD_ADDR, (uint32_t)txgainmemwdata << 0);
}

/// @}

/**
 * @name TXGAIN_MEM_RD register definitions
 * <table>
 * <caption id="TXGAIN_MEM_RD_BF">TXGAIN_MEM_RD bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>31:00 <td>  txgain_mem_rdata <td>R <td>R/W <td>0x0
 * </table>
 *
 * @{
 */

/// Address of the TXGAIN_MEM_RD register
#define BT_RF_TXGAIN_MEM_RD_ADDR   0x4062206C
/// Offset of the TXGAIN_MEM_RD register from the base address
#define BT_RF_TXGAIN_MEM_RD_OFFSET 0x0000006C
/// Index of the TXGAIN_MEM_RD register
#define BT_RF_TXGAIN_MEM_RD_INDEX  0x0000001B
/// Reset value of the TXGAIN_MEM_RD register
#define BT_RF_TXGAIN_MEM_RD_RESET  0x00000000

/**
 * @brief Returns the current value of the TXGAIN_MEM_RD register.
 * The TXGAIN_MEM_RD register will be read and its value returned.
 * @return The current value of the TXGAIN_MEM_RD register.
 */
__INLINE uint32_t bt_rf_txgain_mem_rd_get(void)
{
    return REG_PL_RD(BT_RF_TXGAIN_MEM_RD_ADDR);
}

/**
 * @brief Sets the TXGAIN_MEM_RD register to a value.
 * The TXGAIN_MEM_RD register will be written.
 * @param value - The value to write.
 */
__INLINE void bt_rf_txgain_mem_rd_set(uint32_t value)
{
    REG_PL_WR(BT_RF_TXGAIN_MEM_RD_ADDR, value);
}

// field definitions
/// TXGAIN_MEM_RDATA field mask
#define BT_RF_TXGAIN_MEM_RDATA_MASK   ((uint32_t)0xFFFFFFFF)
/// TXGAIN_MEM_RDATA field LSB position
#define BT_RF_TXGAIN_MEM_RDATA_LSB    0
/// TXGAIN_MEM_RDATA field width
#define BT_RF_TXGAIN_MEM_RDATA_WIDTH  ((uint32_t)0x00000020)

/// TXGAIN_MEM_RDATA field reset value
#define BT_RF_TXGAIN_MEM_RDATA_RST    0x0

/**
 * @brief Returns the current value of the txgain_mem_rdata field in the TXGAIN_MEM_RD register.
 *
 * The TXGAIN_MEM_RD register will be read and the txgain_mem_rdata field's value will be returned.
 *
 * @return The current value of the txgain_mem_rdata field in the TXGAIN_MEM_RD register.
 */
__INLINE uint32_t bt_rf_txgain_mem_rdata_getf(void)
{
    uint32_t localVal = REG_PL_RD(BT_RF_TXGAIN_MEM_RD_ADDR);
    return (localVal >> 0);
}

/**
 * @brief Sets the txgain_mem_rdata field of the TXGAIN_MEM_RD register.
 *
 * The TXGAIN_MEM_RD register will be read, modified to contain the new field value, and written.
 *
 * @param[in] txgainmemrdata - The value to set the field to.
 */
__INLINE void bt_rf_txgain_mem_rdata_setf(uint32_t txgainmemrdata)
{
    REG_PL_WR(BT_RF_TXGAIN_MEM_RD_ADDR, (uint32_t)txgainmemrdata << 0);
}

/// @}


#endif // _REG_BT_RF_H_

/// @}

