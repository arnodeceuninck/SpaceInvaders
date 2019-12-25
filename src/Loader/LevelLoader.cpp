//
// Created by arno on 23/12/2019.
//

#include "LevelLoader.h"
#include "ShipLoader.h"
#include "../EntityModel/PlayerShip.h"
#include "../EntityRepresentation/MovingEntityRepresentation.h"
#include "../Events/EntityCreatedEvent.h"
#include "../EntityRepresentation/GameRepresentation.h"
#include "../EntityController/ShipController.h"

void spaceinvaders::loader::LevelLoader::loadInto(std::shared_ptr<spaceinvaders::model::WorldModel> worldModel,
                                                  std::shared_ptr<spaceinvaders::view::GameRepresentation> gameRepresentation) {
    rapidjson::Document input = getDocument();

    if (auto playerFile = input["player"].GetString()) {

        // Create a player ship, it's representation and it's controller
        auto playerShip = std::make_shared<spaceinvaders::model::PlayerShip>();

        auto shipRepresentation = std::make_shared<spaceinvaders::view::MovingEntityRepresentation>(
                gameRepresentation->getWindow(), gameRepresentation->getTransformation());
        auto shipController = std::make_shared<spaceinvaders::controller::ShipController>(playerShip);

        // Load the contents of the player file to the ship
        ShipLoader shipLoader{playerFile};
        shipLoader.loadInto(playerShip, shipRepresentation);

        std::shared_ptr<spaceinvaders::model::Ship> ship = std::dynamic_pointer_cast<spaceinvaders::model::Ship>(
                playerShip);

        linkObservers(worldModel, gameRepresentation, ship, shipRepresentation, shipController);

    }

    rapidjson::Value &enemiesValue = input["enemies"];

    for (rapidjson::SizeType i = 0; i < enemiesValue.Size(); i++) {

        rapidjson::Value &enemyObj = enemiesValue[i];

        std::string enemyJson = enemyObj["enemy"].GetString();
        double enemyX = enemyObj["x"].GetDouble();
        double enemyY = enemyObj["y"].GetDouble();


    }

    // TODO: enemies
}

void spaceinvaders::loader::LevelLoader::linkObservers(std::shared_ptr<spaceinvaders::model::WorldModel> &worldModel,
                                                       std::shared_ptr<spaceinvaders::view::GameRepresentation> &gameRepresentation,
                                                       std::shared_ptr<spaceinvaders::model::Ship> &ship,
                                                       const std::shared_ptr<spaceinvaders::view::MovingEntityRepresentation> &shipRepresentation,
                                                       const std::shared_ptr<spaceinvaders::controller::ShipController> &shipController) const {// Link the view to the model
//        std::shared_ptr<observer::Observer> observerPlayerRepr = std::dynamic_pointer_cast<observer::Observer>(
//                shipRepresentation);
    ship->addObserver(shipRepresentation);

    // Link the model to the controller
//        auto observerPlayerContr = std::dynamic_pointer_cast<observer::Observer>(ship);
//        shipController->addObserver(ship);
    worldModel->addObserver(ship);
    ship->addObserver(worldModel);

    // Link the entityRepresentation to the gameRepresentation
//        auto entity = std::dynamic_pointer_cast<spaceinvaders::view::EntityRepresentation>(
//                shipRepresentation);
    gameRepresentation->addObserver(shipRepresentation); // Required for updating

    // Link controller and gameRepresentation (required for notifying of WindowInteractions)
    gameRepresentation->getWindow()->addObserver(shipController);

    ship->addObserver(gameRepresentation); // Required for creating bullets representations when bullet fired

    // Notify the view an entity has been created
    std::shared_ptr<spaceinvaders::event::Event> entityCreatedEvent = std::make_shared<spaceinvaders::event::EntityCreatedEvent>(
            ship);
    ship->notifyObservers(entityCreatedEvent);
}

spaceinvaders::loader::LevelLoader::LevelLoader(const std::string &filename) : Loader(filename) {}
