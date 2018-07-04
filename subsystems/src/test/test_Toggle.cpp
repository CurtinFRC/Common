#include "gtest/gtest.h"

#include "toggle.h"

TEST(Toggle, DefConstructor) {
  toggle toggle_def;

  EXPECT_TRUE(toggle_def.tick(true));
}

TEST(Toggle, Falling) {
  toggle toggle(toggle_event::ONFALL);

  for (int i = 0; i < 2; i++) {
    ASSERT_FALSE(toggle.tick(true));
    ASSERT_FALSE(toggle.tick(true));
    ASSERT_TRUE(toggle.tick(false));
    ASSERT_FALSE(toggle.tick(false));
    ASSERT_FALSE(toggle.tick(false));
  }
}

TEST(Toggle, Rising) {
  toggle toggle(toggle_event::ONRISE);

  for (int i = 0; i < 2; i++) {
    ASSERT_FALSE(toggle.tick(false));
    ASSERT_FALSE(toggle.tick(false));
    ASSERT_TRUE(toggle.tick(true));
    ASSERT_FALSE(toggle.tick(true));
    ASSERT_FALSE(toggle.tick(true));
  }
}

TEST(Toggle, Changing) {
  toggle toggle(toggle_event::ONCHANGE);

  for (int i = 0; i < 2; i++) {
    ASSERT_TRUE(toggle.tick(true));
    ASSERT_FALSE(toggle.tick(true));
    ASSERT_FALSE(toggle.tick(true));
    ASSERT_TRUE(toggle.tick(false));
    ASSERT_FALSE(toggle.tick(false));
    ASSERT_FALSE(toggle.tick(false));
  }
}
