//
// Created by arno on 28/12/2019.
//

#include "RocketLoader.h"
#include "../EntityModel/RocketModel.h"

spaceinvaders::loader::RocketLoader::RocketLoader(const std::string& filename) : Loader(filename) {}

void spaceinvaders::loader::RocketLoader::loadInto(
    const std::shared_ptr<spaceinvaders::model::RocketModel>& rocketModel, std::string& spriteFile)
{
        // Read the file
        rapidjson::Document input = getDocument();

        std::string attribute = "width";
        checkAttribute(input, attribute, true);
        auto width = input[attribute.c_str()].GetDouble();
        rocketModel->setWidth(width);

        attribute = "height";
        checkAttribute(input, attribute, true);
        auto height = input[attribute.c_str()].GetDouble();
        rocketModel->setHeight(height);

        attribute = "sprite";
        checkAttribute(input, attribute);
        auto sprite = input[attribute.c_str()].GetString();
        spriteFile = sprite;

        attribute = "damage";
        checkAttribute(input, attribute, true);
        auto damage = input[attribute.c_str()].GetDouble();
        rocketModel->setDamage(damage);

        attribute = "speed";
        checkAttribute(input, attribute, true);
        auto speed = input[attribute.c_str()].GetDouble();
        rocketModel->setSpeed(speed);
}
