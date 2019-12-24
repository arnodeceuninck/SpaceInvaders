//
// Created by arno on 23/12/2019.
//

#include "LevelLoader.h"
#include "ShipLoader.h"
#include "../EntityModel/PlayerShip.h"
#include "../EntityRepresentation/ShipRepresentation.h"
#include "../Events/EntityCreatedEvent.h"
#include "../EntityRepresentation/GameRepresentation.h"

void spaceinvaders::loader::LevelLoader::loadInto(std::shared_ptr<spaceinvaders::model::WorldModel> worldModel,
                                                  std::shared_ptr<spaceinvaders::view::GameRepresentation> gameRepresentation) {
    rapidjson::Document input = getDocument();

    if (auto playerFile = input["player"].GetString()) {
        ShipLoader shipLoader{playerFile};
        std::shared_ptr<spaceinvaders::model::PlayerShip> playerShip = std::make_shared<spaceinvaders::model::PlayerShip>();
        std::shared_ptr<spaceinvaders::view::ShipRepresentation> playerRepresentation = std::make_shared<spaceinvaders::view::ShipRepresentation>(
                gameRepresentation->getWindow(), gameRepresentation->getTransformation());
        shipLoader.loadInto(playerShip, playerRepresentation);

        std::shared_ptr<observer::Observer> observerPlayerRepr = std::dynamic_pointer_cast<observer::Observer>(
                playerRepresentation);
        playerShip->addObserver(observerPlayerRepr);

        std::shared_ptr<spaceinvaders::view::EntityRepresentation> entity = std::dynamic_pointer_cast<spaceinvaders::view::EntityRepresentation>(
                playerRepresentation);
        gameRepresentation->addObserver(entity);

        std::shared_ptr<spaceinvaders::event::Event> entityCreatedEvent = std::make_shared<spaceinvaders::event::EntityCreatedEvent>(
                playerShip);
        playerShip->notifyObservers(entityCreatedEvent);
    }

    // TODO: enemies
}

spaceinvaders::loader::LevelLoader::LevelLoader(const std::string &filename) : Loader(filename) {}
