//
// Created by arno on 17/12/2019.
//

#include "Transformation.h"

spaceinvaders::view::Transformation::Transformation(std::shared_ptr<Dimensions> gameWindow,
                                                    std::shared_ptr<Dimensions> gameModel) : gameDimensions(gameModel),
                                                                                             viewDimensions(
                                                                                                     gameWindow) {}

spaceinvaders::Coordinate spaceinvaders::view::Transformation::transform(spaceinvaders::Coordinate coordinate) {

    // Convert x and y to a coordinate system with same width and height as gameDimensions, but with (0, 0) as starting point
    coordinate -= gameDimensions->getMin();

    // Scale x and y to the viewDimensions
    coordinate *= viewDimensions->getWidth() / gameDimensions->getWidth();

    // Change the (0, 0) starting point to the starting point of the view
    coordinate += viewDimensions->getMin();

    return coordinate;
}

