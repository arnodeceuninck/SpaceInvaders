//
// Created by arno on 14/12/2019.
//

#ifndef SPACEINVADERS_ENTITYREPRESENTATION_H
#define SPACEINVADERS_ENTITYREPRESENTATION_H

#include "../GameWindow.h"
#include "Transformation.h"
#include <memory>

namespace spaceinvaders::model {
    class EntityModel;
}
namespace spaceinvaders::view {
    class GameRepresentation;

    class EntityRepresentation : public observer::Observer {
        std::string spriteFile;
        sf::Texture texture;
        sf::Sprite sprite;
        std::shared_ptr<spaceinvaders::model::EntityModel> entity;
        std::shared_ptr<GameWindow> window;
        std::shared_ptr<Transformation> transformation;
        bool init = false;
    public:
        sf::Texture &getTexture();

        sf::Sprite &getSprite();

        const std::shared_ptr<Transformation> &getTransformation() const;

        bool isInit() const;

        void setInit(bool init);

        void setTransformation(const std::shared_ptr<Transformation> &transformation);


    public:
        EntityRepresentation(const std::shared_ptr<GameWindow> &window, std::shared_ptr<Transformation> transformation);

        EntityRepresentation(const std::shared_ptr<GameWindow> &window);

        const std::shared_ptr<spaceinvaders::model::EntityModel> &getEntity() const;

        std::shared_ptr<GameWindow> &getWindow();

        const std::string &getSpriteFile() const;

        virtual void handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) override;

        void setSpriteFile(const std::string &spriteFile);

        virtual void draw() = 0;
    };
}


#endif //SPACEINVADERS_ENTITYREPRESENTATION_H
