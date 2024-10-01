/*
 * Copyright (c) 2023, CATIE
 * SPDX-License-Identifier: Apache-2.0
 */
#include "mobile_base/mobile_base_differential.h"

namespace sixtron {

MobileBaseDifferential::MobileBaseDifferential(float wheels_distance): _motorWheelsDistance(wheels_distance)
{
}

MobileBaseDifferential::~MobileBaseDifferential() = default;

void MobileBaseDifferential::computeMotorSpeeds()
{
    // Convert angle
    float angle_translate_in_meter_per_s = _target.cmd_rot * (_motorWheelsDistance / 2.0f);

    // Set both motors speed
    _targetSpeedMotorLeft = _target.cmd_lin - angle_translate_in_meter_per_s;
    _targetSpeedMotorRight = _target.cmd_lin + angle_translate_in_meter_per_s;
}

void MobileBaseDifferential::setTargetSpeeds(target_speeds speeds)
{
    _target = speeds;
}

} // namespace sixtron
