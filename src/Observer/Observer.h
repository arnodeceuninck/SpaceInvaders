//
// Created by arno on 14/12/2019.
//

#ifndef SPACEINVADERS_OBSERVER_H
#define SPACEINVADERS_OBSERVER_H

namespace observer {
    template<class T>
    class Observer {
    public:
        virtual void handleEvent(T &t) = 0;
    };
}


#endif //SPACEINVADERS_OBSERVER_H
