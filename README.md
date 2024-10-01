# Mobile Base

This is the 6TRON Mobile Base interface class library.

This library takes linear, tangential and rotational speed as inputs, and should translate them to the motors to move the mobile base.

The interface is described in `mobile_base/mobile_base.h`. The user should create a child class (derived from this interface) and redefined functions `init()` and `update()` in relation to the used framework (ROS, Mbed, Zephyr ...).

For differential robot, a sub-interface already exists with the corresponding calculation. To use it, the user needs to create a child class from `mobile_base/mobile_base_differential.h`, redefined functions `init()` and `update()` as planned, but in the function `update()`, begin with calling `computeMotorSpeeds()`.
