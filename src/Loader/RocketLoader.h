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
        explicit RocketLoader(const std::string &filename);

        void loadInto(const std::shared_ptr<spaceinvaders::model::RocketModel> &rocketModel, std::string &spriteFile);
    };
}


#endif //SPACEINVADERS_ROCKETLOADER_H
