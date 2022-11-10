#ifndef CRC16_H
#define CRC16_H

#include <stdint.h>
#include <stdlib.h>

#define POLY 0x8005 /* x^16 + x^15 + x^2 + 1 */
#define INIT 0x0000

uint16_t calcCRC_bitwise(uint8_t data[], size_t n);

uint16_t calcCRC_table(uint8_t data[], size_t n);

#endif
