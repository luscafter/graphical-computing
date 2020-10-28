#include <stdbool.h>

#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED

void random_value(int matrix[3][3]);
void shows_matrix(int matrix[3][3]);

bool neutral(int matrix[3][3]);
bool opposite(int matrix_x[3][3], int matriz_y[3][3]);
bool commutative(int matrix_x[3][3], int matrix_y[3][3], bool operation);
bool associative(int matrix_x[3][3], int matrix_y[3][3], int matrix_z[3][3], bool operation);
bool distributive(int matrix_x[3][3], int matrix_y[3][3], int matrix_z[3][3]);

#endif // MATRIZ_H_INCLUDED
