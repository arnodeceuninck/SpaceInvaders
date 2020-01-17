//
// Created by arno on 24/12/2019.
//

#ifndef SPACEINVADERS_ENTITYCREATEDEVENT_H
#define SPACEINVADERS_ENTITYCREATEDEVENT_H

#include "../EntityModel/EntityModel.h"
#include "Event.h"
#include <memory>

namespace spaceinvaders::event {
class EntityCreatedEvent : public Event
{
private:
        std::shared_ptr<spaceinvaders::model::EntityModel> entity;
        std::string prefferedSprite;

public:
        /**
         * Get the created entity
         * @return the entity
         */
        [[nodiscard]] const std::shared_ptr<spaceinvaders::model::EntityModel>& getEntity() const;

        /**
         * Get the preferred sprite
         * @return The sprite file specified in the .json
         */
        [[nodiscard]] const std::string& getPrefferedSprite() const;

        /**
         * Notify observers an entity has been created
         * @param entity The created entity
         * @param prefferedSprite The sprite specified in the json file
         */
        EntityCreatedEvent(std::shared_ptr<spaceinvaders::model::EntityModel> entity, std::string prefferedSprite);

        /**
         * Notify an event has been created
         * @param entity The created entity
         */
        explicit EntityCreatedEvent(std::shared_ptr<spaceinvaders::model::EntityModel> entity);
};
} // namespace spaceinvaders::event

#endif // SPACEINVADERS_ENTITYCREATEDEVENT_H
