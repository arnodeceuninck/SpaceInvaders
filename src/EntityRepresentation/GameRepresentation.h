//
// Created by arno on 14/12/2019.
//

#ifndef SPACEINVADERS_GAMEREPRESENTATION_H
#define SPACEINVADERS_GAMEREPRESENTATION_H

#include "../Observer/Observable.h"
#include "EntityRepresentation.h"
#include "Transformation.h"
#include <list>

namespace sf {
    class RenderWindow;
}

namespace spaceinvaders::model {
    class ModelChangedEvent;

    class GameModel;
}

namespace spaceinvaders::view {
    class GameRepresentation : public EntityRepresentation {
    public:
        void handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) override;

        std::list<std::shared_ptr<EntityRepresentation>> representationEntities; // Holds a seperate list, so observer can be implemented with weak_ptrs and to assure there is always a shared pointer for shared_from_this

    public:

        void clear();

        void draw() override;

        void update();

        GameRepresentation(std::shared_ptr<spaceinvaders::model::GameModel> gameModel,
                           std::shared_ptr<GameWindow> gameWindow);

        void checkInput();

        void checkEvent();

    private:

    };
}


#endif //SPACEINVADERS_GAMEREPRESENTATION_H
