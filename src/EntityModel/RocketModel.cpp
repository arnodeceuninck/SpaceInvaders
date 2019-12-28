//
// Created by arno on 24/12/2019.
//

#include "RocketModel.h"
#include "../Events/RocketPositionUpdated.h"

spaceinvaders::model::RocketModel::RocketModel(const spaceinvaders::Coordinate &speedDirection,
                                               const spaceinvaders::Coordinate &position) : MovingEntity(speedDirection,
                                                                                                         position),
                                                                                            damage(damage) {}

void spaceinvaders::model::RocketModel::update(double elapsedSeconds) {
    MovingEntity::update(elapsedSeconds);
    std::shared_ptr<MovingEntity> rocket = std::dynamic_pointer_cast<MovingEntity>(shared_from_this());
    std::shared_ptr<spaceinvaders::event::Event> event = std::make_shared<spaceinvaders::event::RocketPositionUpdated>(
            std::dynamic_pointer_cast<RocketModel>(rocket));
    notifyObservers(event);
}

spaceinvaders::Coordinate spaceinvaders::model::RocketModel::getTop() {
    return spaceinvaders::Coordinate(getPosition().getX(),
                                     getPosition().getY() + getSpeedDirection().getY() * getHeight() / 2);
}

double spaceinvaders::model::RocketModel::getDamage() const {
    return damage;
}

void spaceinvaders::model::RocketModel::setDamage(double damage) {
    RocketModel::damage = damage;
}

void spaceinvaders::model::RocketModel::selfDestroy(double bulletDamage) {
    if (bulletDamage == 0) {
        MovingEntity::selfDestroy();
    }
}
