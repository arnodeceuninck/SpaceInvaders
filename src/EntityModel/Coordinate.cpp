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

spaceinvaders::Coordinate spaceinvaders::Coordinate::operator+(const spaceinvaders::Coordinate &rhs) const {
    double x2 = x + rhs.getX();
    double y2 = y + rhs.getY();
    return Coordinate(x2, y2);
}

spaceinvaders::Coordinate spaceinvaders::Coordinate::operator-(const spaceinvaders::Coordinate &rhs) const {
    double x2 = x - rhs.getX();
    double y2 = y - rhs.getY();
    return Coordinate(x2, y2);
}

spaceinvaders::Coordinate spaceinvaders::Coordinate::operator*(const double &k) const {
    double x2 = x * k;
    double y2 = y * k;
    return Coordinate(x2, y2);
}

spaceinvaders::Coordinate spaceinvaders::Coordinate::operator+=(const spaceinvaders::Coordinate &rhs) {
    x += rhs.getX();
    y += rhs.getY();
    return *this;
}

spaceinvaders::Coordinate spaceinvaders::Coordinate::operator-=(const spaceinvaders::Coordinate &rhs) {
    x -= rhs.getX();
    y -= rhs.getY();
    return *this;
}

spaceinvaders::Coordinate spaceinvaders::Coordinate::operator*=(const double &k) {
    x *= k;
    y *= k;
    return *this;
}

spaceinvaders::Coordinate::Coordinate(double x, double y) : x(x), y(y) {}

void spaceinvaders::Coordinate::mulY(const double &k) {
    y *= k;
}

void spaceinvaders::Coordinate::mulX(const double &k) {
    x *= k;
}

void spaceinvaders::Coordinate::setX(double x) {
    Coordinate::x = x;
}

void spaceinvaders::Coordinate::setY(double y) {
    Coordinate::y = y;
}


