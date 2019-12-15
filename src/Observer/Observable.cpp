//
// Created by arno on 14/12/2019.
//

#include "Observable.h"

template<class T>
void observer::Observable<T>::addObserver(std::shared_ptr<Observer<T>> observer) {
    observers.insert(observer);
}

template<class T>
void observer::Observable<T>::removeObserver(std::shared_ptr<Observer<T>> observer) {
    observers.erase(observer);
}

template<class T>
void observer::Observable<T>::notifyObservers(T &t) {
    for (auto observer: observers) {
        observer->handleEvent(t);
    }
}
