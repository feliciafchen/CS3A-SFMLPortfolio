//
// Created by Felicia Chen on 10/30/22.
//

#include "CardHand.h"

void CardHand::addCard(PAcard card) {
    cardHand.push_back(card);
    sort();
}

void CardHand::sort() {
    int i, j, min_idx;

    for (i = 0; i < cardHand.size()-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < cardHand.size(); j++)
            if (cardHand[j].getRankInt() < cardHand[min_idx].getRankInt())
            {
                min_idx = j;
            }
        if(min_idx!=i)
        {
            PAcard temp = cardHand[min_idx];
            cardHand[min_idx] = cardHand[i];
            cardHand[i] = temp;
        }
    }
}

PAcard CardHand::cardAt(int index) const{
    return cardHand[index];
}

CardHand::CardHand() {

}

int CardHand::getSize() const{
    return cardHand.size();
}

bool CardHand::containsCard(PAcard card) {
    for (int i = 0; i < cardHand.size(); ++i) {
        if(cardHand[i].getRankInt() == card.getRankInt()
            && cardHand[i].getSuitInt() == card.getSuitInt())
            return true;
    }
    return false;
}

bool CardHand::containsRank(rankEnum rank) const{
    for (int i = 0; i < cardHand.size(); ++i) {
        if(cardHand[i].getRankInt() == rank)
            return true;
    }
    return false;
}

bool CardHand::allSameSuit() const{
    for (int i = 0; i < cardHand.size()-1; ++i) {
        if(cardHand[i].getSuitInt() != cardHand[i+1].getSuitInt())
            return false;
    }
    return true;
}

bool CardHand::ofAKind(int count) const{
    int counter = 1;
    for (int i = 0; i < cardHand.size(); ++i) {
        if(cardHand[i].getRankInt() == cardHand[i+1].getRankInt())
            counter++;
    }

    return(counter >= count);
}

int CardHand::rankCount(rankEnum rank) const {
    int count = 0;
    for (int i = 0; i < cardHand.size(); ++i) {
        if(cardHand[i].getRankInt() == rank)
        {
            count++;
        }
    }

    return count;
}

PAcard &CardHand::operator[](unsigned int index) {
    return cardHand[index];
}


std::ostream &operator<<(std::ostream &out, CardHand &cardHand) {
    for (int i = 0; i < cardHand.getSize(); ++i) {
        std::cout << i+1 << ": " << cardHand[i].getRank() << " of " << cardHand[i].getSuit() << std::endl;
    }
    return out;
}

