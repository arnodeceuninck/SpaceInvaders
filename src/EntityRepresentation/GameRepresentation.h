//
// Created by arno on 14/12/2019.
//

#ifndef SPACEINVADERS_GAMEREPRESENTATION_H
#define SPACEINVADERS_GAMEREPRESENTATION_H


#include <memory>
#include "../Observer/Observable.h"
#include "../EntityModel/ModelChangedEvent.h"

namespace sf {
    class RenderWindow;
}

namespace spaceinvaders::view {
    class GameRepresentation : public observer::Observable<spaceinvaders::model::ModelChangedEvent> {
    public:
        GameRepresentation();

        void checkEvent();

    private:
        std::shared_ptr<sf::RenderWindow> window;
    };
}


#endif //SPACEINVADERS_GAMEREPRESENTATION_H
