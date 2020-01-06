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
        /**
         * Resets all controllers (to load a new level)
         */
        void reset();

        /**
         * Check for new input
         */
        void checkInput();

        /**
         * Update everything that happened during the past seconds
         * @param elapsedSeconds
         */
        void update(double elapsedSeconds);

        /**
         * Add a controller
         * @param controller
         */
        void addController(const std::shared_ptr<EntityController> &controller);

        /**
         * Constructor
         */
        GameController();

        /**
         * Constructor with window
         * @param gameWindow
         */
        explicit GameController(std::shared_ptr<spaceinvaders::GameWindow> gameWindow);

        /**
         * Handle an event
         * @param event
         */
        void handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) override;

    private:
        std::list<std::shared_ptr<EntityController>> controlEntities;
        std::shared_ptr<spaceinvaders::GameWindow> gameWindow;
    };
}


#endif //SPACEINVADERS_GAMECONTROLLER_H
