//
// Created by arno on 14/12/2019.
//

#include "EntityRepresentation.h"

const std::string &spaceinvaders::view::EntityRepresentation::getSpriteFile() const {
    return spriteFile;
}

void spaceinvaders::view::EntityRepresentation::setSpriteFile(const std::string &spriteFile) {
    EntityRepresentation::spriteFile = spriteFile;
}
