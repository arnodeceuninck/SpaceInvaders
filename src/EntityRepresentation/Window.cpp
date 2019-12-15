//
// Created by arno on 15/12/2019.
//

#include "Window.h"

spaceinvaders::view::Window::Window(int width, int height) : width(width), height(height) {
    sfmlWindow = std::make_shared<sf::RenderWindow>(sf::VideoMode(width, height), "Space Invaders");
}

void spaceinvaders::view::Window::setBackground(spaceinvaders::view::BackgroundTiles &background) {
    background.draw(*sfmlWindow);
}

int spaceinvaders::view::Window::getWidth() const {
    return width;
}

int spaceinvaders::view::Window::getHeight() const {
    return height;
}
