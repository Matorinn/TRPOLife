#include "game.hpp"
#include "painter.hpp"
#include <GL/gl.h>
#include <GL/glut.h>
#include <SFML/Graphics.hpp>
#include <iostream>

unsigned char lastKey = 0;

void display();
void timer(int = 0);
void keyboard(unsigned char key, int x, int y);

Game game;

int gamedraw(int argc, char** argv)
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

int main(int argc, char* argv[])
{
    sf::RenderWindow window(sf::VideoMode(1000, 600), "MainMenu");
    sf::Texture pb, rb, ob, xb, bb, ttle;
    ttle.loadFromFile("textures/title.png");
    pb.loadFromFile("textures/play.png");
    rb.loadFromFile("textures/rules.png");
    ob.loadFromFile("textures/options.png");
    xb.loadFromFile("textures/exit.png");
    bb.loadFromFile("textures/back.png");
    sf::Sprite playb, rulesb, optionsb, exitb, backb, title;
    playb.setTexture(pb);
    rulesb.setTexture(rb);
    optionsb.setTexture(ob);
    exitb.setTexture(xb);
    backb.setTexture(bb);
    title.setTexture(ttle);

    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonReleased
                && event.mouseButton.button == sf::Mouse::Left) {
                if (sf::IntRect(playb.getGlobalBounds())
                            .contains(sf::Mouse::getPosition(window))) {
                    gamedraw(argc, argv);
                }
            }
        }

        window.clear(sf::Color(82, 82, 82, 255));
        window.draw(title);
        title.setPosition(300, 0);
        window.draw(playb);
        playb.setPosition(300, 125);
        window.display();
    }
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
