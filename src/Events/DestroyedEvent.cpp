//
// Created by arno on 25/12/2019.
//

#include "DestroyedEvent.h"

#include <utility>

const std::shared_ptr<spaceinvaders::model::MovingEntity> &spaceinvaders::event::DestroyedEvent::getEntity() const {
    return entity;
}

spaceinvaders::event::DestroyedEvent::DestroyedEvent(std::shared_ptr<spaceinvaders::model::MovingEntity> entity)
        : entity(std::move(entity)) {}
