#include "test.h"

START_TEST(helper_shift_pos) {
  DEC_INIT(decimal);
  decimal.data[0] = 100;

  shiftl_10(&decimal);
  ck_assert_int_eq(decimal.data[0], 100);

  int err = shiftr_10(&decimal);
  ck_assert_int_eq(err, ARITHMETIC_OK);
  ck_assert_int_eq(decimal.data[0], 10);
  decimal.head.exp = 28;

  shiftl_10(&decimal);
  ck_assert_int_eq(decimal.data[0], 100);
}
END_TEST

Suite* suite_helper_shift10(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("\n === SHIFT TEN TEST ===");
  tc_core = tcase_create("tc");

  tcase_add_test(tc_core, helper_shift_pos);

  suite_add_tcase(s, tc_core);

  return s;
}