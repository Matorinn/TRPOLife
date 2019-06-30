#pragma once
#include "GL/gl.h"
#include "GL/glut.h"
#include "painter.hpp"

class Field {
public:
    Field();
    enum { WIDTH = 120, HEIGHT = 60, SIZE = 10 };
    void genChange();
    void clearField();
    void draw(Painter& p);
    static void motion(int ax, int ay);
    static void motionpass(int ax, int ay);
    static void mouse(int button, int state, int ax, int ay);

private:
    struct Cell {
        bool life;
        int succ;
    } map[WIDTH][HEIGHT];
};
