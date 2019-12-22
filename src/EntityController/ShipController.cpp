//
// Created by arno on 22/12/2019.
//

#include <iostream>
#include "ShipController.h"
#include "../Events/WindowInteractionEvent.h"

void spaceinvaders::controller::ShipController::handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) {
    if (auto wiEvent = std::dynamic_pointer_cast<spaceinvaders::event::WindowInteractionEvent>(event)) {
        if (wiEvent->getEvent().type == sf::Event::KeyPressed) {
            const auto &sfKeyEvent = wiEvent->getEvent().key.code;
            switch (sfKeyEvent) {
                case sf::Keyboard::Left:
                case sf::Keyboard::A:
                    std::cout << "Moving left" << std::endl;
                    break;
                case sf::Keyboard::Right:
                case sf::Keyboard::D:
                    std::cout << "Moving right" << std::endl;
                    break;
                case sf::Keyboard::Up:
                case sf::Keyboard::Down:
                case sf::Keyboard::Space:
                case sf::Keyboard::W:
                case sf::Keyboard::S:
                    std::cout << "Fire!" << std::endl;
                    break;
            }
        }
    }
}
