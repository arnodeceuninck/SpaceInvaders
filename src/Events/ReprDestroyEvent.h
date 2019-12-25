//
// Created by arno on 25/12/2019.
//

#ifndef SPACEINVADERS_REPRDESTROYEDEVENT_H
#define SPACEINVADERS_REPRDESTROYEDEVENT_H


#include <memory>
#include "Event.h"

namespace spaceinvaders::view {
    class EntityRepresentation;
}
namespace spaceinvaders::event {
    class ReprDestroyEvent : public Event {
    public:
        ReprDestroyEvent(const std::shared_ptr<spaceinvaders::view::EntityRepresentation> &entity);

    private:
        std::shared_ptr<spaceinvaders::view::EntityRepresentation> entity;
    public:
        const std::shared_ptr<spaceinvaders::view::EntityRepresentation> &getEntity() const;
    };
}


#endif //SPACEINVADERS_REPRDESTROYEDEVENT_H
