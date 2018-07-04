#include "gtest/gtest.h"

#include "Toggle.h"

TEST(Toggle, DefConstructors) {
  Toggle toggleDef1();

  EXPECT_EQ(toggleDef1.tick(true), true);
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
