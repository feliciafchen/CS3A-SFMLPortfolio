//
// Created by Felicia Chen on 10/30/22.
//

#ifndef HELLOSFML_CARDHAND_H
#define HELLOSFML_CARDHAND_H
#include <iostream>
#include <vector>
#include "PAcard.h"
#include "Deck.h"

class CardHand {
private:
    std::vector<PAcard> cardHand;
    void sort();
public:
    CardHand();
    int getSize() const;
    void addCard(PAcard card);
    bool containsCard(PAcard card);
    bool containsRank(rankEnum rank) const;
    bool ofAKind(int count) const;
    bool allSameSuit() const;
    int rankCount(rankEnum rank) const;
    PAcard cardAt(int index) const;
    PAcard& operator[](unsigned int index);
    friend std::ostream& operator <<(std::ostream& out, CardHand& cardHand);
};


#endif //HELLOSFML_CARDHAND_H
