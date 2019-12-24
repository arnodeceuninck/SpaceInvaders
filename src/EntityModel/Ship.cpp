//
// Created by arno on 14/12/2019.
//

#include <iostream>
#include "Ship.h"
#include "../Events/UpdateEvent.h"
#include "RocketModel.h"

spaceinvaders::model::Ship::Ship(double x, double y) : MovingEntity(0, 0, 2, Coordinate(0, 0), Coordinate(x, y)) {

}


void spaceinvaders::model::Ship::update(double elapsedSeconds) {
    double distance = getSpeed() * elapsedSeconds;
    Coordinate directedDistance = getSpeedDirection() * distance;
    setPosition(getPosition() + directedDistance);
    if (getPosition().getX() > 4 - getWidth() / 2) {
        getPosition().setX(4 - getWidth() / 2);
    } else if (getPosition().getX() < -4 + getWidth() / 2) {
        getPosition().setX(-4 + getWidth() / 2);
    }
}

void spaceinvaders::model::Ship::fire() {
//    auto rocket = std::make_shared<RocketModel>(Coordinate(getPosition().getX(), getPosition().getY()+getHeight()/2));
}

void spaceinvaders::model::Ship::handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) {
    EntityModel::handleEvent(event);
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
