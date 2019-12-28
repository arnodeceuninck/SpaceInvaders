//
// Created by arno on 14/12/2019.
//

#ifndef SPACEINVADERS_GAMEMODEL_H
#define SPACEINVADERS_GAMEMODEL_H


#include "EntityModel.h"
#include "../EntityRepresentation/GameRepresentation.h"
#include "../EntityController/GameController.h"
#include <stack>

namespace spaceinvaders::model {
    class WorldModel;

    class GameModel : public EntityModel {

    public:
        const std::shared_ptr<WorldModel> &getGameWorld() const;

        GameModel();

        void load();

        void handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) override;

        void update(double elapsedSeconds) override;

        const std::shared_ptr<Dimensions> &getDimensions() const;

        void addLevel(std::string level);

    private:
        std::shared_ptr<WorldModel> gameWorld;
        std::shared_ptr<Dimensions> dimensions = std::make_shared<Dimensions>(Coordinate(-4, -3), Coordinate(4, 3));
        std::stack<std::string> levels;

        std::shared_ptr<view::GameRepresentation> gameRepresentation;
        std::shared_ptr<controller::GameController> gameController;

        std::string currentLevel;

        void readLevels(const std::string &levelFile);
    };
}


#endif //SPACEINVADERS_GAMEMODEL_H
