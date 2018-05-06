#include "gtest/gtest.h"

#include "drivetrain.h"

TEST(Subsystem, Drivetrain) {
  subsystems::coupled_drivetrain drivetrain(6.0, 1.0, 10);
  // This really isn't exhausive, you should do more testing than this but this gives the 
  // gist of how to use googletest
  auto result = drivetrain.calculate_angular(90, 1.5, 30);
  ASSERT_GT(result.left_rpm, result.right_rpm);
  ASSERT_GT(result.left_volts, result.right_volts);
  ASSERT_LT(result.rotation_rad_s, 0);
  ASSERT_LT(result.left_volts, 12.0);
  ASSERT_LT(result.right_volts, 12.0);
}