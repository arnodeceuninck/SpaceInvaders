//
// Created by arno on 15/01/2020.
//

#ifndef SPACEINVADERS_ATTRIBUTEMISSING_H
#define SPACEINVADERS_ATTRIBUTEMISSING_H

#include "SiExcecption.h"

namespace spaceinvaders::exception {
    class AttributeMissing : public SiException {
    public:
        AttributeMissing(const std::string &problem);
    };
}


#endif //SPACEINVADERS_ATTRIBUTEMISSING_H
