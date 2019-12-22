//
// Created by arno on 22/12/2019.
//

#include <iostream>
#include "ShipController.h"
#include "../Events/WindowInteractionEvent.h"

void spaceinvaders::controller::ShipController::handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) {
    if (auto wiEvent = std::dynamic_pointer_cast<spaceinvaders::event::WindowInteractionEvent>(event)) {
        if (wiEvent->getEvent().type == sf::Event::KeyPressed) {
            if (wiEvent->getEvent().key.code == sf::Keyboard::A or wiEvent->getEvent().key.code == sf::Keyboard::Left) {
                std::cout << "Moving left" << std::endl;
            }
        }
    }
}
