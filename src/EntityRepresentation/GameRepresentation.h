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
        void handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) override;

    public:
        void draw() override;

        GameRepresentation();

        void checkInput();

        void checkEvent();

    private:

    };
}


#endif //SPACEINVADERS_GAMEREPRESENTATION_H
