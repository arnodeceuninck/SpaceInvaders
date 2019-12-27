//
// Created by arno on 18/12/2019.
//

#include "Event.h"

spaceinvaders::event::Event::Event() {

}

spaceinvaders::event::Event::~Event() {

}

bool spaceinvaders::event::Event::isHandledByGameModel() const {
    return handledByGameModel;
}

void spaceinvaders::event::Event::setHandledByGameModel(bool handledByGameModel) {
    Event::handledByGameModel = handledByGameModel;
}
