//
// Created by arno on 15/01/2020.
//

#ifndef SPACEINVADERS_WRONGOBJECT_H
#define SPACEINVADERS_WRONGOBJECT_H

#include "SiExcecption.h"

namespace spaceinvaders::exception {
    class WrongObject : public SiException {
    public:
        WrongObject(const std::string &shouldBeObject);
    };
}


#endif //SPACEINVADERS_WRONGOBJECT_H
