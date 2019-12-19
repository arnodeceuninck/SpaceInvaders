//
// Created by arno on 14/12/2019.
//

#include "GameModel.h"

void spaceinvaders::model::GameModel::update(double elapsedSeconds) {

}

const std::shared_ptr<spaceinvaders::Dimensions> &spaceinvaders::model::GameModel::getDimensions() const {
    return dimensions;
}

void spaceinvaders::model::GameModel::handleEvent(std::shared_ptr<spaceinvaders::Event> &event) {
    // std::cout << "Event received" << std::endl;
}
