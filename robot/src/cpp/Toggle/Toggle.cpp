#include "Toggle.h"

Toggle::Toggle(toggleEvent _mode) {
  mode = _mode;
  state = false;
  lstate = _mode == 2 ? false : !_mode;
}

Toggle::Toggle(toggleEvent _mode, bool initState) {
  mode = _mode;
  state = false;
  lstate = initState;
}

bool Toggle::tick(bool val) {
  state = lstate != val && !val != mode;
  lstate = val;

  return state;
}

bool Toggle::getState() { return state; }
