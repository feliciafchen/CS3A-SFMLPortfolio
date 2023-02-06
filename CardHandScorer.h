//
// Created by Felicia Chen on 10/30/22.
//

#ifndef HELLOSFML_CARDHANDSCORER_H
#define HELLOSFML_CARDHANDSCORER_H
#include "CardHand.h"
#include "PokerScore.h"

class CardHandScorer {
public:
    static PokerScore scorePokerHand(CardHand cardHand);
private:
    static bool checkRoyalFlush(const CardHand& cardHand);
    static bool checkStraightFlush(const CardHand& cardHand);
    static bool checkFourOfAKind(const CardHand& cardHand);
    static bool checkFullHouse(const CardHand& cardHand);
    static bool checkFlush(const CardHand& cardHand);
    static bool checkStraight(const CardHand& cardHand);
    static bool checkThreeOfAKind(const CardHand& cardHand);
    static bool checkTwoPair(const CardHand& cardHand);
    static bool checkOnePair(const CardHand& cardHand);
    static bool checkHighCard(const CardHand& cardHand);
};


#endif //HELLOSFML_CARDHANDSCORER_H
