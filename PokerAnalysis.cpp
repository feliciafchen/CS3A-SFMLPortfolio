//
// Created by Felicia Chen on 12/14/22.
//

#include "PokerAnalysis.h"

PokerAnalysis::PokerAnalysis(sf::RenderWindow& window) {
    PokerScore pokerScore;

    for (int i = 0; i < 10; ++i) {
        if(!font.loadFromFile("fonts/Roboto-Medium.ttf"))
            exit (10);
        this -> text[i].setFont(font);
        this -> text[i].setCharacterSize(50);
        this -> text[i].setString("1: " + std::to_string(650000/(static_cast<double>(pokerScore.getScore(i)))));
        this -> text[i].setFillColor(sf::Color::White);
    }

    float p1 = 0, p2 = 0;

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            this -> card[i][j].setPosition({p1,p2});
            this -> card[i][j].setSize(150);
            p1 += this -> card[i][j].getSize().x + 10;
        }
        this -> text[i].setPosition(p1 + 150, p2 + 175);
        p2 += 300;
        p1 = 0;
    }

    p1 = window.getSize().x/2, p2 = 0;

    for (int i = 5; i < 10; ++i) {
        for (int j = 0; j < 5; ++j) {
            this -> card[i][j].setSize(150);
            this -> card[i][j].setPosition({p1,p2});
            p1 += this -> card[i][j].getSize().x + 10;
        }
        this -> text[i].setPosition(p1 + 150, p2 + 175);
        p2 += 300;
        p1 = window.getSize().x/2;
    }

    enableState(HIDDEN);
}

void PokerAnalysis::update(sf::RenderWindow &window) {
    if(!checkState(HIDDEN))
    {
        window.clear(sf::Color(73, 99, 72));
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 5; ++j) {
                window.draw(this -> card[i][j]);
            }
            window.draw(this -> text[i]);
        }
    }
}