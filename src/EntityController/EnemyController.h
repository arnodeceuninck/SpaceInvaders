//
// Created by arno on 25/12/2019.
//

#ifndef SPACEINVADERS_ENEMYCONTROLLER_H
#define SPACEINVADERS_ENEMYCONTROLLER_H

#include "EntityController.h"
#include "ShipController.h"

namespace spaceinvaders::controller {
class EnemyController : public ShipController
{
        double firetime;
        bool firstRow = false;
        double timeBetweenFire;

        void checkFire(double elapsedTime);

public:
        /**
         * Check whether the enemy it is controlling is on the first row
         * @return
         */
        [[nodiscard]] bool isFirstRow() const;

        /**
         * Set whether the enemy is on the first row (to avoid checking it each update (intensive operation))
         * @param firstRow
         */
        void setFirstRow(bool firstRow);

        /**
         * Handle an event
         * @param event
         */
        void handleEvent(std::shared_ptr<spaceinvaders::event::Event>& event) override;

        /**
         * Constructor
         * @param timeBetweenFire
         */
        explicit EnemyController(double timeBetweenFire);

        /**
         * Generate a random time to fire again (in the interval [timeBetweenFire, 2*timeBetweenFire]
         * @return
         */
        double randomNextFire();
};
} // namespace spaceinvaders::controller

#endif // SPACEINVADERS_ENEMYCONTROLLER_H
