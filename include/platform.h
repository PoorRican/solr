//
// Created by Josue Figueroa on 7/18/21.
//

#include "Arduino.h"
#include "Stepper.h"

#include "types.h"

#ifndef SOLR_PLATFORM_H
#define SOLR_PLATFORM_H

#define STEPPER_RPM 30
#define STEPPER_RESOLUTION 200    // change this to number of steps per revolution for specific motor
#define GEAR_RATIO 10             // gear ratio. 20 revolutions of motor constitute 1 revolution of gear
#define VERT_REVOLUTIONS 5        // total revolutions to go from 0 to 180 degrees (vertically)
#define HORIZ_REVOLUTIONS 10      // total revolutions to go from 0 to 360 degrees (horizontally)

#define TOTAL_VERT_REVOLUTIONS = STEPPER_RESOLUTION * GEAR_RATIO * VERT_REVOLUTIONS
#define TOTAL_HORIZ_REVOLUTIONS = STEPPER_RESOLUTION * GEAR_RATIO * HORIZ_REVOLUTIONS


/**
 * Abstracts a platform with 2 motors and 2 rotary sensors
 */
class Platform {
public:
  Platform(Stepper* horiz_motor, Stepper* vert_motor) : north(0),
  horiz_motor(horiz_motor), vert_motor(vert_motor),
  orientation({0,0}) {
    get_orientation();
  }
  explicit Platform(const double north, Stepper* horiz_motor, Stepper* vert_motor) : north(north),
  horiz_motor(horiz_motor), vert_motor(vert_motor),
  orientation({0,0}) {
    get_orientation();
  }

  /**
   * Moves platform to given orientation
   *
   * @param o : desired orientation, relative to North.
   * @param absolute : determines if orientation is absolute to true north or not
   */
  void set_orientation(const orientation_t& o, const boolean absolute=true);

  /**
   * Returns current platform orientation
   *
   * @return updated orientation as an `orientation_t`
   */
  orientation_t get_orientation();

  /**
   * Used for dynamically setting north
   *
   * @param north : an angle between 0 and 360 degrees
   */
  void set_north(double north);


private:
  double north;                 // stores current position of north in relation to orientation
  Stepper* horiz_motor;         // motor attached to platform to control horizontal plane
  Stepper* vert_motor;          // motor attached to platform to control vertical plane
  /**
   * Current orientation
   * Gets updated by `read_orientation`
   */
  orientation_t orientation;

  /**
   * Configures stepper motor
   */
  void init_motor();

  /**
   * Reads rotary sensor and updates internal orientation
   */
  void read_orientation();

  /**
   * Engages motors to move platform
   *
   * @param o : desired orientation
   */
  void move(const orientation_t& o) const;

  /**
   * Converts orientation from absolute orientation (relative to north)
   * to orientation relative to platform itself.
   *
   * @return relative orientation
   */
  orientation_t absolute_to_relative(const orientation_t& absolute) const;

  /**
   * Converts orientation from relative orientation (relative to platform)
   * to an absolute orientation relative to North.
   *
   * @return absolute orientation
   */
  orientation_t relative_to_absolute(const orientation_t& relative) const;
};


#endif //SOLR_PLATFORM_H
