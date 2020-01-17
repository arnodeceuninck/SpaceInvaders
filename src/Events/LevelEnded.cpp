//
// Created by arno on 28/12/2019.
//

#include "LevelEnded.h"

bool spaceinvaders::event::LevelEnded::isWin() const { return win; }

spaceinvaders::event::LevelEnded::LevelEnded(bool win) : win(win) {}
