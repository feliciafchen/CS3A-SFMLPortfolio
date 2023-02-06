//
// Created by Felicia Chen on 12/14/22.
//

#include "PongGame.h"

PongGame::PongGame(sf::RenderWindow &window) {
    paddle1.setPosition(window.getSize().x * .028, window.getSize().y * .24);
    paddle1.setFillColor(sf::Color::Blue);

    paddle2.setPosition(window.getSize().x * .96, window.getSize().y * .19);
    paddle2.setFillColor(sf::Color::Blue);

    circle.setRadius(50);
    circle.setPosition(window.getSize().x/2 - circle.getGlobalBounds().width/2,
                       window.getSize().y/2 - circle.getGlobalBounds().height/2);
    circle.setFillColor(sf::Color::White);

    enableState(HIDDEN);
}

void PongGame::update(sf::RenderWindow &window) {
    if(!checkState(HIDDEN))
    {
        circle.bounce(window.getSize(), paddle1, paddle2);

        paddle1.movePaddleWASD(window.getSize());
        paddle2.movePaddle(window.getSize());

        window.clear(sf::Color::Black);
        window.draw(paddle1);
        window.draw(paddle2);
        window.draw(circle);
    }
}
