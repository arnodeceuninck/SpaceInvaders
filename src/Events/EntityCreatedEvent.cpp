//
// Created by arno on 24/12/2019.
//

#include "EntityCreatedEvent.h"

spaceinvaders::event::EntityCreatedEvent::EntityCreatedEvent(
        const std::shared_ptr<spaceinvaders::model::EntityModel> &entity) : entity(entity) {}

const std::shared_ptr<spaceinvaders::model::EntityModel> &spaceinvaders::event::EntityCreatedEvent::getEntity() const {
    return entity;
}

spaceinvaders::event::EntityCreatedEvent::EntityCreatedEvent(
        const std::shared_ptr<spaceinvaders::model::EntityModel> &entity, const std::string &prefferedSprite) : entity(
        entity), prefferedSprite(prefferedSprite) {}

const std::string &spaceinvaders::event::EntityCreatedEvent::getPrefferedSprite() const {
    return prefferedSprite;
}
