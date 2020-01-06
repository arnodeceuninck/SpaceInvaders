//
// Created by arno on 14/12/2019.
//

#ifndef SPACEINVADERS_BACKGROUNDTILES_H
#define SPACEINVADERS_BACKGROUNDTILES_H

#include "EntityRepresentation.h"
#include <string>

namespace spaceinvaders::view {
    class BackgroundTiles : public EntityRepresentation {
    public:
        /**
         * Constructor
         * @param filename containing the background texture
         * @param window to draw on
         */
        BackgroundTiles(const std::string &filename, const std::shared_ptr<GameWindow> &window);

        /**
         * Handle an event
         * @param event
         */
        void handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) override;

        /**
         * Draw itself on the screen
         */
        void draw() override;

    private:
        sf::Texture texture;
    };
}


#endif //SPACEINVADERS_BACKGROUNDTILES_H
