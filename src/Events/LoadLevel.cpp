//
// Created by arno on 28/12/2019.
//

#include "LoadLevel.h"

const std::string &spaceinvaders::event::LoadLevel::getLevel() const {
    return level;
}

spaceinvaders::event::LoadLevel::LoadLevel(const std::string &level) : level(level) {}
