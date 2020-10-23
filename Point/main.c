#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "lib/ponto.h"
#include "lib/ponto.c"
#include "lib/system.h"

/*

 Instituto Federal de Educação, Ciência e Tecnologia do Ceará - IFCE
 Ciência da Computação - Computação Gráfica, 2020.2
 Professor: Necio de Lima Veras
 Discente: Lucas de Araújo Brito
 https://github.com/luscafter/graphical-computing/point

*/

struct Objeto ponto;

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Portuguese");
	
    system(CLEAR);

    printf("\n Para formar um ponto, é necessário receber dois valores para "
    GREEN "X" RESET " e " GREEN "Y" RESET ".\n\n Informe os valores abaixo:\n\n [" GREEN "x" RESET "] = ");
    scanf("%f", &ponto.x);

    printf(" [" GREEN "y" RESET "] = ");
    scanf("%f", &ponto.y);

    glutInit(&argc, argv);                                        // Inicializa a biblioteca GLUT
    glutInitContextVersion(3, 2);                                 // Ópcional por compatibilidade de APIs                  
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);    // Define o modo de exibição inicial 
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);           // Define o tipo de perfil de acordo com a versão         
    glutInitWindowSize(600, 500);                                 // Define a posição inicial e o tamanho da tela 
    glutCreateWindow("Ponto");                                    // Define o nome da janela e a cria
    glutReshapeFunc(resize);                                      // Define a remodelagem da janela
    glutDisplayFunc(draw_point);                                  // Define o conteúdo de exibição da janela
    glutSetWindowTitle("Ponto 2D");                               // Define o título da janela
    glewInit();                                                   // Inicializa os pontos de entrada da extensão
    glClearColor(0.12, 0.12, 0.12, 1);                            // Define valores para o buffer de cor (background)
    glutMainLoop();                                               // Define o loop de processamento de eventos GLUT

    return 0;
}
