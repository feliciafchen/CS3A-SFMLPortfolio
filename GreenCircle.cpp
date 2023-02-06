//
// Created by Felicia Chen on 12/14/22.
//

#include "GreenCircle.h"

GreenCircle::GreenCircle() {
    shape.setRadius(100.f);
    shape.setPosition(100.f, 100.f);
    shape.setFillColor(sf::Color::Green);
    enableState(HIDDEN);
}

void GreenCircle::update(sf::RenderWindow& window) {
    if(!checkState(HIDDEN))
        window.draw(shape);
}
