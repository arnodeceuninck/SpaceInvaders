//
// Created by arno on 24/12/2019.
//

#ifndef SPACEINVADERS_BULLETFIRED_H
#define SPACEINVADERS_BULLETFIRED_H

#include <memory>
#include "Event.h"
#include "../EntityModel/RocketModel.h"

namespace spaceinvaders::event {
    class BulletFired : public Event {
    public:
        BulletFired(const std::shared_ptr<spaceinvaders::model::RocketModel> &rocket);

        const std::shared_ptr<spaceinvaders::model::RocketModel> &getRocket() const;

    private:
        std::shared_ptr<spaceinvaders::model::RocketModel> rocket;
    };
}


#endif //SPACEINVADERS_BULLETFIRED_H
