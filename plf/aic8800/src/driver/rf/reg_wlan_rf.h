/**
 * @file reg_wlan_rf.h
 * @brief Definitions of the WLAN_RF HW block registers and register access functions.
 *
 * @defgroup REG_WLAN_RF REG_WLAN_RF
 * @ingroup REG
 * @{
 *
 * @brief Definitions of the WLAN_RF HW block registers and register access functions.
 */
#ifndef _REG_WLAN_RF_H_
#define _REG_WLAN_RF_H_

#include "compiler.h"
#include "arch.h"
#include "reg_access.h"

/** @brief Number of registers in the REG_WLAN_RF peripheral.
 */
#define REG_WLAN_RF_COUNT 31

/** @brief Decoding mask of the REG_WLAN_RF peripheral registers from the CPU point of view.
 */
#define REG_WLAN_RF_DECODING_MASK 0x0000007F

/**
 * @name WF_PU_TIA_REG register definitions
 * <table>
 * <caption id="WF_PU_TIA_REG_BF">WF_PU_TIA_REG bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>07 <td>      wf_pu_tia_dr <td>R <td>R/W <td>0
 * <tr><td>06 <td>     wf_pu_tia_reg <td>R <td>R/W <td>0
 * <tr><td>05 <td>    wf_tia_rstn_dr <td>R <td>R/W <td>0
 * <tr><td>04 <td>   wf_tia_rstn_reg <td>R <td>R/W <td>0
 * </table>
 *
 * @{
 */

/// Address of the WF_PU_TIA_REG register
#define WLAN_RF_WF_PU_TIA_REG_ADDR   0x40344000
/// Offset of the WF_PU_TIA_REG register from the base address
#define WLAN_RF_WF_PU_TIA_REG_OFFSET 0x00000000
/// Index of the WF_PU_TIA_REG register
#define WLAN_RF_WF_PU_TIA_REG_INDEX  0x00000000
/// Reset value of the WF_PU_TIA_REG register
#define WLAN_RF_WF_PU_TIA_REG_RESET  0x00000000

/**
 * @brief Returns the current value of the WF_PU_TIA_REG register.
 * The WF_PU_TIA_REG register will be read and its value returned.
 * @return The current value of the WF_PU_TIA_REG register.
 */
__INLINE uint32_t wlan_rf_wf_pu_tia_reg_get(void)
{
    return REG_PL_RD(WLAN_RF_WF_PU_TIA_REG_ADDR);
}

/**
 * @brief Sets the WF_PU_TIA_REG register to a value.
 * The WF_PU_TIA_REG register will be written.
 * @param value - The value to write.
 */
__INLINE void wlan_rf_wf_pu_tia_reg_set(uint32_t value)
{
    REG_PL_WR(WLAN_RF_WF_PU_TIA_REG_ADDR, value);
}

// field definitions
/// WF_PU_TIA_DR field bit
#define WLAN_RF_WF_PU_TIA_DR_BIT       ((uint32_t)0x00000080)
/// WF_PU_TIA_DR field position
#define WLAN_RF_WF_PU_TIA_DR_POS       7
/// WF_PU_TIA_REG field bit
#define WLAN_RF_WF_PU_TIA_REG_BIT      ((uint32_t)0x00000040)
/// WF_PU_TIA_REG field position
#define WLAN_RF_WF_PU_TIA_REG_POS      6
/// WF_TIA_RSTN_DR field bit
#define WLAN_RF_WF_TIA_RSTN_DR_BIT     ((uint32_t)0x00000020)
/// WF_TIA_RSTN_DR field position
#define WLAN_RF_WF_TIA_RSTN_DR_POS     5
/// WF_TIA_RSTN_REG field bit
#define WLAN_RF_WF_TIA_RSTN_REG_BIT    ((uint32_t)0x00000010)
/// WF_TIA_RSTN_REG field position
#define WLAN_RF_WF_TIA_RSTN_REG_POS    4

/// WF_PU_TIA_DR field reset value
#define WLAN_RF_WF_PU_TIA_DR_RST       0x0
/// WF_PU_TIA_REG field reset value
#define WLAN_RF_WF_PU_TIA_REG_RST      0x0
/// WF_TIA_RSTN_DR field reset value
#define WLAN_RF_WF_TIA_RSTN_DR_RST     0x0
/// WF_TIA_RSTN_REG field reset value
#define WLAN_RF_WF_TIA_RSTN_REG_RST    0x0

/**
 * @brief Constructs a value for the WF_PU_TIA_REG register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] wfputiadr - The value to use for the wf_pu_tia_dr field.
 * @param[in] wfputiareg - The value to use for the wf_pu_tia_reg field.
 * @param[in] wftiarstndr - The value to use for the wf_tia_rstn_dr field.
 * @param[in] wftiarstnreg - The value to use for the wf_tia_rstn_reg field.
 */
__INLINE void wlan_rf_wf_pu_tia_reg_pack(uint8_t wfputiadr, uint8_t wfputiareg, uint8_t wftiarstndr, uint8_t wftiarstnreg)
{
    REG_PL_WR(WLAN_RF_WF_PU_TIA_REG_ADDR,  ((uint32_t)wfputiadr << 7) | ((uint32_t)wfputiareg << 6) | ((uint32_t)wftiarstndr << 5) | ((uint32_t)wftiarstnreg << 4));
}

/**
 * @brief Unpacks WF_PU_TIA_REG's fields from current value of the WF_PU_TIA_REG register.
 *
 * Reads the WF_PU_TIA_REG register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] wfputiadr - Will be populated with the current value of this field from the register.
 * @param[out] wfputiareg - Will be populated with the current value of this field from the register.
 * @param[out] wftiarstndr - Will be populated with the current value of this field from the register.
 * @param[out] wftiarstnreg - Will be populated with the current value of this field from the register.
 */
__INLINE void wlan_rf_wf_pu_tia_reg_unpack(uint8_t* wfputiadr, uint8_t* wfputiareg, uint8_t* wftiarstndr, uint8_t* wftiarstnreg)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_PU_TIA_REG_ADDR);

    *wfputiadr = (localVal & ((uint32_t)0x00000080)) >> 7;
    *wfputiareg = (localVal & ((uint32_t)0x00000040)) >> 6;
    *wftiarstndr = (localVal & ((uint32_t)0x00000020)) >> 5;
    *wftiarstnreg = (localVal & ((uint32_t)0x00000010)) >> 4;
}

/**
 * @brief Returns the current value of the wf_pu_tia_dr field in the WF_PU_TIA_REG register.
 *
 * The WF_PU_TIA_REG register will be read and the wf_pu_tia_dr field's value will be returned.
 *
 * @return The current value of the wf_pu_tia_dr field in the WF_PU_TIA_REG register.
 */
__INLINE uint8_t wlan_rf_wf_pu_tia_dr_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_PU_TIA_REG_ADDR);
    return ((localVal & ((uint32_t)0x00000080)) >> 7);
}

/**
 * @brief Sets the wf_pu_tia_dr field of the WF_PU_TIA_REG register.
 *
 * The WF_PU_TIA_REG register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wfputiadr - The value to set the field to.
 */
__INLINE void wlan_rf_wf_pu_tia_dr_setf(uint8_t wfputiadr)
{
    REG_PL_WR(WLAN_RF_WF_PU_TIA_REG_ADDR, (REG_PL_RD(WLAN_RF_WF_PU_TIA_REG_ADDR) & ~((uint32_t)0x00000080)) | ((uint32_t)wfputiadr << 7));
}

/**
 * @brief Returns the current value of the wf_pu_tia_reg field in the WF_PU_TIA_REG register.
 *
 * The WF_PU_TIA_REG register will be read and the wf_pu_tia_reg field's value will be returned.
 *
 * @return The current value of the wf_pu_tia_reg field in the WF_PU_TIA_REG register.
 */
__INLINE uint8_t wlan_rf_wf_pu_tia_reg_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_PU_TIA_REG_ADDR);
    return ((localVal & ((uint32_t)0x00000040)) >> 6);
}

/**
 * @brief Sets the wf_pu_tia_reg field of the WF_PU_TIA_REG register.
 *
 * The WF_PU_TIA_REG register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wfputiareg - The value to set the field to.
 */
__INLINE void wlan_rf_wf_pu_tia_reg_setf(uint8_t wfputiareg)
{
    REG_PL_WR(WLAN_RF_WF_PU_TIA_REG_ADDR, (REG_PL_RD(WLAN_RF_WF_PU_TIA_REG_ADDR) & ~((uint32_t)0x00000040)) | ((uint32_t)wfputiareg << 6));
}

/**
 * @brief Returns the current value of the wf_tia_rstn_dr field in the WF_PU_TIA_REG register.
 *
 * The WF_PU_TIA_REG register will be read and the wf_tia_rstn_dr field's value will be returned.
 *
 * @return The current value of the wf_tia_rstn_dr field in the WF_PU_TIA_REG register.
 */
__INLINE uint8_t wlan_rf_wf_tia_rstn_dr_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_PU_TIA_REG_ADDR);
    return ((localVal & ((uint32_t)0x00000020)) >> 5);
}

/**
 * @brief Sets the wf_tia_rstn_dr field of the WF_PU_TIA_REG register.
 *
 * The WF_PU_TIA_REG register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wftiarstndr - The value to set the field to.
 */
__INLINE void wlan_rf_wf_tia_rstn_dr_setf(uint8_t wftiarstndr)
{
    REG_PL_WR(WLAN_RF_WF_PU_TIA_REG_ADDR, (REG_PL_RD(WLAN_RF_WF_PU_TIA_REG_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)wftiarstndr << 5));
}

/**
 * @brief Returns the current value of the wf_tia_rstn_reg field in the WF_PU_TIA_REG register.
 *
 * The WF_PU_TIA_REG register will be read and the wf_tia_rstn_reg field's value will be returned.
 *
 * @return The current value of the wf_tia_rstn_reg field in the WF_PU_TIA_REG register.
 */
__INLINE uint8_t wlan_rf_wf_tia_rstn_reg_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_PU_TIA_REG_ADDR);
    return ((localVal & ((uint32_t)0x00000010)) >> 4);
}

/**
 * @brief Sets the wf_tia_rstn_reg field of the WF_PU_TIA_REG register.
 *
 * The WF_PU_TIA_REG register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wftiarstnreg - The value to set the field to.
 */
__INLINE void wlan_rf_wf_tia_rstn_reg_setf(uint8_t wftiarstnreg)
{
    REG_PL_WR(WLAN_RF_WF_PU_TIA_REG_ADDR, (REG_PL_RD(WLAN_RF_WF_PU_TIA_REG_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)wftiarstnreg << 4));
}

/// @}

/**
 * @name WF_PU_ADC register definitions
 * <table>
 * <caption id="WF_PU_ADC_BF">WF_PU_ADC bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>22 <td>      wf_pu_adc_dr <td>R <td>R/W <td>0
 * <tr><td>21 <td>     wf_pu_adc_reg <td>R <td>R/W <td>0
 * <tr><td>20 <td>wf_pu_adc_vreg_com_dr <td>R <td>R/W <td>0
 * <tr><td>19 <td>wf_pu_adc_vreg_com_reg <td>R <td>R/W <td>0
 * <tr><td>18 <td>wf_pu_adc_vref_com_dr <td>R <td>R/W <td>0
 * <tr><td>17 <td>wf_pu_adc_vref_com_reg <td>R <td>R/W <td>0
 * <tr><td>10 <td>       wf_pu_pa_dr <td>R <td>R/W <td>0
 * <tr><td>09 <td>      wf_pu_pa_reg <td>R <td>R/W <td>0
 * <tr><td>08 <td>  wf_pa_gain_en_dr <td>R <td>R/W <td>0
 * <tr><td>07 <td> wf_pa_gain_en_reg <td>R <td>R/W <td>0
 * <tr><td>06 <td>wf_pa_pkdet_rstn_dr <td>R <td>R/W <td>0
 * <tr><td>05 <td>wf_pa_pkdet_rstn_reg <td>R <td>R/W <td>0
 * </table>
 *
 * @{
 */

/// Address of the WF_PU_ADC register
#define WLAN_RF_WF_PU_ADC_ADDR   0x40344004
/// Offset of the WF_PU_ADC register from the base address
#define WLAN_RF_WF_PU_ADC_OFFSET 0x00000004
/// Index of the WF_PU_ADC register
#define WLAN_RF_WF_PU_ADC_INDEX  0x00000001
/// Reset value of the WF_PU_ADC register
#define WLAN_RF_WF_PU_ADC_RESET  0x00000000

/**
 * @brief Returns the current value of the WF_PU_ADC register.
 * The WF_PU_ADC register will be read and its value returned.
 * @return The current value of the WF_PU_ADC register.
 */
__INLINE uint32_t wlan_rf_wf_pu_adc_get(void)
{
    return REG_PL_RD(WLAN_RF_WF_PU_ADC_ADDR);
}

/**
 * @brief Sets the WF_PU_ADC register to a value.
 * The WF_PU_ADC register will be written.
 * @param value - The value to write.
 */
__INLINE void wlan_rf_wf_pu_adc_set(uint32_t value)
{
    REG_PL_WR(WLAN_RF_WF_PU_ADC_ADDR, value);
}

// field definitions
/// WF_PU_ADC_DR field bit
#define WLAN_RF_WF_PU_ADC_DR_BIT              ((uint32_t)0x00400000)
/// WF_PU_ADC_DR field position
#define WLAN_RF_WF_PU_ADC_DR_POS              22
/// WF_PU_ADC_REG field bit
#define WLAN_RF_WF_PU_ADC_REG_BIT             ((uint32_t)0x00200000)
/// WF_PU_ADC_REG field position
#define WLAN_RF_WF_PU_ADC_REG_POS             21
/// WF_PU_ADC_VREG_COM_DR field bit
#define WLAN_RF_WF_PU_ADC_VREG_COM_DR_BIT     ((uint32_t)0x00100000)
/// WF_PU_ADC_VREG_COM_DR field position
#define WLAN_RF_WF_PU_ADC_VREG_COM_DR_POS     20
/// WF_PU_ADC_VREG_COM_REG field bit
#define WLAN_RF_WF_PU_ADC_VREG_COM_REG_BIT    ((uint32_t)0x00080000)
/// WF_PU_ADC_VREG_COM_REG field position
#define WLAN_RF_WF_PU_ADC_VREG_COM_REG_POS    19
/// WF_PU_ADC_VREF_COM_DR field bit
#define WLAN_RF_WF_PU_ADC_VREF_COM_DR_BIT     ((uint32_t)0x00040000)
/// WF_PU_ADC_VREF_COM_DR field position
#define WLAN_RF_WF_PU_ADC_VREF_COM_DR_POS     18
/// WF_PU_ADC_VREF_COM_REG field bit
#define WLAN_RF_WF_PU_ADC_VREF_COM_REG_BIT    ((uint32_t)0x00020000)
/// WF_PU_ADC_VREF_COM_REG field position
#define WLAN_RF_WF_PU_ADC_VREF_COM_REG_POS    17
/// WF_PU_PA_DR field bit
#define WLAN_RF_WF_PU_PA_DR_BIT               ((uint32_t)0x00000400)
/// WF_PU_PA_DR field position
#define WLAN_RF_WF_PU_PA_DR_POS               10
/// WF_PU_PA_REG field bit
#define WLAN_RF_WF_PU_PA_REG_BIT              ((uint32_t)0x00000200)
/// WF_PU_PA_REG field position
#define WLAN_RF_WF_PU_PA_REG_POS              9
/// WF_PA_GAIN_EN_DR field bit
#define WLAN_RF_WF_PA_GAIN_EN_DR_BIT          ((uint32_t)0x00000100)
/// WF_PA_GAIN_EN_DR field position
#define WLAN_RF_WF_PA_GAIN_EN_DR_POS          8
/// WF_PA_GAIN_EN_REG field bit
#define WLAN_RF_WF_PA_GAIN_EN_REG_BIT         ((uint32_t)0x00000080)
/// WF_PA_GAIN_EN_REG field position
#define WLAN_RF_WF_PA_GAIN_EN_REG_POS         7
/// WF_PA_PKDET_RSTN_DR field bit
#define WLAN_RF_WF_PA_PKDET_RSTN_DR_BIT       ((uint32_t)0x00000040)
/// WF_PA_PKDET_RSTN_DR field position
#define WLAN_RF_WF_PA_PKDET_RSTN_DR_POS       6
/// WF_PA_PKDET_RSTN_REG field bit
#define WLAN_RF_WF_PA_PKDET_RSTN_REG_BIT      ((uint32_t)0x00000020)
/// WF_PA_PKDET_RSTN_REG field position
#define WLAN_RF_WF_PA_PKDET_RSTN_REG_POS      5

/// WF_PU_ADC_DR field reset value
#define WLAN_RF_WF_PU_ADC_DR_RST              0x0
/// WF_PU_ADC_REG field reset value
#define WLAN_RF_WF_PU_ADC_REG_RST             0x0
/// WF_PU_ADC_VREG_COM_DR field reset value
#define WLAN_RF_WF_PU_ADC_VREG_COM_DR_RST     0x0
/// WF_PU_ADC_VREG_COM_REG field reset value
#define WLAN_RF_WF_PU_ADC_VREG_COM_REG_RST    0x0
/// WF_PU_ADC_VREF_COM_DR field reset value
#define WLAN_RF_WF_PU_ADC_VREF_COM_DR_RST     0x0
/// WF_PU_ADC_VREF_COM_REG field reset value
#define WLAN_RF_WF_PU_ADC_VREF_COM_REG_RST    0x0
/// WF_PU_PA_DR field reset value
#define WLAN_RF_WF_PU_PA_DR_RST               0x0
/// WF_PU_PA_REG field reset value
#define WLAN_RF_WF_PU_PA_REG_RST              0x0
/// WF_PA_GAIN_EN_DR field reset value
#define WLAN_RF_WF_PA_GAIN_EN_DR_RST          0x0
/// WF_PA_GAIN_EN_REG field reset value
#define WLAN_RF_WF_PA_GAIN_EN_REG_RST         0x0
/// WF_PA_PKDET_RSTN_DR field reset value
#define WLAN_RF_WF_PA_PKDET_RSTN_DR_RST       0x0
/// WF_PA_PKDET_RSTN_REG field reset value
#define WLAN_RF_WF_PA_PKDET_RSTN_REG_RST      0x0

/**
 * @brief Constructs a value for the WF_PU_ADC register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] wfpuadcdr - The value to use for the wf_pu_adc_dr field.
 * @param[in] wfpuadcreg - The value to use for the wf_pu_adc_reg field.
 * @param[in] wfpuadcvregcomdr - The value to use for the wf_pu_adc_vreg_com_dr field.
 * @param[in] wfpuadcvregcomreg - The value to use for the wf_pu_adc_vreg_com_reg field.
 * @param[in] wfpuadcvrefcomdr - The value to use for the wf_pu_adc_vref_com_dr field.
 * @param[in] wfpuadcvrefcomreg - The value to use for the wf_pu_adc_vref_com_reg field.
 * @param[in] wfpupadr - The value to use for the wf_pu_pa_dr field.
 * @param[in] wfpupareg - The value to use for the wf_pu_pa_reg field.
 * @param[in] wfpagainendr - The value to use for the wf_pa_gain_en_dr field.
 * @param[in] wfpagainenreg - The value to use for the wf_pa_gain_en_reg field.
 * @param[in] wfpapkdetrstndr - The value to use for the wf_pa_pkdet_rstn_dr field.
 * @param[in] wfpapkdetrstnreg - The value to use for the wf_pa_pkdet_rstn_reg field.
 */
__INLINE void wlan_rf_wf_pu_adc_pack(uint8_t wfpuadcdr, uint8_t wfpuadcreg, uint8_t wfpuadcvregcomdr, uint8_t wfpuadcvregcomreg, uint8_t wfpuadcvrefcomdr, uint8_t wfpuadcvrefcomreg, uint8_t wfpupadr, uint8_t wfpupareg, uint8_t wfpagainendr, uint8_t wfpagainenreg, uint8_t wfpapkdetrstndr, uint8_t wfpapkdetrstnreg)
{
    REG_PL_WR(WLAN_RF_WF_PU_ADC_ADDR,  ((uint32_t)wfpuadcdr << 22) | ((uint32_t)wfpuadcreg << 21) | ((uint32_t)wfpuadcvregcomdr << 20) | ((uint32_t)wfpuadcvregcomreg << 19) | ((uint32_t)wfpuadcvrefcomdr << 18) | ((uint32_t)wfpuadcvrefcomreg << 17) | ((uint32_t)wfpupadr << 10) | ((uint32_t)wfpupareg << 9) | ((uint32_t)wfpagainendr << 8) | ((uint32_t)wfpagainenreg << 7) | ((uint32_t)wfpapkdetrstndr << 6) | ((uint32_t)wfpapkdetrstnreg << 5));
}

/**
 * @brief Unpacks WF_PU_ADC's fields from current value of the WF_PU_ADC register.
 *
 * Reads the WF_PU_ADC register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] wfpuadcdr - Will be populated with the current value of this field from the register.
 * @param[out] wfpuadcreg - Will be populated with the current value of this field from the register.
 * @param[out] wfpuadcvregcomdr - Will be populated with the current value of this field from the register.
 * @param[out] wfpuadcvregcomreg - Will be populated with the current value of this field from the register.
 * @param[out] wfpuadcvrefcomdr - Will be populated with the current value of this field from the register.
 * @param[out] wfpuadcvrefcomreg - Will be populated with the current value of this field from the register.
 * @param[out] wfpupadr - Will be populated with the current value of this field from the register.
 * @param[out] wfpupareg - Will be populated with the current value of this field from the register.
 * @param[out] wfpagainendr - Will be populated with the current value of this field from the register.
 * @param[out] wfpagainenreg - Will be populated with the current value of this field from the register.
 * @param[out] wfpapkdetrstndr - Will be populated with the current value of this field from the register.
 * @param[out] wfpapkdetrstnreg - Will be populated with the current value of this field from the register.
 */
__INLINE void wlan_rf_wf_pu_adc_unpack(uint8_t* wfpuadcdr, uint8_t* wfpuadcreg, uint8_t* wfpuadcvregcomdr, uint8_t* wfpuadcvregcomreg, uint8_t* wfpuadcvrefcomdr, uint8_t* wfpuadcvrefcomreg, uint8_t* wfpupadr, uint8_t* wfpupareg, uint8_t* wfpagainendr, uint8_t* wfpagainenreg, uint8_t* wfpapkdetrstndr, uint8_t* wfpapkdetrstnreg)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_PU_ADC_ADDR);

    *wfpuadcdr = (localVal & ((uint32_t)0x00400000)) >> 22;
    *wfpuadcreg = (localVal & ((uint32_t)0x00200000)) >> 21;
    *wfpuadcvregcomdr = (localVal & ((uint32_t)0x00100000)) >> 20;
    *wfpuadcvregcomreg = (localVal & ((uint32_t)0x00080000)) >> 19;
    *wfpuadcvrefcomdr = (localVal & ((uint32_t)0x00040000)) >> 18;
    *wfpuadcvrefcomreg = (localVal & ((uint32_t)0x00020000)) >> 17;
    *wfpupadr = (localVal & ((uint32_t)0x00000400)) >> 10;
    *wfpupareg = (localVal & ((uint32_t)0x00000200)) >> 9;
    *wfpagainendr = (localVal & ((uint32_t)0x00000100)) >> 8;
    *wfpagainenreg = (localVal & ((uint32_t)0x00000080)) >> 7;
    *wfpapkdetrstndr = (localVal & ((uint32_t)0x00000040)) >> 6;
    *wfpapkdetrstnreg = (localVal & ((uint32_t)0x00000020)) >> 5;
}

/**
 * @brief Returns the current value of the wf_pu_adc_dr field in the WF_PU_ADC register.
 *
 * The WF_PU_ADC register will be read and the wf_pu_adc_dr field's value will be returned.
 *
 * @return The current value of the wf_pu_adc_dr field in the WF_PU_ADC register.
 */
__INLINE uint8_t wlan_rf_wf_pu_adc_dr_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_PU_ADC_ADDR);
    return ((localVal & ((uint32_t)0x00400000)) >> 22);
}

/**
 * @brief Sets the wf_pu_adc_dr field of the WF_PU_ADC register.
 *
 * The WF_PU_ADC register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wfpuadcdr - The value to set the field to.
 */
__INLINE void wlan_rf_wf_pu_adc_dr_setf(uint8_t wfpuadcdr)
{
    REG_PL_WR(WLAN_RF_WF_PU_ADC_ADDR, (REG_PL_RD(WLAN_RF_WF_PU_ADC_ADDR) & ~((uint32_t)0x00400000)) | ((uint32_t)wfpuadcdr << 22));
}

/**
 * @brief Returns the current value of the wf_pu_adc_reg field in the WF_PU_ADC register.
 *
 * The WF_PU_ADC register will be read and the wf_pu_adc_reg field's value will be returned.
 *
 * @return The current value of the wf_pu_adc_reg field in the WF_PU_ADC register.
 */
__INLINE uint8_t wlan_rf_wf_pu_adc_reg_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_PU_ADC_ADDR);
    return ((localVal & ((uint32_t)0x00200000)) >> 21);
}

