//
// Created by arno on 25/12/2019.
//

#include "ReprDestroyEvent.h"

const std::shared_ptr<spaceinvaders::view::EntityRepresentation> &
spaceinvaders::event::ReprDestroyEvent::getEntity() const {
    return entity;
}

spaceinvaders::event::ReprDestroyEvent::ReprDestroyEvent(
        const std::shared_ptr<spaceinvaders::view::EntityRepresentation> &entity)
        : entity(entity) {}
