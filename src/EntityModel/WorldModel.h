//
// Created by arno on 14/12/2019.
//

#ifndef SPACEINVADERS_WORLDMODEL_H
#define SPACEINVADERS_WORLDMODEL_H


#include "EntityModel.h"
#include <list>

namespace spaceinvaders::model {

    class WorldModel : public EntityModel {
    private:
        std::list<std::shared_ptr<EntityModel>> movingEntities;
    public:
        void handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) override;

        void update(double elapsedSeconds) override;
    };

}

#endif //SPACEINVADERS_WORLDMODEL_H
