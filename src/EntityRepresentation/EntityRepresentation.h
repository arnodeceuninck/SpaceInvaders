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

    class EntityRepresentation : public observer::Observer,
                                 public observer::Observable,
                                 public std::enable_shared_from_this<EntityRepresentation> {
        std::string spriteFile;
        sf::Texture texture;
        sf::Sprite sprite;
        std::weak_ptr<spaceinvaders::model::EntityModel> entity;
        std::shared_ptr<GameWindow> window;
        bool init = false;

    public:
        /**
         * Get the texture file of the entity
         * @return the texture
         */
        sf::Texture &getTexture();

        /**
         * Get the sprite of the file
         * @return the sprite
         */
        sf::Sprite &getSprite();

        /**
         * Check whether the draw function has been initialized
         * @return whether it is initialized
         */
        bool isInit() const;

        /**
         * Let the representation know it has been initialised
         * @param init Whether it has been initialized
         */
        void setInit(bool init);

        /**
         * Apply a texture to an entity
         * @param texture the file to the texture you want to apply
         */
        void setTexture(const sf::Texture &texture);

        /**
         * Update the sprite
         * @param sprite
         */
        void setSprite(const sf::Sprite &sprite);

        /**
         * Constructor
         * @param window
         */
        explicit EntityRepresentation(std::shared_ptr<GameWindow> window);

        /**
         * Get the model entity it is representing
         * @return the entity
         */
        const std::weak_ptr<spaceinvaders::model::EntityModel> &getEntity() const;

        /**
         * Get the window that is being drawn on
         * @return
         */
        std::shared_ptr<GameWindow> &getWindow();

        /**
         * Get the sprite file
         * @return The sprite file
         */
        const std::string &getSpriteFile() const;

        /**
         * Handle an spaceinvaders::event::Event
         * @param event
         */
        void handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) override;

        /**
         * Update the sprite file
         * @param spriteFile
         */
        void setSpriteFile(const std::string &spriteFile);

        /**
         * Draw itself on the gamewindow
         */
        virtual void draw() = 0;

        /**
         * Constructor
         * @param entity Model it is representing
         * @param window GameWindow to draw on
         * @param sprite
         */
        EntityRepresentation(const std::shared_ptr<spaceinvaders::model::EntityModel> &entity,
                             std::shared_ptr<GameWindow> window, const std::string &sprite);
    };
} // namespace spaceinvaders::view

#endif // SPACEINVADERS_ENTITYREPRESENTATION_H
