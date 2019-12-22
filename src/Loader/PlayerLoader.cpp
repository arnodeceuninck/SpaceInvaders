//
// Created by arno on 22/12/2019.
//

#include <fstream>
#include "PlayerLoader.h"

#include "../EntityModel/PlayerShip.h"
#include "../EntityRepresentation/ShipRepresentation.h"

#include "../../rapidjson/document.h"
#include "../../rapidjson/stringbuffer.h"
#include "../../rapidjson/istreamwrapper.h"

void spaceinvaders::loader::PlayerLoader::loadInto(std::shared_ptr<spaceinvaders::model::PlayerShip> shipModel,
                                                   std::shared_ptr<spaceinvaders::view::ShipRepresentation> shipRepresentation) {
    // Read the file
    std::ifstream inputStream(getFilename());
    rapidjson::IStreamWrapper inputStreamWrapper(inputStream);
    rapidjson::Document input;
    input.ParseStream(inputStreamWrapper);

    if(auto width = input["width"].GetDouble()){
        shipModel->setWidth(width);
    }

    if(auto height = input["height"].GetDouble()){
        shipModel->setHeight(height);
    }

    if(auto sprite = input["sprite"].GetString()){
        shipRepresentation->setSpriteFile(sprite);
    }

    if(auto health = input["health"].GetDouble()){
        shipModel->setHealth(health);
    }

    if(auto damage = input["damage"].GetDouble()){
        shipModel->setDamage(damage);
    }

}
