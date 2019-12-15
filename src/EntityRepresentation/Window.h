//
// Created by arno on 15/12/2019.
//

#ifndef SPACEINVADERS_WINDOW_H
#define SPACEINVADERS_WINDOW_H


#include <memory>
#include "SFML/Graphics.hpp"
#include "BackgroundTiles.h"

namespace spaceinvaders::view {
    class Window {
    public:
        Window(int width, int height);

        void setBackground(BackgroundTiles &background);

        int getWidth() const;

        int getHeight() const;

    private:
        int width;
        int height;
        std::shared_ptr<sf::RenderWindow> sfmlWindow;
    };
}


#endif //SPACEINVADERS_WINDOW_H
