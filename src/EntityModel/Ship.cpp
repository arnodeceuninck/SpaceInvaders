//
// Created by arno on 14/12/2019.
//

#include "Ship.h"

double spaceinvaders::model::Ship::getWidth() const {
    return width;
}

void spaceinvaders::model::Ship::setWidth(double width) {
    Ship::width = width;
}

double spaceinvaders::model::Ship::getHeight() const {
    return height;
}

void spaceinvaders::model::Ship::setHeight(double height) {
    Ship::height = height;
}

double spaceinvaders::model::Ship::getHealth() const {
    return health;
}

void spaceinvaders::model::Ship::setHealth(double health) {
    Ship::health = health;
}

double spaceinvaders::model::Ship::getDamage() const {
    return damage;
}

void spaceinvaders::model::Ship::setDamage(double damage) {
    Ship::damage = damage;
}

double spaceinvaders::model::Ship::getX() const {
    return x;
}

double spaceinvaders::model::Ship::getY() const {
    return y;
}
