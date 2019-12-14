//
// Created by arno on 14/12/2019.
//

#ifndef SPACEINVADERS_GAME_H
#define SPACEINVADERS_GAME_H

#include <SFML/Graphics.hpp>
#include "EntityModel/WorldModel.h"

namespace spaceinvaders {

    class Game {
    public:
        static void Start();

    private:

//        model::WorldModel worldModel;

        std::shared_ptr<sf::RenderWindow> window;

        static void initModel();

        static void initView();

        static void initController();

        static bool gameRunning;

        static void gameLoop();
    };

}

#endif //SPACEINVADERS_GAME_H
