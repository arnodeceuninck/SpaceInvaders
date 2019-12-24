//
// Created by arno on 22/12/2019.
//

#include "ShipRepresentation.h"
#include "../EntityModel/PlayerShip.h"

spaceinvaders::view::ShipRepresentation::ShipRepresentation(std::shared_ptr<GameWindow> window) : EntityRepresentation(
        window) {}


void spaceinvaders::view::ShipRepresentation::handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) {
    EntityRepresentation::handleEvent(event);
}

void spaceinvaders::view::ShipRepresentation::draw() {

}
