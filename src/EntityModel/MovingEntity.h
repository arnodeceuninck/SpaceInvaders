//
// Created by arno on 24/12/2019.
//

#ifndef SPACEINVADERS_MOVINGENTITY_H
#define SPACEINVADERS_MOVINGENTITY_H

#include "EntityModel.h"

namespace spaceinvaders::model {
class MovingEntity : public EntityModel {
private:
    double width{};
    double height{};
    double speed{}; // num per second, field is 8 num
    Coordinate speedDirection;
    Coordinate position;

public:
    /**
     * Constructor
     * @param speedDirection The direction it is moving in
     * @param position The start position
     */
    MovingEntity(const Coordinate &speedDirection, const Coordinate &position);

    /**
     * Constructor
     * @param width
     * @param height
     * @param speed
     * @param speedDirection
     * @param position
     */
    MovingEntity(double width, double height, double speed, const Coordinate &speedDirection,
                 const Coordinate &position);

    /**
     * Get the position of the record
     * @return
     */
    Coordinate &getPosition();

    /**
     * Change the position
     * @param position
     */
    void setPosition(const Coordinate &position);

    /**
     * Get the width
     * @return
     */
    double getWidth() const;

    /**
     * Change the width
     * @param width
     */
    void setWidth(double width);

    /**
     * Get the height
     * @return
     */
    double getHeight() const;

    /**
     * Change the height
     * @param height
     */
    void setHeight(double height);

    /**
     * Get the speed
     * @return
     */
    double getSpeed() const;

    /**
     * Change the speed
     * @param speed
     */
    void setSpeed(double speed);

    /**
     * Update the position
     * @param elapsedSeconds
     */
    void update(double elapsedSeconds) override;

    /**
     * Get the direction it's moving in
     * @return
     */
    const Coordinate &getSpeedDirection() const;

    /**
     * Change the direction it's moving in
     * @param speedDirection
     */
    void setSpeedDirection(const Coordinate &speedDirection);

    /**
     * Handle an event
     * @param event
     */
    void handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) override;

    /**
     * Take damage and destroy itself
     */
    virtual void selfDestroy(double bulletDamage) = 0;

    /**
     * Destroy itself
     */
    virtual void selfDestroy();

    /**
     * Check whether the entity went outside of the window
     * @return
     */
    bool outsideWindow();

    /**
     * Check whether there is a collision with a rocket
     * @param coordinate
     * @return
     */
    bool isCollision(const spaceinvaders::Coordinate &coordinate);
};
} // namespace spaceinvaders::model

#endif // SPACEINVADERS_MOVINGENTITY_H
