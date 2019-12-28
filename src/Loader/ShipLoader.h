//
// Created by arno on 22/12/2019.
//

#ifndef SPACEINVADERS_SHIPLOADER_H
#define SPACEINVADERS_SHIPLOADER_H

#include <memory>
#include "Loader.h"

namespace spaceinvaders::view {
    class GameRepresentation;
}

namespace spaceinvaders::model {
    class Ship;
}

namespace spaceinvaders::loader {
    class ShipLoader : public Loader {
    public:
        void loadInto(const std::shared_ptr<spaceinvaders::model::Ship> &shipModel, std::string &spriteFile);

        explicit ShipLoader(const std::string &filename);
    };
}


#endif //SPACEINVADERS_SHIPLOADER_H
