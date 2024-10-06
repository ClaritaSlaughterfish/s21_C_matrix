#include "../s21_matrix.h"

int row_col_dupl(matrix_t *A) {
  int dupl_exist = 0;
  if (!is_exist(A) && A->rows >= 2 && A->columns >= 2) {
    for (int i = 0; i < A->rows - 1; i++) {
      for (int j = i + 1; j < A->rows; j++) {
        int equal = 1;
        for (int k = 0; k < A->columns; k++) {
          if (A->matrix[i][k] != A->matrix[j][k]) {
            equal = 0;
            break;
          }
        }
        if (equal) {
          dupl_exist = 1;
          break;
        }
      }
      if (dupl_exist) break;
    }
    if (!dupl_exist) {
      for (int i = 0; i < A->columns - 1; i++) {
        for (int j = i + 1; j < A->columns; j++) {
          int equal = 1;
          for (int k = 0; k < A->rows; k++) {
            if (A->matrix[k][i] != A->matrix[k][j]) {
              equal = 0;
              break;
            }
          }
          if (equal) {
            return 1;
          }
        }
        if (dupl_exist) break;
      }
    }
  }
  return dupl_exist;
}

int row_col_zero(matrix_t *A) {
  int zero_exist = 0;
  if (!is_exist(A) && A->rows >= 1 && A->columns >= 1) {
    for (int i = 0; i < A->rows; i++) {
      int all_zero = 1;
      for (int j = 0; j < A->columns; j++) {
        if (A->matrix[i][j] != 0.0) {
          all_zero = 0;
          break;
        }
      }
      if (all_zero) {
        zero_exist = 1;
        break;
      }
    }
    if (!zero_exist) {
      for (int j = 0; j < A->columns; j++) {
        int all_zero = 1;
        for (int i = 0; i < A->rows; i++) {
          if (A->matrix[i][j] != 0.0) {
            all_zero = 0;
            break;
          }
        }
        if (all_zero) {
          zero_exist = 1;
          break;
        }
      }
    }
  }
  return zero_exist;
}

int row_col_prop(matrix_t *A) {
  int props_exist = 0;
  if (!is_exist(A) && A->rows >= 2 && A->columns >= 2) {
    for (int i = 0; i < A->rows - 1; i++) {
      for (int j = i + 1; j < A->rows; j++) {
        int proportional = 1;
        double ratio = A->matrix[i][0] / A->matrix[j][0];
        for (int k = 1; k < A->columns; k++) {
          if (A->matrix[i][k] / A->matrix[j][k] != ratio) {
            proportional = 0;
            break;
          }
        }
        if (proportional) {
          props_exist = 1;
          break;
        }
      }
      if (props_exist) break;
    }
    if (!props_exist) {
      for (int i = 0; i < A->columns - 1; i++) {
        for (int j = i + 1; j < A->columns; j++) {
          int proportional = 1;
          double ratio = A->matrix[0][i] / A->matrix[0][j];
          for (int k = 1; k < A->rows; k++) {
            if (A->matrix[k][i] / A->matrix[k][j] != ratio) {
              proportional = 0;
              break;
            }
          }
          if (proportional) {
            props_exist = 1;
            break;
          }
        }
        if (props_exist) break;
      }
    }
  }
  return props_exist;
}