//
// Created by arno on 14/12/2019.
//

#include "EntityController.h"
#include "../EntityModel/EntityModel.h"

void spaceinvaders::controller::EntityController::handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) {

}

const std::shared_ptr<spaceinvaders::model::EntityModel> &
spaceinvaders::controller::EntityController::getModel() const {
    return model;
}

spaceinvaders::controller::EntityController::EntityController(
        const std::shared_ptr<spaceinvaders::model::EntityModel> &model) : model(model) {}

