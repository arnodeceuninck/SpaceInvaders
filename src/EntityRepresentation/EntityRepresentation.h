//
// Created by arno on 14/12/2019.
//

#ifndef SPACEINVADERS_ENTITYREPRESENTATION_H
#define SPACEINVADERS_ENTITYREPRESENTATION_H

#include "../GameWindow.h"

namespace spaceinvaders::view {
    class EntityRepresentation : public observer::Observer {
        std::string spriteFile;
    public:
        const std::string &getSpriteFile() const;

        void setSpriteFile(const std::string &spriteFile);
    };
}


#endif //SPACEINVADERS_ENTITYREPRESENTATION_H
