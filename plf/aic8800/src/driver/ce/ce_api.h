/**
 ****************************************************************************************
 *
 * @file ce_api.h
 *
 * @brief CE utility functions
 *
 ****************************************************************************************
 */

#ifndef _CE_API_H_
#define _CE_API_H_

/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include "arch.h"
#include "ce_common.h"

#define ECC_LENGTH_MAX    112  //16word * 7
#define ECC_KEY_LEN_MAX   16
#define RSA_LENGTH_MAX    384  //64word *6
#define RSA_KEY_LEN_MAX   64

#define HASH_PAD_LENGTH   64  //64byte

int isGreaterThanOrEqual256(uint32_t *bigHexA, uint32_t *bigHexB);

void dma_cypt_init(dma_cypt_t *obj);

void aes_init(dma_cypt_t *obj);

void hash_init(dma_cypt_t *obj);

void rsa_init(dma_cypt_t *obj);

void ecc_init(dma_cypt_t *obj);

void aes_key_update(dma_cypt_t *obj);

void sha1_calc(uint8_t *input, uint32_t ilen, uint8_t output[20]);

void hash_proc_512bit(dma_cypt_t *ce_obj, hash_state_t *hash_obj, uint32_t *hash_result);

void aes_calc(dma_cypt_t *ce_obj, aes_state_t *aes_obj, uint32_t *aes_result);

void aes_gcm_auth_data_init(aes_gcm_state_t *aes_gcm_obj);

void aes_gcm_calc(dma_cypt_t *ce_obj, aes_gcm_state_t *aes_gcm_obj, uint32_t *aes_result, uint32_t *aes_gcm_tag);

void rsa_coef_init(uint32_t *index, uint32_t *Mod_P);

void rsa_calc(dma_cypt_t *ce_obj, uint32_t *base, uint32_t *comb_rsa_data);

void curve_coef_init(dma_cypt_t *ce_obj, uint32_t *coef_A, uint32_t *Mod_P, uint32_t *R2ModP);

void ecc_generate_key(dma_cypt_t *ce_obj, uint32_t *secret_key, uint32_t *public_key_x, uint32_t *public_key_y, uint32_t *EccResult);

uint32_t pka_len_get(dma_cypt_t *obj);

/**
 ****************************************************************************************
 * @brief Get current key len depend on current mode
****************************************************************************************
*/
void pka_key_len_get(dma_cypt_t *obj);

/**
 ****************************************************************************************
 * @brief Calculate R - Mod_P
 * @param[in]   Mod_P        :modulus P
****************************************************************************************
*/
void Mod_P_inv_calc(uint32_t *Mod_P, uint32_t *Mod_P_inv);

/**
 ****************************************************************************************
 * @brief Calculate a big num subtract another big num
 * @param[in]   pBigNum      :big number A, must bigger than big number B
 * @param[in]   pSmallNum    :big number B
****************************************************************************************
*/
void SubtractFromSelfBigHex256(uint32_t *pBigNum, uint32_t *pSmallNum);

/**
 ****************************************************************************************
 * @brief Calculate AmodP (A length equal B length plus 32bit), the result store in tmpHexA
 * @param[in]   tmpHexA      :big number A, length of A equal length of Mod_P plus 32bit
 * @param[in]   Mod_P        :modulus P
****************************************************************************************
*/
void specialModP256(uint32_t *tmpHexA, uint32_t *Mod_P);

/**
 ****************************************************************************************
 * @brief Calculate R2modP = R^2 mod P
 * @param[in]   Mod_P        :modulus P
****************************************************************************************
*/
void R2_calc(uint32_t *Mod_P, uint32_t *R2modP);

/**
 ****************************************************************************************
 * @brief Combine data for RSA calculate, result = base ^ index mod Mod_P
 * @param[in]   base         :base of power operation
 * @param[in]   index        :index of power operation
 * @param[in]   Mod_P        :modulus P
 * @param[in]   R2modP       :R^2 mod P
 ****************************************************************************************
 */
void rsa_data_comb(uint32_t *base, uint32_t *index, uint32_t *Mod_P, uint32_t *R2modP, uint32_t *comb_rsa_data);

/**
 ****************************************************************************************
 * @brief Combine data for ECC calculate, result = secret_key *(public_key_x,public_key_y)
 *
 * @param[in]   secret_key   :secret_key to generator public key / privkey to generator ECDH
 * @param[in]   public_key_x :ellipse curve base ponit x /public key x
 * @param[in]   public_key_y :ellipse curve base ponit y /public key y
 * @param[in]   coef_A       :ellipse curve y^2 = x^3 + coef_A * x + coef_B
 * @param[in]   Mod_P        :modulus P
 * @param[in]   R2modP       :R^2 mod P
 ****************************************************************************************
 */
void ecc_data_comb(uint32_t *secret_key, uint32_t *public_key_x, uint32_t *public_key_y, uint32_t *coef_A, uint32_t *Mod_P, uint32_t *R2modP, uint32_t *comb_ecc_data);

int aic_get_ecc_generate_key_ready(void);

void chksum_calc_trans(uint32_t *src_addr, uint32_t len, uint32_t endian, uint32_t *dest_addr);

void chksum_calc(uint32_t *src_addr, uint32_t len, uint32_t endian);

uint16_t chksum_result_get(void);

#endif // _CE_API_H_