/**
 * @brief Sets the wf_pu_adc_reg field of the WF_PU_ADC register.
 *
 * The WF_PU_ADC register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wfpuadcreg - The value to set the field to.
 */
__INLINE void wlan_rf_wf_pu_adc_reg_setf(uint8_t wfpuadcreg)
{
    REG_PL_WR(WLAN_RF_WF_PU_ADC_ADDR, (REG_PL_RD(WLAN_RF_WF_PU_ADC_ADDR) & ~((uint32_t)0x00200000)) | ((uint32_t)wfpuadcreg << 21));
}

/**
 * @brief Returns the current value of the wf_pu_adc_vreg_com_dr field in the WF_PU_ADC register.
 *
 * The WF_PU_ADC register will be read and the wf_pu_adc_vreg_com_dr field's value will be returned.
 *
 * @return The current value of the wf_pu_adc_vreg_com_dr field in the WF_PU_ADC register.
 */
__INLINE uint8_t wlan_rf_wf_pu_adc_vreg_com_dr_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_PU_ADC_ADDR);
    return ((localVal & ((uint32_t)0x00100000)) >> 20);
}

/**
 * @brief Sets the wf_pu_adc_vreg_com_dr field of the WF_PU_ADC register.
 *
 * The WF_PU_ADC register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wfpuadcvregcomdr - The value to set the field to.
 */
__INLINE void wlan_rf_wf_pu_adc_vreg_com_dr_setf(uint8_t wfpuadcvregcomdr)
{
    REG_PL_WR(WLAN_RF_WF_PU_ADC_ADDR, (REG_PL_RD(WLAN_RF_WF_PU_ADC_ADDR) & ~((uint32_t)0x00100000)) | ((uint32_t)wfpuadcvregcomdr << 20));
}

/**
 * @brief Returns the current value of the wf_pu_adc_vreg_com_reg field in the WF_PU_ADC register.
 *
 * The WF_PU_ADC register will be read and the wf_pu_adc_vreg_com_reg field's value will be returned.
 *
 * @return The current value of the wf_pu_adc_vreg_com_reg field in the WF_PU_ADC register.
 */
__INLINE uint8_t wlan_rf_wf_pu_adc_vreg_com_reg_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_PU_ADC_ADDR);
    return ((localVal & ((uint32_t)0x00080000)) >> 19);
}

/**
 * @brief Sets the wf_pu_adc_vreg_com_reg field of the WF_PU_ADC register.
 *
 * The WF_PU_ADC register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wfpuadcvregcomreg - The value to set the field to.
 */
__INLINE void wlan_rf_wf_pu_adc_vreg_com_reg_setf(uint8_t wfpuadcvregcomreg)
{
    REG_PL_WR(WLAN_RF_WF_PU_ADC_ADDR, (REG_PL_RD(WLAN_RF_WF_PU_ADC_ADDR) & ~((uint32_t)0x00080000)) | ((uint32_t)wfpuadcvregcomreg << 19));
}

/**
 * @brief Returns the current value of the wf_pu_adc_vref_com_dr field in the WF_PU_ADC register.
 *
 * The WF_PU_ADC register will be read and the wf_pu_adc_vref_com_dr field's value will be returned.
 *
 * @return The current value of the wf_pu_adc_vref_com_dr field in the WF_PU_ADC register.
 */
__INLINE uint8_t wlan_rf_wf_pu_adc_vref_com_dr_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_PU_ADC_ADDR);
    return ((localVal & ((uint32_t)0x00040000)) >> 18);
}

/**
 * @brief Sets the wf_pu_adc_vref_com_dr field of the WF_PU_ADC register.
 *
 * The WF_PU_ADC register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wfpuadcvrefcomdr - The value to set the field to.
 */
__INLINE void wlan_rf_wf_pu_adc_vref_com_dr_setf(uint8_t wfpuadcvrefcomdr)
{
    REG_PL_WR(WLAN_RF_WF_PU_ADC_ADDR, (REG_PL_RD(WLAN_RF_WF_PU_ADC_ADDR) & ~((uint32_t)0x00040000)) | ((uint32_t)wfpuadcvrefcomdr << 18));
}

/**
 * @brief Returns the current value of the wf_pu_adc_vref_com_reg field in the WF_PU_ADC register.
 *
 * The WF_PU_ADC register will be read and the wf_pu_adc_vref_com_reg field's value will be returned.
 *
 * @return The current value of the wf_pu_adc_vref_com_reg field in the WF_PU_ADC register.
 */
__INLINE uint8_t wlan_rf_wf_pu_adc_vref_com_reg_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_PU_ADC_ADDR);
    return ((localVal & ((uint32_t)0x00020000)) >> 17);
}

/**
 * @brief Sets the wf_pu_adc_vref_com_reg field of the WF_PU_ADC register.
 *
 * The WF_PU_ADC register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wfpuadcvrefcomreg - The value to set the field to.
 */
__INLINE void wlan_rf_wf_pu_adc_vref_com_reg_setf(uint8_t wfpuadcvrefcomreg)
{
    REG_PL_WR(WLAN_RF_WF_PU_ADC_ADDR, (REG_PL_RD(WLAN_RF_WF_PU_ADC_ADDR) & ~((uint32_t)0x00020000)) | ((uint32_t)wfpuadcvrefcomreg << 17));
}

/**
 * @brief Returns the current value of the wf_pu_pa_dr field in the WF_PU_ADC register.
 *
 * The WF_PU_ADC register will be read and the wf_pu_pa_dr field's value will be returned.
 *
 * @return The current value of the wf_pu_pa_dr field in the WF_PU_ADC register.
 */
__INLINE uint8_t wlan_rf_wf_pu_pa_dr_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_PU_ADC_ADDR);
    return ((localVal & ((uint32_t)0x00000400)) >> 10);
}

/**
 * @brief Sets the wf_pu_pa_dr field of the WF_PU_ADC register.
 *
 * The WF_PU_ADC register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wfpupadr - The value to set the field to.
 */
__INLINE void wlan_rf_wf_pu_pa_dr_setf(uint8_t wfpupadr)
{
    REG_PL_WR(WLAN_RF_WF_PU_ADC_ADDR, (REG_PL_RD(WLAN_RF_WF_PU_ADC_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)wfpupadr << 10));
}

/**
 * @brief Returns the current value of the wf_pu_pa_reg field in the WF_PU_ADC register.
 *
 * The WF_PU_ADC register will be read and the wf_pu_pa_reg field's value will be returned.
 *
 * @return The current value of the wf_pu_pa_reg field in the WF_PU_ADC register.
 */
__INLINE uint8_t wlan_rf_wf_pu_pa_reg_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_PU_ADC_ADDR);
    return ((localVal & ((uint32_t)0x00000200)) >> 9);
}

/**
 * @brief Sets the wf_pu_pa_reg field of the WF_PU_ADC register.
 *
 * The WF_PU_ADC register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wfpupareg - The value to set the field to.
 */
__INLINE void wlan_rf_wf_pu_pa_reg_setf(uint8_t wfpupareg)
{
    REG_PL_WR(WLAN_RF_WF_PU_ADC_ADDR, (REG_PL_RD(WLAN_RF_WF_PU_ADC_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)wfpupareg << 9));
}

/**
 * @brief Returns the current value of the wf_pa_gain_en_dr field in the WF_PU_ADC register.
 *
 * The WF_PU_ADC register will be read and the wf_pa_gain_en_dr field's value will be returned.
 *
 * @return The current value of the wf_pa_gain_en_dr field in the WF_PU_ADC register.
 */
__INLINE uint8_t wlan_rf_wf_pa_gain_en_dr_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_PU_ADC_ADDR);
    return ((localVal & ((uint32_t)0x00000100)) >> 8);
}

/**
 * @brief Sets the wf_pa_gain_en_dr field of the WF_PU_ADC register.
 *
 * The WF_PU_ADC register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wfpagainendr - The value to set the field to.
 */
__INLINE void wlan_rf_wf_pa_gain_en_dr_setf(uint8_t wfpagainendr)
{
    REG_PL_WR(WLAN_RF_WF_PU_ADC_ADDR, (REG_PL_RD(WLAN_RF_WF_PU_ADC_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)wfpagainendr << 8));
}

/**
 * @brief Returns the current value of the wf_pa_gain_en_reg field in the WF_PU_ADC register.
 *
 * The WF_PU_ADC register will be read and the wf_pa_gain_en_reg field's value will be returned.
 *
 * @return The current value of the wf_pa_gain_en_reg field in the WF_PU_ADC register.
 */
__INLINE uint8_t wlan_rf_wf_pa_gain_en_reg_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_PU_ADC_ADDR);
    return ((localVal & ((uint32_t)0x00000080)) >> 7);
}

/**
 * @brief Sets the wf_pa_gain_en_reg field of the WF_PU_ADC register.
 *
 * The WF_PU_ADC register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wfpagainenreg - The value to set the field to.
 */
__INLINE void wlan_rf_wf_pa_gain_en_reg_setf(uint8_t wfpagainenreg)
{
    REG_PL_WR(WLAN_RF_WF_PU_ADC_ADDR, (REG_PL_RD(WLAN_RF_WF_PU_ADC_ADDR) & ~((uint32_t)0x00000080)) | ((uint32_t)wfpagainenreg << 7));
}

/**
 * @brief Returns the current value of the wf_pa_pkdet_rstn_dr field in the WF_PU_ADC register.
 *
 * The WF_PU_ADC register will be read and the wf_pa_pkdet_rstn_dr field's value will be returned.
 *
 * @return The current value of the wf_pa_pkdet_rstn_dr field in the WF_PU_ADC register.
 */
__INLINE uint8_t wlan_rf_wf_pa_pkdet_rstn_dr_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_PU_ADC_ADDR);
    return ((localVal & ((uint32_t)0x00000040)) >> 6);
}

/**
 * @brief Sets the wf_pa_pkdet_rstn_dr field of the WF_PU_ADC register.
 *
 * The WF_PU_ADC register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wfpapkdetrstndr - The value to set the field to.
 */
__INLINE void wlan_rf_wf_pa_pkdet_rstn_dr_setf(uint8_t wfpapkdetrstndr)
{
    REG_PL_WR(WLAN_RF_WF_PU_ADC_ADDR, (REG_PL_RD(WLAN_RF_WF_PU_ADC_ADDR) & ~((uint32_t)0x00000040)) | ((uint32_t)wfpapkdetrstndr << 6));
}

/**
 * @brief Returns the current value of the wf_pa_pkdet_rstn_reg field in the WF_PU_ADC register.
 *
 * The WF_PU_ADC register will be read and the wf_pa_pkdet_rstn_reg field's value will be returned.
 *
 * @return The current value of the wf_pa_pkdet_rstn_reg field in the WF_PU_ADC register.
 */
__INLINE uint8_t wlan_rf_wf_pa_pkdet_rstn_reg_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_PU_ADC_ADDR);
    return ((localVal & ((uint32_t)0x00000020)) >> 5);
}

/**
 * @brief Sets the wf_pa_pkdet_rstn_reg field of the WF_PU_ADC register.
 *
 * The WF_PU_ADC register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wfpapkdetrstnreg - The value to set the field to.
 */
__INLINE void wlan_rf_wf_pa_pkdet_rstn_reg_setf(uint8_t wfpapkdetrstnreg)
{
    REG_PL_WR(WLAN_RF_WF_PU_ADC_ADDR, (REG_PL_RD(WLAN_RF_WF_PU_ADC_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)wfpapkdetrstnreg << 5));
}

/// @}

/**
 * @name WLAN_RF_PU_BIT register definitions
 * <table>
 * <caption id="WLAN_RF_PU_BIT_BF">WLAN_RF_PU_BIT bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>23:02 <td>    wlan_rf_pu_bit <td>R <td>R/W <td>0x0
 * </table>
 *
 * @{
 */

/// Address of the WLAN_RF_PU_BIT register
#define WLAN_RF_WLAN_RF_PU_BIT_ADDR   0x40344008
/// Offset of the WLAN_RF_PU_BIT register from the base address
#define WLAN_RF_WLAN_RF_PU_BIT_OFFSET 0x00000008
/// Index of the WLAN_RF_PU_BIT register
#define WLAN_RF_WLAN_RF_PU_BIT_INDEX  0x00000002
/// Reset value of the WLAN_RF_PU_BIT register
#define WLAN_RF_WLAN_RF_PU_BIT_RESET  0x00000000

/**
 * @brief Returns the current value of the WLAN_RF_PU_BIT register.
 * The WLAN_RF_PU_BIT register will be read and its value returned.
 * @return The current value of the WLAN_RF_PU_BIT register.
 */
__INLINE uint32_t wlan_rf_wlan_rf_pu_bit_get(void)
{
    return REG_PL_RD(WLAN_RF_WLAN_RF_PU_BIT_ADDR);
}

/**
 * @brief Sets the WLAN_RF_PU_BIT register to a value.
 * The WLAN_RF_PU_BIT register will be written.
 * @param value - The value to write.
 */
__INLINE void wlan_rf_wlan_rf_pu_bit_set(uint32_t value)
{
    REG_PL_WR(WLAN_RF_WLAN_RF_PU_BIT_ADDR, value);
}

// field definitions
/// WLAN_RF_PU_BIT field mask
#define WLAN_RF_WLAN_RF_PU_BIT_MASK   ((uint32_t)0x00FFFFFC)
/// WLAN_RF_PU_BIT field LSB position
#define WLAN_RF_WLAN_RF_PU_BIT_LSB    2
/// WLAN_RF_PU_BIT field width
#define WLAN_RF_WLAN_RF_PU_BIT_WIDTH  ((uint32_t)0x00000016)

/// WLAN_RF_PU_BIT field reset value
#define WLAN_RF_WLAN_RF_PU_BIT_RST    0x0

/**
 * @brief Returns the current value of the wlan_rf_pu_bit field in the WLAN_RF_PU_BIT register.
 *
 * The WLAN_RF_PU_BIT register will be read and the wlan_rf_pu_bit field's value will be returned.
 *
 * @return The current value of the wlan_rf_pu_bit field in the WLAN_RF_PU_BIT register.
 */
__INLINE uint32_t wlan_rf_wlan_rf_pu_bit_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WLAN_RF_PU_BIT_ADDR);
    return (localVal >> 2);
}

/**
 * @brief Sets the wlan_rf_pu_bit field of the WLAN_RF_PU_BIT register.
 *
 * The WLAN_RF_PU_BIT register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wlanrfpubit - The value to set the field to.
 */
__INLINE void wlan_rf_wlan_rf_pu_bit_setf(uint32_t wlanrfpubit)
{
    REG_PL_WR(WLAN_RF_WLAN_RF_PU_BIT_ADDR, (uint32_t)wlanrfpubit << 2);
}

/// @}

/**
 * @name WF_LNA_REG register definitions
 * <table>
 * <caption id="WF_LNA_REG_BF">WF_LNA_REG bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>23 <td>      wf_lna5g_en0 <td>R <td>R/W <td>0
 * <tr><td>22 <td>      wf_lna5g_en1 <td>R <td>R/W <td>0
 * <tr><td>21 <td>     wf_lna24g_en0 <td>R <td>R/W <td>0
 * <tr><td>20 <td>     wf_lna24g_en1 <td>R <td>R/W <td>0
 * <tr><td>11 <td> lna_vcm_res_short <td>R <td>R/W <td>0
 * <tr><td>03 <td>       wf_rmx5g_en <td>R <td>R/W <td>0
 * <tr><td>02 <td>      wf_rmx24g_en <td>R <td>R/W <td>0
 * <tr><td>01 <td> wf_rmx_img_cal_en <td>R <td>R/W <td>0
 * </table>
 *
 * @{
 */

/// Address of the WF_LNA_REG register
#define WLAN_RF_WF_LNA_REG_ADDR   0x40344014
/// Offset of the WF_LNA_REG register from the base address
#define WLAN_RF_WF_LNA_REG_OFFSET 0x00000014
/// Index of the WF_LNA_REG register
#define WLAN_RF_WF_LNA_REG_INDEX  0x00000005
/// Reset value of the WF_LNA_REG register
#define WLAN_RF_WF_LNA_REG_RESET  0x00000000

/**
 * @brief Returns the current value of the WF_LNA_REG register.
 * The WF_LNA_REG register will be read and its value returned.
 * @return The current value of the WF_LNA_REG register.
 */
__INLINE uint32_t wlan_rf_wf_lna_reg_get(void)
{
    return REG_PL_RD(WLAN_RF_WF_LNA_REG_ADDR);
}

/**
 * @brief Sets the WF_LNA_REG register to a value.
 * The WF_LNA_REG register will be written.
 * @param value - The value to write.
 */
__INLINE void wlan_rf_wf_lna_reg_set(uint32_t value)
{
    REG_PL_WR(WLAN_RF_WF_LNA_REG_ADDR, value);
}

// field definitions
/// WF_LNA_5G_EN_0 field bit
#define WLAN_RF_WF_LNA_5G_EN_0_BIT       ((uint32_t)0x00800000)
/// WF_LNA_5G_EN_0 field position
#define WLAN_RF_WF_LNA_5G_EN_0_POS       23
/// WF_LNA_5G_EN_1 field bit
#define WLAN_RF_WF_LNA_5G_EN_1_BIT       ((uint32_t)0x00400000)
/// WF_LNA_5G_EN_1 field position
#define WLAN_RF_WF_LNA_5G_EN_1_POS       22
/// WF_LNA_24G_EN_0 field bit
#define WLAN_RF_WF_LNA_24G_EN_0_BIT      ((uint32_t)0x00200000)
/// WF_LNA_24G_EN_0 field position
#define WLAN_RF_WF_LNA_24G_EN_0_POS      21
/// WF_LNA_24G_EN_1 field bit
#define WLAN_RF_WF_LNA_24G_EN_1_BIT      ((uint32_t)0x00100000)
/// WF_LNA_24G_EN_1 field position
#define WLAN_RF_WF_LNA_24G_EN_1_POS      20
/// LNA_VCM_RES_SHORT field bit
#define WLAN_RF_LNA_VCM_RES_SHORT_BIT    ((uint32_t)0x00000800)
/// LNA_VCM_RES_SHORT field position
#define WLAN_RF_LNA_VCM_RES_SHORT_POS    11
/// WF_RMX_5G_EN field bit
#define WLAN_RF_WF_RMX_5G_EN_BIT         ((uint32_t)0x00000008)
/// WF_RMX_5G_EN field position
#define WLAN_RF_WF_RMX_5G_EN_POS         3
/// WF_RMX_24G_EN field bit
#define WLAN_RF_WF_RMX_24G_EN_BIT        ((uint32_t)0x00000004)
/// WF_RMX_24G_EN field position
#define WLAN_RF_WF_RMX_24G_EN_POS        2
/// WF_RMX_IMG_CAL_EN field bit
#define WLAN_RF_WF_RMX_IMG_CAL_EN_BIT    ((uint32_t)0x00000002)
/// WF_RMX_IMG_CAL_EN field position
#define WLAN_RF_WF_RMX_IMG_CAL_EN_POS    1

/// WF_LNA_5G_EN_0 field reset value
#define WLAN_RF_WF_LNA_5G_EN_0_RST       0x0
/// WF_LNA_5G_EN_1 field reset value
#define WLAN_RF_WF_LNA_5G_EN_1_RST       0x0
/// WF_LNA_24G_EN_0 field reset value
#define WLAN_RF_WF_LNA_24G_EN_0_RST      0x0
/// WF_LNA_24G_EN_1 field reset value
#define WLAN_RF_WF_LNA_24G_EN_1_RST      0x0
/// LNA_VCM_RES_SHORT field reset value
#define WLAN_RF_LNA_VCM_RES_SHORT_RST    0x0
/// WF_RMX_5G_EN field reset value
#define WLAN_RF_WF_RMX_5G_EN_RST         0x0
/// WF_RMX_24G_EN field reset value
#define WLAN_RF_WF_RMX_24G_EN_RST        0x0
/// WF_RMX_IMG_CAL_EN field reset value
#define WLAN_RF_WF_RMX_IMG_CAL_EN_RST    0x0

/**
 * @brief Constructs a value for the WF_LNA_REG register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] wflna5gen0 - The value to use for the wf_lna5g_en0 field.
 * @param[in] wflna5gen1 - The value to use for the wf_lna5g_en1 field.
 * @param[in] wflna24gen0 - The value to use for the wf_lna24g_en0 field.
 * @param[in] wflna24gen1 - The value to use for the wf_lna24g_en1 field.
 * @param[in] lnavcmresshort - The value to use for the lna_vcm_res_short field.
 * @param[in] wfrmx5gen - The value to use for the wf_rmx5g_en field.
 * @param[in] wfrmx24gen - The value to use for the wf_rmx24g_en field.
 * @param[in] wfrmximgcalen - The value to use for the wf_rmx_img_cal_en field.
 */
__INLINE void wlan_rf_wf_lna_reg_pack(uint8_t wflna5gen0, uint8_t wflna5gen1, uint8_t wflna24gen0, uint8_t wflna24gen1, uint8_t lnavcmresshort, uint8_t wfrmx5gen, uint8_t wfrmx24gen, uint8_t wfrmximgcalen)
{
    REG_PL_WR(WLAN_RF_WF_LNA_REG_ADDR,  ((uint32_t)wflna5gen0 << 23) | ((uint32_t)wflna5gen1 << 22) | ((uint32_t)wflna24gen0 << 21) | ((uint32_t)wflna24gen1 << 20) | ((uint32_t)lnavcmresshort << 11) | ((uint32_t)wfrmx5gen << 3) | ((uint32_t)wfrmx24gen << 2) | ((uint32_t)wfrmximgcalen << 1));
}

/**
 * @brief Unpacks WF_LNA_REG's fields from current value of the WF_LNA_REG register.
 *
 * Reads the WF_LNA_REG register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] wflna5gen0 - Will be populated with the current value of this field from the register.
 * @param[out] wflna5gen1 - Will be populated with the current value of this field from the register.
 * @param[out] wflna24gen0 - Will be populated with the current value of this field from the register.
 * @param[out] wflna24gen1 - Will be populated with the current value of this field from the register.
 * @param[out] lnavcmresshort - Will be populated with the current value of this field from the register.
 * @param[out] wfrmx5gen - Will be populated with the current value of this field from the register.
 * @param[out] wfrmx24gen - Will be populated with the current value of this field from the register.
 * @param[out] wfrmximgcalen - Will be populated with the current value of this field from the register.
 */
__INLINE void wlan_rf_wf_lna_reg_unpack(uint8_t* wflna5gen0, uint8_t* wflna5gen1, uint8_t* wflna24gen0, uint8_t* wflna24gen1, uint8_t* lnavcmresshort, uint8_t* wfrmx5gen, uint8_t* wfrmx24gen, uint8_t* wfrmximgcalen)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_LNA_REG_ADDR);

    *wflna5gen0 = (localVal & ((uint32_t)0x00800000)) >> 23;
    *wflna5gen1 = (localVal & ((uint32_t)0x00400000)) >> 22;
    *wflna24gen0 = (localVal & ((uint32_t)0x00200000)) >> 21;
    *wflna24gen1 = (localVal & ((uint32_t)0x00100000)) >> 20;
    *lnavcmresshort = (localVal & ((uint32_t)0x00000800)) >> 11;
    *wfrmx5gen = (localVal & ((uint32_t)0x00000008)) >> 3;
    *wfrmx24gen = (localVal & ((uint32_t)0x00000004)) >> 2;
    *wfrmximgcalen = (localVal & ((uint32_t)0x00000002)) >> 1;
}

/**
 * @brief Returns the current value of the wf_lna5g_en0 field in the WF_LNA_REG register.
 *
 * The WF_LNA_REG register will be read and the wf_lna5g_en0 field's value will be returned.
 *
 * @return The current value of the wf_lna5g_en0 field in the WF_LNA_REG register.
 */
__INLINE uint8_t wlan_rf_wf_lna_5g_en_0_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_LNA_REG_ADDR);
    return ((localVal & ((uint32_t)0x00800000)) >> 23);
}

/**
 * @brief Sets the wf_lna5g_en0 field of the WF_LNA_REG register.
 *
 * The WF_LNA_REG register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wflna5gen0 - The value to set the field to.
 */
__INLINE void wlan_rf_wf_lna_5g_en_0_setf(uint8_t wflna5gen0)
{
    REG_PL_WR(WLAN_RF_WF_LNA_REG_ADDR, (REG_PL_RD(WLAN_RF_WF_LNA_REG_ADDR) & ~((uint32_t)0x00800000)) | ((uint32_t)wflna5gen0 << 23));
}

/**
 * @brief Returns the current value of the wf_lna5g_en1 field in the WF_LNA_REG register.
 *
 * The WF_LNA_REG register will be read and the wf_lna5g_en1 field's value will be returned.
 *
 * @return The current value of the wf_lna5g_en1 field in the WF_LNA_REG register.
 */
__INLINE uint8_t wlan_rf_wf_lna_5g_en_1_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_LNA_REG_ADDR);
    return ((localVal & ((uint32_t)0x00400000)) >> 22);
}

