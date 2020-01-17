//
// Created by arno on 14/12/2019.
//

#ifndef SPACEINVADERS_ENEMYSHIP_H
#define SPACEINVADERS_ENEMYSHIP_H

#include "Ship.h"

namespace spaceinvaders::model {
class EnemyShip : public Ship
{
public:
        /**
         * Initialise at given position
         * @param x width in game coordinates
         * @param y height in game coordinates
         */
        EnemyShip(double x, double y);

        /**
         * Handle an event
         * @param event
         */
        void handleEvent(std::shared_ptr<spaceinvaders::event::Event>& event) override;

        /**
         * Get the direction it's shooting in
         * @return
         */
        Coordinate getShootingDirection() override;

        /**
         * Check whether another ship is in it's fire range
         * @param coordinate The position of the object to check
         * @param bulletSize The size of your bullet
         * @return
         */
        bool inFireRange(Coordinate coordinate, double bulletSize);

        /**
         * Get the front of the ship
         * @return
         */
        Coordinate getShipFront() override;

        void update(double elapsedSeconds) override;
};
} // namespace spaceinvaders::model

#endif // SPACEINVADERS_ENEMYSHIP_H
