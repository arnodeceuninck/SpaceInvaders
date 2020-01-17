//
// Created by arno on 28/12/2019.
//

#include "LoadLevel.h"

#include <utility>

const std::string& spaceinvaders::event::LoadLevel::getLevel() const { return level; }

spaceinvaders::event::LoadLevel::LoadLevel(std::string level) : level(std::move(level)) {}
