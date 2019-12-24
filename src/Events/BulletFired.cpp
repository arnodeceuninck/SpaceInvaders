//
// Created by arno on 24/12/2019.
//

#include "BulletFired.h"

spaceinvaders::event::BulletFired::BulletFired(const std::shared_ptr<spaceinvaders::model::RocketModel> &rocket)
        : rocket(rocket) {}

const std::shared_ptr<spaceinvaders::model::RocketModel> &spaceinvaders::event::BulletFired::getRocket() const {
    return rocket;
}
