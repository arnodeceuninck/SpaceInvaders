//
// Created by arno on 22/12/2019.
//

#ifndef SPACEINVADERS_SHIPLOADER_H
#define SPACEINVADERS_SHIPLOADER_H

#include "Loader.h"
#include <memory>

namespace spaceinvaders::view {
    class GameRepresentation;
}

namespace spaceinvaders::model {
    class Ship;
}

namespace spaceinvaders::loader {
    class ShipLoader : public Loader {
    public:
        /**
         * Load the contents of your file in a model
         * @param shipModel The shipmodel to load the contents in
         * @param spriteFile Returns the spritefile described in the json
         */
        void loadInto(const std::shared_ptr<spaceinvaders::model::Ship> &shipModel, std::string &spriteFile);

        /**
         * Make a loader for a specific file
         * @param filename The json file with the specifications of the ship (in the levels folder)
         */
        explicit ShipLoader(const std::string &filename);
    };
} // namespace spaceinvaders::loader

#endif // SPACEINVADERS_SHIPLOADER_H
