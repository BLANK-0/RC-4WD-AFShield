/*
 Name:		AFShield_4WD_RC.ino
 Created:	07-Feb-18 9:25:03 PM
 Author:	BLANK
*/

#include <AFMotor.h> //Adafruit Motor Shield Library

char BlueSig; // bluetooth data read

AF_DCMotor rightMotor1(4, MOTOR12_1KHZ); // create right front motor using M1 output on Motor Drive Shield, set to 1kHz PWM frequency
AF_DCMotor rightMotor2(1, MOTOR12_1KHZ); // create right back motor using M2 output on Motor Drive Shield, set to 1kHz PWM frequency
AF_DCMotor leftMotor1(3, MOTOR34_1KHZ);  // create left front motor using M3 output on Motor Drive Shield, set to 1kHz PWM frequency
AF_DCMotor leftMotor2(2, MOTOR34_1KHZ);  // create left back motor using M4 output on Motor Drive Shield, set to 1kHz PWM frequency

const int MAXSPEED = 255;
const int SPEED = 100;
const int TURN_SPEED = 75;
const int FAST_TURN_SPEED = 90;

void setup()
{
	Serial.begin(9600); //start serial communication
}

void loop()
{

	if (Serial.available() > 0)
	{
		BlueSig = Serial.read();
	}

	Serial.println(BlueSig); //conditions from android device

	if (BlueSig == 'W')
	{
		moveForward();
	}

	if (BlueSig == 'F')
	{
		moveForward_fast();
	}

	if (BlueSig == 'S')
	{
		moveBackward();
	}

	if (BlueSig == 'B')
	{
		moveBackward_fast();
	}

	if (BlueSig == 'D')
	{
		moveRight();
	}

	if (BlueSig == 'R')
	{
		moveRight_fast();
	}

	if (BlueSig == 'A')
	{
		moveLeft();
	}

	if (BlueSig == 'L')
	{
		moveLeft_fast();
	}

	else if (BlueSig == 'X')
	{
		moveStop();
	}
}

//functions for different modes

void moveForward()
{

	rightMotor1.run(FORWARD); // turn it on going forward
	rightMotor2.run(FORWARD); // turn it on going forward
	leftMotor1.run(FORWARD);  // turn it on going forward
	leftMotor2.run(FORWARD);  // turn it on going forward

	rightMotor1.setSpeed(SPEED);
	rightMotor2.setSpeed(SPEED);
	leftMotor1.setSpeed(SPEED);
	leftMotor2.setSpeed(SPEED);
}

void moveForward_fast()
{

	rightMotor1.run(FORWARD); // turn it on going forward
	rightMotor2.run(FORWARD); // turn it on going forward
	leftMotor1.run(FORWARD);  // turn it on going forward
	leftMotor2.run(FORWARD);  // turn it on going forward

	rightMotor1.setSpeed(MAXSPEED);
	rightMotor2.setSpeed(MAXSPEED);
	leftMotor1.setSpeed(MAXSPEED);
	leftMotor2.setSpeed(MAXSPEED);
}

void moveBackward()
{
	rightMotor1.run(BACKWARD); // turn it on going backward
	rightMotor2.run(BACKWARD); // turn it on going backward
	leftMotor1.run(BACKWARD);  // turn it on going backward
	leftMotor2.run(BACKWARD);  // turn it on going backward

	rightMotor1.setSpeed(SPEED);
	rightMotor2.setSpeed(SPEED);
	leftMotor1.setSpeed(SPEED);
	leftMotor2.setSpeed(SPEED);
}

void moveBackward_fast()
{
	rightMotor1.run(BACKWARD); // turn it on going backward
	rightMotor2.run(BACKWARD); // turn it on going backward
	leftMotor1.run(BACKWARD);  // turn it on going backward
	leftMotor2.run(BACKWARD);  // turn it on going backward

	rightMotor1.setSpeed(MAXSPEED);
	rightMotor2.setSpeed(MAXSPEED);
	leftMotor1.setSpeed(MAXSPEED);
	leftMotor2.setSpeed(MAXSPEED);
}

void moveRight()
{
	rightMotor1.run(BACKWARD); // turn right front motor forward
	rightMotor2.run(BACKWARD); // turn right back motor backward
	leftMotor1.run(FORWARD);   // turn left front motor forward
	leftMotor2.run(FORWARD);   // turn left back motor forward

	rightMotor1.setSpeed(TURN_SPEED);
	rightMotor2.setSpeed(TURN_SPEED);
	leftMotor1.setSpeed(TURN_SPEED);
	leftMotor2.setSpeed(TURN_SPEED);
}

void moveRight_fast()
{
	rightMotor1.run(BACKWARD); // turn right front motor backward
	rightMotor2.run(BACKWARD); // turn right back motor backward
	leftMotor1.run(FORWARD);   // turn left front motor forward
	leftMotor2.run(FORWARD);   // turn left back motor forward

	rightMotor1.setSpeed(FAST_TURN_SPEED);
	rightMotor2.setSpeed(FAST_TURN_SPEED);
	leftMotor1.setSpeed(FAST_TURN_SPEED);
	leftMotor2.setSpeed(FAST_TURN_SPEED);
}

void moveLeft()
{
	rightMotor1.run(FORWARD); // turn right front motor forward
	rightMotor2.run(FORWARD); // turn right back motor forward
	leftMotor1.run(BACKWARD); // turn left front motor backward
	leftMotor2.run(BACKWARD); // turn left back motor backward

	rightMotor1.setSpeed(TURN_SPEED);
	rightMotor2.setSpeed(TURN_SPEED);
	leftMotor1.setSpeed(TURN_SPEED);
	leftMotor2.setSpeed(TURN_SPEED);
}

void moveLeft_fast()
{
	rightMotor1.run(FORWARD); // turn right front motor forward
	rightMotor2.run(FORWARD); // turn right back motor forward
	leftMotor1.run(BACKWARD); // turn left front motor backward
	leftMotor2.run(BACKWARD); // turn left back motor backward

	rightMotor1.setSpeed(FAST_TURN_SPEED);
	rightMotor2.setSpeed(FAST_TURN_SPEED);
	leftMotor1.setSpeed(FAST_TURN_SPEED);
	leftMotor2.setSpeed(FAST_TURN_SPEED);
}

void moveStop()
{
	rightMotor1.run(RELEASE);
	rightMotor2.run(RELEASE);
	leftMotor1.run(RELEASE);
	leftMotor2.run(RELEASE); // stop the motors.

	rightMotor1.setSpeed(0);
	rightMotor2.setSpeed(0);
	leftMotor1.setSpeed(0);
	leftMotor2.setSpeed(0);
}
