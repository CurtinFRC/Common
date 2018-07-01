#pragma once

typedef enum {
  ONFALL,
  ONRISE,
  ONCHANGE
} toggleEvent;

class Toggle {
public:
  Toggle(toggleEvent _mode);
  Toggle(toggleEvent _mode, bool initState);

  bool tick(bool val);

  bool getState();

private:
  toggleEvent mode;
  bool state;
  bool lstate;
};
