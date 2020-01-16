//
// Created by arno on 17/12/2019.
//

#include "Transformation.h"



spaceinvaders::Coordinate spaceinvaders::view::Transformation::transform(spaceinvaders::Coordinate coordinate) {

    // Convert x and y to a coordinate system with same width and height as gameDimensions, but with (0, 0) as starting point
    coordinate -= gameDimensions->getMin();

    // Scale x and y to the viewDimensions
    coordinate.mulX(viewDimensions->getWidth() / gameDimensions->getWidth());
    coordinate.mulY(viewDimensions->getHeight() / gameDimensions->getHeight());

    // Change the (0, 0) starting point to the starting point of the view
    coordinate += viewDimensions->getMin();

    // Y axis is inverted in sfml
    coordinate.mulY(-1);

    return coordinate;
}

void spaceinvaders::view::Transformation::transform(double &width, double &height) {
    width *= viewDimensions->getWidth() / gameDimensions->getWidth();
    height *= viewDimensions->getHeight() / gameDimensions->getHeight();
}

void spaceinvaders::view::Transformation::setGameDimensions(const std::shared_ptr<Dimensions> &gameDimensions) {
    Transformation::gameDimensions = gameDimensions;
}

void spaceinvaders::view::Transformation::setViewDimensions(const std::shared_ptr<Dimensions> &viewDimensions) {
    Transformation::viewDimensions = viewDimensions;
}

spaceinvaders::view::Transformation::Transformation() = default;

spaceinvaders::view::Transformation &spaceinvaders::view::Transformation::getInstance() {
    static Transformation instance;
    return instance;
}

