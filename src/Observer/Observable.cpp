//
// Created by arno on 14/12/2019.
//

#include <SFML/Window/Event.hpp>
#include "Observable.h"

void observer::Observable::addObserver(std::weak_ptr<Observer> observer) {
    // observers.insert(observer); // for a set
    observers.push_back(observer); // for a vector
}

void observer::Observable::removeObserver(std::shared_ptr<Observer> observer) {
    // observers.erase(observer); // for a set
//    observers.erase(std::find(observers.begin(), observers.end(), observer)); // Also not possible, no operator== for weak ptr's

}

void observer::Observable::notifyObservers(std::shared_ptr<spaceinvaders::Event> &event) {
    for (auto observer: observers) {
        if (auto observerSP = observer.lock()) {
            observerSP->handleEvent(event);
        }
    }
}
