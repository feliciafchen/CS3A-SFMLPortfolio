//
// Created by Felicia Chen on 10/10/22.
//

#include "Paddle.h"

Paddle::Paddle() : sf::RectangleShape()
{
    //shape yourself like a pong paddle
    setSize({30,500});
}
void Paddle::movePaddleWASD(const sf::Vector2u& windowSize)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && (getPosition().y < windowSize.y - getSize().y))
    {
        move({0, 20});
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && (getPosition().y > 0))
    {
        move({0, -20});
    }
}
void Paddle::movePaddle(const sf::Vector2u& windowSize)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && (getPosition().y < windowSize.y - getSize().y))
    {
        move({0, 20});
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && (getPosition().y > 0))
    {
        move({0, -20});
    }
}