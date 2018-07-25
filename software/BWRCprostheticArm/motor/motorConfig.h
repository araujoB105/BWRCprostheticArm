/*
 * motorConfig.h
 * This file contains the control parameters (physical and virtual limits) for each motor.
 * araujo@berkeley.edu - 2018
 *
 */

#ifndef MOTOR_MOTORCONFIG_H_
#define MOTOR_MOTORCONFIG_H_
#include "motorControl.h"

#define MOTORCONTROL_HOMING_TIMEOUT 300	/* seconds */

motorControlConfig_t motorControlConfig_thumb =
{
	.limitMode = MOTORLIMITS_BOTHSWITCHS,
	.limitWarningZone = 350,
	.limitEndRight = 380, //UP
	.limitEndLeft = 210 //DOWN1
};

 motorControlConfig_t motorControlConfig_index =
{
	.limitMode = MOTORLIMITS_BOTHSWITCHS,
	.limitWarningZone = 450,
	.limitEndRight = 450, //UP
	.limitEndLeft = 120 //DOWN
};

 motorControlConfig_t motorControlConfig_fingers =
{
	.limitMode = MOTORLIMITS_BOTHSWITCHS,
	.limitWarningZone = 350,
	.limitEndRight = 400, //UP
	.limitEndLeft = 210 //DOWN
};

 motorControlConfig_t motorControlConfig_wrist_azimuth =
{
	.limitMode = MOTORLIMITS_BOTHSWITCHS,
	.limitWarningZone = 350,
	.limitEndRight = 360,
	.limitEndLeft = 240
};

 motorControlConfig_t motorControlConfig_wrist_elevation =
{
	.limitMode = MOTORLIMITS_BOTHSWITCHS,
	.limitWarningZone = 350,
	.limitEndRight = 360,
	.limitEndLeft = 240
};

#endif /* MOTOR_MOTORCONFIG_H_ */
