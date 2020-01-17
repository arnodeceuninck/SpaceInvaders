//
// Created by arno on 15/01/2020.
//

#ifndef SPACEINVADERS_ATTRIBUTEMISSING_H
#define SPACEINVADERS_ATTRIBUTEMISSING_H

#include "SiExcecption.h"

namespace spaceinvaders::exception {
    class AttributeMissing : public SiException {
    public:
        explicit AttributeMissing(const std::string &problem);
    };
} // namespace spaceinvaders::exception

#endif // SPACEINVADERS_ATTRIBUTEMISSING_H
