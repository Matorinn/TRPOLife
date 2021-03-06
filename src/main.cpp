#include "SFML/Graphics.hpp"
#include "game.hpp"

void pressoptions(sf::RenderWindow& window, sf::Event& event, sf::Sprite& backb)
{
    sf::Texture obg, clb, okt, mint, midt, maxt;
    sf::Sprite options_bckg, colorb[7], oksprite[2], mins, mids, maxs;
    obg.loadFromFile("textures/options_bckg.png");
    okt.loadFromFile("textures/ok.png");
    mint.loadFromFile("textures/min.png");
    midt.loadFromFile("textures/mid.png");
    maxt.loadFromFile("textures/max.png");
    clb.loadFromFile("textures/color.png");
    options_bckg.setTexture(obg);
    mins.setTexture(mint);
    mids.setTexture(midt);
    maxs.setTexture(maxt);
    for (int i = 0; i < 7; i++) {
        colorb[i].setTexture(clb);
    }
    colorb[0].setColor(sf::Color(255, 0, 0));
    colorb[1].setColor(sf::Color(255, 255, 255));
    colorb[2].setColor(sf::Color(255, 0, 255));
    colorb[3].setColor(sf::Color(0, 0, 127));
    colorb[4].setColor(sf::Color(0, 255, 0));
    colorb[5].setColor(sf::Color(127, 127, 0));
    colorb[6].setColor(sf::Color(0, 255, 255));
    for (int i = 0; i < 4; i++) {
        colorb[i].setPosition(630 + i * 60, 310);
    }
    for (int i = 0; i < 3; i++) {
        colorb[i + 4].setPosition(630 + i * 60, 370);
    }
    mins.setPosition(690, 210);
    mids.setPosition(760, 210);
    maxs.setPosition(830, 210);
    backb.setPosition(940, 540);
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonReleased
                && event.mouseButton.button == sf::Mouse::Left) {
                if (sf::IntRect(backb.getGlobalBounds())
                            .contains(sf::Mouse::getPosition(window)))
                    return;
                if (sf::IntRect(colorb[0].getGlobalBounds())
                            .contains(sf::Mouse::getPosition(window))) {
                    oksprite[0].setTexture(okt);
                    oksprite[0].setPosition(630, 310);
                    Painter::active = "red";
                }
                if (sf::IntRect(colorb[1].getGlobalBounds())
                            .contains(sf::Mouse::getPosition(window))) {
                    oksprite[0].setTexture(okt);
                    oksprite[0].setPosition(690, 310);
                    Painter::active = "white";
                }
                if (sf::IntRect(colorb[2].getGlobalBounds())
                            .contains(sf::Mouse::getPosition(window))) {
                    oksprite[0].setTexture(okt);
                    oksprite[0].setPosition(750, 310);
                    Painter::active = "magenta";
                }
                if (sf::IntRect(colorb[3].getGlobalBounds())
                            .contains(sf::Mouse::getPosition(window))) {
                    oksprite[0].setTexture(okt);
                    oksprite[0].setPosition(810, 310);
                    Painter::active = "dark_blue";
                }
                if (sf::IntRect(colorb[4].getGlobalBounds())
                            .contains(sf::Mouse::getPosition(window))) {
                    oksprite[0].setTexture(okt);
                    oksprite[0].setPosition(630, 370);
                    Painter::active = "green";
                }
                if (sf::IntRect(colorb[5].getGlobalBounds())
                            .contains(sf::Mouse::getPosition(window))) {
                    oksprite[0].setTexture(okt);
                    oksprite[0].setPosition(690, 370);
                    Painter::active = "brown";
                }
                if (sf::IntRect(colorb[6].getGlobalBounds())
                            .contains(sf::Mouse::getPosition(window))) {
                    oksprite[0].setTexture(okt);
                    oksprite[0].setPosition(750, 370);
                    Painter::active = "cyan";
                }

                if (sf::IntRect(mins.getGlobalBounds())
                            .contains(sf::Mouse::getPosition(window))) {
                    oksprite[1].setTexture(okt);
                    oksprite[1].setPosition(690, 210);
                    Game::speed = 100;
                }

                if (sf::IntRect(mids.getGlobalBounds())
                            .contains(sf::Mouse::getPosition(window))) {
                    oksprite[1].setTexture(okt);
                    oksprite[1].setPosition(760, 210);
                    Game::speed = 10;
                }

                if (sf::IntRect(maxs.getGlobalBounds())
                            .contains(sf::Mouse::getPosition(window))) {
                    oksprite[1].setTexture(okt);
                    oksprite[1].setPosition(830, 210);
                    Game::speed = 1;
                }
            }
        }

        window.clear(sf::Color(82, 82, 82, 255));
        for (int i = 0; i < 7; i++)
            window.draw(colorb[i]);
        window.draw(mins);
        window.draw(mids);
        window.draw(maxs);
        for (int i = 0; i < 2; i++)
            window.draw(oksprite[i]);
        window.draw(options_bckg);
        window.draw(backb);
        window.display();
    }
}

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

