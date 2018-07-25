//araujo@berkeley.edu - 2018

// Do not remove the include below (Arduino compatible)
#include "armApp.h"

#include <generic_list.h>
#include <SerialCommand.h>
#include <SPI.h>
#include <Adafruit_BLE.h>
#include <Adafruit_BluefruitLE_SPI.h>
#include <Adafruit_BluefruitLE_UART.h>
#include <BluefruitConfig.h>



#include "Adafruit_PWMServoDriver.h"
#include "motorControl.h"
#include "motorConfig.h"

// ARM like an entity (future)
//#include "./arm/armControl.h"
//#include "./arm/armConfig.h"



#define DEBUG 1 //Remove after DEBUG

#define THUMB_PIN 6
#define INDEX_PIN 7
#define FINGERS_PIN 5
#define WRIST_ELEVATION_PIN 12
#define WRIST_AZIMUTH_PIN 13

#define FACTORYRESET_ENABLE         1
#define MINIMUM_FIRMWARE_VERSION    "0.6.6"
#define MODE_LED_BEHAVIOUR          "MODE"

#define WINDOW_DECISION 1
#define NUM_GEST 5

SerialCommand SCmd;


motorControl_t* motorControl;
Adafruit_PWMServoDriver servo = Adafruit_PWMServoDriver(&Wire, 0x40);;
Adafruit_BluefruitLE_SPI ble(BLUEFRUIT_SPI_CS, BLUEFRUIT_SPI_IRQ, BLUEFRUIT_SPI_RST);
motorUnit_t* motorUnit_thumb;
motorUnit_t* motorUnit_index;
motorUnit_t* motorUnit_fingers;
motorUnit_t* motorUnit_wrist_azimuth;
motorUnit_t* motorUnit_wrist_elevation;

// ARM like an entity
//armControl_t* armControl;


