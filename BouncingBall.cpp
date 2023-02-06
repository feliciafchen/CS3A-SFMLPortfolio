//
// Created by Felicia Chen on 12/14/22.
//

#include "BouncingBall.h"

BouncingBall::BouncingBall() {
    circle.setRadius(100);
    circle.setPosition(200, 200);
    circle.setFillColor(sf::Color::Green);
    enableState(HIDDEN);
}

void BouncingBall::eventHandler(sf::RenderWindow &window, sf::Event event) {
}

void BouncingBall::update(sf::RenderWindow &window) {
    if(!checkState(HIDDEN))
    {
        bounce(windowSize, circle, moveX, moveY);

        circle.move(moveX, moveY);
        window.clear();
        window.draw(circle);
    }
}

void BouncingBall::bounce(sf::Vector2i window, sf::CircleShape circle, double &moveX, double &moveY) {
    if (circle.getPosition().x == window.x - (circle.getRadius()*2))
    {
        moveX = -10;
    }
    else if(circle.getPosition().x == 0)
    {
        moveX = 10;
    }

    if (circle.getPosition().y == window.y - (circle.getRadius()*2))
    {
        moveY = -10;
    }
    else if(circle.getPosition().y == 0)
    {
        moveY = 10;
    }
}
