//
// Created by arno on 14/12/2019.
//

#include "EnemyShip.h"
#include "../Events/EnemyPositionUpdated.h"

spaceinvaders::model::EnemyShip::EnemyShip(double x, double y) : Ship(x, y) {}

void spaceinvaders::model::EnemyShip::handleEvent(std::shared_ptr<spaceinvaders::event::Event>& event)
{
        Ship::handleEvent(event);
}

spaceinvaders::Coordinate spaceinvaders::model::EnemyShip::getShootingDirection() { return Coordinate(0, -1); }

spaceinvaders::Coordinate spaceinvaders::model::EnemyShip::getShipFront()
{
        return Coordinate(getPosition().getX(), getPosition().getY() - getHeight() / 2);
}

bool spaceinvaders::model::EnemyShip::inFireRange(spaceinvaders::Coordinate coordinate, double bulleSize)
{
        return getPosition().getY() - getHeight() / 2 < coordinate.getY() && // Enemy head is under bulletHead
               coordinate.getX() - bulleSize / 2 < getPosition().getX() + getWidth() / 2 &&
               // Left side of the bullet is smaller then right side of ship
               coordinate.getX() + bulleSize / 2 >
                   getPosition().getX() - getWidth() / 2; // Right side of bullet is greater then left side of ship
}

void spaceinvaders::model::EnemyShip::update(double elapsedSeconds)
{
        spaceinvaders::model::Ship::update(elapsedSeconds);
        std::shared_ptr<spaceinvaders::event::Event> event =
            std::make_shared<spaceinvaders::event::EnemyPositionUpdated>(getPosition() -
                                                                         Coordinate(0, getHeight() / 2));
        notifyObservers(event);
}
