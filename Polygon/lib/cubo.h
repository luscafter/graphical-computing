#include <GL/glew.h>

#ifndef CUBO_H_INCLUDED
#define CUBO_H_INCLUDED

/*

Ao construir a struct abaixo é gerado o seguinte erro: "error: expected ‘=’, ‘,’, ‘;’, ‘asm’ or ‘__attribute__’ before ‘{’ token"

struct Objeto {
	GLfloat x[36];
	GLfloat y[36];
	GLfloat z[36];
} vertex, normal, colors;

*/

void draw_cube(void);
void draw_scene(void);
void update_rotation(void);
void update_title(int period);
void resize(int width, int height);

#endif // CUBO_H_INCLUDED