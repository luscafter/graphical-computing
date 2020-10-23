#include <GL/glew.h>
#include <GL/freeglut.h>
#include <string.h>
#include "cubo.h"

float fps = 0;                   // Frames por segundo
char title[22];                  // Título da janela
int previous_frame;              // Frame anterior
int current_picture = 0;         // Quadro atual

extern float value;              // Variável externa com o valor do tamanho do cubo

// extern struct Objeto vertex, normal, colors;

GLdouble rotation = 0;           // Rotação do cubo

const float velocity = 0.014f;   // Velocidade da rotação

// Vetores responsáveis por armazenar os vértices do cubo (tamanho)

GLfloat vertex_x[] = { 1, -1, -1, -1,  1,  1,    // frente
                       1,  1,  1,  1,  1,  1,    // direita
                       1,  1, -1, -1, -1,  1,    // cima
                      -1, -1, -1, -1, -1, -1,    // esquerda
                      -1,  1,  1,  1, -1, -1,    // baixo
                       1, -1, -1, -1,  1,  1 };  // trás

GLfloat vertex_y[] = { 1,  1, -1, -1, -1,  1,    // frente
                       1, -1, -1, -1,  1,  1,    // direita
                       1,  1,  1,  1,  1,  1,    // cima
                       1,  1, -1, -1, -1,  1,    // esquerda
                      -1, -1, -1, -1, -1, -1,    // baixo
                      -1, -1,  1,  1,  1, -1 };  // trás

GLfloat vertex_z[] = { 1,  1,  1,  1,  1,  1,    // frente
                       1,  1, -1, -1, -1,  1,    // direita
                       1, -1, -1, -1,  1,  1,    // cima
                       1, -1, -1, -1,  1,  1,    // esquerda
                      -1, -1,  1,  1,  1, -1,    // baixo
                      -1, -1, -1, -1, -1, -1 };  // trás

/*

vertex.x[] = { 1, -1, -1, -1,  1,  1,    // frente
               1,  1,  1,  1,  1,  1,    // direita
               1,  1, -1, -1, -1,  1,    // cima
              -1, -1, -1, -1, -1, -1,    // esquerda
              -1,  1,  1,  1, -1, -1,    // baixo
               1, -1, -1, -1,  1,  1 };  // trás

vertex.y[] = { 1,  1, -1, -1, -1,  1,    // frente
               1, -1, -1, -1,  1,  1,    // direita
               1,  1,  1,  1,  1,  1,    // cima
               1,  1, -1, -1, -1,  1,    // esquerda
              -1, -1, -1, -1, -1, -1,    // baixo
              -1, -1,  1,  1,  1, -1 };  // trás

vertex.z[] = { 1,  1,  1,  1,  1,  1,    // frente
               1,  1, -1, -1, -1,  1,    // direita
               1, -1, -1, -1,  1,  1,    // cima
               1, -1, -1, -1,  1,  1,    // esquerda
              -1, -1,  1,  1,  1, -1,    // baixo
              -1, -1, -1, -1, -1, -1 };  // trás

*/

/* Vetores responsáveis por armazenar o "vetor normal" para calcular as cores,
   determinando se a superfície do cubo está sombreada ou contém um realce especular */

GLfloat normal_x[] = { 0,  0,  0,  0,  0,  0,    // frente
                       1,  1,  1,  1,  1,  1,    // direita
                       0,  0,  0,  0,  0,  0,    // cima
                      -1, -1, -1, -1, -1, -1,    // esquerda
                       0,  0,  0,  0,  0,  0,    // baixo
                       0,  0,  0,  0,  0,  0 };  // trás

GLfloat normal_y[] = { 0,  0,  0,  0,  0,  0,    // frente
                       0,  0,  0,  0,  0,  0,    // direita
                       1,  1,  1,  1,  1,  1,    // cima
                       0,  0,  0,  0,  0,  0,    // esquerda
                      -1, -1, -1, -1, -1, -1,    // baixo
                       0,  0,  0,  0,  0,  0 };  // trás

