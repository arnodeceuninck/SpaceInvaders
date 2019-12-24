//
// Created by arno on 14/12/2019.
//

#include <iostream>
#include "PlayerShip.h"


spaceinvaders::model::PlayerShip::PlayerShip() : Ship(0, -2) {}

void spaceinvaders::model::PlayerShip::handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) {
    Ship::handleEvent(event);
}
