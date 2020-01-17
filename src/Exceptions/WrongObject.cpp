//
// Created by arno on 15/01/2020.
//

#include "WrongObject.h"

spaceinvaders::exception::WrongObject::WrongObject(const std::string& shouldBeObject)
    : SiException("Wrong object: should be a " + shouldBeObject)
{
}
