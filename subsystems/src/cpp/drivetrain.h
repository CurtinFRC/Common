#pragma once

namespace subsystems {
  typedef struct {
    double left_volts, right_volts;
    double left_rpm, right_rpm;
    double rotation_rad_s;
  } coupled_drivetrain_out;

  // subsystems::coupled_drivetrain
  //
  // Very basic tank / coupled drivetrain implementation, with gyroscope
  // control. Assumes single-speed reduction gearbox with CIMs for simplicity.
  // Simple proportional-only compensation.
  class coupled_drivetrain {
  public:
    // \param wheel_diameter The wheel diameter in inches
    // \param track_width The distance between the left and right driven wheels in metres
    // \param reduction The gearbox reduction (unitless)
    coupled_drivetrain(double wheel_diameter, double track_width, double reduction) : 
        _wheel_diameter(wheel_diameter), _track_width(track_width), _reduction(reduction) { }

    // calculate_angular
    // \param heading The desired heading in degrees
    // \param speed The desired speed in metres/sec
    // \param gyro The current angle of the gyroscope
    coupled_drivetrain_out calculate_angular(double heading, double speed, double gyro);
  
  private:
    double _wheel_diameter, _track_width, _reduction;
  };
} // namespace subsystems