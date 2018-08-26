/*
 * data.c
 *
 *  Created on: 21-Aug-2018
 *      Author: hrishi
 */

/**
 * @file data.c
 * @brief APIs for integer to ASCII conversion and vice-versa.
 * @author Pranav Deshpande
 * @date 21-Aug-2018
 *
 */

#include "data.h"

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base) {

  uint8_t count = 0;
  int8_t sign = 1;
  int32_t remainder;

  if (data == 0) {
    *ptr = '0';
    ptr++;
    *ptr = '\0';
    --ptr;
    return 1;
  }

  *ptr = '\0';
  ptr++;
  count++;

  if (data < 0) {
    sign = -1;
    data = -data;
  }

  while (data != 0) {
    remainder = data % (int32_t)base;
    *ptr = (remainder > 9) ? (remainder - 10) + 'a' : remainder + '0';
    data = data/base;
    ptr++;
    count++;
  }

  if (sign == -1) {
    *ptr = '-';
    ptr++;
    count++;
  }

  my_reverse(ptr - count, count);

  return count;
}

int32_t my_atoi(uint8_t * ptr,  uint8_t digits, uint32_t base) {
  int32_t converted = 0;
  uint8_t i;
  int8_t sign = 1;

  if (*ptr == '-') {
    sign = -1;
    ptr++;
    digits--;
  }

  for (i = 0; i < digits-1; ++i) {
    converted = converted * base + (*ptr - '0');
    ptr++;
  }

  return sign*converted;
}


