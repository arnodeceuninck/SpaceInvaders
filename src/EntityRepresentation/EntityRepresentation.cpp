//
// Created by arno on 14/12/2019.
//

#include "EntityRepresentation.h"
#include "../Events/EntityCreatedEvent.h"
#include "../Events/DrawUpdate.h"
#include "GameRepresentation.h"

const std::string &spaceinvaders::view::EntityRepresentation::getSpriteFile() const {
    return spriteFile;
}

void spaceinvaders::view::EntityRepresentation::setSpriteFile(const std::string &spriteFile) {
    EntityRepresentation::spriteFile = "res/" + spriteFile;
}

void spaceinvaders::view::EntityRepresentation::handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) {
    if (auto updateEvent = std::dynamic_pointer_cast<spaceinvaders::event::DrawUpdate>(event)) {
        draw();
    } else if (auto entityEvent = std::dynamic_pointer_cast<spaceinvaders::event::EntityCreatedEvent>(event)) {
        entity = entityEvent->getEntity();
    }
}

const std::shared_ptr<spaceinvaders::model::EntityModel> &spaceinvaders::view::EntityRepresentation::getEntity() const {
    return entity;
}

std::shared_ptr<spaceinvaders::GameWindow> &spaceinvaders::view::EntityRepresentation::getWindow() {
    return window;
}

spaceinvaders::view::EntityRepresentation::EntityRepresentation(const std::shared_ptr<GameWindow> &window,
                                                                std::shared_ptr<Transformation> transformation)
        : window(
        window), transformation(transformation) {}

const std::shared_ptr<spaceinvaders::view::Transformation> &
spaceinvaders::view::EntityRepresentation::getTransformation() const {
    return transformation;
}

void
spaceinvaders::view::EntityRepresentation::setTransformation(const std::shared_ptr<Transformation> &transformation) {
    EntityRepresentation::transformation = transformation;
}

spaceinvaders::view::EntityRepresentation::EntityRepresentation(const std::shared_ptr<GameWindow> &window) : window(
        window) {}