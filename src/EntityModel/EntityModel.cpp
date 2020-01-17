//
// Created by arno on 14/12/2019.
//

#include "EntityModel.h"
#include "../Events/UpdateEvent.h"

void spaceinvaders::model::EntityModel::handleEvent(std::shared_ptr<spaceinvaders::event::Event>& event)
{
        if (auto ev = std::dynamic_pointer_cast<spaceinvaders::event::UpdateEvent>(event)) {
                update(ev->getElapsedSeconds());
        }
}