/**
 * @brief Sets the wf_lna5g_en1 field of the WF_LNA_REG register.
 *
 * The WF_LNA_REG register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wflna5gen1 - The value to set the field to.
 */
__INLINE void wlan_rf_wf_lna_5g_en_1_setf(uint8_t wflna5gen1)
{
    REG_PL_WR(WLAN_RF_WF_LNA_REG_ADDR, (REG_PL_RD(WLAN_RF_WF_LNA_REG_ADDR) & ~((uint32_t)0x00400000)) | ((uint32_t)wflna5gen1 << 22));
}

/**
 * @brief Returns the current value of the wf_lna24g_en0 field in the WF_LNA_REG register.
 *
 * The WF_LNA_REG register will be read and the wf_lna24g_en0 field's value will be returned.
 *
 * @return The current value of the wf_lna24g_en0 field in the WF_LNA_REG register.
 */
__INLINE uint8_t wlan_rf_wf_lna_24g_en_0_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_LNA_REG_ADDR);
    return ((localVal & ((uint32_t)0x00200000)) >> 21);
}

/**
 * @brief Sets the wf_lna24g_en0 field of the WF_LNA_REG register.
 *
 * The WF_LNA_REG register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wflna24gen0 - The value to set the field to.
 */
__INLINE void wlan_rf_wf_lna_24g_en_0_setf(uint8_t wflna24gen0)
{
    REG_PL_WR(WLAN_RF_WF_LNA_REG_ADDR, (REG_PL_RD(WLAN_RF_WF_LNA_REG_ADDR) & ~((uint32_t)0x00200000)) | ((uint32_t)wflna24gen0 << 21));
}

/**
 * @brief Returns the current value of the wf_lna24g_en1 field in the WF_LNA_REG register.
 *
 * The WF_LNA_REG register will be read and the wf_lna24g_en1 field's value will be returned.
 *
 * @return The current value of the wf_lna24g_en1 field in the WF_LNA_REG register.
 */
__INLINE uint8_t wlan_rf_wf_lna_24g_en_1_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_LNA_REG_ADDR);
    return ((localVal & ((uint32_t)0x00100000)) >> 20);
}

/**
 * @brief Sets the wf_lna24g_en1 field of the WF_LNA_REG register.
 *
 * The WF_LNA_REG register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wflna24gen1 - The value to set the field to.
 */
__INLINE void wlan_rf_wf_lna_24g_en_1_setf(uint8_t wflna24gen1)
{
    REG_PL_WR(WLAN_RF_WF_LNA_REG_ADDR, (REG_PL_RD(WLAN_RF_WF_LNA_REG_ADDR) & ~((uint32_t)0x00100000)) | ((uint32_t)wflna24gen1 << 20));
}

/**
 * @brief Returns the current value of the lna_vcm_res_short field in the WF_LNA_REG register.
 *
 * The WF_LNA_REG register will be read and the lna_vcm_res_short field's value will be returned.
 *
 * @return The current value of the lna_vcm_res_short field in the WF_LNA_REG register.
 */
__INLINE uint8_t wlan_rf_lna_vcm_res_short_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_LNA_REG_ADDR);
    return ((localVal & ((uint32_t)0x00000800)) >> 11);
}

/**
 * @brief Sets the lna_vcm_res_short field of the WF_LNA_REG register.
 *
 * The WF_LNA_REG register will be read, modified to contain the new field value, and written.
 *
 * @param[in] lnavcmresshort - The value to set the field to.
 */
__INLINE void wlan_rf_lna_vcm_res_short_setf(uint8_t lnavcmresshort)
{
    REG_PL_WR(WLAN_RF_WF_LNA_REG_ADDR, (REG_PL_RD(WLAN_RF_WF_LNA_REG_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)lnavcmresshort << 11));
}

/**
 * @brief Returns the current value of the wf_rmx5g_en field in the WF_LNA_REG register.
 *
 * The WF_LNA_REG register will be read and the wf_rmx5g_en field's value will be returned.
 *
 * @return The current value of the wf_rmx5g_en field in the WF_LNA_REG register.
 */
__INLINE uint8_t wlan_rf_wf_rmx_5g_en_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_LNA_REG_ADDR);
    return ((localVal & ((uint32_t)0x00000008)) >> 3);
}

/**
 * @brief Sets the wf_rmx5g_en field of the WF_LNA_REG register.
 *
 * The WF_LNA_REG register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wfrmx5gen - The value to set the field to.
 */
__INLINE void wlan_rf_wf_rmx_5g_en_setf(uint8_t wfrmx5gen)
{
    REG_PL_WR(WLAN_RF_WF_LNA_REG_ADDR, (REG_PL_RD(WLAN_RF_WF_LNA_REG_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)wfrmx5gen << 3));
}

/**
 * @brief Returns the current value of the wf_rmx24g_en field in the WF_LNA_REG register.
 *
 * The WF_LNA_REG register will be read and the wf_rmx24g_en field's value will be returned.
 *
 * @return The current value of the wf_rmx24g_en field in the WF_LNA_REG register.
 */
__INLINE uint8_t wlan_rf_wf_rmx_24g_en_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_LNA_REG_ADDR);
    return ((localVal & ((uint32_t)0x00000004)) >> 2);
}

/**
 * @brief Sets the wf_rmx24g_en field of the WF_LNA_REG register.
 *
 * The WF_LNA_REG register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wfrmx24gen - The value to set the field to.
 */
__INLINE void wlan_rf_wf_rmx_24g_en_setf(uint8_t wfrmx24gen)
{
    REG_PL_WR(WLAN_RF_WF_LNA_REG_ADDR, (REG_PL_RD(WLAN_RF_WF_LNA_REG_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)wfrmx24gen << 2));
}

/**
 * @brief Returns the current value of the wf_rmx_img_cal_en field in the WF_LNA_REG register.
 *
 * The WF_LNA_REG register will be read and the wf_rmx_img_cal_en field's value will be returned.
 *
 * @return The current value of the wf_rmx_img_cal_en field in the WF_LNA_REG register.
 */
__INLINE uint8_t wlan_rf_wf_rmx_img_cal_en_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_LNA_REG_ADDR);
    return ((localVal & ((uint32_t)0x00000002)) >> 1);
}

/**
 * @brief Sets the wf_rmx_img_cal_en field of the WF_LNA_REG register.
 *
 * The WF_LNA_REG register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wfrmximgcalen - The value to set the field to.
 */
__INLINE void wlan_rf_wf_rmx_img_cal_en_setf(uint8_t wfrmximgcalen)
{
    REG_PL_WR(WLAN_RF_WF_LNA_REG_ADDR, (REG_PL_RD(WLAN_RF_WF_LNA_REG_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)wfrmximgcalen << 1));
}

/// @}

/**
 * @name WF_TIA_CONFIG register definitions
 * <table>
 * <caption id="WF_TIA_CONFIG_BF">WF_TIA_CONFIG bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>11 <td>     wf_tia_aux_en <td>R <td>R/W <td>0
 * <tr><td>08:06 <td>wf_tia_input_sel_aux <td>R <td>R/W <td>0x0
 * </table>
 *
 * @{
 */

/// Address of the WF_TIA_CONFIG register
#define WLAN_RF_WF_TIA_CONFIG_ADDR   0x40344018
/// Offset of the WF_TIA_CONFIG register from the base address
#define WLAN_RF_WF_TIA_CONFIG_OFFSET 0x00000018
/// Index of the WF_TIA_CONFIG register
#define WLAN_RF_WF_TIA_CONFIG_INDEX  0x00000006
/// Reset value of the WF_TIA_CONFIG register
#define WLAN_RF_WF_TIA_CONFIG_RESET  0x00000000

/**
 * @brief Returns the current value of the WF_TIA_CONFIG register.
 * The WF_TIA_CONFIG register will be read and its value returned.
 * @return The current value of the WF_TIA_CONFIG register.
 */
__INLINE uint32_t wlan_rf_wf_tia_config_get(void)
{
    return REG_PL_RD(WLAN_RF_WF_TIA_CONFIG_ADDR);
}

/**
 * @brief Sets the WF_TIA_CONFIG register to a value.
 * The WF_TIA_CONFIG register will be written.
 * @param value - The value to write.
 */
__INLINE void wlan_rf_wf_tia_config_set(uint32_t value)
{
    REG_PL_WR(WLAN_RF_WF_TIA_CONFIG_ADDR, value);
}

// field definitions
/// WF_TIA_AUX_EN field bit
#define WLAN_RF_WF_TIA_AUX_EN_BIT           ((uint32_t)0x00000800)
/// WF_TIA_AUX_EN field position
#define WLAN_RF_WF_TIA_AUX_EN_POS           11
/// WF_TIA_INPUT_SEL_AUX field mask
#define WLAN_RF_WF_TIA_INPUT_SEL_AUX_MASK   ((uint32_t)0x000001C0)
/// WF_TIA_INPUT_SEL_AUX field LSB position
#define WLAN_RF_WF_TIA_INPUT_SEL_AUX_LSB    6
/// WF_TIA_INPUT_SEL_AUX field width
#define WLAN_RF_WF_TIA_INPUT_SEL_AUX_WIDTH  ((uint32_t)0x00000003)

/// WF_TIA_AUX_EN field reset value
#define WLAN_RF_WF_TIA_AUX_EN_RST           0x0
/// WF_TIA_INPUT_SEL_AUX field reset value
#define WLAN_RF_WF_TIA_INPUT_SEL_AUX_RST    0x0

/**
 * @brief Constructs a value for the WF_TIA_CONFIG register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] wftiaauxen - The value to use for the wf_tia_aux_en field.
 * @param[in] wftiainputselaux - The value to use for the wf_tia_input_sel_aux field.
 */
__INLINE void wlan_rf_wf_tia_config_pack(uint8_t wftiaauxen, uint8_t wftiainputselaux)
{
    REG_PL_WR(WLAN_RF_WF_TIA_CONFIG_ADDR,  ((uint32_t)wftiaauxen << 11) | ((uint32_t)wftiainputselaux << 6));
}

/**
 * @brief Unpacks WF_TIA_CONFIG's fields from current value of the WF_TIA_CONFIG register.
 *
 * Reads the WF_TIA_CONFIG register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] wftiaauxen - Will be populated with the current value of this field from the register.
 * @param[out] wftiainputselaux - Will be populated with the current value of this field from the register.
 */
__INLINE void wlan_rf_wf_tia_config_unpack(uint8_t* wftiaauxen, uint8_t* wftiainputselaux)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_TIA_CONFIG_ADDR);

    *wftiaauxen = (localVal & ((uint32_t)0x00000800)) >> 11;
    *wftiainputselaux = (localVal & ((uint32_t)0x000001C0)) >> 6;
}

/**
 * @brief Returns the current value of the wf_tia_aux_en field in the WF_TIA_CONFIG register.
 *
 * The WF_TIA_CONFIG register will be read and the wf_tia_aux_en field's value will be returned.
 *
 * @return The current value of the wf_tia_aux_en field in the WF_TIA_CONFIG register.
 */
__INLINE uint8_t wlan_rf_wf_tia_aux_en_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_TIA_CONFIG_ADDR);
    return ((localVal & ((uint32_t)0x00000800)) >> 11);
}

/**
 * @brief Sets the wf_tia_aux_en field of the WF_TIA_CONFIG register.
 *
 * The WF_TIA_CONFIG register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wftiaauxen - The value to set the field to.
 */
__INLINE void wlan_rf_wf_tia_aux_en_setf(uint8_t wftiaauxen)
{
    REG_PL_WR(WLAN_RF_WF_TIA_CONFIG_ADDR, (REG_PL_RD(WLAN_RF_WF_TIA_CONFIG_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)wftiaauxen << 11));
}

/**
 * @brief Returns the current value of the wf_tia_input_sel_aux field in the WF_TIA_CONFIG register.
 *
 * The WF_TIA_CONFIG register will be read and the wf_tia_input_sel_aux field's value will be returned.
 *
 * @return The current value of the wf_tia_input_sel_aux field in the WF_TIA_CONFIG register.
 */
__INLINE uint8_t wlan_rf_wf_tia_input_sel_aux_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_TIA_CONFIG_ADDR);
    return ((localVal & ((uint32_t)0x000001C0)) >> 6);
}

/**
 * @brief Sets the wf_tia_input_sel_aux field of the WF_TIA_CONFIG register.
 *
 * The WF_TIA_CONFIG register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wftiainputselaux - The value to set the field to.
 */
__INLINE void wlan_rf_wf_tia_input_sel_aux_setf(uint8_t wftiainputselaux)
{
    REG_PL_WR(WLAN_RF_WF_TIA_CONFIG_ADDR, (REG_PL_RD(WLAN_RF_WF_TIA_CONFIG_ADDR) & ~((uint32_t)0x000001C0)) | ((uint32_t)wftiainputselaux << 6));
}

/// @}

/**
 * @name WF_TIA_AUX_BUF_GBIT register definitions
 * <table>
 * <caption id="WF_TIA_AUX_BUF_GBIT_BF">WF_TIA_AUX_BUF_GBIT bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>09:07 <td>wf_tia_aux_buf_gbit <td>R <td>R/W <td>0x0
 * </table>
 *
 * @{
 */

/// Address of the WF_TIA_AUX_BUF_GBIT register
#define WLAN_RF_WF_TIA_AUX_BUF_GBIT_ADDR   0x4034401C
/// Offset of the WF_TIA_AUX_BUF_GBIT register from the base address
#define WLAN_RF_WF_TIA_AUX_BUF_GBIT_OFFSET 0x0000001C
/// Index of the WF_TIA_AUX_BUF_GBIT register
#define WLAN_RF_WF_TIA_AUX_BUF_GBIT_INDEX  0x00000007
/// Reset value of the WF_TIA_AUX_BUF_GBIT register
#define WLAN_RF_WF_TIA_AUX_BUF_GBIT_RESET  0x00000000

/**
 * @brief Returns the current value of the WF_TIA_AUX_BUF_GBIT register.
 * The WF_TIA_AUX_BUF_GBIT register will be read and its value returned.
 * @return The current value of the WF_TIA_AUX_BUF_GBIT register.
 */
__INLINE uint32_t wlan_rf_wf_tia_aux_buf_gbit_get(void)
{
    return REG_PL_RD(WLAN_RF_WF_TIA_AUX_BUF_GBIT_ADDR);
}

/**
 * @brief Sets the WF_TIA_AUX_BUF_GBIT register to a value.
 * The WF_TIA_AUX_BUF_GBIT register will be written.
 * @param value - The value to write.
 */
__INLINE void wlan_rf_wf_tia_aux_buf_gbit_set(uint32_t value)
{
    REG_PL_WR(WLAN_RF_WF_TIA_AUX_BUF_GBIT_ADDR, value);
}

// field definitions
/// WF_TIA_AUX_BUF_GBIT field mask
#define WLAN_RF_WF_TIA_AUX_BUF_GBIT_MASK   ((uint32_t)0x00000380)
/// WF_TIA_AUX_BUF_GBIT field LSB position
#define WLAN_RF_WF_TIA_AUX_BUF_GBIT_LSB    7
/// WF_TIA_AUX_BUF_GBIT field width
#define WLAN_RF_WF_TIA_AUX_BUF_GBIT_WIDTH  ((uint32_t)0x00000003)

/// WF_TIA_AUX_BUF_GBIT field reset value
#define WLAN_RF_WF_TIA_AUX_BUF_GBIT_RST    0x0

/**
 * @brief Returns the current value of the wf_tia_aux_buf_gbit field in the WF_TIA_AUX_BUF_GBIT register.
 *
 * The WF_TIA_AUX_BUF_GBIT register will be read and the wf_tia_aux_buf_gbit field's value will be returned.
 *
 * @return The current value of the wf_tia_aux_buf_gbit field in the WF_TIA_AUX_BUF_GBIT register.
 */
__INLINE uint8_t wlan_rf_wf_tia_aux_buf_gbit_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_TIA_AUX_BUF_GBIT_ADDR);
    return (localVal >> 7);
}

/**
 * @brief Sets the wf_tia_aux_buf_gbit field of the WF_TIA_AUX_BUF_GBIT register.
 *
 * The WF_TIA_AUX_BUF_GBIT register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wftiaauxbufgbit - The value to set the field to.
 */
__INLINE void wlan_rf_wf_tia_aux_buf_gbit_setf(uint8_t wftiaauxbufgbit)
{
    REG_PL_WR(WLAN_RF_WF_TIA_AUX_BUF_GBIT_ADDR, (uint32_t)wftiaauxbufgbit << 7);
}

/// @}

/**
 * @name WF_RXFLT_REG register definitions
 * <table>
 * <caption id="WF_RXFLT_REG_BF">WF_RXFLT_REG bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>11 <td>  wf_rxflt_bw_mode <td>R <td>R/W <td>0
 * <tr><td>10:09 <td> wf_rxflt_vcm_vbit <td>R <td>R/W <td>0x0
 * </table>
 *
 * @{
 */

/// Address of the WF_RXFLT_REG register
#define WLAN_RF_WF_RXFLT_REG_ADDR   0x40344020
/// Offset of the WF_RXFLT_REG register from the base address
#define WLAN_RF_WF_RXFLT_REG_OFFSET 0x00000020
/// Index of the WF_RXFLT_REG register
#define WLAN_RF_WF_RXFLT_REG_INDEX  0x00000008
/// Reset value of the WF_RXFLT_REG register
#define WLAN_RF_WF_RXFLT_REG_RESET  0x00000000

/**
 * @brief Returns the current value of the WF_RXFLT_REG register.
 * The WF_RXFLT_REG register will be read and its value returned.
 * @return The current value of the WF_RXFLT_REG register.
 */
__INLINE uint32_t wlan_rf_wf_rxflt_reg_get(void)
{
    return REG_PL_RD(WLAN_RF_WF_RXFLT_REG_ADDR);
}

/**
 * @brief Sets the WF_RXFLT_REG register to a value.
 * The WF_RXFLT_REG register will be written.
 * @param value - The value to write.
 */
__INLINE void wlan_rf_wf_rxflt_reg_set(uint32_t value)
{
    REG_PL_WR(WLAN_RF_WF_RXFLT_REG_ADDR, value);
}

// field definitions
/// WF_RXFLT_BW_MODE field bit
#define WLAN_RF_WF_RXFLT_BW_MODE_BIT     ((uint32_t)0x00000800)
/// WF_RXFLT_BW_MODE field position
#define WLAN_RF_WF_RXFLT_BW_MODE_POS     11
/// WF_RXFLT_VCM_VBIT field mask
#define WLAN_RF_WF_RXFLT_VCM_VBIT_MASK   ((uint32_t)0x00000600)
/// WF_RXFLT_VCM_VBIT field LSB position
#define WLAN_RF_WF_RXFLT_VCM_VBIT_LSB    9
/// WF_RXFLT_VCM_VBIT field width
#define WLAN_RF_WF_RXFLT_VCM_VBIT_WIDTH  ((uint32_t)0x00000002)

/// WF_RXFLT_BW_MODE field reset value
#define WLAN_RF_WF_RXFLT_BW_MODE_RST     0x0
/// WF_RXFLT_VCM_VBIT field reset value
#define WLAN_RF_WF_RXFLT_VCM_VBIT_RST    0x0

/**
 * @brief Constructs a value for the WF_RXFLT_REG register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] wfrxfltbwmode - The value to use for the wf_rxflt_bw_mode field.
 * @param[in] wfrxfltvcmvbit - The value to use for the wf_rxflt_vcm_vbit field.
 */
__INLINE void wlan_rf_wf_rxflt_reg_pack(uint8_t wfrxfltbwmode, uint8_t wfrxfltvcmvbit)
{
    REG_PL_WR(WLAN_RF_WF_RXFLT_REG_ADDR,  ((uint32_t)wfrxfltbwmode << 11) | ((uint32_t)wfrxfltvcmvbit << 9));
}

/**
 * @brief Unpacks WF_RXFLT_REG's fields from current value of the WF_RXFLT_REG register.
 *
 * Reads the WF_RXFLT_REG register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] wfrxfltbwmode - Will be populated with the current value of this field from the register.
 * @param[out] wfrxfltvcmvbit - Will be populated with the current value of this field from the register.
 */
__INLINE void wlan_rf_wf_rxflt_reg_unpack(uint8_t* wfrxfltbwmode, uint8_t* wfrxfltvcmvbit)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_RXFLT_REG_ADDR);

    *wfrxfltbwmode = (localVal & ((uint32_t)0x00000800)) >> 11;
    *wfrxfltvcmvbit = (localVal & ((uint32_t)0x00000600)) >> 9;
}

/**
 * @brief Returns the current value of the wf_rxflt_bw_mode field in the WF_RXFLT_REG register.
 *
 * The WF_RXFLT_REG register will be read and the wf_rxflt_bw_mode field's value will be returned.
 *
 * @return The current value of the wf_rxflt_bw_mode field in the WF_RXFLT_REG register.
 */
__INLINE uint8_t wlan_rf_wf_rxflt_bw_mode_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_RXFLT_REG_ADDR);
    return ((localVal & ((uint32_t)0x00000800)) >> 11);
}

/**
 * @brief Sets the wf_rxflt_bw_mode field of the WF_RXFLT_REG register.
 *
 * The WF_RXFLT_REG register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wfrxfltbwmode - The value to set the field to.
 */
__INLINE void wlan_rf_wf_rxflt_bw_mode_setf(uint8_t wfrxfltbwmode)
{
    REG_PL_WR(WLAN_RF_WF_RXFLT_REG_ADDR, (REG_PL_RD(WLAN_RF_WF_RXFLT_REG_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)wfrxfltbwmode << 11));
}

/**
 * @brief Returns the current value of the wf_rxflt_vcm_vbit field in the WF_RXFLT_REG register.
 *
 * The WF_RXFLT_REG register will be read and the wf_rxflt_vcm_vbit field's value will be returned.
 *
 * @return The current value of the wf_rxflt_vcm_vbit field in the WF_RXFLT_REG register.
 */
__INLINE uint8_t wlan_rf_wf_rxflt_vcm_vbit_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_RXFLT_REG_ADDR);
    return ((localVal & ((uint32_t)0x00000600)) >> 9);
}

/**
 * @brief Sets the wf_rxflt_vcm_vbit field of the WF_RXFLT_REG register.
 *
 * The WF_RXFLT_REG register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wfrxfltvcmvbit - The value to set the field to.
 */
__INLINE void wlan_rf_wf_rxflt_vcm_vbit_setf(uint8_t wfrxfltvcmvbit)
{
    REG_PL_WR(WLAN_RF_WF_RXFLT_REG_ADDR, (REG_PL_RD(WLAN_RF_WF_RXFLT_REG_ADDR) & ~((uint32_t)0x00000600)) | ((uint32_t)wfrxfltvcmvbit << 9));
}

/// @}

/**
 * @name WF_ADC_CONFIG register definitions
 * <table>
 * <caption id="WF_ADC_CONFIG_BF">WF_ADC_CONFIG bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>22 <td>     wf_adc_aux_en <td>R <td>R/W <td>0
 * <tr><td>20:17 <td>   wf_adc_cmp_ibit <td>R <td>R/W <td>0x0
 * <tr><td>16:15 <td>wf_adc_clk_sel_bit <td>R <td>R/W <td>0x0
 * <tr><td>13:10 <td>    wf_adc_dly_bit <td>R <td>R/W <td>0x0
 * </table>
 *
 * @{
 */

/// Address of the WF_ADC_CONFIG register
#define WLAN_RF_WF_ADC_CONFIG_ADDR   0x40344024
/// Offset of the WF_ADC_CONFIG register from the base address
#define WLAN_RF_WF_ADC_CONFIG_OFFSET 0x00000024
/// Index of the WF_ADC_CONFIG register
#define WLAN_RF_WF_ADC_CONFIG_INDEX  0x00000009
/// Reset value of the WF_ADC_CONFIG register
#define WLAN_RF_WF_ADC_CONFIG_RESET  0x00000000

/**
 * @brief Returns the current value of the WF_ADC_CONFIG register.
 * The WF_ADC_CONFIG register will be read and its value returned.
 * @return The current value of the WF_ADC_CONFIG register.
 */
__INLINE uint32_t wlan_rf_wf_adc_config_get(void)
{
    return REG_PL_RD(WLAN_RF_WF_ADC_CONFIG_ADDR);
}

/**
 * @brief Sets the WF_ADC_CONFIG register to a value.
 * The WF_ADC_CONFIG register will be written.
 * @param value - The value to write.
 */
__INLINE void wlan_rf_wf_adc_config_set(uint32_t value)
{
    REG_PL_WR(WLAN_RF_WF_ADC_CONFIG_ADDR, value);
}

