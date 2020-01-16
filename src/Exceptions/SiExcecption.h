//
// Created by arno on 15/01/2020.
//

#ifndef SPACEINVADERS_SIEXCECPTION_H
#define SPACEINVADERS_SIEXCECPTION_H

#include <exception>
#include <string>


namespace spaceinvaders::exception {

/**
 * Default exception type of errors occured in spaceinvaders
 */
    class SiException : public std::exception {
    private:
        std::string problem;
    public:
        /**
         * Make an exception
         * @param problem The problem why the exception is thrown
         */
        explicit SiException(std::string problem);

        /**
         * Get the reason that caused the exception
         * @return a c string describing the cause of the exception
         */
        [[nodiscard]] const char *what() const noexcept override;
    };

}


#endif //SPACEINVADERS_SIEXCECPTION_H
