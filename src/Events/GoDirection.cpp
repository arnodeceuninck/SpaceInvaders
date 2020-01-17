//
// Created by arno on 27/12/2019.
//

#include "GoDirection.h"

spaceinvaders::event::GoDirection::GoDirection(const spaceinvaders::Coordinate& direction) : direction(direction) {}

const spaceinvaders::Coordinate& spaceinvaders::event::GoDirection::getDirection() const { return direction; }
