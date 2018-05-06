#include "drivetrain.h"

using namespace subsystems;

coupled_drivetrain_out coupled_drivetrain::calculate_angular(double heading, double speed, double gyro) {
  // In a real system you'd probably want to find the shortest angle, not just
  // the pure offset, that way your robot never needs to turn more than 90 degrees
  // per call.
  double angular_error = gyro - heading;
  // This will need tuning.
  // rad/s = kP * angular_error (rad), kP = 1/s
  double turn_rate = 0.5 * (angular_error / 180.0f * 3.1415); 
  
  // linear velocity = radius * angular velocity
  double turn_v = (_track_width / 2) * turn_rate;
  
  // doesn't approach true linear speed we want, but good enough
  double vel_left = turn_v + speed;
  double vel_right = turn_v - speed;

  // rad/s = v / r, rpm = rad/s * 0.159155
  double left_rpm = ((vel_left / (_wheel_diameter / 2)) * 0.159155) / _reduction;
  double right_rpm = ((vel_right / (_wheel_diameter / 2)) * 0.159155) / _reduction;

  double max_rpm = 5330;
  double max_volts = 12.0;

  // Assuming perfectly proportional
  // You could get a lot more specific about this, whether it be with a control loop
  // or system modelling, or both.
  double left_volts = (left_rpm / max_rpm) * max_volts;
  double right_volts = (right_rpm / max_rpm) * max_volts;

  return coupled_drivetrain_out{
    left_volts, right_volts,
    left_rpm, right_rpm,
    turn_rate
  };
}