/*
 * armControl.c
araujo@berkeley.edu - 2018
 */
#include <stdlib.h>
#include "armControl.h"

#include "math.h"
#include "armConfig.h"

//static void
//armControl_supervisorTask (void * instance);



retval_t
armControl_create (armControl_t** armControl)
{
	/* Allocate memory */
	armControl_t* newarmControl = (armControl_t*)malloc(sizeof(armControl_t)); //OS dependent

	/* Initialize driver */
	newarmControl->architecture =  NULL;

	*armControl = newarmControl;

	return RET_OK;
}

retval_t
armControl_configure (armControl_t* armControl,
						motorControl_t* motorControl,
						motorUnit_t* fingers,
						motorUnit_t* index,
						motorUnit_t* thumb,
						motorUnit_t* wristAzimuth,
						motorUnit_t* wristElevation)
{
	if (armControl == NULL)
	{
		return RET_ERROR;
	}

	/* Allocate memory */
	armControl->architecture = (armArchitecture_t*)malloc(sizeof(armArchitecture_t));
	armControl->architecture->fingers = (armFingers_t*)malloc(sizeof(armFingers_t));
	armControl->architecture->fingers->fingersControl = (armMotorChannel_t*)malloc(sizeof(armMotorChannel_t));
	armControl->architecture->index = (armIndex_t*)malloc(sizeof(armIndex_t));
	armControl->architecture->index->indexControl = (armMotorChannel_t*)malloc(sizeof(armMotorChannel_t));
	armControl->architecture->thumb = (armThumb_t*)malloc(sizeof(armThumb_t));
	armControl->architecture->thumb->thumbControl = (armMotorChannel_t*)malloc(sizeof(armMotorChannel_t));
	armControl->architecture->wrist = (armWrist_t*)malloc(sizeof(armWrist_t));
	armControl->architecture->wrist->azimuth = (armMotorChannel_t*)malloc(sizeof(armMotorChannel_t));
	armControl->architecture->wrist->elevation = (armMotorChannel_t*)malloc(sizeof(armMotorChannel_t));
	armControl->architecture->sensors = (armSensors_t*)malloc(sizeof(armSensors_t));

	armControl->operation = (armOperation_t*)malloc(sizeof(armOperation_t));
	armControl->operation->fingersOperation = (armFingersOperation_t*)malloc(sizeof(armOperation_t));
	armControl->operation->indexOperation = (armIndexOperation_t*)malloc(sizeof(armOperation_t));
	armControl->operation->thumbOperation = (armThumbOperation_t*)malloc(sizeof(armOperation_t));
	armControl->operation->wristOperation = (armWristOperation_t*)malloc(sizeof(armOperation_t));

	/* Initialize driver */
	armControl->motorControl = motorControl;

	armControl->architecture->fingers->fingersControl->motorUnit = fingers;
	armControl->architecture->index->indexControl->motorUnit = index;
	armControl->architecture->thumb->thumbControl->motorUnit = thumb;

	armControl->architecture->wrist->azimuth->motorUnit = wristAzimuth;
	armControl->architecture->wrist->elevation->motorUnit = wristElevation;

	armControl->architecture->sensors->inclinationOffsetXaxis = 0;
	armControl->architecture->sensors->inclinationOffsetYaxis = 0;
	armControl->architecture->sensors->inclinationOffsetZaxis = 0;


	armControl->operation->fingersOperation->status = FINGERS_OP_STOPPED;
	armControl->operation->indexOperation->status = INDEX_OP_STOPPED;
	armControl->operation->thumbOperation->status = THUMB_OP_STOPPED;
	armControl->operation->wristOperation->status = WRIST_OP_STOPPED;


	//armControl->supervisorTask = osThreadCreate(osThread(rb_supervisorTask), ( void *) armControl);
	return RET_OK;
}
///XXX index and thumb remaining...
retval_t
armControl_fingers_enableHoming (armControl_t* armControl)
{
	return RET_OK;
}

retval_t
armControl_fingers_disableHoming (armControl_t* armControl)
{
	return RET_OK;
}

retval_t
armControl_homeUnits (armControl_t* armControl)
{
	if(motorControl_homeUnits(armControl->motorControl) != RET_OK)
	{
		return RET_ERROR;
	}
	return armControl_retrieveLimits(armControl);
}

