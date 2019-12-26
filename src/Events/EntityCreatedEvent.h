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
        const std::shared_ptr<spaceinvaders::model::EntityModel> &getEntity() const;

        const std::string &getPrefferedSprite() const;

        EntityCreatedEvent(const std::shared_ptr<spaceinvaders::model::EntityModel> &entity,
                           const std::string &prefferedSprite);

        EntityCreatedEvent(const std::shared_ptr<spaceinvaders::model::EntityModel> &entity);
    };
}


#endif //SPACEINVADERS_ENTITYCREATEDEVENT_H
