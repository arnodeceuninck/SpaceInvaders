//
// Created by arno on 22/12/2019.
//

#include "Loader.h"

spaceinvaders::loader::Loader::Loader(const std::string &filename) : filename(filename) {}

const std::string &spaceinvaders::loader::Loader::getFilename() const {
    return filename;
}
