//
// Created by arno on 25/12/2019.
//

#ifndef SPACEINVADERS_DESTROYEDEVENT_H
#define SPACEINVADERS_DESTROYEDEVENT_H

#include "Event.h"
#include <memory>

namespace spaceinvaders::model {
class MovingEntity;
}
namespace spaceinvaders::event {
class DestroyedEvent : public Event
{
public:
        /**
         * Notify an entity has been destroyed
         * @param entity The destroyed entity
         */
        explicit DestroyedEvent(std::shared_ptr<spaceinvaders::model::MovingEntity> entity);

        /**
         * Get the destroyed entity
         * @return the entity
         */
        [[nodiscard]] const std::shared_ptr<spaceinvaders::model::MovingEntity>& getEntity() const;

private:
        std::shared_ptr<spaceinvaders::model::MovingEntity> entity;
};
} // namespace spaceinvaders::event

#endif // SPACEINVADERS_DESTROYEDEVENT_H