GLfloat normal_z[] = { 1,  1,  1,  1,  1,  1,    // frente
                       0,  0,  0,  0,  0,  0,    // direita
                       0,  0,  0,  0,  0,  0,    // cima
                       0,  0,  0,  0,  0,  0,    // esquerda
                       0,  0,  0,  0,  0,  0,    // baixo
                      -1, -1, -1, -1, -1, -1 };  // trás

/*

normal.x[] = { 0,  0,  0,  0,  0,  0,    // frente
               1,  1,  1,  1,  1,  1,    // direita
               0,  0,  0,  0,  0,  0,    // cima
              -1, -1, -1, -1, -1, -1,    // esquerda
               0,  0,  0,  0,  0,  0,    // baixo
               0,  0,  0,  0,  0,  0 };  // trás

normal.y[] = { 0,  0,  0,  0,  0,  0,    // frente
               0,  0,  0,  0,  0,  0,    // direita
               1,  1,  1,  1,  1,  1,    // cima
               0,  0,  0,  0,  0,  0,    // esquerda
              -1, -1, -1, -1, -1, -1,    // baixo
               0,  0,  0,  0,  0,  0 };  // trás

normal.z[] = { 1,  1,  1,  1,  1,  1,    // frente
               0,  0,  0,  0,  0,  0,    // direita
               0,  0,  0,  0,  0,  0,    // cima
               0,  0,  0,  0,  0,  0,    // esquerda
               0,  0,  0,  0,  0,  0,    // baixo
              -1, -1, -1, -1, -1, -1 };  // trás

*/

// Vetor responsável por armazenar as cores de cada vértice

GLfloat colors_x[] = { 1, 1, 1, 1, 1, 1,    // frente
                       1, 1, 0, 0, 0, 1,    // direita
                       1, 0, 0, 0, 1, 1,    // cima
                       1, 0, 0, 0, 1, 1,    // esquerda
                       0, 0, 1, 1, 1, 0,    // baixo
                       0, 0, 0, 0, 0, 0 };  // trás

GLfloat colors_y[] = { 1, 1, 0, 0, 0, 1,    // frente
                       1, 0, 0, 0, 1, 1,    // direita
                       1, 1, 1, 1, 1, 1,    // cima
                       1, 1, 0, 0, 0, 1,    // esquerda
                       0, 0, 0, 0, 0, 0,    // baixo
                       0, 0, 1, 1, 1, 0 };  // trás

GLfloat colors_z[] = { 1, 0, 0, 0, 1, 1,    // frente
                       1, 1, 1, 1, 1, 1,    // direita
                       1, 1, 0, 0, 0, 1,    // cima
                       0, 0, 0, 0, 0, 0,    // esquerda
                       0, 1, 1, 1, 0, 0,    // baixo
                       1, 0, 0, 0, 1, 1 };  // trás

/*

colors.x[] = { 1, 1, 1, 1, 1, 1,    // frente
               1, 1, 0, 0, 0, 1,    // direita
               1, 0, 0, 0, 1, 1,    // cima
               1, 0, 0, 0, 1, 1,    // esquerda
               0, 0, 1, 1, 1, 0,    // baixo
               0, 0, 0, 0, 0, 0 };  // trás

colors.y[] = { 1, 1, 0, 0, 0, 1,    // frente
               1, 0, 0, 0, 1, 1,    // direita
               1, 1, 1, 1, 1, 1,    // cima
               1, 1, 0, 0, 0, 1,    // esquerda
               0, 0, 0, 0, 0, 0,    // baixo
               0, 0, 1, 1, 1, 0 };  // trás

colors.z[] = { 1, 0, 0, 0, 1, 1,    // frente
               1, 1, 1, 1, 1, 1,    // direita
               1, 1, 0, 0, 0, 1,    // cima
               0, 0, 0, 0, 0, 0,    // esquerda
               0, 1, 1, 1, 0, 0,    // baixo
               1, 0, 0, 0, 1, 1 };  // trás

*/

// Função responśavel por moldar o cubo

