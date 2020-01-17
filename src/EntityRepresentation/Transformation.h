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
private:
    Transformation();

public:
    /**
     * Get an instance of the Transformation (singleton)
     * @return static transformation instance
     */
    static Transformation &getInstance();
    //        Transformation(std::shared_ptr<Dimensions> gameWindow, std::shared_ptr<Dimensions> gameModel);

    /**
     * Transform between dimensions
     * @param coordinate in gameDimensions
     * @return coordinate in viewDimensions
     */
    Coordinate transform(spaceinvaders::Coordinate coordinate);

    /**
     * Transform a width and height to view dimensions
     * @param width in gameDimensions which becomes view dimensions
     * @param height in gameDimensions which becomes view dimensions
     */
    void transform(double &width, double &height);

    /**
     * Change the dimensions of the game
     * @param gameDimensions the new dimensions
     */
    void setGameDimensions(const std::shared_ptr<Dimensions> &gameDimensions);

    /**
     * Change the dimensions of the view
     * @param viewDimensions the new Dimensions
     */
    void setViewDimensions(const std::shared_ptr<Dimensions> &viewDimensions);

    std::shared_ptr<Dimensions> gameDimensions;
    std::shared_ptr<Dimensions> viewDimensions;
};
} // namespace spaceinvaders::view

#endif // SPACEINVADERS_TRANSFORMATION_H
