#include "../s21_matrix_test.h"

START_TEST(s21_create_matrix_test_1) {
  int rows = 1;
  int columns = 1;
  matrix_t A = {0};

  int res = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(A.rows, rows);
  ck_assert_int_eq(A.columns, columns);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_test_2) {
  int rows = -5;
  int columns = 1;
  matrix_t A = {0};

  int res = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(res, ERROR);
  s21_remove_matrix(&A);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
  ck_assert_int_eq(A.matrix == NULL, 1);
}
END_TEST

START_TEST(s21_create_matrix_test_3) {
  int rows = 1;
  int columns = -1;
  matrix_t A = {0};

  int res = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(res, ERROR);
  s21_remove_matrix(&A);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
  ck_assert_int_eq(A.matrix == NULL, 1);
}
END_TEST

START_TEST(s21_create_matrix_test_4) {
  int rows = 0;
  int columns = 1;
  matrix_t A = {0};

  int res = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(res, ERROR);
  s21_remove_matrix(&A);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
  ck_assert_int_eq(A.matrix == NULL, 1);
}
END_TEST

START_TEST(s21_create_matrix_test_5) {
  int rows = 1;
  int columns = 0;
  matrix_t A = {0};

  int res = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(res, ERROR);
  s21_remove_matrix(&A);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
  ck_assert_int_eq(A.matrix == NULL, 1);
}
END_TEST

START_TEST(s21_create_matrix_test_6) {
  int rows = 5;
  int columns = 3;
  matrix_t A = {0};

  int res = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(A.rows, rows);
  ck_assert_int_eq(A.columns, columns);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_test_7) {
  int rows = 2;
  int columns = 4;

  int res = s21_create_matrix(rows, columns, NULL);
  ck_assert_int_eq(res, ERROR);
}
END_TEST

START_TEST(s21_create_matrix_test_8) {
  int rows = 5;
  int columns = 4;
  matrix_t A = {0};

  int res = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(A.rows, rows);
  ck_assert_int_eq(A.columns, columns);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_test_9) {
  int rows = 7;
  int columns = 20;
  matrix_t A = {0};

  int res = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(A.rows, rows);
  ck_assert_int_eq(A.columns, columns);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_test_10) {
  int rows = 80;
  int columns = 61;
  matrix_t A = {0};

  int res = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(A.rows, rows);
  ck_assert_int_eq(A.columns, columns);
  s21_remove_matrix(&A);
}
END_TEST

Suite *s21_create_matrix_suite(void) {
  TCase *tc_case = tcase_create("create_matrix");
  Suite *s = suite_create("s21_create_matrix_test");

  tcase_add_test(tc_case, s21_create_matrix_test_1);
  tcase_add_test(tc_case, s21_create_matrix_test_2);
  tcase_add_test(tc_case, s21_create_matrix_test_3);
  tcase_add_test(tc_case, s21_create_matrix_test_4);
  tcase_add_test(tc_case, s21_create_matrix_test_5);
  tcase_add_test(tc_case, s21_create_matrix_test_6);
  tcase_add_test(tc_case, s21_create_matrix_test_7);
  tcase_add_test(tc_case, s21_create_matrix_test_8);
  tcase_add_test(tc_case, s21_create_matrix_test_9);
  tcase_add_test(tc_case, s21_create_matrix_test_10);

  suite_add_tcase(s, tc_case);

  return s;
}
