//
// Created by Felicia Chen on 12/14/22.
//

#ifndef FCPOKERANALYSIS_POKERANALYSIS_H
#define FCPOKERANALYSIS_POKERANALYSIS_H
#include "SFML/Graphics.hpp"
#include "PAcard.h"
#include "test.h"
#include "PokerScore.h"
#include "DrawCard.h"
#include "States.h"
#include "Games.h"

class PokerAnalysis : public States, public Games{
private:
    DrawCard card[10][5] = {{DrawCard(SPADES, ACE), DrawCard(SPADES, KING), DrawCard(SPADES, QUEEN), DrawCard(SPADES, JACK), DrawCard(SPADES, TEN) },
                            {DrawCard(DIAMONDS, ACE), DrawCard(DIAMONDS, TWO), DrawCard(DIAMONDS, THREE), DrawCard(DIAMONDS, FOUR), DrawCard(DIAMONDS, FIVE) },
                            {DrawCard(DIAMONDS, SEVEN), DrawCard(CLUBS, SEVEN), DrawCard(HEARTS, SEVEN), DrawCard(SPADES, SEVEN), DrawCard(SPADES, NINE) },
                            {DrawCard(DIAMONDS, THREE), DrawCard(CLUBS, THREE), DrawCard(HEARTS, THREE), DrawCard(DIAMONDS, EIGHT), DrawCard(CLUBS, EIGHT) },
                            {DrawCard(SPADES, FIVE), DrawCard(SPADES, SEVEN), DrawCard(SPADES, TEN), DrawCard(SPADES, QUEEN), DrawCard(SPADES, KING) },
                            {DrawCard(CLUBS, ACE), DrawCard(HEARTS, TWO), DrawCard(SPADES, THREE), DrawCard(HEARTS, FOUR), DrawCard(CLUBS, FIVE) },
                            {DrawCard(DIAMONDS, EIGHT), DrawCard(HEARTS, EIGHT), DrawCard(CLUBS, EIGHT), DrawCard(DIAMONDS, TWO), DrawCard(SPADES, QUEEN) },
                            {DrawCard(DIAMONDS, NINE), DrawCard(HEARTS, NINE), DrawCard(CLUBS, TEN), DrawCard(DIAMONDS, TEN), DrawCard(SPADES, KING) },
                            {DrawCard(HEARTS, KING), DrawCard(SPADES, KING), DrawCard(SPADES, ACE), DrawCard(SPADES, NINE), DrawCard(CLUBS, QUEEN) },
                            {DrawCard(DIAMONDS, TEN), DrawCard(CLUBS, THREE), DrawCard(HEARTS, QUEEN), DrawCard(SPADES, ACE), DrawCard(DIAMONDS, JACK) }};
    sf::Text text[10];
    sf::Font font;
public:
    PokerAnalysis(sf::RenderWindow& window);
    void update(sf::RenderWindow& window);
};


#endif //FCPOKERANALYSIS_POKERANALYSIS_H
