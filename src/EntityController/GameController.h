//
// Created by arno on 14/12/2019.
//

#ifndef SPACEINVADERS_GAMECONTROLLER_H
#define SPACEINVADERS_GAMECONTROLLER_H

#include "EntityController.h"
#include "../GameWindow.h"

#include <list>

namespace spaceinvaders::controller {
    class GameController : public EntityController {
    public:
        void reset();

        void checkInput();

        void update(double elapsedSeconds);

        void addController(std::shared_ptr<EntityController> controller);

        GameController();

        GameController(const std::shared_ptr<spaceinvaders::GameWindow> &gameWindow);

        void handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) override;

    private:
        std::list<std::shared_ptr<EntityController>> controlEntities;
        std::shared_ptr<spaceinvaders::GameWindow> gameWindow;
    };
}


#endif //SPACEINVADERS_GAMECONTROLLER_H
