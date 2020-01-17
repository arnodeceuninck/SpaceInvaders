//
// Created by arno on 28/12/2019.
//

#ifndef SPACEINVADERS_LOADLEVEL_H
#define SPACEINVADERS_LOADLEVEL_H

#include "Event.h"
#include <string>

namespace spaceinvaders::event {
    class LoadLevel : public Event {
        std::string level;

    public:
        /**
         * Request a specific level to be loaded
         * @param level The level to be loaded (filename)
         */
        explicit LoadLevel(std::string level);

        /**
         * Get the level that should be loaded
         * @return filename of the level (in the levels folder)
         */
        [[nodiscard]] const std::string &getLevel() const;
    };
} // namespace spaceinvaders::event

#endif // SPACEINVADERS_LOADLEVEL_H
