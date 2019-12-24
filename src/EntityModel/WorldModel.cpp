//
// Created by arno on 14/12/2019.
//

#include "WorldModel.h"
#include "../Events/UpdateEvent.h"
#include "../Events/BulletFired.h"

void spaceinvaders::model::WorldModel::handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) {
    if (auto ev = std::dynamic_pointer_cast<spaceinvaders::event::BulletFired>(event)) {
        addObserver(ev->getRocket());
    }
}

void spaceinvaders::model::WorldModel::update(double elapsedSeconds) {
    std::shared_ptr<spaceinvaders::event::Event> updateEv = std::make_shared<spaceinvaders::event::UpdateEvent>(
            elapsedSeconds);
    notifyObservers(updateEv);
}
