//
// Created by arno on 14/12/2019.
//

#ifndef SPACEINVADERS_GAME_H
#define SPACEINVADERS_GAME_H

#include "Observer/Observer.h"
#include <memory>

namespace sf {
    class RenderWindow;
}

namespace spaceinvaders {

    namespace model {
        class GameModel;
    }

    namespace view {
        class GameRepresentation;
    }

    namespace controller {
        class GameController;
    }

    class GameWindow;

    class Game : public observer::Observer, public std::enable_shared_from_this<Game> {
    public:
        /**
         * Standard constructor for the game, sets everything up and starts the gameloop
         */
        Game();

        /**
         * Handles following events: LoadLevel, LevelEnded and GameEnded
         * @param event One of the events described above
         */
        void handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) override;


    private:
        void Start();

        std::shared_ptr<model::GameModel> gameModel;
        std::shared_ptr<view::GameRepresentation> gameRepresentation;
        std::shared_ptr<controller::GameController> gameController;

        std::shared_ptr<GameWindow> gameWindow;

        bool showingMessage = false;
        double messageTime = 0;

        void initModel();

        void initView();

        void loadLevel(const std::string &level);

        void initController();

        bool gameRunning{};

        void gameLoop();
    };

}

#endif //SPACEINVADERS_GAME_H
