#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int success = 1;
  if (is_exist(A) || is_exist(B) || A->rows != B->rows ||
      A->columns != B->columns)
    success = 0;
  else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > EPS) {
          success = 0;
        } else
          success = 1;
      }
    }
  }
  return success;
}
