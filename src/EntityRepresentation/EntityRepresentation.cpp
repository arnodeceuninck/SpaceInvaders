//
// Created by arno on 14/12/2019.
//

#include "EntityRepresentation.h"
#include "../Events/EntityCreatedEvent.h"
#include "../Events/DrawUpdate.h"
#include "GameRepresentation.h"
#include "../Events/ReprDestroyEvent.h"
#include "../Events/DestroyedEvent.h"

const std::string &spaceinvaders::view::EntityRepresentation::getSpriteFile() const {
    return spriteFile;
}

void spaceinvaders::view::EntityRepresentation::setSpriteFile(const std::string &spriteFile) {
    EntityRepresentation::spriteFile = "res/" + spriteFile;
}

void spaceinvaders::view::EntityRepresentation::handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) {
    if (auto updateEvent = std::dynamic_pointer_cast<spaceinvaders::event::DrawUpdate>(
            event)) { // From GameRepresentation
        draw();
//    } else if (auto entityEvent = std::dynamic_pointer_cast<spaceinvaders::event::EntityCreatedEvent>(
//            event)) { // From EntityModel
//        entity = entityEvent->getEntity();
    } else if (auto destroyEvent = std::dynamic_pointer_cast<spaceinvaders::event::DestroyedEvent>(
            event)) { // From EntityModel

        auto wptr = std::shared_ptr<EntityRepresentation>(this,
                                                          [](EntityRepresentation *) {}); // I don't know why it works, but it works :-) (Happy me)

        auto me = shared_from_this(); // Weird, there must exist one since it is an observer, and there is always a shared pointer from observable to observer
        std::shared_ptr<spaceinvaders::event::Event> ev = std::make_shared<spaceinvaders::event::ReprDestroyEvent>(me);
        notifyObservers(ev); // To GameRepresentation
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

bool spaceinvaders::view::EntityRepresentation::isInit() const {
    return init;
}

void spaceinvaders::view::EntityRepresentation::setInit(bool init) {
    EntityRepresentation::init = init;
}

sf::Texture &spaceinvaders::view::EntityRepresentation::getTexture() {
    return texture;
}

sf::Sprite &spaceinvaders::view::EntityRepresentation::getSprite() {
    return sprite;
}

void spaceinvaders::view::EntityRepresentation::setTexture(const sf::Texture &texture) {
    EntityRepresentation::texture = texture;
}

void spaceinvaders::view::EntityRepresentation::setSprite(const sf::Sprite &sprite) {
    EntityRepresentation::sprite = sprite;
}

void
spaceinvaders::view::EntityRepresentation::setEntity(const std::shared_ptr<spaceinvaders::model::EntityModel> &entity) {
    EntityRepresentation::entity = entity;
}

spaceinvaders::view::EntityRepresentation::EntityRepresentation(
        const std::shared_ptr<spaceinvaders::model::EntityModel> &entity, const std::shared_ptr<GameWindow> &window,
        const std::shared_ptr<Transformation> &transformation) : entity(entity), window(window),
                                                                 transformation(transformation) {}
