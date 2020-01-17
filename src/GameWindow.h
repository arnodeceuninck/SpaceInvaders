//
// Created by arno on 15/12/2019.
//

#ifndef SPACEINVADERS_GAMEWINDOW_H
#define SPACEINVADERS_GAMEWINDOW_H

#include "EntityModel/Dimensions.h"
#include "Observer/Observable.h"
#include "SFML/Graphics.hpp"

namespace spaceinvaders {
    class GameWindow : public observer::Observable {
    public:
        /**
         * Initialise a GameWindow (also initializes the sfml window)
         * @param width The width of the window
         * @param height The height of the window
         */
        GameWindow(int width, int height);

        /**
         * Obtain the width of the gamewindow
         * @return width of GameWindow
         */
        [[nodiscard]] int getWidth() const;

        /**
         * Obtain the height of gamewindow
         * @return height of GameWindow
         */
        [[nodiscard]] int getHeight() const;

        /**
         * Returns the dimensions (lowerleftcorner and uperrightcorner)
         * @return dimensions of gameWindow
         */
        std::shared_ptr<Dimensions> getDimensions();

        /**
         * Checks the sfmlWindow for updates and broadcasts an event if necessarily
         */
        void checkInput();

        /**
         * Get the sfml window
         * @return sfml window
         */
        [[nodiscard]] const std::shared_ptr<sf::RenderWindow> &getSfmlWindow() const;

    private:
        sf::Event lastEvent{};
        int width;
        int height;
        std::shared_ptr<sf::RenderWindow> sfmlWindow;
    };
} // namespace spaceinvaders

#endif // SPACEINVADERS_GAMEWINDOW_H
