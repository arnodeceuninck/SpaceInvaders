//
// Created by arno on 15/12/2019.
//

#ifndef SPACEINVADERS_STOPWATCH_H
#define SPACEINVADERS_STOPWATCH_H


#include <chrono>

// TODO: Singelton pattern

namespace spaceinvaders {
    class Stopwatch {
    public:
        /**
         *  Start a new clock at the current time
         */
        Stopwatch();

        /**
         * Change the time from which the clock calculates it's duration to the currentTime
         */
        void reset();

        /**
         * Get the duration between the last reset point (or creation of the clock) till the current time
         * @return double containing the elapsed seconds between last reset point and current time
         */
        double elapsedTime();

    private:
        std::chrono::system_clock::time_point startTime;

        std::chrono::system_clock::time_point currentTime();
    };
}


#endif //SPACEINVADERS_STOPWATCH_H