//
// Created by arno on 14/12/2019.
//

#include "PlayerShip.h"
#include "../Events/EnemyPositionUpdated.h"
#include "../Events/GameEnded.h"

spaceinvaders::model::PlayerShip::PlayerShip() : Ship(0, -2.5) {}

void spaceinvaders::model::PlayerShip::handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) {
    if (auto pu = std::dynamic_pointer_cast<spaceinvaders::event::EnemyPositionUpdated>(event)) {
        if (isCollision(pu->getNewFront()) // in case you've hit the ship
            or getPosition().getY() >
               pu->getNewFront()
                       .getY()) { // in case the ship was next to you, didn't hit you, but went on your level
            MovingEntity::selfDestroy();
        }
    }
    Ship::handleEvent(event);
}

spaceinvaders::Coordinate spaceinvaders::model::PlayerShip::getShootingDirection() { return Coordinate(0, 1); }

spaceinvaders::Coordinate spaceinvaders::model::PlayerShip::getShipFront() {
    return Coordinate(getPosition().getX(), getPosition().getY() + getHeight() / 2);
}
