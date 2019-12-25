//
// Created by arno on 25/12/2019.
//

#include "ShipController.h"
#include "../EntityModel/Ship.h"

void spaceinvaders::controller::ShipController::go(spaceinvaders::Coordinate coordinate) {
    if (auto ship = std::dynamic_pointer_cast<spaceinvaders::model::Ship>(getModel())) {
        ship->setSpeedDirection(coordinate);
    }
}

void spaceinvaders::controller::ShipController::fire() {
    if (auto ship = std::dynamic_pointer_cast<spaceinvaders::model::Ship>(getModel())) {
        ship->fire();
    }
}

spaceinvaders::controller::ShipController::ShipController(
        const std::shared_ptr<spaceinvaders::model::EntityModel> &model) : EntityController(model) {}
