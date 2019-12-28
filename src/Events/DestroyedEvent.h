//
// Created by arno on 25/12/2019.
//

#ifndef SPACEINVADERS_DESTROYEDEVENT_H
#define SPACEINVADERS_DESTROYEDEVENT_H


#include <memory>
#include "Event.h"

namespace spaceinvaders::model {
    class MovingEntity;
}
namespace spaceinvaders::event {
    class DestroyedEvent : public Event {
    public:
        explicit DestroyedEvent(std::shared_ptr<spaceinvaders::model::MovingEntity> entity);

    private:
        std::shared_ptr<spaceinvaders::model::MovingEntity> entity;
    public:
        [[nodiscard]] const std::shared_ptr<spaceinvaders::model::MovingEntity> &getEntity() const;
    };
}


#endif //SPACEINVADERS_DESTROYEDEVENT_H
