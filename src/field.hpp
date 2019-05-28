#pragma once

class Painter;

class Field {
public:
    enum { WIDTH = 120, HEIGHT = 60, SIZE = 10 };
    Field();

    void draw(Painter& p);

private:
    void genChange();
    struct Cell {
        bool life;
        int succ;
    } map[WIDTH][HEIGHT];
};
