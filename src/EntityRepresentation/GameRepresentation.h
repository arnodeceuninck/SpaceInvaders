//
// Created by arno on 14/12/2019.
//

#ifndef SPACEINVADERS_GAMEREPRESENTATION_H
#define SPACEINVADERS_GAMEREPRESENTATION_H


#include <memory>
#include "../Observer/Observable.h"
#include "../EntityModel/ModelChangedEvent.h"
#include "SFML/Graphics.hpp"
#include "../GameWindow.h"

namespace sf {
    class RenderWindow;
}

namespace spaceinvaders::view {
    class GameRepresentation : public observer::Observable<spaceinvaders::model::ModelChangedEvent> {
    public:
        GameRepresentation();

        void checkEvent();

        const GameWindow &getWindow() const;

    private:
        GameWindow window;
    };
}


#endif //SPACEINVADERS_GAMEREPRESENTATION_H
