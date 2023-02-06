//
// Created by Felicia Chen on 10/30/22.
//

#include "CardHandScorer.h"

PokerScore CardHandScorer::scorePokerHand(CardHand cardHand) {
    PokerScore pokerScore;

    if(checkRoyalFlush(cardHand))
        pokerScore += ROYAL_FLUSH;

    if(checkStraightFlush(cardHand))
        pokerScore += STRAIGHT_FLUSH;

    if(checkFourOfAKind(cardHand))
        pokerScore += FOUR_OF_A_KIND;

    if(checkFullHouse(cardHand))
        pokerScore += FULL_HOUSE;

    if(checkFlush(cardHand))
        pokerScore += FLUSH;

    if(checkStraight(cardHand))
        pokerScore += STRAIGHT;

    if(checkThreeOfAKind(cardHand))
        pokerScore += THREE_OF_A_KIND;

    if(checkTwoPair(cardHand))
        pokerScore += TWO_PAIR;

    if(checkOnePair(cardHand))
        pokerScore += ONE_PAIR;

    if(checkHighCard(cardHand))
        pokerScore += HIGH_CARD;

    return pokerScore;
}

bool CardHandScorer::checkRoyalFlush(const CardHand &cardHand) {
    return(cardHand.allSameSuit() && cardHand.containsRank(ACE)
    && cardHand.containsRank(KING) && cardHand.containsRank(QUEEN)
    && cardHand.containsRank(JACK) && cardHand.containsRank(TEN));
}

bool CardHandScorer::checkStraightFlush(const CardHand &cardHand) {
    return(cardHand.allSameSuit() && checkStraight(cardHand));
}

bool CardHandScorer::checkFourOfAKind(const CardHand &cardHand) {
    return(cardHand.ofAKind(4));
}

bool CardHandScorer::checkFullHouse(const CardHand &cardHand) {
    bool first2same = cardHand.cardAt(0).getRankInt() == cardHand.cardAt(1).getRankInt();
    bool first3same = (cardHand.cardAt(0).getRankInt() == cardHand.cardAt(1).getRankInt()) &&
            (cardHand.cardAt(0).getRankInt() == cardHand.cardAt(2).getRankInt());

    bool last2same = cardHand.cardAt(3).getRankInt() == cardHand.cardAt(4).getRankInt();
    bool last3same = (cardHand.cardAt(2).getRankInt() == cardHand.cardAt(3).getRankInt()) &&
                      (cardHand.cardAt(3).getRankInt() == cardHand.cardAt(4).getRankInt());

    return(first2same && last3same || first3same && last2same);
}

bool CardHandScorer::checkFlush(const CardHand &cardHand) {
    return (cardHand.allSameSuit());
}

bool CardHandScorer::checkStraight(const CardHand &cardHand) {
    for (int i = 0; i < cardHand.getSize()-1; ++i) {
        if(cardHand.cardAt(i).getRankInt() != cardHand.cardAt(i+1).getRankInt() - 1)
            return false;
    }

    return true;
}

bool CardHandScorer::checkThreeOfAKind(const CardHand &cardHand) {
    return(cardHand.ofAKind(3));
}

bool CardHandScorer::checkTwoPair(const CardHand &cardHand) {
    int counter = 0;
    for (int i = 0; i < cardHand.getSize()-1; ++i) {
        if(cardHand.cardAt(i).getRankInt() == cardHand.cardAt(i+1).getRankInt())
        {
            counter++;
            i++;
        }
    }

    return(counter >= 2);
}

bool CardHandScorer::checkOnePair(const CardHand &cardHand) {
    return(cardHand.ofAKind(2));
}

bool CardHandScorer::checkHighCard(const CardHand &cardHand) {
    if(cardHand.getSize() > 0)
        return true;

    return false;
}
