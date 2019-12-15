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
    // Virtual function couldn't use a template, but is required, because a subject must be able to notify different events
    template<class T>
    class Observable {
        std::set<std::shared_ptr<Observer<T>>> observers;

    public:

        void addObserver(std::shared_ptr<Observer<T>> observer);

        void removeObserver(std::shared_ptr<Observer<T>> observer);

        void notifyObservers(T &t);
    };

}


#endif //SPACEINVADERS_OBSERVABLE_H
