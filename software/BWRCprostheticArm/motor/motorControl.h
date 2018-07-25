/*
 * motorControl.h
 * Performs high-level control and monitoring for tmcm11x0 motor modules.
 * araujo@berkeley.edu - 2018
 */

#ifndef MODULES_MOTORCONTROL_H_
#define MODULES_MOTORCONTROL_H_



#include <generic_list.h>
#include <stddef.h>
#include "stdint.h"
#include "Adafruit_PWMServoDriver.h"


#define NUM_MOTORS 5

typedef enum{
	RET_OK,
	RET_ERROR,
	RET_TIMEOUT
}retval_t;


typedef enum{
	MOTORMODE_POSITION,
	MOTORMODE_SPEED, /*Not implemented*/
}motorMode_t;

typedef enum{
	MOTOR_ROT_LEFT,
	MOTOR_ROT_RIGHT,
}motorDirection_t;

typedef enum{
	MOTOR_IDLE,
	MOTOR_HOLD,
	MOTOR_MOVING,
	MOTOR_STALLED,
	MOTOR_ERROR,
	MOTOR_RFS,		/* Reference search mode */
}motorStatus_t;

typedef enum{
	MOTOR_OPERATION_NO,
	MOTOR_OPERATION_NOT_STARTED,
	MOTOR_OPERATION_IN_PROGRESS,
	MOTOR_OPERATION_ENDED,
	MOTOR_OPERATION_FAILED,
}motorOperationStatus_t;

typedef enum{
	MOTORLIMITS_NO,
	MOTORLIMITS_LEFTSWITCH,
	MOTORLIMITS_RIGHTSWITCH,
	MOTORLIMITS_BOTHSWITCHS,
}motorLimits_t;

typedef struct motorOperation_
{
	motorMode_t type;
	motorOperationStatus_t status;
	uint32_t pin;
	motorDirection_t direction;
	uint32_t microsteps;
}motorOperation_t;

typedef struct motorControlConfig_
{
	motorLimits_t limitMode;
	int32_t limitWarningZone;
	int32_t limitEndRight;
	int32_t limitEndLeft;

}motorControlConfig_t;

typedef enum{
	MOTORCONTROL_ENABLED,
	MOTORCONTROL_DISABLED,
}motorControl_status_t;

typedef struct motorUnit_
{
	Adafruit_PWMServoDriver servo_driver;//Servo
	motorStatus_t status;
	motorOperation_t* operation;
	motorControlConfig_t* controlConfig;
	uint8_t resolution; //step/degree
	uint32_t position;//maximum 0 to X
	
}motorUnit_t;

typedef struct motorControl_
{
	motorControl_status_t status;
	gen_list* motors;;//Array or dynamic

}motorControl_t;

/**
* @brief 				Creates the structures needed for the motor control.
* @param motorControl   Pointer where the structure address will be stored
* @retval  				RET_OK if successful.
*/
retval_t
motorControl_init (motorControl_t** motorControl);

/**
* @brief 				Adds a motor module to the control system. It will configure the module parameters with
						the supplied configurations.
* @param motorControl   Pointer to the motorControl structure
* @param motorUnit 		Pointer where the created motor unit will be created
* @param tmcm_motor		Driver instance to be used to communicate with the motor module
* @param motorConfig 	Configuration to be sent to the motor module
* @param controlConfig 	Configuration to control the motor module
* @retval  				RET_OK if successful.
*/
retval_t
motorControl_addMotor (motorControl_t* motorControl,
					   motorUnit_t** motorUnit,
					   Adafruit_PWMServoDriver servo_driver,
					   motorOperation_t** motor_operation,
					   motorControlConfig_t* controlConfig);

/**
* @brief 				Launches the control tasks to enable motor control and actions.
* @param motorControl   Pointer to the motorControl structure
* @retval  				RET_OK if successful.
*/
retval_t
motorControl_start (motorControl_t* motorControl);

/**
* @brief 				Stops the control threads.
* @param motorControl   Pointer to the motorControl st ructure
* @retval  				RET_OK if successful.
*/
retval_t
motorControl_stop (motorControl_t* motorControl);

