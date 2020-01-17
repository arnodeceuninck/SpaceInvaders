//
// Created by arno on 22/12/2019.
//

#ifndef SPACEINVADERS_PLAYERCONTROLLER_H
#define SPACEINVADERS_PLAYERCONTROLLER_H

#include "../EntityModel/Coordinate.h"
#include "../Events/MovingEntityEvent.h"
#include "EntityController.h"
#include "ShipController.h"

namespace spaceinvaders::controller {
    class PlayerController : public ShipController {
    public:
        /**
         * Constructor
         */
        PlayerController();

        /**
         * Handle an event
         * @param event
         */
        void handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) override;
    };
} // namespace spaceinvaders::controller

#endif // SPACEINVADERS_PLAYERCONTROLLER_H
