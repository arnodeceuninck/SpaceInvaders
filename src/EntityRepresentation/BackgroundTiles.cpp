//
// Created by arno on 14/12/2019.
//

#include "BackgroundTiles.h"

spaceinvaders::view::BackgroundTiles::BackgroundTiles(const std::string& filename,
                                                      const std::shared_ptr<GameWindow>& window)
    : EntityRepresentation(window)
{
        texture.loadFromFile(filename);
        texture.setRepeated(true);

        std::shared_ptr<sf::RenderWindow> sfmlWindow = getWindow()->getSfmlWindow();

        // Define a rectangle to draw the background on
        sf::View view(sfmlWindow->getDefaultView());
        sf::FloatRect fBounds(0.f, 0.f, 1000.f, 1000.f); // TODO: How to span over entire window?

        sf::IntRect iBounds(fBounds);
        sf::Sprite sprite(texture, iBounds);

        // move sprite 'up' by its height except the view height for start:
        sprite.setPosition(fBounds.left, fBounds.top - 1000.f + view.getSize().y);

        sfmlWindow->setView(view);
        setSprite(sprite);
}

void spaceinvaders::view::BackgroundTiles::draw()
{
        getWindow()->getSfmlWindow()->draw(getSprite());
        //    sfmlWindow->display();
}

void spaceinvaders::view::BackgroundTiles::handleEvent(std::shared_ptr<spaceinvaders::event::Event>& event)
{
        EntityRepresentation::handleEvent(event);
}
