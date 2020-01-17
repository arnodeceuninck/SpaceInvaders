//
// Created by arno on 24/12/2019.
//

#include "EntityCreatedEvent.h"

#include <utility>

spaceinvaders::event::EntityCreatedEvent::EntityCreatedEvent(std::shared_ptr<spaceinvaders::model::EntityModel> entity)
    : entity(std::move(entity))
{
}

const std::shared_ptr<spaceinvaders::model::EntityModel>& spaceinvaders::event::EntityCreatedEvent::getEntity() const
{
        return entity;
}

spaceinvaders::event::EntityCreatedEvent::EntityCreatedEvent(std::shared_ptr<spaceinvaders::model::EntityModel> entity,
                                                             std::string prefferedSprite)
    : entity(std::move(entity)), prefferedSprite(std::move(prefferedSprite))
{
}

const std::string& spaceinvaders::event::EntityCreatedEvent::getPrefferedSprite() const { return prefferedSprite; }