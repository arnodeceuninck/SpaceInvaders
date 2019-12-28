//
// Created by arno on 24/12/2019.
//

#ifndef SPACEINVADERS_ENTITYCREATEDEVENT_H
#define SPACEINVADERS_ENTITYCREATEDEVENT_H

#include <memory>
#include "Event.h"
#include "../EntityModel/EntityModel.h"

namespace spaceinvaders::event {
    class EntityCreatedEvent : public Event {
    private:
        std::shared_ptr<spaceinvaders::model::EntityModel> entity;
        std::string prefferedSprite;

    public:
        [[nodiscard]] const std::shared_ptr<spaceinvaders::model::EntityModel> &getEntity() const;

        [[nodiscard]] const std::string &getPrefferedSprite() const;

        EntityCreatedEvent(std::shared_ptr<spaceinvaders::model::EntityModel> entity,
                           std::string prefferedSprite);

        explicit EntityCreatedEvent(std::shared_ptr<spaceinvaders::model::EntityModel> entity);
    };
}


#endif //SPACEINVADERS_ENTITYCREATEDEVENT_H
