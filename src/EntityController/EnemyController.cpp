//
// Created by arno on 25/12/2019.
//

#include <cmath>
#include <iostream>
#include "EnemyController.h"
#include "../Events/UpdateEvent.h"

void spaceinvaders::controller::EnemyController::checkFire(double elapsedTime) {
    if (!firstRow) {
        return;
    }
    firetime -= elapsedTime;
    if (firetime < 0) {
        fire();
        firetime = randomNextFire();
    }
}

spaceinvaders::controller::EnemyController::EnemyController(double timeBetweenFire) : timeBetweenFire(timeBetweenFire) {
    firetime = randomNextFire();
}

void spaceinvaders::controller::EnemyController::handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) {
    if (auto ev = std::dynamic_pointer_cast<spaceinvaders::event::UpdateEvent>(event)) {
        checkFire(ev->getElapsedSeconds());
    }
}

bool spaceinvaders::controller::EnemyController::isFirstRow() const {
    return firstRow;
}

void spaceinvaders::controller::EnemyController::setFirstRow(bool firstRow) {
    EnemyController::firstRow = firstRow;
}

double spaceinvaders::controller::EnemyController::randomNextFire() {
    double nextFire = std::fmod(static_cast<double>(random()) / 100, timeBetweenFire) + timeBetweenFire;
//    std::cout << "Next fire: " << nextFire << std::endl;
    return nextFire;
}
