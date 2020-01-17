//
// Created by arno on 25/12/2019.
//

#ifndef SPACEINVADERS_ROCKETPOSITIONUPDATED_H
#define SPACEINVADERS_ROCKETPOSITIONUPDATED_H

#include "Event.h"
#include <memory>

namespace spaceinvaders::model {
class RocketModel;
}

namespace spaceinvaders::event {
class RocketPositionUpdated : public Event
{

private:
        std::shared_ptr<spaceinvaders::model::RocketModel> rocket;

public:
        [[nodiscard]] const std::shared_ptr<spaceinvaders::model::RocketModel>& getRocket() const;

public:
        explicit RocketPositionUpdated(std::shared_ptr<spaceinvaders::model::RocketModel> rocket);
};
} // namespace spaceinvaders::event

#endif // SPACEINVADERS_ROCKETPOSITIONUPDATED_H
