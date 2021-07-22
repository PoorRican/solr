//
// Created by Josue Figueroa on 7/19/21.
//
#include "Arduino.h"
#include "serial.h"


orientation_t request_position() {
  String raw;
  while(Serial.available() <= 0) {
    Serial.write("Current Solar Position: ");
  }
  while(Serial.available() > 0) {
    // TODO: catch incorrect format
    raw = Serial.read();
    idx = raw.indexOf(", ");
    String sea, azimuth;
    sea = raw.substring(0, idx);
    azimuth = raw.substring(idx + 2);
    return orientation_t(sea.toDouble(), azimuth.toDouble());
  }
}

coordinate_t request_location() {
  String raw;
  while(Serial.available() <= 0) {
    Serial.write("Current Coordinates: ");
  }
  while(Serial.available() > 0) {
    // TODO: catch incorrect format
    raw = Serial.read();
    idx = raw.indexOf(", ");
    String lat, lon;
    lat = raw.substring(0, idx);
    lon = raw.substring(idx + 2);
    return coordinate_t(lat.toDouble(), lon.toDouble());
  }
}

double request_north() {
  String raw;
  while(Serial.available() <= 0) {
    Serial.write("North Offset: ");
  }
  while(Serial.available() > 0) {
    // TODO: catch incorrect format
    String raw = Serial.read();
    return raw.toDouble();
  }
}