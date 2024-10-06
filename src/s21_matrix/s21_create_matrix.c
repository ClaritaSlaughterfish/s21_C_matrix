#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *A) {
  int error = 0;
  if (rows <= 0 || columns <= 0 || A == NULL)
    error = 1;
  else {
    A->rows = rows;
    A->matrix = (double **)calloc(rows, sizeof(double *));
    if (A->matrix != NULL) {
      A->columns = columns;
      for (int i = 0; i < A->rows; i++) {
        A->matrix[i] = (double *)calloc(A->columns, sizeof(double));
      }
    } else
      error = 1;
  }
  return error;
}