#include "bind.h"

#include <functional>

bind::bind(std::function<bool()> trigger, std::function<void()> callback) {
  _trigger = trigger;
  _callback = callback;
}


bool bind::is_triggered() {
  return is_enabled ? _trigger() : false;
}

std::function<void()> bind::get_callback() {
  return _callback;
}
