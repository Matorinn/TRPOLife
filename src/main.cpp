#include "game.hpp"
#include "painter.hpp"
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>

unsigned char lastKey = 0;

void display();
void timer(int = 0);
void keyboard(unsigned char key, int x, int y);

Game game;

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(Field::WIDTH * Field::SIZE, Field::HEIGHT * Field::SIZE);
    glutInitWindowPosition(100, 780);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutCreateWindow("Game of life");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,
            Field::WIDTH * Field::SIZE,
            Field::HEIGHT * Field::SIZE,
            0,
            -1,
            1);

    glutDisplayFunc(display);
    timer(0);

    glutKeyboardFunc(keyboard);
    glClearColor(0, 0, 0, 0);
    glutMainLoop();

    return 0;
}

void keyboard(unsigned char key, int x, int y)
{
    if (key == 27)
        exit(0);
    lastKey = key;
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    Painter p;
    game.drawRand(p);
    glutSwapBuffers();
}

void timer(int)
{
    display();
    glutTimerFunc(10, timer, 0);
}
