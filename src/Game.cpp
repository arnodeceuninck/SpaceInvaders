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
#include "Events/LoadLevel.h"
#include "Events/GameEnded.h"
#include "Events/LevelEnded.h"

//#define MAX_CYCLES_PER_SECOND 30 // The number of max game loops allowed in one second
#define MAX_CYCLES_PER_SECOND 30
#define MIN_TIME_PER_CYCLE 1000000000.0 / MAX_CYCLES_PER_SECOND // The minimum required time in seconds as double between each clock cycle

namespace spaceinvaders {

    void Game::Start() {

        auto wptr = std::shared_ptr<Game>(this, [](Game *) {});

        // Initialise the game Model, View & Controller
        initModel();
        initView();
        initController();

        gameModel->load();

        gameRunning = true;

        gameLoop();
    }

    void Game::initModel() {
        gameModel = std::make_shared<model::GameModel>();
        gameModel->getGameWorld()->addObserver(gameModel);
        gameModel->addObserver(shared_from_this());
    }

    void Game::initView() {
        gameWindow = std::make_shared<GameWindow>(800, 600);
        gameRepresentation = std::make_shared<view::GameRepresentation>(gameModel, gameWindow);
        gameModel->addObserver(gameRepresentation);
    }

    void Game::initController() {
        gameController = std::make_shared<controller::GameController>(gameWindow);
        gameWindow->addObserver(gameController);
        gameController->addObserver(shared_from_this());
    }

    void Game::gameLoop() {

        // Keep track of the elapsed time after each loop
        Stopwatch clock{};

        while (gameRunning) {

            // Check whether enough time has passed to start the next cycle
            if (clock.elapsedTime() < MIN_TIME_PER_CYCLE) {
                continue;
            }

            // Remember the elapsed time for the calculations
            double elapsedSeconds = clock.elapsedTime() / 1000000000;

            // Restart the timer
            clock.reset();

            if (showingMessage) {
                messageTime -= elapsedSeconds;
                if (messageTime < 0) {
                    gameModel->load();
                    showingMessage = false;
                }
                continue;
            }

            // The game loop itself
            gameController->update(elapsedSeconds);
//            gameRepresentation->getWindow()->checkInput();
            gameModel->update(elapsedSeconds);
            // gameView will get updated while observing the gameModel

            if (!showingMessage) {
                gameRepresentation->update(); // Update the window
            }

        }
    }

    Game::Game() {
        Start();
    }

    void Game::handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) {
        if (auto ll = std::dynamic_pointer_cast<spaceinvaders::event::LoadLevel>(event)) {
            loadLevel(ll->getLevel());
        } else if (auto ge = std::dynamic_pointer_cast<spaceinvaders::event::GameEnded>(event)) {
            gameRunning = false;
        } else if (auto le = std::dynamic_pointer_cast<spaceinvaders::event::LevelEnded>(event)) {
            if (le->isWin()) {
                gameRepresentation->showMessage("Victory");
            } else {
                gameRepresentation->showMessage("Dead");
            }
            messageTime = 2;
            showingMessage = true;
//            gameRepresentation->update();
        }
    }

    void Game::loadLevel(std::string level) {

        gameRepresentation->reset();
        gameController->reset();

        loader::LevelLoader loader{level};
        loader.addObserver(gameModel);
        loader.loadInto(gameRepresentation, gameController);
    }

}
