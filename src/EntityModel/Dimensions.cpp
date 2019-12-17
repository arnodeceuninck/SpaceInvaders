//
// Created by arno on 17/12/2019.
//

#include "Dimensions.h"

double spaceinvaders::Dimensions::getWidth() {
    return max.getX() - min.getX();
}

double spaceinvaders::Dimensions::getHeight() {
    return max.getY() - min.getY();
}


spaceinvaders::Dimensions::Dimensions(const spaceinvaders::Coordinate &min, const spaceinvaders::Coordinate &max) : min(
        min), max(max) {}

const spaceinvaders::Coordinate &spaceinvaders::Dimensions::getMin() const {
    return min;
}

const spaceinvaders::Coordinate &spaceinvaders::Dimensions::getMax() const {
    return max;
}
