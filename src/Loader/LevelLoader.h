//
// Created by arno on 23/12/2019.
//

#ifndef SPACEINVADERS_LEVELLOADER_H
#define SPACEINVADERS_LEVELLOADER_H

#include "../EntityModel/WorldModel.h"
#include "Loader.h"

namespace spaceinvaders::loader {
    class LevelLoader : public Loader {
        void loadInto(std::shared_ptr<spaceinvaders::model::WorldModel> worldModel);
    };
}


#endif //SPACEINVADERS_LEVELLOADER_H
