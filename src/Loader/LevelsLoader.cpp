//
// Created by arno on 28/12/2019.
//

#include "LevelsLoader.h"
#include "../EntityModel/GameModel.h"
#include "../EntityRepresentation/GameRepresentation.h"

spaceinvaders::loader::LevelsLoader::LevelsLoader(const std::string &filename) : Loader(filename) {}

void spaceinvaders::loader::LevelsLoader::loadInto(std::shared_ptr<spaceinvaders::model::GameModel> gameModel,
                                                   std::shared_ptr<spaceinvaders::view::GameRepresentation> gameRepresentation) {

    rapidjson::Document input = getDocument();

    std::string background = input["background"].GetString();
    gameRepresentation->setBackground(background);

    rapidjson::Value &levelsValue = input["levels"];

    for (unsigned int i = levelsValue.Size(); i > 0; i--) {

        rapidjson::Value &obj = levelsValue[i - 1];
        std::string file = obj["file"].GetString();
        gameModel->addLevel(file);
    }
}
