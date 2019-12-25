//
// Created by arno on 25/12/2019.
//

#ifndef SPACEINVADERS_ROCKETPOSITIONUPDATED_H
#define SPACEINVADERS_ROCKETPOSITIONUPDATED_H

#include <memory>
#include "Event.h"

namespace spaceinvaders::model {
    class RocketModel;
}

namespace spaceinvaders::event {
    class RocketPositionUpdated : public Event {
        std::shared_ptr<spaceinvaders::model::RocketModel> rocket;
    public:
        const std::shared_ptr<spaceinvaders::model::RocketModel> &getRocket() const;

    public:
        RocketPositionUpdated(const std::shared_ptr<spaceinvaders::model::RocketModel> &rocket);
    };
}


#endif //SPACEINVADERS_ROCKETPOSITIONUPDATED_H
