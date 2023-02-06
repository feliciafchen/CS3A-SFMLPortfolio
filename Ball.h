//
// Created by Felicia Chen on 10/10/22.
//

#ifndef HELLOSFML_BALL_H
#define HELLOSFML_BALL_H
#include <SFML/Graphics.hpp>

class Ball: public sf::CircleShape
{
private:
    sf::Vector2f velocity = {10, 10};

public:
    void bounce(const sf::RenderWindow& window);
    void bounce(const sf::Vector2u& windowSize, sf::RectangleShape lRect, sf::RectangleShape rRect);
    void setVelocity(const sf::Vector2f velocity);
    void resetGame(const sf::Vector2u& windowSize, int paddle);
};


#endif //HELLOSFML_BALL_H
