//
// Created by arno on 15/12/2019.
//

#include "GameWindow.h"

spaceinvaders::GameWindow::GameWindow(int width, int height) : width(width), height(height) {
    sfmlWindow = std::make_shared<sf::RenderWindow>(sf::VideoMode(width, height), "Space Invaders");
}


int spaceinvaders::GameWindow::getWidth() const {
    return width;
}

int spaceinvaders::GameWindow::getHeight() const {
    return height;
}

const std::shared_ptr<sf::RenderWindow> &spaceinvaders::GameWindow::getSfmlWindow() const {
    return sfmlWindow;
}

void spaceinvaders::GameWindow::checkInput() {
    while (sfmlWindow->pollEvent(lastEvent)) {
//        notifyObservers(lastEvent);
    }
}
