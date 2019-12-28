//
// Created by arno on 24/12/2019.
//

#ifndef SPACEINVADERS_UPDATEEVENT_H
#define SPACEINVADERS_UPDATEEVENT_H

#include "Event.h"

namespace spaceinvaders::event {
    class UpdateEvent : public Event {
        double elapsedSeconds;
    public:
        [[nodiscard]] double getElapsedSeconds() const;

    public:
        explicit UpdateEvent(double elapsedSeconds);
    };
}


#endif //SPACEINVADERS_UPDATEEVENT_H
