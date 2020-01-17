//
// Created by arno on 24/12/2019.
//

#ifndef SPACEINVADERS_FIREBULLET_H
#define SPACEINVADERS_FIREBULLET_H

#include "../EntityModel/RocketModel.h"
#include "Event.h"
#include <memory>

namespace spaceinvaders::event {
/**
 * Request the model to fire a bullet
 */
    class FireBullet : public Event {
    };
} // namespace spaceinvaders::event

#endif // SPACEINVADERS_FIREBULLET_H