retval_t
armControl_retrieveLimits (armControl_t* armControl)
{
	/* Store default limits */
	motorLimits_t limitType;
	int32_t leftLimit, rightLimit;

	motorControl_unit_getLimits (armControl->motorControl,
								 armControl->architecture->wrist->azimuth->motorUnit,
								 &limitType,
								 &leftLimit, 	/* Should be 0 */
								 &rightLimit);	/* Should be positive (end switches on both sides) */

	armControl->architecture->wrist->azimuthLowerLimit = leftLimit;
	armControl->architecture->wrist->azimuthUpperLimit = rightLimit;

	motorControl_unit_getLimits (armControl->motorControl,
								 armControl->architecture->wrist->elevation->motorUnit,
								 &limitType, 
								 &leftLimit, 	/* Should be negative (right end switch only) */
								 &rightLimit);	/* Should be 0 */

	armControl->architecture->wrist->elevationLowerLimit = rightLimit;
	armControl->architecture->wrist->elevationUpperLimit = leftLimit;
	return RET_OK;
}

retval_t
armControl_getAcceleration (armControl_t* armControl,
							 int* x,
							 int* y,
							 int* z)
{
	int rawAccMeasure [3];
	
	//if (adxl345_getXYZg (&rawAccMeasure [0], &rawAccMeasure [1], &rawAccMeasure [2]) != RET_OK)
	//{
	//	return RET_ERROR;
	//}
	//Read accelerometer

	*x = rawAccMeasure [0] - armControl->architecture->sensors->inclinationOffsetXaxis;
	*y = rawAccMeasure [1] - armControl->architecture->sensors->inclinationOffsetYaxis;
	*z = rawAccMeasure [2] - armControl->architecture->sensors->inclinationOffsetZaxis;

	return RET_OK;
}


retval_t
armControl_fingers_move (armControl_t* armControl,
					        armControl_fingersDirection_t direction,
					   	   	int speed)
{
	int rpm = speed * FINGERS_CIRCULAR_REDUCTION * FINGERS_CIRCULARTOLINERAR_CONVERSION;
	motorDirection_t motorDirection = (direction == FINGERS_CLOSE) ? MOTOR_ROT_RIGHT : MOTOR_ROT_LEFT;


	armControl->operation->fingersOperation->direction = (direction == FINGERS_CLOSE) ? FINGERS_DIR_CLOSING : FINGERS_DIR_OPENING;

	if (motorControl_unit_rotate (armControl->motorControl,
							      armControl->architecture->fingers->fingersControl->motorUnit,
							 	  motorDirection,
							 	  rpm) != RET_OK)
	{

		return RET_ERROR;
	}
	armControl->operation->fingersOperation->status = FINGERS_OP_MOVING;


	return RET_OK;
}


retval_t
armControl_fingers_stop (armControl_t* armControl)
{
	if(motorControl_unit_stop (armControl->motorControl,
							   armControl->architecture->fingers->fingersControl->motorUnit) != RET_OK)
	{
		return RET_ERROR;
	}
	armControl->operation->fingersOperation->status = FINGERS_OP_STOPPED;
	return RET_OK;
}


retval_t
armControl_finger_launchAutoAdjust (armControl_t* armControl,
										int lowerThreshold,
										int upperThreshold)
{
	if (armControl->operation->fingersOperation->status == FINGERS_OP_ADJUSTING)
	{
		armControl_fingers_stop (armControl);
	}

	int currentLiftMeasure;

	/* If the fingers pressure is too high, close the fingers */
	if (currentLiftMeasure > upperThreshold)
	{

		armControl->operation->fingersOperation->lowerThreshold = lowerThreshold;
		armControl->operation->fingersOperation->upperThreshold = upperThreshold;
		armControl->operation->fingersOperation->direction = FINGERS_DIR_CLOSING;
		armControl->operation->fingersOperation->elapsedTicks = 0;

		int rpm = FINGERS_AUTOADJUST_SPEED * FINGERS_CIRCULAR_REDUCTION * FINGERS_CIRCULARTOLINERAR_CONVERSION;
		motorDirection_t motorDirection = MOTOR_ROT_RIGHT;
		if (motorControl_unit_rotate (armControl->motorControl,
								      armControl->architecture->fingers->fingersControl->motorUnit,
								 	  motorDirection,
								 	  rpm) != RET_OK)
		{

			return RET_ERROR;
		}

		armControl->operation->fingersOperation->status = FINGERS_OP_ADJUSTING;

	}

	/* If the fingers pressure is too low, open the fingers */
	if (currentLiftMeasure < lowerThreshold)
	{

		armControl->operation->fingersOperation->lowerThreshold = lowerThreshold;
		armControl->operation->fingersOperation->upperThreshold = upperThreshold;
		armControl->operation->fingersOperation->direction = FINGERS_DIR_OPENING;
		armControl->operation->fingersOperation->elapsedTicks = 0;

		int rpm = FINGERS_AUTOADJUST_SPEED * FINGERS_CIRCULAR_REDUCTION * FINGERS_CIRCULARTOLINERAR_CONVERSION;
		motorDirection_t motorDirection = MOTOR_ROT_LEFT;
		if (motorControl_unit_rotate (armControl->motorControl,
								      armControl->architecture->fingers->fingersControl->motorUnit,
								 	  motorDirection,
								 	  rpm) != RET_OK)
		{

			return RET_ERROR;
		}

		armControl->operation->fingersOperation->status = FINGERS_OP_ADJUSTING;

	}

	return RET_OK;
}

