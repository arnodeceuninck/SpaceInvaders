//
// Created by arno on 15/12/2019.
//

#ifndef SPACEINVADERS_CONTROLLEREVENT_H
#define SPACEINVADERS_CONTROLLEREVENT_H

#include "Event.h"

namespace spaceinvaders::event {
/**
 * An event from the controller
 */
class ControllerEvent : public Event
{
public:
        /**
         * Constructor
         */
        ControllerEvent();
};
} // namespace spaceinvaders::event

#endif // SPACEINVADERS_CONTROLLEREVENT_H
