//
// Created by arno on 15/12/2019.
//

#ifndef SPACEINVADERS_GAMEWINDOW_H
#define SPACEINVADERS_GAMEWINDOW_H


#include <memory>
#include "SFML/Graphics.hpp"
#include "Observer/Observable.h"

namespace spaceinvaders {
    class GameWindow : public observer::Observable<sf::Event> {
    public:
        GameWindow(int width, int height);

        int getWidth() const;

        int getHeight() const;

        void checkInput();

        const std::shared_ptr<sf::RenderWindow> &getSfmlWindow() const;

    private:
        sf::Event lastEvent;
        int width;
        int height;
        std::shared_ptr<sf::RenderWindow> sfmlWindow;
    };
}


#endif //SPACEINVADERS_GAMEWINDOW_H
