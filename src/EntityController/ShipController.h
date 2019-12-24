//
// Created by arno on 22/12/2019.
//

#ifndef SPACEINVADERS_SHIPCONTROLLER_H
#define SPACEINVADERS_SHIPCONTROLLER_H

#include "EntityController.h"
#include "../Events/MovingEntityEvent.h"
#include "../EntityModel/Coordinate.h"

namespace spaceinvaders::controller {
    class ShipController : public EntityController {
        std::shared_ptr<spaceinvaders::event::MovingEntityEvent> lastEvent;
    public:
        ShipController(const std::shared_ptr<spaceinvaders::model::EntityModel> &model);

        void go(Coordinate coordinate);

        void fire();

        void handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) override;
    };
}


#endif //SPACEINVADERS_SHIPCONTROLLER_H
