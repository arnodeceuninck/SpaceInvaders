//
// Created by arno on 22/12/2019.
//

#include "ShipRepresentation.h"
#include "../EntityModel/PlayerShip.h"

spaceinvaders::view::ShipRepresentation::ShipRepresentation(
        std::shared_ptr<spaceinvaders::model::Ship> ship) {
    std::shared_ptr<observer::Observer> observerThis = std::dynamic_pointer_cast<observer::Observer>(
            shared_from_this());
    ship->addObserver(observerThis);
}

void spaceinvaders::view::ShipRepresentation::handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) {

}
