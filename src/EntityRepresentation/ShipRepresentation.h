//
// Created by arno on 22/12/2019.
//

#ifndef SPACEINVADERS_SHIPREPRESENTATION_H
#define SPACEINVADERS_SHIPREPRESENTATION_H

#include "EntityRepresentation.h"

namespace spaceinvaders::model {
    class Ship;
}

namespace spaceinvaders::view {
    class ShipRepresentation : public EntityRepresentation, public std::enable_shared_from_this<ShipRepresentation> {

    public:
        void draw() override;

        ShipRepresentation(std::shared_ptr<GameWindow> window, std::shared_ptr<Transformation> transformation);

        void handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) override;
    };
}


#endif //SPACEINVADERS_SHIPREPRESENTATION_H