retval_t
armControl_fingers_getAutoAdjustStatus (armControl_t* armControl,
										   armFingersOperationStatus_t* status)
{
	*status = armControl->operation->fingersOperation->status;
	return RET_OK;
}

retval_t
armControl_wrist_move (armControl_t* armControl,
							armWristDirection_t direction,
							int speed)
{
	if (armControl == NULL)
	{
		return RET_ERROR;
	}

	int rpm;


	motorDirection_t motorDirection;

	switch (direction)
	{
		case WRIST_UP:
		rpm = speed * WRIST_ELEVATION_CIRCULAR_REDUCTION * WRIST_ELEVATION_CIRCULAR_FINALRELATION;
		motorDirection = MOTOR_ROT_LEFT;
		motorControl_unit_rotate (armControl->motorControl,
						          armControl->architecture->wrist->elevation->motorUnit,
						          motorDirection,
						          rpm);
		break;
		case WRIST_DOWN:
		rpm = speed * WRIST_ELEVATION_CIRCULAR_REDUCTION * WRIST_ELEVATION_CIRCULAR_FINALRELATION;
		motorDirection = MOTOR_ROT_RIGHT;
		motorControl_unit_rotate (armControl->motorControl,
						          armControl->architecture->wrist->elevation->motorUnit,
						          motorDirection,
						          rpm);
		break;
		case WRIST_LEFT:
		rpm = speed * WRIST_AZIMUTH_CIRCULAR_REDUCTION * WRIST_AZIMUTH_CIRCULAR_FINALRELATION;
		motorDirection = MOTOR_ROT_LEFT;
		motorControl_unit_rotate (armControl->motorControl,
						          armControl->architecture->wrist->azimuth->motorUnit,
						          motorDirection,
						          rpm);
		break;
		case WRIST_RIGHT:
		rpm = speed * WRIST_AZIMUTH_CIRCULAR_REDUCTION * WRIST_AZIMUTH_CIRCULAR_FINALRELATION;
		motorDirection = MOTOR_ROT_RIGHT;
		motorControl_unit_rotate (armControl->motorControl,
						          armControl->architecture->wrist->azimuth->motorUnit,
						          motorDirection,
						          rpm);
		break;
		default:
			return RET_ERROR;
		break;
	}

	return RET_OK;
}

retval_t
armControl_wrist_position (armControl_t* armControl,
								int azimuth,
								int elevation)
{
	if(armControl_wrist_positionAzimuth (armControl, azimuth) != RET_OK)
	{
		return RET_ERROR;
	}
	if(armControl_wrist_positionElevation (armControl, elevation) != RET_OK)
	{
		return RET_ERROR;
	}

	return RET_OK;
}

retval_t
armControl_wrist_positionAzimuth (armControl_t* armControl,
									   int azimuth)
{
	int32_t position = armControl->architecture->wrist->azimuthLowerLimit +
						azimuth * (armControl->architecture->wrist->azimuthUpperLimit -
							armControl->architecture->wrist->azimuthLowerLimit);

	return motorControl_unit_position (armControl->motorControl,
									   armControl->architecture->wrist->azimuth->motorUnit,
									   position);
}

