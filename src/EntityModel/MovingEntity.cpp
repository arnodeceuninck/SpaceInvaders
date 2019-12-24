//
// Created by arno on 24/12/2019.
//

#include "MovingEntity.h"

double spaceinvaders::model::MovingEntity::getWidth() const {
    return width;
}

void spaceinvaders::model::MovingEntity::setWidth(double width) {
    MovingEntity::width = width;
}

double spaceinvaders::model::MovingEntity::getHeight() const {
    return height;
}

void spaceinvaders::model::MovingEntity::setHeight(double height) {
    MovingEntity::height = height;
}


double spaceinvaders::model::MovingEntity::getSpeed() const {
    return speed;
}

void spaceinvaders::model::MovingEntity::setSpeed(double speed) {
    MovingEntity::speed = speed;
}

const spaceinvaders::Coordinate &spaceinvaders::model::MovingEntity::getSpeedDirection() const {
    return speedDirection;
}

void spaceinvaders::model::MovingEntity::setSpeedDirection(const spaceinvaders::Coordinate &speedDirection) {
    MovingEntity::speedDirection = speedDirection;
}

spaceinvaders::Coordinate &spaceinvaders::model::MovingEntity::getPosition() {
    return position;
}

void spaceinvaders::model::MovingEntity::setPosition(const spaceinvaders::Coordinate &position) {
    MovingEntity::position = position;
}

spaceinvaders::model::MovingEntity::MovingEntity(double width, double height, double speed,
                                                 const spaceinvaders::Coordinate &speedDirection,
                                                 const spaceinvaders::Coordinate &position) : width(width),
                                                                                              height(height),
                                                                                              speed(speed),
                                                                                              speedDirection(
                                                                                                      speedDirection),
                                                                                              position(position) {}
