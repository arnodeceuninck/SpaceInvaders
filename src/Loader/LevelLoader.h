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

namespace spaceinvaders::loader {
    class LevelLoader : public Loader {
    public:
        LevelLoader(const std::string &filename);

        void loadInto(std::shared_ptr<spaceinvaders::model::WorldModel> worldModel,
                      std::shared_ptr<spaceinvaders::view::GameRepresentation> gameRepresentation);
    };
}


#endif //SPACEINVADERS_LEVELLOADER_H
