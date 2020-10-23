#include <GL/freeglut.h>
#include "ponto.h"

extern struct Objeto ponto;

// Função responśavel por desenhar o ponto

void draw_point() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);    // Limpa o buffer de cor
    glPushMatrix();                                        // Empilha a matriz atual
    gluLookAt(0, 2.2, -5.2, 0, -0.12, 0, 0, 1, 0);         // Define a posição de visualização
    
    glBegin(GL_POINTS);                                    // Define qual objeto será desenhado (ponto)
    glColor3f(1.0f, 1.0f, 1.0f);                           // Define a cor atual do vértice
    glVertex2f(ponto.x, ponto.y);                          // Define as coordenadas do vértice
    glEnd();                                               // Delimita o vértice, finalizando a função

    glPopMatrix();                                         // Desempilha a pilha
    glutSwapBuffers();                                     // Troca os buffers da janela atual se houver buffer duplo
}

// Função responsável por redimensionar a janela

void resize(int width, int height) {
    glViewport(0, 0, width, height);                        // Define o formato da janela
    glMatrixMode(GL_PROJECTION);                            // Aplica operações de pilha à matriz de projeção
    glLoadIdentity();                                       // Substitui a matriz atual pela matriz identidade para manter o objeto na posição
    gluPerspective(62, (float)(width) / height, 1, 600);    // Define a perspectiva de visualização
    glMatrixMode(GL_MODELVIEW);                             // Aplica operações de pilha à matriz de modeview
    glLoadIdentity();                                       // Substitui a matriz atual pela matriz identidade para manter o objeto na posição
}
