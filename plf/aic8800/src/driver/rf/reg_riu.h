/**
 * @file reg_riu.h
 * @brief Definitions of the RIU HW block registers and register access functions.
 *
 * @defgroup REG_RIU REG_RIU
 * @ingroup REG
 * @{
 *
 * @brief Definitions of the RIU HW block registers and register access functions.
 */
#ifndef _REG_RIU_H_
#define _REG_RIU_H_

#include "co_int.h"
#include "compiler.h"
#include "arch.h"
#include "reg_access.h"

/** @brief Number of registers in the REG_RIU peripheral.
 */
#define REG_RIU_COUNT 321

/** @brief Decoding mask of the REG_RIU peripheral registers from the CPU point of view.
 */
#define REG_RIU_DECODING_MASK 0x000007FF

/**
 * @name RWNXVERSION register definitions
 * <table>
 * <caption id="RWNXVERSION_BF">RWNXVERSION bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>31:24 <td>          RESERVED <td>W <td>R <td>0x0
 * <tr><td>23:22 <td>        AGCRAMMODE <td>W <td>R <td>0x2
 * <tr><td>21 <td>            IQCOMP <td>W <td>R <td>0
 * <tr><td>20 <td>          DSSSCORR <td>W <td>R <td>1
 * <tr><td>19 <td>           FIQCOMP <td>W <td>R <td>0
 * <tr><td>18 <td>            AGCSNR <td>W <td>R <td>1
 * <tr><td>16 <td>             RADAR <td>W <td>R <td>1
 * <tr><td>14 <td>           DSSSCCK <td>W <td>R <td>1
 * <tr><td>13:12 <td>              CHBW <td>W <td>R <td>0x2
 * <tr><td>11:08 <td>               NSS <td>W <td>R <td>0x2
 * <tr><td>07:04 <td>               NTX <td>W <td>R <td>0x2
 * <tr><td>03:00 <td>               NRX <td>W <td>R <td>0x2
 * </table>
 *
 * @{
 */

/// Address of the RWNXVERSION register
#define RIU_RWNXVERSION_ADDR   0x4033B000
/// Offset of the RWNXVERSION register from the base address
#define RIU_RWNXVERSION_OFFSET 0x00000000
/// Index of the RWNXVERSION register
#define RIU_RWNXVERSION_INDEX  0x00000000
/// Reset value of the RWNXVERSION register
#define RIU_RWNXVERSION_RESET  0x00956222

/**
 * @brief Returns the current value of the RWNXVERSION register.
 * The RWNXVERSION register will be read and its value returned.
 * @return The current value of the RWNXVERSION register.
 */
__INLINE uint32_t riu_rwnxversion_get(void)
{
    return REG_PL_RD(RIU_RWNXVERSION_ADDR);
}

// field definitions
/// RESERVED field mask
#define RIU_RESERVED_MASK     ((uint32_t)0xFF000000)
/// RESERVED field LSB position
#define RIU_RESERVED_LSB      24
/// RESERVED field width
#define RIU_RESERVED_WIDTH    ((uint32_t)0x00000008)
/// AGCRAMMODE field mask
#define RIU_AGCRAMMODE_MASK   ((uint32_t)0x00C00000)
/// AGCRAMMODE field LSB position
#define RIU_AGCRAMMODE_LSB    22
/// AGCRAMMODE field width
#define RIU_AGCRAMMODE_WIDTH  ((uint32_t)0x00000002)
/// IQCOMP field bit
#define RIU_IQCOMP_BIT        ((uint32_t)0x00200000)
/// IQCOMP field position
#define RIU_IQCOMP_POS        21
/// DSSSCORR field bit
#define RIU_DSSSCORR_BIT      ((uint32_t)0x00100000)
/// DSSSCORR field position
#define RIU_DSSSCORR_POS      20
/// FIQCOMP field bit
#define RIU_FIQCOMP_BIT       ((uint32_t)0x00080000)
/// FIQCOMP field position
#define RIU_FIQCOMP_POS       19
/// AGCSNR field bit
#define RIU_AGCSNR_BIT        ((uint32_t)0x00040000)
/// AGCSNR field position
#define RIU_AGCSNR_POS        18
/// RADAR field bit
#define RIU_RADAR_BIT         ((uint32_t)0x00010000)
/// RADAR field position
#define RIU_RADAR_POS         16
/// DSSSCCK field bit
#define RIU_DSSSCCK_BIT       ((uint32_t)0x00004000)
/// DSSSCCK field position
#define RIU_DSSSCCK_POS       14
/// CHBW field mask
#define RIU_CHBW_MASK         ((uint32_t)0x00003000)
/// CHBW field LSB position
#define RIU_CHBW_LSB          12
/// CHBW field width
#define RIU_CHBW_WIDTH        ((uint32_t)0x00000002)
/// NSS field mask
#define RIU_NSS_MASK          ((uint32_t)0x00000F00)
/// NSS field LSB position
#define RIU_NSS_LSB           8
/// NSS field width
#define RIU_NSS_WIDTH         ((uint32_t)0x00000004)
/// NTX field mask
#define RIU_NTX_MASK          ((uint32_t)0x000000F0)
/// NTX field LSB position
#define RIU_NTX_LSB           4
/// NTX field width
#define RIU_NTX_WIDTH         ((uint32_t)0x00000004)
/// NRX field mask
#define RIU_NRX_MASK          ((uint32_t)0x0000000F)
/// NRX field LSB position
#define RIU_NRX_LSB           0
/// NRX field width
#define RIU_NRX_WIDTH         ((uint32_t)0x00000004)

/// RESERVED field reset value
#define RIU_RESERVED_RST      0x0
/// AGCRAMMODE field reset value
#define RIU_AGCRAMMODE_RST    0x2
/// IQCOMP field reset value
#define RIU_IQCOMP_RST        0x0
/// DSSSCORR field reset value
#define RIU_DSSSCORR_RST      0x1
/// FIQCOMP field reset value
#define RIU_FIQCOMP_RST       0x0
/// AGCSNR field reset value
#define RIU_AGCSNR_RST        0x1
/// RADAR field reset value
#define RIU_RADAR_RST         0x1
/// DSSSCCK field reset value
#define RIU_DSSSCCK_RST       0x1
/// CHBW field reset value
#define RIU_CHBW_RST          0x2
/// NSS field reset value
#define RIU_NSS_RST           0x2
/// NTX field reset value
#define RIU_NTX_RST           0x2
/// NRX field reset value
#define RIU_NRX_RST           0x2

/**
 * @brief Unpacks RWNXVERSION's fields from current value of the RWNXVERSION register.
 *
 * Reads the RWNXVERSION register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] reserved - Will be populated with the current value of this field from the register.
 * @param[out] agcrammode - Will be populated with the current value of this field from the register.
 * @param[out] iqcomp - Will be populated with the current value of this field from the register.
 * @param[out] dssscorr - Will be populated with the current value of this field from the register.
 * @param[out] fiqcomp - Will be populated with the current value of this field from the register.
 * @param[out] agcsnr - Will be populated with the current value of this field from the register.
 * @param[out] radar - Will be populated with the current value of this field from the register.
 * @param[out] dssscck - Will be populated with the current value of this field from the register.
 * @param[out] chbw - Will be populated with the current value of this field from the register.
 * @param[out] nss - Will be populated with the current value of this field from the register.
 * @param[out] ntx - Will be populated with the current value of this field from the register.
 * @param[out] nrx - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxversion_unpack(uint8_t* reserved, uint8_t* agcrammode, uint8_t* iqcomp, uint8_t* dssscorr, uint8_t* fiqcomp, uint8_t* agcsnr, uint8_t* radar, uint8_t* dssscck, uint8_t* chbw, uint8_t* nss, uint8_t* ntx, uint8_t* nrx)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXVERSION_ADDR);

    *reserved = (localVal & ((uint32_t)0xFF000000)) >> 24;
    *agcrammode = (localVal & ((uint32_t)0x00C00000)) >> 22;
    *iqcomp = (localVal & ((uint32_t)0x00200000)) >> 21;
    *dssscorr = (localVal & ((uint32_t)0x00100000)) >> 20;
    *fiqcomp = (localVal & ((uint32_t)0x00080000)) >> 19;
    *agcsnr = (localVal & ((uint32_t)0x00040000)) >> 18;
    *radar = (localVal & ((uint32_t)0x00010000)) >> 16;
    *dssscck = (localVal & ((uint32_t)0x00004000)) >> 14;
    *chbw = (localVal & ((uint32_t)0x00003000)) >> 12;
    *nss = (localVal & ((uint32_t)0x00000F00)) >> 8;
    *ntx = (localVal & ((uint32_t)0x000000F0)) >> 4;
    *nrx = (localVal & ((uint32_t)0x0000000F)) >> 0;
}

/**
 * @brief Returns the current value of the RESERVED field in the RWNXVERSION register.
 *
 * The RWNXVERSION register will be read and the RESERVED field's value will be returned.
 *
 * @return The current value of the RESERVED field in the RWNXVERSION register.
 */
__INLINE uint8_t riu_reserved_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXVERSION_ADDR);
    return ((localVal & ((uint32_t)0xFF000000)) >> 24);
}

/**
 * @brief Returns the current value of the AGCRAMMODE field in the RWNXVERSION register.
 *
 * The RWNXVERSION register will be read and the AGCRAMMODE field's value will be returned.
 *
 * @return The current value of the AGCRAMMODE field in the RWNXVERSION register.
 */
__INLINE uint8_t riu_agcrammode_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXVERSION_ADDR);
    return ((localVal & ((uint32_t)0x00C00000)) >> 22);
}

/**
 * @brief Returns the current value of the IQCOMP field in the RWNXVERSION register.
 *
 * The RWNXVERSION register will be read and the IQCOMP field's value will be returned.
 *
 * @return The current value of the IQCOMP field in the RWNXVERSION register.
 */
__INLINE uint8_t riu_iqcomp_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXVERSION_ADDR);
    return ((localVal & ((uint32_t)0x00200000)) >> 21);
}

/**
 * @brief Returns the current value of the DSSSCORR field in the RWNXVERSION register.
 *
 * The RWNXVERSION register will be read and the DSSSCORR field's value will be returned.
 *
 * @return The current value of the DSSSCORR field in the RWNXVERSION register.
 */
__INLINE uint8_t riu_dssscorr_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXVERSION_ADDR);
    return ((localVal & ((uint32_t)0x00100000)) >> 20);
}

/**
 * @brief Returns the current value of the FIQCOMP field in the RWNXVERSION register.
 *
 * The RWNXVERSION register will be read and the FIQCOMP field's value will be returned.
 *
 * @return The current value of the FIQCOMP field in the RWNXVERSION register.
 */
__INLINE uint8_t riu_fiqcomp_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXVERSION_ADDR);
    return ((localVal & ((uint32_t)0x00080000)) >> 19);
}

/**
 * @brief Returns the current value of the AGCSNR field in the RWNXVERSION register.
 *
 * The RWNXVERSION register will be read and the AGCSNR field's value will be returned.
 *
 * @return The current value of the AGCSNR field in the RWNXVERSION register.
 */
__INLINE uint8_t riu_agcsnr_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXVERSION_ADDR);
    return ((localVal & ((uint32_t)0x00040000)) >> 18);
}

/**
 * @brief Returns the current value of the RADAR field in the RWNXVERSION register.
 *
 * The RWNXVERSION register will be read and the RADAR field's value will be returned.
 *
 * @return The current value of the RADAR field in the RWNXVERSION register.
 */
__INLINE uint8_t riu_radar_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXVERSION_ADDR);
    return ((localVal & ((uint32_t)0x00010000)) >> 16);
}

/**
 * @brief Returns the current value of the DSSSCCK field in the RWNXVERSION register.
 *
 * The RWNXVERSION register will be read and the DSSSCCK field's value will be returned.
 *
 * @return The current value of the DSSSCCK field in the RWNXVERSION register.
 */
__INLINE uint8_t riu_dssscck_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXVERSION_ADDR);
    return ((localVal & ((uint32_t)0x00004000)) >> 14);
}

/**
 * @brief Returns the current value of the CHBW field in the RWNXVERSION register.
 *
 * The RWNXVERSION register will be read and the CHBW field's value will be returned.
 *
 * @return The current value of the CHBW field in the RWNXVERSION register.
 */
__INLINE uint8_t riu_chbw_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXVERSION_ADDR);
    return ((localVal & ((uint32_t)0x00003000)) >> 12);
}

/**
 * @brief Returns the current value of the NSS field in the RWNXVERSION register.
 *
 * The RWNXVERSION register will be read and the NSS field's value will be returned.
 *
 * @return The current value of the NSS field in the RWNXVERSION register.
 */
__INLINE uint8_t riu_nss_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXVERSION_ADDR);
    return ((localVal & ((uint32_t)0x00000F00)) >> 8);
}

/**
 * @brief Returns the current value of the NTX field in the RWNXVERSION register.
 *
 * The RWNXVERSION register will be read and the NTX field's value will be returned.
 *
 * @return The current value of the NTX field in the RWNXVERSION register.
 */
__INLINE uint8_t riu_ntx_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXVERSION_ADDR);
    return ((localVal & ((uint32_t)0x000000F0)) >> 4);
}

/**
 * @brief Returns the current value of the NRX field in the RWNXVERSION register.
 *
 * The RWNXVERSION register will be read and the NRX field's value will be returned.
 *
 * @return The current value of the NRX field in the RWNXVERSION register.
 */
__INLINE uint8_t riu_nrx_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXVERSION_ADDR);
    return ((localVal & ((uint32_t)0x0000000F)) >> 0);
}

/// @}

/**
 * @name RWNXSTATICCONFIG register definitions
 * <table>
 * <caption id="RWNXSTATICCONFIG_BF">RWNXSTATICCONFIG bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>01:00 <td>         ACTIVEANT <td>R <td>R/W <td>0x0
 * </table>
 *
 * @{
 */

/// Address of the RWNXSTATICCONFIG register
#define RIU_RWNXSTATICCONFIG_ADDR   0x4033B004
/// Offset of the RWNXSTATICCONFIG register from the base address
#define RIU_RWNXSTATICCONFIG_OFFSET 0x00000004
/// Index of the RWNXSTATICCONFIG register
#define RIU_RWNXSTATICCONFIG_INDEX  0x00000001
/// Reset value of the RWNXSTATICCONFIG register
#define RIU_RWNXSTATICCONFIG_RESET  0x00000000

/**
 * @brief Returns the current value of the RWNXSTATICCONFIG register.
 * The RWNXSTATICCONFIG register will be read and its value returned.
 * @return The current value of the RWNXSTATICCONFIG register.
 */
__INLINE uint32_t riu_rwnxstaticconfig_get(void)
{
    return REG_PL_RD(RIU_RWNXSTATICCONFIG_ADDR);
}

/**
 * @brief Sets the RWNXSTATICCONFIG register to a value.
 * The RWNXSTATICCONFIG register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxstaticconfig_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXSTATICCONFIG_ADDR, value);
}

// field definitions
/// ACTIVEANT field mask
#define RIU_ACTIVEANT_MASK   ((uint32_t)0x00000003)
/// ACTIVEANT field LSB position
#define RIU_ACTIVEANT_LSB    0
/// ACTIVEANT field width
#define RIU_ACTIVEANT_WIDTH  ((uint32_t)0x00000002)

/// ACTIVEANT field reset value
#define RIU_ACTIVEANT_RST    0x0

/**
 * @brief Returns the current value of the ACTIVEANT field in the RWNXSTATICCONFIG register.
 *
 * The RWNXSTATICCONFIG register will be read and the ACTIVEANT field's value will be returned.
 *
 * @return The current value of the ACTIVEANT field in the RWNXSTATICCONFIG register.
 */
__INLINE uint8_t riu_activeant_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXSTATICCONFIG_ADDR);
    return (localVal >> 0);
}

/**
 * @brief Sets the ACTIVEANT field of the RWNXSTATICCONFIG register.
 *
 * The RWNXSTATICCONFIG register will be read, modified to contain the new field value, and written.
 *
 * @param[in] activeant - The value to set the field to.
 */
__INLINE void riu_activeant_setf(uint8_t activeant)
{
    REG_PL_WR(RIU_RWNXSTATICCONFIG_ADDR, (uint32_t)activeant << 0);
}

/// @}

/**
 * @name RWNXDYNAMICCONFIG register definitions
 * <table>
 * <caption id="RWNXDYNAMICCONFIG_BF">RWNXDYNAMICCONFIG bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>16 <td>AGCINBDPOWSTARTCAPTURE <td>R/W <td>R/W <td>0
 * </table>
 *
 * @{
 */

/// Address of the RWNXDYNAMICCONFIG register
#define RIU_RWNXDYNAMICCONFIG_ADDR   0x4033B008
/// Offset of the RWNXDYNAMICCONFIG register from the base address
#define RIU_RWNXDYNAMICCONFIG_OFFSET 0x00000008
/// Index of the RWNXDYNAMICCONFIG register
#define RIU_RWNXDYNAMICCONFIG_INDEX  0x00000002
/// Reset value of the RWNXDYNAMICCONFIG register
#define RIU_RWNXDYNAMICCONFIG_RESET  0x00000000

/**
 * @brief Returns the current value of the RWNXDYNAMICCONFIG register.
 * The RWNXDYNAMICCONFIG register will be read and its value returned.
 * @return The current value of the RWNXDYNAMICCONFIG register.
 */
__INLINE uint32_t riu_rwnxdynamicconfig_get(void)
{
    return REG_PL_RD(RIU_RWNXDYNAMICCONFIG_ADDR);
}

/**
 * @brief Sets the RWNXDYNAMICCONFIG register to a value.
 * The RWNXDYNAMICCONFIG register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxdynamicconfig_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXDYNAMICCONFIG_ADDR, value);
}

// field definitions
/// AGCINBDPOWSTARTCAPTURE field bit
#define RIU_AGCINBDPOWSTARTCAPTURE_BIT    ((uint32_t)0x00010000)
/// AGCINBDPOWSTARTCAPTURE field position
#define RIU_AGCINBDPOWSTARTCAPTURE_POS    16

/// AGCINBDPOWSTARTCAPTURE field reset value
#define RIU_AGCINBDPOWSTARTCAPTURE_RST    0x0

/**
 * @brief Returns the current value of the AGCINBDPOWSTARTCAPTURE field in the RWNXDYNAMICCONFIG register.
 *
 * The RWNXDYNAMICCONFIG register will be read and the AGCINBDPOWSTARTCAPTURE field's value will be returned.
 *
 * @return The current value of the AGCINBDPOWSTARTCAPTURE field in the RWNXDYNAMICCONFIG register.
 */
__INLINE uint8_t riu_agcinbdpowstartcapture_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXDYNAMICCONFIG_ADDR);
    return (localVal >> 16);
}

/**
 * @brief Sets the AGCINBDPOWSTARTCAPTURE field of the RWNXDYNAMICCONFIG register.
 *
 * The RWNXDYNAMICCONFIG register will be read, modified to contain the new field value, and written.
 *
 * @param[in] agcinbdpowstartcapture - The value to set the field to.
 */
__INLINE void riu_agcinbdpowstartcapture_setf(uint8_t agcinbdpowstartcapture)
{
    REG_PL_WR(RIU_RWNXDYNAMICCONFIG_ADDR, (uint32_t)agcinbdpowstartcapture << 16);
}

/// @}

/**
 * @name RWNXIQCTRL register definitions
 * <table>
 * <caption id="RWNXIQCTRL_BF">RWNXIQCTRL bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>28 <td>     TXIQSWAPPATH1 <td>R <td>R/W <td>0
 * <tr><td>27 <td>     TXIQSWAPPATH0 <td>R <td>R/W <td>0
 * <tr><td>23 <td>     RXIQSWAPPATH1 <td>R <td>R/W <td>0
 * <tr><td>22 <td>     RXIQSWAPPATH0 <td>R <td>R/W <td>0
 * <tr><td>15 <td>     TXIQDELPATHQ1 <td>R <td>R/W <td>0
 * <tr><td>14 <td>     TXIQDELPATHI1 <td>R <td>R/W <td>0
 * <tr><td>13 <td>     TXIQDELPATHQ0 <td>R <td>R/W <td>0
 * <tr><td>12 <td>     TXIQDELPATHI0 <td>R <td>R/W <td>0
 * <tr><td>05 <td>     RXIQDELPATHQ1 <td>R <td>R/W <td>0
 * <tr><td>04 <td>     RXIQDELPATHI1 <td>R <td>R/W <td>0
 * <tr><td>03 <td>     RXIQDELPATHQ0 <td>R <td>R/W <td>0
 * <tr><td>02 <td>     RXIQDELPATHI0 <td>R <td>R/W <td>0
 * <tr><td>01 <td>      TXC2SDISBCFG <td>R <td>R/W <td>0
 * <tr><td>00 <td>      RXC2SDISBCFG <td>R <td>R/W <td>0
 * </table>
 *
 * @{
 */

/// Address of the RWNXIQCTRL register
#define RIU_RWNXIQCTRL_ADDR   0x4033B01C
/// Offset of the RWNXIQCTRL register from the base address
#define RIU_RWNXIQCTRL_OFFSET 0x0000001C
/// Index of the RWNXIQCTRL register
#define RIU_RWNXIQCTRL_INDEX  0x00000007
/// Reset value of the RWNXIQCTRL register
#define RIU_RWNXIQCTRL_RESET  0x00000000

/**
 * @brief Returns the current value of the RWNXIQCTRL register.
 * The RWNXIQCTRL register will be read and its value returned.
 * @return The current value of the RWNXIQCTRL register.
 */
__INLINE uint32_t riu_rwnxiqctrl_get(void)
{
    return REG_PL_RD(RIU_RWNXIQCTRL_ADDR);
}

/**
 * @brief Sets the RWNXIQCTRL register to a value.
 * The RWNXIQCTRL register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxiqctrl_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXIQCTRL_ADDR, value);
}

// field definitions
/// TXIQSWAPPATH1 field bit
#define RIU_TXIQSWAPPATH1_BIT    ((uint32_t)0x10000000)
/// TXIQSWAPPATH1 field position
#define RIU_TXIQSWAPPATH1_POS    28
/// TXIQSWAPPATH0 field bit
#define RIU_TXIQSWAPPATH0_BIT    ((uint32_t)0x08000000)
/// TXIQSWAPPATH0 field position
#define RIU_TXIQSWAPPATH0_POS    27
/// RXIQSWAPPATH1 field bit
#define RIU_RXIQSWAPPATH1_BIT    ((uint32_t)0x00800000)
/// RXIQSWAPPATH1 field position
#define RIU_RXIQSWAPPATH1_POS    23
/// RXIQSWAPPATH0 field bit
#define RIU_RXIQSWAPPATH0_BIT    ((uint32_t)0x00400000)
/// RXIQSWAPPATH0 field position
#define RIU_RXIQSWAPPATH0_POS    22
/// TXIQDELPATHQ1 field bit
#define RIU_TXIQDELPATHQ1_BIT    ((uint32_t)0x00008000)
/// TXIQDELPATHQ1 field position
#define RIU_TXIQDELPATHQ1_POS    15
/// TXIQDELPATHI1 field bit
#define RIU_TXIQDELPATHI1_BIT    ((uint32_t)0x00004000)
/// TXIQDELPATHI1 field position
#define RIU_TXIQDELPATHI1_POS    14
/// TXIQDELPATHQ0 field bit
#define RIU_TXIQDELPATHQ0_BIT    ((uint32_t)0x00002000)
/// TXIQDELPATHQ0 field position
#define RIU_TXIQDELPATHQ0_POS    13
/// TXIQDELPATHI0 field bit
#define RIU_TXIQDELPATHI0_BIT    ((uint32_t)0x00001000)
/// TXIQDELPATHI0 field position
#define RIU_TXIQDELPATHI0_POS    12
/// RXIQDELPATHQ1 field bit
#define RIU_RXIQDELPATHQ1_BIT    ((uint32_t)0x00000020)
/// RXIQDELPATHQ1 field position
#define RIU_RXIQDELPATHQ1_POS    5
/// RXIQDELPATHI1 field bit
#define RIU_RXIQDELPATHI1_BIT    ((uint32_t)0x00000010)
/// RXIQDELPATHI1 field position
#define RIU_RXIQDELPATHI1_POS    4
/// RXIQDELPATHQ0 field bit
#define RIU_RXIQDELPATHQ0_BIT    ((uint32_t)0x00000008)
/// RXIQDELPATHQ0 field position
#define RIU_RXIQDELPATHQ0_POS    3
/// RXIQDELPATHI0 field bit
#define RIU_RXIQDELPATHI0_BIT    ((uint32_t)0x00000004)
/// RXIQDELPATHI0 field position
#define RIU_RXIQDELPATHI0_POS    2
/// TXC2SDISBCFG field bit
#define RIU_TXC2SDISBCFG_BIT     ((uint32_t)0x00000002)
/// TXC2SDISBCFG field position
#define RIU_TXC2SDISBCFG_POS     1
/// RXC2SDISBCFG field bit
#define RIU_RXC2SDISBCFG_BIT     ((uint32_t)0x00000001)
/// RXC2SDISBCFG field position
#define RIU_RXC2SDISBCFG_POS     0

/// TXIQSWAPPATH1 field reset value
#define RIU_TXIQSWAPPATH1_RST    0x0
/// TXIQSWAPPATH0 field reset value
#define RIU_TXIQSWAPPATH0_RST    0x0
/// RXIQSWAPPATH1 field reset value
#define RIU_RXIQSWAPPATH1_RST    0x0
/// RXIQSWAPPATH0 field reset value
#define RIU_RXIQSWAPPATH0_RST    0x0
/// TXIQDELPATHQ1 field reset value
#define RIU_TXIQDELPATHQ1_RST    0x0
/// TXIQDELPATHI1 field reset value
#define RIU_TXIQDELPATHI1_RST    0x0
/// TXIQDELPATHQ0 field reset value
#define RIU_TXIQDELPATHQ0_RST    0x0
/// TXIQDELPATHI0 field reset value
#define RIU_TXIQDELPATHI0_RST    0x0
/// RXIQDELPATHQ1 field reset value
#define RIU_RXIQDELPATHQ1_RST    0x0
/// RXIQDELPATHI1 field reset value
#define RIU_RXIQDELPATHI1_RST    0x0
/// RXIQDELPATHQ0 field reset value
#define RIU_RXIQDELPATHQ0_RST    0x0
/// RXIQDELPATHI0 field reset value
#define RIU_RXIQDELPATHI0_RST    0x0
/// TXC2SDISBCFG field reset value
#define RIU_TXC2SDISBCFG_RST     0x0
/// RXC2SDISBCFG field reset value
#define RIU_RXC2SDISBCFG_RST     0x0

/**
 * @brief Constructs a value for the RWNXIQCTRL register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] txiqswappath1 - The value to use for the TXIQSWAPPATH1 field.
 * @param[in] txiqswappath0 - The value to use for the TXIQSWAPPATH0 field.
 * @param[in] rxiqswappath1 - The value to use for the RXIQSWAPPATH1 field.
 * @param[in] rxiqswappath0 - The value to use for the RXIQSWAPPATH0 field.
 * @param[in] txiqdelpathq1 - The value to use for the TXIQDELPATHQ1 field.
 * @param[in] txiqdelpathi1 - The value to use for the TXIQDELPATHI1 field.
 * @param[in] txiqdelpathq0 - The value to use for the TXIQDELPATHQ0 field.
 * @param[in] txiqdelpathi0 - The value to use for the TXIQDELPATHI0 field.
 * @param[in] rxiqdelpathq1 - The value to use for the RXIQDELPATHQ1 field.
 * @param[in] rxiqdelpathi1 - The value to use for the RXIQDELPATHI1 field.
 * @param[in] rxiqdelpathq0 - The value to use for the RXIQDELPATHQ0 field.
 * @param[in] rxiqdelpathi0 - The value to use for the RXIQDELPATHI0 field.
 * @param[in] txc2sdisbcfg - The value to use for the TXC2SDISBCFG field.
 * @param[in] rxc2sdisbcfg - The value to use for the RXC2SDISBCFG field.
 */
__INLINE void riu_rwnxiqctrl_pack(uint8_t txiqswappath1, uint8_t txiqswappath0, uint8_t rxiqswappath1, uint8_t rxiqswappath0, uint8_t txiqdelpathq1, uint8_t txiqdelpathi1, uint8_t txiqdelpathq0, uint8_t txiqdelpathi0, uint8_t rxiqdelpathq1, uint8_t rxiqdelpathi1, uint8_t rxiqdelpathq0, uint8_t rxiqdelpathi0, uint8_t txc2sdisbcfg, uint8_t rxc2sdisbcfg)
{
    REG_PL_WR(RIU_RWNXIQCTRL_ADDR,  ((uint32_t)txiqswappath1 << 28) | ((uint32_t)txiqswappath0 << 27) | ((uint32_t)rxiqswappath1 << 23) | ((uint32_t)rxiqswappath0 << 22) | ((uint32_t)txiqdelpathq1 << 15) | ((uint32_t)txiqdelpathi1 << 14) | ((uint32_t)txiqdelpathq0 << 13) | ((uint32_t)txiqdelpathi0 << 12) | ((uint32_t)rxiqdelpathq1 << 5) | ((uint32_t)rxiqdelpathi1 << 4) | ((uint32_t)rxiqdelpathq0 << 3) | ((uint32_t)rxiqdelpathi0 << 2) | ((uint32_t)txc2sdisbcfg << 1) | ((uint32_t)rxc2sdisbcfg << 0));
}

/**
 * @brief Unpacks RWNXIQCTRL's fields from current value of the RWNXIQCTRL register.
 *
 * Reads the RWNXIQCTRL register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] txiqswappath1 - Will be populated with the current value of this field from the register.
 * @param[out] txiqswappath0 - Will be populated with the current value of this field from the register.
 * @param[out] rxiqswappath1 - Will be populated with the current value of this field from the register.
 * @param[out] rxiqswappath0 - Will be populated with the current value of this field from the register.
 * @param[out] txiqdelpathq1 - Will be populated with the current value of this field from the register.
 * @param[out] txiqdelpathi1 - Will be populated with the current value of this field from the register.
 * @param[out] txiqdelpathq0 - Will be populated with the current value of this field from the register.
 * @param[out] txiqdelpathi0 - Will be populated with the current value of this field from the register.
 * @param[out] rxiqdelpathq1 - Will be populated with the current value of this field from the register.
 * @param[out] rxiqdelpathi1 - Will be populated with the current value of this field from the register.
 * @param[out] rxiqdelpathq0 - Will be populated with the current value of this field from the register.
 * @param[out] rxiqdelpathi0 - Will be populated with the current value of this field from the register.
 * @param[out] txc2sdisbcfg - Will be populated with the current value of this field from the register.
 * @param[out] rxc2sdisbcfg - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxiqctrl_unpack(uint8_t* txiqswappath1, uint8_t* txiqswappath0, uint8_t* rxiqswappath1, uint8_t* rxiqswappath0, uint8_t* txiqdelpathq1, uint8_t* txiqdelpathi1, uint8_t* txiqdelpathq0, uint8_t* txiqdelpathi0, uint8_t* rxiqdelpathq1, uint8_t* rxiqdelpathi1, uint8_t* rxiqdelpathq0, uint8_t* rxiqdelpathi0, uint8_t* txc2sdisbcfg, uint8_t* rxc2sdisbcfg)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXIQCTRL_ADDR);

    *txiqswappath1 = (localVal & ((uint32_t)0x10000000)) >> 28;
    *txiqswappath0 = (localVal & ((uint32_t)0x08000000)) >> 27;
    *rxiqswappath1 = (localVal & ((uint32_t)0x00800000)) >> 23;
    *rxiqswappath0 = (localVal & ((uint32_t)0x00400000)) >> 22;
    *txiqdelpathq1 = (localVal & ((uint32_t)0x00008000)) >> 15;
    *txiqdelpathi1 = (localVal & ((uint32_t)0x00004000)) >> 14;
    *txiqdelpathq0 = (localVal & ((uint32_t)0x00002000)) >> 13;
    *txiqdelpathi0 = (localVal & ((uint32_t)0x00001000)) >> 12;
    *rxiqdelpathq1 = (localVal & ((uint32_t)0x00000020)) >> 5;
    *rxiqdelpathi1 = (localVal & ((uint32_t)0x00000010)) >> 4;
    *rxiqdelpathq0 = (localVal & ((uint32_t)0x00000008)) >> 3;
    *rxiqdelpathi0 = (localVal & ((uint32_t)0x00000004)) >> 2;
    *txc2sdisbcfg = (localVal & ((uint32_t)0x00000002)) >> 1;
    *rxc2sdisbcfg = (localVal & ((uint32_t)0x00000001)) >> 0;
}

/**
 * @brief Returns the current value of the TXIQSWAPPATH1 field in the RWNXIQCTRL register.
 *
 * The RWNXIQCTRL register will be read and the TXIQSWAPPATH1 field's value will be returned.
 *
 * @return The current value of the TXIQSWAPPATH1 field in the RWNXIQCTRL register.
 */
__INLINE uint8_t riu_txiqswappath1_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXIQCTRL_ADDR);
    return ((localVal & ((uint32_t)0x10000000)) >> 28);
}

/**
 * @brief Sets the TXIQSWAPPATH1 field of the RWNXIQCTRL register.
 *
 * The RWNXIQCTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] txiqswappath1 - The value to set the field to.
 */
__INLINE void riu_txiqswappath1_setf(uint8_t txiqswappath1)
{
    REG_PL_WR(RIU_RWNXIQCTRL_ADDR, (REG_PL_RD(RIU_RWNXIQCTRL_ADDR) & ~((uint32_t)0x10000000)) | ((uint32_t)txiqswappath1 << 28));
}

/**
 * @brief Returns the current value of the TXIQSWAPPATH0 field in the RWNXIQCTRL register.
 *
 * The RWNXIQCTRL register will be read and the TXIQSWAPPATH0 field's value will be returned.
 *
 * @return The current value of the TXIQSWAPPATH0 field in the RWNXIQCTRL register.
 */
__INLINE uint8_t riu_txiqswappath0_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXIQCTRL_ADDR);
    return ((localVal & ((uint32_t)0x08000000)) >> 27);
}

/**
 * @brief Sets the TXIQSWAPPATH0 field of the RWNXIQCTRL register.
 *
 * The RWNXIQCTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] txiqswappath0 - The value to set the field to.
 */
__INLINE void riu_txiqswappath0_setf(uint8_t txiqswappath0)
{
    REG_PL_WR(RIU_RWNXIQCTRL_ADDR, (REG_PL_RD(RIU_RWNXIQCTRL_ADDR) & ~((uint32_t)0x08000000)) | ((uint32_t)txiqswappath0 << 27));
}

/**
 * @brief Returns the current value of the RXIQSWAPPATH1 field in the RWNXIQCTRL register.
 *
 * The RWNXIQCTRL register will be read and the RXIQSWAPPATH1 field's value will be returned.
 *
 * @return The current value of the RXIQSWAPPATH1 field in the RWNXIQCTRL register.
 */
__INLINE uint8_t riu_rxiqswappath1_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXIQCTRL_ADDR);
    return ((localVal & ((uint32_t)0x00800000)) >> 23);
}

/**
 * @brief Sets the RXIQSWAPPATH1 field of the RWNXIQCTRL register.
 *
 * The RWNXIQCTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rxiqswappath1 - The value to set the field to.
 */
__INLINE void riu_rxiqswappath1_setf(uint8_t rxiqswappath1)
{
    REG_PL_WR(RIU_RWNXIQCTRL_ADDR, (REG_PL_RD(RIU_RWNXIQCTRL_ADDR) & ~((uint32_t)0x00800000)) | ((uint32_t)rxiqswappath1 << 23));
}

/**
 * @brief Returns the current value of the RXIQSWAPPATH0 field in the RWNXIQCTRL register.
 *
 * The RWNXIQCTRL register will be read and the RXIQSWAPPATH0 field's value will be returned.
 *
 * @return The current value of the RXIQSWAPPATH0 field in the RWNXIQCTRL register.
 */
__INLINE uint8_t riu_rxiqswappath0_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXIQCTRL_ADDR);
    return ((localVal & ((uint32_t)0x00400000)) >> 22);
}

/**
 * @brief Sets the RXIQSWAPPATH0 field of the RWNXIQCTRL register.
 *
 * The RWNXIQCTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rxiqswappath0 - The value to set the field to.
 */
__INLINE void riu_rxiqswappath0_setf(uint8_t rxiqswappath0)
{
    REG_PL_WR(RIU_RWNXIQCTRL_ADDR, (REG_PL_RD(RIU_RWNXIQCTRL_ADDR) & ~((uint32_t)0x00400000)) | ((uint32_t)rxiqswappath0 << 22));
}

/**
 * @brief Returns the current value of the TXIQDELPATHQ1 field in the RWNXIQCTRL register.
 *
 * The RWNXIQCTRL register will be read and the TXIQDELPATHQ1 field's value will be returned.
 *
 * @return The current value of the TXIQDELPATHQ1 field in the RWNXIQCTRL register.
 */
__INLINE uint8_t riu_txiqdelpathq1_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXIQCTRL_ADDR);
    return ((localVal & ((uint32_t)0x00008000)) >> 15);
}

/**
 * @brief Sets the TXIQDELPATHQ1 field of the RWNXIQCTRL register.
 *
 * The RWNXIQCTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] txiqdelpathq1 - The value to set the field to.
 */
__INLINE void riu_txiqdelpathq1_setf(uint8_t txiqdelpathq1)
{
    REG_PL_WR(RIU_RWNXIQCTRL_ADDR, (REG_PL_RD(RIU_RWNXIQCTRL_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)txiqdelpathq1 << 15));
}

/**
 * @brief Returns the current value of the TXIQDELPATHI1 field in the RWNXIQCTRL register.
 *
 * The RWNXIQCTRL register will be read and the TXIQDELPATHI1 field's value will be returned.
 *
 * @return The current value of the TXIQDELPATHI1 field in the RWNXIQCTRL register.
 */
__INLINE uint8_t riu_txiqdelpathi1_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXIQCTRL_ADDR);
    return ((localVal & ((uint32_t)0x00004000)) >> 14);
}

/**
 * @brief Sets the TXIQDELPATHI1 field of the RWNXIQCTRL register.
 *
 * The RWNXIQCTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] txiqdelpathi1 - The value to set the field to.
 */
__INLINE void riu_txiqdelpathi1_setf(uint8_t txiqdelpathi1)
{
    REG_PL_WR(RIU_RWNXIQCTRL_ADDR, (REG_PL_RD(RIU_RWNXIQCTRL_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)txiqdelpathi1 << 14));
}

/**
 * @brief Returns the current value of the TXIQDELPATHQ0 field in the RWNXIQCTRL register.
 *
 * The RWNXIQCTRL register will be read and the TXIQDELPATHQ0 field's value will be returned.
 *
 * @return The current value of the TXIQDELPATHQ0 field in the RWNXIQCTRL register.
 */
__INLINE uint8_t riu_txiqdelpathq0_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXIQCTRL_ADDR);
    return ((localVal & ((uint32_t)0x00002000)) >> 13);
}

/**
 * @brief Sets the TXIQDELPATHQ0 field of the RWNXIQCTRL register.
 *
 * The RWNXIQCTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] txiqdelpathq0 - The value to set the field to.
 */
__INLINE void riu_txiqdelpathq0_setf(uint8_t txiqdelpathq0)
{
    REG_PL_WR(RIU_RWNXIQCTRL_ADDR, (REG_PL_RD(RIU_RWNXIQCTRL_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)txiqdelpathq0 << 13));
}

/**
 * @brief Returns the current value of the TXIQDELPATHI0 field in the RWNXIQCTRL register.
 *
 * The RWNXIQCTRL register will be read and the TXIQDELPATHI0 field's value will be returned.
 *
 * @return The current value of the TXIQDELPATHI0 field in the RWNXIQCTRL register.
 */
__INLINE uint8_t riu_txiqdelpathi0_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXIQCTRL_ADDR);
    return ((localVal & ((uint32_t)0x00001000)) >> 12);
}

/**
 * @brief Sets the TXIQDELPATHI0 field of the RWNXIQCTRL register.
 *
 * The RWNXIQCTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] txiqdelpathi0 - The value to set the field to.
 */
__INLINE void riu_txiqdelpathi0_setf(uint8_t txiqdelpathi0)
{
    REG_PL_WR(RIU_RWNXIQCTRL_ADDR, (REG_PL_RD(RIU_RWNXIQCTRL_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)txiqdelpathi0 << 12));
}

/**
 * @brief Returns the current value of the RXIQDELPATHQ1 field in the RWNXIQCTRL register.
 *
 * The RWNXIQCTRL register will be read and the RXIQDELPATHQ1 field's value will be returned.
 *
 * @return The current value of the RXIQDELPATHQ1 field in the RWNXIQCTRL register.
 */
__INLINE uint8_t riu_rxiqdelpathq1_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXIQCTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000020)) >> 5);
}

/**
 * @brief Sets the RXIQDELPATHQ1 field of the RWNXIQCTRL register.
 *
 * The RWNXIQCTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rxiqdelpathq1 - The value to set the field to.
 */
__INLINE void riu_rxiqdelpathq1_setf(uint8_t rxiqdelpathq1)
{
    REG_PL_WR(RIU_RWNXIQCTRL_ADDR, (REG_PL_RD(RIU_RWNXIQCTRL_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)rxiqdelpathq1 << 5));
}

/**
 * @brief Returns the current value of the RXIQDELPATHI1 field in the RWNXIQCTRL register.
 *
 * The RWNXIQCTRL register will be read and the RXIQDELPATHI1 field's value will be returned.
 *
 * @return The current value of the RXIQDELPATHI1 field in the RWNXIQCTRL register.
 */
__INLINE uint8_t riu_rxiqdelpathi1_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXIQCTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000010)) >> 4);
}

/**
 * @brief Sets the RXIQDELPATHI1 field of the RWNXIQCTRL register.
 *
 * The RWNXIQCTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rxiqdelpathi1 - The value to set the field to.
 */
__INLINE void riu_rxiqdelpathi1_setf(uint8_t rxiqdelpathi1)
{
    REG_PL_WR(RIU_RWNXIQCTRL_ADDR, (REG_PL_RD(RIU_RWNXIQCTRL_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)rxiqdelpathi1 << 4));
}

/**
 * @brief Returns the current value of the RXIQDELPATHQ0 field in the RWNXIQCTRL register.
 *
 * The RWNXIQCTRL register will be read and the RXIQDELPATHQ0 field's value will be returned.
 *
 * @return The current value of the RXIQDELPATHQ0 field in the RWNXIQCTRL register.
 */
__INLINE uint8_t riu_rxiqdelpathq0_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXIQCTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000008)) >> 3);
}

/**
 * @brief Sets the RXIQDELPATHQ0 field of the RWNXIQCTRL register.
 *
 * The RWNXIQCTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rxiqdelpathq0 - The value to set the field to.
 */
__INLINE void riu_rxiqdelpathq0_setf(uint8_t rxiqdelpathq0)
{
    REG_PL_WR(RIU_RWNXIQCTRL_ADDR, (REG_PL_RD(RIU_RWNXIQCTRL_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)rxiqdelpathq0 << 3));
}

/**
 * @brief Returns the current value of the RXIQDELPATHI0 field in the RWNXIQCTRL register.
 *
 * The RWNXIQCTRL register will be read and the RXIQDELPATHI0 field's value will be returned.
 *
 * @return The current value of the RXIQDELPATHI0 field in the RWNXIQCTRL register.
 */
__INLINE uint8_t riu_rxiqdelpathi0_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXIQCTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000004)) >> 2);
}

/**
 * @brief Sets the RXIQDELPATHI0 field of the RWNXIQCTRL register.
 *
 * The RWNXIQCTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rxiqdelpathi0 - The value to set the field to.
 */
__INLINE void riu_rxiqdelpathi0_setf(uint8_t rxiqdelpathi0)
{
    REG_PL_WR(RIU_RWNXIQCTRL_ADDR, (REG_PL_RD(RIU_RWNXIQCTRL_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)rxiqdelpathi0 << 2));
}

/**
 * @brief Returns the current value of the TXC2SDISBCFG field in the RWNXIQCTRL register.
 *
 * The RWNXIQCTRL register will be read and the TXC2SDISBCFG field's value will be returned.
 *
 * @return The current value of the TXC2SDISBCFG field in the RWNXIQCTRL register.
 */
__INLINE uint8_t riu_txc2sdisbcfg_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXIQCTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000002)) >> 1);
}

/**
 * @brief Sets the TXC2SDISBCFG field of the RWNXIQCTRL register.
 *
 * The RWNXIQCTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] txc2sdisbcfg - The value to set the field to.
 */
__INLINE void riu_txc2sdisbcfg_setf(uint8_t txc2sdisbcfg)
{
    REG_PL_WR(RIU_RWNXIQCTRL_ADDR, (REG_PL_RD(RIU_RWNXIQCTRL_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)txc2sdisbcfg << 1));
}

/**
 * @brief Returns the current value of the RXC2SDISBCFG field in the RWNXIQCTRL register.
 *
 * The RWNXIQCTRL register will be read and the RXC2SDISBCFG field's value will be returned.
 *
 * @return The current value of the RXC2SDISBCFG field in the RWNXIQCTRL register.
 */
__INLINE uint8_t riu_rxc2sdisbcfg_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXIQCTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief Sets the RXC2SDISBCFG field of the RWNXIQCTRL register.
 *
 * The RWNXIQCTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rxc2sdisbcfg - The value to set the field to.
 */
__INLINE void riu_rxc2sdisbcfg_setf(uint8_t rxc2sdisbcfg)
{
    REG_PL_WR(RIU_RWNXIQCTRL_ADDR, (REG_PL_RD(RIU_RWNXIQCTRL_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)rxc2sdisbcfg << 0));
}

/// @}

/**
 * @name RWNXMACSTATICCONFIG register definitions
 * <table>
 * <caption id="RWNXMACSTATICCONFIG_BF">RWNXMACSTATICCONFIG bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>30 <td>               CRX <td>R <td>R/W <td>1
 * <tr><td>29 <td>            LNA_EN <td>R <td>R/W <td>1
 * <tr><td>27 <td>             PA_EN <td>R <td>R/W <td>0
 * <tr><td>01:00 <td>          PSSELECT <td>R <td>R/W <td>0x0
 * </table>
 *
 * @{
 */

/// Address of the RWNXMACSTATICCONFIG register
#define RIU_RWNXMACSTATICCONFIG_ADDR   0x4033B080
/// Offset of the RWNXMACSTATICCONFIG register from the base address
#define RIU_RWNXMACSTATICCONFIG_OFFSET 0x00000080
/// Index of the RWNXMACSTATICCONFIG register
#define RIU_RWNXMACSTATICCONFIG_INDEX  0x00000020
/// Reset value of the RWNXMACSTATICCONFIG register
#define RIU_RWNXMACSTATICCONFIG_RESET  0x60000000

/**
 * @brief Returns the current value of the RWNXMACSTATICCONFIG register.
 * The RWNXMACSTATICCONFIG register will be read and its value returned.
 * @return The current value of the RWNXMACSTATICCONFIG register.
 */
__INLINE uint32_t riu_rwnxmacstaticconfig_get(void)
{
    return REG_PL_RD(RIU_RWNXMACSTATICCONFIG_ADDR);
}

/**
 * @brief Sets the RWNXMACSTATICCONFIG register to a value.
 * The RWNXMACSTATICCONFIG register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxmacstaticconfig_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXMACSTATICCONFIG_ADDR, value);
}

// field definitions
/// CRX field bit
#define RIU_CRX_BIT         ((uint32_t)0x40000000)
/// CRX field position
#define RIU_CRX_POS         30
/// LNA_EN field bit
#define RIU_LNA_EN_BIT      ((uint32_t)0x20000000)
/// LNA_EN field position
#define RIU_LNA_EN_POS      29
/// PA_EN field bit
#define RIU_PA_EN_BIT       ((uint32_t)0x08000000)
/// PA_EN field position
#define RIU_PA_EN_POS       27
/// PSSELECT field mask
#define RIU_PSSELECT_MASK   ((uint32_t)0x00000003)
/// PSSELECT field LSB position
#define RIU_PSSELECT_LSB    0
/// PSSELECT field width
#define RIU_PSSELECT_WIDTH  ((uint32_t)0x00000002)

/// CRX field reset value
#define RIU_CRX_RST         0x1
/// LNA_EN field reset value
#define RIU_LNA_EN_RST      0x1
/// PA_EN field reset value
#define RIU_PA_EN_RST       0x0
/// PSSELECT field reset value
#define RIU_PSSELECT_RST    0x0

/**
 * @brief Constructs a value for the RWNXMACSTATICCONFIG register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] crx - The value to use for the CRX field.
 * @param[in] lnaen - The value to use for the LNA_EN field.
 * @param[in] paen - The value to use for the PA_EN field.
 * @param[in] psselect - The value to use for the PSSELECT field.
 */
__INLINE void riu_rwnxmacstaticconfig_pack(uint8_t crx, uint8_t lnaen, uint8_t paen, uint8_t psselect)
{
    REG_PL_WR(RIU_RWNXMACSTATICCONFIG_ADDR,  ((uint32_t)crx << 30) | ((uint32_t)lnaen << 29) | ((uint32_t)paen << 27) | ((uint32_t)psselect << 0));
}

/**
 * @brief Unpacks RWNXMACSTATICCONFIG's fields from current value of the RWNXMACSTATICCONFIG register.
 *
 * Reads the RWNXMACSTATICCONFIG register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] crx - Will be populated with the current value of this field from the register.
 * @param[out] lnaen - Will be populated with the current value of this field from the register.
 * @param[out] paen - Will be populated with the current value of this field from the register.
 * @param[out] psselect - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxmacstaticconfig_unpack(uint8_t* crx, uint8_t* lnaen, uint8_t* paen, uint8_t* psselect)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXMACSTATICCONFIG_ADDR);

    *crx = (localVal & ((uint32_t)0x40000000)) >> 30;
    *lnaen = (localVal & ((uint32_t)0x20000000)) >> 29;
    *paen = (localVal & ((uint32_t)0x08000000)) >> 27;
    *psselect = (localVal & ((uint32_t)0x00000003)) >> 0;
}

/**
 * @brief Returns the current value of the CRX field in the RWNXMACSTATICCONFIG register.
 *
 * The RWNXMACSTATICCONFIG register will be read and the CRX field's value will be returned.
 *
 * @return The current value of the CRX field in the RWNXMACSTATICCONFIG register.
 */
__INLINE uint8_t riu_crx_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXMACSTATICCONFIG_ADDR);
    return ((localVal & ((uint32_t)0x40000000)) >> 30);
}

/**
 * @brief Sets the CRX field of the RWNXMACSTATICCONFIG register.
 *
 * The RWNXMACSTATICCONFIG register will be read, modified to contain the new field value, and written.
 *
 * @param[in] crx - The value to set the field to.
 */
__INLINE void riu_crx_setf(uint8_t crx)
{
    REG_PL_WR(RIU_RWNXMACSTATICCONFIG_ADDR, (REG_PL_RD(RIU_RWNXMACSTATICCONFIG_ADDR) & ~((uint32_t)0x40000000)) | ((uint32_t)crx << 30));
}

/**
 * @brief Returns the current value of the LNA_EN field in the RWNXMACSTATICCONFIG register.
 *
 * The RWNXMACSTATICCONFIG register will be read and the LNA_EN field's value will be returned.
 *
 * @return The current value of the LNA_EN field in the RWNXMACSTATICCONFIG register.
 */
__INLINE uint8_t riu_lna_en_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXMACSTATICCONFIG_ADDR);
    return ((localVal & ((uint32_t)0x20000000)) >> 29);
}

/**
 * @brief Sets the LNA_EN field of the RWNXMACSTATICCONFIG register.
 *
 * The RWNXMACSTATICCONFIG register will be read, modified to contain the new field value, and written.
 *
 * @param[in] lnaen - The value to set the field to.
 */
__INLINE void riu_lna_en_setf(uint8_t lnaen)
{
    REG_PL_WR(RIU_RWNXMACSTATICCONFIG_ADDR, (REG_PL_RD(RIU_RWNXMACSTATICCONFIG_ADDR) & ~((uint32_t)0x20000000)) | ((uint32_t)lnaen << 29));
}

/**
 * @brief Returns the current value of the PA_EN field in the RWNXMACSTATICCONFIG register.
 *
 * The RWNXMACSTATICCONFIG register will be read and the PA_EN field's value will be returned.
 *
 * @return The current value of the PA_EN field in the RWNXMACSTATICCONFIG register.
 */
__INLINE uint8_t riu_pa_en_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXMACSTATICCONFIG_ADDR);
    return ((localVal & ((uint32_t)0x08000000)) >> 27);
}

/**
 * @brief Sets the PA_EN field of the RWNXMACSTATICCONFIG register.
 *
 * The RWNXMACSTATICCONFIG register will be read, modified to contain the new field value, and written.
 *
 * @param[in] paen - The value to set the field to.
 */
__INLINE void riu_pa_en_setf(uint8_t paen)
{
    REG_PL_WR(RIU_RWNXMACSTATICCONFIG_ADDR, (REG_PL_RD(RIU_RWNXMACSTATICCONFIG_ADDR) & ~((uint32_t)0x08000000)) | ((uint32_t)paen << 27));
}

/**
 * @brief Returns the current value of the PSSELECT field in the RWNXMACSTATICCONFIG register.
 *
 * The RWNXMACSTATICCONFIG register will be read and the PSSELECT field's value will be returned.
 *
 * @return The current value of the PSSELECT field in the RWNXMACSTATICCONFIG register.
 */
__INLINE uint8_t riu_psselect_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXMACSTATICCONFIG_ADDR);
    return ((localVal & ((uint32_t)0x00000003)) >> 0);
}

/**
 * @brief Sets the PSSELECT field of the RWNXMACSTATICCONFIG register.
 *
 * The RWNXMACSTATICCONFIG register will be read, modified to contain the new field value, and written.
 *
 * @param[in] psselect - The value to set the field to.
 */
__INLINE void riu_psselect_setf(uint8_t psselect)
{
    REG_PL_WR(RIU_RWNXMACSTATICCONFIG_ADDR, (REG_PL_RD(RIU_RWNXMACSTATICCONFIG_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)psselect << 0));
}

/// @}

/**
 * @name RWNXFECTRL0 register definitions
 * <table>
 * <caption id="RWNXFECTRL0_BF">RWNXFECTRL0 bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>22:16 <td>   TX80DIGGAINLIN0 <td>R <td>R/W <td>0x20
 * <tr><td>14:08 <td>   TX40DIGGAINLIN0 <td>R <td>R/W <td>0x20
 * <tr><td>06:00 <td>   TX20DIGGAINLIN0 <td>R <td>R/W <td>0x40
 * </table>
 *
 * @{
 */

/// Address of the RWNXFECTRL0 register
#define RIU_RWNXFECTRL0_ADDR   0x4033B100
/// Offset of the RWNXFECTRL0 register from the base address
#define RIU_RWNXFECTRL0_OFFSET 0x00000100
/// Index of the RWNXFECTRL0 register
#define RIU_RWNXFECTRL0_INDEX  0x00000040
/// Reset value of the RWNXFECTRL0 register
#define RIU_RWNXFECTRL0_RESET  0x00202040

/**
 * @brief Returns the current value of the RWNXFECTRL0 register.
 * The RWNXFECTRL0 register will be read and its value returned.
 * @return The current value of the RWNXFECTRL0 register.
 */
__INLINE uint32_t riu_rwnxfectrl0_get(void)
{
    return REG_PL_RD(RIU_RWNXFECTRL0_ADDR);
}

/**
 * @brief Sets the RWNXFECTRL0 register to a value.
 * The RWNXFECTRL0 register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxfectrl0_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXFECTRL0_ADDR, value);
}

// field definitions
/// TX80DIGGAINLIN0 field mask
#define RIU_TX80DIGGAINLIN0_MASK   ((uint32_t)0x007F0000)
/// TX80DIGGAINLIN0 field LSB position
#define RIU_TX80DIGGAINLIN0_LSB    16
/// TX80DIGGAINLIN0 field width
#define RIU_TX80DIGGAINLIN0_WIDTH  ((uint32_t)0x00000007)
/// TX40DIGGAINLIN0 field mask
#define RIU_TX40DIGGAINLIN0_MASK   ((uint32_t)0x00007F00)
/// TX40DIGGAINLIN0 field LSB position
#define RIU_TX40DIGGAINLIN0_LSB    8
/// TX40DIGGAINLIN0 field width
#define RIU_TX40DIGGAINLIN0_WIDTH  ((uint32_t)0x00000007)
/// TX20DIGGAINLIN0 field mask
#define RIU_TX20DIGGAINLIN0_MASK   ((uint32_t)0x0000007F)
/// TX20DIGGAINLIN0 field LSB position
#define RIU_TX20DIGGAINLIN0_LSB    0
/// TX20DIGGAINLIN0 field width
#define RIU_TX20DIGGAINLIN0_WIDTH  ((uint32_t)0x00000007)

/// TX80DIGGAINLIN0 field reset value
#define RIU_TX80DIGGAINLIN0_RST    0x20
/// TX40DIGGAINLIN0 field reset value
#define RIU_TX40DIGGAINLIN0_RST    0x20
/// TX20DIGGAINLIN0 field reset value
#define RIU_TX20DIGGAINLIN0_RST    0x40

/**
 * @brief Constructs a value for the RWNXFECTRL0 register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] tx80diggainlin0 - The value to use for the TX80DIGGAINLIN0 field.
 * @param[in] tx40diggainlin0 - The value to use for the TX40DIGGAINLIN0 field.
 * @param[in] tx20diggainlin0 - The value to use for the TX20DIGGAINLIN0 field.
 */
__INLINE void riu_rwnxfectrl0_pack(uint8_t tx80diggainlin0, uint8_t tx40diggainlin0, uint8_t tx20diggainlin0)
{
    REG_PL_WR(RIU_RWNXFECTRL0_ADDR,  ((uint32_t)tx80diggainlin0 << 16) | ((uint32_t)tx40diggainlin0 << 8) | ((uint32_t)tx20diggainlin0 << 0));
}

/**
 * @brief Unpacks RWNXFECTRL0's fields from current value of the RWNXFECTRL0 register.
 *
 * Reads the RWNXFECTRL0 register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] tx80diggainlin0 - Will be populated with the current value of this field from the register.
 * @param[out] tx40diggainlin0 - Will be populated with the current value of this field from the register.
 * @param[out] tx20diggainlin0 - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxfectrl0_unpack(uint8_t* tx80diggainlin0, uint8_t* tx40diggainlin0, uint8_t* tx20diggainlin0)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFECTRL0_ADDR);

    *tx80diggainlin0 = (localVal & ((uint32_t)0x007F0000)) >> 16;
    *tx40diggainlin0 = (localVal & ((uint32_t)0x00007F00)) >> 8;
    *tx20diggainlin0 = (localVal & ((uint32_t)0x0000007F)) >> 0;
}

/**
 * @brief Returns the current value of the TX80DIGGAINLIN0 field in the RWNXFECTRL0 register.
 *
 * The RWNXFECTRL0 register will be read and the TX80DIGGAINLIN0 field's value will be returned.
 *
 * @return The current value of the TX80DIGGAINLIN0 field in the RWNXFECTRL0 register.
 */
__INLINE uint8_t riu_tx80diggainlin0_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFECTRL0_ADDR);
    return ((localVal & ((uint32_t)0x007F0000)) >> 16);
}

/**
 * @brief Sets the TX80DIGGAINLIN0 field of the RWNXFECTRL0 register.
 *
 * The RWNXFECTRL0 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] tx80diggainlin0 - The value to set the field to.
 */
__INLINE void riu_tx80diggainlin0_setf(uint8_t tx80diggainlin0)
{
    REG_PL_WR(RIU_RWNXFECTRL0_ADDR, (REG_PL_RD(RIU_RWNXFECTRL0_ADDR) & ~((uint32_t)0x007F0000)) | ((uint32_t)tx80diggainlin0 << 16));
}

/**
 * @brief Returns the current value of the TX40DIGGAINLIN0 field in the RWNXFECTRL0 register.
 *
 * The RWNXFECTRL0 register will be read and the TX40DIGGAINLIN0 field's value will be returned.
 *
 * @return The current value of the TX40DIGGAINLIN0 field in the RWNXFECTRL0 register.
 */
__INLINE uint8_t riu_tx40diggainlin0_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFECTRL0_ADDR);
    return ((localVal & ((uint32_t)0x00007F00)) >> 8);
}

/**
 * @brief Sets the TX40DIGGAINLIN0 field of the RWNXFECTRL0 register.
 *
 * The RWNXFECTRL0 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] tx40diggainlin0 - The value to set the field to.
 */
__INLINE void riu_tx40diggainlin0_setf(uint8_t tx40diggainlin0)
{
    REG_PL_WR(RIU_RWNXFECTRL0_ADDR, (REG_PL_RD(RIU_RWNXFECTRL0_ADDR) & ~((uint32_t)0x00007F00)) | ((uint32_t)tx40diggainlin0 << 8));
}

/**
 * @brief Returns the current value of the TX20DIGGAINLIN0 field in the RWNXFECTRL0 register.
 *
 * The RWNXFECTRL0 register will be read and the TX20DIGGAINLIN0 field's value will be returned.
 *
 * @return The current value of the TX20DIGGAINLIN0 field in the RWNXFECTRL0 register.
 */
__INLINE uint8_t riu_tx20diggainlin0_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFECTRL0_ADDR);
    return ((localVal & ((uint32_t)0x0000007F)) >> 0);
}

/**
 * @brief Sets the TX20DIGGAINLIN0 field of the RWNXFECTRL0 register.
 *
 * The RWNXFECTRL0 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] tx20diggainlin0 - The value to set the field to.
 */
__INLINE void riu_tx20diggainlin0_setf(uint8_t tx20diggainlin0)
{
    REG_PL_WR(RIU_RWNXFECTRL0_ADDR, (REG_PL_RD(RIU_RWNXFECTRL0_ADDR) & ~((uint32_t)0x0000007F)) | ((uint32_t)tx20diggainlin0 << 0));
}

/// @}

/**
 * @name RWNXFECTRL1 register definitions
 * <table>
 * <caption id="RWNXFECTRL1_BF">RWNXFECTRL1 bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>22:16 <td>   TX80DIGGAINLIN1 <td>R <td>R/W <td>0x20
 * <tr><td>14:08 <td>   TX40DIGGAINLIN1 <td>R <td>R/W <td>0x20
 * <tr><td>06:00 <td>   TX20DIGGAINLIN1 <td>R <td>R/W <td>0x40
 * </table>
 *
 * @{
 */

/// Address of the RWNXFECTRL1 register
#define RIU_RWNXFECTRL1_ADDR   0x4033B104
/// Offset of the RWNXFECTRL1 register from the base address
#define RIU_RWNXFECTRL1_OFFSET 0x00000104
/// Index of the RWNXFECTRL1 register
#define RIU_RWNXFECTRL1_INDEX  0x00000041
/// Reset value of the RWNXFECTRL1 register
#define RIU_RWNXFECTRL1_RESET  0x00202040

/**
 * @brief Returns the current value of the RWNXFECTRL1 register.
 * The RWNXFECTRL1 register will be read and its value returned.
 * @return The current value of the RWNXFECTRL1 register.
 */
__INLINE uint32_t riu_rwnxfectrl1_get(void)
{
    return REG_PL_RD(RIU_RWNXFECTRL1_ADDR);
}

/**
 * @brief Sets the RWNXFECTRL1 register to a value.
 * The RWNXFECTRL1 register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxfectrl1_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXFECTRL1_ADDR, value);
}

// field definitions
/// TX80DIGGAINLIN1 field mask
#define RIU_TX80DIGGAINLIN1_MASK   ((uint32_t)0x007F0000)
/// TX80DIGGAINLIN1 field LSB position
#define RIU_TX80DIGGAINLIN1_LSB    16
/// TX80DIGGAINLIN1 field width
#define RIU_TX80DIGGAINLIN1_WIDTH  ((uint32_t)0x00000007)
/// TX40DIGGAINLIN1 field mask
#define RIU_TX40DIGGAINLIN1_MASK   ((uint32_t)0x00007F00)
/// TX40DIGGAINLIN1 field LSB position
#define RIU_TX40DIGGAINLIN1_LSB    8
/// TX40DIGGAINLIN1 field width
#define RIU_TX40DIGGAINLIN1_WIDTH  ((uint32_t)0x00000007)
/// TX20DIGGAINLIN1 field mask
#define RIU_TX20DIGGAINLIN1_MASK   ((uint32_t)0x0000007F)
/// TX20DIGGAINLIN1 field LSB position
#define RIU_TX20DIGGAINLIN1_LSB    0
/// TX20DIGGAINLIN1 field width
#define RIU_TX20DIGGAINLIN1_WIDTH  ((uint32_t)0x00000007)

/// TX80DIGGAINLIN1 field reset value
#define RIU_TX80DIGGAINLIN1_RST    0x20
/// TX40DIGGAINLIN1 field reset value
#define RIU_TX40DIGGAINLIN1_RST    0x20
/// TX20DIGGAINLIN1 field reset value
#define RIU_TX20DIGGAINLIN1_RST    0x40

/**
 * @brief Constructs a value for the RWNXFECTRL1 register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] tx80diggainlin1 - The value to use for the TX80DIGGAINLIN1 field.
 * @param[in] tx40diggainlin1 - The value to use for the TX40DIGGAINLIN1 field.
 * @param[in] tx20diggainlin1 - The value to use for the TX20DIGGAINLIN1 field.
 */
__INLINE void riu_rwnxfectrl1_pack(uint8_t tx80diggainlin1, uint8_t tx40diggainlin1, uint8_t tx20diggainlin1)
{
    REG_PL_WR(RIU_RWNXFECTRL1_ADDR,  ((uint32_t)tx80diggainlin1 << 16) | ((uint32_t)tx40diggainlin1 << 8) | ((uint32_t)tx20diggainlin1 << 0));
}

/**
 * @brief Unpacks RWNXFECTRL1's fields from current value of the RWNXFECTRL1 register.
 *
 * Reads the RWNXFECTRL1 register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] tx80diggainlin1 - Will be populated with the current value of this field from the register.
 * @param[out] tx40diggainlin1 - Will be populated with the current value of this field from the register.
 * @param[out] tx20diggainlin1 - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxfectrl1_unpack(uint8_t* tx80diggainlin1, uint8_t* tx40diggainlin1, uint8_t* tx20diggainlin1)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFECTRL1_ADDR);

    *tx80diggainlin1 = (localVal & ((uint32_t)0x007F0000)) >> 16;
    *tx40diggainlin1 = (localVal & ((uint32_t)0x00007F00)) >> 8;
    *tx20diggainlin1 = (localVal & ((uint32_t)0x0000007F)) >> 0;
}

/**
 * @brief Returns the current value of the TX80DIGGAINLIN1 field in the RWNXFECTRL1 register.
 *
 * The RWNXFECTRL1 register will be read and the TX80DIGGAINLIN1 field's value will be returned.
 *
 * @return The current value of the TX80DIGGAINLIN1 field in the RWNXFECTRL1 register.
 */
__INLINE uint8_t riu_tx80diggainlin1_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFECTRL1_ADDR);
    return ((localVal & ((uint32_t)0x007F0000)) >> 16);
}

/**
 * @brief Sets the TX80DIGGAINLIN1 field of the RWNXFECTRL1 register.
 *
 * The RWNXFECTRL1 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] tx80diggainlin1 - The value to set the field to.
 */
__INLINE void riu_tx80diggainlin1_setf(uint8_t tx80diggainlin1)
{
    REG_PL_WR(RIU_RWNXFECTRL1_ADDR, (REG_PL_RD(RIU_RWNXFECTRL1_ADDR) & ~((uint32_t)0x007F0000)) | ((uint32_t)tx80diggainlin1 << 16));
}

/**
 * @brief Returns the current value of the TX40DIGGAINLIN1 field in the RWNXFECTRL1 register.
 *
 * The RWNXFECTRL1 register will be read and the TX40DIGGAINLIN1 field's value will be returned.
 *
 * @return The current value of the TX40DIGGAINLIN1 field in the RWNXFECTRL1 register.
 */
__INLINE uint8_t riu_tx40diggainlin1_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFECTRL1_ADDR);
    return ((localVal & ((uint32_t)0x00007F00)) >> 8);
}

/**
 * @brief Sets the TX40DIGGAINLIN1 field of the RWNXFECTRL1 register.
 *
 * The RWNXFECTRL1 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] tx40diggainlin1 - The value to set the field to.
 */
__INLINE void riu_tx40diggainlin1_setf(uint8_t tx40diggainlin1)
{
    REG_PL_WR(RIU_RWNXFECTRL1_ADDR, (REG_PL_RD(RIU_RWNXFECTRL1_ADDR) & ~((uint32_t)0x00007F00)) | ((uint32_t)tx40diggainlin1 << 8));
}

/**
 * @brief Returns the current value of the TX20DIGGAINLIN1 field in the RWNXFECTRL1 register.
 *
 * The RWNXFECTRL1 register will be read and the TX20DIGGAINLIN1 field's value will be returned.
 *
 * @return The current value of the TX20DIGGAINLIN1 field in the RWNXFECTRL1 register.
 */
__INLINE uint8_t riu_tx20diggainlin1_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFECTRL1_ADDR);
    return ((localVal & ((uint32_t)0x0000007F)) >> 0);
}

/**
 * @brief Sets the TX20DIGGAINLIN1 field of the RWNXFECTRL1 register.
 *
 * The RWNXFECTRL1 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] tx20diggainlin1 - The value to set the field to.
 */
__INLINE void riu_tx20diggainlin1_setf(uint8_t tx20diggainlin1)
{
    REG_PL_WR(RIU_RWNXFECTRL1_ADDR, (REG_PL_RD(RIU_RWNXFECTRL1_ADDR) & ~((uint32_t)0x0000007F)) | ((uint32_t)tx20diggainlin1 << 0));
}

/// @}

#if RW_NX_IQ_COMP_EN
/**
 * @name RWNXFETXIQCOMP0 register definitions
 * <table>
 * <caption id="RWNXFETXIQCOMP0_BF">RWNXFETXIQCOMP0 bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>29 <td>  TXIQPHASECOMPEN0 <td>R <td>R/W <td>0
 * <tr><td>28 <td>   TXIQGAINCOMPEN0 <td>R <td>R/W <td>0
 * <tr><td>24:16 <td>        TXIQPHASE0 <td>R <td>R/W <td>0x0
 * <tr><td>10:00 <td>         TXIQGAIN0 <td>R <td>R/W <td>0x400
 * </table>
 *
 * @{
 */

/// Address of the RWNXFETXIQCOMP0 register
#define RIU_RWNXFETXIQCOMP0_ADDR   0x4033B108
/// Offset of the RWNXFETXIQCOMP0 register from the base address
#define RIU_RWNXFETXIQCOMP0_OFFSET 0x00000108
/// Index of the RWNXFETXIQCOMP0 register
#define RIU_RWNXFETXIQCOMP0_INDEX  0x00000042
/// Reset value of the RWNXFETXIQCOMP0 register
#define RIU_RWNXFETXIQCOMP0_RESET  0x00000400

/**
 * @brief Returns the current value of the RWNXFETXIQCOMP0 register.
 * The RWNXFETXIQCOMP0 register will be read and its value returned.
 * @return The current value of the RWNXFETXIQCOMP0 register.
 */
__INLINE uint32_t riu_rwnxfetxiqcomp0_get(void)
{
    return REG_PL_RD(RIU_RWNXFETXIQCOMP0_ADDR);
}

/**
 * @brief Sets the RWNXFETXIQCOMP0 register to a value.
 * The RWNXFETXIQCOMP0 register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxfetxiqcomp0_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXFETXIQCOMP0_ADDR, value);
}

// field definitions
/// TXIQPHASECOMPEN0 field bit
#define RIU_TXIQPHASECOMPEN0_BIT    ((uint32_t)0x20000000)
/// TXIQPHASECOMPEN0 field position
#define RIU_TXIQPHASECOMPEN0_POS    29
/// TXIQGAINCOMPEN0 field bit
#define RIU_TXIQGAINCOMPEN0_BIT     ((uint32_t)0x10000000)
/// TXIQGAINCOMPEN0 field position
#define RIU_TXIQGAINCOMPEN0_POS     28
/// TXIQPHASE0 field mask
#define RIU_TXIQPHASE0_MASK         ((uint32_t)0x01FF0000)
/// TXIQPHASE0 field LSB position
#define RIU_TXIQPHASE0_LSB          16
/// TXIQPHASE0 field width
#define RIU_TXIQPHASE0_WIDTH        ((uint32_t)0x00000009)
/// TXIQGAIN0 field mask
#define RIU_TXIQGAIN0_MASK          ((uint32_t)0x000007FF)
/// TXIQGAIN0 field LSB position
#define RIU_TXIQGAIN0_LSB           0
/// TXIQGAIN0 field width
#define RIU_TXIQGAIN0_WIDTH         ((uint32_t)0x0000000B)

/// TXIQPHASECOMPEN0 field reset value
#define RIU_TXIQPHASECOMPEN0_RST    0x0
/// TXIQGAINCOMPEN0 field reset value
#define RIU_TXIQGAINCOMPEN0_RST     0x0
/// TXIQPHASE0 field reset value
#define RIU_TXIQPHASE0_RST          0x0
/// TXIQGAIN0 field reset value
#define RIU_TXIQGAIN0_RST           0x400

/**
 * @brief Constructs a value for the RWNXFETXIQCOMP0 register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] txiqphasecompen0 - The value to use for the TXIQPHASECOMPEN0 field.
 * @param[in] txiqgaincompen0 - The value to use for the TXIQGAINCOMPEN0 field.
 * @param[in] txiqphase0 - The value to use for the TXIQPHASE0 field.
 * @param[in] txiqgain0 - The value to use for the TXIQGAIN0 field.
 */
__INLINE void riu_rwnxfetxiqcomp0_pack(uint8_t txiqphasecompen0, uint8_t txiqgaincompen0, uint16_t txiqphase0, uint16_t txiqgain0)
{
    REG_PL_WR(RIU_RWNXFETXIQCOMP0_ADDR,  ((uint32_t)txiqphasecompen0 << 29) | ((uint32_t)txiqgaincompen0 << 28) | ((uint32_t)txiqphase0 << 16) | ((uint32_t)txiqgain0 << 0));
}

/**
 * @brief Unpacks RWNXFETXIQCOMP0's fields from current value of the RWNXFETXIQCOMP0 register.
 *
 * Reads the RWNXFETXIQCOMP0 register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] txiqphasecompen0 - Will be populated with the current value of this field from the register.
 * @param[out] txiqgaincompen0 - Will be populated with the current value of this field from the register.
 * @param[out] txiqphase0 - Will be populated with the current value of this field from the register.
 * @param[out] txiqgain0 - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxfetxiqcomp0_unpack(uint8_t* txiqphasecompen0, uint8_t* txiqgaincompen0, uint16_t* txiqphase0, uint16_t* txiqgain0)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFETXIQCOMP0_ADDR);

    *txiqphasecompen0 = (localVal & ((uint32_t)0x20000000)) >> 29;
    *txiqgaincompen0 = (localVal & ((uint32_t)0x10000000)) >> 28;
    *txiqphase0 = (localVal & ((uint32_t)0x01FF0000)) >> 16;
    *txiqgain0 = (localVal & ((uint32_t)0x000007FF)) >> 0;
}

/**
 * @brief Returns the current value of the TXIQPHASECOMPEN0 field in the RWNXFETXIQCOMP0 register.
 *
 * The RWNXFETXIQCOMP0 register will be read and the TXIQPHASECOMPEN0 field's value will be returned.
 *
 * @return The current value of the TXIQPHASECOMPEN0 field in the RWNXFETXIQCOMP0 register.
 */
__INLINE uint8_t riu_txiqphasecompen0_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFETXIQCOMP0_ADDR);
    return ((localVal & ((uint32_t)0x20000000)) >> 29);
}

/**
 * @brief Sets the TXIQPHASECOMPEN0 field of the RWNXFETXIQCOMP0 register.
 *
 * The RWNXFETXIQCOMP0 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] txiqphasecompen0 - The value to set the field to.
 */
__INLINE void riu_txiqphasecompen0_setf(uint8_t txiqphasecompen0)
{
    REG_PL_WR(RIU_RWNXFETXIQCOMP0_ADDR, (REG_PL_RD(RIU_RWNXFETXIQCOMP0_ADDR) & ~((uint32_t)0x20000000)) | ((uint32_t)txiqphasecompen0 << 29));
}

/**
 * @brief Returns the current value of the TXIQGAINCOMPEN0 field in the RWNXFETXIQCOMP0 register.
 *
 * The RWNXFETXIQCOMP0 register will be read and the TXIQGAINCOMPEN0 field's value will be returned.
 *
 * @return The current value of the TXIQGAINCOMPEN0 field in the RWNXFETXIQCOMP0 register.
 */
__INLINE uint8_t riu_txiqgaincompen0_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFETXIQCOMP0_ADDR);
    return ((localVal & ((uint32_t)0x10000000)) >> 28);
}

/**
 * @brief Sets the TXIQGAINCOMPEN0 field of the RWNXFETXIQCOMP0 register.
 *
 * The RWNXFETXIQCOMP0 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] txiqgaincompen0 - The value to set the field to.
 */
__INLINE void riu_txiqgaincompen0_setf(uint8_t txiqgaincompen0)
{
    REG_PL_WR(RIU_RWNXFETXIQCOMP0_ADDR, (REG_PL_RD(RIU_RWNXFETXIQCOMP0_ADDR) & ~((uint32_t)0x10000000)) | ((uint32_t)txiqgaincompen0 << 28));
}

/**
 * @brief Returns the current value of the TXIQPHASE0 field in the RWNXFETXIQCOMP0 register.
 *
 * The RWNXFETXIQCOMP0 register will be read and the TXIQPHASE0 field's value will be returned.
 *
 * @return The current value of the TXIQPHASE0 field in the RWNXFETXIQCOMP0 register.
 */
__INLINE uint16_t riu_txiqphase0_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFETXIQCOMP0_ADDR);
    return ((localVal & ((uint32_t)0x01FF0000)) >> 16);
}

/**
 * @brief Sets the TXIQPHASE0 field of the RWNXFETXIQCOMP0 register.
 *
 * The RWNXFETXIQCOMP0 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] txiqphase0 - The value to set the field to.
 */
__INLINE void riu_txiqphase0_setf(uint16_t txiqphase0)
{
    REG_PL_WR(RIU_RWNXFETXIQCOMP0_ADDR, (REG_PL_RD(RIU_RWNXFETXIQCOMP0_ADDR) & ~((uint32_t)0x01FF0000)) | ((uint32_t)txiqphase0 << 16));
}

/**
 * @brief Returns the current value of the TXIQGAIN0 field in the RWNXFETXIQCOMP0 register.
 *
 * The RWNXFETXIQCOMP0 register will be read and the TXIQGAIN0 field's value will be returned.
 *
 * @return The current value of the TXIQGAIN0 field in the RWNXFETXIQCOMP0 register.
 */
__INLINE uint16_t riu_txiqgain0_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFETXIQCOMP0_ADDR);
    return ((localVal & ((uint32_t)0x000007FF)) >> 0);
}

/**
 * @brief Sets the TXIQGAIN0 field of the RWNXFETXIQCOMP0 register.
 *
 * The RWNXFETXIQCOMP0 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] txiqgain0 - The value to set the field to.
 */
__INLINE void riu_txiqgain0_setf(uint16_t txiqgain0)
{
    REG_PL_WR(RIU_RWNXFETXIQCOMP0_ADDR, (REG_PL_RD(RIU_RWNXFETXIQCOMP0_ADDR) & ~((uint32_t)0x000007FF)) | ((uint32_t)txiqgain0 << 0));
}

#endif // RW_NX_IQ_COMP_EN
/// @}

#if RW_NX_IQ_COMP_EN
/**
 * @name RWNXFETXIQCOMP1 register definitions
 * <table>
 * <caption id="RWNXFETXIQCOMP1_BF">RWNXFETXIQCOMP1 bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>29 <td>  TXIQPHASECOMPEN1 <td>R <td>R/W <td>0
 * <tr><td>28 <td>   TXIQGAINCOMPEN1 <td>R <td>R/W <td>0
 * <tr><td>24:16 <td>        TXIQPHASE1 <td>R <td>R/W <td>0x0
 * <tr><td>10:00 <td>         TXIQGAIN1 <td>R <td>R/W <td>0x400
 * </table>
 *
 * @{
 */

/// Address of the RWNXFETXIQCOMP1 register
#define RIU_RWNXFETXIQCOMP1_ADDR   0x4033B10C
/// Offset of the RWNXFETXIQCOMP1 register from the base address
#define RIU_RWNXFETXIQCOMP1_OFFSET 0x0000010C
/// Index of the RWNXFETXIQCOMP1 register
#define RIU_RWNXFETXIQCOMP1_INDEX  0x00000043
/// Reset value of the RWNXFETXIQCOMP1 register
#define RIU_RWNXFETXIQCOMP1_RESET  0x00000400

/**
 * @brief Returns the current value of the RWNXFETXIQCOMP1 register.
 * The RWNXFETXIQCOMP1 register will be read and its value returned.
 * @return The current value of the RWNXFETXIQCOMP1 register.
 */
__INLINE uint32_t riu_rwnxfetxiqcomp1_get(void)
{
    return REG_PL_RD(RIU_RWNXFETXIQCOMP1_ADDR);
}

/**
 * @brief Sets the RWNXFETXIQCOMP1 register to a value.
 * The RWNXFETXIQCOMP1 register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxfetxiqcomp1_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXFETXIQCOMP1_ADDR, value);
}

// field definitions
/// TXIQPHASECOMPEN1 field bit
#define RIU_TXIQPHASECOMPEN1_BIT    ((uint32_t)0x20000000)
/// TXIQPHASECOMPEN1 field position
#define RIU_TXIQPHASECOMPEN1_POS    29
/// TXIQGAINCOMPEN1 field bit
#define RIU_TXIQGAINCOMPEN1_BIT     ((uint32_t)0x10000000)
/// TXIQGAINCOMPEN1 field position
#define RIU_TXIQGAINCOMPEN1_POS     28
/// TXIQPHASE1 field mask
#define RIU_TXIQPHASE1_MASK         ((uint32_t)0x01FF0000)
/// TXIQPHASE1 field LSB position
#define RIU_TXIQPHASE1_LSB          16
/// TXIQPHASE1 field width
#define RIU_TXIQPHASE1_WIDTH        ((uint32_t)0x00000009)
/// TXIQGAIN1 field mask
#define RIU_TXIQGAIN1_MASK          ((uint32_t)0x000007FF)
/// TXIQGAIN1 field LSB position
#define RIU_TXIQGAIN1_LSB           0
/// TXIQGAIN1 field width
#define RIU_TXIQGAIN1_WIDTH         ((uint32_t)0x0000000B)

/// TXIQPHASECOMPEN1 field reset value
#define RIU_TXIQPHASECOMPEN1_RST    0x0
/// TXIQGAINCOMPEN1 field reset value
#define RIU_TXIQGAINCOMPEN1_RST     0x0
/// TXIQPHASE1 field reset value
#define RIU_TXIQPHASE1_RST          0x0
/// TXIQGAIN1 field reset value
#define RIU_TXIQGAIN1_RST           0x400

/**
 * @brief Constructs a value for the RWNXFETXIQCOMP1 register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] txiqphasecompen1 - The value to use for the TXIQPHASECOMPEN1 field.
 * @param[in] txiqgaincompen1 - The value to use for the TXIQGAINCOMPEN1 field.
 * @param[in] txiqphase1 - The value to use for the TXIQPHASE1 field.
 * @param[in] txiqgain1 - The value to use for the TXIQGAIN1 field.
 */
__INLINE void riu_rwnxfetxiqcomp1_pack(uint8_t txiqphasecompen1, uint8_t txiqgaincompen1, uint16_t txiqphase1, uint16_t txiqgain1)
{
    REG_PL_WR(RIU_RWNXFETXIQCOMP1_ADDR,  ((uint32_t)txiqphasecompen1 << 29) | ((uint32_t)txiqgaincompen1 << 28) | ((uint32_t)txiqphase1 << 16) | ((uint32_t)txiqgain1 << 0));
}

/**
 * @brief Unpacks RWNXFETXIQCOMP1's fields from current value of the RWNXFETXIQCOMP1 register.
 *
 * Reads the RWNXFETXIQCOMP1 register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] txiqphasecompen1 - Will be populated with the current value of this field from the register.
 * @param[out] txiqgaincompen1 - Will be populated with the current value of this field from the register.
 * @param[out] txiqphase1 - Will be populated with the current value of this field from the register.
 * @param[out] txiqgain1 - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxfetxiqcomp1_unpack(uint8_t* txiqphasecompen1, uint8_t* txiqgaincompen1, uint16_t* txiqphase1, uint16_t* txiqgain1)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFETXIQCOMP1_ADDR);

    *txiqphasecompen1 = (localVal & ((uint32_t)0x20000000)) >> 29;
    *txiqgaincompen1 = (localVal & ((uint32_t)0x10000000)) >> 28;
    *txiqphase1 = (localVal & ((uint32_t)0x01FF0000)) >> 16;
    *txiqgain1 = (localVal & ((uint32_t)0x000007FF)) >> 0;
}

/**
 * @brief Returns the current value of the TXIQPHASECOMPEN1 field in the RWNXFETXIQCOMP1 register.
 *
 * The RWNXFETXIQCOMP1 register will be read and the TXIQPHASECOMPEN1 field's value will be returned.
 *
 * @return The current value of the TXIQPHASECOMPEN1 field in the RWNXFETXIQCOMP1 register.
 */
__INLINE uint8_t riu_txiqphasecompen1_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFETXIQCOMP1_ADDR);
    return ((localVal & ((uint32_t)0x20000000)) >> 29);
}

/**
 * @brief Sets the TXIQPHASECOMPEN1 field of the RWNXFETXIQCOMP1 register.
 *
 * The RWNXFETXIQCOMP1 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] txiqphasecompen1 - The value to set the field to.
 */
__INLINE void riu_txiqphasecompen1_setf(uint8_t txiqphasecompen1)
{
    REG_PL_WR(RIU_RWNXFETXIQCOMP1_ADDR, (REG_PL_RD(RIU_RWNXFETXIQCOMP1_ADDR) & ~((uint32_t)0x20000000)) | ((uint32_t)txiqphasecompen1 << 29));
}

/**
 * @brief Returns the current value of the TXIQGAINCOMPEN1 field in the RWNXFETXIQCOMP1 register.
 *
 * The RWNXFETXIQCOMP1 register will be read and the TXIQGAINCOMPEN1 field's value will be returned.
 *
 * @return The current value of the TXIQGAINCOMPEN1 field in the RWNXFETXIQCOMP1 register.
 */
__INLINE uint8_t riu_txiqgaincompen1_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFETXIQCOMP1_ADDR);
    return ((localVal & ((uint32_t)0x10000000)) >> 28);
}

/**
 * @brief Sets the TXIQGAINCOMPEN1 field of the RWNXFETXIQCOMP1 register.
 *
 * The RWNXFETXIQCOMP1 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] txiqgaincompen1 - The value to set the field to.
 */
__INLINE void riu_txiqgaincompen1_setf(uint8_t txiqgaincompen1)
{
    REG_PL_WR(RIU_RWNXFETXIQCOMP1_ADDR, (REG_PL_RD(RIU_RWNXFETXIQCOMP1_ADDR) & ~((uint32_t)0x10000000)) | ((uint32_t)txiqgaincompen1 << 28));
}

/**
 * @brief Returns the current value of the TXIQPHASE1 field in the RWNXFETXIQCOMP1 register.
 *
 * The RWNXFETXIQCOMP1 register will be read and the TXIQPHASE1 field's value will be returned.
 *
 * @return The current value of the TXIQPHASE1 field in the RWNXFETXIQCOMP1 register.
 */
__INLINE uint16_t riu_txiqphase1_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFETXIQCOMP1_ADDR);
    return ((localVal & ((uint32_t)0x01FF0000)) >> 16);
}

/**
 * @brief Sets the TXIQPHASE1 field of the RWNXFETXIQCOMP1 register.
 *
 * The RWNXFETXIQCOMP1 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] txiqphase1 - The value to set the field to.
 */
__INLINE void riu_txiqphase1_setf(uint16_t txiqphase1)
{
    REG_PL_WR(RIU_RWNXFETXIQCOMP1_ADDR, (REG_PL_RD(RIU_RWNXFETXIQCOMP1_ADDR) & ~((uint32_t)0x01FF0000)) | ((uint32_t)txiqphase1 << 16));
}

/**
 * @brief Returns the current value of the TXIQGAIN1 field in the RWNXFETXIQCOMP1 register.
 *
 * The RWNXFETXIQCOMP1 register will be read and the TXIQGAIN1 field's value will be returned.
 *
 * @return The current value of the TXIQGAIN1 field in the RWNXFETXIQCOMP1 register.
 */
__INLINE uint16_t riu_txiqgain1_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFETXIQCOMP1_ADDR);
    return ((localVal & ((uint32_t)0x000007FF)) >> 0);
}

/**
 * @brief Sets the TXIQGAIN1 field of the RWNXFETXIQCOMP1 register.
 *
 * The RWNXFETXIQCOMP1 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] txiqgain1 - The value to set the field to.
 */
__INLINE void riu_txiqgain1_setf(uint16_t txiqgain1)
{
    REG_PL_WR(RIU_RWNXFETXIQCOMP1_ADDR, (REG_PL_RD(RIU_RWNXFETXIQCOMP1_ADDR) & ~((uint32_t)0x000007FF)) | ((uint32_t)txiqgain1 << 0));
}

#endif // RW_NX_IQ_COMP_EN
/// @}

#if RW_NX_IQ_COMP_EN
/**
 * @name RWNXFERXIQESTCTRL register definitions
 * <table>
 * <caption id="RWNXFERXIQESTCTRL_BF">RWNXFERXIQESTCTRL bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>31:24 <td>        IQESTFOMIN <td>R <td>R/W <td>0x0
 * <tr><td>22:20 <td>       IQESTBWLIST <td>R <td>R/W <td>0x7
 * <tr><td>15:12 <td>       IQESTMCSMIN <td>R <td>R/W <td>0x0
 * <tr><td>11:04 <td>       IQESTSNRMIN <td>R <td>R/W <td>0x0
 * <tr><td>03 <td>    RXIQPHASEESTEN <td>R <td>R/W <td>0
 * <tr><td>02 <td>     RXIQGAINESTEN <td>R <td>R/W <td>0
 * <tr><td>01 <td>   RXIQPHASECOMPEN <td>R <td>R/W <td>0
 * <tr><td>00 <td>    RXIQGAINCOMPEN <td>R <td>R/W <td>0
 * </table>
 *
 * @{
 */

/// Address of the RWNXFERXIQESTCTRL register
#define RIU_RWNXFERXIQESTCTRL_ADDR   0x4033B110
/// Offset of the RWNXFERXIQESTCTRL register from the base address
#define RIU_RWNXFERXIQESTCTRL_OFFSET 0x00000110
/// Index of the RWNXFERXIQESTCTRL register
#define RIU_RWNXFERXIQESTCTRL_INDEX  0x00000044
/// Reset value of the RWNXFERXIQESTCTRL register
#define RIU_RWNXFERXIQESTCTRL_RESET  0x00700000

/**
 * @brief Returns the current value of the RWNXFERXIQESTCTRL register.
 * The RWNXFERXIQESTCTRL register will be read and its value returned.
 * @return The current value of the RWNXFERXIQESTCTRL register.
 */
__INLINE uint32_t riu_rwnxferxiqestctrl_get(void)
{
    return REG_PL_RD(RIU_RWNXFERXIQESTCTRL_ADDR);
}

/**
 * @brief Sets the RWNXFERXIQESTCTRL register to a value.
 * The RWNXFERXIQESTCTRL register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxferxiqestctrl_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXFERXIQESTCTRL_ADDR, value);
}

// field definitions
/// IQESTFOMIN field mask
#define RIU_IQESTFOMIN_MASK        ((uint32_t)0xFF000000)
/// IQESTFOMIN field LSB position
#define RIU_IQESTFOMIN_LSB         24
/// IQESTFOMIN field width
#define RIU_IQESTFOMIN_WIDTH       ((uint32_t)0x00000008)
/// IQESTBWLIST field mask
#define RIU_IQESTBWLIST_MASK       ((uint32_t)0x00700000)
/// IQESTBWLIST field LSB position
#define RIU_IQESTBWLIST_LSB        20
/// IQESTBWLIST field width
#define RIU_IQESTBWLIST_WIDTH      ((uint32_t)0x00000003)
/// IQESTMCSMIN field mask
#define RIU_IQESTMCSMIN_MASK       ((uint32_t)0x0000F000)
/// IQESTMCSMIN field LSB position
#define RIU_IQESTMCSMIN_LSB        12
/// IQESTMCSMIN field width
#define RIU_IQESTMCSMIN_WIDTH      ((uint32_t)0x00000004)
/// IQESTSNRMIN field mask
#define RIU_IQESTSNRMIN_MASK       ((uint32_t)0x00000FF0)
/// IQESTSNRMIN field LSB position
#define RIU_IQESTSNRMIN_LSB        4
/// IQESTSNRMIN field width
#define RIU_IQESTSNRMIN_WIDTH      ((uint32_t)0x00000008)
/// RXIQPHASEESTEN field bit
#define RIU_RXIQPHASEESTEN_BIT     ((uint32_t)0x00000008)
/// RXIQPHASEESTEN field position
#define RIU_RXIQPHASEESTEN_POS     3
/// RXIQGAINESTEN field bit
#define RIU_RXIQGAINESTEN_BIT      ((uint32_t)0x00000004)
/// RXIQGAINESTEN field position
#define RIU_RXIQGAINESTEN_POS      2
/// RXIQPHASECOMPEN field bit
#define RIU_RXIQPHASECOMPEN_BIT    ((uint32_t)0x00000002)
/// RXIQPHASECOMPEN field position
#define RIU_RXIQPHASECOMPEN_POS    1
/// RXIQGAINCOMPEN field bit
#define RIU_RXIQGAINCOMPEN_BIT     ((uint32_t)0x00000001)
/// RXIQGAINCOMPEN field position
#define RIU_RXIQGAINCOMPEN_POS     0

/// IQESTFOMIN field reset value
#define RIU_IQESTFOMIN_RST         0x0
/// IQESTBWLIST field reset value
#define RIU_IQESTBWLIST_RST        0x7
/// IQESTMCSMIN field reset value
#define RIU_IQESTMCSMIN_RST        0x0
/// IQESTSNRMIN field reset value
#define RIU_IQESTSNRMIN_RST        0x0
/// RXIQPHASEESTEN field reset value
#define RIU_RXIQPHASEESTEN_RST     0x0
/// RXIQGAINESTEN field reset value
#define RIU_RXIQGAINESTEN_RST      0x0
/// RXIQPHASECOMPEN field reset value
#define RIU_RXIQPHASECOMPEN_RST    0x0
/// RXIQGAINCOMPEN field reset value
#define RIU_RXIQGAINCOMPEN_RST     0x0

/**
 * @brief Constructs a value for the RWNXFERXIQESTCTRL register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] iqestfomin - The value to use for the IQESTFOMIN field.
 * @param[in] iqestbwlist - The value to use for the IQESTBWLIST field.
 * @param[in] iqestmcsmin - The value to use for the IQESTMCSMIN field.
 * @param[in] iqestsnrmin - The value to use for the IQESTSNRMIN field.
 * @param[in] rxiqphaseesten - The value to use for the RXIQPHASEESTEN field.
 * @param[in] rxiqgainesten - The value to use for the RXIQGAINESTEN field.
 * @param[in] rxiqphasecompen - The value to use for the RXIQPHASECOMPEN field.
 * @param[in] rxiqgaincompen - The value to use for the RXIQGAINCOMPEN field.
 */
__INLINE void riu_rwnxferxiqestctrl_pack(uint8_t iqestfomin, uint8_t iqestbwlist, uint8_t iqestmcsmin, uint8_t iqestsnrmin, uint8_t rxiqphaseesten, uint8_t rxiqgainesten, uint8_t rxiqphasecompen, uint8_t rxiqgaincompen)
{
    REG_PL_WR(RIU_RWNXFERXIQESTCTRL_ADDR,  ((uint32_t)iqestfomin << 24) | ((uint32_t)iqestbwlist << 20) | ((uint32_t)iqestmcsmin << 12) | ((uint32_t)iqestsnrmin << 4) | ((uint32_t)rxiqphaseesten << 3) | ((uint32_t)rxiqgainesten << 2) | ((uint32_t)rxiqphasecompen << 1) | ((uint32_t)rxiqgaincompen << 0));
}

/**
 * @brief Unpacks RWNXFERXIQESTCTRL's fields from current value of the RWNXFERXIQESTCTRL register.
 *
 * Reads the RWNXFERXIQESTCTRL register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] iqestfomin - Will be populated with the current value of this field from the register.
 * @param[out] iqestbwlist - Will be populated with the current value of this field from the register.
 * @param[out] iqestmcsmin - Will be populated with the current value of this field from the register.
 * @param[out] iqestsnrmin - Will be populated with the current value of this field from the register.
 * @param[out] rxiqphaseesten - Will be populated with the current value of this field from the register.
 * @param[out] rxiqgainesten - Will be populated with the current value of this field from the register.
 * @param[out] rxiqphasecompen - Will be populated with the current value of this field from the register.
 * @param[out] rxiqgaincompen - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxferxiqestctrl_unpack(uint8_t* iqestfomin, uint8_t* iqestbwlist, uint8_t* iqestmcsmin, uint8_t* iqestsnrmin, uint8_t* rxiqphaseesten, uint8_t* rxiqgainesten, uint8_t* rxiqphasecompen, uint8_t* rxiqgaincompen)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFERXIQESTCTRL_ADDR);

    *iqestfomin = (localVal & ((uint32_t)0xFF000000)) >> 24;
    *iqestbwlist = (localVal & ((uint32_t)0x00700000)) >> 20;
    *iqestmcsmin = (localVal & ((uint32_t)0x0000F000)) >> 12;
    *iqestsnrmin = (localVal & ((uint32_t)0x00000FF0)) >> 4;
    *rxiqphaseesten = (localVal & ((uint32_t)0x00000008)) >> 3;
    *rxiqgainesten = (localVal & ((uint32_t)0x00000004)) >> 2;
    *rxiqphasecompen = (localVal & ((uint32_t)0x00000002)) >> 1;
    *rxiqgaincompen = (localVal & ((uint32_t)0x00000001)) >> 0;
}

/**
 * @brief Returns the current value of the IQESTFOMIN field in the RWNXFERXIQESTCTRL register.
 *
 * The RWNXFERXIQESTCTRL register will be read and the IQESTFOMIN field's value will be returned.
 *
 * @return The current value of the IQESTFOMIN field in the RWNXFERXIQESTCTRL register.
 */
__INLINE uint8_t riu_iqestfomin_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFERXIQESTCTRL_ADDR);
    return ((localVal & ((uint32_t)0xFF000000)) >> 24);
}

/**
 * @brief Sets the IQESTFOMIN field of the RWNXFERXIQESTCTRL register.
 *
 * The RWNXFERXIQESTCTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] iqestfomin - The value to set the field to.
 */
__INLINE void riu_iqestfomin_setf(uint8_t iqestfomin)
{
    REG_PL_WR(RIU_RWNXFERXIQESTCTRL_ADDR, (REG_PL_RD(RIU_RWNXFERXIQESTCTRL_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)iqestfomin << 24));
}

/**
 * @brief Returns the current value of the IQESTBWLIST field in the RWNXFERXIQESTCTRL register.
 *
 * The RWNXFERXIQESTCTRL register will be read and the IQESTBWLIST field's value will be returned.
 *
 * @return The current value of the IQESTBWLIST field in the RWNXFERXIQESTCTRL register.
 */
__INLINE uint8_t riu_iqestbwlist_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFERXIQESTCTRL_ADDR);
    return ((localVal & ((uint32_t)0x00700000)) >> 20);
}

/**
 * @brief Sets the IQESTBWLIST field of the RWNXFERXIQESTCTRL register.
 *
 * The RWNXFERXIQESTCTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] iqestbwlist - The value to set the field to.
 */
__INLINE void riu_iqestbwlist_setf(uint8_t iqestbwlist)
{
    REG_PL_WR(RIU_RWNXFERXIQESTCTRL_ADDR, (REG_PL_RD(RIU_RWNXFERXIQESTCTRL_ADDR) & ~((uint32_t)0x00700000)) | ((uint32_t)iqestbwlist << 20));
}

/**
 * @brief Returns the current value of the IQESTMCSMIN field in the RWNXFERXIQESTCTRL register.
 *
 * The RWNXFERXIQESTCTRL register will be read and the IQESTMCSMIN field's value will be returned.
 *
 * @return The current value of the IQESTMCSMIN field in the RWNXFERXIQESTCTRL register.
 */
__INLINE uint8_t riu_iqestmcsmin_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFERXIQESTCTRL_ADDR);
    return ((localVal & ((uint32_t)0x0000F000)) >> 12);
}

/**
 * @brief Sets the IQESTMCSMIN field of the RWNXFERXIQESTCTRL register.
 *
 * The RWNXFERXIQESTCTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] iqestmcsmin - The value to set the field to.
 */
__INLINE void riu_iqestmcsmin_setf(uint8_t iqestmcsmin)
{
    REG_PL_WR(RIU_RWNXFERXIQESTCTRL_ADDR, (REG_PL_RD(RIU_RWNXFERXIQESTCTRL_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)iqestmcsmin << 12));
}

/**
 * @brief Returns the current value of the IQESTSNRMIN field in the RWNXFERXIQESTCTRL register.
 *
 * The RWNXFERXIQESTCTRL register will be read and the IQESTSNRMIN field's value will be returned.
 *
 * @return The current value of the IQESTSNRMIN field in the RWNXFERXIQESTCTRL register.
 */
__INLINE uint8_t riu_iqestsnrmin_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFERXIQESTCTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000FF0)) >> 4);
}

/**
 * @brief Sets the IQESTSNRMIN field of the RWNXFERXIQESTCTRL register.
 *
 * The RWNXFERXIQESTCTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] iqestsnrmin - The value to set the field to.
 */
__INLINE void riu_iqestsnrmin_setf(uint8_t iqestsnrmin)
{
    REG_PL_WR(RIU_RWNXFERXIQESTCTRL_ADDR, (REG_PL_RD(RIU_RWNXFERXIQESTCTRL_ADDR) & ~((uint32_t)0x00000FF0)) | ((uint32_t)iqestsnrmin << 4));
}

/**
 * @brief Returns the current value of the RXIQPHASEESTEN field in the RWNXFERXIQESTCTRL register.
 *
 * The RWNXFERXIQESTCTRL register will be read and the RXIQPHASEESTEN field's value will be returned.
 *
 * @return The current value of the RXIQPHASEESTEN field in the RWNXFERXIQESTCTRL register.
 */
__INLINE uint8_t riu_rxiqphaseesten_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFERXIQESTCTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000008)) >> 3);
}

/**
 * @brief Sets the RXIQPHASEESTEN field of the RWNXFERXIQESTCTRL register.
 *
 * The RWNXFERXIQESTCTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rxiqphaseesten - The value to set the field to.
 */
__INLINE void riu_rxiqphaseesten_setf(uint8_t rxiqphaseesten)
{
    REG_PL_WR(RIU_RWNXFERXIQESTCTRL_ADDR, (REG_PL_RD(RIU_RWNXFERXIQESTCTRL_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)rxiqphaseesten << 3));
}

/**
 * @brief Returns the current value of the RXIQGAINESTEN field in the RWNXFERXIQESTCTRL register.
 *
 * The RWNXFERXIQESTCTRL register will be read and the RXIQGAINESTEN field's value will be returned.
 *
 * @return The current value of the RXIQGAINESTEN field in the RWNXFERXIQESTCTRL register.
 */
__INLINE uint8_t riu_rxiqgainesten_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFERXIQESTCTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000004)) >> 2);
}

/**
 * @brief Sets the RXIQGAINESTEN field of the RWNXFERXIQESTCTRL register.
 *
 * The RWNXFERXIQESTCTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rxiqgainesten - The value to set the field to.
 */
__INLINE void riu_rxiqgainesten_setf(uint8_t rxiqgainesten)
{
    REG_PL_WR(RIU_RWNXFERXIQESTCTRL_ADDR, (REG_PL_RD(RIU_RWNXFERXIQESTCTRL_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)rxiqgainesten << 2));
}

/**
 * @brief Returns the current value of the RXIQPHASECOMPEN field in the RWNXFERXIQESTCTRL register.
 *
 * The RWNXFERXIQESTCTRL register will be read and the RXIQPHASECOMPEN field's value will be returned.
 *
 * @return The current value of the RXIQPHASECOMPEN field in the RWNXFERXIQESTCTRL register.
 */
__INLINE uint8_t riu_rxiqphasecompen_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFERXIQESTCTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000002)) >> 1);
}

/**
 * @brief Sets the RXIQPHASECOMPEN field of the RWNXFERXIQESTCTRL register.
 *
 * The RWNXFERXIQESTCTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rxiqphasecompen - The value to set the field to.
 */
__INLINE void riu_rxiqphasecompen_setf(uint8_t rxiqphasecompen)
{
    REG_PL_WR(RIU_RWNXFERXIQESTCTRL_ADDR, (REG_PL_RD(RIU_RWNXFERXIQESTCTRL_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)rxiqphasecompen << 1));
}

/**
 * @brief Returns the current value of the RXIQGAINCOMPEN field in the RWNXFERXIQESTCTRL register.
 *
 * The RWNXFERXIQESTCTRL register will be read and the RXIQGAINCOMPEN field's value will be returned.
 *
 * @return The current value of the RXIQGAINCOMPEN field in the RWNXFERXIQESTCTRL register.
 */
__INLINE uint8_t riu_rxiqgaincompen_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFERXIQESTCTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief Sets the RXIQGAINCOMPEN field of the RWNXFERXIQESTCTRL register.
 *
 * The RWNXFERXIQESTCTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rxiqgaincompen - The value to set the field to.
 */
__INLINE void riu_rxiqgaincompen_setf(uint8_t rxiqgaincompen)
{
    REG_PL_WR(RIU_RWNXFERXIQESTCTRL_ADDR, (REG_PL_RD(RIU_RWNXFERXIQESTCTRL_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)rxiqgaincompen << 0));
}

#endif // RW_NX_IQ_COMP_EN
/// @}

#if RW_NX_IQ_COMP_EN
/**
 * @name RWNXFERXIQESTLOOP register definitions
 * <table>
 * <caption id="RWNXFERXIQESTLOOP_BF">RWNXFERXIQESTLOOP bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>30:28 <td>      RXIQESTSTEP4 <td>R <td>R/W <td>0x2
 * <tr><td>27:25 <td>      RXIQESTSTEP3 <td>R <td>R/W <td>0x2
 * <tr><td>24:22 <td>      RXIQESTSTEP2 <td>R <td>R/W <td>0x2
 * <tr><td>21:19 <td>      RXIQESTSTEP1 <td>R <td>R/W <td>0x2
 * <tr><td>18:16 <td>      RXIQESTSTEP0 <td>R <td>R/W <td>0x2
 * <tr><td>15:13 <td>RXIQESTPHASESTEPSTOP <td>R <td>R/W <td>0x1
 * <tr><td>12:10 <td>RXIQESTPHASESTEPINIT <td>R <td>R/W <td>0x5
 * <tr><td>09:07 <td>RXIQESTGAINSTEPSTOP <td>R <td>R/W <td>0x1
 * <tr><td>06:04 <td>RXIQESTGAINSTEPINIT <td>R <td>R/W <td>0x6
 * <tr><td>02:00 <td>        RXIQESTDEL <td>R <td>R/W <td>0x2
 * </table>
 *
 * @{
 */

/// Address of the RWNXFERXIQESTLOOP register
#define RIU_RWNXFERXIQESTLOOP_ADDR   0x4033B114
/// Offset of the RWNXFERXIQESTLOOP register from the base address
#define RIU_RWNXFERXIQESTLOOP_OFFSET 0x00000114
/// Index of the RWNXFERXIQESTLOOP register
#define RIU_RWNXFERXIQESTLOOP_INDEX  0x00000045
/// Reset value of the RWNXFERXIQESTLOOP register
#define RIU_RWNXFERXIQESTLOOP_RESET  0x249234E2

/**
 * @brief Returns the current value of the RWNXFERXIQESTLOOP register.
 * The RWNXFERXIQESTLOOP register will be read and its value returned.
 * @return The current value of the RWNXFERXIQESTLOOP register.
 */
__INLINE uint32_t riu_rwnxferxiqestloop_get(void)
{
    return REG_PL_RD(RIU_RWNXFERXIQESTLOOP_ADDR);
}

/**
 * @brief Sets the RWNXFERXIQESTLOOP register to a value.
 * The RWNXFERXIQESTLOOP register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxferxiqestloop_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXFERXIQESTLOOP_ADDR, value);
}

// field definitions
/// RXIQESTSTEP4 field mask
#define RIU_RXIQESTSTEP4_MASK           ((uint32_t)0x70000000)
/// RXIQESTSTEP4 field LSB position
#define RIU_RXIQESTSTEP4_LSB            28
/// RXIQESTSTEP4 field width
#define RIU_RXIQESTSTEP4_WIDTH          ((uint32_t)0x00000003)
/// RXIQESTSTEP3 field mask
#define RIU_RXIQESTSTEP3_MASK           ((uint32_t)0x0E000000)
/// RXIQESTSTEP3 field LSB position
#define RIU_RXIQESTSTEP3_LSB            25
/// RXIQESTSTEP3 field width
#define RIU_RXIQESTSTEP3_WIDTH          ((uint32_t)0x00000003)
/// RXIQESTSTEP2 field mask
#define RIU_RXIQESTSTEP2_MASK           ((uint32_t)0x01C00000)
/// RXIQESTSTEP2 field LSB position
#define RIU_RXIQESTSTEP2_LSB            22
/// RXIQESTSTEP2 field width
#define RIU_RXIQESTSTEP2_WIDTH          ((uint32_t)0x00000003)
/// RXIQESTSTEP1 field mask
#define RIU_RXIQESTSTEP1_MASK           ((uint32_t)0x00380000)
/// RXIQESTSTEP1 field LSB position
#define RIU_RXIQESTSTEP1_LSB            19
/// RXIQESTSTEP1 field width
#define RIU_RXIQESTSTEP1_WIDTH          ((uint32_t)0x00000003)
/// RXIQESTSTEP0 field mask
#define RIU_RXIQESTSTEP0_MASK           ((uint32_t)0x00070000)
/// RXIQESTSTEP0 field LSB position
#define RIU_RXIQESTSTEP0_LSB            16
/// RXIQESTSTEP0 field width
#define RIU_RXIQESTSTEP0_WIDTH          ((uint32_t)0x00000003)
/// RXIQESTPHASESTEPSTOP field mask
#define RIU_RXIQESTPHASESTEPSTOP_MASK   ((uint32_t)0x0000E000)
/// RXIQESTPHASESTEPSTOP field LSB position
#define RIU_RXIQESTPHASESTEPSTOP_LSB    13
/// RXIQESTPHASESTEPSTOP field width
#define RIU_RXIQESTPHASESTEPSTOP_WIDTH  ((uint32_t)0x00000003)
/// RXIQESTPHASESTEPINIT field mask
#define RIU_RXIQESTPHASESTEPINIT_MASK   ((uint32_t)0x00001C00)
/// RXIQESTPHASESTEPINIT field LSB position
#define RIU_RXIQESTPHASESTEPINIT_LSB    10
/// RXIQESTPHASESTEPINIT field width
#define RIU_RXIQESTPHASESTEPINIT_WIDTH  ((uint32_t)0x00000003)
/// RXIQESTGAINSTEPSTOP field mask
#define RIU_RXIQESTGAINSTEPSTOP_MASK    ((uint32_t)0x00000380)
/// RXIQESTGAINSTEPSTOP field LSB position
#define RIU_RXIQESTGAINSTEPSTOP_LSB     7
/// RXIQESTGAINSTEPSTOP field width
#define RIU_RXIQESTGAINSTEPSTOP_WIDTH   ((uint32_t)0x00000003)
/// RXIQESTGAINSTEPINIT field mask
#define RIU_RXIQESTGAINSTEPINIT_MASK    ((uint32_t)0x00000070)
/// RXIQESTGAINSTEPINIT field LSB position
#define RIU_RXIQESTGAINSTEPINIT_LSB     4
/// RXIQESTGAINSTEPINIT field width
#define RIU_RXIQESTGAINSTEPINIT_WIDTH   ((uint32_t)0x00000003)
/// RXIQESTDEL field mask
#define RIU_RXIQESTDEL_MASK             ((uint32_t)0x00000007)
/// RXIQESTDEL field LSB position
#define RIU_RXIQESTDEL_LSB              0
/// RXIQESTDEL field width
#define RIU_RXIQESTDEL_WIDTH            ((uint32_t)0x00000003)

/// RXIQESTSTEP4 field reset value
#define RIU_RXIQESTSTEP4_RST            0x2
/// RXIQESTSTEP3 field reset value
#define RIU_RXIQESTSTEP3_RST            0x2
/// RXIQESTSTEP2 field reset value
#define RIU_RXIQESTSTEP2_RST            0x2
/// RXIQESTSTEP1 field reset value
#define RIU_RXIQESTSTEP1_RST            0x2
/// RXIQESTSTEP0 field reset value
#define RIU_RXIQESTSTEP0_RST            0x2
/// RXIQESTPHASESTEPSTOP field reset value
#define RIU_RXIQESTPHASESTEPSTOP_RST    0x1
/// RXIQESTPHASESTEPINIT field reset value
#define RIU_RXIQESTPHASESTEPINIT_RST    0x5
/// RXIQESTGAINSTEPSTOP field reset value
#define RIU_RXIQESTGAINSTEPSTOP_RST     0x1
/// RXIQESTGAINSTEPINIT field reset value
#define RIU_RXIQESTGAINSTEPINIT_RST     0x6
/// RXIQESTDEL field reset value
#define RIU_RXIQESTDEL_RST              0x2

/**
 * @brief Constructs a value for the RWNXFERXIQESTLOOP register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] rxiqeststep4 - The value to use for the RXIQESTSTEP4 field.
 * @param[in] rxiqeststep3 - The value to use for the RXIQESTSTEP3 field.
 * @param[in] rxiqeststep2 - The value to use for the RXIQESTSTEP2 field.
 * @param[in] rxiqeststep1 - The value to use for the RXIQESTSTEP1 field.
 * @param[in] rxiqeststep0 - The value to use for the RXIQESTSTEP0 field.
 * @param[in] rxiqestphasestepstop - The value to use for the RXIQESTPHASESTEPSTOP field.
 * @param[in] rxiqestphasestepinit - The value to use for the RXIQESTPHASESTEPINIT field.
 * @param[in] rxiqestgainstepstop - The value to use for the RXIQESTGAINSTEPSTOP field.
 * @param[in] rxiqestgainstepinit - The value to use for the RXIQESTGAINSTEPINIT field.
 * @param[in] rxiqestdel - The value to use for the RXIQESTDEL field.
 */
__INLINE void riu_rwnxferxiqestloop_pack(uint8_t rxiqeststep4, uint8_t rxiqeststep3, uint8_t rxiqeststep2, uint8_t rxiqeststep1, uint8_t rxiqeststep0, uint8_t rxiqestphasestepstop, uint8_t rxiqestphasestepinit, uint8_t rxiqestgainstepstop, uint8_t rxiqestgainstepinit, uint8_t rxiqestdel)
{
    REG_PL_WR(RIU_RWNXFERXIQESTLOOP_ADDR,  ((uint32_t)rxiqeststep4 << 28) | ((uint32_t)rxiqeststep3 << 25) | ((uint32_t)rxiqeststep2 << 22) | ((uint32_t)rxiqeststep1 << 19) | ((uint32_t)rxiqeststep0 << 16) | ((uint32_t)rxiqestphasestepstop << 13) | ((uint32_t)rxiqestphasestepinit << 10) | ((uint32_t)rxiqestgainstepstop << 7) | ((uint32_t)rxiqestgainstepinit << 4) | ((uint32_t)rxiqestdel << 0));
}

/**
 * @brief Unpacks RWNXFERXIQESTLOOP's fields from current value of the RWNXFERXIQESTLOOP register.
 *
 * Reads the RWNXFERXIQESTLOOP register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] rxiqeststep4 - Will be populated with the current value of this field from the register.
 * @param[out] rxiqeststep3 - Will be populated with the current value of this field from the register.
 * @param[out] rxiqeststep2 - Will be populated with the current value of this field from the register.
 * @param[out] rxiqeststep1 - Will be populated with the current value of this field from the register.
 * @param[out] rxiqeststep0 - Will be populated with the current value of this field from the register.
 * @param[out] rxiqestphasestepstop - Will be populated with the current value of this field from the register.
 * @param[out] rxiqestphasestepinit - Will be populated with the current value of this field from the register.
 * @param[out] rxiqestgainstepstop - Will be populated with the current value of this field from the register.
 * @param[out] rxiqestgainstepinit - Will be populated with the current value of this field from the register.
 * @param[out] rxiqestdel - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxferxiqestloop_unpack(uint8_t* rxiqeststep4, uint8_t* rxiqeststep3, uint8_t* rxiqeststep2, uint8_t* rxiqeststep1, uint8_t* rxiqeststep0, uint8_t* rxiqestphasestepstop, uint8_t* rxiqestphasestepinit, uint8_t* rxiqestgainstepstop, uint8_t* rxiqestgainstepinit, uint8_t* rxiqestdel)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFERXIQESTLOOP_ADDR);

    *rxiqeststep4 = (localVal & ((uint32_t)0x70000000)) >> 28;
    *rxiqeststep3 = (localVal & ((uint32_t)0x0E000000)) >> 25;
    *rxiqeststep2 = (localVal & ((uint32_t)0x01C00000)) >> 22;
    *rxiqeststep1 = (localVal & ((uint32_t)0x00380000)) >> 19;
    *rxiqeststep0 = (localVal & ((uint32_t)0x00070000)) >> 16;
    *rxiqestphasestepstop = (localVal & ((uint32_t)0x0000E000)) >> 13;
    *rxiqestphasestepinit = (localVal & ((uint32_t)0x00001C00)) >> 10;
    *rxiqestgainstepstop = (localVal & ((uint32_t)0x00000380)) >> 7;
    *rxiqestgainstepinit = (localVal & ((uint32_t)0x00000070)) >> 4;
    *rxiqestdel = (localVal & ((uint32_t)0x00000007)) >> 0;
}

/**
 * @brief Returns the current value of the RXIQESTSTEP4 field in the RWNXFERXIQESTLOOP register.
 *
 * The RWNXFERXIQESTLOOP register will be read and the RXIQESTSTEP4 field's value will be returned.
 *
 * @return The current value of the RXIQESTSTEP4 field in the RWNXFERXIQESTLOOP register.
 */
__INLINE uint8_t riu_rxiqeststep4_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFERXIQESTLOOP_ADDR);
    return ((localVal & ((uint32_t)0x70000000)) >> 28);
}

/**
 * @brief Sets the RXIQESTSTEP4 field of the RWNXFERXIQESTLOOP register.
 *
 * The RWNXFERXIQESTLOOP register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rxiqeststep4 - The value to set the field to.
 */
__INLINE void riu_rxiqeststep4_setf(uint8_t rxiqeststep4)
{
    REG_PL_WR(RIU_RWNXFERXIQESTLOOP_ADDR, (REG_PL_RD(RIU_RWNXFERXIQESTLOOP_ADDR) & ~((uint32_t)0x70000000)) | ((uint32_t)rxiqeststep4 << 28));
}

/**
 * @brief Returns the current value of the RXIQESTSTEP3 field in the RWNXFERXIQESTLOOP register.
 *
 * The RWNXFERXIQESTLOOP register will be read and the RXIQESTSTEP3 field's value will be returned.
 *
 * @return The current value of the RXIQESTSTEP3 field in the RWNXFERXIQESTLOOP register.
 */
__INLINE uint8_t riu_rxiqeststep3_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFERXIQESTLOOP_ADDR);
    return ((localVal & ((uint32_t)0x0E000000)) >> 25);
}

/**
 * @brief Sets the RXIQESTSTEP3 field of the RWNXFERXIQESTLOOP register.
 *
 * The RWNXFERXIQESTLOOP register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rxiqeststep3 - The value to set the field to.
 */
__INLINE void riu_rxiqeststep3_setf(uint8_t rxiqeststep3)
{
    REG_PL_WR(RIU_RWNXFERXIQESTLOOP_ADDR, (REG_PL_RD(RIU_RWNXFERXIQESTLOOP_ADDR) & ~((uint32_t)0x0E000000)) | ((uint32_t)rxiqeststep3 << 25));
}

/**
 * @brief Returns the current value of the RXIQESTSTEP2 field in the RWNXFERXIQESTLOOP register.
 *
 * The RWNXFERXIQESTLOOP register will be read and the RXIQESTSTEP2 field's value will be returned.
 *
 * @return The current value of the RXIQESTSTEP2 field in the RWNXFERXIQESTLOOP register.
 */
__INLINE uint8_t riu_rxiqeststep2_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFERXIQESTLOOP_ADDR);
    return ((localVal & ((uint32_t)0x01C00000)) >> 22);
}

/**
 * @brief Sets the RXIQESTSTEP2 field of the RWNXFERXIQESTLOOP register.
 *
 * The RWNXFERXIQESTLOOP register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rxiqeststep2 - The value to set the field to.
 */
__INLINE void riu_rxiqeststep2_setf(uint8_t rxiqeststep2)
{
    REG_PL_WR(RIU_RWNXFERXIQESTLOOP_ADDR, (REG_PL_RD(RIU_RWNXFERXIQESTLOOP_ADDR) & ~((uint32_t)0x01C00000)) | ((uint32_t)rxiqeststep2 << 22));
}

/**
 * @brief Returns the current value of the RXIQESTSTEP1 field in the RWNXFERXIQESTLOOP register.
 *
 * The RWNXFERXIQESTLOOP register will be read and the RXIQESTSTEP1 field's value will be returned.
 *
 * @return The current value of the RXIQESTSTEP1 field in the RWNXFERXIQESTLOOP register.
 */
__INLINE uint8_t riu_rxiqeststep1_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFERXIQESTLOOP_ADDR);
    return ((localVal & ((uint32_t)0x00380000)) >> 19);
}

/**
 * @brief Sets the RXIQESTSTEP1 field of the RWNXFERXIQESTLOOP register.
 *
 * The RWNXFERXIQESTLOOP register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rxiqeststep1 - The value to set the field to.
 */
__INLINE void riu_rxiqeststep1_setf(uint8_t rxiqeststep1)
{
    REG_PL_WR(RIU_RWNXFERXIQESTLOOP_ADDR, (REG_PL_RD(RIU_RWNXFERXIQESTLOOP_ADDR) & ~((uint32_t)0x00380000)) | ((uint32_t)rxiqeststep1 << 19));
}

/**
 * @brief Returns the current value of the RXIQESTSTEP0 field in the RWNXFERXIQESTLOOP register.
 *
 * The RWNXFERXIQESTLOOP register will be read and the RXIQESTSTEP0 field's value will be returned.
 *
 * @return The current value of the RXIQESTSTEP0 field in the RWNXFERXIQESTLOOP register.
 */
__INLINE uint8_t riu_rxiqeststep0_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFERXIQESTLOOP_ADDR);
    return ((localVal & ((uint32_t)0x00070000)) >> 16);
}

/**
 * @brief Sets the RXIQESTSTEP0 field of the RWNXFERXIQESTLOOP register.
 *
 * The RWNXFERXIQESTLOOP register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rxiqeststep0 - The value to set the field to.
 */
__INLINE void riu_rxiqeststep0_setf(uint8_t rxiqeststep0)
{
    REG_PL_WR(RIU_RWNXFERXIQESTLOOP_ADDR, (REG_PL_RD(RIU_RWNXFERXIQESTLOOP_ADDR) & ~((uint32_t)0x00070000)) | ((uint32_t)rxiqeststep0 << 16));
}

/**
 * @brief Returns the current value of the RXIQESTPHASESTEPSTOP field in the RWNXFERXIQESTLOOP register.
 *
 * The RWNXFERXIQESTLOOP register will be read and the RXIQESTPHASESTEPSTOP field's value will be returned.
 *
 * @return The current value of the RXIQESTPHASESTEPSTOP field in the RWNXFERXIQESTLOOP register.
 */
__INLINE uint8_t riu_rxiqestphasestepstop_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFERXIQESTLOOP_ADDR);
    return ((localVal & ((uint32_t)0x0000E000)) >> 13);
}

/**
 * @brief Sets the RXIQESTPHASESTEPSTOP field of the RWNXFERXIQESTLOOP register.
 *
 * The RWNXFERXIQESTLOOP register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rxiqestphasestepstop - The value to set the field to.
 */
__INLINE void riu_rxiqestphasestepstop_setf(uint8_t rxiqestphasestepstop)
{
    REG_PL_WR(RIU_RWNXFERXIQESTLOOP_ADDR, (REG_PL_RD(RIU_RWNXFERXIQESTLOOP_ADDR) & ~((uint32_t)0x0000E000)) | ((uint32_t)rxiqestphasestepstop << 13));
}

/**
 * @brief Returns the current value of the RXIQESTPHASESTEPINIT field in the RWNXFERXIQESTLOOP register.
 *
 * The RWNXFERXIQESTLOOP register will be read and the RXIQESTPHASESTEPINIT field's value will be returned.
 *
 * @return The current value of the RXIQESTPHASESTEPINIT field in the RWNXFERXIQESTLOOP register.
 */
__INLINE uint8_t riu_rxiqestphasestepinit_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFERXIQESTLOOP_ADDR);
    return ((localVal & ((uint32_t)0x00001C00)) >> 10);
}

/**
 * @brief Sets the RXIQESTPHASESTEPINIT field of the RWNXFERXIQESTLOOP register.
 *
 * The RWNXFERXIQESTLOOP register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rxiqestphasestepinit - The value to set the field to.
 */
__INLINE void riu_rxiqestphasestepinit_setf(uint8_t rxiqestphasestepinit)
{
    REG_PL_WR(RIU_RWNXFERXIQESTLOOP_ADDR, (REG_PL_RD(RIU_RWNXFERXIQESTLOOP_ADDR) & ~((uint32_t)0x00001C00)) | ((uint32_t)rxiqestphasestepinit << 10));
}

/**
 * @brief Returns the current value of the RXIQESTGAINSTEPSTOP field in the RWNXFERXIQESTLOOP register.
 *
 * The RWNXFERXIQESTLOOP register will be read and the RXIQESTGAINSTEPSTOP field's value will be returned.
 *
 * @return The current value of the RXIQESTGAINSTEPSTOP field in the RWNXFERXIQESTLOOP register.
 */
__INLINE uint8_t riu_rxiqestgainstepstop_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFERXIQESTLOOP_ADDR);
    return ((localVal & ((uint32_t)0x00000380)) >> 7);
}

/**
 * @brief Sets the RXIQESTGAINSTEPSTOP field of the RWNXFERXIQESTLOOP register.
 *
 * The RWNXFERXIQESTLOOP register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rxiqestgainstepstop - The value to set the field to.
 */
__INLINE void riu_rxiqestgainstepstop_setf(uint8_t rxiqestgainstepstop)
{
    REG_PL_WR(RIU_RWNXFERXIQESTLOOP_ADDR, (REG_PL_RD(RIU_RWNXFERXIQESTLOOP_ADDR) & ~((uint32_t)0x00000380)) | ((uint32_t)rxiqestgainstepstop << 7));
}

/**
 * @brief Returns the current value of the RXIQESTGAINSTEPINIT field in the RWNXFERXIQESTLOOP register.
 *
 * The RWNXFERXIQESTLOOP register will be read and the RXIQESTGAINSTEPINIT field's value will be returned.
 *
 * @return The current value of the RXIQESTGAINSTEPINIT field in the RWNXFERXIQESTLOOP register.
 */
__INLINE uint8_t riu_rxiqestgainstepinit_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFERXIQESTLOOP_ADDR);
    return ((localVal & ((uint32_t)0x00000070)) >> 4);
}

/**
 * @brief Sets the RXIQESTGAINSTEPINIT field of the RWNXFERXIQESTLOOP register.
 *
 * The RWNXFERXIQESTLOOP register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rxiqestgainstepinit - The value to set the field to.
 */
__INLINE void riu_rxiqestgainstepinit_setf(uint8_t rxiqestgainstepinit)
{
    REG_PL_WR(RIU_RWNXFERXIQESTLOOP_ADDR, (REG_PL_RD(RIU_RWNXFERXIQESTLOOP_ADDR) & ~((uint32_t)0x00000070)) | ((uint32_t)rxiqestgainstepinit << 4));
}

/**
 * @brief Returns the current value of the RXIQESTDEL field in the RWNXFERXIQESTLOOP register.
 *
 * The RWNXFERXIQESTLOOP register will be read and the RXIQESTDEL field's value will be returned.
 *
 * @return The current value of the RXIQESTDEL field in the RWNXFERXIQESTLOOP register.
 */
__INLINE uint8_t riu_rxiqestdel_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFERXIQESTLOOP_ADDR);
    return ((localVal & ((uint32_t)0x00000007)) >> 0);
}

/**
 * @brief Sets the RXIQESTDEL field of the RWNXFERXIQESTLOOP register.
 *
 * The RWNXFERXIQESTLOOP register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rxiqestdel - The value to set the field to.
 */
__INLINE void riu_rxiqestdel_setf(uint8_t rxiqestdel)
{
    REG_PL_WR(RIU_RWNXFERXIQESTLOOP_ADDR, (REG_PL_RD(RIU_RWNXFERXIQESTLOOP_ADDR) & ~((uint32_t)0x00000007)) | ((uint32_t)rxiqestdel << 0));
}

#endif // RW_NX_IQ_COMP_EN
/// @}

#if RW_NX_IQ_COMP_EN
/**
 * @name RWNXFERXIQESTCLR register definitions
 * <table>
 * <caption id="RWNXFERXIQESTCLR_BF">RWNXFERXIQESTCLR bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>00 <td>      IQESTITERCLR <td>R <td>S <td>0
 * </table>
 *
 * @{
 */

/// Address of the RWNXFERXIQESTCLR register
#define RIU_RWNXFERXIQESTCLR_ADDR   0x4033B118
/// Offset of the RWNXFERXIQESTCLR register from the base address
#define RIU_RWNXFERXIQESTCLR_OFFSET 0x00000118
/// Index of the RWNXFERXIQESTCLR register
#define RIU_RWNXFERXIQESTCLR_INDEX  0x00000046
/// Reset value of the RWNXFERXIQESTCLR register
#define RIU_RWNXFERXIQESTCLR_RESET  0x00000000

/**
 * @brief Returns the current value of the RWNXFERXIQESTCLR register.
 * The RWNXFERXIQESTCLR register will be read and its value returned.
 * @return The current value of the RWNXFERXIQESTCLR register.
 */
__INLINE uint32_t riu_rwnxferxiqestclr_get(void)
{
    return REG_PL_RD(RIU_RWNXFERXIQESTCLR_ADDR);
}

/**
 * @brief Sets the RWNXFERXIQESTCLR register to a value.
 * The RWNXFERXIQESTCLR register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxferxiqestclr_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXFERXIQESTCLR_ADDR, value);
}

// field definitions
/// IQESTITERCLR field bit
#define RIU_IQESTITERCLR_BIT    ((uint32_t)0x00000001)
/// IQESTITERCLR field position
#define RIU_IQESTITERCLR_POS    0

/// IQESTITERCLR field reset value
#define RIU_IQESTITERCLR_RST    0x0

/**
 * @brief Returns the current value of the IQESTITERCLR field in the RWNXFERXIQESTCLR register.
 *
 * The RWNXFERXIQESTCLR register will be read and the IQESTITERCLR field's value will be returned.
 *
 * @return The current value of the IQESTITERCLR field in the RWNXFERXIQESTCLR register.
 */
__INLINE uint8_t riu_iqestiterclr_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFERXIQESTCLR_ADDR);
    return (localVal >> 0);
}

/**
 * @brief Sets the IQESTITERCLR field of the RWNXFERXIQESTCLR register.
 *
 * The RWNXFERXIQESTCLR register will be read, modified to contain the new field value, and written.
 *
 * @param[in] iqestiterclr - The value to set the field to.
 */
__INLINE void riu_iqestiterclr_setf(uint8_t iqestiterclr)
{
    REG_PL_WR(RIU_RWNXFERXIQESTCLR_ADDR, (uint32_t)iqestiterclr << 0);
}

#endif // RW_NX_IQ_COMP_EN
/// @}

#if RW_NX_IQ_COMP_EN
/**
 * @name RWNXFERXIQCOMP0 register definitions
 * <table>
 * <caption id="RWNXFERXIQCOMP0_BF">RWNXFERXIQCOMP0 bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>24:16 <td>        RXIQPHASE0 <td>R <td>R/W <td>0x0
 * <tr><td>10:00 <td>         RXIQGAIN0 <td>R <td>R/W <td>0x400
 * </table>
 *
 * @{
 */

/// Address of the RWNXFERXIQCOMP0 register
#define RIU_RWNXFERXIQCOMP0_ADDR   0x4033B11C
/// Offset of the RWNXFERXIQCOMP0 register from the base address
#define RIU_RWNXFERXIQCOMP0_OFFSET 0x0000011C
/// Index of the RWNXFERXIQCOMP0 register
#define RIU_RWNXFERXIQCOMP0_INDEX  0x00000047
/// Reset value of the RWNXFERXIQCOMP0 register
#define RIU_RWNXFERXIQCOMP0_RESET  0x00000400

/**
 * @brief Returns the current value of the RWNXFERXIQCOMP0 register.
 * The RWNXFERXIQCOMP0 register will be read and its value returned.
 * @return The current value of the RWNXFERXIQCOMP0 register.
 */
__INLINE uint32_t riu_rwnxferxiqcomp0_get(void)
{
    return REG_PL_RD(RIU_RWNXFERXIQCOMP0_ADDR);
}

/**
 * @brief Sets the RWNXFERXIQCOMP0 register to a value.
 * The RWNXFERXIQCOMP0 register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxferxiqcomp0_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXFERXIQCOMP0_ADDR, value);
}

// field definitions
/// RXIQPHASE0 field mask
#define RIU_RXIQPHASE0_MASK   ((uint32_t)0x01FF0000)
/// RXIQPHASE0 field LSB position
#define RIU_RXIQPHASE0_LSB    16
/// RXIQPHASE0 field width
#define RIU_RXIQPHASE0_WIDTH  ((uint32_t)0x00000009)
/// RXIQGAIN0 field mask
#define RIU_RXIQGAIN0_MASK    ((uint32_t)0x000007FF)
/// RXIQGAIN0 field LSB position
#define RIU_RXIQGAIN0_LSB     0
/// RXIQGAIN0 field width
#define RIU_RXIQGAIN0_WIDTH   ((uint32_t)0x0000000B)

/// RXIQPHASE0 field reset value
#define RIU_RXIQPHASE0_RST    0x0
/// RXIQGAIN0 field reset value
#define RIU_RXIQGAIN0_RST     0x400

/**
 * @brief Constructs a value for the RWNXFERXIQCOMP0 register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] rxiqphase0 - The value to use for the RXIQPHASE0 field.
 * @param[in] rxiqgain0 - The value to use for the RXIQGAIN0 field.
 */
__INLINE void riu_rwnxferxiqcomp0_pack(uint16_t rxiqphase0, uint16_t rxiqgain0)
{
    REG_PL_WR(RIU_RWNXFERXIQCOMP0_ADDR,  ((uint32_t)rxiqphase0 << 16) | ((uint32_t)rxiqgain0 << 0));
}

/**
 * @brief Unpacks RWNXFERXIQCOMP0's fields from current value of the RWNXFERXIQCOMP0 register.
 *
 * Reads the RWNXFERXIQCOMP0 register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] rxiqphase0 - Will be populated with the current value of this field from the register.
 * @param[out] rxiqgain0 - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxferxiqcomp0_unpack(uint16_t* rxiqphase0, uint16_t* rxiqgain0)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFERXIQCOMP0_ADDR);

    *rxiqphase0 = (localVal & ((uint32_t)0x01FF0000)) >> 16;
    *rxiqgain0 = (localVal & ((uint32_t)0x000007FF)) >> 0;
}

/**
 * @brief Returns the current value of the RXIQPHASE0 field in the RWNXFERXIQCOMP0 register.
 *
 * The RWNXFERXIQCOMP0 register will be read and the RXIQPHASE0 field's value will be returned.
 *
 * @return The current value of the RXIQPHASE0 field in the RWNXFERXIQCOMP0 register.
 */
__INLINE uint16_t riu_rxiqphase0_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFERXIQCOMP0_ADDR);
    return ((localVal & ((uint32_t)0x01FF0000)) >> 16);
}

/**
 * @brief Sets the RXIQPHASE0 field of the RWNXFERXIQCOMP0 register.
 *
 * The RWNXFERXIQCOMP0 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rxiqphase0 - The value to set the field to.
 */
__INLINE void riu_rxiqphase0_setf(uint16_t rxiqphase0)
{
    REG_PL_WR(RIU_RWNXFERXIQCOMP0_ADDR, (REG_PL_RD(RIU_RWNXFERXIQCOMP0_ADDR) & ~((uint32_t)0x01FF0000)) | ((uint32_t)rxiqphase0 << 16));
}

/**
 * @brief Returns the current value of the RXIQGAIN0 field in the RWNXFERXIQCOMP0 register.
 *
 * The RWNXFERXIQCOMP0 register will be read and the RXIQGAIN0 field's value will be returned.
 *
 * @return The current value of the RXIQGAIN0 field in the RWNXFERXIQCOMP0 register.
 */
__INLINE uint16_t riu_rxiqgain0_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFERXIQCOMP0_ADDR);
    return ((localVal & ((uint32_t)0x000007FF)) >> 0);
}

/**
 * @brief Sets the RXIQGAIN0 field of the RWNXFERXIQCOMP0 register.
 *
 * The RWNXFERXIQCOMP0 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rxiqgain0 - The value to set the field to.
 */
__INLINE void riu_rxiqgain0_setf(uint16_t rxiqgain0)
{
    REG_PL_WR(RIU_RWNXFERXIQCOMP0_ADDR, (REG_PL_RD(RIU_RWNXFERXIQCOMP0_ADDR) & ~((uint32_t)0x000007FF)) | ((uint32_t)rxiqgain0 << 0));
}

#endif // RW_NX_IQ_COMP_EN
/// @}

#if RW_NX_IQ_COMP_EN
/**
 * @name RWNXFERXIQCOMP1 register definitions
 * <table>
 * <caption id="RWNXFERXIQCOMP1_BF">RWNXFERXIQCOMP1 bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>24:16 <td>        RXIQPHASE1 <td>R <td>R/W <td>0x0
 * <tr><td>10:00 <td>         RXIQGAIN1 <td>R <td>R/W <td>0x400
 * </table>
 *
 * @{
 */

/// Address of the RWNXFERXIQCOMP1 register
#define RIU_RWNXFERXIQCOMP1_ADDR   0x4033B120
/// Offset of the RWNXFERXIQCOMP1 register from the base address
#define RIU_RWNXFERXIQCOMP1_OFFSET 0x00000120
/// Index of the RWNXFERXIQCOMP1 register
#define RIU_RWNXFERXIQCOMP1_INDEX  0x00000048
/// Reset value of the RWNXFERXIQCOMP1 register
#define RIU_RWNXFERXIQCOMP1_RESET  0x00000400

/**
 * @brief Returns the current value of the RWNXFERXIQCOMP1 register.
 * The RWNXFERXIQCOMP1 register will be read and its value returned.
 * @return The current value of the RWNXFERXIQCOMP1 register.
 */
__INLINE uint32_t riu_rwnxferxiqcomp1_get(void)
{
    return REG_PL_RD(RIU_RWNXFERXIQCOMP1_ADDR);
}

/**
 * @brief Sets the RWNXFERXIQCOMP1 register to a value.
 * The RWNXFERXIQCOMP1 register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxferxiqcomp1_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXFERXIQCOMP1_ADDR, value);
}

// field definitions
/// RXIQPHASE1 field mask
#define RIU_RXIQPHASE1_MASK   ((uint32_t)0x01FF0000)
/// RXIQPHASE1 field LSB position
#define RIU_RXIQPHASE1_LSB    16
/// RXIQPHASE1 field width
#define RIU_RXIQPHASE1_WIDTH  ((uint32_t)0x00000009)
/// RXIQGAIN1 field mask
#define RIU_RXIQGAIN1_MASK    ((uint32_t)0x000007FF)
/// RXIQGAIN1 field LSB position
#define RIU_RXIQGAIN1_LSB     0
/// RXIQGAIN1 field width
#define RIU_RXIQGAIN1_WIDTH   ((uint32_t)0x0000000B)

/// RXIQPHASE1 field reset value
#define RIU_RXIQPHASE1_RST    0x0
/// RXIQGAIN1 field reset value
#define RIU_RXIQGAIN1_RST     0x400

/**
 * @brief Constructs a value for the RWNXFERXIQCOMP1 register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] rxiqphase1 - The value to use for the RXIQPHASE1 field.
 * @param[in] rxiqgain1 - The value to use for the RXIQGAIN1 field.
 */
__INLINE void riu_rwnxferxiqcomp1_pack(uint16_t rxiqphase1, uint16_t rxiqgain1)
{
    REG_PL_WR(RIU_RWNXFERXIQCOMP1_ADDR,  ((uint32_t)rxiqphase1 << 16) | ((uint32_t)rxiqgain1 << 0));
}

/**
 * @brief Unpacks RWNXFERXIQCOMP1's fields from current value of the RWNXFERXIQCOMP1 register.
 *
 * Reads the RWNXFERXIQCOMP1 register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] rxiqphase1 - Will be populated with the current value of this field from the register.
 * @param[out] rxiqgain1 - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxferxiqcomp1_unpack(uint16_t* rxiqphase1, uint16_t* rxiqgain1)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFERXIQCOMP1_ADDR);

    *rxiqphase1 = (localVal & ((uint32_t)0x01FF0000)) >> 16;
    *rxiqgain1 = (localVal & ((uint32_t)0x000007FF)) >> 0;
}

/**
 * @brief Returns the current value of the RXIQPHASE1 field in the RWNXFERXIQCOMP1 register.
 *
 * The RWNXFERXIQCOMP1 register will be read and the RXIQPHASE1 field's value will be returned.
 *
 * @return The current value of the RXIQPHASE1 field in the RWNXFERXIQCOMP1 register.
 */
__INLINE uint16_t riu_rxiqphase1_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFERXIQCOMP1_ADDR);
    return ((localVal & ((uint32_t)0x01FF0000)) >> 16);
}

/**
 * @brief Sets the RXIQPHASE1 field of the RWNXFERXIQCOMP1 register.
 *
 * The RWNXFERXIQCOMP1 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rxiqphase1 - The value to set the field to.
 */
__INLINE void riu_rxiqphase1_setf(uint16_t rxiqphase1)
{
    REG_PL_WR(RIU_RWNXFERXIQCOMP1_ADDR, (REG_PL_RD(RIU_RWNXFERXIQCOMP1_ADDR) & ~((uint32_t)0x01FF0000)) | ((uint32_t)rxiqphase1 << 16));
}

/**
 * @brief Returns the current value of the RXIQGAIN1 field in the RWNXFERXIQCOMP1 register.
 *
 * The RWNXFERXIQCOMP1 register will be read and the RXIQGAIN1 field's value will be returned.
 *
 * @return The current value of the RXIQGAIN1 field in the RWNXFERXIQCOMP1 register.
 */
__INLINE uint16_t riu_rxiqgain1_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFERXIQCOMP1_ADDR);
    return ((localVal & ((uint32_t)0x000007FF)) >> 0);
}

/**
 * @brief Sets the RXIQGAIN1 field of the RWNXFERXIQCOMP1 register.
 *
 * The RWNXFERXIQCOMP1 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rxiqgain1 - The value to set the field to.
 */
__INLINE void riu_rxiqgain1_setf(uint16_t rxiqgain1)
{
    REG_PL_WR(RIU_RWNXFERXIQCOMP1_ADDR, (REG_PL_RD(RIU_RWNXFERXIQCOMP1_ADDR) & ~((uint32_t)0x000007FF)) | ((uint32_t)rxiqgain1 << 0));
}

#endif // RW_NX_IQ_COMP_EN
/// @}

#if RW_NX_FIQ_COMP_EN
/**
 * @name RWNXFEFIQCTRL register definitions
 * <table>
 * <caption id="RWNXFEFIQCTRL_BF">RWNXFEFIQCTRL bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>12 <td>        FIQPATHSEL <td>R <td>R/W <td>0
 * <tr><td>08 <td>           FIQTXRX <td>R <td>R/W <td>0
 * <tr><td>02 <td>       FIQRXBYPASS <td>R <td>R/W <td>1
 * <tr><td>01 <td>       FIQTXBYPASS <td>R <td>R/W <td>1
 * <tr><td>00 <td>          FIQCALEN <td>R <td>R/W <td>0
 * </table>
 *
 * @{
 */

/// Address of the RWNXFEFIQCTRL register
#define RIU_RWNXFEFIQCTRL_ADDR   0x4033B124
/// Offset of the RWNXFEFIQCTRL register from the base address
#define RIU_RWNXFEFIQCTRL_OFFSET 0x00000124
/// Index of the RWNXFEFIQCTRL register
#define RIU_RWNXFEFIQCTRL_INDEX  0x00000049
/// Reset value of the RWNXFEFIQCTRL register
#define RIU_RWNXFEFIQCTRL_RESET  0x00000006

/**
 * @brief Returns the current value of the RWNXFEFIQCTRL register.
 * The RWNXFEFIQCTRL register will be read and its value returned.
 * @return The current value of the RWNXFEFIQCTRL register.
 */
__INLINE uint32_t riu_rwnxfefiqctrl_get(void)
{
    return REG_PL_RD(RIU_RWNXFEFIQCTRL_ADDR);
}

/**
 * @brief Sets the RWNXFEFIQCTRL register to a value.
 * The RWNXFEFIQCTRL register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxfefiqctrl_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXFEFIQCTRL_ADDR, value);
}

// field definitions
/// FIQPATHSEL field bit
#define RIU_FIQPATHSEL_BIT     ((uint32_t)0x00001000)
/// FIQPATHSEL field position
#define RIU_FIQPATHSEL_POS     12
/// FIQTXRX field bit
#define RIU_FIQTXRX_BIT        ((uint32_t)0x00000100)
/// FIQTXRX field position
#define RIU_FIQTXRX_POS        8
/// FIQRXBYPASS field bit
#define RIU_FIQRXBYPASS_BIT    ((uint32_t)0x00000004)
/// FIQRXBYPASS field position
#define RIU_FIQRXBYPASS_POS    2
/// FIQTXBYPASS field bit
#define RIU_FIQTXBYPASS_BIT    ((uint32_t)0x00000002)
/// FIQTXBYPASS field position
#define RIU_FIQTXBYPASS_POS    1
/// FIQCALEN field bit
#define RIU_FIQCALEN_BIT       ((uint32_t)0x00000001)
/// FIQCALEN field position
#define RIU_FIQCALEN_POS       0

/// FIQPATHSEL field reset value
#define RIU_FIQPATHSEL_RST     0x0
/// FIQTXRX field reset value
#define RIU_FIQTXRX_RST        0x0
/// FIQRXBYPASS field reset value
#define RIU_FIQRXBYPASS_RST    0x1
/// FIQTXBYPASS field reset value
#define RIU_FIQTXBYPASS_RST    0x1
/// FIQCALEN field reset value
#define RIU_FIQCALEN_RST       0x0

/**
 * @brief Constructs a value for the RWNXFEFIQCTRL register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] fiqpathsel - The value to use for the FIQPATHSEL field.
 * @param[in] fiqtxrx - The value to use for the FIQTXRX field.
 * @param[in] fiqrxbypass - The value to use for the FIQRXBYPASS field.
 * @param[in] fiqtxbypass - The value to use for the FIQTXBYPASS field.
 * @param[in] fiqcalen - The value to use for the FIQCALEN field.
 */
__INLINE void riu_rwnxfefiqctrl_pack(uint8_t fiqpathsel, uint8_t fiqtxrx, uint8_t fiqrxbypass, uint8_t fiqtxbypass, uint8_t fiqcalen)
{
    REG_PL_WR(RIU_RWNXFEFIQCTRL_ADDR,  ((uint32_t)fiqpathsel << 12) | ((uint32_t)fiqtxrx << 8) | ((uint32_t)fiqrxbypass << 2) | ((uint32_t)fiqtxbypass << 1) | ((uint32_t)fiqcalen << 0));
}

/**
 * @brief Unpacks RWNXFEFIQCTRL's fields from current value of the RWNXFEFIQCTRL register.
 *
 * Reads the RWNXFEFIQCTRL register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] fiqpathsel - Will be populated with the current value of this field from the register.
 * @param[out] fiqtxrx - Will be populated with the current value of this field from the register.
 * @param[out] fiqrxbypass - Will be populated with the current value of this field from the register.
 * @param[out] fiqtxbypass - Will be populated with the current value of this field from the register.
 * @param[out] fiqcalen - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxfefiqctrl_unpack(uint8_t* fiqpathsel, uint8_t* fiqtxrx, uint8_t* fiqrxbypass, uint8_t* fiqtxbypass, uint8_t* fiqcalen)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFEFIQCTRL_ADDR);

    *fiqpathsel = (localVal & ((uint32_t)0x00001000)) >> 12;
    *fiqtxrx = (localVal & ((uint32_t)0x00000100)) >> 8;
    *fiqrxbypass = (localVal & ((uint32_t)0x00000004)) >> 2;
    *fiqtxbypass = (localVal & ((uint32_t)0x00000002)) >> 1;
    *fiqcalen = (localVal & ((uint32_t)0x00000001)) >> 0;
}

/**
 * @brief Returns the current value of the FIQPATHSEL field in the RWNXFEFIQCTRL register.
 *
 * The RWNXFEFIQCTRL register will be read and the FIQPATHSEL field's value will be returned.
 *
 * @return The current value of the FIQPATHSEL field in the RWNXFEFIQCTRL register.
 */
__INLINE uint8_t riu_fiqpathsel_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFEFIQCTRL_ADDR);
    return ((localVal & ((uint32_t)0x00001000)) >> 12);
}

/**
 * @brief Sets the FIQPATHSEL field of the RWNXFEFIQCTRL register.
 *
 * The RWNXFEFIQCTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] fiqpathsel - The value to set the field to.
 */
__INLINE void riu_fiqpathsel_setf(uint8_t fiqpathsel)
{
    REG_PL_WR(RIU_RWNXFEFIQCTRL_ADDR, (REG_PL_RD(RIU_RWNXFEFIQCTRL_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)fiqpathsel << 12));
}

/**
 * @brief Returns the current value of the FIQTXRX field in the RWNXFEFIQCTRL register.
 *
 * The RWNXFEFIQCTRL register will be read and the FIQTXRX field's value will be returned.
 *
 * @return The current value of the FIQTXRX field in the RWNXFEFIQCTRL register.
 */
__INLINE uint8_t riu_fiqtxrx_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFEFIQCTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000100)) >> 8);
}

/**
 * @brief Sets the FIQTXRX field of the RWNXFEFIQCTRL register.
 *
 * The RWNXFEFIQCTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] fiqtxrx - The value to set the field to.
 */
__INLINE void riu_fiqtxrx_setf(uint8_t fiqtxrx)
{
    REG_PL_WR(RIU_RWNXFEFIQCTRL_ADDR, (REG_PL_RD(RIU_RWNXFEFIQCTRL_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)fiqtxrx << 8));
}

/**
 * @brief Returns the current value of the FIQRXBYPASS field in the RWNXFEFIQCTRL register.
 *
 * The RWNXFEFIQCTRL register will be read and the FIQRXBYPASS field's value will be returned.
 *
 * @return The current value of the FIQRXBYPASS field in the RWNXFEFIQCTRL register.
 */
__INLINE uint8_t riu_fiqrxbypass_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFEFIQCTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000004)) >> 2);
}

/**
 * @brief Sets the FIQRXBYPASS field of the RWNXFEFIQCTRL register.
 *
 * The RWNXFEFIQCTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] fiqrxbypass - The value to set the field to.
 */
__INLINE void riu_fiqrxbypass_setf(uint8_t fiqrxbypass)
{
    REG_PL_WR(RIU_RWNXFEFIQCTRL_ADDR, (REG_PL_RD(RIU_RWNXFEFIQCTRL_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)fiqrxbypass << 2));
}

/**
 * @brief Returns the current value of the FIQTXBYPASS field in the RWNXFEFIQCTRL register.
 *
 * The RWNXFEFIQCTRL register will be read and the FIQTXBYPASS field's value will be returned.
 *
 * @return The current value of the FIQTXBYPASS field in the RWNXFEFIQCTRL register.
 */
__INLINE uint8_t riu_fiqtxbypass_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFEFIQCTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000002)) >> 1);
}

/**
 * @brief Sets the FIQTXBYPASS field of the RWNXFEFIQCTRL register.
 *
 * The RWNXFEFIQCTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] fiqtxbypass - The value to set the field to.
 */
__INLINE void riu_fiqtxbypass_setf(uint8_t fiqtxbypass)
{
    REG_PL_WR(RIU_RWNXFEFIQCTRL_ADDR, (REG_PL_RD(RIU_RWNXFEFIQCTRL_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)fiqtxbypass << 1));
}

/**
 * @brief Returns the current value of the FIQCALEN field in the RWNXFEFIQCTRL register.
 *
 * The RWNXFEFIQCTRL register will be read and the FIQCALEN field's value will be returned.
 *
 * @return The current value of the FIQCALEN field in the RWNXFEFIQCTRL register.
 */
__INLINE uint8_t riu_fiqcalen_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFEFIQCTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief Sets the FIQCALEN field of the RWNXFEFIQCTRL register.
 *
 * The RWNXFEFIQCTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] fiqcalen - The value to set the field to.
 */
__INLINE void riu_fiqcalen_setf(uint8_t fiqcalen)
{
    REG_PL_WR(RIU_RWNXFEFIQCTRL_ADDR, (REG_PL_RD(RIU_RWNXFEFIQCTRL_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)fiqcalen << 0));
}

#endif // RW_NX_FIQ_COMP_EN
/// @}

#if RW_NX_FIQ_COMP_EN
/**
 * @name RWNXFEFIQCOLL register definitions
 * <table>
 * <caption id="RWNXFEFIQCOLL_BF">RWNXFEFIQCOLL bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>31:24 <td>   FIQCOLLWROFFSET <td>R <td>R/W <td>0x80
 * <tr><td>23:16 <td>   FIQCOLLRDOFFSET <td>R <td>R/W <td>0x0
 * <tr><td>15:08 <td>       FIQCOLLSIZE <td>R <td>R/W <td>0x80
 * <tr><td>00 <td>       FIQCOLLPATH <td>R <td>R/W <td>0
 * </table>
 *
 * @{
 */

/// Address of the RWNXFEFIQCOLL register
#define RIU_RWNXFEFIQCOLL_ADDR   0x4033B128
/// Offset of the RWNXFEFIQCOLL register from the base address
#define RIU_RWNXFEFIQCOLL_OFFSET 0x00000128
/// Index of the RWNXFEFIQCOLL register
#define RIU_RWNXFEFIQCOLL_INDEX  0x0000004A
/// Reset value of the RWNXFEFIQCOLL register
#define RIU_RWNXFEFIQCOLL_RESET  0x80008000

/**
 * @brief Returns the current value of the RWNXFEFIQCOLL register.
 * The RWNXFEFIQCOLL register will be read and its value returned.
 * @return The current value of the RWNXFEFIQCOLL register.
 */
__INLINE uint32_t riu_rwnxfefiqcoll_get(void)
{
    return REG_PL_RD(RIU_RWNXFEFIQCOLL_ADDR);
}

/**
 * @brief Sets the RWNXFEFIQCOLL register to a value.
 * The RWNXFEFIQCOLL register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxfefiqcoll_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXFEFIQCOLL_ADDR, value);
}

// field definitions
/// FIQCOLLWROFFSET field mask
#define RIU_FIQCOLLWROFFSET_MASK   ((uint32_t)0xFF000000)
/// FIQCOLLWROFFSET field LSB position
#define RIU_FIQCOLLWROFFSET_LSB    24
/// FIQCOLLWROFFSET field width
#define RIU_FIQCOLLWROFFSET_WIDTH  ((uint32_t)0x00000008)
/// FIQCOLLRDOFFSET field mask
#define RIU_FIQCOLLRDOFFSET_MASK   ((uint32_t)0x00FF0000)
/// FIQCOLLRDOFFSET field LSB position
#define RIU_FIQCOLLRDOFFSET_LSB    16
/// FIQCOLLRDOFFSET field width
#define RIU_FIQCOLLRDOFFSET_WIDTH  ((uint32_t)0x00000008)
/// FIQCOLLSIZE field mask
#define RIU_FIQCOLLSIZE_MASK       ((uint32_t)0x0000FF00)
/// FIQCOLLSIZE field LSB position
#define RIU_FIQCOLLSIZE_LSB        8
/// FIQCOLLSIZE field width
#define RIU_FIQCOLLSIZE_WIDTH      ((uint32_t)0x00000008)
/// FIQCOLLPATH field bit
#define RIU_FIQCOLLPATH_BIT        ((uint32_t)0x00000001)
/// FIQCOLLPATH field position
#define RIU_FIQCOLLPATH_POS        0

/// FIQCOLLWROFFSET field reset value
#define RIU_FIQCOLLWROFFSET_RST    0x80
/// FIQCOLLRDOFFSET field reset value
#define RIU_FIQCOLLRDOFFSET_RST    0x0
/// FIQCOLLSIZE field reset value
#define RIU_FIQCOLLSIZE_RST        0x80
/// FIQCOLLPATH field reset value
#define RIU_FIQCOLLPATH_RST        0x0

/**
 * @brief Constructs a value for the RWNXFEFIQCOLL register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] fiqcollwroffset - The value to use for the FIQCOLLWROFFSET field.
 * @param[in] fiqcollrdoffset - The value to use for the FIQCOLLRDOFFSET field.
 * @param[in] fiqcollsize - The value to use for the FIQCOLLSIZE field.
 * @param[in] fiqcollpath - The value to use for the FIQCOLLPATH field.
 */
__INLINE void riu_rwnxfefiqcoll_pack(uint8_t fiqcollwroffset, uint8_t fiqcollrdoffset, uint8_t fiqcollsize, uint8_t fiqcollpath)
{
    REG_PL_WR(RIU_RWNXFEFIQCOLL_ADDR,  ((uint32_t)fiqcollwroffset << 24) | ((uint32_t)fiqcollrdoffset << 16) | ((uint32_t)fiqcollsize << 8) | ((uint32_t)fiqcollpath << 0));
}

/**
 * @brief Unpacks RWNXFEFIQCOLL's fields from current value of the RWNXFEFIQCOLL register.
 *
 * Reads the RWNXFEFIQCOLL register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] fiqcollwroffset - Will be populated with the current value of this field from the register.
 * @param[out] fiqcollrdoffset - Will be populated with the current value of this field from the register.
 * @param[out] fiqcollsize - Will be populated with the current value of this field from the register.
 * @param[out] fiqcollpath - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxfefiqcoll_unpack(uint8_t* fiqcollwroffset, uint8_t* fiqcollrdoffset, uint8_t* fiqcollsize, uint8_t* fiqcollpath)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFEFIQCOLL_ADDR);

    *fiqcollwroffset = (localVal & ((uint32_t)0xFF000000)) >> 24;
    *fiqcollrdoffset = (localVal & ((uint32_t)0x00FF0000)) >> 16;
    *fiqcollsize = (localVal & ((uint32_t)0x0000FF00)) >> 8;
    *fiqcollpath = (localVal & ((uint32_t)0x00000001)) >> 0;
}

/**
 * @brief Returns the current value of the FIQCOLLWROFFSET field in the RWNXFEFIQCOLL register.
 *
 * The RWNXFEFIQCOLL register will be read and the FIQCOLLWROFFSET field's value will be returned.
 *
 * @return The current value of the FIQCOLLWROFFSET field in the RWNXFEFIQCOLL register.
 */
__INLINE uint8_t riu_fiqcollwroffset_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFEFIQCOLL_ADDR);
    return ((localVal & ((uint32_t)0xFF000000)) >> 24);
}

/**
 * @brief Sets the FIQCOLLWROFFSET field of the RWNXFEFIQCOLL register.
 *
 * The RWNXFEFIQCOLL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] fiqcollwroffset - The value to set the field to.
 */
__INLINE void riu_fiqcollwroffset_setf(uint8_t fiqcollwroffset)
{
    REG_PL_WR(RIU_RWNXFEFIQCOLL_ADDR, (REG_PL_RD(RIU_RWNXFEFIQCOLL_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)fiqcollwroffset << 24));
}

/**
 * @brief Returns the current value of the FIQCOLLRDOFFSET field in the RWNXFEFIQCOLL register.
 *
 * The RWNXFEFIQCOLL register will be read and the FIQCOLLRDOFFSET field's value will be returned.
 *
 * @return The current value of the FIQCOLLRDOFFSET field in the RWNXFEFIQCOLL register.
 */
__INLINE uint8_t riu_fiqcollrdoffset_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFEFIQCOLL_ADDR);
    return ((localVal & ((uint32_t)0x00FF0000)) >> 16);
}

/**
 * @brief Sets the FIQCOLLRDOFFSET field of the RWNXFEFIQCOLL register.
 *
 * The RWNXFEFIQCOLL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] fiqcollrdoffset - The value to set the field to.
 */
__INLINE void riu_fiqcollrdoffset_setf(uint8_t fiqcollrdoffset)
{
    REG_PL_WR(RIU_RWNXFEFIQCOLL_ADDR, (REG_PL_RD(RIU_RWNXFEFIQCOLL_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)fiqcollrdoffset << 16));
}

/**
 * @brief Returns the current value of the FIQCOLLSIZE field in the RWNXFEFIQCOLL register.
 *
 * The RWNXFEFIQCOLL register will be read and the FIQCOLLSIZE field's value will be returned.
 *
 * @return The current value of the FIQCOLLSIZE field in the RWNXFEFIQCOLL register.
 */
__INLINE uint8_t riu_fiqcollsize_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFEFIQCOLL_ADDR);
    return ((localVal & ((uint32_t)0x0000FF00)) >> 8);
}

/**
 * @brief Sets the FIQCOLLSIZE field of the RWNXFEFIQCOLL register.
 *
 * The RWNXFEFIQCOLL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] fiqcollsize - The value to set the field to.
 */
__INLINE void riu_fiqcollsize_setf(uint8_t fiqcollsize)
{
    REG_PL_WR(RIU_RWNXFEFIQCOLL_ADDR, (REG_PL_RD(RIU_RWNXFEFIQCOLL_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)fiqcollsize << 8));
}

/**
 * @brief Returns the current value of the FIQCOLLPATH field in the RWNXFEFIQCOLL register.
 *
 * The RWNXFEFIQCOLL register will be read and the FIQCOLLPATH field's value will be returned.
 *
 * @return The current value of the FIQCOLLPATH field in the RWNXFEFIQCOLL register.
 */
__INLINE uint8_t riu_fiqcollpath_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFEFIQCOLL_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief Sets the FIQCOLLPATH field of the RWNXFEFIQCOLL register.
 *
 * The RWNXFEFIQCOLL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] fiqcollpath - The value to set the field to.
 */
__INLINE void riu_fiqcollpath_setf(uint8_t fiqcollpath)
{
    REG_PL_WR(RIU_RWNXFEFIQCOLL_ADDR, (REG_PL_RD(RIU_RWNXFEFIQCOLL_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)fiqcollpath << 0));
}

#endif // RW_NX_FIQ_COMP_EN
/// @}

#if RW_NX_FIQ_COMP_EN
/**
 * @name RWNXFEFIQEST0 register definitions
 * <table>
 * <caption id="RWNXFEFIQEST0_BF">RWNXFEFIQEST0 bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>31:24 <td>     FIQESTQOFFSET <td>R <td>R/W <td>0x80
 * <tr><td>23:16 <td>     FIQESTIOFFSET <td>R <td>R/W <td>0x0
 * <tr><td>07:00 <td>        FIQESTSIZE <td>R <td>R/W <td>0x80
 * </table>
 *
 * @{
 */

/// Address of the RWNXFEFIQEST0 register
#define RIU_RWNXFEFIQEST0_ADDR   0x4033B12C
/// Offset of the RWNXFEFIQEST0 register from the base address
#define RIU_RWNXFEFIQEST0_OFFSET 0x0000012C
/// Index of the RWNXFEFIQEST0 register
#define RIU_RWNXFEFIQEST0_INDEX  0x0000004B
/// Reset value of the RWNXFEFIQEST0 register
#define RIU_RWNXFEFIQEST0_RESET  0x80000080

/**
 * @brief Returns the current value of the RWNXFEFIQEST0 register.
 * The RWNXFEFIQEST0 register will be read and its value returned.
 * @return The current value of the RWNXFEFIQEST0 register.
 */
__INLINE uint32_t riu_rwnxfefiqest0_get(void)
{
    return REG_PL_RD(RIU_RWNXFEFIQEST0_ADDR);
}

/**
 * @brief Sets the RWNXFEFIQEST0 register to a value.
 * The RWNXFEFIQEST0 register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxfefiqest0_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXFEFIQEST0_ADDR, value);
}

// field definitions
/// FIQESTQOFFSET field mask
#define RIU_FIQESTQOFFSET_MASK   ((uint32_t)0xFF000000)
/// FIQESTQOFFSET field LSB position
#define RIU_FIQESTQOFFSET_LSB    24
/// FIQESTQOFFSET field width
#define RIU_FIQESTQOFFSET_WIDTH  ((uint32_t)0x00000008)
/// FIQESTIOFFSET field mask
#define RIU_FIQESTIOFFSET_MASK   ((uint32_t)0x00FF0000)
/// FIQESTIOFFSET field LSB position
#define RIU_FIQESTIOFFSET_LSB    16
/// FIQESTIOFFSET field width
#define RIU_FIQESTIOFFSET_WIDTH  ((uint32_t)0x00000008)
/// FIQESTSIZE field mask
#define RIU_FIQESTSIZE_MASK      ((uint32_t)0x000000FF)
/// FIQESTSIZE field LSB position
#define RIU_FIQESTSIZE_LSB       0
/// FIQESTSIZE field width
#define RIU_FIQESTSIZE_WIDTH     ((uint32_t)0x00000008)

/// FIQESTQOFFSET field reset value
#define RIU_FIQESTQOFFSET_RST    0x80
/// FIQESTIOFFSET field reset value
#define RIU_FIQESTIOFFSET_RST    0x0
/// FIQESTSIZE field reset value
#define RIU_FIQESTSIZE_RST       0x80

/**
 * @brief Constructs a value for the RWNXFEFIQEST0 register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] fiqestqoffset - The value to use for the FIQESTQOFFSET field.
 * @param[in] fiqestioffset - The value to use for the FIQESTIOFFSET field.
 * @param[in] fiqestsize - The value to use for the FIQESTSIZE field.
 */
__INLINE void riu_rwnxfefiqest0_pack(uint8_t fiqestqoffset, uint8_t fiqestioffset, uint8_t fiqestsize)
{
    REG_PL_WR(RIU_RWNXFEFIQEST0_ADDR,  ((uint32_t)fiqestqoffset << 24) | ((uint32_t)fiqestioffset << 16) | ((uint32_t)fiqestsize << 0));
}

/**
 * @brief Unpacks RWNXFEFIQEST0's fields from current value of the RWNXFEFIQEST0 register.
 *
 * Reads the RWNXFEFIQEST0 register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] fiqestqoffset - Will be populated with the current value of this field from the register.
 * @param[out] fiqestioffset - Will be populated with the current value of this field from the register.
 * @param[out] fiqestsize - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxfefiqest0_unpack(uint8_t* fiqestqoffset, uint8_t* fiqestioffset, uint8_t* fiqestsize)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFEFIQEST0_ADDR);

    *fiqestqoffset = (localVal & ((uint32_t)0xFF000000)) >> 24;
    *fiqestioffset = (localVal & ((uint32_t)0x00FF0000)) >> 16;
    *fiqestsize = (localVal & ((uint32_t)0x000000FF)) >> 0;
}

/**
 * @brief Returns the current value of the FIQESTQOFFSET field in the RWNXFEFIQEST0 register.
 *
 * The RWNXFEFIQEST0 register will be read and the FIQESTQOFFSET field's value will be returned.
 *
 * @return The current value of the FIQESTQOFFSET field in the RWNXFEFIQEST0 register.
 */
__INLINE uint8_t riu_fiqestqoffset_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFEFIQEST0_ADDR);
    return ((localVal & ((uint32_t)0xFF000000)) >> 24);
}

/**
 * @brief Sets the FIQESTQOFFSET field of the RWNXFEFIQEST0 register.
 *
 * The RWNXFEFIQEST0 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] fiqestqoffset - The value to set the field to.
 */
__INLINE void riu_fiqestqoffset_setf(uint8_t fiqestqoffset)
{
    REG_PL_WR(RIU_RWNXFEFIQEST0_ADDR, (REG_PL_RD(RIU_RWNXFEFIQEST0_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)fiqestqoffset << 24));
}

/**
 * @brief Returns the current value of the FIQESTIOFFSET field in the RWNXFEFIQEST0 register.
 *
 * The RWNXFEFIQEST0 register will be read and the FIQESTIOFFSET field's value will be returned.
 *
 * @return The current value of the FIQESTIOFFSET field in the RWNXFEFIQEST0 register.
 */
__INLINE uint8_t riu_fiqestioffset_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFEFIQEST0_ADDR);
    return ((localVal & ((uint32_t)0x00FF0000)) >> 16);
}

/**
 * @brief Sets the FIQESTIOFFSET field of the RWNXFEFIQEST0 register.
 *
 * The RWNXFEFIQEST0 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] fiqestioffset - The value to set the field to.
 */
__INLINE void riu_fiqestioffset_setf(uint8_t fiqestioffset)
{
    REG_PL_WR(RIU_RWNXFEFIQEST0_ADDR, (REG_PL_RD(RIU_RWNXFEFIQEST0_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)fiqestioffset << 16));
}

/**
 * @brief Returns the current value of the FIQESTSIZE field in the RWNXFEFIQEST0 register.
 *
 * The RWNXFEFIQEST0 register will be read and the FIQESTSIZE field's value will be returned.
 *
 * @return The current value of the FIQESTSIZE field in the RWNXFEFIQEST0 register.
 */
__INLINE uint8_t riu_fiqestsize_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFEFIQEST0_ADDR);
    return ((localVal & ((uint32_t)0x000000FF)) >> 0);
}

/**
 * @brief Sets the FIQESTSIZE field of the RWNXFEFIQEST0 register.
 *
 * The RWNXFEFIQEST0 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] fiqestsize - The value to set the field to.
 */
__INLINE void riu_fiqestsize_setf(uint8_t fiqestsize)
{
    REG_PL_WR(RIU_RWNXFEFIQEST0_ADDR, (REG_PL_RD(RIU_RWNXFEFIQEST0_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)fiqestsize << 0));
}

#endif // RW_NX_FIQ_COMP_EN
/// @}

#if RW_NX_FIQ_COMP_EN
/**
 * @name RWNXFEFIQEST1 register definitions
 * <table>
 * <caption id="RWNXFEFIQEST1_BF">RWNXFEFIQEST1 bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>19:16 <td>        FIQESTSTEP <td>R <td>R/W <td>0x6
 * <tr><td>15:00 <td>        FIQESTNITE <td>R <td>R/W <td>0x2710
 * </table>
 *
 * @{
 */

/// Address of the RWNXFEFIQEST1 register
#define RIU_RWNXFEFIQEST1_ADDR   0x4033B130
/// Offset of the RWNXFEFIQEST1 register from the base address
#define RIU_RWNXFEFIQEST1_OFFSET 0x00000130
/// Index of the RWNXFEFIQEST1 register
#define RIU_RWNXFEFIQEST1_INDEX  0x0000004C
/// Reset value of the RWNXFEFIQEST1 register
#define RIU_RWNXFEFIQEST1_RESET  0x00062710

/**
 * @brief Returns the current value of the RWNXFEFIQEST1 register.
 * The RWNXFEFIQEST1 register will be read and its value returned.
 * @return The current value of the RWNXFEFIQEST1 register.
 */
__INLINE uint32_t riu_rwnxfefiqest1_get(void)
{
    return REG_PL_RD(RIU_RWNXFEFIQEST1_ADDR);
}

/**
 * @brief Sets the RWNXFEFIQEST1 register to a value.
 * The RWNXFEFIQEST1 register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxfefiqest1_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXFEFIQEST1_ADDR, value);
}

// field definitions
/// FIQESTSTEP field mask
#define RIU_FIQESTSTEP_MASK   ((uint32_t)0x000F0000)
/// FIQESTSTEP field LSB position
#define RIU_FIQESTSTEP_LSB    16
/// FIQESTSTEP field width
#define RIU_FIQESTSTEP_WIDTH  ((uint32_t)0x00000004)
/// FIQESTNITE field mask
#define RIU_FIQESTNITE_MASK   ((uint32_t)0x0000FFFF)
/// FIQESTNITE field LSB position
#define RIU_FIQESTNITE_LSB    0
/// FIQESTNITE field width
#define RIU_FIQESTNITE_WIDTH  ((uint32_t)0x00000010)

/// FIQESTSTEP field reset value
#define RIU_FIQESTSTEP_RST    0x6
/// FIQESTNITE field reset value
#define RIU_FIQESTNITE_RST    0x2710

/**
 * @brief Constructs a value for the RWNXFEFIQEST1 register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] fiqeststep - The value to use for the FIQESTSTEP field.
 * @param[in] fiqestnite - The value to use for the FIQESTNITE field.
 */
__INLINE void riu_rwnxfefiqest1_pack(uint8_t fiqeststep, uint16_t fiqestnite)
{
    REG_PL_WR(RIU_RWNXFEFIQEST1_ADDR,  ((uint32_t)fiqeststep << 16) | ((uint32_t)fiqestnite << 0));
}

/**
 * @brief Unpacks RWNXFEFIQEST1's fields from current value of the RWNXFEFIQEST1 register.
 *
 * Reads the RWNXFEFIQEST1 register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] fiqeststep - Will be populated with the current value of this field from the register.
 * @param[out] fiqestnite - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxfefiqest1_unpack(uint8_t* fiqeststep, uint16_t* fiqestnite)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFEFIQEST1_ADDR);

    *fiqeststep = (localVal & ((uint32_t)0x000F0000)) >> 16;
    *fiqestnite = (localVal & ((uint32_t)0x0000FFFF)) >> 0;
}

/**
 * @brief Returns the current value of the FIQESTSTEP field in the RWNXFEFIQEST1 register.
 *
 * The RWNXFEFIQEST1 register will be read and the FIQESTSTEP field's value will be returned.
 *
 * @return The current value of the FIQESTSTEP field in the RWNXFEFIQEST1 register.
 */
__INLINE uint8_t riu_fiqeststep_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFEFIQEST1_ADDR);
    return ((localVal & ((uint32_t)0x000F0000)) >> 16);
}

/**
 * @brief Sets the FIQESTSTEP field of the RWNXFEFIQEST1 register.
 *
 * The RWNXFEFIQEST1 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] fiqeststep - The value to set the field to.
 */
__INLINE void riu_fiqeststep_setf(uint8_t fiqeststep)
{
    REG_PL_WR(RIU_RWNXFEFIQEST1_ADDR, (REG_PL_RD(RIU_RWNXFEFIQEST1_ADDR) & ~((uint32_t)0x000F0000)) | ((uint32_t)fiqeststep << 16));
}

/**
 * @brief Returns the current value of the FIQESTNITE field in the RWNXFEFIQEST1 register.
 *
 * The RWNXFEFIQEST1 register will be read and the FIQESTNITE field's value will be returned.
 *
 * @return The current value of the FIQESTNITE field in the RWNXFEFIQEST1 register.
 */
__INLINE uint16_t riu_fiqestnite_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFEFIQEST1_ADDR);
    return ((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}

/**
 * @brief Sets the FIQESTNITE field of the RWNXFEFIQEST1 register.
 *
 * The RWNXFEFIQEST1 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] fiqestnite - The value to set the field to.
 */
__INLINE void riu_fiqestnite_setf(uint16_t fiqestnite)
{
    REG_PL_WR(RIU_RWNXFEFIQEST1_ADDR, (REG_PL_RD(RIU_RWNXFEFIQEST1_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)fiqestnite << 0));
}

#endif // RW_NX_FIQ_COMP_EN
/// @}

#if RW_NX_FIQ_COMP_EN
/**
 * @name RWNXFEFIQDEL register definitions
 * <table>
 * <caption id="RWNXFEFIQDEL_BF">RWNXFEFIQDEL bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>28:24 <td>          FIQRXDEL <td>R <td>R/W <td>0x9
 * <tr><td>20:16 <td>          FIQTXDEL <td>R <td>R/W <td>0x9
 * <tr><td>07:00 <td>        FIQCOLLDEL <td>R <td>R/W <td>0x0
 * </table>
 *
 * @{
 */

/// Address of the RWNXFEFIQDEL register
#define RIU_RWNXFEFIQDEL_ADDR   0x4033B134
/// Offset of the RWNXFEFIQDEL register from the base address
#define RIU_RWNXFEFIQDEL_OFFSET 0x00000134
/// Index of the RWNXFEFIQDEL register
#define RIU_RWNXFEFIQDEL_INDEX  0x0000004D
/// Reset value of the RWNXFEFIQDEL register
#define RIU_RWNXFEFIQDEL_RESET  0x09090000

/**
 * @brief Returns the current value of the RWNXFEFIQDEL register.
 * The RWNXFEFIQDEL register will be read and its value returned.
 * @return The current value of the RWNXFEFIQDEL register.
 */
__INLINE uint32_t riu_rwnxfefiqdel_get(void)
{
    return REG_PL_RD(RIU_RWNXFEFIQDEL_ADDR);
}

/**
 * @brief Sets the RWNXFEFIQDEL register to a value.
 * The RWNXFEFIQDEL register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxfefiqdel_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXFEFIQDEL_ADDR, value);
}

// field definitions
/// FIQRXDEL field mask
#define RIU_FIQRXDEL_MASK     ((uint32_t)0x1F000000)
/// FIQRXDEL field LSB position
#define RIU_FIQRXDEL_LSB      24
/// FIQRXDEL field width
#define RIU_FIQRXDEL_WIDTH    ((uint32_t)0x00000005)
/// FIQTXDEL field mask
#define RIU_FIQTXDEL_MASK     ((uint32_t)0x001F0000)
/// FIQTXDEL field LSB position
#define RIU_FIQTXDEL_LSB      16
/// FIQTXDEL field width
#define RIU_FIQTXDEL_WIDTH    ((uint32_t)0x00000005)
/// FIQCOLLDEL field mask
#define RIU_FIQCOLLDEL_MASK   ((uint32_t)0x000000FF)
/// FIQCOLLDEL field LSB position
#define RIU_FIQCOLLDEL_LSB    0
/// FIQCOLLDEL field width
#define RIU_FIQCOLLDEL_WIDTH  ((uint32_t)0x00000008)

/// FIQRXDEL field reset value
#define RIU_FIQRXDEL_RST      0x9
/// FIQTXDEL field reset value
#define RIU_FIQTXDEL_RST      0x9
/// FIQCOLLDEL field reset value
#define RIU_FIQCOLLDEL_RST    0x0

/**
 * @brief Constructs a value for the RWNXFEFIQDEL register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] fiqrxdel - The value to use for the FIQRXDEL field.
 * @param[in] fiqtxdel - The value to use for the FIQTXDEL field.
 * @param[in] fiqcolldel - The value to use for the FIQCOLLDEL field.
 */
__INLINE void riu_rwnxfefiqdel_pack(uint8_t fiqrxdel, uint8_t fiqtxdel, uint8_t fiqcolldel)
{
    REG_PL_WR(RIU_RWNXFEFIQDEL_ADDR,  ((uint32_t)fiqrxdel << 24) | ((uint32_t)fiqtxdel << 16) | ((uint32_t)fiqcolldel << 0));
}

/**
 * @brief Unpacks RWNXFEFIQDEL's fields from current value of the RWNXFEFIQDEL register.
 *
 * Reads the RWNXFEFIQDEL register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] fiqrxdel - Will be populated with the current value of this field from the register.
 * @param[out] fiqtxdel - Will be populated with the current value of this field from the register.
 * @param[out] fiqcolldel - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxfefiqdel_unpack(uint8_t* fiqrxdel, uint8_t* fiqtxdel, uint8_t* fiqcolldel)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFEFIQDEL_ADDR);

    *fiqrxdel = (localVal & ((uint32_t)0x1F000000)) >> 24;
    *fiqtxdel = (localVal & ((uint32_t)0x001F0000)) >> 16;
    *fiqcolldel = (localVal & ((uint32_t)0x000000FF)) >> 0;
}

/**
 * @brief Returns the current value of the FIQRXDEL field in the RWNXFEFIQDEL register.
 *
 * The RWNXFEFIQDEL register will be read and the FIQRXDEL field's value will be returned.
 *
 * @return The current value of the FIQRXDEL field in the RWNXFEFIQDEL register.
 */
__INLINE uint8_t riu_fiqrxdel_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFEFIQDEL_ADDR);
    return ((localVal & ((uint32_t)0x1F000000)) >> 24);
}

/**
 * @brief Sets the FIQRXDEL field of the RWNXFEFIQDEL register.
 *
 * The RWNXFEFIQDEL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] fiqrxdel - The value to set the field to.
 */
__INLINE void riu_fiqrxdel_setf(uint8_t fiqrxdel)
{
    REG_PL_WR(RIU_RWNXFEFIQDEL_ADDR, (REG_PL_RD(RIU_RWNXFEFIQDEL_ADDR) & ~((uint32_t)0x1F000000)) | ((uint32_t)fiqrxdel << 24));
}

/**
 * @brief Returns the current value of the FIQTXDEL field in the RWNXFEFIQDEL register.
 *
 * The RWNXFEFIQDEL register will be read and the FIQTXDEL field's value will be returned.
 *
 * @return The current value of the FIQTXDEL field in the RWNXFEFIQDEL register.
 */
__INLINE uint8_t riu_fiqtxdel_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFEFIQDEL_ADDR);
    return ((localVal & ((uint32_t)0x001F0000)) >> 16);
}

/**
 * @brief Sets the FIQTXDEL field of the RWNXFEFIQDEL register.
 *
 * The RWNXFEFIQDEL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] fiqtxdel - The value to set the field to.
 */
__INLINE void riu_fiqtxdel_setf(uint8_t fiqtxdel)
{
    REG_PL_WR(RIU_RWNXFEFIQDEL_ADDR, (REG_PL_RD(RIU_RWNXFEFIQDEL_ADDR) & ~((uint32_t)0x001F0000)) | ((uint32_t)fiqtxdel << 16));
}

/**
 * @brief Returns the current value of the FIQCOLLDEL field in the RWNXFEFIQDEL register.
 *
 * The RWNXFEFIQDEL register will be read and the FIQCOLLDEL field's value will be returned.
 *
 * @return The current value of the FIQCOLLDEL field in the RWNXFEFIQDEL register.
 */
__INLINE uint8_t riu_fiqcolldel_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFEFIQDEL_ADDR);
    return ((localVal & ((uint32_t)0x000000FF)) >> 0);
}

/**
 * @brief Sets the FIQCOLLDEL field of the RWNXFEFIQDEL register.
 *
 * The RWNXFEFIQDEL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] fiqcolldel - The value to set the field to.
 */
__INLINE void riu_fiqcolldel_setf(uint8_t fiqcolldel)
{
    REG_PL_WR(RIU_RWNXFEFIQDEL_ADDR, (REG_PL_RD(RIU_RWNXFEFIQDEL_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)fiqcolldel << 0));
}

#endif // RW_NX_FIQ_COMP_EN
/// @}

#if RW_NX_FIQ_COMP_EN
/**
 * @name RWNXFEFIQCOEFF register definitions
 * <table>
 * <caption id="RWNXFEFIQCOEFF_BF">RWNXFEFIQCOEFF bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>15:00 <td>          FIQCOEFF <td>R <td>R/W <td>0x0
 * </table>
 *
 * @{
 */

/// Address of the RWNXFEFIQCOEFF register
#define RIU_RWNXFEFIQCOEFF_ADDR   0x4033B138
/// Offset of the RWNXFEFIQCOEFF register from the base address
#define RIU_RWNXFEFIQCOEFF_OFFSET 0x00000138
/// Index of the RWNXFEFIQCOEFF register
#define RIU_RWNXFEFIQCOEFF_INDEX  0x0000004E
/// Reset value of the RWNXFEFIQCOEFF register
#define RIU_RWNXFEFIQCOEFF_RESET  0x00000000
/// Number of elements of the RWNXFEFIQCOEFF register array
#define RIU_RWNXFEFIQCOEFF_COUNT  20

/**
 * @brief Returns the current value of the RWNXFEFIQCOEFF register.
 * The RWNXFEFIQCOEFF register will be read and its value returned.
 * @param[in] reg_idx Index of the register
 * @return The current value of the RWNXFEFIQCOEFF register.
 */
__INLINE uint32_t riu_rwnxfefiqcoeff_get(int reg_idx)
{
    return REG_PL_RD(RIU_RWNXFEFIQCOEFF_ADDR + reg_idx * 4);
}

/**
 * @brief Sets the RWNXFEFIQCOEFF register to a value.
 * The RWNXFEFIQCOEFF register will be written.
 * @param[in] reg_idx Index of the register
 * @param value - The value to write.
 */
__INLINE void riu_rwnxfefiqcoeff_set(int reg_idx, uint32_t value)
{
    REG_PL_WR(RIU_RWNXFEFIQCOEFF_ADDR + reg_idx * 4, value);
}

// field definitions
/// FIQCOEFF field mask
#define RIU_FIQCOEFF_MASK   ((uint32_t)0x0000FFFF)
/// FIQCOEFF field LSB position
#define RIU_FIQCOEFF_LSB    0
/// FIQCOEFF field width
#define RIU_FIQCOEFF_WIDTH  ((uint32_t)0x00000010)

/// FIQCOEFF field reset value
#define RIU_FIQCOEFF_RST    0x0

/**
 * @brief Returns the current value of the FIQCOEFF field in the RWNXFEFIQCOEFF register.
 *
 * The RWNXFEFIQCOEFF register will be read and the FIQCOEFF field's value will be returned.
 *
 * @param[in] reg_idx Index of the register
 * @return The current value of the FIQCOEFF field in the RWNXFEFIQCOEFF register.
 */
__INLINE uint16_t riu_fiqcoeff_getf(int reg_idx)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFEFIQCOEFF_ADDR + reg_idx * 4);
    return (localVal >> 0);
}

/**
 * @brief Sets the FIQCOEFF field of the RWNXFEFIQCOEFF register.
 *
 * The RWNXFEFIQCOEFF register will be read, modified to contain the new field value, and written.
 *
 * @param[in] reg_idx Index of the register
 * @param[in] fiqcoeff - The value to set the field to.
 */
__INLINE void riu_fiqcoeff_setf(int reg_idx, uint16_t fiqcoeff)
{
    REG_PL_WR(RIU_RWNXFEFIQCOEFF_ADDR + reg_idx * 4, (uint32_t)fiqcoeff << 0);
}

#endif // RW_NX_FIQ_COMP_EN
/// @}

#if RW_NX_FIQ_COMP_EN
/**
 * @name RWNXFEFIQCOEFFUPDATE register definitions
 * <table>
 * <caption id="RWNXFEFIQCOEFFUPDATE_BF">RWNXFEFIQCOEFFUPDATE bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>00 <td>    FIQCOEFFUPDATE <td>R/W <td>R/W <td>0
 * </table>
 *
 * @{
 */

/// Address of the RWNXFEFIQCOEFFUPDATE register
#define RIU_RWNXFEFIQCOEFFUPDATE_ADDR   0x4033B188
/// Offset of the RWNXFEFIQCOEFFUPDATE register from the base address
#define RIU_RWNXFEFIQCOEFFUPDATE_OFFSET 0x00000188
/// Index of the RWNXFEFIQCOEFFUPDATE register
#define RIU_RWNXFEFIQCOEFFUPDATE_INDEX  0x00000062
/// Reset value of the RWNXFEFIQCOEFFUPDATE register
#define RIU_RWNXFEFIQCOEFFUPDATE_RESET  0x00000000

/**
 * @brief Returns the current value of the RWNXFEFIQCOEFFUPDATE register.
 * The RWNXFEFIQCOEFFUPDATE register will be read and its value returned.
 * @return The current value of the RWNXFEFIQCOEFFUPDATE register.
 */
__INLINE uint32_t riu_rwnxfefiqcoeffupdate_get(void)
{
    return REG_PL_RD(RIU_RWNXFEFIQCOEFFUPDATE_ADDR);
}

/**
 * @brief Sets the RWNXFEFIQCOEFFUPDATE register to a value.
 * The RWNXFEFIQCOEFFUPDATE register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxfefiqcoeffupdate_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXFEFIQCOEFFUPDATE_ADDR, value);
}

// field definitions
/// FIQCOEFFUPDATE field bit
#define RIU_FIQCOEFFUPDATE_BIT    ((uint32_t)0x00000001)
/// FIQCOEFFUPDATE field position
#define RIU_FIQCOEFFUPDATE_POS    0

/// FIQCOEFFUPDATE field reset value
#define RIU_FIQCOEFFUPDATE_RST    0x0

/**
 * @brief Returns the current value of the FIQCOEFFUPDATE field in the RWNXFEFIQCOEFFUPDATE register.
 *
 * The RWNXFEFIQCOEFFUPDATE register will be read and the FIQCOEFFUPDATE field's value will be returned.
 *
 * @return The current value of the FIQCOEFFUPDATE field in the RWNXFEFIQCOEFFUPDATE register.
 */
__INLINE uint8_t riu_fiqcoeffupdate_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFEFIQCOEFFUPDATE_ADDR);
    return (localVal >> 0);
}

/**
 * @brief Sets the FIQCOEFFUPDATE field of the RWNXFEFIQCOEFFUPDATE register.
 *
 * The RWNXFEFIQCOEFFUPDATE register will be read, modified to contain the new field value, and written.
 *
 * @param[in] fiqcoeffupdate - The value to set the field to.
 */
__INLINE void riu_fiqcoeffupdate_setf(uint8_t fiqcoeffupdate)
{
    REG_PL_WR(RIU_RWNXFEFIQCOEFFUPDATE_ADDR, (uint32_t)fiqcoeffupdate << 0);
}

#endif // RW_NX_FIQ_COMP_EN
/// @}

#if RW_NX_FIQ_COMP_EN
/**
 * @name RWNXFEFIQCOEFFREQ register definitions
 * <table>
 * <caption id="RWNXFEFIQCOEFFREQ_BF">RWNXFEFIQCOEFFREQ bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>00 <td>       FIQCOEFFREQ <td>R/W <td>R/W <td>0
 * </table>
 *
 * @{
 */

/// Address of the RWNXFEFIQCOEFFREQ register
#define RIU_RWNXFEFIQCOEFFREQ_ADDR   0x4033B18C
/// Offset of the RWNXFEFIQCOEFFREQ register from the base address
#define RIU_RWNXFEFIQCOEFFREQ_OFFSET 0x0000018C
/// Index of the RWNXFEFIQCOEFFREQ register
#define RIU_RWNXFEFIQCOEFFREQ_INDEX  0x00000063
/// Reset value of the RWNXFEFIQCOEFFREQ register
#define RIU_RWNXFEFIQCOEFFREQ_RESET  0x00000000

/**
 * @brief Returns the current value of the RWNXFEFIQCOEFFREQ register.
 * The RWNXFEFIQCOEFFREQ register will be read and its value returned.
 * @return The current value of the RWNXFEFIQCOEFFREQ register.
 */
__INLINE uint32_t riu_rwnxfefiqcoeffreq_get(void)
{
    return REG_PL_RD(RIU_RWNXFEFIQCOEFFREQ_ADDR);
}

/**
 * @brief Sets the RWNXFEFIQCOEFFREQ register to a value.
 * The RWNXFEFIQCOEFFREQ register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxfefiqcoeffreq_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXFEFIQCOEFFREQ_ADDR, value);
}

// field definitions
/// FIQCOEFFREQ field bit
#define RIU_FIQCOEFFREQ_BIT    ((uint32_t)0x00000001)
/// FIQCOEFFREQ field position
#define RIU_FIQCOEFFREQ_POS    0

/// FIQCOEFFREQ field reset value
#define RIU_FIQCOEFFREQ_RST    0x0

/**
 * @brief Returns the current value of the FIQCOEFFREQ field in the RWNXFEFIQCOEFFREQ register.
 *
 * The RWNXFEFIQCOEFFREQ register will be read and the FIQCOEFFREQ field's value will be returned.
 *
 * @return The current value of the FIQCOEFFREQ field in the RWNXFEFIQCOEFFREQ register.
 */
__INLINE uint8_t riu_fiqcoeffreq_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFEFIQCOEFFREQ_ADDR);
    return (localVal >> 0);
}

/**
 * @brief Sets the FIQCOEFFREQ field of the RWNXFEFIQCOEFFREQ register.
 *
 * The RWNXFEFIQCOEFFREQ register will be read, modified to contain the new field value, and written.
 *
 * @param[in] fiqcoeffreq - The value to set the field to.
 */
__INLINE void riu_fiqcoeffreq_setf(uint8_t fiqcoeffreq)
{
    REG_PL_WR(RIU_RWNXFEFIQCOEFFREQ_ADDR, (uint32_t)fiqcoeffreq << 0);
}

#endif // RW_NX_FIQ_COMP_EN
/// @}

#if RW_NX_FIQ_COMP_EN
/**
 * @name RWNXFEFIQSTART register definitions
 * <table>
 * <caption id="RWNXFEFIQSTART_BF">RWNXFEFIQSTART bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>16 <td>       FIQESTSTART <td>R <td>S <td>0
 * <tr><td>00 <td>      FIQCOLLSTART <td>R <td>S <td>0
 * </table>
 *
 * @{
 */

/// Address of the RWNXFEFIQSTART register
#define RIU_RWNXFEFIQSTART_ADDR   0x4033B190
/// Offset of the RWNXFEFIQSTART register from the base address
#define RIU_RWNXFEFIQSTART_OFFSET 0x00000190
/// Index of the RWNXFEFIQSTART register
#define RIU_RWNXFEFIQSTART_INDEX  0x00000064
/// Reset value of the RWNXFEFIQSTART register
#define RIU_RWNXFEFIQSTART_RESET  0x00000000

/**
 * @brief Returns the current value of the RWNXFEFIQSTART register.
 * The RWNXFEFIQSTART register will be read and its value returned.
 * @return The current value of the RWNXFEFIQSTART register.
 */
__INLINE uint32_t riu_rwnxfefiqstart_get(void)
{
    return REG_PL_RD(RIU_RWNXFEFIQSTART_ADDR);
}

/**
 * @brief Sets the RWNXFEFIQSTART register to a value.
 * The RWNXFEFIQSTART register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxfefiqstart_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXFEFIQSTART_ADDR, value);
}

// field definitions
/// FIQESTSTART field bit
#define RIU_FIQESTSTART_BIT     ((uint32_t)0x00010000)
/// FIQESTSTART field position
#define RIU_FIQESTSTART_POS     16
/// FIQCOLLSTART field bit
#define RIU_FIQCOLLSTART_BIT    ((uint32_t)0x00000001)
/// FIQCOLLSTART field position
#define RIU_FIQCOLLSTART_POS    0

/// FIQESTSTART field reset value
#define RIU_FIQESTSTART_RST     0x0
/// FIQCOLLSTART field reset value
#define RIU_FIQCOLLSTART_RST    0x0

/**
 * @brief Constructs a value for the RWNXFEFIQSTART register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] fiqeststart - The value to use for the FIQESTSTART field.
 * @param[in] fiqcollstart - The value to use for the FIQCOLLSTART field.
 */
__INLINE void riu_rwnxfefiqstart_pack(uint8_t fiqeststart, uint8_t fiqcollstart)
{
    REG_PL_WR(RIU_RWNXFEFIQSTART_ADDR,  ((uint32_t)fiqeststart << 16) | ((uint32_t)fiqcollstart << 0));
}

/**
 * @brief Unpacks RWNXFEFIQSTART's fields from current value of the RWNXFEFIQSTART register.
 *
 * Reads the RWNXFEFIQSTART register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] fiqeststart - Will be populated with the current value of this field from the register.
 * @param[out] fiqcollstart - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxfefiqstart_unpack(uint8_t* fiqeststart, uint8_t* fiqcollstart)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFEFIQSTART_ADDR);

    *fiqeststart = (localVal & ((uint32_t)0x00010000)) >> 16;
    *fiqcollstart = (localVal & ((uint32_t)0x00000001)) >> 0;
}

/**
 * @brief Returns the current value of the FIQESTSTART field in the RWNXFEFIQSTART register.
 *
 * The RWNXFEFIQSTART register will be read and the FIQESTSTART field's value will be returned.
 *
 * @return The current value of the FIQESTSTART field in the RWNXFEFIQSTART register.
 */
__INLINE uint8_t riu_fiqeststart_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFEFIQSTART_ADDR);
    return ((localVal & ((uint32_t)0x00010000)) >> 16);
}

/**
 * @brief Sets the FIQESTSTART field of the RWNXFEFIQSTART register.
 *
 * The RWNXFEFIQSTART register will be read, modified to contain the new field value, and written.
 *
 * @param[in] fiqeststart - The value to set the field to.
 */
__INLINE void riu_fiqeststart_setf(uint8_t fiqeststart)
{
    REG_PL_WR(RIU_RWNXFEFIQSTART_ADDR, (uint32_t)fiqeststart << 16);
}

/**
 * @brief Returns the current value of the FIQCOLLSTART field in the RWNXFEFIQSTART register.
 *
 * The RWNXFEFIQSTART register will be read and the FIQCOLLSTART field's value will be returned.
 *
 * @return The current value of the FIQCOLLSTART field in the RWNXFEFIQSTART register.
 */
__INLINE uint8_t riu_fiqcollstart_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFEFIQSTART_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief Sets the FIQCOLLSTART field of the RWNXFEFIQSTART register.
 *
 * The RWNXFEFIQSTART register will be read, modified to contain the new field value, and written.
 *
 * @param[in] fiqcollstart - The value to set the field to.
 */
__INLINE void riu_fiqcollstart_setf(uint8_t fiqcollstart)
{
    REG_PL_WR(RIU_RWNXFEFIQSTART_ADDR, (uint32_t)fiqcollstart << 0);
}

#endif // RW_NX_FIQ_COMP_EN
/// @}

/**
 * @name AGCGAINSTAT register definitions
 * <table>
 * <caption id="AGCGAINSTAT_BF">AGCGAINSTAT bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>15:08 <td>          AGCGAIN1 <td>W <td>R <td>0x0
 * <tr><td>07:00 <td>          AGCGAIN0 <td>W <td>R <td>0x0
 * </table>
 *
 * @{
 */

/// Address of the AGCGAINSTAT register
#define RIU_AGCGAINSTAT_ADDR   0x4033B200
/// Offset of the AGCGAINSTAT register from the base address
#define RIU_AGCGAINSTAT_OFFSET 0x00000200
/// Index of the AGCGAINSTAT register
#define RIU_AGCGAINSTAT_INDEX  0x00000080
/// Reset value of the AGCGAINSTAT register
#define RIU_AGCGAINSTAT_RESET  0x00000000

/**
 * @brief Returns the current value of the AGCGAINSTAT register.
 * The AGCGAINSTAT register will be read and its value returned.
 * @return The current value of the AGCGAINSTAT register.
 */
__INLINE uint32_t riu_agcgainstat_get(void)
{
    return REG_PL_RD(RIU_AGCGAINSTAT_ADDR);
}

// field definitions
/// AGCGAIN1 field mask
#define RIU_AGCGAIN1_MASK   ((uint32_t)0x0000FF00)
/// AGCGAIN1 field LSB position
#define RIU_AGCGAIN1_LSB    8
/// AGCGAIN1 field width
#define RIU_AGCGAIN1_WIDTH  ((uint32_t)0x00000008)
/// AGCGAIN0 field mask
#define RIU_AGCGAIN0_MASK   ((uint32_t)0x000000FF)
/// AGCGAIN0 field LSB position
#define RIU_AGCGAIN0_LSB    0
/// AGCGAIN0 field width
#define RIU_AGCGAIN0_WIDTH  ((uint32_t)0x00000008)

/// AGCGAIN1 field reset value
#define RIU_AGCGAIN1_RST    0x0
/// AGCGAIN0 field reset value
#define RIU_AGCGAIN0_RST    0x0

/**
 * @brief Unpacks AGCGAINSTAT's fields from current value of the AGCGAINSTAT register.
 *
 * Reads the AGCGAINSTAT register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] agcgain1 - Will be populated with the current value of this field from the register.
 * @param[out] agcgain0 - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_agcgainstat_unpack(uint8_t* agcgain1, uint8_t* agcgain0)
{
    uint32_t localVal = REG_PL_RD(RIU_AGCGAINSTAT_ADDR);

    *agcgain1 = (localVal & ((uint32_t)0x0000FF00)) >> 8;
    *agcgain0 = (localVal & ((uint32_t)0x000000FF)) >> 0;
}

/**
 * @brief Returns the current value of the AGCGAIN1 field in the AGCGAINSTAT register.
 *
 * The AGCGAINSTAT register will be read and the AGCGAIN1 field's value will be returned.
 *
 * @return The current value of the AGCGAIN1 field in the AGCGAINSTAT register.
 */
__INLINE uint8_t riu_agcgain1_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_AGCGAINSTAT_ADDR);
    return ((localVal & ((uint32_t)0x0000FF00)) >> 8);
}

/**
 * @brief Returns the current value of the AGCGAIN0 field in the AGCGAINSTAT register.
 *
 * The AGCGAINSTAT register will be read and the AGCGAIN0 field's value will be returned.
 *
 * @return The current value of the AGCGAIN0 field in the AGCGAINSTAT register.
 */
__INLINE uint8_t riu_agcgain0_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_AGCGAINSTAT_ADDR);
    return ((localVal & ((uint32_t)0x000000FF)) >> 0);
}

/// @}

/**
 * @name AGCADCPOWSTAT register definitions
 * <table>
 * <caption id="AGCADCPOWSTAT_BF">AGCADCPOWSTAT bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>14:08 <td>        ADCPOWDBV1 <td>W <td>R <td>0x0
 * <tr><td>06:00 <td>        ADCPOWDBV0 <td>W <td>R <td>0x0
 * </table>
 *
 * @{
 */

/// Address of the AGCADCPOWSTAT register
#define RIU_AGCADCPOWSTAT_ADDR   0x4033B208
/// Offset of the AGCADCPOWSTAT register from the base address
#define RIU_AGCADCPOWSTAT_OFFSET 0x00000208
/// Index of the AGCADCPOWSTAT register
#define RIU_AGCADCPOWSTAT_INDEX  0x00000082
/// Reset value of the AGCADCPOWSTAT register
#define RIU_AGCADCPOWSTAT_RESET  0x00000000

/**
 * @brief Returns the current value of the AGCADCPOWSTAT register.
 * The AGCADCPOWSTAT register will be read and its value returned.
 * @return The current value of the AGCADCPOWSTAT register.
 */
__INLINE uint32_t riu_agcadcpowstat_get(void)
{
    return REG_PL_RD(RIU_AGCADCPOWSTAT_ADDR);
}

// field definitions
/// ADCPOWDBV1 field mask
#define RIU_ADCPOWDBV1_MASK   ((uint32_t)0x00007F00)
/// ADCPOWDBV1 field LSB position
#define RIU_ADCPOWDBV1_LSB    8
/// ADCPOWDBV1 field width
#define RIU_ADCPOWDBV1_WIDTH  ((uint32_t)0x00000007)
/// ADCPOWDBV0 field mask
#define RIU_ADCPOWDBV0_MASK   ((uint32_t)0x0000007F)
/// ADCPOWDBV0 field LSB position
#define RIU_ADCPOWDBV0_LSB    0
/// ADCPOWDBV0 field width
#define RIU_ADCPOWDBV0_WIDTH  ((uint32_t)0x00000007)

/// ADCPOWDBV1 field reset value
#define RIU_ADCPOWDBV1_RST    0x0
/// ADCPOWDBV0 field reset value
#define RIU_ADCPOWDBV0_RST    0x0

/**
 * @brief Unpacks AGCADCPOWSTAT's fields from current value of the AGCADCPOWSTAT register.
 *
 * Reads the AGCADCPOWSTAT register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] adcpowdbv1 - Will be populated with the current value of this field from the register.
 * @param[out] adcpowdbv0 - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_agcadcpowstat_unpack(uint8_t* adcpowdbv1, uint8_t* adcpowdbv0)
{
    uint32_t localVal = REG_PL_RD(RIU_AGCADCPOWSTAT_ADDR);

    *adcpowdbv1 = (localVal & ((uint32_t)0x00007F00)) >> 8;
    *adcpowdbv0 = (localVal & ((uint32_t)0x0000007F)) >> 0;
}

/**
 * @brief Returns the current value of the ADCPOWDBV1 field in the AGCADCPOWSTAT register.
 *
 * The AGCADCPOWSTAT register will be read and the ADCPOWDBV1 field's value will be returned.
 *
 * @return The current value of the ADCPOWDBV1 field in the AGCADCPOWSTAT register.
 */
__INLINE uint8_t riu_adcpowdbv1_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_AGCADCPOWSTAT_ADDR);
    return ((localVal & ((uint32_t)0x00007F00)) >> 8);
}

/**
 * @brief Returns the current value of the ADCPOWDBV0 field in the AGCADCPOWSTAT register.
 *
 * The AGCADCPOWSTAT register will be read and the ADCPOWDBV0 field's value will be returned.
 *
 * @return The current value of the ADCPOWDBV0 field in the AGCADCPOWSTAT register.
 */
__INLINE uint8_t riu_adcpowdbv0_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_AGCADCPOWSTAT_ADDR);
    return ((localVal & ((uint32_t)0x0000007F)) >> 0);
}

/// @}

/**
 * @name AGCINBDPOW20PSTAT register definitions
 * <table>
 * <caption id="AGCINBDPOW20PSTAT_BF">AGCINBDPOW20PSTAT bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>15:08 <td>    INBDPOW20PDBM1 <td>W <td>R <td>0x0
 * <tr><td>07:00 <td>    INBDPOW20PDBM0 <td>W <td>R <td>0x0
 * </table>
 *
 * @{
 */

/// Address of the AGCINBDPOW20PSTAT register
#define RIU_AGCINBDPOW20PSTAT_ADDR   0x4033B20C
/// Offset of the AGCINBDPOW20PSTAT register from the base address
#define RIU_AGCINBDPOW20PSTAT_OFFSET 0x0000020C
/// Index of the AGCINBDPOW20PSTAT register
#define RIU_AGCINBDPOW20PSTAT_INDEX  0x00000083
/// Reset value of the AGCINBDPOW20PSTAT register
#define RIU_AGCINBDPOW20PSTAT_RESET  0x00000000

/**
 * @brief Returns the current value of the AGCINBDPOW20PSTAT register.
 * The AGCINBDPOW20PSTAT register will be read and its value returned.
 * @return The current value of the AGCINBDPOW20PSTAT register.
 */
__INLINE uint32_t riu_agcinbdpow20pstat_get(void)
{
    return REG_PL_RD(RIU_AGCINBDPOW20PSTAT_ADDR);
}

// field definitions
/// INBDPOW20PDBM1 field mask
#define RIU_INBDPOW20PDBM1_MASK   ((uint32_t)0x0000FF00)
/// INBDPOW20PDBM1 field LSB position
#define RIU_INBDPOW20PDBM1_LSB    8
/// INBDPOW20PDBM1 field width
#define RIU_INBDPOW20PDBM1_WIDTH  ((uint32_t)0x00000008)
/// INBDPOW20PDBM0 field mask
#define RIU_INBDPOW20PDBM0_MASK   ((uint32_t)0x000000FF)
/// INBDPOW20PDBM0 field LSB position
#define RIU_INBDPOW20PDBM0_LSB    0
/// INBDPOW20PDBM0 field width
#define RIU_INBDPOW20PDBM0_WIDTH  ((uint32_t)0x00000008)

/// INBDPOW20PDBM1 field reset value
#define RIU_INBDPOW20PDBM1_RST    0x0
/// INBDPOW20PDBM0 field reset value
#define RIU_INBDPOW20PDBM0_RST    0x0

/**
 * @brief Unpacks AGCINBDPOW20PSTAT's fields from current value of the AGCINBDPOW20PSTAT register.
 *
 * Reads the AGCINBDPOW20PSTAT register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] inbdpow20pdbm1 - Will be populated with the current value of this field from the register.
 * @param[out] inbdpow20pdbm0 - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_agcinbdpow20pstat_unpack(uint8_t* inbdpow20pdbm1, uint8_t* inbdpow20pdbm0)
{
    uint32_t localVal = REG_PL_RD(RIU_AGCINBDPOW20PSTAT_ADDR);

    *inbdpow20pdbm1 = (localVal & ((uint32_t)0x0000FF00)) >> 8;
    *inbdpow20pdbm0 = (localVal & ((uint32_t)0x000000FF)) >> 0;
}

/**
 * @brief Returns the current value of the INBDPOW20PDBM1 field in the AGCINBDPOW20PSTAT register.
 *
 * The AGCINBDPOW20PSTAT register will be read and the INBDPOW20PDBM1 field's value will be returned.
 *
 * @return The current value of the INBDPOW20PDBM1 field in the AGCINBDPOW20PSTAT register.
 */
__INLINE uint8_t riu_inbdpow20pdbm1_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_AGCINBDPOW20PSTAT_ADDR);
    return ((localVal & ((uint32_t)0x0000FF00)) >> 8);
}

/**
 * @brief Returns the current value of the INBDPOW20PDBM0 field in the AGCINBDPOW20PSTAT register.
 *
 * The AGCINBDPOW20PSTAT register will be read and the INBDPOW20PDBM0 field's value will be returned.
 *
 * @return The current value of the INBDPOW20PDBM0 field in the AGCINBDPOW20PSTAT register.
 */
__INLINE uint8_t riu_inbdpow20pdbm0_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_AGCINBDPOW20PSTAT_ADDR);
    return ((localVal & ((uint32_t)0x000000FF)) >> 0);
}

/// @}

/**
 * @name AGCDIGGAIN0STAT register definitions
 * <table>
 * <caption id="AGCDIGGAIN0STAT_BF">AGCDIGGAIN0STAT bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>22:16 <td>     DIGGAIN80ANT0 <td>W <td>R <td>0x0
 * <tr><td>14:08 <td>     DIGGAIN40ANT0 <td>W <td>R <td>0x0
 * <tr><td>06:00 <td>     DIGGAIN20ANT0 <td>W <td>R <td>0x0
 * </table>
 *
 * @{
 */

/// Address of the AGCDIGGAIN0STAT register
#define RIU_AGCDIGGAIN0STAT_ADDR   0x4033B210
/// Offset of the AGCDIGGAIN0STAT register from the base address
#define RIU_AGCDIGGAIN0STAT_OFFSET 0x00000210
/// Index of the AGCDIGGAIN0STAT register
#define RIU_AGCDIGGAIN0STAT_INDEX  0x00000084
/// Reset value of the AGCDIGGAIN0STAT register
#define RIU_AGCDIGGAIN0STAT_RESET  0x00000000

/**
 * @brief Returns the current value of the AGCDIGGAIN0STAT register.
 * The AGCDIGGAIN0STAT register will be read and its value returned.
 * @return The current value of the AGCDIGGAIN0STAT register.
 */
__INLINE uint32_t riu_agcdiggain0stat_get(void)
{
    return REG_PL_RD(RIU_AGCDIGGAIN0STAT_ADDR);
}

// field definitions
/// DIGGAIN80ANT0 field mask
#define RIU_DIGGAIN80ANT0_MASK   ((uint32_t)0x007F0000)
/// DIGGAIN80ANT0 field LSB position
#define RIU_DIGGAIN80ANT0_LSB    16
/// DIGGAIN80ANT0 field width
#define RIU_DIGGAIN80ANT0_WIDTH  ((uint32_t)0x00000007)
/// DIGGAIN40ANT0 field mask
#define RIU_DIGGAIN40ANT0_MASK   ((uint32_t)0x00007F00)
/// DIGGAIN40ANT0 field LSB position
#define RIU_DIGGAIN40ANT0_LSB    8
/// DIGGAIN40ANT0 field width
#define RIU_DIGGAIN40ANT0_WIDTH  ((uint32_t)0x00000007)
/// DIGGAIN20ANT0 field mask
#define RIU_DIGGAIN20ANT0_MASK   ((uint32_t)0x0000007F)
/// DIGGAIN20ANT0 field LSB position
#define RIU_DIGGAIN20ANT0_LSB    0
/// DIGGAIN20ANT0 field width
#define RIU_DIGGAIN20ANT0_WIDTH  ((uint32_t)0x00000007)

/// DIGGAIN80ANT0 field reset value
#define RIU_DIGGAIN80ANT0_RST    0x0
/// DIGGAIN40ANT0 field reset value
#define RIU_DIGGAIN40ANT0_RST    0x0
/// DIGGAIN20ANT0 field reset value
#define RIU_DIGGAIN20ANT0_RST    0x0

/**
 * @brief Unpacks AGCDIGGAIN0STAT's fields from current value of the AGCDIGGAIN0STAT register.
 *
 * Reads the AGCDIGGAIN0STAT register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] diggain80ant0 - Will be populated with the current value of this field from the register.
 * @param[out] diggain40ant0 - Will be populated with the current value of this field from the register.
 * @param[out] diggain20ant0 - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_agcdiggain0stat_unpack(uint8_t* diggain80ant0, uint8_t* diggain40ant0, uint8_t* diggain20ant0)
{
    uint32_t localVal = REG_PL_RD(RIU_AGCDIGGAIN0STAT_ADDR);

    *diggain80ant0 = (localVal & ((uint32_t)0x007F0000)) >> 16;
    *diggain40ant0 = (localVal & ((uint32_t)0x00007F00)) >> 8;
    *diggain20ant0 = (localVal & ((uint32_t)0x0000007F)) >> 0;
}

/**
 * @brief Returns the current value of the DIGGAIN80ANT0 field in the AGCDIGGAIN0STAT register.
 *
 * The AGCDIGGAIN0STAT register will be read and the DIGGAIN80ANT0 field's value will be returned.
 *
 * @return The current value of the DIGGAIN80ANT0 field in the AGCDIGGAIN0STAT register.
 */
__INLINE uint8_t riu_diggain80ant0_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_AGCDIGGAIN0STAT_ADDR);
    return ((localVal & ((uint32_t)0x007F0000)) >> 16);
}

/**
 * @brief Returns the current value of the DIGGAIN40ANT0 field in the AGCDIGGAIN0STAT register.
 *
 * The AGCDIGGAIN0STAT register will be read and the DIGGAIN40ANT0 field's value will be returned.
 *
 * @return The current value of the DIGGAIN40ANT0 field in the AGCDIGGAIN0STAT register.
 */
__INLINE uint8_t riu_diggain40ant0_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_AGCDIGGAIN0STAT_ADDR);
    return ((localVal & ((uint32_t)0x00007F00)) >> 8);
}

/**
 * @brief Returns the current value of the DIGGAIN20ANT0 field in the AGCDIGGAIN0STAT register.
 *
 * The AGCDIGGAIN0STAT register will be read and the DIGGAIN20ANT0 field's value will be returned.
 *
 * @return The current value of the DIGGAIN20ANT0 field in the AGCDIGGAIN0STAT register.
 */
__INLINE uint8_t riu_diggain20ant0_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_AGCDIGGAIN0STAT_ADDR);
    return ((localVal & ((uint32_t)0x0000007F)) >> 0);
}

/// @}

/**
 * @name AGCDIGGAIN1STAT register definitions
 * <table>
 * <caption id="AGCDIGGAIN1STAT_BF">AGCDIGGAIN1STAT bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>22:16 <td>     DIGGAIN80ANT1 <td>W <td>R <td>0x0
 * <tr><td>14:08 <td>     DIGGAIN40ANT1 <td>W <td>R <td>0x0
 * <tr><td>06:00 <td>     DIGGAIN20ANT1 <td>W <td>R <td>0x0
 * </table>
 *
 * @{
 */

/// Address of the AGCDIGGAIN1STAT register
#define RIU_AGCDIGGAIN1STAT_ADDR   0x4033B214
/// Offset of the AGCDIGGAIN1STAT register from the base address
#define RIU_AGCDIGGAIN1STAT_OFFSET 0x00000214
/// Index of the AGCDIGGAIN1STAT register
#define RIU_AGCDIGGAIN1STAT_INDEX  0x00000085
/// Reset value of the AGCDIGGAIN1STAT register
#define RIU_AGCDIGGAIN1STAT_RESET  0x00000000

/**
 * @brief Returns the current value of the AGCDIGGAIN1STAT register.
 * The AGCDIGGAIN1STAT register will be read and its value returned.
 * @return The current value of the AGCDIGGAIN1STAT register.
 */
__INLINE uint32_t riu_agcdiggain1stat_get(void)
{
    return REG_PL_RD(RIU_AGCDIGGAIN1STAT_ADDR);
}

// field definitions
/// DIGGAIN80ANT1 field mask
#define RIU_DIGGAIN80ANT1_MASK   ((uint32_t)0x007F0000)
/// DIGGAIN80ANT1 field LSB position
#define RIU_DIGGAIN80ANT1_LSB    16
/// DIGGAIN80ANT1 field width
#define RIU_DIGGAIN80ANT1_WIDTH  ((uint32_t)0x00000007)
/// DIGGAIN40ANT1 field mask
#define RIU_DIGGAIN40ANT1_MASK   ((uint32_t)0x00007F00)
/// DIGGAIN40ANT1 field LSB position
#define RIU_DIGGAIN40ANT1_LSB    8
/// DIGGAIN40ANT1 field width
#define RIU_DIGGAIN40ANT1_WIDTH  ((uint32_t)0x00000007)
/// DIGGAIN20ANT1 field mask
#define RIU_DIGGAIN20ANT1_MASK   ((uint32_t)0x0000007F)
/// DIGGAIN20ANT1 field LSB position
#define RIU_DIGGAIN20ANT1_LSB    0
/// DIGGAIN20ANT1 field width
#define RIU_DIGGAIN20ANT1_WIDTH  ((uint32_t)0x00000007)

/// DIGGAIN80ANT1 field reset value
#define RIU_DIGGAIN80ANT1_RST    0x0
/// DIGGAIN40ANT1 field reset value
#define RIU_DIGGAIN40ANT1_RST    0x0
/// DIGGAIN20ANT1 field reset value
#define RIU_DIGGAIN20ANT1_RST    0x0

/**
 * @brief Unpacks AGCDIGGAIN1STAT's fields from current value of the AGCDIGGAIN1STAT register.
 *
 * Reads the AGCDIGGAIN1STAT register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] diggain80ant1 - Will be populated with the current value of this field from the register.
 * @param[out] diggain40ant1 - Will be populated with the current value of this field from the register.
 * @param[out] diggain20ant1 - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_agcdiggain1stat_unpack(uint8_t* diggain80ant1, uint8_t* diggain40ant1, uint8_t* diggain20ant1)
{
    uint32_t localVal = REG_PL_RD(RIU_AGCDIGGAIN1STAT_ADDR);

    *diggain80ant1 = (localVal & ((uint32_t)0x007F0000)) >> 16;
    *diggain40ant1 = (localVal & ((uint32_t)0x00007F00)) >> 8;
    *diggain20ant1 = (localVal & ((uint32_t)0x0000007F)) >> 0;
}

/**
 * @brief Returns the current value of the DIGGAIN80ANT1 field in the AGCDIGGAIN1STAT register.
 *
 * The AGCDIGGAIN1STAT register will be read and the DIGGAIN80ANT1 field's value will be returned.
 *
 * @return The current value of the DIGGAIN80ANT1 field in the AGCDIGGAIN1STAT register.
 */
__INLINE uint8_t riu_diggain80ant1_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_AGCDIGGAIN1STAT_ADDR);
    return ((localVal & ((uint32_t)0x007F0000)) >> 16);
}

/**
 * @brief Returns the current value of the DIGGAIN40ANT1 field in the AGCDIGGAIN1STAT register.
 *
 * The AGCDIGGAIN1STAT register will be read and the DIGGAIN40ANT1 field's value will be returned.
 *
 * @return The current value of the DIGGAIN40ANT1 field in the AGCDIGGAIN1STAT register.
 */
__INLINE uint8_t riu_diggain40ant1_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_AGCDIGGAIN1STAT_ADDR);
    return ((localVal & ((uint32_t)0x00007F00)) >> 8);
}

/**
 * @brief Returns the current value of the DIGGAIN20ANT1 field in the AGCDIGGAIN1STAT register.
 *
 * The AGCDIGGAIN1STAT register will be read and the DIGGAIN20ANT1 field's value will be returned.
 *
 * @return The current value of the DIGGAIN20ANT1 field in the AGCDIGGAIN1STAT register.
 */
__INLINE uint8_t riu_diggain20ant1_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_AGCDIGGAIN1STAT_ADDR);
    return ((localVal & ((uint32_t)0x0000007F)) >> 0);
}

/// @}

#if RW_RADAR_EN
/**
 * @name RADARFIFOSTAT register definitions
 * <table>
 * <caption id="RADARFIFOSTAT_BF">RADARFIFOSTAT bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>00 <td>      RADFIFOEMPTY <td>W <td>R <td>1
 * </table>
 *
 * @{
 */

/// Address of the RADARFIFOSTAT register
#define RIU_RADARFIFOSTAT_ADDR   0x4033B220
/// Offset of the RADARFIFOSTAT register from the base address
#define RIU_RADARFIFOSTAT_OFFSET 0x00000220
/// Index of the RADARFIFOSTAT register
#define RIU_RADARFIFOSTAT_INDEX  0x00000088
/// Reset value of the RADARFIFOSTAT register
#define RIU_RADARFIFOSTAT_RESET  0x00000001

/**
 * @brief Returns the current value of the RADARFIFOSTAT register.
 * The RADARFIFOSTAT register will be read and its value returned.
 * @return The current value of the RADARFIFOSTAT register.
 */
__INLINE uint32_t riu_radarfifostat_get(void)
{
    return REG_PL_RD(RIU_RADARFIFOSTAT_ADDR);
}

// field definitions
/// RADFIFOEMPTY field bit
#define RIU_RADFIFOEMPTY_BIT    ((uint32_t)0x00000001)
/// RADFIFOEMPTY field position
#define RIU_RADFIFOEMPTY_POS    0

/// RADFIFOEMPTY field reset value
#define RIU_RADFIFOEMPTY_RST    0x1

/**
 * @brief Returns the current value of the RADFIFOEMPTY field in the RADARFIFOSTAT register.
 *
 * The RADARFIFOSTAT register will be read and the RADFIFOEMPTY field's value will be returned.
 *
 * @return The current value of the RADFIFOEMPTY field in the RADARFIFOSTAT register.
 */
__INLINE uint8_t riu_radfifoempty_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RADARFIFOSTAT_ADDR);
    return (localVal >> 0);
}

#endif // RW_RADAR_EN
/// @}

/**
 * @name AGCINBDPOW20PNOISESTAT register definitions
 * <table>
 * <caption id="AGCINBDPOW20PNOISESTAT_BF">AGCINBDPOW20PNOISESTAT bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>15:08 <td>INBDPOW20PNOISEDBM1 <td>W <td>R <td>0x0
 * <tr><td>07:00 <td>INBDPOW20PNOISEDBM0 <td>W <td>R <td>0x0
 * </table>
 *
 * @{
 */

/// Address of the AGCINBDPOW20PNOISESTAT register
#define RIU_AGCINBDPOW20PNOISESTAT_ADDR   0x4033B228
/// Offset of the AGCINBDPOW20PNOISESTAT register from the base address
#define RIU_AGCINBDPOW20PNOISESTAT_OFFSET 0x00000228
/// Index of the AGCINBDPOW20PNOISESTAT register
#define RIU_AGCINBDPOW20PNOISESTAT_INDEX  0x0000008A
/// Reset value of the AGCINBDPOW20PNOISESTAT register
#define RIU_AGCINBDPOW20PNOISESTAT_RESET  0x00000000

/**
 * @brief Returns the current value of the AGCINBDPOW20PNOISESTAT register.
 * The AGCINBDPOW20PNOISESTAT register will be read and its value returned.
 * @return The current value of the AGCINBDPOW20PNOISESTAT register.
 */
__INLINE uint32_t riu_agcinbdpow20pnoisestat_get(void)
{
    return REG_PL_RD(RIU_AGCINBDPOW20PNOISESTAT_ADDR);
}

// field definitions
/// INBDPOW20PNOISEDBM1 field mask
#define RIU_INBDPOW20PNOISEDBM1_MASK   ((uint32_t)0x0000FF00)
/// INBDPOW20PNOISEDBM1 field LSB position
#define RIU_INBDPOW20PNOISEDBM1_LSB    8
/// INBDPOW20PNOISEDBM1 field width
#define RIU_INBDPOW20PNOISEDBM1_WIDTH  ((uint32_t)0x00000008)
/// INBDPOW20PNOISEDBM0 field mask
#define RIU_INBDPOW20PNOISEDBM0_MASK   ((uint32_t)0x000000FF)
/// INBDPOW20PNOISEDBM0 field LSB position
#define RIU_INBDPOW20PNOISEDBM0_LSB    0
/// INBDPOW20PNOISEDBM0 field width
#define RIU_INBDPOW20PNOISEDBM0_WIDTH  ((uint32_t)0x00000008)

/// INBDPOW20PNOISEDBM1 field reset value
#define RIU_INBDPOW20PNOISEDBM1_RST    0x0
/// INBDPOW20PNOISEDBM0 field reset value
#define RIU_INBDPOW20PNOISEDBM0_RST    0x0

/**
 * @brief Unpacks AGCINBDPOW20PNOISESTAT's fields from current value of the AGCINBDPOW20PNOISESTAT register.
 *
 * Reads the AGCINBDPOW20PNOISESTAT register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] inbdpow20pnoisedbm1 - Will be populated with the current value of this field from the register.
 * @param[out] inbdpow20pnoisedbm0 - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_agcinbdpow20pnoisestat_unpack(uint8_t* inbdpow20pnoisedbm1, uint8_t* inbdpow20pnoisedbm0)
{
    uint32_t localVal = REG_PL_RD(RIU_AGCINBDPOW20PNOISESTAT_ADDR);

    *inbdpow20pnoisedbm1 = (localVal & ((uint32_t)0x0000FF00)) >> 8;
    *inbdpow20pnoisedbm0 = (localVal & ((uint32_t)0x000000FF)) >> 0;
}

/**
 * @brief Returns the current value of the INBDPOW20PNOISEDBM1 field in the AGCINBDPOW20PNOISESTAT register.
 *
 * The AGCINBDPOW20PNOISESTAT register will be read and the INBDPOW20PNOISEDBM1 field's value will be returned.
 *
 * @return The current value of the INBDPOW20PNOISEDBM1 field in the AGCINBDPOW20PNOISESTAT register.
 */
__INLINE uint8_t riu_inbdpow20pnoisedbm1_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_AGCINBDPOW20PNOISESTAT_ADDR);
    return ((localVal & ((uint32_t)0x0000FF00)) >> 8);
}

/**
 * @brief Returns the current value of the INBDPOW20PNOISEDBM0 field in the AGCINBDPOW20PNOISESTAT register.
 *
 * The AGCINBDPOW20PNOISESTAT register will be read and the INBDPOW20PNOISEDBM0 field's value will be returned.
 *
 * @return The current value of the INBDPOW20PNOISEDBM0 field in the AGCINBDPOW20PNOISESTAT register.
 */
__INLINE uint8_t riu_inbdpow20pnoisedbm0_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_AGCINBDPOW20PNOISESTAT_ADDR);
    return ((localVal & ((uint32_t)0x000000FF)) >> 0);
}

/// @}

/**
 * @name AGCINBDPOWSECSTAT register definitions
 * <table>
 * <caption id="AGCINBDPOWSECSTAT_BF">AGCINBDPOWSECSTAT bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>23:16 <td>     INBDPOW40SDBM <td>W <td>R <td>0x0
 * <tr><td>07:00 <td>     INBDPOW20SDBM <td>W <td>R <td>0x0
 * </table>
 *
 * @{
 */

/// Address of the AGCINBDPOWSECSTAT register
#define RIU_AGCINBDPOWSECSTAT_ADDR   0x4033B22C
/// Offset of the AGCINBDPOWSECSTAT register from the base address
#define RIU_AGCINBDPOWSECSTAT_OFFSET 0x0000022C
/// Index of the AGCINBDPOWSECSTAT register
#define RIU_AGCINBDPOWSECSTAT_INDEX  0x0000008B
/// Reset value of the AGCINBDPOWSECSTAT register
#define RIU_AGCINBDPOWSECSTAT_RESET  0x00000000

/**
 * @brief Returns the current value of the AGCINBDPOWSECSTAT register.
 * The AGCINBDPOWSECSTAT register will be read and its value returned.
 * @return The current value of the AGCINBDPOWSECSTAT register.
 */
__INLINE uint32_t riu_agcinbdpowsecstat_get(void)
{
    return REG_PL_RD(RIU_AGCINBDPOWSECSTAT_ADDR);
}

// field definitions
/// INBDPOW40SDBM field mask
#define RIU_INBDPOW40SDBM_MASK   ((uint32_t)0x00FF0000)
/// INBDPOW40SDBM field LSB position
#define RIU_INBDPOW40SDBM_LSB    16
/// INBDPOW40SDBM field width
#define RIU_INBDPOW40SDBM_WIDTH  ((uint32_t)0x00000008)
/// INBDPOW20SDBM field mask
#define RIU_INBDPOW20SDBM_MASK   ((uint32_t)0x000000FF)
/// INBDPOW20SDBM field LSB position
#define RIU_INBDPOW20SDBM_LSB    0
/// INBDPOW20SDBM field width
#define RIU_INBDPOW20SDBM_WIDTH  ((uint32_t)0x00000008)

/// INBDPOW40SDBM field reset value
#define RIU_INBDPOW40SDBM_RST    0x0
/// INBDPOW20SDBM field reset value
#define RIU_INBDPOW20SDBM_RST    0x0

/**
 * @brief Unpacks AGCINBDPOWSECSTAT's fields from current value of the AGCINBDPOWSECSTAT register.
 *
 * Reads the AGCINBDPOWSECSTAT register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] inbdpow40sdbm - Will be populated with the current value of this field from the register.
 * @param[out] inbdpow20sdbm - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_agcinbdpowsecstat_unpack(uint8_t* inbdpow40sdbm, uint8_t* inbdpow20sdbm)
{
    uint32_t localVal = REG_PL_RD(RIU_AGCINBDPOWSECSTAT_ADDR);

    *inbdpow40sdbm = (localVal & ((uint32_t)0x00FF0000)) >> 16;
    *inbdpow20sdbm = (localVal & ((uint32_t)0x000000FF)) >> 0;
}

/**
 * @brief Returns the current value of the INBDPOW40SDBM field in the AGCINBDPOWSECSTAT register.
 *
 * The AGCINBDPOWSECSTAT register will be read and the INBDPOW40SDBM field's value will be returned.
 *
 * @return The current value of the INBDPOW40SDBM field in the AGCINBDPOWSECSTAT register.
 */
__INLINE uint8_t riu_inbdpow40sdbm_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_AGCINBDPOWSECSTAT_ADDR);
    return ((localVal & ((uint32_t)0x00FF0000)) >> 16);
}

/**
 * @brief Returns the current value of the INBDPOW20SDBM field in the AGCINBDPOWSECSTAT register.
 *
 * The AGCINBDPOWSECSTAT register will be read and the INBDPOW20SDBM field's value will be returned.
 *
 * @return The current value of the INBDPOW20SDBM field in the AGCINBDPOWSECSTAT register.
 */
__INLINE uint8_t riu_inbdpow20sdbm_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_AGCINBDPOWSECSTAT_ADDR);
    return ((localVal & ((uint32_t)0x000000FF)) >> 0);
}

/// @}

/**
 * @name AGCINBDPOWSECNOISESTAT register definitions
 * <table>
 * <caption id="AGCINBDPOWSECNOISESTAT_BF">AGCINBDPOWSECNOISESTAT bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>23:16 <td>INBDPOW40SNOISEDBM <td>W <td>R <td>0x0
 * <tr><td>07:00 <td>INBDPOW20SNOISEDBM <td>W <td>R <td>0x0
 * </table>
 *
 * @{
 */

/// Address of the AGCINBDPOWSECNOISESTAT register
#define RIU_AGCINBDPOWSECNOISESTAT_ADDR   0x4033B230
/// Offset of the AGCINBDPOWSECNOISESTAT register from the base address
#define RIU_AGCINBDPOWSECNOISESTAT_OFFSET 0x00000230
/// Index of the AGCINBDPOWSECNOISESTAT register
#define RIU_AGCINBDPOWSECNOISESTAT_INDEX  0x0000008C
/// Reset value of the AGCINBDPOWSECNOISESTAT register
#define RIU_AGCINBDPOWSECNOISESTAT_RESET  0x00000000

/**
 * @brief Returns the current value of the AGCINBDPOWSECNOISESTAT register.
 * The AGCINBDPOWSECNOISESTAT register will be read and its value returned.
 * @return The current value of the AGCINBDPOWSECNOISESTAT register.
 */
__INLINE uint32_t riu_agcinbdpowsecnoisestat_get(void)
{
    return REG_PL_RD(RIU_AGCINBDPOWSECNOISESTAT_ADDR);
}

// field definitions
/// INBDPOW40SNOISEDBM field mask
#define RIU_INBDPOW40SNOISEDBM_MASK   ((uint32_t)0x00FF0000)
/// INBDPOW40SNOISEDBM field LSB position
#define RIU_INBDPOW40SNOISEDBM_LSB    16
/// INBDPOW40SNOISEDBM field width
#define RIU_INBDPOW40SNOISEDBM_WIDTH  ((uint32_t)0x00000008)
/// INBDPOW20SNOISEDBM field mask
#define RIU_INBDPOW20SNOISEDBM_MASK   ((uint32_t)0x000000FF)
/// INBDPOW20SNOISEDBM field LSB position
#define RIU_INBDPOW20SNOISEDBM_LSB    0
/// INBDPOW20SNOISEDBM field width
#define RIU_INBDPOW20SNOISEDBM_WIDTH  ((uint32_t)0x00000008)

/// INBDPOW40SNOISEDBM field reset value
#define RIU_INBDPOW40SNOISEDBM_RST    0x0
/// INBDPOW20SNOISEDBM field reset value
#define RIU_INBDPOW20SNOISEDBM_RST    0x0

/**
 * @brief Unpacks AGCINBDPOWSECNOISESTAT's fields from current value of the AGCINBDPOWSECNOISESTAT register.
 *
 * Reads the AGCINBDPOWSECNOISESTAT register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] inbdpow40snoisedbm - Will be populated with the current value of this field from the register.
 * @param[out] inbdpow20snoisedbm - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_agcinbdpowsecnoisestat_unpack(uint8_t* inbdpow40snoisedbm, uint8_t* inbdpow20snoisedbm)
{
    uint32_t localVal = REG_PL_RD(RIU_AGCINBDPOWSECNOISESTAT_ADDR);

    *inbdpow40snoisedbm = (localVal & ((uint32_t)0x00FF0000)) >> 16;
    *inbdpow20snoisedbm = (localVal & ((uint32_t)0x000000FF)) >> 0;
}

/**
 * @brief Returns the current value of the INBDPOW40SNOISEDBM field in the AGCINBDPOWSECNOISESTAT register.
 *
 * The AGCINBDPOWSECNOISESTAT register will be read and the INBDPOW40SNOISEDBM field's value will be returned.
 *
 * @return The current value of the INBDPOW40SNOISEDBM field in the AGCINBDPOWSECNOISESTAT register.
 */
__INLINE uint8_t riu_inbdpow40snoisedbm_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_AGCINBDPOWSECNOISESTAT_ADDR);
    return ((localVal & ((uint32_t)0x00FF0000)) >> 16);
}

/**
 * @brief Returns the current value of the INBDPOW20SNOISEDBM field in the AGCINBDPOWSECNOISESTAT register.
 *
 * The AGCINBDPOWSECNOISESTAT register will be read and the INBDPOW20SNOISEDBM field's value will be returned.
 *
 * @return The current value of the INBDPOW20SNOISEDBM field in the AGCINBDPOWSECNOISESTAT register.
 */
__INLINE uint8_t riu_inbdpow20snoisedbm_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_AGCINBDPOWSECNOISESTAT_ADDR);
    return ((localVal & ((uint32_t)0x000000FF)) >> 0);
}

/// @}

#if RW_NX_IQ_COMP_EN
/**
 * @name RWNXFERXIQSTATVARI0 register definitions
 * <table>
 * <caption id="RWNXFERXIQSTATVARI0_BF">RWNXFERXIQSTATVARI0 bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>21:00 <td>         RXIQVARI0 <td>W <td>R <td>0x0
 * </table>
 *
 * @{
 */

/// Address of the RWNXFERXIQSTATVARI0 register
#define RIU_RWNXFERXIQSTATVARI0_ADDR   0x4033B240
/// Offset of the RWNXFERXIQSTATVARI0 register from the base address
#define RIU_RWNXFERXIQSTATVARI0_OFFSET 0x00000240
/// Index of the RWNXFERXIQSTATVARI0 register
#define RIU_RWNXFERXIQSTATVARI0_INDEX  0x00000090
/// Reset value of the RWNXFERXIQSTATVARI0 register
#define RIU_RWNXFERXIQSTATVARI0_RESET  0x00000000

/**
 * @brief Returns the current value of the RWNXFERXIQSTATVARI0 register.
 * The RWNXFERXIQSTATVARI0 register will be read and its value returned.
 * @return The current value of the RWNXFERXIQSTATVARI0 register.
 */
__INLINE uint32_t riu_rwnxferxiqstatvari0_get(void)
{
    return REG_PL_RD(RIU_RWNXFERXIQSTATVARI0_ADDR);
}

// field definitions
/// RXIQVARI0 field mask
#define RIU_RXIQVARI0_MASK   ((uint32_t)0x003FFFFF)
/// RXIQVARI0 field LSB position
#define RIU_RXIQVARI0_LSB    0
/// RXIQVARI0 field width
#define RIU_RXIQVARI0_WIDTH  ((uint32_t)0x00000016)

/// RXIQVARI0 field reset value
#define RIU_RXIQVARI0_RST    0x0

/**
 * @brief Returns the current value of the RXIQVARI0 field in the RWNXFERXIQSTATVARI0 register.
 *
 * The RWNXFERXIQSTATVARI0 register will be read and the RXIQVARI0 field's value will be returned.
 *
 * @return The current value of the RXIQVARI0 field in the RWNXFERXIQSTATVARI0 register.
 */
__INLINE uint32_t riu_rxiqvari0_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFERXIQSTATVARI0_ADDR);
    return (localVal >> 0);
}

#endif // RW_NX_IQ_COMP_EN
/// @}

#if RW_NX_IQ_COMP_EN
/**
 * @name RWNXFERXIQSTATVARQ0 register definitions
 * <table>
 * <caption id="RWNXFERXIQSTATVARQ0_BF">RWNXFERXIQSTATVARQ0 bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>21:00 <td>         RXIQVARQ0 <td>W <td>R <td>0x0
 * </table>
 *
 * @{
 */

/// Address of the RWNXFERXIQSTATVARQ0 register
#define RIU_RWNXFERXIQSTATVARQ0_ADDR   0x4033B244
/// Offset of the RWNXFERXIQSTATVARQ0 register from the base address
#define RIU_RWNXFERXIQSTATVARQ0_OFFSET 0x00000244
/// Index of the RWNXFERXIQSTATVARQ0 register
#define RIU_RWNXFERXIQSTATVARQ0_INDEX  0x00000091
/// Reset value of the RWNXFERXIQSTATVARQ0 register
#define RIU_RWNXFERXIQSTATVARQ0_RESET  0x00000000

/**
 * @brief Returns the current value of the RWNXFERXIQSTATVARQ0 register.
 * The RWNXFERXIQSTATVARQ0 register will be read and its value returned.
 * @return The current value of the RWNXFERXIQSTATVARQ0 register.
 */
__INLINE uint32_t riu_rwnxferxiqstatvarq0_get(void)
{
    return REG_PL_RD(RIU_RWNXFERXIQSTATVARQ0_ADDR);
}

// field definitions
/// RXIQVARQ0 field mask
#define RIU_RXIQVARQ0_MASK   ((uint32_t)0x003FFFFF)
/// RXIQVARQ0 field LSB position
#define RIU_RXIQVARQ0_LSB    0
/// RXIQVARQ0 field width
#define RIU_RXIQVARQ0_WIDTH  ((uint32_t)0x00000016)

/// RXIQVARQ0 field reset value
#define RIU_RXIQVARQ0_RST    0x0

/**
 * @brief Returns the current value of the RXIQVARQ0 field in the RWNXFERXIQSTATVARQ0 register.
 *
 * The RWNXFERXIQSTATVARQ0 register will be read and the RXIQVARQ0 field's value will be returned.
 *
 * @return The current value of the RXIQVARQ0 field in the RWNXFERXIQSTATVARQ0 register.
 */
__INLINE uint32_t riu_rxiqvarq0_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFERXIQSTATVARQ0_ADDR);
    return (localVal >> 0);
}

#endif // RW_NX_IQ_COMP_EN
/// @}

#if RW_NX_IQ_COMP_EN
/**
 * @name RWNXFERXIQSTATMIQ0 register definitions
 * <table>
 * <caption id="RWNXFERXIQSTATMIQ0_BF">RWNXFERXIQSTATMIQ0 bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>22:00 <td>      RXIQSTATMIQ0 <td>W <td>R <td>0x0
 * </table>
 *
 * @{
 */

/// Address of the RWNXFERXIQSTATMIQ0 register
#define RIU_RWNXFERXIQSTATMIQ0_ADDR   0x4033B248
/// Offset of the RWNXFERXIQSTATMIQ0 register from the base address
#define RIU_RWNXFERXIQSTATMIQ0_OFFSET 0x00000248
/// Index of the RWNXFERXIQSTATMIQ0 register
#define RIU_RWNXFERXIQSTATMIQ0_INDEX  0x00000092
/// Reset value of the RWNXFERXIQSTATMIQ0 register
#define RIU_RWNXFERXIQSTATMIQ0_RESET  0x00000000

/**
 * @brief Returns the current value of the RWNXFERXIQSTATMIQ0 register.
 * The RWNXFERXIQSTATMIQ0 register will be read and its value returned.
 * @return The current value of the RWNXFERXIQSTATMIQ0 register.
 */
__INLINE uint32_t riu_rwnxferxiqstatmiq0_get(void)
{
    return REG_PL_RD(RIU_RWNXFERXIQSTATMIQ0_ADDR);
}

// field definitions
/// RXIQSTATMIQ0 field mask
#define RIU_RXIQSTATMIQ0_MASK   ((uint32_t)0x007FFFFF)
/// RXIQSTATMIQ0 field LSB position
#define RIU_RXIQSTATMIQ0_LSB    0
/// RXIQSTATMIQ0 field width
#define RIU_RXIQSTATMIQ0_WIDTH  ((uint32_t)0x00000017)

/// RXIQSTATMIQ0 field reset value
#define RIU_RXIQSTATMIQ0_RST    0x0

/**
 * @brief Returns the current value of the RXIQSTATMIQ0 field in the RWNXFERXIQSTATMIQ0 register.
 *
 * The RWNXFERXIQSTATMIQ0 register will be read and the RXIQSTATMIQ0 field's value will be returned.
 *
 * @return The current value of the RXIQSTATMIQ0 field in the RWNXFERXIQSTATMIQ0 register.
 */
__INLINE uint32_t riu_rxiqstatmiq0_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFERXIQSTATMIQ0_ADDR);
    return (localVal >> 0);
}

#endif // RW_NX_IQ_COMP_EN
/// @}

#if RW_NX_IQ_COMP_EN
/**
 * @name RWNXFERXIQSTAT0 register definitions
 * <table>
 * <caption id="RWNXFERXIQSTAT0_BF">RWNXFERXIQSTAT0 bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>24:16 <td>    RXIQSTATPHASE0 <td>W <td>R <td>0x0
 * <tr><td>10:00 <td>     RXIQSTATGAIN0 <td>W <td>R <td>0x0
 * </table>
 *
 * @{
 */

/// Address of the RWNXFERXIQSTAT0 register
#define RIU_RWNXFERXIQSTAT0_ADDR   0x4033B24C
/// Offset of the RWNXFERXIQSTAT0 register from the base address
#define RIU_RWNXFERXIQSTAT0_OFFSET 0x0000024C
/// Index of the RWNXFERXIQSTAT0 register
#define RIU_RWNXFERXIQSTAT0_INDEX  0x00000093
/// Reset value of the RWNXFERXIQSTAT0 register
#define RIU_RWNXFERXIQSTAT0_RESET  0x00000000

/**
 * @brief Returns the current value of the RWNXFERXIQSTAT0 register.
 * The RWNXFERXIQSTAT0 register will be read and its value returned.
 * @return The current value of the RWNXFERXIQSTAT0 register.
 */
__INLINE uint32_t riu_rwnxferxiqstat0_get(void)
{
    return REG_PL_RD(RIU_RWNXFERXIQSTAT0_ADDR);
}

// field definitions
/// RXIQSTATPHASE0 field mask
#define RIU_RXIQSTATPHASE0_MASK   ((uint32_t)0x01FF0000)
/// RXIQSTATPHASE0 field LSB position
#define RIU_RXIQSTATPHASE0_LSB    16
/// RXIQSTATPHASE0 field width
#define RIU_RXIQSTATPHASE0_WIDTH  ((uint32_t)0x00000009)
/// RXIQSTATGAIN0 field mask
#define RIU_RXIQSTATGAIN0_MASK    ((uint32_t)0x000007FF)
/// RXIQSTATGAIN0 field LSB position
#define RIU_RXIQSTATGAIN0_LSB     0
/// RXIQSTATGAIN0 field width
#define RIU_RXIQSTATGAIN0_WIDTH   ((uint32_t)0x0000000B)

/// RXIQSTATPHASE0 field reset value
#define RIU_RXIQSTATPHASE0_RST    0x0
/// RXIQSTATGAIN0 field reset value
#define RIU_RXIQSTATGAIN0_RST     0x0

/**
 * @brief Unpacks RWNXFERXIQSTAT0's fields from current value of the RWNXFERXIQSTAT0 register.
 *
 * Reads the RWNXFERXIQSTAT0 register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] rxiqstatphase0 - Will be populated with the current value of this field from the register.
 * @param[out] rxiqstatgain0 - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxferxiqstat0_unpack(uint16_t* rxiqstatphase0, uint16_t* rxiqstatgain0)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFERXIQSTAT0_ADDR);

    *rxiqstatphase0 = (localVal & ((uint32_t)0x01FF0000)) >> 16;
    *rxiqstatgain0 = (localVal & ((uint32_t)0x000007FF)) >> 0;
}

/**
 * @brief Returns the current value of the RXIQSTATPHASE0 field in the RWNXFERXIQSTAT0 register.
 *
 * The RWNXFERXIQSTAT0 register will be read and the RXIQSTATPHASE0 field's value will be returned.
 *
 * @return The current value of the RXIQSTATPHASE0 field in the RWNXFERXIQSTAT0 register.
 */
__INLINE uint16_t riu_rxiqstatphase0_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFERXIQSTAT0_ADDR);
    return ((localVal & ((uint32_t)0x01FF0000)) >> 16);
}

/**
 * @brief Returns the current value of the RXIQSTATGAIN0 field in the RWNXFERXIQSTAT0 register.
 *
 * The RWNXFERXIQSTAT0 register will be read and the RXIQSTATGAIN0 field's value will be returned.
 *
 * @return The current value of the RXIQSTATGAIN0 field in the RWNXFERXIQSTAT0 register.
 */
__INLINE uint16_t riu_rxiqstatgain0_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFERXIQSTAT0_ADDR);
    return ((localVal & ((uint32_t)0x000007FF)) >> 0);
}

#endif // RW_NX_IQ_COMP_EN
/// @}

#if RW_NX_IQ_COMP_EN
/**
 * @name RWNXFERXIQSTATVARI1 register definitions
 * <table>
 * <caption id="RWNXFERXIQSTATVARI1_BF">RWNXFERXIQSTATVARI1 bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>21:00 <td>         RXIQVARI1 <td>W <td>R <td>0x0
 * </table>
 *
 * @{
 */

/// Address of the RWNXFERXIQSTATVARI1 register
#define RIU_RWNXFERXIQSTATVARI1_ADDR   0x4033B250
/// Offset of the RWNXFERXIQSTATVARI1 register from the base address
#define RIU_RWNXFERXIQSTATVARI1_OFFSET 0x00000250
/// Index of the RWNXFERXIQSTATVARI1 register
#define RIU_RWNXFERXIQSTATVARI1_INDEX  0x00000094
/// Reset value of the RWNXFERXIQSTATVARI1 register
#define RIU_RWNXFERXIQSTATVARI1_RESET  0x00000000

/**
 * @brief Returns the current value of the RWNXFERXIQSTATVARI1 register.
 * The RWNXFERXIQSTATVARI1 register will be read and its value returned.
 * @return The current value of the RWNXFERXIQSTATVARI1 register.
 */
__INLINE uint32_t riu_rwnxferxiqstatvari1_get(void)
{
    return REG_PL_RD(RIU_RWNXFERXIQSTATVARI1_ADDR);
}

// field definitions
/// RXIQVARI1 field mask
#define RIU_RXIQVARI1_MASK   ((uint32_t)0x003FFFFF)
/// RXIQVARI1 field LSB position
#define RIU_RXIQVARI1_LSB    0
/// RXIQVARI1 field width
#define RIU_RXIQVARI1_WIDTH  ((uint32_t)0x00000016)

/// RXIQVARI1 field reset value
#define RIU_RXIQVARI1_RST    0x0

/**
 * @brief Returns the current value of the RXIQVARI1 field in the RWNXFERXIQSTATVARI1 register.
 *
 * The RWNXFERXIQSTATVARI1 register will be read and the RXIQVARI1 field's value will be returned.
 *
 * @return The current value of the RXIQVARI1 field in the RWNXFERXIQSTATVARI1 register.
 */
__INLINE uint32_t riu_rxiqvari1_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFERXIQSTATVARI1_ADDR);
    return (localVal >> 0);
}

#endif // RW_NX_IQ_COMP_EN
/// @}

#if RW_NX_IQ_COMP_EN
/**
 * @name RWNXFERXIQSTATVARQ1 register definitions
 * <table>
 * <caption id="RWNXFERXIQSTATVARQ1_BF">RWNXFERXIQSTATVARQ1 bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>21:00 <td>         RXIQVARQ1 <td>W <td>R <td>0x0
 * </table>
 *
 * @{
 */

/// Address of the RWNXFERXIQSTATVARQ1 register
#define RIU_RWNXFERXIQSTATVARQ1_ADDR   0x4033B254
/// Offset of the RWNXFERXIQSTATVARQ1 register from the base address
#define RIU_RWNXFERXIQSTATVARQ1_OFFSET 0x00000254
/// Index of the RWNXFERXIQSTATVARQ1 register
#define RIU_RWNXFERXIQSTATVARQ1_INDEX  0x00000095
/// Reset value of the RWNXFERXIQSTATVARQ1 register
#define RIU_RWNXFERXIQSTATVARQ1_RESET  0x00000000

/**
 * @brief Returns the current value of the RWNXFERXIQSTATVARQ1 register.
 * The RWNXFERXIQSTATVARQ1 register will be read and its value returned.
 * @return The current value of the RWNXFERXIQSTATVARQ1 register.
 */
__INLINE uint32_t riu_rwnxferxiqstatvarq1_get(void)
{
    return REG_PL_RD(RIU_RWNXFERXIQSTATVARQ1_ADDR);
}

// field definitions
/// RXIQVARQ1 field mask
#define RIU_RXIQVARQ1_MASK   ((uint32_t)0x003FFFFF)
/// RXIQVARQ1 field LSB position
#define RIU_RXIQVARQ1_LSB    0
/// RXIQVARQ1 field width
#define RIU_RXIQVARQ1_WIDTH  ((uint32_t)0x00000016)

/// RXIQVARQ1 field reset value
#define RIU_RXIQVARQ1_RST    0x0

/**
 * @brief Returns the current value of the RXIQVARQ1 field in the RWNXFERXIQSTATVARQ1 register.
 *
 * The RWNXFERXIQSTATVARQ1 register will be read and the RXIQVARQ1 field's value will be returned.
 *
 * @return The current value of the RXIQVARQ1 field in the RWNXFERXIQSTATVARQ1 register.
 */
__INLINE uint32_t riu_rxiqvarq1_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFERXIQSTATVARQ1_ADDR);
    return (localVal >> 0);
}

#endif // RW_NX_IQ_COMP_EN
/// @}

#if RW_NX_IQ_COMP_EN
/**
 * @name RWNXFERXIQSTATMIQ1 register definitions
 * <table>
 * <caption id="RWNXFERXIQSTATMIQ1_BF">RWNXFERXIQSTATMIQ1 bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>22:00 <td>      RXIQSTATMIQ1 <td>W <td>R <td>0x0
 * </table>
 *
 * @{
 */

/// Address of the RWNXFERXIQSTATMIQ1 register
#define RIU_RWNXFERXIQSTATMIQ1_ADDR   0x4033B258
/// Offset of the RWNXFERXIQSTATMIQ1 register from the base address
#define RIU_RWNXFERXIQSTATMIQ1_OFFSET 0x00000258
/// Index of the RWNXFERXIQSTATMIQ1 register
#define RIU_RWNXFERXIQSTATMIQ1_INDEX  0x00000096
/// Reset value of the RWNXFERXIQSTATMIQ1 register
#define RIU_RWNXFERXIQSTATMIQ1_RESET  0x00000000

/**
 * @brief Returns the current value of the RWNXFERXIQSTATMIQ1 register.
 * The RWNXFERXIQSTATMIQ1 register will be read and its value returned.
 * @return The current value of the RWNXFERXIQSTATMIQ1 register.
 */
__INLINE uint32_t riu_rwnxferxiqstatmiq1_get(void)
{
    return REG_PL_RD(RIU_RWNXFERXIQSTATMIQ1_ADDR);
}

// field definitions
/// RXIQSTATMIQ1 field mask
#define RIU_RXIQSTATMIQ1_MASK   ((uint32_t)0x007FFFFF)
/// RXIQSTATMIQ1 field LSB position
#define RIU_RXIQSTATMIQ1_LSB    0
/// RXIQSTATMIQ1 field width
#define RIU_RXIQSTATMIQ1_WIDTH  ((uint32_t)0x00000017)

/// RXIQSTATMIQ1 field reset value
#define RIU_RXIQSTATMIQ1_RST    0x0

/**
 * @brief Returns the current value of the RXIQSTATMIQ1 field in the RWNXFERXIQSTATMIQ1 register.
 *
 * The RWNXFERXIQSTATMIQ1 register will be read and the RXIQSTATMIQ1 field's value will be returned.
 *
 * @return The current value of the RXIQSTATMIQ1 field in the RWNXFERXIQSTATMIQ1 register.
 */
__INLINE uint32_t riu_rxiqstatmiq1_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFERXIQSTATMIQ1_ADDR);
    return (localVal >> 0);
}

#endif // RW_NX_IQ_COMP_EN
/// @}

#if RW_NX_IQ_COMP_EN
/**
 * @name RWNXFERXIQSTAT1 register definitions
 * <table>
 * <caption id="RWNXFERXIQSTAT1_BF">RWNXFERXIQSTAT1 bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>24:16 <td>    RXIQSTATPHASE1 <td>W <td>R <td>0x0
 * <tr><td>10:00 <td>     RXIQSTATGAIN1 <td>W <td>R <td>0x0
 * </table>
 *
 * @{
 */

/// Address of the RWNXFERXIQSTAT1 register
#define RIU_RWNXFERXIQSTAT1_ADDR   0x4033B25C
/// Offset of the RWNXFERXIQSTAT1 register from the base address
#define RIU_RWNXFERXIQSTAT1_OFFSET 0x0000025C
/// Index of the RWNXFERXIQSTAT1 register
#define RIU_RWNXFERXIQSTAT1_INDEX  0x00000097
/// Reset value of the RWNXFERXIQSTAT1 register
#define RIU_RWNXFERXIQSTAT1_RESET  0x00000000

/**
 * @brief Returns the current value of the RWNXFERXIQSTAT1 register.
 * The RWNXFERXIQSTAT1 register will be read and its value returned.
 * @return The current value of the RWNXFERXIQSTAT1 register.
 */
__INLINE uint32_t riu_rwnxferxiqstat1_get(void)
{
    return REG_PL_RD(RIU_RWNXFERXIQSTAT1_ADDR);
}

// field definitions
/// RXIQSTATPHASE1 field mask
#define RIU_RXIQSTATPHASE1_MASK   ((uint32_t)0x01FF0000)
/// RXIQSTATPHASE1 field LSB position
#define RIU_RXIQSTATPHASE1_LSB    16
/// RXIQSTATPHASE1 field width
#define RIU_RXIQSTATPHASE1_WIDTH  ((uint32_t)0x00000009)
/// RXIQSTATGAIN1 field mask
#define RIU_RXIQSTATGAIN1_MASK    ((uint32_t)0x000007FF)
/// RXIQSTATGAIN1 field LSB position
#define RIU_RXIQSTATGAIN1_LSB     0
/// RXIQSTATGAIN1 field width
#define RIU_RXIQSTATGAIN1_WIDTH   ((uint32_t)0x0000000B)

/// RXIQSTATPHASE1 field reset value
#define RIU_RXIQSTATPHASE1_RST    0x0
/// RXIQSTATGAIN1 field reset value
#define RIU_RXIQSTATGAIN1_RST     0x0

/**
 * @brief Unpacks RWNXFERXIQSTAT1's fields from current value of the RWNXFERXIQSTAT1 register.
 *
 * Reads the RWNXFERXIQSTAT1 register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] rxiqstatphase1 - Will be populated with the current value of this field from the register.
 * @param[out] rxiqstatgain1 - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxferxiqstat1_unpack(uint16_t* rxiqstatphase1, uint16_t* rxiqstatgain1)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFERXIQSTAT1_ADDR);

    *rxiqstatphase1 = (localVal & ((uint32_t)0x01FF0000)) >> 16;
    *rxiqstatgain1 = (localVal & ((uint32_t)0x000007FF)) >> 0;
}

/**
 * @brief Returns the current value of the RXIQSTATPHASE1 field in the RWNXFERXIQSTAT1 register.
 *
 * The RWNXFERXIQSTAT1 register will be read and the RXIQSTATPHASE1 field's value will be returned.
 *
 * @return The current value of the RXIQSTATPHASE1 field in the RWNXFERXIQSTAT1 register.
 */
__INLINE uint16_t riu_rxiqstatphase1_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFERXIQSTAT1_ADDR);
    return ((localVal & ((uint32_t)0x01FF0000)) >> 16);
}

/**
 * @brief Returns the current value of the RXIQSTATGAIN1 field in the RWNXFERXIQSTAT1 register.
 *
 * The RWNXFERXIQSTAT1 register will be read and the RXIQSTATGAIN1 field's value will be returned.
 *
 * @return The current value of the RXIQSTATGAIN1 field in the RWNXFERXIQSTAT1 register.
 */
__INLINE uint16_t riu_rxiqstatgain1_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFERXIQSTAT1_ADDR);
    return ((localVal & ((uint32_t)0x000007FF)) >> 0);
}

#endif // RW_NX_IQ_COMP_EN
/// @}

#if RW_NX_FIQ_COMP_EN
/**
 * @name RWNXFEFIQDONE register definitions
 * <table>
 * <caption id="RWNXFEFIQDONE_BF">RWNXFEFIQDONE bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>16 <td>        FIQESTDONE <td>W <td>R <td>1
 * <tr><td>00 <td>       FIQCOLLDONE <td>W <td>R <td>1
 * </table>
 *
 * @{
 */

/// Address of the RWNXFEFIQDONE register
#define RIU_RWNXFEFIQDONE_ADDR   0x4033B260
/// Offset of the RWNXFEFIQDONE register from the base address
#define RIU_RWNXFEFIQDONE_OFFSET 0x00000260
/// Index of the RWNXFEFIQDONE register
#define RIU_RWNXFEFIQDONE_INDEX  0x00000098
/// Reset value of the RWNXFEFIQDONE register
#define RIU_RWNXFEFIQDONE_RESET  0x00010001

/**
 * @brief Returns the current value of the RWNXFEFIQDONE register.
 * The RWNXFEFIQDONE register will be read and its value returned.
 * @return The current value of the RWNXFEFIQDONE register.
 */
__INLINE uint32_t riu_rwnxfefiqdone_get(void)
{
    return REG_PL_RD(RIU_RWNXFEFIQDONE_ADDR);
}

// field definitions
/// FIQESTDONE field bit
#define RIU_FIQESTDONE_BIT     ((uint32_t)0x00010000)
/// FIQESTDONE field position
#define RIU_FIQESTDONE_POS     16
/// FIQCOLLDONE field bit
#define RIU_FIQCOLLDONE_BIT    ((uint32_t)0x00000001)
/// FIQCOLLDONE field position
#define RIU_FIQCOLLDONE_POS    0

/// FIQESTDONE field reset value
#define RIU_FIQESTDONE_RST     0x1
/// FIQCOLLDONE field reset value
#define RIU_FIQCOLLDONE_RST    0x1

/**
 * @brief Unpacks RWNXFEFIQDONE's fields from current value of the RWNXFEFIQDONE register.
 *
 * Reads the RWNXFEFIQDONE register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] fiqestdone - Will be populated with the current value of this field from the register.
 * @param[out] fiqcolldone - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxfefiqdone_unpack(uint8_t* fiqestdone, uint8_t* fiqcolldone)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFEFIQDONE_ADDR);

    *fiqestdone = (localVal & ((uint32_t)0x00010000)) >> 16;
    *fiqcolldone = (localVal & ((uint32_t)0x00000001)) >> 0;
}

/**
 * @brief Returns the current value of the FIQESTDONE field in the RWNXFEFIQDONE register.
 *
 * The RWNXFEFIQDONE register will be read and the FIQESTDONE field's value will be returned.
 *
 * @return The current value of the FIQESTDONE field in the RWNXFEFIQDONE register.
 */
__INLINE uint8_t riu_fiqestdone_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFEFIQDONE_ADDR);
    return ((localVal & ((uint32_t)0x00010000)) >> 16);
}

/**
 * @brief Returns the current value of the FIQCOLLDONE field in the RWNXFEFIQDONE register.
 *
 * The RWNXFEFIQDONE register will be read and the FIQCOLLDONE field's value will be returned.
 *
 * @return The current value of the FIQCOLLDONE field in the RWNXFEFIQDONE register.
 */
__INLINE uint8_t riu_fiqcolldone_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFEFIQDONE_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}

#endif // RW_NX_FIQ_COMP_EN
/// @}

#if RW_NX_FIQ_COMP_EN
/**
 * @name RWNXFEFIQSTAT0 register definitions
 * <table>
 * <caption id="RWNXFEFIQSTAT0_BF">RWNXFEFIQSTAT0 bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>28:16 <td>    FIQTXESTERROR0 <td>W <td>R <td>0x0
 * <tr><td>12:00 <td>    FIQRXESTERROR0 <td>W <td>R <td>0x0
 * </table>
 *
 * @{
 */

/// Address of the RWNXFEFIQSTAT0 register
#define RIU_RWNXFEFIQSTAT0_ADDR   0x4033B264
/// Offset of the RWNXFEFIQSTAT0 register from the base address
#define RIU_RWNXFEFIQSTAT0_OFFSET 0x00000264
/// Index of the RWNXFEFIQSTAT0 register
#define RIU_RWNXFEFIQSTAT0_INDEX  0x00000099
/// Reset value of the RWNXFEFIQSTAT0 register
#define RIU_RWNXFEFIQSTAT0_RESET  0x00000000

/**
 * @brief Returns the current value of the RWNXFEFIQSTAT0 register.
 * The RWNXFEFIQSTAT0 register will be read and its value returned.
 * @return The current value of the RWNXFEFIQSTAT0 register.
 */
__INLINE uint32_t riu_rwnxfefiqstat0_get(void)
{
    return REG_PL_RD(RIU_RWNXFEFIQSTAT0_ADDR);
}

// field definitions
/// FIQTXESTERROR0 field mask
#define RIU_FIQTXESTERROR0_MASK   ((uint32_t)0x1FFF0000)
/// FIQTXESTERROR0 field LSB position
#define RIU_FIQTXESTERROR0_LSB    16
/// FIQTXESTERROR0 field width
#define RIU_FIQTXESTERROR0_WIDTH  ((uint32_t)0x0000000D)
/// FIQRXESTERROR0 field mask
#define RIU_FIQRXESTERROR0_MASK   ((uint32_t)0x00001FFF)
/// FIQRXESTERROR0 field LSB position
#define RIU_FIQRXESTERROR0_LSB    0
/// FIQRXESTERROR0 field width
#define RIU_FIQRXESTERROR0_WIDTH  ((uint32_t)0x0000000D)

/// FIQTXESTERROR0 field reset value
#define RIU_FIQTXESTERROR0_RST    0x0
/// FIQRXESTERROR0 field reset value
#define RIU_FIQRXESTERROR0_RST    0x0

/**
 * @brief Unpacks RWNXFEFIQSTAT0's fields from current value of the RWNXFEFIQSTAT0 register.
 *
 * Reads the RWNXFEFIQSTAT0 register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] fiqtxesterror0 - Will be populated with the current value of this field from the register.
 * @param[out] fiqrxesterror0 - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxfefiqstat0_unpack(uint16_t* fiqtxesterror0, uint16_t* fiqrxesterror0)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFEFIQSTAT0_ADDR);

    *fiqtxesterror0 = (localVal & ((uint32_t)0x1FFF0000)) >> 16;
    *fiqrxesterror0 = (localVal & ((uint32_t)0x00001FFF)) >> 0;
}

/**
 * @brief Returns the current value of the FIQTXESTERROR0 field in the RWNXFEFIQSTAT0 register.
 *
 * The RWNXFEFIQSTAT0 register will be read and the FIQTXESTERROR0 field's value will be returned.
 *
 * @return The current value of the FIQTXESTERROR0 field in the RWNXFEFIQSTAT0 register.
 */
__INLINE uint16_t riu_fiqtxesterror0_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFEFIQSTAT0_ADDR);
    return ((localVal & ((uint32_t)0x1FFF0000)) >> 16);
}

/**
 * @brief Returns the current value of the FIQRXESTERROR0 field in the RWNXFEFIQSTAT0 register.
 *
 * The RWNXFEFIQSTAT0 register will be read and the FIQRXESTERROR0 field's value will be returned.
 *
 * @return The current value of the FIQRXESTERROR0 field in the RWNXFEFIQSTAT0 register.
 */
__INLINE uint16_t riu_fiqrxesterror0_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFEFIQSTAT0_ADDR);
    return ((localVal & ((uint32_t)0x00001FFF)) >> 0);
}

#endif // RW_NX_FIQ_COMP_EN
/// @}

#if RW_NX_FIQ_COMP_EN
/**
 * @name RWNXFEFIQSTAT1 register definitions
 * <table>
 * <caption id="RWNXFEFIQSTAT1_BF">RWNXFEFIQSTAT1 bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>28:16 <td>    FIQTXESTERROR1 <td>W <td>R <td>0x0
 * <tr><td>12:00 <td>    FIQRXESTERROR1 <td>W <td>R <td>0x0
 * </table>
 *
 * @{
 */

/// Address of the RWNXFEFIQSTAT1 register
#define RIU_RWNXFEFIQSTAT1_ADDR   0x4033B268
/// Offset of the RWNXFEFIQSTAT1 register from the base address
#define RIU_RWNXFEFIQSTAT1_OFFSET 0x00000268
/// Index of the RWNXFEFIQSTAT1 register
#define RIU_RWNXFEFIQSTAT1_INDEX  0x0000009A
/// Reset value of the RWNXFEFIQSTAT1 register
#define RIU_RWNXFEFIQSTAT1_RESET  0x00000000

/**
 * @brief Returns the current value of the RWNXFEFIQSTAT1 register.
 * The RWNXFEFIQSTAT1 register will be read and its value returned.
 * @return The current value of the RWNXFEFIQSTAT1 register.
 */
__INLINE uint32_t riu_rwnxfefiqstat1_get(void)
{
    return REG_PL_RD(RIU_RWNXFEFIQSTAT1_ADDR);
}

// field definitions
/// FIQTXESTERROR1 field mask
#define RIU_FIQTXESTERROR1_MASK   ((uint32_t)0x1FFF0000)
/// FIQTXESTERROR1 field LSB position
#define RIU_FIQTXESTERROR1_LSB    16
/// FIQTXESTERROR1 field width
#define RIU_FIQTXESTERROR1_WIDTH  ((uint32_t)0x0000000D)
/// FIQRXESTERROR1 field mask
#define RIU_FIQRXESTERROR1_MASK   ((uint32_t)0x00001FFF)
/// FIQRXESTERROR1 field LSB position
#define RIU_FIQRXESTERROR1_LSB    0
/// FIQRXESTERROR1 field width
#define RIU_FIQRXESTERROR1_WIDTH  ((uint32_t)0x0000000D)

/// FIQTXESTERROR1 field reset value
#define RIU_FIQTXESTERROR1_RST    0x0
/// FIQRXESTERROR1 field reset value
#define RIU_FIQRXESTERROR1_RST    0x0

/**
 * @brief Unpacks RWNXFEFIQSTAT1's fields from current value of the RWNXFEFIQSTAT1 register.
 *
 * Reads the RWNXFEFIQSTAT1 register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] fiqtxesterror1 - Will be populated with the current value of this field from the register.
 * @param[out] fiqrxesterror1 - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxfefiqstat1_unpack(uint16_t* fiqtxesterror1, uint16_t* fiqrxesterror1)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFEFIQSTAT1_ADDR);

    *fiqtxesterror1 = (localVal & ((uint32_t)0x1FFF0000)) >> 16;
    *fiqrxesterror1 = (localVal & ((uint32_t)0x00001FFF)) >> 0;
}

/**
 * @brief Returns the current value of the FIQTXESTERROR1 field in the RWNXFEFIQSTAT1 register.
 *
 * The RWNXFEFIQSTAT1 register will be read and the FIQTXESTERROR1 field's value will be returned.
 *
 * @return The current value of the FIQTXESTERROR1 field in the RWNXFEFIQSTAT1 register.
 */
__INLINE uint16_t riu_fiqtxesterror1_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFEFIQSTAT1_ADDR);
    return ((localVal & ((uint32_t)0x1FFF0000)) >> 16);
}

/**
 * @brief Returns the current value of the FIQRXESTERROR1 field in the RWNXFEFIQSTAT1 register.
 *
 * The RWNXFEFIQSTAT1 register will be read and the FIQRXESTERROR1 field's value will be returned.
 *
 * @return The current value of the FIQRXESTERROR1 field in the RWNXFEFIQSTAT1 register.
 */
__INLINE uint16_t riu_fiqrxesterror1_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFEFIQSTAT1_ADDR);
    return ((localVal & ((uint32_t)0x00001FFF)) >> 0);
}

#endif // RW_NX_FIQ_COMP_EN
/// @}

#if RW_NX_FIQ_COMP_EN
/**
 * @name RWNXFEFIQSTATCOEFF register definitions
 * <table>
 * <caption id="RWNXFEFIQSTATCOEFF_BF">RWNXFEFIQSTATCOEFF bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>15:00 <td>      FIQSTATCOEFF <td>W <td>R <td>0x0
 * </table>
 *
 * @{
 */

/// Address of the RWNXFEFIQSTATCOEFF register
#define RIU_RWNXFEFIQSTATCOEFF_ADDR   0x4033B26C
/// Offset of the RWNXFEFIQSTATCOEFF register from the base address
#define RIU_RWNXFEFIQSTATCOEFF_OFFSET 0x0000026C
/// Index of the RWNXFEFIQSTATCOEFF register
#define RIU_RWNXFEFIQSTATCOEFF_INDEX  0x0000009B
/// Reset value of the RWNXFEFIQSTATCOEFF register
#define RIU_RWNXFEFIQSTATCOEFF_RESET  0x00000000
/// Number of elements of the RWNXFEFIQSTATCOEFF register array
#define RIU_RWNXFEFIQSTATCOEFF_COUNT  20

/**
 * @brief Returns the current value of the RWNXFEFIQSTATCOEFF register.
 * The RWNXFEFIQSTATCOEFF register will be read and its value returned.
 * @param[in] reg_idx Index of the register
 * @return The current value of the RWNXFEFIQSTATCOEFF register.
 */
__INLINE uint32_t riu_rwnxfefiqstatcoeff_get(int reg_idx)
{
    return REG_PL_RD(RIU_RWNXFEFIQSTATCOEFF_ADDR + reg_idx * 4);
}

// field definitions
/// FIQSTATCOEFF field mask
#define RIU_FIQSTATCOEFF_MASK   ((uint32_t)0x0000FFFF)
/// FIQSTATCOEFF field LSB position
#define RIU_FIQSTATCOEFF_LSB    0
/// FIQSTATCOEFF field width
#define RIU_FIQSTATCOEFF_WIDTH  ((uint32_t)0x00000010)

/// FIQSTATCOEFF field reset value
#define RIU_FIQSTATCOEFF_RST    0x0

/**
 * @brief Returns the current value of the FIQSTATCOEFF field in the RWNXFEFIQSTATCOEFF register.
 *
 * The RWNXFEFIQSTATCOEFF register will be read and the FIQSTATCOEFF field's value will be returned.
 *
 * @param[in] reg_idx Index of the register
 * @return The current value of the FIQSTATCOEFF field in the RWNXFEFIQSTATCOEFF register.
 */
__INLINE uint16_t riu_fiqstatcoeff_getf(int reg_idx)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFEFIQSTATCOEFF_ADDR + reg_idx * 4);
    return (localVal >> 0);
}

#endif // RW_NX_FIQ_COMP_EN
/// @}

/**
 * @name RWNXAGCANTLOSS register definitions
 * <table>
 * <caption id="RWNXAGCANTLOSS_BF">RWNXAGCANTLOSS bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>11:08 <td>      RFLOSSANT1DB <td>R <td>R/W <td>0x0
 * <tr><td>03:00 <td>      RFLOSSANT0DB <td>R <td>R/W <td>0x0
 * </table>
 *
 * @{
 */

/// Address of the RWNXAGCANTLOSS register
#define RIU_RWNXAGCANTLOSS_ADDR   0x4033B300
/// Offset of the RWNXAGCANTLOSS register from the base address
#define RIU_RWNXAGCANTLOSS_OFFSET 0x00000300
/// Index of the RWNXAGCANTLOSS register
#define RIU_RWNXAGCANTLOSS_INDEX  0x000000C0
/// Reset value of the RWNXAGCANTLOSS register
#define RIU_RWNXAGCANTLOSS_RESET  0x00000000

/**
 * @brief Returns the current value of the RWNXAGCANTLOSS register.
 * The RWNXAGCANTLOSS register will be read and its value returned.
 * @return The current value of the RWNXAGCANTLOSS register.
 */
__INLINE uint32_t riu_rwnxagcantloss_get(void)
{
    return REG_PL_RD(RIU_RWNXAGCANTLOSS_ADDR);
}

/**
 * @brief Sets the RWNXAGCANTLOSS register to a value.
 * The RWNXAGCANTLOSS register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxagcantloss_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXAGCANTLOSS_ADDR, value);
}

// field definitions
/// RFLOSSANT1DB field mask
#define RIU_RFLOSSANT1DB_MASK   ((uint32_t)0x00000F00)
/// RFLOSSANT1DB field LSB position
#define RIU_RFLOSSANT1DB_LSB    8
/// RFLOSSANT1DB field width
#define RIU_RFLOSSANT1DB_WIDTH  ((uint32_t)0x00000004)
/// RFLOSSANT0DB field mask
#define RIU_RFLOSSANT0DB_MASK   ((uint32_t)0x0000000F)
/// RFLOSSANT0DB field LSB position
#define RIU_RFLOSSANT0DB_LSB    0
/// RFLOSSANT0DB field width
#define RIU_RFLOSSANT0DB_WIDTH  ((uint32_t)0x00000004)

/// RFLOSSANT1DB field reset value
#define RIU_RFLOSSANT1DB_RST    0x0
/// RFLOSSANT0DB field reset value
#define RIU_RFLOSSANT0DB_RST    0x0

/**
 * @brief Constructs a value for the RWNXAGCANTLOSS register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] rflossant1db - The value to use for the RFLOSSANT1DB field.
 * @param[in] rflossant0db - The value to use for the RFLOSSANT0DB field.
 */
__INLINE void riu_rwnxagcantloss_pack(uint8_t rflossant1db, uint8_t rflossant0db)
{
    REG_PL_WR(RIU_RWNXAGCANTLOSS_ADDR,  ((uint32_t)rflossant1db << 8) | ((uint32_t)rflossant0db << 0));
}

/**
 * @brief Unpacks RWNXAGCANTLOSS's fields from current value of the RWNXAGCANTLOSS register.
 *
 * Reads the RWNXAGCANTLOSS register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] rflossant1db - Will be populated with the current value of this field from the register.
 * @param[out] rflossant0db - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxagcantloss_unpack(uint8_t* rflossant1db, uint8_t* rflossant0db)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCANTLOSS_ADDR);

    *rflossant1db = (localVal & ((uint32_t)0x00000F00)) >> 8;
    *rflossant0db = (localVal & ((uint32_t)0x0000000F)) >> 0;
}

/**
 * @brief Returns the current value of the RFLOSSANT1DB field in the RWNXAGCANTLOSS register.
 *
 * The RWNXAGCANTLOSS register will be read and the RFLOSSANT1DB field's value will be returned.
 *
 * @return The current value of the RFLOSSANT1DB field in the RWNXAGCANTLOSS register.
 */
__INLINE uint8_t riu_rflossant1db_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCANTLOSS_ADDR);
    return ((localVal & ((uint32_t)0x00000F00)) >> 8);
}

/**
 * @brief Sets the RFLOSSANT1DB field of the RWNXAGCANTLOSS register.
 *
 * The RWNXAGCANTLOSS register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rflossant1db - The value to set the field to.
 */
__INLINE void riu_rflossant1db_setf(uint8_t rflossant1db)
{
    REG_PL_WR(RIU_RWNXAGCANTLOSS_ADDR, (REG_PL_RD(RIU_RWNXAGCANTLOSS_ADDR) & ~((uint32_t)0x00000F00)) | ((uint32_t)rflossant1db << 8));
}

/**
 * @brief Returns the current value of the RFLOSSANT0DB field in the RWNXAGCANTLOSS register.
 *
 * The RWNXAGCANTLOSS register will be read and the RFLOSSANT0DB field's value will be returned.
 *
 * @return The current value of the RFLOSSANT0DB field in the RWNXAGCANTLOSS register.
 */
__INLINE uint8_t riu_rflossant0db_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCANTLOSS_ADDR);
    return ((localVal & ((uint32_t)0x0000000F)) >> 0);
}

/**
 * @brief Sets the RFLOSSANT0DB field of the RWNXAGCANTLOSS register.
 *
 * The RWNXAGCANTLOSS register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rflossant0db - The value to set the field to.
 */
__INLINE void riu_rflossant0db_setf(uint8_t rflossant0db)
{
    REG_PL_WR(RIU_RWNXAGCANTLOSS_ADDR, (REG_PL_RD(RIU_RWNXAGCANTLOSS_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)rflossant0db << 0));
}

/// @}

/**
 * @name RWNXAGCGAINRANGE register definitions
 * <table>
 * <caption id="RWNXAGCGAINRANGE_BF">RWNXAGCGAINRANGE bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>30:24 <td>   RFGAINMAX4DETDB <td>R <td>R/W <td>0x42
 * <tr><td>22:16 <td>   RFGAINMIN4DETDB <td>R <td>R/W <td>0x0
 * <tr><td>14:08 <td>       RFGAINMAXDB <td>R <td>R/W <td>0x42
 * <tr><td>06:00 <td>       RFGAINMINDB <td>R <td>R/W <td>0x0
 * </table>
 *
 * @{
 */

/// Address of the RWNXAGCGAINRANGE register
#define RIU_RWNXAGCGAINRANGE_ADDR   0x4033B304
/// Offset of the RWNXAGCGAINRANGE register from the base address
#define RIU_RWNXAGCGAINRANGE_OFFSET 0x00000304
/// Index of the RWNXAGCGAINRANGE register
#define RIU_RWNXAGCGAINRANGE_INDEX  0x000000C1
/// Reset value of the RWNXAGCGAINRANGE register
#define RIU_RWNXAGCGAINRANGE_RESET  0x42004200

/**
 * @brief Returns the current value of the RWNXAGCGAINRANGE register.
 * The RWNXAGCGAINRANGE register will be read and its value returned.
 * @return The current value of the RWNXAGCGAINRANGE register.
 */
__INLINE uint32_t riu_rwnxagcgainrange_get(void)
{
    return REG_PL_RD(RIU_RWNXAGCGAINRANGE_ADDR);
}

/**
 * @brief Sets the RWNXAGCGAINRANGE register to a value.
 * The RWNXAGCGAINRANGE register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxagcgainrange_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXAGCGAINRANGE_ADDR, value);
}

// field definitions
/// RFGAINMAX4DETDB field mask
#define RIU_RFGAINMAX4DETDB_MASK   ((uint32_t)0x7F000000)
/// RFGAINMAX4DETDB field LSB position
#define RIU_RFGAINMAX4DETDB_LSB    24
/// RFGAINMAX4DETDB field width
#define RIU_RFGAINMAX4DETDB_WIDTH  ((uint32_t)0x00000007)
/// RFGAINMIN4DETDB field mask
#define RIU_RFGAINMIN4DETDB_MASK   ((uint32_t)0x007F0000)
/// RFGAINMIN4DETDB field LSB position
#define RIU_RFGAINMIN4DETDB_LSB    16
/// RFGAINMIN4DETDB field width
#define RIU_RFGAINMIN4DETDB_WIDTH  ((uint32_t)0x00000007)
/// RFGAINMAXDB field mask
#define RIU_RFGAINMAXDB_MASK       ((uint32_t)0x00007F00)
/// RFGAINMAXDB field LSB position
#define RIU_RFGAINMAXDB_LSB        8
/// RFGAINMAXDB field width
#define RIU_RFGAINMAXDB_WIDTH      ((uint32_t)0x00000007)
/// RFGAINMINDB field mask
#define RIU_RFGAINMINDB_MASK       ((uint32_t)0x0000007F)
/// RFGAINMINDB field LSB position
#define RIU_RFGAINMINDB_LSB        0
/// RFGAINMINDB field width
#define RIU_RFGAINMINDB_WIDTH      ((uint32_t)0x00000007)

/// RFGAINMAX4DETDB field reset value
#define RIU_RFGAINMAX4DETDB_RST    0x42
/// RFGAINMIN4DETDB field reset value
#define RIU_RFGAINMIN4DETDB_RST    0x0
/// RFGAINMAXDB field reset value
#define RIU_RFGAINMAXDB_RST        0x42
/// RFGAINMINDB field reset value
#define RIU_RFGAINMINDB_RST        0x0

/**
 * @brief Constructs a value for the RWNXAGCGAINRANGE register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] rfgainmax4detdb - The value to use for the RFGAINMAX4DETDB field.
 * @param[in] rfgainmin4detdb - The value to use for the RFGAINMIN4DETDB field.
 * @param[in] rfgainmaxdb - The value to use for the RFGAINMAXDB field.
 * @param[in] rfgainmindb - The value to use for the RFGAINMINDB field.
 */
__INLINE void riu_rwnxagcgainrange_pack(uint8_t rfgainmax4detdb, uint8_t rfgainmin4detdb, uint8_t rfgainmaxdb, uint8_t rfgainmindb)
{
    REG_PL_WR(RIU_RWNXAGCGAINRANGE_ADDR,  ((uint32_t)rfgainmax4detdb << 24) | ((uint32_t)rfgainmin4detdb << 16) | ((uint32_t)rfgainmaxdb << 8) | ((uint32_t)rfgainmindb << 0));
}

/**
 * @brief Unpacks RWNXAGCGAINRANGE's fields from current value of the RWNXAGCGAINRANGE register.
 *
 * Reads the RWNXAGCGAINRANGE register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] rfgainmax4detdb - Will be populated with the current value of this field from the register.
 * @param[out] rfgainmin4detdb - Will be populated with the current value of this field from the register.
 * @param[out] rfgainmaxdb - Will be populated with the current value of this field from the register.
 * @param[out] rfgainmindb - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxagcgainrange_unpack(uint8_t* rfgainmax4detdb, uint8_t* rfgainmin4detdb, uint8_t* rfgainmaxdb, uint8_t* rfgainmindb)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCGAINRANGE_ADDR);

    *rfgainmax4detdb = (localVal & ((uint32_t)0x7F000000)) >> 24;
    *rfgainmin4detdb = (localVal & ((uint32_t)0x007F0000)) >> 16;
    *rfgainmaxdb = (localVal & ((uint32_t)0x00007F00)) >> 8;
    *rfgainmindb = (localVal & ((uint32_t)0x0000007F)) >> 0;
}

/**
 * @brief Returns the current value of the RFGAINMAX4DETDB field in the RWNXAGCGAINRANGE register.
 *
 * The RWNXAGCGAINRANGE register will be read and the RFGAINMAX4DETDB field's value will be returned.
 *
 * @return The current value of the RFGAINMAX4DETDB field in the RWNXAGCGAINRANGE register.
 */
__INLINE uint8_t riu_rfgainmax4detdb_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCGAINRANGE_ADDR);
    return ((localVal & ((uint32_t)0x7F000000)) >> 24);
}

/**
 * @brief Sets the RFGAINMAX4DETDB field of the RWNXAGCGAINRANGE register.
 *
 * The RWNXAGCGAINRANGE register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rfgainmax4detdb - The value to set the field to.
 */
__INLINE void riu_rfgainmax4detdb_setf(uint8_t rfgainmax4detdb)
{
    REG_PL_WR(RIU_RWNXAGCGAINRANGE_ADDR, (REG_PL_RD(RIU_RWNXAGCGAINRANGE_ADDR) & ~((uint32_t)0x7F000000)) | ((uint32_t)rfgainmax4detdb << 24));
}

/**
 * @brief Returns the current value of the RFGAINMIN4DETDB field in the RWNXAGCGAINRANGE register.
 *
 * The RWNXAGCGAINRANGE register will be read and the RFGAINMIN4DETDB field's value will be returned.
 *
 * @return The current value of the RFGAINMIN4DETDB field in the RWNXAGCGAINRANGE register.
 */
__INLINE uint8_t riu_rfgainmin4detdb_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCGAINRANGE_ADDR);
    return ((localVal & ((uint32_t)0x007F0000)) >> 16);
}

/**
 * @brief Sets the RFGAINMIN4DETDB field of the RWNXAGCGAINRANGE register.
 *
 * The RWNXAGCGAINRANGE register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rfgainmin4detdb - The value to set the field to.
 */
__INLINE void riu_rfgainmin4detdb_setf(uint8_t rfgainmin4detdb)
{
    REG_PL_WR(RIU_RWNXAGCGAINRANGE_ADDR, (REG_PL_RD(RIU_RWNXAGCGAINRANGE_ADDR) & ~((uint32_t)0x007F0000)) | ((uint32_t)rfgainmin4detdb << 16));
}

/**
 * @brief Returns the current value of the RFGAINMAXDB field in the RWNXAGCGAINRANGE register.
 *
 * The RWNXAGCGAINRANGE register will be read and the RFGAINMAXDB field's value will be returned.
 *
 * @return The current value of the RFGAINMAXDB field in the RWNXAGCGAINRANGE register.
 */
__INLINE uint8_t riu_rfgainmaxdb_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCGAINRANGE_ADDR);
    return ((localVal & ((uint32_t)0x00007F00)) >> 8);
}

/**
 * @brief Sets the RFGAINMAXDB field of the RWNXAGCGAINRANGE register.
 *
 * The RWNXAGCGAINRANGE register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rfgainmaxdb - The value to set the field to.
 */
__INLINE void riu_rfgainmaxdb_setf(uint8_t rfgainmaxdb)
{
    REG_PL_WR(RIU_RWNXAGCGAINRANGE_ADDR, (REG_PL_RD(RIU_RWNXAGCGAINRANGE_ADDR) & ~((uint32_t)0x00007F00)) | ((uint32_t)rfgainmaxdb << 8));
}

/**
 * @brief Returns the current value of the RFGAINMINDB field in the RWNXAGCGAINRANGE register.
 *
 * The RWNXAGCGAINRANGE register will be read and the RFGAINMINDB field's value will be returned.
 *
 * @return The current value of the RFGAINMINDB field in the RWNXAGCGAINRANGE register.
 */
__INLINE uint8_t riu_rfgainmindb_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCGAINRANGE_ADDR);
    return ((localVal & ((uint32_t)0x0000007F)) >> 0);
}

/**
 * @brief Sets the RFGAINMINDB field of the RWNXAGCGAINRANGE register.
 *
 * The RWNXAGCGAINRANGE register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rfgainmindb - The value to set the field to.
 */
__INLINE void riu_rfgainmindb_setf(uint8_t rfgainmindb)
{
    REG_PL_WR(RIU_RWNXAGCGAINRANGE_ADDR, (REG_PL_RD(RIU_RWNXAGCGAINRANGE_ADDR) & ~((uint32_t)0x0000007F)) | ((uint32_t)rfgainmindb << 0));
}

/// @}

/**
 * @name RWNXAGCDIGGAINCONF register definitions
 * <table>
 * <caption id="RWNXAGCDIGGAINCONF_BF">RWNXAGCDIGGAINCONF bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>19:16 <td>     DIGGAIN80VS20 <td>R <td>R/W <td>0x0
 * <tr><td>03:00 <td>     DIGGAIN40VS20 <td>R <td>R/W <td>0x0
 * </table>
 *
 * @{
 */

/// Address of the RWNXAGCDIGGAINCONF register
#define RIU_RWNXAGCDIGGAINCONF_ADDR   0x4033B308
/// Offset of the RWNXAGCDIGGAINCONF register from the base address
#define RIU_RWNXAGCDIGGAINCONF_OFFSET 0x00000308
/// Index of the RWNXAGCDIGGAINCONF register
#define RIU_RWNXAGCDIGGAINCONF_INDEX  0x000000C2
/// Reset value of the RWNXAGCDIGGAINCONF register
#define RIU_RWNXAGCDIGGAINCONF_RESET  0x00000000

/**
 * @brief Returns the current value of the RWNXAGCDIGGAINCONF register.
 * The RWNXAGCDIGGAINCONF register will be read and its value returned.
 * @return The current value of the RWNXAGCDIGGAINCONF register.
 */
__INLINE uint32_t riu_rwnxagcdiggainconf_get(void)
{
    return REG_PL_RD(RIU_RWNXAGCDIGGAINCONF_ADDR);
}

/**
 * @brief Sets the RWNXAGCDIGGAINCONF register to a value.
 * The RWNXAGCDIGGAINCONF register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxagcdiggainconf_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXAGCDIGGAINCONF_ADDR, value);
}

// field definitions
/// DIGGAIN80VS20 field mask
#define RIU_DIGGAIN80VS20_MASK   ((uint32_t)0x000F0000)
/// DIGGAIN80VS20 field LSB position
#define RIU_DIGGAIN80VS20_LSB    16
/// DIGGAIN80VS20 field width
#define RIU_DIGGAIN80VS20_WIDTH  ((uint32_t)0x00000004)
/// DIGGAIN40VS20 field mask
#define RIU_DIGGAIN40VS20_MASK   ((uint32_t)0x0000000F)
/// DIGGAIN40VS20 field LSB position
#define RIU_DIGGAIN40VS20_LSB    0
/// DIGGAIN40VS20 field width
#define RIU_DIGGAIN40VS20_WIDTH  ((uint32_t)0x00000004)

/// DIGGAIN80VS20 field reset value
#define RIU_DIGGAIN80VS20_RST    0x0
/// DIGGAIN40VS20 field reset value
#define RIU_DIGGAIN40VS20_RST    0x0

/**
 * @brief Constructs a value for the RWNXAGCDIGGAINCONF register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] diggain80vs20 - The value to use for the DIGGAIN80VS20 field.
 * @param[in] diggain40vs20 - The value to use for the DIGGAIN40VS20 field.
 */
__INLINE void riu_rwnxagcdiggainconf_pack(uint8_t diggain80vs20, uint8_t diggain40vs20)
{
    REG_PL_WR(RIU_RWNXAGCDIGGAINCONF_ADDR,  ((uint32_t)diggain80vs20 << 16) | ((uint32_t)diggain40vs20 << 0));
}

/**
 * @brief Unpacks RWNXAGCDIGGAINCONF's fields from current value of the RWNXAGCDIGGAINCONF register.
 *
 * Reads the RWNXAGCDIGGAINCONF register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] diggain80vs20 - Will be populated with the current value of this field from the register.
 * @param[out] diggain40vs20 - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxagcdiggainconf_unpack(uint8_t* diggain80vs20, uint8_t* diggain40vs20)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCDIGGAINCONF_ADDR);

    *diggain80vs20 = (localVal & ((uint32_t)0x000F0000)) >> 16;
    *diggain40vs20 = (localVal & ((uint32_t)0x0000000F)) >> 0;
}

/**
 * @brief Returns the current value of the DIGGAIN80VS20 field in the RWNXAGCDIGGAINCONF register.
 *
 * The RWNXAGCDIGGAINCONF register will be read and the DIGGAIN80VS20 field's value will be returned.
 *
 * @return The current value of the DIGGAIN80VS20 field in the RWNXAGCDIGGAINCONF register.
 */
__INLINE uint8_t riu_diggain80vs20_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCDIGGAINCONF_ADDR);
    return ((localVal & ((uint32_t)0x000F0000)) >> 16);
}

/**
 * @brief Sets the DIGGAIN80VS20 field of the RWNXAGCDIGGAINCONF register.
 *
 * The RWNXAGCDIGGAINCONF register will be read, modified to contain the new field value, and written.
 *
 * @param[in] diggain80vs20 - The value to set the field to.
 */
__INLINE void riu_diggain80vs20_setf(uint8_t diggain80vs20)
{
    REG_PL_WR(RIU_RWNXAGCDIGGAINCONF_ADDR, (REG_PL_RD(RIU_RWNXAGCDIGGAINCONF_ADDR) & ~((uint32_t)0x000F0000)) | ((uint32_t)diggain80vs20 << 16));
}

/**
 * @brief Returns the current value of the DIGGAIN40VS20 field in the RWNXAGCDIGGAINCONF register.
 *
 * The RWNXAGCDIGGAINCONF register will be read and the DIGGAIN40VS20 field's value will be returned.
 *
 * @return The current value of the DIGGAIN40VS20 field in the RWNXAGCDIGGAINCONF register.
 */
__INLINE uint8_t riu_diggain40vs20_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCDIGGAINCONF_ADDR);
    return ((localVal & ((uint32_t)0x0000000F)) >> 0);
}

/**
 * @brief Sets the DIGGAIN40VS20 field of the RWNXAGCDIGGAINCONF register.
 *
 * The RWNXAGCDIGGAINCONF register will be read, modified to contain the new field value, and written.
 *
 * @param[in] diggain40vs20 - The value to set the field to.
 */
__INLINE void riu_diggain40vs20_setf(uint8_t diggain40vs20)
{
    REG_PL_WR(RIU_RWNXAGCDIGGAINCONF_ADDR, (REG_PL_RD(RIU_RWNXAGCDIGGAINCONF_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)diggain40vs20 << 0));
}

/// @}

#if RW_NX_AGC_SNR_EN
/**
 * @name RWNXAGCNOISECONF register definitions
 * <table>
 * <caption id="RWNXAGCNOISECONF_BF">RWNXAGCNOISECONF bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>16 <td>        SNRMEASSEL <td>R <td>R/W <td>0
 * </table>
 *
 * @{
 */

/// Address of the RWNXAGCNOISECONF register
#define RIU_RWNXAGCNOISECONF_ADDR   0x4033B30C
/// Offset of the RWNXAGCNOISECONF register from the base address
#define RIU_RWNXAGCNOISECONF_OFFSET 0x0000030C
/// Index of the RWNXAGCNOISECONF register
#define RIU_RWNXAGCNOISECONF_INDEX  0x000000C3
/// Reset value of the RWNXAGCNOISECONF register
#define RIU_RWNXAGCNOISECONF_RESET  0x00000000

/**
 * @brief Returns the current value of the RWNXAGCNOISECONF register.
 * The RWNXAGCNOISECONF register will be read and its value returned.
 * @return The current value of the RWNXAGCNOISECONF register.
 */
__INLINE uint32_t riu_rwnxagcnoiseconf_get(void)
{
    return REG_PL_RD(RIU_RWNXAGCNOISECONF_ADDR);
}

/**
 * @brief Sets the RWNXAGCNOISECONF register to a value.
 * The RWNXAGCNOISECONF register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxagcnoiseconf_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXAGCNOISECONF_ADDR, value);
}

// field definitions
/// SNRMEASSEL field bit
#define RIU_SNRMEASSEL_BIT    ((uint32_t)0x00010000)
/// SNRMEASSEL field position
#define RIU_SNRMEASSEL_POS    16

/// SNRMEASSEL field reset value
#define RIU_SNRMEASSEL_RST    0x0

/**
 * @brief Returns the current value of the SNRMEASSEL field in the RWNXAGCNOISECONF register.
 *
 * The RWNXAGCNOISECONF register will be read and the SNRMEASSEL field's value will be returned.
 *
 * @return The current value of the SNRMEASSEL field in the RWNXAGCNOISECONF register.
 */
__INLINE uint8_t riu_snrmeassel_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCNOISECONF_ADDR);
    return (localVal >> 16);
}

/**
 * @brief Sets the SNRMEASSEL field of the RWNXAGCNOISECONF register.
 *
 * The RWNXAGCNOISECONF register will be read, modified to contain the new field value, and written.
 *
 * @param[in] snrmeassel - The value to set the field to.
 */
__INLINE void riu_snrmeassel_setf(uint8_t snrmeassel)
{
    REG_PL_WR(RIU_RWNXAGCNOISECONF_ADDR, (uint32_t)snrmeassel << 16);
}

#endif // RW_NX_AGC_SNR_EN
/// @}

/**
 * @name RWNXAGCACI20MARG0 register definitions
 * <table>
 * <caption id="RWNXAGCACI20MARG0_BF">RWNXAGCACI20MARG0 bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>29:24 <td>     ACI20MARGMCS3 <td>R <td>R/W <td>0x2
 * <tr><td>21:16 <td>     ACI20MARGMCS2 <td>R <td>R/W <td>0x4
 * <tr><td>13:08 <td>     ACI20MARGMCS1 <td>R <td>R/W <td>0x5
 * <tr><td>05:00 <td>     ACI20MARGMCS0 <td>R <td>R/W <td>0x7
 * </table>
 *
 * @{
 */

/// Address of the RWNXAGCACI20MARG0 register
#define RIU_RWNXAGCACI20MARG0_ADDR   0x4033B340
/// Offset of the RWNXAGCACI20MARG0 register from the base address
#define RIU_RWNXAGCACI20MARG0_OFFSET 0x00000340
/// Index of the RWNXAGCACI20MARG0 register
#define RIU_RWNXAGCACI20MARG0_INDEX  0x000000D0
/// Reset value of the RWNXAGCACI20MARG0 register
#define RIU_RWNXAGCACI20MARG0_RESET  0x02040507

/**
 * @brief Returns the current value of the RWNXAGCACI20MARG0 register.
 * The RWNXAGCACI20MARG0 register will be read and its value returned.
 * @return The current value of the RWNXAGCACI20MARG0 register.
 */
__INLINE uint32_t riu_rwnxagcaci20marg0_get(void)
{
    return REG_PL_RD(RIU_RWNXAGCACI20MARG0_ADDR);
}

/**
 * @brief Sets the RWNXAGCACI20MARG0 register to a value.
 * The RWNXAGCACI20MARG0 register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxagcaci20marg0_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXAGCACI20MARG0_ADDR, value);
}

// field definitions
/// ACI20MARGMCS3 field mask
#define RIU_ACI20MARGMCS3_MASK   ((uint32_t)0x3F000000)
/// ACI20MARGMCS3 field LSB position
#define RIU_ACI20MARGMCS3_LSB    24
/// ACI20MARGMCS3 field width
#define RIU_ACI20MARGMCS3_WIDTH  ((uint32_t)0x00000006)
/// ACI20MARGMCS2 field mask
#define RIU_ACI20MARGMCS2_MASK   ((uint32_t)0x003F0000)
/// ACI20MARGMCS2 field LSB position
#define RIU_ACI20MARGMCS2_LSB    16
/// ACI20MARGMCS2 field width
#define RIU_ACI20MARGMCS2_WIDTH  ((uint32_t)0x00000006)
/// ACI20MARGMCS1 field mask
#define RIU_ACI20MARGMCS1_MASK   ((uint32_t)0x00003F00)
/// ACI20MARGMCS1 field LSB position
#define RIU_ACI20MARGMCS1_LSB    8
/// ACI20MARGMCS1 field width
#define RIU_ACI20MARGMCS1_WIDTH  ((uint32_t)0x00000006)
/// ACI20MARGMCS0 field mask
#define RIU_ACI20MARGMCS0_MASK   ((uint32_t)0x0000003F)
/// ACI20MARGMCS0 field LSB position
#define RIU_ACI20MARGMCS0_LSB    0
/// ACI20MARGMCS0 field width
#define RIU_ACI20MARGMCS0_WIDTH  ((uint32_t)0x00000006)

/// ACI20MARGMCS3 field reset value
#define RIU_ACI20MARGMCS3_RST    0x2
/// ACI20MARGMCS2 field reset value
#define RIU_ACI20MARGMCS2_RST    0x4
/// ACI20MARGMCS1 field reset value
#define RIU_ACI20MARGMCS1_RST    0x5
/// ACI20MARGMCS0 field reset value
#define RIU_ACI20MARGMCS0_RST    0x7

/**
 * @brief Constructs a value for the RWNXAGCACI20MARG0 register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] aci20margmcs3 - The value to use for the ACI20MARGMCS3 field.
 * @param[in] aci20margmcs2 - The value to use for the ACI20MARGMCS2 field.
 * @param[in] aci20margmcs1 - The value to use for the ACI20MARGMCS1 field.
 * @param[in] aci20margmcs0 - The value to use for the ACI20MARGMCS0 field.
 */
__INLINE void riu_rwnxagcaci20marg0_pack(uint8_t aci20margmcs3, uint8_t aci20margmcs2, uint8_t aci20margmcs1, uint8_t aci20margmcs0)
{
    REG_PL_WR(RIU_RWNXAGCACI20MARG0_ADDR,  ((uint32_t)aci20margmcs3 << 24) | ((uint32_t)aci20margmcs2 << 16) | ((uint32_t)aci20margmcs1 << 8) | ((uint32_t)aci20margmcs0 << 0));
}

/**
 * @brief Unpacks RWNXAGCACI20MARG0's fields from current value of the RWNXAGCACI20MARG0 register.
 *
 * Reads the RWNXAGCACI20MARG0 register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] aci20margmcs3 - Will be populated with the current value of this field from the register.
 * @param[out] aci20margmcs2 - Will be populated with the current value of this field from the register.
 * @param[out] aci20margmcs1 - Will be populated with the current value of this field from the register.
 * @param[out] aci20margmcs0 - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxagcaci20marg0_unpack(uint8_t* aci20margmcs3, uint8_t* aci20margmcs2, uint8_t* aci20margmcs1, uint8_t* aci20margmcs0)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCACI20MARG0_ADDR);

    *aci20margmcs3 = (localVal & ((uint32_t)0x3F000000)) >> 24;
    *aci20margmcs2 = (localVal & ((uint32_t)0x003F0000)) >> 16;
    *aci20margmcs1 = (localVal & ((uint32_t)0x00003F00)) >> 8;
    *aci20margmcs0 = (localVal & ((uint32_t)0x0000003F)) >> 0;
}

/**
 * @brief Returns the current value of the ACI20MARGMCS3 field in the RWNXAGCACI20MARG0 register.
 *
 * The RWNXAGCACI20MARG0 register will be read and the ACI20MARGMCS3 field's value will be returned.
 *
 * @return The current value of the ACI20MARGMCS3 field in the RWNXAGCACI20MARG0 register.
 */
__INLINE uint8_t riu_aci20margmcs3_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCACI20MARG0_ADDR);
    return ((localVal & ((uint32_t)0x3F000000)) >> 24);
}

/**
 * @brief Sets the ACI20MARGMCS3 field of the RWNXAGCACI20MARG0 register.
 *
 * The RWNXAGCACI20MARG0 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] aci20margmcs3 - The value to set the field to.
 */
__INLINE void riu_aci20margmcs3_setf(uint8_t aci20margmcs3)
{
    REG_PL_WR(RIU_RWNXAGCACI20MARG0_ADDR, (REG_PL_RD(RIU_RWNXAGCACI20MARG0_ADDR) & ~((uint32_t)0x3F000000)) | ((uint32_t)aci20margmcs3 << 24));
}

/**
 * @brief Returns the current value of the ACI20MARGMCS2 field in the RWNXAGCACI20MARG0 register.
 *
 * The RWNXAGCACI20MARG0 register will be read and the ACI20MARGMCS2 field's value will be returned.
 *
 * @return The current value of the ACI20MARGMCS2 field in the RWNXAGCACI20MARG0 register.
 */
__INLINE uint8_t riu_aci20margmcs2_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCACI20MARG0_ADDR);
    return ((localVal & ((uint32_t)0x003F0000)) >> 16);
}

/**
 * @brief Sets the ACI20MARGMCS2 field of the RWNXAGCACI20MARG0 register.
 *
 * The RWNXAGCACI20MARG0 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] aci20margmcs2 - The value to set the field to.
 */
__INLINE void riu_aci20margmcs2_setf(uint8_t aci20margmcs2)
{
    REG_PL_WR(RIU_RWNXAGCACI20MARG0_ADDR, (REG_PL_RD(RIU_RWNXAGCACI20MARG0_ADDR) & ~((uint32_t)0x003F0000)) | ((uint32_t)aci20margmcs2 << 16));
}

/**
 * @brief Returns the current value of the ACI20MARGMCS1 field in the RWNXAGCACI20MARG0 register.
 *
 * The RWNXAGCACI20MARG0 register will be read and the ACI20MARGMCS1 field's value will be returned.
 *
 * @return The current value of the ACI20MARGMCS1 field in the RWNXAGCACI20MARG0 register.
 */
__INLINE uint8_t riu_aci20margmcs1_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCACI20MARG0_ADDR);
    return ((localVal & ((uint32_t)0x00003F00)) >> 8);
}

/**
 * @brief Sets the ACI20MARGMCS1 field of the RWNXAGCACI20MARG0 register.
 *
 * The RWNXAGCACI20MARG0 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] aci20margmcs1 - The value to set the field to.
 */
__INLINE void riu_aci20margmcs1_setf(uint8_t aci20margmcs1)
{
    REG_PL_WR(RIU_RWNXAGCACI20MARG0_ADDR, (REG_PL_RD(RIU_RWNXAGCACI20MARG0_ADDR) & ~((uint32_t)0x00003F00)) | ((uint32_t)aci20margmcs1 << 8));
}

/**
 * @brief Returns the current value of the ACI20MARGMCS0 field in the RWNXAGCACI20MARG0 register.
 *
 * The RWNXAGCACI20MARG0 register will be read and the ACI20MARGMCS0 field's value will be returned.
 *
 * @return The current value of the ACI20MARGMCS0 field in the RWNXAGCACI20MARG0 register.
 */
__INLINE uint8_t riu_aci20margmcs0_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCACI20MARG0_ADDR);
    return ((localVal & ((uint32_t)0x0000003F)) >> 0);
}

/**
 * @brief Sets the ACI20MARGMCS0 field of the RWNXAGCACI20MARG0 register.
 *
 * The RWNXAGCACI20MARG0 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] aci20margmcs0 - The value to set the field to.
 */
__INLINE void riu_aci20margmcs0_setf(uint8_t aci20margmcs0)
{
    REG_PL_WR(RIU_RWNXAGCACI20MARG0_ADDR, (REG_PL_RD(RIU_RWNXAGCACI20MARG0_ADDR) & ~((uint32_t)0x0000003F)) | ((uint32_t)aci20margmcs0 << 0));
}

/// @}

/**
 * @name RWNXAGCACI20MARG1 register definitions
 * <table>
 * <caption id="RWNXAGCACI20MARG1_BF">RWNXAGCACI20MARG1 bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>29:24 <td>     ACI20MARGMCS7 <td>R <td>R/W <td>0x0
 * <tr><td>21:16 <td>     ACI20MARGMCS6 <td>R <td>R/W <td>0x0
 * <tr><td>13:08 <td>     ACI20MARGMCS5 <td>R <td>R/W <td>0x0
 * <tr><td>05:00 <td>     ACI20MARGMCS4 <td>R <td>R/W <td>0x1
 * </table>
 *
 * @{
 */

/// Address of the RWNXAGCACI20MARG1 register
#define RIU_RWNXAGCACI20MARG1_ADDR   0x4033B344
/// Offset of the RWNXAGCACI20MARG1 register from the base address
#define RIU_RWNXAGCACI20MARG1_OFFSET 0x00000344
/// Index of the RWNXAGCACI20MARG1 register
#define RIU_RWNXAGCACI20MARG1_INDEX  0x000000D1
/// Reset value of the RWNXAGCACI20MARG1 register
#define RIU_RWNXAGCACI20MARG1_RESET  0x00000001

/**
 * @brief Returns the current value of the RWNXAGCACI20MARG1 register.
 * The RWNXAGCACI20MARG1 register will be read and its value returned.
 * @return The current value of the RWNXAGCACI20MARG1 register.
 */
__INLINE uint32_t riu_rwnxagcaci20marg1_get(void)
{
    return REG_PL_RD(RIU_RWNXAGCACI20MARG1_ADDR);
}

/**
 * @brief Sets the RWNXAGCACI20MARG1 register to a value.
 * The RWNXAGCACI20MARG1 register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxagcaci20marg1_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXAGCACI20MARG1_ADDR, value);
}

// field definitions
/// ACI20MARGMCS7 field mask
#define RIU_ACI20MARGMCS7_MASK   ((uint32_t)0x3F000000)
/// ACI20MARGMCS7 field LSB position
#define RIU_ACI20MARGMCS7_LSB    24
/// ACI20MARGMCS7 field width
#define RIU_ACI20MARGMCS7_WIDTH  ((uint32_t)0x00000006)
/// ACI20MARGMCS6 field mask
#define RIU_ACI20MARGMCS6_MASK   ((uint32_t)0x003F0000)
/// ACI20MARGMCS6 field LSB position
#define RIU_ACI20MARGMCS6_LSB    16
/// ACI20MARGMCS6 field width
#define RIU_ACI20MARGMCS6_WIDTH  ((uint32_t)0x00000006)
/// ACI20MARGMCS5 field mask
#define RIU_ACI20MARGMCS5_MASK   ((uint32_t)0x00003F00)
/// ACI20MARGMCS5 field LSB position
#define RIU_ACI20MARGMCS5_LSB    8
/// ACI20MARGMCS5 field width
#define RIU_ACI20MARGMCS5_WIDTH  ((uint32_t)0x00000006)
/// ACI20MARGMCS4 field mask
#define RIU_ACI20MARGMCS4_MASK   ((uint32_t)0x0000003F)
/// ACI20MARGMCS4 field LSB position
#define RIU_ACI20MARGMCS4_LSB    0
/// ACI20MARGMCS4 field width
#define RIU_ACI20MARGMCS4_WIDTH  ((uint32_t)0x00000006)

/// ACI20MARGMCS7 field reset value
#define RIU_ACI20MARGMCS7_RST    0x0
/// ACI20MARGMCS6 field reset value
#define RIU_ACI20MARGMCS6_RST    0x0
/// ACI20MARGMCS5 field reset value
#define RIU_ACI20MARGMCS5_RST    0x0
/// ACI20MARGMCS4 field reset value
#define RIU_ACI20MARGMCS4_RST    0x1

/**
 * @brief Constructs a value for the RWNXAGCACI20MARG1 register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] aci20margmcs7 - The value to use for the ACI20MARGMCS7 field.
 * @param[in] aci20margmcs6 - The value to use for the ACI20MARGMCS6 field.
 * @param[in] aci20margmcs5 - The value to use for the ACI20MARGMCS5 field.
 * @param[in] aci20margmcs4 - The value to use for the ACI20MARGMCS4 field.
 */
__INLINE void riu_rwnxagcaci20marg1_pack(uint8_t aci20margmcs7, uint8_t aci20margmcs6, uint8_t aci20margmcs5, uint8_t aci20margmcs4)
{
    REG_PL_WR(RIU_RWNXAGCACI20MARG1_ADDR,  ((uint32_t)aci20margmcs7 << 24) | ((uint32_t)aci20margmcs6 << 16) | ((uint32_t)aci20margmcs5 << 8) | ((uint32_t)aci20margmcs4 << 0));
}

/**
 * @brief Unpacks RWNXAGCACI20MARG1's fields from current value of the RWNXAGCACI20MARG1 register.
 *
 * Reads the RWNXAGCACI20MARG1 register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] aci20margmcs7 - Will be populated with the current value of this field from the register.
 * @param[out] aci20margmcs6 - Will be populated with the current value of this field from the register.
 * @param[out] aci20margmcs5 - Will be populated with the current value of this field from the register.
 * @param[out] aci20margmcs4 - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxagcaci20marg1_unpack(uint8_t* aci20margmcs7, uint8_t* aci20margmcs6, uint8_t* aci20margmcs5, uint8_t* aci20margmcs4)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCACI20MARG1_ADDR);

    *aci20margmcs7 = (localVal & ((uint32_t)0x3F000000)) >> 24;
    *aci20margmcs6 = (localVal & ((uint32_t)0x003F0000)) >> 16;
    *aci20margmcs5 = (localVal & ((uint32_t)0x00003F00)) >> 8;
    *aci20margmcs4 = (localVal & ((uint32_t)0x0000003F)) >> 0;
}

/**
 * @brief Returns the current value of the ACI20MARGMCS7 field in the RWNXAGCACI20MARG1 register.
 *
 * The RWNXAGCACI20MARG1 register will be read and the ACI20MARGMCS7 field's value will be returned.
 *
 * @return The current value of the ACI20MARGMCS7 field in the RWNXAGCACI20MARG1 register.
 */
__INLINE uint8_t riu_aci20margmcs7_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCACI20MARG1_ADDR);
    return ((localVal & ((uint32_t)0x3F000000)) >> 24);
}

/**
 * @brief Sets the ACI20MARGMCS7 field of the RWNXAGCACI20MARG1 register.
 *
 * The RWNXAGCACI20MARG1 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] aci20margmcs7 - The value to set the field to.
 */
__INLINE void riu_aci20margmcs7_setf(uint8_t aci20margmcs7)
{
    REG_PL_WR(RIU_RWNXAGCACI20MARG1_ADDR, (REG_PL_RD(RIU_RWNXAGCACI20MARG1_ADDR) & ~((uint32_t)0x3F000000)) | ((uint32_t)aci20margmcs7 << 24));
}

/**
 * @brief Returns the current value of the ACI20MARGMCS6 field in the RWNXAGCACI20MARG1 register.
 *
 * The RWNXAGCACI20MARG1 register will be read and the ACI20MARGMCS6 field's value will be returned.
 *
 * @return The current value of the ACI20MARGMCS6 field in the RWNXAGCACI20MARG1 register.
 */
__INLINE uint8_t riu_aci20margmcs6_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCACI20MARG1_ADDR);
    return ((localVal & ((uint32_t)0x003F0000)) >> 16);
}

/**
 * @brief Sets the ACI20MARGMCS6 field of the RWNXAGCACI20MARG1 register.
 *
 * The RWNXAGCACI20MARG1 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] aci20margmcs6 - The value to set the field to.
 */
__INLINE void riu_aci20margmcs6_setf(uint8_t aci20margmcs6)
{
    REG_PL_WR(RIU_RWNXAGCACI20MARG1_ADDR, (REG_PL_RD(RIU_RWNXAGCACI20MARG1_ADDR) & ~((uint32_t)0x003F0000)) | ((uint32_t)aci20margmcs6 << 16));
}

/**
 * @brief Returns the current value of the ACI20MARGMCS5 field in the RWNXAGCACI20MARG1 register.
 *
 * The RWNXAGCACI20MARG1 register will be read and the ACI20MARGMCS5 field's value will be returned.
 *
 * @return The current value of the ACI20MARGMCS5 field in the RWNXAGCACI20MARG1 register.
 */
__INLINE uint8_t riu_aci20margmcs5_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCACI20MARG1_ADDR);
    return ((localVal & ((uint32_t)0x00003F00)) >> 8);
}

/**
 * @brief Sets the ACI20MARGMCS5 field of the RWNXAGCACI20MARG1 register.
 *
 * The RWNXAGCACI20MARG1 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] aci20margmcs5 - The value to set the field to.
 */
__INLINE void riu_aci20margmcs5_setf(uint8_t aci20margmcs5)
{
    REG_PL_WR(RIU_RWNXAGCACI20MARG1_ADDR, (REG_PL_RD(RIU_RWNXAGCACI20MARG1_ADDR) & ~((uint32_t)0x00003F00)) | ((uint32_t)aci20margmcs5 << 8));
}

/**
 * @brief Returns the current value of the ACI20MARGMCS4 field in the RWNXAGCACI20MARG1 register.
 *
 * The RWNXAGCACI20MARG1 register will be read and the ACI20MARGMCS4 field's value will be returned.
 *
 * @return The current value of the ACI20MARGMCS4 field in the RWNXAGCACI20MARG1 register.
 */
__INLINE uint8_t riu_aci20margmcs4_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCACI20MARG1_ADDR);
    return ((localVal & ((uint32_t)0x0000003F)) >> 0);
}

/**
 * @brief Sets the ACI20MARGMCS4 field of the RWNXAGCACI20MARG1 register.
 *
 * The RWNXAGCACI20MARG1 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] aci20margmcs4 - The value to set the field to.
 */
__INLINE void riu_aci20margmcs4_setf(uint8_t aci20margmcs4)
{
    REG_PL_WR(RIU_RWNXAGCACI20MARG1_ADDR, (REG_PL_RD(RIU_RWNXAGCACI20MARG1_ADDR) & ~((uint32_t)0x0000003F)) | ((uint32_t)aci20margmcs4 << 0));
}

/// @}

/**
 * @name RWNXAGCACI20MARG2 register definitions
 * <table>
 * <caption id="RWNXAGCACI20MARG2_BF">RWNXAGCACI20MARG2 bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>13:08 <td>     ACI20MARGMCS9 <td>R <td>R/W <td>0x0
 * <tr><td>05:00 <td>     ACI20MARGMCS8 <td>R <td>R/W <td>0x0
 * </table>
 *
 * @{
 */

/// Address of the RWNXAGCACI20MARG2 register
#define RIU_RWNXAGCACI20MARG2_ADDR   0x4033B348
/// Offset of the RWNXAGCACI20MARG2 register from the base address
#define RIU_RWNXAGCACI20MARG2_OFFSET 0x00000348
/// Index of the RWNXAGCACI20MARG2 register
#define RIU_RWNXAGCACI20MARG2_INDEX  0x000000D2
/// Reset value of the RWNXAGCACI20MARG2 register
#define RIU_RWNXAGCACI20MARG2_RESET  0x00000000

/**
 * @brief Returns the current value of the RWNXAGCACI20MARG2 register.
 * The RWNXAGCACI20MARG2 register will be read and its value returned.
 * @return The current value of the RWNXAGCACI20MARG2 register.
 */
__INLINE uint32_t riu_rwnxagcaci20marg2_get(void)
{
    return REG_PL_RD(RIU_RWNXAGCACI20MARG2_ADDR);
}

/**
 * @brief Sets the RWNXAGCACI20MARG2 register to a value.
 * The RWNXAGCACI20MARG2 register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxagcaci20marg2_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXAGCACI20MARG2_ADDR, value);
}

// field definitions
/// ACI20MARGMCS9 field mask
#define RIU_ACI20MARGMCS9_MASK   ((uint32_t)0x00003F00)
/// ACI20MARGMCS9 field LSB position
#define RIU_ACI20MARGMCS9_LSB    8
/// ACI20MARGMCS9 field width
#define RIU_ACI20MARGMCS9_WIDTH  ((uint32_t)0x00000006)
/// ACI20MARGMCS8 field mask
#define RIU_ACI20MARGMCS8_MASK   ((uint32_t)0x0000003F)
/// ACI20MARGMCS8 field LSB position
#define RIU_ACI20MARGMCS8_LSB    0
/// ACI20MARGMCS8 field width
#define RIU_ACI20MARGMCS8_WIDTH  ((uint32_t)0x00000006)

/// ACI20MARGMCS9 field reset value
#define RIU_ACI20MARGMCS9_RST    0x0
/// ACI20MARGMCS8 field reset value
#define RIU_ACI20MARGMCS8_RST    0x0

/**
 * @brief Constructs a value for the RWNXAGCACI20MARG2 register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] aci20margmcs9 - The value to use for the ACI20MARGMCS9 field.
 * @param[in] aci20margmcs8 - The value to use for the ACI20MARGMCS8 field.
 */
__INLINE void riu_rwnxagcaci20marg2_pack(uint8_t aci20margmcs9, uint8_t aci20margmcs8)
{
    REG_PL_WR(RIU_RWNXAGCACI20MARG2_ADDR,  ((uint32_t)aci20margmcs9 << 8) | ((uint32_t)aci20margmcs8 << 0));
}

/**
 * @brief Unpacks RWNXAGCACI20MARG2's fields from current value of the RWNXAGCACI20MARG2 register.
 *
 * Reads the RWNXAGCACI20MARG2 register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] aci20margmcs9 - Will be populated with the current value of this field from the register.
 * @param[out] aci20margmcs8 - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxagcaci20marg2_unpack(uint8_t* aci20margmcs9, uint8_t* aci20margmcs8)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCACI20MARG2_ADDR);

    *aci20margmcs9 = (localVal & ((uint32_t)0x00003F00)) >> 8;
    *aci20margmcs8 = (localVal & ((uint32_t)0x0000003F)) >> 0;
}

/**
 * @brief Returns the current value of the ACI20MARGMCS9 field in the RWNXAGCACI20MARG2 register.
 *
 * The RWNXAGCACI20MARG2 register will be read and the ACI20MARGMCS9 field's value will be returned.
 *
 * @return The current value of the ACI20MARGMCS9 field in the RWNXAGCACI20MARG2 register.
 */
__INLINE uint8_t riu_aci20margmcs9_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCACI20MARG2_ADDR);
    return ((localVal & ((uint32_t)0x00003F00)) >> 8);
}

/**
 * @brief Sets the ACI20MARGMCS9 field of the RWNXAGCACI20MARG2 register.
 *
 * The RWNXAGCACI20MARG2 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] aci20margmcs9 - The value to set the field to.
 */
__INLINE void riu_aci20margmcs9_setf(uint8_t aci20margmcs9)
{
    REG_PL_WR(RIU_RWNXAGCACI20MARG2_ADDR, (REG_PL_RD(RIU_RWNXAGCACI20MARG2_ADDR) & ~((uint32_t)0x00003F00)) | ((uint32_t)aci20margmcs9 << 8));
}

/**
 * @brief Returns the current value of the ACI20MARGMCS8 field in the RWNXAGCACI20MARG2 register.
 *
 * The RWNXAGCACI20MARG2 register will be read and the ACI20MARGMCS8 field's value will be returned.
 *
 * @return The current value of the ACI20MARGMCS8 field in the RWNXAGCACI20MARG2 register.
 */
__INLINE uint8_t riu_aci20margmcs8_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCACI20MARG2_ADDR);
    return ((localVal & ((uint32_t)0x0000003F)) >> 0);
}

/**
 * @brief Sets the ACI20MARGMCS8 field of the RWNXAGCACI20MARG2 register.
 *
 * The RWNXAGCACI20MARG2 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] aci20margmcs8 - The value to set the field to.
 */
__INLINE void riu_aci20margmcs8_setf(uint8_t aci20margmcs8)
{
    REG_PL_WR(RIU_RWNXAGCACI20MARG2_ADDR, (REG_PL_RD(RIU_RWNXAGCACI20MARG2_ADDR) & ~((uint32_t)0x0000003F)) | ((uint32_t)aci20margmcs8 << 0));
}

/// @}

/**
 * @name RWNXAGCACI40MARG0 register definitions
 * <table>
 * <caption id="RWNXAGCACI40MARG0_BF">RWNXAGCACI40MARG0 bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>29:24 <td>     ACI40MARGMCS3 <td>R <td>R/W <td>0x9
 * <tr><td>21:16 <td>     ACI40MARGMCS2 <td>R <td>R/W <td>0xB
 * <tr><td>13:08 <td>     ACI40MARGMCS1 <td>R <td>R/W <td>0xD
 * <tr><td>05:00 <td>     ACI40MARGMCS0 <td>R <td>R/W <td>0x10
 * </table>
 *
 * @{
 */

/// Address of the RWNXAGCACI40MARG0 register
#define RIU_RWNXAGCACI40MARG0_ADDR   0x4033B34C
/// Offset of the RWNXAGCACI40MARG0 register from the base address
#define RIU_RWNXAGCACI40MARG0_OFFSET 0x0000034C
/// Index of the RWNXAGCACI40MARG0 register
#define RIU_RWNXAGCACI40MARG0_INDEX  0x000000D3
/// Reset value of the RWNXAGCACI40MARG0 register
#define RIU_RWNXAGCACI40MARG0_RESET  0x090B0D10

/**
 * @brief Returns the current value of the RWNXAGCACI40MARG0 register.
 * The RWNXAGCACI40MARG0 register will be read and its value returned.
 * @return The current value of the RWNXAGCACI40MARG0 register.
 */
__INLINE uint32_t riu_rwnxagcaci40marg0_get(void)
{
    return REG_PL_RD(RIU_RWNXAGCACI40MARG0_ADDR);
}

/**
 * @brief Sets the RWNXAGCACI40MARG0 register to a value.
 * The RWNXAGCACI40MARG0 register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxagcaci40marg0_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXAGCACI40MARG0_ADDR, value);
}

// field definitions
/// ACI40MARGMCS3 field mask
#define RIU_ACI40MARGMCS3_MASK   ((uint32_t)0x3F000000)
/// ACI40MARGMCS3 field LSB position
#define RIU_ACI40MARGMCS3_LSB    24
/// ACI40MARGMCS3 field width
#define RIU_ACI40MARGMCS3_WIDTH  ((uint32_t)0x00000006)
/// ACI40MARGMCS2 field mask
#define RIU_ACI40MARGMCS2_MASK   ((uint32_t)0x003F0000)
/// ACI40MARGMCS2 field LSB position
#define RIU_ACI40MARGMCS2_LSB    16
/// ACI40MARGMCS2 field width
#define RIU_ACI40MARGMCS2_WIDTH  ((uint32_t)0x00000006)
/// ACI40MARGMCS1 field mask
#define RIU_ACI40MARGMCS1_MASK   ((uint32_t)0x00003F00)
/// ACI40MARGMCS1 field LSB position
#define RIU_ACI40MARGMCS1_LSB    8
/// ACI40MARGMCS1 field width
#define RIU_ACI40MARGMCS1_WIDTH  ((uint32_t)0x00000006)
/// ACI40MARGMCS0 field mask
#define RIU_ACI40MARGMCS0_MASK   ((uint32_t)0x0000003F)
/// ACI40MARGMCS0 field LSB position
#define RIU_ACI40MARGMCS0_LSB    0
/// ACI40MARGMCS0 field width
#define RIU_ACI40MARGMCS0_WIDTH  ((uint32_t)0x00000006)

/// ACI40MARGMCS3 field reset value
#define RIU_ACI40MARGMCS3_RST    0x9
/// ACI40MARGMCS2 field reset value
#define RIU_ACI40MARGMCS2_RST    0xB
/// ACI40MARGMCS1 field reset value
#define RIU_ACI40MARGMCS1_RST    0xD
/// ACI40MARGMCS0 field reset value
#define RIU_ACI40MARGMCS0_RST    0x10

/**
 * @brief Constructs a value for the RWNXAGCACI40MARG0 register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] aci40margmcs3 - The value to use for the ACI40MARGMCS3 field.
 * @param[in] aci40margmcs2 - The value to use for the ACI40MARGMCS2 field.
 * @param[in] aci40margmcs1 - The value to use for the ACI40MARGMCS1 field.
 * @param[in] aci40margmcs0 - The value to use for the ACI40MARGMCS0 field.
 */
__INLINE void riu_rwnxagcaci40marg0_pack(uint8_t aci40margmcs3, uint8_t aci40margmcs2, uint8_t aci40margmcs1, uint8_t aci40margmcs0)
{
    REG_PL_WR(RIU_RWNXAGCACI40MARG0_ADDR,  ((uint32_t)aci40margmcs3 << 24) | ((uint32_t)aci40margmcs2 << 16) | ((uint32_t)aci40margmcs1 << 8) | ((uint32_t)aci40margmcs0 << 0));
}

/**
 * @brief Unpacks RWNXAGCACI40MARG0's fields from current value of the RWNXAGCACI40MARG0 register.
 *
 * Reads the RWNXAGCACI40MARG0 register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] aci40margmcs3 - Will be populated with the current value of this field from the register.
 * @param[out] aci40margmcs2 - Will be populated with the current value of this field from the register.
 * @param[out] aci40margmcs1 - Will be populated with the current value of this field from the register.
 * @param[out] aci40margmcs0 - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxagcaci40marg0_unpack(uint8_t* aci40margmcs3, uint8_t* aci40margmcs2, uint8_t* aci40margmcs1, uint8_t* aci40margmcs0)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCACI40MARG0_ADDR);

    *aci40margmcs3 = (localVal & ((uint32_t)0x3F000000)) >> 24;
    *aci40margmcs2 = (localVal & ((uint32_t)0x003F0000)) >> 16;
    *aci40margmcs1 = (localVal & ((uint32_t)0x00003F00)) >> 8;
    *aci40margmcs0 = (localVal & ((uint32_t)0x0000003F)) >> 0;
}

/**
 * @brief Returns the current value of the ACI40MARGMCS3 field in the RWNXAGCACI40MARG0 register.
 *
 * The RWNXAGCACI40MARG0 register will be read and the ACI40MARGMCS3 field's value will be returned.
 *
 * @return The current value of the ACI40MARGMCS3 field in the RWNXAGCACI40MARG0 register.
 */
__INLINE uint8_t riu_aci40margmcs3_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCACI40MARG0_ADDR);
    return ((localVal & ((uint32_t)0x3F000000)) >> 24);
}

/**
 * @brief Sets the ACI40MARGMCS3 field of the RWNXAGCACI40MARG0 register.
 *
 * The RWNXAGCACI40MARG0 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] aci40margmcs3 - The value to set the field to.
 */
__INLINE void riu_aci40margmcs3_setf(uint8_t aci40margmcs3)
{
    REG_PL_WR(RIU_RWNXAGCACI40MARG0_ADDR, (REG_PL_RD(RIU_RWNXAGCACI40MARG0_ADDR) & ~((uint32_t)0x3F000000)) | ((uint32_t)aci40margmcs3 << 24));
}

/**
 * @brief Returns the current value of the ACI40MARGMCS2 field in the RWNXAGCACI40MARG0 register.
 *
 * The RWNXAGCACI40MARG0 register will be read and the ACI40MARGMCS2 field's value will be returned.
 *
 * @return The current value of the ACI40MARGMCS2 field in the RWNXAGCACI40MARG0 register.
 */
__INLINE uint8_t riu_aci40margmcs2_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCACI40MARG0_ADDR);
    return ((localVal & ((uint32_t)0x003F0000)) >> 16);
}

/**
 * @brief Sets the ACI40MARGMCS2 field of the RWNXAGCACI40MARG0 register.
 *
 * The RWNXAGCACI40MARG0 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] aci40margmcs2 - The value to set the field to.
 */
__INLINE void riu_aci40margmcs2_setf(uint8_t aci40margmcs2)
{
    REG_PL_WR(RIU_RWNXAGCACI40MARG0_ADDR, (REG_PL_RD(RIU_RWNXAGCACI40MARG0_ADDR) & ~((uint32_t)0x003F0000)) | ((uint32_t)aci40margmcs2 << 16));
}

/**
 * @brief Returns the current value of the ACI40MARGMCS1 field in the RWNXAGCACI40MARG0 register.
 *
 * The RWNXAGCACI40MARG0 register will be read and the ACI40MARGMCS1 field's value will be returned.
 *
 * @return The current value of the ACI40MARGMCS1 field in the RWNXAGCACI40MARG0 register.
 */
__INLINE uint8_t riu_aci40margmcs1_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCACI40MARG0_ADDR);
    return ((localVal & ((uint32_t)0x00003F00)) >> 8);
}

/**
 * @brief Sets the ACI40MARGMCS1 field of the RWNXAGCACI40MARG0 register.
 *
 * The RWNXAGCACI40MARG0 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] aci40margmcs1 - The value to set the field to.
 */
__INLINE void riu_aci40margmcs1_setf(uint8_t aci40margmcs1)
{
    REG_PL_WR(RIU_RWNXAGCACI40MARG0_ADDR, (REG_PL_RD(RIU_RWNXAGCACI40MARG0_ADDR) & ~((uint32_t)0x00003F00)) | ((uint32_t)aci40margmcs1 << 8));
}

/**
 * @brief Returns the current value of the ACI40MARGMCS0 field in the RWNXAGCACI40MARG0 register.
 *
 * The RWNXAGCACI40MARG0 register will be read and the ACI40MARGMCS0 field's value will be returned.
 *
 * @return The current value of the ACI40MARGMCS0 field in the RWNXAGCACI40MARG0 register.
 */
__INLINE uint8_t riu_aci40margmcs0_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCACI40MARG0_ADDR);
    return ((localVal & ((uint32_t)0x0000003F)) >> 0);
}

/**
 * @brief Sets the ACI40MARGMCS0 field of the RWNXAGCACI40MARG0 register.
 *
 * The RWNXAGCACI40MARG0 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] aci40margmcs0 - The value to set the field to.
 */
__INLINE void riu_aci40margmcs0_setf(uint8_t aci40margmcs0)
{
    REG_PL_WR(RIU_RWNXAGCACI40MARG0_ADDR, (REG_PL_RD(RIU_RWNXAGCACI40MARG0_ADDR) & ~((uint32_t)0x0000003F)) | ((uint32_t)aci40margmcs0 << 0));
}

/// @}

/**
 * @name RWNXAGCACI40MARG1 register definitions
 * <table>
 * <caption id="RWNXAGCACI40MARG1_BF">RWNXAGCACI40MARG1 bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>29:24 <td>     ACI40MARGMCS7 <td>R <td>R/W <td>0x2
 * <tr><td>21:16 <td>     ACI40MARGMCS6 <td>R <td>R/W <td>0x3
 * <tr><td>13:08 <td>     ACI40MARGMCS5 <td>R <td>R/W <td>0x3
 * <tr><td>05:00 <td>     ACI40MARGMCS4 <td>R <td>R/W <td>0x5
 * </table>
 *
 * @{
 */

/// Address of the RWNXAGCACI40MARG1 register
#define RIU_RWNXAGCACI40MARG1_ADDR   0x4033B350
/// Offset of the RWNXAGCACI40MARG1 register from the base address
#define RIU_RWNXAGCACI40MARG1_OFFSET 0x00000350
/// Index of the RWNXAGCACI40MARG1 register
#define RIU_RWNXAGCACI40MARG1_INDEX  0x000000D4
/// Reset value of the RWNXAGCACI40MARG1 register
#define RIU_RWNXAGCACI40MARG1_RESET  0x02030305

/**
 * @brief Returns the current value of the RWNXAGCACI40MARG1 register.
 * The RWNXAGCACI40MARG1 register will be read and its value returned.
 * @return The current value of the RWNXAGCACI40MARG1 register.
 */
__INLINE uint32_t riu_rwnxagcaci40marg1_get(void)
{
    return REG_PL_RD(RIU_RWNXAGCACI40MARG1_ADDR);
}

/**
 * @brief Sets the RWNXAGCACI40MARG1 register to a value.
 * The RWNXAGCACI40MARG1 register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxagcaci40marg1_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXAGCACI40MARG1_ADDR, value);
}

// field definitions
/// ACI40MARGMCS7 field mask
#define RIU_ACI40MARGMCS7_MASK   ((uint32_t)0x3F000000)
/// ACI40MARGMCS7 field LSB position
#define RIU_ACI40MARGMCS7_LSB    24
/// ACI40MARGMCS7 field width
#define RIU_ACI40MARGMCS7_WIDTH  ((uint32_t)0x00000006)
/// ACI40MARGMCS6 field mask
#define RIU_ACI40MARGMCS6_MASK   ((uint32_t)0x003F0000)
/// ACI40MARGMCS6 field LSB position
#define RIU_ACI40MARGMCS6_LSB    16
/// ACI40MARGMCS6 field width
#define RIU_ACI40MARGMCS6_WIDTH  ((uint32_t)0x00000006)
/// ACI40MARGMCS5 field mask
#define RIU_ACI40MARGMCS5_MASK   ((uint32_t)0x00003F00)
/// ACI40MARGMCS5 field LSB position
#define RIU_ACI40MARGMCS5_LSB    8
/// ACI40MARGMCS5 field width
#define RIU_ACI40MARGMCS5_WIDTH  ((uint32_t)0x00000006)
/// ACI40MARGMCS4 field mask
#define RIU_ACI40MARGMCS4_MASK   ((uint32_t)0x0000003F)
/// ACI40MARGMCS4 field LSB position
#define RIU_ACI40MARGMCS4_LSB    0
/// ACI40MARGMCS4 field width
#define RIU_ACI40MARGMCS4_WIDTH  ((uint32_t)0x00000006)

/// ACI40MARGMCS7 field reset value
#define RIU_ACI40MARGMCS7_RST    0x2
/// ACI40MARGMCS6 field reset value
#define RIU_ACI40MARGMCS6_RST    0x3
/// ACI40MARGMCS5 field reset value
#define RIU_ACI40MARGMCS5_RST    0x3
/// ACI40MARGMCS4 field reset value
#define RIU_ACI40MARGMCS4_RST    0x5

/**
 * @brief Constructs a value for the RWNXAGCACI40MARG1 register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] aci40margmcs7 - The value to use for the ACI40MARGMCS7 field.
 * @param[in] aci40margmcs6 - The value to use for the ACI40MARGMCS6 field.
 * @param[in] aci40margmcs5 - The value to use for the ACI40MARGMCS5 field.
 * @param[in] aci40margmcs4 - The value to use for the ACI40MARGMCS4 field.
 */
__INLINE void riu_rwnxagcaci40marg1_pack(uint8_t aci40margmcs7, uint8_t aci40margmcs6, uint8_t aci40margmcs5, uint8_t aci40margmcs4)
{
    REG_PL_WR(RIU_RWNXAGCACI40MARG1_ADDR,  ((uint32_t)aci40margmcs7 << 24) | ((uint32_t)aci40margmcs6 << 16) | ((uint32_t)aci40margmcs5 << 8) | ((uint32_t)aci40margmcs4 << 0));
}

/**
 * @brief Unpacks RWNXAGCACI40MARG1's fields from current value of the RWNXAGCACI40MARG1 register.
 *
 * Reads the RWNXAGCACI40MARG1 register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] aci40margmcs7 - Will be populated with the current value of this field from the register.
 * @param[out] aci40margmcs6 - Will be populated with the current value of this field from the register.
 * @param[out] aci40margmcs5 - Will be populated with the current value of this field from the register.
 * @param[out] aci40margmcs4 - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxagcaci40marg1_unpack(uint8_t* aci40margmcs7, uint8_t* aci40margmcs6, uint8_t* aci40margmcs5, uint8_t* aci40margmcs4)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCACI40MARG1_ADDR);

    *aci40margmcs7 = (localVal & ((uint32_t)0x3F000000)) >> 24;
    *aci40margmcs6 = (localVal & ((uint32_t)0x003F0000)) >> 16;
    *aci40margmcs5 = (localVal & ((uint32_t)0x00003F00)) >> 8;
    *aci40margmcs4 = (localVal & ((uint32_t)0x0000003F)) >> 0;
}

/**
 * @brief Returns the current value of the ACI40MARGMCS7 field in the RWNXAGCACI40MARG1 register.
 *
 * The RWNXAGCACI40MARG1 register will be read and the ACI40MARGMCS7 field's value will be returned.
 *
 * @return The current value of the ACI40MARGMCS7 field in the RWNXAGCACI40MARG1 register.
 */
__INLINE uint8_t riu_aci40margmcs7_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCACI40MARG1_ADDR);
    return ((localVal & ((uint32_t)0x3F000000)) >> 24);
}

/**
 * @brief Sets the ACI40MARGMCS7 field of the RWNXAGCACI40MARG1 register.
 *
 * The RWNXAGCACI40MARG1 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] aci40margmcs7 - The value to set the field to.
 */
__INLINE void riu_aci40margmcs7_setf(uint8_t aci40margmcs7)
{
    REG_PL_WR(RIU_RWNXAGCACI40MARG1_ADDR, (REG_PL_RD(RIU_RWNXAGCACI40MARG1_ADDR) & ~((uint32_t)0x3F000000)) | ((uint32_t)aci40margmcs7 << 24));
}

/**
 * @brief Returns the current value of the ACI40MARGMCS6 field in the RWNXAGCACI40MARG1 register.
 *
 * The RWNXAGCACI40MARG1 register will be read and the ACI40MARGMCS6 field's value will be returned.
 *
 * @return The current value of the ACI40MARGMCS6 field in the RWNXAGCACI40MARG1 register.
 */
__INLINE uint8_t riu_aci40margmcs6_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCACI40MARG1_ADDR);
    return ((localVal & ((uint32_t)0x003F0000)) >> 16);
}

/**
 * @brief Sets the ACI40MARGMCS6 field of the RWNXAGCACI40MARG1 register.
 *
 * The RWNXAGCACI40MARG1 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] aci40margmcs6 - The value to set the field to.
 */
__INLINE void riu_aci40margmcs6_setf(uint8_t aci40margmcs6)
{
    REG_PL_WR(RIU_RWNXAGCACI40MARG1_ADDR, (REG_PL_RD(RIU_RWNXAGCACI40MARG1_ADDR) & ~((uint32_t)0x003F0000)) | ((uint32_t)aci40margmcs6 << 16));
}

/**
 * @brief Returns the current value of the ACI40MARGMCS5 field in the RWNXAGCACI40MARG1 register.
 *
 * The RWNXAGCACI40MARG1 register will be read and the ACI40MARGMCS5 field's value will be returned.
 *
 * @return The current value of the ACI40MARGMCS5 field in the RWNXAGCACI40MARG1 register.
 */
__INLINE uint8_t riu_aci40margmcs5_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCACI40MARG1_ADDR);
    return ((localVal & ((uint32_t)0x00003F00)) >> 8);
}

/**
 * @brief Sets the ACI40MARGMCS5 field of the RWNXAGCACI40MARG1 register.
 *
 * The RWNXAGCACI40MARG1 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] aci40margmcs5 - The value to set the field to.
 */
__INLINE void riu_aci40margmcs5_setf(uint8_t aci40margmcs5)
{
    REG_PL_WR(RIU_RWNXAGCACI40MARG1_ADDR, (REG_PL_RD(RIU_RWNXAGCACI40MARG1_ADDR) & ~((uint32_t)0x00003F00)) | ((uint32_t)aci40margmcs5 << 8));
}

/**
 * @brief Returns the current value of the ACI40MARGMCS4 field in the RWNXAGCACI40MARG1 register.
 *
 * The RWNXAGCACI40MARG1 register will be read and the ACI40MARGMCS4 field's value will be returned.
 *
 * @return The current value of the ACI40MARGMCS4 field in the RWNXAGCACI40MARG1 register.
 */
__INLINE uint8_t riu_aci40margmcs4_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCACI40MARG1_ADDR);
    return ((localVal & ((uint32_t)0x0000003F)) >> 0);
}

/**
 * @brief Sets the ACI40MARGMCS4 field of the RWNXAGCACI40MARG1 register.
 *
 * The RWNXAGCACI40MARG1 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] aci40margmcs4 - The value to set the field to.
 */
__INLINE void riu_aci40margmcs4_setf(uint8_t aci40margmcs4)
{
    REG_PL_WR(RIU_RWNXAGCACI40MARG1_ADDR, (REG_PL_RD(RIU_RWNXAGCACI40MARG1_ADDR) & ~((uint32_t)0x0000003F)) | ((uint32_t)aci40margmcs4 << 0));
}

/// @}

/**
 * @name RWNXAGCACI40MARG2 register definitions
 * <table>
 * <caption id="RWNXAGCACI40MARG2_BF">RWNXAGCACI40MARG2 bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>13:08 <td>     ACI40MARGMCS9 <td>R <td>R/W <td>0x1
 * <tr><td>05:00 <td>     ACI40MARGMCS8 <td>R <td>R/W <td>0x1
 * </table>
 *
 * @{
 */

/// Address of the RWNXAGCACI40MARG2 register
#define RIU_RWNXAGCACI40MARG2_ADDR   0x4033B354
/// Offset of the RWNXAGCACI40MARG2 register from the base address
#define RIU_RWNXAGCACI40MARG2_OFFSET 0x00000354
/// Index of the RWNXAGCACI40MARG2 register
#define RIU_RWNXAGCACI40MARG2_INDEX  0x000000D5
/// Reset value of the RWNXAGCACI40MARG2 register
#define RIU_RWNXAGCACI40MARG2_RESET  0x00000101

/**
 * @brief Returns the current value of the RWNXAGCACI40MARG2 register.
 * The RWNXAGCACI40MARG2 register will be read and its value returned.
 * @return The current value of the RWNXAGCACI40MARG2 register.
 */
__INLINE uint32_t riu_rwnxagcaci40marg2_get(void)
{
    return REG_PL_RD(RIU_RWNXAGCACI40MARG2_ADDR);
}

/**
 * @brief Sets the RWNXAGCACI40MARG2 register to a value.
 * The RWNXAGCACI40MARG2 register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxagcaci40marg2_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXAGCACI40MARG2_ADDR, value);
}

// field definitions
/// ACI40MARGMCS9 field mask
#define RIU_ACI40MARGMCS9_MASK   ((uint32_t)0x00003F00)
/// ACI40MARGMCS9 field LSB position
#define RIU_ACI40MARGMCS9_LSB    8
/// ACI40MARGMCS9 field width
#define RIU_ACI40MARGMCS9_WIDTH  ((uint32_t)0x00000006)
/// ACI40MARGMCS8 field mask
#define RIU_ACI40MARGMCS8_MASK   ((uint32_t)0x0000003F)
/// ACI40MARGMCS8 field LSB position
#define RIU_ACI40MARGMCS8_LSB    0
/// ACI40MARGMCS8 field width
#define RIU_ACI40MARGMCS8_WIDTH  ((uint32_t)0x00000006)

/// ACI40MARGMCS9 field reset value
#define RIU_ACI40MARGMCS9_RST    0x1
/// ACI40MARGMCS8 field reset value
#define RIU_ACI40MARGMCS8_RST    0x1

/**
 * @brief Constructs a value for the RWNXAGCACI40MARG2 register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] aci40margmcs9 - The value to use for the ACI40MARGMCS9 field.
 * @param[in] aci40margmcs8 - The value to use for the ACI40MARGMCS8 field.
 */
__INLINE void riu_rwnxagcaci40marg2_pack(uint8_t aci40margmcs9, uint8_t aci40margmcs8)
{
    REG_PL_WR(RIU_RWNXAGCACI40MARG2_ADDR,  ((uint32_t)aci40margmcs9 << 8) | ((uint32_t)aci40margmcs8 << 0));
}

/**
 * @brief Unpacks RWNXAGCACI40MARG2's fields from current value of the RWNXAGCACI40MARG2 register.
 *
 * Reads the RWNXAGCACI40MARG2 register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] aci40margmcs9 - Will be populated with the current value of this field from the register.
 * @param[out] aci40margmcs8 - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxagcaci40marg2_unpack(uint8_t* aci40margmcs9, uint8_t* aci40margmcs8)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCACI40MARG2_ADDR);

    *aci40margmcs9 = (localVal & ((uint32_t)0x00003F00)) >> 8;
    *aci40margmcs8 = (localVal & ((uint32_t)0x0000003F)) >> 0;
}

/**
 * @brief Returns the current value of the ACI40MARGMCS9 field in the RWNXAGCACI40MARG2 register.
 *
 * The RWNXAGCACI40MARG2 register will be read and the ACI40MARGMCS9 field's value will be returned.
 *
 * @return The current value of the ACI40MARGMCS9 field in the RWNXAGCACI40MARG2 register.
 */
__INLINE uint8_t riu_aci40margmcs9_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCACI40MARG2_ADDR);
    return ((localVal & ((uint32_t)0x00003F00)) >> 8);
}

/**
 * @brief Sets the ACI40MARGMCS9 field of the RWNXAGCACI40MARG2 register.
 *
 * The RWNXAGCACI40MARG2 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] aci40margmcs9 - The value to set the field to.
 */
__INLINE void riu_aci40margmcs9_setf(uint8_t aci40margmcs9)
{
    REG_PL_WR(RIU_RWNXAGCACI40MARG2_ADDR, (REG_PL_RD(RIU_RWNXAGCACI40MARG2_ADDR) & ~((uint32_t)0x00003F00)) | ((uint32_t)aci40margmcs9 << 8));
}

/**
 * @brief Returns the current value of the ACI40MARGMCS8 field in the RWNXAGCACI40MARG2 register.
 *
 * The RWNXAGCACI40MARG2 register will be read and the ACI40MARGMCS8 field's value will be returned.
 *
 * @return The current value of the ACI40MARGMCS8 field in the RWNXAGCACI40MARG2 register.
 */
__INLINE uint8_t riu_aci40margmcs8_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCACI40MARG2_ADDR);
    return ((localVal & ((uint32_t)0x0000003F)) >> 0);
}

/**
 * @brief Sets the ACI40MARGMCS8 field of the RWNXAGCACI40MARG2 register.
 *
 * The RWNXAGCACI40MARG2 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] aci40margmcs8 - The value to set the field to.
 */
__INLINE void riu_aci40margmcs8_setf(uint8_t aci40margmcs8)
{
    REG_PL_WR(RIU_RWNXAGCACI40MARG2_ADDR, (REG_PL_RD(RIU_RWNXAGCACI40MARG2_ADDR) & ~((uint32_t)0x0000003F)) | ((uint32_t)aci40margmcs8 << 0));
}

/// @}

/**
 * @name RWNXAGCACI80MARG0 register definitions
 * <table>
 * <caption id="RWNXAGCACI80MARG0_BF">RWNXAGCACI80MARG0 bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>29:24 <td>     ACI80MARGMCS3 <td>R <td>R/W <td>0x18
 * <tr><td>21:16 <td>     ACI80MARGMCS2 <td>R <td>R/W <td>0x1B
 * <tr><td>13:08 <td>     ACI80MARGMCS1 <td>R <td>R/W <td>0x1D
 * <tr><td>05:00 <td>     ACI80MARGMCS0 <td>R <td>R/W <td>0x20
 * </table>
 *
 * @{
 */

/// Address of the RWNXAGCACI80MARG0 register
#define RIU_RWNXAGCACI80MARG0_ADDR   0x4033B358
/// Offset of the RWNXAGCACI80MARG0 register from the base address
#define RIU_RWNXAGCACI80MARG0_OFFSET 0x00000358
/// Index of the RWNXAGCACI80MARG0 register
#define RIU_RWNXAGCACI80MARG0_INDEX  0x000000D6
/// Reset value of the RWNXAGCACI80MARG0 register
#define RIU_RWNXAGCACI80MARG0_RESET  0x181B1D20

/**
 * @brief Returns the current value of the RWNXAGCACI80MARG0 register.
 * The RWNXAGCACI80MARG0 register will be read and its value returned.
 * @return The current value of the RWNXAGCACI80MARG0 register.
 */
__INLINE uint32_t riu_rwnxagcaci80marg0_get(void)
{
    return REG_PL_RD(RIU_RWNXAGCACI80MARG0_ADDR);
}

/**
 * @brief Sets the RWNXAGCACI80MARG0 register to a value.
 * The RWNXAGCACI80MARG0 register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxagcaci80marg0_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXAGCACI80MARG0_ADDR, value);
}

// field definitions
/// ACI80MARGMCS3 field mask
#define RIU_ACI80MARGMCS3_MASK   ((uint32_t)0x3F000000)
/// ACI80MARGMCS3 field LSB position
#define RIU_ACI80MARGMCS3_LSB    24
/// ACI80MARGMCS3 field width
#define RIU_ACI80MARGMCS3_WIDTH  ((uint32_t)0x00000006)
/// ACI80MARGMCS2 field mask
#define RIU_ACI80MARGMCS2_MASK   ((uint32_t)0x003F0000)
/// ACI80MARGMCS2 field LSB position
#define RIU_ACI80MARGMCS2_LSB    16
/// ACI80MARGMCS2 field width
#define RIU_ACI80MARGMCS2_WIDTH  ((uint32_t)0x00000006)
/// ACI80MARGMCS1 field mask
#define RIU_ACI80MARGMCS1_MASK   ((uint32_t)0x00003F00)
/// ACI80MARGMCS1 field LSB position
#define RIU_ACI80MARGMCS1_LSB    8
/// ACI80MARGMCS1 field width
#define RIU_ACI80MARGMCS1_WIDTH  ((uint32_t)0x00000006)
/// ACI80MARGMCS0 field mask
#define RIU_ACI80MARGMCS0_MASK   ((uint32_t)0x0000003F)
/// ACI80MARGMCS0 field LSB position
#define RIU_ACI80MARGMCS0_LSB    0
/// ACI80MARGMCS0 field width
#define RIU_ACI80MARGMCS0_WIDTH  ((uint32_t)0x00000006)

/// ACI80MARGMCS3 field reset value
#define RIU_ACI80MARGMCS3_RST    0x18
/// ACI80MARGMCS2 field reset value
#define RIU_ACI80MARGMCS2_RST    0x1B
/// ACI80MARGMCS1 field reset value
#define RIU_ACI80MARGMCS1_RST    0x1D
/// ACI80MARGMCS0 field reset value
#define RIU_ACI80MARGMCS0_RST    0x20

/**
 * @brief Constructs a value for the RWNXAGCACI80MARG0 register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] aci80margmcs3 - The value to use for the ACI80MARGMCS3 field.
 * @param[in] aci80margmcs2 - The value to use for the ACI80MARGMCS2 field.
 * @param[in] aci80margmcs1 - The value to use for the ACI80MARGMCS1 field.
 * @param[in] aci80margmcs0 - The value to use for the ACI80MARGMCS0 field.
 */
__INLINE void riu_rwnxagcaci80marg0_pack(uint8_t aci80margmcs3, uint8_t aci80margmcs2, uint8_t aci80margmcs1, uint8_t aci80margmcs0)
{
    REG_PL_WR(RIU_RWNXAGCACI80MARG0_ADDR,  ((uint32_t)aci80margmcs3 << 24) | ((uint32_t)aci80margmcs2 << 16) | ((uint32_t)aci80margmcs1 << 8) | ((uint32_t)aci80margmcs0 << 0));
}

/**
 * @brief Unpacks RWNXAGCACI80MARG0's fields from current value of the RWNXAGCACI80MARG0 register.
 *
 * Reads the RWNXAGCACI80MARG0 register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] aci80margmcs3 - Will be populated with the current value of this field from the register.
 * @param[out] aci80margmcs2 - Will be populated with the current value of this field from the register.
 * @param[out] aci80margmcs1 - Will be populated with the current value of this field from the register.
 * @param[out] aci80margmcs0 - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxagcaci80marg0_unpack(uint8_t* aci80margmcs3, uint8_t* aci80margmcs2, uint8_t* aci80margmcs1, uint8_t* aci80margmcs0)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCACI80MARG0_ADDR);

    *aci80margmcs3 = (localVal & ((uint32_t)0x3F000000)) >> 24;
    *aci80margmcs2 = (localVal & ((uint32_t)0x003F0000)) >> 16;
    *aci80margmcs1 = (localVal & ((uint32_t)0x00003F00)) >> 8;
    *aci80margmcs0 = (localVal & ((uint32_t)0x0000003F)) >> 0;
}

/**
 * @brief Returns the current value of the ACI80MARGMCS3 field in the RWNXAGCACI80MARG0 register.
 *
 * The RWNXAGCACI80MARG0 register will be read and the ACI80MARGMCS3 field's value will be returned.
 *
 * @return The current value of the ACI80MARGMCS3 field in the RWNXAGCACI80MARG0 register.
 */
__INLINE uint8_t riu_aci80margmcs3_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCACI80MARG0_ADDR);
    return ((localVal & ((uint32_t)0x3F000000)) >> 24);
}

/**
 * @brief Sets the ACI80MARGMCS3 field of the RWNXAGCACI80MARG0 register.
 *
 * The RWNXAGCACI80MARG0 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] aci80margmcs3 - The value to set the field to.
 */
__INLINE void riu_aci80margmcs3_setf(uint8_t aci80margmcs3)
{
    REG_PL_WR(RIU_RWNXAGCACI80MARG0_ADDR, (REG_PL_RD(RIU_RWNXAGCACI80MARG0_ADDR) & ~((uint32_t)0x3F000000)) | ((uint32_t)aci80margmcs3 << 24));
}

/**
 * @brief Returns the current value of the ACI80MARGMCS2 field in the RWNXAGCACI80MARG0 register.
 *
 * The RWNXAGCACI80MARG0 register will be read and the ACI80MARGMCS2 field's value will be returned.
 *
 * @return The current value of the ACI80MARGMCS2 field in the RWNXAGCACI80MARG0 register.
 */
__INLINE uint8_t riu_aci80margmcs2_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCACI80MARG0_ADDR);
    return ((localVal & ((uint32_t)0x003F0000)) >> 16);
}

/**
 * @brief Sets the ACI80MARGMCS2 field of the RWNXAGCACI80MARG0 register.
 *
 * The RWNXAGCACI80MARG0 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] aci80margmcs2 - The value to set the field to.
 */
__INLINE void riu_aci80margmcs2_setf(uint8_t aci80margmcs2)
{
    REG_PL_WR(RIU_RWNXAGCACI80MARG0_ADDR, (REG_PL_RD(RIU_RWNXAGCACI80MARG0_ADDR) & ~((uint32_t)0x003F0000)) | ((uint32_t)aci80margmcs2 << 16));
}

/**
 * @brief Returns the current value of the ACI80MARGMCS1 field in the RWNXAGCACI80MARG0 register.
 *
 * The RWNXAGCACI80MARG0 register will be read and the ACI80MARGMCS1 field's value will be returned.
 *
 * @return The current value of the ACI80MARGMCS1 field in the RWNXAGCACI80MARG0 register.
 */
__INLINE uint8_t riu_aci80margmcs1_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCACI80MARG0_ADDR);
    return ((localVal & ((uint32_t)0x00003F00)) >> 8);
}

/**
 * @brief Sets the ACI80MARGMCS1 field of the RWNXAGCACI80MARG0 register.
 *
 * The RWNXAGCACI80MARG0 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] aci80margmcs1 - The value to set the field to.
 */
__INLINE void riu_aci80margmcs1_setf(uint8_t aci80margmcs1)
{
    REG_PL_WR(RIU_RWNXAGCACI80MARG0_ADDR, (REG_PL_RD(RIU_RWNXAGCACI80MARG0_ADDR) & ~((uint32_t)0x00003F00)) | ((uint32_t)aci80margmcs1 << 8));
}

/**
 * @brief Returns the current value of the ACI80MARGMCS0 field in the RWNXAGCACI80MARG0 register.
 *
 * The RWNXAGCACI80MARG0 register will be read and the ACI80MARGMCS0 field's value will be returned.
 *
 * @return The current value of the ACI80MARGMCS0 field in the RWNXAGCACI80MARG0 register.
 */
__INLINE uint8_t riu_aci80margmcs0_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCACI80MARG0_ADDR);
    return ((localVal & ((uint32_t)0x0000003F)) >> 0);
}

/**
 * @brief Sets the ACI80MARGMCS0 field of the RWNXAGCACI80MARG0 register.
 *
 * The RWNXAGCACI80MARG0 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] aci80margmcs0 - The value to set the field to.
 */
__INLINE void riu_aci80margmcs0_setf(uint8_t aci80margmcs0)
{
    REG_PL_WR(RIU_RWNXAGCACI80MARG0_ADDR, (REG_PL_RD(RIU_RWNXAGCACI80MARG0_ADDR) & ~((uint32_t)0x0000003F)) | ((uint32_t)aci80margmcs0 << 0));
}

/// @}

/**
 * @name RWNXAGCACI80MARG1 register definitions
 * <table>
 * <caption id="RWNXAGCACI80MARG1_BF">RWNXAGCACI80MARG1 bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>29:24 <td>     ACI80MARGMCS7 <td>R <td>R/W <td>0xE
 * <tr><td>21:16 <td>     ACI80MARGMCS6 <td>R <td>R/W <td>0xF
 * <tr><td>13:08 <td>     ACI80MARGMCS5 <td>R <td>R/W <td>0x10
 * <tr><td>05:00 <td>     ACI80MARGMCS4 <td>R <td>R/W <td>0x14
 * </table>
 *
 * @{
 */

/// Address of the RWNXAGCACI80MARG1 register
#define RIU_RWNXAGCACI80MARG1_ADDR   0x4033B35C
/// Offset of the RWNXAGCACI80MARG1 register from the base address
#define RIU_RWNXAGCACI80MARG1_OFFSET 0x0000035C
/// Index of the RWNXAGCACI80MARG1 register
#define RIU_RWNXAGCACI80MARG1_INDEX  0x000000D7
/// Reset value of the RWNXAGCACI80MARG1 register
#define RIU_RWNXAGCACI80MARG1_RESET  0x0E0F1014

/**
 * @brief Returns the current value of the RWNXAGCACI80MARG1 register.
 * The RWNXAGCACI80MARG1 register will be read and its value returned.
 * @return The current value of the RWNXAGCACI80MARG1 register.
 */
__INLINE uint32_t riu_rwnxagcaci80marg1_get(void)
{
    return REG_PL_RD(RIU_RWNXAGCACI80MARG1_ADDR);
}

/**
 * @brief Sets the RWNXAGCACI80MARG1 register to a value.
 * The RWNXAGCACI80MARG1 register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxagcaci80marg1_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXAGCACI80MARG1_ADDR, value);
}

// field definitions
/// ACI80MARGMCS7 field mask
#define RIU_ACI80MARGMCS7_MASK   ((uint32_t)0x3F000000)
/// ACI80MARGMCS7 field LSB position
#define RIU_ACI80MARGMCS7_LSB    24
/// ACI80MARGMCS7 field width
#define RIU_ACI80MARGMCS7_WIDTH  ((uint32_t)0x00000006)
/// ACI80MARGMCS6 field mask
#define RIU_ACI80MARGMCS6_MASK   ((uint32_t)0x003F0000)
/// ACI80MARGMCS6 field LSB position
#define RIU_ACI80MARGMCS6_LSB    16
/// ACI80MARGMCS6 field width
#define RIU_ACI80MARGMCS6_WIDTH  ((uint32_t)0x00000006)
/// ACI80MARGMCS5 field mask
#define RIU_ACI80MARGMCS5_MASK   ((uint32_t)0x00003F00)
/// ACI80MARGMCS5 field LSB position
#define RIU_ACI80MARGMCS5_LSB    8
/// ACI80MARGMCS5 field width
#define RIU_ACI80MARGMCS5_WIDTH  ((uint32_t)0x00000006)
/// ACI80MARGMCS4 field mask
#define RIU_ACI80MARGMCS4_MASK   ((uint32_t)0x0000003F)
/// ACI80MARGMCS4 field LSB position
#define RIU_ACI80MARGMCS4_LSB    0
/// ACI80MARGMCS4 field width
#define RIU_ACI80MARGMCS4_WIDTH  ((uint32_t)0x00000006)

/// ACI80MARGMCS7 field reset value
#define RIU_ACI80MARGMCS7_RST    0xE
/// ACI80MARGMCS6 field reset value
#define RIU_ACI80MARGMCS6_RST    0xF
/// ACI80MARGMCS5 field reset value
#define RIU_ACI80MARGMCS5_RST    0x10
/// ACI80MARGMCS4 field reset value
#define RIU_ACI80MARGMCS4_RST    0x14

/**
 * @brief Constructs a value for the RWNXAGCACI80MARG1 register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] aci80margmcs7 - The value to use for the ACI80MARGMCS7 field.
 * @param[in] aci80margmcs6 - The value to use for the ACI80MARGMCS6 field.
 * @param[in] aci80margmcs5 - The value to use for the ACI80MARGMCS5 field.
 * @param[in] aci80margmcs4 - The value to use for the ACI80MARGMCS4 field.
 */
__INLINE void riu_rwnxagcaci80marg1_pack(uint8_t aci80margmcs7, uint8_t aci80margmcs6, uint8_t aci80margmcs5, uint8_t aci80margmcs4)
{
    REG_PL_WR(RIU_RWNXAGCACI80MARG1_ADDR,  ((uint32_t)aci80margmcs7 << 24) | ((uint32_t)aci80margmcs6 << 16) | ((uint32_t)aci80margmcs5 << 8) | ((uint32_t)aci80margmcs4 << 0));
}

/**
 * @brief Unpacks RWNXAGCACI80MARG1's fields from current value of the RWNXAGCACI80MARG1 register.
 *
 * Reads the RWNXAGCACI80MARG1 register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] aci80margmcs7 - Will be populated with the current value of this field from the register.
 * @param[out] aci80margmcs6 - Will be populated with the current value of this field from the register.
 * @param[out] aci80margmcs5 - Will be populated with the current value of this field from the register.
 * @param[out] aci80margmcs4 - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxagcaci80marg1_unpack(uint8_t* aci80margmcs7, uint8_t* aci80margmcs6, uint8_t* aci80margmcs5, uint8_t* aci80margmcs4)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCACI80MARG1_ADDR);

    *aci80margmcs7 = (localVal & ((uint32_t)0x3F000000)) >> 24;
    *aci80margmcs6 = (localVal & ((uint32_t)0x003F0000)) >> 16;
    *aci80margmcs5 = (localVal & ((uint32_t)0x00003F00)) >> 8;
    *aci80margmcs4 = (localVal & ((uint32_t)0x0000003F)) >> 0;
}

/**
 * @brief Returns the current value of the ACI80MARGMCS7 field in the RWNXAGCACI80MARG1 register.
 *
 * The RWNXAGCACI80MARG1 register will be read and the ACI80MARGMCS7 field's value will be returned.
 *
 * @return The current value of the ACI80MARGMCS7 field in the RWNXAGCACI80MARG1 register.
 */
__INLINE uint8_t riu_aci80margmcs7_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCACI80MARG1_ADDR);
    return ((localVal & ((uint32_t)0x3F000000)) >> 24);
}

/**
 * @brief Sets the ACI80MARGMCS7 field of the RWNXAGCACI80MARG1 register.
 *
 * The RWNXAGCACI80MARG1 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] aci80margmcs7 - The value to set the field to.
 */
__INLINE void riu_aci80margmcs7_setf(uint8_t aci80margmcs7)
{
    REG_PL_WR(RIU_RWNXAGCACI80MARG1_ADDR, (REG_PL_RD(RIU_RWNXAGCACI80MARG1_ADDR) & ~((uint32_t)0x3F000000)) | ((uint32_t)aci80margmcs7 << 24));
}

/**
 * @brief Returns the current value of the ACI80MARGMCS6 field in the RWNXAGCACI80MARG1 register.
 *
 * The RWNXAGCACI80MARG1 register will be read and the ACI80MARGMCS6 field's value will be returned.
 *
 * @return The current value of the ACI80MARGMCS6 field in the RWNXAGCACI80MARG1 register.
 */
__INLINE uint8_t riu_aci80margmcs6_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCACI80MARG1_ADDR);
    return ((localVal & ((uint32_t)0x003F0000)) >> 16);
}

/**
 * @brief Sets the ACI80MARGMCS6 field of the RWNXAGCACI80MARG1 register.
 *
 * The RWNXAGCACI80MARG1 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] aci80margmcs6 - The value to set the field to.
 */
__INLINE void riu_aci80margmcs6_setf(uint8_t aci80margmcs6)
{
    REG_PL_WR(RIU_RWNXAGCACI80MARG1_ADDR, (REG_PL_RD(RIU_RWNXAGCACI80MARG1_ADDR) & ~((uint32_t)0x003F0000)) | ((uint32_t)aci80margmcs6 << 16));
}

/**
 * @brief Returns the current value of the ACI80MARGMCS5 field in the RWNXAGCACI80MARG1 register.
 *
 * The RWNXAGCACI80MARG1 register will be read and the ACI80MARGMCS5 field's value will be returned.
 *
 * @return The current value of the ACI80MARGMCS5 field in the RWNXAGCACI80MARG1 register.
 */
__INLINE uint8_t riu_aci80margmcs5_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCACI80MARG1_ADDR);
    return ((localVal & ((uint32_t)0x00003F00)) >> 8);
}

/**
 * @brief Sets the ACI80MARGMCS5 field of the RWNXAGCACI80MARG1 register.
 *
 * The RWNXAGCACI80MARG1 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] aci80margmcs5 - The value to set the field to.
 */
__INLINE void riu_aci80margmcs5_setf(uint8_t aci80margmcs5)
{
    REG_PL_WR(RIU_RWNXAGCACI80MARG1_ADDR, (REG_PL_RD(RIU_RWNXAGCACI80MARG1_ADDR) & ~((uint32_t)0x00003F00)) | ((uint32_t)aci80margmcs5 << 8));
}

/**
 * @brief Returns the current value of the ACI80MARGMCS4 field in the RWNXAGCACI80MARG1 register.
 *
 * The RWNXAGCACI80MARG1 register will be read and the ACI80MARGMCS4 field's value will be returned.
 *
 * @return The current value of the ACI80MARGMCS4 field in the RWNXAGCACI80MARG1 register.
 */
__INLINE uint8_t riu_aci80margmcs4_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCACI80MARG1_ADDR);
    return ((localVal & ((uint32_t)0x0000003F)) >> 0);
}

/**
 * @brief Sets the ACI80MARGMCS4 field of the RWNXAGCACI80MARG1 register.
 *
 * The RWNXAGCACI80MARG1 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] aci80margmcs4 - The value to set the field to.
 */
__INLINE void riu_aci80margmcs4_setf(uint8_t aci80margmcs4)
{
    REG_PL_WR(RIU_RWNXAGCACI80MARG1_ADDR, (REG_PL_RD(RIU_RWNXAGCACI80MARG1_ADDR) & ~((uint32_t)0x0000003F)) | ((uint32_t)aci80margmcs4 << 0));
}

/// @}

/**
 * @name RWNXAGCACI80MARG2 register definitions
 * <table>
 * <caption id="RWNXAGCACI80MARG2_BF">RWNXAGCACI80MARG2 bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>13:08 <td>     ACI80MARGMCS9 <td>R <td>R/W <td>0x8
 * <tr><td>05:00 <td>     ACI80MARGMCS8 <td>R <td>R/W <td>0xA
 * </table>
 *
 * @{
 */

/// Address of the RWNXAGCACI80MARG2 register
#define RIU_RWNXAGCACI80MARG2_ADDR   0x4033B360
/// Offset of the RWNXAGCACI80MARG2 register from the base address
#define RIU_RWNXAGCACI80MARG2_OFFSET 0x00000360
/// Index of the RWNXAGCACI80MARG2 register
#define RIU_RWNXAGCACI80MARG2_INDEX  0x000000D8
/// Reset value of the RWNXAGCACI80MARG2 register
#define RIU_RWNXAGCACI80MARG2_RESET  0x0000080A

/**
 * @brief Returns the current value of the RWNXAGCACI80MARG2 register.
 * The RWNXAGCACI80MARG2 register will be read and its value returned.
 * @return The current value of the RWNXAGCACI80MARG2 register.
 */
__INLINE uint32_t riu_rwnxagcaci80marg2_get(void)
{
    return REG_PL_RD(RIU_RWNXAGCACI80MARG2_ADDR);
}

/**
 * @brief Sets the RWNXAGCACI80MARG2 register to a value.
 * The RWNXAGCACI80MARG2 register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxagcaci80marg2_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXAGCACI80MARG2_ADDR, value);
}

// field definitions
/// ACI80MARGMCS9 field mask
#define RIU_ACI80MARGMCS9_MASK   ((uint32_t)0x00003F00)
/// ACI80MARGMCS9 field LSB position
#define RIU_ACI80MARGMCS9_LSB    8
/// ACI80MARGMCS9 field width
#define RIU_ACI80MARGMCS9_WIDTH  ((uint32_t)0x00000006)
/// ACI80MARGMCS8 field mask
#define RIU_ACI80MARGMCS8_MASK   ((uint32_t)0x0000003F)
/// ACI80MARGMCS8 field LSB position
#define RIU_ACI80MARGMCS8_LSB    0
/// ACI80MARGMCS8 field width
#define RIU_ACI80MARGMCS8_WIDTH  ((uint32_t)0x00000006)

/// ACI80MARGMCS9 field reset value
#define RIU_ACI80MARGMCS9_RST    0x8
/// ACI80MARGMCS8 field reset value
#define RIU_ACI80MARGMCS8_RST    0xA

/**
 * @brief Constructs a value for the RWNXAGCACI80MARG2 register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] aci80margmcs9 - The value to use for the ACI80MARGMCS9 field.
 * @param[in] aci80margmcs8 - The value to use for the ACI80MARGMCS8 field.
 */
__INLINE void riu_rwnxagcaci80marg2_pack(uint8_t aci80margmcs9, uint8_t aci80margmcs8)
{
    REG_PL_WR(RIU_RWNXAGCACI80MARG2_ADDR,  ((uint32_t)aci80margmcs9 << 8) | ((uint32_t)aci80margmcs8 << 0));
}

/**
 * @brief Unpacks RWNXAGCACI80MARG2's fields from current value of the RWNXAGCACI80MARG2 register.
 *
 * Reads the RWNXAGCACI80MARG2 register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] aci80margmcs9 - Will be populated with the current value of this field from the register.
 * @param[out] aci80margmcs8 - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxagcaci80marg2_unpack(uint8_t* aci80margmcs9, uint8_t* aci80margmcs8)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCACI80MARG2_ADDR);

    *aci80margmcs9 = (localVal & ((uint32_t)0x00003F00)) >> 8;
    *aci80margmcs8 = (localVal & ((uint32_t)0x0000003F)) >> 0;
}

/**
 * @brief Returns the current value of the ACI80MARGMCS9 field in the RWNXAGCACI80MARG2 register.
 *
 * The RWNXAGCACI80MARG2 register will be read and the ACI80MARGMCS9 field's value will be returned.
 *
 * @return The current value of the ACI80MARGMCS9 field in the RWNXAGCACI80MARG2 register.
 */
__INLINE uint8_t riu_aci80margmcs9_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCACI80MARG2_ADDR);
    return ((localVal & ((uint32_t)0x00003F00)) >> 8);
}

/**
 * @brief Sets the ACI80MARGMCS9 field of the RWNXAGCACI80MARG2 register.
 *
 * The RWNXAGCACI80MARG2 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] aci80margmcs9 - The value to set the field to.
 */
__INLINE void riu_aci80margmcs9_setf(uint8_t aci80margmcs9)
{
    REG_PL_WR(RIU_RWNXAGCACI80MARG2_ADDR, (REG_PL_RD(RIU_RWNXAGCACI80MARG2_ADDR) & ~((uint32_t)0x00003F00)) | ((uint32_t)aci80margmcs9 << 8));
}

/**
 * @brief Returns the current value of the ACI80MARGMCS8 field in the RWNXAGCACI80MARG2 register.
 *
 * The RWNXAGCACI80MARG2 register will be read and the ACI80MARGMCS8 field's value will be returned.
 *
 * @return The current value of the ACI80MARGMCS8 field in the RWNXAGCACI80MARG2 register.
 */
__INLINE uint8_t riu_aci80margmcs8_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCACI80MARG2_ADDR);
    return ((localVal & ((uint32_t)0x0000003F)) >> 0);
}

/**
 * @brief Sets the ACI80MARGMCS8 field of the RWNXAGCACI80MARG2 register.
 *
 * The RWNXAGCACI80MARG2 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] aci80margmcs8 - The value to set the field to.
 */
__INLINE void riu_aci80margmcs8_setf(uint8_t aci80margmcs8)
{
    REG_PL_WR(RIU_RWNXAGCACI80MARG2_ADDR, (REG_PL_RD(RIU_RWNXAGCACI80MARG2_ADDR) & ~((uint32_t)0x0000003F)) | ((uint32_t)aci80margmcs8 << 0));
}

/// @}

/**
 * @name RWNXAGCSAT register definitions
 * <table>
 * <caption id="RWNXAGCSAT_BF">RWNXAGCSAT bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>28:24 <td>      SATDELAY50NS <td>R <td>R/W <td>0x8
 * <tr><td>21:16 <td>     SATHIGHTHRDBV <td>R <td>R/W <td>0x39
 * <tr><td>13:08 <td>      SATLOWTHRDBV <td>R <td>R/W <td>0x35
 * <tr><td>05:00 <td>         SATTHRDBV <td>R <td>R/W <td>0x36
 * </table>
 *
 * @{
 */

/// Address of the RWNXAGCSAT register
#define RIU_RWNXAGCSAT_ADDR   0x4033B364
/// Offset of the RWNXAGCSAT register from the base address
#define RIU_RWNXAGCSAT_OFFSET 0x00000364
/// Index of the RWNXAGCSAT register
#define RIU_RWNXAGCSAT_INDEX  0x000000D9
/// Reset value of the RWNXAGCSAT register
#define RIU_RWNXAGCSAT_RESET  0x08393536

/**
 * @brief Returns the current value of the RWNXAGCSAT register.
 * The RWNXAGCSAT register will be read and its value returned.
 * @return The current value of the RWNXAGCSAT register.
 */
__INLINE uint32_t riu_rwnxagcsat_get(void)
{
    return REG_PL_RD(RIU_RWNXAGCSAT_ADDR);
}

/**
 * @brief Sets the RWNXAGCSAT register to a value.
 * The RWNXAGCSAT register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxagcsat_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXAGCSAT_ADDR, value);
}

// field definitions
/// SATDELAY50NS field mask
#define RIU_SATDELAY50NS_MASK    ((uint32_t)0x1F000000)
/// SATDELAY50NS field LSB position
#define RIU_SATDELAY50NS_LSB     24
/// SATDELAY50NS field width
#define RIU_SATDELAY50NS_WIDTH   ((uint32_t)0x00000005)
/// SATHIGHTHRDBV field mask
#define RIU_SATHIGHTHRDBV_MASK   ((uint32_t)0x003F0000)
/// SATHIGHTHRDBV field LSB position
#define RIU_SATHIGHTHRDBV_LSB    16
/// SATHIGHTHRDBV field width
#define RIU_SATHIGHTHRDBV_WIDTH  ((uint32_t)0x00000006)
/// SATLOWTHRDBV field mask
#define RIU_SATLOWTHRDBV_MASK    ((uint32_t)0x00003F00)
/// SATLOWTHRDBV field LSB position
#define RIU_SATLOWTHRDBV_LSB     8
/// SATLOWTHRDBV field width
#define RIU_SATLOWTHRDBV_WIDTH   ((uint32_t)0x00000006)
/// SATTHRDBV field mask
#define RIU_SATTHRDBV_MASK       ((uint32_t)0x0000003F)
/// SATTHRDBV field LSB position
#define RIU_SATTHRDBV_LSB        0
/// SATTHRDBV field width
#define RIU_SATTHRDBV_WIDTH      ((uint32_t)0x00000006)

/// SATDELAY50NS field reset value
#define RIU_SATDELAY50NS_RST     0x8
/// SATHIGHTHRDBV field reset value
#define RIU_SATHIGHTHRDBV_RST    0x39
/// SATLOWTHRDBV field reset value
#define RIU_SATLOWTHRDBV_RST     0x35
/// SATTHRDBV field reset value
#define RIU_SATTHRDBV_RST        0x36

/**
 * @brief Constructs a value for the RWNXAGCSAT register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] satdelay50ns - The value to use for the SATDELAY50NS field.
 * @param[in] sathighthrdbv - The value to use for the SATHIGHTHRDBV field.
 * @param[in] satlowthrdbv - The value to use for the SATLOWTHRDBV field.
 * @param[in] satthrdbv - The value to use for the SATTHRDBV field.
 */
__INLINE void riu_rwnxagcsat_pack(uint8_t satdelay50ns, uint8_t sathighthrdbv, uint8_t satlowthrdbv, uint8_t satthrdbv)
{
    REG_PL_WR(RIU_RWNXAGCSAT_ADDR,  ((uint32_t)satdelay50ns << 24) | ((uint32_t)sathighthrdbv << 16) | ((uint32_t)satlowthrdbv << 8) | ((uint32_t)satthrdbv << 0));
}

/**
 * @brief Unpacks RWNXAGCSAT's fields from current value of the RWNXAGCSAT register.
 *
 * Reads the RWNXAGCSAT register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] satdelay50ns - Will be populated with the current value of this field from the register.
 * @param[out] sathighthrdbv - Will be populated with the current value of this field from the register.
 * @param[out] satlowthrdbv - Will be populated with the current value of this field from the register.
 * @param[out] satthrdbv - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxagcsat_unpack(uint8_t* satdelay50ns, uint8_t* sathighthrdbv, uint8_t* satlowthrdbv, uint8_t* satthrdbv)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCSAT_ADDR);

    *satdelay50ns = (localVal & ((uint32_t)0x1F000000)) >> 24;
    *sathighthrdbv = (localVal & ((uint32_t)0x003F0000)) >> 16;
    *satlowthrdbv = (localVal & ((uint32_t)0x00003F00)) >> 8;
    *satthrdbv = (localVal & ((uint32_t)0x0000003F)) >> 0;
}

/**
 * @brief Returns the current value of the SATDELAY50NS field in the RWNXAGCSAT register.
 *
 * The RWNXAGCSAT register will be read and the SATDELAY50NS field's value will be returned.
 *
 * @return The current value of the SATDELAY50NS field in the RWNXAGCSAT register.
 */
__INLINE uint8_t riu_satdelay50ns_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCSAT_ADDR);
    return ((localVal & ((uint32_t)0x1F000000)) >> 24);
}

/**
 * @brief Sets the SATDELAY50NS field of the RWNXAGCSAT register.
 *
 * The RWNXAGCSAT register will be read, modified to contain the new field value, and written.
 *
 * @param[in] satdelay50ns - The value to set the field to.
 */
__INLINE void riu_satdelay50ns_setf(uint8_t satdelay50ns)
{
    REG_PL_WR(RIU_RWNXAGCSAT_ADDR, (REG_PL_RD(RIU_RWNXAGCSAT_ADDR) & ~((uint32_t)0x1F000000)) | ((uint32_t)satdelay50ns << 24));
}

/**
 * @brief Returns the current value of the SATHIGHTHRDBV field in the RWNXAGCSAT register.
 *
 * The RWNXAGCSAT register will be read and the SATHIGHTHRDBV field's value will be returned.
 *
 * @return The current value of the SATHIGHTHRDBV field in the RWNXAGCSAT register.
 */
__INLINE uint8_t riu_sathighthrdbv_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCSAT_ADDR);
    return ((localVal & ((uint32_t)0x003F0000)) >> 16);
}

/**
 * @brief Sets the SATHIGHTHRDBV field of the RWNXAGCSAT register.
 *
 * The RWNXAGCSAT register will be read, modified to contain the new field value, and written.
 *
 * @param[in] sathighthrdbv - The value to set the field to.
 */
__INLINE void riu_sathighthrdbv_setf(uint8_t sathighthrdbv)
{
    REG_PL_WR(RIU_RWNXAGCSAT_ADDR, (REG_PL_RD(RIU_RWNXAGCSAT_ADDR) & ~((uint32_t)0x003F0000)) | ((uint32_t)sathighthrdbv << 16));
}

/**
 * @brief Returns the current value of the SATLOWTHRDBV field in the RWNXAGCSAT register.
 *
 * The RWNXAGCSAT register will be read and the SATLOWTHRDBV field's value will be returned.
 *
 * @return The current value of the SATLOWTHRDBV field in the RWNXAGCSAT register.
 */
__INLINE uint8_t riu_satlowthrdbv_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCSAT_ADDR);
    return ((localVal & ((uint32_t)0x00003F00)) >> 8);
}

/**
 * @brief Sets the SATLOWTHRDBV field of the RWNXAGCSAT register.
 *
 * The RWNXAGCSAT register will be read, modified to contain the new field value, and written.
 *
 * @param[in] satlowthrdbv - The value to set the field to.
 */
__INLINE void riu_satlowthrdbv_setf(uint8_t satlowthrdbv)
{
    REG_PL_WR(RIU_RWNXAGCSAT_ADDR, (REG_PL_RD(RIU_RWNXAGCSAT_ADDR) & ~((uint32_t)0x00003F00)) | ((uint32_t)satlowthrdbv << 8));
}

/**
 * @brief Returns the current value of the SATTHRDBV field in the RWNXAGCSAT register.
 *
 * The RWNXAGCSAT register will be read and the SATTHRDBV field's value will be returned.
 *
 * @return The current value of the SATTHRDBV field in the RWNXAGCSAT register.
 */
__INLINE uint8_t riu_satthrdbv_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCSAT_ADDR);
    return ((localVal & ((uint32_t)0x0000003F)) >> 0);
}

/**
 * @brief Sets the SATTHRDBV field of the RWNXAGCSAT register.
 *
 * The RWNXAGCSAT register will be read, modified to contain the new field value, and written.
 *
 * @param[in] satthrdbv - The value to set the field to.
 */
__INLINE void riu_satthrdbv_setf(uint8_t satthrdbv)
{
    REG_PL_WR(RIU_RWNXAGCSAT_ADDR, (REG_PL_RD(RIU_RWNXAGCSAT_ADDR) & ~((uint32_t)0x0000003F)) | ((uint32_t)satthrdbv << 0));
}

/// @}

/**
 * @name RWNXAGCCROSS register definitions
 * <table>
 * <caption id="RWNXAGCCROSS_BF">RWNXAGCCROSS bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>21:12 <td>    CROSSDNTHRQDBM <td>R <td>R/W <td>0x288
 * <tr><td>09:00 <td>    CROSSUPTHRQDBM <td>R <td>R/W <td>0x288
 * </table>
 *
 * @{
 */

/// Address of the RWNXAGCCROSS register
#define RIU_RWNXAGCCROSS_ADDR   0x4033B368
/// Offset of the RWNXAGCCROSS register from the base address
#define RIU_RWNXAGCCROSS_OFFSET 0x00000368
/// Index of the RWNXAGCCROSS register
#define RIU_RWNXAGCCROSS_INDEX  0x000000DA
/// Reset value of the RWNXAGCCROSS register
#define RIU_RWNXAGCCROSS_RESET  0x00288288

/**
 * @brief Returns the current value of the RWNXAGCCROSS register.
 * The RWNXAGCCROSS register will be read and its value returned.
 * @return The current value of the RWNXAGCCROSS register.
 */
__INLINE uint32_t riu_rwnxagccross_get(void)
{
    return REG_PL_RD(RIU_RWNXAGCCROSS_ADDR);
}

/**
 * @brief Sets the RWNXAGCCROSS register to a value.
 * The RWNXAGCCROSS register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxagccross_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXAGCCROSS_ADDR, value);
}

// field definitions
/// CROSSDNTHRQDBM field mask
#define RIU_CROSSDNTHRQDBM_MASK   ((uint32_t)0x003FF000)
/// CROSSDNTHRQDBM field LSB position
#define RIU_CROSSDNTHRQDBM_LSB    12
/// CROSSDNTHRQDBM field width
#define RIU_CROSSDNTHRQDBM_WIDTH  ((uint32_t)0x0000000A)
/// CROSSUPTHRQDBM field mask
#define RIU_CROSSUPTHRQDBM_MASK   ((uint32_t)0x000003FF)
/// CROSSUPTHRQDBM field LSB position
#define RIU_CROSSUPTHRQDBM_LSB    0
/// CROSSUPTHRQDBM field width
#define RIU_CROSSUPTHRQDBM_WIDTH  ((uint32_t)0x0000000A)

/// CROSSDNTHRQDBM field reset value
#define RIU_CROSSDNTHRQDBM_RST    0x288
/// CROSSUPTHRQDBM field reset value
#define RIU_CROSSUPTHRQDBM_RST    0x288

/**
 * @brief Constructs a value for the RWNXAGCCROSS register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] crossdnthrqdbm - The value to use for the CROSSDNTHRQDBM field.
 * @param[in] crossupthrqdbm - The value to use for the CROSSUPTHRQDBM field.
 */
__INLINE void riu_rwnxagccross_pack(uint16_t crossdnthrqdbm, uint16_t crossupthrqdbm)
{
    REG_PL_WR(RIU_RWNXAGCCROSS_ADDR,  ((uint32_t)crossdnthrqdbm << 12) | ((uint32_t)crossupthrqdbm << 0));
}

/**
 * @brief Unpacks RWNXAGCCROSS's fields from current value of the RWNXAGCCROSS register.
 *
 * Reads the RWNXAGCCROSS register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] crossdnthrqdbm - Will be populated with the current value of this field from the register.
 * @param[out] crossupthrqdbm - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxagccross_unpack(uint16_t* crossdnthrqdbm, uint16_t* crossupthrqdbm)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCCROSS_ADDR);

    *crossdnthrqdbm = (localVal & ((uint32_t)0x003FF000)) >> 12;
    *crossupthrqdbm = (localVal & ((uint32_t)0x000003FF)) >> 0;
}

/**
 * @brief Returns the current value of the CROSSDNTHRQDBM field in the RWNXAGCCROSS register.
 *
 * The RWNXAGCCROSS register will be read and the CROSSDNTHRQDBM field's value will be returned.
 *
 * @return The current value of the CROSSDNTHRQDBM field in the RWNXAGCCROSS register.
 */
__INLINE uint16_t riu_crossdnthrqdbm_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCCROSS_ADDR);
    return ((localVal & ((uint32_t)0x003FF000)) >> 12);
}

/**
 * @brief Sets the CROSSDNTHRQDBM field of the RWNXAGCCROSS register.
 *
 * The RWNXAGCCROSS register will be read, modified to contain the new field value, and written.
 *
 * @param[in] crossdnthrqdbm - The value to set the field to.
 */
__INLINE void riu_crossdnthrqdbm_setf(uint16_t crossdnthrqdbm)
{
    REG_PL_WR(RIU_RWNXAGCCROSS_ADDR, (REG_PL_RD(RIU_RWNXAGCCROSS_ADDR) & ~((uint32_t)0x003FF000)) | ((uint32_t)crossdnthrqdbm << 12));
}

/**
 * @brief Returns the current value of the CROSSUPTHRQDBM field in the RWNXAGCCROSS register.
 *
 * The RWNXAGCCROSS register will be read and the CROSSUPTHRQDBM field's value will be returned.
 *
 * @return The current value of the CROSSUPTHRQDBM field in the RWNXAGCCROSS register.
 */
__INLINE uint16_t riu_crossupthrqdbm_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCCROSS_ADDR);
    return ((localVal & ((uint32_t)0x000003FF)) >> 0);
}

/**
 * @brief Sets the CROSSUPTHRQDBM field of the RWNXAGCCROSS register.
 *
 * The RWNXAGCCROSS register will be read, modified to contain the new field value, and written.
 *
 * @param[in] crossupthrqdbm - The value to set the field to.
 */
__INLINE void riu_crossupthrqdbm_setf(uint16_t crossupthrqdbm)
{
    REG_PL_WR(RIU_RWNXAGCCROSS_ADDR, (REG_PL_RD(RIU_RWNXAGCCROSS_ADDR) & ~((uint32_t)0x000003FF)) | ((uint32_t)crossupthrqdbm << 0));
}

/// @}

/**
 * @name RWNXAGCRAMP register definitions
 * <table>
 * <caption id="RWNXAGCRAMP_BF">RWNXAGCRAMP bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>26:24 <td>    RAMPDNNDLINDEX <td>R <td>R/W <td>0x5
 * <tr><td>23:16 <td>      RAMPDNGAPQDB <td>R <td>R/W <td>0x20
 * <tr><td>10:08 <td>    RAMPUPNDLINDEX <td>R <td>R/W <td>0x7
 * <tr><td>07:00 <td>      RAMPUPGAPQDB <td>R <td>R/W <td>0x10
 * </table>
 *
 * @{
 */

/// Address of the RWNXAGCRAMP register
#define RIU_RWNXAGCRAMP_ADDR   0x4033B36C
/// Offset of the RWNXAGCRAMP register from the base address
#define RIU_RWNXAGCRAMP_OFFSET 0x0000036C
/// Index of the RWNXAGCRAMP register
#define RIU_RWNXAGCRAMP_INDEX  0x000000DB
/// Reset value of the RWNXAGCRAMP register
#define RIU_RWNXAGCRAMP_RESET  0x05200710

/**
 * @brief Returns the current value of the RWNXAGCRAMP register.
 * The RWNXAGCRAMP register will be read and its value returned.
 * @return The current value of the RWNXAGCRAMP register.
 */
__INLINE uint32_t riu_rwnxagcramp_get(void)
{
    return REG_PL_RD(RIU_RWNXAGCRAMP_ADDR);
}

/**
 * @brief Sets the RWNXAGCRAMP register to a value.
 * The RWNXAGCRAMP register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxagcramp_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXAGCRAMP_ADDR, value);
}

// field definitions
/// RAMPDNNDLINDEX field mask
#define RIU_RAMPDNNDLINDEX_MASK   ((uint32_t)0x07000000)
/// RAMPDNNDLINDEX field LSB position
#define RIU_RAMPDNNDLINDEX_LSB    24
/// RAMPDNNDLINDEX field width
#define RIU_RAMPDNNDLINDEX_WIDTH  ((uint32_t)0x00000003)
/// RAMPDNGAPQDB field mask
#define RIU_RAMPDNGAPQDB_MASK     ((uint32_t)0x00FF0000)
/// RAMPDNGAPQDB field LSB position
#define RIU_RAMPDNGAPQDB_LSB      16
/// RAMPDNGAPQDB field width
#define RIU_RAMPDNGAPQDB_WIDTH    ((uint32_t)0x00000008)
/// RAMPUPNDLINDEX field mask
#define RIU_RAMPUPNDLINDEX_MASK   ((uint32_t)0x00000700)
/// RAMPUPNDLINDEX field LSB position
#define RIU_RAMPUPNDLINDEX_LSB    8
/// RAMPUPNDLINDEX field width
#define RIU_RAMPUPNDLINDEX_WIDTH  ((uint32_t)0x00000003)
/// RAMPUPGAPQDB field mask
#define RIU_RAMPUPGAPQDB_MASK     ((uint32_t)0x000000FF)
/// RAMPUPGAPQDB field LSB position
#define RIU_RAMPUPGAPQDB_LSB      0
/// RAMPUPGAPQDB field width
#define RIU_RAMPUPGAPQDB_WIDTH    ((uint32_t)0x00000008)

/// RAMPDNNDLINDEX field reset value
#define RIU_RAMPDNNDLINDEX_RST    0x5
/// RAMPDNGAPQDB field reset value
#define RIU_RAMPDNGAPQDB_RST      0x20
/// RAMPUPNDLINDEX field reset value
#define RIU_RAMPUPNDLINDEX_RST    0x7
/// RAMPUPGAPQDB field reset value
#define RIU_RAMPUPGAPQDB_RST      0x10

/**
 * @brief Constructs a value for the RWNXAGCRAMP register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] rampdnndlindex - The value to use for the RAMPDNNDLINDEX field.
 * @param[in] rampdngapqdb - The value to use for the RAMPDNGAPQDB field.
 * @param[in] rampupndlindex - The value to use for the RAMPUPNDLINDEX field.
 * @param[in] rampupgapqdb - The value to use for the RAMPUPGAPQDB field.
 */
__INLINE void riu_rwnxagcramp_pack(uint8_t rampdnndlindex, uint8_t rampdngapqdb, uint8_t rampupndlindex, uint8_t rampupgapqdb)
{
    REG_PL_WR(RIU_RWNXAGCRAMP_ADDR,  ((uint32_t)rampdnndlindex << 24) | ((uint32_t)rampdngapqdb << 16) | ((uint32_t)rampupndlindex << 8) | ((uint32_t)rampupgapqdb << 0));
}

/**
 * @brief Unpacks RWNXAGCRAMP's fields from current value of the RWNXAGCRAMP register.
 *
 * Reads the RWNXAGCRAMP register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] rampdnndlindex - Will be populated with the current value of this field from the register.
 * @param[out] rampdngapqdb - Will be populated with the current value of this field from the register.
 * @param[out] rampupndlindex - Will be populated with the current value of this field from the register.
 * @param[out] rampupgapqdb - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxagcramp_unpack(uint8_t* rampdnndlindex, uint8_t* rampdngapqdb, uint8_t* rampupndlindex, uint8_t* rampupgapqdb)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCRAMP_ADDR);

    *rampdnndlindex = (localVal & ((uint32_t)0x07000000)) >> 24;
    *rampdngapqdb = (localVal & ((uint32_t)0x00FF0000)) >> 16;
    *rampupndlindex = (localVal & ((uint32_t)0x00000700)) >> 8;
    *rampupgapqdb = (localVal & ((uint32_t)0x000000FF)) >> 0;
}

/**
 * @brief Returns the current value of the RAMPDNNDLINDEX field in the RWNXAGCRAMP register.
 *
 * The RWNXAGCRAMP register will be read and the RAMPDNNDLINDEX field's value will be returned.
 *
 * @return The current value of the RAMPDNNDLINDEX field in the RWNXAGCRAMP register.
 */
__INLINE uint8_t riu_rampdnndlindex_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCRAMP_ADDR);
    return ((localVal & ((uint32_t)0x07000000)) >> 24);
}

/**
 * @brief Sets the RAMPDNNDLINDEX field of the RWNXAGCRAMP register.
 *
 * The RWNXAGCRAMP register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rampdnndlindex - The value to set the field to.
 */
__INLINE void riu_rampdnndlindex_setf(uint8_t rampdnndlindex)
{
    REG_PL_WR(RIU_RWNXAGCRAMP_ADDR, (REG_PL_RD(RIU_RWNXAGCRAMP_ADDR) & ~((uint32_t)0x07000000)) | ((uint32_t)rampdnndlindex << 24));
}

/**
 * @brief Returns the current value of the RAMPDNGAPQDB field in the RWNXAGCRAMP register.
 *
 * The RWNXAGCRAMP register will be read and the RAMPDNGAPQDB field's value will be returned.
 *
 * @return The current value of the RAMPDNGAPQDB field in the RWNXAGCRAMP register.
 */
__INLINE uint8_t riu_rampdngapqdb_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCRAMP_ADDR);
    return ((localVal & ((uint32_t)0x00FF0000)) >> 16);
}

/**
 * @brief Sets the RAMPDNGAPQDB field of the RWNXAGCRAMP register.
 *
 * The RWNXAGCRAMP register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rampdngapqdb - The value to set the field to.
 */
__INLINE void riu_rampdngapqdb_setf(uint8_t rampdngapqdb)
{
    REG_PL_WR(RIU_RWNXAGCRAMP_ADDR, (REG_PL_RD(RIU_RWNXAGCRAMP_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)rampdngapqdb << 16));
}

/**
 * @brief Returns the current value of the RAMPUPNDLINDEX field in the RWNXAGCRAMP register.
 *
 * The RWNXAGCRAMP register will be read and the RAMPUPNDLINDEX field's value will be returned.
 *
 * @return The current value of the RAMPUPNDLINDEX field in the RWNXAGCRAMP register.
 */
__INLINE uint8_t riu_rampupndlindex_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCRAMP_ADDR);
    return ((localVal & ((uint32_t)0x00000700)) >> 8);
}

/**
 * @brief Sets the RAMPUPNDLINDEX field of the RWNXAGCRAMP register.
 *
 * The RWNXAGCRAMP register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rampupndlindex - The value to set the field to.
 */
__INLINE void riu_rampupndlindex_setf(uint8_t rampupndlindex)
{
    REG_PL_WR(RIU_RWNXAGCRAMP_ADDR, (REG_PL_RD(RIU_RWNXAGCRAMP_ADDR) & ~((uint32_t)0x00000700)) | ((uint32_t)rampupndlindex << 8));
}

/**
 * @brief Returns the current value of the RAMPUPGAPQDB field in the RWNXAGCRAMP register.
 *
 * The RWNXAGCRAMP register will be read and the RAMPUPGAPQDB field's value will be returned.
 *
 * @return The current value of the RAMPUPGAPQDB field in the RWNXAGCRAMP register.
 */
__INLINE uint8_t riu_rampupgapqdb_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCRAMP_ADDR);
    return ((localVal & ((uint32_t)0x000000FF)) >> 0);
}

/**
 * @brief Sets the RAMPUPGAPQDB field of the RWNXAGCRAMP register.
 *
 * The RWNXAGCRAMP register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rampupgapqdb - The value to set the field to.
 */
__INLINE void riu_rampupgapqdb_setf(uint8_t rampupgapqdb)
{
    REG_PL_WR(RIU_RWNXAGCRAMP_ADDR, (REG_PL_RD(RIU_RWNXAGCRAMP_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)rampupgapqdb << 0));
}

/// @}

/**
 * @name RWNXAGCSTABDIS register definitions
 * <table>
 * <caption id="RWNXAGCSTABDIS_BF">RWNXAGCSTABDIS bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>27:24 <td>      ADCPOWDISNDL <td>R <td>R/W <td>0x8
 * <tr><td>22:16 <td>   ADCPOWDISTHRDBV <td>R <td>R/W <td>0x54
 * <tr><td>10:08 <td>      PLATNDLINDEX <td>R <td>R/W <td>0x3
 * <tr><td>04:00 <td>         PLATDPQDB <td>R <td>R/W <td>0x8
 * </table>
 *
 * @{
 */

/// Address of the RWNXAGCSTABDIS register
#define RIU_RWNXAGCSTABDIS_ADDR   0x4033B370
/// Offset of the RWNXAGCSTABDIS register from the base address
#define RIU_RWNXAGCSTABDIS_OFFSET 0x00000370
/// Index of the RWNXAGCSTABDIS register
#define RIU_RWNXAGCSTABDIS_INDEX  0x000000DC
/// Reset value of the RWNXAGCSTABDIS register
#define RIU_RWNXAGCSTABDIS_RESET  0x08540308

/**
 * @brief Returns the current value of the RWNXAGCSTABDIS register.
 * The RWNXAGCSTABDIS register will be read and its value returned.
 * @return The current value of the RWNXAGCSTABDIS register.
 */
__INLINE uint32_t riu_rwnxagcstabdis_get(void)
{
    return REG_PL_RD(RIU_RWNXAGCSTABDIS_ADDR);
}

/**
 * @brief Sets the RWNXAGCSTABDIS register to a value.
 * The RWNXAGCSTABDIS register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxagcstabdis_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXAGCSTABDIS_ADDR, value);
}

// field definitions
/// ADCPOWDISNDL field mask
#define RIU_ADCPOWDISNDL_MASK      ((uint32_t)0x0F000000)
/// ADCPOWDISNDL field LSB position
#define RIU_ADCPOWDISNDL_LSB       24
/// ADCPOWDISNDL field width
#define RIU_ADCPOWDISNDL_WIDTH     ((uint32_t)0x00000004)
/// ADCPOWDISTHRDBV field mask
#define RIU_ADCPOWDISTHRDBV_MASK   ((uint32_t)0x007F0000)
/// ADCPOWDISTHRDBV field LSB position
#define RIU_ADCPOWDISTHRDBV_LSB    16
/// ADCPOWDISTHRDBV field width
#define RIU_ADCPOWDISTHRDBV_WIDTH  ((uint32_t)0x00000007)
/// PLATNDLINDEX field mask
#define RIU_PLATNDLINDEX_MASK      ((uint32_t)0x00000700)
/// PLATNDLINDEX field LSB position
#define RIU_PLATNDLINDEX_LSB       8
/// PLATNDLINDEX field width
#define RIU_PLATNDLINDEX_WIDTH     ((uint32_t)0x00000003)
/// PLATDPQDB field mask
#define RIU_PLATDPQDB_MASK         ((uint32_t)0x0000001F)
/// PLATDPQDB field LSB position
#define RIU_PLATDPQDB_LSB          0
/// PLATDPQDB field width
#define RIU_PLATDPQDB_WIDTH        ((uint32_t)0x00000005)

/// ADCPOWDISNDL field reset value
#define RIU_ADCPOWDISNDL_RST       0x8
/// ADCPOWDISTHRDBV field reset value
#define RIU_ADCPOWDISTHRDBV_RST    0x54
/// PLATNDLINDEX field reset value
#define RIU_PLATNDLINDEX_RST       0x3
/// PLATDPQDB field reset value
#define RIU_PLATDPQDB_RST          0x8

/**
 * @brief Constructs a value for the RWNXAGCSTABDIS register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] adcpowdisndl - The value to use for the ADCPOWDISNDL field.
 * @param[in] adcpowdisthrdbv - The value to use for the ADCPOWDISTHRDBV field.
 * @param[in] platndlindex - The value to use for the PLATNDLINDEX field.
 * @param[in] platdpqdb - The value to use for the PLATDPQDB field.
 */
__INLINE void riu_rwnxagcstabdis_pack(uint8_t adcpowdisndl, uint8_t adcpowdisthrdbv, uint8_t platndlindex, uint8_t platdpqdb)
{
    REG_PL_WR(RIU_RWNXAGCSTABDIS_ADDR,  ((uint32_t)adcpowdisndl << 24) | ((uint32_t)adcpowdisthrdbv << 16) | ((uint32_t)platndlindex << 8) | ((uint32_t)platdpqdb << 0));
}

/**
 * @brief Unpacks RWNXAGCSTABDIS's fields from current value of the RWNXAGCSTABDIS register.
 *
 * Reads the RWNXAGCSTABDIS register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] adcpowdisndl - Will be populated with the current value of this field from the register.
 * @param[out] adcpowdisthrdbv - Will be populated with the current value of this field from the register.
 * @param[out] platndlindex - Will be populated with the current value of this field from the register.
 * @param[out] platdpqdb - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxagcstabdis_unpack(uint8_t* adcpowdisndl, uint8_t* adcpowdisthrdbv, uint8_t* platndlindex, uint8_t* platdpqdb)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCSTABDIS_ADDR);

    *adcpowdisndl = (localVal & ((uint32_t)0x0F000000)) >> 24;
    *adcpowdisthrdbv = (localVal & ((uint32_t)0x007F0000)) >> 16;
    *platndlindex = (localVal & ((uint32_t)0x00000700)) >> 8;
    *platdpqdb = (localVal & ((uint32_t)0x0000001F)) >> 0;
}

/**
 * @brief Returns the current value of the ADCPOWDISNDL field in the RWNXAGCSTABDIS register.
 *
 * The RWNXAGCSTABDIS register will be read and the ADCPOWDISNDL field's value will be returned.
 *
 * @return The current value of the ADCPOWDISNDL field in the RWNXAGCSTABDIS register.
 */
__INLINE uint8_t riu_adcpowdisndl_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCSTABDIS_ADDR);
    return ((localVal & ((uint32_t)0x0F000000)) >> 24);
}

/**
 * @brief Sets the ADCPOWDISNDL field of the RWNXAGCSTABDIS register.
 *
 * The RWNXAGCSTABDIS register will be read, modified to contain the new field value, and written.
 *
 * @param[in] adcpowdisndl - The value to set the field to.
 */
__INLINE void riu_adcpowdisndl_setf(uint8_t adcpowdisndl)
{
    REG_PL_WR(RIU_RWNXAGCSTABDIS_ADDR, (REG_PL_RD(RIU_RWNXAGCSTABDIS_ADDR) & ~((uint32_t)0x0F000000)) | ((uint32_t)adcpowdisndl << 24));
}

/**
 * @brief Returns the current value of the ADCPOWDISTHRDBV field in the RWNXAGCSTABDIS register.
 *
 * The RWNXAGCSTABDIS register will be read and the ADCPOWDISTHRDBV field's value will be returned.
 *
 * @return The current value of the ADCPOWDISTHRDBV field in the RWNXAGCSTABDIS register.
 */
__INLINE uint8_t riu_adcpowdisthrdbv_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCSTABDIS_ADDR);
    return ((localVal & ((uint32_t)0x007F0000)) >> 16);
}

/**
 * @brief Sets the ADCPOWDISTHRDBV field of the RWNXAGCSTABDIS register.
 *
 * The RWNXAGCSTABDIS register will be read, modified to contain the new field value, and written.
 *
 * @param[in] adcpowdisthrdbv - The value to set the field to.
 */
__INLINE void riu_adcpowdisthrdbv_setf(uint8_t adcpowdisthrdbv)
{
    REG_PL_WR(RIU_RWNXAGCSTABDIS_ADDR, (REG_PL_RD(RIU_RWNXAGCSTABDIS_ADDR) & ~((uint32_t)0x007F0000)) | ((uint32_t)adcpowdisthrdbv << 16));
}

/**
 * @brief Returns the current value of the PLATNDLINDEX field in the RWNXAGCSTABDIS register.
 *
 * The RWNXAGCSTABDIS register will be read and the PLATNDLINDEX field's value will be returned.
 *
 * @return The current value of the PLATNDLINDEX field in the RWNXAGCSTABDIS register.
 */
__INLINE uint8_t riu_platndlindex_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCSTABDIS_ADDR);
    return ((localVal & ((uint32_t)0x00000700)) >> 8);
}

/**
 * @brief Sets the PLATNDLINDEX field of the RWNXAGCSTABDIS register.
 *
 * The RWNXAGCSTABDIS register will be read, modified to contain the new field value, and written.
 *
 * @param[in] platndlindex - The value to set the field to.
 */
__INLINE void riu_platndlindex_setf(uint8_t platndlindex)
{
    REG_PL_WR(RIU_RWNXAGCSTABDIS_ADDR, (REG_PL_RD(RIU_RWNXAGCSTABDIS_ADDR) & ~((uint32_t)0x00000700)) | ((uint32_t)platndlindex << 8));
}

/**
 * @brief Returns the current value of the PLATDPQDB field in the RWNXAGCSTABDIS register.
 *
 * The RWNXAGCSTABDIS register will be read and the PLATDPQDB field's value will be returned.
 *
 * @return The current value of the PLATDPQDB field in the RWNXAGCSTABDIS register.
 */
__INLINE uint8_t riu_platdpqdb_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCSTABDIS_ADDR);
    return ((localVal & ((uint32_t)0x0000001F)) >> 0);
}

/**
 * @brief Sets the PLATDPQDB field of the RWNXAGCSTABDIS register.
 *
 * The RWNXAGCSTABDIS register will be read, modified to contain the new field value, and written.
 *
 * @param[in] platdpqdb - The value to set the field to.
 */
__INLINE void riu_platdpqdb_setf(uint8_t platdpqdb)
{
    REG_PL_WR(RIU_RWNXAGCSTABDIS_ADDR, (REG_PL_RD(RIU_RWNXAGCSTABDIS_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)platdpqdb << 0));
}

/// @}

/**
 * @name RWNXAGCDCCOMP0 register definitions
 * <table>
 * <caption id="RWNXAGCDCCOMP0_BF">RWNXAGCDCCOMP0 bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>29:28 <td>        DCDSSSTYPE <td>R <td>R/W <td>0x1
 * <tr><td>25:24 <td>    DCCENTEREDTYPE <td>R <td>R/W <td>0x3
 * <tr><td>21:20 <td>       DCAGC20TYPE <td>R <td>R/W <td>0x1
 * <tr><td>17:16 <td>         DCADCTYPE <td>R <td>R/W <td>0x1
 * <tr><td>14:08 <td> DCADCHOLDTIME50NS <td>R <td>R/W <td>0x14
 * <tr><td>06:00 <td> DCADCZEROTIME50NS <td>R <td>R/W <td>0x0
 * </table>
 *
 * @{
 */

/// Address of the RWNXAGCDCCOMP0 register
#define RIU_RWNXAGCDCCOMP0_ADDR   0x4033B374
/// Offset of the RWNXAGCDCCOMP0 register from the base address
#define RIU_RWNXAGCDCCOMP0_OFFSET 0x00000374
/// Index of the RWNXAGCDCCOMP0 register
#define RIU_RWNXAGCDCCOMP0_INDEX  0x000000DD
/// Reset value of the RWNXAGCDCCOMP0 register
#define RIU_RWNXAGCDCCOMP0_RESET  0x13111400

/**
 * @brief Returns the current value of the RWNXAGCDCCOMP0 register.
 * The RWNXAGCDCCOMP0 register will be read and its value returned.
 * @return The current value of the RWNXAGCDCCOMP0 register.
 */
__INLINE uint32_t riu_rwnxagcdccomp0_get(void)
{
    return REG_PL_RD(RIU_RWNXAGCDCCOMP0_ADDR);
}

/**
 * @brief Sets the RWNXAGCDCCOMP0 register to a value.
 * The RWNXAGCDCCOMP0 register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxagcdccomp0_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXAGCDCCOMP0_ADDR, value);
}

// field definitions
/// DCDSSSTYPE field mask
#define RIU_DCDSSSTYPE_MASK          ((uint32_t)0x30000000)
/// DCDSSSTYPE field LSB position
#define RIU_DCDSSSTYPE_LSB           28
/// DCDSSSTYPE field width
#define RIU_DCDSSSTYPE_WIDTH         ((uint32_t)0x00000002)
/// DCCENTEREDTYPE field mask
#define RIU_DCCENTEREDTYPE_MASK      ((uint32_t)0x03000000)
/// DCCENTEREDTYPE field LSB position
#define RIU_DCCENTEREDTYPE_LSB       24
/// DCCENTEREDTYPE field width
#define RIU_DCCENTEREDTYPE_WIDTH     ((uint32_t)0x00000002)
/// DCAGC20TYPE field mask
#define RIU_DCAGC20TYPE_MASK         ((uint32_t)0x00300000)
/// DCAGC20TYPE field LSB position
#define RIU_DCAGC20TYPE_LSB          20
/// DCAGC20TYPE field width
#define RIU_DCAGC20TYPE_WIDTH        ((uint32_t)0x00000002)
/// DCADCTYPE field mask
#define RIU_DCADCTYPE_MASK           ((uint32_t)0x00030000)
/// DCADCTYPE field LSB position
#define RIU_DCADCTYPE_LSB            16
/// DCADCTYPE field width
#define RIU_DCADCTYPE_WIDTH          ((uint32_t)0x00000002)
/// DCADCHOLDTIME50NS field mask
#define RIU_DCADCHOLDTIME50NS_MASK   ((uint32_t)0x00007F00)
/// DCADCHOLDTIME50NS field LSB position
#define RIU_DCADCHOLDTIME50NS_LSB    8
/// DCADCHOLDTIME50NS field width
#define RIU_DCADCHOLDTIME50NS_WIDTH  ((uint32_t)0x00000007)
/// DCADCZEROTIME50NS field mask
#define RIU_DCADCZEROTIME50NS_MASK   ((uint32_t)0x0000007F)
/// DCADCZEROTIME50NS field LSB position
#define RIU_DCADCZEROTIME50NS_LSB    0
/// DCADCZEROTIME50NS field width
#define RIU_DCADCZEROTIME50NS_WIDTH  ((uint32_t)0x00000007)

/// DCDSSSTYPE field reset value
#define RIU_DCDSSSTYPE_RST           0x1
/// DCCENTEREDTYPE field reset value
#define RIU_DCCENTEREDTYPE_RST       0x3
/// DCAGC20TYPE field reset value
#define RIU_DCAGC20TYPE_RST          0x1
/// DCADCTYPE field reset value
#define RIU_DCADCTYPE_RST            0x1
/// DCADCHOLDTIME50NS field reset value
#define RIU_DCADCHOLDTIME50NS_RST    0x14
/// DCADCZEROTIME50NS field reset value
#define RIU_DCADCZEROTIME50NS_RST    0x0

/**
 * @brief Constructs a value for the RWNXAGCDCCOMP0 register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] dcdssstype - The value to use for the DCDSSSTYPE field.
 * @param[in] dccenteredtype - The value to use for the DCCENTEREDTYPE field.
 * @param[in] dcagc20type - The value to use for the DCAGC20TYPE field.
 * @param[in] dcadctype - The value to use for the DCADCTYPE field.
 * @param[in] dcadcholdtime50ns - The value to use for the DCADCHOLDTIME50NS field.
 * @param[in] dcadczerotime50ns - The value to use for the DCADCZEROTIME50NS field.
 */
__INLINE void riu_rwnxagcdccomp0_pack(uint8_t dcdssstype, uint8_t dccenteredtype, uint8_t dcagc20type, uint8_t dcadctype, uint8_t dcadcholdtime50ns, uint8_t dcadczerotime50ns)
{
    REG_PL_WR(RIU_RWNXAGCDCCOMP0_ADDR,  ((uint32_t)dcdssstype << 28) | ((uint32_t)dccenteredtype << 24) | ((uint32_t)dcagc20type << 20) | ((uint32_t)dcadctype << 16) | ((uint32_t)dcadcholdtime50ns << 8) | ((uint32_t)dcadczerotime50ns << 0));
}

/**
 * @brief Unpacks RWNXAGCDCCOMP0's fields from current value of the RWNXAGCDCCOMP0 register.
 *
 * Reads the RWNXAGCDCCOMP0 register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] dcdssstype - Will be populated with the current value of this field from the register.
 * @param[out] dccenteredtype - Will be populated with the current value of this field from the register.
 * @param[out] dcagc20type - Will be populated with the current value of this field from the register.
 * @param[out] dcadctype - Will be populated with the current value of this field from the register.
 * @param[out] dcadcholdtime50ns - Will be populated with the current value of this field from the register.
 * @param[out] dcadczerotime50ns - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxagcdccomp0_unpack(uint8_t* dcdssstype, uint8_t* dccenteredtype, uint8_t* dcagc20type, uint8_t* dcadctype, uint8_t* dcadcholdtime50ns, uint8_t* dcadczerotime50ns)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCDCCOMP0_ADDR);

    *dcdssstype = (localVal & ((uint32_t)0x30000000)) >> 28;
    *dccenteredtype = (localVal & ((uint32_t)0x03000000)) >> 24;
    *dcagc20type = (localVal & ((uint32_t)0x00300000)) >> 20;
    *dcadctype = (localVal & ((uint32_t)0x00030000)) >> 16;
    *dcadcholdtime50ns = (localVal & ((uint32_t)0x00007F00)) >> 8;
    *dcadczerotime50ns = (localVal & ((uint32_t)0x0000007F)) >> 0;
}

/**
 * @brief Returns the current value of the DCDSSSTYPE field in the RWNXAGCDCCOMP0 register.
 *
 * The RWNXAGCDCCOMP0 register will be read and the DCDSSSTYPE field's value will be returned.
 *
 * @return The current value of the DCDSSSTYPE field in the RWNXAGCDCCOMP0 register.
 */
__INLINE uint8_t riu_dcdssstype_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCDCCOMP0_ADDR);
    return ((localVal & ((uint32_t)0x30000000)) >> 28);
}

/**
 * @brief Sets the DCDSSSTYPE field of the RWNXAGCDCCOMP0 register.
 *
 * The RWNXAGCDCCOMP0 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] dcdssstype - The value to set the field to.
 */
__INLINE void riu_dcdssstype_setf(uint8_t dcdssstype)
{
    REG_PL_WR(RIU_RWNXAGCDCCOMP0_ADDR, (REG_PL_RD(RIU_RWNXAGCDCCOMP0_ADDR) & ~((uint32_t)0x30000000)) | ((uint32_t)dcdssstype << 28));
}

/**
 * @brief Returns the current value of the DCCENTEREDTYPE field in the RWNXAGCDCCOMP0 register.
 *
 * The RWNXAGCDCCOMP0 register will be read and the DCCENTEREDTYPE field's value will be returned.
 *
 * @return The current value of the DCCENTEREDTYPE field in the RWNXAGCDCCOMP0 register.
 */
__INLINE uint8_t riu_dccenteredtype_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCDCCOMP0_ADDR);
    return ((localVal & ((uint32_t)0x03000000)) >> 24);
}

/**
 * @brief Sets the DCCENTEREDTYPE field of the RWNXAGCDCCOMP0 register.
 *
 * The RWNXAGCDCCOMP0 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] dccenteredtype - The value to set the field to.
 */
__INLINE void riu_dccenteredtype_setf(uint8_t dccenteredtype)
{
    REG_PL_WR(RIU_RWNXAGCDCCOMP0_ADDR, (REG_PL_RD(RIU_RWNXAGCDCCOMP0_ADDR) & ~((uint32_t)0x03000000)) | ((uint32_t)dccenteredtype << 24));
}

/**
 * @brief Returns the current value of the DCAGC20TYPE field in the RWNXAGCDCCOMP0 register.
 *
 * The RWNXAGCDCCOMP0 register will be read and the DCAGC20TYPE field's value will be returned.
 *
 * @return The current value of the DCAGC20TYPE field in the RWNXAGCDCCOMP0 register.
 */
__INLINE uint8_t riu_dcagc20type_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCDCCOMP0_ADDR);
    return ((localVal & ((uint32_t)0x00300000)) >> 20);
}

/**
 * @brief Sets the DCAGC20TYPE field of the RWNXAGCDCCOMP0 register.
 *
 * The RWNXAGCDCCOMP0 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] dcagc20type - The value to set the field to.
 */
__INLINE void riu_dcagc20type_setf(uint8_t dcagc20type)
{
    REG_PL_WR(RIU_RWNXAGCDCCOMP0_ADDR, (REG_PL_RD(RIU_RWNXAGCDCCOMP0_ADDR) & ~((uint32_t)0x00300000)) | ((uint32_t)dcagc20type << 20));
}

/**
 * @brief Returns the current value of the DCADCTYPE field in the RWNXAGCDCCOMP0 register.
 *
 * The RWNXAGCDCCOMP0 register will be read and the DCADCTYPE field's value will be returned.
 *
 * @return The current value of the DCADCTYPE field in the RWNXAGCDCCOMP0 register.
 */
__INLINE uint8_t riu_dcadctype_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCDCCOMP0_ADDR);
    return ((localVal & ((uint32_t)0x00030000)) >> 16);
}

/**
 * @brief Sets the DCADCTYPE field of the RWNXAGCDCCOMP0 register.
 *
 * The RWNXAGCDCCOMP0 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] dcadctype - The value to set the field to.
 */
__INLINE void riu_dcadctype_setf(uint8_t dcadctype)
{
    REG_PL_WR(RIU_RWNXAGCDCCOMP0_ADDR, (REG_PL_RD(RIU_RWNXAGCDCCOMP0_ADDR) & ~((uint32_t)0x00030000)) | ((uint32_t)dcadctype << 16));
}

/**
 * @brief Returns the current value of the DCADCHOLDTIME50NS field in the RWNXAGCDCCOMP0 register.
 *
 * The RWNXAGCDCCOMP0 register will be read and the DCADCHOLDTIME50NS field's value will be returned.
 *
 * @return The current value of the DCADCHOLDTIME50NS field in the RWNXAGCDCCOMP0 register.
 */
__INLINE uint8_t riu_dcadcholdtime50ns_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCDCCOMP0_ADDR);
    return ((localVal & ((uint32_t)0x00007F00)) >> 8);
}

/**
 * @brief Sets the DCADCHOLDTIME50NS field of the RWNXAGCDCCOMP0 register.
 *
 * The RWNXAGCDCCOMP0 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] dcadcholdtime50ns - The value to set the field to.
 */
__INLINE void riu_dcadcholdtime50ns_setf(uint8_t dcadcholdtime50ns)
{
    REG_PL_WR(RIU_RWNXAGCDCCOMP0_ADDR, (REG_PL_RD(RIU_RWNXAGCDCCOMP0_ADDR) & ~((uint32_t)0x00007F00)) | ((uint32_t)dcadcholdtime50ns << 8));
}

/**
 * @brief Returns the current value of the DCADCZEROTIME50NS field in the RWNXAGCDCCOMP0 register.
 *
 * The RWNXAGCDCCOMP0 register will be read and the DCADCZEROTIME50NS field's value will be returned.
 *
 * @return The current value of the DCADCZEROTIME50NS field in the RWNXAGCDCCOMP0 register.
 */
__INLINE uint8_t riu_dcadczerotime50ns_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCDCCOMP0_ADDR);
    return ((localVal & ((uint32_t)0x0000007F)) >> 0);
}

/**
 * @brief Sets the DCADCZEROTIME50NS field of the RWNXAGCDCCOMP0 register.
 *
 * The RWNXAGCDCCOMP0 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] dcadczerotime50ns - The value to set the field to.
 */
__INLINE void riu_dcadczerotime50ns_setf(uint8_t dcadczerotime50ns)
{
    REG_PL_WR(RIU_RWNXAGCDCCOMP0_ADDR, (REG_PL_RD(RIU_RWNXAGCDCCOMP0_ADDR) & ~((uint32_t)0x0000007F)) | ((uint32_t)dcadczerotime50ns << 0));
}

/// @}

/**
 * @name RWNXAGCDCCOMP1 register definitions
 * <table>
 * <caption id="RWNXAGCDCCOMP1_BF">RWNXAGCDCCOMP1 bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>30:24 <td>DCCENTEREDHOLDTIME50NS <td>R <td>R/W <td>0x8
 * <tr><td>22:16 <td>DCCENTEREDZEROTIME50NS <td>R <td>R/W <td>0x2
 * <tr><td>14:08 <td>DCAGC20HOLDTIME50NS <td>R <td>R/W <td>0x0
 * <tr><td>06:00 <td>DCAGC20ZEROTIME50NS <td>R <td>R/W <td>0x2
 * </table>
 *
 * @{
 */

/// Address of the RWNXAGCDCCOMP1 register
#define RIU_RWNXAGCDCCOMP1_ADDR   0x4033B378
/// Offset of the RWNXAGCDCCOMP1 register from the base address
#define RIU_RWNXAGCDCCOMP1_OFFSET 0x00000378
/// Index of the RWNXAGCDCCOMP1 register
#define RIU_RWNXAGCDCCOMP1_INDEX  0x000000DE
/// Reset value of the RWNXAGCDCCOMP1 register
#define RIU_RWNXAGCDCCOMP1_RESET  0x08020002

/**
 * @brief Returns the current value of the RWNXAGCDCCOMP1 register.
 * The RWNXAGCDCCOMP1 register will be read and its value returned.
 * @return The current value of the RWNXAGCDCCOMP1 register.
 */
__INLINE uint32_t riu_rwnxagcdccomp1_get(void)
{
    return REG_PL_RD(RIU_RWNXAGCDCCOMP1_ADDR);
}

/**
 * @brief Sets the RWNXAGCDCCOMP1 register to a value.
 * The RWNXAGCDCCOMP1 register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxagcdccomp1_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXAGCDCCOMP1_ADDR, value);
}

// field definitions
/// DCCENTEREDHOLDTIME50NS field mask
#define RIU_DCCENTEREDHOLDTIME50NS_MASK   ((uint32_t)0x7F000000)
/// DCCENTEREDHOLDTIME50NS field LSB position
#define RIU_DCCENTEREDHOLDTIME50NS_LSB    24
/// DCCENTEREDHOLDTIME50NS field width
#define RIU_DCCENTEREDHOLDTIME50NS_WIDTH  ((uint32_t)0x00000007)
/// DCCENTEREDZEROTIME50NS field mask
#define RIU_DCCENTEREDZEROTIME50NS_MASK   ((uint32_t)0x007F0000)
/// DCCENTEREDZEROTIME50NS field LSB position
#define RIU_DCCENTEREDZEROTIME50NS_LSB    16
/// DCCENTEREDZEROTIME50NS field width
#define RIU_DCCENTEREDZEROTIME50NS_WIDTH  ((uint32_t)0x00000007)
/// DCAGC20HOLDTIME50NS field mask
#define RIU_DCAGC20HOLDTIME50NS_MASK      ((uint32_t)0x00007F00)
/// DCAGC20HOLDTIME50NS field LSB position
#define RIU_DCAGC20HOLDTIME50NS_LSB       8
/// DCAGC20HOLDTIME50NS field width
#define RIU_DCAGC20HOLDTIME50NS_WIDTH     ((uint32_t)0x00000007)
/// DCAGC20ZEROTIME50NS field mask
#define RIU_DCAGC20ZEROTIME50NS_MASK      ((uint32_t)0x0000007F)
/// DCAGC20ZEROTIME50NS field LSB position
#define RIU_DCAGC20ZEROTIME50NS_LSB       0
/// DCAGC20ZEROTIME50NS field width
#define RIU_DCAGC20ZEROTIME50NS_WIDTH     ((uint32_t)0x00000007)

/// DCCENTEREDHOLDTIME50NS field reset value
#define RIU_DCCENTEREDHOLDTIME50NS_RST    0x8
/// DCCENTEREDZEROTIME50NS field reset value
#define RIU_DCCENTEREDZEROTIME50NS_RST    0x2
/// DCAGC20HOLDTIME50NS field reset value
#define RIU_DCAGC20HOLDTIME50NS_RST       0x0
/// DCAGC20ZEROTIME50NS field reset value
#define RIU_DCAGC20ZEROTIME50NS_RST       0x2

/**
 * @brief Constructs a value for the RWNXAGCDCCOMP1 register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] dccenteredholdtime50ns - The value to use for the DCCENTEREDHOLDTIME50NS field.
 * @param[in] dccenteredzerotime50ns - The value to use for the DCCENTEREDZEROTIME50NS field.
 * @param[in] dcagc20holdtime50ns - The value to use for the DCAGC20HOLDTIME50NS field.
 * @param[in] dcagc20zerotime50ns - The value to use for the DCAGC20ZEROTIME50NS field.
 */
__INLINE void riu_rwnxagcdccomp1_pack(uint8_t dccenteredholdtime50ns, uint8_t dccenteredzerotime50ns, uint8_t dcagc20holdtime50ns, uint8_t dcagc20zerotime50ns)
{
    REG_PL_WR(RIU_RWNXAGCDCCOMP1_ADDR,  ((uint32_t)dccenteredholdtime50ns << 24) | ((uint32_t)dccenteredzerotime50ns << 16) | ((uint32_t)dcagc20holdtime50ns << 8) | ((uint32_t)dcagc20zerotime50ns << 0));
}

/**
 * @brief Unpacks RWNXAGCDCCOMP1's fields from current value of the RWNXAGCDCCOMP1 register.
 *
 * Reads the RWNXAGCDCCOMP1 register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] dccenteredholdtime50ns - Will be populated with the current value of this field from the register.
 * @param[out] dccenteredzerotime50ns - Will be populated with the current value of this field from the register.
 * @param[out] dcagc20holdtime50ns - Will be populated with the current value of this field from the register.
 * @param[out] dcagc20zerotime50ns - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxagcdccomp1_unpack(uint8_t* dccenteredholdtime50ns, uint8_t* dccenteredzerotime50ns, uint8_t* dcagc20holdtime50ns, uint8_t* dcagc20zerotime50ns)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCDCCOMP1_ADDR);

    *dccenteredholdtime50ns = (localVal & ((uint32_t)0x7F000000)) >> 24;
    *dccenteredzerotime50ns = (localVal & ((uint32_t)0x007F0000)) >> 16;
    *dcagc20holdtime50ns = (localVal & ((uint32_t)0x00007F00)) >> 8;
    *dcagc20zerotime50ns = (localVal & ((uint32_t)0x0000007F)) >> 0;
}

/**
 * @brief Returns the current value of the DCCENTEREDHOLDTIME50NS field in the RWNXAGCDCCOMP1 register.
 *
 * The RWNXAGCDCCOMP1 register will be read and the DCCENTEREDHOLDTIME50NS field's value will be returned.
 *
 * @return The current value of the DCCENTEREDHOLDTIME50NS field in the RWNXAGCDCCOMP1 register.
 */
__INLINE uint8_t riu_dccenteredholdtime50ns_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCDCCOMP1_ADDR);
    return ((localVal & ((uint32_t)0x7F000000)) >> 24);
}

/**
 * @brief Sets the DCCENTEREDHOLDTIME50NS field of the RWNXAGCDCCOMP1 register.
 *
 * The RWNXAGCDCCOMP1 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] dccenteredholdtime50ns - The value to set the field to.
 */
__INLINE void riu_dccenteredholdtime50ns_setf(uint8_t dccenteredholdtime50ns)
{
    REG_PL_WR(RIU_RWNXAGCDCCOMP1_ADDR, (REG_PL_RD(RIU_RWNXAGCDCCOMP1_ADDR) & ~((uint32_t)0x7F000000)) | ((uint32_t)dccenteredholdtime50ns << 24));
}

/**
 * @brief Returns the current value of the DCCENTEREDZEROTIME50NS field in the RWNXAGCDCCOMP1 register.
 *
 * The RWNXAGCDCCOMP1 register will be read and the DCCENTEREDZEROTIME50NS field's value will be returned.
 *
 * @return The current value of the DCCENTEREDZEROTIME50NS field in the RWNXAGCDCCOMP1 register.
 */
__INLINE uint8_t riu_dccenteredzerotime50ns_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCDCCOMP1_ADDR);
    return ((localVal & ((uint32_t)0x007F0000)) >> 16);
}

/**
 * @brief Sets the DCCENTEREDZEROTIME50NS field of the RWNXAGCDCCOMP1 register.
 *
 * The RWNXAGCDCCOMP1 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] dccenteredzerotime50ns - The value to set the field to.
 */
__INLINE void riu_dccenteredzerotime50ns_setf(uint8_t dccenteredzerotime50ns)
{
    REG_PL_WR(RIU_RWNXAGCDCCOMP1_ADDR, (REG_PL_RD(RIU_RWNXAGCDCCOMP1_ADDR) & ~((uint32_t)0x007F0000)) | ((uint32_t)dccenteredzerotime50ns << 16));
}

/**
 * @brief Returns the current value of the DCAGC20HOLDTIME50NS field in the RWNXAGCDCCOMP1 register.
 *
 * The RWNXAGCDCCOMP1 register will be read and the DCAGC20HOLDTIME50NS field's value will be returned.
 *
 * @return The current value of the DCAGC20HOLDTIME50NS field in the RWNXAGCDCCOMP1 register.
 */
__INLINE uint8_t riu_dcagc20holdtime50ns_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCDCCOMP1_ADDR);
    return ((localVal & ((uint32_t)0x00007F00)) >> 8);
}

/**
 * @brief Sets the DCAGC20HOLDTIME50NS field of the RWNXAGCDCCOMP1 register.
 *
 * The RWNXAGCDCCOMP1 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] dcagc20holdtime50ns - The value to set the field to.
 */
__INLINE void riu_dcagc20holdtime50ns_setf(uint8_t dcagc20holdtime50ns)
{
    REG_PL_WR(RIU_RWNXAGCDCCOMP1_ADDR, (REG_PL_RD(RIU_RWNXAGCDCCOMP1_ADDR) & ~((uint32_t)0x00007F00)) | ((uint32_t)dcagc20holdtime50ns << 8));
}

/**
 * @brief Returns the current value of the DCAGC20ZEROTIME50NS field in the RWNXAGCDCCOMP1 register.
 *
 * The RWNXAGCDCCOMP1 register will be read and the DCAGC20ZEROTIME50NS field's value will be returned.
 *
 * @return The current value of the DCAGC20ZEROTIME50NS field in the RWNXAGCDCCOMP1 register.
 */
__INLINE uint8_t riu_dcagc20zerotime50ns_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCDCCOMP1_ADDR);
    return ((localVal & ((uint32_t)0x0000007F)) >> 0);
}

/**
 * @brief Sets the DCAGC20ZEROTIME50NS field of the RWNXAGCDCCOMP1 register.
 *
 * The RWNXAGCDCCOMP1 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] dcagc20zerotime50ns - The value to set the field to.
 */
__INLINE void riu_dcagc20zerotime50ns_setf(uint8_t dcagc20zerotime50ns)
{
    REG_PL_WR(RIU_RWNXAGCDCCOMP1_ADDR, (REG_PL_RD(RIU_RWNXAGCDCCOMP1_ADDR) & ~((uint32_t)0x0000007F)) | ((uint32_t)dcagc20zerotime50ns << 0));
}

/// @}

/**
 * @name RWNXAGCDCCOMP2 register definitions
 * <table>
 * <caption id="RWNXAGCDCCOMP2_BF">RWNXAGCDCCOMP2 bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>30:24 <td>DCDSSSHOLDTIME50NS <td>R <td>R/W <td>0x0
 * <tr><td>22:16 <td>DCDSSSZEROTIME50NS <td>R <td>R/W <td>0x2
 * <tr><td>06:00 <td>     DELDCSTABLECC <td>R <td>R/W <td>0x0
 * </table>
 *
 * @{
 */

/// Address of the RWNXAGCDCCOMP2 register
#define RIU_RWNXAGCDCCOMP2_ADDR   0x4033B37C
/// Offset of the RWNXAGCDCCOMP2 register from the base address
#define RIU_RWNXAGCDCCOMP2_OFFSET 0x0000037C
/// Index of the RWNXAGCDCCOMP2 register
#define RIU_RWNXAGCDCCOMP2_INDEX  0x000000DF
/// Reset value of the RWNXAGCDCCOMP2 register
#define RIU_RWNXAGCDCCOMP2_RESET  0x00020000

/**
 * @brief Returns the current value of the RWNXAGCDCCOMP2 register.
 * The RWNXAGCDCCOMP2 register will be read and its value returned.
 * @return The current value of the RWNXAGCDCCOMP2 register.
 */
__INLINE uint32_t riu_rwnxagcdccomp2_get(void)
{
    return REG_PL_RD(RIU_RWNXAGCDCCOMP2_ADDR);
}

/**
 * @brief Sets the RWNXAGCDCCOMP2 register to a value.
 * The RWNXAGCDCCOMP2 register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxagcdccomp2_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXAGCDCCOMP2_ADDR, value);
}

// field definitions
/// DCDSSSHOLDTIME50NS field mask
#define RIU_DCDSSSHOLDTIME50NS_MASK   ((uint32_t)0x7F000000)
/// DCDSSSHOLDTIME50NS field LSB position
#define RIU_DCDSSSHOLDTIME50NS_LSB    24
/// DCDSSSHOLDTIME50NS field width
#define RIU_DCDSSSHOLDTIME50NS_WIDTH  ((uint32_t)0x00000007)
/// DCDSSSZEROTIME50NS field mask
#define RIU_DCDSSSZEROTIME50NS_MASK   ((uint32_t)0x007F0000)
/// DCDSSSZEROTIME50NS field LSB position
#define RIU_DCDSSSZEROTIME50NS_LSB    16
/// DCDSSSZEROTIME50NS field width
#define RIU_DCDSSSZEROTIME50NS_WIDTH  ((uint32_t)0x00000007)
/// DELDCSTABLECC field mask
#define RIU_DELDCSTABLECC_MASK        ((uint32_t)0x0000007F)
/// DELDCSTABLECC field LSB position
#define RIU_DELDCSTABLECC_LSB         0
/// DELDCSTABLECC field width
#define RIU_DELDCSTABLECC_WIDTH       ((uint32_t)0x00000007)

/// DCDSSSHOLDTIME50NS field reset value
#define RIU_DCDSSSHOLDTIME50NS_RST    0x0
/// DCDSSSZEROTIME50NS field reset value
#define RIU_DCDSSSZEROTIME50NS_RST    0x2
/// DELDCSTABLECC field reset value
#define RIU_DELDCSTABLECC_RST         0x0

/**
 * @brief Constructs a value for the RWNXAGCDCCOMP2 register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] dcdsssholdtime50ns - The value to use for the DCDSSSHOLDTIME50NS field.
 * @param[in] dcdssszerotime50ns - The value to use for the DCDSSSZEROTIME50NS field.
 * @param[in] deldcstablecc - The value to use for the DELDCSTABLECC field.
 */
__INLINE void riu_rwnxagcdccomp2_pack(uint8_t dcdsssholdtime50ns, uint8_t dcdssszerotime50ns, uint8_t deldcstablecc)
{
    REG_PL_WR(RIU_RWNXAGCDCCOMP2_ADDR,  ((uint32_t)dcdsssholdtime50ns << 24) | ((uint32_t)dcdssszerotime50ns << 16) | ((uint32_t)deldcstablecc << 0));
}

/**
 * @brief Unpacks RWNXAGCDCCOMP2's fields from current value of the RWNXAGCDCCOMP2 register.
 *
 * Reads the RWNXAGCDCCOMP2 register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] dcdsssholdtime50ns - Will be populated with the current value of this field from the register.
 * @param[out] dcdssszerotime50ns - Will be populated with the current value of this field from the register.
 * @param[out] deldcstablecc - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxagcdccomp2_unpack(uint8_t* dcdsssholdtime50ns, uint8_t* dcdssszerotime50ns, uint8_t* deldcstablecc)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCDCCOMP2_ADDR);

    *dcdsssholdtime50ns = (localVal & ((uint32_t)0x7F000000)) >> 24;
    *dcdssszerotime50ns = (localVal & ((uint32_t)0x007F0000)) >> 16;
    *deldcstablecc = (localVal & ((uint32_t)0x0000007F)) >> 0;
}

/**
 * @brief Returns the current value of the DCDSSSHOLDTIME50NS field in the RWNXAGCDCCOMP2 register.
 *
 * The RWNXAGCDCCOMP2 register will be read and the DCDSSSHOLDTIME50NS field's value will be returned.
 *
 * @return The current value of the DCDSSSHOLDTIME50NS field in the RWNXAGCDCCOMP2 register.
 */
__INLINE uint8_t riu_dcdsssholdtime50ns_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCDCCOMP2_ADDR);
    return ((localVal & ((uint32_t)0x7F000000)) >> 24);
}

/**
 * @brief Sets the DCDSSSHOLDTIME50NS field of the RWNXAGCDCCOMP2 register.
 *
 * The RWNXAGCDCCOMP2 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] dcdsssholdtime50ns - The value to set the field to.
 */
__INLINE void riu_dcdsssholdtime50ns_setf(uint8_t dcdsssholdtime50ns)
{
    REG_PL_WR(RIU_RWNXAGCDCCOMP2_ADDR, (REG_PL_RD(RIU_RWNXAGCDCCOMP2_ADDR) & ~((uint32_t)0x7F000000)) | ((uint32_t)dcdsssholdtime50ns << 24));
}

/**
 * @brief Returns the current value of the DCDSSSZEROTIME50NS field in the RWNXAGCDCCOMP2 register.
 *
 * The RWNXAGCDCCOMP2 register will be read and the DCDSSSZEROTIME50NS field's value will be returned.
 *
 * @return The current value of the DCDSSSZEROTIME50NS field in the RWNXAGCDCCOMP2 register.
 */
__INLINE uint8_t riu_dcdssszerotime50ns_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCDCCOMP2_ADDR);
    return ((localVal & ((uint32_t)0x007F0000)) >> 16);
}

/**
 * @brief Sets the DCDSSSZEROTIME50NS field of the RWNXAGCDCCOMP2 register.
 *
 * The RWNXAGCDCCOMP2 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] dcdssszerotime50ns - The value to set the field to.
 */
__INLINE void riu_dcdssszerotime50ns_setf(uint8_t dcdssszerotime50ns)
{
    REG_PL_WR(RIU_RWNXAGCDCCOMP2_ADDR, (REG_PL_RD(RIU_RWNXAGCDCCOMP2_ADDR) & ~((uint32_t)0x007F0000)) | ((uint32_t)dcdssszerotime50ns << 16));
}

/**
 * @brief Returns the current value of the DELDCSTABLECC field in the RWNXAGCDCCOMP2 register.
 *
 * The RWNXAGCDCCOMP2 register will be read and the DELDCSTABLECC field's value will be returned.
 *
 * @return The current value of the DELDCSTABLECC field in the RWNXAGCDCCOMP2 register.
 */
__INLINE uint8_t riu_deldcstablecc_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCDCCOMP2_ADDR);
    return ((localVal & ((uint32_t)0x0000007F)) >> 0);
}

/**
 * @brief Sets the DELDCSTABLECC field of the RWNXAGCDCCOMP2 register.
 *
 * The RWNXAGCDCCOMP2 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] deldcstablecc - The value to set the field to.
 */
__INLINE void riu_deldcstablecc_setf(uint8_t deldcstablecc)
{
    REG_PL_WR(RIU_RWNXAGCDCCOMP2_ADDR, (REG_PL_RD(RIU_RWNXAGCDCCOMP2_ADDR) & ~((uint32_t)0x0000007F)) | ((uint32_t)deldcstablecc << 0));
}

/// @}

/**
 * @name RWNXAGCEVT0 register definitions
 * <table>
 * <caption id="RWNXAGCEVT0_BF">RWNXAGCEVT0 bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>31:26 <td>           EVT0OP1 <td>R <td>R/W <td>0x14
 * <tr><td>25:20 <td>           EVT0OP2 <td>R <td>R/W <td>0x10
 * <tr><td>19:14 <td>           EVT0OP3 <td>R <td>R/W <td>0x1
 * <tr><td>13 <td>      EVT0PATHCOMB <td>R <td>R/W <td>0
 * <tr><td>12:10 <td>        EVT0OPCOMB <td>R <td>R/W <td>0x1
 * <tr><td>08:00 <td>        EVT0TGTADD <td>R <td>R/W <td>0x2
 * </table>
 *
 * @{
 */

/// Address of the RWNXAGCEVT0 register
#define RIU_RWNXAGCEVT0_ADDR   0x4033B380
/// Offset of the RWNXAGCEVT0 register from the base address
#define RIU_RWNXAGCEVT0_OFFSET 0x00000380
/// Index of the RWNXAGCEVT0 register
#define RIU_RWNXAGCEVT0_INDEX  0x000000E0
/// Reset value of the RWNXAGCEVT0 register
#define RIU_RWNXAGCEVT0_RESET  0x51004402

/**
 * @brief Returns the current value of the RWNXAGCEVT0 register.
 * The RWNXAGCEVT0 register will be read and its value returned.
 * @return The current value of the RWNXAGCEVT0 register.
 */
__INLINE uint32_t riu_rwnxagcevt0_get(void)
{
    return REG_PL_RD(RIU_RWNXAGCEVT0_ADDR);
}

/**
 * @brief Sets the RWNXAGCEVT0 register to a value.
 * The RWNXAGCEVT0 register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxagcevt0_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXAGCEVT0_ADDR, value);
}

// field definitions
/// EVT0OP1 field mask
#define RIU_EVT0OP1_MASK        ((uint32_t)0xFC000000)
/// EVT0OP1 field LSB position
#define RIU_EVT0OP1_LSB         26
/// EVT0OP1 field width
#define RIU_EVT0OP1_WIDTH       ((uint32_t)0x00000006)
/// EVT0OP2 field mask
#define RIU_EVT0OP2_MASK        ((uint32_t)0x03F00000)
/// EVT0OP2 field LSB position
#define RIU_EVT0OP2_LSB         20
/// EVT0OP2 field width
#define RIU_EVT0OP2_WIDTH       ((uint32_t)0x00000006)
/// EVT0OP3 field mask
#define RIU_EVT0OP3_MASK        ((uint32_t)0x000FC000)
/// EVT0OP3 field LSB position
#define RIU_EVT0OP3_LSB         14
/// EVT0OP3 field width
#define RIU_EVT0OP3_WIDTH       ((uint32_t)0x00000006)
/// EVT0PATHCOMB field bit
#define RIU_EVT0PATHCOMB_BIT    ((uint32_t)0x00002000)
/// EVT0PATHCOMB field position
#define RIU_EVT0PATHCOMB_POS    13
/// EVT0OPCOMB field mask
#define RIU_EVT0OPCOMB_MASK     ((uint32_t)0x00001C00)
/// EVT0OPCOMB field LSB position
#define RIU_EVT0OPCOMB_LSB      10
/// EVT0OPCOMB field width
#define RIU_EVT0OPCOMB_WIDTH    ((uint32_t)0x00000003)
/// EVT0TGTADD field mask
#define RIU_EVT0TGTADD_MASK     ((uint32_t)0x000001FF)
/// EVT0TGTADD field LSB position
#define RIU_EVT0TGTADD_LSB      0
/// EVT0TGTADD field width
#define RIU_EVT0TGTADD_WIDTH    ((uint32_t)0x00000009)

/// EVT0OP1 field reset value
#define RIU_EVT0OP1_RST         0x14
/// EVT0OP2 field reset value
#define RIU_EVT0OP2_RST         0x10
/// EVT0OP3 field reset value
#define RIU_EVT0OP3_RST         0x1
/// EVT0PATHCOMB field reset value
#define RIU_EVT0PATHCOMB_RST    0x0
/// EVT0OPCOMB field reset value
#define RIU_EVT0OPCOMB_RST      0x1
/// EVT0TGTADD field reset value
#define RIU_EVT0TGTADD_RST      0x2

/**
 * @brief Constructs a value for the RWNXAGCEVT0 register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] evt0op1 - The value to use for the EVT0OP1 field.
 * @param[in] evt0op2 - The value to use for the EVT0OP2 field.
 * @param[in] evt0op3 - The value to use for the EVT0OP3 field.
 * @param[in] evt0pathcomb - The value to use for the EVT0PATHCOMB field.
 * @param[in] evt0opcomb - The value to use for the EVT0OPCOMB field.
 * @param[in] evt0tgtadd - The value to use for the EVT0TGTADD field.
 */
__INLINE void riu_rwnxagcevt0_pack(uint8_t evt0op1, uint8_t evt0op2, uint8_t evt0op3, uint8_t evt0pathcomb, uint8_t evt0opcomb, uint16_t evt0tgtadd)
{
    REG_PL_WR(RIU_RWNXAGCEVT0_ADDR,  ((uint32_t)evt0op1 << 26) | ((uint32_t)evt0op2 << 20) | ((uint32_t)evt0op3 << 14) | ((uint32_t)evt0pathcomb << 13) | ((uint32_t)evt0opcomb << 10) | ((uint32_t)evt0tgtadd << 0));
}

/**
 * @brief Unpacks RWNXAGCEVT0's fields from current value of the RWNXAGCEVT0 register.
 *
 * Reads the RWNXAGCEVT0 register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] evt0op1 - Will be populated with the current value of this field from the register.
 * @param[out] evt0op2 - Will be populated with the current value of this field from the register.
 * @param[out] evt0op3 - Will be populated with the current value of this field from the register.
 * @param[out] evt0pathcomb - Will be populated with the current value of this field from the register.
 * @param[out] evt0opcomb - Will be populated with the current value of this field from the register.
 * @param[out] evt0tgtadd - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxagcevt0_unpack(uint8_t* evt0op1, uint8_t* evt0op2, uint8_t* evt0op3, uint8_t* evt0pathcomb, uint8_t* evt0opcomb, uint16_t* evt0tgtadd)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCEVT0_ADDR);

    *evt0op1 = (localVal & ((uint32_t)0xFC000000)) >> 26;
    *evt0op2 = (localVal & ((uint32_t)0x03F00000)) >> 20;
    *evt0op3 = (localVal & ((uint32_t)0x000FC000)) >> 14;
    *evt0pathcomb = (localVal & ((uint32_t)0x00002000)) >> 13;
    *evt0opcomb = (localVal & ((uint32_t)0x00001C00)) >> 10;
    *evt0tgtadd = (localVal & ((uint32_t)0x000001FF)) >> 0;
}

/**
 * @brief Returns the current value of the EVT0OP1 field in the RWNXAGCEVT0 register.
 *
 * The RWNXAGCEVT0 register will be read and the EVT0OP1 field's value will be returned.
 *
 * @return The current value of the EVT0OP1 field in the RWNXAGCEVT0 register.
 */
__INLINE uint8_t riu_evt0op1_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCEVT0_ADDR);
    return ((localVal & ((uint32_t)0xFC000000)) >> 26);
}

/**
 * @brief Sets the EVT0OP1 field of the RWNXAGCEVT0 register.
 *
 * The RWNXAGCEVT0 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] evt0op1 - The value to set the field to.
 */
__INLINE void riu_evt0op1_setf(uint8_t evt0op1)
{
    REG_PL_WR(RIU_RWNXAGCEVT0_ADDR, (REG_PL_RD(RIU_RWNXAGCEVT0_ADDR) & ~((uint32_t)0xFC000000)) | ((uint32_t)evt0op1 << 26));
}

/**
 * @brief Returns the current value of the EVT0OP2 field in the RWNXAGCEVT0 register.
 *
 * The RWNXAGCEVT0 register will be read and the EVT0OP2 field's value will be returned.
 *
 * @return The current value of the EVT0OP2 field in the RWNXAGCEVT0 register.
 */
__INLINE uint8_t riu_evt0op2_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCEVT0_ADDR);
    return ((localVal & ((uint32_t)0x03F00000)) >> 20);
}

/**
 * @brief Sets the EVT0OP2 field of the RWNXAGCEVT0 register.
 *
 * The RWNXAGCEVT0 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] evt0op2 - The value to set the field to.
 */
__INLINE void riu_evt0op2_setf(uint8_t evt0op2)
{
    REG_PL_WR(RIU_RWNXAGCEVT0_ADDR, (REG_PL_RD(RIU_RWNXAGCEVT0_ADDR) & ~((uint32_t)0x03F00000)) | ((uint32_t)evt0op2 << 20));
}

/**
 * @brief Returns the current value of the EVT0OP3 field in the RWNXAGCEVT0 register.
 *
 * The RWNXAGCEVT0 register will be read and the EVT0OP3 field's value will be returned.
 *
 * @return The current value of the EVT0OP3 field in the RWNXAGCEVT0 register.
 */
__INLINE uint8_t riu_evt0op3_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCEVT0_ADDR);
    return ((localVal & ((uint32_t)0x000FC000)) >> 14);
}

/**
 * @brief Sets the EVT0OP3 field of the RWNXAGCEVT0 register.
 *
 * The RWNXAGCEVT0 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] evt0op3 - The value to set the field to.
 */
__INLINE void riu_evt0op3_setf(uint8_t evt0op3)
{
    REG_PL_WR(RIU_RWNXAGCEVT0_ADDR, (REG_PL_RD(RIU_RWNXAGCEVT0_ADDR) & ~((uint32_t)0x000FC000)) | ((uint32_t)evt0op3 << 14));
}

/**
 * @brief Returns the current value of the EVT0PATHCOMB field in the RWNXAGCEVT0 register.
 *
 * The RWNXAGCEVT0 register will be read and the EVT0PATHCOMB field's value will be returned.
 *
 * @return The current value of the EVT0PATHCOMB field in the RWNXAGCEVT0 register.
 */
__INLINE uint8_t riu_evt0pathcomb_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCEVT0_ADDR);
    return ((localVal & ((uint32_t)0x00002000)) >> 13);
}

/**
 * @brief Sets the EVT0PATHCOMB field of the RWNXAGCEVT0 register.
 *
 * The RWNXAGCEVT0 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] evt0pathcomb - The value to set the field to.
 */
__INLINE void riu_evt0pathcomb_setf(uint8_t evt0pathcomb)
{
    REG_PL_WR(RIU_RWNXAGCEVT0_ADDR, (REG_PL_RD(RIU_RWNXAGCEVT0_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)evt0pathcomb << 13));
}

/**
 * @brief Returns the current value of the EVT0OPCOMB field in the RWNXAGCEVT0 register.
 *
 * The RWNXAGCEVT0 register will be read and the EVT0OPCOMB field's value will be returned.
 *
 * @return The current value of the EVT0OPCOMB field in the RWNXAGCEVT0 register.
 */
__INLINE uint8_t riu_evt0opcomb_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCEVT0_ADDR);
    return ((localVal & ((uint32_t)0x00001C00)) >> 10);
}

/**
 * @brief Sets the EVT0OPCOMB field of the RWNXAGCEVT0 register.
 *
 * The RWNXAGCEVT0 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] evt0opcomb - The value to set the field to.
 */
__INLINE void riu_evt0opcomb_setf(uint8_t evt0opcomb)
{
    REG_PL_WR(RIU_RWNXAGCEVT0_ADDR, (REG_PL_RD(RIU_RWNXAGCEVT0_ADDR) & ~((uint32_t)0x00001C00)) | ((uint32_t)evt0opcomb << 10));
}

/**
 * @brief Returns the current value of the EVT0TGTADD field in the RWNXAGCEVT0 register.
 *
 * The RWNXAGCEVT0 register will be read and the EVT0TGTADD field's value will be returned.
 *
 * @return The current value of the EVT0TGTADD field in the RWNXAGCEVT0 register.
 */
__INLINE uint16_t riu_evt0tgtadd_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCEVT0_ADDR);
    return ((localVal & ((uint32_t)0x000001FF)) >> 0);
}

/**
 * @brief Sets the EVT0TGTADD field of the RWNXAGCEVT0 register.
 *
 * The RWNXAGCEVT0 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] evt0tgtadd - The value to set the field to.
 */
__INLINE void riu_evt0tgtadd_setf(uint16_t evt0tgtadd)
{
    REG_PL_WR(RIU_RWNXAGCEVT0_ADDR, (REG_PL_RD(RIU_RWNXAGCEVT0_ADDR) & ~((uint32_t)0x000001FF)) | ((uint32_t)evt0tgtadd << 0));
}

/// @}

/**
 * @name RWNXAGCEVT1 register definitions
 * <table>
 * <caption id="RWNXAGCEVT1_BF">RWNXAGCEVT1 bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>31:26 <td>           EVT1OP1 <td>R <td>R/W <td>0x15
 * <tr><td>25:20 <td>           EVT1OP2 <td>R <td>R/W <td>0x17
 * <tr><td>19:14 <td>           EVT1OP3 <td>R <td>R/W <td>0xF
 * <tr><td>13 <td>      EVT1PATHCOMB <td>R <td>R/W <td>0
 * <tr><td>12:10 <td>        EVT1OPCOMB <td>R <td>R/W <td>0x2
 * <tr><td>08:00 <td>        EVT1TGTADD <td>R <td>R/W <td>0x5
 * </table>
 *
 * @{
 */

/// Address of the RWNXAGCEVT1 register
#define RIU_RWNXAGCEVT1_ADDR   0x4033B384
/// Offset of the RWNXAGCEVT1 register from the base address
#define RIU_RWNXAGCEVT1_OFFSET 0x00000384
/// Index of the RWNXAGCEVT1 register
#define RIU_RWNXAGCEVT1_INDEX  0x000000E1
/// Reset value of the RWNXAGCEVT1 register
#define RIU_RWNXAGCEVT1_RESET  0x5573C805

/**
 * @brief Returns the current value of the RWNXAGCEVT1 register.
 * The RWNXAGCEVT1 register will be read and its value returned.
 * @return The current value of the RWNXAGCEVT1 register.
 */
__INLINE uint32_t riu_rwnxagcevt1_get(void)
{
    return REG_PL_RD(RIU_RWNXAGCEVT1_ADDR);
}

/**
 * @brief Sets the RWNXAGCEVT1 register to a value.
 * The RWNXAGCEVT1 register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxagcevt1_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXAGCEVT1_ADDR, value);
}

// field definitions
/// EVT1OP1 field mask
#define RIU_EVT1OP1_MASK        ((uint32_t)0xFC000000)
/// EVT1OP1 field LSB position
#define RIU_EVT1OP1_LSB         26
/// EVT1OP1 field width
#define RIU_EVT1OP1_WIDTH       ((uint32_t)0x00000006)
/// EVT1OP2 field mask
#define RIU_EVT1OP2_MASK        ((uint32_t)0x03F00000)
/// EVT1OP2 field LSB position
#define RIU_EVT1OP2_LSB         20
/// EVT1OP2 field width
#define RIU_EVT1OP2_WIDTH       ((uint32_t)0x00000006)
/// EVT1OP3 field mask
#define RIU_EVT1OP3_MASK        ((uint32_t)0x000FC000)
/// EVT1OP3 field LSB position
#define RIU_EVT1OP3_LSB         14
/// EVT1OP3 field width
#define RIU_EVT1OP3_WIDTH       ((uint32_t)0x00000006)
/// EVT1PATHCOMB field bit
#define RIU_EVT1PATHCOMB_BIT    ((uint32_t)0x00002000)
/// EVT1PATHCOMB field position
#define RIU_EVT1PATHCOMB_POS    13
/// EVT1OPCOMB field mask
#define RIU_EVT1OPCOMB_MASK     ((uint32_t)0x00001C00)
/// EVT1OPCOMB field LSB position
#define RIU_EVT1OPCOMB_LSB      10
/// EVT1OPCOMB field width
#define RIU_EVT1OPCOMB_WIDTH    ((uint32_t)0x00000003)
/// EVT1TGTADD field mask
#define RIU_EVT1TGTADD_MASK     ((uint32_t)0x000001FF)
/// EVT1TGTADD field LSB position
#define RIU_EVT1TGTADD_LSB      0
/// EVT1TGTADD field width
#define RIU_EVT1TGTADD_WIDTH    ((uint32_t)0x00000009)

/// EVT1OP1 field reset value
#define RIU_EVT1OP1_RST         0x15
/// EVT1OP2 field reset value
#define RIU_EVT1OP2_RST         0x17
/// EVT1OP3 field reset value
#define RIU_EVT1OP3_RST         0xF
/// EVT1PATHCOMB field reset value
#define RIU_EVT1PATHCOMB_RST    0x0
/// EVT1OPCOMB field reset value
#define RIU_EVT1OPCOMB_RST      0x2
/// EVT1TGTADD field reset value
#define RIU_EVT1TGTADD_RST      0x5

/**
 * @brief Constructs a value for the RWNXAGCEVT1 register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] evt1op1 - The value to use for the EVT1OP1 field.
 * @param[in] evt1op2 - The value to use for the EVT1OP2 field.
 * @param[in] evt1op3 - The value to use for the EVT1OP3 field.
 * @param[in] evt1pathcomb - The value to use for the EVT1PATHCOMB field.
 * @param[in] evt1opcomb - The value to use for the EVT1OPCOMB field.
 * @param[in] evt1tgtadd - The value to use for the EVT1TGTADD field.
 */
__INLINE void riu_rwnxagcevt1_pack(uint8_t evt1op1, uint8_t evt1op2, uint8_t evt1op3, uint8_t evt1pathcomb, uint8_t evt1opcomb, uint16_t evt1tgtadd)
{
    REG_PL_WR(RIU_RWNXAGCEVT1_ADDR,  ((uint32_t)evt1op1 << 26) | ((uint32_t)evt1op2 << 20) | ((uint32_t)evt1op3 << 14) | ((uint32_t)evt1pathcomb << 13) | ((uint32_t)evt1opcomb << 10) | ((uint32_t)evt1tgtadd << 0));
}

/**
 * @brief Unpacks RWNXAGCEVT1's fields from current value of the RWNXAGCEVT1 register.
 *
 * Reads the RWNXAGCEVT1 register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] evt1op1 - Will be populated with the current value of this field from the register.
 * @param[out] evt1op2 - Will be populated with the current value of this field from the register.
 * @param[out] evt1op3 - Will be populated with the current value of this field from the register.
 * @param[out] evt1pathcomb - Will be populated with the current value of this field from the register.
 * @param[out] evt1opcomb - Will be populated with the current value of this field from the register.
 * @param[out] evt1tgtadd - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxagcevt1_unpack(uint8_t* evt1op1, uint8_t* evt1op2, uint8_t* evt1op3, uint8_t* evt1pathcomb, uint8_t* evt1opcomb, uint16_t* evt1tgtadd)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCEVT1_ADDR);

    *evt1op1 = (localVal & ((uint32_t)0xFC000000)) >> 26;
    *evt1op2 = (localVal & ((uint32_t)0x03F00000)) >> 20;
    *evt1op3 = (localVal & ((uint32_t)0x000FC000)) >> 14;
    *evt1pathcomb = (localVal & ((uint32_t)0x00002000)) >> 13;
    *evt1opcomb = (localVal & ((uint32_t)0x00001C00)) >> 10;
    *evt1tgtadd = (localVal & ((uint32_t)0x000001FF)) >> 0;
}

/**
 * @brief Returns the current value of the EVT1OP1 field in the RWNXAGCEVT1 register.
 *
 * The RWNXAGCEVT1 register will be read and the EVT1OP1 field's value will be returned.
 *
 * @return The current value of the EVT1OP1 field in the RWNXAGCEVT1 register.
 */
__INLINE uint8_t riu_evt1op1_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCEVT1_ADDR);
    return ((localVal & ((uint32_t)0xFC000000)) >> 26);
}

/**
 * @brief Sets the EVT1OP1 field of the RWNXAGCEVT1 register.
 *
 * The RWNXAGCEVT1 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] evt1op1 - The value to set the field to.
 */
__INLINE void riu_evt1op1_setf(uint8_t evt1op1)
{
    REG_PL_WR(RIU_RWNXAGCEVT1_ADDR, (REG_PL_RD(RIU_RWNXAGCEVT1_ADDR) & ~((uint32_t)0xFC000000)) | ((uint32_t)evt1op1 << 26));
}

/**
 * @brief Returns the current value of the EVT1OP2 field in the RWNXAGCEVT1 register.
 *
 * The RWNXAGCEVT1 register will be read and the EVT1OP2 field's value will be returned.
 *
 * @return The current value of the EVT1OP2 field in the RWNXAGCEVT1 register.
 */
__INLINE uint8_t riu_evt1op2_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCEVT1_ADDR);
    return ((localVal & ((uint32_t)0x03F00000)) >> 20);
}

/**
 * @brief Sets the EVT1OP2 field of the RWNXAGCEVT1 register.
 *
 * The RWNXAGCEVT1 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] evt1op2 - The value to set the field to.
 */
__INLINE void riu_evt1op2_setf(uint8_t evt1op2)
{
    REG_PL_WR(RIU_RWNXAGCEVT1_ADDR, (REG_PL_RD(RIU_RWNXAGCEVT1_ADDR) & ~((uint32_t)0x03F00000)) | ((uint32_t)evt1op2 << 20));
}

/**
 * @brief Returns the current value of the EVT1OP3 field in the RWNXAGCEVT1 register.
 *
 * The RWNXAGCEVT1 register will be read and the EVT1OP3 field's value will be returned.
 *
 * @return The current value of the EVT1OP3 field in the RWNXAGCEVT1 register.
 */
__INLINE uint8_t riu_evt1op3_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCEVT1_ADDR);
    return ((localVal & ((uint32_t)0x000FC000)) >> 14);
}

/**
 * @brief Sets the EVT1OP3 field of the RWNXAGCEVT1 register.
 *
 * The RWNXAGCEVT1 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] evt1op3 - The value to set the field to.
 */
__INLINE void riu_evt1op3_setf(uint8_t evt1op3)
{
    REG_PL_WR(RIU_RWNXAGCEVT1_ADDR, (REG_PL_RD(RIU_RWNXAGCEVT1_ADDR) & ~((uint32_t)0x000FC000)) | ((uint32_t)evt1op3 << 14));
}

/**
 * @brief Returns the current value of the EVT1PATHCOMB field in the RWNXAGCEVT1 register.
 *
 * The RWNXAGCEVT1 register will be read and the EVT1PATHCOMB field's value will be returned.
 *
 * @return The current value of the EVT1PATHCOMB field in the RWNXAGCEVT1 register.
 */
__INLINE uint8_t riu_evt1pathcomb_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCEVT1_ADDR);
    return ((localVal & ((uint32_t)0x00002000)) >> 13);
}

/**
 * @brief Sets the EVT1PATHCOMB field of the RWNXAGCEVT1 register.
 *
 * The RWNXAGCEVT1 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] evt1pathcomb - The value to set the field to.
 */
__INLINE void riu_evt1pathcomb_setf(uint8_t evt1pathcomb)
{
    REG_PL_WR(RIU_RWNXAGCEVT1_ADDR, (REG_PL_RD(RIU_RWNXAGCEVT1_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)evt1pathcomb << 13));
}

/**
 * @brief Returns the current value of the EVT1OPCOMB field in the RWNXAGCEVT1 register.
 *
 * The RWNXAGCEVT1 register will be read and the EVT1OPCOMB field's value will be returned.
 *
 * @return The current value of the EVT1OPCOMB field in the RWNXAGCEVT1 register.
 */
__INLINE uint8_t riu_evt1opcomb_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCEVT1_ADDR);
    return ((localVal & ((uint32_t)0x00001C00)) >> 10);
}

/**
 * @brief Sets the EVT1OPCOMB field of the RWNXAGCEVT1 register.
 *
 * The RWNXAGCEVT1 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] evt1opcomb - The value to set the field to.
 */
__INLINE void riu_evt1opcomb_setf(uint8_t evt1opcomb)
{
    REG_PL_WR(RIU_RWNXAGCEVT1_ADDR, (REG_PL_RD(RIU_RWNXAGCEVT1_ADDR) & ~((uint32_t)0x00001C00)) | ((uint32_t)evt1opcomb << 10));
}

/**
 * @brief Returns the current value of the EVT1TGTADD field in the RWNXAGCEVT1 register.
 *
 * The RWNXAGCEVT1 register will be read and the EVT1TGTADD field's value will be returned.
 *
 * @return The current value of the EVT1TGTADD field in the RWNXAGCEVT1 register.
 */
__INLINE uint16_t riu_evt1tgtadd_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCEVT1_ADDR);
    return ((localVal & ((uint32_t)0x000001FF)) >> 0);
}

/**
 * @brief Sets the EVT1TGTADD field of the RWNXAGCEVT1 register.
 *
 * The RWNXAGCEVT1 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] evt1tgtadd - The value to set the field to.
 */
__INLINE void riu_evt1tgtadd_setf(uint16_t evt1tgtadd)
{
    REG_PL_WR(RIU_RWNXAGCEVT1_ADDR, (REG_PL_RD(RIU_RWNXAGCEVT1_ADDR) & ~((uint32_t)0x000001FF)) | ((uint32_t)evt1tgtadd << 0));
}

/// @}

/**
 * @name RWNXAGCEVT2 register definitions
 * <table>
 * <caption id="RWNXAGCEVT2_BF">RWNXAGCEVT2 bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>31:26 <td>           EVT2OP1 <td>R <td>R/W <td>0x19
 * <tr><td>25:20 <td>           EVT2OP2 <td>R <td>R/W <td>0x0
 * <tr><td>19:14 <td>           EVT2OP3 <td>R <td>R/W <td>0xE
 * <tr><td>13 <td>      EVT2PATHCOMB <td>R <td>R/W <td>1
 * <tr><td>12:10 <td>        EVT2OPCOMB <td>R <td>R/W <td>0x2
 * <tr><td>08:00 <td>        EVT2TGTADD <td>R <td>R/W <td>0x8
 * </table>
 *
 * @{
 */

/// Address of the RWNXAGCEVT2 register
#define RIU_RWNXAGCEVT2_ADDR   0x4033B388
/// Offset of the RWNXAGCEVT2 register from the base address
#define RIU_RWNXAGCEVT2_OFFSET 0x00000388
/// Index of the RWNXAGCEVT2 register
#define RIU_RWNXAGCEVT2_INDEX  0x000000E2
/// Reset value of the RWNXAGCEVT2 register
#define RIU_RWNXAGCEVT2_RESET  0x6403A808

/**
 * @brief Returns the current value of the RWNXAGCEVT2 register.
 * The RWNXAGCEVT2 register will be read and its value returned.
 * @return The current value of the RWNXAGCEVT2 register.
 */
__INLINE uint32_t riu_rwnxagcevt2_get(void)
{
    return REG_PL_RD(RIU_RWNXAGCEVT2_ADDR);
}

/**
 * @brief Sets the RWNXAGCEVT2 register to a value.
 * The RWNXAGCEVT2 register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxagcevt2_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXAGCEVT2_ADDR, value);
}

// field definitions
/// EVT2OP1 field mask
#define RIU_EVT2OP1_MASK        ((uint32_t)0xFC000000)
/// EVT2OP1 field LSB position
#define RIU_EVT2OP1_LSB         26
/// EVT2OP1 field width
#define RIU_EVT2OP1_WIDTH       ((uint32_t)0x00000006)
/// EVT2OP2 field mask
#define RIU_EVT2OP2_MASK        ((uint32_t)0x03F00000)
/// EVT2OP2 field LSB position
#define RIU_EVT2OP2_LSB         20
/// EVT2OP2 field width
#define RIU_EVT2OP2_WIDTH       ((uint32_t)0x00000006)
/// EVT2OP3 field mask
#define RIU_EVT2OP3_MASK        ((uint32_t)0x000FC000)
/// EVT2OP3 field LSB position
#define RIU_EVT2OP3_LSB         14
/// EVT2OP3 field width
#define RIU_EVT2OP3_WIDTH       ((uint32_t)0x00000006)
/// EVT2PATHCOMB field bit
#define RIU_EVT2PATHCOMB_BIT    ((uint32_t)0x00002000)
/// EVT2PATHCOMB field position
#define RIU_EVT2PATHCOMB_POS    13
/// EVT2OPCOMB field mask
#define RIU_EVT2OPCOMB_MASK     ((uint32_t)0x00001C00)
/// EVT2OPCOMB field LSB position
#define RIU_EVT2OPCOMB_LSB      10
/// EVT2OPCOMB field width
#define RIU_EVT2OPCOMB_WIDTH    ((uint32_t)0x00000003)
/// EVT2TGTADD field mask
#define RIU_EVT2TGTADD_MASK     ((uint32_t)0x000001FF)
/// EVT2TGTADD field LSB position
#define RIU_EVT2TGTADD_LSB      0
/// EVT2TGTADD field width
#define RIU_EVT2TGTADD_WIDTH    ((uint32_t)0x00000009)

/// EVT2OP1 field reset value
#define RIU_EVT2OP1_RST         0x19
/// EVT2OP2 field reset value
#define RIU_EVT2OP2_RST         0x0
/// EVT2OP3 field reset value
#define RIU_EVT2OP3_RST         0xE
/// EVT2PATHCOMB field reset value
#define RIU_EVT2PATHCOMB_RST    0x1
/// EVT2OPCOMB field reset value
#define RIU_EVT2OPCOMB_RST      0x2
/// EVT2TGTADD field reset value
#define RIU_EVT2TGTADD_RST      0x8

/**
 * @brief Constructs a value for the RWNXAGCEVT2 register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] evt2op1 - The value to use for the EVT2OP1 field.
 * @param[in] evt2op2 - The value to use for the EVT2OP2 field.
 * @param[in] evt2op3 - The value to use for the EVT2OP3 field.
 * @param[in] evt2pathcomb - The value to use for the EVT2PATHCOMB field.
 * @param[in] evt2opcomb - The value to use for the EVT2OPCOMB field.
 * @param[in] evt2tgtadd - The value to use for the EVT2TGTADD field.
 */
__INLINE void riu_rwnxagcevt2_pack(uint8_t evt2op1, uint8_t evt2op2, uint8_t evt2op3, uint8_t evt2pathcomb, uint8_t evt2opcomb, uint16_t evt2tgtadd)
{
    REG_PL_WR(RIU_RWNXAGCEVT2_ADDR,  ((uint32_t)evt2op1 << 26) | ((uint32_t)evt2op2 << 20) | ((uint32_t)evt2op3 << 14) | ((uint32_t)evt2pathcomb << 13) | ((uint32_t)evt2opcomb << 10) | ((uint32_t)evt2tgtadd << 0));
}

/**
 * @brief Unpacks RWNXAGCEVT2's fields from current value of the RWNXAGCEVT2 register.
 *
 * Reads the RWNXAGCEVT2 register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] evt2op1 - Will be populated with the current value of this field from the register.
 * @param[out] evt2op2 - Will be populated with the current value of this field from the register.
 * @param[out] evt2op3 - Will be populated with the current value of this field from the register.
 * @param[out] evt2pathcomb - Will be populated with the current value of this field from the register.
 * @param[out] evt2opcomb - Will be populated with the current value of this field from the register.
 * @param[out] evt2tgtadd - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxagcevt2_unpack(uint8_t* evt2op1, uint8_t* evt2op2, uint8_t* evt2op3, uint8_t* evt2pathcomb, uint8_t* evt2opcomb, uint16_t* evt2tgtadd)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCEVT2_ADDR);

    *evt2op1 = (localVal & ((uint32_t)0xFC000000)) >> 26;
    *evt2op2 = (localVal & ((uint32_t)0x03F00000)) >> 20;
    *evt2op3 = (localVal & ((uint32_t)0x000FC000)) >> 14;
    *evt2pathcomb = (localVal & ((uint32_t)0x00002000)) >> 13;
    *evt2opcomb = (localVal & ((uint32_t)0x00001C00)) >> 10;
    *evt2tgtadd = (localVal & ((uint32_t)0x000001FF)) >> 0;
}

/**
 * @brief Returns the current value of the EVT2OP1 field in the RWNXAGCEVT2 register.
 *
 * The RWNXAGCEVT2 register will be read and the EVT2OP1 field's value will be returned.
 *
 * @return The current value of the EVT2OP1 field in the RWNXAGCEVT2 register.
 */
__INLINE uint8_t riu_evt2op1_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCEVT2_ADDR);
    return ((localVal & ((uint32_t)0xFC000000)) >> 26);
}

/**
 * @brief Sets the EVT2OP1 field of the RWNXAGCEVT2 register.
 *
 * The RWNXAGCEVT2 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] evt2op1 - The value to set the field to.
 */
__INLINE void riu_evt2op1_setf(uint8_t evt2op1)
{
    REG_PL_WR(RIU_RWNXAGCEVT2_ADDR, (REG_PL_RD(RIU_RWNXAGCEVT2_ADDR) & ~((uint32_t)0xFC000000)) | ((uint32_t)evt2op1 << 26));
}

/**
 * @brief Returns the current value of the EVT2OP2 field in the RWNXAGCEVT2 register.
 *
 * The RWNXAGCEVT2 register will be read and the EVT2OP2 field's value will be returned.
 *
 * @return The current value of the EVT2OP2 field in the RWNXAGCEVT2 register.
 */
__INLINE uint8_t riu_evt2op2_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCEVT2_ADDR);
    return ((localVal & ((uint32_t)0x03F00000)) >> 20);
}

/**
 * @brief Sets the EVT2OP2 field of the RWNXAGCEVT2 register.
 *
 * The RWNXAGCEVT2 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] evt2op2 - The value to set the field to.
 */
__INLINE void riu_evt2op2_setf(uint8_t evt2op2)
{
    REG_PL_WR(RIU_RWNXAGCEVT2_ADDR, (REG_PL_RD(RIU_RWNXAGCEVT2_ADDR) & ~((uint32_t)0x03F00000)) | ((uint32_t)evt2op2 << 20));
}

/**
 * @brief Returns the current value of the EVT2OP3 field in the RWNXAGCEVT2 register.
 *
 * The RWNXAGCEVT2 register will be read and the EVT2OP3 field's value will be returned.
 *
 * @return The current value of the EVT2OP3 field in the RWNXAGCEVT2 register.
 */
__INLINE uint8_t riu_evt2op3_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCEVT2_ADDR);
    return ((localVal & ((uint32_t)0x000FC000)) >> 14);
}

/**
 * @brief Sets the EVT2OP3 field of the RWNXAGCEVT2 register.
 *
 * The RWNXAGCEVT2 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] evt2op3 - The value to set the field to.
 */
__INLINE void riu_evt2op3_setf(uint8_t evt2op3)
{
    REG_PL_WR(RIU_RWNXAGCEVT2_ADDR, (REG_PL_RD(RIU_RWNXAGCEVT2_ADDR) & ~((uint32_t)0x000FC000)) | ((uint32_t)evt2op3 << 14));
}

/**
 * @brief Returns the current value of the EVT2PATHCOMB field in the RWNXAGCEVT2 register.
 *
 * The RWNXAGCEVT2 register will be read and the EVT2PATHCOMB field's value will be returned.
 *
 * @return The current value of the EVT2PATHCOMB field in the RWNXAGCEVT2 register.
 */
__INLINE uint8_t riu_evt2pathcomb_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCEVT2_ADDR);
    return ((localVal & ((uint32_t)0x00002000)) >> 13);
}

/**
 * @brief Sets the EVT2PATHCOMB field of the RWNXAGCEVT2 register.
 *
 * The RWNXAGCEVT2 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] evt2pathcomb - The value to set the field to.
 */
__INLINE void riu_evt2pathcomb_setf(uint8_t evt2pathcomb)
{
    REG_PL_WR(RIU_RWNXAGCEVT2_ADDR, (REG_PL_RD(RIU_RWNXAGCEVT2_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)evt2pathcomb << 13));
}

/**
 * @brief Returns the current value of the EVT2OPCOMB field in the RWNXAGCEVT2 register.
 *
 * The RWNXAGCEVT2 register will be read and the EVT2OPCOMB field's value will be returned.
 *
 * @return The current value of the EVT2OPCOMB field in the RWNXAGCEVT2 register.
 */
__INLINE uint8_t riu_evt2opcomb_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCEVT2_ADDR);
    return ((localVal & ((uint32_t)0x00001C00)) >> 10);
}

/**
 * @brief Sets the EVT2OPCOMB field of the RWNXAGCEVT2 register.
 *
 * The RWNXAGCEVT2 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] evt2opcomb - The value to set the field to.
 */
__INLINE void riu_evt2opcomb_setf(uint8_t evt2opcomb)
{
    REG_PL_WR(RIU_RWNXAGCEVT2_ADDR, (REG_PL_RD(RIU_RWNXAGCEVT2_ADDR) & ~((uint32_t)0x00001C00)) | ((uint32_t)evt2opcomb << 10));
}

/**
 * @brief Returns the current value of the EVT2TGTADD field in the RWNXAGCEVT2 register.
 *
 * The RWNXAGCEVT2 register will be read and the EVT2TGTADD field's value will be returned.
 *
 * @return The current value of the EVT2TGTADD field in the RWNXAGCEVT2 register.
 */
__INLINE uint16_t riu_evt2tgtadd_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCEVT2_ADDR);
    return ((localVal & ((uint32_t)0x000001FF)) >> 0);
}

/**
 * @brief Sets the EVT2TGTADD field of the RWNXAGCEVT2 register.
 *
 * The RWNXAGCEVT2 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] evt2tgtadd - The value to set the field to.
 */
__INLINE void riu_evt2tgtadd_setf(uint16_t evt2tgtadd)
{
    REG_PL_WR(RIU_RWNXAGCEVT2_ADDR, (REG_PL_RD(RIU_RWNXAGCEVT2_ADDR) & ~((uint32_t)0x000001FF)) | ((uint32_t)evt2tgtadd << 0));
}

/// @}

/**
 * @name RWNXAGCEVT3 register definitions
 * <table>
 * <caption id="RWNXAGCEVT3_BF">RWNXAGCEVT3 bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>31:26 <td>           EVT3OP1 <td>R <td>R/W <td>0x1
 * <tr><td>25:20 <td>           EVT3OP2 <td>R <td>R/W <td>0xF
 * <tr><td>19:14 <td>           EVT3OP3 <td>R <td>R/W <td>0x3F
 * <tr><td>13 <td>      EVT3PATHCOMB <td>R <td>R/W <td>0
 * <tr><td>12:10 <td>        EVT3OPCOMB <td>R <td>R/W <td>0x1
 * <tr><td>08:00 <td>        EVT3TGTADD <td>R <td>R/W <td>0xB
 * </table>
 *
 * @{
 */

/// Address of the RWNXAGCEVT3 register
#define RIU_RWNXAGCEVT3_ADDR   0x4033B38C
/// Offset of the RWNXAGCEVT3 register from the base address
#define RIU_RWNXAGCEVT3_OFFSET 0x0000038C
/// Index of the RWNXAGCEVT3 register
#define RIU_RWNXAGCEVT3_INDEX  0x000000E3
/// Reset value of the RWNXAGCEVT3 register
#define RIU_RWNXAGCEVT3_RESET  0x04FFC40B

/**
 * @brief Returns the current value of the RWNXAGCEVT3 register.
 * The RWNXAGCEVT3 register will be read and its value returned.
 * @return The current value of the RWNXAGCEVT3 register.
 */
__INLINE uint32_t riu_rwnxagcevt3_get(void)
{
    return REG_PL_RD(RIU_RWNXAGCEVT3_ADDR);
}

/**
 * @brief Sets the RWNXAGCEVT3 register to a value.
 * The RWNXAGCEVT3 register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxagcevt3_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXAGCEVT3_ADDR, value);
}

// field definitions
/// EVT3OP1 field mask
#define RIU_EVT3OP1_MASK        ((uint32_t)0xFC000000)
/// EVT3OP1 field LSB position
#define RIU_EVT3OP1_LSB         26
/// EVT3OP1 field width
#define RIU_EVT3OP1_WIDTH       ((uint32_t)0x00000006)
/// EVT3OP2 field mask
#define RIU_EVT3OP2_MASK        ((uint32_t)0x03F00000)
/// EVT3OP2 field LSB position
#define RIU_EVT3OP2_LSB         20
/// EVT3OP2 field width
#define RIU_EVT3OP2_WIDTH       ((uint32_t)0x00000006)
/// EVT3OP3 field mask
#define RIU_EVT3OP3_MASK        ((uint32_t)0x000FC000)
/// EVT3OP3 field LSB position
#define RIU_EVT3OP3_LSB         14
/// EVT3OP3 field width
#define RIU_EVT3OP3_WIDTH       ((uint32_t)0x00000006)
/// EVT3PATHCOMB field bit
#define RIU_EVT3PATHCOMB_BIT    ((uint32_t)0x00002000)
/// EVT3PATHCOMB field position
#define RIU_EVT3PATHCOMB_POS    13
/// EVT3OPCOMB field mask
#define RIU_EVT3OPCOMB_MASK     ((uint32_t)0x00001C00)
/// EVT3OPCOMB field LSB position
#define RIU_EVT3OPCOMB_LSB      10
/// EVT3OPCOMB field width
#define RIU_EVT3OPCOMB_WIDTH    ((uint32_t)0x00000003)
/// EVT3TGTADD field mask
#define RIU_EVT3TGTADD_MASK     ((uint32_t)0x000001FF)
/// EVT3TGTADD field LSB position
#define RIU_EVT3TGTADD_LSB      0
/// EVT3TGTADD field width
#define RIU_EVT3TGTADD_WIDTH    ((uint32_t)0x00000009)

/// EVT3OP1 field reset value
#define RIU_EVT3OP1_RST         0x1
/// EVT3OP2 field reset value
#define RIU_EVT3OP2_RST         0xF
/// EVT3OP3 field reset value
#define RIU_EVT3OP3_RST         0x3F
/// EVT3PATHCOMB field reset value
#define RIU_EVT3PATHCOMB_RST    0x0
/// EVT3OPCOMB field reset value
#define RIU_EVT3OPCOMB_RST      0x1
/// EVT3TGTADD field reset value
#define RIU_EVT3TGTADD_RST      0xB

/**
 * @brief Constructs a value for the RWNXAGCEVT3 register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] evt3op1 - The value to use for the EVT3OP1 field.
 * @param[in] evt3op2 - The value to use for the EVT3OP2 field.
 * @param[in] evt3op3 - The value to use for the EVT3OP3 field.
 * @param[in] evt3pathcomb - The value to use for the EVT3PATHCOMB field.
 * @param[in] evt3opcomb - The value to use for the EVT3OPCOMB field.
 * @param[in] evt3tgtadd - The value to use for the EVT3TGTADD field.
 */
__INLINE void riu_rwnxagcevt3_pack(uint8_t evt3op1, uint8_t evt3op2, uint8_t evt3op3, uint8_t evt3pathcomb, uint8_t evt3opcomb, uint16_t evt3tgtadd)
{
    REG_PL_WR(RIU_RWNXAGCEVT3_ADDR,  ((uint32_t)evt3op1 << 26) | ((uint32_t)evt3op2 << 20) | ((uint32_t)evt3op3 << 14) | ((uint32_t)evt3pathcomb << 13) | ((uint32_t)evt3opcomb << 10) | ((uint32_t)evt3tgtadd << 0));
}

/**
 * @brief Unpacks RWNXAGCEVT3's fields from current value of the RWNXAGCEVT3 register.
 *
 * Reads the RWNXAGCEVT3 register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] evt3op1 - Will be populated with the current value of this field from the register.
 * @param[out] evt3op2 - Will be populated with the current value of this field from the register.
 * @param[out] evt3op3 - Will be populated with the current value of this field from the register.
 * @param[out] evt3pathcomb - Will be populated with the current value of this field from the register.
 * @param[out] evt3opcomb - Will be populated with the current value of this field from the register.
 * @param[out] evt3tgtadd - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxagcevt3_unpack(uint8_t* evt3op1, uint8_t* evt3op2, uint8_t* evt3op3, uint8_t* evt3pathcomb, uint8_t* evt3opcomb, uint16_t* evt3tgtadd)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCEVT3_ADDR);

    *evt3op1 = (localVal & ((uint32_t)0xFC000000)) >> 26;
    *evt3op2 = (localVal & ((uint32_t)0x03F00000)) >> 20;
    *evt3op3 = (localVal & ((uint32_t)0x000FC000)) >> 14;
    *evt3pathcomb = (localVal & ((uint32_t)0x00002000)) >> 13;
    *evt3opcomb = (localVal & ((uint32_t)0x00001C00)) >> 10;
    *evt3tgtadd = (localVal & ((uint32_t)0x000001FF)) >> 0;
}

/**
 * @brief Returns the current value of the EVT3OP1 field in the RWNXAGCEVT3 register.
 *
 * The RWNXAGCEVT3 register will be read and the EVT3OP1 field's value will be returned.
 *
 * @return The current value of the EVT3OP1 field in the RWNXAGCEVT3 register.
 */
__INLINE uint8_t riu_evt3op1_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCEVT3_ADDR);
    return ((localVal & ((uint32_t)0xFC000000)) >> 26);
}

/**
 * @brief Sets the EVT3OP1 field of the RWNXAGCEVT3 register.
 *
 * The RWNXAGCEVT3 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] evt3op1 - The value to set the field to.
 */
__INLINE void riu_evt3op1_setf(uint8_t evt3op1)
{
    REG_PL_WR(RIU_RWNXAGCEVT3_ADDR, (REG_PL_RD(RIU_RWNXAGCEVT3_ADDR) & ~((uint32_t)0xFC000000)) | ((uint32_t)evt3op1 << 26));
}

/**
 * @brief Returns the current value of the EVT3OP2 field in the RWNXAGCEVT3 register.
 *
 * The RWNXAGCEVT3 register will be read and the EVT3OP2 field's value will be returned.
 *
 * @return The current value of the EVT3OP2 field in the RWNXAGCEVT3 register.
 */
__INLINE uint8_t riu_evt3op2_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCEVT3_ADDR);
    return ((localVal & ((uint32_t)0x03F00000)) >> 20);
}

/**
 * @brief Sets the EVT3OP2 field of the RWNXAGCEVT3 register.
 *
 * The RWNXAGCEVT3 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] evt3op2 - The value to set the field to.
 */
__INLINE void riu_evt3op2_setf(uint8_t evt3op2)
{
    REG_PL_WR(RIU_RWNXAGCEVT3_ADDR, (REG_PL_RD(RIU_RWNXAGCEVT3_ADDR) & ~((uint32_t)0x03F00000)) | ((uint32_t)evt3op2 << 20));
}

/**
 * @brief Returns the current value of the EVT3OP3 field in the RWNXAGCEVT3 register.
 *
 * The RWNXAGCEVT3 register will be read and the EVT3OP3 field's value will be returned.
 *
 * @return The current value of the EVT3OP3 field in the RWNXAGCEVT3 register.
 */
__INLINE uint8_t riu_evt3op3_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCEVT3_ADDR);
    return ((localVal & ((uint32_t)0x000FC000)) >> 14);
}

/**
 * @brief Sets the EVT3OP3 field of the RWNXAGCEVT3 register.
 *
 * The RWNXAGCEVT3 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] evt3op3 - The value to set the field to.
 */
__INLINE void riu_evt3op3_setf(uint8_t evt3op3)
{
    REG_PL_WR(RIU_RWNXAGCEVT3_ADDR, (REG_PL_RD(RIU_RWNXAGCEVT3_ADDR) & ~((uint32_t)0x000FC000)) | ((uint32_t)evt3op3 << 14));
}

/**
 * @brief Returns the current value of the EVT3PATHCOMB field in the RWNXAGCEVT3 register.
 *
 * The RWNXAGCEVT3 register will be read and the EVT3PATHCOMB field's value will be returned.
 *
 * @return The current value of the EVT3PATHCOMB field in the RWNXAGCEVT3 register.
 */
__INLINE uint8_t riu_evt3pathcomb_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCEVT3_ADDR);
    return ((localVal & ((uint32_t)0x00002000)) >> 13);
}

/**
 * @brief Sets the EVT3PATHCOMB field of the RWNXAGCEVT3 register.
 *
 * The RWNXAGCEVT3 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] evt3pathcomb - The value to set the field to.
 */
__INLINE void riu_evt3pathcomb_setf(uint8_t evt3pathcomb)
{
    REG_PL_WR(RIU_RWNXAGCEVT3_ADDR, (REG_PL_RD(RIU_RWNXAGCEVT3_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)evt3pathcomb << 13));
}

/**
 * @brief Returns the current value of the EVT3OPCOMB field in the RWNXAGCEVT3 register.
 *
 * The RWNXAGCEVT3 register will be read and the EVT3OPCOMB field's value will be returned.
 *
 * @return The current value of the EVT3OPCOMB field in the RWNXAGCEVT3 register.
 */
__INLINE uint8_t riu_evt3opcomb_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCEVT3_ADDR);
    return ((localVal & ((uint32_t)0x00001C00)) >> 10);
}

/**
 * @brief Sets the EVT3OPCOMB field of the RWNXAGCEVT3 register.
 *
 * The RWNXAGCEVT3 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] evt3opcomb - The value to set the field to.
 */
__INLINE void riu_evt3opcomb_setf(uint8_t evt3opcomb)
{
    REG_PL_WR(RIU_RWNXAGCEVT3_ADDR, (REG_PL_RD(RIU_RWNXAGCEVT3_ADDR) & ~((uint32_t)0x00001C00)) | ((uint32_t)evt3opcomb << 10));
}

/**
 * @brief Returns the current value of the EVT3TGTADD field in the RWNXAGCEVT3 register.
 *
 * The RWNXAGCEVT3 register will be read and the EVT3TGTADD field's value will be returned.
 *
 * @return The current value of the EVT3TGTADD field in the RWNXAGCEVT3 register.
 */
__INLINE uint16_t riu_evt3tgtadd_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCEVT3_ADDR);
    return ((localVal & ((uint32_t)0x000001FF)) >> 0);
}

/**
 * @brief Sets the EVT3TGTADD field of the RWNXAGCEVT3 register.
 *
 * The RWNXAGCEVT3 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] evt3tgtadd - The value to set the field to.
 */
__INLINE void riu_evt3tgtadd_setf(uint16_t evt3tgtadd)
{
    REG_PL_WR(RIU_RWNXAGCEVT3_ADDR, (REG_PL_RD(RIU_RWNXAGCEVT3_ADDR) & ~((uint32_t)0x000001FF)) | ((uint32_t)evt3tgtadd << 0));
}

/// @}

/**
 * @name RWNXAGCCNTL register definitions
 * <table>
 * <caption id="RWNXAGCCNTL_BF">RWNXAGCCNTL bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>19 <td>      AGCRAM_READY <td>R <td>R/W <td>0
 * <tr><td>18:17 <td>   AGCROM_MODE_SEL <td>R <td>R/W <td>0x1
 * <tr><td>16 <td>       HTSTFGAINEN <td>R <td>R/W <td>1
 * <tr><td>12 <td>       AGCFSMRESET <td>R <td>R/W <td>0
 * <tr><td>11 <td>        RADARDETEN <td>R <td>R/W <td>0
 * <tr><td>10 <td>         RIFSDETEN <td>R <td>R/W <td>1
 * <tr><td>09 <td>          DSSSONLY <td>R <td>R/W <td>0
 * <tr><td>08 <td>          OFDMONLY <td>R <td>R/W <td>0
 * <tr><td>07:04 <td>          GPSTATUS <td>R <td>R/W <td>0x0
 * <tr><td>01:00 <td>       COMBPATHSEL <td>R <td>R/W <td>0x3
 * </table>
 *
 * @{
 */

/// Address of the RWNXAGCCNTL register
#define RIU_RWNXAGCCNTL_ADDR   0x4033B390
/// Offset of the RWNXAGCCNTL register from the base address
#define RIU_RWNXAGCCNTL_OFFSET 0x00000390
/// Index of the RWNXAGCCNTL register
#define RIU_RWNXAGCCNTL_INDEX  0x000000E4
/// Reset value of the RWNXAGCCNTL register
#define RIU_RWNXAGCCNTL_RESET  0x00030403

/**
 * @brief Returns the current value of the RWNXAGCCNTL register.
 * The RWNXAGCCNTL register will be read and its value returned.
 * @return The current value of the RWNXAGCCNTL register.
 */
__INLINE uint32_t riu_rwnxagccntl_get(void)
{
    return REG_PL_RD(RIU_RWNXAGCCNTL_ADDR);
}

/**
 * @brief Sets the RWNXAGCCNTL register to a value.
 * The RWNXAGCCNTL register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxagccntl_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXAGCCNTL_ADDR, value);
}

// field definitions
/// AGCRAM_READY field bit
#define RIU_AGCRAM_READY_BIT       ((uint32_t)0x00080000)
/// AGCRAM_READY field position
#define RIU_AGCRAM_READY_POS       19
/// AGCROM_MODE_SEL field mask
#define RIU_AGCROM_MODE_SEL_MASK   ((uint32_t)0x00060000)
/// AGCROM_MODE_SEL field LSB position
#define RIU_AGCROM_MODE_SEL_LSB    17
/// AGCROM_MODE_SEL field width
#define RIU_AGCROM_MODE_SEL_WIDTH  ((uint32_t)0x00000002)
/// HTSTFGAINEN field bit
#define RIU_HTSTFGAINEN_BIT        ((uint32_t)0x00010000)
/// HTSTFGAINEN field position
#define RIU_HTSTFGAINEN_POS        16
/// AGCFSMRESET field bit
#define RIU_AGCFSMRESET_BIT        ((uint32_t)0x00001000)
/// AGCFSMRESET field position
#define RIU_AGCFSMRESET_POS        12
/// RADARDETEN field bit
#define RIU_RADARDETEN_BIT         ((uint32_t)0x00000800)
/// RADARDETEN field position
#define RIU_RADARDETEN_POS         11
/// RIFSDETEN field bit
#define RIU_RIFSDETEN_BIT          ((uint32_t)0x00000400)
/// RIFSDETEN field position
#define RIU_RIFSDETEN_POS          10
/// DSSSONLY field bit
#define RIU_DSSSONLY_BIT           ((uint32_t)0x00000200)
/// DSSSONLY field position
#define RIU_DSSSONLY_POS           9
/// OFDMONLY field bit
#define RIU_OFDMONLY_BIT           ((uint32_t)0x00000100)
/// OFDMONLY field position
#define RIU_OFDMONLY_POS           8
/// GPSTATUS field mask
#define RIU_GPSTATUS_MASK          ((uint32_t)0x000000F0)
/// GPSTATUS field LSB position
#define RIU_GPSTATUS_LSB           4
/// GPSTATUS field width
#define RIU_GPSTATUS_WIDTH         ((uint32_t)0x00000004)
/// COMBPATHSEL field mask
#define RIU_COMBPATHSEL_MASK       ((uint32_t)0x00000003)
/// COMBPATHSEL field LSB position
#define RIU_COMBPATHSEL_LSB        0
/// COMBPATHSEL field width
#define RIU_COMBPATHSEL_WIDTH      ((uint32_t)0x00000002)

/// AGCRAM_READY field reset value
#define RIU_AGCRAM_READY_RST       0x0
/// AGCROM_MODE_SEL field reset value
#define RIU_AGCROM_MODE_SEL_RST    0x1
/// HTSTFGAINEN field reset value
#define RIU_HTSTFGAINEN_RST        0x1
/// AGCFSMRESET field reset value
#define RIU_AGCFSMRESET_RST        0x0
/// RADARDETEN field reset value
#define RIU_RADARDETEN_RST         0x0
/// RIFSDETEN field reset value
#define RIU_RIFSDETEN_RST          0x1
/// DSSSONLY field reset value
#define RIU_DSSSONLY_RST           0x0
/// OFDMONLY field reset value
#define RIU_OFDMONLY_RST           0x0
/// GPSTATUS field reset value
#define RIU_GPSTATUS_RST           0x0
/// COMBPATHSEL field reset value
#define RIU_COMBPATHSEL_RST        0x3

/**
 * @brief Constructs a value for the RWNXAGCCNTL register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] agcramready - The value to use for the AGCRAM_READY field.
 * @param[in] agcrommodesel - The value to use for the AGCROM_MODE_SEL field.
 * @param[in] htstfgainen - The value to use for the HTSTFGAINEN field.
 * @param[in] agcfsmreset - The value to use for the AGCFSMRESET field.
 * @param[in] radardeten - The value to use for the RADARDETEN field.
 * @param[in] rifsdeten - The value to use for the RIFSDETEN field.
 * @param[in] dsssonly - The value to use for the DSSSONLY field.
 * @param[in] ofdmonly - The value to use for the OFDMONLY field.
 * @param[in] gpstatus - The value to use for the GPSTATUS field.
 * @param[in] combpathsel - The value to use for the COMBPATHSEL field.
 */
__INLINE void riu_rwnxagccntl_pack(uint8_t agcramready, uint8_t agcrommodesel, uint8_t htstfgainen, uint8_t agcfsmreset, uint8_t radardeten, uint8_t rifsdeten, uint8_t dsssonly, uint8_t ofdmonly, uint8_t gpstatus, uint8_t combpathsel)
{
    REG_PL_WR(RIU_RWNXAGCCNTL_ADDR,  ((uint32_t)agcramready << 19) | ((uint32_t)agcrommodesel << 17) | ((uint32_t)htstfgainen << 16) | ((uint32_t)agcfsmreset << 12) | ((uint32_t)radardeten << 11) | ((uint32_t)rifsdeten << 10) | ((uint32_t)dsssonly << 9) | ((uint32_t)ofdmonly << 8) | ((uint32_t)gpstatus << 4) | ((uint32_t)combpathsel << 0));
}

/**
 * @brief Unpacks RWNXAGCCNTL's fields from current value of the RWNXAGCCNTL register.
 *
 * Reads the RWNXAGCCNTL register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] agcramready - Will be populated with the current value of this field from the register.
 * @param[out] agcrommodesel - Will be populated with the current value of this field from the register.
 * @param[out] htstfgainen - Will be populated with the current value of this field from the register.
 * @param[out] agcfsmreset - Will be populated with the current value of this field from the register.
 * @param[out] radardeten - Will be populated with the current value of this field from the register.
 * @param[out] rifsdeten - Will be populated with the current value of this field from the register.
 * @param[out] dsssonly - Will be populated with the current value of this field from the register.
 * @param[out] ofdmonly - Will be populated with the current value of this field from the register.
 * @param[out] gpstatus - Will be populated with the current value of this field from the register.
 * @param[out] combpathsel - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxagccntl_unpack(uint8_t* agcramready, uint8_t* agcrommodesel, uint8_t* htstfgainen, uint8_t* agcfsmreset, uint8_t* radardeten, uint8_t* rifsdeten, uint8_t* dsssonly, uint8_t* ofdmonly, uint8_t* gpstatus, uint8_t* combpathsel)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCCNTL_ADDR);

    *agcramready = (localVal & ((uint32_t)0x00080000)) >> 19;
    *agcrommodesel = (localVal & ((uint32_t)0x00060000)) >> 17;
    *htstfgainen = (localVal & ((uint32_t)0x00010000)) >> 16;
    *agcfsmreset = (localVal & ((uint32_t)0x00001000)) >> 12;
    *radardeten = (localVal & ((uint32_t)0x00000800)) >> 11;
    *rifsdeten = (localVal & ((uint32_t)0x00000400)) >> 10;
    *dsssonly = (localVal & ((uint32_t)0x00000200)) >> 9;
    *ofdmonly = (localVal & ((uint32_t)0x00000100)) >> 8;
    *gpstatus = (localVal & ((uint32_t)0x000000F0)) >> 4;
    *combpathsel = (localVal & ((uint32_t)0x00000003)) >> 0;
}

/**
 * @brief Returns the current value of the AGCRAM_READY field in the RWNXAGCCNTL register.
 *
 * The RWNXAGCCNTL register will be read and the AGCRAM_READY field's value will be returned.
 *
 * @return The current value of the AGCRAM_READY field in the RWNXAGCCNTL register.
 */
__INLINE uint8_t riu_agcram_ready_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCCNTL_ADDR);
    return ((localVal & ((uint32_t)0x00080000)) >> 19);
}

/**
 * @brief Sets the AGCRAM_READY field of the RWNXAGCCNTL register.
 *
 * The RWNXAGCCNTL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] agcramready - The value to set the field to.
 */
__INLINE void riu_agcram_ready_setf(uint8_t agcramready)
{
    REG_PL_WR(RIU_RWNXAGCCNTL_ADDR, (REG_PL_RD(RIU_RWNXAGCCNTL_ADDR) & ~((uint32_t)0x00080000)) | ((uint32_t)agcramready << 19));
}

/**
 * @brief Returns the current value of the AGCROM_MODE_SEL field in the RWNXAGCCNTL register.
 *
 * The RWNXAGCCNTL register will be read and the AGCROM_MODE_SEL field's value will be returned.
 *
 * @return The current value of the AGCROM_MODE_SEL field in the RWNXAGCCNTL register.
 */
__INLINE uint8_t riu_agcrom_mode_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCCNTL_ADDR);
    return ((localVal & ((uint32_t)0x00060000)) >> 17);
}

/**
 * @brief Sets the AGCROM_MODE_SEL field of the RWNXAGCCNTL register.
 *
 * The RWNXAGCCNTL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] agcrommodesel - The value to set the field to.
 */
__INLINE void riu_agcrom_mode_sel_setf(uint8_t agcrommodesel)
{
    REG_PL_WR(RIU_RWNXAGCCNTL_ADDR, (REG_PL_RD(RIU_RWNXAGCCNTL_ADDR) & ~((uint32_t)0x00060000)) | ((uint32_t)agcrommodesel << 17));
}

/**
 * @brief Returns the current value of the HTSTFGAINEN field in the RWNXAGCCNTL register.
 *
 * The RWNXAGCCNTL register will be read and the HTSTFGAINEN field's value will be returned.
 *
 * @return The current value of the HTSTFGAINEN field in the RWNXAGCCNTL register.
 */
__INLINE uint8_t riu_htstfgainen_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCCNTL_ADDR);
    return ((localVal & ((uint32_t)0x00010000)) >> 16);
}

/**
 * @brief Sets the HTSTFGAINEN field of the RWNXAGCCNTL register.
 *
 * The RWNXAGCCNTL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] htstfgainen - The value to set the field to.
 */
__INLINE void riu_htstfgainen_setf(uint8_t htstfgainen)
{
    REG_PL_WR(RIU_RWNXAGCCNTL_ADDR, (REG_PL_RD(RIU_RWNXAGCCNTL_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)htstfgainen << 16));
}

/**
 * @brief Returns the current value of the AGCFSMRESET field in the RWNXAGCCNTL register.
 *
 * The RWNXAGCCNTL register will be read and the AGCFSMRESET field's value will be returned.
 *
 * @return The current value of the AGCFSMRESET field in the RWNXAGCCNTL register.
 */
__INLINE uint8_t riu_agcfsmreset_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCCNTL_ADDR);
    return ((localVal & ((uint32_t)0x00001000)) >> 12);
}

/**
 * @brief Sets the AGCFSMRESET field of the RWNXAGCCNTL register.
 *
 * The RWNXAGCCNTL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] agcfsmreset - The value to set the field to.
 */
__INLINE void riu_agcfsmreset_setf(uint8_t agcfsmreset)
{
    REG_PL_WR(RIU_RWNXAGCCNTL_ADDR, (REG_PL_RD(RIU_RWNXAGCCNTL_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)agcfsmreset << 12));
}

/**
 * @brief Returns the current value of the RADARDETEN field in the RWNXAGCCNTL register.
 *
 * The RWNXAGCCNTL register will be read and the RADARDETEN field's value will be returned.
 *
 * @return The current value of the RADARDETEN field in the RWNXAGCCNTL register.
 */
__INLINE uint8_t riu_radardeten_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCCNTL_ADDR);
    return ((localVal & ((uint32_t)0x00000800)) >> 11);
}

/**
 * @brief Sets the RADARDETEN field of the RWNXAGCCNTL register.
 *
 * The RWNXAGCCNTL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] radardeten - The value to set the field to.
 */
__INLINE void riu_radardeten_setf(uint8_t radardeten)
{
    REG_PL_WR(RIU_RWNXAGCCNTL_ADDR, (REG_PL_RD(RIU_RWNXAGCCNTL_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)radardeten << 11));
}

/**
 * @brief Returns the current value of the RIFSDETEN field in the RWNXAGCCNTL register.
 *
 * The RWNXAGCCNTL register will be read and the RIFSDETEN field's value will be returned.
 *
 * @return The current value of the RIFSDETEN field in the RWNXAGCCNTL register.
 */
__INLINE uint8_t riu_rifsdeten_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCCNTL_ADDR);
    return ((localVal & ((uint32_t)0x00000400)) >> 10);
}

/**
 * @brief Sets the RIFSDETEN field of the RWNXAGCCNTL register.
 *
 * The RWNXAGCCNTL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rifsdeten - The value to set the field to.
 */
__INLINE void riu_rifsdeten_setf(uint8_t rifsdeten)
{
    REG_PL_WR(RIU_RWNXAGCCNTL_ADDR, (REG_PL_RD(RIU_RWNXAGCCNTL_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)rifsdeten << 10));
}

/**
 * @brief Returns the current value of the DSSSONLY field in the RWNXAGCCNTL register.
 *
 * The RWNXAGCCNTL register will be read and the DSSSONLY field's value will be returned.
 *
 * @return The current value of the DSSSONLY field in the RWNXAGCCNTL register.
 */
__INLINE uint8_t riu_dsssonly_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCCNTL_ADDR);
    return ((localVal & ((uint32_t)0x00000200)) >> 9);
}

/**
 * @brief Sets the DSSSONLY field of the RWNXAGCCNTL register.
 *
 * The RWNXAGCCNTL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] dsssonly - The value to set the field to.
 */
__INLINE void riu_dsssonly_setf(uint8_t dsssonly)
{
    REG_PL_WR(RIU_RWNXAGCCNTL_ADDR, (REG_PL_RD(RIU_RWNXAGCCNTL_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)dsssonly << 9));
}

/**
 * @brief Returns the current value of the OFDMONLY field in the RWNXAGCCNTL register.
 *
 * The RWNXAGCCNTL register will be read and the OFDMONLY field's value will be returned.
 *
 * @return The current value of the OFDMONLY field in the RWNXAGCCNTL register.
 */
__INLINE uint8_t riu_ofdmonly_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCCNTL_ADDR);
    return ((localVal & ((uint32_t)0x00000100)) >> 8);
}

/**
 * @brief Sets the OFDMONLY field of the RWNXAGCCNTL register.
 *
 * The RWNXAGCCNTL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] ofdmonly - The value to set the field to.
 */
__INLINE void riu_ofdmonly_setf(uint8_t ofdmonly)
{
    REG_PL_WR(RIU_RWNXAGCCNTL_ADDR, (REG_PL_RD(RIU_RWNXAGCCNTL_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)ofdmonly << 8));
}

/**
 * @brief Returns the current value of the GPSTATUS field in the RWNXAGCCNTL register.
 *
 * The RWNXAGCCNTL register will be read and the GPSTATUS field's value will be returned.
 *
 * @return The current value of the GPSTATUS field in the RWNXAGCCNTL register.
 */
__INLINE uint8_t riu_gpstatus_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCCNTL_ADDR);
    return ((localVal & ((uint32_t)0x000000F0)) >> 4);
}

/**
 * @brief Sets the GPSTATUS field of the RWNXAGCCNTL register.
 *
 * The RWNXAGCCNTL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] gpstatus - The value to set the field to.
 */
__INLINE void riu_gpstatus_setf(uint8_t gpstatus)
{
    REG_PL_WR(RIU_RWNXAGCCNTL_ADDR, (REG_PL_RD(RIU_RWNXAGCCNTL_ADDR) & ~((uint32_t)0x000000F0)) | ((uint32_t)gpstatus << 4));
}

/**
 * @brief Returns the current value of the COMBPATHSEL field in the RWNXAGCCNTL register.
 *
 * The RWNXAGCCNTL register will be read and the COMBPATHSEL field's value will be returned.
 *
 * @return The current value of the COMBPATHSEL field in the RWNXAGCCNTL register.
 */
__INLINE uint8_t riu_combpathsel_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCCNTL_ADDR);
    return ((localVal & ((uint32_t)0x00000003)) >> 0);
}

/**
 * @brief Sets the COMBPATHSEL field of the RWNXAGCCNTL register.
 *
 * The RWNXAGCCNTL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] combpathsel - The value to set the field to.
 */
__INLINE void riu_combpathsel_setf(uint8_t combpathsel)
{
    REG_PL_WR(RIU_RWNXAGCCNTL_ADDR, (REG_PL_RD(RIU_RWNXAGCCNTL_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)combpathsel << 0));
}

/// @}

/**
 * @name RWNXAGCDSP0 register definitions
 * <table>
 * <caption id="RWNXAGCDSP0_BF">RWNXAGCDSP0 bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>27:24 <td>           NBITADC <td>R <td>R/W <td>0xC
 * <tr><td>23:16 <td>      VPEAKADCQDBV <td>R <td>R/W <td>0xE8
 * <tr><td>15:08 <td>      ADCPOWMINDBV <td>R <td>R/W <td>0xB5
 * <tr><td>07:00 <td>    ADCPOWBIASQDBV <td>R <td>R/W <td>0x0
 * </table>
 *
 * @{
 */

/// Address of the RWNXAGCDSP0 register
#define RIU_RWNXAGCDSP0_ADDR   0x4033B394
/// Offset of the RWNXAGCDSP0 register from the base address
#define RIU_RWNXAGCDSP0_OFFSET 0x00000394
/// Index of the RWNXAGCDSP0 register
#define RIU_RWNXAGCDSP0_INDEX  0x000000E5
/// Reset value of the RWNXAGCDSP0 register
#define RIU_RWNXAGCDSP0_RESET  0x0CE8B500

/**
 * @brief Returns the current value of the RWNXAGCDSP0 register.
 * The RWNXAGCDSP0 register will be read and its value returned.
 * @return The current value of the RWNXAGCDSP0 register.
 */
__INLINE uint32_t riu_rwnxagcdsp0_get(void)
{
    return REG_PL_RD(RIU_RWNXAGCDSP0_ADDR);
}

/**
 * @brief Sets the RWNXAGCDSP0 register to a value.
 * The RWNXAGCDSP0 register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxagcdsp0_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXAGCDSP0_ADDR, value);
}

// field definitions
/// NBITADC field mask
#define RIU_NBITADC_MASK          ((uint32_t)0x0F000000)
/// NBITADC field LSB position
#define RIU_NBITADC_LSB           24
/// NBITADC field width
#define RIU_NBITADC_WIDTH         ((uint32_t)0x00000004)
/// VPEAKADCQDBV field mask
#define RIU_VPEAKADCQDBV_MASK     ((uint32_t)0x00FF0000)
/// VPEAKADCQDBV field LSB position
#define RIU_VPEAKADCQDBV_LSB      16
/// VPEAKADCQDBV field width
#define RIU_VPEAKADCQDBV_WIDTH    ((uint32_t)0x00000008)
/// ADCPOWMINDBV field mask
#define RIU_ADCPOWMINDBV_MASK     ((uint32_t)0x0000FF00)
/// ADCPOWMINDBV field LSB position
#define RIU_ADCPOWMINDBV_LSB      8
/// ADCPOWMINDBV field width
#define RIU_ADCPOWMINDBV_WIDTH    ((uint32_t)0x00000008)
/// ADCPOWBIASQDBV field mask
#define RIU_ADCPOWBIASQDBV_MASK   ((uint32_t)0x000000FF)
/// ADCPOWBIASQDBV field LSB position
#define RIU_ADCPOWBIASQDBV_LSB    0
/// ADCPOWBIASQDBV field width
#define RIU_ADCPOWBIASQDBV_WIDTH  ((uint32_t)0x00000008)

/// NBITADC field reset value
#define RIU_NBITADC_RST           0xC
/// VPEAKADCQDBV field reset value
#define RIU_VPEAKADCQDBV_RST      0xE8
/// ADCPOWMINDBV field reset value
#define RIU_ADCPOWMINDBV_RST      0xB5
/// ADCPOWBIASQDBV field reset value
#define RIU_ADCPOWBIASQDBV_RST    0x0

/**
 * @brief Constructs a value for the RWNXAGCDSP0 register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] nbitadc - The value to use for the NBITADC field.
 * @param[in] vpeakadcqdbv - The value to use for the VPEAKADCQDBV field.
 * @param[in] adcpowmindbv - The value to use for the ADCPOWMINDBV field.
 * @param[in] adcpowbiasqdbv - The value to use for the ADCPOWBIASQDBV field.
 */
__INLINE void riu_rwnxagcdsp0_pack(uint8_t nbitadc, uint8_t vpeakadcqdbv, uint8_t adcpowmindbv, uint8_t adcpowbiasqdbv)
{
    REG_PL_WR(RIU_RWNXAGCDSP0_ADDR,  ((uint32_t)nbitadc << 24) | ((uint32_t)vpeakadcqdbv << 16) | ((uint32_t)adcpowmindbv << 8) | ((uint32_t)adcpowbiasqdbv << 0));
}

/**
 * @brief Unpacks RWNXAGCDSP0's fields from current value of the RWNXAGCDSP0 register.
 *
 * Reads the RWNXAGCDSP0 register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] nbitadc - Will be populated with the current value of this field from the register.
 * @param[out] vpeakadcqdbv - Will be populated with the current value of this field from the register.
 * @param[out] adcpowmindbv - Will be populated with the current value of this field from the register.
 * @param[out] adcpowbiasqdbv - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxagcdsp0_unpack(uint8_t* nbitadc, uint8_t* vpeakadcqdbv, uint8_t* adcpowmindbv, uint8_t* adcpowbiasqdbv)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCDSP0_ADDR);

    *nbitadc = (localVal & ((uint32_t)0x0F000000)) >> 24;
    *vpeakadcqdbv = (localVal & ((uint32_t)0x00FF0000)) >> 16;
    *adcpowmindbv = (localVal & ((uint32_t)0x0000FF00)) >> 8;
    *adcpowbiasqdbv = (localVal & ((uint32_t)0x000000FF)) >> 0;
}

/**
 * @brief Returns the current value of the NBITADC field in the RWNXAGCDSP0 register.
 *
 * The RWNXAGCDSP0 register will be read and the NBITADC field's value will be returned.
 *
 * @return The current value of the NBITADC field in the RWNXAGCDSP0 register.
 */
__INLINE uint8_t riu_nbitadc_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCDSP0_ADDR);
    return ((localVal & ((uint32_t)0x0F000000)) >> 24);
}

/**
 * @brief Sets the NBITADC field of the RWNXAGCDSP0 register.
 *
 * The RWNXAGCDSP0 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] nbitadc - The value to set the field to.
 */
__INLINE void riu_nbitadc_setf(uint8_t nbitadc)
{
    REG_PL_WR(RIU_RWNXAGCDSP0_ADDR, (REG_PL_RD(RIU_RWNXAGCDSP0_ADDR) & ~((uint32_t)0x0F000000)) | ((uint32_t)nbitadc << 24));
}

/**
 * @brief Returns the current value of the VPEAKADCQDBV field in the RWNXAGCDSP0 register.
 *
 * The RWNXAGCDSP0 register will be read and the VPEAKADCQDBV field's value will be returned.
 *
 * @return The current value of the VPEAKADCQDBV field in the RWNXAGCDSP0 register.
 */
__INLINE uint8_t riu_vpeakadcqdbv_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCDSP0_ADDR);
    return ((localVal & ((uint32_t)0x00FF0000)) >> 16);
}

/**
 * @brief Sets the VPEAKADCQDBV field of the RWNXAGCDSP0 register.
 *
 * The RWNXAGCDSP0 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] vpeakadcqdbv - The value to set the field to.
 */
__INLINE void riu_vpeakadcqdbv_setf(uint8_t vpeakadcqdbv)
{
    REG_PL_WR(RIU_RWNXAGCDSP0_ADDR, (REG_PL_RD(RIU_RWNXAGCDSP0_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)vpeakadcqdbv << 16));
}

/**
 * @brief Returns the current value of the ADCPOWMINDBV field in the RWNXAGCDSP0 register.
 *
 * The RWNXAGCDSP0 register will be read and the ADCPOWMINDBV field's value will be returned.
 *
 * @return The current value of the ADCPOWMINDBV field in the RWNXAGCDSP0 register.
 */
__INLINE uint8_t riu_adcpowmindbv_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCDSP0_ADDR);
    return ((localVal & ((uint32_t)0x0000FF00)) >> 8);
}

/**
 * @brief Sets the ADCPOWMINDBV field of the RWNXAGCDSP0 register.
 *
 * The RWNXAGCDSP0 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] adcpowmindbv - The value to set the field to.
 */
__INLINE void riu_adcpowmindbv_setf(uint8_t adcpowmindbv)
{
    REG_PL_WR(RIU_RWNXAGCDSP0_ADDR, (REG_PL_RD(RIU_RWNXAGCDSP0_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)adcpowmindbv << 8));
}

/**
 * @brief Returns the current value of the ADCPOWBIASQDBV field in the RWNXAGCDSP0 register.
 *
 * The RWNXAGCDSP0 register will be read and the ADCPOWBIASQDBV field's value will be returned.
 *
 * @return The current value of the ADCPOWBIASQDBV field in the RWNXAGCDSP0 register.
 */
__INLINE uint8_t riu_adcpowbiasqdbv_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCDSP0_ADDR);
    return ((localVal & ((uint32_t)0x000000FF)) >> 0);
}

/**
 * @brief Sets the ADCPOWBIASQDBV field of the RWNXAGCDSP0 register.
 *
 * The RWNXAGCDSP0 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] adcpowbiasqdbv - The value to set the field to.
 */
__INLINE void riu_adcpowbiasqdbv_setf(uint8_t adcpowbiasqdbv)
{
    REG_PL_WR(RIU_RWNXAGCDSP0_ADDR, (REG_PL_RD(RIU_RWNXAGCDSP0_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)adcpowbiasqdbv << 0));
}

/// @}

/**
 * @name RWNXAGCDSP1 register definitions
 * <table>
 * <caption id="RWNXAGCDSP1_BF">RWNXAGCDSP1 bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>15:08 <td>      ADCPOWMINDBM <td>R <td>R/W <td>0x9C
 * <tr><td>07:00 <td>    ADCPOWBIASQDBM <td>R <td>R/W <td>0x0
 * </table>
 *
 * @{
 */

/// Address of the RWNXAGCDSP1 register
#define RIU_RWNXAGCDSP1_ADDR   0x4033B398
/// Offset of the RWNXAGCDSP1 register from the base address
#define RIU_RWNXAGCDSP1_OFFSET 0x00000398
/// Index of the RWNXAGCDSP1 register
#define RIU_RWNXAGCDSP1_INDEX  0x000000E6
/// Reset value of the RWNXAGCDSP1 register
#define RIU_RWNXAGCDSP1_RESET  0x00009C00

/**
 * @brief Returns the current value of the RWNXAGCDSP1 register.
 * The RWNXAGCDSP1 register will be read and its value returned.
 * @return The current value of the RWNXAGCDSP1 register.
 */
__INLINE uint32_t riu_rwnxagcdsp1_get(void)
{
    return REG_PL_RD(RIU_RWNXAGCDSP1_ADDR);
}

/**
 * @brief Sets the RWNXAGCDSP1 register to a value.
 * The RWNXAGCDSP1 register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxagcdsp1_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXAGCDSP1_ADDR, value);
}

// field definitions
/// ADCPOWMINDBM field mask
#define RIU_ADCPOWMINDBM_MASK     ((uint32_t)0x0000FF00)
/// ADCPOWMINDBM field LSB position
#define RIU_ADCPOWMINDBM_LSB      8
/// ADCPOWMINDBM field width
#define RIU_ADCPOWMINDBM_WIDTH    ((uint32_t)0x00000008)
/// ADCPOWBIASQDBM field mask
#define RIU_ADCPOWBIASQDBM_MASK   ((uint32_t)0x000000FF)
/// ADCPOWBIASQDBM field LSB position
#define RIU_ADCPOWBIASQDBM_LSB    0
/// ADCPOWBIASQDBM field width
#define RIU_ADCPOWBIASQDBM_WIDTH  ((uint32_t)0x00000008)

/// ADCPOWMINDBM field reset value
#define RIU_ADCPOWMINDBM_RST      0x9C
/// ADCPOWBIASQDBM field reset value
#define RIU_ADCPOWBIASQDBM_RST    0x0

/**
 * @brief Constructs a value for the RWNXAGCDSP1 register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] adcpowmindbm - The value to use for the ADCPOWMINDBM field.
 * @param[in] adcpowbiasqdbm - The value to use for the ADCPOWBIASQDBM field.
 */
__INLINE void riu_rwnxagcdsp1_pack(uint8_t adcpowmindbm, uint8_t adcpowbiasqdbm)
{
    REG_PL_WR(RIU_RWNXAGCDSP1_ADDR,  ((uint32_t)adcpowmindbm << 8) | ((uint32_t)adcpowbiasqdbm << 0));
}

/**
 * @brief Unpacks RWNXAGCDSP1's fields from current value of the RWNXAGCDSP1 register.
 *
 * Reads the RWNXAGCDSP1 register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] adcpowmindbm - Will be populated with the current value of this field from the register.
 * @param[out] adcpowbiasqdbm - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxagcdsp1_unpack(uint8_t* adcpowmindbm, uint8_t* adcpowbiasqdbm)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCDSP1_ADDR);

    *adcpowmindbm = (localVal & ((uint32_t)0x0000FF00)) >> 8;
    *adcpowbiasqdbm = (localVal & ((uint32_t)0x000000FF)) >> 0;
}

/**
 * @brief Returns the current value of the ADCPOWMINDBM field in the RWNXAGCDSP1 register.
 *
 * The RWNXAGCDSP1 register will be read and the ADCPOWMINDBM field's value will be returned.
 *
 * @return The current value of the ADCPOWMINDBM field in the RWNXAGCDSP1 register.
 */
__INLINE uint8_t riu_adcpowmindbm_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCDSP1_ADDR);
    return ((localVal & ((uint32_t)0x0000FF00)) >> 8);
}

/**
 * @brief Sets the ADCPOWMINDBM field of the RWNXAGCDSP1 register.
 *
 * The RWNXAGCDSP1 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] adcpowmindbm - The value to set the field to.
 */
__INLINE void riu_adcpowmindbm_setf(uint8_t adcpowmindbm)
{
    REG_PL_WR(RIU_RWNXAGCDSP1_ADDR, (REG_PL_RD(RIU_RWNXAGCDSP1_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)adcpowmindbm << 8));
}

/**
 * @brief Returns the current value of the ADCPOWBIASQDBM field in the RWNXAGCDSP1 register.
 *
 * The RWNXAGCDSP1 register will be read and the ADCPOWBIASQDBM field's value will be returned.
 *
 * @return The current value of the ADCPOWBIASQDBM field in the RWNXAGCDSP1 register.
 */
__INLINE uint8_t riu_adcpowbiasqdbm_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCDSP1_ADDR);
    return ((localVal & ((uint32_t)0x000000FF)) >> 0);
}

/**
 * @brief Sets the ADCPOWBIASQDBM field of the RWNXAGCDSP1 register.
 *
 * The RWNXAGCDSP1 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] adcpowbiasqdbm - The value to set the field to.
 */
__INLINE void riu_adcpowbiasqdbm_setf(uint8_t adcpowbiasqdbm)
{
    REG_PL_WR(RIU_RWNXAGCDSP1_ADDR, (REG_PL_RD(RIU_RWNXAGCDSP1_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)adcpowbiasqdbm << 0));
}

/// @}

/**
 * @name RWNXAGCDSP2 register definitions
 * <table>
 * <caption id="RWNXAGCDSP2_BF">RWNXAGCDSP2 bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>23:16 <td> INBDPOW40SBIASQDB <td>R <td>R/W <td>0x0
 * <tr><td>15:08 <td> INBDPOW20SBIASQDB <td>R <td>R/W <td>0x0
 * <tr><td>07:00 <td> INBDPOW20PBIASQDB <td>R <td>R/W <td>0x0
 * </table>
 *
 * @{
 */

/// Address of the RWNXAGCDSP2 register
#define RIU_RWNXAGCDSP2_ADDR   0x4033B39C
/// Offset of the RWNXAGCDSP2 register from the base address
#define RIU_RWNXAGCDSP2_OFFSET 0x0000039C
/// Index of the RWNXAGCDSP2 register
#define RIU_RWNXAGCDSP2_INDEX  0x000000E7
/// Reset value of the RWNXAGCDSP2 register
#define RIU_RWNXAGCDSP2_RESET  0x00000000

/**
 * @brief Returns the current value of the RWNXAGCDSP2 register.
 * The RWNXAGCDSP2 register will be read and its value returned.
 * @return The current value of the RWNXAGCDSP2 register.
 */
__INLINE uint32_t riu_rwnxagcdsp2_get(void)
{
    return REG_PL_RD(RIU_RWNXAGCDSP2_ADDR);
}

/**
 * @brief Sets the RWNXAGCDSP2 register to a value.
 * The RWNXAGCDSP2 register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxagcdsp2_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXAGCDSP2_ADDR, value);
}

// field definitions
/// INBDPOW40SBIASQDB field mask
#define RIU_INBDPOW40SBIASQDB_MASK   ((uint32_t)0x00FF0000)
/// INBDPOW40SBIASQDB field LSB position
#define RIU_INBDPOW40SBIASQDB_LSB    16
/// INBDPOW40SBIASQDB field width
#define RIU_INBDPOW40SBIASQDB_WIDTH  ((uint32_t)0x00000008)
/// INBDPOW20SBIASQDB field mask
#define RIU_INBDPOW20SBIASQDB_MASK   ((uint32_t)0x0000FF00)
/// INBDPOW20SBIASQDB field LSB position
#define RIU_INBDPOW20SBIASQDB_LSB    8
/// INBDPOW20SBIASQDB field width
#define RIU_INBDPOW20SBIASQDB_WIDTH  ((uint32_t)0x00000008)
/// INBDPOW20PBIASQDB field mask
#define RIU_INBDPOW20PBIASQDB_MASK   ((uint32_t)0x000000FF)
/// INBDPOW20PBIASQDB field LSB position
#define RIU_INBDPOW20PBIASQDB_LSB    0
/// INBDPOW20PBIASQDB field width
#define RIU_INBDPOW20PBIASQDB_WIDTH  ((uint32_t)0x00000008)

/// INBDPOW40SBIASQDB field reset value
#define RIU_INBDPOW40SBIASQDB_RST    0x0
/// INBDPOW20SBIASQDB field reset value
#define RIU_INBDPOW20SBIASQDB_RST    0x0
/// INBDPOW20PBIASQDB field reset value
#define RIU_INBDPOW20PBIASQDB_RST    0x0

/**
 * @brief Constructs a value for the RWNXAGCDSP2 register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] inbdpow40sbiasqdb - The value to use for the INBDPOW40SBIASQDB field.
 * @param[in] inbdpow20sbiasqdb - The value to use for the INBDPOW20SBIASQDB field.
 * @param[in] inbdpow20pbiasqdb - The value to use for the INBDPOW20PBIASQDB field.
 */
__INLINE void riu_rwnxagcdsp2_pack(uint8_t inbdpow40sbiasqdb, uint8_t inbdpow20sbiasqdb, uint8_t inbdpow20pbiasqdb)
{
    REG_PL_WR(RIU_RWNXAGCDSP2_ADDR,  ((uint32_t)inbdpow40sbiasqdb << 16) | ((uint32_t)inbdpow20sbiasqdb << 8) | ((uint32_t)inbdpow20pbiasqdb << 0));
}

/**
 * @brief Unpacks RWNXAGCDSP2's fields from current value of the RWNXAGCDSP2 register.
 *
 * Reads the RWNXAGCDSP2 register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] inbdpow40sbiasqdb - Will be populated with the current value of this field from the register.
 * @param[out] inbdpow20sbiasqdb - Will be populated with the current value of this field from the register.
 * @param[out] inbdpow20pbiasqdb - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxagcdsp2_unpack(uint8_t* inbdpow40sbiasqdb, uint8_t* inbdpow20sbiasqdb, uint8_t* inbdpow20pbiasqdb)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCDSP2_ADDR);

    *inbdpow40sbiasqdb = (localVal & ((uint32_t)0x00FF0000)) >> 16;
    *inbdpow20sbiasqdb = (localVal & ((uint32_t)0x0000FF00)) >> 8;
    *inbdpow20pbiasqdb = (localVal & ((uint32_t)0x000000FF)) >> 0;
}

/**
 * @brief Returns the current value of the INBDPOW40SBIASQDB field in the RWNXAGCDSP2 register.
 *
 * The RWNXAGCDSP2 register will be read and the INBDPOW40SBIASQDB field's value will be returned.
 *
 * @return The current value of the INBDPOW40SBIASQDB field in the RWNXAGCDSP2 register.
 */
__INLINE uint8_t riu_inbdpow40sbiasqdb_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCDSP2_ADDR);
    return ((localVal & ((uint32_t)0x00FF0000)) >> 16);
}

/**
 * @brief Sets the INBDPOW40SBIASQDB field of the RWNXAGCDSP2 register.
 *
 * The RWNXAGCDSP2 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] inbdpow40sbiasqdb - The value to set the field to.
 */
__INLINE void riu_inbdpow40sbiasqdb_setf(uint8_t inbdpow40sbiasqdb)
{
    REG_PL_WR(RIU_RWNXAGCDSP2_ADDR, (REG_PL_RD(RIU_RWNXAGCDSP2_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)inbdpow40sbiasqdb << 16));
}

/**
 * @brief Returns the current value of the INBDPOW20SBIASQDB field in the RWNXAGCDSP2 register.
 *
 * The RWNXAGCDSP2 register will be read and the INBDPOW20SBIASQDB field's value will be returned.
 *
 * @return The current value of the INBDPOW20SBIASQDB field in the RWNXAGCDSP2 register.
 */
__INLINE uint8_t riu_inbdpow20sbiasqdb_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCDSP2_ADDR);
    return ((localVal & ((uint32_t)0x0000FF00)) >> 8);
}

/**
 * @brief Sets the INBDPOW20SBIASQDB field of the RWNXAGCDSP2 register.
 *
 * The RWNXAGCDSP2 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] inbdpow20sbiasqdb - The value to set the field to.
 */
__INLINE void riu_inbdpow20sbiasqdb_setf(uint8_t inbdpow20sbiasqdb)
{
    REG_PL_WR(RIU_RWNXAGCDSP2_ADDR, (REG_PL_RD(RIU_RWNXAGCDSP2_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)inbdpow20sbiasqdb << 8));
}

/**
 * @brief Returns the current value of the INBDPOW20PBIASQDB field in the RWNXAGCDSP2 register.
 *
 * The RWNXAGCDSP2 register will be read and the INBDPOW20PBIASQDB field's value will be returned.
 *
 * @return The current value of the INBDPOW20PBIASQDB field in the RWNXAGCDSP2 register.
 */
__INLINE uint8_t riu_inbdpow20pbiasqdb_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCDSP2_ADDR);
    return ((localVal & ((uint32_t)0x000000FF)) >> 0);
}

/**
 * @brief Sets the INBDPOW20PBIASQDB field of the RWNXAGCDSP2 register.
 *
 * The RWNXAGCDSP2 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] inbdpow20pbiasqdb - The value to set the field to.
 */
__INLINE void riu_inbdpow20pbiasqdb_setf(uint8_t inbdpow20pbiasqdb)
{
    REG_PL_WR(RIU_RWNXAGCDSP2_ADDR, (REG_PL_RD(RIU_RWNXAGCDSP2_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)inbdpow20pbiasqdb << 0));
}

/// @}

/**
 * @name RWNXAGCDSP3 register definitions
 * <table>
 * <caption id="RWNXAGCDSP3_BF">RWNXAGCDSP3 bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>27:20 <td>     INBDPOWMINDBV <td>R <td>R/W <td>0xBF
 * <tr><td>17:16 <td>           INBDRND <td>R <td>R/W <td>0x3
 * <tr><td>07:00 <td>     INBDPOWMINDBM <td>R <td>R/W <td>0x9C
 * </table>
 *
 * @{
 */

/// Address of the RWNXAGCDSP3 register
#define RIU_RWNXAGCDSP3_ADDR   0x4033B3A0
/// Offset of the RWNXAGCDSP3 register from the base address
#define RIU_RWNXAGCDSP3_OFFSET 0x000003A0
/// Index of the RWNXAGCDSP3 register
#define RIU_RWNXAGCDSP3_INDEX  0x000000E8
/// Reset value of the RWNXAGCDSP3 register
#define RIU_RWNXAGCDSP3_RESET  0x0BF3009C

/**
 * @brief Returns the current value of the RWNXAGCDSP3 register.
 * The RWNXAGCDSP3 register will be read and its value returned.
 * @return The current value of the RWNXAGCDSP3 register.
 */
__INLINE uint32_t riu_rwnxagcdsp3_get(void)
{
    return REG_PL_RD(RIU_RWNXAGCDSP3_ADDR);
}

/**
 * @brief Sets the RWNXAGCDSP3 register to a value.
 * The RWNXAGCDSP3 register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxagcdsp3_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXAGCDSP3_ADDR, value);
}

// field definitions
/// INBDPOWMINDBV field mask
#define RIU_INBDPOWMINDBV_MASK   ((uint32_t)0x0FF00000)
/// INBDPOWMINDBV field LSB position
#define RIU_INBDPOWMINDBV_LSB    20
/// INBDPOWMINDBV field width
#define RIU_INBDPOWMINDBV_WIDTH  ((uint32_t)0x00000008)
/// INBDRND field mask
#define RIU_INBDRND_MASK         ((uint32_t)0x00030000)
/// INBDRND field LSB position
#define RIU_INBDRND_LSB          16
/// INBDRND field width
#define RIU_INBDRND_WIDTH        ((uint32_t)0x00000002)
/// INBDPOWMINDBM field mask
#define RIU_INBDPOWMINDBM_MASK   ((uint32_t)0x000000FF)
/// INBDPOWMINDBM field LSB position
#define RIU_INBDPOWMINDBM_LSB    0
/// INBDPOWMINDBM field width
#define RIU_INBDPOWMINDBM_WIDTH  ((uint32_t)0x00000008)

/// INBDPOWMINDBV field reset value
#define RIU_INBDPOWMINDBV_RST    0xBF
/// INBDRND field reset value
#define RIU_INBDRND_RST          0x3
/// INBDPOWMINDBM field reset value
#define RIU_INBDPOWMINDBM_RST    0x9C

/**
 * @brief Constructs a value for the RWNXAGCDSP3 register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] inbdpowmindbv - The value to use for the INBDPOWMINDBV field.
 * @param[in] inbdrnd - The value to use for the INBDRND field.
 * @param[in] inbdpowmindbm - The value to use for the INBDPOWMINDBM field.
 */
__INLINE void riu_rwnxagcdsp3_pack(uint8_t inbdpowmindbv, uint8_t inbdrnd, uint8_t inbdpowmindbm)
{
    REG_PL_WR(RIU_RWNXAGCDSP3_ADDR,  ((uint32_t)inbdpowmindbv << 20) | ((uint32_t)inbdrnd << 16) | ((uint32_t)inbdpowmindbm << 0));
}

/**
 * @brief Unpacks RWNXAGCDSP3's fields from current value of the RWNXAGCDSP3 register.
 *
 * Reads the RWNXAGCDSP3 register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] inbdpowmindbv - Will be populated with the current value of this field from the register.
 * @param[out] inbdrnd - Will be populated with the current value of this field from the register.
 * @param[out] inbdpowmindbm - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxagcdsp3_unpack(uint8_t* inbdpowmindbv, uint8_t* inbdrnd, uint8_t* inbdpowmindbm)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCDSP3_ADDR);

    *inbdpowmindbv = (localVal & ((uint32_t)0x0FF00000)) >> 20;
    *inbdrnd = (localVal & ((uint32_t)0x00030000)) >> 16;
    *inbdpowmindbm = (localVal & ((uint32_t)0x000000FF)) >> 0;
}

/**
 * @brief Returns the current value of the INBDPOWMINDBV field in the RWNXAGCDSP3 register.
 *
 * The RWNXAGCDSP3 register will be read and the INBDPOWMINDBV field's value will be returned.
 *
 * @return The current value of the INBDPOWMINDBV field in the RWNXAGCDSP3 register.
 */
__INLINE uint8_t riu_inbdpowmindbv_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCDSP3_ADDR);
    return ((localVal & ((uint32_t)0x0FF00000)) >> 20);
}

/**
 * @brief Sets the INBDPOWMINDBV field of the RWNXAGCDSP3 register.
 *
 * The RWNXAGCDSP3 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] inbdpowmindbv - The value to set the field to.
 */
__INLINE void riu_inbdpowmindbv_setf(uint8_t inbdpowmindbv)
{
    REG_PL_WR(RIU_RWNXAGCDSP3_ADDR, (REG_PL_RD(RIU_RWNXAGCDSP3_ADDR) & ~((uint32_t)0x0FF00000)) | ((uint32_t)inbdpowmindbv << 20));
}

/**
 * @brief Returns the current value of the INBDRND field in the RWNXAGCDSP3 register.
 *
 * The RWNXAGCDSP3 register will be read and the INBDRND field's value will be returned.
 *
 * @return The current value of the INBDRND field in the RWNXAGCDSP3 register.
 */
__INLINE uint8_t riu_inbdrnd_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCDSP3_ADDR);
    return ((localVal & ((uint32_t)0x00030000)) >> 16);
}

/**
 * @brief Sets the INBDRND field of the RWNXAGCDSP3 register.
 *
 * The RWNXAGCDSP3 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] inbdrnd - The value to set the field to.
 */
__INLINE void riu_inbdrnd_setf(uint8_t inbdrnd)
{
    REG_PL_WR(RIU_RWNXAGCDSP3_ADDR, (REG_PL_RD(RIU_RWNXAGCDSP3_ADDR) & ~((uint32_t)0x00030000)) | ((uint32_t)inbdrnd << 16));
}

/**
 * @brief Returns the current value of the INBDPOWMINDBM field in the RWNXAGCDSP3 register.
 *
 * The RWNXAGCDSP3 register will be read and the INBDPOWMINDBM field's value will be returned.
 *
 * @return The current value of the INBDPOWMINDBM field in the RWNXAGCDSP3 register.
 */
__INLINE uint8_t riu_inbdpowmindbm_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCDSP3_ADDR);
    return ((localVal & ((uint32_t)0x000000FF)) >> 0);
}

/**
 * @brief Sets the INBDPOWMINDBM field of the RWNXAGCDSP3 register.
 *
 * The RWNXAGCDSP3 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] inbdpowmindbm - The value to set the field to.
 */
__INLINE void riu_inbdpowmindbm_setf(uint8_t inbdpowmindbm)
{
    REG_PL_WR(RIU_RWNXAGCDSP3_ADDR, (REG_PL_RD(RIU_RWNXAGCDSP3_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)inbdpowmindbm << 0));
}

/// @}

/**
 * @name RWNXAGCDSP4 register definitions
 * <table>
 * <caption id="RWNXAGCDSP4_BF">RWNXAGCDSP4 bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>15:08 <td>          FE40GAIN <td>R <td>R/W <td>0x2
 * <tr><td>07:00 <td>          FE20GAIN <td>R <td>R/W <td>0x2
 * </table>
 *
 * @{
 */

/// Address of the RWNXAGCDSP4 register
#define RIU_RWNXAGCDSP4_ADDR   0x4033B3A4
/// Offset of the RWNXAGCDSP4 register from the base address
#define RIU_RWNXAGCDSP4_OFFSET 0x000003A4
/// Index of the RWNXAGCDSP4 register
#define RIU_RWNXAGCDSP4_INDEX  0x000000E9
/// Reset value of the RWNXAGCDSP4 register
#define RIU_RWNXAGCDSP4_RESET  0x00000202

/**
 * @brief Returns the current value of the RWNXAGCDSP4 register.
 * The RWNXAGCDSP4 register will be read and its value returned.
 * @return The current value of the RWNXAGCDSP4 register.
 */
__INLINE uint32_t riu_rwnxagcdsp4_get(void)
{
    return REG_PL_RD(RIU_RWNXAGCDSP4_ADDR);
}

/**
 * @brief Sets the RWNXAGCDSP4 register to a value.
 * The RWNXAGCDSP4 register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxagcdsp4_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXAGCDSP4_ADDR, value);
}

// field definitions
/// FE40GAIN field mask
#define RIU_FE40GAIN_MASK   ((uint32_t)0x0000FF00)
/// FE40GAIN field LSB position
#define RIU_FE40GAIN_LSB    8
/// FE40GAIN field width
#define RIU_FE40GAIN_WIDTH  ((uint32_t)0x00000008)
/// FE20GAIN field mask
#define RIU_FE20GAIN_MASK   ((uint32_t)0x000000FF)
/// FE20GAIN field LSB position
#define RIU_FE20GAIN_LSB    0
/// FE20GAIN field width
#define RIU_FE20GAIN_WIDTH  ((uint32_t)0x00000008)

/// FE40GAIN field reset value
#define RIU_FE40GAIN_RST    0x2
/// FE20GAIN field reset value
#define RIU_FE20GAIN_RST    0x2

/**
 * @brief Constructs a value for the RWNXAGCDSP4 register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] fe40gain - The value to use for the FE40GAIN field.
 * @param[in] fe20gain - The value to use for the FE20GAIN field.
 */
__INLINE void riu_rwnxagcdsp4_pack(uint8_t fe40gain, uint8_t fe20gain)
{
    REG_PL_WR(RIU_RWNXAGCDSP4_ADDR,  ((uint32_t)fe40gain << 8) | ((uint32_t)fe20gain << 0));
}

/**
 * @brief Unpacks RWNXAGCDSP4's fields from current value of the RWNXAGCDSP4 register.
 *
 * Reads the RWNXAGCDSP4 register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] fe40gain - Will be populated with the current value of this field from the register.
 * @param[out] fe20gain - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxagcdsp4_unpack(uint8_t* fe40gain, uint8_t* fe20gain)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCDSP4_ADDR);

    *fe40gain = (localVal & ((uint32_t)0x0000FF00)) >> 8;
    *fe20gain = (localVal & ((uint32_t)0x000000FF)) >> 0;
}

/**
 * @brief Returns the current value of the FE40GAIN field in the RWNXAGCDSP4 register.
 *
 * The RWNXAGCDSP4 register will be read and the FE40GAIN field's value will be returned.
 *
 * @return The current value of the FE40GAIN field in the RWNXAGCDSP4 register.
 */
__INLINE uint8_t riu_fe40gain_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCDSP4_ADDR);
    return ((localVal & ((uint32_t)0x0000FF00)) >> 8);
}

/**
 * @brief Sets the FE40GAIN field of the RWNXAGCDSP4 register.
 *
 * The RWNXAGCDSP4 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] fe40gain - The value to set the field to.
 */
__INLINE void riu_fe40gain_setf(uint8_t fe40gain)
{
    REG_PL_WR(RIU_RWNXAGCDSP4_ADDR, (REG_PL_RD(RIU_RWNXAGCDSP4_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)fe40gain << 8));
}

/**
 * @brief Returns the current value of the FE20GAIN field in the RWNXAGCDSP4 register.
 *
 * The RWNXAGCDSP4 register will be read and the FE20GAIN field's value will be returned.
 *
 * @return The current value of the FE20GAIN field in the RWNXAGCDSP4 register.
 */
__INLINE uint8_t riu_fe20gain_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCDSP4_ADDR);
    return ((localVal & ((uint32_t)0x000000FF)) >> 0);
}

/**
 * @brief Sets the FE20GAIN field of the RWNXAGCDSP4 register.
 *
 * The RWNXAGCDSP4 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] fe20gain - The value to set the field to.
 */
__INLINE void riu_fe20gain_setf(uint8_t fe20gain)
{
    REG_PL_WR(RIU_RWNXAGCDSP4_ADDR, (REG_PL_RD(RIU_RWNXAGCDSP4_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)fe20gain << 0));
}

/// @}

/**
 * @name RWNXAGCCCA0 register definitions
 * <table>
 * <caption id="RWNXAGCCCA0_BF">RWNXAGCCCA0 bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>22:20 <td>   DELCCARAMPDNTAP <td>R <td>R/W <td>0x5
 * <tr><td>18:16 <td>   DELCCARAMPUPTAP <td>R <td>R/W <td>0x5
 * <tr><td>13:08 <td>      CCADETRAMPDN <td>R <td>R/W <td>0x9
 * <tr><td>05:00 <td>      CCADETRAMPUP <td>R <td>R/W <td>0x9
 * </table>
 *
 * @{
 */

/// Address of the RWNXAGCCCA0 register
#define RIU_RWNXAGCCCA0_ADDR   0x4033B3A8
/// Offset of the RWNXAGCCCA0 register from the base address
#define RIU_RWNXAGCCCA0_OFFSET 0x000003A8
/// Index of the RWNXAGCCCA0 register
#define RIU_RWNXAGCCCA0_INDEX  0x000000EA
/// Reset value of the RWNXAGCCCA0 register
#define RIU_RWNXAGCCCA0_RESET  0x00550909

/**
 * @brief Returns the current value of the RWNXAGCCCA0 register.
 * The RWNXAGCCCA0 register will be read and its value returned.
 * @return The current value of the RWNXAGCCCA0 register.
 */
__INLINE uint32_t riu_rwnxagccca0_get(void)
{
    return REG_PL_RD(RIU_RWNXAGCCCA0_ADDR);
}

/**
 * @brief Sets the RWNXAGCCCA0 register to a value.
 * The RWNXAGCCCA0 register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxagccca0_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXAGCCCA0_ADDR, value);
}

// field definitions
/// DELCCARAMPDNTAP field mask
#define RIU_DELCCARAMPDNTAP_MASK   ((uint32_t)0x00700000)
/// DELCCARAMPDNTAP field LSB position
#define RIU_DELCCARAMPDNTAP_LSB    20
/// DELCCARAMPDNTAP field width
#define RIU_DELCCARAMPDNTAP_WIDTH  ((uint32_t)0x00000003)
/// DELCCARAMPUPTAP field mask
#define RIU_DELCCARAMPUPTAP_MASK   ((uint32_t)0x00070000)
/// DELCCARAMPUPTAP field LSB position
#define RIU_DELCCARAMPUPTAP_LSB    16
/// DELCCARAMPUPTAP field width
#define RIU_DELCCARAMPUPTAP_WIDTH  ((uint32_t)0x00000003)
/// CCADETRAMPDN field mask
#define RIU_CCADETRAMPDN_MASK      ((uint32_t)0x00003F00)
/// CCADETRAMPDN field LSB position
#define RIU_CCADETRAMPDN_LSB       8
/// CCADETRAMPDN field width
#define RIU_CCADETRAMPDN_WIDTH     ((uint32_t)0x00000006)
/// CCADETRAMPUP field mask
#define RIU_CCADETRAMPUP_MASK      ((uint32_t)0x0000003F)
/// CCADETRAMPUP field LSB position
#define RIU_CCADETRAMPUP_LSB       0
/// CCADETRAMPUP field width
#define RIU_CCADETRAMPUP_WIDTH     ((uint32_t)0x00000006)

/// DELCCARAMPDNTAP field reset value
#define RIU_DELCCARAMPDNTAP_RST    0x5
/// DELCCARAMPUPTAP field reset value
#define RIU_DELCCARAMPUPTAP_RST    0x5
/// CCADETRAMPDN field reset value
#define RIU_CCADETRAMPDN_RST       0x9
/// CCADETRAMPUP field reset value
#define RIU_CCADETRAMPUP_RST       0x9

/**
 * @brief Constructs a value for the RWNXAGCCCA0 register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] delccarampdntap - The value to use for the DELCCARAMPDNTAP field.
 * @param[in] delccarampuptap - The value to use for the DELCCARAMPUPTAP field.
 * @param[in] ccadetrampdn - The value to use for the CCADETRAMPDN field.
 * @param[in] ccadetrampup - The value to use for the CCADETRAMPUP field.
 */
__INLINE void riu_rwnxagccca0_pack(uint8_t delccarampdntap, uint8_t delccarampuptap, uint8_t ccadetrampdn, uint8_t ccadetrampup)
{
    REG_PL_WR(RIU_RWNXAGCCCA0_ADDR,  ((uint32_t)delccarampdntap << 20) | ((uint32_t)delccarampuptap << 16) | ((uint32_t)ccadetrampdn << 8) | ((uint32_t)ccadetrampup << 0));
}

/**
 * @brief Unpacks RWNXAGCCCA0's fields from current value of the RWNXAGCCCA0 register.
 *
 * Reads the RWNXAGCCCA0 register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] delccarampdntap - Will be populated with the current value of this field from the register.
 * @param[out] delccarampuptap - Will be populated with the current value of this field from the register.
 * @param[out] ccadetrampdn - Will be populated with the current value of this field from the register.
 * @param[out] ccadetrampup - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxagccca0_unpack(uint8_t* delccarampdntap, uint8_t* delccarampuptap, uint8_t* ccadetrampdn, uint8_t* ccadetrampup)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCCCA0_ADDR);

    *delccarampdntap = (localVal & ((uint32_t)0x00700000)) >> 20;
    *delccarampuptap = (localVal & ((uint32_t)0x00070000)) >> 16;
    *ccadetrampdn = (localVal & ((uint32_t)0x00003F00)) >> 8;
    *ccadetrampup = (localVal & ((uint32_t)0x0000003F)) >> 0;
}

/**
 * @brief Returns the current value of the DELCCARAMPDNTAP field in the RWNXAGCCCA0 register.
 *
 * The RWNXAGCCCA0 register will be read and the DELCCARAMPDNTAP field's value will be returned.
 *
 * @return The current value of the DELCCARAMPDNTAP field in the RWNXAGCCCA0 register.
 */
__INLINE uint8_t riu_delccarampdntap_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCCCA0_ADDR);
    return ((localVal & ((uint32_t)0x00700000)) >> 20);
}

/**
 * @brief Sets the DELCCARAMPDNTAP field of the RWNXAGCCCA0 register.
 *
 * The RWNXAGCCCA0 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] delccarampdntap - The value to set the field to.
 */
__INLINE void riu_delccarampdntap_setf(uint8_t delccarampdntap)
{
    REG_PL_WR(RIU_RWNXAGCCCA0_ADDR, (REG_PL_RD(RIU_RWNXAGCCCA0_ADDR) & ~((uint32_t)0x00700000)) | ((uint32_t)delccarampdntap << 20));
}

/**
 * @brief Returns the current value of the DELCCARAMPUPTAP field in the RWNXAGCCCA0 register.
 *
 * The RWNXAGCCCA0 register will be read and the DELCCARAMPUPTAP field's value will be returned.
 *
 * @return The current value of the DELCCARAMPUPTAP field in the RWNXAGCCCA0 register.
 */
__INLINE uint8_t riu_delccarampuptap_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCCCA0_ADDR);
    return ((localVal & ((uint32_t)0x00070000)) >> 16);
}

/**
 * @brief Sets the DELCCARAMPUPTAP field of the RWNXAGCCCA0 register.
 *
 * The RWNXAGCCCA0 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] delccarampuptap - The value to set the field to.
 */
__INLINE void riu_delccarampuptap_setf(uint8_t delccarampuptap)
{
    REG_PL_WR(RIU_RWNXAGCCCA0_ADDR, (REG_PL_RD(RIU_RWNXAGCCCA0_ADDR) & ~((uint32_t)0x00070000)) | ((uint32_t)delccarampuptap << 16));
}

/**
 * @brief Returns the current value of the CCADETRAMPDN field in the RWNXAGCCCA0 register.
 *
 * The RWNXAGCCCA0 register will be read and the CCADETRAMPDN field's value will be returned.
 *
 * @return The current value of the CCADETRAMPDN field in the RWNXAGCCCA0 register.
 */
__INLINE uint8_t riu_ccadetrampdn_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCCCA0_ADDR);
    return ((localVal & ((uint32_t)0x00003F00)) >> 8);
}

/**
 * @brief Sets the CCADETRAMPDN field of the RWNXAGCCCA0 register.
 *
 * The RWNXAGCCCA0 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] ccadetrampdn - The value to set the field to.
 */
__INLINE void riu_ccadetrampdn_setf(uint8_t ccadetrampdn)
{
    REG_PL_WR(RIU_RWNXAGCCCA0_ADDR, (REG_PL_RD(RIU_RWNXAGCCCA0_ADDR) & ~((uint32_t)0x00003F00)) | ((uint32_t)ccadetrampdn << 8));
}

/**
 * @brief Returns the current value of the CCADETRAMPUP field in the RWNXAGCCCA0 register.
 *
 * The RWNXAGCCCA0 register will be read and the CCADETRAMPUP field's value will be returned.
 *
 * @return The current value of the CCADETRAMPUP field in the RWNXAGCCCA0 register.
 */
__INLINE uint8_t riu_ccadetrampup_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCCCA0_ADDR);
    return ((localVal & ((uint32_t)0x0000003F)) >> 0);
}

/**
 * @brief Sets the CCADETRAMPUP field of the RWNXAGCCCA0 register.
 *
 * The RWNXAGCCCA0 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] ccadetrampup - The value to set the field to.
 */
__INLINE void riu_ccadetrampup_setf(uint8_t ccadetrampup)
{
    REG_PL_WR(RIU_RWNXAGCCCA0_ADDR, (REG_PL_RD(RIU_RWNXAGCCCA0_ADDR) & ~((uint32_t)0x0000003F)) | ((uint32_t)ccadetrampup << 0));
}

/// @}

/**
 * @name RWNXAGCCCA1 register definitions
 * <table>
 * <caption id="RWNXAGCCCA1_BF">RWNXAGCCCA1 bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>28:20 <td>INBDCCA20PPOWMINDBM <td>R <td>R/W <td>0x1B5
 * <tr><td>19:12 <td>  CCA20PFALLTHRDBM <td>R <td>R/W <td>0xBF
 * <tr><td>09 <td>          DISCCAEN <td>R <td>R/W <td>1
 * <tr><td>08 <td>          SATCCAEN <td>R <td>R/W <td>1
 * <tr><td>07:00 <td>  CCA20PRISETHRDBM <td>R <td>R/W <td>0xC2
 * </table>
 *
 * @{
 */

/// Address of the RWNXAGCCCA1 register
#define RIU_RWNXAGCCCA1_ADDR   0x4033B3AC
/// Offset of the RWNXAGCCCA1 register from the base address
#define RIU_RWNXAGCCCA1_OFFSET 0x000003AC
/// Index of the RWNXAGCCCA1 register
#define RIU_RWNXAGCCCA1_INDEX  0x000000EB
/// Reset value of the RWNXAGCCCA1 register
#define RIU_RWNXAGCCCA1_RESET  0x1B5BF3C2

/**
 * @brief Returns the current value of the RWNXAGCCCA1 register.
 * The RWNXAGCCCA1 register will be read and its value returned.
 * @return The current value of the RWNXAGCCCA1 register.
 */
__INLINE uint32_t riu_rwnxagccca1_get(void)
{
    return REG_PL_RD(RIU_RWNXAGCCCA1_ADDR);
}

/**
 * @brief Sets the RWNXAGCCCA1 register to a value.
 * The RWNXAGCCCA1 register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxagccca1_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXAGCCCA1_ADDR, value);
}

// field definitions
/// INBDCCA20PPOWMINDBM field mask
#define RIU_INBDCCA20PPOWMINDBM_MASK   ((uint32_t)0x1FF00000)
/// INBDCCA20PPOWMINDBM field LSB position
#define RIU_INBDCCA20PPOWMINDBM_LSB    20
/// INBDCCA20PPOWMINDBM field width
#define RIU_INBDCCA20PPOWMINDBM_WIDTH  ((uint32_t)0x00000009)
/// CCA20PFALLTHRDBM field mask
#define RIU_CCA20PFALLTHRDBM_MASK      ((uint32_t)0x000FF000)
/// CCA20PFALLTHRDBM field LSB position
#define RIU_CCA20PFALLTHRDBM_LSB       12
/// CCA20PFALLTHRDBM field width
#define RIU_CCA20PFALLTHRDBM_WIDTH     ((uint32_t)0x00000008)
/// DISCCAEN field bit
#define RIU_DISCCAEN_BIT               ((uint32_t)0x00000200)
/// DISCCAEN field position
#define RIU_DISCCAEN_POS               9
/// SATCCAEN field bit
#define RIU_SATCCAEN_BIT               ((uint32_t)0x00000100)
/// SATCCAEN field position
#define RIU_SATCCAEN_POS               8
/// CCA20PRISETHRDBM field mask
#define RIU_CCA20PRISETHRDBM_MASK      ((uint32_t)0x000000FF)
/// CCA20PRISETHRDBM field LSB position
#define RIU_CCA20PRISETHRDBM_LSB       0
/// CCA20PRISETHRDBM field width
#define RIU_CCA20PRISETHRDBM_WIDTH     ((uint32_t)0x00000008)

/// INBDCCA20PPOWMINDBM field reset value
#define RIU_INBDCCA20PPOWMINDBM_RST    0x1B5
/// CCA20PFALLTHRDBM field reset value
#define RIU_CCA20PFALLTHRDBM_RST       0xBF
/// DISCCAEN field reset value
#define RIU_DISCCAEN_RST               0x1
/// SATCCAEN field reset value
#define RIU_SATCCAEN_RST               0x1
/// CCA20PRISETHRDBM field reset value
#define RIU_CCA20PRISETHRDBM_RST       0xC2

/**
 * @brief Constructs a value for the RWNXAGCCCA1 register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] inbdcca20ppowmindbm - The value to use for the INBDCCA20PPOWMINDBM field.
 * @param[in] cca20pfallthrdbm - The value to use for the CCA20PFALLTHRDBM field.
 * @param[in] disccaen - The value to use for the DISCCAEN field.
 * @param[in] satccaen - The value to use for the SATCCAEN field.
 * @param[in] cca20prisethrdbm - The value to use for the CCA20PRISETHRDBM field.
 */
__INLINE void riu_rwnxagccca1_pack(uint16_t inbdcca20ppowmindbm, uint8_t cca20pfallthrdbm, uint8_t disccaen, uint8_t satccaen, uint8_t cca20prisethrdbm)
{
    REG_PL_WR(RIU_RWNXAGCCCA1_ADDR,  ((uint32_t)inbdcca20ppowmindbm << 20) | ((uint32_t)cca20pfallthrdbm << 12) | ((uint32_t)disccaen << 9) | ((uint32_t)satccaen << 8) | ((uint32_t)cca20prisethrdbm << 0));
}

/**
 * @brief Unpacks RWNXAGCCCA1's fields from current value of the RWNXAGCCCA1 register.
 *
 * Reads the RWNXAGCCCA1 register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] inbdcca20ppowmindbm - Will be populated with the current value of this field from the register.
 * @param[out] cca20pfallthrdbm - Will be populated with the current value of this field from the register.
 * @param[out] disccaen - Will be populated with the current value of this field from the register.
 * @param[out] satccaen - Will be populated with the current value of this field from the register.
 * @param[out] cca20prisethrdbm - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxagccca1_unpack(uint16_t* inbdcca20ppowmindbm, uint8_t* cca20pfallthrdbm, uint8_t* disccaen, uint8_t* satccaen, uint8_t* cca20prisethrdbm)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCCCA1_ADDR);

    *inbdcca20ppowmindbm = (localVal & ((uint32_t)0x1FF00000)) >> 20;
    *cca20pfallthrdbm = (localVal & ((uint32_t)0x000FF000)) >> 12;
    *disccaen = (localVal & ((uint32_t)0x00000200)) >> 9;
    *satccaen = (localVal & ((uint32_t)0x00000100)) >> 8;
    *cca20prisethrdbm = (localVal & ((uint32_t)0x000000FF)) >> 0;
}

/**
 * @brief Returns the current value of the INBDCCA20PPOWMINDBM field in the RWNXAGCCCA1 register.
 *
 * The RWNXAGCCCA1 register will be read and the INBDCCA20PPOWMINDBM field's value will be returned.
 *
 * @return The current value of the INBDCCA20PPOWMINDBM field in the RWNXAGCCCA1 register.
 */
__INLINE uint16_t riu_inbdcca20ppowmindbm_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCCCA1_ADDR);
    return ((localVal & ((uint32_t)0x1FF00000)) >> 20);
}

/**
 * @brief Sets the INBDCCA20PPOWMINDBM field of the RWNXAGCCCA1 register.
 *
 * The RWNXAGCCCA1 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] inbdcca20ppowmindbm - The value to set the field to.
 */
__INLINE void riu_inbdcca20ppowmindbm_setf(uint16_t inbdcca20ppowmindbm)
{
    REG_PL_WR(RIU_RWNXAGCCCA1_ADDR, (REG_PL_RD(RIU_RWNXAGCCCA1_ADDR) & ~((uint32_t)0x1FF00000)) | ((uint32_t)inbdcca20ppowmindbm << 20));
}

/**
 * @brief Returns the current value of the CCA20PFALLTHRDBM field in the RWNXAGCCCA1 register.
 *
 * The RWNXAGCCCA1 register will be read and the CCA20PFALLTHRDBM field's value will be returned.
 *
 * @return The current value of the CCA20PFALLTHRDBM field in the RWNXAGCCCA1 register.
 */
__INLINE uint8_t riu_cca20pfallthrdbm_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCCCA1_ADDR);
    return ((localVal & ((uint32_t)0x000FF000)) >> 12);
}

/**
 * @brief Sets the CCA20PFALLTHRDBM field of the RWNXAGCCCA1 register.
 *
 * The RWNXAGCCCA1 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] cca20pfallthrdbm - The value to set the field to.
 */
__INLINE void riu_cca20pfallthrdbm_setf(uint8_t cca20pfallthrdbm)
{
    REG_PL_WR(RIU_RWNXAGCCCA1_ADDR, (REG_PL_RD(RIU_RWNXAGCCCA1_ADDR) & ~((uint32_t)0x000FF000)) | ((uint32_t)cca20pfallthrdbm << 12));
}

/**
 * @brief Returns the current value of the DISCCAEN field in the RWNXAGCCCA1 register.
 *
 * The RWNXAGCCCA1 register will be read and the DISCCAEN field's value will be returned.
 *
 * @return The current value of the DISCCAEN field in the RWNXAGCCCA1 register.
 */
__INLINE uint8_t riu_disccaen_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCCCA1_ADDR);
    return ((localVal & ((uint32_t)0x00000200)) >> 9);
}

/**
 * @brief Sets the DISCCAEN field of the RWNXAGCCCA1 register.
 *
 * The RWNXAGCCCA1 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] disccaen - The value to set the field to.
 */
__INLINE void riu_disccaen_setf(uint8_t disccaen)
{
    REG_PL_WR(RIU_RWNXAGCCCA1_ADDR, (REG_PL_RD(RIU_RWNXAGCCCA1_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)disccaen << 9));
}

/**
 * @brief Returns the current value of the SATCCAEN field in the RWNXAGCCCA1 register.
 *
 * The RWNXAGCCCA1 register will be read and the SATCCAEN field's value will be returned.
 *
 * @return The current value of the SATCCAEN field in the RWNXAGCCCA1 register.
 */
__INLINE uint8_t riu_satccaen_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCCCA1_ADDR);
    return ((localVal & ((uint32_t)0x00000100)) >> 8);
}

/**
 * @brief Sets the SATCCAEN field of the RWNXAGCCCA1 register.
 *
 * The RWNXAGCCCA1 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] satccaen - The value to set the field to.
 */
__INLINE void riu_satccaen_setf(uint8_t satccaen)
{
    REG_PL_WR(RIU_RWNXAGCCCA1_ADDR, (REG_PL_RD(RIU_RWNXAGCCCA1_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)satccaen << 8));
}

/**
 * @brief Returns the current value of the CCA20PRISETHRDBM field in the RWNXAGCCCA1 register.
 *
 * The RWNXAGCCCA1 register will be read and the CCA20PRISETHRDBM field's value will be returned.
 *
 * @return The current value of the CCA20PRISETHRDBM field in the RWNXAGCCCA1 register.
 */
__INLINE uint8_t riu_cca20prisethrdbm_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCCCA1_ADDR);
    return ((localVal & ((uint32_t)0x000000FF)) >> 0);
}

/**
 * @brief Sets the CCA20PRISETHRDBM field of the RWNXAGCCCA1 register.
 *
 * The RWNXAGCCCA1 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] cca20prisethrdbm - The value to set the field to.
 */
__INLINE void riu_cca20prisethrdbm_setf(uint8_t cca20prisethrdbm)
{
    REG_PL_WR(RIU_RWNXAGCCCA1_ADDR, (REG_PL_RD(RIU_RWNXAGCCCA1_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)cca20prisethrdbm << 0));
}

/// @}

/**
 * @name RWNXAGCCCACTRL register definitions
 * <table>
 * <caption id="RWNXAGCCCACTRL_BF">RWNXAGCCCACTRL bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>31:28 <td>      CCAFLAG3CTRL <td>R <td>R/W <td>0xA
 * <tr><td>27:24 <td>      CCAFLAG2CTRL <td>R <td>R/W <td>0xA
 * <tr><td>23:20 <td>      CCAFLAG1CTRL <td>R <td>R/W <td>0xA
 * <tr><td>19:16 <td>      CCAFLAG0CTRL <td>R <td>R/W <td>0xA
 * <tr><td>15:14 <td>      ANTSELCCA40S <td>R <td>R/W <td>0x0
 * <tr><td>13:12 <td>      ANTSELCCA20S <td>R <td>R/W <td>0x0
 * <tr><td>09 <td>          CCADEMOD <td>R <td>R/W <td>1
 * <tr><td>08 <td>           CCACSEN <td>R <td>R/W <td>1
 * <tr><td>06:04 <td>       CCARAMPUDEN <td>R <td>R/W <td>0x7
 * <tr><td>02:00 <td>       CCAENERGYEN <td>R <td>R/W <td>0x7
 * </table>
 *
 * @{
 */

/// Address of the RWNXAGCCCACTRL register
#define RIU_RWNXAGCCCACTRL_ADDR   0x4033B3B0
/// Offset of the RWNXAGCCCACTRL register from the base address
#define RIU_RWNXAGCCCACTRL_OFFSET 0x000003B0
/// Index of the RWNXAGCCCACTRL register
#define RIU_RWNXAGCCCACTRL_INDEX  0x000000EC
/// Reset value of the RWNXAGCCCACTRL register
#define RIU_RWNXAGCCCACTRL_RESET  0xAAAA0377

/**
 * @brief Returns the current value of the RWNXAGCCCACTRL register.
 * The RWNXAGCCCACTRL register will be read and its value returned.
 * @return The current value of the RWNXAGCCCACTRL register.
 */
__INLINE uint32_t riu_rwnxagcccactrl_get(void)
{
    return REG_PL_RD(RIU_RWNXAGCCCACTRL_ADDR);
}

/**
 * @brief Sets the RWNXAGCCCACTRL register to a value.
 * The RWNXAGCCCACTRL register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxagcccactrl_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXAGCCCACTRL_ADDR, value);
}

// field definitions
/// CCAFLAG3CTRL field mask
#define RIU_CCAFLAG3CTRL_MASK   ((uint32_t)0xF0000000)
/// CCAFLAG3CTRL field LSB position
#define RIU_CCAFLAG3CTRL_LSB    28
/// CCAFLAG3CTRL field width
#define RIU_CCAFLAG3CTRL_WIDTH  ((uint32_t)0x00000004)
/// CCAFLAG2CTRL field mask
#define RIU_CCAFLAG2CTRL_MASK   ((uint32_t)0x0F000000)
/// CCAFLAG2CTRL field LSB position
#define RIU_CCAFLAG2CTRL_LSB    24
/// CCAFLAG2CTRL field width
#define RIU_CCAFLAG2CTRL_WIDTH  ((uint32_t)0x00000004)
/// CCAFLAG1CTRL field mask
#define RIU_CCAFLAG1CTRL_MASK   ((uint32_t)0x00F00000)
/// CCAFLAG1CTRL field LSB position
#define RIU_CCAFLAG1CTRL_LSB    20
/// CCAFLAG1CTRL field width
#define RIU_CCAFLAG1CTRL_WIDTH  ((uint32_t)0x00000004)
/// CCAFLAG0CTRL field mask
#define RIU_CCAFLAG0CTRL_MASK   ((uint32_t)0x000F0000)
/// CCAFLAG0CTRL field LSB position
#define RIU_CCAFLAG0CTRL_LSB    16
/// CCAFLAG0CTRL field width
#define RIU_CCAFLAG0CTRL_WIDTH  ((uint32_t)0x00000004)
/// ANTSELCCA40S field mask
#define RIU_ANTSELCCA40S_MASK   ((uint32_t)0x0000C000)
/// ANTSELCCA40S field LSB position
#define RIU_ANTSELCCA40S_LSB    14
/// ANTSELCCA40S field width
#define RIU_ANTSELCCA40S_WIDTH  ((uint32_t)0x00000002)
/// ANTSELCCA20S field mask
#define RIU_ANTSELCCA20S_MASK   ((uint32_t)0x00003000)
/// ANTSELCCA20S field LSB position
#define RIU_ANTSELCCA20S_LSB    12
/// ANTSELCCA20S field width
#define RIU_ANTSELCCA20S_WIDTH  ((uint32_t)0x00000002)
/// CCADEMOD field bit
#define RIU_CCADEMOD_BIT        ((uint32_t)0x00000200)
/// CCADEMOD field position
#define RIU_CCADEMOD_POS        9
/// CCACSEN field bit
#define RIU_CCACSEN_BIT         ((uint32_t)0x00000100)
/// CCACSEN field position
#define RIU_CCACSEN_POS         8
/// CCARAMPUDEN field mask
#define RIU_CCARAMPUDEN_MASK    ((uint32_t)0x00000070)
/// CCARAMPUDEN field LSB position
#define RIU_CCARAMPUDEN_LSB     4
/// CCARAMPUDEN field width
#define RIU_CCARAMPUDEN_WIDTH   ((uint32_t)0x00000003)
/// CCAENERGYEN field mask
#define RIU_CCAENERGYEN_MASK    ((uint32_t)0x00000007)
/// CCAENERGYEN field LSB position
#define RIU_CCAENERGYEN_LSB     0
/// CCAENERGYEN field width
#define RIU_CCAENERGYEN_WIDTH   ((uint32_t)0x00000003)

/// CCAFLAG3CTRL field reset value
#define RIU_CCAFLAG3CTRL_RST    0xA
/// CCAFLAG2CTRL field reset value
#define RIU_CCAFLAG2CTRL_RST    0xA
/// CCAFLAG1CTRL field reset value
#define RIU_CCAFLAG1CTRL_RST    0xA
/// CCAFLAG0CTRL field reset value
#define RIU_CCAFLAG0CTRL_RST    0xA
/// ANTSELCCA40S field reset value
#define RIU_ANTSELCCA40S_RST    0x0
/// ANTSELCCA20S field reset value
#define RIU_ANTSELCCA20S_RST    0x0
/// CCADEMOD field reset value
#define RIU_CCADEMOD_RST        0x1
/// CCACSEN field reset value
#define RIU_CCACSEN_RST         0x1
/// CCARAMPUDEN field reset value
#define RIU_CCARAMPUDEN_RST     0x7
/// CCAENERGYEN field reset value
#define RIU_CCAENERGYEN_RST     0x7

/**
 * @brief Constructs a value for the RWNXAGCCCACTRL register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] ccaflag3ctrl - The value to use for the CCAFLAG3CTRL field.
 * @param[in] ccaflag2ctrl - The value to use for the CCAFLAG2CTRL field.
 * @param[in] ccaflag1ctrl - The value to use for the CCAFLAG1CTRL field.
 * @param[in] ccaflag0ctrl - The value to use for the CCAFLAG0CTRL field.
 * @param[in] antselcca40s - The value to use for the ANTSELCCA40S field.
 * @param[in] antselcca20s - The value to use for the ANTSELCCA20S field.
 * @param[in] ccademod - The value to use for the CCADEMOD field.
 * @param[in] ccacsen - The value to use for the CCACSEN field.
 * @param[in] ccarampuden - The value to use for the CCARAMPUDEN field.
 * @param[in] ccaenergyen - The value to use for the CCAENERGYEN field.
 */
__INLINE void riu_rwnxagcccactrl_pack(uint8_t ccaflag3ctrl, uint8_t ccaflag2ctrl, uint8_t ccaflag1ctrl, uint8_t ccaflag0ctrl, uint8_t antselcca40s, uint8_t antselcca20s, uint8_t ccademod, uint8_t ccacsen, uint8_t ccarampuden, uint8_t ccaenergyen)
{
    REG_PL_WR(RIU_RWNXAGCCCACTRL_ADDR,  ((uint32_t)ccaflag3ctrl << 28) | ((uint32_t)ccaflag2ctrl << 24) | ((uint32_t)ccaflag1ctrl << 20) | ((uint32_t)ccaflag0ctrl << 16) | ((uint32_t)antselcca40s << 14) | ((uint32_t)antselcca20s << 12) | ((uint32_t)ccademod << 9) | ((uint32_t)ccacsen << 8) | ((uint32_t)ccarampuden << 4) | ((uint32_t)ccaenergyen << 0));
}

/**
 * @brief Unpacks RWNXAGCCCACTRL's fields from current value of the RWNXAGCCCACTRL register.
 *
 * Reads the RWNXAGCCCACTRL register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] ccaflag3ctrl - Will be populated with the current value of this field from the register.
 * @param[out] ccaflag2ctrl - Will be populated with the current value of this field from the register.
 * @param[out] ccaflag1ctrl - Will be populated with the current value of this field from the register.
 * @param[out] ccaflag0ctrl - Will be populated with the current value of this field from the register.
 * @param[out] antselcca40s - Will be populated with the current value of this field from the register.
 * @param[out] antselcca20s - Will be populated with the current value of this field from the register.
 * @param[out] ccademod - Will be populated with the current value of this field from the register.
 * @param[out] ccacsen - Will be populated with the current value of this field from the register.
 * @param[out] ccarampuden - Will be populated with the current value of this field from the register.
 * @param[out] ccaenergyen - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxagcccactrl_unpack(uint8_t* ccaflag3ctrl, uint8_t* ccaflag2ctrl, uint8_t* ccaflag1ctrl, uint8_t* ccaflag0ctrl, uint8_t* antselcca40s, uint8_t* antselcca20s, uint8_t* ccademod, uint8_t* ccacsen, uint8_t* ccarampuden, uint8_t* ccaenergyen)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCCCACTRL_ADDR);

    *ccaflag3ctrl = (localVal & ((uint32_t)0xF0000000)) >> 28;
    *ccaflag2ctrl = (localVal & ((uint32_t)0x0F000000)) >> 24;
    *ccaflag1ctrl = (localVal & ((uint32_t)0x00F00000)) >> 20;
    *ccaflag0ctrl = (localVal & ((uint32_t)0x000F0000)) >> 16;
    *antselcca40s = (localVal & ((uint32_t)0x0000C000)) >> 14;
    *antselcca20s = (localVal & ((uint32_t)0x00003000)) >> 12;
    *ccademod = (localVal & ((uint32_t)0x00000200)) >> 9;
    *ccacsen = (localVal & ((uint32_t)0x00000100)) >> 8;
    *ccarampuden = (localVal & ((uint32_t)0x00000070)) >> 4;
    *ccaenergyen = (localVal & ((uint32_t)0x00000007)) >> 0;
}

/**
 * @brief Returns the current value of the CCAFLAG3CTRL field in the RWNXAGCCCACTRL register.
 *
 * The RWNXAGCCCACTRL register will be read and the CCAFLAG3CTRL field's value will be returned.
 *
 * @return The current value of the CCAFLAG3CTRL field in the RWNXAGCCCACTRL register.
 */
__INLINE uint8_t riu_ccaflag3ctrl_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCCCACTRL_ADDR);
    return ((localVal & ((uint32_t)0xF0000000)) >> 28);
}

/**
 * @brief Sets the CCAFLAG3CTRL field of the RWNXAGCCCACTRL register.
 *
 * The RWNXAGCCCACTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] ccaflag3ctrl - The value to set the field to.
 */
__INLINE void riu_ccaflag3ctrl_setf(uint8_t ccaflag3ctrl)
{
    REG_PL_WR(RIU_RWNXAGCCCACTRL_ADDR, (REG_PL_RD(RIU_RWNXAGCCCACTRL_ADDR) & ~((uint32_t)0xF0000000)) | ((uint32_t)ccaflag3ctrl << 28));
}

/**
 * @brief Returns the current value of the CCAFLAG2CTRL field in the RWNXAGCCCACTRL register.
 *
 * The RWNXAGCCCACTRL register will be read and the CCAFLAG2CTRL field's value will be returned.
 *
 * @return The current value of the CCAFLAG2CTRL field in the RWNXAGCCCACTRL register.
 */
__INLINE uint8_t riu_ccaflag2ctrl_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCCCACTRL_ADDR);
    return ((localVal & ((uint32_t)0x0F000000)) >> 24);
}

/**
 * @brief Sets the CCAFLAG2CTRL field of the RWNXAGCCCACTRL register.
 *
 * The RWNXAGCCCACTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] ccaflag2ctrl - The value to set the field to.
 */
__INLINE void riu_ccaflag2ctrl_setf(uint8_t ccaflag2ctrl)
{
    REG_PL_WR(RIU_RWNXAGCCCACTRL_ADDR, (REG_PL_RD(RIU_RWNXAGCCCACTRL_ADDR) & ~((uint32_t)0x0F000000)) | ((uint32_t)ccaflag2ctrl << 24));
}

/**
 * @brief Returns the current value of the CCAFLAG1CTRL field in the RWNXAGCCCACTRL register.
 *
 * The RWNXAGCCCACTRL register will be read and the CCAFLAG1CTRL field's value will be returned.
 *
 * @return The current value of the CCAFLAG1CTRL field in the RWNXAGCCCACTRL register.
 */
__INLINE uint8_t riu_ccaflag1ctrl_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCCCACTRL_ADDR);
    return ((localVal & ((uint32_t)0x00F00000)) >> 20);
}

/**
 * @brief Sets the CCAFLAG1CTRL field of the RWNXAGCCCACTRL register.
 *
 * The RWNXAGCCCACTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] ccaflag1ctrl - The value to set the field to.
 */
__INLINE void riu_ccaflag1ctrl_setf(uint8_t ccaflag1ctrl)
{
    REG_PL_WR(RIU_RWNXAGCCCACTRL_ADDR, (REG_PL_RD(RIU_RWNXAGCCCACTRL_ADDR) & ~((uint32_t)0x00F00000)) | ((uint32_t)ccaflag1ctrl << 20));
}

/**
 * @brief Returns the current value of the CCAFLAG0CTRL field in the RWNXAGCCCACTRL register.
 *
 * The RWNXAGCCCACTRL register will be read and the CCAFLAG0CTRL field's value will be returned.
 *
 * @return The current value of the CCAFLAG0CTRL field in the RWNXAGCCCACTRL register.
 */
__INLINE uint8_t riu_ccaflag0ctrl_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCCCACTRL_ADDR);
    return ((localVal & ((uint32_t)0x000F0000)) >> 16);
}

/**
 * @brief Sets the CCAFLAG0CTRL field of the RWNXAGCCCACTRL register.
 *
 * The RWNXAGCCCACTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] ccaflag0ctrl - The value to set the field to.
 */
__INLINE void riu_ccaflag0ctrl_setf(uint8_t ccaflag0ctrl)
{
    REG_PL_WR(RIU_RWNXAGCCCACTRL_ADDR, (REG_PL_RD(RIU_RWNXAGCCCACTRL_ADDR) & ~((uint32_t)0x000F0000)) | ((uint32_t)ccaflag0ctrl << 16));
}

/**
 * @brief Returns the current value of the ANTSELCCA40S field in the RWNXAGCCCACTRL register.
 *
 * The RWNXAGCCCACTRL register will be read and the ANTSELCCA40S field's value will be returned.
 *
 * @return The current value of the ANTSELCCA40S field in the RWNXAGCCCACTRL register.
 */
__INLINE uint8_t riu_antselcca40s_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCCCACTRL_ADDR);
    return ((localVal & ((uint32_t)0x0000C000)) >> 14);
}

/**
 * @brief Sets the ANTSELCCA40S field of the RWNXAGCCCACTRL register.
 *
 * The RWNXAGCCCACTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] antselcca40s - The value to set the field to.
 */
__INLINE void riu_antselcca40s_setf(uint8_t antselcca40s)
{
    REG_PL_WR(RIU_RWNXAGCCCACTRL_ADDR, (REG_PL_RD(RIU_RWNXAGCCCACTRL_ADDR) & ~((uint32_t)0x0000C000)) | ((uint32_t)antselcca40s << 14));
}

/**
 * @brief Returns the current value of the ANTSELCCA20S field in the RWNXAGCCCACTRL register.
 *
 * The RWNXAGCCCACTRL register will be read and the ANTSELCCA20S field's value will be returned.
 *
 * @return The current value of the ANTSELCCA20S field in the RWNXAGCCCACTRL register.
 */
__INLINE uint8_t riu_antselcca20s_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCCCACTRL_ADDR);
    return ((localVal & ((uint32_t)0x00003000)) >> 12);
}

/**
 * @brief Sets the ANTSELCCA20S field of the RWNXAGCCCACTRL register.
 *
 * The RWNXAGCCCACTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] antselcca20s - The value to set the field to.
 */
__INLINE void riu_antselcca20s_setf(uint8_t antselcca20s)
{
    REG_PL_WR(RIU_RWNXAGCCCACTRL_ADDR, (REG_PL_RD(RIU_RWNXAGCCCACTRL_ADDR) & ~((uint32_t)0x00003000)) | ((uint32_t)antselcca20s << 12));
}

/**
 * @brief Returns the current value of the CCADEMOD field in the RWNXAGCCCACTRL register.
 *
 * The RWNXAGCCCACTRL register will be read and the CCADEMOD field's value will be returned.
 *
 * @return The current value of the CCADEMOD field in the RWNXAGCCCACTRL register.
 */
__INLINE uint8_t riu_ccademod_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCCCACTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000200)) >> 9);
}

/**
 * @brief Sets the CCADEMOD field of the RWNXAGCCCACTRL register.
 *
 * The RWNXAGCCCACTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] ccademod - The value to set the field to.
 */
__INLINE void riu_ccademod_setf(uint8_t ccademod)
{
    REG_PL_WR(RIU_RWNXAGCCCACTRL_ADDR, (REG_PL_RD(RIU_RWNXAGCCCACTRL_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)ccademod << 9));
}

/**
 * @brief Returns the current value of the CCACSEN field in the RWNXAGCCCACTRL register.
 *
 * The RWNXAGCCCACTRL register will be read and the CCACSEN field's value will be returned.
 *
 * @return The current value of the CCACSEN field in the RWNXAGCCCACTRL register.
 */
__INLINE uint8_t riu_ccacsen_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCCCACTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000100)) >> 8);
}

/**
 * @brief Sets the CCACSEN field of the RWNXAGCCCACTRL register.
 *
 * The RWNXAGCCCACTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] ccacsen - The value to set the field to.
 */
__INLINE void riu_ccacsen_setf(uint8_t ccacsen)
{
    REG_PL_WR(RIU_RWNXAGCCCACTRL_ADDR, (REG_PL_RD(RIU_RWNXAGCCCACTRL_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)ccacsen << 8));
}

/**
 * @brief Returns the current value of the CCARAMPUDEN field in the RWNXAGCCCACTRL register.
 *
 * The RWNXAGCCCACTRL register will be read and the CCARAMPUDEN field's value will be returned.
 *
 * @return The current value of the CCARAMPUDEN field in the RWNXAGCCCACTRL register.
 */
__INLINE uint8_t riu_ccarampuden_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCCCACTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000070)) >> 4);
}

/**
 * @brief Sets the CCARAMPUDEN field of the RWNXAGCCCACTRL register.
 *
 * The RWNXAGCCCACTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] ccarampuden - The value to set the field to.
 */
__INLINE void riu_ccarampuden_setf(uint8_t ccarampuden)
{
    REG_PL_WR(RIU_RWNXAGCCCACTRL_ADDR, (REG_PL_RD(RIU_RWNXAGCCCACTRL_ADDR) & ~((uint32_t)0x00000070)) | ((uint32_t)ccarampuden << 4));
}

/**
 * @brief Returns the current value of the CCAENERGYEN field in the RWNXAGCCCACTRL register.
 *
 * The RWNXAGCCCACTRL register will be read and the CCAENERGYEN field's value will be returned.
 *
 * @return The current value of the CCAENERGYEN field in the RWNXAGCCCACTRL register.
 */
__INLINE uint8_t riu_ccaenergyen_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCCCACTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000007)) >> 0);
}

/**
 * @brief Sets the CCAENERGYEN field of the RWNXAGCCCACTRL register.
 *
 * The RWNXAGCCCACTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] ccaenergyen - The value to set the field to.
 */
__INLINE void riu_ccaenergyen_setf(uint8_t ccaenergyen)
{
    REG_PL_WR(RIU_RWNXAGCCCACTRL_ADDR, (REG_PL_RD(RIU_RWNXAGCCCACTRL_ADDR) & ~((uint32_t)0x00000007)) | ((uint32_t)ccaenergyen << 0));
}

/// @}

/**
 * @name RWNXAGCCCASTATE0 register definitions
 * <table>
 * <caption id="RWNXAGCCCASTATE0_BF">RWNXAGCCCASTATE0 bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>26:16 <td>  RXSTATECCA20SSEL <td>R <td>R/W <td>0xD4
 * <tr><td>10:00 <td>  RXSTATECCA20PSEL <td>R <td>R/W <td>0x6FE
 * </table>
 *
 * @{
 */

/// Address of the RWNXAGCCCASTATE0 register
#define RIU_RWNXAGCCCASTATE0_ADDR   0x4033B3B4
/// Offset of the RWNXAGCCCASTATE0 register from the base address
#define RIU_RWNXAGCCCASTATE0_OFFSET 0x000003B4
/// Index of the RWNXAGCCCASTATE0 register
#define RIU_RWNXAGCCCASTATE0_INDEX  0x000000ED
/// Reset value of the RWNXAGCCCASTATE0 register
#define RIU_RWNXAGCCCASTATE0_RESET  0x00D406FE

/**
 * @brief Returns the current value of the RWNXAGCCCASTATE0 register.
 * The RWNXAGCCCASTATE0 register will be read and its value returned.
 * @return The current value of the RWNXAGCCCASTATE0 register.
 */
__INLINE uint32_t riu_rwnxagcccastate0_get(void)
{
    return REG_PL_RD(RIU_RWNXAGCCCASTATE0_ADDR);
}

/**
 * @brief Sets the RWNXAGCCCASTATE0 register to a value.
 * The RWNXAGCCCASTATE0 register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxagcccastate0_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXAGCCCASTATE0_ADDR, value);
}

// field definitions
/// RXSTATECCA20SSEL field mask
#define RIU_RXSTATECCA20SSEL_MASK   ((uint32_t)0x07FF0000)
/// RXSTATECCA20SSEL field LSB position
#define RIU_RXSTATECCA20SSEL_LSB    16
/// RXSTATECCA20SSEL field width
#define RIU_RXSTATECCA20SSEL_WIDTH  ((uint32_t)0x0000000B)
/// RXSTATECCA20PSEL field mask
#define RIU_RXSTATECCA20PSEL_MASK   ((uint32_t)0x000007FF)
/// RXSTATECCA20PSEL field LSB position
#define RIU_RXSTATECCA20PSEL_LSB    0
/// RXSTATECCA20PSEL field width
#define RIU_RXSTATECCA20PSEL_WIDTH  ((uint32_t)0x0000000B)

/// RXSTATECCA20SSEL field reset value
#define RIU_RXSTATECCA20SSEL_RST    0xD4
/// RXSTATECCA20PSEL field reset value
#define RIU_RXSTATECCA20PSEL_RST    0x6FE

/**
 * @brief Constructs a value for the RWNXAGCCCASTATE0 register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] rxstatecca20ssel - The value to use for the RXSTATECCA20SSEL field.
 * @param[in] rxstatecca20psel - The value to use for the RXSTATECCA20PSEL field.
 */
__INLINE void riu_rwnxagcccastate0_pack(uint16_t rxstatecca20ssel, uint16_t rxstatecca20psel)
{
    REG_PL_WR(RIU_RWNXAGCCCASTATE0_ADDR,  ((uint32_t)rxstatecca20ssel << 16) | ((uint32_t)rxstatecca20psel << 0));
}

/**
 * @brief Unpacks RWNXAGCCCASTATE0's fields from current value of the RWNXAGCCCASTATE0 register.
 *
 * Reads the RWNXAGCCCASTATE0 register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] rxstatecca20ssel - Will be populated with the current value of this field from the register.
 * @param[out] rxstatecca20psel - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxagcccastate0_unpack(uint16_t* rxstatecca20ssel, uint16_t* rxstatecca20psel)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCCCASTATE0_ADDR);

    *rxstatecca20ssel = (localVal & ((uint32_t)0x07FF0000)) >> 16;
    *rxstatecca20psel = (localVal & ((uint32_t)0x000007FF)) >> 0;
}

/**
 * @brief Returns the current value of the RXSTATECCA20SSEL field in the RWNXAGCCCASTATE0 register.
 *
 * The RWNXAGCCCASTATE0 register will be read and the RXSTATECCA20SSEL field's value will be returned.
 *
 * @return The current value of the RXSTATECCA20SSEL field in the RWNXAGCCCASTATE0 register.
 */
__INLINE uint16_t riu_rxstatecca20ssel_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCCCASTATE0_ADDR);
    return ((localVal & ((uint32_t)0x07FF0000)) >> 16);
}

/**
 * @brief Sets the RXSTATECCA20SSEL field of the RWNXAGCCCASTATE0 register.
 *
 * The RWNXAGCCCASTATE0 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rxstatecca20ssel - The value to set the field to.
 */
__INLINE void riu_rxstatecca20ssel_setf(uint16_t rxstatecca20ssel)
{
    REG_PL_WR(RIU_RWNXAGCCCASTATE0_ADDR, (REG_PL_RD(RIU_RWNXAGCCCASTATE0_ADDR) & ~((uint32_t)0x07FF0000)) | ((uint32_t)rxstatecca20ssel << 16));
}

/**
 * @brief Returns the current value of the RXSTATECCA20PSEL field in the RWNXAGCCCASTATE0 register.
 *
 * The RWNXAGCCCASTATE0 register will be read and the RXSTATECCA20PSEL field's value will be returned.
 *
 * @return The current value of the RXSTATECCA20PSEL field in the RWNXAGCCCASTATE0 register.
 */
__INLINE uint16_t riu_rxstatecca20psel_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCCCASTATE0_ADDR);
    return ((localVal & ((uint32_t)0x000007FF)) >> 0);
}

/**
 * @brief Sets the RXSTATECCA20PSEL field of the RWNXAGCCCASTATE0 register.
 *
 * The RWNXAGCCCASTATE0 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rxstatecca20psel - The value to set the field to.
 */
__INLINE void riu_rxstatecca20psel_setf(uint16_t rxstatecca20psel)
{
    REG_PL_WR(RIU_RWNXAGCCCASTATE0_ADDR, (REG_PL_RD(RIU_RWNXAGCCCASTATE0_ADDR) & ~((uint32_t)0x000007FF)) | ((uint32_t)rxstatecca20psel << 0));
}

/// @}

/**
 * @name RWNXAGCCCASTATE1 register definitions
 * <table>
 * <caption id="RWNXAGCCCASTATE1_BF">RWNXAGCCCASTATE1 bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>10:00 <td>  RXSTATECCA40SSEL <td>R <td>R/W <td>0x80
 * </table>
 *
 * @{
 */

/// Address of the RWNXAGCCCASTATE1 register
#define RIU_RWNXAGCCCASTATE1_ADDR   0x4033B3B8
/// Offset of the RWNXAGCCCASTATE1 register from the base address
#define RIU_RWNXAGCCCASTATE1_OFFSET 0x000003B8
/// Index of the RWNXAGCCCASTATE1 register
#define RIU_RWNXAGCCCASTATE1_INDEX  0x000000EE
/// Reset value of the RWNXAGCCCASTATE1 register
#define RIU_RWNXAGCCCASTATE1_RESET  0x00000080

/**
 * @brief Returns the current value of the RWNXAGCCCASTATE1 register.
 * The RWNXAGCCCASTATE1 register will be read and its value returned.
 * @return The current value of the RWNXAGCCCASTATE1 register.
 */
__INLINE uint32_t riu_rwnxagcccastate1_get(void)
{
    return REG_PL_RD(RIU_RWNXAGCCCASTATE1_ADDR);
}

/**
 * @brief Sets the RWNXAGCCCASTATE1 register to a value.
 * The RWNXAGCCCASTATE1 register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxagcccastate1_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXAGCCCASTATE1_ADDR, value);
}

// field definitions
/// RXSTATECCA40SSEL field mask
#define RIU_RXSTATECCA40SSEL_MASK   ((uint32_t)0x000007FF)
/// RXSTATECCA40SSEL field LSB position
#define RIU_RXSTATECCA40SSEL_LSB    0
/// RXSTATECCA40SSEL field width
#define RIU_RXSTATECCA40SSEL_WIDTH  ((uint32_t)0x0000000B)

/// RXSTATECCA40SSEL field reset value
#define RIU_RXSTATECCA40SSEL_RST    0x80

/**
 * @brief Returns the current value of the RXSTATECCA40SSEL field in the RWNXAGCCCASTATE1 register.
 *
 * The RWNXAGCCCASTATE1 register will be read and the RXSTATECCA40SSEL field's value will be returned.
 *
 * @return The current value of the RXSTATECCA40SSEL field in the RWNXAGCCCASTATE1 register.
 */
__INLINE uint16_t riu_rxstatecca40ssel_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCCCASTATE1_ADDR);
    return (localVal >> 0);
}

/**
 * @brief Sets the RXSTATECCA40SSEL field of the RWNXAGCCCASTATE1 register.
 *
 * The RWNXAGCCCASTATE1 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rxstatecca40ssel - The value to set the field to.
 */
__INLINE void riu_rxstatecca40ssel_setf(uint16_t rxstatecca40ssel)
{
    REG_PL_WR(RIU_RWNXAGCCCASTATE1_ADDR, (uint32_t)rxstatecca40ssel << 0);
}

/// @}

/**
 * @name RWNXAGCCCATIMEOUT register definitions
 * <table>
 * <caption id="RWNXAGCCCATIMEOUT_BF">RWNXAGCCCATIMEOUT bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>31:00 <td>        CCATIMEOUT <td>R <td>R/W <td>0x88B80
 * </table>
 *
 * @{
 */

/// Address of the RWNXAGCCCATIMEOUT register
#define RIU_RWNXAGCCCATIMEOUT_ADDR   0x4033B3BC
/// Offset of the RWNXAGCCCATIMEOUT register from the base address
#define RIU_RWNXAGCCCATIMEOUT_OFFSET 0x000003BC
/// Index of the RWNXAGCCCATIMEOUT register
#define RIU_RWNXAGCCCATIMEOUT_INDEX  0x000000EF
/// Reset value of the RWNXAGCCCATIMEOUT register
#define RIU_RWNXAGCCCATIMEOUT_RESET  0x00088B80

/**
 * @brief Returns the current value of the RWNXAGCCCATIMEOUT register.
 * The RWNXAGCCCATIMEOUT register will be read and its value returned.
 * @return The current value of the RWNXAGCCCATIMEOUT register.
 */
__INLINE uint32_t riu_rwnxagcccatimeout_get(void)
{
    return REG_PL_RD(RIU_RWNXAGCCCATIMEOUT_ADDR);
}

/**
 * @brief Sets the RWNXAGCCCATIMEOUT register to a value.
 * The RWNXAGCCCATIMEOUT register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxagcccatimeout_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXAGCCCATIMEOUT_ADDR, value);
}

// field definitions
/// CCATIMEOUT field mask
#define RIU_CCATIMEOUT_MASK   ((uint32_t)0xFFFFFFFF)
/// CCATIMEOUT field LSB position
#define RIU_CCATIMEOUT_LSB    0
/// CCATIMEOUT field width
#define RIU_CCATIMEOUT_WIDTH  ((uint32_t)0x00000020)

/// CCATIMEOUT field reset value
#define RIU_CCATIMEOUT_RST    0x88B80

/**
 * @brief Returns the current value of the CCATIMEOUT field in the RWNXAGCCCATIMEOUT register.
 *
 * The RWNXAGCCCATIMEOUT register will be read and the CCATIMEOUT field's value will be returned.
 *
 * @return The current value of the CCATIMEOUT field in the RWNXAGCCCATIMEOUT register.
 */
__INLINE uint32_t riu_ccatimeout_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCCCATIMEOUT_ADDR);
    return (localVal >> 0);
}

/**
 * @brief Sets the CCATIMEOUT field of the RWNXAGCCCATIMEOUT register.
 *
 * The RWNXAGCCCATIMEOUT register will be read, modified to contain the new field value, and written.
 *
 * @param[in] ccatimeout - The value to set the field to.
 */
__INLINE void riu_ccatimeout_setf(uint32_t ccatimeout)
{
    REG_PL_WR(RIU_RWNXAGCCCATIMEOUT_ADDR, (uint32_t)ccatimeout << 0);
}

/// @}

/**
 * @name RWNXAGCCOMP0 register definitions
 * <table>
 * <caption id="RWNXAGCCOMP0_BF">RWNXAGCCOMP0 bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>31:24 <td>IDINBDPOWGAPDNQDBM <td>R <td>R/W <td>0x28
 * <tr><td>23:16 <td>IDINBDPOWGAPUPQDBM <td>R <td>R/W <td>0x28
 * <tr><td>15:08 <td>  INBDPOWINFTHRDBM <td>R <td>R/W <td>0xB0
 * <tr><td>07:00 <td>  INBDPOWSUPTHRDBM <td>R <td>R/W <td>0xC4
 * </table>
 *
 * @{
 */

/// Address of the RWNXAGCCOMP0 register
#define RIU_RWNXAGCCOMP0_ADDR   0x4033B3C0
/// Offset of the RWNXAGCCOMP0 register from the base address
#define RIU_RWNXAGCCOMP0_OFFSET 0x000003C0
/// Index of the RWNXAGCCOMP0 register
#define RIU_RWNXAGCCOMP0_INDEX  0x000000F0
/// Reset value of the RWNXAGCCOMP0 register
#define RIU_RWNXAGCCOMP0_RESET  0x2828B0C4

/**
 * @brief Returns the current value of the RWNXAGCCOMP0 register.
 * The RWNXAGCCOMP0 register will be read and its value returned.
 * @return The current value of the RWNXAGCCOMP0 register.
 */
__INLINE uint32_t riu_rwnxagccomp0_get(void)
{
    return REG_PL_RD(RIU_RWNXAGCCOMP0_ADDR);
}

/**
 * @brief Sets the RWNXAGCCOMP0 register to a value.
 * The RWNXAGCCOMP0 register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxagccomp0_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXAGCCOMP0_ADDR, value);
}

// field definitions
/// IDINBDPOWGAPDNQDBM field mask
#define RIU_IDINBDPOWGAPDNQDBM_MASK   ((uint32_t)0xFF000000)
/// IDINBDPOWGAPDNQDBM field LSB position
#define RIU_IDINBDPOWGAPDNQDBM_LSB    24
/// IDINBDPOWGAPDNQDBM field width
#define RIU_IDINBDPOWGAPDNQDBM_WIDTH  ((uint32_t)0x00000008)
/// IDINBDPOWGAPUPQDBM field mask
#define RIU_IDINBDPOWGAPUPQDBM_MASK   ((uint32_t)0x00FF0000)
/// IDINBDPOWGAPUPQDBM field LSB position
#define RIU_IDINBDPOWGAPUPQDBM_LSB    16
/// IDINBDPOWGAPUPQDBM field width
#define RIU_IDINBDPOWGAPUPQDBM_WIDTH  ((uint32_t)0x00000008)
/// INBDPOWINFTHRDBM field mask
#define RIU_INBDPOWINFTHRDBM_MASK     ((uint32_t)0x0000FF00)
/// INBDPOWINFTHRDBM field LSB position
#define RIU_INBDPOWINFTHRDBM_LSB      8
/// INBDPOWINFTHRDBM field width
#define RIU_INBDPOWINFTHRDBM_WIDTH    ((uint32_t)0x00000008)
/// INBDPOWSUPTHRDBM field mask
#define RIU_INBDPOWSUPTHRDBM_MASK     ((uint32_t)0x000000FF)
/// INBDPOWSUPTHRDBM field LSB position
#define RIU_INBDPOWSUPTHRDBM_LSB      0
/// INBDPOWSUPTHRDBM field width
#define RIU_INBDPOWSUPTHRDBM_WIDTH    ((uint32_t)0x00000008)

/// IDINBDPOWGAPDNQDBM field reset value
#define RIU_IDINBDPOWGAPDNQDBM_RST    0x28
/// IDINBDPOWGAPUPQDBM field reset value
#define RIU_IDINBDPOWGAPUPQDBM_RST    0x28
/// INBDPOWINFTHRDBM field reset value
#define RIU_INBDPOWINFTHRDBM_RST      0xB0
/// INBDPOWSUPTHRDBM field reset value
#define RIU_INBDPOWSUPTHRDBM_RST      0xC4

/**
 * @brief Constructs a value for the RWNXAGCCOMP0 register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] idinbdpowgapdnqdbm - The value to use for the IDINBDPOWGAPDNQDBM field.
 * @param[in] idinbdpowgapupqdbm - The value to use for the IDINBDPOWGAPUPQDBM field.
 * @param[in] inbdpowinfthrdbm - The value to use for the INBDPOWINFTHRDBM field.
 * @param[in] inbdpowsupthrdbm - The value to use for the INBDPOWSUPTHRDBM field.
 */
__INLINE void riu_rwnxagccomp0_pack(uint8_t idinbdpowgapdnqdbm, uint8_t idinbdpowgapupqdbm, uint8_t inbdpowinfthrdbm, uint8_t inbdpowsupthrdbm)
{
    REG_PL_WR(RIU_RWNXAGCCOMP0_ADDR,  ((uint32_t)idinbdpowgapdnqdbm << 24) | ((uint32_t)idinbdpowgapupqdbm << 16) | ((uint32_t)inbdpowinfthrdbm << 8) | ((uint32_t)inbdpowsupthrdbm << 0));
}

/**
 * @brief Unpacks RWNXAGCCOMP0's fields from current value of the RWNXAGCCOMP0 register.
 *
 * Reads the RWNXAGCCOMP0 register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] idinbdpowgapdnqdbm - Will be populated with the current value of this field from the register.
 * @param[out] idinbdpowgapupqdbm - Will be populated with the current value of this field from the register.
 * @param[out] inbdpowinfthrdbm - Will be populated with the current value of this field from the register.
 * @param[out] inbdpowsupthrdbm - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxagccomp0_unpack(uint8_t* idinbdpowgapdnqdbm, uint8_t* idinbdpowgapupqdbm, uint8_t* inbdpowinfthrdbm, uint8_t* inbdpowsupthrdbm)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCCOMP0_ADDR);

    *idinbdpowgapdnqdbm = (localVal & ((uint32_t)0xFF000000)) >> 24;
    *idinbdpowgapupqdbm = (localVal & ((uint32_t)0x00FF0000)) >> 16;
    *inbdpowinfthrdbm = (localVal & ((uint32_t)0x0000FF00)) >> 8;
    *inbdpowsupthrdbm = (localVal & ((uint32_t)0x000000FF)) >> 0;
}

/**
 * @brief Returns the current value of the IDINBDPOWGAPDNQDBM field in the RWNXAGCCOMP0 register.
 *
 * The RWNXAGCCOMP0 register will be read and the IDINBDPOWGAPDNQDBM field's value will be returned.
 *
 * @return The current value of the IDINBDPOWGAPDNQDBM field in the RWNXAGCCOMP0 register.
 */
__INLINE uint8_t riu_idinbdpowgapdnqdbm_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCCOMP0_ADDR);
    return ((localVal & ((uint32_t)0xFF000000)) >> 24);
}

/**
 * @brief Sets the IDINBDPOWGAPDNQDBM field of the RWNXAGCCOMP0 register.
 *
 * The RWNXAGCCOMP0 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] idinbdpowgapdnqdbm - The value to set the field to.
 */
__INLINE void riu_idinbdpowgapdnqdbm_setf(uint8_t idinbdpowgapdnqdbm)
{
    REG_PL_WR(RIU_RWNXAGCCOMP0_ADDR, (REG_PL_RD(RIU_RWNXAGCCOMP0_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)idinbdpowgapdnqdbm << 24));
}

/**
 * @brief Returns the current value of the IDINBDPOWGAPUPQDBM field in the RWNXAGCCOMP0 register.
 *
 * The RWNXAGCCOMP0 register will be read and the IDINBDPOWGAPUPQDBM field's value will be returned.
 *
 * @return The current value of the IDINBDPOWGAPUPQDBM field in the RWNXAGCCOMP0 register.
 */
__INLINE uint8_t riu_idinbdpowgapupqdbm_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCCOMP0_ADDR);
    return ((localVal & ((uint32_t)0x00FF0000)) >> 16);
}

/**
 * @brief Sets the IDINBDPOWGAPUPQDBM field of the RWNXAGCCOMP0 register.
 *
 * The RWNXAGCCOMP0 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] idinbdpowgapupqdbm - The value to set the field to.
 */
__INLINE void riu_idinbdpowgapupqdbm_setf(uint8_t idinbdpowgapupqdbm)
{
    REG_PL_WR(RIU_RWNXAGCCOMP0_ADDR, (REG_PL_RD(RIU_RWNXAGCCOMP0_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)idinbdpowgapupqdbm << 16));
}

/**
 * @brief Returns the current value of the INBDPOWINFTHRDBM field in the RWNXAGCCOMP0 register.
 *
 * The RWNXAGCCOMP0 register will be read and the INBDPOWINFTHRDBM field's value will be returned.
 *
 * @return The current value of the INBDPOWINFTHRDBM field in the RWNXAGCCOMP0 register.
 */
__INLINE uint8_t riu_inbdpowinfthrdbm_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCCOMP0_ADDR);
    return ((localVal & ((uint32_t)0x0000FF00)) >> 8);
}

/**
 * @brief Sets the INBDPOWINFTHRDBM field of the RWNXAGCCOMP0 register.
 *
 * The RWNXAGCCOMP0 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] inbdpowinfthrdbm - The value to set the field to.
 */
__INLINE void riu_inbdpowinfthrdbm_setf(uint8_t inbdpowinfthrdbm)
{
    REG_PL_WR(RIU_RWNXAGCCOMP0_ADDR, (REG_PL_RD(RIU_RWNXAGCCOMP0_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)inbdpowinfthrdbm << 8));
}

/**
 * @brief Returns the current value of the INBDPOWSUPTHRDBM field in the RWNXAGCCOMP0 register.
 *
 * The RWNXAGCCOMP0 register will be read and the INBDPOWSUPTHRDBM field's value will be returned.
 *
 * @return The current value of the INBDPOWSUPTHRDBM field in the RWNXAGCCOMP0 register.
 */
__INLINE uint8_t riu_inbdpowsupthrdbm_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCCOMP0_ADDR);
    return ((localVal & ((uint32_t)0x000000FF)) >> 0);
}

/**
 * @brief Sets the INBDPOWSUPTHRDBM field of the RWNXAGCCOMP0 register.
 *
 * The RWNXAGCCOMP0 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] inbdpowsupthrdbm - The value to set the field to.
 */
__INLINE void riu_inbdpowsupthrdbm_setf(uint8_t inbdpowsupthrdbm)
{
    REG_PL_WR(RIU_RWNXAGCCOMP0_ADDR, (REG_PL_RD(RIU_RWNXAGCCOMP0_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)inbdpowsupthrdbm << 0));
}

/// @}

/**
 * @name RWNXAGCCOMP1 register definitions
 * <table>
 * <caption id="RWNXAGCCOMP1_BF">RWNXAGCCOMP1 bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>31:24 <td>   ADCPOWINFTHRDBV <td>R <td>R/W <td>0xDD
 * <tr><td>23:16 <td>   ADCPOWSUPTHRDBV <td>R <td>R/W <td>0xDB
 * <tr><td>15:08 <td>   ADCPOWINFTHRDBM <td>R <td>R/W <td>0xBF
 * <tr><td>07:00 <td>   ADCPOWSUPTHRDBM <td>R <td>R/W <td>0xBE
 * </table>
 *
 * @{
 */

/// Address of the RWNXAGCCOMP1 register
#define RIU_RWNXAGCCOMP1_ADDR   0x4033B3C4
/// Offset of the RWNXAGCCOMP1 register from the base address
#define RIU_RWNXAGCCOMP1_OFFSET 0x000003C4
/// Index of the RWNXAGCCOMP1 register
#define RIU_RWNXAGCCOMP1_INDEX  0x000000F1
/// Reset value of the RWNXAGCCOMP1 register
#define RIU_RWNXAGCCOMP1_RESET  0xDDDBBFBE

/**
 * @brief Returns the current value of the RWNXAGCCOMP1 register.
 * The RWNXAGCCOMP1 register will be read and its value returned.
 * @return The current value of the RWNXAGCCOMP1 register.
 */
__INLINE uint32_t riu_rwnxagccomp1_get(void)
{
    return REG_PL_RD(RIU_RWNXAGCCOMP1_ADDR);
}

/**
 * @brief Sets the RWNXAGCCOMP1 register to a value.
 * The RWNXAGCCOMP1 register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxagccomp1_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXAGCCOMP1_ADDR, value);
}

// field definitions
/// ADCPOWINFTHRDBV field mask
#define RIU_ADCPOWINFTHRDBV_MASK   ((uint32_t)0xFF000000)
/// ADCPOWINFTHRDBV field LSB position
#define RIU_ADCPOWINFTHRDBV_LSB    24
/// ADCPOWINFTHRDBV field width
#define RIU_ADCPOWINFTHRDBV_WIDTH  ((uint32_t)0x00000008)
/// ADCPOWSUPTHRDBV field mask
#define RIU_ADCPOWSUPTHRDBV_MASK   ((uint32_t)0x00FF0000)
/// ADCPOWSUPTHRDBV field LSB position
#define RIU_ADCPOWSUPTHRDBV_LSB    16
/// ADCPOWSUPTHRDBV field width
#define RIU_ADCPOWSUPTHRDBV_WIDTH  ((uint32_t)0x00000008)
/// ADCPOWINFTHRDBM field mask
#define RIU_ADCPOWINFTHRDBM_MASK   ((uint32_t)0x0000FF00)
/// ADCPOWINFTHRDBM field LSB position
#define RIU_ADCPOWINFTHRDBM_LSB    8
/// ADCPOWINFTHRDBM field width
#define RIU_ADCPOWINFTHRDBM_WIDTH  ((uint32_t)0x00000008)
/// ADCPOWSUPTHRDBM field mask
#define RIU_ADCPOWSUPTHRDBM_MASK   ((uint32_t)0x000000FF)
/// ADCPOWSUPTHRDBM field LSB position
#define RIU_ADCPOWSUPTHRDBM_LSB    0
/// ADCPOWSUPTHRDBM field width
#define RIU_ADCPOWSUPTHRDBM_WIDTH  ((uint32_t)0x00000008)

/// ADCPOWINFTHRDBV field reset value
#define RIU_ADCPOWINFTHRDBV_RST    0xDD
/// ADCPOWSUPTHRDBV field reset value
#define RIU_ADCPOWSUPTHRDBV_RST    0xDB
/// ADCPOWINFTHRDBM field reset value
#define RIU_ADCPOWINFTHRDBM_RST    0xBF
/// ADCPOWSUPTHRDBM field reset value
#define RIU_ADCPOWSUPTHRDBM_RST    0xBE

/**
 * @brief Constructs a value for the RWNXAGCCOMP1 register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] adcpowinfthrdbv - The value to use for the ADCPOWINFTHRDBV field.
 * @param[in] adcpowsupthrdbv - The value to use for the ADCPOWSUPTHRDBV field.
 * @param[in] adcpowinfthrdbm - The value to use for the ADCPOWINFTHRDBM field.
 * @param[in] adcpowsupthrdbm - The value to use for the ADCPOWSUPTHRDBM field.
 */
__INLINE void riu_rwnxagccomp1_pack(uint8_t adcpowinfthrdbv, uint8_t adcpowsupthrdbv, uint8_t adcpowinfthrdbm, uint8_t adcpowsupthrdbm)
{
    REG_PL_WR(RIU_RWNXAGCCOMP1_ADDR,  ((uint32_t)adcpowinfthrdbv << 24) | ((uint32_t)adcpowsupthrdbv << 16) | ((uint32_t)adcpowinfthrdbm << 8) | ((uint32_t)adcpowsupthrdbm << 0));
}

/**
 * @brief Unpacks RWNXAGCCOMP1's fields from current value of the RWNXAGCCOMP1 register.
 *
 * Reads the RWNXAGCCOMP1 register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] adcpowinfthrdbv - Will be populated with the current value of this field from the register.
 * @param[out] adcpowsupthrdbv - Will be populated with the current value of this field from the register.
 * @param[out] adcpowinfthrdbm - Will be populated with the current value of this field from the register.
 * @param[out] adcpowsupthrdbm - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxagccomp1_unpack(uint8_t* adcpowinfthrdbv, uint8_t* adcpowsupthrdbv, uint8_t* adcpowinfthrdbm, uint8_t* adcpowsupthrdbm)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCCOMP1_ADDR);

    *adcpowinfthrdbv = (localVal & ((uint32_t)0xFF000000)) >> 24;
    *adcpowsupthrdbv = (localVal & ((uint32_t)0x00FF0000)) >> 16;
    *adcpowinfthrdbm = (localVal & ((uint32_t)0x0000FF00)) >> 8;
    *adcpowsupthrdbm = (localVal & ((uint32_t)0x000000FF)) >> 0;
}

/**
 * @brief Returns the current value of the ADCPOWINFTHRDBV field in the RWNXAGCCOMP1 register.
 *
 * The RWNXAGCCOMP1 register will be read and the ADCPOWINFTHRDBV field's value will be returned.
 *
 * @return The current value of the ADCPOWINFTHRDBV field in the RWNXAGCCOMP1 register.
 */
__INLINE uint8_t riu_adcpowinfthrdbv_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCCOMP1_ADDR);
    return ((localVal & ((uint32_t)0xFF000000)) >> 24);
}

/**
 * @brief Sets the ADCPOWINFTHRDBV field of the RWNXAGCCOMP1 register.
 *
 * The RWNXAGCCOMP1 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] adcpowinfthrdbv - The value to set the field to.
 */
__INLINE void riu_adcpowinfthrdbv_setf(uint8_t adcpowinfthrdbv)
{
    REG_PL_WR(RIU_RWNXAGCCOMP1_ADDR, (REG_PL_RD(RIU_RWNXAGCCOMP1_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)adcpowinfthrdbv << 24));
}

/**
 * @brief Returns the current value of the ADCPOWSUPTHRDBV field in the RWNXAGCCOMP1 register.
 *
 * The RWNXAGCCOMP1 register will be read and the ADCPOWSUPTHRDBV field's value will be returned.
 *
 * @return The current value of the ADCPOWSUPTHRDBV field in the RWNXAGCCOMP1 register.
 */
__INLINE uint8_t riu_adcpowsupthrdbv_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCCOMP1_ADDR);
    return ((localVal & ((uint32_t)0x00FF0000)) >> 16);
}

/**
 * @brief Sets the ADCPOWSUPTHRDBV field of the RWNXAGCCOMP1 register.
 *
 * The RWNXAGCCOMP1 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] adcpowsupthrdbv - The value to set the field to.
 */
__INLINE void riu_adcpowsupthrdbv_setf(uint8_t adcpowsupthrdbv)
{
    REG_PL_WR(RIU_RWNXAGCCOMP1_ADDR, (REG_PL_RD(RIU_RWNXAGCCOMP1_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)adcpowsupthrdbv << 16));
}

/**
 * @brief Returns the current value of the ADCPOWINFTHRDBM field in the RWNXAGCCOMP1 register.
 *
 * The RWNXAGCCOMP1 register will be read and the ADCPOWINFTHRDBM field's value will be returned.
 *
 * @return The current value of the ADCPOWINFTHRDBM field in the RWNXAGCCOMP1 register.
 */
__INLINE uint8_t riu_adcpowinfthrdbm_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCCOMP1_ADDR);
    return ((localVal & ((uint32_t)0x0000FF00)) >> 8);
}

/**
 * @brief Sets the ADCPOWINFTHRDBM field of the RWNXAGCCOMP1 register.
 *
 * The RWNXAGCCOMP1 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] adcpowinfthrdbm - The value to set the field to.
 */
__INLINE void riu_adcpowinfthrdbm_setf(uint8_t adcpowinfthrdbm)
{
    REG_PL_WR(RIU_RWNXAGCCOMP1_ADDR, (REG_PL_RD(RIU_RWNXAGCCOMP1_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)adcpowinfthrdbm << 8));
}

/**
 * @brief Returns the current value of the ADCPOWSUPTHRDBM field in the RWNXAGCCOMP1 register.
 *
 * The RWNXAGCCOMP1 register will be read and the ADCPOWSUPTHRDBM field's value will be returned.
 *
 * @return The current value of the ADCPOWSUPTHRDBM field in the RWNXAGCCOMP1 register.
 */
__INLINE uint8_t riu_adcpowsupthrdbm_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCCOMP1_ADDR);
    return ((localVal & ((uint32_t)0x000000FF)) >> 0);
}

/**
 * @brief Sets the ADCPOWSUPTHRDBM field of the RWNXAGCCOMP1 register.
 *
 * The RWNXAGCCOMP1 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] adcpowsupthrdbm - The value to set the field to.
 */
__INLINE void riu_adcpowsupthrdbm_setf(uint8_t adcpowsupthrdbm)
{
    REG_PL_WR(RIU_RWNXAGCCOMP1_ADDR, (REG_PL_RD(RIU_RWNXAGCCOMP1_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)adcpowsupthrdbm << 0));
}

/// @}

#if RW_RADAR_EN
/**
 * @name RWNXAGCRADAR register definitions
 * <table>
 * <caption id="RWNXAGCRADAR_BF">RWNXAGCRADAR bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>29:28 <td>       ANTSELRADAR <td>R <td>R/W <td>0x0
 * <tr><td>27:24 <td>       FREQSINGGAP <td>R <td>R/W <td>0x0
 * <tr><td>23:16 <td>          FREQSING <td>R <td>R/W <td>0x0
 * <tr><td>11:08 <td>        FOMSINGGAP <td>R <td>R/W <td>0x0
 * <tr><td>07:00 <td>           FOMSING <td>R <td>R/W <td>0x0
 * </table>
 *
 * @{
 */

/// Address of the RWNXAGCRADAR register
#define RIU_RWNXAGCRADAR_ADDR   0x4033B3C8
/// Offset of the RWNXAGCRADAR register from the base address
#define RIU_RWNXAGCRADAR_OFFSET 0x000003C8
/// Index of the RWNXAGCRADAR register
#define RIU_RWNXAGCRADAR_INDEX  0x000000F2
/// Reset value of the RWNXAGCRADAR register
#define RIU_RWNXAGCRADAR_RESET  0x00000000

/**
 * @brief Returns the current value of the RWNXAGCRADAR register.
 * The RWNXAGCRADAR register will be read and its value returned.
 * @return The current value of the RWNXAGCRADAR register.
 */
__INLINE uint32_t riu_rwnxagcradar_get(void)
{
    return REG_PL_RD(RIU_RWNXAGCRADAR_ADDR);
}

/**
 * @brief Sets the RWNXAGCRADAR register to a value.
 * The RWNXAGCRADAR register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxagcradar_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXAGCRADAR_ADDR, value);
}

// field definitions
/// ANTSELRADAR field mask
#define RIU_ANTSELRADAR_MASK   ((uint32_t)0x30000000)
/// ANTSELRADAR field LSB position
#define RIU_ANTSELRADAR_LSB    28
/// ANTSELRADAR field width
#define RIU_ANTSELRADAR_WIDTH  ((uint32_t)0x00000002)
/// FREQSINGGAP field mask
#define RIU_FREQSINGGAP_MASK   ((uint32_t)0x0F000000)
/// FREQSINGGAP field LSB position
#define RIU_FREQSINGGAP_LSB    24
/// FREQSINGGAP field width
#define RIU_FREQSINGGAP_WIDTH  ((uint32_t)0x00000004)
/// FREQSING field mask
#define RIU_FREQSING_MASK      ((uint32_t)0x00FF0000)
/// FREQSING field LSB position
#define RIU_FREQSING_LSB       16
/// FREQSING field width
#define RIU_FREQSING_WIDTH     ((uint32_t)0x00000008)
/// FOMSINGGAP field mask
#define RIU_FOMSINGGAP_MASK    ((uint32_t)0x00000F00)
/// FOMSINGGAP field LSB position
#define RIU_FOMSINGGAP_LSB     8
/// FOMSINGGAP field width
#define RIU_FOMSINGGAP_WIDTH   ((uint32_t)0x00000004)
/// FOMSING field mask
#define RIU_FOMSING_MASK       ((uint32_t)0x000000FF)
/// FOMSING field LSB position
#define RIU_FOMSING_LSB        0
/// FOMSING field width
#define RIU_FOMSING_WIDTH      ((uint32_t)0x00000008)

/// ANTSELRADAR field reset value
#define RIU_ANTSELRADAR_RST    0x0
/// FREQSINGGAP field reset value
#define RIU_FREQSINGGAP_RST    0x0
/// FREQSING field reset value
#define RIU_FREQSING_RST       0x0
/// FOMSINGGAP field reset value
#define RIU_FOMSINGGAP_RST     0x0
/// FOMSING field reset value
#define RIU_FOMSING_RST        0x0

/**
 * @brief Constructs a value for the RWNXAGCRADAR register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] antselradar - The value to use for the ANTSELRADAR field.
 * @param[in] freqsinggap - The value to use for the FREQSINGGAP field.
 * @param[in] freqsing - The value to use for the FREQSING field.
 * @param[in] fomsinggap - The value to use for the FOMSINGGAP field.
 * @param[in] fomsing - The value to use for the FOMSING field.
 */
__INLINE void riu_rwnxagcradar_pack(uint8_t antselradar, uint8_t freqsinggap, uint8_t freqsing, uint8_t fomsinggap, uint8_t fomsing)
{
    REG_PL_WR(RIU_RWNXAGCRADAR_ADDR,  ((uint32_t)antselradar << 28) | ((uint32_t)freqsinggap << 24) | ((uint32_t)freqsing << 16) | ((uint32_t)fomsinggap << 8) | ((uint32_t)fomsing << 0));
}

/**
 * @brief Unpacks RWNXAGCRADAR's fields from current value of the RWNXAGCRADAR register.
 *
 * Reads the RWNXAGCRADAR register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] antselradar - Will be populated with the current value of this field from the register.
 * @param[out] freqsinggap - Will be populated with the current value of this field from the register.
 * @param[out] freqsing - Will be populated with the current value of this field from the register.
 * @param[out] fomsinggap - Will be populated with the current value of this field from the register.
 * @param[out] fomsing - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxagcradar_unpack(uint8_t* antselradar, uint8_t* freqsinggap, uint8_t* freqsing, uint8_t* fomsinggap, uint8_t* fomsing)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCRADAR_ADDR);

    *antselradar = (localVal & ((uint32_t)0x30000000)) >> 28;
    *freqsinggap = (localVal & ((uint32_t)0x0F000000)) >> 24;
    *freqsing = (localVal & ((uint32_t)0x00FF0000)) >> 16;
    *fomsinggap = (localVal & ((uint32_t)0x00000F00)) >> 8;
    *fomsing = (localVal & ((uint32_t)0x000000FF)) >> 0;
}

/**
 * @brief Returns the current value of the ANTSELRADAR field in the RWNXAGCRADAR register.
 *
 * The RWNXAGCRADAR register will be read and the ANTSELRADAR field's value will be returned.
 *
 * @return The current value of the ANTSELRADAR field in the RWNXAGCRADAR register.
 */
__INLINE uint8_t riu_antselradar_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCRADAR_ADDR);
    return ((localVal & ((uint32_t)0x30000000)) >> 28);
}

/**
 * @brief Sets the ANTSELRADAR field of the RWNXAGCRADAR register.
 *
 * The RWNXAGCRADAR register will be read, modified to contain the new field value, and written.
 *
 * @param[in] antselradar - The value to set the field to.
 */
__INLINE void riu_antselradar_setf(uint8_t antselradar)
{
    REG_PL_WR(RIU_RWNXAGCRADAR_ADDR, (REG_PL_RD(RIU_RWNXAGCRADAR_ADDR) & ~((uint32_t)0x30000000)) | ((uint32_t)antselradar << 28));
}

/**
 * @brief Returns the current value of the FREQSINGGAP field in the RWNXAGCRADAR register.
 *
 * The RWNXAGCRADAR register will be read and the FREQSINGGAP field's value will be returned.
 *
 * @return The current value of the FREQSINGGAP field in the RWNXAGCRADAR register.
 */
__INLINE uint8_t riu_freqsinggap_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCRADAR_ADDR);
    return ((localVal & ((uint32_t)0x0F000000)) >> 24);
}

/**
 * @brief Sets the FREQSINGGAP field of the RWNXAGCRADAR register.
 *
 * The RWNXAGCRADAR register will be read, modified to contain the new field value, and written.
 *
 * @param[in] freqsinggap - The value to set the field to.
 */
__INLINE void riu_freqsinggap_setf(uint8_t freqsinggap)
{
    REG_PL_WR(RIU_RWNXAGCRADAR_ADDR, (REG_PL_RD(RIU_RWNXAGCRADAR_ADDR) & ~((uint32_t)0x0F000000)) | ((uint32_t)freqsinggap << 24));
}

/**
 * @brief Returns the current value of the FREQSING field in the RWNXAGCRADAR register.
 *
 * The RWNXAGCRADAR register will be read and the FREQSING field's value will be returned.
 *
 * @return The current value of the FREQSING field in the RWNXAGCRADAR register.
 */
__INLINE uint8_t riu_freqsing_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCRADAR_ADDR);
    return ((localVal & ((uint32_t)0x00FF0000)) >> 16);
}

/**
 * @brief Sets the FREQSING field of the RWNXAGCRADAR register.
 *
 * The RWNXAGCRADAR register will be read, modified to contain the new field value, and written.
 *
 * @param[in] freqsing - The value to set the field to.
 */
__INLINE void riu_freqsing_setf(uint8_t freqsing)
{
    REG_PL_WR(RIU_RWNXAGCRADAR_ADDR, (REG_PL_RD(RIU_RWNXAGCRADAR_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)freqsing << 16));
}

/**
 * @brief Returns the current value of the FOMSINGGAP field in the RWNXAGCRADAR register.
 *
 * The RWNXAGCRADAR register will be read and the FOMSINGGAP field's value will be returned.
 *
 * @return The current value of the FOMSINGGAP field in the RWNXAGCRADAR register.
 */
__INLINE uint8_t riu_fomsinggap_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCRADAR_ADDR);
    return ((localVal & ((uint32_t)0x00000F00)) >> 8);
}

/**
 * @brief Sets the FOMSINGGAP field of the RWNXAGCRADAR register.
 *
 * The RWNXAGCRADAR register will be read, modified to contain the new field value, and written.
 *
 * @param[in] fomsinggap - The value to set the field to.
 */
__INLINE void riu_fomsinggap_setf(uint8_t fomsinggap)
{
    REG_PL_WR(RIU_RWNXAGCRADAR_ADDR, (REG_PL_RD(RIU_RWNXAGCRADAR_ADDR) & ~((uint32_t)0x00000F00)) | ((uint32_t)fomsinggap << 8));
}

/**
 * @brief Returns the current value of the FOMSING field in the RWNXAGCRADAR register.
 *
 * The RWNXAGCRADAR register will be read and the FOMSING field's value will be returned.
 *
 * @return The current value of the FOMSING field in the RWNXAGCRADAR register.
 */
__INLINE uint8_t riu_fomsing_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCRADAR_ADDR);
    return ((localVal & ((uint32_t)0x000000FF)) >> 0);
}

/**
 * @brief Sets the FOMSING field of the RWNXAGCRADAR register.
 *
 * The RWNXAGCRADAR register will be read, modified to contain the new field value, and written.
 *
 * @param[in] fomsing - The value to set the field to.
 */
__INLINE void riu_fomsing_setf(uint8_t fomsing)
{
    REG_PL_WR(RIU_RWNXAGCRADAR_ADDR, (REG_PL_RD(RIU_RWNXAGCRADAR_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)fomsing << 0));
}

#endif // RW_RADAR_EN
/// @}

#if RW_RADAR_EN
/**
 * @name RWNXAGCRADARTIM register definitions
 * <table>
 * <caption id="RWNXAGCRADARTIM_BF">RWNXAGCRADARTIM bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>31 <td>   PULSETIMERCLEAR <td>R <td>S <td>0
 * <tr><td>18:16 <td>   PULSEIRQFIFOTHR <td>R <td>R/W <td>0x3
 * <tr><td>07:00 <td>   PULSEIRQTIMEOUT <td>R <td>R/W <td>0x8
 * </table>
 *
 * @{
 */

/// Address of the RWNXAGCRADARTIM register
#define RIU_RWNXAGCRADARTIM_ADDR   0x4033B3CC
/// Offset of the RWNXAGCRADARTIM register from the base address
#define RIU_RWNXAGCRADARTIM_OFFSET 0x000003CC
/// Index of the RWNXAGCRADARTIM register
#define RIU_RWNXAGCRADARTIM_INDEX  0x000000F3
/// Reset value of the RWNXAGCRADARTIM register
#define RIU_RWNXAGCRADARTIM_RESET  0x00030008

/**
 * @brief Returns the current value of the RWNXAGCRADARTIM register.
 * The RWNXAGCRADARTIM register will be read and its value returned.
 * @return The current value of the RWNXAGCRADARTIM register.
 */
__INLINE uint32_t riu_rwnxagcradartim_get(void)
{
    return REG_PL_RD(RIU_RWNXAGCRADARTIM_ADDR);
}

/**
 * @brief Sets the RWNXAGCRADARTIM register to a value.
 * The RWNXAGCRADARTIM register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxagcradartim_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXAGCRADARTIM_ADDR, value);
}

// field definitions
/// PULSETIMERCLEAR field bit
#define RIU_PULSETIMERCLEAR_BIT    ((uint32_t)0x80000000)
/// PULSETIMERCLEAR field position
#define RIU_PULSETIMERCLEAR_POS    31
/// PULSEIRQFIFOTHR field mask
#define RIU_PULSEIRQFIFOTHR_MASK   ((uint32_t)0x00070000)
/// PULSEIRQFIFOTHR field LSB position
#define RIU_PULSEIRQFIFOTHR_LSB    16
/// PULSEIRQFIFOTHR field width
#define RIU_PULSEIRQFIFOTHR_WIDTH  ((uint32_t)0x00000003)
/// PULSEIRQTIMEOUT field mask
#define RIU_PULSEIRQTIMEOUT_MASK   ((uint32_t)0x000000FF)
/// PULSEIRQTIMEOUT field LSB position
#define RIU_PULSEIRQTIMEOUT_LSB    0
/// PULSEIRQTIMEOUT field width
#define RIU_PULSEIRQTIMEOUT_WIDTH  ((uint32_t)0x00000008)

/// PULSETIMERCLEAR field reset value
#define RIU_PULSETIMERCLEAR_RST    0x0
/// PULSEIRQFIFOTHR field reset value
#define RIU_PULSEIRQFIFOTHR_RST    0x3
/// PULSEIRQTIMEOUT field reset value
#define RIU_PULSEIRQTIMEOUT_RST    0x8

/**
 * @brief Constructs a value for the RWNXAGCRADARTIM register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] pulsetimerclear - The value to use for the PULSETIMERCLEAR field.
 * @param[in] pulseirqfifothr - The value to use for the PULSEIRQFIFOTHR field.
 * @param[in] pulseirqtimeout - The value to use for the PULSEIRQTIMEOUT field.
 */
__INLINE void riu_rwnxagcradartim_pack(uint8_t pulsetimerclear, uint8_t pulseirqfifothr, uint8_t pulseirqtimeout)
{
    REG_PL_WR(RIU_RWNXAGCRADARTIM_ADDR,  ((uint32_t)pulsetimerclear << 31) | ((uint32_t)pulseirqfifothr << 16) | ((uint32_t)pulseirqtimeout << 0));
}

/**
 * @brief Unpacks RWNXAGCRADARTIM's fields from current value of the RWNXAGCRADARTIM register.
 *
 * Reads the RWNXAGCRADARTIM register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] pulsetimerclear - Will be populated with the current value of this field from the register.
 * @param[out] pulseirqfifothr - Will be populated with the current value of this field from the register.
 * @param[out] pulseirqtimeout - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxagcradartim_unpack(uint8_t* pulsetimerclear, uint8_t* pulseirqfifothr, uint8_t* pulseirqtimeout)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCRADARTIM_ADDR);

    *pulsetimerclear = (localVal & ((uint32_t)0x80000000)) >> 31;
    *pulseirqfifothr = (localVal & ((uint32_t)0x00070000)) >> 16;
    *pulseirqtimeout = (localVal & ((uint32_t)0x000000FF)) >> 0;
}

/**
 * @brief Returns the current value of the PULSETIMERCLEAR field in the RWNXAGCRADARTIM register.
 *
 * The RWNXAGCRADARTIM register will be read and the PULSETIMERCLEAR field's value will be returned.
 *
 * @return The current value of the PULSETIMERCLEAR field in the RWNXAGCRADARTIM register.
 */
__INLINE uint8_t riu_pulsetimerclear_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCRADARTIM_ADDR);
    return ((localVal & ((uint32_t)0x80000000)) >> 31);
}

/**
 * @brief Sets the PULSETIMERCLEAR field of the RWNXAGCRADARTIM register.
 *
 * The RWNXAGCRADARTIM register will be read, modified to contain the new field value, and written.
 *
 * @param[in] pulsetimerclear - The value to set the field to.
 */
__INLINE void riu_pulsetimerclear_setf(uint8_t pulsetimerclear)
{
    REG_PL_WR(RIU_RWNXAGCRADARTIM_ADDR, (REG_PL_RD(RIU_RWNXAGCRADARTIM_ADDR) & ~((uint32_t)0x80000000)) | ((uint32_t)pulsetimerclear << 31));
}

/**
 * @brief Returns the current value of the PULSEIRQFIFOTHR field in the RWNXAGCRADARTIM register.
 *
 * The RWNXAGCRADARTIM register will be read and the PULSEIRQFIFOTHR field's value will be returned.
 *
 * @return The current value of the PULSEIRQFIFOTHR field in the RWNXAGCRADARTIM register.
 */
__INLINE uint8_t riu_pulseirqfifothr_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCRADARTIM_ADDR);
    return ((localVal & ((uint32_t)0x00070000)) >> 16);
}

/**
 * @brief Sets the PULSEIRQFIFOTHR field of the RWNXAGCRADARTIM register.
 *
 * The RWNXAGCRADARTIM register will be read, modified to contain the new field value, and written.
 *
 * @param[in] pulseirqfifothr - The value to set the field to.
 */
__INLINE void riu_pulseirqfifothr_setf(uint8_t pulseirqfifothr)
{
    REG_PL_WR(RIU_RWNXAGCRADARTIM_ADDR, (REG_PL_RD(RIU_RWNXAGCRADARTIM_ADDR) & ~((uint32_t)0x00070000)) | ((uint32_t)pulseirqfifothr << 16));
}

/**
 * @brief Returns the current value of the PULSEIRQTIMEOUT field in the RWNXAGCRADARTIM register.
 *
 * The RWNXAGCRADARTIM register will be read and the PULSEIRQTIMEOUT field's value will be returned.
 *
 * @return The current value of the PULSEIRQTIMEOUT field in the RWNXAGCRADARTIM register.
 */
__INLINE uint8_t riu_pulseirqtimeout_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCRADARTIM_ADDR);
    return ((localVal & ((uint32_t)0x000000FF)) >> 0);
}

/**
 * @brief Sets the PULSEIRQTIMEOUT field of the RWNXAGCRADARTIM register.
 *
 * The RWNXAGCRADARTIM register will be read, modified to contain the new field value, and written.
 *
 * @param[in] pulseirqtimeout - The value to set the field to.
 */
__INLINE void riu_pulseirqtimeout_setf(uint8_t pulseirqtimeout)
{
    REG_PL_WR(RIU_RWNXAGCRADARTIM_ADDR, (REG_PL_RD(RIU_RWNXAGCRADARTIM_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)pulseirqtimeout << 0));
}

#endif // RW_RADAR_EN
/// @}

#if RW_RADAR_EN
/**
 * @name RWNXAGCDCCOMPRADAR register definitions
 * <table>
 * <caption id="RWNXAGCDCCOMPRADAR_BF">RWNXAGCDCCOMPRADAR bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>29:28 <td>       DCRADARTYPE <td>R <td>R/W <td>0x0
 * <tr><td>22:16 <td>DCRADARHOLDTIME50NS <td>R <td>R/W <td>0x8
 * <tr><td>14:08 <td>DCRADARZEROTIME50NS <td>R <td>R/W <td>0x0
 * </table>
 *
 * @{
 */

/// Address of the RWNXAGCDCCOMPRADAR register
#define RIU_RWNXAGCDCCOMPRADAR_ADDR   0x4033B3D0
/// Offset of the RWNXAGCDCCOMPRADAR register from the base address
#define RIU_RWNXAGCDCCOMPRADAR_OFFSET 0x000003D0
/// Index of the RWNXAGCDCCOMPRADAR register
#define RIU_RWNXAGCDCCOMPRADAR_INDEX  0x000000F4
/// Reset value of the RWNXAGCDCCOMPRADAR register
#define RIU_RWNXAGCDCCOMPRADAR_RESET  0x00080000

/**
 * @brief Returns the current value of the RWNXAGCDCCOMPRADAR register.
 * The RWNXAGCDCCOMPRADAR register will be read and its value returned.
 * @return The current value of the RWNXAGCDCCOMPRADAR register.
 */
__INLINE uint32_t riu_rwnxagcdccompradar_get(void)
{
    return REG_PL_RD(RIU_RWNXAGCDCCOMPRADAR_ADDR);
}

/**
 * @brief Sets the RWNXAGCDCCOMPRADAR register to a value.
 * The RWNXAGCDCCOMPRADAR register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxagcdccompradar_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXAGCDCCOMPRADAR_ADDR, value);
}

// field definitions
/// DCRADARTYPE field mask
#define RIU_DCRADARTYPE_MASK           ((uint32_t)0x30000000)
/// DCRADARTYPE field LSB position
#define RIU_DCRADARTYPE_LSB            28
/// DCRADARTYPE field width
#define RIU_DCRADARTYPE_WIDTH          ((uint32_t)0x00000002)
/// DCRADARHOLDTIME50NS field mask
#define RIU_DCRADARHOLDTIME50NS_MASK   ((uint32_t)0x007F0000)
/// DCRADARHOLDTIME50NS field LSB position
#define RIU_DCRADARHOLDTIME50NS_LSB    16
/// DCRADARHOLDTIME50NS field width
#define RIU_DCRADARHOLDTIME50NS_WIDTH  ((uint32_t)0x00000007)
/// DCRADARZEROTIME50NS field mask
#define RIU_DCRADARZEROTIME50NS_MASK   ((uint32_t)0x00007F00)
/// DCRADARZEROTIME50NS field LSB position
#define RIU_DCRADARZEROTIME50NS_LSB    8
/// DCRADARZEROTIME50NS field width
#define RIU_DCRADARZEROTIME50NS_WIDTH  ((uint32_t)0x00000007)

/// DCRADARTYPE field reset value
#define RIU_DCRADARTYPE_RST            0x0
/// DCRADARHOLDTIME50NS field reset value
#define RIU_DCRADARHOLDTIME50NS_RST    0x8
/// DCRADARZEROTIME50NS field reset value
#define RIU_DCRADARZEROTIME50NS_RST    0x0

/**
 * @brief Constructs a value for the RWNXAGCDCCOMPRADAR register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] dcradartype - The value to use for the DCRADARTYPE field.
 * @param[in] dcradarholdtime50ns - The value to use for the DCRADARHOLDTIME50NS field.
 * @param[in] dcradarzerotime50ns - The value to use for the DCRADARZEROTIME50NS field.
 */
__INLINE void riu_rwnxagcdccompradar_pack(uint8_t dcradartype, uint8_t dcradarholdtime50ns, uint8_t dcradarzerotime50ns)
{
    REG_PL_WR(RIU_RWNXAGCDCCOMPRADAR_ADDR,  ((uint32_t)dcradartype << 28) | ((uint32_t)dcradarholdtime50ns << 16) | ((uint32_t)dcradarzerotime50ns << 8));
}

/**
 * @brief Unpacks RWNXAGCDCCOMPRADAR's fields from current value of the RWNXAGCDCCOMPRADAR register.
 *
 * Reads the RWNXAGCDCCOMPRADAR register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] dcradartype - Will be populated with the current value of this field from the register.
 * @param[out] dcradarholdtime50ns - Will be populated with the current value of this field from the register.
 * @param[out] dcradarzerotime50ns - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxagcdccompradar_unpack(uint8_t* dcradartype, uint8_t* dcradarholdtime50ns, uint8_t* dcradarzerotime50ns)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCDCCOMPRADAR_ADDR);

    *dcradartype = (localVal & ((uint32_t)0x30000000)) >> 28;
    *dcradarholdtime50ns = (localVal & ((uint32_t)0x007F0000)) >> 16;
    *dcradarzerotime50ns = (localVal & ((uint32_t)0x00007F00)) >> 8;
}

/**
 * @brief Returns the current value of the DCRADARTYPE field in the RWNXAGCDCCOMPRADAR register.
 *
 * The RWNXAGCDCCOMPRADAR register will be read and the DCRADARTYPE field's value will be returned.
 *
 * @return The current value of the DCRADARTYPE field in the RWNXAGCDCCOMPRADAR register.
 */
__INLINE uint8_t riu_dcradartype_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCDCCOMPRADAR_ADDR);
    return ((localVal & ((uint32_t)0x30000000)) >> 28);
}

/**
 * @brief Sets the DCRADARTYPE field of the RWNXAGCDCCOMPRADAR register.
 *
 * The RWNXAGCDCCOMPRADAR register will be read, modified to contain the new field value, and written.
 *
 * @param[in] dcradartype - The value to set the field to.
 */
__INLINE void riu_dcradartype_setf(uint8_t dcradartype)
{
    REG_PL_WR(RIU_RWNXAGCDCCOMPRADAR_ADDR, (REG_PL_RD(RIU_RWNXAGCDCCOMPRADAR_ADDR) & ~((uint32_t)0x30000000)) | ((uint32_t)dcradartype << 28));
}

/**
 * @brief Returns the current value of the DCRADARHOLDTIME50NS field in the RWNXAGCDCCOMPRADAR register.
 *
 * The RWNXAGCDCCOMPRADAR register will be read and the DCRADARHOLDTIME50NS field's value will be returned.
 *
 * @return The current value of the DCRADARHOLDTIME50NS field in the RWNXAGCDCCOMPRADAR register.
 */
__INLINE uint8_t riu_dcradarholdtime50ns_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCDCCOMPRADAR_ADDR);
    return ((localVal & ((uint32_t)0x007F0000)) >> 16);
}

/**
 * @brief Sets the DCRADARHOLDTIME50NS field of the RWNXAGCDCCOMPRADAR register.
 *
 * The RWNXAGCDCCOMPRADAR register will be read, modified to contain the new field value, and written.
 *
 * @param[in] dcradarholdtime50ns - The value to set the field to.
 */
__INLINE void riu_dcradarholdtime50ns_setf(uint8_t dcradarholdtime50ns)
{
    REG_PL_WR(RIU_RWNXAGCDCCOMPRADAR_ADDR, (REG_PL_RD(RIU_RWNXAGCDCCOMPRADAR_ADDR) & ~((uint32_t)0x007F0000)) | ((uint32_t)dcradarholdtime50ns << 16));
}

/**
 * @brief Returns the current value of the DCRADARZEROTIME50NS field in the RWNXAGCDCCOMPRADAR register.
 *
 * The RWNXAGCDCCOMPRADAR register will be read and the DCRADARZEROTIME50NS field's value will be returned.
 *
 * @return The current value of the DCRADARZEROTIME50NS field in the RWNXAGCDCCOMPRADAR register.
 */
__INLINE uint8_t riu_dcradarzerotime50ns_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCDCCOMPRADAR_ADDR);
    return ((localVal & ((uint32_t)0x00007F00)) >> 8);
}

/**
 * @brief Sets the DCRADARZEROTIME50NS field of the RWNXAGCDCCOMPRADAR register.
 *
 * The RWNXAGCDCCOMPRADAR register will be read, modified to contain the new field value, and written.
 *
 * @param[in] dcradarzerotime50ns - The value to set the field to.
 */
__INLINE void riu_dcradarzerotime50ns_setf(uint8_t dcradarzerotime50ns)
{
    REG_PL_WR(RIU_RWNXAGCDCCOMPRADAR_ADDR, (REG_PL_RD(RIU_RWNXAGCDCCOMPRADAR_ADDR) & ~((uint32_t)0x00007F00)) | ((uint32_t)dcradarzerotime50ns << 8));
}

#endif // RW_RADAR_EN
/// @}

/**
 * @name RWNXAGCCCA2 register definitions
 * <table>
 * <caption id="RWNXAGCCCA2_BF">RWNXAGCCCA2 bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>28:20 <td>INBDCCA20SPOWMINDBM <td>R <td>R/W <td>0x1B0
 * <tr><td>19:12 <td>  CCA20SFALLTHRDBM <td>R <td>R/W <td>0xB5
 * <tr><td>07:00 <td>  CCA20SRISETHRDBM <td>R <td>R/W <td>0xB8
 * </table>
 *
 * @{
 */

/// Address of the RWNXAGCCCA2 register
#define RIU_RWNXAGCCCA2_ADDR   0x4033B3D4
/// Offset of the RWNXAGCCCA2 register from the base address
#define RIU_RWNXAGCCCA2_OFFSET 0x000003D4
/// Index of the RWNXAGCCCA2 register
#define RIU_RWNXAGCCCA2_INDEX  0x000000F5
/// Reset value of the RWNXAGCCCA2 register
#define RIU_RWNXAGCCCA2_RESET  0x1B0B50B8

/**
 * @brief Returns the current value of the RWNXAGCCCA2 register.
 * The RWNXAGCCCA2 register will be read and its value returned.
 * @return The current value of the RWNXAGCCCA2 register.
 */
__INLINE uint32_t riu_rwnxagccca2_get(void)
{
    return REG_PL_RD(RIU_RWNXAGCCCA2_ADDR);
}

/**
 * @brief Sets the RWNXAGCCCA2 register to a value.
 * The RWNXAGCCCA2 register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxagccca2_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXAGCCCA2_ADDR, value);
}

// field definitions
/// INBDCCA20SPOWMINDBM field mask
#define RIU_INBDCCA20SPOWMINDBM_MASK   ((uint32_t)0x1FF00000)
/// INBDCCA20SPOWMINDBM field LSB position
#define RIU_INBDCCA20SPOWMINDBM_LSB    20
/// INBDCCA20SPOWMINDBM field width
#define RIU_INBDCCA20SPOWMINDBM_WIDTH  ((uint32_t)0x00000009)
/// CCA20SFALLTHRDBM field mask
#define RIU_CCA20SFALLTHRDBM_MASK      ((uint32_t)0x000FF000)
/// CCA20SFALLTHRDBM field LSB position
#define RIU_CCA20SFALLTHRDBM_LSB       12
/// CCA20SFALLTHRDBM field width
#define RIU_CCA20SFALLTHRDBM_WIDTH     ((uint32_t)0x00000008)
/// CCA20SRISETHRDBM field mask
#define RIU_CCA20SRISETHRDBM_MASK      ((uint32_t)0x000000FF)
/// CCA20SRISETHRDBM field LSB position
#define RIU_CCA20SRISETHRDBM_LSB       0
/// CCA20SRISETHRDBM field width
#define RIU_CCA20SRISETHRDBM_WIDTH     ((uint32_t)0x00000008)

/// INBDCCA20SPOWMINDBM field reset value
#define RIU_INBDCCA20SPOWMINDBM_RST    0x1B0
/// CCA20SFALLTHRDBM field reset value
#define RIU_CCA20SFALLTHRDBM_RST       0xB5
/// CCA20SRISETHRDBM field reset value
#define RIU_CCA20SRISETHRDBM_RST       0xB8

/**
 * @brief Constructs a value for the RWNXAGCCCA2 register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] inbdcca20spowmindbm - The value to use for the INBDCCA20SPOWMINDBM field.
 * @param[in] cca20sfallthrdbm - The value to use for the CCA20SFALLTHRDBM field.
 * @param[in] cca20srisethrdbm - The value to use for the CCA20SRISETHRDBM field.
 */
__INLINE void riu_rwnxagccca2_pack(uint16_t inbdcca20spowmindbm, uint8_t cca20sfallthrdbm, uint8_t cca20srisethrdbm)
{
    REG_PL_WR(RIU_RWNXAGCCCA2_ADDR,  ((uint32_t)inbdcca20spowmindbm << 20) | ((uint32_t)cca20sfallthrdbm << 12) | ((uint32_t)cca20srisethrdbm << 0));
}

/**
 * @brief Unpacks RWNXAGCCCA2's fields from current value of the RWNXAGCCCA2 register.
 *
 * Reads the RWNXAGCCCA2 register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] inbdcca20spowmindbm - Will be populated with the current value of this field from the register.
 * @param[out] cca20sfallthrdbm - Will be populated with the current value of this field from the register.
 * @param[out] cca20srisethrdbm - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxagccca2_unpack(uint16_t* inbdcca20spowmindbm, uint8_t* cca20sfallthrdbm, uint8_t* cca20srisethrdbm)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCCCA2_ADDR);

    *inbdcca20spowmindbm = (localVal & ((uint32_t)0x1FF00000)) >> 20;
    *cca20sfallthrdbm = (localVal & ((uint32_t)0x000FF000)) >> 12;
    *cca20srisethrdbm = (localVal & ((uint32_t)0x000000FF)) >> 0;
}

/**
 * @brief Returns the current value of the INBDCCA20SPOWMINDBM field in the RWNXAGCCCA2 register.
 *
 * The RWNXAGCCCA2 register will be read and the INBDCCA20SPOWMINDBM field's value will be returned.
 *
 * @return The current value of the INBDCCA20SPOWMINDBM field in the RWNXAGCCCA2 register.
 */
__INLINE uint16_t riu_inbdcca20spowmindbm_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCCCA2_ADDR);
    return ((localVal & ((uint32_t)0x1FF00000)) >> 20);
}

/**
 * @brief Sets the INBDCCA20SPOWMINDBM field of the RWNXAGCCCA2 register.
 *
 * The RWNXAGCCCA2 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] inbdcca20spowmindbm - The value to set the field to.
 */
__INLINE void riu_inbdcca20spowmindbm_setf(uint16_t inbdcca20spowmindbm)
{
    REG_PL_WR(RIU_RWNXAGCCCA2_ADDR, (REG_PL_RD(RIU_RWNXAGCCCA2_ADDR) & ~((uint32_t)0x1FF00000)) | ((uint32_t)inbdcca20spowmindbm << 20));
}

/**
 * @brief Returns the current value of the CCA20SFALLTHRDBM field in the RWNXAGCCCA2 register.
 *
 * The RWNXAGCCCA2 register will be read and the CCA20SFALLTHRDBM field's value will be returned.
 *
 * @return The current value of the CCA20SFALLTHRDBM field in the RWNXAGCCCA2 register.
 */
__INLINE uint8_t riu_cca20sfallthrdbm_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCCCA2_ADDR);
    return ((localVal & ((uint32_t)0x000FF000)) >> 12);
}

/**
 * @brief Sets the CCA20SFALLTHRDBM field of the RWNXAGCCCA2 register.
 *
 * The RWNXAGCCCA2 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] cca20sfallthrdbm - The value to set the field to.
 */
__INLINE void riu_cca20sfallthrdbm_setf(uint8_t cca20sfallthrdbm)
{
    REG_PL_WR(RIU_RWNXAGCCCA2_ADDR, (REG_PL_RD(RIU_RWNXAGCCCA2_ADDR) & ~((uint32_t)0x000FF000)) | ((uint32_t)cca20sfallthrdbm << 12));
}

/**
 * @brief Returns the current value of the CCA20SRISETHRDBM field in the RWNXAGCCCA2 register.
 *
 * The RWNXAGCCCA2 register will be read and the CCA20SRISETHRDBM field's value will be returned.
 *
 * @return The current value of the CCA20SRISETHRDBM field in the RWNXAGCCCA2 register.
 */
__INLINE uint8_t riu_cca20srisethrdbm_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCCCA2_ADDR);
    return ((localVal & ((uint32_t)0x000000FF)) >> 0);
}

/**
 * @brief Sets the CCA20SRISETHRDBM field of the RWNXAGCCCA2 register.
 *
 * The RWNXAGCCCA2 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] cca20srisethrdbm - The value to set the field to.
 */
__INLINE void riu_cca20srisethrdbm_setf(uint8_t cca20srisethrdbm)
{
    REG_PL_WR(RIU_RWNXAGCCCA2_ADDR, (REG_PL_RD(RIU_RWNXAGCCCA2_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)cca20srisethrdbm << 0));
}

/// @}

/**
 * @name RWNXAGCCCA3 register definitions
 * <table>
 * <caption id="RWNXAGCCCA3_BF">RWNXAGCCCA3 bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>28:20 <td>INBDCCA40SPOWMINDBM <td>R <td>R/W <td>0x1B0
 * <tr><td>19:12 <td>  CCA40SFALLTHRDBM <td>R <td>R/W <td>0xB5
 * <tr><td>07:00 <td>  CCA40SRISETHRDBM <td>R <td>R/W <td>0xB8
 * </table>
 *
 * @{
 */

/// Address of the RWNXAGCCCA3 register
#define RIU_RWNXAGCCCA3_ADDR   0x4033B3D8
/// Offset of the RWNXAGCCCA3 register from the base address
#define RIU_RWNXAGCCCA3_OFFSET 0x000003D8
/// Index of the RWNXAGCCCA3 register
#define RIU_RWNXAGCCCA3_INDEX  0x000000F6
/// Reset value of the RWNXAGCCCA3 register
#define RIU_RWNXAGCCCA3_RESET  0x1B0B50B8

/**
 * @brief Returns the current value of the RWNXAGCCCA3 register.
 * The RWNXAGCCCA3 register will be read and its value returned.
 * @return The current value of the RWNXAGCCCA3 register.
 */
__INLINE uint32_t riu_rwnxagccca3_get(void)
{
    return REG_PL_RD(RIU_RWNXAGCCCA3_ADDR);
}

/**
 * @brief Sets the RWNXAGCCCA3 register to a value.
 * The RWNXAGCCCA3 register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxagccca3_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXAGCCCA3_ADDR, value);
}

// field definitions
/// INBDCCA40SPOWMINDBM field mask
#define RIU_INBDCCA40SPOWMINDBM_MASK   ((uint32_t)0x1FF00000)
/// INBDCCA40SPOWMINDBM field LSB position
#define RIU_INBDCCA40SPOWMINDBM_LSB    20
/// INBDCCA40SPOWMINDBM field width
#define RIU_INBDCCA40SPOWMINDBM_WIDTH  ((uint32_t)0x00000009)
/// CCA40SFALLTHRDBM field mask
#define RIU_CCA40SFALLTHRDBM_MASK      ((uint32_t)0x000FF000)
/// CCA40SFALLTHRDBM field LSB position
#define RIU_CCA40SFALLTHRDBM_LSB       12
/// CCA40SFALLTHRDBM field width
#define RIU_CCA40SFALLTHRDBM_WIDTH     ((uint32_t)0x00000008)
/// CCA40SRISETHRDBM field mask
#define RIU_CCA40SRISETHRDBM_MASK      ((uint32_t)0x000000FF)
/// CCA40SRISETHRDBM field LSB position
#define RIU_CCA40SRISETHRDBM_LSB       0
/// CCA40SRISETHRDBM field width
#define RIU_CCA40SRISETHRDBM_WIDTH     ((uint32_t)0x00000008)

/// INBDCCA40SPOWMINDBM field reset value
#define RIU_INBDCCA40SPOWMINDBM_RST    0x1B0
/// CCA40SFALLTHRDBM field reset value
#define RIU_CCA40SFALLTHRDBM_RST       0xB5
/// CCA40SRISETHRDBM field reset value
#define RIU_CCA40SRISETHRDBM_RST       0xB8

/**
 * @brief Constructs a value for the RWNXAGCCCA3 register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] inbdcca40spowmindbm - The value to use for the INBDCCA40SPOWMINDBM field.
 * @param[in] cca40sfallthrdbm - The value to use for the CCA40SFALLTHRDBM field.
 * @param[in] cca40srisethrdbm - The value to use for the CCA40SRISETHRDBM field.
 */
__INLINE void riu_rwnxagccca3_pack(uint16_t inbdcca40spowmindbm, uint8_t cca40sfallthrdbm, uint8_t cca40srisethrdbm)
{
    REG_PL_WR(RIU_RWNXAGCCCA3_ADDR,  ((uint32_t)inbdcca40spowmindbm << 20) | ((uint32_t)cca40sfallthrdbm << 12) | ((uint32_t)cca40srisethrdbm << 0));
}

/**
 * @brief Unpacks RWNXAGCCCA3's fields from current value of the RWNXAGCCCA3 register.
 *
 * Reads the RWNXAGCCCA3 register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] inbdcca40spowmindbm - Will be populated with the current value of this field from the register.
 * @param[out] cca40sfallthrdbm - Will be populated with the current value of this field from the register.
 * @param[out] cca40srisethrdbm - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxagccca3_unpack(uint16_t* inbdcca40spowmindbm, uint8_t* cca40sfallthrdbm, uint8_t* cca40srisethrdbm)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCCCA3_ADDR);

    *inbdcca40spowmindbm = (localVal & ((uint32_t)0x1FF00000)) >> 20;
    *cca40sfallthrdbm = (localVal & ((uint32_t)0x000FF000)) >> 12;
    *cca40srisethrdbm = (localVal & ((uint32_t)0x000000FF)) >> 0;
}

/**
 * @brief Returns the current value of the INBDCCA40SPOWMINDBM field in the RWNXAGCCCA3 register.
 *
 * The RWNXAGCCCA3 register will be read and the INBDCCA40SPOWMINDBM field's value will be returned.
 *
 * @return The current value of the INBDCCA40SPOWMINDBM field in the RWNXAGCCCA3 register.
 */
__INLINE uint16_t riu_inbdcca40spowmindbm_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCCCA3_ADDR);
    return ((localVal & ((uint32_t)0x1FF00000)) >> 20);
}

/**
 * @brief Sets the INBDCCA40SPOWMINDBM field of the RWNXAGCCCA3 register.
 *
 * The RWNXAGCCCA3 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] inbdcca40spowmindbm - The value to set the field to.
 */
__INLINE void riu_inbdcca40spowmindbm_setf(uint16_t inbdcca40spowmindbm)
{
    REG_PL_WR(RIU_RWNXAGCCCA3_ADDR, (REG_PL_RD(RIU_RWNXAGCCCA3_ADDR) & ~((uint32_t)0x1FF00000)) | ((uint32_t)inbdcca40spowmindbm << 20));
}

/**
 * @brief Returns the current value of the CCA40SFALLTHRDBM field in the RWNXAGCCCA3 register.
 *
 * The RWNXAGCCCA3 register will be read and the CCA40SFALLTHRDBM field's value will be returned.
 *
 * @return The current value of the CCA40SFALLTHRDBM field in the RWNXAGCCCA3 register.
 */
__INLINE uint8_t riu_cca40sfallthrdbm_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCCCA3_ADDR);
    return ((localVal & ((uint32_t)0x000FF000)) >> 12);
}

/**
 * @brief Sets the CCA40SFALLTHRDBM field of the RWNXAGCCCA3 register.
 *
 * The RWNXAGCCCA3 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] cca40sfallthrdbm - The value to set the field to.
 */
__INLINE void riu_cca40sfallthrdbm_setf(uint8_t cca40sfallthrdbm)
{
    REG_PL_WR(RIU_RWNXAGCCCA3_ADDR, (REG_PL_RD(RIU_RWNXAGCCCA3_ADDR) & ~((uint32_t)0x000FF000)) | ((uint32_t)cca40sfallthrdbm << 12));
}

/**
 * @brief Returns the current value of the CCA40SRISETHRDBM field in the RWNXAGCCCA3 register.
 *
 * The RWNXAGCCCA3 register will be read and the CCA40SRISETHRDBM field's value will be returned.
 *
 * @return The current value of the CCA40SRISETHRDBM field in the RWNXAGCCCA3 register.
 */
__INLINE uint8_t riu_cca40srisethrdbm_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXAGCCCA3_ADDR);
    return ((localVal & ((uint32_t)0x000000FF)) >> 0);
}

/**
 * @brief Sets the CCA40SRISETHRDBM field of the RWNXAGCCCA3 register.
 *
 * The RWNXAGCCCA3 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] cca40srisethrdbm - The value to set the field to.
 */
__INLINE void riu_cca40srisethrdbm_setf(uint8_t cca40srisethrdbm)
{
    REG_PL_WR(RIU_RWNXAGCCCA3_ADDR, (REG_PL_RD(RIU_RWNXAGCCCA3_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)cca40srisethrdbm << 0));
}

/// @}

/**
 * @name RWNXMACINTEN register definitions
 * <table>
 * <caption id="RWNXMACINTEN_BF">RWNXMACINTEN bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>12 <td>  IRQMACRADARDETEN <td>R <td>R/W <td>0
 * <tr><td>08 <td>IRQMACCCATIMEOUTEN <td>R <td>R/W <td>0
 * </table>
 *
 * @{
 */

/// Address of the RWNXMACINTEN register
#define RIU_RWNXMACINTEN_ADDR   0x4033B414
/// Offset of the RWNXMACINTEN register from the base address
#define RIU_RWNXMACINTEN_OFFSET 0x00000414
/// Index of the RWNXMACINTEN register
#define RIU_RWNXMACINTEN_INDEX  0x00000105
/// Reset value of the RWNXMACINTEN register
#define RIU_RWNXMACINTEN_RESET  0x00000000

/**
 * @brief Returns the current value of the RWNXMACINTEN register.
 * The RWNXMACINTEN register will be read and its value returned.
 * @return The current value of the RWNXMACINTEN register.
 */
__INLINE uint32_t riu_rwnxmacinten_get(void)
{
    return REG_PL_RD(RIU_RWNXMACINTEN_ADDR);
}

/**
 * @brief Sets the RWNXMACINTEN register to a value.
 * The RWNXMACINTEN register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxmacinten_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXMACINTEN_ADDR, value);
}

// field definitions
/// IRQMACRADARDETEN field bit
#define RIU_IRQMACRADARDETEN_BIT      ((uint32_t)0x00001000)
/// IRQMACRADARDETEN field position
#define RIU_IRQMACRADARDETEN_POS      12
/// IRQMACCCATIMEOUTEN field bit
#define RIU_IRQMACCCATIMEOUTEN_BIT    ((uint32_t)0x00000100)
/// IRQMACCCATIMEOUTEN field position
#define RIU_IRQMACCCATIMEOUTEN_POS    8

/// IRQMACRADARDETEN field reset value
#define RIU_IRQMACRADARDETEN_RST      0x0
/// IRQMACCCATIMEOUTEN field reset value
#define RIU_IRQMACCCATIMEOUTEN_RST    0x0

/**
 * @brief Constructs a value for the RWNXMACINTEN register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] irqmacradardeten - The value to use for the IRQMACRADARDETEN field.
 * @param[in] irqmacccatimeouten - The value to use for the IRQMACCCATIMEOUTEN field.
 */
__INLINE void riu_rwnxmacinten_pack(uint8_t irqmacradardeten, uint8_t irqmacccatimeouten)
{
    REG_PL_WR(RIU_RWNXMACINTEN_ADDR,  ((uint32_t)irqmacradardeten << 12) | ((uint32_t)irqmacccatimeouten << 8));
}

/**
 * @brief Unpacks RWNXMACINTEN's fields from current value of the RWNXMACINTEN register.
 *
 * Reads the RWNXMACINTEN register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] irqmacradardeten - Will be populated with the current value of this field from the register.
 * @param[out] irqmacccatimeouten - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxmacinten_unpack(uint8_t* irqmacradardeten, uint8_t* irqmacccatimeouten)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXMACINTEN_ADDR);

    *irqmacradardeten = (localVal & ((uint32_t)0x00001000)) >> 12;
    *irqmacccatimeouten = (localVal & ((uint32_t)0x00000100)) >> 8;
}

/**
 * @brief Returns the current value of the IRQMACRADARDETEN field in the RWNXMACINTEN register.
 *
 * The RWNXMACINTEN register will be read and the IRQMACRADARDETEN field's value will be returned.
 *
 * @return The current value of the IRQMACRADARDETEN field in the RWNXMACINTEN register.
 */
__INLINE uint8_t riu_irqmacradardeten_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXMACINTEN_ADDR);
    return ((localVal & ((uint32_t)0x00001000)) >> 12);
}

/**
 * @brief Sets the IRQMACRADARDETEN field of the RWNXMACINTEN register.
 *
 * The RWNXMACINTEN register will be read, modified to contain the new field value, and written.
 *
 * @param[in] irqmacradardeten - The value to set the field to.
 */
__INLINE void riu_irqmacradardeten_setf(uint8_t irqmacradardeten)
{
    REG_PL_WR(RIU_RWNXMACINTEN_ADDR, (REG_PL_RD(RIU_RWNXMACINTEN_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)irqmacradardeten << 12));
}

/**
 * @brief Returns the current value of the IRQMACCCATIMEOUTEN field in the RWNXMACINTEN register.
 *
 * The RWNXMACINTEN register will be read and the IRQMACCCATIMEOUTEN field's value will be returned.
 *
 * @return The current value of the IRQMACCCATIMEOUTEN field in the RWNXMACINTEN register.
 */
__INLINE uint8_t riu_irqmacccatimeouten_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXMACINTEN_ADDR);
    return ((localVal & ((uint32_t)0x00000100)) >> 8);
}

/**
 * @brief Sets the IRQMACCCATIMEOUTEN field of the RWNXMACINTEN register.
 *
 * The RWNXMACINTEN register will be read, modified to contain the new field value, and written.
 *
 * @param[in] irqmacccatimeouten - The value to set the field to.
 */
__INLINE void riu_irqmacccatimeouten_setf(uint8_t irqmacccatimeouten)
{
    REG_PL_WR(RIU_RWNXMACINTEN_ADDR, (REG_PL_RD(RIU_RWNXMACINTEN_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)irqmacccatimeouten << 8));
}

/// @}

/**
 * @name RWNXMACINTSTATRAW register definitions
 * <table>
 * <caption id="RWNXMACINTSTATRAW_BF">RWNXMACINTSTATRAW bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>12 <td> IRQMACRADARDETRAW <td>W <td>R <td>0
 * <tr><td>08 <td>IRQMACCCATIMEOUTRAW <td>W <td>R <td>0
 * </table>
 *
 * @{
 */

/// Address of the RWNXMACINTSTATRAW register
#define RIU_RWNXMACINTSTATRAW_ADDR   0x4033B418
/// Offset of the RWNXMACINTSTATRAW register from the base address
#define RIU_RWNXMACINTSTATRAW_OFFSET 0x00000418
/// Index of the RWNXMACINTSTATRAW register
#define RIU_RWNXMACINTSTATRAW_INDEX  0x00000106
/// Reset value of the RWNXMACINTSTATRAW register
#define RIU_RWNXMACINTSTATRAW_RESET  0x00000000

/**
 * @brief Returns the current value of the RWNXMACINTSTATRAW register.
 * The RWNXMACINTSTATRAW register will be read and its value returned.
 * @return The current value of the RWNXMACINTSTATRAW register.
 */
__INLINE uint32_t riu_rwnxmacintstatraw_get(void)
{
    return REG_PL_RD(RIU_RWNXMACINTSTATRAW_ADDR);
}

// field definitions
/// IRQMACRADARDETRAW field bit
#define RIU_IRQMACRADARDETRAW_BIT      ((uint32_t)0x00001000)
/// IRQMACRADARDETRAW field position
#define RIU_IRQMACRADARDETRAW_POS      12
/// IRQMACCCATIMEOUTRAW field bit
#define RIU_IRQMACCCATIMEOUTRAW_BIT    ((uint32_t)0x00000100)
/// IRQMACCCATIMEOUTRAW field position
#define RIU_IRQMACCCATIMEOUTRAW_POS    8

/// IRQMACRADARDETRAW field reset value
#define RIU_IRQMACRADARDETRAW_RST      0x0
/// IRQMACCCATIMEOUTRAW field reset value
#define RIU_IRQMACCCATIMEOUTRAW_RST    0x0

/**
 * @brief Unpacks RWNXMACINTSTATRAW's fields from current value of the RWNXMACINTSTATRAW register.
 *
 * Reads the RWNXMACINTSTATRAW register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] irqmacradardetraw - Will be populated with the current value of this field from the register.
 * @param[out] irqmacccatimeoutraw - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxmacintstatraw_unpack(uint8_t* irqmacradardetraw, uint8_t* irqmacccatimeoutraw)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXMACINTSTATRAW_ADDR);

    *irqmacradardetraw = (localVal & ((uint32_t)0x00001000)) >> 12;
    *irqmacccatimeoutraw = (localVal & ((uint32_t)0x00000100)) >> 8;
}

/**
 * @brief Returns the current value of the IRQMACRADARDETRAW field in the RWNXMACINTSTATRAW register.
 *
 * The RWNXMACINTSTATRAW register will be read and the IRQMACRADARDETRAW field's value will be returned.
 *
 * @return The current value of the IRQMACRADARDETRAW field in the RWNXMACINTSTATRAW register.
 */
__INLINE uint8_t riu_irqmacradardetraw_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXMACINTSTATRAW_ADDR);
    return ((localVal & ((uint32_t)0x00001000)) >> 12);
}

/**
 * @brief Returns the current value of the IRQMACCCATIMEOUTRAW field in the RWNXMACINTSTATRAW register.
 *
 * The RWNXMACINTSTATRAW register will be read and the IRQMACCCATIMEOUTRAW field's value will be returned.
 *
 * @return The current value of the IRQMACCCATIMEOUTRAW field in the RWNXMACINTSTATRAW register.
 */
__INLINE uint8_t riu_irqmacccatimeoutraw_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXMACINTSTATRAW_ADDR);
    return ((localVal & ((uint32_t)0x00000100)) >> 8);
}

/// @}

/**
 * @name RWNXMACINTSTATMASKED register definitions
 * <table>
 * <caption id="RWNXMACINTSTATMASKED_BF">RWNXMACINTSTATMASKED bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>12 <td>IRQMACRADARDETMASKED <td>W <td>R <td>0
 * <tr><td>08 <td>IRQMACCCATIMEOUTMASKED <td>W <td>R <td>0
 * </table>
 *
 * @{
 */

/// Address of the RWNXMACINTSTATMASKED register
#define RIU_RWNXMACINTSTATMASKED_ADDR   0x4033B41C
/// Offset of the RWNXMACINTSTATMASKED register from the base address
#define RIU_RWNXMACINTSTATMASKED_OFFSET 0x0000041C
/// Index of the RWNXMACINTSTATMASKED register
#define RIU_RWNXMACINTSTATMASKED_INDEX  0x00000107
/// Reset value of the RWNXMACINTSTATMASKED register
#define RIU_RWNXMACINTSTATMASKED_RESET  0x00000000

/**
 * @brief Returns the current value of the RWNXMACINTSTATMASKED register.
 * The RWNXMACINTSTATMASKED register will be read and its value returned.
 * @return The current value of the RWNXMACINTSTATMASKED register.
 */
__INLINE uint32_t riu_rwnxmacintstatmasked_get(void)
{
    return REG_PL_RD(RIU_RWNXMACINTSTATMASKED_ADDR);
}

// field definitions
/// IRQMACRADARDETMASKED field bit
#define RIU_IRQMACRADARDETMASKED_BIT      ((uint32_t)0x00001000)
/// IRQMACRADARDETMASKED field position
#define RIU_IRQMACRADARDETMASKED_POS      12
/// IRQMACCCATIMEOUTMASKED field bit
#define RIU_IRQMACCCATIMEOUTMASKED_BIT    ((uint32_t)0x00000100)
/// IRQMACCCATIMEOUTMASKED field position
#define RIU_IRQMACCCATIMEOUTMASKED_POS    8

/// IRQMACRADARDETMASKED field reset value
#define RIU_IRQMACRADARDETMASKED_RST      0x0
/// IRQMACCCATIMEOUTMASKED field reset value
#define RIU_IRQMACCCATIMEOUTMASKED_RST    0x0

/**
 * @brief Unpacks RWNXMACINTSTATMASKED's fields from current value of the RWNXMACINTSTATMASKED register.
 *
 * Reads the RWNXMACINTSTATMASKED register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] irqmacradardetmasked - Will be populated with the current value of this field from the register.
 * @param[out] irqmacccatimeoutmasked - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxmacintstatmasked_unpack(uint8_t* irqmacradardetmasked, uint8_t* irqmacccatimeoutmasked)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXMACINTSTATMASKED_ADDR);

    *irqmacradardetmasked = (localVal & ((uint32_t)0x00001000)) >> 12;
    *irqmacccatimeoutmasked = (localVal & ((uint32_t)0x00000100)) >> 8;
}

/**
 * @brief Returns the current value of the IRQMACRADARDETMASKED field in the RWNXMACINTSTATMASKED register.
 *
 * The RWNXMACINTSTATMASKED register will be read and the IRQMACRADARDETMASKED field's value will be returned.
 *
 * @return The current value of the IRQMACRADARDETMASKED field in the RWNXMACINTSTATMASKED register.
 */
__INLINE uint8_t riu_irqmacradardetmasked_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXMACINTSTATMASKED_ADDR);
    return ((localVal & ((uint32_t)0x00001000)) >> 12);
}

/**
 * @brief Returns the current value of the IRQMACCCATIMEOUTMASKED field in the RWNXMACINTSTATMASKED register.
 *
 * The RWNXMACINTSTATMASKED register will be read and the IRQMACCCATIMEOUTMASKED field's value will be returned.
 *
 * @return The current value of the IRQMACCCATIMEOUTMASKED field in the RWNXMACINTSTATMASKED register.
 */
__INLINE uint8_t riu_irqmacccatimeoutmasked_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXMACINTSTATMASKED_ADDR);
    return ((localVal & ((uint32_t)0x00000100)) >> 8);
}

/// @}

/**
 * @name RWNXMACINTACK register definitions
 * <table>
 * <caption id="RWNXMACINTACK_BF">RWNXMACINTACK bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>12 <td> IRQMACRADARDETACK <td>R <td>C <td>0
 * <tr><td>08 <td>IRQMACCCATIMEOUTACK <td>R <td>C <td>0
 * </table>
 *
 * @{
 */

/// Address of the RWNXMACINTACK register
#define RIU_RWNXMACINTACK_ADDR   0x4033B420
/// Offset of the RWNXMACINTACK register from the base address
#define RIU_RWNXMACINTACK_OFFSET 0x00000420
/// Index of the RWNXMACINTACK register
#define RIU_RWNXMACINTACK_INDEX  0x00000108
/// Reset value of the RWNXMACINTACK register
#define RIU_RWNXMACINTACK_RESET  0x00000000

/**
 * @brief Returns the current value of the RWNXMACINTACK register.
 * The RWNXMACINTACK register will be read and its value returned.
 * @return The current value of the RWNXMACINTACK register.
 */
__INLINE uint32_t riu_rwnxmacintack_get(void)
{
    return REG_PL_RD(RIU_RWNXMACINTACK_ADDR);
}

/**
 * @brief Sets the RWNXMACINTACK register to a value.
 * The RWNXMACINTACK register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxmacintack_clear(uint32_t value)
{
    REG_PL_WR(RIU_RWNXMACINTACK_ADDR, value);
}

// field definitions
/// IRQMACRADARDETACK field bit
#define RIU_IRQMACRADARDETACK_BIT      ((uint32_t)0x00001000)
/// IRQMACRADARDETACK field position
#define RIU_IRQMACRADARDETACK_POS      12
/// IRQMACCCATIMEOUTACK field bit
#define RIU_IRQMACCCATIMEOUTACK_BIT    ((uint32_t)0x00000100)
/// IRQMACCCATIMEOUTACK field position
#define RIU_IRQMACCCATIMEOUTACK_POS    8

/// IRQMACRADARDETACK field reset value
#define RIU_IRQMACRADARDETACK_RST      0x0
/// IRQMACCCATIMEOUTACK field reset value
#define RIU_IRQMACCCATIMEOUTACK_RST    0x0

/**
 * @brief Constructs a value for the RWNXMACINTACK register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] irqmacradardetack - The value to use for the IRQMACRADARDETACK field.
 * @param[in] irqmacccatimeoutack - The value to use for the IRQMACCCATIMEOUTACK field.
 */
__INLINE void riu_rwnxmacintack_pack(uint8_t irqmacradardetack, uint8_t irqmacccatimeoutack)
{
    REG_PL_WR(RIU_RWNXMACINTACK_ADDR,  ((uint32_t)irqmacradardetack << 12) | ((uint32_t)irqmacccatimeoutack << 8));
}

/**
 * @brief Unpacks RWNXMACINTACK's fields from current value of the RWNXMACINTACK register.
 *
 * Reads the RWNXMACINTACK register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] irqmacradardetack - Will be populated with the current value of this field from the register.
 * @param[out] irqmacccatimeoutack - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxmacintack_unpack(uint8_t* irqmacradardetack, uint8_t* irqmacccatimeoutack)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXMACINTACK_ADDR);

    *irqmacradardetack = (localVal & ((uint32_t)0x00001000)) >> 12;
    *irqmacccatimeoutack = (localVal & ((uint32_t)0x00000100)) >> 8;
}

/**
 * @brief Returns the current value of the IRQMACRADARDETACK field in the RWNXMACINTACK register.
 *
 * The RWNXMACINTACK register will be read and the IRQMACRADARDETACK field's value will be returned.
 *
 * @return The current value of the IRQMACRADARDETACK field in the RWNXMACINTACK register.
 */
__INLINE uint8_t riu_irqmacradardetack_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXMACINTACK_ADDR);
    return ((localVal & ((uint32_t)0x00001000)) >> 12);
}

/**
 * @brief Sets the IRQMACRADARDETACK field of the RWNXMACINTACK register.
 *
 * The RWNXMACINTACK register will be read, modified to contain the new field value, and written.
 *
 * @param[in] irqmacradardetack - The value to set the field to.
 */
__INLINE void riu_irqmacradardetack_clearf(uint8_t irqmacradardetack)
{
    REG_PL_WR(RIU_RWNXMACINTACK_ADDR, (uint32_t)irqmacradardetack << 12);
}

/**
 * @brief Returns the current value of the IRQMACCCATIMEOUTACK field in the RWNXMACINTACK register.
 *
 * The RWNXMACINTACK register will be read and the IRQMACCCATIMEOUTACK field's value will be returned.
 *
 * @return The current value of the IRQMACCCATIMEOUTACK field in the RWNXMACINTACK register.
 */
__INLINE uint8_t riu_irqmacccatimeoutack_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXMACINTACK_ADDR);
    return ((localVal & ((uint32_t)0x00000100)) >> 8);
}

/**
 * @brief Sets the IRQMACCCATIMEOUTACK field of the RWNXMACINTACK register.
 *
 * The RWNXMACINTACK register will be read, modified to contain the new field value, and written.
 *
 * @param[in] irqmacccatimeoutack - The value to set the field to.
 */
__INLINE void riu_irqmacccatimeoutack_clearf(uint8_t irqmacccatimeoutack)
{
    REG_PL_WR(RIU_RWNXMACINTACK_ADDR, (uint32_t)irqmacccatimeoutack << 8);
}

/// @}

/**
 * @name RWNXMACINTGEN register definitions
 * <table>
 * <caption id="RWNXMACINTGEN_BF">RWNXMACINTGEN bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>12 <td> IRQMACRADARDETGEN <td>R <td>S <td>0
 * <tr><td>08 <td>IRQMACCCATIMEOUTGEN <td>R <td>S <td>0
 * </table>
 *
 * @{
 */

/// Address of the RWNXMACINTGEN register
#define RIU_RWNXMACINTGEN_ADDR   0x4033B424
/// Offset of the RWNXMACINTGEN register from the base address
#define RIU_RWNXMACINTGEN_OFFSET 0x00000424
/// Index of the RWNXMACINTGEN register
#define RIU_RWNXMACINTGEN_INDEX  0x00000109
/// Reset value of the RWNXMACINTGEN register
#define RIU_RWNXMACINTGEN_RESET  0x00000000

/**
 * @brief Returns the current value of the RWNXMACINTGEN register.
 * The RWNXMACINTGEN register will be read and its value returned.
 * @return The current value of the RWNXMACINTGEN register.
 */
__INLINE uint32_t riu_rwnxmacintgen_get(void)
{
    return REG_PL_RD(RIU_RWNXMACINTGEN_ADDR);
}

/**
 * @brief Sets the RWNXMACINTGEN register to a value.
 * The RWNXMACINTGEN register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxmacintgen_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXMACINTGEN_ADDR, value);
}

// field definitions
/// IRQMACRADARDETGEN field bit
#define RIU_IRQMACRADARDETGEN_BIT      ((uint32_t)0x00001000)
/// IRQMACRADARDETGEN field position
#define RIU_IRQMACRADARDETGEN_POS      12
/// IRQMACCCATIMEOUTGEN field bit
#define RIU_IRQMACCCATIMEOUTGEN_BIT    ((uint32_t)0x00000100)
/// IRQMACCCATIMEOUTGEN field position
#define RIU_IRQMACCCATIMEOUTGEN_POS    8

/// IRQMACRADARDETGEN field reset value
#define RIU_IRQMACRADARDETGEN_RST      0x0
/// IRQMACCCATIMEOUTGEN field reset value
#define RIU_IRQMACCCATIMEOUTGEN_RST    0x0

/**
 * @brief Constructs a value for the RWNXMACINTGEN register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] irqmacradardetgen - The value to use for the IRQMACRADARDETGEN field.
 * @param[in] irqmacccatimeoutgen - The value to use for the IRQMACCCATIMEOUTGEN field.
 */
__INLINE void riu_rwnxmacintgen_pack(uint8_t irqmacradardetgen, uint8_t irqmacccatimeoutgen)
{
    REG_PL_WR(RIU_RWNXMACINTGEN_ADDR,  ((uint32_t)irqmacradardetgen << 12) | ((uint32_t)irqmacccatimeoutgen << 8));
}

/**
 * @brief Unpacks RWNXMACINTGEN's fields from current value of the RWNXMACINTGEN register.
 *
 * Reads the RWNXMACINTGEN register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] irqmacradardetgen - Will be populated with the current value of this field from the register.
 * @param[out] irqmacccatimeoutgen - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxmacintgen_unpack(uint8_t* irqmacradardetgen, uint8_t* irqmacccatimeoutgen)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXMACINTGEN_ADDR);

    *irqmacradardetgen = (localVal & ((uint32_t)0x00001000)) >> 12;
    *irqmacccatimeoutgen = (localVal & ((uint32_t)0x00000100)) >> 8;
}

/**
 * @brief Returns the current value of the IRQMACRADARDETGEN field in the RWNXMACINTGEN register.
 *
 * The RWNXMACINTGEN register will be read and the IRQMACRADARDETGEN field's value will be returned.
 *
 * @return The current value of the IRQMACRADARDETGEN field in the RWNXMACINTGEN register.
 */
__INLINE uint8_t riu_irqmacradardetgen_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXMACINTGEN_ADDR);
    return ((localVal & ((uint32_t)0x00001000)) >> 12);
}

/**
 * @brief Sets the IRQMACRADARDETGEN field of the RWNXMACINTGEN register.
 *
 * The RWNXMACINTGEN register will be read, modified to contain the new field value, and written.
 *
 * @param[in] irqmacradardetgen - The value to set the field to.
 */
__INLINE void riu_irqmacradardetgen_setf(uint8_t irqmacradardetgen)
{
    REG_PL_WR(RIU_RWNXMACINTGEN_ADDR, (uint32_t)irqmacradardetgen << 12);
}

/**
 * @brief Returns the current value of the IRQMACCCATIMEOUTGEN field in the RWNXMACINTGEN register.
 *
 * The RWNXMACINTGEN register will be read and the IRQMACCCATIMEOUTGEN field's value will be returned.
 *
 * @return The current value of the IRQMACCCATIMEOUTGEN field in the RWNXMACINTGEN register.
 */
__INLINE uint8_t riu_irqmacccatimeoutgen_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXMACINTGEN_ADDR);
    return ((localVal & ((uint32_t)0x00000100)) >> 8);
}

/**
 * @brief Sets the IRQMACCCATIMEOUTGEN field of the RWNXMACINTGEN register.
 *
 * The RWNXMACINTGEN register will be read, modified to contain the new field value, and written.
 *
 * @param[in] irqmacccatimeoutgen - The value to set the field to.
 */
__INLINE void riu_irqmacccatimeoutgen_setf(uint8_t irqmacccatimeoutgen)
{
    REG_PL_WR(RIU_RWNXMACINTGEN_ADDR, (uint32_t)irqmacccatimeoutgen << 8);
}

/// @}

#if RW_NX_DERIV_80211B
/**
 * @name RWNXFEDSSSCCKCNTL register definitions
 * <table>
 * <caption id="RWNXFEDSSSCCKCNTL_BF">RWNXFEDSSSCCKCNTL bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>18:16 <td>       RXSHIFT4044 <td>R <td>R/W <td>0x4
 * <tr><td>13:12 <td>       TXSHIFT4044 <td>R <td>R/W <td>0x1
 * <tr><td>06:05 <td>     BRXPATHSELREG <td>R <td>R/W <td>0x0
 * <tr><td>04 <td>  RXPATHSELFROMREG <td>R <td>R/W <td>1
 * </table>
 *
 * @{
 */

/// Address of the RWNXFEDSSSCCKCNTL register
#define RIU_RWNXFEDSSSCCKCNTL_ADDR   0x4033B500
/// Offset of the RWNXFEDSSSCCKCNTL register from the base address
#define RIU_RWNXFEDSSSCCKCNTL_OFFSET 0x00000500
/// Index of the RWNXFEDSSSCCKCNTL register
#define RIU_RWNXFEDSSSCCKCNTL_INDEX  0x00000140
/// Reset value of the RWNXFEDSSSCCKCNTL register
#define RIU_RWNXFEDSSSCCKCNTL_RESET  0x00041010

/**
 * @brief Returns the current value of the RWNXFEDSSSCCKCNTL register.
 * The RWNXFEDSSSCCKCNTL register will be read and its value returned.
 * @return The current value of the RWNXFEDSSSCCKCNTL register.
 */
__INLINE uint32_t riu_rwnxfedssscckcntl_get(void)
{
    return REG_PL_RD(RIU_RWNXFEDSSSCCKCNTL_ADDR);
}

/**
 * @brief Sets the RWNXFEDSSSCCKCNTL register to a value.
 * The RWNXFEDSSSCCKCNTL register will be written.
 * @param value - The value to write.
 */
__INLINE void riu_rwnxfedssscckcntl_set(uint32_t value)
{
    REG_PL_WR(RIU_RWNXFEDSSSCCKCNTL_ADDR, value);
}

// field definitions
/// RXSHIFT4044 field mask
#define RIU_RXSHIFT4044_MASK        ((uint32_t)0x00070000)
/// RXSHIFT4044 field LSB position
#define RIU_RXSHIFT4044_LSB         16
/// RXSHIFT4044 field width
#define RIU_RXSHIFT4044_WIDTH       ((uint32_t)0x00000003)
/// TXSHIFT4044 field mask
#define RIU_TXSHIFT4044_MASK        ((uint32_t)0x00003000)
/// TXSHIFT4044 field LSB position
#define RIU_TXSHIFT4044_LSB         12
/// TXSHIFT4044 field width
#define RIU_TXSHIFT4044_WIDTH       ((uint32_t)0x00000002)
/// BRXPATHSELREG field mask
#define RIU_BRXPATHSELREG_MASK      ((uint32_t)0x00000060)
/// BRXPATHSELREG field LSB position
#define RIU_BRXPATHSELREG_LSB       5
/// BRXPATHSELREG field width
#define RIU_BRXPATHSELREG_WIDTH     ((uint32_t)0x00000002)
/// RXPATHSELFROMREG field bit
#define RIU_RXPATHSELFROMREG_BIT    ((uint32_t)0x00000010)
/// RXPATHSELFROMREG field position
#define RIU_RXPATHSELFROMREG_POS    4

/// RXSHIFT4044 field reset value
#define RIU_RXSHIFT4044_RST         0x4
/// TXSHIFT4044 field reset value
#define RIU_TXSHIFT4044_RST         0x1
/// BRXPATHSELREG field reset value
#define RIU_BRXPATHSELREG_RST       0x0
/// RXPATHSELFROMREG field reset value
#define RIU_RXPATHSELFROMREG_RST    0x1

/**
 * @brief Constructs a value for the RWNXFEDSSSCCKCNTL register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] rxshift4044 - The value to use for the RXSHIFT4044 field.
 * @param[in] txshift4044 - The value to use for the TXSHIFT4044 field.
 * @param[in] brxpathselreg - The value to use for the BRXPATHSELREG field.
 * @param[in] rxpathselfromreg - The value to use for the RXPATHSELFROMREG field.
 */
__INLINE void riu_rwnxfedssscckcntl_pack(uint8_t rxshift4044, uint8_t txshift4044, uint8_t brxpathselreg, uint8_t rxpathselfromreg)
{
    REG_PL_WR(RIU_RWNXFEDSSSCCKCNTL_ADDR,  ((uint32_t)rxshift4044 << 16) | ((uint32_t)txshift4044 << 12) | ((uint32_t)brxpathselreg << 5) | ((uint32_t)rxpathselfromreg << 4));
}

/**
 * @brief Unpacks RWNXFEDSSSCCKCNTL's fields from current value of the RWNXFEDSSSCCKCNTL register.
 *
 * Reads the RWNXFEDSSSCCKCNTL register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] rxshift4044 - Will be populated with the current value of this field from the register.
 * @param[out] txshift4044 - Will be populated with the current value of this field from the register.
 * @param[out] brxpathselreg - Will be populated with the current value of this field from the register.
 * @param[out] rxpathselfromreg - Will be populated with the current value of this field from the register.
 */
__INLINE void riu_rwnxfedssscckcntl_unpack(uint8_t* rxshift4044, uint8_t* txshift4044, uint8_t* brxpathselreg, uint8_t* rxpathselfromreg)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFEDSSSCCKCNTL_ADDR);

    *rxshift4044 = (localVal & ((uint32_t)0x00070000)) >> 16;
    *txshift4044 = (localVal & ((uint32_t)0x00003000)) >> 12;
    *brxpathselreg = (localVal & ((uint32_t)0x00000060)) >> 5;
    *rxpathselfromreg = (localVal & ((uint32_t)0x00000010)) >> 4;
}

/**
 * @brief Returns the current value of the RXSHIFT4044 field in the RWNXFEDSSSCCKCNTL register.
 *
 * The RWNXFEDSSSCCKCNTL register will be read and the RXSHIFT4044 field's value will be returned.
 *
 * @return The current value of the RXSHIFT4044 field in the RWNXFEDSSSCCKCNTL register.
 */
__INLINE uint8_t riu_rxshift4044_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFEDSSSCCKCNTL_ADDR);
    return ((localVal & ((uint32_t)0x00070000)) >> 16);
}

/**
 * @brief Sets the RXSHIFT4044 field of the RWNXFEDSSSCCKCNTL register.
 *
 * The RWNXFEDSSSCCKCNTL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rxshift4044 - The value to set the field to.
 */
__INLINE void riu_rxshift4044_setf(uint8_t rxshift4044)
{
    REG_PL_WR(RIU_RWNXFEDSSSCCKCNTL_ADDR, (REG_PL_RD(RIU_RWNXFEDSSSCCKCNTL_ADDR) & ~((uint32_t)0x00070000)) | ((uint32_t)rxshift4044 << 16));
}

/**
 * @brief Returns the current value of the TXSHIFT4044 field in the RWNXFEDSSSCCKCNTL register.
 *
 * The RWNXFEDSSSCCKCNTL register will be read and the TXSHIFT4044 field's value will be returned.
 *
 * @return The current value of the TXSHIFT4044 field in the RWNXFEDSSSCCKCNTL register.
 */
__INLINE uint8_t riu_txshift4044_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFEDSSSCCKCNTL_ADDR);
    return ((localVal & ((uint32_t)0x00003000)) >> 12);
}

/**
 * @brief Sets the TXSHIFT4044 field of the RWNXFEDSSSCCKCNTL register.
 *
 * The RWNXFEDSSSCCKCNTL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] txshift4044 - The value to set the field to.
 */
__INLINE void riu_txshift4044_setf(uint8_t txshift4044)
{
    REG_PL_WR(RIU_RWNXFEDSSSCCKCNTL_ADDR, (REG_PL_RD(RIU_RWNXFEDSSSCCKCNTL_ADDR) & ~((uint32_t)0x00003000)) | ((uint32_t)txshift4044 << 12));
}

/**
 * @brief Returns the current value of the BRXPATHSELREG field in the RWNXFEDSSSCCKCNTL register.
 *
 * The RWNXFEDSSSCCKCNTL register will be read and the BRXPATHSELREG field's value will be returned.
 *
 * @return The current value of the BRXPATHSELREG field in the RWNXFEDSSSCCKCNTL register.
 */
__INLINE uint8_t riu_brxpathselreg_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFEDSSSCCKCNTL_ADDR);
    return ((localVal & ((uint32_t)0x00000060)) >> 5);
}

/**
 * @brief Sets the BRXPATHSELREG field of the RWNXFEDSSSCCKCNTL register.
 *
 * The RWNXFEDSSSCCKCNTL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] brxpathselreg - The value to set the field to.
 */
__INLINE void riu_brxpathselreg_setf(uint8_t brxpathselreg)
{
    REG_PL_WR(RIU_RWNXFEDSSSCCKCNTL_ADDR, (REG_PL_RD(RIU_RWNXFEDSSSCCKCNTL_ADDR) & ~((uint32_t)0x00000060)) | ((uint32_t)brxpathselreg << 5));
}

/**
 * @brief Returns the current value of the RXPATHSELFROMREG field in the RWNXFEDSSSCCKCNTL register.
 *
 * The RWNXFEDSSSCCKCNTL register will be read and the RXPATHSELFROMREG field's value will be returned.
 *
 * @return The current value of the RXPATHSELFROMREG field in the RWNXFEDSSSCCKCNTL register.
 */
__INLINE uint8_t riu_rxpathselfromreg_getf(void)
{
    uint32_t localVal = REG_PL_RD(RIU_RWNXFEDSSSCCKCNTL_ADDR);
    return ((localVal & ((uint32_t)0x00000010)) >> 4);
}

/**
 * @brief Sets the RXPATHSELFROMREG field of the RWNXFEDSSSCCKCNTL register.
 *
 * The RWNXFEDSSSCCKCNTL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rxpathselfromreg - The value to set the field to.
 */
__INLINE void riu_rxpathselfromreg_setf(uint8_t rxpathselfromreg)
{
    REG_PL_WR(RIU_RWNXFEDSSSCCKCNTL_ADDR, (REG_PL_RD(RIU_RWNXFEDSSSCCKCNTL_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)rxpathselfromreg << 4));
}

#endif // RW_NX_DERIV_80211B
/// @}


#endif // _REG_RIU_H_

/// @}

