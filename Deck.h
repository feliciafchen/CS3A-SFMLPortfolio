//
// Created by Felicia Chen on 10/29/22.
//

#ifndef HELLOSFML_DECK_H
#define HELLOSFML_DECK_H
#include "PAcard.h"
#include <iostream>

class Deck {
private:
    int cardIndex = 0;
    PAcard deck[52];
    const int DECK_SIZE = 52;
public:
    Deck();
    void shuffle();
    PAcard dealCard();
    PAcard getCardAt(int index) const;
    int getCardIndex();
    friend std::ostream& operator <<(std::ostream& out, const Deck& deck);
};


#endif //HELLOSFML_DECK_H
