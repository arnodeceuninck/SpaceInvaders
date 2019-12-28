//
// Created by arno on 14/12/2019.
//

#include "PlayerShip.h"


spaceinvaders::model::PlayerShip::PlayerShip() : Ship(0, -2.5) {}

void spaceinvaders::model::PlayerShip::handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) {
    Ship::handleEvent(event);
}

spaceinvaders::Coordinate spaceinvaders::model::PlayerShip::getShootingDirection() {
    return Coordinate(0, 1);
}

spaceinvaders::Coordinate spaceinvaders::model::PlayerShip::getShipFront() {
    return Coordinate(getPosition().getX(),
                      getPosition().getY() +
                      getHeight() / 2);
}
