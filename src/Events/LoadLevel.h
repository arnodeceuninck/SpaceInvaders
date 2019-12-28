//
// Created by arno on 28/12/2019.
//

#ifndef SPACEINVADERS_LOADLEVEL_H
#define SPACEINVADERS_LOADLEVEL_H

#include <string>
#include "Event.h"

namespace spaceinvaders::event {
    class LoadLevel : public Event {
        std::string level;
    public:
        explicit LoadLevel(std::string level);

        [[nodiscard]] const std::string &getLevel() const;
    };
}


#endif //SPACEINVADERS_LOADLEVEL_H
