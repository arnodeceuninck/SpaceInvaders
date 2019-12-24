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
        BackgroundTiles(std::string filename, std::shared_ptr<GameWindow> window);

        void handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) override;

        void draw();

    private:
        sf::Texture texture;
    };
}


#endif //SPACEINVADERS_BACKGROUNDTILES_H
