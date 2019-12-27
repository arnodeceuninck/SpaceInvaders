//
// Created by arno on 22/12/2019.
//

#ifndef SPACEINVADERS_PLAYERCONTROLLER_H
#define SPACEINVADERS_PLAYERCONTROLLER_H

#include "EntityController.h"
#include "../Events/MovingEntityEvent.h"
#include "../EntityModel/Coordinate.h"
#include "ShipController.h"

namespace spaceinvaders::controller {
    class PlayerController : public ShipController {
        std::shared_ptr<spaceinvaders::event::MovingEntityEvent> lastEvent;
    public:
        PlayerController();

        void handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) override;
    };
}


#endif //SPACEINVADERS_PLAYERCONTROLLER_H
