#ifndef _ASIO_H_
#define _ASIO_H_

#include <stdint.h>
#include <stdbool.h>
#include "audio_types.h"
#include "dma_api_bt.h"

//PingPong
typedef enum {
    ASIO_PP_PING = 0,
    ASIO_PP_PANG = 1
} ASIO_PP_T;

typedef enum {
    ASIO_STATUS_NONE            = 0x00,//initial value
    ASIO_STATUS_ASIO_OPEN       = 0x01,//set at asio_open ,clear at asio_close
    ASIO_STATUS_STREAM_OPEN     = 0x02,//set at asio_stream_open, clear at asio_stream_close
    ASIO_STATUS_STREAM_START    = 0x04,//set at asio_stream_start, clear at asio_stream_stop
    ASIO_STATUS_STREAM_PAUSE    = 0x08,//set at asio_stream_pause, clear at asio_stream_resume
    ASIO_STATUS_MASK            = 0x0F,
} ASIO_STATUS_T;

typedef enum {
    ASIO_ERR_NONE = 0,
    ASIO_ERR_FAIL = -1,
} ASIO_ERR_T;

#define ASIO_PP_NEXT(pp)    (pp == ASIO_PP_PING ? ASIO_PP_PANG : ASIO_PP_PING)

typedef uint32_t (*ASIO_STREAM_HANDLER_T)(uint8_t *buf, uint32_t len);

typedef struct {
    bool sync_en;
    bool sync_master;
    AUD_CH_NUM_T sync_ch_num;
    uint8_t sync_ch_map;
} ASIO_STREAM_SYNC_T;

typedef struct {
    AUD_BITS_T bits;
    AUD_CH_NUM_T ch_num;
    //used by internal codec adc
    uint8_t ch_map;
    AUD_DEVICE_T device;
    AUD_PATH_T path;
    /*
     * if src_en is true, then src_samp_rate must be set correctly
     *
     * for playback, samp_rate is input of SRC, src_samp_rate is output of SRC
     * buffer--->samp_rate--->SRC--->src_samp_rate--->device
     *
     * for capture, samp_rate is output of SRC, src_samp_rate is input of SRC
     * buffer<---samp_rate<---SRC<---src_samp_rate<---device
     */
    AUD_SAMPRATE_T samp_rate;
    AUD_SAMPRATE_T src_samp_rate;
    ASIO_STREAM_HANDLER_T handler;
    uint8_t *buf_ptr;
    uint32_t buf_size;
    bool src_en;
    bool eq_en;
    bool mux_en;
    uint8_t vol;

    //only by internal codec adc when software use the 3rd mic, the 3rd mic must be used with the 1st and 2nd mic togrther
    ASIO_STREAM_SYNC_T sync;
} ASIO_STREAM_CFG_T;

typedef struct {
    ASIO_PP_T pp_index;     //pcm buffer PingPong index
    uint8_t pp_cnt;         //count of missed notifications
    uint8_t status;
    AUD_DEVICE_T device;
    AUD_PATH_T path;
    uint8_t rsvd[3];//for DWORD align
} ASIO_STREAM_CTL_T;

typedef struct {
    ASIO_STREAM_CTL_T ctl;
    ASIO_STREAM_CFG_T cfg;

    ASIO_STREAM_HANDLER_T handler;

    // dma buffer pointer and buffer size
    uint8_t *dma_buf_ptr;
    uint32_t dma_buf_size;

    /* Must keep desc DWORD align */
    DMA_CX_DESC_T *dma_cx_desc[2];

    DMA_CFG_T dma_cfg;
} ASIO_STREAM_ENTITY_T;

void asio_task_lock(void);
void asio_task_unlock(void);
void asio_stream_handler_running_set(AUD_STREAM_GROUP_T group, AUD_STREAM_T stream, bool running);
bool asio_stream_handler_running_get(AUD_STREAM_GROUP_T group, AUD_STREAM_T stream);
int asio_open(void);
void asio_stream_update_dma_config(AUD_STREAM_GROUP_T group, AUD_STREAM_T stream, const ASIO_STREAM_CFG_T *cfg);
int asio_stream_open(AUD_STREAM_GROUP_T group, AUD_STREAM_T stream, const ASIO_STREAM_CFG_T *cfg);
int asio_stream_config(AUD_STREAM_GROUP_T group, AUD_STREAM_T stream, const ASIO_STREAM_CFG_T *cfg);
void asio_stream_mute(AUD_STREAM_T stream);
int asio_stream_raw_digital_volume_set(AUD_STREAM_T stream, uint8_t volume);
uint8_t asio_stream_raw_digital_volume_get(AUD_STREAM_T stream);
bool asio_stream_raw_digital_volume_up(AUD_STREAM_T stream, uint8_t step);
bool asio_stream_raw_digital_volume_down(AUD_STREAM_T stream, uint8_t step);
int asio_stream_preload(AUD_STREAM_GROUP_T group, AUD_STREAM_T stream, bool ping);
int asio_stream_start(AUD_STREAM_GROUP_T group, AUD_STREAM_T stream);
int asio_stream_stop(AUD_STREAM_GROUP_T group, AUD_STREAM_T stream);
int asio_stream_pause(AUD_STREAM_GROUP_T group, AUD_STREAM_T stream);
int asio_stream_resume(AUD_STREAM_GROUP_T group, AUD_STREAM_T stream);
int asio_stream_close(AUD_STREAM_GROUP_T group, AUD_STREAM_T stream);
int asio_close(void);
int asio_stream_config_get(AUD_STREAM_GROUP_T group, AUD_STREAM_T stream, ASIO_STREAM_CFG_T *cfg, bool lock_task);
int asio_stream_config_ptr_get(AUD_STREAM_GROUP_T group, AUD_STREAM_T stream, ASIO_STREAM_CFG_T **cfg, bool lock_task);
uint8_t *asio_stream_dma_buf_ptr_get(AUD_STREAM_GROUP_T group, AUD_STREAM_T stream);
uint32_t asio_stream_current_dma_addr_get(AUD_STREAM_GROUP_T group, AUD_STREAM_T stream);
uint32_t asio_stream_current_dma_lli_cntr_get(AUD_STREAM_GROUP_T group, AUD_STREAM_T stream);
void asio_task_priority_set(uint32_t priority);
uint32_t asio_task_priority_get(void);
uint32_t asio_task_default_priority_get(void);
void asio_task_priority_reset(void);
void asio_init(void);
#endif

