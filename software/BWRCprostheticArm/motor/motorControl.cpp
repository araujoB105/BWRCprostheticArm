/*
 * motorControl.c
 * araujo@berkeley.edu - 2018
 */
#include <stdlib.h>
#include <SerialCommand.h>

#include "motorControl.h"

#include <generic_list.h>

#include "Adafruit_PWMServoDriver.h"


retval_t
motorControl_init (motorControl_t** motorControl)
{
	/* Allocate memory */
	motorControl_t* newMotorControl= (motorControl_t*) malloc(sizeof(motorControl_t));

	/* Initialize driver */
	newMotorControl->status =  MOTORCONTROL_DISABLED;
	newMotorControl->motors = gen_list_init();
	*motorControl = newMotorControl;

	return RET_OK;
}

retval_t
motorControl_addMotor (motorControl_t* motorControl,
					   motorUnit_t** motorUnit,
					   Adafruit_PWMServoDriver servo_driver,
					   motorOperation_t** motor_operation,
					   motorControlConfig_t* controlConfig)
{
	if (motorControl == NULL)
	{
		return RET_ERROR;
	}

	/* Allocate memory */
	motorUnit_t* newMotorUnit =(motorUnit_t*) malloc(sizeof(motorUnit_t));

	/* Initialize motor unit */
	newMotorUnit->servo_driver = servo_driver;
	newMotorUnit->status = MOTOR_IDLE;
	newMotorUnit->operation = *motor_operation;
	newMotorUnit->controlConfig = controlConfig;

	gen_list_add(motorControl->motors, (void*) newMotorUnit);

	*motorUnit = newMotorUnit;
	return RET_OK;
}

retval_t
motorControl_start (motorControl_t* motorControl)
{
	if (motorControl == NULL)
	{
		return RET_ERROR;
	}
	motorControl->status = MOTORCONTROL_ENABLED;

	return RET_OK;
}

retval_t
motorControl_stop (motorControl_t* motorControl)
{
	if (motorControl == NULL)
	{
		return RET_ERROR;
	}


	motorControl->status = MOTORCONTROL_DISABLED;

	return RET_OK;
}




retval_t
motorControl_unit_moveSteps (motorControl_t* motorControl,
				   			 motorUnit_t* motorUnit,
				   			 motorDirection_t direction,
				   			 uint32_t steps)
{
	/* If the motor unit has virtual limits, the position should be read to check that the command is allowed.
	   The movement is not allowed if the final position is beyond the end limit. */

	if (motorUnit->controlConfig->limitMode == MOTORLIMITS_LEFTSWITCH)
	{

		if (direction == MOTOR_ROT_RIGHT)
		{
			if ((steps) > motorUnit->controlConfig->limitEndRight)
			{
				return RET_ERROR;
			}
		}
	}
	if (motorUnit->controlConfig->limitMode == MOTORLIMITS_RIGHTSWITCH)
	{
		if (direction == MOTOR_ROT_LEFT)
		{
			if ((steps) < motorUnit->controlConfig->limitEndLeft)
			{
				return RET_ERROR;
			}
		}
	}

	if ((steps < motorUnit->controlConfig->limitEndLeft) || (steps > motorUnit->controlConfig->limitEndRight)){
		Serial.println("Out of limits");
		return RET_ERROR;
	}

	motorUnit->servo_driver.setPWM(motorUnit->operation->pin, 0, steps);
	motorUnit->operation->status = MOTOR_OPERATION_IN_PROGRESS;
	motorUnit->operation->type = MOTORMODE_POSITION;
	motorUnit->operation->direction = direction;
	motorUnit->operation->microsteps = steps;
	motorUnit->position = steps;

	return RET_OK;
}

retval_t
motorControl_unit_moveSteps_low (motorControl_t* motorControl,
				   			 motorUnit_t* motorUnit,
				   			 motorDirection_t direction,
				   			 uint32_t steps)
{
	/* If the motor unit has virtual limits, the position should be read to check that the command is allowed.
	   The movement is not allowed if the final position is beyond the end limit. */
	int i;

	if (motorUnit->controlConfig->limitMode == MOTORLIMITS_LEFTSWITCH)
	{

		if (direction == MOTOR_ROT_RIGHT)
		{
			if ((steps) > motorUnit->controlConfig->limitEndRight)
			{
				return RET_ERROR;
			}
		}
	}
	if (motorUnit->controlConfig->limitMode == MOTORLIMITS_RIGHTSWITCH)
	{
		if (direction == MOTOR_ROT_LEFT)
		{
			if ((steps) < motorUnit->controlConfig->limitEndLeft)
			{
				return RET_ERROR;
			}
		}
	}

	if ((steps < motorUnit->controlConfig->limitEndLeft) || (steps > motorUnit->controlConfig->limitEndRight)){
		Serial.println("Out of limits");
		return RET_ERROR;
	}

	if (steps >= motorUnit->position){
		for (i=0;i<=(steps-motorUnit->position);i+=5){
			motorUnit->servo_driver.setPWM(motorUnit->operation->pin, 0, motorUnit->position+i);
			delay(10);
		}
}else{

	for (i=0;i<=(motorUnit->position - steps);i+=5){
		motorUnit->servo_driver.setPWM(motorUnit->operation->pin, 0, motorUnit->position-i);
		delay(10);

}

}
	motorUnit->servo_driver.setPWM(motorUnit->operation->pin, 0, steps);
	motorUnit->operation->status = MOTOR_OPERATION_IN_PROGRESS;
	motorUnit->operation->type = MOTORMODE_POSITION;
	motorUnit->operation->direction = direction;
	motorUnit->operation->microsteps = steps;
	motorUnit->position = steps;

	return RET_OK;
}



