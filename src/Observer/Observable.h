//
// Created by arno on 14/12/2019.
//

#ifndef SPACEINVADERS_OBSERVABLE_H
#define SPACEINVADERS_OBSERVABLE_H

#include <list>

#include "Observer.h"

namespace spaceinvaders::observer {

    // aka Subject
    class Observable {
        std::list<std::weak_ptr<Observer>> observers; // Can't be placed in a set, since wp's don't have operator<

    public:

        void addObserver(std::shared_ptr<Observer> observer);

        void removeObserver(std::shared_ptr<Observer> observer);

        void notifyObservers(std::shared_ptr<spaceinvaders::event::Event> &event);
    };

}


#endif //SPACEINVADERS_OBSERVABLE_H
