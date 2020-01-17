//
// Created by arno on 25/12/2019.
//

#include "ShipController.h"
#include "../EntityModel/Ship.h"
#include "../Events/FireBullet.h"
#include "../Events/GoDirection.h"

void spaceinvaders::controller::ShipController::go(spaceinvaders::Coordinate coordinate) {
    std::shared_ptr<spaceinvaders::event::Event> event =
            std::make_shared<spaceinvaders::event::GoDirection>(coordinate);
    notifyObservers(event);
}

void spaceinvaders::controller::ShipController::fire() {
    std::shared_ptr<spaceinvaders::event::Event> event = std::make_shared<spaceinvaders::event::FireBullet>();
    notifyObservers(event);
}

spaceinvaders::controller::ShipController::ShipController() : EntityController() {}
