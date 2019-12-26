//
// Created by arno on 24/12/2019.
//

#include "RocketModel.h"
#include "../Events/RocketPositionUpdated.h"

spaceinvaders::model::RocketModel::RocketModel(double width, double height, double speed,
                                               const spaceinvaders::Coordinate &speedDirection,
                                               const spaceinvaders::Coordinate &position) : MovingEntity(width, height,
                                                                                                         speed,
                                                                                                         speedDirection,
                                                                                                         position) {}

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
