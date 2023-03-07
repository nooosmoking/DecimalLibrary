#ifndef S21_BINARY_H_
#define S21_BINARY_H_

#include "../s21_struct.h"

#define DEC_NULL              \
  {                           \
    {0, 0, 0}, { .flags = 0 } \
  }

#define DECIMAL_ONE  \
  (s21_decimal) {    \
    {1, 0, 0}, {     \
      { 0, 0, 0, 0 } \
    }                \
  }

#define DEC_INIT(x) s21_decimal x = DEC_NULL
#define IS_SET(X, POS) ((X >> POS) & 1U)
#define ADD_BIT(X, POS) ((X) |= (1U << (POS)))
#define SET_BIT(X, BIT, POS) (X |= (BIT << POS))
#define INIT_ZERO(X) (X &= (0U << 32))
#define ZERO_BIT(X, POS) (X &= ~(1UL << POS));

#define MAX_DECIMAL 79228162514264337593543950335.0F
#define MIN_DECIMAL -79228162514264337593543950335.0F

// logic
s21_decimal bit_xor(s21_decimal a, s21_decimal b);
s21_decimal bit_or(s21_decimal a, s21_decimal b);
s21_decimal bit_and(s21_decimal a, s21_decimal b);
s21_decimal bit_not(s21_decimal a);

// Helpers
void zerro_data(s21_decimal *val);
void clean_value(s21_decimal *val);
short compare_position(s21_decimal a, s21_decimal b);
s21_decimal s21_pow10(int exp);
int dec_normalize(s21_decimal *v1, s21_decimal *v2);
int binary_round(s21_decimal *val);

// eq
short compare(s21_decimal a, s21_decimal b);
int eq_zero(s21_decimal value);
int eq_max(s21_decimal value);
int eq_val(s21_decimal value1, s21_decimal value2);

// Smart bit setters
void set_bit(s21_decimal *n, int pos, int bit);
void set_bit_1(s21_decimal *n, int pos);
void set_bit_0(s21_decimal *n, int pos);
int get_bit(s21_decimal n, int pos);

// shift
int shiftl(s21_decimal *a);
void shiftr(s21_decimal *a);

// arifm
s21_decimal binary_addition(s21_decimal value_1, s21_decimal value_2, int *err);
s21_decimal binary_subtraction(s21_decimal value_1, s21_decimal value_2,
                               int *err);
s21_decimal binary_multiplication(s21_decimal value_1, s21_decimal value_2,
                                  int *err);
s21_decimal binary_division(s21_decimal value_1, s21_decimal value_2, int *err,
                            s21_decimal *mod);

#endif
