#pragma config(Motor,  port1,           leftFront,     tmotorVex393, openLoop)
#pragma config(Motor,  port2,           rightFront,    tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port9,           leftRear,      tmotorVex393, openLoop)
#pragma config(Motor,  port10,           rightRear,     tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port5,           leftArm,       tmotorVex393, openLoop)
#pragma config(Motor,  port6,           rightArm,      tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port7,           leftArm2,      tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port8,           rightArm2,     tmotorVex393, openLoop)
#pragma config(Motor,  port3,           leftIntake,    tmotorVex393, openLoop)
#pragma config(Motor,  port4,          rightIntake,   tmotorVex393, openLoop, reversed)
#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(60)
#pragma userControlDuration(0)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
  // Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task autonomous()
{
 	//Hits first large ball into goal zone. (Total time: 1 second)
	ClearTimer(T1);
	while(time1[T1] < 1000)
	{
  motor[leftFront] = 127;
  motor[leftRear] = 127;
  motor[rightFront] = 127;
  motor[rightRear] = 127;
  motor[leftArm] = 80;
  motor[rightArm] = 80;
  motor[leftArm2] = 80;
  motor[rightArm2] = 80;
	}
	//Keeps arm lifted, turns to the right 90 degrees. (Total time: 1.5 seconds)
	ClearTimer(T1);
	while(time1[T1] < 500)
	{
	motor[leftFront] = 127;
  motor[leftRear] = 127;
  motor[rightFront] = -127;
  motor[rightRear] = -127;
  motor[leftArm] = 80;
  motor[rightArm] = 80;
  motor[leftArm2] = 80;
  motor[rightArm2] = 80;
	}
	//Hits remaining large balls into goal zone. (Total time: 4.5 seconds)
	ClearTimer(T1);
	while(time1[T1] < 3000)
	{
  motor[leftFront] = 127;
  motor[leftRear] = 127;
  motor[rightFront] = 127;
  motor[rightRear] = 127;
  motor[leftArm] = 80;
  motor[rightArm] = 80;
  motor[leftArm2] = 80;
  motor[rightArm2] = 80;
	}
	//Keeps arm lifted, turns to the right 90 degrees. (Total time: 5 seconds)
	ClearTimer(T1);
	while(time1[T1] < 500)
	{
	motor[leftFront] = 127;
  motor[leftRear] = 127;
  motor[rightFront] = -127;
  motor[rightRear] = -127;
  motor[leftArm] = 80;
  motor[rightArm] = 80;
  motor[leftArm2] = 80;
  motor[rightArm2] = 80;
	}
	//Lowers arm, opens intake, drives forward to pick up two small balls. (Total time: 7.5 seconds)
	ClearTimer(T1);
	while(time1[T1] < 2500)
	{
  motor[leftFront] = 127;
  motor[leftRear] = 127;
  motor[rightFront] = 127;
  motor[rightRear] = 127;
  motor[leftArm] = -40;
  motor[rightArm] = -40;
  motor[leftArm2] = -40;
  motor[rightArm2] = -40;
  motor[leftIntake] = 127;
  motor[rightIntake] = 127;
	}
	//Turns to the right 162 degrees. (Total time: 8.4 seconds)
	ClearTimer(T1);
	while(time1[T1] < 900)
	{
	motor[leftFront] = 127;
  motor[leftRear] = 127;
  motor[rightFront] = -127;
  motor[rightRear] = -127;
 }
 //Goes forward to the goal. (Total time: 11.4 seconds)
 ClearTimer(T1);
	while(time1[T1] < 3000)
	{
	motor[leftFront] = 127;
  motor[leftRear] = 127;
  motor[rightFront] = 127;
  motor[rightRear] = 127;
 }
 //Lifts arm. (Total time: 12.4 seconds)
	ClearTimer(T1);
	while(time1[T1] < 1000)
	{
		motor[leftArm] = 80;
		motor[rightArm] = 80;
		motor[leftArm2]= 80;
		motor[rightArm2] = 80;
	}
	//Deposits balls in goal. (Total time: 13.9 seconds)
	ClearTimer(T1);
	while(time1[T1] < 1500)
	{
		motor[leftIntake] = 127;
		motor[rightIntake] = 127;
		motor[leftArm] = 80;
		motor[rightArm] = 80;
		motor[leftArm2]= 80;
		motor[rightArm2] = 80;
	}
	//Lowers arm. (Total time: 14.9 seconds)
	ClearTimer(T1);
	while(time1[T1] < 1000)
	{
		motor[leftArm] = -40;
		motor[rightArm] = -40;
		motor[leftArm2]= -40;
		motor[rightArm2] = -40;
	}
	//Turns to the right 162 degrees. (Total time: 15.8 seconds)
	ClearTimer(T1);
	while(time1[T1] < 900)
	{
	motor[leftFront] = 127;
  motor[leftRear] = 127;
  motor[rightFront] = -127;
  motor[rightRear] = -127;
 }
	//Opens intake, drives forward to pick up two small balls. (Total time: 20.8 seconds)
	ClearTimer(T1);
	while(time1[T1] < 5000)
	{
  motor[leftFront] = 127;
  motor[leftRear] = 127;
  motor[rightFront] = 127;
  motor[rightRear] = 127;
  motor[leftIntake] = 127;
  motor[rightIntake] = 127;
	}
	//Turns to the right 180 degrees. (Total time: 21.8 seconds)
	ClearTimer(T1);
	while(time1[T1] < 1000)
	{
	motor[leftFront] = 127;
  motor[leftRear] = 127;
  motor[rightFront] = -127;
  motor[rightRear] = -127;
 }
 	//Drives forward to goal. (Total time: 26.8 seconds)
	ClearTimer(T1);
	while(time1[T1] < 5000)
	{
  motor[leftFront] = 127;
  motor[leftRear] = 127;
  motor[rightFront] = 127;
  motor[rightRear] = 127;
}
//Lifts arm. (Total time: 27.8 seconds)
	ClearTimer(T1);
	while(time1[T1] < 1000)
	{
		motor[leftArm] = 80;
		motor[rightArm] = 80;
		motor[leftArm2]= 80;
		motor[rightArm2] = 80;
	}
	//Deposits balls in goal. (Total time: 29.3 seconds)
	ClearTimer(T1);
	while(time1[T1] < 1500)
	{
		motor[leftIntake] = 127;
		motor[rightIntake] = 127;
		motor[leftArm] = 80;
		motor[rightArm] = 80;
		motor[leftArm2]= 80;
		motor[rightArm2] = 80;
	}

}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task usercontrol()
{
	// User control code here, inside the loop

	while (true)
	{
	  // This is the main execution loop for the user control program. Each time through the loop
	  // your program should update motor + servo values based on feedback from the joysticks.

	  // .....................................................................................
	  // Insert user code here. This is where you use the joystick values to update your motors, etc.
	  // .....................................................................................

	  UserControlCodePlaceholderForTesting(); // Remove this function call once you have "real" code.
	}
}
