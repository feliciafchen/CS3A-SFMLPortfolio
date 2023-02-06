//
// Created by Felicia Chen on 11/2/22.
//

#ifndef FCPOKERANALYSIS_DrawCard_H
#define FCPOKERANALYSIS_DrawCard_H
#include <iostream>
#include "SFML/Graphics.hpp"
#include "rankEnum.h"
#include "suitEnum.h"
#include "PAcard.h"

class DrawCard : public sf::Drawable, sf::Transformable
{
private:
    PAcard card;
    sf::RectangleShape background;
    sf::Text rank1, rank2;
    sf::Sprite suit;
    sf::Texture texture;
    static sf::Font font;
    std::string rankToString();
    std::string suitToString();
    void initialize();
    void setupBackground();
    void setupRank();
    void setupSuit();
public:
    DrawCard();
    DrawCard(suitEnum suit, rankEnum rank);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void setSize(float size);
    sf::Vector2f getSize();
    void setPosition(sf::Vector2f position);
    sf::Vector2f getPosition();
};


#endif //FCPOKERANALYSIS_DrawCard_H
