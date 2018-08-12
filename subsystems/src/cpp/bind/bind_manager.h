#pragma once

#include <memory>
#include <vector>

#include "bind.h"

class bind_manager {
private:
  static bind_manager *instance;
  bind_manager();

  std::vector<bind> _binds;

public:
  static bind_manager *get_instance();
  void add_bind(bind new_bind);
  void tick();
};
