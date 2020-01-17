//
// Created by arno on 27/12/2019.
//

#ifndef SPACEINVADERS_GODIRECTION_H
#define SPACEINVADERS_GODIRECTION_H

#include "../EntityModel/Coordinate.h"
#include "Event.h"

namespace spaceinvaders::event {
class GoDirection : public Event
{
        Coordinate direction;

public:
        /**
         * Request observer (model) to go a specific direction
         * @param direction A normalized vector pointing to the new direction
         */
        explicit GoDirection(const Coordinate& direction);

        /**
         * Get the new direction
         * @return normalized vector pointing to the new direction
         */
        [[nodiscard]] const Coordinate& getDirection() const;
};
} // namespace spaceinvaders::event

#endif // SPACEINVADERS_GODIRECTION_H
