/*
 * armControl.h
 * araujo@berkeley.edu - 2018
 */

#ifndef MODULES_armCONTROL_H_
#define MODULES_armCONTROL_H_

#include "../motor/motorControl.h"
//#include "arm_math.h"

typedef struct armMotorChannel_{//One channel -> one o MORE motorUnits
	motorUnit_t* motorUnit;
}armMotorChannel_t;


// Fingers definitions
typedef enum{
	FINGERS_OPEN,
	FINGERS_CLOSE,
}armControl_fingersDirection_t;

typedef struct armFingers_{
	armMotorChannel_t* fingersControl;
}armFingers_t;

// Index definitions
typedef enum{
	INDEX_OPEN,
	INDEX_CLOSE,
}armControl_indexDirection_t;

typedef struct armIndex_{
	armMotorChannel_t* indexControl;
}armIndex_t;

// Thumb definitions
typedef enum{
	THUMB_OPEN,
	THUMB_CLOSE,
}armControl_thumbDirection_t;

typedef struct armThumb_{
	armMotorChannel_t* thumbControl;
}armThumb_t;

//Wrist definitions

typedef enum {
	WRIST_UP,
	WRIST_DOWN,
	WRIST_LEFT,
	WRIST_RIGHT,
}armWristDirection_t;

typedef enum {
	WRIST_VIEWLIMIT_LOWER,
	WRIST_VIEWLIMIT_UPPER,
}armWristViewLimit_t;

typedef struct armWrist_{
	armMotorChannel_t* azimuth;
	armMotorChannel_t* elevation;
	int32_t azimuthLowerLimit;
	int32_t azimuthUpperLimit;
	int32_t elevationLowerLimit;
	int32_t elevationUpperLimit;
}armWrist_t;

typedef enum {
	WRIST_OP_STOPPED,
	WRIST_OP_MOVING,
	WRIST_OP_ADJUSTING,
	WRIST_OP_TIMEOUT,
}armWristOperationStatus_t;

typedef enum {
	WRIST_DIR_UP,
	WRIST_DIR_DOWN,
	WRIST_DIR_LEFT,
	WRIST_DIR_RIGHT,
}armWristOperationDirection_t;

typedef struct armWristOperation_{
	armWristOperationStatus_t status;
	int lowerThreshold;
	int upperThreshold;
	int leftThreshold;
	int rightThreshold;
	armWristOperationDirection_t direction;
	uint16_t elapsedTicks;
}armWristOperation_t;

typedef struct armSensors_{ //Could be interesting...
	int inclinationOffsetXaxis;
	int inclinationOffsetYaxis;
	int inclinationOffsetZaxis;
}armSensors_t;

typedef struct armArchitecture_{
	armFingers_t* fingers;
	armIndex_t* index;
	armThumb_t* thumb;
	armWrist_t* wrist;
	armSensors_t* sensors;
}armArchitecture_t;

typedef enum {
	FINGERS_OP_STOPPED,
	FINGERS_OP_MOVING,
	FINGERS_OP_ADJUSTING,
	FINGERS_OP_TIMEOUT,
}armFingersOperationStatus_t;

typedef enum {
	FINGERS_DIR_OPENING,
	FINGERS_DIR_CLOSING,
}armFingersOperationDirection_t;

typedef struct armFingersOperation_{
	armFingersOperationStatus_t status;
	int lowerThreshold;
	int upperThreshold;
	armFingersOperationDirection_t direction;
	uint16_t elapsedTicks;
}armFingersOperation_t;

typedef enum {
	INDEX_OP_STOPPED,
	INDEX_OP_MOVING,
	INDEX_OP_ADJUSTING,
	INDEX_OP_TIMEOUT,
}armIndexOperationStatus_t;

typedef enum {
	INDEX_DIR_OPENING,
	INDEX_DIR_CLOSING,
}armIndexOperationDirection_t;

typedef struct armIndexOperation_{
	armIndexOperationStatus_t status;
	int lowerThreshold;
	int upperThreshold;
	armIndexOperationDirection_t direction;
	uint16_t elapsedTicks;
}armIndexOperation_t;

typedef enum {
	THUMB_OP_STOPPED,
	THUMB_OP_MOVING,
	THUMB_OP_ADJUSTING,
	THUMB_OP_TIMEOUT,
}armThumbOperationStatus_t;

typedef enum {
	THUMB_DIR_OPENING,
	THUMB_DIR_CLOSING,
}armThumbOperationDirection_t;

typedef struct armThumbOperation_{
	armThumbOperationStatus_t status;
	int lowerThreshold;
	int upperThreshold;
	armThumbOperationDirection_t direction;
	uint16_t elapsedTicks;
}armThumbOperation_t;


