//
// Created by arno on 14/12/2019.
//

#include "GameRepresentation.h"
#include "BackgroundTiles.h"
#include "SFML/Graphics.hpp"

spaceinvaders::view::GameRepresentation::GameRepresentation() : EntityRepresentation(
        std::make_shared<GameWindow>(800, 600)) {

    BackgroundTiles background{"res/Background.jpg", getWindow()};
    background.draw();
}

void spaceinvaders::view::GameRepresentation::checkEvent() {
    sf::Event event;
//    while (window->pollEvent(event)){
//        // Notify the observers of this event
//    };
}

void spaceinvaders::view::GameRepresentation::checkInput() {
    getWindow()->checkInput();
}

void spaceinvaders::view::GameRepresentation::handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) {
    EntityRepresentation::handleEvent(event);
}

void spaceinvaders::view::GameRepresentation::draw() {

}
