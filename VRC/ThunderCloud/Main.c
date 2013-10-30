#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    accel,          sensorNone)
#pragma config(Sensor, in2,    poten,          sensorNone)
#pragma config(Sensor, in3,    gyro,           sensorGyro)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Motor,  port1,           armRight,      tmotorVex393, openLoop)
#pragma config(Motor,  port2,           intakeRight,   tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port3,           intakeLeft,    tmotorVex393, openLoop)
#pragma config(Motor,  port4,           armLeft2,      tmotorVex393, openLoop)
#pragma config(Motor,  port5,           armLeft,       tmotorVex393, openLoop)
#pragma config(Motor,  port6,           backRight,     tmotorVex393, openLoop, reversed, encoder, encoderPort, I2C_2, 1000)
#pragma config(Motor,  port7,           frontRight,    tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port8,           frontLeft,     tmotorVex393, openLoop)
#pragma config(Motor,  port9,           backLeft,      tmotorVex393, openLoop, encoder, encoderPort, I2C_1, 1000)
#pragma config(Motor,  port10,          armRight2,     tmotorVex393, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(125)

#include "Vex_Competition_Includes.c"
#include "PIDController.c"
#include "LCD.c"
#include "Sound.c"

PIDController armPID;
PIDController turnPID;

const int ARMAX = 3800;
const int ARMIN = 2000;

/*int pickSide()
{
	int side = -1;
	while (true)
	{
		clearLCDLine(0);
	 	clearLCDLine(1);
	 	displayLCDPos(0, 0);
	 	displayLCDCenteredString(0,"Which Side?");
	 	displayLCDPos(1, 0);
	 	displayNextLCDString("Left       Right");
	 	if(nLCDButtons == 1)
	 	{
	 		side = 0;
	 		break;
		}
		else if(nLCDButtons == 4)
		{
			side = 1;
			break;
		}
	}
 	return side;
}*/

void driveArcade(int y, int x) {
	motor[frontLeft] = motor[backLeft] = y + x;
	motor[frontRight] = motor[backRight] = y - x;
}
void setArmSpeed(int z) {
	motor[armRight] = motor[armLeft] = motor[armLeft2] = motor[armRight2] = z;
}
void setIntakeSpeed(int speed) {
		motor[intakeLeft] = motor[intakeRight] = speed;
}
int scaleInput(int a) {
	return a;
	//return a * a;
}



///////////////////////////////////////////////////////////
// Robot Tasks
///////////////////////////////////////////////////////////

void pre_auton() {
	init(armPID, 0.564444, 0, 0);
	init(turnPID, 0.267368, 0, 0);

	SensorType[gyro] = sensorNone;
	wait1Msec(1000);
	SensorType[gyro] = sensorGyro;
	wait1Msec(2000);
	SensorValue[gyro]=0;
	SensorFullCount[gyro]=3600;

	// Autonomous initialization
  bStopTasksBetweenModes = true;

  StartTask(startLCD);
}
task autonomous() {
	// Autonomous
	//playMissionImpossible();

	// setSetpoint(turnPID, [degrees x 10 (0 to 3600)] );
	// setEnabled(turnPID); setDisabled(turnPID);
	// driveArcade([127 to -127], 0);
	// wait1Msec([time in msec]);
	/*driveArcade(127, 0);
	wait1Msec(4000);
	driveArcade(0, 0);

	setSetpoint(turnPID, 1270);
	setEnabled(turnPID);
	wait1Msec(1000);
	setDisabled(turnPID);
	driveArcade(0, 0);

	driveArcade(-127, 0);
	wait1Msec(4000);
	driveArcade(0, 0);*/
//	string a = "autonomous"
//	displayString(a, a);


	//setSetpoint(armPID,3200);	//raise arm
	//setEnabled(armPID,true);
	//wait1Msec(1000);
	//setEnabled(armPID,false);
	setIntakeSpeed(-127);				//drop buckie ball

	setArmSpeed(100);
	wait1Msec(1000);
	setArmSpeed(5);

	driveArcade(70,0);					//drive forward
	wait1Msec(1100);
	driveArcade(0,0);

	setIntakeSpeed(0);
	setArmSpeed(20);

	wait1Msec(1000);

	driveArcade(-70,0);				//drive back
	wait1Msec(1200);
	driveArcade(0,0);


	wait1Msec(5000);

	driveArcade(70,0);					//drive forward
	wait1Msec(1300);
	driveArcade(0,0);

	wait1Msec(1000);

	driveArcade(-70,0);				//drive back
	wait1Msec(1300);
	driveArcade(0,0);

	//setSetpoint(turnPID,950);	//turn to the right 90
	//setEnabled(turnPID,true);
	//wait1Msec(1000);
	//setEnabled(turnPID,false);
	//driveArcade(0,127);
	//wait1Msec(1000);
	//driveArcade(0,0);

	/*wait1Msec(3000);

	//setSetpoint(turnPID,-950);//turn to the left 90
	//setEnabled(turnPID,true);
	//wait1Msec(1000);
	//setEnabled(turnPID,false);
	//driveArcade(0,-127);
	//wait1Msec(1000);
	//driveArcade(0,0);

	driveArcade(127,0);				//drive forward
	wait1Msec(1500);
	driveArcade(0,0);*/

/*	setIntakeSpeed(127);				//drop buckie ball
	wait10Msec(5000);
	setIntakeSpeed(0);*/
}

task usercontrol() {
	// User control initialization
	while (true) { // User control loop
	  int driveX = scaleInput(vexRT[Ch4]);
	  int driveY = scaleInput(vexRT[Ch3]);
	  int armSpeed = vexRT[Ch2];
	  int intakeSpeed = 127*((vexRT[Btn5U]|vexRT[Btn5D])-(vexRT[Btn6U]|vexRT[Btn6D]));
	  /*if (vexRT[Btn8R] == 1) {
	  	if (armPID.enabled != true) {
	 			setSetpoint(armPID, SensorValue[poten]);
	 			setEnabled(armPID, true);
	 			setThresholds(armPID, -127, 127);
	 		} else {
	 			setEnabled(armPID, false);
	 		}
		}
	 /* if (vexRT[Btn8D] == 1) {
			if (turnPID.enabled == true) {s
				setEnabled(turnPID, false);
			} else {
				setEnabled(turnPID, true);
				setSetpoint(turnPID, SensorValue[gyro]);
				setThresholds(turnPID, -127, 127);
			}
		}*/
		/*string potenString, gyroString;
		sprintf(potenString, "%3f%c", SensorValue[poten]);
		sprintf(gyroString, "%3f%c", SensorValue[gyro]);
		displayString(potenString, gyroString);*/

	  driveArcade(turnPID.enabled ? calculate(turnPID, SensorValue[gyro]) : driveY, driveX);
	  setArmSpeed(armPID.enabled ? calculate(armPID, SensorValue[poten]) : armSpeed);
	  setIntakeSpeed(intakeSpeed);
	}
}
