//
// Created by arno on 14/12/2019.
//

#include "GameController.h"

namespace spaceinvaders::controller {
    void GameController::checkInput() {
        std::shared_ptr<spaceinvaders::event::Event> controlEvent = std::make_shared<spaceinvaders::event::ControllerEvent>();
        notifyObservers(controlEvent);
    }
}