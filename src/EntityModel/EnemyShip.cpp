//
// Created by arno on 14/12/2019.
//

#include "EnemyShip.h"

spaceinvaders::model::EnemyShip::EnemyShip(double x, double y) : Ship(x, y) {}

void spaceinvaders::model::EnemyShip::handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) {
    Ship::handleEvent(event);
}

spaceinvaders::Coordinate spaceinvaders::model::EnemyShip::getShootingDirection() {
    return Coordinate(0, -1);
}

spaceinvaders::Coordinate spaceinvaders::model::EnemyShip::getShipFront() {
    return Coordinate(getPosition().getX(),
                      getPosition().getY() -
                      getHeight() / 2);
}

