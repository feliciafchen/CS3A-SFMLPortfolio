//
// Created by Felicia Chen on 10/30/22.
//

#include "PokerScore.h"
#include <iostream>

void PokerScore::operator+=(const Scores &score) {
    scores.push_back(score);
}

void PokerScore::operator+=(const PokerScore &score) {
    for (int i = 0; i < score.getSize(); ++i) {
        scores.push_back(score.scores[i]);
    }
}

Scores &PokerScore::operator[](unsigned int index) {
    return scores[index];
}

PokerScore::PokerScore() {

}

bool operator==(const PokerScore &p, Scores score) {
    for (int i = 0; i < p.scores.size(); ++i) {
        if (p.scores.at(i) == score)
            return true;
    }
    return false;
}

int PokerScore::getSize() const{
    return scores.size();
}

void PokerScore::fillArray() {
    score[0] = royalFlush;
    score[1] = straightFlush;
    score[2] = fourOfAKind;
    score[3] = fullHouse;
    score[4] = flush;
    score[5] = straight;
    score[6] = threeOfAKind;
    score[7] = twoPair;
    score[8] = onePair;
    score[9] = highCard;
}

int PokerScore::getScore(int index) {
    if(index > 9 || index < 0)
        exit(11);

    return score[index];
}

void PokerScore::analyze() {
    for (int i = 0; i < scores.size(); ++i) {
        if(scores[i] == ROYAL_FLUSH)
            royalFlush += 1;
        else if(scores[i] == STRAIGHT_FLUSH)
            straightFlush += 1;
        else if(scores[i] == FOUR_OF_A_KIND)
            fourOfAKind += 1;
        else if(scores[i] == FULL_HOUSE)
            fullHouse += 1;
        else if(scores[i] == FLUSH)
            flush += 1;
        else if(scores[i] == STRAIGHT)
            straight += 1;
        else if(scores[i] == THREE_OF_A_KIND)
            threeOfAKind += 1;
        else if(scores[i] == TWO_PAIR)
            twoPair += 1;
        else if(scores[i] == ONE_PAIR)
            onePair += 1;
        else if(scores[i] == HIGH_CARD)
            highCard += 1;
    }
}

std::ostream &operator<<(std::ostream &out, PokerScore &pokerScore) {
    pokerScore.analyze();
    pokerScore.fillArray();

    std::cout << "royal flush: " << pokerScore.getRoyalFlush() << std::endl;
    std::cout << "straight flush: " << pokerScore.getStraightFlush() << std::endl;
    std::cout << "four of a kind: " << pokerScore.getFourOfAKind() << std::endl;
    std::cout << "full house: " << pokerScore.getFullHouse() << std::endl;
    std::cout << "flush: " << pokerScore.getFlush() << std::endl;
    std::cout << "straight: " << pokerScore.getStraight() << std::endl;
    std::cout << "three of a kind: " << pokerScore.getThreeOfAKind() << std::endl;
    std::cout << "two pair: " << pokerScore.getTwoPair() << std::endl;
    std::cout << "one pair: " << pokerScore.getOnePair() << std::endl;
    std::cout << "high card: " << pokerScore.getHighCard() << std::endl;
    return out;
}

int PokerScore::getRoyalFlush() const {
    return royalFlush;
}

int PokerScore::getStraightFlush() const {
    return straightFlush;
}

int PokerScore::getFourOfAKind() const {
    return fourOfAKind;
}

int PokerScore::getFullHouse() const {
    return fullHouse;
}

int PokerScore::getFlush() const {
    return flush;
}

int PokerScore::getStraight() const {
    return straight;
}

int PokerScore::getThreeOfAKind() const {
    return threeOfAKind;
}

int PokerScore::getTwoPair() const {
    return twoPair;
}

int PokerScore::getOnePair() const {
    return onePair;
}

int PokerScore::getHighCard() const {
    return highCard;
}