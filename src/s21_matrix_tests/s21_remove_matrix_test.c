#include "../s21_matrix_test.h"

START_TEST(s21_remove_matrix_test_1) {
  matrix_t A = {0};

  int res = OK;
  s21_remove_matrix(&A);
  if (A.matrix != NULL) res = ERROR;

  ck_assert_int_eq(res, OK);
}
END_TEST

START_TEST(s21_remove_matrix_test_2) {
  int rows = 1;
  int columns = 1;
  matrix_t A = {0};

  int res = s21_create_matrix(rows, columns, &A);
  s21_remove_matrix(&A);
  if (A.matrix != NULL) res = ERROR;

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
}
END_TEST

START_TEST(s21_remove_matrix_test_3) {
  int rows = 15;
  int columns = 24;
  matrix_t A = {0};

  int res = s21_create_matrix(rows, columns, &A);
  s21_remove_matrix(&A);
  if (A.matrix != NULL) res = ERROR;

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
}
END_TEST

Suite *s21_remove_matrix_suite(void) {
  TCase *tc_case = tcase_create("remove_matrix");
  Suite *s = suite_create("s21_remove_matrix_test");

  tcase_add_test(tc_case, s21_remove_matrix_test_1);
  tcase_add_test(tc_case, s21_remove_matrix_test_2);
  tcase_add_test(tc_case, s21_remove_matrix_test_3);

  suite_add_tcase(s, tc_case);

  return s;
}