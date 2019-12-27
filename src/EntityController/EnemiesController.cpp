//
// Created by arno on 25/12/2019.
//

#include <iostream>
#include "EnemiesController.h"
#include "../Events/UpdateEvent.h"
#include "../EntityModel/EnemyShip.h"
#include "../Events/GoDirection.h"
#include "../Events/FireBullet.h"
#include "EnemyController.h"

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

        checkFirstRowEnemies();
    }
//    }
}

spaceinvaders::controller::EnemiesController::EnemiesController() : direction(right),
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


bool spaceinvaders::controller::EnemiesController::enemyCloseToRightBorder() {
    for (auto enemy: enemies) {
        if (auto enemySP = enemy.first.lock()) {
            if (enemySP->getPosition().getX() + enemySP->getWidth() / 2 > 3.90) {
                return true;
            }
        }
    }
    return false;
}

bool spaceinvaders::controller::EnemiesController::enemyCloseToLeftBorder() {
    for (auto enemy: enemies) {
        if (auto enemySP = enemy.first.lock()) {
            if (enemySP->getPosition().getX() - enemySP->getWidth() / 2 < -3.90) {
                return true;
            }
        }
    }
    return false;
}

void spaceinvaders::controller::EnemiesController::go(spaceinvaders::Coordinate coordinate) {
    std::shared_ptr<spaceinvaders::event::Event> event = std::make_shared<spaceinvaders::event::GoDirection>(
            coordinate);
    notifyObservers(event);
}

void spaceinvaders::controller::EnemiesController::fire() {
    std::shared_ptr<spaceinvaders::event::Event> event = std::make_shared<spaceinvaders::event::FireBullet>();
    notifyObservers(event);
}

void spaceinvaders::controller::EnemiesController::addEnemy(std::shared_ptr<spaceinvaders::model::EnemyShip> enemy,
                                                            std::shared_ptr<EnemyController> controller) {
    enemies.emplace_back(
            std::pair<std::weak_ptr<spaceinvaders::model::EnemyShip>, std::weak_ptr<EnemyController>>(enemy,
                                                                                                      controller));
    addObserver(enemy);
    enemy->setSpeedDirection(Coordinate(1, 0));
}

void spaceinvaders::controller::EnemiesController::checkFirstRowEnemies() {
    for (auto enemy: enemies) {
        auto spController = enemy.second.lock();
        auto spCheckingEnemy = enemy.first.lock();
        if (spController && spCheckingEnemy && !spController->isFirstRow()) {
            Coordinate inFront = spCheckingEnemy->getPosition() - Coordinate(0, spCheckingEnemy->getHeight());
            bool firstRow = true;
            for (auto enemy2: enemies) {
                auto spEnemy = enemy2.first.lock();
                if (spEnemy == spCheckingEnemy) {
                    continue;
                }
                if (spEnemy && spEnemy->isCollision(inFront)) {
                    firstRow = false;
                }
            }
            if (firstRow) {
                spController->setFirstRow(true);
            }
        }
    }
}

