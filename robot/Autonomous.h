#pragma once

#include "WPILib.h"
#include "autoqueue.h"
#include "drivetrain.h"

using namespace autonomous;
using namespace std;
using namespace autoqueue;
using namespace drivetrain;

namespace autonomous {
	class Auton {
	public:
		Auton(DriveTrain *drive);
		void ChooseRoutine(int inputs);
		void Periodic();
	private:
		DriveTrain *autoDrive;
		AutoQueue *stage1 = new AutoQueue;
		void Baseline();
		void LeftAuto();
		void RightAuto();

	};
}
