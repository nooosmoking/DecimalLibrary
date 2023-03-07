#include "head.h"

s21_decimal s21_pow10(int exp) {
  const s21_decimal arr[] = {
      {{0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
        0b00000000000000000000000000000001},
       {.flags = 0}},
      {{0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
        0b00000000000000000000000000001010},
       {.flags = 0}},
      {{0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
        0b00000000000000000000000001100100},
       {.flags = 0}},
      {{0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
        0b00000000000000000000001111101000},
       {.flags = 0}},
      {{0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
        0b00000000000000000010011100010000},
       {.flags = 0}},
      {{0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
        0b00000000000000011000011010100000},
       {.flags = 0}},
      {{0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
        0b00000000000011110100001001000000},
       {.flags = 0}},
      {{0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
        0b00000000100110001001011010000000},
       {.flags = 0}},
      {{0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
        0b00000101111101011110000100000000},
       {.flags = 0}},
      {{0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
        0b00111011100110101100101000000000},
       {.flags = 0}},
      {{0b00000000000000000000000000000000, 0b00000000000000000000000000000010,
        0b01010100000010111110010000000000},
       {.flags = 0}},
      {{0b00000000000000000000000000000000, 0b00000000000000000000000000010111,
        0b01001000011101101110100000000000},
       {.flags = 0}},
      {{0b00000000000000000000000000000000, 0b00000000000000000000000011101000,
        0b11010100101001010001000000000000},
       {.flags = 0}},
      {{0b00000000000000000000000000000000, 0b00000000000000000000100100011000,
        0b01001110011100101010000000000000},
       {.flags = 0}},
      {{0b00000000000000000000000000000000, 0b00000000000000000101101011110011,
        0b00010000011110100100000000000000},
       {.flags = 0}},
      {{0b00000000000000000000000000000000, 0b00000000000000111000110101111110,
        0b10100100110001101000000000000000},
       {.flags = 0}},
      {{0b00000000000000000000000000000000, 0b00000000001000111000011011110010,
        0b01101111110000010000000000000000},
       {.flags = 0}},
      {{0b00000000000000000000000000000000, 0b00000001011000110100010101111000,
        0b01011101100010100000000000000000},
       {.flags = 0}},
      {{0b00000000000000000000000000000000, 0b00001101111000001011011010110011,
        0b10100111011001000000000000000000},
       {.flags = 0}},
      {{0b00000000000000000000000000000000, 0b10001010110001110010001100000100,
        0b10001001111010000000000000000000},
       {.flags = 0}},
      {{0b00000000000000000000000000000101, 0b01101011110001110101111000101101,
        0b01100011000100000000000000000000},
       {.flags = 0}},
      {{0b00000000000000000000000000110110, 0b00110101110010011010110111000101,
        0b11011110101000000000000000000000},
       {.flags = 0}},
      {{0b00000000000000000000001000011110, 0b00011001111000001100100110111010,
        0b10110010010000000000000000000000},
       {.flags = 0}},
      {{0b00000000000000000001010100101101, 0b00000010110001111110000101001010,
        0b11110110100000000000000000000000},
       {.flags = 0}},
      {{0b00000000000000001101001111000010, 0b00011011110011101100110011101101,
        0b10100001000000000000000000000000},
       {.flags = 0}},
      {{0b00000000000010000100010110010101, 0b00010110000101000000000101001000,
        0b01001010000000000000000000000000},
       {.flags = 0}},
      {{0b00000000010100101011011111010010, 0b11011100110010000000110011010010,
        0b11100100000000000000000000000000},
       {.flags = 0}},
      {{0b00000011001110110010111000111100, 0b10011111110100001000000000111100,
        0b11101000000000000000000000000000},
       {.flags = 0}},
      {{0b10000001001111110011100101111000, 0b11111000100101000000100110000100,
        0b010000000000000000000000000000},
       {.flags = 0}},
  };
  s21_decimal swap = arr[exp];
  swap.data[0] = arr[exp].data[2];
  swap.data[2] = arr[exp].data[0];
  return swap;
}
