//
// Created by arno on 14/12/2019.
//

#include <iostream>
#include "GameRepresentation.h"
#include "BackgroundTiles.h"
#include "SFML/Graphics.hpp"
#include "../Events/DrawUpdate.h"
#include "../EntityModel/GameModel.h"
#include "../Events/BulletFired.h"
#include "MovingEntityRepresentation.h"
#include "../Events/EntityCreatedEvent.h"
#include "../Events/ReprDestroyEvent.h"

spaceinvaders::view::GameRepresentation::GameRepresentation(std::shared_ptr<spaceinvaders::model::GameModel> gameModel)
        : EntityRepresentation(
        std::make_shared<GameWindow>(800, 600)) {

    auto gwD = getWindow()->getDimensions();
    auto gmD = gameModel->getDimensions();
    auto transf = std::make_shared<Transformation>(gwD, gmD);
    setTransformation(transf);

    auto background = std::make_shared<BackgroundTiles>("res/Background.jpg", getWindow());
    addObserver(background);
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
    if (auto ev = std::dynamic_pointer_cast<spaceinvaders::event::BulletFired>(event)) {
        std::shared_ptr<MovingEntityRepresentation> rocket = std::make_shared<MovingEntityRepresentation>(getWindow(),
                                                                                                          getTransformation());
        rocket->setSpriteFile("Bullet.png");
        addObserver(rocket);
        ev->getRocket()->addObserver(rocket);

        std::cout << "FIREEEEEEEEEEEEEEEEEEEEBAAAALLLLL" << std::endl;
//        std::shared_ptr<>();
    } else if (auto de = std::dynamic_pointer_cast<spaceinvaders::event::ReprDestroyEvent>(event)) {
        removeObserver(de->getEntity());
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

