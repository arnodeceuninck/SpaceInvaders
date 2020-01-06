//
// Created by arno on 14/12/2019.
//

#ifndef SPACEINVADERS_PLAYERSHIP_H
#define SPACEINVADERS_PLAYERSHIP_H

#include "Ship.h"

namespace spaceinvaders::model {
    class PlayerShip : public Ship {
    public:
        /**
         * Constructor
         */
        PlayerShip();

        /**
         * Handle an event
         * @param event
         */
        void handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) override;

        /**
         * Get the front of the ship
         * @return
         */
        Coordinate getShipFront() override;

        /**
         * Get the direction the ship shoots in
         * @return
         */
        Coordinate getShootingDirection() override;
    };
}


#endif //SPACEINVADERS_PLAYERSHIP_H
