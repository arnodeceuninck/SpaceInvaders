//
// Created by arno on 24/12/2019.
//

#ifndef SPACEINVADERS_FIREBULLET_H
#define SPACEINVADERS_FIREBULLET_H

#include <memory>
#include "Event.h"
#include "../EntityModel/RocketModel.h"

namespace spaceinvaders::event {
    /**
     * Request the model to fire a bullet
     */
    class FireBullet : public Event {
    };
}


#endif //SPACEINVADERS_FIREBULLET_H
