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
        void go(Coordinate coordinate);

        void fire();

        ShipController(const std::shared_ptr<spaceinvaders::model::EntityModel> &model);
    };
}


#endif //SPACEINVADERS_SHIPCONTROLLER_H
