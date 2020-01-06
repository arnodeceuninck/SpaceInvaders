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
        /**
         * Draw the entityu on the view
         */
        void draw() override;

//        MovingEntityRepresentation(std::shared_ptr<GameWindow> window, std::shared_ptr<Transformation> transformation);

        /**
         * Create a new representation
         * @param entity The game model entity it represents
         * @param window The window to draw on
         * @param sprite The filename of the texture file that will be used
         */
        MovingEntityRepresentation(const std::shared_ptr<spaceinvaders::model::EntityModel> &entity,
                                   const std::shared_ptr<GameWindow> &window, const std::string &sprite);

        /**
         * Handle an incoming event
         * @param event
         */
        void handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) override;

        /**
         * Destructor
         */
        ~MovingEntityRepresentation() override;
    };
}


#endif //SPACEINVADERS_MOVINGENTITYREPRESENTATION_H
