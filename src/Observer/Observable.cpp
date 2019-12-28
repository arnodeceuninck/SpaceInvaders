//
// Created by arno on 14/12/2019.
//

#include "Observable.h"

void
spaceinvaders::observer::Observable::addObserver(const std::shared_ptr<spaceinvaders::observer::Observer> &observer) {
    // observers.insert(observer); // for a set
    observers.push_back(observer); // for a vector
}

void spaceinvaders::observer::Observable::notifyObservers(std::shared_ptr<spaceinvaders::event::Event> &event) {
    for (const auto &observer: observers) {
        if (auto observerSP = observer.lock()) {
            observerSP->handleEvent(event);
        }
    }
}
