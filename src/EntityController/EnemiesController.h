//
// Created by arno on 25/12/2019.
//

#ifndef SPACEINVADERS_ENEMIESCONTROLLER_H
#define SPACEINVADERS_ENEMIESCONTROLLER_H

#include "ShipController.h"
#include "../EntityModel/EnemyShip.h"
#include "EnemyController.h"

#include <vector>

namespace spaceinvaders::controller {
    enum Direction {
        left, right, down
    };

    class EnemiesController : public ShipController {
        std::list<std::pair<std::weak_ptr<spaceinvaders::model::EnemyShip>, std::weak_ptr<EnemyController>>> enemies;
        Direction direction;
        double downTime;
        Direction previousDirection;
    public:
        void go(Coordinate coordinate);

        void fire();

        void
        addEnemy(std::shared_ptr<spaceinvaders::model::EnemyShip> enemy, std::shared_ptr<EnemyController> controller);

        EnemiesController();

        void handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) override;

        void goDown(double elapsedTime);


        bool enemyCloseToRightBorder();

        bool enemyCloseToLeftBorder();

        void checkFirstRowEnemies();
    };
}


#endif //SPACEINVADERS_ENEMIESCONTROLLER_H