/**
* @brief 				Launches the reference search on all motor modules registered in the control system.
* @param motorControl   Pointer to the motorControl structure
* @retval  				RET_OK if successful. RET_ERROR if the operation times out without ending.
*/
retval_t
motorControl_homeUnits (motorControl_t* motorControl);

/**
* @brief 				Stops the movement of the given motor unit
* @param motorControl   Pointer to the motorControl structure
* @param motorUnit 		Motor unit to be stopped
* @retval  				RET_OK if successful.
*/
retval_t
motorControl_unit_stop (motorControl_t* motorControl,
				  		motorUnit_t* motorUnit);

/**
* @brief 				Rotates the axis of the given motor unit at exact speed in rpm
* @param motorControl   Pointer to the motorControl structure
* @param motorUnit 		Motor unit to be rotated
* @param direction 		Direction of the rotation
* @param rpm 			Speed of the rotation
* @retval  				RET_OK if successful.
*/
retval_t
motorControl_unit_rotate (motorControl_t* motorControl,
					      motorUnit_t* motorUnit,
					 	  motorDirection_t direction,
					 	  int rpm);

/**
* @brief 				Rotates the axis of the given motor unit a number of steps
* @param motorControl   Pointer to the motorControl structure
* @param motorUnit 		Motor unit to be moved
* @param direction 		Direction of the rotation
* @param steps 			Steps to move the axis
* @retval  				RET_OK if successful.
*/
retval_t
motorControl_unit_moveSteps (motorControl_t* motorControl,
				   			 motorUnit_t* motorUnit,
				   			 motorDirection_t direction,
				   			 uint32_t steps);


retval_t
motorControl_unit_moveSteps_low (motorControl_t* motorControl,
				   			 motorUnit_t* motorUnit,
				   			 motorDirection_t direction,
				   			 uint32_t steps);

/**
* @brief 				Moves the axis of the given motor unit to an absolute position
* @param motorControl   Pointer to the motorControl structure
* @param motorUnit 		Motor unit to be moved
* @param position 		Final positiion of the axis
* @retval  				RET_OK if successful.
*/

retval_t
motorControl_unit_position (motorControl_t* motorControl,
				   			motorUnit_t* motorUnit,
				   			int32_t position);

/**
* @brief 				Sets the speed used for absolute movements
* @param motorControl   Pointer to the motorControl structure
* @param motorUnit 		Motor unit to be set
* @param rpm 			Speed in rpm to be used
* @retval  				RET_OK if successful.
*/
retval_t
motorControl_unit_setPositioningSpeed (motorControl_t* motorControl,
									   motorUnit_t* motorUnit,
									   int rpm);

/**
* @brief 				Gets the speed used for absolute movements
* @param motorControl   Pointer to the motorControl structure
* @param motorUnit 		Motor unit to be read
* @param rpm 			Pointer to the variable where the speed will be stored
* @retval  				RET_OK if successful.
*/
retval_t
motorControl_unit_getPositioningSpeed (motorControl_t* motorControl,
									   motorUnit_t* motorUnit,
									   int rpm);

/**
* @brief 				Gets the current absolute position
* @param motorControl   Pointer to the motorControl structure
* @param motorUnit 		Motor unit to be read
* @param position 		Pointer to the variable where the position will be stored
* @retval  				RET_OK if successful.
*/
retval_t
motorControl_unit_getPosition (motorControl_t* motorControl,
				   			   motorUnit_t* motorUnit,
				   			   int32_t* position);

/**
* @brief 				Gets the positions of the applicable limits
* @param motorControl   Pointer to the motorControl structure
* @param motorUnit 		Motor unit to be read
* @param motorLimits 	Type of limits applicable to the moduel
* @param leftLimit 		Pointer to the variable where the left limit position will be stored
* @param rightLimit 	Pointer to the variable where the right limit position will be stored
* @retval  				RET_OK if successful.
*/
retval_t
motorControl_unit_getLimits (motorControl_t* motorControl,
							 motorUnit_t* motorUnit,
							 motorLimits_t* motorLimits,
							 int32_t* leftLimit,
							 int32_t* rightLimit);

#endif /* MODULES_MOTORCONTROL_H_ */
