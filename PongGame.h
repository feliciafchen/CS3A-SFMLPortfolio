//
// Created by Felicia Chen on 12/14/22.
//

#ifndef HELLOSFML_PONGGAME_H
#define HELLOSFML_PONGGAME_H
#include "Ball.h"
#include "Paddle.h"
#include "States.h"
#include "Games.h"

class PongGame : public States, public Games{
private:
    Ball circle;
    Paddle paddle1, paddle2;
public:
    PongGame(sf::RenderWindow& window);
    void update(sf::RenderWindow& window);
};


#endif //HELLOSFML_PONGGAME_H
