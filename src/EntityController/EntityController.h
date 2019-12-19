//
// Created by arno on 14/12/2019.
//

#ifndef SPACEINVADERS_ENTITYCONTROLLER_H
#define SPACEINVADERS_ENTITYCONTROLLER_H

#include "../Observer/Observable.h"
#include "ControllerEvent.h"

namespace sf {
    class Event;
}

namespace spaceinvaders::controller {
    class ControllerEvent;

    class EntityController : public observer::Observer, public observer::Observable {
        virtual void checkInput() = 0;

    public:
        void handleEvent(std::shared_ptr<spaceinvaders::Event> &event) override;
    };

}


#endif //SPACEINVADERS_ENTITYCONTROLLER_H
