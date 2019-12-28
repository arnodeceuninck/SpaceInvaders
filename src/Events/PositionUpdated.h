//
// Created by arno on 27/12/2019.
//

#ifndef SPACEINVADERS_POSITIONUPDATED_H
#define SPACEINVADERS_POSITIONUPDATED_H

#include "../EntityModel/Coordinate.h"
#include "Event.h"

namespace spaceinvaders::event {
    class PositionUpdated : public Event {
        Coordinate newPosition;
    public:
        /**
         * Constructor, notify observers your position has changed
         * @param newPosition The new position (duhh)
         */
        explicit PositionUpdated(const Coordinate &newPosition);

        /**
         * Get the new position
         * @return the new position
         */
        [[nodiscard]] const Coordinate &getNewPosition() const;
    };
}


#endif //SPACEINVADERS_POSITIONUPDATED_H
