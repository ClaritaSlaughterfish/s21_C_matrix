#include "../s21_matrix.h"

void minor_aux(matrix_t* A, int a, int b, matrix_t* B) {
  int bi = 0;
  for (int i = 0; i < A->rows; i++) {
    if (i != a) {
      int bj = 0;
      for (int j = 0; j < A->columns; j++) {
        if (j != b) {
          B->matrix[bi][bj] = A->matrix[i][j];
          bj++;
        }
      }
      bi++;
    }
  }
}