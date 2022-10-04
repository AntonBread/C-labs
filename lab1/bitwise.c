#include <stdint.h>
#include "bitwise.h"

// change all types to stdint ones

//
// Set Bits
//

void setBits_8(int8_t* x, int8_t mask)
{
    *x = *x | mask;
}

void setBits_16(int16_t* x, int16_t mask)
{
    *x = *x | mask;
}

void setBits_32(int32_t* x, int32_t mask)
{
    *x = *x | mask;
}



//
// Reset Bits
//

void resetBits_8(int8_t* x, int8_t mask)
{
    *x = *x & mask;
}

void resetBits_16(int16_t* x, int16_t mask)
{
    *x = *x & mask;
}

void resetBits_32(int32_t* x, int32_t mask)
{
    *x = *x & mask;
}



//
// Inverse Bits
//

void inverseBitsMask_8(int8_t* x, int8_t mask)
{
    *x = *x ^ mask;
}

void inverseBitsMask_16(int16_t* x, int16_t mask)
{
    *x = *x ^ mask;
}

void inverseBitsMask_32(int32_t* x, int32_t mask)
{
    *x = *x ^ mask;
}



//
// Logical Left Shift
//

void logicalLeftShift_8(int8_t* x, int shift)
{
    *x = *x << shift;
}

void logicalLeftShift_16(int16_t* x, int shift)
{
    *x = *x << shift;
}

void logicalLeftShift_32(int32_t* x, int shift)
{
    *x = *x << shift;
}



//
// Logical Right Shift
//

void logicalRightShift_8(int8_t* x, int shift)
{
    *x = *x >> shift;
}

void logicalRightShift_16(int16_t* x, int shift)
{
    *x = *x >> shift;
}

void logicalRightShift_32(int32_t* x, int shift)
{
    *x = *x >> shift;
}



//
// Circular Left Shift
//

void circularLeftShift_8(int8_t* x, int shift)
{
    // Unsigned temp because right shifting signed numbers
    // fills the upper bits with whatever was in the last bit
    uint8_t temp = *x;
    shift = (shift % 8);
    *x = (temp << shift) | (temp >> (8 - shift));
}

void circularLeftShift_16(int16_t* x, int shift)
{
    uint16_t temp = *x;
    shift = (shift % 16);
    *x = (temp << shift) | (temp >> (16 - shift));
}

void circularLeftShift_32(int32_t* x, int shift)
{
    uint32_t temp = *x;
    shift = (shift % 32);
    *x = (temp << shift) | (temp >> (32 - shift));
}



//
// Circular Right Shift
//

void circularRightShift_8(int8_t* x, int shift)
{
    uint8_t temp = *x;
    shift = (shift % 8);
    *x = (temp >> shift) | (temp << (8 - shift));
}

void circularRightShift_16(int16_t* x, int shift)
{
    uint16_t temp = *x;
    shift = (shift % 16);
    *x = (temp >> shift) | (temp << (16 - shift));
}

void circularRightShift_32(int32_t* x, int shift)
{
    uint32_t temp = *x;
    shift = (shift % 32);
    *x = (temp >> shift) | (temp << (32 - shift));
}
