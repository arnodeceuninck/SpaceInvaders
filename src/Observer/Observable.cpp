//
// Created by arno on 14/12/2019.
//

#include "Observable.h"

void observer::Observable::addObserver(std::shared_ptr<Observer> observer) {
    observers.insert(observer);
}

void observer::Observable::removeObserver(std::shared_ptr<Observer> observer) {
    observers.erase(observer);
}

void observer::Observable::notifyObservers() {
    for (auto observer: observers) {
        observer->handleEvent();
    }
}
