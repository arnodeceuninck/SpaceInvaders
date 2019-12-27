//
// Created by arno on 14/12/2019.
//

#include <iostream>
#include "GameModel.h"
#include "../Loader/LevelLoader.h"
#include "WorldModel.h"
#include "../Events/EntityCreatedEvent.h"

void spaceinvaders::model::GameModel::update(double elapsedSeconds) {
    gameWorld->update(elapsedSeconds);
}

const std::shared_ptr<spaceinvaders::Dimensions> &spaceinvaders::model::GameModel::getDimensions() const {
    return dimensions;
}

void spaceinvaders::model::GameModel::handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) {
    event->setHandledByGameModel(true);
    if (auto ec = std::dynamic_pointer_cast<spaceinvaders::event::EntityCreatedEvent>(event)) {
        std::cout << "Event received" << std::endl;
        notifyObservers(event);
    }
}

spaceinvaders::model::GameModel::GameModel() {
    gameWorld = std::make_shared<WorldModel>();
    addObserver(gameWorld);
}

const std::shared_ptr<spaceinvaders::model::WorldModel> &spaceinvaders::model::GameModel::getGameWorld() const {
    return gameWorld;
}

void spaceinvaders::model::GameModel::gameLoop() {

}
