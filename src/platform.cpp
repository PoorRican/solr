//
// Created by Josue Figueroa on 7/18/21.
//

#include "platform.h"

void Platform::set_north(const double n) {
  north = fmod(n, 360);
}

orientation_t Platform::get_orientation() {
  read_orientation();
  return orientation;
}

void Platform::set_orientation(orientation_t &o) {

}

orientation_t Platform::absolute_to_relative(const orientation_t &absolute) const {
  return orientation_t({absolute.r - north, absolute.theta});
}

orientation_t Platform::relative_to_absolute(const orientation_t &relative) const {
  return orientation_t({relative.r + north, relative.theta});
}