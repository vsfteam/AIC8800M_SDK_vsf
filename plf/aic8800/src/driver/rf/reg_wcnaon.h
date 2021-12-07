/**
 * @file reg_wcnaon.h
 * @brief Definitions of the WCNAON HW block registers and register access functions.
 *
 * @defgroup REG_WCNAON REG_WCNAON
 * @ingroup REG
 * @{
 *
 * @brief Definitions of the WCNAON HW block registers and register access functions.
 */
#ifndef _REG_WCNAON_H_
#define _REG_WCNAON_H_

#include "compiler.h"
#include "arch.h"
#include "reg_access.h"

/** @brief Number of registers in the REG_WCNAON peripheral.
 */
#define REG_WCNAON_COUNT 73

/** @brief Decoding mask of the REG_WCNAON peripheral registers from the CPU point of view.
 */
#define REG_WCNAON_DECODING_MASK 0x000001FF

/**
 * @name BT_MEM_CFG1 register definitions
 * <table>
 * <caption id="BT_MEM_CFG1_BF">BT_MEM_CFG1 bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>20:17 <td>            bt_cfg <td>R <td>R/W <td>0x1
 * <tr><td>16 <td>      btfw_lp_mode <td>R <td>R/W <td>0
 * <tr><td>15:00 <td>        bt_mem_cfg <td>R <td>R/W <td>0x220
 * </table>
 *
 * @{
 */

/// Address of the BT_MEM_CFG1 register
#define WCNAON_BT_MEM_CFG1_ADDR   0x40580000
/// Offset of the BT_MEM_CFG1 register from the base address
#define WCNAON_BT_MEM_CFG1_OFFSET 0x00000000
/// Index of the BT_MEM_CFG1 register
#define WCNAON_BT_MEM_CFG1_INDEX  0x00000000
/// Reset value of the BT_MEM_CFG1 register
#define WCNAON_BT_MEM_CFG1_RESET  0x00020220

/**
 * @brief Returns the current value of the BT_MEM_CFG1 register.
 * The BT_MEM_CFG1 register will be read and its value returned.
 * @return The current value of the BT_MEM_CFG1 register.
 */
__INLINE uint32_t wcnaon_bt_mem_cfg1_get(void)
{
    return REG_PL_RD(WCNAON_BT_MEM_CFG1_ADDR);
}

/**
 * @brief Sets the BT_MEM_CFG1 register to a value.
 * The BT_MEM_CFG1 register will be written.
 * @param value - The value to write.
 */
__INLINE void wcnaon_bt_mem_cfg1_set(uint32_t value)
{
    REG_PL_WR(WCNAON_BT_MEM_CFG1_ADDR, value);
}

// field definitions
/// BT_CFG field mask
#define WCNAON_BT_CFG_MASK         ((uint32_t)0x001E0000)
/// BT_CFG field LSB position
#define WCNAON_BT_CFG_LSB          17
/// BT_CFG field width
#define WCNAON_BT_CFG_WIDTH        ((uint32_t)0x00000004)
/// BTFW_LP_MODE field bit
#define WCNAON_BTFW_LP_MODE_BIT    ((uint32_t)0x00010000)
/// BTFW_LP_MODE field position
#define WCNAON_BTFW_LP_MODE_POS    16
/// BT_MEM_CFG field mask
#define WCNAON_BT_MEM_CFG_MASK     ((uint32_t)0x0000FFFF)
/// BT_MEM_CFG field LSB position
#define WCNAON_BT_MEM_CFG_LSB      0
/// BT_MEM_CFG field width
#define WCNAON_BT_MEM_CFG_WIDTH    ((uint32_t)0x00000010)

/// BT_CFG field reset value
#define WCNAON_BT_CFG_RST          0x1
/// BTFW_LP_MODE field reset value
#define WCNAON_BTFW_LP_MODE_RST    0x0
/// BT_MEM_CFG field reset value
#define WCNAON_BT_MEM_CFG_RST      0x220

/**
 * @brief Constructs a value for the BT_MEM_CFG1 register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] btcfg - The value to use for the bt_cfg field.
 * @param[in] btfwlpmode - The value to use for the btfw_lp_mode field.
 * @param[in] btmemcfg - The value to use for the bt_mem_cfg field.
 */
__INLINE void wcnaon_bt_mem_cfg1_pack(uint8_t btcfg, uint8_t btfwlpmode, uint16_t btmemcfg)
{
    REG_PL_WR(WCNAON_BT_MEM_CFG1_ADDR,  ((uint32_t)btcfg << 17) | ((uint32_t)btfwlpmode << 16) | ((uint32_t)btmemcfg << 0));
}

/**
 * @brief Unpacks BT_MEM_CFG1's fields from current value of the BT_MEM_CFG1 register.
 *
 * Reads the BT_MEM_CFG1 register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] btcfg - Will be populated with the current value of this field from the register.
 * @param[out] btfwlpmode - Will be populated with the current value of this field from the register.
 * @param[out] btmemcfg - Will be populated with the current value of this field from the register.
 */
__INLINE void wcnaon_bt_mem_cfg1_unpack(uint8_t* btcfg, uint8_t* btfwlpmode, uint16_t* btmemcfg)
{
    uint32_t localVal = REG_PL_RD(WCNAON_BT_MEM_CFG1_ADDR);

    *btcfg = (localVal & ((uint32_t)0x001E0000)) >> 17;
    *btfwlpmode = (localVal & ((uint32_t)0x00010000)) >> 16;
    *btmemcfg = (localVal & ((uint32_t)0x0000FFFF)) >> 0;
}

/**
 * @brief Returns the current value of the bt_cfg field in the BT_MEM_CFG1 register.
 *
 * The BT_MEM_CFG1 register will be read and the bt_cfg field's value will be returned.
 *
 * @return The current value of the bt_cfg field in the BT_MEM_CFG1 register.
 */
__INLINE uint8_t wcnaon_bt_cfg_getf(void)
{
    uint32_t localVal = REG_PL_RD(WCNAON_BT_MEM_CFG1_ADDR);
    return ((localVal & ((uint32_t)0x001E0000)) >> 17);
}

/**
 * @brief Sets the bt_cfg field of the BT_MEM_CFG1 register.
 *
 * The BT_MEM_CFG1 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] btcfg - The value to set the field to.
 */
__INLINE void wcnaon_bt_cfg_setf(uint8_t btcfg)
{
    REG_PL_WR(WCNAON_BT_MEM_CFG1_ADDR, (REG_PL_RD(WCNAON_BT_MEM_CFG1_ADDR) & ~((uint32_t)0x001E0000)) | ((uint32_t)btcfg << 17));
}

/**
 * @brief Returns the current value of the btfw_lp_mode field in the BT_MEM_CFG1 register.
 *
 * The BT_MEM_CFG1 register will be read and the btfw_lp_mode field's value will be returned.
 *
 * @return The current value of the btfw_lp_mode field in the BT_MEM_CFG1 register.
 */
__INLINE uint8_t wcnaon_btfw_lp_mode_getf(void)
{
    uint32_t localVal = REG_PL_RD(WCNAON_BT_MEM_CFG1_ADDR);
    return ((localVal & ((uint32_t)0x00010000)) >> 16);
}

/**
 * @brief Sets the btfw_lp_mode field of the BT_MEM_CFG1 register.
 *
 * The BT_MEM_CFG1 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] btfwlpmode - The value to set the field to.
 */
__INLINE void wcnaon_btfw_lp_mode_setf(uint8_t btfwlpmode)
{
    REG_PL_WR(WCNAON_BT_MEM_CFG1_ADDR, (REG_PL_RD(WCNAON_BT_MEM_CFG1_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)btfwlpmode << 16));
}

/**
 * @brief Returns the current value of the bt_mem_cfg field in the BT_MEM_CFG1 register.
 *
 * The BT_MEM_CFG1 register will be read and the bt_mem_cfg field's value will be returned.
 *
 * @return The current value of the bt_mem_cfg field in the BT_MEM_CFG1 register.
 */
