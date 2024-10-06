#include "../s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *C) {
  int error = 0;
  if (is_exist(A) || is_exist(B) || C == NULL)
    error = 1;
  else if (A->rows != B->rows || A->columns != B->columns)
    error = 2;
  else {
    error = s21_create_matrix(A->rows, A->columns, C);
    if (error == 0) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          C->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
          if (!isfinite(C->matrix[i][j])) error = 2;
        }
      }
    }
  }
  return error;
}