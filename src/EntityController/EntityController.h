//
// Created by arno on 14/12/2019.
//

#ifndef SPACEINVADERS_ENTITYCONTROLLER_H
#define SPACEINVADERS_ENTITYCONTROLLER_H

#include "../Observer/Observable.h"
#include "../Events/ControllerEvent.h"

namespace spaceinvaders::model {
    class EntityModel;
}
namespace spaceinvaders::controller {
    class EntityController : public observer::Observer, public observer::Observable {
    public:
        EntityController();

//        const std::shared_ptr<spaceinvaders::model::EntityModel> &getModel() const;

        void handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) override;
    };

}


#endif //SPACEINVADERS_ENTITYCONTROLLER_H
