#pragma once

#include "WPILib.h"
#include <Timer.h>
#include <ctre/Phoenix.h>

using namespace std;

namespace drivetrain {
	class DriveTrain {
	public:
		DriveTrain();
		void Stop();
		void TankDrive(double left, double right);
		bool DriveDistance(double speed, double dist, double timeout=0);
		bool GyroTurn(double speed, double angle, double timeout=0);
		bool EncoderTurn(double speed, double angle, double timeout=0);
		bool MotionProfile(string profile);
	private:
		TalonSRX *left1, *left2, *left3, *right1, *right2, *right3;
		const double K = 4000; //encoder ticks per wheel rotation.
		const double circum = 0.4787787204071; // circumference of wheel in m;
	};
}