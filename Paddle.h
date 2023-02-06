//
// Created by Felicia Chen on 10/10/22.
//

#ifndef HELLOSFML_PADDLE_H
#define HELLOSFML_PADDLE_H
#include <SFML/Graphics.hpp>

class Paddle : public sf::RectangleShape
{
public:
    Paddle();
    void movePaddleWASD(const sf::Vector2u& windowSize);
    void movePaddle(const sf::Vector2u& windowSize);
};


#endif //HELLOSFML_PADDLE_H
