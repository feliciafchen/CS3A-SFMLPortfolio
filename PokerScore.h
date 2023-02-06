//
// Created by Felicia Chen on 10/30/22.
//

#ifndef HELLOSFML_POKERSCORE_H
#define HELLOSFML_POKERSCORE_H
#include "scoresEnum.h"
#include <vector>

class PokerScore {
private:
    std::vector<Scores> scores;
    int royalFlush = 0, straightFlush = 0, fourOfAKind = 0,
            fullHouse = 0, flush = 0, straight = 0, threeOfAKind = 0,
            twoPair = 0, onePair = 0, highCard = 0;
    int score[10];

public:
    PokerScore();
    void fillArray();
    void analyze();
    int getRoyalFlush() const;
    int getStraightFlush() const;
    int getFourOfAKind() const;
    int getFullHouse() const;
    int getFlush() const;
    int getStraight() const;
    int getThreeOfAKind() const;
    int getTwoPair() const;
    int getOnePair() const;
    int getHighCard() const;
    int getScore(int index);
    int getSize() const;
    void operator += (const Scores& score);
    void operator += (const PokerScore& score);
    friend bool operator ==(const PokerScore& p, Scores score);
    Scores& operator[](unsigned int index);
    friend std::ostream& operator <<(std::ostream& out, PokerScore& pokerScore);
};


#endif //HELLOSFML_POKERSCORE_H
