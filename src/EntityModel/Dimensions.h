//
// Created by arno on 17/12/2019.
//

#ifndef SPACEINVADERS_DIMENSIONS_H
#define SPACEINVADERS_DIMENSIONS_H

#include "Coordinate.h"

namespace spaceinvaders {
class Dimensions {
public:
    /**
     * Constructor
     * @param min Lower left corner
     * @param max Upper right corner
     */
    Dimensions(const Coordinate &min, const Coordinate &max);

    /**
     * Get the width
     * @return
     */
        double getWidth();

        /**
         * Get the height
         * @return
         */
        double getHeight();

    /**
     * Get the lower left corner
     * @return
     */
    [[nodiscard]] const Coordinate &getMin() const;

    /**
     * Get the upper right corner
     * @return
     */
    //        [[nodiscard]] const Coordinate &getMax() const;

private:
    Coordinate min;
    Coordinate max;
};
} // namespace spaceinvaders

#endif // SPACEINVADERS_DIMENSIONS_H
