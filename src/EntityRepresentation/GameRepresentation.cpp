//
// Created by arno on 14/12/2019.
//

#include "GameRepresentation.h"
#include "BackgroundTiles.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>


spaceinvaders::view::GameRepresentation::GameRepresentation() : window(GameWindow(800, 600)) {

    BackgroundTiles background{"res/BGTile.jpg"};
    background.draw(window);
}

void spaceinvaders::view::GameRepresentation::checkEvent() {
    sf::Event event;
//    while (window->pollEvent(event)){
//        // Notify the observers of this event
//    };
}

const spaceinvaders::view::GameWindow &spaceinvaders::view::GameRepresentation::getWindow() const {
    return window;
}
