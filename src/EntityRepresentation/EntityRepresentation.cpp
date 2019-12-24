//
// Created by arno on 14/12/2019.
//

#include "EntityRepresentation.h"
#include "../Events/EntityCreatedEvent.h"

const std::string &spaceinvaders::view::EntityRepresentation::getSpriteFile() const {
    return spriteFile;
}

void spaceinvaders::view::EntityRepresentation::setSpriteFile(const std::string &spriteFile) {
    EntityRepresentation::spriteFile = spriteFile;
}

void spaceinvaders::view::EntityRepresentation::handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) {
    if (auto entityEvent = std::dynamic_pointer_cast<spaceinvaders::event::EntityCreatedEvent>(event)) {
        entity = entityEvent->getEntity();
        draw();
    }
}

const std::shared_ptr<spaceinvaders::model::EntityModel> &spaceinvaders::view::EntityRepresentation::getEntity() const {
    return entity;
}

std::shared_ptr<spaceinvaders::GameWindow> &spaceinvaders::view::EntityRepresentation::getWindow() {
    return window;
}

spaceinvaders::view::EntityRepresentation::EntityRepresentation(const std::shared_ptr<GameWindow> &window) : window(
        window) {}

