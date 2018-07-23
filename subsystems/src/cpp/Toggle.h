#pragma once

typedef enum {
  ONFALL,
  ONRISE,
  ONCHANGE
} toggle_event;

class toggle {
public:
  toggle(toggle_event mode = toggle_event::ONRISE);
  toggle(toggle_event mode, bool init_state);

  bool tick(bool val);

  bool getTriggered();

private:
  toggle_event _mode;
  bool _triggered;
  bool _lstate;
};
