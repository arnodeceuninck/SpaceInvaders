//
// Created by arno on 25/12/2019.
//

#include "EnemyController.h"
#include "../Events/UpdateEvent.h"
#include "../EntityModel/EnemyShip.h"

void spaceinvaders::controller::EnemyController::handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) {
    if (auto ev = std::dynamic_pointer_cast<spaceinvaders::event::UpdateEvent>(event)) {
        if (auto ship = std::dynamic_pointer_cast<spaceinvaders::model::EnemyShip>(getModel())) {
            if (direction == down) {
                goDown(ev->getElapsedSeconds());
            }

            if (enemyCloseToRightBorder()) {
                goDown(ev->getElapsedSeconds());
            } else if (enemyCloseToLeftBorder()) {
                goDown(ev->getElapsedSeconds());
            }
        }
    }
}

spaceinvaders::controller::EnemyController::EnemyController(
        const std::shared_ptr<spaceinvaders::model::EntityModel> &model) : ShipController(model), direction(right),
                                                                           previousDirection(down) {
    go(Coordinate(1, 0));
}

void spaceinvaders::controller::EnemyController::goDown(double elapsedTime) {
    if (direction != down) {
        go(Coordinate(0, -1));
        previousDirection = direction;
        direction = down;
        downTime = 0.25;
    } else {
        downTime -= elapsedTime;
    }

    if (downTime < 0) {
        if (previousDirection == left) {
            go(Coordinate(1, 0));
            previousDirection = direction;
            direction = right;
        } else if (previousDirection == right) {
            go(Coordinate(-1, 0));
            previousDirection = direction;
            direction = left;
        }
    }
}

void spaceinvaders::controller::EnemyController::setLeftMostEnemy(
        const std::shared_ptr<spaceinvaders::model::EnemyShip> &leftMostEnemy) {
    EnemyController::leftMostEnemy = leftMostEnemy;
}

void spaceinvaders::controller::EnemyController::setRightMostEnemy(
        const std::shared_ptr<spaceinvaders::model::EnemyShip> &rightMostEnemy) {
    EnemyController::rightMostEnemy = rightMostEnemy;
}

bool spaceinvaders::controller::EnemyController::enemyCloseToRightBorder() {
    return rightMostEnemy->getPosition().getX() + rightMostEnemy->getWidth() / 2 > 3.90;
}

bool spaceinvaders::controller::EnemyController::enemyCloseToLeftBorder() {
    return leftMostEnemy->getPosition().getX() - rightMostEnemy->getWidth() / 2 < -3.90;
}
