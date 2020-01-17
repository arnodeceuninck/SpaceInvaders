//
// Created by arno on 24/12/2019.
//

#ifndef SPACEINVADERS_MOVINGLEFT_H
#define SPACEINVADERS_MOVINGLEFT_H

#include "MovingEntityEvent.h"

namespace spaceinvaders::event {
/**
 * Notify the model it should move left
 */
class MovingLeft : public MovingEntityEvent
{
};
} // namespace spaceinvaders::event

#endif // SPACEINVADERS_MOVINGLEFT_H
