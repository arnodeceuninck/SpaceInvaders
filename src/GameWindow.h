//
// Created by arno on 15/12/2019.
//

#ifndef SPACEINVADERS_GAMEWINDOW_H
#define SPACEINVADERS_GAMEWINDOW_H

#include "Observer/Observable.h"
#include "SFML/Graphics.hpp"
#include "EntityModel/Dimensions.h"

namespace spaceinvaders {
    class GameWindow : public observer::Observable {
    public:
        GameWindow(int width, int height);

        [[nodiscard]] int getWidth() const;

        [[nodiscard]] int getHeight() const;

        std::shared_ptr<Dimensions> getDimensions();

        void checkInput();

        [[nodiscard]] const std::shared_ptr<sf::RenderWindow> &getSfmlWindow() const;

    private:
        sf::Event lastEvent{};
        int width;
        int height;
        std::shared_ptr<sf::RenderWindow> sfmlWindow;
    };
}


#endif //SPACEINVADERS_GAMEWINDOW_H
