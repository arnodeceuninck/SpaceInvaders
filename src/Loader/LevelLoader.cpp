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
        auto playerRepresentation = std::make_shared<spaceinvaders::view::MovingEntityRepresentation>(
                gameRepresentation->getWindow(), gameRepresentation->getTransformation());
        auto shipController = std::make_shared<spaceinvaders::controller::ShipController>(playerShip);

        // Load the contents of the player file to the ship
        ShipLoader shipLoader{playerFile};
        shipLoader.loadInto(playerShip, playerRepresentation);

        // Link the view to the model
//        std::shared_ptr<observer::Observer> observerPlayerRepr = std::dynamic_pointer_cast<observer::Observer>(
//                playerRepresentation);
        playerShip->addObserver(playerRepresentation);

        // Link the model to the controller
//        auto observerPlayerContr = std::dynamic_pointer_cast<observer::Observer>(playerShip);
//        shipController->addObserver(playerShip);
        worldModel->addObserver(playerShip);
        playerShip->addObserver(worldModel);

        // Link the entityRepresentation to the gameRepresentation
//        auto entity = std::dynamic_pointer_cast<spaceinvaders::view::EntityRepresentation>(
//                playerRepresentation);
        gameRepresentation->addObserver(playerRepresentation); // Required for updating

        // Link controller and gameRepresentation (required for notifying of WindowInteractions)
        gameRepresentation->getWindow()->addObserver(shipController);

        playerShip->addObserver(gameRepresentation); // Required for creating bullets representations when bullet fired

        // Notify the view an entity has been created
        std::shared_ptr<spaceinvaders::event::Event> entityCreatedEvent = std::make_shared<spaceinvaders::event::EntityCreatedEvent>(
                playerShip);
        playerShip->notifyObservers(entityCreatedEvent);
    }

    // TODO: enemies
}

spaceinvaders::loader::LevelLoader::LevelLoader(const std::string &filename) : Loader(filename) {}
