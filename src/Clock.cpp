//
// Created by arno on 15/12/2019.
//

#include "Clock.h"

spaceinvaders::Clock::Clock() {
    reset();
}

void spaceinvaders::Clock::reset() {
    startTime = std::chrono::system_clock::now();
}

double spaceinvaders::Clock::elapsedTime() {
    return (currentTime() - startTime).count();
}

std::chrono::system_clock::time_point spaceinvaders::Clock::currentTime() {
    return std::chrono::system_clock::now();
}
