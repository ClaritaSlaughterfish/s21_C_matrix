#include "../s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *B) {
  int error = 0;
  if (!is_exist(A) && B != NULL) {
    if (s21_create_matrix(A->rows, A->columns, B) == 0) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          B->matrix[i][j] = A->matrix[i][j] * number;
          if (!isfinite(B->matrix[i][j])) error = 2;
        }
      }
    } else
      error = 1;
  } else
    error = 1;
  return error;
}