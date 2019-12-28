//
// Created by arno on 28/12/2019.
//

#ifndef SPACEINVADERS_LEVELSLOADER_H
#define SPACEINVADERS_LEVELSLOADER_H

#include "Loader.h"

namespace spaceinvaders::view {
    class GameRepresentation;
}
namespace spaceinvaders::model {
    class GameModel;
}
namespace spaceinvaders::loader {
    class LevelsLoader : public Loader {
    public:
        LevelsLoader(const std::string &filename);

        void loadInto(std::shared_ptr<spaceinvaders::model::GameModel> gameModel,
                      std::shared_ptr<spaceinvaders::view::GameRepresentation> gameRepresentation);
    };
}


#endif //SPACEINVADERS_LEVELSLOADER_H
