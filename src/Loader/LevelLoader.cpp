//
// Created by arno on 23/12/2019.
//

#include "LevelLoader.h"
#include "ShipLoader.h"
#include "../EntityModel/PlayerShip.h"
#include "../EntityRepresentation/ShipRepresentation.h"

void spaceinvaders::loader::LevelLoader::loadInto(std::shared_ptr<spaceinvaders::model::WorldModel> worldModel) {
    rapidjson::Document input = getDocument();

    if (auto playerFile = input["player"].GetString()) {
        ShipLoader shipLoader{playerFile};
        std::shared_ptr<spaceinvaders::model::PlayerShip> playerShip = std::make_shared<spaceinvaders::model::PlayerShip>();
        std::shared_ptr<spaceinvaders::view::ShipRepresentation> playerRepresentation = std::make_shared<spaceinvaders::view::ShipRepresentation>(
                playerShip);
        shipLoader.loadInto(playerShip, playerRepresentation);
    }

    // TODO: enemies
}
