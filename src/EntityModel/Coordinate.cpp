//
// Created by arno on 17/12/2019.
//

#include "Coordinate.h"

double spaceinvaders::Coordinate::getX() const {
    return x;
}

double spaceinvaders::Coordinate::getY() const {
    return y;
}

spaceinvaders::Coordinate spaceinvaders::Coordinate::operator+(const spaceinvaders::Coordinate &rhs) {
    x += rhs.getX();
    y += rhs.getY();
}

spaceinvaders::Coordinate spaceinvaders::Coordinate::operator-(const spaceinvaders::Coordinate &rhs) {
    x -= rhs.getX();
    y -= rhs.getY();
}

spaceinvaders::Coordinate spaceinvaders::Coordinate::operator*(const int &k) {
    x *= k;
    y *= k;
}

spaceinvaders::Coordinate spaceinvaders::Coordinate::operator+=(const spaceinvaders::Coordinate &rhs) {
    return *this + rhs;
}

spaceinvaders::Coordinate spaceinvaders::Coordinate::operator-=(const spaceinvaders::Coordinate &rhs) {
    return *this - rhs;
}

spaceinvaders::Coordinate spaceinvaders::Coordinate::operator*=(const int &k) {
    return *this * k;
}

spaceinvaders::Coordinate::Coordinate(double x, double y) : x(x), y(y) {}

void spaceinvaders::Coordinate::invertY() {
    y = -y;
}

