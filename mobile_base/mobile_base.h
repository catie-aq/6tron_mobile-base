/*
 * Copyright (c) 2023, CATIE
 * SPDX-License-Identifier: Apache-2.0
 */
#ifndef CATIE_SIXTRON_MOBILE_BASE_H
#define CATIE_SIXTRON_MOBILE_BASE_H

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
    mobile_base_start = 0,
    mobile_base_stop = 1,
} MobileBase_status;

class MobileBase {

public:
    virtual void init() = 0;

    virtual void update() = 0; // Update motors outputs

    void setTargetSpeeds(target_speeds speeds)
    {
        _target = speeds;
    }

    void start()
    {
        _mobile_base_status = mobile_base_start;
    }

    void stop() // prevent the motor base to move or updating his PIDs
    {
        _mobile_base_status = mobile_base_stop;
    }

protected:
    MobileBase_status _mobile_base_status = mobile_base_stop;
    target_speeds _target;
};

} // namespace sixtron

#endif // CATIE_SIXTRON_MOBILE_BASE_H
