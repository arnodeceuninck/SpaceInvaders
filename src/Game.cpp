//
// Created by arno on 14/12/2019.
//

#include <iostream>
#include "Game.h"

#include "EntityRepresentation/GameRepresentation.h"
#include "EntityController/GameController.h"
#include "EntityModel/GameModel.h"

#include "Stopwatch.h"

#define MAX_CYCLES_PER_SECOND 3 // The number of max game loops allowed in one second
#define MIN_TIME_PER_CYCLE 1000000000.0 / MAX_CYCLES_PER_SECOND // The minimum required time in seconds as double between each clock cycle

namespace spaceinvaders {

    void Game::Start() {

        // Initialise the game Model, View & Controller
        initModel();
        initView();
        initController();

        gameRunning = true;

        gameLoop();
    }

    void Game::initModel() {
        gameModel = std::make_shared<model::GameModel>();
    }

    void Game::initView() {
        gameRepresentation = std::make_shared<view::GameRepresentation>();
    }

    void Game::initController() {
        gameController = std::make_shared<controller::GameController>();
        gameController->addObserver(
                weak_from_this()); // Because appearently there isn't an immediate way to convert a raw pointer to a weak pointer
        // TODO: Is it possible to cast raw pointer (this) to shared pointer?
//        gameRepresentation->getWindow()->addObserver();
//        wcl.addObserver(static_cast<const std::shared_ptr<Observer < sf::Event>>>(this));
//        gameWindow.addObserver();
    }

    void Game::gameLoop() {

        // Keep track of the elapsed time after each loop
        Stopwatch clock{};

        int i = 0;
        while (gameRunning) {

            // Check whether enough time has passed to start the next cycle
            if (clock.elapsedTime() < MIN_TIME_PER_CYCLE) {
                continue;
            }
            std::cout << ++i << std::endl;

            // Remember the elapsed time for the calculations
            double elapsedSeconds = clock.elapsedTime() / 1000000000;

            // Restart the timer
            clock.reset();

            // The game loop itself
            gameRepresentation->getWindow()->checkInput();
            gameModel->update(elapsedSeconds);
            // gameView will get updated while observing the gameModel
        }
    }

    Game::Game() {
        Start();
    }

    void Game::handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) {
        gameRunning = false;
    }

}
