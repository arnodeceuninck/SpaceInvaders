//
// Created by arno on 24/12/2019.
//

#ifndef SPACEINVADERS_ROCKETMODEL_H
#define SPACEINVADERS_ROCKETMODEL_H

#include "EntityModel.h"
#include "MovingEntity.h"

namespace spaceinvaders::model {
class RocketModel : public MovingEntity {
    double damage;
public:
    double getDamage() const;

public:
    void update(double elapsedSeconds) override;

    RocketModel();

    RocketModel(double width, double height, double speed, const Coordinate &speedDirection,
                const Coordinate &position, double damage);

    Coordinate getTop();
};
}


#endif //SPACEINVADERS_ROCKETMODEL_H
