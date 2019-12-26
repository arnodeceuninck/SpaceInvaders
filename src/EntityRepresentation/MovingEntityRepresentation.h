//
// Created by arno on 22/12/2019.
//

#ifndef SPACEINVADERS_MOVINGENTITYREPRESENTATION_H
#define SPACEINVADERS_MOVINGENTITYREPRESENTATION_H

#include "EntityRepresentation.h"

namespace spaceinvaders::model {
    class Ship;
}

namespace spaceinvaders::view {
    class MovingEntityRepresentation
            : public EntityRepresentation, public std::enable_shared_from_this<MovingEntityRepresentation> {

    public:
        void draw() override;

//        MovingEntityRepresentation(std::shared_ptr<GameWindow> window, std::shared_ptr<Transformation> transformation);

        MovingEntityRepresentation(const std::shared_ptr<spaceinvaders::model::EntityModel> &entity,
                                   const std::shared_ptr<GameWindow> &window,
                                   const std::shared_ptr<Transformation> &transformation);

        void handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) override;
    };
}


#endif //SPACEINVADERS_MOVINGENTITYREPRESENTATION_H
