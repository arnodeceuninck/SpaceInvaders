//
// Created by arno on 25/12/2019.
//

#ifndef SPACEINVADERS_ENEMIESCONTROLLER_H
#define SPACEINVADERS_ENEMIESCONTROLLER_H

#include "../EntityModel/EnemyShip.h"
#include "EnemyController.h"
#include "ShipController.h"

#include <vector>

namespace spaceinvaders::controller {
    enum Direction {
        left,
        right,
        down
    };

/**
 * Control a group of enemies
 */
    class EnemiesController : public ShipController {
        std::list<std::pair<std::weak_ptr<spaceinvaders::model::EnemyShip>, std::weak_ptr<EnemyController>>> enemies;
        Direction direction;
        double downTime{};
        Direction previousDirection;

    public:
        /**
         * Change direction
         * @param coordinate normalized direction vector
         */
        void go(Coordinate coordinate) override;

        /**
         * Set the direction the enemies start in
         */
        void setStartDirection();

        /**
         * Fire a rocket
         */
        void fire() override;

        /**
         * Add an enemy to the group this controls
         * @param enemy Model of the enemy
         * @param controller Individual controller
         */
        void addEnemy(const std::shared_ptr<spaceinvaders::model::EnemyShip> &enemy,
                      const std::shared_ptr<EnemyController> &controller);

        /**
         * constructor
         */
        EnemiesController();

        /**
         * Handle an event
         * @param event
         */
        void handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) override;

        /**
         * Go down
         * @param elapsedTime
         */
        void goDown(double elapsedTime);

        /**
         * Check whether an enemy is close to the right border
         * @return
         */
        bool enemyCloseToRightBorder();

        /**
         * Check whether an enemy is close to the left border
         * @return
         */
        bool enemyCloseToLeftBorder();

        /**
         * Update for all individual enemy controllers whether they are on the first row
         */
        void checkFirstRowEnemies();
    };
} // namespace spaceinvaders::controller

#endif // SPACEINVADERS_ENEMIESCONTROLLER_H
