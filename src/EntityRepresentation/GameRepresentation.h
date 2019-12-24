//
// Created by arno on 14/12/2019.
//

#ifndef SPACEINVADERS_GAMEREPRESENTATION_H
#define SPACEINVADERS_GAMEREPRESENTATION_H

#include "../Observer/Observable.h"
#include "EntityRepresentation.h"
#include "Transformation.h"

namespace sf {
    class RenderWindow;
}

namespace spaceinvaders::model {
    class ModelChangedEvent;

    class GameModel;
}

namespace spaceinvaders::view {
    class GameRepresentation : public observer::Observable, public EntityRepresentation {
    public:
        void handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) override;

    public:

        void clear();

        void draw() override;

        void update();

        GameRepresentation(std::shared_ptr<spaceinvaders::model::GameModel> gameModel);

        void checkInput();

        void checkEvent();

    private:

    };
}


#endif //SPACEINVADERS_GAMEREPRESENTATION_H
