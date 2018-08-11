#include "Autonomous.h"

using namespace autonomous;

Auton::Auton(DriveTrain *drive) {
	autoDrive = drive;
	stage1->clearQueue();
}

void Auton::ChooseRoutine(int inputs) { //Choose auto routine 
	if (inputs == 1) {
		Baseline();
	}
	else {
		RightAuto();
	}
}

void Auton::Periodic() {
	if (stage1->queueRunner()) {
		//next stage
	}
}

void Auton::Baseline() {
	stage1->addStep([=](){return autoDrive->DriveDistance(1, 4);});
	stage1->addStep("TurnAngle", 1, 90, 2);
}
 
void Auton::LeftAuto() {
	stage1->addStep(left);
}

void Auton::RightAuto() {
	stage1->addStep(Right);
}
