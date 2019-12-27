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
        virtual void go(Coordinate coordinate);

        virtual void fire();

        ShipController();
    };
}


#endif //SPACEINVADERS_SHIPCONTROLLER_H
