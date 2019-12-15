//
// Created by arno on 15/12/2019.
//

#ifndef SPACEINVADERS_CLOCK_H
#define SPACEINVADERS_CLOCK_H


#include <chrono>

namespace spaceinvaders {
    class Clock {
    public:
        /**
         *  Start a new clock at the current time
         */
        Clock();

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


#endif //SPACEINVADERS_CLOCK_H
