/*
 * Copyright (c) 2023, CATIE
 * SPDX-License-Identifier: Apache-2.0
 */
#include "motor_base/motor_base_two_wheels.h"

namespace sixtron {

MotorBaseTwoWheels::MotorBaseTwoWheels(float wheels_distance): _motorWheelsDistance(wheels_distance)
{
}

MotorBaseTwoWheels::~MotorBaseTwoWheels() = default;

void MotorBaseTwoWheels::computeMotorSpeeds()
{
    // Convert angle
    float angle_translate_in_meter_per_s = _target.cmd_rot * (_motorWheelsDistance / 2.0f);

    // Set both motors speed
    _targetSpeedMotorLeft = _target.cmd_lin - angle_translate_in_meter_per_s;
    _targetSpeedMotorRight = _target.cmd_lin + angle_translate_in_meter_per_s;
}

void MotorBaseTwoWheels::setTargetSpeeds(target_speeds speeds)
{
    _target = speeds;
}

} // namespace sixtron
