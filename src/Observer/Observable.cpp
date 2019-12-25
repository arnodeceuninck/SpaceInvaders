//
// Created by arno on 14/12/2019.
//

#include <SFML/Window/Event.hpp>
#include "Observable.h"

void observer::Observable::addObserver(std::shared_ptr<Observer> observer) {
    // observers.insert(observer); // for a set
    observers.push_back(observer); // for a vector
}

void observer::Observable::removeObserver(std::shared_ptr<Observer> observer) {
    auto obs = std::find(observers.begin(), observers.end(), observer);
    if (obs != observers.end()) {
        observers.erase(obs); // for a set
    }
//    observers.erase(std::find(observers.begin(), observers.end(), observer)); // Also not possible, no operator== for weak ptr's

}

void observer::Observable::notifyObservers(std::shared_ptr<spaceinvaders::event::Event> &event) {
    for (auto observer: observers) {
//        if (auto observerSP = observer.lock()) {
        if (observer.get() != nullptr) {
            observer->handleEvent(event);
        }
//        }
    }
}
