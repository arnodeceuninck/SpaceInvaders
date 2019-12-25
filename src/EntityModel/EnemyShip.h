//
// Created by arno on 14/12/2019.
//

#ifndef SPACEINVADERS_ENEMYSHIP_H
#define SPACEINVADERS_ENEMYSHIP_H

#include "Ship.h"

namespace spaceinvaders::model {
    class EnemyShip : public Ship {
    public:
        EnemyShip(double x, double y);

        void handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) override;

        Coordinate getShootingDirection() override;

        Coordinate getShipFront() override;
    };
}


#endif //SPACEINVADERS_ENEMYSHIP_H
