//
// Created by arno on 22/12/2019.
//

#ifndef SPACEINVADERS_LOADER_H
#define SPACEINVADERS_LOADER_H

#include <string>

#include "../../rapidjson/document.h"
#include "../Observer/Observable.h"

namespace spaceinvaders::loader {
    class Loader : public observer::Observable {
    private:
        std::string filename;
    public:
        explicit Loader(const std::string &filename);

        [[nodiscard]] rapidjson::Document getDocument() const;

        [[nodiscard]] const std::string &getFilename() const;
    };
}


#endif //SPACEINVADERS_LOADER_H
