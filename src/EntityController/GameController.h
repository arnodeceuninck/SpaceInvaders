//
// Created by arno on 14/12/2019.
//

#ifndef SPACEINVADERS_GAMECONTROLLER_H
#define SPACEINVADERS_GAMECONTROLLER_H

#include "EntityController.h"

namespace spaceinvaders::controller {
    class GameController : public EntityController {
    public:
        void checkInput() override;

    private:
    };
}


#endif //SPACEINVADERS_GAMECONTROLLER_H
