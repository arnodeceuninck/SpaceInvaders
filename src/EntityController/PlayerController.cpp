//
// Created by arno on 22/12/2019.
//

#include "PlayerController.h"
#include "../EntityModel/Ship.h"
#include "../Events/MovingLeft.h"
#include "../Events/StoppedMovingLeft.h"
#include "../Events/WindowInteractionEvent.h"

void spaceinvaders::controller::PlayerController::handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) {
    if (auto wiEvent = std::dynamic_pointer_cast<spaceinvaders::event::WindowInteractionEvent>(event)) {
        if (wiEvent->getEvent().type == sf::Event::KeyPressed) {
            const auto &sfKeyEvent = wiEvent->getEvent().key.code;
            std::shared_ptr<spaceinvaders::event::Event> moveEvent;
            switch (sfKeyEvent) {
                case sf::Keyboard::Left:
                case sf::Keyboard::A:
                    go(Coordinate(-1, 0));
                    moveEvent = std::make_shared<spaceinvaders::event::MovingLeft>();
                    //                    std::cout << "Moving left" << std::endl;
                    break;
                case sf::Keyboard::Right:
                case sf::Keyboard::D:
                    go(Coordinate(1, 0));
                    //                    std::cout << "Moving right" << std::endl;
                    break;
                case sf::Keyboard::Up:
                case sf::Keyboard::Down:
                case sf::Keyboard::Space:
                case sf::Keyboard::W:
                case sf::Keyboard::S:
                    fire();
                    //                    std::cout << "Fire!" << std::endl;
                    break;
                default:
                    return;
            }
            notifyObservers(moveEvent);
        } else if (wiEvent->getEvent().type == sf::Event::KeyReleased) {
            const auto &sfKeyEvent = wiEvent->getEvent().key.code;
            std::shared_ptr<spaceinvaders::event::Event> stopMoveEvent;
            switch (sfKeyEvent) {
                case sf::Keyboard::Left:
                case sf::Keyboard::A:
                    go(Coordinate(0, 0));
                    stopMoveEvent = std::make_shared<spaceinvaders::event::StoppedMovingLeft>();
                    notifyObservers(stopMoveEvent);
                    //                    std::cout << "Stopped moving left" << std::endl;
                    break;
                case sf::Keyboard::Right:
                case sf::Keyboard::D:
                    go(Coordinate(0, 0));
                    //                    std::cout << "Stopped moving right" << std::endl;
                    break;
                case sf::Keyboard::Up:
                case sf::Keyboard::Down:
                case sf::Keyboard::Space:
                case sf::Keyboard::W:
                case sf::Keyboard::S:
                    //                    std::cout << "Stopped firing" << std::endl;
                    break;
                default:
                    return;
            }
            notifyObservers(stopMoveEvent);
        }
    }
}

spaceinvaders::controller::PlayerController::PlayerController() = default;
