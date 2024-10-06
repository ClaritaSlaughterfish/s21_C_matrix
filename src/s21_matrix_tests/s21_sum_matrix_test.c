#include "../s21_matrix_test.h"

START_TEST(s21_sum_matrix_test_1) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t C = {0};
  int res = s21_sum_matrix(&A, &B, &C);

  ck_assert_int_eq(res, ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sum_matrix_test_2) {
  int rows = 2;
  int columns = 2;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t C = {0};
  s21_create_matrix(rows, columns, &A);
  int res = s21_sum_matrix(&A, &B, &C);

  ck_assert_int_eq(res, ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sum_matrix_test_3) {
  int rows = 2;
  int columns = 2;
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  int res = s21_sum_matrix(&A, &B, NULL);

  ck_assert_int_eq(res, ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sum_matrix_test_4) {
  int rows = 2;
  int columns = 2;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t C = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows - 1, columns, &B);
  int res = s21_sum_matrix(&A, &B, &C);

  ck_assert_int_eq(res, ERROR_CULC);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sum_matrix_test_5) {
  int rows = 2;
  int columns = 2;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t C = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns + 1, &B);
  int res = s21_sum_matrix(&A, &B, &C);

  ck_assert_int_eq(res, ERROR_CULC);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sum_matrix_test_6) {
  int rows = 2;
  int columns = 2;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t C = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  A.matrix[0][0] = 0.0;
  A.matrix[0][1] = 0.1;
  A.matrix[1][0] = 1.0;
  A.matrix[1][1] = 1.1;

  B.matrix[0][0] = 0.0;
  B.matrix[0][1] = 0.1;
  B.matrix[1][0] = 1.0;
  B.matrix[1][1] = 1.1;

  int res = s21_sum_matrix(&A, &B, &C);

  ck_assert_int_eq(res, OK);
  ck_assert_double_eq(C.matrix[0][0], 0.0);
  ck_assert_double_eq(C.matrix[0][1], 0.2);
  ck_assert_double_eq(C.matrix[1][0], 2.0);
  ck_assert_double_eq(C.matrix[1][1], 2.2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

Suite *s21_sum_matrix_suite(void) {
  TCase *tc_case = tcase_create("sum_matrix");
  Suite *s = suite_create("s21_sum_matrix_test");

  tcase_add_test(tc_case, s21_sum_matrix_test_1);
  tcase_add_test(tc_case, s21_sum_matrix_test_2);
  tcase_add_test(tc_case, s21_sum_matrix_test_3);
  tcase_add_test(tc_case, s21_sum_matrix_test_4);
  tcase_add_test(tc_case, s21_sum_matrix_test_5);
  tcase_add_test(tc_case, s21_sum_matrix_test_6);

  suite_add_tcase(s, tc_case);

  return s;
}