__INLINE uint16_t wcnaon_bt_mem_cfg_getf(void)
{
    uint32_t localVal = REG_PL_RD(WCNAON_BT_MEM_CFG1_ADDR);
    return ((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}

/**
 * @brief Sets the bt_mem_cfg field of the BT_MEM_CFG1 register.
 *
 * The BT_MEM_CFG1 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] btmemcfg - The value to set the field to.
 */
__INLINE void wcnaon_bt_mem_cfg_setf(uint16_t btmemcfg)
{
    REG_PL_WR(WCNAON_BT_MEM_CFG1_ADDR, (REG_PL_RD(WCNAON_BT_MEM_CFG1_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)btmemcfg << 0));
}

/// @}

/**
 * @name WIFI_MEM_CFG register definitions
 * <table>
 * <caption id="WIFI_MEM_CFG_BF">WIFI_MEM_CFG bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>15:00 <td>      wifi_mem_cfg <td>R <td>R/W <td>0x220
 * </table>
 *
 * @{
 */

/// Address of the WIFI_MEM_CFG register
#define WCNAON_WIFI_MEM_CFG_ADDR   0x40580004
/// Offset of the WIFI_MEM_CFG register from the base address
#define WCNAON_WIFI_MEM_CFG_OFFSET 0x00000004
/// Index of the WIFI_MEM_CFG register
#define WCNAON_WIFI_MEM_CFG_INDEX  0x00000001
/// Reset value of the WIFI_MEM_CFG register
#define WCNAON_WIFI_MEM_CFG_RESET  0x00000220

/**
 * @brief Returns the current value of the WIFI_MEM_CFG register.
 * The WIFI_MEM_CFG register will be read and its value returned.
 * @return The current value of the WIFI_MEM_CFG register.
 */
__INLINE uint32_t wcnaon_wifi_mem_cfg_get(void)
{
    return REG_PL_RD(WCNAON_WIFI_MEM_CFG_ADDR);
}

/**
 * @brief Sets the WIFI_MEM_CFG register to a value.
 * The WIFI_MEM_CFG register will be written.
 * @param value - The value to write.
 */
__INLINE void wcnaon_wifi_mem_cfg_set(uint32_t value)
{
    REG_PL_WR(WCNAON_WIFI_MEM_CFG_ADDR, value);
}

// field definitions
/// WIFI_MEM_CFG field mask
#define WCNAON_WIFI_MEM_CFG_MASK   ((uint32_t)0x0000FFFF)
/// WIFI_MEM_CFG field LSB position
#define WCNAON_WIFI_MEM_CFG_LSB    0
/// WIFI_MEM_CFG field width
#define WCNAON_WIFI_MEM_CFG_WIDTH  ((uint32_t)0x00000010)

/// WIFI_MEM_CFG field reset value
#define WCNAON_WIFI_MEM_CFG_RST    0x220

/**
 * @brief Returns the current value of the wifi_mem_cfg field in the WIFI_MEM_CFG register.
 *
 * The WIFI_MEM_CFG register will be read and the wifi_mem_cfg field's value will be returned.
 *
 * @return The current value of the wifi_mem_cfg field in the WIFI_MEM_CFG register.
 */
__INLINE uint16_t wcnaon_wifi_mem_cfg_getf(void)
{
    uint32_t localVal = REG_PL_RD(WCNAON_WIFI_MEM_CFG_ADDR);
    return (localVal >> 0);
}

/**
 * @brief Sets the wifi_mem_cfg field of the WIFI_MEM_CFG register.
 *
 * The WIFI_MEM_CFG register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wifimemcfg - The value to set the field to.
 */
__INLINE void wcnaon_wifi_mem_cfg_setf(uint16_t wifimemcfg)
{
    REG_PL_WR(WCNAON_WIFI_MEM_CFG_ADDR, (uint32_t)wifimemcfg << 0);
}

/// @}

/**
 * @name BT_CLK_CFG0 register definitions
 * <table>
 * <caption id="BT_CLK_CFG0_BF">BT_CLK_CFG0 bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>31 <td>     bt_div_num_ld <td>R <td>R/W <td>0
 * <tr><td>24:16 <td>          bt_div_M <td>R <td>R/W <td>0x1
 * <tr><td>15:00 <td>          bt_div_N <td>R <td>R/W <td>0x2
 * </table>
 *
 * @{
 */

/// Address of the BT_CLK_CFG0 register
#define WCNAON_BT_CLK_CFG0_ADDR   0x40580008
/// Offset of the BT_CLK_CFG0 register from the base address
#define WCNAON_BT_CLK_CFG0_OFFSET 0x00000008
/// Index of the BT_CLK_CFG0 register
#define WCNAON_BT_CLK_CFG0_INDEX  0x00000002
/// Reset value of the BT_CLK_CFG0 register
#define WCNAON_BT_CLK_CFG0_RESET  0x00010002

/**
 * @brief Returns the current value of the BT_CLK_CFG0 register.
 * The BT_CLK_CFG0 register will be read and its value returned.
 * @return The current value of the BT_CLK_CFG0 register.
 */
__INLINE uint32_t wcnaon_bt_clk_cfg0_get(void)
{
    return REG_PL_RD(WCNAON_BT_CLK_CFG0_ADDR);
}

/**
 * @brief Sets the BT_CLK_CFG0 register to a value.
 * The BT_CLK_CFG0 register will be written.
 * @param value - The value to write.
 */
__INLINE void wcnaon_bt_clk_cfg0_set(uint32_t value)
{
    REG_PL_WR(WCNAON_BT_CLK_CFG0_ADDR, value);
}

// field definitions
/// BT_DIV_NUM_LD field bit
#define WCNAON_BT_DIV_NUM_LD_BIT    ((uint32_t)0x80000000)
/// BT_DIV_NUM_LD field position
#define WCNAON_BT_DIV_NUM_LD_POS    31
/// BT_DIV_M field mask
#define WCNAON_BT_DIV_M_MASK        ((uint32_t)0x01FF0000)
/// BT_DIV_M field LSB position
#define WCNAON_BT_DIV_M_LSB         16
/// BT_DIV_M field width
#define WCNAON_BT_DIV_M_WIDTH       ((uint32_t)0x00000009)
/// BT_DIV_N field mask
#define WCNAON_BT_DIV_N_MASK        ((uint32_t)0x0000FFFF)
/// BT_DIV_N field LSB position
#define WCNAON_BT_DIV_N_LSB         0
/// BT_DIV_N field width
#define WCNAON_BT_DIV_N_WIDTH       ((uint32_t)0x00000010)

/// BT_DIV_NUM_LD field reset value
#define WCNAON_BT_DIV_NUM_LD_RST    0x0
/// BT_DIV_M field reset value
#define WCNAON_BT_DIV_M_RST         0x1
/// BT_DIV_N field reset value
#define WCNAON_BT_DIV_N_RST         0x2

/**
 * @brief Constructs a value for the BT_CLK_CFG0 register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] btdivnumld - The value to use for the bt_div_num_ld field.
 * @param[in] btdivm - The value to use for the bt_div_M field.
 * @param[in] btdivn - The value to use for the bt_div_N field.
 */
__INLINE void wcnaon_bt_clk_cfg0_pack(uint8_t btdivnumld, uint16_t btdivm, uint16_t btdivn)
{
    REG_PL_WR(WCNAON_BT_CLK_CFG0_ADDR,  ((uint32_t)btdivnumld << 31) | ((uint32_t)btdivm << 16) | ((uint32_t)btdivn << 0));
}

/**
 * @brief Unpacks BT_CLK_CFG0's fields from current value of the BT_CLK_CFG0 register.
 *
 * Reads the BT_CLK_CFG0 register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] btdivnumld - Will be populated with the current value of this field from the register.
 * @param[out] btdivm - Will be populated with the current value of this field from the register.
 * @param[out] btdivn - Will be populated with the current value of this field from the register.
 */
__INLINE void wcnaon_bt_clk_cfg0_unpack(uint8_t* btdivnumld, uint16_t* btdivm, uint16_t* btdivn)
{
    uint32_t localVal = REG_PL_RD(WCNAON_BT_CLK_CFG0_ADDR);

    *btdivnumld = (localVal & ((uint32_t)0x80000000)) >> 31;
    *btdivm = (localVal & ((uint32_t)0x01FF0000)) >> 16;
    *btdivn = (localVal & ((uint32_t)0x0000FFFF)) >> 0;
}

/**
 * @brief Returns the current value of the bt_div_num_ld field in the BT_CLK_CFG0 register.
 *
 * The BT_CLK_CFG0 register will be read and the bt_div_num_ld field's value will be returned.
 *
 * @return The current value of the bt_div_num_ld field in the BT_CLK_CFG0 register.
 */
__INLINE uint8_t wcnaon_bt_div_num_ld_getf(void)
{
    uint32_t localVal = REG_PL_RD(WCNAON_BT_CLK_CFG0_ADDR);
    return ((localVal & ((uint32_t)0x80000000)) >> 31);
}

/**
 * @brief Sets the bt_div_num_ld field of the BT_CLK_CFG0 register.
 *
 * The BT_CLK_CFG0 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] btdivnumld - The value to set the field to.
 */
__INLINE void wcnaon_bt_div_num_ld_setf(uint8_t btdivnumld)
{
    REG_PL_WR(WCNAON_BT_CLK_CFG0_ADDR, (REG_PL_RD(WCNAON_BT_CLK_CFG0_ADDR) & ~((uint32_t)0x80000000)) | ((uint32_t)btdivnumld << 31));
}

/**
 * @brief Returns the current value of the bt_div_M field in the BT_CLK_CFG0 register.
 *
 * The BT_CLK_CFG0 register will be read and the bt_div_M field's value will be returned.
 *
 * @return The current value of the bt_div_M field in the BT_CLK_CFG0 register.
 */
__INLINE uint16_t wcnaon_bt_div_m_getf(void)
{
    uint32_t localVal = REG_PL_RD(WCNAON_BT_CLK_CFG0_ADDR);
    return ((localVal & ((uint32_t)0x01FF0000)) >> 16);
}

/**
 * @brief Sets the bt_div_M field of the BT_CLK_CFG0 register.
 *
 * The BT_CLK_CFG0 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] btdivm - The value to set the field to.
 */
__INLINE void wcnaon_bt_div_m_setf(uint16_t btdivm)
{
    REG_PL_WR(WCNAON_BT_CLK_CFG0_ADDR, (REG_PL_RD(WCNAON_BT_CLK_CFG0_ADDR) & ~((uint32_t)0x01FF0000)) | ((uint32_t)btdivm << 16));
}

/**
 * @brief Returns the current value of the bt_div_N field in the BT_CLK_CFG0 register.
 *
 * The BT_CLK_CFG0 register will be read and the bt_div_N field's value will be returned.
 *
 * @return The current value of the bt_div_N field in the BT_CLK_CFG0 register.
 */
__INLINE uint16_t wcnaon_bt_div_n_getf(void)
{
    uint32_t localVal = REG_PL_RD(WCNAON_BT_CLK_CFG0_ADDR);
    return ((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}

/**
 * @brief Sets the bt_div_N field of the BT_CLK_CFG0 register.
 *
 * The BT_CLK_CFG0 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] btdivn - The value to set the field to.
 */
__INLINE void wcnaon_bt_div_n_setf(uint16_t btdivn)
{
    REG_PL_WR(WCNAON_BT_CLK_CFG0_ADDR, (REG_PL_RD(WCNAON_BT_CLK_CFG0_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)btdivn << 0));
}

/// @}

/**
 * @name BT_CLK_CFG1 register definitions
 * <table>
 * <caption id="BT_CLK_CFG1_BF">BT_CLK_CFG1 bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>29:24 <td>      bt_cfg_rfsel <td>R <td>R/W <td>0x0
 * <tr><td>22:16 <td>       bt_clkg_cfg <td>R <td>R/W <td>0x0
 * <tr><td>05:00 <td>         bt_clksel <td>R <td>R/W <td>0x0
 * </table>
 *
 * @{
 */

/// Address of the BT_CLK_CFG1 register
#define WCNAON_BT_CLK_CFG1_ADDR   0x4058000C
/// Offset of the BT_CLK_CFG1 register from the base address
#define WCNAON_BT_CLK_CFG1_OFFSET 0x0000000C
/// Index of the BT_CLK_CFG1 register
#define WCNAON_BT_CLK_CFG1_INDEX  0x00000003
/// Reset value of the BT_CLK_CFG1 register
#define WCNAON_BT_CLK_CFG1_RESET  0x00000000

/**
 * @brief Returns the current value of the BT_CLK_CFG1 register.
 * The BT_CLK_CFG1 register will be read and its value returned.
 * @return The current value of the BT_CLK_CFG1 register.
 */
__INLINE uint32_t wcnaon_bt_clk_cfg1_get(void)
{
    return REG_PL_RD(WCNAON_BT_CLK_CFG1_ADDR);
}

/**
 * @brief Sets the BT_CLK_CFG1 register to a value.
 * The BT_CLK_CFG1 register will be written.
 * @param value - The value to write.
 */
__INLINE void wcnaon_bt_clk_cfg1_set(uint32_t value)
{
    REG_PL_WR(WCNAON_BT_CLK_CFG1_ADDR, value);
}

// field definitions
/// BT_CFG_RFSEL field mask
#define WCNAON_BT_CFG_RFSEL_MASK   ((uint32_t)0x3F000000)
/// BT_CFG_RFSEL field LSB position
#define WCNAON_BT_CFG_RFSEL_LSB    24
/// BT_CFG_RFSEL field width
#define WCNAON_BT_CFG_RFSEL_WIDTH  ((uint32_t)0x00000006)
/// BT_CLKG_CFG field mask
#define WCNAON_BT_CLKG_CFG_MASK    ((uint32_t)0x007F0000)
/// BT_CLKG_CFG field LSB position
#define WCNAON_BT_CLKG_CFG_LSB     16
/// BT_CLKG_CFG field width
#define WCNAON_BT_CLKG_CFG_WIDTH   ((uint32_t)0x00000007)
/// BT_CLKSEL field mask
#define WCNAON_BT_CLKSEL_MASK      ((uint32_t)0x0000003F)
/// BT_CLKSEL field LSB position
#define WCNAON_BT_CLKSEL_LSB       0
/// BT_CLKSEL field width
#define WCNAON_BT_CLKSEL_WIDTH     ((uint32_t)0x00000006)

/// BT_CFG_RFSEL field reset value
#define WCNAON_BT_CFG_RFSEL_RST    0x0
/// BT_CLKG_CFG field reset value
#define WCNAON_BT_CLKG_CFG_RST     0x0
/// BT_CLKSEL field reset value
#define WCNAON_BT_CLKSEL_RST       0x0

/**
 * @brief Constructs a value for the BT_CLK_CFG1 register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] btcfgrfsel - The value to use for the bt_cfg_rfsel field.
 * @param[in] btclkgcfg - The value to use for the bt_clkg_cfg field.
 * @param[in] btclksel - The value to use for the bt_clksel field.
 */
__INLINE void wcnaon_bt_clk_cfg1_pack(uint8_t btcfgrfsel, uint8_t btclkgcfg, uint8_t btclksel)
{
    REG_PL_WR(WCNAON_BT_CLK_CFG1_ADDR,  ((uint32_t)btcfgrfsel << 24) | ((uint32_t)btclkgcfg << 16) | ((uint32_t)btclksel << 0));
}

/**
 * @brief Unpacks BT_CLK_CFG1's fields from current value of the BT_CLK_CFG1 register.
 *
 * Reads the BT_CLK_CFG1 register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] btcfgrfsel - Will be populated with the current value of this field from the register.
 * @param[out] btclkgcfg - Will be populated with the current value of this field from the register.
 * @param[out] btclksel - Will be populated with the current value of this field from the register.
 */
__INLINE void wcnaon_bt_clk_cfg1_unpack(uint8_t* btcfgrfsel, uint8_t* btclkgcfg, uint8_t* btclksel)
{
    uint32_t localVal = REG_PL_RD(WCNAON_BT_CLK_CFG1_ADDR);

    *btcfgrfsel = (localVal & ((uint32_t)0x3F000000)) >> 24;
    *btclkgcfg = (localVal & ((uint32_t)0x007F0000)) >> 16;
    *btclksel = (localVal & ((uint32_t)0x0000003F)) >> 0;
}

/**
 * @brief Returns the current value of the bt_cfg_rfsel field in the BT_CLK_CFG1 register.
 *
 * The BT_CLK_CFG1 register will be read and the bt_cfg_rfsel field's value will be returned.
 *
 * @return The current value of the bt_cfg_rfsel field in the BT_CLK_CFG1 register.
 */
__INLINE uint8_t wcnaon_bt_cfg_rfsel_getf(void)
{
    uint32_t localVal = REG_PL_RD(WCNAON_BT_CLK_CFG1_ADDR);
    return ((localVal & ((uint32_t)0x3F000000)) >> 24);
}

/**
 * @brief Sets the bt_cfg_rfsel field of the BT_CLK_CFG1 register.
 *
 * The BT_CLK_CFG1 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] btcfgrfsel - The value to set the field to.
 */
__INLINE void wcnaon_bt_cfg_rfsel_setf(uint8_t btcfgrfsel)
{
    REG_PL_WR(WCNAON_BT_CLK_CFG1_ADDR, (REG_PL_RD(WCNAON_BT_CLK_CFG1_ADDR) & ~((uint32_t)0x3F000000)) | ((uint32_t)btcfgrfsel << 24));
}

/**
 * @brief Returns the current value of the bt_clkg_cfg field in the BT_CLK_CFG1 register.
 *
 * The BT_CLK_CFG1 register will be read and the bt_clkg_cfg field's value will be returned.
 *
 * @return The current value of the bt_clkg_cfg field in the BT_CLK_CFG1 register.
 */
__INLINE uint8_t wcnaon_bt_clkg_cfg_getf(void)
{
    uint32_t localVal = REG_PL_RD(WCNAON_BT_CLK_CFG1_ADDR);
    return ((localVal & ((uint32_t)0x007F0000)) >> 16);
}

/**
 * @brief Sets the bt_clkg_cfg field of the BT_CLK_CFG1 register.
 *
 * The BT_CLK_CFG1 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] btclkgcfg - The value to set the field to.
 */
__INLINE void wcnaon_bt_clkg_cfg_setf(uint8_t btclkgcfg)
{
    REG_PL_WR(WCNAON_BT_CLK_CFG1_ADDR, (REG_PL_RD(WCNAON_BT_CLK_CFG1_ADDR) & ~((uint32_t)0x007F0000)) | ((uint32_t)btclkgcfg << 16));
}

/**
 * @brief Returns the current value of the bt_clksel field in the BT_CLK_CFG1 register.
 *
 * The BT_CLK_CFG1 register will be read and the bt_clksel field's value will be returned.
 *
 * @return The current value of the bt_clksel field in the BT_CLK_CFG1 register.
 */
__INLINE uint8_t wcnaon_bt_clksel_getf(void)
{
    uint32_t localVal = REG_PL_RD(WCNAON_BT_CLK_CFG1_ADDR);
    return ((localVal & ((uint32_t)0x0000003F)) >> 0);
}

/**
 * @brief Sets the bt_clksel field of the BT_CLK_CFG1 register.
 *
 * The BT_CLK_CFG1 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] btclksel - The value to set the field to.
 */
__INLINE void wcnaon_bt_clksel_setf(uint8_t btclksel)
{
    REG_PL_WR(WCNAON_BT_CLK_CFG1_ADDR, (REG_PL_RD(WCNAON_BT_CLK_CFG1_ADDR) & ~((uint32_t)0x0000003F)) | ((uint32_t)btclksel << 0));
}

/// @}

/**
 * @name WIFI_SOFT_WAKEUP_REQ register definitions
 * <table>
 * <caption id="WIFI_SOFT_WAKEUP_REQ_BF">WIFI_SOFT_WAKEUP_REQ bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>11 <td>  bt_wakeup_lp_sel <td>R <td>R/W <td>0
 * <tr><td>10 <td>wlan_wakeup_lp_sel <td>R <td>R/W <td>0
 * <tr><td>09 <td>   bt_cfg_power_en <td>R <td>R/W <td>0
 * <tr><td>08 <td>     bt_cfg_cpu_en <td>R <td>R/W <td>1
 * <tr><td>06:05 <td>           mon_sel <td>R <td>R/W <td>0x0
 * <tr><td>04 <td>wlan_radio_cg_sleep_en <td>R <td>R/W <td>0
 * <tr><td>03 <td>wlan_cpu_wakeup_en <td>R <td>R/W <td>0
 * <tr><td>02 <td>wlan_radio_sleep_en <td>R <td>R/W <td>0
 * <tr><td>01 <td>wlan_power_sleep_en <td>R <td>R/W <td>0
 * <tr><td>00 <td>wlan_soft_wakeup_req <td>R <td>R/W <td>0
 * </table>
 *
 * @{
 */

/// Address of the WIFI_SOFT_WAKEUP_REQ register
#define WCNAON_WIFI_SOFT_WAKEUP_REQ_ADDR   0x40580010
/// Offset of the WIFI_SOFT_WAKEUP_REQ register from the base address
#define WCNAON_WIFI_SOFT_WAKEUP_REQ_OFFSET 0x00000010
/// Index of the WIFI_SOFT_WAKEUP_REQ register
#define WCNAON_WIFI_SOFT_WAKEUP_REQ_INDEX  0x00000004
/// Reset value of the WIFI_SOFT_WAKEUP_REQ register
#define WCNAON_WIFI_SOFT_WAKEUP_REQ_RESET  0x00000100

/**
 * @brief Returns the current value of the WIFI_SOFT_WAKEUP_REQ register.
 * The WIFI_SOFT_WAKEUP_REQ register will be read and its value returned.
 * @return The current value of the WIFI_SOFT_WAKEUP_REQ register.
 */
__INLINE uint32_t wcnaon_wifi_soft_wakeup_req_get(void)
{
    return REG_PL_RD(WCNAON_WIFI_SOFT_WAKEUP_REQ_ADDR);
}

/**
 * @brief Sets the WIFI_SOFT_WAKEUP_REQ register to a value.
 * The WIFI_SOFT_WAKEUP_REQ register will be written.
 * @param value - The value to write.
 */
__INLINE void wcnaon_wifi_soft_wakeup_req_set(uint32_t value)
{
    REG_PL_WR(WCNAON_WIFI_SOFT_WAKEUP_REQ_ADDR, value);
}

// field definitions
/// BT_WAKEUP_LP_SEL field bit
#define WCNAON_BT_WAKEUP_LP_SEL_BIT          ((uint32_t)0x00000800)
/// BT_WAKEUP_LP_SEL field position
#define WCNAON_BT_WAKEUP_LP_SEL_POS          11
/// WLAN_WAKEUP_LP_SEL field bit
#define WCNAON_WLAN_WAKEUP_LP_SEL_BIT        ((uint32_t)0x00000400)
/// WLAN_WAKEUP_LP_SEL field position
#define WCNAON_WLAN_WAKEUP_LP_SEL_POS        10
/// BT_CFG_POWER_EN field bit
#define WCNAON_BT_CFG_POWER_EN_BIT           ((uint32_t)0x00000200)
/// BT_CFG_POWER_EN field position
#define WCNAON_BT_CFG_POWER_EN_POS           9
/// BT_CFG_CPU_EN field bit
#define WCNAON_BT_CFG_CPU_EN_BIT             ((uint32_t)0x00000100)
/// BT_CFG_CPU_EN field position
#define WCNAON_BT_CFG_CPU_EN_POS             8
/// MON_SEL field mask
#define WCNAON_MON_SEL_MASK                  ((uint32_t)0x00000060)
/// MON_SEL field LSB position
#define WCNAON_MON_SEL_LSB                   5
/// MON_SEL field width
#define WCNAON_MON_SEL_WIDTH                 ((uint32_t)0x00000002)
/// WLAN_RADIO_CG_SLEEP_EN field bit
#define WCNAON_WLAN_RADIO_CG_SLEEP_EN_BIT    ((uint32_t)0x00000010)
/// WLAN_RADIO_CG_SLEEP_EN field position
#define WCNAON_WLAN_RADIO_CG_SLEEP_EN_POS    4
/// WLAN_CPU_WAKEUP_EN field bit
#define WCNAON_WLAN_CPU_WAKEUP_EN_BIT        ((uint32_t)0x00000008)
/// WLAN_CPU_WAKEUP_EN field position
#define WCNAON_WLAN_CPU_WAKEUP_EN_POS        3
/// WLAN_RADIO_SLEEP_EN field bit
#define WCNAON_WLAN_RADIO_SLEEP_EN_BIT       ((uint32_t)0x00000004)
/// WLAN_RADIO_SLEEP_EN field position
#define WCNAON_WLAN_RADIO_SLEEP_EN_POS       2
/// WLAN_POWER_SLEEP_EN field bit
#define WCNAON_WLAN_POWER_SLEEP_EN_BIT       ((uint32_t)0x00000002)
/// WLAN_POWER_SLEEP_EN field position
#define WCNAON_WLAN_POWER_SLEEP_EN_POS       1
/// WLAN_SOFT_WAKEUP_REQ field bit
#define WCNAON_WLAN_SOFT_WAKEUP_REQ_BIT      ((uint32_t)0x00000001)
/// WLAN_SOFT_WAKEUP_REQ field position
#define WCNAON_WLAN_SOFT_WAKEUP_REQ_POS      0

/// BT_WAKEUP_LP_SEL field reset value
#define WCNAON_BT_WAKEUP_LP_SEL_RST          0x0
/// WLAN_WAKEUP_LP_SEL field reset value
#define WCNAON_WLAN_WAKEUP_LP_SEL_RST        0x0
/// BT_CFG_POWER_EN field reset value
#define WCNAON_BT_CFG_POWER_EN_RST           0x0
/// BT_CFG_CPU_EN field reset value
#define WCNAON_BT_CFG_CPU_EN_RST             0x1
/// MON_SEL field reset value
#define WCNAON_MON_SEL_RST                   0x0
/// WLAN_RADIO_CG_SLEEP_EN field reset value
#define WCNAON_WLAN_RADIO_CG_SLEEP_EN_RST    0x0
/// WLAN_CPU_WAKEUP_EN field reset value
#define WCNAON_WLAN_CPU_WAKEUP_EN_RST        0x0
/// WLAN_RADIO_SLEEP_EN field reset value
#define WCNAON_WLAN_RADIO_SLEEP_EN_RST       0x0
/// WLAN_POWER_SLEEP_EN field reset value
#define WCNAON_WLAN_POWER_SLEEP_EN_RST       0x0
/// WLAN_SOFT_WAKEUP_REQ field reset value
#define WCNAON_WLAN_SOFT_WAKEUP_REQ_RST      0x0

/**
 * @brief Constructs a value for the WIFI_SOFT_WAKEUP_REQ register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] btwakeuplpsel - The value to use for the bt_wakeup_lp_sel field.
 * @param[in] wlanwakeuplpsel - The value to use for the wlan_wakeup_lp_sel field.
 * @param[in] btcfgpoweren - The value to use for the bt_cfg_power_en field.
 * @param[in] btcfgcpuen - The value to use for the bt_cfg_cpu_en field.
 * @param[in] monsel - The value to use for the mon_sel field.
 * @param[in] wlanradiocgsleepen - The value to use for the wlan_radio_cg_sleep_en field.
 * @param[in] wlancpuwakeupen - The value to use for the wlan_cpu_wakeup_en field.
 * @param[in] wlanradiosleepen - The value to use for the wlan_radio_sleep_en field.
 * @param[in] wlanpowersleepen - The value to use for the wlan_power_sleep_en field.
 * @param[in] wlansoftwakeupreq - The value to use for the wlan_soft_wakeup_req field.
 */
__INLINE void wcnaon_wifi_soft_wakeup_req_pack(uint8_t btwakeuplpsel, uint8_t wlanwakeuplpsel, uint8_t btcfgpoweren, uint8_t btcfgcpuen, uint8_t monsel, uint8_t wlanradiocgsleepen, uint8_t wlancpuwakeupen, uint8_t wlanradiosleepen, uint8_t wlanpowersleepen, uint8_t wlansoftwakeupreq)
{
    REG_PL_WR(WCNAON_WIFI_SOFT_WAKEUP_REQ_ADDR,  ((uint32_t)btwakeuplpsel << 11) | ((uint32_t)wlanwakeuplpsel << 10) | ((uint32_t)btcfgpoweren << 9) | ((uint32_t)btcfgcpuen << 8) | ((uint32_t)monsel << 5) | ((uint32_t)wlanradiocgsleepen << 4) | ((uint32_t)wlancpuwakeupen << 3) | ((uint32_t)wlanradiosleepen << 2) | ((uint32_t)wlanpowersleepen << 1) | ((uint32_t)wlansoftwakeupreq << 0));
}

/**
 * @brief Unpacks WIFI_SOFT_WAKEUP_REQ's fields from current value of the WIFI_SOFT_WAKEUP_REQ register.
 *
 * Reads the WIFI_SOFT_WAKEUP_REQ register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] btwakeuplpsel - Will be populated with the current value of this field from the register.
 * @param[out] wlanwakeuplpsel - Will be populated with the current value of this field from the register.
 * @param[out] btcfgpoweren - Will be populated with the current value of this field from the register.
 * @param[out] btcfgcpuen - Will be populated with the current value of this field from the register.
 * @param[out] monsel - Will be populated with the current value of this field from the register.
 * @param[out] wlanradiocgsleepen - Will be populated with the current value of this field from the register.
 * @param[out] wlancpuwakeupen - Will be populated with the current value of this field from the register.
 * @param[out] wlanradiosleepen - Will be populated with the current value of this field from the register.
 * @param[out] wlanpowersleepen - Will be populated with the current value of this field from the register.
 * @param[out] wlansoftwakeupreq - Will be populated with the current value of this field from the register.
 */
__INLINE void wcnaon_wifi_soft_wakeup_req_unpack(uint8_t* btwakeuplpsel, uint8_t* wlanwakeuplpsel, uint8_t* btcfgpoweren, uint8_t* btcfgcpuen, uint8_t* monsel, uint8_t* wlanradiocgsleepen, uint8_t* wlancpuwakeupen, uint8_t* wlanradiosleepen, uint8_t* wlanpowersleepen, uint8_t* wlansoftwakeupreq)
{
    uint32_t localVal = REG_PL_RD(WCNAON_WIFI_SOFT_WAKEUP_REQ_ADDR);

    *btwakeuplpsel = (localVal & ((uint32_t)0x00000800)) >> 11;
    *wlanwakeuplpsel = (localVal & ((uint32_t)0x00000400)) >> 10;
    *btcfgpoweren = (localVal & ((uint32_t)0x00000200)) >> 9;
    *btcfgcpuen = (localVal & ((uint32_t)0x00000100)) >> 8;
    *monsel = (localVal & ((uint32_t)0x00000060)) >> 5;
    *wlanradiocgsleepen = (localVal & ((uint32_t)0x00000010)) >> 4;
    *wlancpuwakeupen = (localVal & ((uint32_t)0x00000008)) >> 3;
    *wlanradiosleepen = (localVal & ((uint32_t)0x00000004)) >> 2;
    *wlanpowersleepen = (localVal & ((uint32_t)0x00000002)) >> 1;
    *wlansoftwakeupreq = (localVal & ((uint32_t)0x00000001)) >> 0;
}

/**
 * @brief Returns the current value of the bt_wakeup_lp_sel field in the WIFI_SOFT_WAKEUP_REQ register.
 *
 * The WIFI_SOFT_WAKEUP_REQ register will be read and the bt_wakeup_lp_sel field's value will be returned.
 *
 * @return The current value of the bt_wakeup_lp_sel field in the WIFI_SOFT_WAKEUP_REQ register.
 */
__INLINE uint8_t wcnaon_bt_wakeup_lp_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(WCNAON_WIFI_SOFT_WAKEUP_REQ_ADDR);
    return ((localVal & ((uint32_t)0x00000800)) >> 11);
}

/**
 * @brief Sets the bt_wakeup_lp_sel field of the WIFI_SOFT_WAKEUP_REQ register.
 *
 * The WIFI_SOFT_WAKEUP_REQ register will be read, modified to contain the new field value, and written.
 *
 * @param[in] btwakeuplpsel - The value to set the field to.
 */
__INLINE void wcnaon_bt_wakeup_lp_sel_setf(uint8_t btwakeuplpsel)
{
    REG_PL_WR(WCNAON_WIFI_SOFT_WAKEUP_REQ_ADDR, (REG_PL_RD(WCNAON_WIFI_SOFT_WAKEUP_REQ_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)btwakeuplpsel << 11));
}

/**
 * @brief Returns the current value of the wlan_wakeup_lp_sel field in the WIFI_SOFT_WAKEUP_REQ register.
 *
 * The WIFI_SOFT_WAKEUP_REQ register will be read and the wlan_wakeup_lp_sel field's value will be returned.
 *
 * @return The current value of the wlan_wakeup_lp_sel field in the WIFI_SOFT_WAKEUP_REQ register.
 */
__INLINE uint8_t wcnaon_wlan_wakeup_lp_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(WCNAON_WIFI_SOFT_WAKEUP_REQ_ADDR);
    return ((localVal & ((uint32_t)0x00000400)) >> 10);
}

/**
 * @brief Sets the wlan_wakeup_lp_sel field of the WIFI_SOFT_WAKEUP_REQ register.
 *
 * The WIFI_SOFT_WAKEUP_REQ register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wlanwakeuplpsel - The value to set the field to.
 */
__INLINE void wcnaon_wlan_wakeup_lp_sel_setf(uint8_t wlanwakeuplpsel)
{
    REG_PL_WR(WCNAON_WIFI_SOFT_WAKEUP_REQ_ADDR, (REG_PL_RD(WCNAON_WIFI_SOFT_WAKEUP_REQ_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)wlanwakeuplpsel << 10));
}

/**
 * @brief Returns the current value of the bt_cfg_power_en field in the WIFI_SOFT_WAKEUP_REQ register.
 *
 * The WIFI_SOFT_WAKEUP_REQ register will be read and the bt_cfg_power_en field's value will be returned.
 *
 * @return The current value of the bt_cfg_power_en field in the WIFI_SOFT_WAKEUP_REQ register.
 */
__INLINE uint8_t wcnaon_bt_cfg_power_en_getf(void)
{
    uint32_t localVal = REG_PL_RD(WCNAON_WIFI_SOFT_WAKEUP_REQ_ADDR);
    return ((localVal & ((uint32_t)0x00000200)) >> 9);
}

/**
 * @brief Sets the bt_cfg_power_en field of the WIFI_SOFT_WAKEUP_REQ register.
 *
 * The WIFI_SOFT_WAKEUP_REQ register will be read, modified to contain the new field value, and written.
 *
 * @param[in] btcfgpoweren - The value to set the field to.
 */
__INLINE void wcnaon_bt_cfg_power_en_setf(uint8_t btcfgpoweren)
{
    REG_PL_WR(WCNAON_WIFI_SOFT_WAKEUP_REQ_ADDR, (REG_PL_RD(WCNAON_WIFI_SOFT_WAKEUP_REQ_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)btcfgpoweren << 9));
}

/**
 * @brief Returns the current value of the bt_cfg_cpu_en field in the WIFI_SOFT_WAKEUP_REQ register.
 *
 * The WIFI_SOFT_WAKEUP_REQ register will be read and the bt_cfg_cpu_en field's value will be returned.
 *
 * @return The current value of the bt_cfg_cpu_en field in the WIFI_SOFT_WAKEUP_REQ register.
 */
__INLINE uint8_t wcnaon_bt_cfg_cpu_en_getf(void)
{
    uint32_t localVal = REG_PL_RD(WCNAON_WIFI_SOFT_WAKEUP_REQ_ADDR);
    return ((localVal & ((uint32_t)0x00000100)) >> 8);
}

/**
 * @brief Sets the bt_cfg_cpu_en field of the WIFI_SOFT_WAKEUP_REQ register.
 *
 * The WIFI_SOFT_WAKEUP_REQ register will be read, modified to contain the new field value, and written.
 *
 * @param[in] btcfgcpuen - The value to set the field to.
 */
__INLINE void wcnaon_bt_cfg_cpu_en_setf(uint8_t btcfgcpuen)
{
    REG_PL_WR(WCNAON_WIFI_SOFT_WAKEUP_REQ_ADDR, (REG_PL_RD(WCNAON_WIFI_SOFT_WAKEUP_REQ_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)btcfgcpuen << 8));
}

/**
 * @brief Returns the current value of the mon_sel field in the WIFI_SOFT_WAKEUP_REQ register.
 *
 * The WIFI_SOFT_WAKEUP_REQ register will be read and the mon_sel field's value will be returned.
 *
 * @return The current value of the mon_sel field in the WIFI_SOFT_WAKEUP_REQ register.
 */
__INLINE uint8_t wcnaon_mon_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(WCNAON_WIFI_SOFT_WAKEUP_REQ_ADDR);
    return ((localVal & ((uint32_t)0x00000060)) >> 5);
}

/**
 * @brief Sets the mon_sel field of the WIFI_SOFT_WAKEUP_REQ register.
 *
 * The WIFI_SOFT_WAKEUP_REQ register will be read, modified to contain the new field value, and written.
 *
 * @param[in] monsel - The value to set the field to.
 */
__INLINE void wcnaon_mon_sel_setf(uint8_t monsel)
{
    REG_PL_WR(WCNAON_WIFI_SOFT_WAKEUP_REQ_ADDR, (REG_PL_RD(WCNAON_WIFI_SOFT_WAKEUP_REQ_ADDR) & ~((uint32_t)0x00000060)) | ((uint32_t)monsel << 5));
}

/**
 * @brief Returns the current value of the wlan_radio_cg_sleep_en field in the WIFI_SOFT_WAKEUP_REQ register.
 *
 * The WIFI_SOFT_WAKEUP_REQ register will be read and the wlan_radio_cg_sleep_en field's value will be returned.
 *
 * @return The current value of the wlan_radio_cg_sleep_en field in the WIFI_SOFT_WAKEUP_REQ register.
 */
__INLINE uint8_t wcnaon_wlan_radio_cg_sleep_en_getf(void)
{
    uint32_t localVal = REG_PL_RD(WCNAON_WIFI_SOFT_WAKEUP_REQ_ADDR);
    return ((localVal & ((uint32_t)0x00000010)) >> 4);
}

/**
 * @brief Sets the wlan_radio_cg_sleep_en field of the WIFI_SOFT_WAKEUP_REQ register.
 *
 * The WIFI_SOFT_WAKEUP_REQ register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wlanradiocgsleepen - The value to set the field to.
 */
__INLINE void wcnaon_wlan_radio_cg_sleep_en_setf(uint8_t wlanradiocgsleepen)
{
    REG_PL_WR(WCNAON_WIFI_SOFT_WAKEUP_REQ_ADDR, (REG_PL_RD(WCNAON_WIFI_SOFT_WAKEUP_REQ_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)wlanradiocgsleepen << 4));
}

/**
 * @brief Returns the current value of the wlan_cpu_wakeup_en field in the WIFI_SOFT_WAKEUP_REQ register.
 *
 * The WIFI_SOFT_WAKEUP_REQ register will be read and the wlan_cpu_wakeup_en field's value will be returned.
 *
 * @return The current value of the wlan_cpu_wakeup_en field in the WIFI_SOFT_WAKEUP_REQ register.
 */
__INLINE uint8_t wcnaon_wlan_cpu_wakeup_en_getf(void)
{
    uint32_t localVal = REG_PL_RD(WCNAON_WIFI_SOFT_WAKEUP_REQ_ADDR);
    return ((localVal & ((uint32_t)0x00000008)) >> 3);
}

/**
 * @brief Sets the wlan_cpu_wakeup_en field of the WIFI_SOFT_WAKEUP_REQ register.
 *
 * The WIFI_SOFT_WAKEUP_REQ register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wlancpuwakeupen - The value to set the field to.
 */
__INLINE void wcnaon_wlan_cpu_wakeup_en_setf(uint8_t wlancpuwakeupen)
{
    REG_PL_WR(WCNAON_WIFI_SOFT_WAKEUP_REQ_ADDR, (REG_PL_RD(WCNAON_WIFI_SOFT_WAKEUP_REQ_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)wlancpuwakeupen << 3));
}

/**
 * @brief Returns the current value of the wlan_radio_sleep_en field in the WIFI_SOFT_WAKEUP_REQ register.
 *
 * The WIFI_SOFT_WAKEUP_REQ register will be read and the wlan_radio_sleep_en field's value will be returned.
 *
 * @return The current value of the wlan_radio_sleep_en field in the WIFI_SOFT_WAKEUP_REQ register.
 */
__INLINE uint8_t wcnaon_wlan_radio_sleep_en_getf(void)
{
    uint32_t localVal = REG_PL_RD(WCNAON_WIFI_SOFT_WAKEUP_REQ_ADDR);
    return ((localVal & ((uint32_t)0x00000004)) >> 2);
}

/**
 * @brief Sets the wlan_radio_sleep_en field of the WIFI_SOFT_WAKEUP_REQ register.
 *
 * The WIFI_SOFT_WAKEUP_REQ register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wlanradiosleepen - The value to set the field to.
 */
__INLINE void wcnaon_wlan_radio_sleep_en_setf(uint8_t wlanradiosleepen)
{
    REG_PL_WR(WCNAON_WIFI_SOFT_WAKEUP_REQ_ADDR, (REG_PL_RD(WCNAON_WIFI_SOFT_WAKEUP_REQ_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)wlanradiosleepen << 2));
}

/**
 * @brief Returns the current value of the wlan_power_sleep_en field in the WIFI_SOFT_WAKEUP_REQ register.
 *
 * The WIFI_SOFT_WAKEUP_REQ register will be read and the wlan_power_sleep_en field's value will be returned.
 *
 * @return The current value of the wlan_power_sleep_en field in the WIFI_SOFT_WAKEUP_REQ register.
 */
__INLINE uint8_t wcnaon_wlan_power_sleep_en_getf(void)
{
    uint32_t localVal = REG_PL_RD(WCNAON_WIFI_SOFT_WAKEUP_REQ_ADDR);
    return ((localVal & ((uint32_t)0x00000002)) >> 1);
}

/**
 * @brief Sets the wlan_power_sleep_en field of the WIFI_SOFT_WAKEUP_REQ register.
 *
 * The WIFI_SOFT_WAKEUP_REQ register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wlanpowersleepen - The value to set the field to.
 */
__INLINE void wcnaon_wlan_power_sleep_en_setf(uint8_t wlanpowersleepen)
{
    REG_PL_WR(WCNAON_WIFI_SOFT_WAKEUP_REQ_ADDR, (REG_PL_RD(WCNAON_WIFI_SOFT_WAKEUP_REQ_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)wlanpowersleepen << 1));
}

/**
 * @brief Returns the current value of the wlan_soft_wakeup_req field in the WIFI_SOFT_WAKEUP_REQ register.
 *
 * The WIFI_SOFT_WAKEUP_REQ register will be read and the wlan_soft_wakeup_req field's value will be returned.
 *
 * @return The current value of the wlan_soft_wakeup_req field in the WIFI_SOFT_WAKEUP_REQ register.
 */
__INLINE uint8_t wcnaon_wlan_soft_wakeup_req_getf(void)
{
    uint32_t localVal = REG_PL_RD(WCNAON_WIFI_SOFT_WAKEUP_REQ_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief Sets the wlan_soft_wakeup_req field of the WIFI_SOFT_WAKEUP_REQ register.
 *
 * The WIFI_SOFT_WAKEUP_REQ register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wlansoftwakeupreq - The value to set the field to.
 */
__INLINE void wcnaon_wlan_soft_wakeup_req_setf(uint8_t wlansoftwakeupreq)
{
    REG_PL_WR(WCNAON_WIFI_SOFT_WAKEUP_REQ_ADDR, (REG_PL_RD(WCNAON_WIFI_SOFT_WAKEUP_REQ_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)wlansoftwakeupreq << 0));
}

/// @}

/**
 * @name WIFI_WAKEUP_DELAY_TIMER register definitions
 * <table>
 * <caption id="WIFI_WAKEUP_DELAY_TIMER_BF">WIFI_WAKEUP_DELAY_TIMER bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>31:22 <td>         wlan_twrm <td>R <td>W <td>0x0
 * <tr><td>21:11 <td>        wlan_twpwr <td>R <td>W <td>0x0
 * <tr><td>10:00 <td>        wlan_twext <td>R <td>W <td>0x0
 * </table>
 *
 * @{
 */

/// Address of the WIFI_WAKEUP_DELAY_TIMER register
#define WCNAON_WIFI_WAKEUP_DELAY_TIMER_ADDR   0x40580014
/// Offset of the WIFI_WAKEUP_DELAY_TIMER register from the base address
#define WCNAON_WIFI_WAKEUP_DELAY_TIMER_OFFSET 0x00000014
/// Index of the WIFI_WAKEUP_DELAY_TIMER register
#define WCNAON_WIFI_WAKEUP_DELAY_TIMER_INDEX  0x00000005
/// Reset value of the WIFI_WAKEUP_DELAY_TIMER register
#define WCNAON_WIFI_WAKEUP_DELAY_TIMER_RESET  0x00000000

/**
 * @brief Sets the WIFI_WAKEUP_DELAY_TIMER register to a value.
 * The WIFI_WAKEUP_DELAY_TIMER register will be written.
 * @param value - The value to write.
 */
__INLINE void wcnaon_wifi_wakeup_delay_timer_set(uint32_t value)
{
    REG_PL_WR(WCNAON_WIFI_WAKEUP_DELAY_TIMER_ADDR, value);
}

// field definitions
/// WLAN_TWRM field mask
#define WCNAON_WLAN_TWRM_MASK    ((uint32_t)0xFFC00000)
/// WLAN_TWRM field LSB position
#define WCNAON_WLAN_TWRM_LSB     22
/// WLAN_TWRM field width
#define WCNAON_WLAN_TWRM_WIDTH   ((uint32_t)0x0000000A)
/// WLAN_TWPWR field mask
#define WCNAON_WLAN_TWPWR_MASK   ((uint32_t)0x003FF800)
/// WLAN_TWPWR field LSB position
#define WCNAON_WLAN_TWPWR_LSB    11
/// WLAN_TWPWR field width
#define WCNAON_WLAN_TWPWR_WIDTH  ((uint32_t)0x0000000B)
/// WLAN_TWEXT field mask
#define WCNAON_WLAN_TWEXT_MASK   ((uint32_t)0x000007FF)
/// WLAN_TWEXT field LSB position
#define WCNAON_WLAN_TWEXT_LSB    0
/// WLAN_TWEXT field width
#define WCNAON_WLAN_TWEXT_WIDTH  ((uint32_t)0x0000000B)

/// WLAN_TWRM field reset value
#define WCNAON_WLAN_TWRM_RST     0x0
/// WLAN_TWPWR field reset value
#define WCNAON_WLAN_TWPWR_RST    0x0
/// WLAN_TWEXT field reset value
#define WCNAON_WLAN_TWEXT_RST    0x0

/**
 * @brief Constructs a value for the WIFI_WAKEUP_DELAY_TIMER register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] wlantwrm - The value to use for the wlan_twrm field.
 * @param[in] wlantwpwr - The value to use for the wlan_twpwr field.
 * @param[in] wlantwext - The value to use for the wlan_twext field.
 */
__INLINE void wcnaon_wifi_wakeup_delay_timer_pack(uint16_t wlantwrm, uint16_t wlantwpwr, uint16_t wlantwext)
{
    REG_PL_WR(WCNAON_WIFI_WAKEUP_DELAY_TIMER_ADDR,  ((uint32_t)wlantwrm << 22) | ((uint32_t)wlantwpwr << 11) | ((uint32_t)wlantwext << 0));
}

/**
 * @brief Sets the wlan_twrm field of the WIFI_WAKEUP_DELAY_TIMER register.
 *
 * The WIFI_WAKEUP_DELAY_TIMER register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wlantwrm - The value to set the field to.
 */
__INLINE void wcnaon_wlan_twrm_setf(uint16_t wlantwrm)
{
    REG_PL_WR(WCNAON_WIFI_WAKEUP_DELAY_TIMER_ADDR, (REG_PL_RD(WCNAON_WIFI_WAKEUP_DELAY_TIMER_ADDR) & ~((uint32_t)0xFFC00000)) | ((uint32_t)wlantwrm << 22));
}

/**
 * @brief Sets the wlan_twpwr field of the WIFI_WAKEUP_DELAY_TIMER register.
 *
 * The WIFI_WAKEUP_DELAY_TIMER register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wlantwpwr - The value to set the field to.
 */
__INLINE void wcnaon_wlan_twpwr_setf(uint16_t wlantwpwr)
{
    REG_PL_WR(WCNAON_WIFI_WAKEUP_DELAY_TIMER_ADDR, (REG_PL_RD(WCNAON_WIFI_WAKEUP_DELAY_TIMER_ADDR) & ~((uint32_t)0x003FF800)) | ((uint32_t)wlantwpwr << 11));
}

/**
 * @brief Sets the wlan_twext field of the WIFI_WAKEUP_DELAY_TIMER register.
 *
 * The WIFI_WAKEUP_DELAY_TIMER register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wlantwext - The value to set the field to.
 */
__INLINE void wcnaon_wlan_twext_setf(uint16_t wlantwext)
{
    REG_PL_WR(WCNAON_WIFI_WAKEUP_DELAY_TIMER_ADDR, (REG_PL_RD(WCNAON_WIFI_WAKEUP_DELAY_TIMER_ADDR) & ~((uint32_t)0x000007FF)) | ((uint32_t)wlantwext << 0));
}

/// @}

/**
 * @name WFBT_RFEN_CTRL register definitions
 * <table>
 * <caption id="WFBT_RFEN_CTRL_BF">WFBT_RFEN_CTRL bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>03 <td>        bt_rfen_dr <td>R <td>W <td>0
 * <tr><td>02 <td>       bt_rfen_reg <td>R <td>W <td>0
 * <tr><td>01 <td>        wf_rfen_dr <td>R <td>W <td>0
 * <tr><td>00 <td>      wf_rf_en_reg <td>R <td>W <td>0
 * </table>
 *
 * @{
 */

/// Address of the WFBT_RFEN_CTRL register
#define WCNAON_WFBT_RFEN_CTRL_ADDR   0x40580018
/// Offset of the WFBT_RFEN_CTRL register from the base address
#define WCNAON_WFBT_RFEN_CTRL_OFFSET 0x00000018
/// Index of the WFBT_RFEN_CTRL register
#define WCNAON_WFBT_RFEN_CTRL_INDEX  0x00000006
/// Reset value of the WFBT_RFEN_CTRL register
#define WCNAON_WFBT_RFEN_CTRL_RESET  0x00000000

/**
 * @brief Sets the WFBT_RFEN_CTRL register to a value.
 * The WFBT_RFEN_CTRL register will be written.
 * @param value - The value to write.
 */
__INLINE void wcnaon_wfbt_rfen_ctrl_set(uint32_t value)
{
    REG_PL_WR(WCNAON_WFBT_RFEN_CTRL_ADDR, value);
}

// field definitions
/// BT_RFEN_DR field bit
#define WCNAON_BT_RFEN_DR_BIT      ((uint32_t)0x00000008)
/// BT_RFEN_DR field position
#define WCNAON_BT_RFEN_DR_POS      3
/// BT_RFEN_REG field bit
#define WCNAON_BT_RFEN_REG_BIT     ((uint32_t)0x00000004)
/// BT_RFEN_REG field position
#define WCNAON_BT_RFEN_REG_POS     2
/// WF_RFEN_DR field bit
#define WCNAON_WF_RFEN_DR_BIT      ((uint32_t)0x00000002)
/// WF_RFEN_DR field position
#define WCNAON_WF_RFEN_DR_POS      1
/// WF_RF_EN_REG field bit
#define WCNAON_WF_RF_EN_REG_BIT    ((uint32_t)0x00000001)
/// WF_RF_EN_REG field position
#define WCNAON_WF_RF_EN_REG_POS    0

/// BT_RFEN_DR field reset value
#define WCNAON_BT_RFEN_DR_RST      0x0
/// BT_RFEN_REG field reset value
#define WCNAON_BT_RFEN_REG_RST     0x0
/// WF_RFEN_DR field reset value
#define WCNAON_WF_RFEN_DR_RST      0x0
/// WF_RF_EN_REG field reset value
#define WCNAON_WF_RF_EN_REG_RST    0x0

/**
 * @brief Constructs a value for the WFBT_RFEN_CTRL register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] btrfendr - The value to use for the bt_rfen_dr field.
 * @param[in] btrfenreg - The value to use for the bt_rfen_reg field.
 * @param[in] wfrfendr - The value to use for the wf_rfen_dr field.
 * @param[in] wfrfenreg - The value to use for the wf_rf_en_reg field.
 */
__INLINE void wcnaon_wfbt_rfen_ctrl_pack(uint8_t btrfendr, uint8_t btrfenreg, uint8_t wfrfendr, uint8_t wfrfenreg)
{
    REG_PL_WR(WCNAON_WFBT_RFEN_CTRL_ADDR,  ((uint32_t)btrfendr << 3) | ((uint32_t)btrfenreg << 2) | ((uint32_t)wfrfendr << 1) | ((uint32_t)wfrfenreg << 0));
}

/**
 * @brief Sets the bt_rfen_dr field of the WFBT_RFEN_CTRL register.
 *
 * The WFBT_RFEN_CTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] btrfendr - The value to set the field to.
 */
__INLINE void wcnaon_bt_rfen_dr_setf(uint8_t btrfendr)
{
    REG_PL_WR(WCNAON_WFBT_RFEN_CTRL_ADDR, (REG_PL_RD(WCNAON_WFBT_RFEN_CTRL_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)btrfendr << 3));
}

/**
 * @brief Sets the bt_rfen_reg field of the WFBT_RFEN_CTRL register.
 *
 * The WFBT_RFEN_CTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] btrfenreg - The value to set the field to.
 */
__INLINE void wcnaon_bt_rfen_reg_setf(uint8_t btrfenreg)
{
    REG_PL_WR(WCNAON_WFBT_RFEN_CTRL_ADDR, (REG_PL_RD(WCNAON_WFBT_RFEN_CTRL_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)btrfenreg << 2));
}

/**
 * @brief Sets the wf_rfen_dr field of the WFBT_RFEN_CTRL register.
 *
 * The WFBT_RFEN_CTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wfrfendr - The value to set the field to.
 */
__INLINE void wcnaon_wf_rfen_dr_setf(uint8_t wfrfendr)
{
    REG_PL_WR(WCNAON_WFBT_RFEN_CTRL_ADDR, (REG_PL_RD(WCNAON_WFBT_RFEN_CTRL_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)wfrfendr << 1));
}

/**
 * @brief Sets the wf_rf_en_reg field of the WFBT_RFEN_CTRL register.
 *
 * The WFBT_RFEN_CTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wfrfenreg - The value to set the field to.
 */
__INLINE void wcnaon_wf_rf_en_reg_setf(uint8_t wfrfenreg)
{
    REG_PL_WR(WCNAON_WFBT_RFEN_CTRL_ADDR, (REG_PL_RD(WCNAON_WFBT_RFEN_CTRL_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)wfrfenreg << 0));
}

/// @}

/**
 * @name DEEPSLEEP_WAKEUP_IND register definitions
 * <table>
 * <caption id="DEEPSLEEP_WAKEUP_IND_BF">DEEPSLEEP_WAKEUP_IND bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>31:04 <td>            hw_eco <td>R <td>R/W <td>0x0
 * <tr><td>03:00 <td>deepsleep_wakeup_ind <td>R <td>R/W <td>0x0
 * </table>
 *
 * @{
 */

/// Address of the DEEPSLEEP_WAKEUP_IND register
#define WCNAON_DEEPSLEEP_WAKEUP_IND_ADDR   0x4058001C
/// Offset of the DEEPSLEEP_WAKEUP_IND register from the base address
#define WCNAON_DEEPSLEEP_WAKEUP_IND_OFFSET 0x0000001C
/// Index of the DEEPSLEEP_WAKEUP_IND register
#define WCNAON_DEEPSLEEP_WAKEUP_IND_INDEX  0x00000007
/// Reset value of the DEEPSLEEP_WAKEUP_IND register
#define WCNAON_DEEPSLEEP_WAKEUP_IND_RESET  0x00000000

/**
 * @brief Returns the current value of the DEEPSLEEP_WAKEUP_IND register.
 * The DEEPSLEEP_WAKEUP_IND register will be read and its value returned.
 * @return The current value of the DEEPSLEEP_WAKEUP_IND register.
 */
__INLINE uint32_t wcnaon_deepsleep_wakeup_ind_get(void)
{
    return REG_PL_RD(WCNAON_DEEPSLEEP_WAKEUP_IND_ADDR);
}

/**
 * @brief Sets the DEEPSLEEP_WAKEUP_IND register to a value.
 * The DEEPSLEEP_WAKEUP_IND register will be written.
 * @param value - The value to write.
 */
__INLINE void wcnaon_deepsleep_wakeup_ind_set(uint32_t value)
{
    REG_PL_WR(WCNAON_DEEPSLEEP_WAKEUP_IND_ADDR, value);
}

// field definitions
/// HW_ECO field mask
#define WCNAON_HW_ECO_MASK                 ((uint32_t)0xFFFFFFF0)
/// HW_ECO field LSB position
#define WCNAON_HW_ECO_LSB                  4
/// HW_ECO field width
#define WCNAON_HW_ECO_WIDTH                ((uint32_t)0x0000001C)
/// DEEPSLEEP_WAKEUP_IND field mask
#define WCNAON_DEEPSLEEP_WAKEUP_IND_MASK   ((uint32_t)0x0000000F)
/// DEEPSLEEP_WAKEUP_IND field LSB position
#define WCNAON_DEEPSLEEP_WAKEUP_IND_LSB    0
/// DEEPSLEEP_WAKEUP_IND field width
#define WCNAON_DEEPSLEEP_WAKEUP_IND_WIDTH  ((uint32_t)0x00000004)

/// HW_ECO field reset value
#define WCNAON_HW_ECO_RST                  0x0
/// DEEPSLEEP_WAKEUP_IND field reset value
#define WCNAON_DEEPSLEEP_WAKEUP_IND_RST    0x0

/**
 * @brief Constructs a value for the DEEPSLEEP_WAKEUP_IND register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] hweco - The value to use for the hw_eco field.
 * @param[in] deepsleepwakeupind - The value to use for the deepsleep_wakeup_ind field.
 */
__INLINE void wcnaon_deepsleep_wakeup_ind_pack(uint32_t hweco, uint8_t deepsleepwakeupind)
{
    REG_PL_WR(WCNAON_DEEPSLEEP_WAKEUP_IND_ADDR,  ((uint32_t)hweco << 4) | ((uint32_t)deepsleepwakeupind << 0));
}

/**
 * @brief Unpacks DEEPSLEEP_WAKEUP_IND's fields from current value of the DEEPSLEEP_WAKEUP_IND register.
 *
 * Reads the DEEPSLEEP_WAKEUP_IND register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] hweco - Will be populated with the current value of this field from the register.
 * @param[out] deepsleepwakeupind - Will be populated with the current value of this field from the register.
 */
__INLINE void wcnaon_deepsleep_wakeup_ind_unpack(uint32_t* hweco, uint8_t* deepsleepwakeupind)
{
    uint32_t localVal = REG_PL_RD(WCNAON_DEEPSLEEP_WAKEUP_IND_ADDR);

    *hweco = (localVal & ((uint32_t)0xFFFFFFF0)) >> 4;
    *deepsleepwakeupind = (localVal & ((uint32_t)0x0000000F)) >> 0;
}

/**
 * @brief Returns the current value of the hw_eco field in the DEEPSLEEP_WAKEUP_IND register.
 *
 * The DEEPSLEEP_WAKEUP_IND register will be read and the hw_eco field's value will be returned.
 *
 * @return The current value of the hw_eco field in the DEEPSLEEP_WAKEUP_IND register.
 */
__INLINE uint32_t wcnaon_hw_eco_getf(void)
{
    uint32_t localVal = REG_PL_RD(WCNAON_DEEPSLEEP_WAKEUP_IND_ADDR);
    return ((localVal & ((uint32_t)0xFFFFFFF0)) >> 4);
}

/**
 * @brief Sets the hw_eco field of the DEEPSLEEP_WAKEUP_IND register.
 *
 * The DEEPSLEEP_WAKEUP_IND register will be read, modified to contain the new field value, and written.
 *
 * @param[in] hweco - The value to set the field to.
 */
__INLINE void wcnaon_hw_eco_setf(uint32_t hweco)
{
    REG_PL_WR(WCNAON_DEEPSLEEP_WAKEUP_IND_ADDR, (REG_PL_RD(WCNAON_DEEPSLEEP_WAKEUP_IND_ADDR) & ~((uint32_t)0xFFFFFFF0)) | ((uint32_t)hweco << 4));
}

/**
 * @brief Returns the current value of the deepsleep_wakeup_ind field in the DEEPSLEEP_WAKEUP_IND register.
 *
 * The DEEPSLEEP_WAKEUP_IND register will be read and the deepsleep_wakeup_ind field's value will be returned.
 *
 * @return The current value of the deepsleep_wakeup_ind field in the DEEPSLEEP_WAKEUP_IND register.
 */
__INLINE uint8_t wcnaon_deepsleep_wakeup_ind_getf(void)
{
    uint32_t localVal = REG_PL_RD(WCNAON_DEEPSLEEP_WAKEUP_IND_ADDR);
    return ((localVal & ((uint32_t)0x0000000F)) >> 0);
}

/**
 * @brief Sets the deepsleep_wakeup_ind field of the DEEPSLEEP_WAKEUP_IND register.
 *
 * The DEEPSLEEP_WAKEUP_IND register will be read, modified to contain the new field value, and written.
 *
 * @param[in] deepsleepwakeupind - The value to set the field to.
 */
__INLINE void wcnaon_deepsleep_wakeup_ind_setf(uint8_t deepsleepwakeupind)
{
    REG_PL_WR(WCNAON_DEEPSLEEP_WAKEUP_IND_ADDR, (REG_PL_RD(WCNAON_DEEPSLEEP_WAKEUP_IND_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)deepsleepwakeupind << 0));
}

/// @}

/**
 * @name MAXIM_SPI register definitions
 * <table>
 * <caption id="MAXIM_SPI_BF">MAXIM_SPI bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>31 <td>        START_DONE <td>C <td>S <td>0
 * <tr><td>24 <td>                CS <td>R/W <td>R/W <td>0
 * <tr><td>23:20 <td>         PRESCALER <td>R <td>R/W <td>0x0
 * <tr><td>19:16 <td>           ADDRESS <td>R/W <td>R/W <td>0x0
 * <tr><td>13:00 <td>              DATA <td>R/W <td>R/W <td>0x0
 * </table>
 *
 * @{
 */

/// Address of the MAXIM_SPI register
#define WCNAON_MAXIM_SPI_ADDR   0x40580020
/// Offset of the MAXIM_SPI register from the base address
#define WCNAON_MAXIM_SPI_OFFSET 0x00000020
/// Index of the MAXIM_SPI register
#define WCNAON_MAXIM_SPI_INDEX  0x00000008
/// Reset value of the MAXIM_SPI register
#define WCNAON_MAXIM_SPI_RESET  0x00000000

/**
 * @brief Returns the current value of the MAXIM_SPI register.
 * The MAXIM_SPI register will be read and its value returned.
 * @return The current value of the MAXIM_SPI register.
 */
__INLINE uint32_t wcnaon_maxim_spi_get(void)
{
    return REG_PL_RD(WCNAON_MAXIM_SPI_ADDR);
}

/**
 * @brief Sets the MAXIM_SPI register to a value.
 * The MAXIM_SPI register will be written.
 * @param value - The value to write.
 */
__INLINE void wcnaon_maxim_spi_set(uint32_t value)
{
    REG_PL_WR(WCNAON_MAXIM_SPI_ADDR, value);
}

// field definitions
/// START_DONE field bit
#define WCNAON_START_DONE_BIT    ((uint32_t)0x80000000)
/// START_DONE field position
#define WCNAON_START_DONE_POS    31
/// CS field bit
#define WCNAON_CS_BIT            ((uint32_t)0x01000000)
/// CS field position
#define WCNAON_CS_POS            24
/// PRESCALER field mask
#define WCNAON_PRESCALER_MASK    ((uint32_t)0x00F00000)
/// PRESCALER field LSB position
#define WCNAON_PRESCALER_LSB     20
/// PRESCALER field width
#define WCNAON_PRESCALER_WIDTH   ((uint32_t)0x00000004)
/// ADDRESS field mask
#define WCNAON_ADDRESS_MASK      ((uint32_t)0x000F0000)
/// ADDRESS field LSB position
#define WCNAON_ADDRESS_LSB       16
/// ADDRESS field width
#define WCNAON_ADDRESS_WIDTH     ((uint32_t)0x00000004)
/// DATA field mask
#define WCNAON_DATA_MASK         ((uint32_t)0x00003FFF)
/// DATA field LSB position
#define WCNAON_DATA_LSB          0
/// DATA field width
#define WCNAON_DATA_WIDTH        ((uint32_t)0x0000000E)

/// START_DONE field reset value
#define WCNAON_START_DONE_RST    0x0
/// CS field reset value
#define WCNAON_CS_RST            0x0
/// PRESCALER field reset value
#define WCNAON_PRESCALER_RST     0x0
/// ADDRESS field reset value
#define WCNAON_ADDRESS_RST       0x0
/// DATA field reset value
#define WCNAON_DATA_RST          0x0

/**
 * @brief Constructs a value for the MAXIM_SPI register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] startdone - The value to use for the START_DONE field.
 * @param[in] cs - The value to use for the CS field.
 * @param[in] prescaler - The value to use for the PRESCALER field.
 * @param[in] address - The value to use for the ADDRESS field.
 * @param[in] data - The value to use for the DATA field.
 */
__INLINE void wcnaon_maxim_spi_pack(uint8_t startdone, uint8_t cs, uint8_t prescaler, uint8_t address, uint16_t data)
{
    REG_PL_WR(WCNAON_MAXIM_SPI_ADDR,  ((uint32_t)startdone << 31) | ((uint32_t)cs << 24) | ((uint32_t)prescaler << 20) | ((uint32_t)address << 16) | ((uint32_t)data << 0));
}

/**
 * @brief Unpacks MAXIM_SPI's fields from current value of the MAXIM_SPI register.
 *
 * Reads the MAXIM_SPI register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] startdone - Will be populated with the current value of this field from the register.
 * @param[out] cs - Will be populated with the current value of this field from the register.
 * @param[out] prescaler - Will be populated with the current value of this field from the register.
 * @param[out] address - Will be populated with the current value of this field from the register.
 * @param[out] data - Will be populated with the current value of this field from the register.
 */
__INLINE void wcnaon_maxim_spi_unpack(uint8_t* startdone, uint8_t* cs, uint8_t* prescaler, uint8_t* address, uint16_t* data)
{
    uint32_t localVal = REG_PL_RD(WCNAON_MAXIM_SPI_ADDR);

    *startdone = (localVal & ((uint32_t)0x80000000)) >> 31;
    *cs = (localVal & ((uint32_t)0x01000000)) >> 24;
    *prescaler = (localVal & ((uint32_t)0x00F00000)) >> 20;
    *address = (localVal & ((uint32_t)0x000F0000)) >> 16;
    *data = (localVal & ((uint32_t)0x00003FFF)) >> 0;
}

/**
 * @brief Returns the current value of the START_DONE field in the MAXIM_SPI register.
 *
 * The MAXIM_SPI register will be read and the START_DONE field's value will be returned.
 *
 * @return The current value of the START_DONE field in the MAXIM_SPI register.
 */
__INLINE uint8_t wcnaon_start_done_getf(void)
{
    uint32_t localVal = REG_PL_RD(WCNAON_MAXIM_SPI_ADDR);
    return ((localVal & ((uint32_t)0x80000000)) >> 31);
}

/**
 * @brief Sets the START_DONE field of the MAXIM_SPI register.
 *
 * The MAXIM_SPI register will be read, modified to contain the new field value, and written.
 *
 * @param[in] startdone - The value to set the field to.
 */
__INLINE void wcnaon_start_done_setf(uint8_t startdone)
{
    REG_PL_WR(WCNAON_MAXIM_SPI_ADDR, (REG_PL_RD(WCNAON_MAXIM_SPI_ADDR) & ~((uint32_t)0x80000000)) | ((uint32_t)startdone << 31));
}

/**
 * @brief Returns the current value of the CS field in the MAXIM_SPI register.
 *
 * The MAXIM_SPI register will be read and the CS field's value will be returned.
 *
 * @return The current value of the CS field in the MAXIM_SPI register.
 */
__INLINE uint8_t wcnaon_cs_getf(void)
{
    uint32_t localVal = REG_PL_RD(WCNAON_MAXIM_SPI_ADDR);
    return ((localVal & ((uint32_t)0x01000000)) >> 24);
}

/**
 * @brief Sets the CS field of the MAXIM_SPI register.
 *
 * The MAXIM_SPI register will be read, modified to contain the new field value, and written.
 *
 * @param[in] cs - The value to set the field to.
 */
__INLINE void wcnaon_cs_setf(uint8_t cs)
{
    REG_PL_WR(WCNAON_MAXIM_SPI_ADDR, (REG_PL_RD(WCNAON_MAXIM_SPI_ADDR) & ~((uint32_t)0x01000000)) | ((uint32_t)cs << 24));
}

/**
 * @brief Returns the current value of the PRESCALER field in the MAXIM_SPI register.
 *
 * The MAXIM_SPI register will be read and the PRESCALER field's value will be returned.
 *
 * @return The current value of the PRESCALER field in the MAXIM_SPI register.
 */
__INLINE uint8_t wcnaon_prescaler_getf(void)
{
    uint32_t localVal = REG_PL_RD(WCNAON_MAXIM_SPI_ADDR);
    return ((localVal & ((uint32_t)0x00F00000)) >> 20);
}

/**
 * @brief Sets the PRESCALER field of the MAXIM_SPI register.
 *
 * The MAXIM_SPI register will be read, modified to contain the new field value, and written.
 *
 * @param[in] prescaler - The value to set the field to.
 */
__INLINE void wcnaon_prescaler_setf(uint8_t prescaler)
{
    REG_PL_WR(WCNAON_MAXIM_SPI_ADDR, (REG_PL_RD(WCNAON_MAXIM_SPI_ADDR) & ~((uint32_t)0x00F00000)) | ((uint32_t)prescaler << 20));
}

/**
 * @brief Returns the current value of the ADDRESS field in the MAXIM_SPI register.
 *
 * The MAXIM_SPI register will be read and the ADDRESS field's value will be returned.
 *
 * @return The current value of the ADDRESS field in the MAXIM_SPI register.
 */
__INLINE uint8_t wcnaon_address_getf(void)
{
    uint32_t localVal = REG_PL_RD(WCNAON_MAXIM_SPI_ADDR);
    return ((localVal & ((uint32_t)0x000F0000)) >> 16);
}

/**
 * @brief Sets the ADDRESS field of the MAXIM_SPI register.
 *
 * The MAXIM_SPI register will be read, modified to contain the new field value, and written.
 *
 * @param[in] address - The value to set the field to.
 */
__INLINE void wcnaon_address_setf(uint8_t address)
{
    REG_PL_WR(WCNAON_MAXIM_SPI_ADDR, (REG_PL_RD(WCNAON_MAXIM_SPI_ADDR) & ~((uint32_t)0x000F0000)) | ((uint32_t)address << 16));
}

/**
 * @brief Returns the current value of the DATA field in the MAXIM_SPI register.
 *
 * The MAXIM_SPI register will be read and the DATA field's value will be returned.
 *
 * @return The current value of the DATA field in the MAXIM_SPI register.
 */
__INLINE uint16_t wcnaon_data_getf(void)
{
    uint32_t localVal = REG_PL_RD(WCNAON_MAXIM_SPI_ADDR);
    return ((localVal & ((uint32_t)0x00003FFF)) >> 0);
}

/**
 * @brief Sets the DATA field of the MAXIM_SPI register.
 *
 * The MAXIM_SPI register will be read, modified to contain the new field value, and written.
 *
 * @param[in] data - The value to set the field to.
 */
__INLINE void wcnaon_data_setf(uint16_t data)
{
    REG_PL_WR(WCNAON_MAXIM_SPI_ADDR, (REG_PL_RD(WCNAON_MAXIM_SPI_ADDR) & ~((uint32_t)0x00003FFF)) | ((uint32_t)data << 0));
}

/// @}

/**
 * @name CM_PU_CTRL register definitions
 * <table>
 * <caption id="CM_PU_CTRL_BF">CM_PU_CTRL bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>11 <td>    cm_pu_bbpll_dr <td>R <td>R/W <td>0
 * <tr><td>10 <td>   cm_pu_bbpll_reg <td>R <td>R/W <td>0
 * </table>
 *
 * @{
 */

/// Address of the CM_PU_CTRL register
#define WCNAON_CM_PU_CTRL_ADDR   0x40580100
/// Offset of the CM_PU_CTRL register from the base address
#define WCNAON_CM_PU_CTRL_OFFSET 0x00000100
/// Index of the CM_PU_CTRL register
#define WCNAON_CM_PU_CTRL_INDEX  0x00000040
/// Reset value of the CM_PU_CTRL register
#define WCNAON_CM_PU_CTRL_RESET  0x00000000

/**
 * @brief Returns the current value of the CM_PU_CTRL register.
 * The CM_PU_CTRL register will be read and its value returned.
 * @return The current value of the CM_PU_CTRL register.
 */
__INLINE uint32_t wcnaon_cm_pu_ctrl_get(void)
{
    return REG_PL_RD(WCNAON_CM_PU_CTRL_ADDR);
}

/**
 * @brief Sets the CM_PU_CTRL register to a value.
 * The CM_PU_CTRL register will be written.
 * @param value - The value to write.
 */
__INLINE void wcnaon_cm_pu_ctrl_set(uint32_t value)
{
    REG_PL_WR(WCNAON_CM_PU_CTRL_ADDR, value);
}

// field definitions
/// CM_PU_BBPLL_DR field bit
#define WCNAON_CM_PU_BBPLL_DR_BIT     ((uint32_t)0x00000800)
/// CM_PU_BBPLL_DR field position
#define WCNAON_CM_PU_BBPLL_DR_POS     11
/// CM_PU_BBPLL_REG field bit
#define WCNAON_CM_PU_BBPLL_REG_BIT    ((uint32_t)0x00000400)
/// CM_PU_BBPLL_REG field position
#define WCNAON_CM_PU_BBPLL_REG_POS    10

/// CM_PU_BBPLL_DR field reset value
#define WCNAON_CM_PU_BBPLL_DR_RST     0x0
/// CM_PU_BBPLL_REG field reset value
#define WCNAON_CM_PU_BBPLL_REG_RST    0x0

/**
 * @brief Constructs a value for the CM_PU_CTRL register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] cmpubbplldr - The value to use for the cm_pu_bbpll_dr field.
 * @param[in] cmpubbpllreg - The value to use for the cm_pu_bbpll_reg field.
 */
__INLINE void wcnaon_cm_pu_ctrl_pack(uint8_t cmpubbplldr, uint8_t cmpubbpllreg)
{
    REG_PL_WR(WCNAON_CM_PU_CTRL_ADDR,  ((uint32_t)cmpubbplldr << 11) | ((uint32_t)cmpubbpllreg << 10));
}

/**
 * @brief Unpacks CM_PU_CTRL's fields from current value of the CM_PU_CTRL register.
 *
 * Reads the CM_PU_CTRL register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] cmpubbplldr - Will be populated with the current value of this field from the register.
 * @param[out] cmpubbpllreg - Will be populated with the current value of this field from the register.
 */
__INLINE void wcnaon_cm_pu_ctrl_unpack(uint8_t* cmpubbplldr, uint8_t* cmpubbpllreg)
{
    uint32_t localVal = REG_PL_RD(WCNAON_CM_PU_CTRL_ADDR);

    *cmpubbplldr = (localVal & ((uint32_t)0x00000800)) >> 11;
    *cmpubbpllreg = (localVal & ((uint32_t)0x00000400)) >> 10;
}

/**
 * @brief Returns the current value of the cm_pu_bbpll_dr field in the CM_PU_CTRL register.
 *
 * The CM_PU_CTRL register will be read and the cm_pu_bbpll_dr field's value will be returned.
 *
 * @return The current value of the cm_pu_bbpll_dr field in the CM_PU_CTRL register.
 */
__INLINE uint8_t wcnaon_cm_pu_bbpll_dr_getf(void)
{
    uint32_t localVal = REG_PL_RD(WCNAON_CM_PU_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000800)) >> 11);
}

/**
 * @brief Sets the cm_pu_bbpll_dr field of the CM_PU_CTRL register.
 *
 * The CM_PU_CTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] cmpubbplldr - The value to set the field to.
 */
__INLINE void wcnaon_cm_pu_bbpll_dr_setf(uint8_t cmpubbplldr)
{
    REG_PL_WR(WCNAON_CM_PU_CTRL_ADDR, (REG_PL_RD(WCNAON_CM_PU_CTRL_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)cmpubbplldr << 11));
}

/**
 * @brief Returns the current value of the cm_pu_bbpll_reg field in the CM_PU_CTRL register.
 *
 * The CM_PU_CTRL register will be read and the cm_pu_bbpll_reg field's value will be returned.
 *
 * @return The current value of the cm_pu_bbpll_reg field in the CM_PU_CTRL register.
 */
__INLINE uint8_t wcnaon_cm_pu_bbpll_reg_getf(void)
{
    uint32_t localVal = REG_PL_RD(WCNAON_CM_PU_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000400)) >> 10);
}

