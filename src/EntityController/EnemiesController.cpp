//
// Created by arno on 25/12/2019.
//

#include "EnemiesController.h"
#include "../Events/UpdateEvent.h"
#include "../EntityModel/EnemyShip.h"
#include "../Events/GoDirection.h"

void spaceinvaders::controller::EnemiesController::handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) {
    if (auto ev = std::dynamic_pointer_cast<spaceinvaders::event::UpdateEvent>(event)) {
//        if (auto ship = std::dynamic_pointer_cast<spaceinvaders::model::EnemyShip>(getModel())) {
        if (direction == down) {
            goDown(ev->getElapsedSeconds());
        }

        if (enemyCloseToRightBorder()) {
            goDown(ev->getElapsedSeconds());
        } else if (enemyCloseToLeftBorder()) {
            goDown(ev->getElapsedSeconds());
        }
    }
//    }
}

spaceinvaders::controller::EnemiesController::EnemiesController(
        const std::shared_ptr<spaceinvaders::model::EntityModel> &model) : ShipController(model), direction(right),
                                                                           previousDirection(down) {
    go(Coordinate(1, 0));
}

void spaceinvaders::controller::EnemiesController::goDown(double elapsedTime) {
    if (direction != down) {
        go(Coordinate(0, -1));
        previousDirection = direction;
        direction = down;
        downTime = 0.20;
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

void spaceinvaders::controller::EnemiesController::setLeftMostEnemy(
        const std::shared_ptr<spaceinvaders::model::EnemyShip> &leftMostEnemy) {
    EnemiesController::leftMostEnemy = leftMostEnemy;
}

void spaceinvaders::controller::EnemiesController::setRightMostEnemy(
        const std::shared_ptr<spaceinvaders::model::EnemyShip> &rightMostEnemy) {
    EnemiesController::rightMostEnemy = rightMostEnemy;
}

bool spaceinvaders::controller::EnemiesController::enemyCloseToRightBorder() {
    return rightMostEnemy->getPosition().getX() + rightMostEnemy->getWidth() / 2 > 3.90;
}

bool spaceinvaders::controller::EnemiesController::enemyCloseToLeftBorder() {
    return leftMostEnemy->getPosition().getX() - rightMostEnemy->getWidth() / 2 < -3.90;
}

void spaceinvaders::controller::EnemiesController::go(spaceinvaders::Coordinate coordinate) {
    std::shared_ptr<spaceinvaders::event::Event> event = std::make_shared<spaceinvaders::event::GoDirection>(
            coordinate);
    notifyObservers(event);
}

void spaceinvaders::controller::EnemiesController::fire() {
    for (auto enemy: enemies) {
        if (auto ship = std::dynamic_pointer_cast<spaceinvaders::model::Ship>(enemy)) {
            ship->fire();
        }
    }
}

void spaceinvaders::controller::EnemiesController::addEnemy(std::shared_ptr<spaceinvaders::model::EnemyShip> enemy) {
//    enemies.push_back(enemy);
    addObserver(enemy);
    enemy->setSpeedDirection(Coordinate(1, 0));
}
