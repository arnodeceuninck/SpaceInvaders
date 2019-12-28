//
// Created by arno on 28/12/2019.
//

#include "RocketLoader.h"
#include "../EntityModel/RocketModel.h"

spaceinvaders::loader::RocketLoader::RocketLoader(const std::string &filename) : Loader(filename) {}

void
spaceinvaders::loader::RocketLoader::loadInto(const std::shared_ptr<spaceinvaders::model::RocketModel> &rocketModel,
                                              std::string &spriteFile) {
    // Read the file
    rapidjson::Document input = getDocument();

    if (auto width = input["width"].GetDouble()) {
        rocketModel->setWidth(width);
    }

    if (auto height = input["height"].GetDouble()) {
        rocketModel->setHeight(height);
    }

    if (auto sprite = input["sprite"].GetString()) {
        spriteFile = sprite;
    }

    if (auto damage = input["damage"].GetDouble()) {
        rocketModel->setDamage(damage);
    }

    if (auto speed = input["speed"].GetDouble()) {
        rocketModel->setSpeed(speed);
    }

}
