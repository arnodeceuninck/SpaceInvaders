//
// Created by arno on 23/12/2019.
//

#include <iostream>
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
#include "../Exceptions/AttributeMissing.h"

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
        const std::shared_ptr<spaceinvaders::view::GameRepresentation> &gameRepresentation,
        const std::shared_ptr<spaceinvaders::controller::GameController> &gameController) {
    rapidjson::Document input = getDocument();

    std::string attribute = "player";
    checkAttribute(input, attribute);
    if (auto playerFile = input[attribute.c_str()].GetString()) {

        // Create a player ship, it's representation and it's controller
        auto playerShip = std::make_shared<spaceinvaders::model::PlayerShip>();
        auto shipController = std::make_shared<spaceinvaders::controller::PlayerController>();

        // Load the contents of the player file to the ship
        ShipLoader shipLoader{playerFile};
        std::string spriteFile;
        shipLoader.loadInto(playerShip, spriteFile);

        std::shared_ptr<spaceinvaders::event::Event> event = std::make_shared<spaceinvaders::event::EntityCreatedEvent>(
                playerShip, spriteFile);
        notifyObservers(
                event);

        gameController->addController(
                shipController);
        shipController->addObserver(playerShip);
    }

    // If null, it won't be looped through
    rapidjson::Value &enemiesValue = input["enemies"];

    auto enemiesController = std::make_shared<spaceinvaders::controller::EnemiesController>();

    for (rapidjson::SizeType i = 0; i < enemiesValue.Size(); i++) {

        rapidjson::Value &enemyObj = enemiesValue[i];

        if (enemyObj["enemy"].IsNull() or enemyObj["x"].IsNull() or enemyObj["y"].IsNull())
            throw spaceinvaders::exception::AttributeMissing("enemy, x or y");

        std::string enemyJson = enemyObj["enemy"].GetString();
        double enemyX = enemyObj["x"].GetDouble();
        double enemyY = enemyObj["y"].GetDouble();

        // Create a player ship, it's representation and it's controller
        auto enemyShip = std::make_shared<spaceinvaders::model::EnemyShip>(enemyX, enemyY);

        // Load the contents of the player file to the ship
        ShipLoader shipLoader{enemyJson};
        std::string spriteFile;
        shipLoader.loadInto(enemyShip, spriteFile);

        auto enemyController = std::make_shared<spaceinvaders::controller::EnemyController>(
                enemyShip->getTimeBetweenFire());
        enemiesController->addEnemy(enemyShip, enemyController);
        enemyController->addObserver(enemyShip);

        std::shared_ptr<spaceinvaders::event::Event> event = std::make_shared<spaceinvaders::event::EntityCreatedEvent>(
                enemyShip, spriteFile);
        notifyObservers(
                event);

        gameController->addController(enemyController);
        enemyController->addObserver(enemyShip);

    }

    gameController->addController(enemiesController);
    enemiesController->addObserver(gameController);

}


spaceinvaders::loader::LevelLoader::LevelLoader(const std::string &filename) : Loader(filename) {}
