//
// Created by arno on 15/01/2020.
//

#ifndef SPACEINVADERS_OBJECTNULLEXCEPTION_H
#define SPACEINVADERS_OBJECTNULLEXCEPTION_H


#include "SiExcecption.h"

namespace spaceinvaders::exception {
    class ObjectNullException : public SiException {
    public:
        explicit ObjectNullException(const std::string &problem);
    };
}

#endif //SPACEINVADERS_OBJECTNULLEXCEPTION_H
