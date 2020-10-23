#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include "lib/cubo.h"
#include "lib/cubo.c"
#include "lib/system.h"

/*

 Instituto Federal de Educação, Ciência e Tecnologia do Ceará - IFCE
 Ciência da Computação - Computação Gráfica, 2020.2
 Professor: Necio de Lima Veras
 Discente: Lucas de Araújo Brito
 https://github.com/luscafter/graphical-computing/polygon

*/

float value;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Portuguese");

	bool invalid;
	
	do {
		system(CLEAR);
		invalid = false;

		printf("\n Para formar um cubo de tamanho perfeito, é necessário receber valores iguais para " GREEN
			   "X" RESET ", " GREEN "Y" RESET " e " GREEN "Z" RESET ".\n\n Informe um valor abaixo:"
			   "\n\n [" GREEN "x" RESET ", " GREEN "y" RESET ", " GREEN "z" RESET "] = ");

    	scanf("%f", &value);

    	if(value < 0.1f || value > 2.5f) {
    		printf("\n [" RED "!" RESET "] Informe um valor (tamanho) entre 0.1 e 2.5\n");
    		invalid = true;
    		delay();
    	}

	} while(invalid);

    glutInit(&argc, argv);                                        // Inicializa a biblioteca GLUT
    glutInitContextVersion(3, 2);                                 // Ópcional por compatibilidade de APIs                  
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);    // Define o modo de exibição inicial 
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);           // Define o tipo de perfil de acordo com a versão         
    glutInitWindowSize(600, 500);                                 // Define a posição inicial e o tamanho da tela 
    glutCreateWindow("Cubo");                                     // Define o nome da janela e a cria
    glutReshapeFunc(resize);                                      // Define a remodelagem da janela
    glutDisplayFunc(draw_scene);                                  // Define o conteúdo de exibição da janela
    glutIdleFunc(update_rotation);                                // Define o tipo de animação contínua (rotação)
    glutTimerFunc(0, update_title, 500);                          // Define um delay que a função deve esperar antes de executar
    glewInit();                                                   // Inicializa os pontos de entrada da extensão
    glClearColor(0.12, 0.12, 0.12, 1);                            // Define valores para o buffer de cor (background)
    glEnable(GL_DEPTH_TEST);                                      // Faz comparações de de profundidade e atualiza o buffer
    glutMainLoop();                                               // Define o loop de processamento de eventos GLUT

    return 0;
}
