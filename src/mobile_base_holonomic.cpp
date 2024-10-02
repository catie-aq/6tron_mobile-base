/*
 * Copyright (c) 2024, CATIE
 * SPDX-License-Identifier: Apache-2.0
 */
#include "mobile_base/mobile_base_holonomic.h"

namespace sixtron {

MobileBaseHolonomic::MobileBaseHolonomic(
        const float distanceToCenter, const int numberOfWheels, float offset)
{
    assert(("The distance from wheels to center can't be null", distanceToCenter > 0.0f));
    assert(("An holonomic robot must have at least 3 wheels", numberOfWheels > 2));

    _number_of_wheels = numberOfWheels;
    _distance_to_center = distanceToCenter;
    _wheels_speeds.column = 1;
    _offset_angle = offset;
    _wheels_speeds.line = numberOfWheels;

    std::vector<std::vector<float>> initvector(
            _wheels_speeds.line, std::vector<float>(_wheels_speeds.column));

    _wheels_speeds.Matrice = initvector;
}

MobileBaseHolonomic::~MobileBaseHolonomic() = default;

void MobileBaseHolonomic::computeMotorSpeeds()
{
    for (int k = 0; k < _number_of_wheels; k++) {
        _wheels_speeds.Matrice[k][0]
                = -sinf(float(k) * 2.0f * float(M_PI) / float(_number_of_wheels) + _offset_angle)
                        * _target.cmd_lin
                + cosf(float(k) * 2.0f * float(M_PI) / float(_number_of_wheels) + _offset_angle)
                        * _target.cmd_tan
                + _distance_to_center * _target.cmd_rot;
    }
}

void MobileBaseHolonomic::setTargetSpeeds(target_speeds speeds)
{
    _target = speeds;
}

} // namespace sixtron
