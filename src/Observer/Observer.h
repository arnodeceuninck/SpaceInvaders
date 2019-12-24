//
// Created by arno on 14/12/2019.
//

#ifndef SPACEINVADERS_OBSERVER_H
#define SPACEINVADERS_OBSERVER_H

#include <memory>

namespace spaceinvaders::event {
    class Event;
}

namespace observer {
//    class Obsevable;
    class Observer {
    public:
        virtual void handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) = 0;

        virtual ~Observer();
    };
}


#endif //SPACEINVADERS_OBSERVER_H
