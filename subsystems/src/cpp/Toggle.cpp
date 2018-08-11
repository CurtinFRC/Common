#include "toggle.h"

toggle::toggle(toggle_event mode) {
  _mode = mode;
  _triggered = false;
  _lstate = mode == 2 ? false : !mode;
}

toggle::toggle(toggle_event mode, bool initState) {
  _mode = mode;
  _triggered = false;
  _lstate = initState;
}

bool toggle::tick(bool val) {
  _triggered = _lstate != val && !val != _mode;
  _lstate = val;

  return _triggered;
}

bool toggle::getTriggered() { return _triggered; }
