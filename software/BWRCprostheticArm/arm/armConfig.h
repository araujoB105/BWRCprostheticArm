/*
 * motorConfig.h
araujo@berkeley.edu - 2018
 */

#ifndef ARM_ARMCONFIG_H_
#define ARM_ARMCONFIG_H_

/* Relation from motor to wrist (motor->gears->linear) */
#define WRIST_CIRCULAR_REDUCTION 1			/* Adimensional */
#define WRIST_CIRCULAR_FINALRELATION 1			/* Adimensional */
#define WRIST_CIRCULATOLINEAR_CONVERSION 15 	/* cm/revolution */

/* All different relations between motors and arm */


/* Fingers relations (motor->gears->wormdrive->fingers) */
#define FINGERS_CIRCULAR_REDUCTION 1			/* Adimensional */
#define FINGERS_CIRCULARTOLINERAR_CONVERSION 5 	/* mm/revolution */
#define FINGERS_STROKE_LENGTH 25					/* mm */
#define FINGERS_AUTOADJUST_SPEED 25 /*Standar speed*/

/* Waterjet relations (motor->gears->angle) */
#define WRIST_AZIMUTH_CIRCULAR_REDUCTION 1		/* Adimensional */
#define WRIST_AZIMUTH_CIRCULAR_FINALRELATION 1	/* Adimensional */
#define WRIST_ELEVATION_CIRCULAR_REDUCTION 1		/* Adimensional */
#define WRIST_ELEVATION_CIRCULAR_FINALRELATION 1	/* Adimensional */


#endif /* ARM_ARMCONFIG_H_ */
