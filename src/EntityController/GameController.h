//
// Created by arno on 14/12/2019.
//

#ifndef SPACEINVADERS_GAMECONTROLLER_H
#define SPACEINVADERS_GAMECONTROLLER_H

#include "EntityController.h"

namespace spaceinvaders::controller {
    class GameController : public EntityController {
    public:
        void checkInput();

        GameController(const std::shared_ptr<spaceinvaders::model::EntityModel> &model);

    private:
    };
}


#endif //SPACEINVADERS_GAMECONTROLLER_H
