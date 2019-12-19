//
// Created by arno on 14/12/2019.
//

#ifndef SPACEINVADERS_GAMEMODEL_H
#define SPACEINVADERS_GAMEMODEL_H


#include "EntityModel.h"

namespace spaceinvaders::model {
    class GameModel : public EntityModel {

    public:
        void handleEvent(std::shared_ptr<spaceinvaders::Event> &event) override;

        void update(double elapsedSeconds);

        const std::shared_ptr<Dimensions> &getDimensions() const;

    private:
        std::shared_ptr<Dimensions> dimensions = std::make_shared<Dimensions>(Coordinate(-4, -3), Coordinate(4, 3));
    };
}


#endif //SPACEINVADERS_GAMEMODEL_H
