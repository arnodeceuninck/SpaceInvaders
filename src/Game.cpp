//
// Created by arno on 14/12/2019.
//

#include <iostream>
#include "Game.h"

#include "EntityRepresentation/GameRepresentation.h"
#include "EntityController/GameController.h"
#include "EntityModel/GameModel.h"

#include "GameWindow.h"

#include "Stopwatch.h"
#include "EntityController/PlayerController.h"
#include "Loader/LevelLoader.h"

//#define MAX_CYCLES_PER_SECOND 30 // The number of max game loops allowed in one second
#define MAX_CYCLES_PER_SECOND 30
#define MIN_TIME_PER_CYCLE 1000000000.0 / MAX_CYCLES_PER_SECOND // The minimum required time in seconds as double between each clock cycle

namespace spaceinvaders {

    void Game::Start() {

        // Initialise the game Model, View & Controller
        initModel();
        initView();
        initController();


        loader::LevelLoader loader{"lvl0.json"};
        loader.addObserver(gameModel);
        loader.loadInto(gameRepresentation, gameController);

        gameRunning = true;

        gameLoop();
    }

    void Game::initModel() {
        gameModel = std::make_shared<model::GameModel>();
        gameModel->getGameWorld()->addObserver(gameModel);
    }

    void Game::initView() {
        gameWindow = std::make_shared<GameWindow>(800, 600);
        gameRepresentation = std::make_shared<view::GameRepresentation>(gameModel, gameWindow);
        gameModel->addObserver(gameRepresentation);
    }

    void Game::initController() {
        gameController = std::make_shared<controller::GameController>(gameWindow);
        gameWindow->addObserver(gameController);
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
            i++;
//            std::cout << ++i << std::endl;

            // Remember the elapsed time for the calculations
            double elapsedSeconds = clock.elapsedTime() / 1000000000;

            // Restart the timer
            clock.reset();

            // The game loop itself
            gameController->update(elapsedSeconds);
//            gameRepresentation->getWindow()->checkInput();
            gameModel->update(elapsedSeconds);
            // gameView will get updated while observing the gameModel

            gameRepresentation->update(); // Update the window

            if (i >= 1500) {
                gameRunning = false; // TODO: Remove this line
            }
        }
    }

    Game::Game() {
        Start();
    }

    void Game::handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) {
        gameRunning = false;
    }

}
