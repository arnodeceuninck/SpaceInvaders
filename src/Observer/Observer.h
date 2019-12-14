//
// Created by arno on 14/12/2019.
//

#ifndef SPACEINVADERS_OBSERVER_H
#define SPACEINVADERS_OBSERVER_H

namespace observer {
    class Observer {
    public:
        virtual void handleEvent() = 0;
    };
}


#endif //SPACEINVADERS_OBSERVER_H
