//
// Created by arno on 24/12/2019.
//

#ifndef SPACEINVADERS_UPDATEEVENT_H
#define SPACEINVADERS_UPDATEEVENT_H

#include "Event.h"

namespace spaceinvaders::event {
class UpdateEvent : public Event
{
        double elapsedSeconds;

public:
        /**
         * Get the passed seconds
         * @return seconds
         */
        [[nodiscard]] double getElapsedSeconds() const;

        /**
         * Constructor
         * @param elapsedSeconds Seconds to be updated
         */
        explicit UpdateEvent(double elapsedSeconds);
};
} // namespace spaceinvaders::event

#endif // SPACEINVADERS_UPDATEEVENT_H
