//
// Created by arno on 14/12/2019.
//

#include "GameRepresentation.h"
#include "BackgroundTiles.h"
#include "SFML/Graphics.hpp"

spaceinvaders::view::GameRepresentation::GameRepresentation() : window(std::make_shared<GameWindow>(800, 600)) {

    BackgroundTiles background{"res/Background.jpg"};
    background.draw(*window);
}

void spaceinvaders::view::GameRepresentation::checkEvent() {
    sf::Event event;
//    while (window->pollEvent(event)){
//        // Notify the observers of this event
//    };
}

void spaceinvaders::view::GameRepresentation::checkInput() {
    window->checkInput();
}

const std::shared_ptr<spaceinvaders::GameWindow> &spaceinvaders::view::GameRepresentation::getWindow() const {
    return window;
}

void spaceinvaders::view::GameRepresentation::handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) {

}