/**
 * @brief Sets the cm_pu_bbpll_reg field of the CM_PU_CTRL register.
 *
 * The CM_PU_CTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] cmpubbpllreg - The value to set the field to.
 */
__INLINE void wcnaon_cm_pu_bbpll_reg_setf(uint8_t cmpubbpllreg)
{
    REG_PL_WR(WCNAON_CM_PU_CTRL_ADDR, (REG_PL_RD(WCNAON_CM_PU_CTRL_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)cmpubbpllreg << 10));
}

/// @}

/**
 * @name CM_MDLL_REG register definitions
 * <table>
 * <caption id="CM_MDLL_REG_BF">CM_MDLL_REG bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>16 <td>  cm_mdll_band_sel <td>R <td>R/W <td>0
 * <tr><td>15:13 <td>  cm_mdll_band_bit <td>R <td>R/W <td>0x0
 * </table>
 *
 * @{
 */

/// Address of the CM_MDLL_REG register
#define WCNAON_CM_MDLL_REG_ADDR   0x40580104
/// Offset of the CM_MDLL_REG register from the base address
#define WCNAON_CM_MDLL_REG_OFFSET 0x00000104
/// Index of the CM_MDLL_REG register
#define WCNAON_CM_MDLL_REG_INDEX  0x00000041
/// Reset value of the CM_MDLL_REG register
#define WCNAON_CM_MDLL_REG_RESET  0x00000000

