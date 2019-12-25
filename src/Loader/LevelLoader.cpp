//
// Created by arno on 23/12/2019.
//

#include "LevelLoader.h"
#include "ShipLoader.h"
#include "../EntityModel/PlayerShip.h"
#include "../EntityRepresentation/MovingEntityRepresentation.h"
#include "../Events/EntityCreatedEvent.h"
#include "../EntityRepresentation/GameRepresentation.h"
#include "../EntityController/PlayerController.h"
#include "../EntityModel/EnemyShip.h"
#include "../EntityController/GameController.h"
#include "../EntityController/EnemyController.h"

void spaceinvaders::loader::LevelLoader::loadInto(std::shared_ptr<spaceinvaders::model::WorldModel> worldModel,
                                                  std::shared_ptr<spaceinvaders::view::GameRepresentation> gameRepresentation,
                                                  std::shared_ptr<spaceinvaders::controller::GameController> gameController) {
    rapidjson::Document input = getDocument();

    if (auto playerFile = input["player"].GetString()) {

        // Create a player ship, it's representation and it's controller
        auto playerShip = std::make_shared<spaceinvaders::model::PlayerShip>();

        auto shipRepresentation = std::make_shared<spaceinvaders::view::MovingEntityRepresentation>(
                gameRepresentation->getWindow(), gameRepresentation->getTransformation());
        auto shipController = std::make_shared<spaceinvaders::controller::PlayerController>(playerShip);

        // Load the contents of the player file to the ship
        ShipLoader shipLoader{playerFile};
        shipLoader.loadInto(playerShip, shipRepresentation);

        std::shared_ptr<spaceinvaders::model::Ship> ship = std::dynamic_pointer_cast<spaceinvaders::model::Ship>(
                playerShip);

        linkObservers(worldModel, gameRepresentation, ship, shipRepresentation, shipController, gameController, true);

    }

    rapidjson::Value &enemiesValue = input["enemies"];

    std::shared_ptr<spaceinvaders::model::EnemyShip> leftMostEnemy;
    std::shared_ptr<spaceinvaders::model::EnemyShip> rightMostEnemy;
    double minPos = std::numeric_limits<double>::infinity();
    double maxPos = -std::numeric_limits<double>::infinity();

    for (rapidjson::SizeType i = 0; i < enemiesValue.Size(); i++) {

        rapidjson::Value &enemyObj = enemiesValue[i];

        std::string enemyJson = enemyObj["enemy"].GetString();
        double enemyX = enemyObj["x"].GetDouble();
        double enemyY = enemyObj["y"].GetDouble();

        // Create a player ship, it's representation and it's controller
        auto enemyShip = std::make_shared<spaceinvaders::model::EnemyShip>(enemyX, enemyY);

        auto shipRepresentation = std::make_shared<spaceinvaders::view::MovingEntityRepresentation>(
                gameRepresentation->getWindow(), gameRepresentation->getTransformation());
        auto enemyController = std::make_shared<spaceinvaders::controller::EnemyController>(enemyShip);

        // Load the contents of the player file to the ship
        ShipLoader shipLoader{enemyJson};
        shipLoader.loadInto(enemyShip, shipRepresentation);

        if (enemyX < minPos) {
            minPos = enemyX;
            leftMostEnemy = enemyShip;
        }
        if (enemyX > maxPos) {
            maxPos = enemyX;
            rightMostEnemy = enemyShip;
        }

        // TODO: move outside loop
        enemyController->setLeftMostEnemy(leftMostEnemy);
        enemyController->setRightMostEnemy(rightMostEnemy);

        std::shared_ptr<spaceinvaders::model::Ship> ship = std::dynamic_pointer_cast<spaceinvaders::model::Ship>(
                enemyShip);
        std::shared_ptr<spaceinvaders::controller::ShipController> shipController = std::dynamic_pointer_cast<spaceinvaders::controller::ShipController>(
                enemyController);
        linkObservers(worldModel, gameRepresentation, ship, shipRepresentation, shipController, gameController, false);


    }
}

void spaceinvaders::loader::LevelLoader::linkObservers(std::shared_ptr<spaceinvaders::model::WorldModel> &worldModel,
                                                       std::shared_ptr<spaceinvaders::view::GameRepresentation> &gameRepresentation,
                                                       std::shared_ptr<spaceinvaders::model::Ship> &ship,
                                                       const std::shared_ptr<spaceinvaders::view::MovingEntityRepresentation> &shipRepresentation,
                                                       const std::shared_ptr<spaceinvaders::controller::ShipController> &shipController,
                                                       std::shared_ptr<spaceinvaders::controller::GameController> gameController,
                                                       bool playerShip) const {// Link the view to the model

    ship->addObserver(shipRepresentation);

    // Link the model to the controller
    worldModel->addObserver(ship);
    ship->addObserver(worldModel);

    gameRepresentation->addObserver(shipRepresentation); // Required for updating

    // Link controller and gameRepresentation (required for notifying of WindowInteractions)
    if (playerShip) {
        gameRepresentation->getWindow()->addObserver(shipController);
    } else {
        gameController->addObserver(shipController);
    }

    ship->addObserver(gameRepresentation); // Required for creating bullets representations when bullet fired

    // Notify the view an entity has been created
    std::shared_ptr<spaceinvaders::event::Event> entityCreatedEvent = std::make_shared<spaceinvaders::event::EntityCreatedEvent>(
            ship);
    ship->notifyObservers(entityCreatedEvent);
}

spaceinvaders::loader::LevelLoader::LevelLoader(const std::string &filename) : Loader(filename) {}
