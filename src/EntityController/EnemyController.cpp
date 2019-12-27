//
// Created by arno on 25/12/2019.
//

#include "EnemyController.h"
#include "../Events/UpdateEvent.h"

void spaceinvaders::controller::EnemyController::checkFire(double elapsedTime) {
    firetime -= elapsedTime;
    if (firetime < 0) {
        fire();
        firetime = random() % 10 + 5;
    }
}

spaceinvaders::controller::EnemyController::EnemyController(
        const std::shared_ptr<spaceinvaders::model::EntityModel> &model) : firetime(random() % 10 + 5) {}

void spaceinvaders::controller::EnemyController::handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) {
    if (auto ev = std::dynamic_pointer_cast<spaceinvaders::event::UpdateEvent>(event)) {
        checkFire(ev->getElapsedSeconds());
    }
}
