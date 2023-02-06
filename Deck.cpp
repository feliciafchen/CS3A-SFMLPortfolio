//
// Created by Felicia Chen on 10/29/22.
//

#include "Deck.h"


Deck::Deck() {
    int a = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 13; ++j) {
            deck[a] = PAcard(suitEnum(i), rankEnum(j));
            a++;
        }
    }

    shuffle();
}

void Deck::shuffle() {
    PAcard temp;
    for (int i = 0; i < DECK_SIZE; ++i) {
        int a = rand() % 52;
        temp = deck[i];
        deck[i] = deck[a];
        deck[a] = temp;
    }
}

PAcard Deck::dealCard() {
    if(getCardIndex() >= 52)
    {
        std::cout << "No more cards in deck.\n";
        exit(0);
    }
    return deck[cardIndex++];
}

PAcard Deck::getCardAt(int index) const{
    return deck[index];
}


std::ostream &operator<<(std::ostream &out, const Deck &deck) {
    for (int i = 0; i < deck.DECK_SIZE; ++i) {
        out << i+1 << ": " << deck.getCardAt(i).getRank() << " of " << deck.getCardAt(i).getSuit() << std::endl;
    }
    return out;
}

int Deck::getCardIndex() {
    return cardIndex;
}
