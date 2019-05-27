#include "field.hpp"
#include "painter.hpp"
#include <cstdlib>
#include <ctime>

Field::Field()
{
    srand(static_cast<unsigned int>(time(0)));
    for (int y = 0; y < HEIGHT; y++)
        for (int x = 0; x < WIDTH; x++) {
            map[x][y].life = bool(std::rand() % 2);
            map[x][y].succ = 0;
        }
}

void Field::draw(Painter& p)
{
    for (int i = 0; i < HEIGHT; i++)
        for (int j = 0; j < WIDTH; j++)
            if (map[i][j].life)
                p.rect(SIZE / 2 + j * SIZE, SIZE / 2 + i * SIZE);
}
