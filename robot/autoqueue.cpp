#include "autoqueue.h"
#include "drivetrain.h"
#include <map>

using namespace autoqueue;
using namespace drivetrain;

AutoQueue::AutoQueue(void* object) {}

AutoQueue::AutoQueue(void* object, vector<function<bool()>> prefill) {
	queueList = prefill;
}

void AutoQueue::addStep(function<bool()> step) {
	queueList.insert(queueList.end(), step);
}

void AutoQueue::clearQueue() {
	queueList.clear();
}

bool AutoQueue::queueRunner() {
	bool state = false;
	if (increment < queueList.size()) {
		if (queueList[increment]()) increment++;
	}
	else {
		state = true;
		overrideIncrement(0);
	}
	return state;
}

void AutoQueue::overrideIncrement(unsigned int input) {
	increment = input;
}