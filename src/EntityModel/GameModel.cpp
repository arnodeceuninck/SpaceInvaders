//
// Created by arno on 14/12/2019.
//

#include "GameModel.h"
#include "../Loader/LevelLoader.h"
#include "WorldModel.h"

void spaceinvaders::model::GameModel::update(double elapsedSeconds) {
    gameWorld->update(elapsedSeconds);
}

const std::shared_ptr<spaceinvaders::Dimensions> &spaceinvaders::model::GameModel::getDimensions() const {
    return dimensions;
}

void spaceinvaders::model::GameModel::handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) {
    // std::cout << "Event received" << std::endl;
}

spaceinvaders::model::GameModel::GameModel() {
    gameWorld = std::make_shared<WorldModel>();
}

const std::shared_ptr<spaceinvaders::model::WorldModel> &spaceinvaders::model::GameModel::getGameWorld() const {
    return gameWorld;
}

void spaceinvaders::model::GameModel::gameLoop() {

}
