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
    void selfDestroy(double bulletDamage) override;

    double getDamage() const;

    void setDamage(double damage);

public:

    void update(double elapsedSeconds) override;

    RocketModel(const Coordinate &position, const Coordinate &shootingDirection);

    Coordinate getTop();
};
}


#endif //SPACEINVADERS_ROCKETMODEL_H
