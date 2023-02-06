//
// Created by Felicia Chen on 10/25/22.
//

#include "PAcard.h"

PAcard::PAcard() : PAcard(HEARTS, ACE)
{

}

PAcard::PAcard(suitEnum suit, rankEnum rank)
: _suit(suit), _rank(rank)
{
}

std::string PAcard::rankToString() {
    switch(_rank)
    {
        case ACE:
            return "A";
        case JACK:
            return "J";
        case QUEEN:
            return "Q";
        case KING:
            return "K";
        default:
            return std::to_string(_rank+1);
    }
}

std::string PAcard::suitToString() {
    switch(_suit)
    {
        case DIAMONDS:
            return "images/diamonds.png";
        case CLUBS:
            return "images/clubs.png";
        case HEARTS:
            return "images/hearts.png";
        case SPADES:
            return "images/spades.png";
        default:
            std::cout << "cant do that\n";
            exit(10);
    }
}

rankEnum PAcard::getRankInt() const {
    return _rank;
}

void PAcard::setRank(rankEnum rank) {
    _rank = rank;
}

suitEnum PAcard::getSuitInt() const {
    return _suit;
}

void PAcard::setSuit(suitEnum suit) {
    _suit = suit;
}

std::string PAcard::getRank() const{

    switch(_rank)
    {
        case ACE:
            return "Ace";
        case TWO:
            return "Two";
        case THREE:
            return "Three";
        case FOUR:
            return "Four";
        case FIVE:
            return "Five";
        case SIX:
            return "Six";
        case SEVEN:
            return "Seven";
        case EIGHT:
            return "Eight";
        case NINE:
            return "Nine";
        case TEN:
            return "Ten";
        case JACK:
            return "Jack";
        case QUEEN:
            return "Queen";
        case KING:
            return "King";
        default:
            std::cout << "smt went wrong";
            exit(11);
    }
}

std::string PAcard::getSuit() const{
    switch(_suit)
    {
        case DIAMONDS:
            return "Diamonds";
        case CLUBS:
            return "Clubs";
        case HEARTS:
            return "Hearts";
        case SPADES:
            return "Spades";
        default:
            std::cout << "cant do that\n";
            exit(40);
    }
}

std::ostream &operator<<(std::ostream &out, const PAcard &card) {
    out << card.getRank() << "of" << card.getSuit();
    return out;
}
