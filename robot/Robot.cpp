#include "WPILib.h"
#include <iostream>
#include <string>
#include <SmartDashboard/SmartDashboard.h>
#include <PowerDistributionPanel.h>
#include "drivetrain.h"
#include "Autonomous.h"

using namespace frc;
using namespace std;
using namespace cs;
using namespace nt;
using namespace drivetrain;
using namespace autonomous;

class Robot : public IterativeRobot {
	XboxController *xbox;
	DriveTrain *drive;
	Auton *auton;

	SendableChooser<int> *AutoChooser; // Choose auto mode

public:

	void RobotInit() {
		xbox = new XboxController(0);
		drive = new DriveTrain();
		auton = new Auton(drive);
		AutoChooser = new SendableChooser<int>;
	}

	void AutonomousInit() {
		drive->Stop(); //safety precaution
	}

	void AutonomousPeriodic() {
		auton->ChooseRoutine((int)AutoChooser->GetSelected());
	}

	void TeleopInit() {
		drive->Stop(); //safety precaution
	}

	void TeleopPeriodic() {
		drive->TankDrive(0, 0); // drive robot from controller inputs
	}
};

START_ROBOT_CLASS(Robot)
