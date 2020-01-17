//
// Created by arno on 14/12/2019.
//

#ifndef SPACEINVADERS_ENTITYMODEL_H
#define SPACEINVADERS_ENTITYMODEL_H

#include "../Observer/Observable.h"
#include "Dimensions.h"

#include <memory>

namespace spaceinvaders::controller {
    class ControllerEvent;
}
namespace spaceinvaders::model {
    class ModelChangedEvent;

    class EntityModel : public observer::Observer,
                        public observer::Observable,
                        public std::enable_shared_from_this<EntityModel> {
    public:
        /**
         * Update its position
         * @param elapsedSeconds
         */
        virtual void update(double elapsedSeconds) = 0;

        /**
         * Handle an event
         * @param event
         */
        void handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) override;
    };
} // namespace spaceinvaders::model

#endif // SPACEINVADERS_ENTITYMODEL_H
