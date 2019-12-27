//
// Created by arno on 22/12/2019.
//

#include "ShipLoader.h"

#include "../EntityModel/Ship.h"
#include "../EntityRepresentation/MovingEntityRepresentation.h"
#include "../Events/EntityCreatedEvent.h"

void spaceinvaders::loader::ShipLoader::loadInto(std::shared_ptr<spaceinvaders::model::Ship> shipModel,
                                                 std::string &spriteFile) {
    // Read the file
    rapidjson::Document input = getDocument();

    if (auto width = input["width"].GetDouble()) {
        shipModel->setWidth(width);
    }

    if (auto height = input["height"].GetDouble()) {
        shipModel->setHeight(height);
    }

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
}

spaceinvaders::loader::ShipLoader::ShipLoader(const std::string &filename) : Loader(filename) {}

