#include "../s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *Atrp) {
  int error = 0;
  if (is_exist(A) || Atrp == NULL)
    error = 1;
  else {
    if (s21_create_matrix(A->columns, A->rows, Atrp) == 0) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          Atrp->matrix[j][i] = A->matrix[i][j];
        }
      }
    } else
      error = 1;
  }
  return error;
}