void draw_cube() {

    glBegin(GL_TRIANGLES);    // Define qual objeto será desenhado (triângulo)

    // Altera o tamanho dos vértices de acordo com o valor escolhido

    if(value != 1) {
        for(int i = 0; i < 36; i++) {
            if(vertex_x[i] > 0)
                vertex_x[i] = value;
            else
                vertex_x[i] = -value;

            if(vertex_y[i] > 0)
                vertex_y[i] = value;
            else
                vertex_y[i] = -value;

            if(vertex_z[i] > 0)
                vertex_z[i] = value;
            else
                vertex_z[i] = -value;
        }
    }

    /*

    if(value != 1) {
        for(int i = 0; i < 36; i++) {
            if(vertex.x[i] > 0)
                vertex.x[i] = value;
            else
                vertex.x[i] = -value;

            if(vertex.y[i] > 0)
                vertex.y[i] = value;
            else
                vertex.y[i] = -value;

            if(vertex.z[i] > 0)
                vertex.z[i] = value;
            else
                vertex.z[i] = -value;
        }
    }

    */

    // O cubo possui 36 vértices, cada vértice possui "x, y, z". Portanto, (36 x 3) = 108 vértices ao total.

    for(int i = 0; i < 36; i++) {

        glNormal3f(normal_x[i], normal_y[i], normal_z[i]);   // Define as coordenadas do "vetor normal"
        glColor3f(colors_x[i], colors_y[i], colors_z[i]);    // Define a cor atual de cada vértice
        glVertex3f(vertex_x[i], vertex_y[i], vertex_z[i]);   // Define as coordenadas dos vértices

        /*

        glNormal3f(normal.x[i], normal.y[i], normal.z[i]);
        glColor3f(colors.x[i], colors.y[i], colors.z[i]);
        glVertex3f(vertex.x[i], vertex.y[i], vertex.z[i]);

        */

    }

    glEnd();   // Delimita os vértices, finalizando a função
}

// Função responsável por desenhar o cubo e fazer a animação

void draw_scene() {

    int current_frame = glutGet(GLUT_ELAPSED_TIME);        // Recupera o tempo em milissegundos desde que "glutInit()" foi executada

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);    // Limpa o buffer de cor

    glPushMatrix();                                        // Empilha a matriz atual

    gluLookAt(0, 2.2, -5.2, 0, -0.12, 0, 0, 1, 0);         // Define a posição de visualização
    glRotated(rotation, 1, 1, 1);                          // Define a rotação de acordo com o eixo selecionado (x, y, z)
    draw_cube();                                           // Desenha o cubo

    glPopMatrix();                                         // Desempilha a pilha

    previous_frame = current_frame;                        // Frame anterior recebe o frame atual
    current_picture++;                                     // O quadro atual é incrementado

    glutSwapBuffers();                                     // Troca os buffers da janela atual se houver buffer duplo
}

// Função responsável por fazer a rotação do cubo

void update_rotation() {

    int current_frame = glutGet(GLUT_ELAPSED_TIME);    // Recupera o tempo em milissegundos desde que "glutInit()" foi executada
    int time = current_frame - previous_frame;         // Calcula o frame atual com o frame anterior

    rotation += velocity * time;                       // Calcula a rotação do cubo

    if(rotation > 360.0f) {                            // Atualiza a rotação caso tenha ultrapassado 360°
        rotation -= 360.0f;
    }

    glutPostRedisplay();                               // Marca a janela atual por prioridade para ser exibida novamente
}

// Função responsável por atualizar o título da janela com o FPS

void update_title(int period) {

    fps = current_picture;
    current_picture = 0;

    sprintf(title, "Cubo 3D - [%.2f FPS]", fps);

    glutSetWindowTitle(title);                      // Define o título da janela
    glutTimerFunc(period, update_title, period);    // Define um delay que a função deve esperar antes de executar
}

// Função responsável por redimensionar a janela

void resize(int width, int height) {

    glViewport(0, 0, width, height);                        // Define o formato da janela
    glMatrixMode(GL_PROJECTION);                            // Aplica operações de pilha à matriz de projeção
    glLoadIdentity();                                       // Substitui a matriz atual pela matriz identidade
    gluPerspective(62, (float)(width) / height, 1, 600);    // Define a perspectiva de visualização
    glMatrixMode(GL_MODELVIEW);                             // Aplica operações de pilha à matriz de modeview
    glLoadIdentity();                                       // Substitui a matriz atual pela matriz identidade
}