retval_t
arm_init (void){

	motorOperation_t* motorOperation_thumb;
	motorOperation_t* motorOperation_index;
	motorOperation_t* motorOperation_fingers;
	motorOperation_t* motorOperation_wrist_azimuth;
	motorOperation_t* motorOperation_wrist_elevation;


	motorOperation_thumb = (motorOperation_t*)malloc(sizeof(motorOperation_t));
	motorOperation_index = (motorOperation_t*)malloc(sizeof(motorOperation_t));
	motorOperation_fingers = (motorOperation_t*)malloc(sizeof(motorOperation_t));
	motorOperation_wrist_azimuth = (motorOperation_t*)malloc(sizeof(motorOperation_t));
	motorOperation_wrist_elevation = (motorOperation_t*)malloc(sizeof(motorOperation_t));

	if (motorOperation_thumb == NULL)
		Serial.println("Thumb problem!");
	if (motorOperation_thumb == NULL)
			Serial.println("Index problem!");
	if (motorOperation_thumb == NULL)
			Serial.println("Fingers problem!");
	if (motorOperation_thumb == NULL)
			Serial.println("Wrist problem!");
	if (motorOperation_thumb == NULL)
			Serial.println("Wrist problem!");

	motorOperation_thumb->direction=MOTOR_ROT_LEFT;
	motorOperation_thumb->microsteps=200;
	motorOperation_thumb->pin=THUMB_PIN; //Electronic depend
	motorOperation_thumb->status=MOTOR_OPERATION_NOT_STARTED;
	motorOperation_thumb->type= MOTORMODE_POSITION;

	motorOperation_index->direction=MOTOR_ROT_LEFT;
	motorOperation_index->microsteps=200;
	motorOperation_index->pin=INDEX_PIN; //Electronic depend
	motorOperation_index->status=MOTOR_OPERATION_NOT_STARTED;
	motorOperation_index->type= MOTORMODE_POSITION;

	motorOperation_fingers->direction=MOTOR_ROT_LEFT;
	motorOperation_fingers->microsteps=200;
	motorOperation_fingers->pin=FINGERS_PIN; //Electronic depend
	motorOperation_fingers->status=MOTOR_OPERATION_NOT_STARTED;
	motorOperation_fingers->type= MOTORMODE_POSITION;

	motorOperation_wrist_azimuth->direction=MOTOR_ROT_LEFT;
	motorOperation_wrist_azimuth->microsteps=200;
	motorOperation_wrist_azimuth->pin=WRIST_AZIMUTH_PIN; //Electronic depend
	motorOperation_wrist_azimuth->status=MOTOR_OPERATION_NOT_STARTED;
	motorOperation_wrist_azimuth->type= MOTORMODE_POSITION;

	motorOperation_wrist_elevation->direction=MOTOR_ROT_LEFT;
	motorOperation_wrist_elevation->microsteps=200;
	motorOperation_wrist_elevation->pin=WRIST_ELEVATION_PIN; //Electronic depend
	motorOperation_wrist_elevation->status=MOTOR_OPERATION_NOT_STARTED;
	motorOperation_wrist_elevation->type= MOTORMODE_POSITION;

	Serial.println("Motor operation");


		if (motorControl_init(&motorControl) != RET_OK)
		{
			return RET_ERROR;
		}

		Serial.println("Pass Motor Control Init");


		if (motorControl_addMotor(motorControl,
								  &motorUnit_thumb,
								  servo,
								  &motorOperation_thumb,
								  &motorControlConfig_thumb) != RET_OK)
		{
			return RET_ERROR;
		}
		Serial.println("Pass add Thumb");


		if (motorControl_addMotor(motorControl,
								  &motorUnit_index,
								  servo,
								  &motorOperation_index,
								  &motorControlConfig_index) != RET_OK)
		{
			return RET_ERROR;
		}

		if (motorControl_addMotor(motorControl,
								  &motorUnit_fingers,
								  servo,
								  &motorOperation_fingers,
								  &motorControlConfig_fingers) != RET_OK)
		{
			return RET_ERROR;
		}

		if (motorControl_addMotor(motorControl,
								  &motorUnit_wrist_azimuth,
								  servo,
								  &motorOperation_wrist_azimuth,
								  &motorControlConfig_wrist_azimuth) != RET_OK)
		{
			return RET_ERROR;
		}

		if (motorControl_addMotor(motorControl,
								  &motorUnit_wrist_elevation,
								  servo,
								  &motorOperation_wrist_elevation,
								  &motorControlConfig_wrist_elevation) != RET_OK)
		{
			return RET_ERROR;
		}

		Serial.println("Added motors");


		if (motorControl_start(motorControl) != RET_OK)
		{
			return RET_ERROR;
		}


// ARM like an entity

//		if (armControl_create(&armControl) != RET_OK)
//		{
//			return RET_ERROR;
//		}
//
//		if (armControl_configure (armControl,
//									motorControl,
//									motorUnit_thumb,
//									motorUnit_index,
//									motorUnit_fingers,
//									motorUnit_wrist_azimuth,
//									motorUnit_wrist_elevation) != RET_OK)
//		{
//			return RET_ERROR;
//		}

		servo.begin();
		servo.setPWMFreq(55);  // Servos run at ~50 Hz updates
		delay(10);

		Serial.println("Added ARM");

		return RET_OK;
}


void LED_on()
{
  Serial.println("LED on");
  digitalWrite(13, HIGH);
}

void LED_off()
{
  Serial.println("LED off");
  digitalWrite(13, LOW);

}

void SayHello()
{
  char *arg;
  arg = SCmd.next();    // Get the next argument from the SerialCommand object buffer
  if (arg != NULL)      // As long as it existed, take it
  {
    Serial.print("Hello ");
    Serial.println(arg);
  }
  else {
    Serial.println("Hello, whoever you are");
  }
}


// This gets set as the default handler, and gets called when no other command matches.
void unrecognized()
{
  Serial.println("What?");
}

void fist_command()
{

#ifdef DEBUG
  Serial.println("We're in fist_command");
#endif

  motorControl_unit_moveSteps (motorControl, motorUnit_index, MOTOR_ROT_RIGHT, 150);
  motorControl_unit_moveSteps(motorControl, motorUnit_fingers, MOTOR_ROT_RIGHT, 220);
  motorControl_unit_moveSteps (motorControl, motorUnit_thumb, MOTOR_ROT_RIGHT, 220);

}

void three_command()
{


#ifdef DEBUG
  Serial.println("We're in three_command");
#endif

  motorControl_unit_moveSteps_low (motorControl, motorUnit_index, MOTOR_ROT_RIGHT, 150);
  motorControl_unit_moveSteps_low (motorControl, motorUnit_fingers, MOTOR_ROT_RIGHT, 380);
  motorControl_unit_moveSteps_low (motorControl, motorUnit_thumb, MOTOR_ROT_RIGHT, 220);

}

