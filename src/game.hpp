#pragma once
#include "field.hpp"
#include <GL/gl.h>
#include <GL/glut.h>

class Painter;

class Game {
public:
    Game();
    static int speed;
    void drawRand(Painter& p);
    int gamedraw(int argc, char** argv);
    // void keyboard(unsigned char key, int x, int y);

private:
    // static Field field_;
    static void display();
    static void timer(int);
};
