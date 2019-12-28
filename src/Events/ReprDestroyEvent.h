//
// Created by arno on 25/12/2019.
//

#ifndef SPACEINVADERS_REPRDESTROYEDEVENT_H
#define SPACEINVADERS_REPRDESTROYEDEVENT_H


#include <memory>
#include "Event.h"

namespace spaceinvaders::observer {
    class Observer;
}
namespace spaceinvaders::event {
    class ReprDestroyEvent : public Event {
    public:
        /**
         * Constructor: Destroy a reprEntity
         * @param entity The representation event that got destroyed
         */
        explicit ReprDestroyEvent(std::shared_ptr<observer::Observer> entity);

        /**
         * Get the destroyed entity
         * @return the entity
         */
        [[nodiscard]] const std::shared_ptr<spaceinvaders::observer::Observer> &getEntity() const;

    private:
        std::shared_ptr<spaceinvaders::observer::Observer> entity;
    };
}


#endif //SPACEINVADERS_REPRDESTROYEDEVENT_H
