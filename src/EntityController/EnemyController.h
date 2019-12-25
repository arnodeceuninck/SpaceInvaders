//
// Created by arno on 25/12/2019.
//

#ifndef SPACEINVADERS_ENEMYCONTROLLER_H
#define SPACEINVADERS_ENEMYCONTROLLER_H

#include "EntityController.h"
#include "ShipController.h"

namespace spaceinvaders::controller {
    class EnemyController : public ShipController {
        double firetime;

        void checkFire(double elapsedTime);

    public:
        void handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) override;

        EnemyController(const std::shared_ptr<spaceinvaders::model::EntityModel> &model);
    };
}


#endif //SPACEINVADERS_ENEMYCONTROLLER_H
