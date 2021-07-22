//
// Created by Josue Figueroa on 7/18/21.
//

#ifndef SOLR_TYPES_H
#define SOLR_TYPES_H


struct orientation_t {
  double r;       // horizontal angle
  double theta;   // vertical angle in relation to horizon
};

struct coordinate_t {
  double latitude;
  double longitude;
};

#include <Arduino.h>

#endif //SOLR_TYPES_H
