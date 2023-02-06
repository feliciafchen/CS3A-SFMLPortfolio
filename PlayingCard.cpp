//
// Created by Felicia Chen on 12/14/22.
//
#include "PlayingCard.h"

PlayingCard::PlayingCard() {
    Card card(HEARTS, TWO);
    this -> card = card;

    enableState(HIDDEN);
}

void PlayingCard::update(sf::RenderWindow &window) {
    if(!checkState(HIDDEN))
    {
        window.clear();
        window.draw(card);
    }
}