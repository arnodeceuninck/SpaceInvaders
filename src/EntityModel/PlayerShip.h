//
// Created by arno on 14/12/2019.
//

#ifndef SPACEINVADERS_PLAYERSHIP_H
#define SPACEINVADERS_PLAYERSHIP_H

#include "Ship.h"

namespace spaceinvaders::model {
    class PlayerShip : public Ship {
    public:
        PlayerShip();

    public:
        void handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) override;
    };
}


#endif //SPACEINVADERS_PLAYERSHIP_H
