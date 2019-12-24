//
// Created by arno on 24/12/2019.
//

#include "UpdateEvent.h"

spaceinvaders::event::UpdateEvent::UpdateEvent(double elapsedSeconds) : elapsedSeconds(elapsedSeconds) {}

double spaceinvaders::event::UpdateEvent::getElapsedSeconds() const {
    return elapsedSeconds;
}
