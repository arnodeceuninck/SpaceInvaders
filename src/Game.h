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
#include "Observer/Observer.h"
#include "EntityController/WindowCloseListener.h"

namespace spaceinvaders {

    class Game : public observer::Observer<sf::Event> {
    public:
        Game();

        void handleEvent(sf::Event &event) override;

    private:
        void Start();

        controller::WindowCloseListener wcl;
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
