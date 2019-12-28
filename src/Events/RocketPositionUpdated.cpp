//
// Created by arno on 25/12/2019.
//

#include "RocketPositionUpdated.h"

#include <utility>

spaceinvaders::event::RocketPositionUpdated::RocketPositionUpdated(
        std::shared_ptr<spaceinvaders::model::RocketModel> rocket) : rocket(std::move(rocket)) {}

const std::shared_ptr<spaceinvaders::model::RocketModel> &
spaceinvaders::event::RocketPositionUpdated::getRocket() const {
    return rocket;
}
