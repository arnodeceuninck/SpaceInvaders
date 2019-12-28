//
// Created by arno on 14/12/2019.
//

#include "GameController.h"
#include "../Events/UpdateEvent.h"
#include "../Events/WindowInteractionEvent.h"
#include "../Events/ControllerCreated.h"

namespace spaceinvaders::controller {
    void GameController::checkInput() {
        gameWindow->checkInput();
//        std::shared_ptr<spaceinvaders::event::Event> controlEvent = std::make_shared<spaceinvaders::event::ControllerEvent>();
//        notifyObservers(controlEvent);
    }

    GameController::GameController() {}

    void GameController::update(double elapsedSeconds) {
        checkInput();
        std::shared_ptr<spaceinvaders::event::Event> event = std::make_shared<spaceinvaders::event::UpdateEvent>(
                elapsedSeconds);
        notifyObservers(event);
    }

    GameController::GameController(const std::shared_ptr<spaceinvaders::GameWindow> &gameWindow) : gameWindow(
            gameWindow) {
    }

    void GameController::handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) {
        EntityController::handleEvent(event);
        if (auto wie = std::dynamic_pointer_cast<spaceinvaders::event::WindowInteractionEvent>(event)) {
            notifyObservers(event);
        }
    }

    void GameController::addController(std::shared_ptr<EntityController> controller) {
        controlEntities.emplace_back(controller);
        addObserver(controller);
    }

    void GameController::reset() {
        controlEntities.clear();
    }
}