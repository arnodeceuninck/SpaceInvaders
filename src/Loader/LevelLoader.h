//
// Created by arno on 23/12/2019.
//

#ifndef SPACEINVADERS_LEVELLOADER_H
#define SPACEINVADERS_LEVELLOADER_H

#include "../EntityModel/WorldModel.h"
#include "Loader.h"

namespace spaceinvaders::view {
    class GameRepresentation;
}

namespace spaceinvaders::model {
    class Ship;
}
namespace spaceinvaders::view {
    class MovingEntityRepresentation;
}
namespace spaceinvaders::controller {
    class GameController;

    class ShipController;
}

namespace spaceinvaders::loader {
    class LevelLoader : public Loader {
    public:
        LevelLoader(const std::string &filename);

        void loadInto(std::shared_ptr<spaceinvaders::model::WorldModel> worldModel,
                      std::shared_ptr<spaceinvaders::view::GameRepresentation> gameRepresentation,
                      std::shared_ptr<spaceinvaders::controller::GameController> gameController);

        void linkObservers(std::shared_ptr<spaceinvaders::model::WorldModel> &worldModel,
                           std::shared_ptr<spaceinvaders::view::GameRepresentation> &gameRepresentation,
                           std::shared_ptr<spaceinvaders::model::Ship> &ship,
                           const std::shared_ptr<spaceinvaders::view::MovingEntityRepresentation> &shipRepresentation,
                           const std::shared_ptr<spaceinvaders::controller::ShipController> &shipController,
                           std::shared_ptr<spaceinvaders::controller::GameController> gameController,
                           bool playerShip) const;
    };
}


#endif //SPACEINVADERS_LEVELLOADER_H
