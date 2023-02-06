//
// Created by Felicia Chen on 12/14/22.
//

#ifndef FELICIACHENCS3APORTFOLIO_ARROWS_H
#define FELICIACHENCS3APORTFOLIO_ARROWS_H
#include "SFML/Graphics.hpp"
#include "States.h"
#include "Images.h"
#include "MouseEvents.h"
#include "Arrow.h"

class Arrows : public States{
private:
    sf::Clock clock;
    Arrow right1, right2, left1, left2;
    void setup(sf::RenderWindow& window);
public:
    Arrows();
    Arrows(sf::RenderWindow& window);
    void update(sf::RenderWindow& window);
    bool rightIsClicked(sf::RenderWindow& window);
    bool leftIsClicked(sf::RenderWindow& window);
};


#endif //FELICIACHENCS3APORTFOLIO_ARROWS_H
