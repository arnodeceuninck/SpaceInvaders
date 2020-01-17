//
// Created by arno on 14/12/2019.
//

#ifndef SPACEINVADERS_SHIP_H
#define SPACEINVADERS_SHIP_H

#include "EntityModel.h"
#include "MovingEntity.h"

namespace spaceinvaders::model {
class Ship : public MovingEntity
{
        double health{};
        double damage{};
        double fireTimeout = 0;
        double timeBetweenFire{};
        std::string bulletFile;

public:
        /**
         * Apply changes that happend in the past second
         * @param elapsedSeconds The time that has passed (in seconds)
         */
        void update(double elapsedSeconds) override;

        /**
         * Set the json file which describes the type of bullets this ship fires
         * @param bulletFile
         */
        void setBulletFile(const std::string& bulletFile);

        /**
         * Get the cooldown time between two bullets
         * @return
         */
        double getTimeBetweenFire() const;

        /**
         * Set the cooldowntime
         * @param timeBetweenFire
         */
        void setTimeBetweenFire(double timeBetweenFire);

        /**
         * Check whether the ship has waited long enough to fire again
         * @return
         */
        bool readyToFire();

        /**
         * Set the health of the ship
         * @param health
         */
        void setHealth(double health);

        /**
         * Handle an event
         * @param event
         */
        void handleEvent(std::shared_ptr<spaceinvaders::event::Event>& event) override;

        /**
         * Constructor
         * @param x width coordinate in game dimensions
         * @param y height coordinate in game dimensions
         */
        Ship(double x, double y);

        /**
         * Fire a bullet (only fires if ready to fire)
         */
        void fire();

        /**
         * Get the direction a ship shoots in
         * @return
         */
        virtual Coordinate getShootingDirection() = 0;

        /**
         * Get the position of the front of the ship
         * @return
         */
        virtual Coordinate getShipFront() = 0;

        /**
         * Take damage and destroy itself when necessarily
         * @param bulletDamage
         */
        void selfDestroy(double bulletDamage) override;
};
} // namespace spaceinvaders::model

#endif // SPACEINVADERS_SHIP_H
