//
// Created by arno on 25/12/2019.
//

#ifndef SPACEINVADERS_ENEMYCONTROLLER_H
#define SPACEINVADERS_ENEMYCONTROLLER_H

#include "ShipController.h"
#include "../EntityModel/EnemyShip.h"

namespace spaceinvaders::controller {
    enum Direction {
        left, right, down
    };

    class EnemyController : public ShipController {
        Direction direction;
        double downTime;
        Direction previousDirection;
        std::shared_ptr<spaceinvaders::model::EnemyShip> leftMostEnemy;
        std::shared_ptr<spaceinvaders::model::EnemyShip> rightMostEnemy;
    public:
        void setLeftMostEnemy(const std::shared_ptr<spaceinvaders::model::EnemyShip> &leftMostEnemy);

        void setRightMostEnemy(const std::shared_ptr<spaceinvaders::model::EnemyShip> &rightMostEnemy);

        EnemyController(const std::shared_ptr<spaceinvaders::model::EntityModel> &model);

        void handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) override;

        void goDown(double elapsedTime);

        bool enemyCloseToRightBorder();

        bool enemyCloseToLeftBorder();
    };
}


#endif //SPACEINVADERS_ENEMYCONTROLLER_H
