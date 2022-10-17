#include <stdint.h>
#include <math.h>
#include "ds18b20.h"

void scratchpadInit(ScratchpadTypeDef *scratchpad)
{
    (*scratchpad).temp_LSB = 0;
    (*scratchpad).temp_MSB = 0;
    (*scratchpad).alarm_TH = 125;
    (*scratchpad).alarm_TL = -55;
    (*scratchpad).config = CONFIG_RES_9;
    (*scratchpad).CRC8 = 0;
    (*scratchpad).logIndex = 0;
    (*scratchpad).tempf = 0.0;
    
    for (int i = 0; i < 8; i++)
    {
        (*scratchpad).rom[i] = 0;
    }
}

float getTemp(ScratchpadTypeDef *scratchpad)
{
    float temp = (((*scratchpad).temp_MSB * 256) + (*scratchpad).temp_LSB)*0.0625;
    (*scratchpad).tempf = temp;
    return temp;
}

void setTemp_LSB(ScratchpadTypeDef *scratchpad, uint8_t lsb)
{
    (*scratchpad).temp_LSB = lsb;
}

void setTemp_MSB(ScratchpadTypeDef *scratchpad, int8_t msb)
{
    (*scratchpad).temp_MSB = msb;
}

void setTempf(ScratchpadTypeDef *scratchpad, float temp)
{
    float temp2 = temp / 16;
    float temp3 = truncf(temp2);
    float temp4 = temp2 - temp3;
    
    uint8_t lsb = temp4 * 256;
    int8_t msb = temp3;
    
    (*scratchpad).temp_LSB = lsb;
    (*scratchpad).temp_MSB = msb;
    (*scratchpad).tempf = temp;
}

void setConfig(ScratchpadTypeDef *scratchpad, int8_t resolution)
{
    switch (resolution)
    {
        case CONFIG_RES_9:
            (*scratchpad).config = resolution;
            break;
        case CONFIG_RES_10:
            (*scratchpad).config = resolution;
            break;
        case CONFIG_RES_11:
            (*scratchpad).config = resolution;
            break;
        case CONFIG_RES_12:
            (*scratchpad).config = resolution;
            break;
    }
}

void setAlarm_TH(ScratchpadTypeDef *scratchpad, int8_t temp)
{
    (*scratchpad).alarm_TH = temp;
}

void setAlarm_TL(ScratchpadTypeDef *scratchpad, int8_t temp)
{
    (*scratchpad).alarm_TL = temp;
}

void setCRC(ScratchpadTypeDef *scratchpad, int8_t CRC)
{
    (*scratchpad).CRC8 = CRC;
}

void setReserved_1(ScratchpadTypeDef *scratchpad, int8_t value)
{
    (*scratchpad).reserved_1 = value;
}

void setReserved_2(ScratchpadTypeDef *scratchpad, int8_t value)
{
    (*scratchpad).reserved_2 = value;
}

void setReserved_3(ScratchpadTypeDef *scratchpad, int8_t value)
{
    (*scratchpad).reserved_3 = value;
}

void logTemp(ScratchpadTypeDef *scratchpad, float temp)
{
    (*scratchpad).log[(*scratchpad).logIndex] = temp;
    (*scratchpad).logIndex++;
    if ((*scratchpad).logIndex >= 100)
        (*scratchpad).logIndex = 0;
}
