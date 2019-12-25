//
// Created by arno on 25/12/2019.
//

#include "RocketPositionUpdated.h"

spaceinvaders::event::RocketPositionUpdated::RocketPositionUpdated(
        const std::shared_ptr<spaceinvaders::model::RocketModel> &rocket) : rocket(rocket) {}

const std::shared_ptr<spaceinvaders::model::RocketModel> &
spaceinvaders::event::RocketPositionUpdated::getRocket() const {
    return rocket;
}