typedef struct armOperation_{
	armFingersOperation_t* fingersOperation;
	armIndexOperation_t* indexOperation;
	armThumbOperation_t* thumbOperation;
	armWristOperation_t* wristOperation;

}armOperation_t;

typedef struct armControl_{
	armArchitecture_t* architecture;
	motorControl_t* motorControl;
	armOperation_t* operation;
}armControl_t;





/**
* @brief 				Creates the structures needed for arm control
* @param armControl   Pointer where the armControl structure address will be stored
* @retval  				RET_OK if successful.
*/
retval_t
armControl_create (armControl_t** armControl);

/**
* @brief 					Configures the motor modules arm control will use for each mechanism
* @param armControl   		Pointer to the armControl structure
* @param motorControl   	Pointer to the motorControl structure that will be used to control the motors
* @param fingers   			Motor module for the fingers
* @param index				Motor module for the index
* @param thumb				Motor modules for the thumb
* @param wristAzimuth   	Motor module for the wrist azimuth
* @param wristElevation   	Motor module for the wrist elevation
* @retval  				RET_OK if successful.
*/
retval_t
armControl_configure (armControl_t* armControl,
						motorControl_t* motorControl,
						motorUnit_t* fingers,
						motorUnit_t* index,
						motorUnit_t* thumb,
						motorUnit_t* wristAzimuth,
						motorUnit_t* wristElevation);

/**
* @brief 				Enables homing of the fingers motor module.
* @param armControl   Pointer to the armControl structure
* @retval  				RET_OK if successful.
*/
retval_t
armControl_fingers_enableHoming (armControl_t* armControl);

/**
* @brief 				Disables homing of the fingers motor module.
* @param armControl   Pointer to the armControl structure
* @retval  				RET_OK if successful.
*/
retval_t
armControl_fingers_disableHoming (armControl_t* armControl);

/**
* @brief 				Performs the homing of the units that are configured with end switches.
*						It will block until it finishes or timeouts.
* @param armControl   Pointer to the armControl structure
* @retval  				RET_OK if successful.
*/
retval_t
armControl_homeUnits (armControl_t* armControl);

/**
* @brief 				Reads the positions of the end of the mechanisms after homing.
* @param armControl   Pointer to the armControl structure
* @retval  				RET_OK if successful.
*/
retval_t
armControl_retrieveLimits (armControl_t* armControl);

/**
* @brief 				Reads the acceleration of the inclination sensor
* @param armControl   	Pointer to the armControl structure
* @param x 				Pointer to the variable where the x axis acceleration will be stored.
* @param y 				Pointer to the variable where the y axis acceleration will be stored.
* @param z 				Pointer to the variable where the z axis acceleration will be stored.
* @retval  				RET_OK if successful.
*/
retval_t
armControl_getAcceleration (armControl_t* armControl,
							 int* x,
							 int* y,
							 int* z);

/**
* @brief 				Reads the accelerometer readings and saves it as the measure offset to 
*						correct future readings.
* @param armControl   	Pointer to the armControl structure
* @retval  				RET_OK if successful.
*/
retval_t
armControl_setReferenceInclination (armControl_t* armControl);

/**
* @brief 				Reads the spherical inclination angles of the arm
* @param armControl   	Pointer to the armControl structure
* @param theta			Pointer to the variable where the theta angle will be stored
* @param psi			Pointer to the variable where the psi angle will be stored
* @param phi			Pointer to the variable where the phi angle will be stored
* @retval  				RET_OK if successful.
*/
retval_t
armControl_getInclination (armControl_t* armControl,
							 int* theta,
							 int* psi,
							 int* phi);
/**
* @brief 				Moves the fingers
* @param armControl   	Pointer to the armControl structure
* @param direction		Direction of the movement
* @param speed			Target speed
* @retval  				RET_OK if successful.
*/
retval_t
armControl_fingers_move (armControl_t* armControl,
					        armControl_fingersDirection_t direction,
					   	   	int speed);

/**
* @brief 				Stops the fingers
* @param armControl   	Pointer to the armControl structure
* @retval  				RET_OK if successful.
*/
retval_t
armControl_fingers_stop (armControl_t* armControl);


retval_t
armControl_fingers_launchAutoAdjust (armControl_t* armControl,
										int lowerThreshold,
										int upperThreshold);

/**
* @brief 				Reads the current status of the fingers auto adjust operation
* @param armControl   	Pointer to the armControl structure
* @param status 		Pointer where the status will be saved
* @retval  				RET_OK if successful.
*/
retval_t
armControl_fingers_getAutoAdjustStatus (armControl_t* armControl,
										   armFingersOperationStatus_t* status);

/**
* @brief 				Moves the index
* @param armControl   	Pointer to the armControl structure
* @param direction		Direction of the movement
* @param speed			Target speed
* @retval  				RET_OK if successful.
*/
retval_t
armControl_index_move (armControl_t* armControl,
					        armControl_indexDirection_t direction,
					   	   	int speed);

