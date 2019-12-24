//
// Created by arno on 24/12/2019.
//

#include "RocketModel.h"

spaceinvaders::model::RocketModel::RocketModel(double width, double height, double speed,
                                               const spaceinvaders::Coordinate &speedDirection,
                                               const spaceinvaders::Coordinate &position) : MovingEntity(width, height,
                                                                                                         speed,
                                                                                                         speedDirection,
                                                                                                         position) {}
