//
// Created by arno on 14/12/2019.
//

#include "GameController.h"
#include "../Events/UpdateEvent.h"

namespace spaceinvaders::controller {
    void GameController::checkInput() {
        std::shared_ptr<spaceinvaders::event::Event> controlEvent = std::make_shared<spaceinvaders::event::ControllerEvent>();
        notifyObservers(controlEvent);
    }

    GameController::GameController(const std::shared_ptr<spaceinvaders::model::EntityModel> &model) : EntityController(
            model) {}

    void GameController::update(double elapsedSeconds) {
        checkInput();
        std::shared_ptr<spaceinvaders::event::Event> event = std::make_shared<spaceinvaders::event::UpdateEvent>(
                elapsedSeconds);
        notifyObservers(event);
    }
}