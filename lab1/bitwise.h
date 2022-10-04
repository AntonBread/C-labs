#ifndef BITWISE_H
#define BITWISE_H

#include <stdint.h>

void setBits_8(int8_t* x, int8_t mask);
void setBits_16(int16_t* x, int16_t mask);
void setBits_32(int32_t* x, int32_t mask);

void resetBits_8(int8_t* x, int8_t mask);
void resetBits_16(int16_t* x, int16_t mask);
void resetBits_32(int32_t* x, int32_t mask);

void inverseBitsMask_8(int8_t* x, int8_t mask);
void inverseBitsMask_16(int16_t* x, int16_t mask);
void inverseBitsMask_32(int32_t* x, int32_t mask);

void logicalLeftShift_8(int8_t* x, int shift);
void logicalLeftShift_16(int16_t* x, int shift);
void logicalLeftShift_32(int32_t* x, int shift);

void logicalRightShift_8(int8_t* x, int shift);
void logicalRightShift_16(int16_t* x, int shift);
void logicalRightShift_32(int32_t* x, int shift);

void circularLeftShift_8(int8_t* x, int shift);
void circularLeftShift_16(int16_t* x, int shift);
void circularLeftShift_32(int32_t* x, int shift);

void circularRightShift_8(int8_t* x, int shift);
void circularRightShift_16(int16_t* x, int shift);
void circularRightShift_32(int32_t* x, int shift);

#endif
