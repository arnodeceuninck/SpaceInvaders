//
// Created by arno on 18/12/2019.
//

#ifndef SPACEINVADERS_EVENT_H
#define SPACEINVADERS_EVENT_H

namespace spaceinvaders::event {
    class Event {
        bool handledByGameModel = false;
    public:
        /**
         * Chech whether the event has been handled by the gameModel
         * @return true when handled by gameModel
         */
        [[nodiscard]] bool isHandledByGameModel() const;

        /**
         * Check wheter the event has been handled by the gameModel
         * @param handledByGameModel true when handled by gameModel
         */
        void setHandledByGameModel(bool handledByGameModel);

        /**
         * Constructor
         */
        Event();

        /**
         * Destructor (required for dynamic casting)
         */
        virtual ~Event();
    };
}


#endif //SPACEINVADERS_EVENT_H
