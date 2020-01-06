//
// Created by arno on 25/12/2019.
//

#ifndef SPACEINVADERS_SHIPCONTROLLER_H
#define SPACEINVADERS_SHIPCONTROLLER_H

#include "../EntityModel/Coordinate.h"
#include "EntityController.h"

namespace spaceinvaders::controller {
    class ShipController : public EntityController {
    public:
        /**
         * Request a ship to change it's direction
         * @param coordinate The direction you want the ship to go in (normalized)
         */
        virtual void go(Coordinate coordinate);

        /**
         * Request a ship to fire
         */
        virtual void fire();

        /**
         * Constructor
         */
        ShipController();
    };
}


#endif //SPACEINVADERS_SHIPCONTROLLER_H
