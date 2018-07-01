.#include "gtest/gtest.h"

#include "Toggle/Toggle.h"

TEST(Toggle, DefConstructor) {
  Toggle toggleFall(toggleEvent::ONFALL), toggleRise(toggleEvent::ONRISE);
  Toggle toggleChange(toggleEvent::ONCHANGE);

  ASSERT_EQ(toggleFall.getState(), true);
  ASSERT_EQ(toggleRise.getState(), false);
  ASSERT_EQ(toggleChange.getState(), false);
}

TEST(Toggle, ManConstructor) {
  Toggle toggleFall(toggleEvent::ONFALL, false), toggleRise(toggleEvent::ONRISE, true), toggleChange(toggleEvent::ONCHANGE, true);

  ASSERT_EQ(toggleFall.getState(), false);
  ASSERT_EQ(toggleRise.getState(), true);
  ASSERT_EQ(toggleChange.getState(), true);
}

TEST(Toggle, Falling) {
  Toggle toggle(toggleEvent::ONFALL);

  for (int i = 0; i < 2; i++) {
    ASSERT_EQ(toggle.tick(true), false);
    ASSERT_EQ(toggle.tick(true), false);
    ASSERT_EQ(toggle.tick(false), true);
    ASSERT_EQ(toggle.tick(false), false);
    ASSERT_EQ(toggle.tick(false), false);
  }
}

TEST(Toggle, Rising) {
  Toggle toggle(toggleEvent::ONRISE);

  for (int i = 0; i < 2; i++) {
    ASSERT_EQ(toggle.tick(false), false);
    ASSERT_EQ(toggle.tick(false), false);
    ASSERT_EQ(toggle.tick(true), true);
    ASSERT_EQ(toggle.tick(true), false);
    ASSERT_EQ(toggle.tick(true), false);
  }
}

TEST(Toggle, Changing) {
  Toggle toggle(toggleEvent::ONCHANGE);

  for (int i = 0; i < 2; i++) {
    ASSERT_EQ(toggle.tick(true), true);
    ASSERT_EQ(toggle.tick(true), false);
    ASSERT_EQ(toggle.tick(true), false);
    ASSERT_EQ(toggle.tick(false), true);
    ASSERT_EQ(toggle.tick(false), false);
    ASSERT_EQ(toggle.tick(false), false);
  }
}
