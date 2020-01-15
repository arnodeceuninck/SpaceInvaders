//
// Created by arno on 15/01/2020.
//

#ifndef SPACEINVADERS_ENEMYPOSITIONUPDATED_H
#define SPACEINVADERS_ENEMYPOSITIONUPDATED_H

#include "../EntityModel/Coordinate.h"
#include "Event.h"

namespace spaceinvaders::event {
    /**
     * Seperate class from rocketposition updated, so EnemyShip must not always be included.
     */
    class EnemyPositionUpdated : public Event {
        Coordinate newFront;
    public:
        EnemyPositionUpdated(const Coordinate &newFront);

        const Coordinate &getNewFront() const;
    };
}


#endif //SPACEINVADERS_ENEMYPOSITIONUPDATED_H