// field definitions
/// WF_ADC_AUX_EN field bit
#define WLAN_RF_WF_ADC_AUX_EN_BIT         ((uint32_t)0x00400000)
/// WF_ADC_AUX_EN field position
#define WLAN_RF_WF_ADC_AUX_EN_POS         22
/// WF_ADC_CMP_IBIT field mask
#define WLAN_RF_WF_ADC_CMP_IBIT_MASK      ((uint32_t)0x001E0000)
/// WF_ADC_CMP_IBIT field LSB position
#define WLAN_RF_WF_ADC_CMP_IBIT_LSB       17
/// WF_ADC_CMP_IBIT field width
#define WLAN_RF_WF_ADC_CMP_IBIT_WIDTH     ((uint32_t)0x00000004)
/// WF_ADC_CLK_SEL_BIT field mask
#define WLAN_RF_WF_ADC_CLK_SEL_BIT_MASK   ((uint32_t)0x00018000)
/// WF_ADC_CLK_SEL_BIT field LSB position
#define WLAN_RF_WF_ADC_CLK_SEL_BIT_LSB    15
/// WF_ADC_CLK_SEL_BIT field width
#define WLAN_RF_WF_ADC_CLK_SEL_BIT_WIDTH  ((uint32_t)0x00000002)
/// WF_ADC_DLY_BIT field mask
#define WLAN_RF_WF_ADC_DLY_BIT_MASK       ((uint32_t)0x00003C00)
/// WF_ADC_DLY_BIT field LSB position
#define WLAN_RF_WF_ADC_DLY_BIT_LSB        10
/// WF_ADC_DLY_BIT field width
#define WLAN_RF_WF_ADC_DLY_BIT_WIDTH      ((uint32_t)0x00000004)

/// WF_ADC_AUX_EN field reset value
#define WLAN_RF_WF_ADC_AUX_EN_RST         0x0
/// WF_ADC_CMP_IBIT field reset value
#define WLAN_RF_WF_ADC_CMP_IBIT_RST       0x0
/// WF_ADC_CLK_SEL_BIT field reset value
#define WLAN_RF_WF_ADC_CLK_SEL_BIT_RST    0x0
/// WF_ADC_DLY_BIT field reset value
#define WLAN_RF_WF_ADC_DLY_BIT_RST        0x0

/**
 * @brief Constructs a value for the WF_ADC_CONFIG register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] wfadcauxen - The value to use for the wf_adc_aux_en field.
 * @param[in] wfadccmpibit - The value to use for the wf_adc_cmp_ibit field.
 * @param[in] wfadcclkselbit - The value to use for the wf_adc_clk_sel_bit field.
 * @param[in] wfadcdlybit - The value to use for the wf_adc_dly_bit field.
 */
__INLINE void wlan_rf_wf_adc_config_pack(uint8_t wfadcauxen, uint8_t wfadccmpibit, uint8_t wfadcclkselbit, uint8_t wfadcdlybit)
{
    REG_PL_WR(WLAN_RF_WF_ADC_CONFIG_ADDR,  ((uint32_t)wfadcauxen << 22) | ((uint32_t)wfadccmpibit << 17) | ((uint32_t)wfadcclkselbit << 15) | ((uint32_t)wfadcdlybit << 10));
}

/**
 * @brief Unpacks WF_ADC_CONFIG's fields from current value of the WF_ADC_CONFIG register.
 *
 * Reads the WF_ADC_CONFIG register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] wfadcauxen - Will be populated with the current value of this field from the register.
 * @param[out] wfadccmpibit - Will be populated with the current value of this field from the register.
 * @param[out] wfadcclkselbit - Will be populated with the current value of this field from the register.
 * @param[out] wfadcdlybit - Will be populated with the current value of this field from the register.
 */
__INLINE void wlan_rf_wf_adc_config_unpack(uint8_t* wfadcauxen, uint8_t* wfadccmpibit, uint8_t* wfadcclkselbit, uint8_t* wfadcdlybit)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_ADC_CONFIG_ADDR);

    *wfadcauxen = (localVal & ((uint32_t)0x00400000)) >> 22;
    *wfadccmpibit = (localVal & ((uint32_t)0x001E0000)) >> 17;
    *wfadcclkselbit = (localVal & ((uint32_t)0x00018000)) >> 15;
    *wfadcdlybit = (localVal & ((uint32_t)0x00003C00)) >> 10;
}

/**
 * @brief Returns the current value of the wf_adc_aux_en field in the WF_ADC_CONFIG register.
 *
 * The WF_ADC_CONFIG register will be read and the wf_adc_aux_en field's value will be returned.
 *
 * @return The current value of the wf_adc_aux_en field in the WF_ADC_CONFIG register.
 */
__INLINE uint8_t wlan_rf_wf_adc_aux_en_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_ADC_CONFIG_ADDR);
    return ((localVal & ((uint32_t)0x00400000)) >> 22);
}

/**
 * @brief Sets the wf_adc_aux_en field of the WF_ADC_CONFIG register.
 *
 * The WF_ADC_CONFIG register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wfadcauxen - The value to set the field to.
 */
__INLINE void wlan_rf_wf_adc_aux_en_setf(uint8_t wfadcauxen)
{
    REG_PL_WR(WLAN_RF_WF_ADC_CONFIG_ADDR, (REG_PL_RD(WLAN_RF_WF_ADC_CONFIG_ADDR) & ~((uint32_t)0x00400000)) | ((uint32_t)wfadcauxen << 22));
}

/**
 * @brief Returns the current value of the wf_adc_cmp_ibit field in the WF_ADC_CONFIG register.
 *
 * The WF_ADC_CONFIG register will be read and the wf_adc_cmp_ibit field's value will be returned.
 *
 * @return The current value of the wf_adc_cmp_ibit field in the WF_ADC_CONFIG register.
 */
__INLINE uint8_t wlan_rf_wf_adc_cmp_ibit_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_ADC_CONFIG_ADDR);
    return ((localVal & ((uint32_t)0x001E0000)) >> 17);
}

/**
 * @brief Sets the wf_adc_cmp_ibit field of the WF_ADC_CONFIG register.
 *
 * The WF_ADC_CONFIG register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wfadccmpibit - The value to set the field to.
 */
__INLINE void wlan_rf_wf_adc_cmp_ibit_setf(uint8_t wfadccmpibit)
{
    REG_PL_WR(WLAN_RF_WF_ADC_CONFIG_ADDR, (REG_PL_RD(WLAN_RF_WF_ADC_CONFIG_ADDR) & ~((uint32_t)0x001E0000)) | ((uint32_t)wfadccmpibit << 17));
}

/**
 * @brief Returns the current value of the wf_adc_clk_sel_bit field in the WF_ADC_CONFIG register.
 *
 * The WF_ADC_CONFIG register will be read and the wf_adc_clk_sel_bit field's value will be returned.
 *
 * @return The current value of the wf_adc_clk_sel_bit field in the WF_ADC_CONFIG register.
 */
__INLINE uint8_t wlan_rf_wf_adc_clk_sel_bit_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_ADC_CONFIG_ADDR);
    return ((localVal & ((uint32_t)0x00018000)) >> 15);
}

/**
 * @brief Sets the wf_adc_clk_sel_bit field of the WF_ADC_CONFIG register.
 *
 * The WF_ADC_CONFIG register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wfadcclkselbit - The value to set the field to.
 */
__INLINE void wlan_rf_wf_adc_clk_sel_bit_setf(uint8_t wfadcclkselbit)
{
    REG_PL_WR(WLAN_RF_WF_ADC_CONFIG_ADDR, (REG_PL_RD(WLAN_RF_WF_ADC_CONFIG_ADDR) & ~((uint32_t)0x00018000)) | ((uint32_t)wfadcclkselbit << 15));
}

/**
 * @brief Returns the current value of the wf_adc_dly_bit field in the WF_ADC_CONFIG register.
 *
 * The WF_ADC_CONFIG register will be read and the wf_adc_dly_bit field's value will be returned.
 *
 * @return The current value of the wf_adc_dly_bit field in the WF_ADC_CONFIG register.
 */
__INLINE uint8_t wlan_rf_wf_adc_dly_bit_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_ADC_CONFIG_ADDR);
    return ((localVal & ((uint32_t)0x00003C00)) >> 10);
}

/**
 * @brief Sets the wf_adc_dly_bit field of the WF_ADC_CONFIG register.
 *
 * The WF_ADC_CONFIG register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wfadcdlybit - The value to set the field to.
 */
__INLINE void wlan_rf_wf_adc_dly_bit_setf(uint8_t wfadcdlybit)
{
    REG_PL_WR(WLAN_RF_WF_ADC_CONFIG_ADDR, (REG_PL_RD(WLAN_RF_WF_ADC_CONFIG_ADDR) & ~((uint32_t)0x00003C00)) | ((uint32_t)wfadcdlybit << 10));
}

/// @}

/**
 * @name WF_ADC_CONFIG2 register definitions
 * <table>
 * <caption id="WF_ADC_CONFIG2_BF">WF_ADC_CONFIG2 bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>06 <td>wf_adc_vref_stb_en <td>R <td>R/W <td>0
 * <tr><td>05 <td>wf_adc_iq_synch_en <td>R <td>R/W <td>0
 * </table>
 *
 * @{
 */

/// Address of the WF_ADC_CONFIG2 register
#define WLAN_RF_WF_ADC_CONFIG2_ADDR   0x40344028
/// Offset of the WF_ADC_CONFIG2 register from the base address
#define WLAN_RF_WF_ADC_CONFIG2_OFFSET 0x00000028
/// Index of the WF_ADC_CONFIG2 register
#define WLAN_RF_WF_ADC_CONFIG2_INDEX  0x0000000A
/// Reset value of the WF_ADC_CONFIG2 register
#define WLAN_RF_WF_ADC_CONFIG2_RESET  0x00000000

/**
 * @brief Returns the current value of the WF_ADC_CONFIG2 register.
 * The WF_ADC_CONFIG2 register will be read and its value returned.
 * @return The current value of the WF_ADC_CONFIG2 register.
 */
__INLINE uint32_t wlan_rf_wf_adc_config2_get(void)
{
    return REG_PL_RD(WLAN_RF_WF_ADC_CONFIG2_ADDR);
}

/**
 * @brief Sets the WF_ADC_CONFIG2 register to a value.
 * The WF_ADC_CONFIG2 register will be written.
 * @param value - The value to write.
 */
__INLINE void wlan_rf_wf_adc_config2_set(uint32_t value)
{
    REG_PL_WR(WLAN_RF_WF_ADC_CONFIG2_ADDR, value);
}

// field definitions
/// WF_ADC_VREF_STB_EN field bit
#define WLAN_RF_WF_ADC_VREF_STB_EN_BIT    ((uint32_t)0x00000040)
/// WF_ADC_VREF_STB_EN field position
#define WLAN_RF_WF_ADC_VREF_STB_EN_POS    6
/// WF_ADC_IQ_SYNCH_EN field bit
#define WLAN_RF_WF_ADC_IQ_SYNCH_EN_BIT    ((uint32_t)0x00000020)
/// WF_ADC_IQ_SYNCH_EN field position
#define WLAN_RF_WF_ADC_IQ_SYNCH_EN_POS    5

/// WF_ADC_VREF_STB_EN field reset value
#define WLAN_RF_WF_ADC_VREF_STB_EN_RST    0x0
/// WF_ADC_IQ_SYNCH_EN field reset value
#define WLAN_RF_WF_ADC_IQ_SYNCH_EN_RST    0x0

/**
 * @brief Constructs a value for the WF_ADC_CONFIG2 register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] wfadcvrefstben - The value to use for the wf_adc_vref_stb_en field.
 * @param[in] wfadciqsynchen - The value to use for the wf_adc_iq_synch_en field.
 */
__INLINE void wlan_rf_wf_adc_config2_pack(uint8_t wfadcvrefstben, uint8_t wfadciqsynchen)
{
    REG_PL_WR(WLAN_RF_WF_ADC_CONFIG2_ADDR,  ((uint32_t)wfadcvrefstben << 6) | ((uint32_t)wfadciqsynchen << 5));
}

/**
 * @brief Unpacks WF_ADC_CONFIG2's fields from current value of the WF_ADC_CONFIG2 register.
 *
 * Reads the WF_ADC_CONFIG2 register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] wfadcvrefstben - Will be populated with the current value of this field from the register.
 * @param[out] wfadciqsynchen - Will be populated with the current value of this field from the register.
 */
__INLINE void wlan_rf_wf_adc_config2_unpack(uint8_t* wfadcvrefstben, uint8_t* wfadciqsynchen)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_ADC_CONFIG2_ADDR);

    *wfadcvrefstben = (localVal & ((uint32_t)0x00000040)) >> 6;
    *wfadciqsynchen = (localVal & ((uint32_t)0x00000020)) >> 5;
}

/**
 * @brief Returns the current value of the wf_adc_vref_stb_en field in the WF_ADC_CONFIG2 register.
 *
 * The WF_ADC_CONFIG2 register will be read and the wf_adc_vref_stb_en field's value will be returned.
 *
 * @return The current value of the wf_adc_vref_stb_en field in the WF_ADC_CONFIG2 register.
 */
__INLINE uint8_t wlan_rf_wf_adc_vref_stb_en_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_ADC_CONFIG2_ADDR);
    return ((localVal & ((uint32_t)0x00000040)) >> 6);
}

/**
 * @brief Sets the wf_adc_vref_stb_en field of the WF_ADC_CONFIG2 register.
 *
 * The WF_ADC_CONFIG2 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wfadcvrefstben - The value to set the field to.
 */
__INLINE void wlan_rf_wf_adc_vref_stb_en_setf(uint8_t wfadcvrefstben)
{
    REG_PL_WR(WLAN_RF_WF_ADC_CONFIG2_ADDR, (REG_PL_RD(WLAN_RF_WF_ADC_CONFIG2_ADDR) & ~((uint32_t)0x00000040)) | ((uint32_t)wfadcvrefstben << 6));
}

/**
 * @brief Returns the current value of the wf_adc_iq_synch_en field in the WF_ADC_CONFIG2 register.
 *
 * The WF_ADC_CONFIG2 register will be read and the wf_adc_iq_synch_en field's value will be returned.
 *
 * @return The current value of the wf_adc_iq_synch_en field in the WF_ADC_CONFIG2 register.
 */
__INLINE uint8_t wlan_rf_wf_adc_iq_synch_en_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_ADC_CONFIG2_ADDR);
    return ((localVal & ((uint32_t)0x00000020)) >> 5);
}

/**
 * @brief Sets the wf_adc_iq_synch_en field of the WF_ADC_CONFIG2 register.
 *
 * The WF_ADC_CONFIG2 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wfadciqsynchen - The value to set the field to.
 */
__INLINE void wlan_rf_wf_adc_iq_synch_en_setf(uint8_t wfadciqsynchen)
{
    REG_PL_WR(WLAN_RF_WF_ADC_CONFIG2_ADDR, (REG_PL_RD(WLAN_RF_WF_ADC_CONFIG2_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)wfadciqsynchen << 5));
}

/// @}

/**
 * @name WF_LOFT_CONFIG register definitions
 * <table>
 * <caption id="WF_LOFT_CONFIG_BF">WF_LOFT_CONFIG bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>10 <td>        wf_loft_en <td>R <td>R/W <td>0
 * <tr><td>09:08 <td>      wf_loft_gbit <td>R <td>R/W <td>0x0
 * <tr><td>07 <td>   wf_loft_lp_mode <td>R <td>R/W <td>0
 * <tr><td>06 <td>     wf_loft_vi_en <td>R <td>R/W <td>0
 * <tr><td>05 <td>     wf_loft_vv_en <td>R <td>R/W <td>0
 * </table>
 *
 * @{
 */

/// Address of the WF_LOFT_CONFIG register
#define WLAN_RF_WF_LOFT_CONFIG_ADDR   0x4034402C
/// Offset of the WF_LOFT_CONFIG register from the base address
#define WLAN_RF_WF_LOFT_CONFIG_OFFSET 0x0000002C
/// Index of the WF_LOFT_CONFIG register
#define WLAN_RF_WF_LOFT_CONFIG_INDEX  0x0000000B
/// Reset value of the WF_LOFT_CONFIG register
#define WLAN_RF_WF_LOFT_CONFIG_RESET  0x00000000

/**
 * @brief Returns the current value of the WF_LOFT_CONFIG register.
 * The WF_LOFT_CONFIG register will be read and its value returned.
 * @return The current value of the WF_LOFT_CONFIG register.
 */
__INLINE uint32_t wlan_rf_wf_loft_config_get(void)
{
    return REG_PL_RD(WLAN_RF_WF_LOFT_CONFIG_ADDR);
}

/**
 * @brief Sets the WF_LOFT_CONFIG register to a value.
 * The WF_LOFT_CONFIG register will be written.
 * @param value - The value to write.
 */
__INLINE void wlan_rf_wf_loft_config_set(uint32_t value)
{
    REG_PL_WR(WLAN_RF_WF_LOFT_CONFIG_ADDR, value);
}

// field definitions
/// WF_LOFT_EN field bit
#define WLAN_RF_WF_LOFT_EN_BIT         ((uint32_t)0x00000400)
/// WF_LOFT_EN field position
#define WLAN_RF_WF_LOFT_EN_POS         10
/// WF_LOFT_GBIT field mask
#define WLAN_RF_WF_LOFT_GBIT_MASK      ((uint32_t)0x00000300)
/// WF_LOFT_GBIT field LSB position
#define WLAN_RF_WF_LOFT_GBIT_LSB       8
/// WF_LOFT_GBIT field width
#define WLAN_RF_WF_LOFT_GBIT_WIDTH     ((uint32_t)0x00000002)
/// WF_LOFT_LP_MODE field bit
#define WLAN_RF_WF_LOFT_LP_MODE_BIT    ((uint32_t)0x00000080)
/// WF_LOFT_LP_MODE field position
#define WLAN_RF_WF_LOFT_LP_MODE_POS    7
/// WF_LOFT_VI_EN field bit
#define WLAN_RF_WF_LOFT_VI_EN_BIT      ((uint32_t)0x00000040)
/// WF_LOFT_VI_EN field position
#define WLAN_RF_WF_LOFT_VI_EN_POS      6
/// WF_LOFT_VV_EN field bit
#define WLAN_RF_WF_LOFT_VV_EN_BIT      ((uint32_t)0x00000020)
/// WF_LOFT_VV_EN field position
#define WLAN_RF_WF_LOFT_VV_EN_POS      5

/// WF_LOFT_EN field reset value
#define WLAN_RF_WF_LOFT_EN_RST         0x0
/// WF_LOFT_GBIT field reset value
#define WLAN_RF_WF_LOFT_GBIT_RST       0x0
/// WF_LOFT_LP_MODE field reset value
#define WLAN_RF_WF_LOFT_LP_MODE_RST    0x0
/// WF_LOFT_VI_EN field reset value
#define WLAN_RF_WF_LOFT_VI_EN_RST      0x0
/// WF_LOFT_VV_EN field reset value
#define WLAN_RF_WF_LOFT_VV_EN_RST      0x0

/**
 * @brief Constructs a value for the WF_LOFT_CONFIG register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] wfloften - The value to use for the wf_loft_en field.
 * @param[in] wfloftgbit - The value to use for the wf_loft_gbit field.
 * @param[in] wfloftlpmode - The value to use for the wf_loft_lp_mode field.
 * @param[in] wfloftvien - The value to use for the wf_loft_vi_en field.
 * @param[in] wfloftvven - The value to use for the wf_loft_vv_en field.
 */
__INLINE void wlan_rf_wf_loft_config_pack(uint8_t wfloften, uint8_t wfloftgbit, uint8_t wfloftlpmode, uint8_t wfloftvien, uint8_t wfloftvven)
{
    REG_PL_WR(WLAN_RF_WF_LOFT_CONFIG_ADDR,  ((uint32_t)wfloften << 10) | ((uint32_t)wfloftgbit << 8) | ((uint32_t)wfloftlpmode << 7) | ((uint32_t)wfloftvien << 6) | ((uint32_t)wfloftvven << 5));
}

/**
 * @brief Unpacks WF_LOFT_CONFIG's fields from current value of the WF_LOFT_CONFIG register.
 *
 * Reads the WF_LOFT_CONFIG register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] wfloften - Will be populated with the current value of this field from the register.
 * @param[out] wfloftgbit - Will be populated with the current value of this field from the register.
 * @param[out] wfloftlpmode - Will be populated with the current value of this field from the register.
 * @param[out] wfloftvien - Will be populated with the current value of this field from the register.
 * @param[out] wfloftvven - Will be populated with the current value of this field from the register.
 */
__INLINE void wlan_rf_wf_loft_config_unpack(uint8_t* wfloften, uint8_t* wfloftgbit, uint8_t* wfloftlpmode, uint8_t* wfloftvien, uint8_t* wfloftvven)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_LOFT_CONFIG_ADDR);

    *wfloften = (localVal & ((uint32_t)0x00000400)) >> 10;
    *wfloftgbit = (localVal & ((uint32_t)0x00000300)) >> 8;
    *wfloftlpmode = (localVal & ((uint32_t)0x00000080)) >> 7;
    *wfloftvien = (localVal & ((uint32_t)0x00000040)) >> 6;
    *wfloftvven = (localVal & ((uint32_t)0x00000020)) >> 5;
}

/**
 * @brief Returns the current value of the wf_loft_en field in the WF_LOFT_CONFIG register.
 *
 * The WF_LOFT_CONFIG register will be read and the wf_loft_en field's value will be returned.
 *
 * @return The current value of the wf_loft_en field in the WF_LOFT_CONFIG register.
 */
__INLINE uint8_t wlan_rf_wf_loft_en_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_LOFT_CONFIG_ADDR);
    return ((localVal & ((uint32_t)0x00000400)) >> 10);
}

/**
 * @brief Sets the wf_loft_en field of the WF_LOFT_CONFIG register.
 *
 * The WF_LOFT_CONFIG register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wfloften - The value to set the field to.
 */
__INLINE void wlan_rf_wf_loft_en_setf(uint8_t wfloften)
{
    REG_PL_WR(WLAN_RF_WF_LOFT_CONFIG_ADDR, (REG_PL_RD(WLAN_RF_WF_LOFT_CONFIG_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)wfloften << 10));
}

/**
 * @brief Returns the current value of the wf_loft_gbit field in the WF_LOFT_CONFIG register.
 *
 * The WF_LOFT_CONFIG register will be read and the wf_loft_gbit field's value will be returned.
 *
 * @return The current value of the wf_loft_gbit field in the WF_LOFT_CONFIG register.
 */
__INLINE uint8_t wlan_rf_wf_loft_gbit_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_LOFT_CONFIG_ADDR);
    return ((localVal & ((uint32_t)0x00000300)) >> 8);
}

/**
 * @brief Sets the wf_loft_gbit field of the WF_LOFT_CONFIG register.
 *
 * The WF_LOFT_CONFIG register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wfloftgbit - The value to set the field to.
 */
__INLINE void wlan_rf_wf_loft_gbit_setf(uint8_t wfloftgbit)
{
    REG_PL_WR(WLAN_RF_WF_LOFT_CONFIG_ADDR, (REG_PL_RD(WLAN_RF_WF_LOFT_CONFIG_ADDR) & ~((uint32_t)0x00000300)) | ((uint32_t)wfloftgbit << 8));
}

/**
 * @brief Returns the current value of the wf_loft_lp_mode field in the WF_LOFT_CONFIG register.
 *
 * The WF_LOFT_CONFIG register will be read and the wf_loft_lp_mode field's value will be returned.
 *
 * @return The current value of the wf_loft_lp_mode field in the WF_LOFT_CONFIG register.
 */
__INLINE uint8_t wlan_rf_wf_loft_lp_mode_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_LOFT_CONFIG_ADDR);
    return ((localVal & ((uint32_t)0x00000080)) >> 7);
}

/**
 * @brief Sets the wf_loft_lp_mode field of the WF_LOFT_CONFIG register.
 *
 * The WF_LOFT_CONFIG register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wfloftlpmode - The value to set the field to.
 */
__INLINE void wlan_rf_wf_loft_lp_mode_setf(uint8_t wfloftlpmode)
{
    REG_PL_WR(WLAN_RF_WF_LOFT_CONFIG_ADDR, (REG_PL_RD(WLAN_RF_WF_LOFT_CONFIG_ADDR) & ~((uint32_t)0x00000080)) | ((uint32_t)wfloftlpmode << 7));
}

/**
 * @brief Returns the current value of the wf_loft_vi_en field in the WF_LOFT_CONFIG register.
 *
 * The WF_LOFT_CONFIG register will be read and the wf_loft_vi_en field's value will be returned.
 *
 * @return The current value of the wf_loft_vi_en field in the WF_LOFT_CONFIG register.
 */
__INLINE uint8_t wlan_rf_wf_loft_vi_en_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_LOFT_CONFIG_ADDR);
    return ((localVal & ((uint32_t)0x00000040)) >> 6);
}

/**
 * @brief Sets the wf_loft_vi_en field of the WF_LOFT_CONFIG register.
 *
 * The WF_LOFT_CONFIG register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wfloftvien - The value to set the field to.
 */
__INLINE void wlan_rf_wf_loft_vi_en_setf(uint8_t wfloftvien)
{
    REG_PL_WR(WLAN_RF_WF_LOFT_CONFIG_ADDR, (REG_PL_RD(WLAN_RF_WF_LOFT_CONFIG_ADDR) & ~((uint32_t)0x00000040)) | ((uint32_t)wfloftvien << 6));
}

