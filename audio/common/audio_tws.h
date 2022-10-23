#ifndef _AUDIO_TWS_H_
#define _AUDIO_TWS_H_

typedef struct{
    uint32_t current_clk;
    uint32_t counterNum;
    uint32_t master_current_samplerate;
    uint32_t current_bt_counter;
    uint32_t current_bt_counter_offset;
    uint32_t strb_cycle_offset;
}MediaSyncParamStruct;

typedef struct{
    uint32_t one_frame_size;              //sbc: frame len  ; aac: 0
    uint32_t inbuffer_frame_num;          //input buffer frame num ; sbc: num * 128 = all in sample count ;aac: num*1024 = all in sample count
    uint32_t one_byte_times;              //us
}Audio_Sync_Struct;

typedef struct{
    uint32_t sco_input_frame_num;
    uint32_t sco_cacheing_0_num;
    uint32_t sco_drop_frame_num;
}Sco_Sync_Struct;

#endif
