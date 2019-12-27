//
// Created by arno on 27/12/2019.
//

#ifndef SPACEINVADERS_CONTROLLERCREATED_H
#define SPACEINVADERS_CONTROLLERCREATED_H

//#include <bits/shared_ptr.h>

#include <memory>
#include "Event.h"
#include "../EntityController/EntityController.h"

namespace spaceinvaders::event {
    class ControllerCreated : public Event {
        std::shared_ptr<spaceinvaders::controller::EntityController> controller;
    public:
        ControllerCreated(const std::shared_ptr<spaceinvaders::controller::EntityController> &controller);

        const std::shared_ptr<spaceinvaders::controller::EntityController> &getController() const;
    };
}


#endif //SPACEINVADERS_CONTROLLERCREATED_H
