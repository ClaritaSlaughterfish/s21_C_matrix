#include "../s21_matrix_test.h"

START_TEST(s21_mult_matrix_test_1) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t C = {0};

  int res = s21_mult_matrix(&A, &B, &C);

  ck_assert_int_eq(res, ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_mult_matrix_test_2) {
  matrix_t B = {0};
  matrix_t C = {0};

  int res = s21_mult_matrix(NULL, &B, &C);

  ck_assert_int_eq(res, ERROR);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_mult_matrix_test_3) {
  matrix_t A = {0};
  matrix_t C = {0};

  int res = s21_mult_matrix(&A, NULL, &C);

  ck_assert_int_eq(res, ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_mult_matrix_test_4) {
  matrix_t A = {0};
  matrix_t B = {0};

  int res = s21_mult_matrix(&A, &B, NULL);

  ck_assert_int_eq(res, ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_mult_matrix_test_5) {
  int rows = 2;
  int columns = 2;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t C = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 1;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 2;

  B.matrix[0][0] = 1;
  B.matrix[0][1] = 1;
  B.matrix[1][0] = 2;
  B.matrix[1][1] = 2;

  int res = s21_mult_matrix(&A, &B, &C);

  ck_assert_int_eq(res, OK);
  ck_assert_double_eq(C.matrix[0][0], 3.0);
  ck_assert_double_eq(C.matrix[0][1], 3.0);
  ck_assert_double_eq(C.matrix[1][0], 6.0);
  ck_assert_double_eq(C.matrix[1][1], 6.0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_mult_matrix_test_6) {
  int rows = 2;
  int columns = 3;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t C = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows + 4, columns, &B);

  int res = s21_mult_matrix(&A, &B, &C);

  ck_assert_int_eq(res, ERROR_CULC);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_mult_matrix_test_7) {
  int rows = 3;
  int columns = 4;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t C = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(columns, rows, &B);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 3;
  A.matrix[0][2] = 0.1;
  A.matrix[0][3] = 2;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[1][3] = 2;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 0;
  A.matrix[2][3] = 0;

  B.matrix[0][0] = 1;
  B.matrix[0][1] = 0;
  B.matrix[0][2] = 0;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 0;
  B.matrix[1][2] = 0;
  B.matrix[2][0] = 0.1;
  B.matrix[2][1] = 0;
  B.matrix[2][2] = 5;
  B.matrix[3][0] = 2;
  B.matrix[3][1] = 0;
  B.matrix[3][2] = 0;

  int res = s21_mult_matrix(&A, &B, &C);

  ck_assert_int_eq(res, OK);
  ck_assert_double_eq(C.matrix[0][0], 14.01);
  ck_assert_double_eq(C.matrix[0][1], 0);
  ck_assert_double_eq(C.matrix[0][2], 0.5);
  ck_assert_double_eq(C.matrix[1][0], 4);
  ck_assert_double_eq(C.matrix[1][1], 0);
  ck_assert_double_eq(C.matrix[1][2], 0);
  ck_assert_double_eq(C.matrix[2][0], 6);
  ck_assert_double_eq(C.matrix[2][1], 0);
  ck_assert_double_eq(C.matrix[2][2], 0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

Suite *s21_mult_matrix_suite(void) {
  TCase *tc_case = tcase_create("mult_matrixs21_mult_matrix");
  Suite *s = suite_create("s21_mult_matrix_test");

  tcase_add_test(tc_case, s21_mult_matrix_test_1);
  tcase_add_test(tc_case, s21_mult_matrix_test_2);
  tcase_add_test(tc_case, s21_mult_matrix_test_3);
  tcase_add_test(tc_case, s21_mult_matrix_test_4);
  tcase_add_test(tc_case, s21_mult_matrix_test_5);
  tcase_add_test(tc_case, s21_mult_matrix_test_6);
  tcase_add_test(tc_case, s21_mult_matrix_test_7);

  suite_add_tcase(s, tc_case);

  return s;
}