//
// Created by arno on 15/01/2020.
//

#ifndef SPACEINVADERS_FILEMISSING_H
#define SPACEINVADERS_FILEMISSING_H

#include "SiExcecption.h"

namespace spaceinvaders::exception {
    /**
     * Class for when one of the required input files is missing
     */
    class FileMissing : public SiException {
    public:
        /**
         * Constructor
         * @param filename The name of the missing file
         */
        explicit FileMissing(const std::string &filename);
    };
}

#endif //SPACEINVADERS_FILEMISSING_H
