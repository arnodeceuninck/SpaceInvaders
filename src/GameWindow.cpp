//
// Created by arno on 15/12/2019.
//

#include "GameWindow.h"
#include "Events/WindowInteractionEvent.h"
#include "Exceptions/ObjectNullException.h"

spaceinvaders::GameWindow::GameWindow(int width, int height) : width(width), height(height)
{
        sfmlWindow = std::make_shared<sf::RenderWindow>(
            sf::VideoMode(static_cast<unsigned int>(width), static_cast<unsigned int>(height)), "Space Invaders");
}

int spaceinvaders::GameWindow::getWidth() const { return width; }

int spaceinvaders::GameWindow::getHeight() const { return height; }

const std::shared_ptr<sf::RenderWindow>& spaceinvaders::GameWindow::getSfmlWindow() const { return sfmlWindow; }

void spaceinvaders::GameWindow::checkInput()
{
        if (sfmlWindow == nullptr)
                throw spaceinvaders::exception::ObjectNullException(
                    "sfmlWindow shouldn't be NULL when calling this function");

        while (sfmlWindow->pollEvent(lastEvent)) {
                std::shared_ptr<spaceinvaders::event::Event> event =
                    std::make_shared<spaceinvaders::event::WindowInteractionEvent>(lastEvent);
                notifyObservers(event);
        }
}

std::shared_ptr<spaceinvaders::Dimensions> spaceinvaders::GameWindow::getDimensions()
{
        Coordinate min{0, static_cast<double>(-height)};
        Coordinate max{static_cast<double>(width), 0};
        return std::make_shared<spaceinvaders::Dimensions>(min, max);
}
