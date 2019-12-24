//
// Created by arno on 14/12/2019.
//

#include "BackgroundTiles.h"


spaceinvaders::view::BackgroundTiles::BackgroundTiles(std::string filename, std::shared_ptr<GameWindow> window)
        : EntityRepresentation(window) {
    texture.loadFromFile(filename);
    texture.setRepeated(true);
}

void spaceinvaders::view::BackgroundTiles::draw() {

    std::shared_ptr<sf::RenderWindow> sfmlWindow = getWindow()->getSfmlWindow();

    // Define a rectangle to draw the background on
    sf::View view(sfmlWindow->getDefaultView());
    sf::FloatRect fBounds(0.f, 0.f, 1000.f, 1000.f); // TODO: How to span over entire window?

    sf::IntRect iBounds(fBounds);
    sf::Sprite Sprite(texture, iBounds);

    // move sprite 'up' by its height except the view height for start:
    Sprite.setPosition(fBounds.left, fBounds.top - 1000.f + view.getSize().y);

    sfmlWindow->setView(view);
    sfmlWindow->draw(Sprite);
    sfmlWindow->display();
}

void spaceinvaders::view::BackgroundTiles::handleEvent(std::shared_ptr<spaceinvaders::event::Event> &event) {
    EntityRepresentation::handleEvent(event);
}
