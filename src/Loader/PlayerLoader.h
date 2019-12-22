//
// Created by arno on 22/12/2019.
//

#ifndef SPACEINVADERS_PLAYERLOADER_H
#define SPACEINVADERS_PLAYERLOADER_H

#include <memory>
#include "Loader.h"

namespace spaceinvaders::view{
    class ShipRepresentation;
}

namespace spaceinvaders::model{
    class PlayerShip;
}

namespace spaceinvaders::loader {
    class PlayerLoader : public Loader {
        void loadInto(std::shared_ptr<spaceinvaders::model::PlayerShip> shipModel, std::shared_ptr<spaceinvaders::view::ShipRepresentation> shipRepresentation);
    };
}


#endif //SPACEINVADERS_PLAYERLOADER_H
