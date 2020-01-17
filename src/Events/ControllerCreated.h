//
// Created by arno on 27/12/2019.
//

#ifndef SPACEINVADERS_CONTROLLERCREATED_H
#define SPACEINVADERS_CONTROLLERCREATED_H

//#include <bits/shared_ptr.h>

#include "../EntityController/EntityController.h"
#include "Event.h"
#include <memory>

namespace spaceinvaders::event {
    class ControllerCreated : public Event {
        std::shared_ptr<spaceinvaders::controller::EntityController> controller;

    public:
        /**
         * Notify a controller has been created
         * @param controller The controller
         */
        explicit ControllerCreated(std::shared_ptr<spaceinvaders::controller::EntityController> controller);

        /**
         * Get the created controller
         * @return
         */
        [[nodiscard]] const std::shared_ptr<spaceinvaders::controller::EntityController> &getController() const;
    };
} // namespace spaceinvaders::event

#endif // SPACEINVADERS_CONTROLLERCREATED_H
