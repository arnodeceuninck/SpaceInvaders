//
// Created by arno on 25/12/2019.
//

#include "ReprDestroyEvent.h"

const std::weak_ptr<spaceinvaders::observer::Observer> &
spaceinvaders::event::ReprDestroyEvent::getEntity() const {
    return entity;
}

spaceinvaders::event::ReprDestroyEvent::ReprDestroyEvent(
        std::weak_ptr<observer::Observer> entity)
        : entity(entity) {}