/**
 * @brief Returns the current value of the CM_MDLL_REG register.
 * The CM_MDLL_REG register will be read and its value returned.
 * @return The current value of the CM_MDLL_REG register.
 */
__INLINE uint32_t wcnaon_cm_mdll_reg_get(void)
{
    return REG_PL_RD(WCNAON_CM_MDLL_REG_ADDR);
}

/**
 * @brief Sets the CM_MDLL_REG register to a value.
 * The CM_MDLL_REG register will be written.
 * @param value - The value to write.
 */
__INLINE void wcnaon_cm_mdll_reg_set(uint32_t value)
{
    REG_PL_WR(WCNAON_CM_MDLL_REG_ADDR, value);
}

// field definitions
/// CM_MDLL_BAND_SEL field bit
#define WCNAON_CM_MDLL_BAND_SEL_BIT    ((uint32_t)0x00010000)
/// CM_MDLL_BAND_SEL field position
#define WCNAON_CM_MDLL_BAND_SEL_POS    16
/// CM_MDLL_BAND_BIT field mask
#define WCNAON_CM_MDLL_BAND_BIT_MASK   ((uint32_t)0x0000E000)
/// CM_MDLL_BAND_BIT field LSB position
#define WCNAON_CM_MDLL_BAND_BIT_LSB    13
/// CM_MDLL_BAND_BIT field width
#define WCNAON_CM_MDLL_BAND_BIT_WIDTH  ((uint32_t)0x00000003)

