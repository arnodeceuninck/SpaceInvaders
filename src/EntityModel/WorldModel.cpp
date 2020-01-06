//
// Created by arno on 14/12/2019.
//

#include <iostream>
#include "WorldModel.h"
#include "../Events/UpdateEvent.h"
#include "../Events/FireBullet.h"
#include "../Events/RocketPositionUpdated.h"
#include "../Events/DestroyedEvent.h"
#include "../Events/EntityCreatedEvent.h"
#include "PlayerShip.h"
#include "EnemyShip.h"
#include "../Events/LevelEnded.h"

void spaceinvaders::model::WorldModel::handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) {
    if (auto entityEvent = std::dynamic_pointer_cast<spaceinvaders::event::EntityCreatedEvent>(
            event)) { // From EntityModel
        if (!event->isHandledByGameModel()) {
            notifyObservers(event);
            return;
        }
        if (auto entity = std::dynamic_pointer_cast<spaceinvaders::model::MovingEntity>(entityEvent->getEntity())) {
//            std::cout << "Entity added to gameWorld" << std::endl;
            addObserver(entity);
            entity->addObserver(shared_from_this());
            movingEntities.emplace_back(entity);
            if (auto enemy = std::dynamic_pointer_cast<spaceinvaders::model::EnemyShip>(entityEvent->getEntity())) {
                ++enemyCount;
            }
        }

    }
//    else if (auto bf = std::dynamic_pointer_cast<spaceinvaders::event::FireBullet>(event)) {
//        // TODO: remove: should happen with entityCreated
//        addObserver(bf->getRocket());
//        std::shared_ptr<WorldModel> wm = std::dynamic_pointer_cast<WorldModel>(shared_from_this());
//        bf->getRocket()->addObserver(wm);
//    }
    else if (auto rpu = std::dynamic_pointer_cast<spaceinvaders::event::RocketPositionUpdated>(event)) {
        notifyObservers(event); // Let the observers check for collisions
    } else if (auto de = std::dynamic_pointer_cast<spaceinvaders::event::DestroyedEvent>(event)) {
        movingEntities.remove(de->getEntity());
        bool levelEnded = false;
        if (std::dynamic_pointer_cast<spaceinvaders::model::PlayerShip>(de->getEntity())) {
            levelEnded = true;
//            std::cout << "GAME OVER" << std::endl;
        } else if (std::dynamic_pointer_cast<spaceinvaders::model::EnemyShip>(de->getEntity())) {
            --enemyCount;
//            std::cout << "Enemy killed: " << enemyCount << " left" << std::endl;
            if (enemyCount == 0) {
                levelEnded = true;
//                std::cout << "VICTORY" << std::endl;
            }
        }
        if (levelEnded) {
            std::shared_ptr<spaceinvaders::event::Event> eventLE = std::make_shared<spaceinvaders::event::LevelEnded>(
                    enemyCount == 0);
            reset();
            notifyObservers(eventLE);
        }
    }
}

void spaceinvaders::model::WorldModel::update(double elapsedSeconds) {
    std::shared_ptr<spaceinvaders::event::Event> updateEv = std::make_shared<spaceinvaders::event::UpdateEvent>(
            elapsedSeconds);
    notifyObservers(updateEv);
}

void spaceinvaders::model::WorldModel::reset() {
    enemyCount = 0;
    movingEntities.clear();
}
