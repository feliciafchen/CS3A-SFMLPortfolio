//
// Created by Felicia Chen on 12/14/22.
//

#ifndef SHOOTA_SHOOTAGAME_H
#define SHOOTA_SHOOTAGAME_H
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Player.h"
#include <cstdlib>
#include "Bullet.h"
#include "Mobs.h"
#include "ListItem.h"
#include "Games.h"

class ShootaGame : public States, public Games{
private:
    ListItem restart;
    sf::Sprite grass;
    Player player;
    Mobs mobs;
    sf::Text score;
    void restartShoota(sf::Vector2u window);
public:
    ShootaGame(sf::RenderWindow& window);
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update(sf::RenderWindow& window);
};

#endif //SHOOTA_SHOOTAGAME_H
