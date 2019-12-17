//
// Created by arno on 15/12/2019.
//

#ifndef SPACEINVADERS_WINDOWCLOSELISTENER_H
#define SPACEINVADERS_WINDOWCLOSELISTENER_H

#include <SFML/Window/Event.hpp>
#include "../Observer/Observer.h"
#include "../Observer/Observable.h"

namespace spaceinvaders::controller {
    class WindowCloseListener : public observer::Observer<sf::Event>, public observer::Observable<sf::Event> {
        void handleEvent(sf::Event &event) override;
    };
}


#endif //SPACEINVADERS_WINDOWCLOSELISTENER_H
