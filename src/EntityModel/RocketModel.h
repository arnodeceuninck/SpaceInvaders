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
    /**
     * Destroys itself (if bullet damage is 0)
     * @param bulletDamage
     */
    void selfDestroy(double bulletDamage) override;

    /**
     * Get the damage
     * @return The damage the rocket does to an object
     */
    double getDamage() const;

    /**
     * Set the damage a rocket does
     * @param damage
     */
    void setDamage(double damage);

    /**
     * Update it's position
     * @param elapsedSeconds
     */
    void update(double elapsedSeconds) override;

    /**
     * Constructor
     * @param position Start position
     * @param shootingDirection The direction it will move in
     */
    RocketModel(const Coordinate &position, const Coordinate &shootingDirection);

    /**
     * Get the front of the bullet
     */
    Coordinate getTop();
};
} // namespace spaceinvaders::model

#endif // SPACEINVADERS_ROCKETMODEL_H
