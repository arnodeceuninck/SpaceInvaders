//
// Created by arno on 14/12/2019.
//

#include <SFML/Window/Event.hpp>
#include "GameController.h"

namespace spaceinvaders::controller {
    void GameController::update() {
        sf::Event event;
    }

    void GameController::addObserver(std::shared_ptr<observer::Observer> observer) {

    }

    void GameController::removeObserver(std::shared_ptr<observer::Observer> observer) {

    }

    void GameController::notifyObservers() {

    }
}