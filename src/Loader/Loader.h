//
// Created by arno on 22/12/2019.
//

#ifndef SPACEINVADERS_LOADER_H
#define SPACEINVADERS_LOADER_H

#include <string>

namespace spaceinvaders::loader {
    class Loader {
    private:
        std::string filename;
    public:
        Loader(const std::string &filename);

        const std::string &getFilename() const;
    };
}


#endif //SPACEINVADERS_LOADER_H