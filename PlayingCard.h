//
// Created by Felicia Chen on 12/14/22.
//

#ifndef HELLOSFML_PLAYINGCARD_H
#define HELLOSFML_PLAYINGCARD_H
#include "SFML/Graphics.hpp"
#include "Card.h"
#include "States.h"
#include "Games.h"

class PlayingCard : public States, public Games{
private:
    Card card;
public:
    PlayingCard();
    void update(sf::RenderWindow& window);
};

#endif //HELLOSFML_PLAYINGCARD_H
