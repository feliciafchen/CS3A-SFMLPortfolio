//
// Created by Felicia Chen on 12/14/22.
//

#ifndef FELICIACHENCS3APORTFOLIO_BOUNCINGBALL_H
#define FELICIACHENCS3APORTFOLIO_BOUNCINGBALL_H
#include "SFML/Graphics.hpp"
#include "States.h"
#include "Games.h"

class BouncingBall : public States, public Games{
private:
    double moveX = 10, moveY = 10;
    const int width = 2650;
    const int height = 1600;
    sf::Vector2i windowSize{width, height};
    sf::CircleShape circle;
    void bounce(sf::Vector2i window, sf::CircleShape circle, double& moveX, double& moveY);
public:
    BouncingBall();
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update(sf::RenderWindow& window);
};


#endif //FELICIACHENCS3APORTFOLIO_BOUNCINGBALL_H
