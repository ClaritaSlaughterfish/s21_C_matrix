#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *B) {
  int error = 0;
  if (is_exist(A) || B == NULL)
    error = 1;
  else if (A->rows != A->columns)
    error = 2;  // else if (!is_square(A)) error = 2;
  else {
    double det = 0.0;
    error = s21_determinant(A, &det);
    if (error == 0 && det != 0) {
      matrix_t tmp_comp;
      if (A->rows == 1) {
        error = s21_create_matrix(1, 1, B);
        if (error == 0) {
          B->matrix[0][0] = 1 / (A->matrix[0][0]);
        }
      } else if (s21_calc_complements(A, &tmp_comp) == 0) {
        matrix_t tmp_tran;
        if (s21_transpose(&tmp_comp, &tmp_tran) == 0) {
          if (s21_mult_number(&tmp_tran, (1 / det), B) != 0) {
            error = 2;
          }
          s21_remove_matrix(&tmp_tran);
        } else
          error = 2;
        s21_remove_matrix(&tmp_comp);
      } else
        error = 2;
    } else
      error = 2;
  }
  return error;
}