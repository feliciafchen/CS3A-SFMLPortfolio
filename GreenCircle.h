//
// Created by Felicia Chen on 12/14/22.
//

#ifndef FELICIACHENCS3APORTFOLIO_GREENCIRCLE_H
#define FELICIACHENCS3APORTFOLIO_GREENCIRCLE_H
#include "SFML/Graphics.hpp"
#include "States.h"
#include "Games.h"

class GreenCircle : public States, public Games{
private:
    sf::CircleShape shape;
public:
    GreenCircle();
    void update(sf::RenderWindow& window);
};


#endif //FELICIACHENCS3APORTFOLIO_GREENCIRCLE_H