void extend_command()
{

#ifdef DEBUG
  Serial.println("We're in extend_command");
#endif

  motorControl_unit_moveSteps (motorControl, motorUnit_fingers, MOTOR_ROT_RIGHT, 370);
  motorControl_unit_moveSteps (motorControl, motorUnit_thumb, MOTOR_ROT_RIGHT, 380);
  motorControl_unit_moveSteps(motorControl, motorUnit_index, MOTOR_ROT_RIGHT, 450);

}

void cool_command()
{

#ifdef DEBUG
  Serial.println("We're in go_command");
#endif

  motorControl_unit_moveSteps_low (motorControl, motorUnit_index, MOTOR_ROT_RIGHT, 150);
  motorControl_unit_moveSteps_low (motorControl, motorUnit_fingers, MOTOR_ROT_RIGHT, 220);
  motorControl_unit_moveSteps_low (motorControl, motorUnit_thumb, MOTOR_ROT_RIGHT, 380);

}

void pointer_command()
{

#ifdef DEBUG
  Serial.println("We're in pointer_command");
#endif

   motorControl_unit_moveSteps_low (motorControl, motorUnit_index, MOTOR_ROT_RIGHT, 450);
  motorControl_unit_moveSteps_low (motorControl, motorUnit_fingers, MOTOR_ROT_RIGHT, 220);
  motorControl_unit_moveSteps_low (motorControl, motorUnit_thumb, MOTOR_ROT_RIGHT, 220);

}


void thumb_command()
{
  int aNumber=1;
  char *arg;

#ifdef DEBUG
  Serial.println("We're in thumb_command");
#endif

  arg = SCmd.next();
  if (arg != NULL)
  {
    aNumber=atoi(arg);    // Converts a char string to an integer
    Serial.print("First argument was: ");
    Serial.println(aNumber);
  }
  else {
    Serial.println("No arguments");
  }

  motorControl_unit_moveSteps (motorControl, motorUnit_thumb, MOTOR_ROT_RIGHT, aNumber);

}

void thumb_slow_command()
{
  int aNumber=1;
  char *arg;

#ifdef DEBUG
  Serial.println("We're in thumb_slow__command");
#endif

  arg = SCmd.next();
  if (arg != NULL)
  {
    aNumber=atoi(arg);    // Converts a char string to an integer
    Serial.print("First argument was: ");
    Serial.println(aNumber);
  }
  else {
    Serial.println("No arguments");
  }

	  motorControl_unit_moveSteps_low (motorControl, motorUnit_thumb, MOTOR_ROT_RIGHT, aNumber);


}


void index_command()
{
  int aNumber =1;
  char *arg;

#ifdef DEBUG
  Serial.println("We're in index_command");
#endif

  arg = SCmd.next();
  if (arg != NULL)
  {
    aNumber=atoi(arg);    // Converts a char string to an integer
    Serial.print("First argument was: ");
    Serial.println(aNumber);
  }
  else {
    Serial.println("No arguments");
  }

  motorControl_unit_moveSteps (motorControl, motorUnit_index, MOTOR_ROT_RIGHT, aNumber);

}


void index_slow_command()
{
  int aNumber=1;
  char *arg;

#ifdef DEBUG
  Serial.println("We're in index_command");
#endif

  arg = SCmd.next();
  if (arg != NULL)
  {
    aNumber=atoi(arg);    // Converts a char string to an integer
    Serial.print("First argument was: ");
    Serial.println(aNumber);
  }
  else {
    Serial.println("No arguments");
  }

	  motorControl_unit_moveSteps_low (motorControl, motorUnit_index, MOTOR_ROT_RIGHT, aNumber);


}


void fingers_command()
{
  int aNumber=1;
  char *arg;

#ifdef DEBUG
  Serial.println("We're in fingers_command");
#endif
  arg = SCmd.next();
  if (arg != NULL)
  {
    aNumber=atoi(arg);    // Converts a char string to an integer
    Serial.print("First argument was: ");
    Serial.println(aNumber);
  }
  else {
    Serial.println("No arguments");
  }

  motorControl_unit_moveSteps (motorControl, motorUnit_fingers, MOTOR_ROT_RIGHT, aNumber);

}


