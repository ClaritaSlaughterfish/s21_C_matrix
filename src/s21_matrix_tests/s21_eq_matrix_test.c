#include "../s21_matrix_test.h"

START_TEST(s21_eq_matrix_test_1) {
  int rows = 3;
  int columns = 3;
  matrix_t A = {0};
  matrix_t B = {0};

  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows - 1, columns - 1, &B);

  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_2) {
  matrix_t A = {0};
  matrix_t B = {0};
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(FAILURE, result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_3) {
  int rows = 3;
  int columns = 3;
  matrix_t A = {0};

  s21_create_matrix(rows, columns, &A);

  int res = s21_eq_matrix(&A, NULL);
  ck_assert_int_eq(res, FAILURE);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_eq_matrix_test_4) {
  int rows = 3;
  int columns = 3;
  matrix_t A = {0};

  s21_create_matrix(rows, columns, &A);

  int res = s21_eq_matrix(NULL, &A);
  ck_assert_int_eq(res, FAILURE);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_eq_matrix_test_5) {
  int rows = 3;
  int columns = 3;
  matrix_t A = {0};

  s21_create_matrix(rows, columns, &A);
  A.rows = -1;

  int res = s21_eq_matrix(&A, &A);
  ck_assert_int_eq(res, FAILURE);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_eq_matrix_test_6) {
  int rows = 3;
  int columns = 3;
  matrix_t A = {0};

  s21_create_matrix(rows, columns, &A);

  int res = s21_eq_matrix(&A, &A);
  ck_assert_int_eq(res, SUCCESS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_eq_matrix_test_7) {
  int rows = 1;
  int columns = 1;
  matrix_t A = {0};
  matrix_t B = {0};

  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  A.matrix[0][0] = 12.0;
  B.matrix[0][0] = 12.00000009;

  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_8) {
  int rows = 1;
  int columns = 1;
  matrix_t A = {0};
  matrix_t B = {0};

  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  A.matrix[0][0] = 12.0;
  B.matrix[0][0] = -55.2;

  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_9) {
  int rows = 3;
  int columns = 3;
  matrix_t A = {0};

  s21_create_matrix(rows, columns, &A);
  A.columns = -1;

  int res = s21_eq_matrix(&A, &A);
  ck_assert_int_eq(res, FAILURE);
  s21_remove_matrix(&A);
}
END_TEST

Suite *s21_eq_matrix_suite(void) {
  TCase *tc_case = tcase_create("eq_matrix");
  Suite *s = suite_create("s21_eq_matrix_test");

  tcase_add_test(tc_case, s21_eq_matrix_test_1);
  tcase_add_test(tc_case, s21_eq_matrix_test_2);
  tcase_add_test(tc_case, s21_eq_matrix_test_3);
  tcase_add_test(tc_case, s21_eq_matrix_test_4);
  tcase_add_test(tc_case, s21_eq_matrix_test_5);
  tcase_add_test(tc_case, s21_eq_matrix_test_6);
  tcase_add_test(tc_case, s21_eq_matrix_test_7);
  tcase_add_test(tc_case, s21_eq_matrix_test_8);
  tcase_add_test(tc_case, s21_eq_matrix_test_9);

  suite_add_tcase(s, tc_case);

  return s;
}
