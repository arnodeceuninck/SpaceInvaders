//
// Created by arno on 17/12/2019.
//

#ifndef SPACEINVADERS_DIMENSIONS_H
#define SPACEINVADERS_DIMENSIONS_H

#include "Coordinate.h"

namespace spaceinvaders {
    class Dimensions {
    public:
        Dimensions(const Coordinate &min, const Coordinate &max);

        double getWidth();

        double getHeight();

        const Coordinate &getMin() const;

        const Coordinate &getMax() const;

    private:
        Coordinate min;
        Coordinate max;
    };
}


#endif //SPACEINVADERS_DIMENSIONS_H
