//
// Created by arno on 14/12/2019.
//

#ifndef SPACEINVADERS_GAMEREPRESENTATION_H
#define SPACEINVADERS_GAMEREPRESENTATION_H

#include "../Observer/Observable.h"
#include "EntityRepresentation.h"

namespace sf {
    class RenderWindow;
}

namespace spaceinvaders::model {
    class ModelChangedEvent;
}

namespace spaceinvaders::view {
    class GameRepresentation : public observer::Observable, public EntityRepresentation {
    public:
        GameRepresentation();

        void checkEvent();

        const GameWindow &getWindow() const;

    private:
        GameWindow window;
    };
}


#endif //SPACEINVADERS_GAMEREPRESENTATION_H