/// CM_MDLL_BAND_SEL field reset value
#define WCNAON_CM_MDLL_BAND_SEL_RST    0x0
/// CM_MDLL_BAND_BIT field reset value
#define WCNAON_CM_MDLL_BAND_BIT_RST    0x0

/**
 * @brief Constructs a value for the CM_MDLL_REG register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] cmmdllbandsel - The value to use for the cm_mdll_band_sel field.
 * @param[in] cmmdllbandbit - The value to use for the cm_mdll_band_bit field.
 */
__INLINE void wcnaon_cm_mdll_reg_pack(uint8_t cmmdllbandsel, uint8_t cmmdllbandbit)
{
    REG_PL_WR(WCNAON_CM_MDLL_REG_ADDR,  ((uint32_t)cmmdllbandsel << 16) | ((uint32_t)cmmdllbandbit << 13));
}

/**
 * @brief Unpacks CM_MDLL_REG's fields from current value of the CM_MDLL_REG register.
 *
 * Reads the CM_MDLL_REG register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] cmmdllbandsel - Will be populated with the current value of this field from the register.
 * @param[out] cmmdllbandbit - Will be populated with the current value of this field from the register.
 */
__INLINE void wcnaon_cm_mdll_reg_unpack(uint8_t* cmmdllbandsel, uint8_t* cmmdllbandbit)
{
    uint32_t localVal = REG_PL_RD(WCNAON_CM_MDLL_REG_ADDR);

    *cmmdllbandsel = (localVal & ((uint32_t)0x00010000)) >> 16;
    *cmmdllbandbit = (localVal & ((uint32_t)0x0000E000)) >> 13;
}

