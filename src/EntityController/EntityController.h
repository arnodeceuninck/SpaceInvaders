//
// Created by arno on 14/12/2019.
//

#ifndef SPACEINVADERS_ENTITYCONTROLLER_H
#define SPACEINVADERS_ENTITYCONTROLLER_H

#include "../Observer/Observable.h"

namespace spaceinvaders::controller {

    class EntityController : public observer::Observable {
        virtual void update() = 0;
    };

}


#endif //SPACEINVADERS_ENTITYCONTROLLER_H
