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
        explicit PositionUpdated(const Coordinate &newPosition);

        [[nodiscard]] const Coordinate &getNewPosition() const;
    };
}


#endif //SPACEINVADERS_POSITIONUPDATED_H