/**
 * @brief Returns the current value of the cm_mdll_band_sel field in the CM_MDLL_REG register.
 *
 * The CM_MDLL_REG register will be read and the cm_mdll_band_sel field's value will be returned.
 *
 * @return The current value of the cm_mdll_band_sel field in the CM_MDLL_REG register.
 */
__INLINE uint8_t wcnaon_cm_mdll_band_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(WCNAON_CM_MDLL_REG_ADDR);
    return ((localVal & ((uint32_t)0x00010000)) >> 16);
}

/**
 * @brief Sets the cm_mdll_band_sel field of the CM_MDLL_REG register.
 *
 * The CM_MDLL_REG register will be read, modified to contain the new field value, and written.
 *
 * @param[in] cmmdllbandsel - The value to set the field to.
 */
__INLINE void wcnaon_cm_mdll_band_sel_setf(uint8_t cmmdllbandsel)
{
    REG_PL_WR(WCNAON_CM_MDLL_REG_ADDR, (REG_PL_RD(WCNAON_CM_MDLL_REG_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)cmmdllbandsel << 16));
}

/**
 * @brief Returns the current value of the cm_mdll_band_bit field in the CM_MDLL_REG register.
 *
 * The CM_MDLL_REG register will be read and the cm_mdll_band_bit field's value will be returned.
 *
 * @return The current value of the cm_mdll_band_bit field in the CM_MDLL_REG register.
 */
