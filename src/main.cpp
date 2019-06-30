#include "game.hpp"
#include "painter.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

void pressrules(sf::RenderWindow& window, sf::Event& event, sf::Sprite& backb)
{
    sf::Texture rbg;
    sf::Sprite rules_bckg;
    rbg.loadFromFile("textures/rules_bckg.png");
    rules_bckg.setTexture(rbg);
    backb.setPosition(940, 540);
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonReleased
                && event.mouseButton.button == sf::Mouse::Left)
                if (sf::IntRect(backb.getGlobalBounds())
                            .contains(sf::Mouse::getPosition(window)))
                    return;
        }

        window.clear(sf::Color(82, 82, 82, 255));
        window.draw(rules_bckg);
        window.draw(backb);
        window.display();
    }
}

int main(int argc, char* argv[])
{
    Game game;
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
                    game.gamedraw(argc, argv);
                }
                if (sf::IntRect(rulesb.getGlobalBounds())
                            .contains(sf::Mouse::getPosition(window))) {
                    pressrules(window, event, backb);
                }
                if (sf::IntRect(optionsb.getGlobalBounds())
                            .contains(sf::Mouse::getPosition(window))) {
                }
                if (sf::IntRect(exitb.getGlobalBounds())
                            .contains(sf::Mouse::getPosition(window))) {
                    window.close();
                }
            }
        }

        window.clear(sf::Color(82, 82, 82, 255));
        window.draw(title);
        title.setPosition(300, 0);
        window.draw(playb);
        playb.setPosition(300, 125);
        window.draw(rulesb);
        rulesb.setPosition(300, 225);
        window.draw(optionsb);
        optionsb.setPosition(300, 325);
        window.draw(exitb);
        exitb.setPosition(300, 425);
        window.display();
    }
}
