#pragma once
#include "field.hpp"

class Painter;

class Game {
public:
    Game();
    void drawRand(Painter& p);

private:
    Field field_;
};
