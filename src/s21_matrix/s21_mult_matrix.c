#include "../s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *C) {
  int error = 0;
  if (is_exist(A) || is_exist(B) || C == NULL)
    error = 1;
  else if (!(A->rows == B->columns) || !(A->columns == B->rows))
    error = 2;
  else {
    if (s21_create_matrix(A->rows, B->columns, C) == 0) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < B->columns; j++) {
          for (int ptr = 0; ptr < A->columns; ptr++) {
            C->matrix[i][j] += A->matrix[i][ptr] * B->matrix[ptr][j];
          }
          if (!isfinite(C->matrix[i][j])) error = 2;
        }
      }
    } else
      error = 1;
  }
  return error;
}
