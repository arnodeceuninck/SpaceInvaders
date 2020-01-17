//
// Created by arno on 14/12/2019.
//

#ifndef SPACEINVADERS_WORLDMODEL_H
#define SPACEINVADERS_WORLDMODEL_H

#include "EntityModel.h"
#include <set>

namespace spaceinvaders::model {

class WorldModel : public EntityModel {
private:
    std::set<std::shared_ptr<EntityModel>> movingEntities;
    int enemyCount = 0;

public:
    /**
     * Handle an event
     * @param event
     */
    void handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) override;

    /**
     * Update things that happened during a given time period
     * @param elapsedSeconds The elapsed time
     */
    void update(double elapsedSeconds) override;

    /**
     * Reset the worldmodel (to prepare for a new level)
     */
    void reset();
};

} // namespace spaceinvaders::model

#endif // SPACEINVADERS_WORLDMODEL_H
