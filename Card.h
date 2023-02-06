//
// Created by Felicia Chen on 10/25/22.
//

#ifndef HELLOSFML_CARD_H
#define HELLOSFML_CARD_H
#include <iostream>
#include "SFML/Graphics.hpp"
#include "rankEnum.h"
#include "suitEnum.h"

class Card : public sf::Drawable, sf::Transformable
{
private:
    sf::RectangleShape background;
    sf::Text rank1, rank2;
    sf::Sprite suit;
    static sf::Texture texture;
    static sf::Font font;
    suitEnum _suit;
    rankEnum _rank;
    std::string rankToString();
    std::string suitToString();
    void initialize();
    void setupBackground();
    void setupRank();
    void setupSuit();
public:
    Card();
    Card(suitEnum suit, rankEnum rank);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};


#endif //HELLOSFML_CARD_H
