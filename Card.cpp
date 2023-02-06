//
// Created by Felicia Chen on 10/25/22.
//

#include "Card.h"

sf::Texture Card::texture;
sf::Font Card::font;

Card::Card() : Card(HEARTS, ACE)
{

}

Card::Card(suitEnum suit, rankEnum rank)
: _suit(suit), _rank(rank)
{
    initialize();
}

std::string Card::rankToString() {
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

std::string Card::suitToString() {
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
            break;
    }
}

void Card::initialize()
{
    setupBackground();
    setupRank();
    setupSuit();
}

void Card::setupRank() {
    if(!font.loadFromFile("fonts/Roboto-Medium.ttf"))
        exit(20);
    rank1.setFont(font);
    rank2.setFont(font);

    rank1.setString(rankToString());
    rank2.setString(rankToString());

    rank1.setCharacterSize(background.getSize().x - 205);
    rank2.setCharacterSize(background.getSize().x - 205);

    if(_suit == HEARTS || _suit == DIAMONDS)
    {
        rank1.setFillColor(sf::Color::Red);
        rank2.setFillColor(sf::Color::Red);
    }
    else
    {
        rank1.setFillColor(sf::Color::Black);
        rank2.setFillColor(sf::Color::Black);
    }

    rank1.setPosition({background.getPosition().x+10, background.getPosition().y+7});
    rank2.setPosition({background.getPosition().x+240, background.getPosition().y+350});

    rank2.setRotation(180);
}

void Card::setupSuit() {
    if(!texture.loadFromFile(suitToString()))
        exit(21);
    suit.setTexture(texture);
    suit.setPosition({background.getPosition().x + 75, background.getPosition().y + 125});
    suit.setScale({.2,.2});
}

void Card::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(background);
    window.draw(suit);
    window.draw(rank1);
    window.draw(rank2);
}

void Card::setupBackground() {
    background.setSize({250,350});
    background.setPosition({200,75});
}