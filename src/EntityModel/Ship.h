//
// Created by arno on 14/12/2019.
//

#ifndef SPACEINVADERS_SHIP_H
#define SPACEINVADERS_SHIP_H

#include "EntityModel.h"

namespace spaceinvaders::model {
    class Ship : public EntityModel {
        double width;
        double height;
        double health;
        double damage;
        double speed; // num per second, field is 8 num
        Coordinate speedDirection;
    public:
        const Coordinate &getSpeedDirection() const;

    private:
        Coordinate position;
    public:
        double getSpeed() const;

        void setSpeed(double speed);

        void setSpeedDirection(const Coordinate &speedDirection);

    private:
        void update(double elapsedSeconds) override;

    public:
        void handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) override;

        void setPosition(const Coordinate &position);

        Ship(double x, double y);

        const Coordinate &getPosition() const;

        double getWidth() const;

        void setWidth(double width);

        double getHeight() const;

        void setHeight(double height);

        double getHealth() const;

        void setHealth(double health);

        double getDamage() const;

        void setDamage(double damage);
    };
}


#endif //SPACEINVADERS_SHIP_H
