//
// Created by arno on 14/12/2019.
//

#ifndef SPACEINVADERS_OBSERVABLE_H
#define SPACEINVADERS_OBSERVABLE_H

#include <set>

#include "Observer.h"

namespace observer {

    // aka Subject
    class Observable {
        std::set<std::shared_ptr<Observer>> observers;

    public:

        void addObserver(std::shared_ptr<Observer> observer);

        void removeObserver(std::shared_ptr<Observer> observer);

        void notifyObservers(std::shared_ptr<spaceinvaders::Event> &event);
    };

}


#endif //SPACEINVADERS_OBSERVABLE_H
