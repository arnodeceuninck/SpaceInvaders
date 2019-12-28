//
// Created by arno on 22/12/2019.
//

#include "Loader.h"

#include <fstream>

#include "../../rapidjson/istreamwrapper.h"


spaceinvaders::loader::Loader::Loader(const std::string &filename) : filename("levels/" + filename) {}

const std::string &spaceinvaders::loader::Loader::getFilename() const {
    return filename;
}

rapidjson::Document spaceinvaders::loader::Loader::getDocument() const {
    std::ifstream inputStream(this->getFilename());
    rapidjson::IStreamWrapper inputStreamWrapper(inputStream);
    rapidjson::Document input;
    input.ParseStream(inputStreamWrapper);
    return input;
}