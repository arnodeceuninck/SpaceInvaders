//
// Created by arno on 15/12/2019.
//

#include "Stopwatch.h"

spaceinvaders::Stopwatch::Stopwatch() { reset(); }

void spaceinvaders::Stopwatch::reset() { startTime = std::chrono::system_clock::now(); }

double spaceinvaders::Stopwatch::elapsedTime() { return (currentTime() - startTime).count(); }

std::chrono::system_clock::time_point spaceinvaders::Stopwatch::currentTime()
{
        return std::chrono::system_clock::now();
}

spaceinvaders::Stopwatch& spaceinvaders::Stopwatch::getInstance()
{
        static Stopwatch instance;
        return instance;
}
