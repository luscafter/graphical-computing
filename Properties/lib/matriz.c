#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

// Fun��o respons�vel por preencher a matriz com valores aleat�rios

void random_value(int matrix[3][3])
{
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            matrix[i][j] = (rand() % 90) + 10;  // Gera um valor aleat�rio entre 10 e 99
        }
    }
}

// Fun��o respons�vel por imprimir a matriz

void shows_matrix(int matrix[3][3])
{
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf(" %d", matrix[i][j]);
        }
        printf("\n");
    }
}

// Fun��o respons�vel por verificar se a matriz � neutra

bool neutral(int matrix[3][3])
{
    int result[3][3];

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            result[i][j] = matrix[i][j] + 0;

            if(result[i][j] != matrix[i][j])  // Verifica se a soma da matriz com zero � diferente da matriz original
                return false;
        }
    }

    return true;
}

// Fun��o respons�vel por verificar se a matriz � oposta

bool opposite(int matrix_x[3][3], int matrix_y[3][3])
{
    int result[3][3];

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            result[i][j] = matrix_x[i][j] + matrix_y[i][j]; // (A + B = 0, ent�o s�o opostas)

            if(result[i][j])                                // Verifica se o resultado � diferente de zero
                return false;
        }
    }

    return true;
}

// Fun��o respons�vel por verificar se a matriz � comutativa

bool commutative(int matrix_x[3][3], int matrix_y[3][3], bool operation)
{
    int result_x[3][3], result_y[3][3];

    if(operation){                                                 // Se a opera��o for "true", ser� feita a soma comutativa
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                result_x[i][j] = matrix_x[i][j] + matrix_y[i][j];  // (A + B)
                result_y[i][j] = matrix_y[i][j] + matrix_x[i][j];  // (B + A)

                if(result_x[i][j] != result_y[i][j])               // Verifica se os resultados s�o diferentes
                    return false;
            }
        }
        return true;
    }

    for(int i = 0; i < 3; i++){                                // � feita a multiplica��o comutativa
        for(int j = 0; j < 3; j++){
            result_x[i][j] = matrix_x[i][j] * matrix_y[i][j];  // (A x B)
            result_y[i][j] = matrix_y[i][j] * matrix_x[i][j];  // (B x A)

            if(result_x[i][j] != result_y[i][j])               // Verifica se os resultados s�o diferentes
                return false;
        }
    }

    return true;
}

// Fun��o respons�vel por verificar se a matriz � associativa

bool associative(int matrix_x[3][3], int matrix_y[3][3], int matrix_z[3][3], bool operation)
{
    int result_x[3][3], result_y[3][3];

    if(operation){                                    // Se a opera��o for "true", ser� feita a soma associativa
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                result_x[i][j] = (matrix_x[i][j] + matrix_y[i][j]) + matrix_z[i][j];  // (A + B) + C
                result_y[i][j] = matrix_x[i][j] + (matrix_y[i][j] + matrix_z[i][j]);  //  A + (B + C)

                if(result_x[i][j] != result_y[i][j])  // Verifica se os resultados s�o diferentes
                    return false;
            }
        }
        return true;
    }

    for(int i = 0; i < 3; i++){                   // � feita a multiplica��o associativa
        for(int j = 0; j < 3; j++){
            result_x[i][j] = (matrix_x[i][j] * matrix_y[i][j]) * matrix_z[i][j];  // (A x B) x C
            result_y[i][j] = matrix_x[i][j] * (matrix_y[i][j] * matrix_z[i][j]);  //  A x (B x C)

            if(result_x[i][j] != result_y[i][j])  // Verifica se os resultados s�o diferentes
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

            if(result_a[i][j] != result_b[i][j])  // Verifica se os resultados s�o diferentes
                return false;

            result_c[i][j] = matrix_x[i][j] * (matrix_y[i][j] + matrix_z[i][j]);                 // A x (B x C)
            result_d[i][j] = matrix_x[i][j] * matrix_y[i][j] + matrix_x[i][j] * matrix_z[i][j];  // AB + AC

            if(result_c[i][j] != result_d[i][j])  // Verifica se os resultados s�o diferentes
                return false;
        }
    }

    return true;
}
