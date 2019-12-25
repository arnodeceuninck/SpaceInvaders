//
// Created by arno on 14/12/2019.
//

#ifndef SPACEINVADERS_WORLDMODEL_H
#define SPACEINVADERS_WORLDMODEL_H


#include "EntityModel.h"

namespace spaceinvaders::model {

class WorldModel : public EntityModel, public std::enable_shared_from_this<WorldModel> {
private:
//        std::set<std::shared_ptr<EntityModel>> entities;
    public:
        void handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) override;

        void update(double elapsedSeconds) override;
    };

}

#endif //SPACEINVADERS_WORLDMODEL_H
