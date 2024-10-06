#include "../s21_matrix_test.h"

START_TEST(s21_determinant_test_1) {
  matrix_t A = {0};
  double determinant = 0;
  int res = s21_determinant(&A, &determinant);

  ck_assert_int_eq(res, ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_test_2) {
  matrix_t A = {0};
  int res = s21_determinant(&A, NULL);

  ck_assert_int_eq(res, ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_test_3) {
  matrix_t A = {0};
  int rows = 2;
  int columns = 0;
  double determinant = 0;

  s21_create_matrix(rows, columns, &A);
  int res = s21_determinant(&A, &determinant);

  ck_assert_int_eq(res, ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_test_4) {
  matrix_t A = {0};
  int size = 2;
  double determinant = 0;

  s21_create_matrix(size, size + 1, &A);
  int res = s21_determinant(&A, &determinant);

  ck_assert_int_eq(res, ERROR_CULC);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_test_5) {
  matrix_t A = {0};
  int rows = 2;

  s21_create_matrix(rows, rows, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = -5;

  int res = s21_determinant(&A, NULL);

  ck_assert_int_eq(res, ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_test_6) {
  matrix_t A = {0};
  int rows = 1;
  double determinant = 0;

  s21_create_matrix(rows, rows, &A);
  A.matrix[0][0] = -7;

  int res = s21_determinant(&A, &determinant);

  ck_assert_int_eq(res, OK);
  ck_assert_double_eq(determinant, -7);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_test_7) {
  matrix_t A = {0};
  int rows = 2;
  double determinant = 0;

  s21_create_matrix(rows, rows, &A);
  A.matrix[0][0] = 7;
  A.matrix[0][1] = 0.5;
  A.matrix[1][0] = 12;
  A.matrix[1][1] = 1.2;

  int res = s21_determinant(&A, &determinant);

  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(determinant, 2.4, EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_test_8) {
  matrix_t A = {0};
  int rows = 3;
  double determinant = 0;

  s21_create_matrix(rows, rows, &A);
  A.matrix[0][0] = 7;
  A.matrix[0][1] = 0.5;
  A.matrix[0][2] = 1;
  A.matrix[1][0] = 12;
  A.matrix[1][1] = 1.2;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 1;
  A.matrix[2][1] = 1;
  A.matrix[2][2] = -1;

  int res = s21_determinant(&A, &determinant);

  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(determinant, 1.9, EPS);
  s21_remove_matrix(&A);
}
END_TEST

Suite *s21_determinant_suite(void) {
  TCase *tc_case = tcase_create("determinant");
  Suite *s = suite_create("s21_determinant_test");

  tcase_add_test(tc_case, s21_determinant_test_1);
  tcase_add_test(tc_case, s21_determinant_test_2);
  tcase_add_test(tc_case, s21_determinant_test_3);
  tcase_add_test(tc_case, s21_determinant_test_4);
  tcase_add_test(tc_case, s21_determinant_test_5);
  tcase_add_test(tc_case, s21_determinant_test_6);
  tcase_add_test(tc_case, s21_determinant_test_7);
  tcase_add_test(tc_case, s21_determinant_test_8);

  suite_add_tcase(s, tc_case);

  return s;
}