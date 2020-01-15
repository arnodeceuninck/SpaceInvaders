//
// Created by arno on 15/01/2020.
//

#include "EnemyPositionUpdated.h"

spaceinvaders::event::EnemyPositionUpdated::EnemyPositionUpdated(const spaceinvaders::Coordinate &newFront) : newFront(
        newFront) {}

const spaceinvaders::Coordinate &spaceinvaders::event::EnemyPositionUpdated::getNewFront() const {
    return newFront;
}
