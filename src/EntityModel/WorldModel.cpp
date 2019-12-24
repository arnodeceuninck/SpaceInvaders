//
// Created by arno on 14/12/2019.
//

#include "WorldModel.h"
#include "../Events/UpdateEvent.h"

void spaceinvaders::model::WorldModel::handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) {

}

void spaceinvaders::model::WorldModel::update(double elapsedSeconds) {
    std::shared_ptr<spaceinvaders::event::Event> updateEv = std::make_shared<spaceinvaders::event::UpdateEvent>(
            elapsedSeconds);
    notifyObservers(updateEv);
}
