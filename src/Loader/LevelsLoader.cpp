//
// Created by arno on 28/12/2019.
//

#include "LevelsLoader.h"
#include "../EntityModel/GameModel.h"
#include "../EntityRepresentation/GameRepresentation.h"
#include "../Exceptions/AttributeMissing.h"

spaceinvaders::loader::LevelsLoader::LevelsLoader(const std::string &filename) : Loader(filename) {}

void spaceinvaders::loader::LevelsLoader::loadInto(std::shared_ptr<spaceinvaders::model::GameModel> gameModel,
                                                   std::shared_ptr<spaceinvaders::view::GameRepresentation> gameRepresentation) {

    rapidjson::Document input = getDocument();

    std::string attribute = "background";
    checkAttribute(input, attribute);
    std::string background = input[attribute.c_str()].GetString();
    gameRepresentation->setBackground(background);

    attribute = "levels";
    checkAttribute(input, attribute);
    rapidjson::Value &levelsValue = input[attribute.c_str()];

    for (unsigned int i = levelsValue.Size(); i > 0; i--) {

        rapidjson::Value &obj = levelsValue[i - 1];
        if (obj["file"].IsNull())
            throw spaceinvaders::exception::AttributeMissing("file");
        std::string file = obj["file"].GetString();
        gameModel->addLevel(file);
    }
}
