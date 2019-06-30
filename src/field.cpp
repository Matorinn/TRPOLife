#include "field.hpp"
#include "GL/glut.h"
#include "painter.hpp"
#include <cstdlib>
#include <ctime>

int m_x, m_y; // mouse x y
bool m_down = false;

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
            if (map[j][i].life)
                p.rect(j * SIZE + 1,
                       i * SIZE + 1,
                       (j + 1) * SIZE - 1,
                       (i + 1) * SIZE - 1);

    if (m_down && m_x > 0 && m_y > 0 && m_x < WIDTH * SIZE
        && m_y < HEIGHT * SIZE)
        map[int(m_x / SIZE)][int(m_y / SIZE)].life = 1;
    else {
        int x = m_x / SIZE;
        int y = m_y / SIZE;
        p.rect(SIZE * x + 1,
               y * SIZE + 1,
               (x + 1) * SIZE - 1,
               (y + 1) * SIZE - 1);
    }
}

void Field::clearField()
{
    for (int y = 0; y < HEIGHT; ++y)
        for (int x = 0; x < WIDTH; ++x) {
            map[x][y].succ = 0;
            map[x][y].life = 0;
        }
}

void Field::genChange()
{
    int count = 0;
    int x_ = 0;
    int y_ = 0;

    for (int y = 0; y < HEIGHT; y++)
        for (int x = 0; x < WIDTH; x++) {
            count = 0;
            // left
            x == 0 ? x_ = WIDTH - 1 : x_ = x - 1;
            if (map[x_][y].life)
                count++;
            // up
            y == 0 ? y_ = HEIGHT - 1 : y_ = y - 1;
            if (map[x][y_].life)
                count++;
            // left + up
            if (map[x_][y_].life)
                count++;
            // right
            x == WIDTH - 1 ? x_ = 0 : x_ = x + 1;
            if (map[x_][y].life)
                count++;
            // right + up
            if (map[x_][y_].life)
                count++;
            // down
            y == HEIGHT - 1 ? y_ = 0 : y_ = y + 1;
            if (map[x][y_].life)
                count++;
            // right + down
            if (map[x_][y_].life)
                count++;
            // left + down
            x == 0 ? x_ = WIDTH - 1 : x_ = x - 1;
            if (map[x_][y_].life)
                count++;

            if (map[x][y].life)
                if (count != 2 && count != 3)
                    map[x][y].succ = false;
                else
                    map[x][y].succ = true;

            if (!map[x][y].life)
                if (count == 3)
                    map[x][y].succ = true;
                else
                    map[x][y].succ = false;
        }

    for (int y = 0; y < HEIGHT; y++)
        for (int x = 0; x < WIDTH; x++)
            map[x][y].life = map[x][y].succ;
}

void Field::motion(int ax, int ay)
{
    m_x = ax;
    m_y = ay;
}
void Field::motionpass(int ax, int ay)
{
    m_x = ax;
    m_y = ay;
}
void Field::mouse(int button, int state, int ax, int ay)
{
    m_y = ay;
    m_x = ax;
    m_down = state == GLUT_DOWN;
}
