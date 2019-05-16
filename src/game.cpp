#include "GL/gl.h"
#include "GL/glut.h"
#include "iostream"

const int X = 60;
const int Y = 120;

extern void (*pDisplay)(void);

struct Cell {
    bool life;
    int succ;
} field[X][Y];

void displayField()
{
    int cellSize = 10;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3ub(255, 255, 255);
    glPointSize(cellSize);

    glBegin(GL_POINTS);

    for (int j = 0; j < Y; j++)
        for (int i = 0; i < X; i++)
            if (field[i][j].life)
                glVertex2f(
                        cellSize / 2 + j * cellSize,
                        cellSize / 2 + i * cellSize);

    glEnd();
    glutSwapBuffers();
}

void gameStart()
{
    // filling structure random data
    for (int i = 0; i < X; i++)
        for (int j = 0; j < Y; j++) {
            field[i][j].life = rand() % 2;
            field[i][j].succ = 0;
        }
    pDisplay = &displayField;
}
