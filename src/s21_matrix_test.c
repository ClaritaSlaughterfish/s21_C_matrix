#include "s21_matrix_test.h"

int main(void) {
  SRunner *runner;

  runner = srunner_create(s21_create_matrix_suite());
  srunner_add_suite(runner, s21_remove_matrix_suite());
  srunner_add_suite(runner, s21_eq_matrix_suite());
  srunner_add_suite(runner, s21_sum_matrix_suite());
  srunner_add_suite(runner, s21_sub_matrix_suite());
  srunner_add_suite(runner, s21_mult_number_suite());
  srunner_add_suite(runner, s21_mult_matrix_suite());
  srunner_add_suite(runner, s21_transpose_suite());
  srunner_add_suite(runner, s21_calc_complements_suite());
  srunner_add_suite(runner, s21_determinant_suite());
  srunner_add_suite(runner, s21_inverse_matrix_suite());

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}