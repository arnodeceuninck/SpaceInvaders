//
// Created by arno on 27/12/2019.
//

#include "ControllerCreated.h"

const std::shared_ptr<spaceinvaders::controller::EntityController> &
spaceinvaders::event::ControllerCreated::getController() const {
    return controller;
}

spaceinvaders::event::ControllerCreated::ControllerCreated(
        const std::shared_ptr<spaceinvaders::controller::EntityController> &controller) : controller(controller) {}
