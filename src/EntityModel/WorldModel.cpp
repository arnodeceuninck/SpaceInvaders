//
// Created by arno on 14/12/2019.
//

#include "WorldModel.h"
#include "../Events/UpdateEvent.h"
#include "../Events/BulletFired.h"
#include "../Events/RocketPositionUpdated.h"

void spaceinvaders::model::WorldModel::handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) {
    if (auto bf = std::dynamic_pointer_cast<spaceinvaders::event::BulletFired>(event)) {
        addObserver(bf->getRocket());
        std::shared_ptr<WorldModel> wm = shared_from_this();
        bf->getRocket()->addObserver(wm);
    } else if (auto rpu = std::dynamic_pointer_cast<spaceinvaders::event::RocketPositionUpdated>(event)) {
        notifyObservers(event); // Let the observers check for collisions
    }
}

void spaceinvaders::model::WorldModel::update(double elapsedSeconds) {
    std::shared_ptr<spaceinvaders::event::Event> updateEv = std::make_shared<spaceinvaders::event::UpdateEvent>(
            elapsedSeconds);
    notifyObservers(updateEv);
}
