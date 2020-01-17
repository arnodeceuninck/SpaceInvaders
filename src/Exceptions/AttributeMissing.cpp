//
// Created by arno on 15/01/2020.
//

#include "AttributeMissing.h"

spaceinvaders::exception::AttributeMissing::AttributeMissing(const std::string &attribute)
        : SiException("Attribute " + attribute + " missing") {
}