/**
* @brief 				Stops the index
* @param armControl   	Pointer to the armControl structure
* @retval  				RET_OK if successful.
*/
retval_t
armControl_index_stop (armControl_t* armControl);


retval_t
armControl_index_launchAutoAdjust (armControl_t* armControl,
										int lowerThreshold,
										int upperThreshold);

/**
* @brief 				Reads the current status of the index auto adjust operation
* @param armControl   	Pointer to the armControl structure
* @param status 		Pointer where the status will be saved
* @retval  				RET_OK if successful.
*/
retval_t
armControl_index_getAutoAdjustStatus (armControl_t* armControl,
										   armFingersOperationStatus_t* status);


/**
* @brief 				Moves the thumb
* @param armControl   	Pointer to the armControl structure
* @param direction		Direction of the movement
* @param speed			Target speed
* @retval  				RET_OK if successful.
*/
retval_t
armControl_thumb_move (armControl_t* armControl,
					        armControl_thumbDirection_t direction,
					   	   	int speed);

/**
* @brief 				Stops the thumb
* @param armControl   	Pointer to the armControl structure
* @retval  				RET_OK if successful.
*/
retval_t
armControl_thumb_stop (armControl_t* armControl);


retval_t
armControl_thumb_launchAutoAdjust (armControl_t* armControl,
										int lowerThreshold,
										int upperThreshold);

/**
* @brief 				Reads the current status of the thumb auto adjust operation
* @param armControl  	Pointer to the armControl structure
* @param status 		Pointer where the status will be saved
* @retval  				RET_OK if successful.
*/
retval_t
armControl_thumb_getAutoAdjustStatus (armControl_t* armControl,
										   armFingersOperationStatus_t* status);


/**
* @brief 				Moves the wrist
* @param armControl   	Pointer to the armControl structure
* @param direction		Direction of the movement
* @param speed			Target speed
* @retval  				RET_OK if successful.
*/
retval_t
armControl_wrist_move (armControl_t* armControl,
							armWristDirection_t direction,
							int speed);

/**
* @brief 				Moves the wrist to an absolute position
* @param armControl   	Pointer to the armControl structure
* @param azimuth		Target azimuth
* @param elevation		Target elevation
* @retval  				RET_OK if successful.
*/
retval_t
armControl_wrist_position (armControl_t* armControl,
								int azimuth,
								int elevation);

/**
* @brief 				Moves the wrist azimuth to an absolute position
* @param armControl   	Pointer to the armControl structure
* @param azimuth		Target azimuth
* @retval  				RET_OK if successful.
*/
retval_t
armControl_wrist_positionAzimuth (armControl_t* armControl,
									   int azimuth);

/**
* @brief 				Moves the wrist azimuth to an absolute position with a given speed
* @param armControl   	Pointer to the armControl structure
* @param azimuth		Target azimuth
* @param speed 			Target speed
* @retval  				RET_OK if successful.
*/
retval_t
armControl_wrist_positionAzimuthSpeed (armControl_t* armControl,
									   		int azimuth,
									   		int speed);

/**
* @brief 				Moves the wrist elevation to an absolute position
* @param armControl   	Pointer to the armControl structure
* @param elevation		Target elevation
* @retval  				RET_OK if successful.
*/
retval_t
armControl_wrist_positionElevation (armControl_t* armControl,
										 int elevation);

/**
* @brief 				Moves the wrist elevation to an absolute position with a given speed
* @param armControl   	Pointer to the armControl structure
* @param elevation		Target elevation
* @param speed 			Target speed
* @retval  				RET_OK if successful.
*/
retval_t
armControl_wrist_positionElevationSpeed (armControl_t* armControl,
										 	  int elevation,
										 	  int speed);

/**
* @brief 				Stops the wrist
* @param armControl   	Pointer to the armControl structure
* @retval  				RET_OK if successful.
*/
retval_t
armControl_wrist_stop (armControl_t* armControl);

/**
* @brief 				Reads the current position of the wrist
* @param armControl   	Pointer to the armControl structure
* @param azimuth 		Pointer to the variable where the azimuth will be stored
* @param elevation 		Pointer to the variable where the elevation will be stored
* @retval  				RET_OK if successful.
*/
retval_t
armControl_wrist_getPosition (armControl_t* armControl,
								   int* azimuth,
								   int* elevation);

/**
* @brief 				Sets a virtual vertical limit
* @param armControl   	Pointer to the armControl structure
* @param viewlimit 		Type of vertical limit
* @retval  				RET_OK if successful.
*/
retval_t
armControl_wrist_setVisualLimit (armControl_t* armControl,
									  armWristViewLimit_t viewlimit);

#endif /* MODULES_armCONTROL_H_ */
