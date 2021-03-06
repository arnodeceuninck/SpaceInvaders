//
// Created by arno on 14/12/2019.
//

#ifndef SPACEINVADERS_GAMEREPRESENTATION_H
#define SPACEINVADERS_GAMEREPRESENTATION_H

#include "../Observer/Observable.h"
#include "EntityRepresentation.h"
#include "Transformation.h"
#include <set>

namespace sf {
class RenderWindow;
}

namespace spaceinvaders::model {
class ModelChangedEvent;

class GameModel;
} // namespace spaceinvaders::model

namespace spaceinvaders::view {
class GameRepresentation : public EntityRepresentation
{
public:
        /**
         * Show a string on the screen (only the background and the string itself will be rendered)
         * @param message The message you want to display
         */
        void showMessage(const std::string& message);

        /**
         * Reset the view (to prepare for a new level)
         */
        void reset();

        /**
         * Handle an event
         * @param event
         */
        void handleEvent(std::shared_ptr<spaceinvaders::event::Event>& event) override;

        std::set<std::shared_ptr<EntityRepresentation>>
            representationEntities; // Holds a seperate list, so observer can be implemented with weak_ptrs and to
        // assure there is always a shared pointer for shared_from_this
        std::string messageText;

public:
        /**
         * Draw itself on the window
         */
        void draw() override;

        /**
         * Update the window
         */
        void update();

        /**
         * Create a new GameRepresentation
         * @param gameModel The model it wil represent
         * @param gameWindow The window it will draw on
         */
        GameRepresentation(const std::shared_ptr<spaceinvaders::model::GameModel>& gameModel,
                           const std::shared_ptr<GameWindow>& gameWindow);

        /**
         * Apply a tiles background
         * @param background The texture file of the background
         */
        void setBackground(const std::string& background);

private:
        std::string bground;
};
} // namespace spaceinvaders::view

#endif // SPACEINVADERS_GAMEREPRESENTATION_H
