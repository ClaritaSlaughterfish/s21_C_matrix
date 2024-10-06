#ifndef S21_S21_MATRIX
#define S21_S21_MATRIX

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

#define SUCCESS 1
#define FAILURE 0

#define OK 0
#define ERROR 1
#define ERROR_CULC 2

#define EPS 1E-7

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);
int is_exist(matrix_t *matrix);
int is_square(matrix_t *matrix);
void minor_aux(matrix_t *A, int row_num, int col_num, matrix_t *result);
int row_col_dupl(matrix_t *A);
int row_col_zero(matrix_t *A);
int row_col_prop(matrix_t *A);
#endif