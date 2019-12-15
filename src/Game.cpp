//
// Created by arno on 14/12/2019.
//

#include <chrono>
#include "Game.h"
#include "Clock.h"

#define MAX_CYCLES_PER_SECOND 30 // The number of max game loops allowed in one second
#define MIN_TIME_PER_CYCLE 1.0 / MAX_CYCLES_PER_SECOND // The minimum required time in seconds as double between each clock cycle

namespace spaceinvaders {

    void Game::Start() {
        // Initialise the game Model, View & Controller
        initModel();
        initView();
        initController();

        gameLoop();
    }

    void Game::initModel() {

    }

    void Game::initView() {

    }

    void Game::initController() {

    }

    void Game::gameLoop() {

        // Keep track of the elapsed time after each loop
        Clock clock{};

        while (gameRunning) {

            // Check whether enough time has passed to start the next cycle
            if (clock.elapsedTime() < MIN_TIME_PER_CYCLE) {
                continue;
            }

            // Remember the elapsed time for the calculations
            double elapsedSeconds = clock.elapsedTime();

            // Restart the timer
            clock.reset();

            // The game loop itself
//            gameController->checkInput();
//            gameModel->update(elapsedSeconds);
            // gameView will get updated while observing the gameModel
        }
    }

}
