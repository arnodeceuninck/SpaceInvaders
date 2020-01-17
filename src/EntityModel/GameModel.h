//
// Created by arno on 14/12/2019.
//

#ifndef SPACEINVADERS_GAMEMODEL_H
#define SPACEINVADERS_GAMEMODEL_H

#include "../EntityController/GameController.h"
#include "../EntityRepresentation/GameRepresentation.h"
#include "EntityModel.h"
#include <stack>

namespace spaceinvaders::model {
    class WorldModel;

    class GameModel : public EntityModel {

    public:
        /**
         * Get the Game Wold
         * @return
         */
        const std::shared_ptr<WorldModel> &getGameWorld() const;

        /**
         * Constructor
         */
        GameModel();

        /**
         * Load the next level
         */
        void load();

        /**
         * Handle an event
         * @param event
         */
        void handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) override;

        /**
         * Update its position
         * @param elapsedSeconds
         */
        void update(double elapsedSeconds) override;

        /**
         * Get the game dimensions
         * @return
         */
        const std::shared_ptr<Dimensions> &getDimensions() const;

        /**
         * Add a level on the level stack
         * @param level
         */
        void addLevel(const std::string &level);

    private:
        std::shared_ptr<WorldModel> gameWorld;
        std::shared_ptr<Dimensions> dimensions = std::make_shared<Dimensions>(Coordinate(-4, -3), Coordinate(4, 3));
        std::stack<std::string> levels;
    };
} // namespace spaceinvaders::model

#endif // SPACEINVADERS_GAMEMODEL_H
