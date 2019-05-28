#include "game.hpp"
#include <cstdlib>

Game::Game()
{
}

void Game::drawRand(Painter& p)
{
    field_.draw(p);
}