void postmenu(
        sf::RenderWindow& window,
        sf::Event& event,
        sf::Sprite& backb,
        sf::Sprite& playb,
        int argc,
        char** argv)
{
    Game game;
    sf::Texture pmbg;
    sf::Sprite postmenu_bckg;
    pmbg.loadFromFile("textures/postmenu.png");
    postmenu_bckg.setTexture(pmbg);
    backb.setPosition(940, 540);
    playb.setPosition(300, 425);
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonReleased
                && event.mouseButton.button == sf::Mouse::Left) {
                if (sf::IntRect(backb.getGlobalBounds())
                            .contains(sf::Mouse::getPosition(window)))
                    return;
                if (sf::IntRect(playb.getGlobalBounds())
                            .contains(sf::Mouse::getPosition(window)))
                    game.gamedraw(argc, argv);
            }
        }

        window.clear(sf::Color(82, 82, 82, 255));
        window.draw(postmenu_bckg);
        window.draw(backb);
        window.draw(playb);
        window.display();
    }
}

int main(int argc, char* argv[])
{
    sf::RenderWindow window(sf::VideoMode(1000, 600), "MainMenu");
    sf::Texture pb, rb, ob, xb, bb, ttle;
    sf::Sprite playb, rulesb, optionsb, exitb, backb, title;
    ttle.loadFromFile("textures/title.png");
    pb.loadFromFile("textures/play.png");
    rb.loadFromFile("textures/rules.png");
    ob.loadFromFile("textures/options.png");
    xb.loadFromFile("textures/exit.png");
    bb.loadFromFile("textures/back.png");
    playb.setTexture(pb);
    rulesb.setTexture(rb);
    optionsb.setTexture(ob);
    exitb.setTexture(xb);
    backb.setTexture(bb);
    title.setTexture(ttle);
    title.setPosition(300, 0);
    rulesb.setPosition(300, 225);
    optionsb.setPosition(300, 325);
    exitb.setPosition(300, 425);
    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonReleased
                && event.mouseButton.button == sf::Mouse::Left) {
                if (sf::IntRect(playb.getGlobalBounds())
                            .contains(sf::Mouse::getPosition(window))) {
                    postmenu(window, event, backb, playb, argc, argv);
                }
                if (sf::IntRect(rulesb.getGlobalBounds())
                            .contains(sf::Mouse::getPosition(window))) {
                    pressrules(window, event, backb);
                }
                if (sf::IntRect(optionsb.getGlobalBounds())
                            .contains(sf::Mouse::getPosition(window))) {
                    pressoptions(window, event, backb);
                }
                if (sf::IntRect(exitb.getGlobalBounds())
                            .contains(sf::Mouse::getPosition(window))) {
                    window.close();
                }
            }
        }

        window.clear(sf::Color(82, 82, 82, 255));
        window.draw(title);
        window.draw(playb);
        playb.setPosition(300, 125);
        window.draw(rulesb);
        window.draw(optionsb);
        window.draw(exitb);
        window.display();
    }
}
