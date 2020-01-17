//
// Created by arno on 28/12/2019.
//

#ifndef SPACEINVADERS_GAMEENDED_H
#define SPACEINVADERS_GAMEENDED_H

#include "Event.h"

namespace spaceinvaders::event {
/**
 * Notify everyone the game has ended
 */
    class GameEnded : public Event {
    };
} // namespace spaceinvaders::event

#endif // SPACEINVADERS_GAMEENDED_H
