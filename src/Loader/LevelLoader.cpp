//
// Created by arno on 23/12/2019.
//

#include "LevelLoader.h"
#include "ShipLoader.h"
#include "../EntityModel/PlayerShip.h"
#include "../Events/EntityCreatedEvent.h"
#include "../EntityRepresentation/GameRepresentation.h"
#include "../EntityController/PlayerController.h"
#include "../EntityModel/EnemyShip.h"
#include "../EntityController/GameController.h"
#include "../EntityController/EnemiesController.h"
#include "../EntityController/EnemyController.h"

// Linking scheme

// NOTE: (Not anymore required, since observers will work with weak_ptr's) All observers also have a pointer to their observable, for easily removing themselves

// RequiredLinks: (observer -> observable)
// ( ) EntityRepresentation -> GameRepresentation : Required for inside representation changes (e.g. windowResize, ...) // Does Gamerepresentation
// ( ) GameRepresentation -> EntityRepresentation // Does GameRepresentation
// ( ) EntityRepresentation -> EntityModel : Required for inside model changes (e.g. modelDestroyed, position changed, ...) // Does ShipLoader
// ( ) EntityModel -> EntityController : Required for control events (e.g. moving left, ...) // Does LevelLoader
// ( ) EntityModel -> GameWorld : Required for inside model changes (e.g. update, ...) NOTE: GameModel is for controlling next level, ... // Does GameModel
// ( ) GameWorld -> EntityModel // Does GameModel
// ( ) EntityController -> GameController : Required for internal control changes (e.g. update, ...) // Does LevelLoader

void spaceinvaders::loader::LevelLoader::loadInto(
        std::shared_ptr<spaceinvaders::view::GameRepresentation> gameRepresentation,
        std::shared_ptr<spaceinvaders::controller::GameController> gameController) {
    rapidjson::Document input = getDocument();

    if (auto playerFile = input["player"].GetString()) {

        // Create a player ship, it's representation and it's controller
        auto playerShip = std::make_shared<spaceinvaders::model::PlayerShip>();
        auto shipController = std::make_shared<spaceinvaders::controller::PlayerController>(playerShip);

        // Load the contents of the player file to the ship
        ShipLoader shipLoader{playerFile};
        shipLoader.loadInto(playerShip, gameRepresentation);

        gameController->addObserver(
                shipController); // TODO: GameController should submit keyEvents to all their observers, meaning gameController is an observer of GameWindow
        shipController->addObserver(playerShip);
    }

    rapidjson::Value &enemiesValue = input["enemies"];

    std::shared_ptr<spaceinvaders::model::EnemyShip> leftMostEnemy; // TODO: add function findLeftMostEnemy to update these once an enemy get destroyed
    std::shared_ptr<spaceinvaders::model::EnemyShip> rightMostEnemy;
    double minPos = std::numeric_limits<double>::infinity();
    double maxPos = -std::numeric_limits<double>::infinity();

    auto enemiesController = std::make_shared<spaceinvaders::controller::EnemiesController>(
            nullptr); // TODO: remvoe entity from controller, only work with events

    for (rapidjson::SizeType i = 0; i < enemiesValue.Size(); i++) {

        rapidjson::Value &enemyObj = enemiesValue[i];

        std::string enemyJson = enemyObj["enemy"].GetString();
        double enemyX = enemyObj["x"].GetDouble();
        double enemyY = enemyObj["y"].GetDouble();

        // Create a player ship, it's representation and it's controller
        auto enemyShip = std::make_shared<spaceinvaders::model::EnemyShip>(enemyX, enemyY);
        auto enemyController = std::make_shared<spaceinvaders::controller::EnemyController>(enemyShip);
        enemiesController->addObserver(enemyShip);
        enemyController->addObserver(enemyShip);

        // Load the contents of the player file to the ship
        ShipLoader shipLoader{enemyJson};
        shipLoader.loadInto(enemyShip, gameRepresentation);

        if (enemyX < minPos) {
            minPos = enemyX;
            leftMostEnemy = enemyShip;
        }
        if (enemyX > maxPos) {
            maxPos = enemyX;
            rightMostEnemy = enemyShip;
        }

        gameController->addObserver(enemyController);
        enemyController->addObserver(enemyShip);

    }

    gameController->addObserver(enemiesController);
    enemiesController->addObserver(gameController);

    enemiesController->setLeftMostEnemy(leftMostEnemy);
    enemiesController->setRightMostEnemy(rightMostEnemy);

}


spaceinvaders::loader::LevelLoader::LevelLoader(const std::string &filename) : Loader(filename) {}
