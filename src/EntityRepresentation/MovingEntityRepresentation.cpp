//
// Created by arno on 22/12/2019.
//

#include "MovingEntityRepresentation.h"
#include "../EntityModel/Ship.h"
#include "../Events/PositionUpdated.h"
#include "../Exceptions/FileMissing.h"
#include "../Exceptions/ObjectNullException.h"
#include "../Exceptions/WrongObject.h"
#include "Transformation.h"

// spaceinvaders::view::MovingEntityRepresentation::MovingEntityRepresentation(std::shared_ptr<GameWindow> window,
//                                                                            std::shared_ptr<Transformation>
//                                                                            transformation)
//        : EntityRepresentation(
//        window, transformation) {}

void spaceinvaders::view::MovingEntityRepresentation::handleEvent(std::shared_ptr<spaceinvaders::event::Event>& event)
{
        EntityRepresentation::handleEvent(event);
        if (auto posEvent = std::dynamic_pointer_cast<spaceinvaders::event::PositionUpdated>(event)) {
                auto sprite324 = getSprite();
                Coordinate position = Transformation::getInstance().transform(posEvent->getNewPosition());
                sprite324.setPosition(static_cast<float>(position.getX()), static_cast<float>(position.getY()));
                setSprite(sprite324);
        }
}

void spaceinvaders::view::MovingEntityRepresentation::draw()
{

        sf::Sprite sprite324 = getSprite();
        sf::Texture texture324 = getTexture();

        if (!isInit()) {

                if (!texture324.loadFromFile(getSpriteFile())) {
                        throw spaceinvaders::exception::FileMissing(getSpriteFile());
                        // error...
                }

                //    sf::Sprite sprite;
                sprite324.setTexture(texture324);
                //    sprite324.setOrigin(0.f, 0.f);
                sprite324.setOrigin(static_cast<float>(sprite324.getTextureRect().width) / 2,
                                    static_cast<float>(sprite324.getTextureRect().height) / 2);
                if (auto entitySP = getEntity().lock()) {
                        if (auto ship = std::dynamic_pointer_cast<spaceinvaders::model::MovingEntity>(entitySP)) {
                                float spriteWidth = sprite324.getTextureRect().width;
                                float spriteHeight = sprite324.getTextureRect().height;
                                auto shipWidth = ship->getWidth();
                                auto shipHeight = ship->getHeight();
                                Transformation::getInstance().transform(shipWidth, shipHeight);
                                sprite324.scale(static_cast<float>(shipWidth) / spriteWidth,
                                                static_cast<float>(shipHeight) / spriteHeight);
                        } else {
                                throw spaceinvaders::exception::WrongObject("ship");
                        }
                }

                setSprite(sprite324);
                setTexture(texture324);

                setInit(true);
        }

        //    if (auto entitySP = getEntity().lock()) {
        //        if (auto ship = std::dynamic_pointer_cast<spaceinvaders::model::MovingEntity>(entitySP)) {
        //            Coordinate position = getTransformation()->transform(ship->getPosition());
        //            sprite324.setPosition(position.getX(), position.getY());
        //        }
        //    }
        //    sprite.setScale(0.5);

        if (getWindow() == nullptr and getWindow()->getSfmlWindow() == nullptr)
                throw spaceinvaders::exception::ObjectNullException(
                    "Window missing in entity or sfmlWindow missing in window");

        getWindow()->getSfmlWindow()->draw(sprite324);
        //    std::cout << "Drawing ship" << std::endl;
}

spaceinvaders::view::MovingEntityRepresentation::MovingEntityRepresentation(
    const std::shared_ptr<spaceinvaders::model::EntityModel>& entity, const std::shared_ptr<GameWindow>& window,
    const std::string& sprite)
    : EntityRepresentation(entity, window, sprite)
{

        //    sf::Sprite sprite324 = getSprite();
        //    sf::Texture texture324 = getTexture();
}