void fingers_slow_command()
{
  int aNumber=1;
  char *arg;

#ifdef DEBUG
  Serial.println("We're in fingers_slow__command");
#endif
  arg = SCmd.next();
  if (arg != NULL)
  {
    aNumber=atoi(arg);    // Converts a char string to an integer
    Serial.print("First argument was: ");
    Serial.println(aNumber);
  }
  else {
    Serial.println("No arguments");
  }

	  motorControl_unit_moveSteps_low (motorControl, motorUnit_fingers, MOTOR_ROT_RIGHT, aNumber);


}

void wrist_elevation_command()
{
  int aNumber=1;
  char *arg;
#ifdef DEBUG
  Serial.println("We're in wrist_elevation_command");
#endif
  arg = SCmd.next();
  if (arg != NULL)
  {
    aNumber=atoi(arg);    // Converts a char string to an integer
    Serial.print("First argument was: ");
    Serial.println(aNumber);
  }
  else {
    Serial.println("No arguments");
  }

  motorControl_unit_moveSteps (motorControl, motorUnit_wrist_elevation, MOTOR_ROT_RIGHT, aNumber);

}

void wrist_azimuth_command()
{
  int aNumber=1;
  char *arg;
#ifdef DEBUG
  Serial.println("We're in wrist_azimuth_command");
#endif
  arg = SCmd.next();
  if (arg != NULL)
  {
    aNumber=atoi(arg);    // Converts a char string to an integer
    Serial.print("First argument was: ");
    Serial.println(aNumber);
  }
  else {
    Serial.println("No arguments");
  }

  motorControl_unit_moveSteps (motorControl, motorUnit_wrist_azimuth, MOTOR_ROT_RIGHT, aNumber);


}

void ok_command()
{
#ifdef DEBUG
    Serial.println("All right!");
#endif
    motorControl_unit_moveSteps_low (motorControl, motorUnit_thumb, MOTOR_ROT_RIGHT, 210);
	delay(1000);
	motorControl_unit_moveSteps_low (motorControl, motorUnit_fingers, MOTOR_ROT_RIGHT, 380);
    delay(1000);
	motorControl_unit_moveSteps_low (motorControl, motorUnit_index, MOTOR_ROT_RIGHT, 150);


}


void stop()
{
#ifdef DEBUG
    Serial.println("STOP!");
#endif

    motorControl_unit_moveSteps (motorControl, motorUnit_thumb, MOTOR_ROT_RIGHT, 300);
    motorControl_unit_moveSteps (motorControl, motorUnit_index, MOTOR_ROT_RIGHT, 300);
    motorControl_unit_moveSteps (motorControl, motorUnit_fingers, MOTOR_ROT_RIGHT, 300);
    motorControl_unit_moveSteps (motorControl, motorUnit_wrist_elevation, MOTOR_ROT_RIGHT, 300);
    motorControl_unit_moveSteps (motorControl, motorUnit_wrist_azimuth, MOTOR_ROT_RIGHT, 300);
}


void add_commands()

{

		SCmd.addCommand("ON",LED_on);       // Turns LED on
		SCmd.addCommand("OFF",LED_off);        // Turns LED off
		SCmd.addCommand("HELLO",SayHello);     // Echos the string argument back
		SCmd.addCommand("T",thumb_command);
		SCmd.addCommand("TS",thumb_slow_command);
		SCmd.addCommand("I",index_command);
		SCmd.addCommand("IS",index_slow_command);
		SCmd.addCommand("F",fingers_command);
		SCmd.addCommand("FS",fingers_slow_command);
		SCmd.addCommand("WE",wrist_elevation_command);
		SCmd.addCommand("WA",wrist_azimuth_command);
		SCmd.addCommand("OK",ok_command);
		SCmd.addCommand("STOP",stop);

		SCmd.addDefaultHandler(unrecognized);  // Handler for command that isn't matched  (says "What?")

}


void error(const __FlashStringHelper*err) {
  Serial.println(err);
  while (1);
}

bool getUserInput(char buffer[], uint8_t maxSize)
{
  // timeout in 100 milliseconds
  TimeoutTimer timeout(100);

  memset(buffer, 0, maxSize);
  while( (!Serial.available()) && !timeout.expired() ) { delay(1); }

  if ( timeout.expired() ) return false;

  delay(2);
  uint8_t count=0;
  do
  {
    count += Serial.readBytes(buffer+count, maxSize);
    delay(2);
  } while( (count < maxSize) && (Serial.available()) );

  return true;
}


