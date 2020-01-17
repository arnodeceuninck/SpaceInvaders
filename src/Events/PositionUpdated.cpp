//
// Created by arno on 27/12/2019.
//

#include "PositionUpdated.h"

const spaceinvaders::Coordinate &spaceinvaders::event::PositionUpdated::getNewPosition() const { return newPosition; }

spaceinvaders::event::PositionUpdated::PositionUpdated(const spaceinvaders::Coordinate &newPosition)
        : newPosition(newPosition) {
}
