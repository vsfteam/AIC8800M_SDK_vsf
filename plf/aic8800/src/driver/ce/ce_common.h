/**
 ****************************************************************************************
 *
 * @file ce_common.h
 *
 * @brief CE common header file
 *
 ****************************************************************************************
 */

#ifndef _CE_COMMON_H_
#define _CE_COMMON_H_

/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include "reg_dma.h"
#include "dma_api.h"

#define RSA2048_WORD_NUM          64
#define RSA1024_WORD_NUM          32
#define ECC160_WORD_NUM           5
#define ECC224_WORD_NUM           7
#define ECC256_WORD_NUM           8
#define ECC384_WORD_NUM           12
#define ECC512_WORD_NUM           16

#define CE_RESULT_UNREADY         0x00
#define CE_RESULT_WAIT_OUT        0x01
#define CE_RESULT_READY           0x02

typedef enum {
    AES_MODE       = 0x00,
    HASH_MODE      = 0x01,
    RSA_MODE       = 0x02,
    ECC_MODE       = 0x03,
    UNSUPPORT_MODE = 0x04
} DMA_CYPT_MOD_T;

typedef enum {
    AES_ECB_MODE    = 0x00,
    AES_CBC_MODE    = 0x01,
    AES_CTR_MODE    = 0x02,
    AES_GCM_MODE    = 0x03
} DMA_CYPT_AES_MOD_T;

typedef enum {
    AES_128_MODE    = 0x04,
    AES_192_MODE    = 0x06,
    AES_256_MODE    = 0x08,
} DMA_CYPT_AES_KEYLEN_T;

typedef enum {
    AES_ENCR        = 0x00,
    AES_DECR        = 0x01
} DMA_CYPT_AES_ENCR_SEL_T;

typedef enum {
    RSA_1024_MODE   = 0x00,
    RSA_2048_MODE   = 0x01
} DMA_CYPT_RSA_MOD_T;

typedef enum {
    ECC_160_MODE    = 0x00,
    ECC_224_MODE    = 0x01,
    ECC_256_MODE    = 0x02,
    ECC_384_MODE    = 0x03,
    ECC_512_MODE    = 0x04
} DMA_CYPT_ECC_MOD_T;

typedef enum {
   ECC_A_NOT_EQ_MINUS_3  = 0x00,
   ECC_A_EQ_MINUS_3      = 0x01
} DMA_CYPT_A_EQ_P3_T;

typedef enum {
   PKA_R2_MODP_UNREADY  = 0x00,
   PKA_R2_MODP_READY    = 0x01
} DMA_R2_MODP_READY_T;

typedef enum {
   AES_BIG_ENDIAN       = 0x00,
   AES_LITTLE_ENDIAN    = 0x01
} DMA_AES_ENDIAN_T;

typedef enum {
   HASH_BIG_ENDIAN       = 0x00,
   HASH_LITTLE_ENDIAN    = 0x01
} DMA_HASH_ENDIAN_T;

typedef enum {
    HASH_SHA224_MODE  = 0x00,
    HASH_SHA256_MODE  = 0x01,
    HASH_SHA1_MODE    = 0x02
} DMA_CYPT_HASH_MOD_T;

typedef enum {
    HASH_SW_PAD       = 0x00,
    HASH_HW_PAD       = 0x01
} DMA_CYPT_HASH_PAD_T;

typedef struct {
    uint32_t length_byte;
    uint32_t *aes_data;
} aes_state_t;

typedef struct {
    uint32_t cipher_dat_len_byte;
    uint32_t auth_dat_len_byte;
    uint32_t auth_dat_pad_len_byte;
    uint32_t *auth_data;
    uint32_t *aes_data;
} aes_gcm_state_t;

typedef struct {
    uint32_t length_byte;
    uint8_t *buf;
} hash_state_t;

typedef struct {
    uint32_t                aes_key[8];
    uint32_t                aes_iv[4];
    DMA_CYPT_AES_KEYLEN_T   aes_keylen;
    uint64_t                aes_plain_len;
    uint64_t                aes_a_len;
    DMA_CYPT_MOD_T          dma_cypt_mode;
    uint8_t                 ce_chn;
    DMA_CYPT_AES_ENCR_SEL_T aes_enc_decr_sel;     //aes encrypt or descrypt mode select
    uint8_t                 rsa_keylen;
    uint32_t                mod_mult_parameter;
    DMA_CYPT_ECC_MOD_T      ecc_mode;
    DMA_CYPT_RSA_MOD_T      rsa_mode;
    DMA_CYPT_AES_MOD_T      aes_mode;
    DMA_CYPT_A_EQ_P3_T      ecc_a_eq_p3;
    DMA_R2_MODP_READY_T     R2modP_sta;
    DMA_AES_ENDIAN_T        aes_endian_sel;
    DMA_HASH_ENDIAN_T       hash_endian_sel;
    DMA_CYPT_HASH_MOD_T     hash_mode;
    DMA_CYPT_HASH_PAD_T     hash_pad_sel;
} dma_cypt_t;

#endif // _CE_COMMON_H_
