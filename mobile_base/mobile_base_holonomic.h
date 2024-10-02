/*
 * Copyright (c) 2024, CATIE
 * SPDX-License-Identifier: Apache-2.0
 */
#ifndef CATIE_SIXTRON_MOBILE_BASE_HOLONOMIC_H
#define CATIE_SIXTRON_MOBILE_BASE_HOLONOMIC_H

#include "cassert"
#include "math_utils/math_utils.h"
#include "mobile_base/mobile_base.h"

namespace sixtron {

class MobileBaseHolonomic: public MobileBase {

public:
    /*!
     *  Default MobileBaseHolonomic constructor.
     *
     *  @param distance_to_center The distance between the wheels and the center of the robot. [m]
     *  @param number_of_wheels The number of holonomic wheels (must be greater than 2)
     *  @param offset The angle offset (to adjust the reference frame X/Y of the mobile base) [rad]
     *
     *  The angle offset must be the same one used in odometry.
     *  The angle between wheels can't be set (yet).
     */
    MobileBaseHolonomic(float distance_to_center, int number_of_wheels, float offset);

    ~MobileBaseHolonomic();

protected:
    void computeMotorSpeeds();
    int _number_of_wheels;
    float _offset_angle;
    Matrix _wheels_speeds;

private:
    float _distance_to_center = 0.0f;
};

} // namespace sixtron

#endif // CATIE_SIXTRON_MOBILE_BASE_HOLONOMIC_H
