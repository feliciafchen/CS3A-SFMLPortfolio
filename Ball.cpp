//
// Created by Felicia Chen on 10/10/22.
//

#include "Ball.h"

void Ball::bounce(const sf::RenderWindow& window)
{

}
void Ball::bounce(const sf::Vector2u& windowSize, sf::RectangleShape lRect, sf::RectangleShape rRect)
{
    sf::FloatRect b = getGlobalBounds();
    sf::FloatRect p1 = lRect.getGlobalBounds();
    sf::FloatRect p2 = rRect.getGlobalBounds();

    if((b.top + b.height >= windowSize.y) || (b.top <= 0))
    {
        velocity.y *= -1;
    }

    if(b.intersects(p2) || (b.intersects(p1)))
    {
        velocity.x *= -1;
    }

    if(getPosition().x <= 0 - getRadius()*2)
    {
        velocity = {0,0};
        resetGame(windowSize, 2);
        return;
    }

    if(getPosition().x >= windowSize.x)
    {
        velocity = {0,0};
        resetGame(windowSize, 1);
        return;
    }

    sf::CircleShape::move(velocity);
}
void Ball::setVelocity(const sf::Vector2f velocity)
{
    this -> velocity = velocity;
}
void Ball::resetGame(const sf::Vector2u& windowSize, int paddle)
{
    setPosition(windowSize.x/2, windowSize.y/2);

    if(paddle == 1) {
//        if((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)))
        {
            velocity = {10, 10};
        }
    }
    else if(paddle == 2)
    {
//        if((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)))
        {
            velocity = {-10,-10};
        }
    }
}