retval_t
armControl_wrist_positionAzimuthSpeed (armControl_t* armControl,
									   	 	int azimuth,
									   		int speed)
{
	int32_t position = armControl->architecture->wrist->azimuthLowerLimit +
						azimuth * (armControl->architecture->wrist->azimuthUpperLimit -
							armControl->architecture->wrist->azimuthLowerLimit);

	/* Set speed before the movement */
	int rpm = speed * WRIST_AZIMUTH_CIRCULAR_REDUCTION * WRIST_AZIMUTH_CIRCULAR_FINALRELATION;
	motorControl_unit_setPositioningSpeed (armControl->motorControl,
									  	   armControl->architecture->wrist->azimuth->motorUnit,
									   	   rpm);

	return motorControl_unit_position (armControl->motorControl,
									   armControl->architecture->wrist->azimuth->motorUnit,
									   position);
}

retval_t
armControl_wrist_positionElevation (armControl_t* armControl,
										 int elevation)
{
	int32_t position = armControl->architecture->wrist->elevationLowerLimit +
						elevation * (armControl->architecture->wrist->elevationUpperLimit -
							armControl->architecture->wrist->elevationLowerLimit);

	return motorControl_unit_position (armControl->motorControl,
									   armControl->architecture->wrist->elevation->motorUnit,
									   position);
}

retval_t
armControl_wrist_positionElevationSpeed (armControl_t* armControl,
										 	  int elevation,
										 	  int speed)
{
	int32_t position = armControl->architecture->wrist->elevationLowerLimit +
						elevation * (armControl->architecture->wrist->elevationUpperLimit -
							armControl->architecture->wrist->elevationLowerLimit);

	/* Set speed before the movement */
	int rpm = speed * WRIST_ELEVATION_CIRCULAR_REDUCTION * WRIST_ELEVATION_CIRCULAR_FINALRELATION;
	motorControl_unit_setPositioningSpeed (armControl->motorControl,
									  	   armControl->architecture->wrist->elevation->motorUnit,
									   	   rpm);

	return motorControl_unit_position (armControl->motorControl,
									   armControl->architecture->wrist->elevation->motorUnit,
									   position);
}

retval_t
armControl_wrist_stop (armControl_t* armControl)
{
	if (motorControl_unit_stop (armControl->motorControl,
							    armControl->architecture->wrist->azimuth->motorUnit) != RET_OK)
	{
		return RET_ERROR;
	}
	if (motorControl_unit_stop (armControl->motorControl,
							    armControl->architecture->wrist->elevation->motorUnit) != RET_OK)
	{
		return RET_ERROR;
	}
	return RET_OK;
}

retval_t
armControl_wrist_getPosition (armControl_t* armControl,
								   int* azimuth,
								   int* elevation)
{
	int32_t azimuthPosition, elevationPosition;

	motorControl_unit_getPosition (armControl->motorControl,
								   armControl->architecture->wrist->azimuth->motorUnit,
								   &azimuthPosition);
	motorControl_unit_getPosition (armControl->motorControl,
								   armControl->architecture->wrist->elevation->motorUnit,
								   &elevationPosition);

	*azimuth = (int) (azimuthPosition - armControl->architecture->wrist->azimuthLowerLimit) /
			   (int) (armControl->architecture->wrist->azimuthUpperLimit - armControl->architecture->wrist->azimuthLowerLimit);
	
	*elevation = (int) (elevationPosition - armControl->architecture->wrist->elevationLowerLimit) /
			   (int) (armControl->architecture->wrist->elevationUpperLimit - armControl->architecture->wrist->elevationLowerLimit);

	return RET_OK;
}

retval_t
armControl_wrist_setVisualLimit (armControl_t* armControl,
									  armWristViewLimit_t viewlimit)
{
	int32_t elevationPosition;
	if (motorControl_unit_getPosition (armControl->motorControl,
								      armControl->architecture->wrist->elevation->motorUnit,
								      &elevationPosition) != RET_OK)
	{
		return RET_ERROR;
	}

	switch (viewlimit)
	{
		case WRIST_VIEWLIMIT_LOWER:
		armControl->architecture->wrist->elevationLowerLimit = elevationPosition;
		break;
		case WRIST_VIEWLIMIT_UPPER:
		armControl->architecture->wrist->elevationUpperLimit = elevationPosition;
		break;
	}

	return RET_OK;
}

