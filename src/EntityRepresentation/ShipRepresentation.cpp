//
// Created by arno on 22/12/2019.
//

#include <iostream>
#include "ShipRepresentation.h"
#include "../EntityModel/Ship.h"
#include "Transformation.h"

spaceinvaders::view::ShipRepresentation::ShipRepresentation(std::shared_ptr<GameWindow> window,
                                                            std::shared_ptr<Transformation> transformation)
        : EntityRepresentation(
        window, transformation) {}


void spaceinvaders::view::ShipRepresentation::handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) {
    EntityRepresentation::handleEvent(event);
}

void spaceinvaders::view::ShipRepresentation::draw() {
    sf::Texture texture;
    if (!texture.loadFromFile(getSpriteFile())) {
        throw std::ios_base::failure("File not found: " + getSpriteFile());
        // error...
    }

    sf::Sprite sprite;
    sprite.setTexture(texture);
//    sprite.setOrigin(0.f, 0.f);
    sprite.setOrigin(sprite.getTextureRect().width / 2, sprite.getTextureRect().height / 2);
    if (auto ship = std::dynamic_pointer_cast<spaceinvaders::model::Ship>(getEntity())) {
        float spriteWidth = sprite.getTextureRect().width;
        float spriteHeight = sprite.getTextureRect().height;
        float shipWidth = ship->getWidth();
        float shipHeight = ship->getHeight();
        getTransformation()->transform(shipWidth, shipHeight);
        sprite.scale(shipWidth / spriteWidth, shipHeight / spriteHeight);
    } else {
        throw std::logic_error("Entity is not a ship");
    }

//    sprite.setScale(0.5);

    getWindow()->getSfmlWindow()->draw(sprite);
    std::cout << "Drawing ship" << std::endl;
}
