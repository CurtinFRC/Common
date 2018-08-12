#include "bind_manager.h"

#include "bind.h"

bind_manager::bind_manager() {}

bind_manager *bind_manager::instance = 0;

bind_manager *bind_manager::get_instance() {
    if (instance == 0) instance = new bind_manager();
    return instance;
}


void bind_manager::add_bind(bind new_bind) {
  _binds.push_back(new_bind);
}


void bind_manager::tick() {
  for (auto it = _binds.begin(); it != _binds.end(); ++it) {
    if (it->is_triggered()) it->get_callback()();
  }
}
