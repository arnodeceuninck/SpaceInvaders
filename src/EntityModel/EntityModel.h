//
// Created by arno on 14/12/2019.
//

#ifndef SPACEINVADERS_ENTITYMODEL_H
#define SPACEINVADERS_ENTITYMODEL_H

#include "../Observer/Observer.h"
#include "../Observer/Observable.h"

namespace spaceinvaders::model {
    class EntityModel : public observer::Observer, public observer::Observable {

    };
}


#endif //SPACEINVADERS_ENTITYMODEL_H
