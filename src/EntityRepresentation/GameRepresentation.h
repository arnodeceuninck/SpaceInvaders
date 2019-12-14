//
// Created by arno on 14/12/2019.
//

#ifndef SPACEINVADERS_GAMEREPRESENTATION_H
#define SPACEINVADERS_GAMEREPRESENTATION_H


#include <SFML/Graphics.hpp>
#include <memory>

namespace spaceinvaders::view {
    class GameRepresentation {
    public:
        GameRepresentation();

    private:
        std::shared_ptr<sf::RenderWindow> window;
    };
}


#endif //SPACEINVADERS_GAMEREPRESENTATION_H
