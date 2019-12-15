//
// Created by arno on 14/12/2019.
//

#ifndef SPACEINVADERS_ENTITYMODEL_H
#define SPACEINVADERS_ENTITYMODEL_H

#include "../Observer/Observer.h"
#include "../Observer/Observable.h"
#include "../EntityController/ControllerEvent.h"
#include "ModelChangedEvent.h"

namespace spaceinvaders::model {
    class EntityModel
            : public observer::Observer<spaceinvaders::controller::ControllerEvent>,
              public observer::Observable<spaceinvaders::model::ModelChangedEvent> {

    };
}


#endif //SPACEINVADERS_ENTITYMODEL_H
