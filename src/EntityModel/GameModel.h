//
// Created by arno on 14/12/2019.
//

#ifndef SPACEINVADERS_GAMEMODEL_H
#define SPACEINVADERS_GAMEMODEL_H


#include <memory>
#include "Dimensions.h"

namespace spaceinvaders::model {
    class GameModel {

    public:
        void update(double elapsedSeconds);

        const std::shared_ptr<Dimensions> &getDimensions() const;

    private:
        std::shared_ptr<Dimensions> dimensions = std::make_shared<Dimensions>(-4, 4, -3, 3);
    };
}


#endif //SPACEINVADERS_GAMEMODEL_H
