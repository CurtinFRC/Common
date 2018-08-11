#pragma once
//#include "stdafx.h"
#include "WPIlib.h"
#include <stdio.h>
#include <iostream>
#include <vector>
#include <functional>
using namespace autoqueue;

namespace autoqueue {
	class AutoQueue {
	public:
		AutoQueue();
		void addStep();

	private:
		vector<function<bool()>> queueList;
	};
}