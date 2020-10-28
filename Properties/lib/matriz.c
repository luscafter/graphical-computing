#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

// Função responsável por preencher a matriz com valores aleatórios

void random_value(int matrix[3][3])
{
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            matrix[i][j] = (rand() % 90) + 10;  // Gera um valor aleatório entre 10 e 99
        }
    }
}

// Função responsável por imprimir a matriz

void shows_matrix(int matrix[3][3])
{
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf(" %d", matrix[i][j]);
        }
        printf("\n");
    }
}

// Função responsável por verificar se a matriz é neutra

bool neutral(int matrix[3][3])
{
    int result_x[3][3], result_y[3][3];

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            result_x[i][j] = matrix[i][j] + 0;  // A + 0

            if(result_x[i][j] != matrix[i][j])  // Verifica se os resultados são diferentes
                return false;

            result_y[i][j] = 0 + matrix[i][j];  // 0 + A

            if(result_y[i][j] != matrix[i][j])  // Verifica se os resultados são diferentes
                return false;
        }
    }

    return true;
}

// Função responsável por verificar se a matriz é oposta

bool opposite(int matrix_x[3][3], int matrix_y[3][3])
{
    int result[3][3];

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            result[i][j] = matrix_x[i][j] + matrix_y[i][j]; // (A + B = 0, então são opostas)

            if(result[i][j])                                // Verifica se o resultado é diferente de zero
                return false;
        }
    }

    return true;
}

// Função responsável por verificar se a matriz é comutativa

bool commutative(int matrix_x[3][3], int matrix_y[3][3], bool operation)
{
    int result_x[3][3], result_y[3][3];

    if(operation){                                                 // Se a operação for "true", será feita a soma comutativa
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                result_x[i][j] = matrix_x[i][j] + matrix_y[i][j];  // (A + B)
                result_y[i][j] = matrix_y[i][j] + matrix_x[i][j];  // (B + A)

                if(result_x[i][j] != result_y[i][j])               // Verifica se os resultados são diferentes
                    return false;
            }
        }
        return true;
    }

    for(int i = 0; i < 3; i++){                                // É feita a multiplicação comutativa
        for(int j = 0; j < 3; j++){
            result_x[i][j] = matrix_x[i][j] * matrix_y[i][j];  // (A x B)
            result_y[i][j] = matrix_y[i][j] * matrix_x[i][j];  // (B x A)

            if(result_x[i][j] != result_y[i][j])               // Verifica se os resultados são diferentes
                return false;
        }
    }

    return true;
}

// Função responsável por verificar se a matriz é associativa

bool associative(int matrix_x[3][3], int matrix_y[3][3], int matrix_z[3][3], bool operation)
{
    int result_x[3][3], result_y[3][3];

    if(operation){                                    // Se a operação for "true", será feita a soma associativa
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                result_x[i][j] = (matrix_x[i][j] + matrix_y[i][j]) + matrix_z[i][j];  // (A + B) + C
                result_y[i][j] = matrix_x[i][j] + (matrix_y[i][j] + matrix_z[i][j]);  //  A + (B + C)

                if(result_x[i][j] != result_y[i][j])  // Verifica se os resultados são diferentes
                    return false;
            }
        }
        return true;
    }

    for(int i = 0; i < 3; i++){                   // É feita a multiplicação associativa
        for(int j = 0; j < 3; j++){
            result_x[i][j] = (matrix_x[i][j] * matrix_y[i][j]) * matrix_z[i][j];  // (A x B) x C
            result_y[i][j] = matrix_x[i][j] * (matrix_y[i][j] * matrix_z[i][j]);  //  A x (B x C)

            if(result_x[i][j] != result_y[i][j])  // Verifica se os resultados são diferentes
                return false;
        }
    }

    return true;
}

bool distributive(int matrix_x[3][3], int matrix_y[3][3], int matrix_z[3][3])
{
    int result_a[3][3], result_b[3][3], result_c[3][3], result_d[3][3];

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            result_a[i][j] = (matrix_x[i][j] + matrix_y[i][j]) * matrix_z[i][j];                 // (A + B) x C
            result_b[i][j] = matrix_x[i][j] * matrix_z[i][j] + matrix_y[i][j] * matrix_z[i][j];  // AC + BC

            if(result_a[i][j] != result_b[i][j])  // Verifica se os resultados são diferentes
                return false;

            result_c[i][j] = matrix_x[i][j] * (matrix_y[i][j] + matrix_z[i][j]);                 // A x (B x C)
            result_d[i][j] = matrix_x[i][j] * matrix_y[i][j] + matrix_x[i][j] * matrix_z[i][j];  // AB + AC

            if(result_c[i][j] != result_d[i][j])  // Verifica se os resultados são diferentes
                return false;
        }
    }

    return true;
}
