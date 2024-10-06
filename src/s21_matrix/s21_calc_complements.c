#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *B) {
  int error = 0;
  if (is_exist(A) || B == NULL)
    error = 1;
  else if (!is_square(A))
    error = 2;
  else if (A->columns == 1)
    error = 2;
  else {
    error = s21_create_matrix(A->rows, A->columns, B);
    if (error == 0) {
      matrix_t minor;
      if (s21_create_matrix(A->rows - 1, A->columns - 1, &minor) == 0) {
        for (int i = 0; i < A->rows && error == 0; i++) {
          for (int j = 0; j < A->rows && error == 0; j++) {
            minor_aux(A, i, j, &minor);
            double tmp_det = 0.0;
            int sign = ((i + j) % 2) == 0 ? 1 : -1;
            if (s21_determinant(&minor, &tmp_det) != 0)
              error = 2;
            else
              B->matrix[i][j] = tmp_det * sign;
          }
        }
        s21_remove_matrix(&minor);
        if (error != 0) s21_remove_matrix(B);
      } else
        error = 1;
    }
  }
  return error;
}