/**
 * @brief Returns the current value of the wf_loft_vv_en field in the WF_LOFT_CONFIG register.
 *
 * The WF_LOFT_CONFIG register will be read and the wf_loft_vv_en field's value will be returned.
 *
 * @return The current value of the wf_loft_vv_en field in the WF_LOFT_CONFIG register.
 */
__INLINE uint8_t wlan_rf_wf_loft_vv_en_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_LOFT_CONFIG_ADDR);
    return ((localVal & ((uint32_t)0x00000020)) >> 5);
}

/**
 * @brief Sets the wf_loft_vv_en field of the WF_LOFT_CONFIG register.
 *
 * The WF_LOFT_CONFIG register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wfloftvven - The value to set the field to.
 */
__INLINE void wlan_rf_wf_loft_vv_en_setf(uint8_t wfloftvven)
{
    REG_PL_WR(WLAN_RF_WF_LOFT_CONFIG_ADDR, (REG_PL_RD(WLAN_RF_WF_LOFT_CONFIG_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)wfloftvven << 5));
}

/// @}

/**
 * @name WF_DTMX_REG register definitions
 * <table>
 * <caption id="WF_DTMX_REG_BF">WF_DTMX_REG bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>30 <td> wf_dtmx_lo5g_mode <td>R <td>R/W <td>0
 * <tr><td>29 <td>wf_dtmx_balun5g_mode <td>R <td>R/W <td>0
 * </table>
 *
 * @{
 */

/// Address of the WF_DTMX_REG register
#define WLAN_RF_WF_DTMX_REG_ADDR   0x40344030
/// Offset of the WF_DTMX_REG register from the base address
#define WLAN_RF_WF_DTMX_REG_OFFSET 0x00000030
/// Index of the WF_DTMX_REG register
#define WLAN_RF_WF_DTMX_REG_INDEX  0x0000000C
/// Reset value of the WF_DTMX_REG register
#define WLAN_RF_WF_DTMX_REG_RESET  0x00000000

/**
 * @brief Returns the current value of the WF_DTMX_REG register.
 * The WF_DTMX_REG register will be read and its value returned.
 * @return The current value of the WF_DTMX_REG register.
 */
__INLINE uint32_t wlan_rf_wf_dtmx_reg_get(void)
{
    return REG_PL_RD(WLAN_RF_WF_DTMX_REG_ADDR);
}

/**
 * @brief Sets the WF_DTMX_REG register to a value.
 * The WF_DTMX_REG register will be written.
 * @param value - The value to write.
 */
__INLINE void wlan_rf_wf_dtmx_reg_set(uint32_t value)
{
    REG_PL_WR(WLAN_RF_WF_DTMX_REG_ADDR, value);
}

// field definitions
/// WF_DTMX_LO_5G_MODE field bit
#define WLAN_RF_WF_DTMX_LO_5G_MODE_BIT       ((uint32_t)0x40000000)
/// WF_DTMX_LO_5G_MODE field position
#define WLAN_RF_WF_DTMX_LO_5G_MODE_POS       30
/// WF_DTMX_BALUN_5G_MODE field bit
#define WLAN_RF_WF_DTMX_BALUN_5G_MODE_BIT    ((uint32_t)0x20000000)
/// WF_DTMX_BALUN_5G_MODE field position
#define WLAN_RF_WF_DTMX_BALUN_5G_MODE_POS    29

/// WF_DTMX_LO_5G_MODE field reset value
#define WLAN_RF_WF_DTMX_LO_5G_MODE_RST       0x0
/// WF_DTMX_BALUN_5G_MODE field reset value
#define WLAN_RF_WF_DTMX_BALUN_5G_MODE_RST    0x0

/**
 * @brief Constructs a value for the WF_DTMX_REG register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] wfdtmxlo5gmode - The value to use for the wf_dtmx_lo5g_mode field.
 * @param[in] wfdtmxbalun5gmode - The value to use for the wf_dtmx_balun5g_mode field.
 */
__INLINE void wlan_rf_wf_dtmx_reg_pack(uint8_t wfdtmxlo5gmode, uint8_t wfdtmxbalun5gmode)
{
    REG_PL_WR(WLAN_RF_WF_DTMX_REG_ADDR,  ((uint32_t)wfdtmxlo5gmode << 30) | ((uint32_t)wfdtmxbalun5gmode << 29));
}

/**
 * @brief Unpacks WF_DTMX_REG's fields from current value of the WF_DTMX_REG register.
 *
 * Reads the WF_DTMX_REG register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] wfdtmxlo5gmode - Will be populated with the current value of this field from the register.
 * @param[out] wfdtmxbalun5gmode - Will be populated with the current value of this field from the register.
 */
__INLINE void wlan_rf_wf_dtmx_reg_unpack(uint8_t* wfdtmxlo5gmode, uint8_t* wfdtmxbalun5gmode)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_DTMX_REG_ADDR);

    *wfdtmxlo5gmode = (localVal & ((uint32_t)0x40000000)) >> 30;
    *wfdtmxbalun5gmode = (localVal & ((uint32_t)0x20000000)) >> 29;
}

/**
 * @brief Returns the current value of the wf_dtmx_lo5g_mode field in the WF_DTMX_REG register.
 *
 * The WF_DTMX_REG register will be read and the wf_dtmx_lo5g_mode field's value will be returned.
 *
 * @return The current value of the wf_dtmx_lo5g_mode field in the WF_DTMX_REG register.
 */
__INLINE uint8_t wlan_rf_wf_dtmx_lo_5g_mode_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_DTMX_REG_ADDR);
    return ((localVal & ((uint32_t)0x40000000)) >> 30);
}

/**
 * @brief Sets the wf_dtmx_lo5g_mode field of the WF_DTMX_REG register.
 *
 * The WF_DTMX_REG register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wfdtmxlo5gmode - The value to set the field to.
 */
__INLINE void wlan_rf_wf_dtmx_lo_5g_mode_setf(uint8_t wfdtmxlo5gmode)
{
    REG_PL_WR(WLAN_RF_WF_DTMX_REG_ADDR, (REG_PL_RD(WLAN_RF_WF_DTMX_REG_ADDR) & ~((uint32_t)0x40000000)) | ((uint32_t)wfdtmxlo5gmode << 30));
}

/**
 * @brief Returns the current value of the wf_dtmx_balun5g_mode field in the WF_DTMX_REG register.
 *
 * The WF_DTMX_REG register will be read and the wf_dtmx_balun5g_mode field's value will be returned.
 *
 * @return The current value of the wf_dtmx_balun5g_mode field in the WF_DTMX_REG register.
 */
__INLINE uint8_t wlan_rf_wf_dtmx_balun_5g_mode_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_DTMX_REG_ADDR);
    return ((localVal & ((uint32_t)0x20000000)) >> 29);
}

/**
 * @brief Sets the wf_dtmx_balun5g_mode field of the WF_DTMX_REG register.
 *
 * The WF_DTMX_REG register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wfdtmxbalun5gmode - The value to set the field to.
 */
__INLINE void wlan_rf_wf_dtmx_balun_5g_mode_setf(uint8_t wfdtmxbalun5gmode)
{
    REG_PL_WR(WLAN_RF_WF_DTMX_REG_ADDR, (REG_PL_RD(WLAN_RF_WF_DTMX_REG_ADDR) & ~((uint32_t)0x20000000)) | ((uint32_t)wfdtmxbalun5gmode << 29));
}

/// @}

/**
 * @name WF_RFPLL_REG1 register definitions
 * <table>
 * <caption id="WF_RFPLL_REG1_BF">WF_RFPLL_REG1 bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>26 <td>wf_rfpll_dpll_mode <td>R <td>R/W <td>0
 * <tr><td>00 <td>          reserved <td>R <td>R/W <td>0
 * </table>
 *
 * @{
 */

/// Address of the WF_RFPLL_REG1 register
#define WLAN_RF_WF_RFPLL_REG1_ADDR   0x40344038
/// Offset of the WF_RFPLL_REG1 register from the base address
#define WLAN_RF_WF_RFPLL_REG1_OFFSET 0x00000038
/// Index of the WF_RFPLL_REG1 register
#define WLAN_RF_WF_RFPLL_REG1_INDEX  0x0000000E
/// Reset value of the WF_RFPLL_REG1 register
#define WLAN_RF_WF_RFPLL_REG1_RESET  0x00000000

/**
 * @brief Returns the current value of the WF_RFPLL_REG1 register.
 * The WF_RFPLL_REG1 register will be read and its value returned.
 * @return The current value of the WF_RFPLL_REG1 register.
 */
__INLINE uint32_t wlan_rf_wf_rfpll_reg1_get(void)
{
    return REG_PL_RD(WLAN_RF_WF_RFPLL_REG1_ADDR);
}

/**
 * @brief Sets the WF_RFPLL_REG1 register to a value.
 * The WF_RFPLL_REG1 register will be written.
 * @param value - The value to write.
 */
__INLINE void wlan_rf_wf_rfpll_reg1_set(uint32_t value)
{
    REG_PL_WR(WLAN_RF_WF_RFPLL_REG1_ADDR, value);
}

// field definitions
/// WF_RFPLL_DPLL_MODE field bit
#define WLAN_RF_WF_RFPLL_DPLL_MODE_BIT    ((uint32_t)0x04000000)
/// WF_RFPLL_DPLL_MODE field position
#define WLAN_RF_WF_RFPLL_DPLL_MODE_POS    26
/// RESERVED field bit
#define WLAN_RF_RESERVED_BIT              ((uint32_t)0x00000001)
/// RESERVED field position
#define WLAN_RF_RESERVED_POS              0

/// WF_RFPLL_DPLL_MODE field reset value
#define WLAN_RF_WF_RFPLL_DPLL_MODE_RST    0x0
/// RESERVED field reset value
#define WLAN_RF_RESERVED_RST              0x0

/**
 * @brief Constructs a value for the WF_RFPLL_REG1 register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] wfrfplldpllmode - The value to use for the wf_rfpll_dpll_mode field.
 * @param[in] reserved - The value to use for the reserved field.
 */
__INLINE void wlan_rf_wf_rfpll_reg1_pack(uint8_t wfrfplldpllmode, uint8_t reserved)
{
    REG_PL_WR(WLAN_RF_WF_RFPLL_REG1_ADDR,  ((uint32_t)wfrfplldpllmode << 26) | ((uint32_t)reserved << 0));
}

/**
 * @brief Unpacks WF_RFPLL_REG1's fields from current value of the WF_RFPLL_REG1 register.
 *
 * Reads the WF_RFPLL_REG1 register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] wfrfplldpllmode - Will be populated with the current value of this field from the register.
 * @param[out] reserved - Will be populated with the current value of this field from the register.
 */
__INLINE void wlan_rf_wf_rfpll_reg1_unpack(uint8_t* wfrfplldpllmode, uint8_t* reserved)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_RFPLL_REG1_ADDR);

    *wfrfplldpllmode = (localVal & ((uint32_t)0x04000000)) >> 26;
    *reserved = (localVal & ((uint32_t)0x00000001)) >> 0;
}

/**
 * @brief Returns the current value of the wf_rfpll_dpll_mode field in the WF_RFPLL_REG1 register.
 *
 * The WF_RFPLL_REG1 register will be read and the wf_rfpll_dpll_mode field's value will be returned.
 *
 * @return The current value of the wf_rfpll_dpll_mode field in the WF_RFPLL_REG1 register.
 */
__INLINE uint8_t wlan_rf_wf_rfpll_dpll_mode_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_RFPLL_REG1_ADDR);
    return ((localVal & ((uint32_t)0x04000000)) >> 26);
}

/**
 * @brief Sets the wf_rfpll_dpll_mode field of the WF_RFPLL_REG1 register.
 *
 * The WF_RFPLL_REG1 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wfrfplldpllmode - The value to set the field to.
 */
__INLINE void wlan_rf_wf_rfpll_dpll_mode_setf(uint8_t wfrfplldpllmode)
{
    REG_PL_WR(WLAN_RF_WF_RFPLL_REG1_ADDR, (REG_PL_RD(WLAN_RF_WF_RFPLL_REG1_ADDR) & ~((uint32_t)0x04000000)) | ((uint32_t)wfrfplldpllmode << 26));
}

/**
 * @brief Returns the current value of the reserved field in the WF_RFPLL_REG1 register.
 *
 * The WF_RFPLL_REG1 register will be read and the reserved field's value will be returned.
 *
 * @return The current value of the reserved field in the WF_RFPLL_REG1 register.
 */
__INLINE uint8_t wlan_rf_reserved_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_RFPLL_REG1_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief Sets the reserved field of the WF_RFPLL_REG1 register.
 *
 * The WF_RFPLL_REG1 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] reserved - The value to set the field to.
 */
__INLINE void wlan_rf_reserved_setf(uint8_t reserved)
{
    REG_PL_WR(WLAN_RF_WF_RFPLL_REG1_ADDR, (REG_PL_RD(WLAN_RF_WF_RFPLL_REG1_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)reserved << 0));
}

/// @}

/**
 * @name WF_RFPLL_REG2 register definitions
 * <table>
 * <caption id="WF_RFPLL_REG2_BF">WF_RFPLL_REG2 bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>10:02 <td>wf_rfpll_adc_clk_div <td>R <td>R/W <td>0x0
 * <tr><td>00 <td>         reserved3 <td>R <td>R/W <td>0
 * </table>
 *
 * @{
 */

/// Address of the WF_RFPLL_REG2 register
#define WLAN_RF_WF_RFPLL_REG2_ADDR   0x4034403C
/// Offset of the WF_RFPLL_REG2 register from the base address
#define WLAN_RF_WF_RFPLL_REG2_OFFSET 0x0000003C
/// Index of the WF_RFPLL_REG2 register
#define WLAN_RF_WF_RFPLL_REG2_INDEX  0x0000000F
/// Reset value of the WF_RFPLL_REG2 register
#define WLAN_RF_WF_RFPLL_REG2_RESET  0x00000000

/**
 * @brief Returns the current value of the WF_RFPLL_REG2 register.
 * The WF_RFPLL_REG2 register will be read and its value returned.
 * @return The current value of the WF_RFPLL_REG2 register.
 */
__INLINE uint32_t wlan_rf_wf_rfpll_reg2_get(void)
{
    return REG_PL_RD(WLAN_RF_WF_RFPLL_REG2_ADDR);
}

/**
 * @brief Sets the WF_RFPLL_REG2 register to a value.
 * The WF_RFPLL_REG2 register will be written.
 * @param value - The value to write.
 */
__INLINE void wlan_rf_wf_rfpll_reg2_set(uint32_t value)
{
    REG_PL_WR(WLAN_RF_WF_RFPLL_REG2_ADDR, value);
}

// field definitions
/// WF_RFPLL_ADC_CLK_DIV field mask
#define WLAN_RF_WF_RFPLL_ADC_CLK_DIV_MASK   ((uint32_t)0x000007FC)
/// WF_RFPLL_ADC_CLK_DIV field LSB position
#define WLAN_RF_WF_RFPLL_ADC_CLK_DIV_LSB    2
/// WF_RFPLL_ADC_CLK_DIV field width
#define WLAN_RF_WF_RFPLL_ADC_CLK_DIV_WIDTH  ((uint32_t)0x00000009)
/// RESERVED_3 field bit
#define WLAN_RF_RESERVED_3_BIT              ((uint32_t)0x00000001)
/// RESERVED_3 field position
#define WLAN_RF_RESERVED_3_POS              0

/// WF_RFPLL_ADC_CLK_DIV field reset value
#define WLAN_RF_WF_RFPLL_ADC_CLK_DIV_RST    0x0
/// RESERVED_3 field reset value
#define WLAN_RF_RESERVED_3_RST              0x0

/**
 * @brief Constructs a value for the WF_RFPLL_REG2 register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] wfrfplladcclkdiv - The value to use for the wf_rfpll_adc_clk_div field.
 * @param[in] reserved3 - The value to use for the reserved3 field.
 */
__INLINE void wlan_rf_wf_rfpll_reg2_pack(uint16_t wfrfplladcclkdiv, uint8_t reserved3)
{
    REG_PL_WR(WLAN_RF_WF_RFPLL_REG2_ADDR,  ((uint32_t)wfrfplladcclkdiv << 2) | ((uint32_t)reserved3 << 0));
}

/**
 * @brief Unpacks WF_RFPLL_REG2's fields from current value of the WF_RFPLL_REG2 register.
 *
 * Reads the WF_RFPLL_REG2 register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] wfrfplladcclkdiv - Will be populated with the current value of this field from the register.
 * @param[out] reserved3 - Will be populated with the current value of this field from the register.
 */
__INLINE void wlan_rf_wf_rfpll_reg2_unpack(uint16_t* wfrfplladcclkdiv, uint8_t* reserved3)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_RFPLL_REG2_ADDR);

    *wfrfplladcclkdiv = (localVal & ((uint32_t)0x000007FC)) >> 2;
    *reserved3 = (localVal & ((uint32_t)0x00000001)) >> 0;
}

/**
 * @brief Returns the current value of the wf_rfpll_adc_clk_div field in the WF_RFPLL_REG2 register.
 *
 * The WF_RFPLL_REG2 register will be read and the wf_rfpll_adc_clk_div field's value will be returned.
 *
 * @return The current value of the wf_rfpll_adc_clk_div field in the WF_RFPLL_REG2 register.
 */
__INLINE uint16_t wlan_rf_wf_rfpll_adc_clk_div_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_RFPLL_REG2_ADDR);
    return ((localVal & ((uint32_t)0x000007FC)) >> 2);
}

/**
 * @brief Sets the wf_rfpll_adc_clk_div field of the WF_RFPLL_REG2 register.
 *
 * The WF_RFPLL_REG2 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wfrfplladcclkdiv - The value to set the field to.
 */
__INLINE void wlan_rf_wf_rfpll_adc_clk_div_setf(uint16_t wfrfplladcclkdiv)
{
    REG_PL_WR(WLAN_RF_WF_RFPLL_REG2_ADDR, (REG_PL_RD(WLAN_RF_WF_RFPLL_REG2_ADDR) & ~((uint32_t)0x000007FC)) | ((uint32_t)wfrfplladcclkdiv << 2));
}

/**
 * @brief Returns the current value of the reserved3 field in the WF_RFPLL_REG2 register.
 *
 * The WF_RFPLL_REG2 register will be read and the reserved3 field's value will be returned.
 *
 * @return The current value of the reserved3 field in the WF_RFPLL_REG2 register.
 */
__INLINE uint8_t wlan_rf_reserved_3_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_RFPLL_REG2_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief Sets the reserved3 field of the WF_RFPLL_REG2 register.
 *
 * The WF_RFPLL_REG2 register will be read, modified to contain the new field value, and written.
 *
 * @param[in] reserved3 - The value to set the field to.
 */
__INLINE void wlan_rf_reserved_3_setf(uint8_t reserved3)
{
    REG_PL_WR(WLAN_RF_WF_RFPLL_REG2_ADDR, (REG_PL_RD(WLAN_RF_WF_RFPLL_REG2_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)reserved3 << 0));
}

/// @}

/**
 * @name WF_GRO_REG register definitions
 * <table>
 * <caption id="WF_GRO_REG_BF">WF_GRO_REG bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>29:26 <td>   wf_gro_reg_vbit <td>R <td>R/W <td>0x0
 * <tr><td>24:23 <td>wf_gro_pdt_ldo_vbit <td>R <td>R/W <td>0x0
 * <tr><td>02:00 <td>wf_rdac_lpf_bw_rbit <td>R <td>R/W <td>0x0
 * </table>
 *
 * @{
 */

/// Address of the WF_GRO_REG register
#define WLAN_RF_WF_GRO_REG_ADDR   0x40344040
/// Offset of the WF_GRO_REG register from the base address
#define WLAN_RF_WF_GRO_REG_OFFSET 0x00000040
/// Index of the WF_GRO_REG register
#define WLAN_RF_WF_GRO_REG_INDEX  0x00000010
/// Reset value of the WF_GRO_REG register
#define WLAN_RF_WF_GRO_REG_RESET  0x00000000

/**
 * @brief Returns the current value of the WF_GRO_REG register.
 * The WF_GRO_REG register will be read and its value returned.
 * @return The current value of the WF_GRO_REG register.
 */
__INLINE uint32_t wlan_rf_wf_gro_reg_get(void)
{
    return REG_PL_RD(WLAN_RF_WF_GRO_REG_ADDR);
}

/**
 * @brief Sets the WF_GRO_REG register to a value.
 * The WF_GRO_REG register will be written.
 * @param value - The value to write.
 */
__INLINE void wlan_rf_wf_gro_reg_set(uint32_t value)
{
    REG_PL_WR(WLAN_RF_WF_GRO_REG_ADDR, value);
}

// field definitions
/// WF_GRO_REG_VBIT field mask
#define WLAN_RF_WF_GRO_REG_VBIT_MASK       ((uint32_t)0x3C000000)
/// WF_GRO_REG_VBIT field LSB position
#define WLAN_RF_WF_GRO_REG_VBIT_LSB        26
/// WF_GRO_REG_VBIT field width
#define WLAN_RF_WF_GRO_REG_VBIT_WIDTH      ((uint32_t)0x00000004)
/// WF_GRO_PDT_LDO_VBIT field mask
#define WLAN_RF_WF_GRO_PDT_LDO_VBIT_MASK   ((uint32_t)0x01800000)
/// WF_GRO_PDT_LDO_VBIT field LSB position
#define WLAN_RF_WF_GRO_PDT_LDO_VBIT_LSB    23
/// WF_GRO_PDT_LDO_VBIT field width
#define WLAN_RF_WF_GRO_PDT_LDO_VBIT_WIDTH  ((uint32_t)0x00000002)
/// WF_RDAC_LPF_BW_RBIT field mask
#define WLAN_RF_WF_RDAC_LPF_BW_RBIT_MASK   ((uint32_t)0x00000007)
/// WF_RDAC_LPF_BW_RBIT field LSB position
#define WLAN_RF_WF_RDAC_LPF_BW_RBIT_LSB    0
/// WF_RDAC_LPF_BW_RBIT field width
#define WLAN_RF_WF_RDAC_LPF_BW_RBIT_WIDTH  ((uint32_t)0x00000003)

/// WF_GRO_REG_VBIT field reset value
#define WLAN_RF_WF_GRO_REG_VBIT_RST        0x0
/// WF_GRO_PDT_LDO_VBIT field reset value
#define WLAN_RF_WF_GRO_PDT_LDO_VBIT_RST    0x0
/// WF_RDAC_LPF_BW_RBIT field reset value
#define WLAN_RF_WF_RDAC_LPF_BW_RBIT_RST    0x0

/**
 * @brief Constructs a value for the WF_GRO_REG register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] wfgroregvbit - The value to use for the wf_gro_reg_vbit field.
 * @param[in] wfgropdtldovbit - The value to use for the wf_gro_pdt_ldo_vbit field.
 * @param[in] wfrdaclpfbwrbit - The value to use for the wf_rdac_lpf_bw_rbit field.
 */
__INLINE void wlan_rf_wf_gro_reg_pack(uint8_t wfgroregvbit, uint8_t wfgropdtldovbit, uint8_t wfrdaclpfbwrbit)
{
    REG_PL_WR(WLAN_RF_WF_GRO_REG_ADDR,  ((uint32_t)wfgroregvbit << 26) | ((uint32_t)wfgropdtldovbit << 23) | ((uint32_t)wfrdaclpfbwrbit << 0));
}

/**
 * @brief Unpacks WF_GRO_REG's fields from current value of the WF_GRO_REG register.
 *
 * Reads the WF_GRO_REG register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] wfgroregvbit - Will be populated with the current value of this field from the register.
 * @param[out] wfgropdtldovbit - Will be populated with the current value of this field from the register.
 * @param[out] wfrdaclpfbwrbit - Will be populated with the current value of this field from the register.
 */
__INLINE void wlan_rf_wf_gro_reg_unpack(uint8_t* wfgroregvbit, uint8_t* wfgropdtldovbit, uint8_t* wfrdaclpfbwrbit)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_GRO_REG_ADDR);

    *wfgroregvbit = (localVal & ((uint32_t)0x3C000000)) >> 26;
    *wfgropdtldovbit = (localVal & ((uint32_t)0x01800000)) >> 23;
    *wfrdaclpfbwrbit = (localVal & ((uint32_t)0x00000007)) >> 0;
}

/**
 * @brief Returns the current value of the wf_gro_reg_vbit field in the WF_GRO_REG register.
 *
 * The WF_GRO_REG register will be read and the wf_gro_reg_vbit field's value will be returned.
 *
 * @return The current value of the wf_gro_reg_vbit field in the WF_GRO_REG register.
 */
__INLINE uint8_t wlan_rf_wf_gro_reg_vbit_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_GRO_REG_ADDR);
    return ((localVal & ((uint32_t)0x3C000000)) >> 26);
}

/**
 * @brief Sets the wf_gro_reg_vbit field of the WF_GRO_REG register.
 *
 * The WF_GRO_REG register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wfgroregvbit - The value to set the field to.
 */
