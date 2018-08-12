#pragma once

#include <functional>

// typedef enum {
//   A = 1,
//   B,
//   X,
//   Y,
//   LEFT_BUMPER,
//   RIGHT_BUMPER,
//   BACK,
//   START,
//   LEFT_JOY,
//   RIGHT_JOY
// } xbox_button;

class bind {
public:
  bind(std::function<bool()> trigger, std::function<void()> callback);

  bool is_enabled;

  bool is_triggered();
  std::function<void()> get_callback();

private:
  std::function<bool()> _trigger;
  std::function<void()> _callback;
};
