//
// Created by arno on 18/12/2019.
//

#ifndef SPACEINVADERS_EVENT_H
#define SPACEINVADERS_EVENT_H

namespace spaceinvaders::event {
    class Event {
        bool handledByGameModel = false;
    public:
        bool isHandledByGameModel() const;

        void setHandledByGameModel(bool handledByGameModel);

        Event();

        virtual ~Event();
    };
}


#endif //SPACEINVADERS_EVENT_H
