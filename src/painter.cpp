#include "painter.hpp"
#include "field.hpp"
#include <GL/gl.h>

void Painter::rect(int x, int y)
{
    glColor3f(1, 1, 1);

    glPointSize(Field::SIZE);

    glBegin(GL_POINTS);

    glVertex2f(x, y);

    glEnd();
}
