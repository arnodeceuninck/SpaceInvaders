//
// Created by arno on 24/12/2019.
//

#ifndef SPACEINVADERS_ROCKETMODEL_H
#define SPACEINVADERS_ROCKETMODEL_H

#include "EntityModel.h"
#include "MovingEntity.h"

namespace spaceinvaders::model {
class RocketModel : public MovingEntity {

public:
    void update(double elapsedSeconds) override;

    RocketModel();

    RocketModel(double width, double height, double speed, const Coordinate &speedDirection,
                const Coordinate &position);

    Coordinate getTop();
};
}


#endif //SPACEINVADERS_ROCKETMODEL_H
