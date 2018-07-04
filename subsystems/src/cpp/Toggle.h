#pragma once

typedef enum {
  ONFALL,
  ONRISE,
  ONCHANGE
} toggleEvent;

class Toggle {
public:
  Toggle(toggleEvent _mode = toggleEvent::ONRISE);
  Toggle(toggleEvent _mode, bool initState);

  bool tick(bool val);

  bool getTriggered();

private:
  toggleEvent mode;
  bool triggered;
  bool lstate;
};