retval_t
motorControl_unit_position (motorControl_t* motorControl,
				   			motorUnit_t* motorUnit,
				   			int32_t position)
{
	/* Calculate the target position and call the moveSteps function. */
	int32_t currentPositionMicrosteps, currentPosition, delta;

	if (position > motorUnit->position)
		return RET_ERROR;
	else{
	currentPositionMicrosteps =  map(position, 0, 180, motorUnit->controlConfig->limitEndLeft, motorUnit->controlConfig->limitEndRight);
	motorUnit->servo_driver.setPWM(motorUnit->operation->pin, 0, currentPositionMicrosteps);
		/* If the position is the current, do nothing */
	}
	return RET_OK;
}

retval_t
motorControl_homeUnits (motorControl_t* motorControl) //Not implemented
{
	if (motorControl == NULL)
	{
		return RET_ERROR;
	}

	return RET_OK;
}



retval_t
motorControl_unit_update (motorControl_t* motorControl, //Not implemented
				  	      motorUnit_t* motorUnit)
{

	if (motorUnit->status != MOTOR_IDLE)
	{
		if (motorControl_unit_stop (motorControl, motorUnit) != RET_OK)
		{
			return RET_ERROR;
		}
	}
	return RET_OK;
}

retval_t
motorControl_unit_stop (motorControl_t* motorControl,
				  		motorUnit_t* motorUnit)
{
	/* Stop motor */

	motorUnit->status = MOTOR_IDLE;
	motorUnit->operation->status = MOTOR_OPERATION_NO;
	return RET_OK;
}

retval_t
motorControl_unit_rotate (motorControl_t* motorControl,
					      motorUnit_t* motorUnit,
					 	  motorDirection_t direction,
					 	  int rpm) //No speed, no implemented
{
	/* If the motor unit has virtual limits, the position should be read to check that the command is allowed.
	   This movement is not allowed if the unit is in the warning zone and the direction is towards the limit.. */


	return RET_OK;
}

retval_t
motorControl_unit_setPositioningSpeed (motorControl_t* motorControl, //Not implemented
									   motorUnit_t* motorUnit,
									   int rpm)
{

	return RET_OK;
}

retval_t
motorControl_unit_getPositioningSpeed (motorControl_t* motorControl, //Not implemented
									   motorUnit_t* motorUnit,
									   int* rpm)
{
	return RET_OK;
}

retval_t
motorControl_unit_getPosition (motorControl_t* motorControl,
				   			   motorUnit_t* motorUnit,
				   			   int32_t* position)
{
	
	return RET_OK;
}

retval_t
motorControl_unit_getLimits (motorControl_t* motorControl,
							 motorUnit_t* motorUnit,
							 motorLimits_t* motorLimits,
							 int32_t* leftLimit,
							 int32_t* rightLimit)
{
	if (motorControl == NULL)
	{
		return RET_ERROR;
	}

	if (motorUnit == NULL)
	{
		return RET_ERROR;
	}

	*motorLimits = motorUnit->controlConfig->limitMode;

	uint32_t microSteps;

	*leftLimit = 0;
	*rightLimit = 0;

	switch (motorUnit->controlConfig->limitMode)
	{
		case MOTORLIMITS_NO:
		break;
		case MOTORLIMITS_LEFTSWITCH:
			*leftLimit = 0;
			*rightLimit = motorUnit->controlConfig->limitWarningZone;
		break;
		case MOTORLIMITS_RIGHTSWITCH:
			*leftLimit = motorUnit->controlConfig->limitWarningZone;
			*rightLimit = 0;
		break;
		case MOTORLIMITS_BOTHSWITCHS:
			*leftLimit = 0;
			*rightLimit = microSteps;
		break;
	}

	return RET_OK;
}

