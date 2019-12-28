//
// Created by arno on 14/12/2019.
//

#include "GameController.h"

#include <utility>
#include "../Events/UpdateEvent.h"
#include "../Events/WindowInteractionEvent.h"
#include "../Events/ControllerCreated.h"
#include "../Events/GameEnded.h"

namespace spaceinvaders::controller {
    void GameController::checkInput() {
        gameWindow->checkInput();
//        std::shared_ptr<spaceinvaders::event::Event> controlEvent = std::make_shared<spaceinvaders::event::ControllerEvent>();
//        notifyObservers(controlEvent);
    }

    GameController::GameController() = default;

    void GameController::update(double elapsedSeconds) {
        checkInput();
        std::shared_ptr<spaceinvaders::event::Event> event = std::make_shared<spaceinvaders::event::UpdateEvent>(
                elapsedSeconds);
        notifyObservers(event);
    }

    GameController::GameController(std::shared_ptr<spaceinvaders::GameWindow> gameWindow) : gameWindow(std::move(
            gameWindow)) {
    }

    void GameController::handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) {
        EntityController::handleEvent(event);
        if (auto wie = std::dynamic_pointer_cast<spaceinvaders::event::WindowInteractionEvent>(event)) {
            if (wie->getEvent().type == sf::Event::Closed) {
                std::shared_ptr<spaceinvaders::event::Event> gameEnded = std::make_shared<spaceinvaders::event::GameEnded>();
                notifyObservers(gameEnded);
            } else {
                notifyObservers(event);
            }
        }
    }

    void GameController::addController(const std::shared_ptr<EntityController> &controller) {
        controlEntities.emplace_back(controller);
        addObserver(controller);
    }

    void GameController::reset() {
        controlEntities.clear();
    }
}