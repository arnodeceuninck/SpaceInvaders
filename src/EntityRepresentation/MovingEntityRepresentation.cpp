//
// Created by arno on 22/12/2019.
//

#include <iostream>
#include "MovingEntityRepresentation.h"
#include "../EntityModel/Ship.h"
#include "Transformation.h"

//spaceinvaders::view::MovingEntityRepresentation::MovingEntityRepresentation(std::shared_ptr<GameWindow> window,
//                                                                            std::shared_ptr<Transformation> transformation)
//        : EntityRepresentation(
//        window, transformation) {}


void spaceinvaders::view::MovingEntityRepresentation::handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) {
    EntityRepresentation::handleEvent(event);
}

void spaceinvaders::view::MovingEntityRepresentation::draw() {

    sf::Sprite sprite324 = getSprite();
    sf::Texture texture324 = getTexture();

    if (!isInit()) {
        if (!texture324.loadFromFile(getSpriteFile())) {
            throw std::ios_base::failure("File not found: " + getSpriteFile());
            // error...
        }

//    sf::Sprite sprite;
        sprite324.setTexture(texture324);
//    sprite324.setOrigin(0.f, 0.f);
        sprite324.setOrigin(sprite324.getTextureRect().width / 2, sprite324.getTextureRect().height / 2);
        if (auto ship = std::dynamic_pointer_cast<spaceinvaders::model::MovingEntity>(getEntity())) {
            float spriteWidth = sprite324.getTextureRect().width;
            float spriteHeight = sprite324.getTextureRect().height;
            float shipWidth = ship->getWidth();
            float shipHeight = ship->getHeight();
            getTransformation()->transform(shipWidth, shipHeight);
            sprite324.scale(shipWidth / spriteWidth, shipHeight / spriteHeight);


        } else {
            throw std::logic_error("Entity is not a ship");
        }

        setSprite(sprite324);
        setTexture(texture324);
        setInit(true);
    }

    if (auto ship = std::dynamic_pointer_cast<spaceinvaders::model::MovingEntity>(getEntity())) {
        Coordinate position = getTransformation()->transform(ship->getPosition());
        sprite324.setPosition(position.getX(), position.getY());
    }
//    sprite.setScale(0.5);

    getWindow()->getSfmlWindow()->draw(sprite324);
//    std::cout << "Drawing ship" << std::endl;
}

spaceinvaders::view::MovingEntityRepresentation::MovingEntityRepresentation(
        const std::shared_ptr<spaceinvaders::model::EntityModel> &entity, const std::shared_ptr<GameWindow> &window,
        const std::shared_ptr<Transformation> &transformation) : EntityRepresentation(entity, window, transformation) {}
