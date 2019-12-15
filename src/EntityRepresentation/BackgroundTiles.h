//
// Created by arno on 14/12/2019.
//

#ifndef SPACEINVADERS_BACKGROUNDTILES_H
#define SPACEINVADERS_BACKGROUNDTILES_H


#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>
#include "EntityRepresentation.h"

namespace spaceinvaders::view {
    class BackgroundTiles : public EntityRepresentation {
    public:
        BackgroundTiles(std::string filename);

        void draw(sf::RenderWindow &sfmlWindow);

    private:
        sf::Texture texture;
    };
}


#endif //SPACEINVADERS_BACKGROUNDTILES_H
