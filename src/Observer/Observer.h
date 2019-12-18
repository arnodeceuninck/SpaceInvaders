//
// Created by arno on 14/12/2019.
//

#ifndef SPACEINVADERS_OBSERVER_H
#define SPACEINVADERS_OBSERVER_H

#include <memory>

namespace spaceinvaders {
    class Event;
}

namespace observer {
    class Observer {
    public:
        virtual void handleEvent(std::shared_ptr<spaceinvaders::Event> &event) = 0;
    };
}


#endif //SPACEINVADERS_OBSERVER_H
