//
// Created by Felicia Chen on 10/25/22.
//

#ifndef HELLOSFML_PACARD_H
#define HELLOSFML_PACARD_H

#include <iostream>
#include "SFML/Graphics.hpp"
#include "rankEnum.h"
#include "suitEnum.h"

class PAcard
{
private:
    rankEnum _rank;
    suitEnum _suit;
    std::string rankToString();
    std::string suitToString();
public:
    PAcard();
    PAcard(suitEnum suit, rankEnum rank);
    rankEnum getRankInt() const;
    void setRank(rankEnum rank);
    suitEnum getSuitInt() const;
    void setSuit(suitEnum suit);
    std::string getRank() const;
    std::string getSuit() const;
    friend std::ostream& operator <<(std::ostream& out, const PAcard& card);
};

#endif //HELLOSFML_PACARD_H
