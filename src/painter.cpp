#include "painter.hpp"
#include "field.hpp"
#include <GL/gl.h>

std::string Painter::active;

void Painter::rect(int x1, int y1, int x2, int y2)
{
    setColor(color[active]);
    glBegin(GL_QUADS);
    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glVertex2f(x1, y2);
    glEnd();
}

void Painter::setColor(int col)
{
    static const struct {
        float r, g, b;
    } colors[] = {
            {1, 0, 0},     // red
            {1, 1, 1},     // white
            {1, 0, 1},     // magenta
            {0, 0, 0.5},   // dark blue
            {0, 1, 0},     // green
            {0.5, 0.5, 0}, // brown
            {0, 1, 1},     // cyan
            {0, 0, 0}      // black
    };
    glColor3f(colors[col].r, colors[col].g, colors[col].b);
}
