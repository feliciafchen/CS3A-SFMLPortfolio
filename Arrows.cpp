//
// Created by Felicia Chen on 12/14/22.
//

#include "Arrows.h"

Arrows::Arrows() {

}

Arrows::Arrows(sf::RenderWindow& window)
: right1(Images::get(BUTTON1)), right2(Images::get(BUTTON2)),
left1(Images::get(LEFTBUTTON1)), left2(Images::get(LEFTBUTTON2))
{
    setup(window);
}

void Arrows::setup(sf::RenderWindow& window) {
    right1.setScale({15, 15});
    right1.setPosition({window.getSize().x - right1.getGlobalBounds().width - 50,
                        window.getSize().y/2 - right1.getGlobalBounds().height/2});

    right2.setScale({15, 15});
    right2.setPosition({window.getSize().x - right1.getGlobalBounds().width - 50,
                        window.getSize().y/2 - right1.getGlobalBounds().height/2});

    left1.setScale({15, 15});
    left1.setPosition({50, window.getSize().y/2 - right1.getGlobalBounds().height/2});

    left2.setScale({15,15});
    left2.setPosition({50, window.getSize().y/2 - right1.getGlobalBounds().height/2});
}

void Arrows::update(sf::RenderWindow &window) {
    if(MouseEvents::isClick(right1, window))
    {
        right1.enableState(HIDDEN);
        clock.restart();
    }
    else if(MouseEvents::isClick(left1, window))
    {
        left1.enableState(HIDDEN);
    }
    else
    {
        right1.disableState(HIDDEN);
        left1.disableState(HIDDEN);
    }

    if(!checkState(HIDDEN))
    {
        window.draw(right2);
        window.draw(left2);
        if(!right1.checkState(HIDDEN))
            window.draw(right1);
        if(!left1.checkState(HIDDEN))
            window.draw(left1);
    }
}

bool Arrows::rightIsClicked(sf::RenderWindow& window) {
    if(!checkState(HIDDEN) && (MouseEvents::isClick(right1, window) || MouseEvents::isClick(right2, window)) && clock.getElapsedTime().asMilliseconds() > 10)
    {
        clock.restart();
        return true;
    }
    return false;
}

bool Arrows::leftIsClicked(sf::RenderWindow& window) {
    if(!checkState(HIDDEN) && (MouseEvents::isClick(left1, window) || MouseEvents::isClick(left2, window)) && clock.getElapsedTime().asMilliseconds() > 10)
    {
        clock.restart();
        return true;
    }
    return false;
}