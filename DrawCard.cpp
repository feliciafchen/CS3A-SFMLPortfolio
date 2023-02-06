//
// Created by Felicia Chen on 11/2/22.
//

#include "DrawCard.h"

sf::Font DrawCard::font;

DrawCard::DrawCard() : DrawCard(SPADES, ACE)
{

}

DrawCard::DrawCard(suitEnum suit, rankEnum rank)
: card(suit, rank)
{
    initialize();
}

std::string DrawCard::rankToString() {
    switch(card.getRankInt())
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
            return std::to_string(card.getRankInt()+1);
    }
}

std::string DrawCard::suitToString() {
    switch(card.getSuitInt())
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

void DrawCard::initialize()
{
    setupBackground();
    setupRank();
    setupSuit();
}

void DrawCard::setupRank() {
    if(!font.loadFromFile("fonts/Roboto-Medium.ttf"))
        exit(20);
    rank1.setFont(font);
    rank2.setFont(font);

    rank1.setString(rankToString());
    rank2.setString(rankToString());

    rank1.setCharacterSize(background.getSize().x/5.5);
    rank2.setCharacterSize(background.getSize().x/5.5);

    if(card.getSuitInt() == HEARTS || card.getSuitInt() == DIAMONDS)
    {
        rank1.setFillColor(sf::Color(163,25,25));
        rank2.setFillColor(sf::Color(163,25,25));
    }
    else
    {
        rank1.setFillColor(sf::Color::Black);
        rank2.setFillColor(sf::Color::Black);
    }


    rank1.setPosition({background.getSize().x/25 + background.getPosition().x, background.getSize().y/50 + background.getPosition().y});
    rank2.setPosition({background.getSize().x*24/25 + background.getPosition().x, background.getSize().y + background.getPosition().y});

    rank2.setRotation(180);
}

void DrawCard::setupSuit() {
    if(!texture.loadFromFile(suitToString()))
        exit(21);
    suit.setTexture(texture);
    suit.setScale({background.getSize().x/1250,background.getSize().x/1250});
    suit.setPosition({(background.getSize().x/2)-(suit.getTexture()->getSize().x * suit.getScale().x)/2,
                      (background.getSize().y/2)-(suit.getTexture()->getSize().y * suit.getScale().y)/2});
}

void DrawCard::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    states.transform = getTransform();
    window.draw(background, states);
    window.draw(suit, states);
    window.draw(rank1, states);
    window.draw(rank2, states);
}

void DrawCard::setupBackground() {
    background.setSize({250,static_cast<float>(background.getSize().x * 1.4)});
    background.setPosition(100, 100);
}

void DrawCard::setSize(float size) {
    background.setSize({size,static_cast<float>(size * 1.4)});
    suit.setScale({background.getSize().x/1250,background.getSize().x/1250});

    float suitWidth = suit.getTexture()->getSize().x * suit.getScale().x;
    float suitHeight = suit.getTexture()->getSize().y * suit.getScale().y;

    suit.setPosition({((background.getSize().x/2)-(suitWidth/2)) + background.getPosition().x,
                      (background.getSize().y/2)-(suitHeight/2) + background.getPosition().y});

    rank1.setCharacterSize(background.getSize().x/5.5);
    rank1.setPosition({background.getSize().x/25 + background.getPosition().x, background.getSize().y/50 + background.getPosition().y});

    rank2.setCharacterSize(background.getSize().x/5.5);
    rank2.setPosition({background.getSize().x*24/25 + background.getPosition().x, background.getSize().y + background.getPosition().y});
}

void DrawCard::setPosition(sf::Vector2f position) {
   sf::Transformable::setPosition(position);
}

sf::Vector2f DrawCard::getSize() {
    sf::Vector2f size = {background.getSize().x, static_cast<float>(background.getSize().x * 1.4)};
    return size;
}

sf::Vector2f DrawCard::getPosition() {
    return background.getPosition();
}