int voteDecision(char* buffer)
{
  uint8_t gest;
  int i;
  int vote[NUM_GEST+1];

  gest=0;
  for (i=0;i<=NUM_GEST;i++)
		vote[i]=0;

  for(i=0; buffer[i]!='\0';i++){
	  switch(buffer[i]) {
	     case '0'  :
	        vote[0]++;
	        break;
	     case '1'  :
	    	vote[1]++;
	    	break;
	     case '2'  :
	    	vote[2]++;
	    	break;
	     case '3'  :
	    	vote[3]++;
	    	break;
	     case '4'  :
	    	vote[4]++;
	    	break;
	     case '5'  :
	     	vote[5]++;
	     	break;
	     default :
		        vote[0]++;
	  }

	  for (i=0;i<=NUM_GEST;i++)
		  if (vote[i] > vote[gest]) //majority of gestures
		        gest = i;

	  return gest;

	  Serial.print(buffer[i]);
  }


  return gest;
}

void alarmMatch()
{
	  digitalWrite(13, LOW);

}


void setup(){



	pinMode(13, OUTPUT);		  //Live LED

	arm_init();

	add_commands();
	delay(500);
 	extend_command();

#ifdef DEBUG
	  Serial.begin(115200);
	  Serial.println(F("Adafruit Bluefruit Command Mode Example"));
	  Serial.println(F("---------------------------------------"));
	  /* Initialise the module */
	  Serial.print(F("Initialising the Bluefruit LE module: "));
#endif
	  if ( !ble.begin(VERBOSE_MODE) )
	  {
	    error(F("Couldn't find Bluefruit, make sure it's in CoMmanD mode & check wiring?"));
	  }
	  Serial.println( F("OK!") );

	  if ( FACTORYRESET_ENABLE )
	  {
	    /* Perform a factory reset to make sure everything is in a known state */
	    Serial.println(F("Performing a factory reset: "));
	    if ( ! ble.factoryReset() ){
	      error(F("Couldn't factory reset"));
	    }
	  }

	  /* Disable command echo from Bluefruit */
	  ble.echo(false);

	  Serial.println("Requesting Bluefruit info:");
	  /* Print Bluefruit information */
	  ble.info();

	  Serial.println(F("Please use Adafruit Bluefruit LE app to connect in UART mode"));
	  Serial.println(F("Then Enter characters to send to Bluefruit"));
	  Serial.println();

	  ble.verbose(false);  // debug info is a little annoying after this point!

	  /* Wait for connection */
	  while (! ble.isConnected()) {
	      delay(500);
	  }

	  // LED Activity command is only supported from 0.6.6
	  if ( ble.isVersionAtLeast(MINIMUM_FIRMWARE_VERSION) )
	  {
	    // Change Mode LED Activity
	    Serial.println(F("******************************"));
	    Serial.println(F("Change LED activity to " MODE_LED_BEHAVIOUR));
	    ble.sendCommandCheckOK("AT+HWModeLED=" MODE_LED_BEHAVIOUR); //DISABLE for Power measurements
	    Serial.println(F("******************************"));
	  }
}

void loop(){


int gest;

#ifdef DEBUG
	SCmd.readSerial();
#endif


	  // Check for incoming characters from Bluefruit
	  ble.println("AT+BLEUARTRX");
	  delay(1000);
	  ble.readline();

	  if (strcmp(ble.buffer, "OK") == 0) {
	    //no data
	    return;
	  }else {
	  if (strcmp(ble.buffer, "0") == 0) {
		//no data
		  return;
	  }


#ifdef DEBUG
	  // Some data was found, its in the buffer
	  Serial.print(F("[Recv] ")); Serial.println(ble.buffer);
#endif

	  gest = voteDecision(ble.buffer);

	  if (gest == 1) {
	  	    fist_command();
	  	    return;
	  	  }
	  else if (gest == 2) {
	  	  	cool_command();
	  	  	return;
	  	  }
	  else if (gest == 3) {
	  	    three_command();
	  	    return;
	  }
	  else if (gest == 4) {
	  	 	pointer_command();
	  	 	return;
	  }
	  else if (gest == 5) {
	 	  	extend_command();
	 	  	return;
	  }
	  else if (gest == 6) {
	  	 	ok_command();
	  	 	return;
	  }
	  }
	  ble.waitForOK();
	  //delay(1000);

}




