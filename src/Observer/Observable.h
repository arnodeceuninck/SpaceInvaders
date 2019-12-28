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

        /**
         * Add an observer to which your events get broadcasted
         * @param observer a shared_ptr to this observer
         */
        void addObserver(const std::shared_ptr<Observer> &observer);

        /**
         * Broadcast an event to your observers
         * @param event The event being broadcasted
         */
        void notifyObservers(std::shared_ptr<spaceinvaders::event::Event> &event);
    };

}


#endif //SPACEINVADERS_OBSERVABLE_H
