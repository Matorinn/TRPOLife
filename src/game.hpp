#pragma once
#include "painter.hpp"

class Game {
public:
    Game();
    int gamedraw(int argc, char** argv);
    static int speed;

private:
    static void keyboard(unsigned char key, int x, int y);
    static void display();
    static void timer(int);
};
