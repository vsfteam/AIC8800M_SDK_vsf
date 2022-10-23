#ifndef _AUDIO_UTILS_H_
#define _AUDIO_UTILS_H_

#include <stdint.h>

void audio_memcpy_16bit(int16_t *dst, int16_t *src, uint32_t n);
void audio_memset_16bit(int16_t *dst, int16_t val, uint32_t n);
void audio_channel_copy_16bits(int16_t *dst, int16_t *src, uint32_t src_n);
void audio_channel_merge_16bits(int16_t *dst, int16_t *src, uint32_t dst_n);
void audio_memcpy_24bit(int32_t *dst, int32_t *src, uint32_t n);
void audio_memset_24bit(int32_t *dst, int32_t val, uint32_t n);
void audio_channel_copy_24bits(int32_t *dst, int32_t *src, uint32_t src_n);
void audio_channel_merge_24bits(int32_t *dst, int32_t *src, uint32_t dst_n);

#endif
