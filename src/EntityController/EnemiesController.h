//
// Created by arno on 25/12/2019.
//

#ifndef SPACEINVADERS_ENEMIESCONTROLLER_H
#define SPACEINVADERS_ENEMIESCONTROLLER_H

#include "ShipController.h"
#include "../EntityModel/EnemyShip.h"

#include <vector>

namespace spaceinvaders::controller {
    enum Direction {
        left, right, down
    };

    class EnemiesController : public ShipController {
        std::list<std::weak_ptr<spaceinvaders::model::EnemyShip>> enemies;
        Direction direction;
        double downTime;
        Direction previousDirection;
    public:
        void go(Coordinate coordinate);

        void fire();

        void addEnemy(std::shared_ptr<spaceinvaders::model::EnemyShip> enemy);

        EnemiesController();

        void handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) override;

        void goDown(double elapsedTime);


        bool enemyCloseToRightBorder();

        bool enemyCloseToLeftBorder();
    };
}


#endif //SPACEINVADERS_ENEMIESCONTROLLER_H
