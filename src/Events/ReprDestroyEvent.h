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
        ReprDestroyEvent(std::shared_ptr<observer::Observer> entity);

    private:
        std::shared_ptr<spaceinvaders::observer::Observer> entity;
    public:
        const std::shared_ptr<spaceinvaders::observer::Observer> &getEntity() const;
    };
}


#endif //SPACEINVADERS_REPRDESTROYEDEVENT_H
