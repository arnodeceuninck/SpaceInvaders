//
// Created by arno on 14/12/2019.
//

#include "Ship.h"
#include "../Events/EntityCreatedEvent.h"
#include "../Events/FireBullet.h"
#include "../Events/UpdateEvent.h"
#include "../Loader/RocketLoader.h"
#include "RocketModel.h"
#include <iostream>

spaceinvaders::model::Ship::Ship(double x, double y) : MovingEntity(0, 0, 2, Coordinate(0, 0), Coordinate(x, y)) {}

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
        auto rocket = std::make_shared<RocketModel>(getShootingDirection(), getShipFront());
        spaceinvaders::loader::RocketLoader rocketLoader{bulletFile};
        std::string file;
        rocketLoader.loadInto(rocket, file);
        std::shared_ptr<spaceinvaders::event::Event> event =
                std::make_shared<spaceinvaders::event::EntityCreatedEvent>(rocket, file);
        notifyObservers(event);

        fireTimeout = timeBetweenFire; // Wait some seconds before you can fire again
    }
}

void spaceinvaders::model::Ship::handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) {
    MovingEntity::handleEvent(event);
    if (auto fireEvent = std::dynamic_pointer_cast<spaceinvaders::event::FireBullet>(event)) {
        fire();
    }
}

void spaceinvaders::model::Ship::setHealth(double health) { Ship::health = health; }

void spaceinvaders::model::Ship::selfDestroy(double bulletDamage) {
    health -= bulletDamage;
    if (health <= 0) {
        MovingEntity::selfDestroy();
    }
}

bool spaceinvaders::model::Ship::readyToFire() { return fireTimeout <= 0; }

double spaceinvaders::model::Ship::getTimeBetweenFire() const { return timeBetweenFire; }

void spaceinvaders::model::Ship::setTimeBetweenFire(double timeBetweenFire) { Ship::timeBetweenFire = timeBetweenFire; }

void spaceinvaders::model::Ship::setBulletFile(const std::string &bulletFile) { Ship::bulletFile = bulletFile; }
