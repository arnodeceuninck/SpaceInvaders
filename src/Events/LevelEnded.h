//
// Created by arno on 28/12/2019.
//

#ifndef SPACEINVADERS_LEVELENDED_H
#define SPACEINVADERS_LEVELENDED_H

#include "Event.h"

namespace spaceinvaders::event {
    class LevelEnded : public Event {
    public:
        /**
         * Notify the level has ended
         * @param win Are all enemies killed?
         */
        explicit LevelEnded(bool win);

        /**
         * Check whether all enemies are killed
         * @return true when victory
         */
        [[nodiscard]] bool isWin() const;

    private:
        bool win;

    };
}


#endif //SPACEINVADERS_LEVELENDED_H
