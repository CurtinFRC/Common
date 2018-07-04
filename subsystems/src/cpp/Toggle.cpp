#include "Toggle.h"

Toggle::Toggle(toggleEvent _mode) {
  mode = _mode;
  triggered = false;
  lstate = _mode == 2 ? false : !_mode;
}

Toggle::Toggle(toggleEvent _mode, bool initState) {
  mode = _mode;
  triggered = false;
  lstate = initState;
}

bool Toggle::tick(bool val) {
  triggered = lstate != val && !val != mode;
  lstate = val;

  return triggered;
}

bool Toggle::getTriggered() { return triggered; }
