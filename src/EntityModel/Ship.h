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
    public:
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
