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
class LevelsLoader : public Loader
{
public:
        /**
         * Make a loader for a levels json file
         * @param filename Name of the json file in the levels folder
         */
        explicit LevelsLoader(const std::string& filename);

        /**
         * Load the contents of the file in a gameModel and gameRepresentation
         * @param gameModel The model the levels will be added to
         * @param gameRepresentation The representation the background will be set on
         */
        void loadInto(const std::shared_ptr<spaceinvaders::model::GameModel>& gameModel,
                      const std::shared_ptr<spaceinvaders::view::GameRepresentation>& gameRepresentation);
};
} // namespace spaceinvaders::loader

#endif // SPACEINVADERS_LEVELSLOADER_H
