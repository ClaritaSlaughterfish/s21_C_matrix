#include "../s21_matrix_test.h"

START_TEST(s21_calc_complements_test_1) {
  matrix_t A = {0};
  matrix_t B = {0};
  int res = s21_calc_complements(&A, &B);

  ck_assert_int_eq(res, ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_calc_complements_test_2) {
  matrix_t A = {0};
  int res = s21_calc_complements(&A, NULL);

  ck_assert_int_eq(res, ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_calc_complements_test_3) {
  matrix_t A = {0};
  int rows = 2;
  int columns = 0;
  matrix_t B = {0};

  s21_create_matrix(rows, columns, &A);
  int res = s21_calc_complements(&A, &B);

  ck_assert_int_eq(res, ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_calc_complements_test_4) {
  matrix_t A = {0};
  int size = 2;
  matrix_t B = {0};

  s21_create_matrix(size, size + 1, &A);
  int res = s21_calc_complements(&A, &B);

  ck_assert_int_eq(res, ERROR_CULC);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_calc_complements_test_5) {
  matrix_t A = {0};
  int size = 1;
  matrix_t B = {0};

  s21_create_matrix(size, size, &A);
  int res = s21_calc_complements(&A, &B);

  ck_assert_int_eq(res, ERROR_CULC);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_calc_complements_test_6) {
  matrix_t A = {0};
  int size = 2;
  matrix_t B = {0};

  s21_create_matrix(size, size, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = -5;

  int res = s21_calc_complements(&A, &B);

  ck_assert_int_eq(res, OK);
  ck_assert_double_eq(B.matrix[0][0], -5);
  ck_assert_double_eq(B.matrix[0][1], -4);
  ck_assert_double_eq(B.matrix[1][0], -2);
  ck_assert_double_eq(B.matrix[1][1], 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_calc_complements_test_7) {
  matrix_t A = {0};
  int size = 2;
  s21_create_matrix(size, size, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = -5;

  int res = s21_calc_complements(&A, NULL);

  ck_assert_int_eq(res, ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_calc_complements_test_8) {
  matrix_t A = {};
  matrix_t result = {};
  matrix_t ref_matrix = {};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &ref_matrix);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 0, A.matrix[1][1] = 4, A.matrix[1][2] = 2;
  A.matrix[2][0] = 5, A.matrix[2][1] = 2, A.matrix[2][2] = 1;
  ck_assert_int_eq(s21_calc_complements(&A, &result), OK);
  ref_matrix.matrix[0][0] = 0, ref_matrix.matrix[0][1] = 10,
  ref_matrix.matrix[0][2] = -20;
  ref_matrix.matrix[1][0] = 4, ref_matrix.matrix[1][1] = -14,
  ref_matrix.matrix[1][2] = 8;
  ref_matrix.matrix[2][0] = -8, ref_matrix.matrix[2][1] = -2,
  ref_matrix.matrix[2][2] = 4;
  ck_assert_int_eq(s21_eq_matrix(&result, &ref_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&ref_matrix);
}
END_TEST

Suite *s21_calc_complements_suite(void) {
  TCase *tc_case = tcase_create("calc_complements");
  Suite *s = suite_create("s21_calc_complements_test");

  tcase_add_test(tc_case, s21_calc_complements_test_1);
  tcase_add_test(tc_case, s21_calc_complements_test_2);
  tcase_add_test(tc_case, s21_calc_complements_test_3);
  tcase_add_test(tc_case, s21_calc_complements_test_4);
  tcase_add_test(tc_case, s21_calc_complements_test_5);
  tcase_add_test(tc_case, s21_calc_complements_test_6);
  tcase_add_test(tc_case, s21_calc_complements_test_7);
  tcase_add_test(tc_case, s21_calc_complements_test_8);

  suite_add_tcase(s, tc_case);

  return s;
}