__INLINE void wlan_rf_wf_gro_reg_vbit_setf(uint8_t wfgroregvbit)
{
    REG_PL_WR(WLAN_RF_WF_GRO_REG_ADDR, (REG_PL_RD(WLAN_RF_WF_GRO_REG_ADDR) & ~((uint32_t)0x3C000000)) | ((uint32_t)wfgroregvbit << 26));
}

/**
 * @brief Returns the current value of the wf_gro_pdt_ldo_vbit field in the WF_GRO_REG register.
 *
 * The WF_GRO_REG register will be read and the wf_gro_pdt_ldo_vbit field's value will be returned.
 *
 * @return The current value of the wf_gro_pdt_ldo_vbit field in the WF_GRO_REG register.
 */
__INLINE uint8_t wlan_rf_wf_gro_pdt_ldo_vbit_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_GRO_REG_ADDR);
    return ((localVal & ((uint32_t)0x01800000)) >> 23);
}

/**
 * @brief Sets the wf_gro_pdt_ldo_vbit field of the WF_GRO_REG register.
 *
 * The WF_GRO_REG register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wfgropdtldovbit - The value to set the field to.
 */
__INLINE void wlan_rf_wf_gro_pdt_ldo_vbit_setf(uint8_t wfgropdtldovbit)
{
    REG_PL_WR(WLAN_RF_WF_GRO_REG_ADDR, (REG_PL_RD(WLAN_RF_WF_GRO_REG_ADDR) & ~((uint32_t)0x01800000)) | ((uint32_t)wfgropdtldovbit << 23));
}

/**
 * @brief Returns the current value of the wf_rdac_lpf_bw_rbit field in the WF_GRO_REG register.
 *
 * The WF_GRO_REG register will be read and the wf_rdac_lpf_bw_rbit field's value will be returned.
 *
 * @return The current value of the wf_rdac_lpf_bw_rbit field in the WF_GRO_REG register.
 */
__INLINE uint8_t wlan_rf_wf_rdac_lpf_bw_rbit_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_GRO_REG_ADDR);
    return ((localVal & ((uint32_t)0x00000007)) >> 0);
}

/**
 * @brief Sets the wf_rdac_lpf_bw_rbit field of the WF_GRO_REG register.
 *
 * The WF_GRO_REG register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wfrdaclpfbwrbit - The value to set the field to.
 */
__INLINE void wlan_rf_wf_rdac_lpf_bw_rbit_setf(uint8_t wfrdaclpfbwrbit)
{
    REG_PL_WR(WLAN_RF_WF_GRO_REG_ADDR, (REG_PL_RD(WLAN_RF_WF_GRO_REG_ADDR) & ~((uint32_t)0x00000007)) | ((uint32_t)wfrdaclpfbwrbit << 0));
}

/// @}

/**
 * @name WF_MISC_REG register definitions
 * <table>
 * <caption id="WF_MISC_REG_BF">WF_MISC_REG bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>31 <td>       reserved_48 <td>R <td>R/W <td>0
 * <tr><td>09:02 <td>    wf_reserve_bit <td>R <td>R/W <td>0x0
 * </table>
 *
 * @{
 */

/// Address of the WF_MISC_REG register
#define WLAN_RF_WF_MISC_REG_ADDR   0x40344048
/// Offset of the WF_MISC_REG register from the base address
#define WLAN_RF_WF_MISC_REG_OFFSET 0x00000048
/// Index of the WF_MISC_REG register
#define WLAN_RF_WF_MISC_REG_INDEX  0x00000012
/// Reset value of the WF_MISC_REG register
#define WLAN_RF_WF_MISC_REG_RESET  0x00000000

/**
 * @brief Returns the current value of the WF_MISC_REG register.
 * The WF_MISC_REG register will be read and its value returned.
 * @return The current value of the WF_MISC_REG register.
 */
__INLINE uint32_t wlan_rf_wf_misc_reg_get(void)
{
    return REG_PL_RD(WLAN_RF_WF_MISC_REG_ADDR);
}

/**
 * @brief Sets the WF_MISC_REG register to a value.
 * The WF_MISC_REG register will be written.
 * @param value - The value to write.
 */
__INLINE void wlan_rf_wf_misc_reg_set(uint32_t value)
{
    REG_PL_WR(WLAN_RF_WF_MISC_REG_ADDR, value);
}

// field definitions
/// RESERVED__48 field bit
#define WLAN_RF_RESERVED__48_BIT      ((uint32_t)0x80000000)
/// RESERVED__48 field position
#define WLAN_RF_RESERVED__48_POS      31
/// WF_RESERVE_BIT field mask
#define WLAN_RF_WF_RESERVE_BIT_MASK   ((uint32_t)0x000003FC)
/// WF_RESERVE_BIT field LSB position
#define WLAN_RF_WF_RESERVE_BIT_LSB    2
/// WF_RESERVE_BIT field width
#define WLAN_RF_WF_RESERVE_BIT_WIDTH  ((uint32_t)0x00000008)

/// RESERVED__48 field reset value
#define WLAN_RF_RESERVED__48_RST      0x0
/// WF_RESERVE_BIT field reset value
#define WLAN_RF_WF_RESERVE_BIT_RST    0x0

/**
 * @brief Constructs a value for the WF_MISC_REG register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] reserved48 - The value to use for the reserved_48 field.
 * @param[in] wfreservebit - The value to use for the wf_reserve_bit field.
 */
__INLINE void wlan_rf_wf_misc_reg_pack(uint8_t reserved48, uint8_t wfreservebit)
{
    REG_PL_WR(WLAN_RF_WF_MISC_REG_ADDR,  ((uint32_t)reserved48 << 31) | ((uint32_t)wfreservebit << 2));
}

/**
 * @brief Unpacks WF_MISC_REG's fields from current value of the WF_MISC_REG register.
 *
 * Reads the WF_MISC_REG register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] reserved48 - Will be populated with the current value of this field from the register.
 * @param[out] wfreservebit - Will be populated with the current value of this field from the register.
 */
__INLINE void wlan_rf_wf_misc_reg_unpack(uint8_t* reserved48, uint8_t* wfreservebit)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_MISC_REG_ADDR);

    *reserved48 = (localVal & ((uint32_t)0x80000000)) >> 31;
    *wfreservebit = (localVal & ((uint32_t)0x000003FC)) >> 2;
}

/**
 * @brief Returns the current value of the reserved_48 field in the WF_MISC_REG register.
 *
 * The WF_MISC_REG register will be read and the reserved_48 field's value will be returned.
 *
 * @return The current value of the reserved_48 field in the WF_MISC_REG register.
 */
__INLINE uint8_t wlan_rf_reserved__48_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_MISC_REG_ADDR);
    return ((localVal & ((uint32_t)0x80000000)) >> 31);
}

/**
 * @brief Sets the reserved_48 field of the WF_MISC_REG register.
 *
 * The WF_MISC_REG register will be read, modified to contain the new field value, and written.
 *
 * @param[in] reserved48 - The value to set the field to.
 */
__INLINE void wlan_rf_reserved__48_setf(uint8_t reserved48)
{
    REG_PL_WR(WLAN_RF_WF_MISC_REG_ADDR, (REG_PL_RD(WLAN_RF_WF_MISC_REG_ADDR) & ~((uint32_t)0x80000000)) | ((uint32_t)reserved48 << 31));
}

/**
 * @brief Returns the current value of the wf_reserve_bit field in the WF_MISC_REG register.
 *
 * The WF_MISC_REG register will be read and the wf_reserve_bit field's value will be returned.
 *
 * @return The current value of the wf_reserve_bit field in the WF_MISC_REG register.
 */
__INLINE uint8_t wlan_rf_wf_reserve_bit_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_WF_MISC_REG_ADDR);
    return ((localVal & ((uint32_t)0x000003FC)) >> 2);
}

/**
 * @brief Sets the wf_reserve_bit field of the WF_MISC_REG register.
 *
 * The WF_MISC_REG register will be read, modified to contain the new field value, and written.
 *
 * @param[in] wfreservebit - The value to set the field to.
 */
__INLINE void wlan_rf_wf_reserve_bit_setf(uint8_t wfreservebit)
{
    REG_PL_WR(WLAN_RF_WF_MISC_REG_ADDR, (REG_PL_RD(WLAN_RF_WF_MISC_REG_ADDR) & ~((uint32_t)0x000003FC)) | ((uint32_t)wfreservebit << 2));
}

/// @}

/**
 * @name MAN_CTRL register definitions
 * <table>
 * <caption id="MAN_CTRL_BF">MAN_CTRL bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>23 <td>         pllon_trx <td>R <td>R/W <td>0
 * <tr><td>21 <td>         Pllon_reg <td>R <td>R/W <td>0
 * <tr><td>20 <td>           txon_dr <td>R <td>R/W <td>0
 * <tr><td>19 <td>          txon_reg <td>R <td>R/W <td>0
 * <tr><td>18 <td>           rxon_dr <td>R <td>R/W <td>0
 * <tr><td>17 <td>          rxon_reg <td>R <td>R/W <td>0
 * <tr><td>16 <td>  rx_gain_dr_pulse <td>R <td>R/W <td>0
 * <tr><td>15 <td>        rx_gain_dr <td>R <td>R/W <td>0
 * <tr><td>12:07 <td>       rx_gain_reg <td>R <td>R/W <td>0x0
 * </table>
 *
 * @{
 */

/// Address of the MAN_CTRL register
#define WLAN_RF_MAN_CTRL_ADDR   0x40344058
/// Offset of the MAN_CTRL register from the base address
#define WLAN_RF_MAN_CTRL_OFFSET 0x00000058
/// Index of the MAN_CTRL register
#define WLAN_RF_MAN_CTRL_INDEX  0x00000016
/// Reset value of the MAN_CTRL register
#define WLAN_RF_MAN_CTRL_RESET  0x00000000

/**
 * @brief Returns the current value of the MAN_CTRL register.
 * The MAN_CTRL register will be read and its value returned.
 * @return The current value of the MAN_CTRL register.
 */
__INLINE uint32_t wlan_rf_man_ctrl_get(void)
{
    return REG_PL_RD(WLAN_RF_MAN_CTRL_ADDR);
}

/**
 * @brief Sets the MAN_CTRL register to a value.
 * The MAN_CTRL register will be written.
 * @param value - The value to write.
 */
__INLINE void wlan_rf_man_ctrl_set(uint32_t value)
{
    REG_PL_WR(WLAN_RF_MAN_CTRL_ADDR, value);
}

// field definitions
/// PLLON_TRX field bit
#define WLAN_RF_PLLON_TRX_BIT           ((uint32_t)0x00800000)
/// PLLON_TRX field position
#define WLAN_RF_PLLON_TRX_POS           23
/// PLLON_REG field bit
#define WLAN_RF_PLLON_REG_BIT           ((uint32_t)0x00200000)
/// PLLON_REG field position
#define WLAN_RF_PLLON_REG_POS           21
/// TXON_DR field bit
#define WLAN_RF_TXON_DR_BIT             ((uint32_t)0x00100000)
/// TXON_DR field position
#define WLAN_RF_TXON_DR_POS             20
/// TXON_REG field bit
#define WLAN_RF_TXON_REG_BIT            ((uint32_t)0x00080000)
/// TXON_REG field position
#define WLAN_RF_TXON_REG_POS            19
/// RXON_DR field bit
#define WLAN_RF_RXON_DR_BIT             ((uint32_t)0x00040000)
/// RXON_DR field position
#define WLAN_RF_RXON_DR_POS             18
/// RXON_REG field bit
#define WLAN_RF_RXON_REG_BIT            ((uint32_t)0x00020000)
/// RXON_REG field position
#define WLAN_RF_RXON_REG_POS            17
/// RX_GAIN_DR_PULSE field bit
#define WLAN_RF_RX_GAIN_DR_PULSE_BIT    ((uint32_t)0x00010000)
/// RX_GAIN_DR_PULSE field position
#define WLAN_RF_RX_GAIN_DR_PULSE_POS    16
/// RX_GAIN_DR field bit
#define WLAN_RF_RX_GAIN_DR_BIT          ((uint32_t)0x00008000)
/// RX_GAIN_DR field position
#define WLAN_RF_RX_GAIN_DR_POS          15
/// RX_GAIN_REG field mask
#define WLAN_RF_RX_GAIN_REG_MASK        ((uint32_t)0x00001F80)
/// RX_GAIN_REG field LSB position
#define WLAN_RF_RX_GAIN_REG_LSB         7
/// RX_GAIN_REG field width
#define WLAN_RF_RX_GAIN_REG_WIDTH       ((uint32_t)0x00000006)

/// PLLON_TRX field reset value
#define WLAN_RF_PLLON_TRX_RST           0x0
/// PLLON_REG field reset value
#define WLAN_RF_PLLON_REG_RST           0x0
/// TXON_DR field reset value
#define WLAN_RF_TXON_DR_RST             0x0
/// TXON_REG field reset value
#define WLAN_RF_TXON_REG_RST            0x0
/// RXON_DR field reset value
#define WLAN_RF_RXON_DR_RST             0x0
/// RXON_REG field reset value
#define WLAN_RF_RXON_REG_RST            0x0
/// RX_GAIN_DR_PULSE field reset value
#define WLAN_RF_RX_GAIN_DR_PULSE_RST    0x0
/// RX_GAIN_DR field reset value
#define WLAN_RF_RX_GAIN_DR_RST          0x0
/// RX_GAIN_REG field reset value
#define WLAN_RF_RX_GAIN_REG_RST         0x0

/**
 * @brief Constructs a value for the MAN_CTRL register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] pllontrx - The value to use for the pllon_trx field.
 * @param[in] pllonreg - The value to use for the Pllon_reg field.
 * @param[in] txondr - The value to use for the txon_dr field.
 * @param[in] txonreg - The value to use for the txon_reg field.
 * @param[in] rxondr - The value to use for the rxon_dr field.
 * @param[in] rxonreg - The value to use for the rxon_reg field.
 * @param[in] rxgaindrpulse - The value to use for the rx_gain_dr_pulse field.
 * @param[in] rxgaindr - The value to use for the rx_gain_dr field.
 * @param[in] rxgainreg - The value to use for the rx_gain_reg field.
 */
__INLINE void wlan_rf_man_ctrl_pack(uint8_t pllontrx, uint8_t pllonreg, uint8_t txondr, uint8_t txonreg, uint8_t rxondr, uint8_t rxonreg, uint8_t rxgaindrpulse, uint8_t rxgaindr, uint8_t rxgainreg)
{
    REG_PL_WR(WLAN_RF_MAN_CTRL_ADDR,  ((uint32_t)pllontrx << 23) | ((uint32_t)pllonreg << 21) | ((uint32_t)txondr << 20) | ((uint32_t)txonreg << 19) | ((uint32_t)rxondr << 18) | ((uint32_t)rxonreg << 17) | ((uint32_t)rxgaindrpulse << 16) | ((uint32_t)rxgaindr << 15) | ((uint32_t)rxgainreg << 7));
}

/**
 * @brief Unpacks MAN_CTRL's fields from current value of the MAN_CTRL register.
 *
 * Reads the MAN_CTRL register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] pllontrx - Will be populated with the current value of this field from the register.
 * @param[out] pllonreg - Will be populated with the current value of this field from the register.
 * @param[out] txondr - Will be populated with the current value of this field from the register.
 * @param[out] txonreg - Will be populated with the current value of this field from the register.
 * @param[out] rxondr - Will be populated with the current value of this field from the register.
 * @param[out] rxonreg - Will be populated with the current value of this field from the register.
 * @param[out] rxgaindrpulse - Will be populated with the current value of this field from the register.
 * @param[out] rxgaindr - Will be populated with the current value of this field from the register.
 * @param[out] rxgainreg - Will be populated with the current value of this field from the register.
 */
__INLINE void wlan_rf_man_ctrl_unpack(uint8_t* pllontrx, uint8_t* pllonreg, uint8_t* txondr, uint8_t* txonreg, uint8_t* rxondr, uint8_t* rxonreg, uint8_t* rxgaindrpulse, uint8_t* rxgaindr, uint8_t* rxgainreg)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_MAN_CTRL_ADDR);

    *pllontrx = (localVal & ((uint32_t)0x00800000)) >> 23;
    *pllonreg = (localVal & ((uint32_t)0x00200000)) >> 21;
    *txondr = (localVal & ((uint32_t)0x00100000)) >> 20;
    *txonreg = (localVal & ((uint32_t)0x00080000)) >> 19;
    *rxondr = (localVal & ((uint32_t)0x00040000)) >> 18;
    *rxonreg = (localVal & ((uint32_t)0x00020000)) >> 17;
    *rxgaindrpulse = (localVal & ((uint32_t)0x00010000)) >> 16;
    *rxgaindr = (localVal & ((uint32_t)0x00008000)) >> 15;
    *rxgainreg = (localVal & ((uint32_t)0x00001F80)) >> 7;
}

/**
 * @brief Returns the current value of the pllon_trx field in the MAN_CTRL register.
 *
 * The MAN_CTRL register will be read and the pllon_trx field's value will be returned.
 *
 * @return The current value of the pllon_trx field in the MAN_CTRL register.
 */
__INLINE uint8_t wlan_rf_pllon_trx_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_MAN_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00800000)) >> 23);
}

/**
 * @brief Sets the pllon_trx field of the MAN_CTRL register.
 *
 * The MAN_CTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] pllontrx - The value to set the field to.
 */
__INLINE void wlan_rf_pllon_trx_setf(uint8_t pllontrx)
{
    REG_PL_WR(WLAN_RF_MAN_CTRL_ADDR, (REG_PL_RD(WLAN_RF_MAN_CTRL_ADDR) & ~((uint32_t)0x00800000)) | ((uint32_t)pllontrx << 23));
}

/**
 * @brief Returns the current value of the Pllon_reg field in the MAN_CTRL register.
 *
 * The MAN_CTRL register will be read and the Pllon_reg field's value will be returned.
 *
 * @return The current value of the Pllon_reg field in the MAN_CTRL register.
 */
__INLINE uint8_t wlan_rf_pllon_reg_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_MAN_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00200000)) >> 21);
}

/**
 * @brief Sets the Pllon_reg field of the MAN_CTRL register.
 *
 * The MAN_CTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] pllonreg - The value to set the field to.
 */
__INLINE void wlan_rf_pllon_reg_setf(uint8_t pllonreg)
{
    REG_PL_WR(WLAN_RF_MAN_CTRL_ADDR, (REG_PL_RD(WLAN_RF_MAN_CTRL_ADDR) & ~((uint32_t)0x00200000)) | ((uint32_t)pllonreg << 21));
}

/**
 * @brief Returns the current value of the txon_dr field in the MAN_CTRL register.
 *
 * The MAN_CTRL register will be read and the txon_dr field's value will be returned.
 *
 * @return The current value of the txon_dr field in the MAN_CTRL register.
 */
__INLINE uint8_t wlan_rf_txon_dr_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_MAN_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00100000)) >> 20);
}

/**
 * @brief Sets the txon_dr field of the MAN_CTRL register.
 *
 * The MAN_CTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] txondr - The value to set the field to.
 */
__INLINE void wlan_rf_txon_dr_setf(uint8_t txondr)
{
    REG_PL_WR(WLAN_RF_MAN_CTRL_ADDR, (REG_PL_RD(WLAN_RF_MAN_CTRL_ADDR) & ~((uint32_t)0x00100000)) | ((uint32_t)txondr << 20));
}

/**
 * @brief Returns the current value of the txon_reg field in the MAN_CTRL register.
 *
 * The MAN_CTRL register will be read and the txon_reg field's value will be returned.
 *
 * @return The current value of the txon_reg field in the MAN_CTRL register.
 */
__INLINE uint8_t wlan_rf_txon_reg_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_MAN_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00080000)) >> 19);
}

/**
 * @brief Sets the txon_reg field of the MAN_CTRL register.
 *
 * The MAN_CTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] txonreg - The value to set the field to.
 */
__INLINE void wlan_rf_txon_reg_setf(uint8_t txonreg)
{
    REG_PL_WR(WLAN_RF_MAN_CTRL_ADDR, (REG_PL_RD(WLAN_RF_MAN_CTRL_ADDR) & ~((uint32_t)0x00080000)) | ((uint32_t)txonreg << 19));
}

/**
 * @brief Returns the current value of the rxon_dr field in the MAN_CTRL register.
 *
 * The MAN_CTRL register will be read and the rxon_dr field's value will be returned.
 *
 * @return The current value of the rxon_dr field in the MAN_CTRL register.
 */
__INLINE uint8_t wlan_rf_rxon_dr_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_MAN_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00040000)) >> 18);
}

/**
 * @brief Sets the rxon_dr field of the MAN_CTRL register.
 *
 * The MAN_CTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rxondr - The value to set the field to.
 */
__INLINE void wlan_rf_rxon_dr_setf(uint8_t rxondr)
{
    REG_PL_WR(WLAN_RF_MAN_CTRL_ADDR, (REG_PL_RD(WLAN_RF_MAN_CTRL_ADDR) & ~((uint32_t)0x00040000)) | ((uint32_t)rxondr << 18));
}

/**
 * @brief Returns the current value of the rxon_reg field in the MAN_CTRL register.
 *
 * The MAN_CTRL register will be read and the rxon_reg field's value will be returned.
 *
 * @return The current value of the rxon_reg field in the MAN_CTRL register.
 */
__INLINE uint8_t wlan_rf_rxon_reg_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_MAN_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00020000)) >> 17);
}

/**
 * @brief Sets the rxon_reg field of the MAN_CTRL register.
 *
 * The MAN_CTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rxonreg - The value to set the field to.
 */
__INLINE void wlan_rf_rxon_reg_setf(uint8_t rxonreg)
{
    REG_PL_WR(WLAN_RF_MAN_CTRL_ADDR, (REG_PL_RD(WLAN_RF_MAN_CTRL_ADDR) & ~((uint32_t)0x00020000)) | ((uint32_t)rxonreg << 17));
}

/**
 * @brief Returns the current value of the rx_gain_dr_pulse field in the MAN_CTRL register.
 *
 * The MAN_CTRL register will be read and the rx_gain_dr_pulse field's value will be returned.
 *
 * @return The current value of the rx_gain_dr_pulse field in the MAN_CTRL register.
 */
__INLINE uint8_t wlan_rf_rx_gain_dr_pulse_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_MAN_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00010000)) >> 16);
}

/**
 * @brief Sets the rx_gain_dr_pulse field of the MAN_CTRL register.
 *
 * The MAN_CTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rxgaindrpulse - The value to set the field to.
 */
__INLINE void wlan_rf_rx_gain_dr_pulse_setf(uint8_t rxgaindrpulse)
{
    REG_PL_WR(WLAN_RF_MAN_CTRL_ADDR, (REG_PL_RD(WLAN_RF_MAN_CTRL_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)rxgaindrpulse << 16));
}

/**
 * @brief Returns the current value of the rx_gain_dr field in the MAN_CTRL register.
 *
 * The MAN_CTRL register will be read and the rx_gain_dr field's value will be returned.
 *
 * @return The current value of the rx_gain_dr field in the MAN_CTRL register.
 */
__INLINE uint8_t wlan_rf_rx_gain_dr_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_MAN_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00008000)) >> 15);
}

/**
 * @brief Sets the rx_gain_dr field of the MAN_CTRL register.
 *
 * The MAN_CTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rxgaindr - The value to set the field to.
 */
__INLINE void wlan_rf_rx_gain_dr_setf(uint8_t rxgaindr)
{
    REG_PL_WR(WLAN_RF_MAN_CTRL_ADDR, (REG_PL_RD(WLAN_RF_MAN_CTRL_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)rxgaindr << 15));
}

/**
 * @brief Returns the current value of the rx_gain_reg field in the MAN_CTRL register.
 *
 * The MAN_CTRL register will be read and the rx_gain_reg field's value will be returned.
 *
 * @return The current value of the rx_gain_reg field in the MAN_CTRL register.
 */
__INLINE uint8_t wlan_rf_rx_gain_reg_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_MAN_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00001F80)) >> 7);
}

/**
 * @brief Sets the rx_gain_reg field of the MAN_CTRL register.
 *
 * The MAN_CTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rxgainreg - The value to set the field to.
 */
__INLINE void wlan_rf_rx_gain_reg_setf(uint8_t rxgainreg)
{
    REG_PL_WR(WLAN_RF_MAN_CTRL_ADDR, (REG_PL_RD(WLAN_RF_MAN_CTRL_ADDR) & ~((uint32_t)0x00001F80)) | ((uint32_t)rxgainreg << 7));
}

/// @}

/**
 * @name RXGAIN_MEM_CTRL register definitions
 * <table>
 * <caption id="RXGAIN_MEM_CTRL_BF">RXGAIN_MEM_CTRL bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>13 <td>rxgain_mem_rw_done <td>R <td>R/W <td>0
 * <tr><td>12 <td>    clk_rxgain_sel <td>R <td>R/W <td>0
 * <tr><td>11 <td>     clk_rxgain_en <td>R <td>R/W <td>0
 * <tr><td>10 <td>    rxgain_mem_cfg <td>R <td>R/W <td>0
 * <tr><td>09 <td>rxgain_mem_ren_pulse <td>R <td>R/W <td>0
 * <tr><td>08 <td>rxgain_mem_wen_pulse <td>R <td>R/W <td>0
 * <tr><td>07:00 <td>rxgain_mem_addr_cfg <td>R <td>R/W <td>0x0
 * </table>
 *
 * @{
 */

