//
// Created by arno on 15/12/2019.
//

#ifndef SPACEINVADERS_WINDOWCLOSELISTENER_H
#define SPACEINVADERS_WINDOWCLOSELISTENER_H

#include "../Observer/Observable.h"

namespace sf {
    class Event;
}

namespace spaceinvaders::controller {
    class WindowCloseListener : public observer::Observer, public observer::Observable {
        void handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) override;
    };
}


#endif //SPACEINVADERS_WINDOWCLOSELISTENER_H
