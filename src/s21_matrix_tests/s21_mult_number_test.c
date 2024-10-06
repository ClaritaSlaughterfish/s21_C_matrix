#include "../s21_matrix_test.h"

START_TEST(s21_mult_number_test_1) {
  matrix_t A = {0};
  double number = 2.0;
  matrix_t B = {0};
  int res = s21_mult_number(&A, number, &B);

  ck_assert_int_eq(res, ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_mult_number_test_2) {
  matrix_t A = {0};
  double number = 2.0;
  int res = s21_mult_number(&A, number, NULL);

  ck_assert_int_eq(res, ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_mult_number_test_3) {
  matrix_t A = {0};
  int rows = 2;
  int columns = 0;
  double number = 2.0;
  matrix_t B = {0};

  s21_create_matrix(rows, columns, &A);
  int res = s21_mult_number(&A, number, &B);

  ck_assert_int_eq(res, ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_mult_number_test_4) {
  matrix_t A = {0};
  int rows = 2;
  int columns = 2;
  double number = 2.0;
  matrix_t B = {0};

  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 0.0;
  A.matrix[0][1] = 0.1;
  A.matrix[1][0] = 1.0;
  A.matrix[1][1] = 1.1;

  int res = s21_mult_number(&A, number, &B);

  ck_assert_int_eq(res, OK);
  ck_assert_double_eq(B.matrix[0][0], 0.0);
  ck_assert_double_eq(B.matrix[0][1], 0.2);
  ck_assert_double_eq(B.matrix[1][0], 2.0);
  ck_assert_double_eq(B.matrix[1][1], 2.2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_mult_number_test_5) {
  matrix_t A = {0};
  double number = 2.0;
  int res = s21_mult_number(&A, number, NULL);

  ck_assert_int_eq(res, ERROR);
  s21_remove_matrix(&A);
}
END_TEST

Suite *s21_mult_number_suite(void) {
  TCase *tc_case = tcase_create("mult_number");
  Suite *s = suite_create("s21_mult_number_test");

  tcase_add_test(tc_case, s21_mult_number_test_1);
  tcase_add_test(tc_case, s21_mult_number_test_2);
  tcase_add_test(tc_case, s21_mult_number_test_3);
  tcase_add_test(tc_case, s21_mult_number_test_4);
  tcase_add_test(tc_case, s21_mult_number_test_5);

  suite_add_tcase(s, tc_case);

  return s;
}