/// Address of the RXGAIN_MEM_CTRL register
#define WLAN_RF_RXGAIN_MEM_CTRL_ADDR   0x40344060
/// Offset of the RXGAIN_MEM_CTRL register from the base address
#define WLAN_RF_RXGAIN_MEM_CTRL_OFFSET 0x00000060
/// Index of the RXGAIN_MEM_CTRL register
#define WLAN_RF_RXGAIN_MEM_CTRL_INDEX  0x00000018
/// Reset value of the RXGAIN_MEM_CTRL register
#define WLAN_RF_RXGAIN_MEM_CTRL_RESET  0x00000000

/**
 * @brief Returns the current value of the RXGAIN_MEM_CTRL register.
 * The RXGAIN_MEM_CTRL register will be read and its value returned.
 * @return The current value of the RXGAIN_MEM_CTRL register.
 */
__INLINE uint32_t wlan_rf_rxgain_mem_ctrl_get(void)
{
    return REG_PL_RD(WLAN_RF_RXGAIN_MEM_CTRL_ADDR);
}

/**
 * @brief Sets the RXGAIN_MEM_CTRL register to a value.
 * The RXGAIN_MEM_CTRL register will be written.
 * @param value - The value to write.
 */
__INLINE void wlan_rf_rxgain_mem_ctrl_set(uint32_t value)
{
    REG_PL_WR(WLAN_RF_RXGAIN_MEM_CTRL_ADDR, value);
}

// field definitions
/// RXGAIN_MEM_RW_DONE field bit
#define WLAN_RF_RXGAIN_MEM_RW_DONE_BIT      ((uint32_t)0x00002000)
/// RXGAIN_MEM_RW_DONE field position
#define WLAN_RF_RXGAIN_MEM_RW_DONE_POS      13
/// CLK_RXGAIN_SEL field bit
#define WLAN_RF_CLK_RXGAIN_SEL_BIT          ((uint32_t)0x00001000)
/// CLK_RXGAIN_SEL field position
#define WLAN_RF_CLK_RXGAIN_SEL_POS          12
/// CLK_RXGAIN_EN field bit
#define WLAN_RF_CLK_RXGAIN_EN_BIT           ((uint32_t)0x00000800)
/// CLK_RXGAIN_EN field position
#define WLAN_RF_CLK_RXGAIN_EN_POS           11
/// RXGAIN_MEM_CFG field bit
#define WLAN_RF_RXGAIN_MEM_CFG_BIT          ((uint32_t)0x00000400)
/// RXGAIN_MEM_CFG field position
#define WLAN_RF_RXGAIN_MEM_CFG_POS          10
/// RXGAIN_MEM_REN_PULSE field bit
#define WLAN_RF_RXGAIN_MEM_REN_PULSE_BIT    ((uint32_t)0x00000200)
/// RXGAIN_MEM_REN_PULSE field position
#define WLAN_RF_RXGAIN_MEM_REN_PULSE_POS    9
/// RXGAIN_MEM_WEN_PULSE field bit
#define WLAN_RF_RXGAIN_MEM_WEN_PULSE_BIT    ((uint32_t)0x00000100)
/// RXGAIN_MEM_WEN_PULSE field position
#define WLAN_RF_RXGAIN_MEM_WEN_PULSE_POS    8
/// RXGAIN_MEM_ADDR_CFG field mask
#define WLAN_RF_RXGAIN_MEM_ADDR_CFG_MASK    ((uint32_t)0x000000FF)
/// RXGAIN_MEM_ADDR_CFG field LSB position
#define WLAN_RF_RXGAIN_MEM_ADDR_CFG_LSB     0
/// RXGAIN_MEM_ADDR_CFG field width
#define WLAN_RF_RXGAIN_MEM_ADDR_CFG_WIDTH   ((uint32_t)0x00000008)

/// RXGAIN_MEM_RW_DONE field reset value
#define WLAN_RF_RXGAIN_MEM_RW_DONE_RST      0x0
/// CLK_RXGAIN_SEL field reset value
#define WLAN_RF_CLK_RXGAIN_SEL_RST          0x0
/// CLK_RXGAIN_EN field reset value
#define WLAN_RF_CLK_RXGAIN_EN_RST           0x0
/// RXGAIN_MEM_CFG field reset value
#define WLAN_RF_RXGAIN_MEM_CFG_RST          0x0
/// RXGAIN_MEM_REN_PULSE field reset value
#define WLAN_RF_RXGAIN_MEM_REN_PULSE_RST    0x0
/// RXGAIN_MEM_WEN_PULSE field reset value
#define WLAN_RF_RXGAIN_MEM_WEN_PULSE_RST    0x0
/// RXGAIN_MEM_ADDR_CFG field reset value
#define WLAN_RF_RXGAIN_MEM_ADDR_CFG_RST     0x0

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
__INLINE void wlan_rf_rxgain_mem_ctrl_pack(uint8_t rxgainmemrwdone, uint8_t clkrxgainsel, uint8_t clkrxgainen, uint8_t rxgainmemcfg, uint8_t rxgainmemrenpulse, uint8_t rxgainmemwenpulse, uint8_t rxgainmemaddrcfg)
{
    REG_PL_WR(WLAN_RF_RXGAIN_MEM_CTRL_ADDR,  ((uint32_t)rxgainmemrwdone << 13) | ((uint32_t)clkrxgainsel << 12) | ((uint32_t)clkrxgainen << 11) | ((uint32_t)rxgainmemcfg << 10) | ((uint32_t)rxgainmemrenpulse << 9) | ((uint32_t)rxgainmemwenpulse << 8) | ((uint32_t)rxgainmemaddrcfg << 0));
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
__INLINE void wlan_rf_rxgain_mem_ctrl_unpack(uint8_t* rxgainmemrwdone, uint8_t* clkrxgainsel, uint8_t* clkrxgainen, uint8_t* rxgainmemcfg, uint8_t* rxgainmemrenpulse, uint8_t* rxgainmemwenpulse, uint8_t* rxgainmemaddrcfg)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_RXGAIN_MEM_CTRL_ADDR);

    *rxgainmemrwdone = (localVal & ((uint32_t)0x00002000)) >> 13;
    *clkrxgainsel = (localVal & ((uint32_t)0x00001000)) >> 12;
    *clkrxgainen = (localVal & ((uint32_t)0x00000800)) >> 11;
    *rxgainmemcfg = (localVal & ((uint32_t)0x00000400)) >> 10;
    *rxgainmemrenpulse = (localVal & ((uint32_t)0x00000200)) >> 9;
    *rxgainmemwenpulse = (localVal & ((uint32_t)0x00000100)) >> 8;
    *rxgainmemaddrcfg = (localVal & ((uint32_t)0x000000FF)) >> 0;
}

/**
 * @brief Returns the current value of the rxgain_mem_rw_done field in the RXGAIN_MEM_CTRL register.
 *
 * The RXGAIN_MEM_CTRL register will be read and the rxgain_mem_rw_done field's value will be returned.
 *
 * @return The current value of the rxgain_mem_rw_done field in the RXGAIN_MEM_CTRL register.
 */
__INLINE uint8_t wlan_rf_rxgain_mem_rw_done_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_RXGAIN_MEM_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00002000)) >> 13);
}

/**
 * @brief Sets the rxgain_mem_rw_done field of the RXGAIN_MEM_CTRL register.
 *
 * The RXGAIN_MEM_CTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rxgainmemrwdone - The value to set the field to.
 */
__INLINE void wlan_rf_rxgain_mem_rw_done_setf(uint8_t rxgainmemrwdone)
{
    REG_PL_WR(WLAN_RF_RXGAIN_MEM_CTRL_ADDR, (REG_PL_RD(WLAN_RF_RXGAIN_MEM_CTRL_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)rxgainmemrwdone << 13));
}

/**
 * @brief Returns the current value of the clk_rxgain_sel field in the RXGAIN_MEM_CTRL register.
 *
 * The RXGAIN_MEM_CTRL register will be read and the clk_rxgain_sel field's value will be returned.
 *
 * @return The current value of the clk_rxgain_sel field in the RXGAIN_MEM_CTRL register.
 */
__INLINE uint8_t wlan_rf_clk_rxgain_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_RXGAIN_MEM_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00001000)) >> 12);
}

/**
 * @brief Sets the clk_rxgain_sel field of the RXGAIN_MEM_CTRL register.
 *
 * The RXGAIN_MEM_CTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] clkrxgainsel - The value to set the field to.
 */
__INLINE void wlan_rf_clk_rxgain_sel_setf(uint8_t clkrxgainsel)
{
    REG_PL_WR(WLAN_RF_RXGAIN_MEM_CTRL_ADDR, (REG_PL_RD(WLAN_RF_RXGAIN_MEM_CTRL_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)clkrxgainsel << 12));
}

/**
 * @brief Returns the current value of the clk_rxgain_en field in the RXGAIN_MEM_CTRL register.
 *
 * The RXGAIN_MEM_CTRL register will be read and the clk_rxgain_en field's value will be returned.
 *
 * @return The current value of the clk_rxgain_en field in the RXGAIN_MEM_CTRL register.
 */
__INLINE uint8_t wlan_rf_clk_rxgain_en_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_RXGAIN_MEM_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000800)) >> 11);
}

/**
 * @brief Sets the clk_rxgain_en field of the RXGAIN_MEM_CTRL register.
 *
 * The RXGAIN_MEM_CTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] clkrxgainen - The value to set the field to.
 */
__INLINE void wlan_rf_clk_rxgain_en_setf(uint8_t clkrxgainen)
{
    REG_PL_WR(WLAN_RF_RXGAIN_MEM_CTRL_ADDR, (REG_PL_RD(WLAN_RF_RXGAIN_MEM_CTRL_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)clkrxgainen << 11));
}

/**
 * @brief Returns the current value of the rxgain_mem_cfg field in the RXGAIN_MEM_CTRL register.
 *
 * The RXGAIN_MEM_CTRL register will be read and the rxgain_mem_cfg field's value will be returned.
 *
 * @return The current value of the rxgain_mem_cfg field in the RXGAIN_MEM_CTRL register.
 */
__INLINE uint8_t wlan_rf_rxgain_mem_cfg_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_RXGAIN_MEM_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000400)) >> 10);
}

/**
 * @brief Sets the rxgain_mem_cfg field of the RXGAIN_MEM_CTRL register.
 *
 * The RXGAIN_MEM_CTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rxgainmemcfg - The value to set the field to.
 */
__INLINE void wlan_rf_rxgain_mem_cfg_setf(uint8_t rxgainmemcfg)
{
    REG_PL_WR(WLAN_RF_RXGAIN_MEM_CTRL_ADDR, (REG_PL_RD(WLAN_RF_RXGAIN_MEM_CTRL_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)rxgainmemcfg << 10));
}

/**
 * @brief Returns the current value of the rxgain_mem_ren_pulse field in the RXGAIN_MEM_CTRL register.
 *
 * The RXGAIN_MEM_CTRL register will be read and the rxgain_mem_ren_pulse field's value will be returned.
 *
 * @return The current value of the rxgain_mem_ren_pulse field in the RXGAIN_MEM_CTRL register.
 */
__INLINE uint8_t wlan_rf_rxgain_mem_ren_pulse_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_RXGAIN_MEM_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000200)) >> 9);
}

/**
 * @brief Sets the rxgain_mem_ren_pulse field of the RXGAIN_MEM_CTRL register.
 *
 * The RXGAIN_MEM_CTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rxgainmemrenpulse - The value to set the field to.
 */
__INLINE void wlan_rf_rxgain_mem_ren_pulse_setf(uint8_t rxgainmemrenpulse)
{
    REG_PL_WR(WLAN_RF_RXGAIN_MEM_CTRL_ADDR, (REG_PL_RD(WLAN_RF_RXGAIN_MEM_CTRL_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)rxgainmemrenpulse << 9));
}

/**
 * @brief Returns the current value of the rxgain_mem_wen_pulse field in the RXGAIN_MEM_CTRL register.
 *
 * The RXGAIN_MEM_CTRL register will be read and the rxgain_mem_wen_pulse field's value will be returned.
 *
 * @return The current value of the rxgain_mem_wen_pulse field in the RXGAIN_MEM_CTRL register.
 */
__INLINE uint8_t wlan_rf_rxgain_mem_wen_pulse_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_RXGAIN_MEM_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000100)) >> 8);
}

/**
 * @brief Sets the rxgain_mem_wen_pulse field of the RXGAIN_MEM_CTRL register.
 *
 * The RXGAIN_MEM_CTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rxgainmemwenpulse - The value to set the field to.
 */
__INLINE void wlan_rf_rxgain_mem_wen_pulse_setf(uint8_t rxgainmemwenpulse)
{
    REG_PL_WR(WLAN_RF_RXGAIN_MEM_CTRL_ADDR, (REG_PL_RD(WLAN_RF_RXGAIN_MEM_CTRL_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)rxgainmemwenpulse << 8));
}

/**
 * @brief Returns the current value of the rxgain_mem_addr_cfg field in the RXGAIN_MEM_CTRL register.
 *
 * The RXGAIN_MEM_CTRL register will be read and the rxgain_mem_addr_cfg field's value will be returned.
 *
 * @return The current value of the rxgain_mem_addr_cfg field in the RXGAIN_MEM_CTRL register.
 */
__INLINE uint8_t wlan_rf_rxgain_mem_addr_cfg_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_RXGAIN_MEM_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x000000FF)) >> 0);
}

/**
 * @brief Sets the rxgain_mem_addr_cfg field of the RXGAIN_MEM_CTRL register.
 *
 * The RXGAIN_MEM_CTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rxgainmemaddrcfg - The value to set the field to.
 */
__INLINE void wlan_rf_rxgain_mem_addr_cfg_setf(uint8_t rxgainmemaddrcfg)
{
    REG_PL_WR(WLAN_RF_RXGAIN_MEM_CTRL_ADDR, (REG_PL_RD(WLAN_RF_RXGAIN_MEM_CTRL_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)rxgainmemaddrcfg << 0));
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
#define WLAN_RF_RXGAIN_MEM_WD_ADDR   0x40344064
/// Offset of the RXGAIN_MEM_WD register from the base address
#define WLAN_RF_RXGAIN_MEM_WD_OFFSET 0x00000064
/// Index of the RXGAIN_MEM_WD register
#define WLAN_RF_RXGAIN_MEM_WD_INDEX  0x00000019
/// Reset value of the RXGAIN_MEM_WD register
#define WLAN_RF_RXGAIN_MEM_WD_RESET  0x00000000

/**
 * @brief Returns the current value of the RXGAIN_MEM_WD register.
 * The RXGAIN_MEM_WD register will be read and its value returned.
 * @return The current value of the RXGAIN_MEM_WD register.
 */
__INLINE uint32_t wlan_rf_rxgain_mem_wd_get(void)
{
    return REG_PL_RD(WLAN_RF_RXGAIN_MEM_WD_ADDR);
}

/**
 * @brief Sets the RXGAIN_MEM_WD register to a value.
 * The RXGAIN_MEM_WD register will be written.
 * @param value - The value to write.
 */
__INLINE void wlan_rf_rxgain_mem_wd_set(uint32_t value)
{
    REG_PL_WR(WLAN_RF_RXGAIN_MEM_WD_ADDR, value);
}

// field definitions
/// RXGAIN_MEM_WDATA field mask
#define WLAN_RF_RXGAIN_MEM_WDATA_MASK   ((uint32_t)0xFFFFFFFF)
/// RXGAIN_MEM_WDATA field LSB position
#define WLAN_RF_RXGAIN_MEM_WDATA_LSB    0
/// RXGAIN_MEM_WDATA field width
#define WLAN_RF_RXGAIN_MEM_WDATA_WIDTH  ((uint32_t)0x00000020)

/// RXGAIN_MEM_WDATA field reset value
#define WLAN_RF_RXGAIN_MEM_WDATA_RST    0x0

/**
 * @brief Returns the current value of the rxgain_mem_wdata field in the RXGAIN_MEM_WD register.
 *
 * The RXGAIN_MEM_WD register will be read and the rxgain_mem_wdata field's value will be returned.
 *
 * @return The current value of the rxgain_mem_wdata field in the RXGAIN_MEM_WD register.
 */
__INLINE uint32_t wlan_rf_rxgain_mem_wdata_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_RXGAIN_MEM_WD_ADDR);
    return (localVal >> 0);
}

/**
 * @brief Sets the rxgain_mem_wdata field of the RXGAIN_MEM_WD register.
 *
 * The RXGAIN_MEM_WD register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rxgainmemwdata - The value to set the field to.
 */
__INLINE void wlan_rf_rxgain_mem_wdata_setf(uint32_t rxgainmemwdata)
{
    REG_PL_WR(WLAN_RF_RXGAIN_MEM_WD_ADDR, (uint32_t)rxgainmemwdata << 0);
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
#define WLAN_RF_RXGAIN_MEM_RD_ADDR   0x40344068
/// Offset of the RXGAIN_MEM_RD register from the base address
#define WLAN_RF_RXGAIN_MEM_RD_OFFSET 0x00000068
/// Index of the RXGAIN_MEM_RD register
#define WLAN_RF_RXGAIN_MEM_RD_INDEX  0x0000001A
/// Reset value of the RXGAIN_MEM_RD register
#define WLAN_RF_RXGAIN_MEM_RD_RESET  0x00000000

/**
 * @brief Returns the current value of the RXGAIN_MEM_RD register.
 * The RXGAIN_MEM_RD register will be read and its value returned.
 * @return The current value of the RXGAIN_MEM_RD register.
 */
__INLINE uint32_t wlan_rf_rxgain_mem_rd_get(void)
{
    return REG_PL_RD(WLAN_RF_RXGAIN_MEM_RD_ADDR);
}

/**
 * @brief Sets the RXGAIN_MEM_RD register to a value.
 * The RXGAIN_MEM_RD register will be written.
 * @param value - The value to write.
 */
__INLINE void wlan_rf_rxgain_mem_rd_set(uint32_t value)
{
    REG_PL_WR(WLAN_RF_RXGAIN_MEM_RD_ADDR, value);
}

// field definitions
/// RXGAIN_MEM_RDATA field mask
#define WLAN_RF_RXGAIN_MEM_RDATA_MASK   ((uint32_t)0xFFFFFFFF)
/// RXGAIN_MEM_RDATA field LSB position
#define WLAN_RF_RXGAIN_MEM_RDATA_LSB    0
/// RXGAIN_MEM_RDATA field width
#define WLAN_RF_RXGAIN_MEM_RDATA_WIDTH  ((uint32_t)0x00000020)

/// RXGAIN_MEM_RDATA field reset value
#define WLAN_RF_RXGAIN_MEM_RDATA_RST    0x0

/**
 * @brief Returns the current value of the rxgain_mem_rdata field in the RXGAIN_MEM_RD register.
 *
 * The RXGAIN_MEM_RD register will be read and the rxgain_mem_rdata field's value will be returned.
 *
 * @return The current value of the rxgain_mem_rdata field in the RXGAIN_MEM_RD register.
 */
__INLINE uint32_t wlan_rf_rxgain_mem_rdata_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_RXGAIN_MEM_RD_ADDR);
    return (localVal >> 0);
}

/**
 * @brief Sets the rxgain_mem_rdata field of the RXGAIN_MEM_RD register.
 *
 * The RXGAIN_MEM_RD register will be read, modified to contain the new field value, and written.
 *
 * @param[in] rxgainmemrdata - The value to set the field to.
 */
__INLINE void wlan_rf_rxgain_mem_rdata_setf(uint32_t rxgainmemrdata)
{
    REG_PL_WR(WLAN_RF_RXGAIN_MEM_RD_ADDR, (uint32_t)rxgainmemrdata << 0);
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
#define WLAN_RF_TXGAIN_MEM_CTRL_ADDR   0x4034406C
/// Offset of the TXGAIN_MEM_CTRL register from the base address
#define WLAN_RF_TXGAIN_MEM_CTRL_OFFSET 0x0000006C
/// Index of the TXGAIN_MEM_CTRL register
#define WLAN_RF_TXGAIN_MEM_CTRL_INDEX  0x0000001B
/// Reset value of the TXGAIN_MEM_CTRL register
#define WLAN_RF_TXGAIN_MEM_CTRL_RESET  0x00000000

/**
 * @brief Returns the current value of the TXGAIN_MEM_CTRL register.
 * The TXGAIN_MEM_CTRL register will be read and its value returned.
 * @return The current value of the TXGAIN_MEM_CTRL register.
 */
__INLINE uint32_t wlan_rf_txgain_mem_ctrl_get(void)
{
    return REG_PL_RD(WLAN_RF_TXGAIN_MEM_CTRL_ADDR);
}

/**
 * @brief Sets the TXGAIN_MEM_CTRL register to a value.
 * The TXGAIN_MEM_CTRL register will be written.
 * @param value - The value to write.
 */
__INLINE void wlan_rf_txgain_mem_ctrl_set(uint32_t value)
{
    REG_PL_WR(WLAN_RF_TXGAIN_MEM_CTRL_ADDR, value);
}

// field definitions
/// TXGAIN_MEM_RW_DONE field bit
#define WLAN_RF_TXGAIN_MEM_RW_DONE_BIT      ((uint32_t)0x00000400)
/// TXGAIN_MEM_RW_DONE field position
#define WLAN_RF_TXGAIN_MEM_RW_DONE_POS      10
/// CLK_TXGAIN_SEL field bit
#define WLAN_RF_CLK_TXGAIN_SEL_BIT          ((uint32_t)0x00000200)
/// CLK_TXGAIN_SEL field position
#define WLAN_RF_CLK_TXGAIN_SEL_POS          9
/// CLK_TXGAIN_EN field bit
#define WLAN_RF_CLK_TXGAIN_EN_BIT           ((uint32_t)0x00000100)
/// CLK_TXGAIN_EN field position
#define WLAN_RF_CLK_TXGAIN_EN_POS           8
/// TXGAIN_MEM_CFG field bit
#define WLAN_RF_TXGAIN_MEM_CFG_BIT          ((uint32_t)0x00000080)
/// TXGAIN_MEM_CFG field position
#define WLAN_RF_TXGAIN_MEM_CFG_POS          7
/// TXGAIN_MEM_REN_PULSE field bit
#define WLAN_RF_TXGAIN_MEM_REN_PULSE_BIT    ((uint32_t)0x00000040)
/// TXGAIN_MEM_REN_PULSE field position
#define WLAN_RF_TXGAIN_MEM_REN_PULSE_POS    6
/// TXGAIN_MEM_WEN_PULSE field bit
#define WLAN_RF_TXGAIN_MEM_WEN_PULSE_BIT    ((uint32_t)0x00000020)
/// TXGAIN_MEM_WEN_PULSE field position
#define WLAN_RF_TXGAIN_MEM_WEN_PULSE_POS    5
/// TXGAIN_MEM_ADDR_CFG field mask
#define WLAN_RF_TXGAIN_MEM_ADDR_CFG_MASK    ((uint32_t)0x0000001F)
/// TXGAIN_MEM_ADDR_CFG field LSB position
#define WLAN_RF_TXGAIN_MEM_ADDR_CFG_LSB     0
/// TXGAIN_MEM_ADDR_CFG field width
#define WLAN_RF_TXGAIN_MEM_ADDR_CFG_WIDTH   ((uint32_t)0x00000005)

/// TXGAIN_MEM_RW_DONE field reset value
#define WLAN_RF_TXGAIN_MEM_RW_DONE_RST      0x0
/// CLK_TXGAIN_SEL field reset value
#define WLAN_RF_CLK_TXGAIN_SEL_RST          0x0
/// CLK_TXGAIN_EN field reset value
#define WLAN_RF_CLK_TXGAIN_EN_RST           0x0
/// TXGAIN_MEM_CFG field reset value
#define WLAN_RF_TXGAIN_MEM_CFG_RST          0x0
/// TXGAIN_MEM_REN_PULSE field reset value
#define WLAN_RF_TXGAIN_MEM_REN_PULSE_RST    0x0
/// TXGAIN_MEM_WEN_PULSE field reset value
#define WLAN_RF_TXGAIN_MEM_WEN_PULSE_RST    0x0
/// TXGAIN_MEM_ADDR_CFG field reset value
#define WLAN_RF_TXGAIN_MEM_ADDR_CFG_RST     0x0

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
__INLINE void wlan_rf_txgain_mem_ctrl_pack(uint8_t txgainmemrwdone, uint8_t clktxgainsel, uint8_t clktxgainen, uint8_t txgainmemcfg, uint8_t txgainmemrenpulse, uint8_t txgainmemwenpulse, uint8_t txgainmemaddrcfg)
{
    REG_PL_WR(WLAN_RF_TXGAIN_MEM_CTRL_ADDR,  ((uint32_t)txgainmemrwdone << 10) | ((uint32_t)clktxgainsel << 9) | ((uint32_t)clktxgainen << 8) | ((uint32_t)txgainmemcfg << 7) | ((uint32_t)txgainmemrenpulse << 6) | ((uint32_t)txgainmemwenpulse << 5) | ((uint32_t)txgainmemaddrcfg << 0));
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
__INLINE void wlan_rf_txgain_mem_ctrl_unpack(uint8_t* txgainmemrwdone, uint8_t* clktxgainsel, uint8_t* clktxgainen, uint8_t* txgainmemcfg, uint8_t* txgainmemrenpulse, uint8_t* txgainmemwenpulse, uint8_t* txgainmemaddrcfg)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_TXGAIN_MEM_CTRL_ADDR);

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
__INLINE uint8_t wlan_rf_txgain_mem_rw_done_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_TXGAIN_MEM_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000400)) >> 10);
}

