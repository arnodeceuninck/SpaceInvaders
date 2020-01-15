//
// Created by arno on 15/01/2020.
//

#include "FileMissing.h"

spaceinvaders::exception::FileMissing::FileMissing(const std::string &filename) : SiException(
        "File " + filename + " missing") {}
