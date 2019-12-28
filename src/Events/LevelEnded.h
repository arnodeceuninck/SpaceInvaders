//
// Created by arno on 28/12/2019.
//

#ifndef SPACEINVADERS_LEVELENDED_H
#define SPACEINVADERS_LEVELENDED_H

#include "Event.h"

namespace spaceinvaders::event {
    class LevelEnded : public Event {
    public:
        LevelEnded(bool win);

        bool isWin() const;

    private:
        bool win;

    };
}


#endif //SPACEINVADERS_LEVELENDED_H
