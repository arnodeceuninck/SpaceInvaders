//
// Created by arno on 22/12/2019.
//

#ifndef SPACEINVADERS_WINDOWINTERACTIONEVENT_H
#define SPACEINVADERS_WINDOWINTERACTIONEVENT_H

#include "ControllerEvent.h"
#include <SFML/Window/Event.hpp>

namespace spaceinvaders::event {
class WindowInteractionEvent : public ControllerEvent
{
        sf::Event event;

public:
        /**
         * Constructor
         * @param event sf::event corresponding to the interaction
         */
        explicit WindowInteractionEvent(const sf::Event& event);

        /**
         * Get the corresponding sf::Event
         * @return the event
         */
        [[nodiscard]] const sf::Event& getEvent() const;
};
} // namespace spaceinvaders::event

#endif // SPACEINVADERS_WINDOWINTERACTIONEVENT_H
