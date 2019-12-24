//
// Created by arno on 14/12/2019.
//

#include <iostream>
#include "Ship.h"
#include "../Events/UpdateEvent.h"

double spaceinvaders::model::Ship::getWidth() const {
    return width;
}

void spaceinvaders::model::Ship::setWidth(double width) {
    Ship::width = width;
}

double spaceinvaders::model::Ship::getHeight() const {
    return height;
}

void spaceinvaders::model::Ship::setHeight(double height) {
    Ship::height = height;
}

double spaceinvaders::model::Ship::getHealth() const {
    return health;
}

void spaceinvaders::model::Ship::setHealth(double health) {
    Ship::health = health;
}

double spaceinvaders::model::Ship::getDamage() const {
    return damage;
}

void spaceinvaders::model::Ship::setDamage(double damage) {
    Ship::damage = damage;
}


const spaceinvaders::Coordinate &spaceinvaders::model::Ship::getPosition() const {
    return position;
}

spaceinvaders::model::Ship::Ship(double x, double y) : position(Coordinate(x, y)), speedDirection(Coordinate(0, 0)),
                                                       speed(2) {

}

const spaceinvaders::Coordinate &spaceinvaders::model::Ship::getSpeedDirection() const {
    return speedDirection;
}

double spaceinvaders::model::Ship::getSpeed() const {
    return speed;
}

void spaceinvaders::model::Ship::setSpeed(double speed) {
    Ship::speed = speed;
}

void spaceinvaders::model::Ship::setSpeedDirection(const spaceinvaders::Coordinate &speedDirection) {
    Ship::speedDirection = speedDirection;
}

void spaceinvaders::model::Ship::setPosition(const spaceinvaders::Coordinate &position) {
    Ship::position = position;
}

void spaceinvaders::model::Ship::update(double elapsedSeconds) {
    double distance = speed * elapsedSeconds;
    Coordinate directedDistance = speedDirection * distance;
    position += directedDistance;
    if (position.getX() > 4 - getWidth() / 2) {
        position.setX(4 - getWidth() / 2);
    } else if (position.getX() < -4 + getWidth() / 2) {
        position.setX(-4 + getWidth() / 2);
    }
}

void spaceinvaders::model::Ship::handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) {
    EntityModel::handleEvent(event);
}
