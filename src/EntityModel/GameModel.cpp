//
// Created by arno on 14/12/2019.
//

#include "GameModel.h"
#include "../Events/EntityCreatedEvent.h"
#include "../Events/GameEnded.h"
#include "../Events/LevelEnded.h"
#include "../Events/LoadLevel.h"
#include "WorldModel.h"

void spaceinvaders::model::GameModel::update(double elapsedSeconds) { gameWorld->update(elapsedSeconds); }

const std::shared_ptr<spaceinvaders::Dimensions> &spaceinvaders::model::GameModel::getDimensions() const {
    return dimensions;
}

void spaceinvaders::model::GameModel::handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) {
    event->setHandledByGameModel(true);
    if (auto ec = std::dynamic_pointer_cast<spaceinvaders::event::EntityCreatedEvent>(event)) {
        //        std::cout << "Event received" << std::endl;
        notifyObservers(event);
    } else if (auto le = std::dynamic_pointer_cast<spaceinvaders::event::LevelEnded>(event)) {
        if (le->isWin()) {
            levels.pop();
        }
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

void spaceinvaders::model::GameModel::load() {
    if (levels.empty()) {
        std::shared_ptr<spaceinvaders::event::Event> event =
                std::make_shared<spaceinvaders::event::GameEnded>();
        notifyObservers(event);
    } else {
        //        gameWorld->reset();
        std::shared_ptr<spaceinvaders::event::Event> event =
                std::make_shared<spaceinvaders::event::LoadLevel>(levels.top());
        notifyObservers(event);
    }
}

void spaceinvaders::model::GameModel::addLevel(const std::string &level) { levels.push(level); }
