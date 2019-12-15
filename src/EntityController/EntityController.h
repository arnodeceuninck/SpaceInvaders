//
// Created by arno on 14/12/2019.
//

#ifndef SPACEINVADERS_ENTITYCONTROLLER_H
#define SPACEINVADERS_ENTITYCONTROLLER_H

#include <SFML/Window/Event.hpp>
#include "../Observer/Observable.h"
#include "../Observer/Observer.h"
#include "ControllerEvent.h"

namespace spaceinvaders::controller {

    class EntityController : public observer::Observer<sf::Event>, public observer::Observable<ControllerEvent> {
        virtual void checkInput() = 0;

    public:
        void handleEvent(sf::Event &event) override;
    };

}


#endif //SPACEINVADERS_ENTITYCONTROLLER_H
