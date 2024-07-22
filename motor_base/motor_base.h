/*
 * Copyright (c) 2023, CATIE
 * SPDX-License-Identifier: Apache-2.0
 */
#ifndef CATIE_SIXTRON_MOTORBASE_H
#define CATIE_SIXTRON_MOTORBASE_H

#include <math.h>
#include <stdint.h>

namespace sixtron {

typedef struct target_speeds target_speeds;

struct target_speeds {
    float cmd_lin = 0.0f; // Linear speed target [m/s]
    float cmd_tan = 0.0f; // Tangential speed target (for omnidirectional drive robots) [m/s]
    float cmd_rot = 0.0f; // Rotational speed target [rad/s]
};

typedef enum {
    motor_base_start = 0,
    motor_base_stop = 1,
} MotorBase_status;

class MotorBase {

public:
    virtual void init() = 0;

    virtual void update() = 0; // Update motors outputs

    virtual void setTargetSpeeds(target_speeds speeds) = 0;

    void start()
    {
        MotorBase_status _motor_base_status = motor_base_start;
    }

    void stop() // prevent the motor base to move or updating his PIDs
    {
        MotorBase_status _motor_base_status = motor_base_stop;
    }

protected:
    MotorBase_status _motor_base_status = motor_base_stop;
};

} // namespace sixtron

#endif // CATIE_SIXTRON_MOTORBASE_H
