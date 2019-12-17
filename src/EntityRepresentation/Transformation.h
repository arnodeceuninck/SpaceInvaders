//
// Created by arno on 17/12/2019.
//

#ifndef SPACEINVADERS_TRANSFORMATION_H
#define SPACEINVADERS_TRANSFORMATION_H

// TODO: singleton pattern

#include "../GameWindow.h"
#include "../EntityModel/GameModel.h"

namespace spaceinvaders::view {
    class Transformation {
    public:
        Transformation(std::shared_ptr<Dimensions> gameWindow, std::shared_ptr<Dimensions> gameModel);

        Coordinate transform(spaceinvaders::Coordinate coordinate);

        std::shared_ptr<Dimensions> gameDimensions;
        std::shared_ptr<Dimensions> viewDimensions;
    };
}

#endif //SPACEINVADERS_TRANSFORMATION_H
