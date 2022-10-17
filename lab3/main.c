#include <stdint.h>
#include <stdlib.h>
#include "ds18b20.h"

int main()
{
    int32_t addr = 0x20000600;
    ScratchpadTypeDef *scratchpad = (ScratchpadTypeDef *) addr;
    scratchpadInit(scratchpad);
    setTempf(scratchpad, 23.375);
    setConfig(scratchpad, CONFIG_RES_12);
    float temp = getTemp(scratchpad);
    logTemp(scratchpad, temp);
    
    setTemp_LSB(scratchpad, 0x91);
    setTemp_MSB(scratchpad, 0x01);
    float temp2 = getTemp(scratchpad);
    logTemp(scratchpad, temp2);
    
    (*scratchpad).temp_LSB = 0xA9;
    (*scratchpad).temp_MSB = 0xFF;
    float temp3 = getTemp(scratchpad);
    logTemp(scratchpad, temp3);
    
    size_t structSize = sizeof(*scratchpad);
    return 0;
}
