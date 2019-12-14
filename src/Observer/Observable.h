//
// Created by arno on 14/12/2019.
//

#ifndef SPACEINVADERS_OBSERVABLE_H
#define SPACEINVADERS_OBSERVABLE_H

#include <set>
#include <memory>

#include "Observer.h"

namespace observer {
    // aka Subject
    class Observable {
        std::set<std::shared_ptr<Observer>> observers;

        virtual void addObserver(std::shared_ptr<Observer> observer) = 0;

        virtual void removeObserver(std::shared_ptr<Observer> observer) = 0;

        virtual void notifyObservers() = 0;
    };
}


#endif //SPACEINVADERS_OBSERVABLE_H
