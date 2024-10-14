/*
 * Copyright (c) 2024, CATIE
 * SPDX-License-Identifier: Apache-2.0
 */
#include "mobile_base/mobile_base_holonomic.h"

namespace sixtron {

MobileBaseHolonomic::MobileBaseHolonomic(
        const float distance_to_center, const int number_of_wheels, float offset)
{
    assert(("The distance from wheels to center can't be null", distance_to_center > 0.0f));
    assert(("An holonomic robot must have at least 3 wheels", number_of_wheels > 2));

    _number_of_wheels = number_of_wheels;
    _distance_to_center = distance_to_center;
    _offset_angle = offset;
    _wheels_speeds = newMatrix(number_of_wheels, 1);
}

MobileBaseHolonomic::~MobileBaseHolonomic() = default;

void MobileBaseHolonomic::computeMotorSpeeds()
{
    for (int k = 0; k < _number_of_wheels; k++) {
        _wheels_speeds.data[k][0]
                = -sinf(float(k) * 2.0f * float(M_PI) / float(_number_of_wheels) + _offset_angle)
                        * _target.cmd_lin
                + cosf(float(k) * 2.0f * float(M_PI) / float(_number_of_wheels) + _offset_angle)
                        * _target.cmd_tan
                + _distance_to_center * _target.cmd_rot;
    }
}

} // namespace sixtron
