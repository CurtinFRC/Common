#include "drivetrain.h"

using namespace drivetrain;

DriveTrain::DriveTrain() {
	left1 = new TalonSRX(0);   //Tank drive motor controllers example.
	left2 = new TalonSRX(1);
	left3 = new TalonSRX(2);
	right1 = new TalonSRX(3);
	right2 = new TalonSRX(4);
	right3 = new TalonSRX(5);
}

void DriveTrain::Stop() {
	//Stop
}

void DriveTrain::TankDrive(double left, double right) {
	// drive function for drivebase
}

bool DriveTrain::DriveDistance(double speed, double dist, double timeout) {
	//Drive a set distance forward.
	//Setup when run first time
	//Run loop and return true when done.
}

bool DriveTrain::GyroTurn(double speed, double dist, double timeout) {
	//Rotate set degrees.
	//Setup when run first time
	//Run loop and return true when done.
}

bool DriveTrain::EncoderTurn(double speed, double dist, double timeout) {
	//Rotate set degrees.
	//Setup when run first time
	//Run loop and return true when done.
}

bool DriveTrain::MotionProfile(string profile) {
	//Run a generated motion profile;
}