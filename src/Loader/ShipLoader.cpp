//
// Created by arno on 22/12/2019.
//

#include "ShipLoader.h"

#include "../EntityModel/Ship.h"
#include "../EntityRepresentation/MovingEntityRepresentation.h"
#include "../Events/EntityCreatedEvent.h"

void spaceinvaders::loader::ShipLoader::loadInto(std::shared_ptr<spaceinvaders::model::Ship> shipModel,
                                                 std::shared_ptr<spaceinvaders::view::GameRepresentation> gameRepresentation) {
    // Read the file
    rapidjson::Document input = getDocument();

    if (auto width = input["width"].GetDouble()) {
        shipModel->setWidth(width);
    }

    if (auto height = input["height"].GetDouble()) {
        shipModel->setHeight(height);
    }

    std::string spriteFile;
    if(auto sprite = input["sprite"].GetString()){
        spriteFile = sprite;
    }

    if (auto health = input["health"].GetDouble()) {
        shipModel->setHealth(health);
    }

    if (auto damage = input["damage"].GetDouble()) {
        shipModel->setDamage(damage);
    }

    if (auto speed = input["speed"].GetDouble()) {
        shipModel->setSpeed(speed);
    }

    std::shared_ptr<spaceinvaders::event::Event> event = std::make_shared<spaceinvaders::event::EntityCreatedEvent>(
            shipModel, spriteFile);
    notifyObservers(
            event); // TODO: GameModel MUST observe LevelLoader, LevelLodader must observe shipLoader (for redirecting event to levelLoader),  worldModel & GameRepresentation must observe GameModel, so the eventCreated can be forwarded to all places requiring it
}

spaceinvaders::loader::ShipLoader::ShipLoader(const std::string &filename) : Loader(filename) {}

