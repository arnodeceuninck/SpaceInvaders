//
// Created by arno on 24/12/2019.
//

#ifndef SPACEINVADERS_MOVINGENTITY_H
#define SPACEINVADERS_MOVINGENTITY_H

#include "EntityModel.h"

namespace spaceinvaders::model {
class MovingEntity : public EntityModel {
private:
    double width;
    double height;
    double speed; // num per second, field is 8 num
    Coordinate speedDirection;
    Coordinate position;
public:
    MovingEntity(double width, double height, double speed, const Coordinate &speedDirection,
                 const Coordinate &position);

        Coordinate &getPosition();

        void setPosition(const Coordinate &position);

        double getWidth() const;

    void setWidth(double width);

    double getHeight() const;

    void setHeight(double height);

    double getSpeed() const;

    void setSpeed(double speed);

    void update(double elapsedSeconds) override;

    const Coordinate &getSpeedDirection() const;

    void setSpeedDirection(const Coordinate &speedDirection);
};
}


#endif //SPACEINVADERS_MOVINGENTITY_H
