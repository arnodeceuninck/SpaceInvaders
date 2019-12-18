//
// Created by arno on 14/12/2019.
//

#ifndef SPACEINVADERS_ENTITYMODEL_H
#define SPACEINVADERS_ENTITYMODEL_H

#include "Dimensions.h"
#include "../Observer/Observable.h"

#include <memory>

namespace spaceinvaders::controller {
    class ControllerEvent;
}
namespace spaceinvaders::model {

    class ModelChangedEvent;

    class EntityModel
            : public observer::Observer,
              public observer::Observable {

    };
}


#endif //SPACEINVADERS_ENTITYMODEL_H
