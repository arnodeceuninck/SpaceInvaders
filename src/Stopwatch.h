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

        static Stopwatch &getInstance();

        /**
         * Change the time from which the clock calculates it's duration to the currentTime
         */
        void reset();

        /**
         * Get the duration between the last reset point (or creation of the clock) till the current time
         * @return double containing the elapsed seconds between last reset point and current time
         */
        double elapsedTime();

        /**
         * Prevent copy-constructor
         */
        Stopwatch(Stopwatch const &) = delete;

        /**
         * Prevent assignment
         */
        void operator=(Stopwatch const &) = delete;


    private:

        /**
         *  Start a new clock at the current time
         */
        Stopwatch();

        std::chrono::system_clock::time_point startTime;

        static std::chrono::system_clock::time_point currentTime();
    };
}


#endif //SPACEINVADERS_STOPWATCH_H
