//
// Created by arno on 22/12/2019.
//

#include "ShipLoader.h"

#include "../EntityModel/Ship.h"
#include "../Events/EntityCreatedEvent.h"
#include "../Exceptions/AttributeMissing.h"

void spaceinvaders::loader::ShipLoader::loadInto(const std::shared_ptr<spaceinvaders::model::Ship> &shipModel,
                                                 std::string &spriteFile) {
    // Read the file
    rapidjson::Document input = getDocument();

    std::string attribute = "width";
    checkAttribute(input, attribute, true);
    auto width = input[attribute.c_str()].GetDouble();
    shipModel->setWidth(width);

    attribute = "height";
    checkAttribute(input, attribute, true);
    auto height = input[attribute.c_str()].GetDouble();
    shipModel->setHeight(height);

    attribute = "sprite";
    checkAttribute(input, attribute);
    auto sprite = input[attribute.c_str()].GetString();
    spriteFile = sprite;

    attribute = "health";
    checkAttribute(input, attribute, true);
    auto health = input[attribute.c_str()].GetDouble();
    shipModel->setHealth(health);

    attribute = "speed";
    checkAttribute(input, attribute, true);
    auto speed = input[attribute.c_str()].GetDouble();
    shipModel->setSpeed(speed);

    attribute = "bullet";
    checkAttribute(input, attribute);
    auto bullet = input[attribute.c_str()].GetString();
    shipModel->setBulletFile(bullet);

    attribute = "timebetweenfire";
    checkAttribute(input, attribute, true);
    auto timebetweenfire = input[attribute.c_str()].GetDouble();
    shipModel->setTimeBetweenFire(timebetweenfire);
}

spaceinvaders::loader::ShipLoader::ShipLoader(const std::string &filename) : Loader(filename) {}
