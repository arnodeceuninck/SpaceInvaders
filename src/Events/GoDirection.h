//
// Created by arno on 27/12/2019.
//

#ifndef SPACEINVADERS_GODIRECTION_H
#define SPACEINVADERS_GODIRECTION_H

#include "Event.h"
#include "../EntityModel/Coordinate.h"

namespace spaceinvaders::event {
    class GoDirection : public Event {
        Coordinate direction;
    public:
        explicit GoDirection(const Coordinate &direction);

        [[nodiscard]] const Coordinate &getDirection() const;
    };
}


#endif //SPACEINVADERS_GODIRECTION_H
