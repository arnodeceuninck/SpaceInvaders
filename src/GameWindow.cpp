//
// Created by arno on 15/12/2019.
//

#include "GameWindow.h"
#include "Events/WindowInteractionEvent.h"

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
        std::shared_ptr<spaceinvaders::event::Event> event = std::make_shared<spaceinvaders::event::WindowInteractionEvent>(
                lastEvent);
        notifyObservers(event);
    }
}
