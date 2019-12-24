//
// Created by arno on 24/12/2019.
//

#include "EntityCreatedEvent.h"

spaceinvaders::event::EntityCreatedEvent::EntityCreatedEvent(
        const std::shared_ptr<spaceinvaders::model::EntityModel> &entity) : entity(entity) {}

const std::shared_ptr<spaceinvaders::model::EntityModel> &spaceinvaders::event::EntityCreatedEvent::getEntity() const {
    return entity;
}
