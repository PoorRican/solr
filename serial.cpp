//
// Created by Josue Figueroa on 7/19/21.
//
#include "Arduino.h"
#include "serial.h"

orientation_t request_position() {
  Serial.write("Current Position:");
  Serial.read();
}

coordinate_t request_location() {

}

double request_north() {

}