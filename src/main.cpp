#include "GL/gl.h"
#include "GL/glut.h"
#include <iostream>

int width = 1200;
int height = 600;

void draw();
void keyboard(unsigned char key, int x, int y);

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(100, 100);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutCreateWindow("Game of life");

    glutDisplayFunc(draw);
    glutKeyboardFunc(keyboard);
    glClearColor(0, 0, 0, 0);

    glutMainLoop();

    return 0;
}

void draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
    // 27 = ESC
    if (key == 27)
        exit(0);
}
