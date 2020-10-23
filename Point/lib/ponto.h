#include <GL/glew.h>

#ifndef PONTO_H_INCLUDED
#define PONTO_H_INCLUDED

struct Objeto {
    GLfloat x;
    GLfloat y;
} ponto;

void draw_point();
void resize(int width, int height);

#endif // OBJETO_H_INCLUDED
