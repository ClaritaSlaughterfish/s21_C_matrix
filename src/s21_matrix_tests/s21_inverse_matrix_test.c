#include "../s21_matrix_test.h"

START_TEST(s21_inverse_matrix_test_1) {
  matrix_t A = {0};
  matrix_t B = {0};
  int res = s21_inverse_matrix(&A, &B);

  ck_assert_int_eq(res, ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_inverse_matrix_test_2) {
  matrix_t A = {0};
  int res = s21_inverse_matrix(&A, NULL);

  ck_assert_int_eq(res, ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_test_3) {
  matrix_t A = {0};
  int rows = 2;
  int columns = 0;
  matrix_t B = {0};

  s21_create_matrix(rows, columns, &A);
  int res = s21_inverse_matrix(&A, &B);

  ck_assert_int_eq(res, ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_inverse_matrix_test_4) {
  matrix_t A = {0};
  int size = 2;
  matrix_t B = {0};

  s21_create_matrix(size, size + 1, &A);
  int res = s21_inverse_matrix(&A, &B);

  ck_assert_int_eq(res, ERROR_CULC);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_inverse_matrix_test_5) {
  matrix_t A = {0};
  int size = 1;
  matrix_t B = {0};

  s21_create_matrix(size, size, &A);
  int res = s21_inverse_matrix(&A, &B);

  ck_assert_int_eq(res, ERROR_CULC);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_inverse_matrix_test_6) {
  matrix_t A = {0};
  int size = 1;
  matrix_t B = {0};

  s21_create_matrix(size, size, &A);

  A.matrix[0][0] = 4;

  int res = s21_inverse_matrix(&A, &B);

  ck_assert_int_eq(res, OK);
  ck_assert_double_eq(B.matrix[0][0], 0.25);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_inverse_matrix_test_7) {
  matrix_t A = {0};
  int size = 2;
  matrix_t B = {0};

  s21_create_matrix(size, size, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 2;

  int res = s21_inverse_matrix(&A, &B);

  ck_assert_int_eq(res, ERROR_CULC);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_test_8) {
  matrix_t A = {0};
  int size = 2;
  matrix_t B = {0};

  s21_create_matrix(size, size, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 3;
  A.matrix[1][0] = 5;
  A.matrix[1][1] = -1;

  int res = s21_inverse_matrix(&A, &B);

  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(B.matrix[0][0], 0.0625, EPS);
  ck_assert_double_eq_tol(B.matrix[0][1], 0.1875, EPS);
  ck_assert_double_eq_tol(B.matrix[1][0], 0.3125, EPS);
  ck_assert_double_eq_tol(B.matrix[1][1], -0.0625, EPS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_inverse_matrix_test_9) {
  matrix_t A = {0};
  int size = 1;
  matrix_t B = {0};
  s21_create_matrix(size, size, &A);
  A.matrix[0][0] = 0;
  int res = s21_inverse_matrix(&A, &B);

  ck_assert_int_eq(res, ERROR_CULC);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_inverse_matrix_test_10) {
  matrix_t A = {0};
  int size = 3;
  matrix_t B = {0};

  s21_create_matrix(size, size, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 2;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 1;
  A.matrix[2][1] = 1;
  A.matrix[2][2] = 2;

  int res = s21_inverse_matrix(&A, &B);

  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(B.matrix[0][0], -0.75, EPS);
  ck_assert_double_eq_tol(B.matrix[0][1], 0.25, EPS);
  ck_assert_double_eq_tol(B.matrix[0][2], 1, EPS);
  ck_assert_double_eq_tol(B.matrix[1][0], 1.25, EPS);
  ck_assert_double_eq_tol(B.matrix[1][1], 0.25, EPS);
  ck_assert_double_eq_tol(B.matrix[1][2], -2, EPS);
  ck_assert_double_eq_tol(B.matrix[2][0], -0.25, EPS);
  ck_assert_double_eq_tol(B.matrix[2][1], -0.25, EPS);
  ck_assert_double_eq_tol(B.matrix[2][2], 1, EPS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *s21_inverse_matrix_suite(void) {
  TCase *tc_case = tcase_create("inverse_matrix");
  Suite *s = suite_create("s21_inverse_matrix_test");

  tcase_add_test(tc_case, s21_inverse_matrix_test_1);
  tcase_add_test(tc_case, s21_inverse_matrix_test_2);
  tcase_add_test(tc_case, s21_inverse_matrix_test_3);
  tcase_add_test(tc_case, s21_inverse_matrix_test_4);
  tcase_add_test(tc_case, s21_inverse_matrix_test_5);
  tcase_add_test(tc_case, s21_inverse_matrix_test_6);
  tcase_add_test(tc_case, s21_inverse_matrix_test_7);
  tcase_add_test(tc_case, s21_inverse_matrix_test_8);
  tcase_add_test(tc_case, s21_inverse_matrix_test_9);
  tcase_add_test(tc_case, s21_inverse_matrix_test_10);

  suite_add_tcase(s, tc_case);

  return s;
}