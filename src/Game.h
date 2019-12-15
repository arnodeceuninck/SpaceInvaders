//
// Created by arno on 14/12/2019.
//

#ifndef SPACEINVADERS_GAME_H
#define SPACEINVADERS_GAME_H

#include <SFML/Graphics.hpp>
#include "EntityModel/WorldModel.h"
#include "EntityModel/GameModel.h"
#include "EntityRepresentation/GameRepresentation.h"
#include "EntityController/GameController.h"

namespace spaceinvaders {

    class Game {
    public:
        void Start();

    private:

        model::GameModel gameModel;
        view::GameRepresentation gameRepresentation;
        controller::GameController gameController;

        std::shared_ptr<sf::RenderWindow> window;

        void initModel();

        void initView();

        void initController();

        bool gameRunning;

        void gameLoop();
    };

}

#endif //SPACEINVADERS_GAME_H
