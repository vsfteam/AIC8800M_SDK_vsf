#include <stdint.h>

void audio_memcpy_16bit(int16_t *dst, int16_t *src, uint32_t n)
{
    for (uint32_t i = 0; i < n; i++) {
        dst[i] = src[i];
    }
}

void audio_memset_16bit(int16_t *dst, int16_t val, uint32_t n)
{
    for (uint32_t i = 0; i < n; i++) {
        dst[i] = val;
    }
}

void audio_channel_copy_16bits(int16_t *dst, int16_t *src, uint32_t src_n)
{
    for (int i = (int)(src_n - 1); i >= 0; i--) {
        dst[i * 2 + 0] = dst[i * 2 + 1] = src[i];
    }
}

void audio_channel_merge_16bits(int16_t *dst, int16_t *src, uint32_t dst_n)
{
    for (uint32_t i = 0; i < dst_n; i++) {
        dst[i] = src[i * 2];
    }
}

void audio_memcpy_24bit(int32_t *dst, int32_t *src, uint32_t n)
{
    for (uint32_t i = 0; i < n; i++) {
        dst[i] = src[i];
    }
}

void audio_memset_24bit(int32_t *dst, int32_t val, uint32_t n)
{
    for (uint32_t i = 0; i < n; i++) {
        dst[i] = val;
    }
}

void audio_channel_copy_24bits(int32_t *dst, int32_t *src, uint32_t src_n)
{
    for (int i = (int)(src_n - 1); i >= 0; i--) {
        dst[i * 2 + 0] = dst[i * 2 + 1] = src[i];
    }
}

void audio_channel_merge_24bits(int32_t *dst, int32_t *src, uint32_t dst_n)
{
    for (uint32_t i = 0; i < dst_n; i++) {
        dst[i] = src[i * 2];
    }
}
