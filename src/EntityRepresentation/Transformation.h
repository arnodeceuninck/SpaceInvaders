//
// Created by arno on 17/12/2019.
//

#ifndef SPACEINVADERS_TRANSFORMATION_H
#define SPACEINVADERS_TRANSFORMATION_H

#include "../EntityModel/Dimensions.h"
#include <memory>

// TODO: singleton pattern


namespace spaceinvaders::view {
    class Transformation {
    public:
        Transformation(std::shared_ptr<Dimensions> gameWindow, std::shared_ptr<Dimensions> gameModel);

        Coordinate transform(spaceinvaders::Coordinate coordinate);

        void transform(double &width, double &height);

        std::shared_ptr<Dimensions> gameDimensions;
        std::shared_ptr<Dimensions> viewDimensions;
    };
}

#endif //SPACEINVADERS_TRANSFORMATION_H
