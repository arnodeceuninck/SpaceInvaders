//
// Created by arno on 22/12/2019.
//

#include "Loader.h"

#include <fstream>

#include "../../rapidjson/istreamwrapper.h"
#include "../Exceptions/AttributeMissing.h"
#include "../Exceptions/FileMissing.h"
#include "../Exceptions/ObjectNullException.h"
#include "../Exceptions/WrongObject.h"

spaceinvaders::loader::Loader::Loader(const std::string &filename) : filename("levels/" + filename) {}

const std::string &spaceinvaders::loader::Loader::getFilename() const { return filename; }

rapidjson::Document spaceinvaders::loader::Loader::getDocument() const {

    if (this->getFilename().empty())
        throw spaceinvaders::exception::ObjectNullException("Filename is still empty");

    std::ifstream inputStream(this->getFilename());
    rapidjson::IStreamWrapper inputStreamWrapper(inputStream);
    rapidjson::Document input;
    input.ParseStream(inputStreamWrapper);

    if (input.IsNull())
        throw spaceinvaders::exception::FileMissing(this->getFilename());

    return input;
}

void spaceinvaders::loader::Loader::checkAttribute(const rapidjson::Document &input, const std::string &attributeName,
                                                   bool checkNum, bool onlyCheckExists) {
    if (input[attributeName.c_str()].IsNull())
        throw spaceinvaders::exception::AttributeMissing(attributeName);

    if (onlyCheckExists)
        return;

    if (checkNum && !input[attributeName.c_str()].IsNumber())
        throw spaceinvaders::exception::WrongObject("double");

    if (!checkNum && !input[attributeName.c_str()].IsString())
        throw spaceinvaders::exception::WrongObject("string");
}
