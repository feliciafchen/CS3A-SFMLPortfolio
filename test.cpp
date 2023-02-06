//
// Created by Felicia Chen on 11/2/22.
//

#include "test.h"
#include <cstdlib>

PokerScore testPokerScore() {

    Deck deck;
    deck.shuffle();

    CardHand ch1;

    for (int i = 0; i < 5; ++i) {
        ch1.addCard(deck.dealCard());
    }
    PokerScore pokerScore = CardHandScorer::scorePokerHand(ch1);

    return pokerScore;
}
