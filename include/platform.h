//
// Created by Josue Figueroa on 7/18/21.
//

#include "types.h"

#ifndef SOLR_PLATFORM_H
#define SOLR_PLATFORM_H


/**
 * Abstracts a platform with 2 motors and 2 rotary sensors
 */
class Platform {
public:
  Platform() : north(0), orientation({0,0}) {}
  explicit Platform(const double north) : north(north), orientation({0,0}) {}

  /**
   * Moves platform to given orientation
   *
   * @param o : desired orientation, relative to North.
   */
  void set_orientation(const orientation_t& o);

  /**
   * Returns current platform orientation
   * @return updated orientation as an `orientation_t`
   */
  orientation_t get_orientation();

  /**
   * Used for dynamically setting north
   * @param north : an angle between 0 and 360 degrees
   */
  void set_north(double north);


private:
  double north;                 // stores current position of north in relation to orientation
  /**
   * Current orientation
   * Gets updated by `read_orientation`
   */
  orientation_t orientation;

  /**
   * Reads rotary sensor and updates internal orientation
   */
  virtual void read_orientation() = 0;

  /**
   * Engages motors to move platform
   * @param o : desired orientation
   */
  virtual void move(orientation_t& o) const = 0;

  /**
   * Converts orientation from absolute orientation (relative to north)
   * to orientation relative to platform itself.
   * @return relative orientation
   */
  orientation_t absolute_to_relative(const orientation_t& absolute) const;

  /**
   * Converts orientation from relative orientation (relative to platform)
   * to an absolute orientation relative to North.
   * @return absolute orientation
   */
  orientation_t relative_to_absolute(const orientation_t& relative) const;
};


#endif //SOLR_PLATFORM_H
