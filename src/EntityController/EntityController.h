//
// Created by arno on 14/12/2019.
//

#ifndef SPACEINVADERS_ENTITYCONTROLLER_H
#define SPACEINVADERS_ENTITYCONTROLLER_H

#include "../Events/ControllerEvent.h"
#include "../Observer/Observable.h"

namespace spaceinvaders::model {
    class EntityModel;
}
namespace spaceinvaders::controller {
    class EntityController : public observer::Observer, public observer::Observable {
    public:
        /**
         * Constructor
         */
        EntityController();

        //        const std::shared_ptr<spaceinvaders::model::EntityModel> &getModel() const;

        /**
         * Handle an event
         * @param event
         */
        void handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) override;
    };

} // namespace spaceinvaders::controller

#endif // SPACEINVADERS_ENTITYCONTROLLER_H
