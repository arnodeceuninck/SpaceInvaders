//
// Created by arno on 15/12/2019.
//

#include "WindowCloseListener.h"

void spaceinvaders::controller::WindowCloseListener::handleEvent(sf::Event &event) {
    if (event.type == sf::Event::Closed)
        notifyObservers(event);
}
