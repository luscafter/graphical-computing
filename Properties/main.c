#include <stdio.h>
#include <locale.h>
#include "lib/matriz.h"
#include "lib/matriz.c"
#include "lib/system.h"

/*

 Instituto Federal de Educação, Ciência e Tecnologia do Ceará - IFCE
 Ciência da Computação - Computação Gráfica, 2020.2
 Professor: Necio de Lima Veras
 Discente: Lucas de Araújo Brito
 https://github.com/luscafter/graphical-computing

*/

int main(void)
{
    srand(time(NULL));

    setlocale(LC_ALL, "Portuguese");

    int matriz_x[3][3], matriz_y[3][3], matriz_z[3][3];

    system(CLEAR);
    printf("\n Propriedades das Matrizes - Computação Gráfica\n");
    printf("\n Soma de Matrizes\n\n [" BLUE "Associativa" RESET "]\n");

    random_value(matriz_x);        // Preenche a "matriz_x"
    random_value(matriz_y);        // Preenche a "matriz_y"
    random_value(matriz_z);        // Preenche a "matriz_z"

    printf("\n Matriz A:\n\n");
    shows_matrix(matriz_x);        // Imprime a "matriz_x"
    printf("\n Matriz B:\n\n");
    shows_matrix(matriz_y);        // Imprime a "matriz_y"
    printf("\n Matriz C:\n\n");
    shows_matrix(matriz_z);        // Imprime a "matriz_z"

    if(associative(matriz_x, matriz_y, matriz_z, true))             // Verifica se a soma das matrizes são associativas
        printf("\n [" GREEN "+" RESET "] Matriz associativa!\n");
    else
        printf("\n [" RED "!" RESET "] Matriz não associativa!\n");
    
    printf("\n [" BLUE "Comutativa" RESET "]\n");

    random_value(matriz_x);        // Preenche a "matriz_x"
    random_value(matriz_y);        // Preenche a "matriz_y"

    printf("\n Matriz A:\n\n");
    shows_matrix(matriz_x);        // Imprime a "matriz_x"
    printf("\n Matriz B:\n\n");
    shows_matrix(matriz_y);        // Imprime a "matriz_y"

    if(commutative(matriz_x, matriz_y, true))                       // Verifica se a matriz é comutativa
        printf("\n [" GREEN "+" RESET "] Matriz comutativa!\n");
    else
        printf("\n [" RED "!" RESET "] Matriz não comutativa!\n");

    printf("\n " BLUE "Neutro" RESET ":\n");

    random_value(matriz_x);        // Preenche a "matriz_x"

    printf("\n Matriz A:\n\n");
    shows_matrix(matriz_x);        // Imprime a "matriz_x" 

    if(neutral(matriz_x))                                           // Verifica se a matriz é neutra
        printf("\n [" GREEN "+" RESET "] Matriz neutra!\n");
    else
        printf("\n [" RED "!" RESET "] Matriz não neutra!\n");
    
    printf("\n [" BLUE "Oposto" RESET "]\n");

    random_value(matriz_x);        // Preenche a "matriz_x"
    random_value(matriz_y);        // Preenche a "matriz_y"

    printf("\n Matriz A:\n\n");
    shows_matrix(matriz_x);        // Imprime a "matriz_x"
    printf("\n Matriz B:\n\n");
    shows_matrix(matriz_y);        // Imprime a "matriz_y"

    if(opposite(matriz_x, matriz_y))                                // Verifica se a matriz é oposta
        printf("\n [" GREEN "+" RESET "] Matriz oposta!\n");
    else
        printf("\n [" RED "!" RESET "] Matriz não oposta!\n");

    printf("\n Multiplicação de Matrizes\n\n [" BLUE "Associativa" RESET "]\n");

    random_value(matriz_x);        // Preenche a "matriz_x"
    random_value(matriz_y);        // Preenche a "matriz_y"
    random_value(matriz_z);        // Preenche a "matriz_z"

    printf("\n Matriz A:\n\n");
    shows_matrix(matriz_x);        // Imprime a "matriz_x"
    printf("\n Matriz B:\n\n");
    shows_matrix(matriz_y);        // Imprime a "matriz_y"
    printf("\n Matriz C:\n\n");
    shows_matrix(matriz_z);        // Imprime a "matriz_z"

    if(associative(matriz_x, matriz_y, matriz_z, false))            // Verifica se a multiplicação das matrizes são associativas
        printf("\n [" GREEN "+" RESET "] Matriz associativa!\n");
    else
        printf("\n [" RED "!" RESET "] Matriz não associativa!\n");

    printf("\n [" BLUE "Comutativa" RESET "]\n");

    random_value(matriz_x);        // Preenche a "matriz_x"
    random_value(matriz_y);        // Preenche a "matriz_y"

    printf("\n Matriz A:\n\n");
    shows_matrix(matriz_x);        // Imprime a "matriz_x"
    printf("\n Matriz B:\n\n");
    shows_matrix(matriz_y);        // Imprime a "matriz_y"

    if(commutative(matriz_x, matriz_y, false))                       // Verifica se a multiplicação das matrizes são comutativas
        printf("\n [" GREEN "+" RESET "] Matriz comutativa!\n");
    else
        printf("\n [" RED "!" RESET "] Matriz não comutativa!\n");

    printf("\n [" BLUE "Distributiva" RESET "]\n");

    random_value(matriz_x);        // Preenche a "matriz_x"
    random_value(matriz_y);        // Preenche a "matriz_y"
    random_value(matriz_z);        // Preenche a "matriz_z"

    printf("\n Matriz A:\n\n");
    shows_matrix(matriz_x);        // Imprime a "matriz_x"
    printf("\n Matriz B:\n\n");
    shows_matrix(matriz_y);        // Imprime a "matriz_y"
    printf("\n Matriz C:\n\n");
    shows_matrix(matriz_z);        // Imprime a "matriz_z"

    if(distributive(matriz_x, matriz_y, matriz_z))                    // Verifica se a soma e a multiplicação das matrizes são distributivas
        printf("\n [" GREEN "+" RESET "] Matriz distributiva!\n\n");
    else
        printf("\n [" RED "!" RESET "] Matriz não distributiva!\n\n");

    return 0;
}
