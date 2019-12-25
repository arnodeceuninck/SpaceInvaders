//
// Created by arno on 14/12/2019.
//

#ifndef SPACEINVADERS_SHIP_H
#define SPACEINVADERS_SHIP_H

#include "EntityModel.h"
#include "MovingEntity.h"

namespace spaceinvaders::model {
    class Ship : public MovingEntity {
        double health;
        double damage;
        double fireTimeout = 0;

    private:
        void update(double elapsedSeconds) override;

    public:
        bool readyToFire();

        double getHealth() const;

        void setHealth(double health);

        double getDamage() const;

        void setDamage(double damage);

        void handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) override;

        Ship(double x, double y);

        void fire();

        virtual Coordinate getShootingDirection() = 0;

        virtual Coordinate getShipFront() = 0;
    };
}


#endif //SPACEINVADERS_SHIP_H
