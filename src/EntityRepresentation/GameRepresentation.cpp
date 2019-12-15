//
// Created by arno on 14/12/2019.
//

#include "GameRepresentation.h"
#include <SFML/Graphics.hpp>


spaceinvaders::view::GameRepresentation::GameRepresentation() {
    window = std::make_shared<sf::RenderWindow>(sf::VideoMode(512, 256), "Space Invaders");
}

void spaceinvaders::view::GameRepresentation::checkEvent() {
    sf::Event event;
//    while (window->pollEvent(event)){
//        // Notify the observers of this event
//    };
}
