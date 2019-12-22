//
// Created by arno on 22/12/2019.
//

#ifndef SPACEINVADERS_SHIPCONTROLLER_H
#define SPACEINVADERS_SHIPCONTROLLER_H

#include "EntityController.h"

namespace spaceinvaders::controller {
    class ShipController : public EntityController {
    public:
        void handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) override;
    };
}


#endif //SPACEINVADERS_SHIPCONTROLLER_H
