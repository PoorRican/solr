//
// Created by Josue Figueroa on 7/18/21.
//

#include "platform.h"


void Platform::init_motor() {
  horiz_motor->setSpeed(STEPPER_RPM);
  vert_motor->setSpeed(STEPPER_RPM);
}

void Platform::set_north(const double n) {
  north = fmod(n, 360);
}

orientation_t Platform::get_orientation() {
  read_orientation();
  return orientation;
}

void Platform::set_orientation(const orientation_t &o, const boolean absolute) {}

orientation_t Platform::absolute_to_relative(const orientation_t &absolute) const {
  return orientation_t({absolute.r - north, absolute.theta});
}

orientation_t Platform::relative_to_absolute(const orientation_t &relative) const {
  return orientation_t({relative.r + north, relative.theta});
}

void Platform::read_orientation() {

}

void Platform::move(const orientation_t& o) const {
  // should `get_orientation` be called beforehand?
  orientation_t diff({orientation.r - o.r, orientation.theta - o.theta});

  // calculate number of rotations necessary
  int horiz = map(abs(diff.r), 0, STEPPER_RESOLUTION * GEAR_RATIO * VERT_REVOLUTIONS, 0, 360);
  int vert  = map(abs(diff.theta), 0, STEPPER_RESOLUTION * GEAR_RATIO * HORIZ_REVOLUTIONS, 0, 180);

  // determine motor direction
  if(diff.r < 0) {
    horiz = -horiz;
  }
  if(diff.theta < 0) {
    vert = -vert;
  }

  // move motors
  horiz_motor->step(horiz);
  vert_motor->step(vert);
}