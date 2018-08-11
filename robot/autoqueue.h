#pragma once

#include "WPIlib.h"

using namespace autoqueue;
using namespace std;

namespace autoqueue {
	class AutoQueue {
	public:
		AutoQueue(void* object);
		AutoQueue(void* object, vector<function<bool()>> prefill);
		void addStep(function<bool()> step);
		void clearQueue();
		bool queueRunner();
		void overrideIncrement(unsigned int input);

	private:
		vector<function<bool()>> queueList;
		unsigned int increment = 0;
	};
}