//
// Created by Felicia Chen on 12/14/22.
//

#ifndef FELICIACHENCS3APORTFOLIO_ARROW_H
#define FELICIACHENCS3APORTFOLIO_ARROW_H
#include <SFML/Graphics/Sprite.hpp>
#include "States.h"

class Arrow : public sf::Sprite, public States{
public:
    Arrow();
    Arrow(const sf::Texture &texture);
};


#endif //FELICIACHENCS3APORTFOLIO_ARROW_H
