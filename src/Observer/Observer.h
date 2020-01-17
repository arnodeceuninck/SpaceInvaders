//
// Created by arno on 14/12/2019.
//

#ifndef SPACEINVADERS_OBSERVER_H
#define SPACEINVADERS_OBSERVER_H

#include <memory>

namespace spaceinvaders::event {
class Event;
}

namespace spaceinvaders::observer {
//    class Obsevable;
class Observer
{
public:
        /**
         * Handle an event the observable has broadcasted
         * @param event The broadcasted event
         */
        virtual void handleEvent(std::shared_ptr<spaceinvaders::event::Event>& event) = 0;

        /**
         * Virtual destructor (used for dynamic casting)
         */
        virtual ~Observer();
};
} // namespace spaceinvaders::observer

#endif // SPACEINVADERS_OBSERVER_H
