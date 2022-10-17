#ifndef DS18B20_H
#define DS18B20_H

#include <stdint.h>

#define CONFIG_RES_9 0x1F
#define CONFIG_RES_10 0x3F
#define CONFIG_RES_11 0x5F
#define CONFIG_RES_12 0x7F

// One-Wire commands:
#define SEARCH_ROM 0xF0
#define READ_ROM 0x33
#define MATCH_ROM 0x55
#define SKIP_ROM 0xCC
#define ALARM_SEARCH 0xEC
#define CONVERT_T 0x44
#define WRITE_SCRATCHPAD 0x4E
#define READ_SCRATCHPAD 0xBE
#define COPY_SCRATCHPAD 0x48
#define RECALL 0xB8
#define READ_POWER_SUPPLY 0xB4

typedef struct ScratchpadTypeDef ScratchpadTypeDef;

struct ScratchpadTypeDef
{
    uint8_t temp_LSB;
    int8_t temp_MSB;
    int8_t alarm_TH;
    int8_t alarm_TL;
    int8_t config;
    int8_t reserved_1;
    int8_t reserved_2;
    int8_t reserved_3;
    int8_t CRC8;
    
    int8_t rom[8];
    
    int8_t logIndex;
    float tempf;
    float log[100];
};

void scratchpadInit(ScratchpadTypeDef *scratchpad);

float getTemp(ScratchpadTypeDef *scratchpad);

void setTemp_LSB(ScratchpadTypeDef *scratchpad, uint8_t lsb);
void setTemp_MSB(ScratchpadTypeDef *scratchpad, int8_t msb);

void setTempf(ScratchpadTypeDef *scratchpad, float temp);

void setConfig(ScratchpadTypeDef *scratchpad, int8_t resolution);

void setAlarm_TH(ScratchpadTypeDef *scratchpad, int8_t temp);

void setAlarm_TL(ScratchpadTypeDef *scratchpad, int8_t temp);

void setCRC(ScratchpadTypeDef *scratchpad, int8_t CRC);

void setReserved_1(ScratchpadTypeDef *scratchpad, int8_t value);
void setReserved_2(ScratchpadTypeDef *scratchpad, int8_t value);
void setReserved_3(ScratchpadTypeDef *scratchpad, int8_t value);

void logTemp(ScratchpadTypeDef *scratchpad, float temp);

#endif
