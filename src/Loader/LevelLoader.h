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
} // namespace spaceinvaders::controller

namespace spaceinvaders::loader {
class LevelLoader : public Loader
{
public:
        /**
         * Make a loader to load a single level in the world
         * @param filename Name of the json file describing the level (in the levels folder)
         */
        explicit LevelLoader(const std::string& filename);

        /**
         * Load the level into a representation and controller
         * @param gameRepresentation
         * @param gameController
         */
        void loadInto(const std::shared_ptr<spaceinvaders::view::GameRepresentation>& gameRepresentation,
                      const std::shared_ptr<spaceinvaders::controller::GameController>& gameController);
};
} // namespace spaceinvaders::loader

#endif // SPACEINVADERS_LEVELLOADER_H
