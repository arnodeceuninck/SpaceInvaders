//
// Created by arno on 14/12/2019.
//

#include <iostream>
#include "GameRepresentation.h"
#include "BackgroundTiles.h"
#include "SFML/Graphics.hpp"
#include "../Events/DrawUpdate.h"
#include "../EntityModel/GameModel.h"
#include "../Events/FireBullet.h"
#include "MovingEntityRepresentation.h"
#include "../Events/EntityCreatedEvent.h"
#include "../Events/ReprDestroyEvent.h"

spaceinvaders::view::GameRepresentation::GameRepresentation(std::shared_ptr<spaceinvaders::model::GameModel> gameModel,
                                                            std::shared_ptr<GameWindow> gameWindow)
        : EntityRepresentation(gameWindow) {

    auto gwD = getWindow()->getDimensions();
    auto gmD = gameModel->getDimensions();
    auto transf = std::make_shared<Transformation>(gwD, gmD);
    setTransformation(transf);

    makeBackground();

}

void spaceinvaders::view::GameRepresentation::checkEvent() {
    sf::Event event;
//    while (window->pollEvent(event)){
//        // Notify the observers of this event
//    };
}

void spaceinvaders::view::GameRepresentation::checkInput() {
    getWindow()->checkInput();
}

void spaceinvaders::view::GameRepresentation::handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) {
    EntityRepresentation::handleEvent(event);
    if (auto entityEvent = std::dynamic_pointer_cast<spaceinvaders::event::EntityCreatedEvent>(
            event)) { // From EntityModel
        if (std::dynamic_pointer_cast<spaceinvaders::model::MovingEntity>(entityEvent->getEntity())) {
            std::cout << "Generating representation for entity" << std::endl;

            std::string sprite;
            if (!entityEvent->getPrefferedSprite().empty()) {
                sprite = entityEvent->getPrefferedSprite();
            } else {
                if (auto entity = std::dynamic_pointer_cast<spaceinvaders::model::RocketModel>(
                        entityEvent->getEntity())) {
                    sprite = "Bullet2.png";
                }
            }

            std::shared_ptr<spaceinvaders::view::MovingEntityRepresentation> representation = std::make_shared<spaceinvaders::view::MovingEntityRepresentation>(
                    entityEvent->getEntity(), getWindow(),
                    getTransformation(), sprite);

            representationEntities.emplace_back(representation);
            std::cout << "#Representations: " << representationEntities.size() << std::endl;

            representation->addObserver(shared_from_this());
            entityEvent->getEntity()->addObserver(representation);
            addObserver(representation);

        }

    } else if (auto de = std::dynamic_pointer_cast<spaceinvaders::event::ReprDestroyEvent>(event)) {
        // TODO: Just remove of the list, since observers should contain weak pointers
//        if (auto entity = de->getEntity().lock())
        representationEntities.remove(std::dynamic_pointer_cast<EntityRepresentation>(de->getEntity()));
    }
}

void spaceinvaders::view::GameRepresentation::draw() {


}

void spaceinvaders::view::GameRepresentation::update() {

    getWindow()->getSfmlWindow()->clear();

    std::shared_ptr<spaceinvaders::event::Event> updateV = std::make_shared<spaceinvaders::event::DrawUpdate>();
    notifyObservers(updateV);

    getWindow()->getSfmlWindow()->display();

}

void spaceinvaders::view::GameRepresentation::makeBackground() {
    auto background = std::make_shared<BackgroundTiles>("res/Background.jpg", getWindow());
    addObserver(background);
    representationEntities.emplace_back(background);
}

void spaceinvaders::view::GameRepresentation::reset() {
    representationEntities.clear();
    makeBackground();
}

