#include "game.hpp"
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>

int width = 1200;
int height = 600;
// last key pressed
unsigned char lastKey = 0;

void (*pDisplay)(void);

void draw();
void timer(int = 0);
void keyboard(unsigned char key, int x, int y);

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(100, 50);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutCreateWindow("Game of life");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, height, 0, -1, 1);

    pDisplay = &draw;
    glutDisplayFunc(pDisplay);
    timer();

    glutKeyboardFunc(keyboard);
    glClearColor(0, 0, 0, 1.0);
    glutMainLoop();

    return 0;
}

void draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3ub(255, 255, 255);

    glutSwapBuffers();
}

void timer(int)
{
    if (lastKey == 32) {
        gameStart();
        lastKey = 0;
    }
    pDisplay();
    glutTimerFunc(10, timer, 0);
}

void keyboard(unsigned char key, int x, int y)
{
    // app closes when Esc pressed
    if (key == 27)
        exit(0);
    lastKey = key;
}
