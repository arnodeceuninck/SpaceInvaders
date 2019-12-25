//
// Created by arno on 14/12/2019.
//

#include <iostream>
#include "Ship.h"
#include "../Events/UpdateEvent.h"
#include "RocketModel.h"
#include "../Events/BulletFired.h"
#include "../Events/EntityCreatedEvent.h"

spaceinvaders::model::Ship::Ship(double x, double y) : MovingEntity(0, 0, 2, Coordinate(0, 0), Coordinate(x, y)) {

}

void spaceinvaders::model::Ship::update(double elapsedSeconds) {
    MovingEntity::update(elapsedSeconds);
    fireTimeout -= elapsedSeconds;
    if (getPosition().getX() > 4 - getWidth() / 2) {
        getPosition().setX(4 - getWidth() / 2);
    } else if (getPosition().getX() < -4 + getWidth() / 2) {
        getPosition().setX(-4 + getWidth() / 2);
    }
}

void spaceinvaders::model::Ship::fire() {
    if (readyToFire()) {
        auto rocket = std::make_shared<RocketModel>(0.3, 0.3, 2.0, getShootingDirection(), getShipFront());
        std::shared_ptr<spaceinvaders::event::Event> event = std::make_shared<spaceinvaders::event::BulletFired>(
                rocket);
        notifyObservers(event);

        std::shared_ptr<spaceinvaders::event::Event> entityCreatedEvent = std::make_shared<spaceinvaders::event::EntityCreatedEvent>(
                rocket);
        rocket->notifyObservers(entityCreatedEvent);

        fireTimeout = 2; // Wait 2 seconds before you can fire again
    }
}

void spaceinvaders::model::Ship::handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) {
    MovingEntity::handleEvent(event);
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

bool spaceinvaders::model::Ship::readyToFire() {
    return fireTimeout <= 0;
}