__INLINE uint8_t wcnaon_cm_mdll_band_bit_getf(void)
{
    uint32_t localVal = REG_PL_RD(WCNAON_CM_MDLL_REG_ADDR);
    return ((localVal & ((uint32_t)0x0000E000)) >> 13);
}

/**
 * @brief Sets the cm_mdll_band_bit field of the CM_MDLL_REG register.
 *
 * The CM_MDLL_REG register will be read, modified to contain the new field value, and written.
 *
 * @param[in] cmmdllbandbit - The value to set the field to.
 */
__INLINE void wcnaon_cm_mdll_band_bit_setf(uint8_t cmmdllbandbit)
{
    REG_PL_WR(WCNAON_CM_MDLL_REG_ADDR, (REG_PL_RD(WCNAON_CM_MDLL_REG_ADDR) & ~((uint32_t)0x0000E000)) | ((uint32_t)cmmdllbandbit << 13));
}

/// @}

/**
 * @name CM_XTAL_REG register definitions
 * <table>
 * <caption id="CM_XTAL_REG_BF">CM_XTAL_REG bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>12 <td>cm_xtal_buf_avdd_sel <td>R <td>R/W <td>0
 * <tr><td>03 <td>   cm_xtal_out_en3 <td>R <td>R/W <td>0
 * <tr><td>01 <td>   cm_xtal_out_en1 <td>R <td>R/W <td>0
 * <tr><td>00 <td>   cm_xtal_out_en0 <td>R <td>R/W <td>0
 * </table>
 *
 * @{
 */

/// Address of the CM_XTAL_REG register
#define WCNAON_CM_XTAL_REG_ADDR   0x40580108
/// Offset of the CM_XTAL_REG register from the base address
#define WCNAON_CM_XTAL_REG_OFFSET 0x00000108
/// Index of the CM_XTAL_REG register
#define WCNAON_CM_XTAL_REG_INDEX  0x00000042
/// Reset value of the CM_XTAL_REG register
#define WCNAON_CM_XTAL_REG_RESET  0x00000000

/**
 * @brief Returns the current value of the CM_XTAL_REG register.
 * The CM_XTAL_REG register will be read and its value returned.
 * @return The current value of the CM_XTAL_REG register.
 */
__INLINE uint32_t wcnaon_cm_xtal_reg_get(void)
{
    return REG_PL_RD(WCNAON_CM_XTAL_REG_ADDR);
}

/**
 * @brief Sets the CM_XTAL_REG register to a value.
 * The CM_XTAL_REG register will be written.
 * @param value - The value to write.
 */
__INLINE void wcnaon_cm_xtal_reg_set(uint32_t value)
{
    REG_PL_WR(WCNAON_CM_XTAL_REG_ADDR, value);
}

// field definitions
/// CM_XTAL_BUF_AVDD_SEL field bit
#define WCNAON_CM_XTAL_BUF_AVDD_SEL_BIT    ((uint32_t)0x00001000)
/// CM_XTAL_BUF_AVDD_SEL field position
#define WCNAON_CM_XTAL_BUF_AVDD_SEL_POS    12
/// CM_XTAL_OUT_EN_3 field bit
#define WCNAON_CM_XTAL_OUT_EN_3_BIT        ((uint32_t)0x00000008)
/// CM_XTAL_OUT_EN_3 field position
#define WCNAON_CM_XTAL_OUT_EN_3_POS        3
/// CM_XTAL_OUT_EN_1 field bit
#define WCNAON_CM_XTAL_OUT_EN_1_BIT        ((uint32_t)0x00000002)
/// CM_XTAL_OUT_EN_1 field position
#define WCNAON_CM_XTAL_OUT_EN_1_POS        1
/// CM_XTAL_OUT_EN_0 field bit
#define WCNAON_CM_XTAL_OUT_EN_0_BIT        ((uint32_t)0x00000001)
/// CM_XTAL_OUT_EN_0 field position
#define WCNAON_CM_XTAL_OUT_EN_0_POS        0

/// CM_XTAL_BUF_AVDD_SEL field reset value
#define WCNAON_CM_XTAL_BUF_AVDD_SEL_RST    0x0
/// CM_XTAL_OUT_EN_3 field reset value
#define WCNAON_CM_XTAL_OUT_EN_3_RST        0x0
/// CM_XTAL_OUT_EN_1 field reset value
#define WCNAON_CM_XTAL_OUT_EN_1_RST        0x0
/// CM_XTAL_OUT_EN_0 field reset value
#define WCNAON_CM_XTAL_OUT_EN_0_RST        0x0

/**
 * @brief Constructs a value for the CM_XTAL_REG register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] cmxtalbufavddsel - The value to use for the cm_xtal_buf_avdd_sel field.
 * @param[in] cmxtalouten3 - The value to use for the cm_xtal_out_en3 field.
 * @param[in] cmxtalouten1 - The value to use for the cm_xtal_out_en1 field.
 * @param[in] cmxtalouten0 - The value to use for the cm_xtal_out_en0 field.
 */
__INLINE void wcnaon_cm_xtal_reg_pack(uint8_t cmxtalbufavddsel, uint8_t cmxtalouten3, uint8_t cmxtalouten1, uint8_t cmxtalouten0)
{
    REG_PL_WR(WCNAON_CM_XTAL_REG_ADDR,  ((uint32_t)cmxtalbufavddsel << 12) | ((uint32_t)cmxtalouten3 << 3) | ((uint32_t)cmxtalouten1 << 1) | ((uint32_t)cmxtalouten0 << 0));
}

/**
 * @brief Unpacks CM_XTAL_REG's fields from current value of the CM_XTAL_REG register.
 *
 * Reads the CM_XTAL_REG register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] cmxtalbufavddsel - Will be populated with the current value of this field from the register.
 * @param[out] cmxtalouten3 - Will be populated with the current value of this field from the register.
 * @param[out] cmxtalouten1 - Will be populated with the current value of this field from the register.
 * @param[out] cmxtalouten0 - Will be populated with the current value of this field from the register.
 */
__INLINE void wcnaon_cm_xtal_reg_unpack(uint8_t* cmxtalbufavddsel, uint8_t* cmxtalouten3, uint8_t* cmxtalouten1, uint8_t* cmxtalouten0)
{
    uint32_t localVal = REG_PL_RD(WCNAON_CM_XTAL_REG_ADDR);

    *cmxtalbufavddsel = (localVal & ((uint32_t)0x00001000)) >> 12;
    *cmxtalouten3 = (localVal & ((uint32_t)0x00000008)) >> 3;
    *cmxtalouten1 = (localVal & ((uint32_t)0x00000002)) >> 1;
    *cmxtalouten0 = (localVal & ((uint32_t)0x00000001)) >> 0;
}

/**
 * @brief Returns the current value of the cm_xtal_buf_avdd_sel field in the CM_XTAL_REG register.
 *
 * The CM_XTAL_REG register will be read and the cm_xtal_buf_avdd_sel field's value will be returned.
 *
 * @return The current value of the cm_xtal_buf_avdd_sel field in the CM_XTAL_REG register.
 */
__INLINE uint8_t wcnaon_cm_xtal_buf_avdd_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(WCNAON_CM_XTAL_REG_ADDR);
    return ((localVal & ((uint32_t)0x00001000)) >> 12);
}

/**
 * @brief Sets the cm_xtal_buf_avdd_sel field of the CM_XTAL_REG register.
 *
 * The CM_XTAL_REG register will be read, modified to contain the new field value, and written.
 *
 * @param[in] cmxtalbufavddsel - The value to set the field to.
 */
__INLINE void wcnaon_cm_xtal_buf_avdd_sel_setf(uint8_t cmxtalbufavddsel)
{
    REG_PL_WR(WCNAON_CM_XTAL_REG_ADDR, (REG_PL_RD(WCNAON_CM_XTAL_REG_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)cmxtalbufavddsel << 12));
}

/**
 * @brief Returns the current value of the cm_xtal_out_en3 field in the CM_XTAL_REG register.
 *
 * The CM_XTAL_REG register will be read and the cm_xtal_out_en3 field's value will be returned.
 *
 * @return The current value of the cm_xtal_out_en3 field in the CM_XTAL_REG register.
 */
__INLINE uint8_t wcnaon_cm_xtal_out_en_3_getf(void)
{
    uint32_t localVal = REG_PL_RD(WCNAON_CM_XTAL_REG_ADDR);
    return ((localVal & ((uint32_t)0x00000008)) >> 3);
}

/**
 * @brief Sets the cm_xtal_out_en3 field of the CM_XTAL_REG register.
 *
 * The CM_XTAL_REG register will be read, modified to contain the new field value, and written.
 *
 * @param[in] cmxtalouten3 - The value to set the field to.
 */
__INLINE void wcnaon_cm_xtal_out_en_3_setf(uint8_t cmxtalouten3)
{
    REG_PL_WR(WCNAON_CM_XTAL_REG_ADDR, (REG_PL_RD(WCNAON_CM_XTAL_REG_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)cmxtalouten3 << 3));
}

/**
 * @brief Returns the current value of the cm_xtal_out_en1 field in the CM_XTAL_REG register.
 *
 * The CM_XTAL_REG register will be read and the cm_xtal_out_en1 field's value will be returned.
 *
 * @return The current value of the cm_xtal_out_en1 field in the CM_XTAL_REG register.
 */
__INLINE uint8_t wcnaon_cm_xtal_out_en_1_getf(void)
{
    uint32_t localVal = REG_PL_RD(WCNAON_CM_XTAL_REG_ADDR);
    return ((localVal & ((uint32_t)0x00000002)) >> 1);
}

