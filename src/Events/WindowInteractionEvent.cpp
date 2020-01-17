//
// Created by arno on 22/12/2019.
//

#include "WindowInteractionEvent.h"

const sf::Event& spaceinvaders::event::WindowInteractionEvent::getEvent() const { return event; }

spaceinvaders::event::WindowInteractionEvent::WindowInteractionEvent(const sf::Event& event) : event(event) {}
