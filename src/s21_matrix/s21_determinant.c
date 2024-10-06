#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int error = 0;
  if (is_exist(A) || result == NULL)
    error = 1;
  else if (A->rows != A->columns)
    error = 2;  // else if (!is_square(A)) error = 2;
  else {
    if (A->rows == 1)
      *result = A->matrix[0][0];
    else if (A->rows == 2) {
      *result =
          A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
    } else {
      *result = 0.0;
      if (row_col_dupl(A) || row_col_zero(A) || row_col_prop(A)) {
        *result = 0.0;
      } else {
        matrix_t minor;
        error = s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
        if (error == 0) {
          for (int i = 0; i < A->rows; i++) {
            minor_aux(A, 0, i, &minor);
            double minor_det = 0.0;
            if (s21_determinant(&minor, &minor_det) == 0) {
              int sign = i % 2 == 0 ? 1 : -1;
              *result += sign * A->matrix[0][i] * minor_det;
            } else {
              error = 2;
              break;
            }
          }
        }
        s21_remove_matrix(&minor);
      }
    }
  }
  return error;
}