/**
 * @brief Sets the cm_xtal_out_en1 field of the CM_XTAL_REG register.
 *
 * The CM_XTAL_REG register will be read, modified to contain the new field value, and written.
 *
 * @param[in] cmxtalouten1 - The value to set the field to.
 */
__INLINE void wcnaon_cm_xtal_out_en_1_setf(uint8_t cmxtalouten1)
{
    REG_PL_WR(WCNAON_CM_XTAL_REG_ADDR, (REG_PL_RD(WCNAON_CM_XTAL_REG_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)cmxtalouten1 << 1));
}

/**
 * @brief Returns the current value of the cm_xtal_out_en0 field in the CM_XTAL_REG register.
 *
 * The CM_XTAL_REG register will be read and the cm_xtal_out_en0 field's value will be returned.
 *
 * @return The current value of the cm_xtal_out_en0 field in the CM_XTAL_REG register.
 */
__INLINE uint8_t wcnaon_cm_xtal_out_en_0_getf(void)
{
    uint32_t localVal = REG_PL_RD(WCNAON_CM_XTAL_REG_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief Sets the cm_xtal_out_en0 field of the CM_XTAL_REG register.
 *
 * The CM_XTAL_REG register will be read, modified to contain the new field value, and written.
 *
 * @param[in] cmxtalouten0 - The value to set the field to.
 */
__INLINE void wcnaon_cm_xtal_out_en_0_setf(uint8_t cmxtalouten0)
{
    REG_PL_WR(WCNAON_CM_XTAL_REG_ADDR, (REG_PL_RD(WCNAON_CM_XTAL_REG_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)cmxtalouten0 << 0));
}

/// @}

/**
 * @name CM_BBPLL_REG2 register definitions
 * <table>
 * <caption id="CM_BBPLL_REG2_BF">CM_BBPLL_REG2 bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>20:19 <td>        clk_vco_en <td>R <td>R/W <td>0x0
 * <tr><td>18:17 <td>        clk_80m_en <td>R <td>R/W <td>0x0
 * <tr><td>02 <td>         divlp5_en <td>R <td>R/W <td>0
 * <tr><td>01:00 <td>     clk_divlp5_en <td>R <td>R/W <td>0x0
 * </table>
 *
 * @{
 */

/// Address of the CM_BBPLL_REG2 register
#define WCNAON_CM_BBPLL_REG2_ADDR   0x40580110
/// Offset of the CM_BBPLL_REG2 register from the base address
#define WCNAON_CM_BBPLL_REG2_OFFSET 0x00000110
/// Index of the CM_BBPLL_REG2 register
#define WCNAON_CM_BBPLL_REG2_INDEX  0x00000044
/// Reset value of the CM_BBPLL_REG2 register
#define WCNAON_CM_BBPLL_REG2_RESET  0x00000000

/**
 * @brief Returns the current value of the CM_BBPLL_REG2 register.
 * The CM_BBPLL_REG2 register will be read and its value returned.
 * @return The current value of the CM_BBPLL_REG2 register.
 */
__INLINE uint32_t wcnaon_cm_bbpll_reg2_get(void)
{
    return REG_PL_RD(WCNAON_CM_BBPLL_REG2_ADDR);
}

/**
 * @brief Sets the CM_BBPLL_REG2 register to a value.
 * The CM_BBPLL_REG2 register will be written.
 * @param value - The value to write.
 */
__INLINE void wcnaon_cm_bbpll_reg2_set(uint32_t value)
{
    REG_PL_WR(WCNAON_CM_BBPLL_REG2_ADDR, value);
}

// field definitions
/// CLK_VCO_EN field mask
#define WCNAON_CLK_VCO_EN_MASK       ((uint32_t)0x00180000)
/// CLK_VCO_EN field LSB position
#define WCNAON_CLK_VCO_EN_LSB        19
/// CLK_VCO_EN field width
#define WCNAON_CLK_VCO_EN_WIDTH      ((uint32_t)0x00000002)
/// CLK__80M_EN field mask
#define WCNAON_CLK__80M_EN_MASK      ((uint32_t)0x00060000)
/// CLK__80M_EN field LSB position
#define WCNAON_CLK__80M_EN_LSB       17
/// CLK__80M_EN field width
#define WCNAON_CLK__80M_EN_WIDTH     ((uint32_t)0x00000002)
/// DIVLP_5_EN field bit
#define WCNAON_DIVLP_5_EN_BIT        ((uint32_t)0x00000004)
/// DIVLP_5_EN field position
#define WCNAON_DIVLP_5_EN_POS        2
/// CLK_DIVLP_5_EN field mask
#define WCNAON_CLK_DIVLP_5_EN_MASK   ((uint32_t)0x00000003)
/// CLK_DIVLP_5_EN field LSB position
#define WCNAON_CLK_DIVLP_5_EN_LSB    0
/// CLK_DIVLP_5_EN field width
#define WCNAON_CLK_DIVLP_5_EN_WIDTH  ((uint32_t)0x00000002)

/// CLK_VCO_EN field reset value
#define WCNAON_CLK_VCO_EN_RST        0x0
/// CLK__80M_EN field reset value
#define WCNAON_CLK__80M_EN_RST       0x0
/// DIVLP_5_EN field reset value
#define WCNAON_DIVLP_5_EN_RST        0x0
/// CLK_DIVLP_5_EN field reset value
#define WCNAON_CLK_DIVLP_5_EN_RST    0x0

/**
 * @brief Constructs a value for the CM_BBPLL_REG2 register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] clkvcoen - The value to use for the clk_vco_en field.
 * @param[in] clk80men - The value to use for the clk_80m_en field.
 * @param[in] divlp5en - The value to use for the divlp5_en field.
 * @param[in] clkdivlp5en - The value to use for the clk_divlp5_en field.
 */
__INLINE void wcnaon_cm_bbpll_reg2_pack(uint8_t clkvcoen, uint8_t clk80men, uint8_t divlp5en, uint8_t clkdivlp5en)
{
    REG_PL_WR(WCNAON_CM_BBPLL_REG2_ADDR,  ((uint32_t)clkvcoen << 19) | ((uint32_t)clk80men << 17) | ((uint32_t)divlp5en << 2) | ((uint32_t)clkdivlp5en << 0));
}

/**
 * @brief Unpacks CM_BBPLL_REG2's fields from current value of the CM_BBPLL_REG2 register.
 *
 * Reads the CM_BBPLL_REG2 register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] clkvcoen - Will be populated with the current value of this field from the register.
 * @param[out] clk80men - Will be populated with the current value of this field from the register.
 * @param[out] divlp5en - Will be populated with the current value of this field from the register.
 * @param[out] clkdivlp5en - Will be populated with the current value of this field from the register.
 */
__INLINE void wcnaon_cm_bbpll_reg2_unpack(uint8_t* clkvcoen, uint8_t* clk80men, uint8_t* divlp5en, uint8_t* clkdivlp5en)
{
    uint32_t localVal = REG_PL_RD(WCNAON_CM_BBPLL_REG2_ADDR);

    *clkvcoen = (localVal & ((uint32_t)0x00180000)) >> 19;
    *clk80men = (localVal & ((uint32_t)0x00060000)) >> 17;
    *divlp5en = (localVal & ((uint32_t)0x00000004)) >> 2;
    *clkdivlp5en = (localVal & ((uint32_t)0x00000003)) >> 0;
}

/**
 * @brief Returns the current value of the clk_vco_en field in the CM_BBPLL_REG2 register.
 *
 * The CM_BBPLL_REG2 register will be read and the clk_vco_en field's value will be returned.
 *
 * @return The current value of the clk_vco_en field in the CM_BBPLL_REG2 register.
 */
__INLINE uint8_t wcnaon_clk_vco_en_getf(void)
{
    uint32_t localVal = REG_PL_RD(WCNAON_CM_BBPLL_REG2_ADDR);
    return ((localVal & ((uint32_t)0x00180000)) >> 19);
}

/**
 * @brief Sets the clk_vco_en field of the CM_BBPLL_REG2 register.
 *
 * The CM_BBPLL_REG2 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] clkvcoen - The value to set the field to.
 */
__INLINE void wcnaon_clk_vco_en_setf(uint8_t clkvcoen)
{
    REG_PL_WR(WCNAON_CM_BBPLL_REG2_ADDR, (REG_PL_RD(WCNAON_CM_BBPLL_REG2_ADDR) & ~((uint32_t)0x00180000)) | ((uint32_t)clkvcoen << 19));
}

/**
 * @brief Returns the current value of the clk_80m_en field in the CM_BBPLL_REG2 register.
 *
 * The CM_BBPLL_REG2 register will be read and the clk_80m_en field's value will be returned.
 *
 * @return The current value of the clk_80m_en field in the CM_BBPLL_REG2 register.
 */
__INLINE uint8_t wcnaon_clk__80m_en_getf(void)
{
    uint32_t localVal = REG_PL_RD(WCNAON_CM_BBPLL_REG2_ADDR);
    return ((localVal & ((uint32_t)0x00060000)) >> 17);
}

/**
 * @brief Sets the clk_80m_en field of the CM_BBPLL_REG2 register.
 *
 * The CM_BBPLL_REG2 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] clk80men - The value to set the field to.
 */
__INLINE void wcnaon_clk__80m_en_setf(uint8_t clk80men)
{
    REG_PL_WR(WCNAON_CM_BBPLL_REG2_ADDR, (REG_PL_RD(WCNAON_CM_BBPLL_REG2_ADDR) & ~((uint32_t)0x00060000)) | ((uint32_t)clk80men << 17));
}

/**
 * @brief Returns the current value of the divlp5_en field in the CM_BBPLL_REG2 register.
 *
 * The CM_BBPLL_REG2 register will be read and the divlp5_en field's value will be returned.
 *
 * @return The current value of the divlp5_en field in the CM_BBPLL_REG2 register.
 */
__INLINE uint8_t wcnaon_divlp_5_en_getf(void)
{
    uint32_t localVal = REG_PL_RD(WCNAON_CM_BBPLL_REG2_ADDR);
    return ((localVal & ((uint32_t)0x00000004)) >> 2);
}

/**
 * @brief Sets the divlp5_en field of the CM_BBPLL_REG2 register.
 *
 * The CM_BBPLL_REG2 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] divlp5en - The value to set the field to.
 */
__INLINE void wcnaon_divlp_5_en_setf(uint8_t divlp5en)
{
    REG_PL_WR(WCNAON_CM_BBPLL_REG2_ADDR, (REG_PL_RD(WCNAON_CM_BBPLL_REG2_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)divlp5en << 2));
}

/**
 * @brief Returns the current value of the clk_divlp5_en field in the CM_BBPLL_REG2 register.
 *
 * The CM_BBPLL_REG2 register will be read and the clk_divlp5_en field's value will be returned.
 *
 * @return The current value of the clk_divlp5_en field in the CM_BBPLL_REG2 register.
 */
__INLINE uint8_t wcnaon_clk_divlp_5_en_getf(void)
{
    uint32_t localVal = REG_PL_RD(WCNAON_CM_BBPLL_REG2_ADDR);
    return ((localVal & ((uint32_t)0x00000003)) >> 0);
}

/**
 * @brief Sets the clk_divlp5_en field of the CM_BBPLL_REG2 register.
 *
 * The CM_BBPLL_REG2 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] clkdivlp5en - The value to set the field to.
 */
__INLINE void wcnaon_clk_divlp_5_en_setf(uint8_t clkdivlp5en)
{
    REG_PL_WR(WCNAON_CM_BBPLL_REG2_ADDR, (REG_PL_RD(WCNAON_CM_BBPLL_REG2_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)clkdivlp5en << 0));
}

/// @}

/**
 * @name CM_BBPLL_CTRL register definitions
 * <table>
 * <caption id="CM_BBPLL_CTRL_BF">CM_BBPLL_CTRL bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>24 <td>    cm_rf_alwayson <td>R <td>R/W <td>0
 * </table>
 *
 * @{
 */

/// Address of the CM_BBPLL_CTRL register
#define WCNAON_CM_BBPLL_CTRL_ADDR   0x40580120
/// Offset of the CM_BBPLL_CTRL register from the base address
#define WCNAON_CM_BBPLL_CTRL_OFFSET 0x00000120
/// Index of the CM_BBPLL_CTRL register
#define WCNAON_CM_BBPLL_CTRL_INDEX  0x00000048
/// Reset value of the CM_BBPLL_CTRL register
#define WCNAON_CM_BBPLL_CTRL_RESET  0x00000000

/**
 * @brief Returns the current value of the CM_BBPLL_CTRL register.
 * The CM_BBPLL_CTRL register will be read and its value returned.
 * @return The current value of the CM_BBPLL_CTRL register.
 */
__INLINE uint32_t wcnaon_cm_bbpll_ctrl_get(void)
{
    return REG_PL_RD(WCNAON_CM_BBPLL_CTRL_ADDR);
}

/**
 * @brief Sets the CM_BBPLL_CTRL register to a value.
 * The CM_BBPLL_CTRL register will be written.
 * @param value - The value to write.
 */
__INLINE void wcnaon_cm_bbpll_ctrl_set(uint32_t value)
{
    REG_PL_WR(WCNAON_CM_BBPLL_CTRL_ADDR, value);
}

// field definitions
/// CM_RF_ALWAYSON field bit
#define WCNAON_CM_RF_ALWAYSON_BIT    ((uint32_t)0x01000000)
/// CM_RF_ALWAYSON field position
#define WCNAON_CM_RF_ALWAYSON_POS    24

/// CM_RF_ALWAYSON field reset value
#define WCNAON_CM_RF_ALWAYSON_RST    0x0

/**
 * @brief Returns the current value of the cm_rf_alwayson field in the CM_BBPLL_CTRL register.
 *
 * The CM_BBPLL_CTRL register will be read and the cm_rf_alwayson field's value will be returned.
 *
 * @return The current value of the cm_rf_alwayson field in the CM_BBPLL_CTRL register.
 */
__INLINE uint8_t wcnaon_cm_rf_alwayson_getf(void)
{
    uint32_t localVal = REG_PL_RD(WCNAON_CM_BBPLL_CTRL_ADDR);
    return (localVal >> 24);
}

/**
 * @brief Sets the cm_rf_alwayson field of the CM_BBPLL_CTRL register.
 *
 * The CM_BBPLL_CTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] cmrfalwayson - The value to set the field to.
 */
__INLINE void wcnaon_cm_rf_alwayson_setf(uint8_t cmrfalwayson)
{
    REG_PL_WR(WCNAON_CM_BBPLL_CTRL_ADDR, (uint32_t)cmrfalwayson << 24);
}

/// @}


#endif // _REG_WCNAON_H_

/// @}

