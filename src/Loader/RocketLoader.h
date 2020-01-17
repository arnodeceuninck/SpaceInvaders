//
// Created by arno on 28/12/2019.
//

#ifndef SPACEINVADERS_ROCKETLOADER_H
#define SPACEINVADERS_ROCKETLOADER_H

#include "Loader.h"

namespace spaceinvaders::model {
class RocketModel;
}
namespace spaceinvaders::loader {
    class RocketLoader : public Loader {
    public:
        /**
         * Make a rocketLoader for a specific file
         * @param filename The json file you want to create a loader for (in the levels folder)
         */
        explicit RocketLoader(const std::string &filename);

        /**
         * Load the contents of the file in a model
         * @param rocketModel The model to load the contents in
         * @param spriteFile return: the texture file described in the json
         */
        void loadInto(const std::shared_ptr<spaceinvaders::model::RocketModel> &rocketModel, std::string &spriteFile);
    };
} // namespace spaceinvaders::loader

#endif // SPACEINVADERS_ROCKETLOADER_H
