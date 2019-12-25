//
// Created by arno on 24/12/2019.
//

#include <iostream>
#include "MovingEntity.h"
#include "../Events/RocketPositionUpdated.h"
#include "RocketModel.h"
#include "../Events/DestroyedEvent.h"

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

void spaceinvaders::model::MovingEntity::update(double elapsedSeconds) {
    double distance = getSpeed() * elapsedSeconds;
    Coordinate directedDistance = getSpeedDirection() * distance;
    setPosition(getPosition() + directedDistance);
}

void spaceinvaders::model::MovingEntity::handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) {
    EntityModel::handleEvent(event);
    if (auto rpu = std::dynamic_pointer_cast<spaceinvaders::event::RocketPositionUpdated>(event)) {
        Coordinate rocketTop{rpu->getRocket()->getTop()};
        if (rocketTop.getX() > getPosition().getX() - getWidth() / 2 &&
            rocketTop.getX() < getPosition().getX() + getWidth() / 2 &&
            rocketTop.getY() > getPosition().getY() - getHeight() / 2 &&
            rocketTop.getY() < getPosition().getY() + getHeight() / 2) {
            std::cout << "COLISSSSIOOOOOOOOOOOOOOOOOOOON" << std::endl;
            selfDestroy();
        }

    }
}

void spaceinvaders::model::MovingEntity::selfDestroy() {
    std::shared_ptr<MovingEntity> me = shared_from_this();
    std::shared_ptr<spaceinvaders::event::Event> event = std::make_shared<spaceinvaders::event::DestroyedEvent>(me);
}