/**
 * @brief Sets the txgain_mem_rw_done field of the TXGAIN_MEM_CTRL register.
 *
 * The TXGAIN_MEM_CTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] txgainmemrwdone - The value to set the field to.
 */
__INLINE void wlan_rf_txgain_mem_rw_done_setf(uint8_t txgainmemrwdone)
{
    REG_PL_WR(WLAN_RF_TXGAIN_MEM_CTRL_ADDR, (REG_PL_RD(WLAN_RF_TXGAIN_MEM_CTRL_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)txgainmemrwdone << 10));
}

/**
 * @brief Returns the current value of the clk_txgain_sel field in the TXGAIN_MEM_CTRL register.
 *
 * The TXGAIN_MEM_CTRL register will be read and the clk_txgain_sel field's value will be returned.
 *
 * @return The current value of the clk_txgain_sel field in the TXGAIN_MEM_CTRL register.
 */
__INLINE uint8_t wlan_rf_clk_txgain_sel_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_TXGAIN_MEM_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000200)) >> 9);
}

/**
 * @brief Sets the clk_txgain_sel field of the TXGAIN_MEM_CTRL register.
 *
 * The TXGAIN_MEM_CTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] clktxgainsel - The value to set the field to.
 */
__INLINE void wlan_rf_clk_txgain_sel_setf(uint8_t clktxgainsel)
{
    REG_PL_WR(WLAN_RF_TXGAIN_MEM_CTRL_ADDR, (REG_PL_RD(WLAN_RF_TXGAIN_MEM_CTRL_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)clktxgainsel << 9));
}

/**
 * @brief Returns the current value of the clk_txgain_en field in the TXGAIN_MEM_CTRL register.
 *
 * The TXGAIN_MEM_CTRL register will be read and the clk_txgain_en field's value will be returned.
 *
 * @return The current value of the clk_txgain_en field in the TXGAIN_MEM_CTRL register.
 */
__INLINE uint8_t wlan_rf_clk_txgain_en_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_TXGAIN_MEM_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000100)) >> 8);
}

/**
 * @brief Sets the clk_txgain_en field of the TXGAIN_MEM_CTRL register.
 *
 * The TXGAIN_MEM_CTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] clktxgainen - The value to set the field to.
 */
__INLINE void wlan_rf_clk_txgain_en_setf(uint8_t clktxgainen)
{
    REG_PL_WR(WLAN_RF_TXGAIN_MEM_CTRL_ADDR, (REG_PL_RD(WLAN_RF_TXGAIN_MEM_CTRL_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)clktxgainen << 8));
}

/**
 * @brief Returns the current value of the txgain_mem_cfg field in the TXGAIN_MEM_CTRL register.
 *
 * The TXGAIN_MEM_CTRL register will be read and the txgain_mem_cfg field's value will be returned.
 *
 * @return The current value of the txgain_mem_cfg field in the TXGAIN_MEM_CTRL register.
 */
__INLINE uint8_t wlan_rf_txgain_mem_cfg_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_TXGAIN_MEM_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000080)) >> 7);
}

/**
 * @brief Sets the txgain_mem_cfg field of the TXGAIN_MEM_CTRL register.
 *
 * The TXGAIN_MEM_CTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] txgainmemcfg - The value to set the field to.
 */
__INLINE void wlan_rf_txgain_mem_cfg_setf(uint8_t txgainmemcfg)
{
    REG_PL_WR(WLAN_RF_TXGAIN_MEM_CTRL_ADDR, (REG_PL_RD(WLAN_RF_TXGAIN_MEM_CTRL_ADDR) & ~((uint32_t)0x00000080)) | ((uint32_t)txgainmemcfg << 7));
}

/**
 * @brief Returns the current value of the txgain_mem_ren_pulse field in the TXGAIN_MEM_CTRL register.
 *
 * The TXGAIN_MEM_CTRL register will be read and the txgain_mem_ren_pulse field's value will be returned.
 *
 * @return The current value of the txgain_mem_ren_pulse field in the TXGAIN_MEM_CTRL register.
 */
__INLINE uint8_t wlan_rf_txgain_mem_ren_pulse_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_TXGAIN_MEM_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000040)) >> 6);
}

/**
 * @brief Sets the txgain_mem_ren_pulse field of the TXGAIN_MEM_CTRL register.
 *
 * The TXGAIN_MEM_CTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] txgainmemrenpulse - The value to set the field to.
 */
__INLINE void wlan_rf_txgain_mem_ren_pulse_setf(uint8_t txgainmemrenpulse)
{
    REG_PL_WR(WLAN_RF_TXGAIN_MEM_CTRL_ADDR, (REG_PL_RD(WLAN_RF_TXGAIN_MEM_CTRL_ADDR) & ~((uint32_t)0x00000040)) | ((uint32_t)txgainmemrenpulse << 6));
}

/**
 * @brief Returns the current value of the txgain_mem_wen_pulse field in the TXGAIN_MEM_CTRL register.
 *
 * The TXGAIN_MEM_CTRL register will be read and the txgain_mem_wen_pulse field's value will be returned.
 *
 * @return The current value of the txgain_mem_wen_pulse field in the TXGAIN_MEM_CTRL register.
 */
__INLINE uint8_t wlan_rf_txgain_mem_wen_pulse_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_TXGAIN_MEM_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000020)) >> 5);
}

/**
 * @brief Sets the txgain_mem_wen_pulse field of the TXGAIN_MEM_CTRL register.
 *
 * The TXGAIN_MEM_CTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] txgainmemwenpulse - The value to set the field to.
 */
__INLINE void wlan_rf_txgain_mem_wen_pulse_setf(uint8_t txgainmemwenpulse)
{
    REG_PL_WR(WLAN_RF_TXGAIN_MEM_CTRL_ADDR, (REG_PL_RD(WLAN_RF_TXGAIN_MEM_CTRL_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)txgainmemwenpulse << 5));
}

/**
 * @brief Returns the current value of the txgain_mem_addr_cfg field in the TXGAIN_MEM_CTRL register.
 *
 * The TXGAIN_MEM_CTRL register will be read and the txgain_mem_addr_cfg field's value will be returned.
 *
 * @return The current value of the txgain_mem_addr_cfg field in the TXGAIN_MEM_CTRL register.
 */
__INLINE uint8_t wlan_rf_txgain_mem_addr_cfg_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_TXGAIN_MEM_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x0000001F)) >> 0);
}

/**
 * @brief Sets the txgain_mem_addr_cfg field of the TXGAIN_MEM_CTRL register.
 *
 * The TXGAIN_MEM_CTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] txgainmemaddrcfg - The value to set the field to.
 */
__INLINE void wlan_rf_txgain_mem_addr_cfg_setf(uint8_t txgainmemaddrcfg)
{
    REG_PL_WR(WLAN_RF_TXGAIN_MEM_CTRL_ADDR, (REG_PL_RD(WLAN_RF_TXGAIN_MEM_CTRL_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)txgainmemaddrcfg << 0));
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
#define WLAN_RF_TXGAIN_MEM_WD_ADDR   0x40344070
/// Offset of the TXGAIN_MEM_WD register from the base address
#define WLAN_RF_TXGAIN_MEM_WD_OFFSET 0x00000070
/// Index of the TXGAIN_MEM_WD register
#define WLAN_RF_TXGAIN_MEM_WD_INDEX  0x0000001C
/// Reset value of the TXGAIN_MEM_WD register
#define WLAN_RF_TXGAIN_MEM_WD_RESET  0x00000000

/**
 * @brief Returns the current value of the TXGAIN_MEM_WD register.
 * The TXGAIN_MEM_WD register will be read and its value returned.
 * @return The current value of the TXGAIN_MEM_WD register.
 */
__INLINE uint32_t wlan_rf_txgain_mem_wd_get(void)
{
    return REG_PL_RD(WLAN_RF_TXGAIN_MEM_WD_ADDR);
}

/**
 * @brief Sets the TXGAIN_MEM_WD register to a value.
 * The TXGAIN_MEM_WD register will be written.
 * @param value - The value to write.
 */
__INLINE void wlan_rf_txgain_mem_wd_set(uint32_t value)
{
    REG_PL_WR(WLAN_RF_TXGAIN_MEM_WD_ADDR, value);
}

// field definitions
/// TXGAIN_MEM_WDATA field mask
#define WLAN_RF_TXGAIN_MEM_WDATA_MASK   ((uint32_t)0xFFFFFFFF)
/// TXGAIN_MEM_WDATA field LSB position
#define WLAN_RF_TXGAIN_MEM_WDATA_LSB    0
/// TXGAIN_MEM_WDATA field width
#define WLAN_RF_TXGAIN_MEM_WDATA_WIDTH  ((uint32_t)0x00000020)

/// TXGAIN_MEM_WDATA field reset value
#define WLAN_RF_TXGAIN_MEM_WDATA_RST    0x0

/**
 * @brief Returns the current value of the txgain_mem_wdata field in the TXGAIN_MEM_WD register.
 *
 * The TXGAIN_MEM_WD register will be read and the txgain_mem_wdata field's value will be returned.
 *
 * @return The current value of the txgain_mem_wdata field in the TXGAIN_MEM_WD register.
 */
__INLINE uint32_t wlan_rf_txgain_mem_wdata_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_TXGAIN_MEM_WD_ADDR);
    return (localVal >> 0);
}

/**
 * @brief Sets the txgain_mem_wdata field of the TXGAIN_MEM_WD register.
 *
 * The TXGAIN_MEM_WD register will be read, modified to contain the new field value, and written.
 *
 * @param[in] txgainmemwdata - The value to set the field to.
 */
__INLINE void wlan_rf_txgain_mem_wdata_setf(uint32_t txgainmemwdata)
{
    REG_PL_WR(WLAN_RF_TXGAIN_MEM_WD_ADDR, (uint32_t)txgainmemwdata << 0);
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
#define WLAN_RF_TXGAIN_MEM_RD_ADDR   0x40344074
/// Offset of the TXGAIN_MEM_RD register from the base address
#define WLAN_RF_TXGAIN_MEM_RD_OFFSET 0x00000074
/// Index of the TXGAIN_MEM_RD register
#define WLAN_RF_TXGAIN_MEM_RD_INDEX  0x0000001D
/// Reset value of the TXGAIN_MEM_RD register
#define WLAN_RF_TXGAIN_MEM_RD_RESET  0x00000000

/**
 * @brief Returns the current value of the TXGAIN_MEM_RD register.
 * The TXGAIN_MEM_RD register will be read and its value returned.
 * @return The current value of the TXGAIN_MEM_RD register.
 */
__INLINE uint32_t wlan_rf_txgain_mem_rd_get(void)
{
    return REG_PL_RD(WLAN_RF_TXGAIN_MEM_RD_ADDR);
}

/**
 * @brief Sets the TXGAIN_MEM_RD register to a value.
 * The TXGAIN_MEM_RD register will be written.
 * @param value - The value to write.
 */
__INLINE void wlan_rf_txgain_mem_rd_set(uint32_t value)
{
    REG_PL_WR(WLAN_RF_TXGAIN_MEM_RD_ADDR, value);
}

// field definitions
/// TXGAIN_MEM_RDATA field mask
#define WLAN_RF_TXGAIN_MEM_RDATA_MASK   ((uint32_t)0xFFFFFFFF)
/// TXGAIN_MEM_RDATA field LSB position
#define WLAN_RF_TXGAIN_MEM_RDATA_LSB    0
/// TXGAIN_MEM_RDATA field width
#define WLAN_RF_TXGAIN_MEM_RDATA_WIDTH  ((uint32_t)0x00000020)

/// TXGAIN_MEM_RDATA field reset value
#define WLAN_RF_TXGAIN_MEM_RDATA_RST    0x0

/**
 * @brief Returns the current value of the txgain_mem_rdata field in the TXGAIN_MEM_RD register.
 *
 * The TXGAIN_MEM_RD register will be read and the txgain_mem_rdata field's value will be returned.
 *
 * @return The current value of the txgain_mem_rdata field in the TXGAIN_MEM_RD register.
 */
__INLINE uint32_t wlan_rf_txgain_mem_rdata_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_TXGAIN_MEM_RD_ADDR);
    return (localVal >> 0);
}

/**
 * @brief Sets the txgain_mem_rdata field of the TXGAIN_MEM_RD register.
 *
 * The TXGAIN_MEM_RD register will be read, modified to contain the new field value, and written.
 *
 * @param[in] txgainmemrdata - The value to set the field to.
 */
__INLINE void wlan_rf_txgain_mem_rdata_setf(uint32_t txgainmemrdata)
{
    REG_PL_WR(WLAN_RF_TXGAIN_MEM_RD_ADDR, (uint32_t)txgainmemrdata << 0);
}

/// @}

/**
 * @name EXT_PA_CTRL register definitions
 * <table>
 * <caption id="EXT_PA_CTRL_BF">EXT_PA_CTRL bitfields</caption>
 * <tr><th>Bits <th>Field Name <th>HW Access <th>SW Access <th>Reset Value
 * <tr><td>28:20 <td>    ext_rxon_delay <td>R <td>R/W <td>0x0
 * <tr><td>19:11 <td>    ext_txon_delay <td>R <td>R/W <td>0x0
 * <tr><td>10:08 <td>         ext_pa_rx <td>R <td>R/W <td>0x0
 * <tr><td>07:04 <td>         ext_pa_tx <td>R <td>R/W <td>0x0
 * <tr><td>03:00 <td>       ext_pa_idle <td>R <td>R/W <td>0x0
 * </table>
 *
 * @{
 */

/// Address of the EXT_PA_CTRL register
#define WLAN_RF_EXT_PA_CTRL_ADDR   0x40344078
/// Offset of the EXT_PA_CTRL register from the base address
#define WLAN_RF_EXT_PA_CTRL_OFFSET 0x00000078
/// Index of the EXT_PA_CTRL register
#define WLAN_RF_EXT_PA_CTRL_INDEX  0x0000001E
/// Reset value of the EXT_PA_CTRL register
#define WLAN_RF_EXT_PA_CTRL_RESET  0x00000000

/**
 * @brief Returns the current value of the EXT_PA_CTRL register.
 * The EXT_PA_CTRL register will be read and its value returned.
 * @return The current value of the EXT_PA_CTRL register.
 */
__INLINE uint32_t wlan_rf_ext_pa_ctrl_get(void)
{
    return REG_PL_RD(WLAN_RF_EXT_PA_CTRL_ADDR);
}

/**
 * @brief Sets the EXT_PA_CTRL register to a value.
 * The EXT_PA_CTRL register will be written.
 * @param value - The value to write.
 */
__INLINE void wlan_rf_ext_pa_ctrl_set(uint32_t value)
{
    REG_PL_WR(WLAN_RF_EXT_PA_CTRL_ADDR, value);
}

// field definitions
/// EXT_RXON_DELAY field mask
#define WLAN_RF_EXT_RXON_DELAY_MASK   ((uint32_t)0x1FF00000)
/// EXT_RXON_DELAY field LSB position
#define WLAN_RF_EXT_RXON_DELAY_LSB    20
/// EXT_RXON_DELAY field width
#define WLAN_RF_EXT_RXON_DELAY_WIDTH  ((uint32_t)0x00000009)
/// EXT_TXON_DELAY field mask
#define WLAN_RF_EXT_TXON_DELAY_MASK   ((uint32_t)0x000FF800)
/// EXT_TXON_DELAY field LSB position
#define WLAN_RF_EXT_TXON_DELAY_LSB    11
/// EXT_TXON_DELAY field width
#define WLAN_RF_EXT_TXON_DELAY_WIDTH  ((uint32_t)0x00000009)
/// EXT_PA_RX field mask
#define WLAN_RF_EXT_PA_RX_MASK        ((uint32_t)0x00000700)
/// EXT_PA_RX field LSB position
#define WLAN_RF_EXT_PA_RX_LSB         8
/// EXT_PA_RX field width
#define WLAN_RF_EXT_PA_RX_WIDTH       ((uint32_t)0x00000003)
/// EXT_PA_TX field mask
#define WLAN_RF_EXT_PA_TX_MASK        ((uint32_t)0x000000F0)
/// EXT_PA_TX field LSB position
#define WLAN_RF_EXT_PA_TX_LSB         4
/// EXT_PA_TX field width
#define WLAN_RF_EXT_PA_TX_WIDTH       ((uint32_t)0x00000004)
/// EXT_PA_IDLE field mask
#define WLAN_RF_EXT_PA_IDLE_MASK      ((uint32_t)0x0000000F)
/// EXT_PA_IDLE field LSB position
#define WLAN_RF_EXT_PA_IDLE_LSB       0
/// EXT_PA_IDLE field width
#define WLAN_RF_EXT_PA_IDLE_WIDTH     ((uint32_t)0x00000004)

/// EXT_RXON_DELAY field reset value
#define WLAN_RF_EXT_RXON_DELAY_RST    0x0
/// EXT_TXON_DELAY field reset value
#define WLAN_RF_EXT_TXON_DELAY_RST    0x0
/// EXT_PA_RX field reset value
#define WLAN_RF_EXT_PA_RX_RST         0x0
/// EXT_PA_TX field reset value
#define WLAN_RF_EXT_PA_TX_RST         0x0
/// EXT_PA_IDLE field reset value
#define WLAN_RF_EXT_PA_IDLE_RST       0x0

/**
 * @brief Constructs a value for the EXT_PA_CTRL register given values for its fields
 * and writes the value to the register.
 *
 * @param[in] extrxondelay - The value to use for the ext_rxon_delay field.
 * @param[in] exttxondelay - The value to use for the ext_txon_delay field.
 * @param[in] extparx - The value to use for the ext_pa_rx field.
 * @param[in] extpatx - The value to use for the ext_pa_tx field.
 * @param[in] extpaidle - The value to use for the ext_pa_idle field.
 */
__INLINE void wlan_rf_ext_pa_ctrl_pack(uint16_t extrxondelay, uint16_t exttxondelay, uint8_t extparx, uint8_t extpatx, uint8_t extpaidle)
{
    REG_PL_WR(WLAN_RF_EXT_PA_CTRL_ADDR,  ((uint32_t)extrxondelay << 20) | ((uint32_t)exttxondelay << 11) | ((uint32_t)extparx << 8) | ((uint32_t)extpatx << 4) | ((uint32_t)extpaidle << 0));
}

/**
 * @brief Unpacks EXT_PA_CTRL's fields from current value of the EXT_PA_CTRL register.
 *
 * Reads the EXT_PA_CTRL register and populates all the _field variables with the corresponding
 * values from the register.
 *
 * @param[out] extrxondelay - Will be populated with the current value of this field from the register.
 * @param[out] exttxondelay - Will be populated with the current value of this field from the register.
 * @param[out] extparx - Will be populated with the current value of this field from the register.
 * @param[out] extpatx - Will be populated with the current value of this field from the register.
 * @param[out] extpaidle - Will be populated with the current value of this field from the register.
 */
__INLINE void wlan_rf_ext_pa_ctrl_unpack(uint16_t* extrxondelay, uint16_t* exttxondelay, uint8_t* extparx, uint8_t* extpatx, uint8_t* extpaidle)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_EXT_PA_CTRL_ADDR);

    *extrxondelay = (localVal & ((uint32_t)0x1FF00000)) >> 20;
    *exttxondelay = (localVal & ((uint32_t)0x000FF800)) >> 11;
    *extparx = (localVal & ((uint32_t)0x00000700)) >> 8;
    *extpatx = (localVal & ((uint32_t)0x000000F0)) >> 4;
    *extpaidle = (localVal & ((uint32_t)0x0000000F)) >> 0;
}

/**
 * @brief Returns the current value of the ext_rxon_delay field in the EXT_PA_CTRL register.
 *
 * The EXT_PA_CTRL register will be read and the ext_rxon_delay field's value will be returned.
 *
 * @return The current value of the ext_rxon_delay field in the EXT_PA_CTRL register.
 */
__INLINE uint16_t wlan_rf_ext_rxon_delay_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_EXT_PA_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x1FF00000)) >> 20);
}

/**
 * @brief Sets the ext_rxon_delay field of the EXT_PA_CTRL register.
 *
 * The EXT_PA_CTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] extrxondelay - The value to set the field to.
 */
__INLINE void wlan_rf_ext_rxon_delay_setf(uint16_t extrxondelay)
{
    REG_PL_WR(WLAN_RF_EXT_PA_CTRL_ADDR, (REG_PL_RD(WLAN_RF_EXT_PA_CTRL_ADDR) & ~((uint32_t)0x1FF00000)) | ((uint32_t)extrxondelay << 20));
}

/**
 * @brief Returns the current value of the ext_txon_delay field in the EXT_PA_CTRL register.
 *
 * The EXT_PA_CTRL register will be read and the ext_txon_delay field's value will be returned.
 *
 * @return The current value of the ext_txon_delay field in the EXT_PA_CTRL register.
 */
__INLINE uint16_t wlan_rf_ext_txon_delay_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_EXT_PA_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x000FF800)) >> 11);
}

/**
 * @brief Sets the ext_txon_delay field of the EXT_PA_CTRL register.
 *
 * The EXT_PA_CTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] exttxondelay - The value to set the field to.
 */
__INLINE void wlan_rf_ext_txon_delay_setf(uint16_t exttxondelay)
{
    REG_PL_WR(WLAN_RF_EXT_PA_CTRL_ADDR, (REG_PL_RD(WLAN_RF_EXT_PA_CTRL_ADDR) & ~((uint32_t)0x000FF800)) | ((uint32_t)exttxondelay << 11));
}

/**
 * @brief Returns the current value of the ext_pa_rx field in the EXT_PA_CTRL register.
 *
 * The EXT_PA_CTRL register will be read and the ext_pa_rx field's value will be returned.
 *
 * @return The current value of the ext_pa_rx field in the EXT_PA_CTRL register.
 */
__INLINE uint8_t wlan_rf_ext_pa_rx_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_EXT_PA_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000700)) >> 8);
}

/**
 * @brief Sets the ext_pa_rx field of the EXT_PA_CTRL register.
 *
 * The EXT_PA_CTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] extparx - The value to set the field to.
 */
__INLINE void wlan_rf_ext_pa_rx_setf(uint8_t extparx)
{
    REG_PL_WR(WLAN_RF_EXT_PA_CTRL_ADDR, (REG_PL_RD(WLAN_RF_EXT_PA_CTRL_ADDR) & ~((uint32_t)0x00000700)) | ((uint32_t)extparx << 8));
}

/**
 * @brief Returns the current value of the ext_pa_tx field in the EXT_PA_CTRL register.
 *
 * The EXT_PA_CTRL register will be read and the ext_pa_tx field's value will be returned.
 *
 * @return The current value of the ext_pa_tx field in the EXT_PA_CTRL register.
 */
__INLINE uint8_t wlan_rf_ext_pa_tx_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_EXT_PA_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x000000F0)) >> 4);
}

/**
 * @brief Sets the ext_pa_tx field of the EXT_PA_CTRL register.
 *
 * The EXT_PA_CTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] extpatx - The value to set the field to.
 */
__INLINE void wlan_rf_ext_pa_tx_setf(uint8_t extpatx)
{
    REG_PL_WR(WLAN_RF_EXT_PA_CTRL_ADDR, (REG_PL_RD(WLAN_RF_EXT_PA_CTRL_ADDR) & ~((uint32_t)0x000000F0)) | ((uint32_t)extpatx << 4));
}

/**
 * @brief Returns the current value of the ext_pa_idle field in the EXT_PA_CTRL register.
 *
 * The EXT_PA_CTRL register will be read and the ext_pa_idle field's value will be returned.
 *
 * @return The current value of the ext_pa_idle field in the EXT_PA_CTRL register.
 */
__INLINE uint8_t wlan_rf_ext_pa_idle_getf(void)
{
    uint32_t localVal = REG_PL_RD(WLAN_RF_EXT_PA_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x0000000F)) >> 0);
}

/**
 * @brief Sets the ext_pa_idle field of the EXT_PA_CTRL register.
 *
 * The EXT_PA_CTRL register will be read, modified to contain the new field value, and written.
 *
 * @param[in] extpaidle - The value to set the field to.
 */
__INLINE void wlan_rf_ext_pa_idle_setf(uint8_t extpaidle)
{
    REG_PL_WR(WLAN_RF_EXT_PA_CTRL_ADDR, (REG_PL_RD(WLAN_RF_EXT_PA_CTRL_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)extpaidle << 0));
}

/// @}


#endif // _REG_WLAN_RF_H_

/// @}

